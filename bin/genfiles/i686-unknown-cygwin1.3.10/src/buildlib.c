/* This is a C header file to be used by the output of the Cyclone
   to C translator.  The corresponding definitions are in file lib/runtime_cyc.c
*/
#ifndef _CYC_INCLUDE_H_
#define _CYC_INCLUDE_H_

#include <setjmp.h>

#ifdef NO_CYC_PREFIX
#define ADD_PREFIX(x) x
#else
#define ADD_PREFIX(x) Cyc_##x
#endif

#ifndef offsetof
/* should be size_t, but int is fine. */
#define offsetof(t,n) ((int)(&(((t *)0)->n)))
#endif

/* Tagged arrays */
struct _dynforward_ptr {
  unsigned char *curr;
  unsigned char *last_plus_one;
};

struct _dyneither_ptr {
  unsigned char *curr; 
  unsigned char *base; 
  unsigned char *last_plus_one; 
};  

/* Discriminated Unions */
struct _xtunion_struct { char *tag; };

/* Need one of these per thread (we don't have threads)
   The runtime maintains a stack that contains either _handler_cons
   structs or _RegionHandle structs.  The tag is 0 for a handler_cons
   and 1 for a region handle.  */
struct _RuntimeStack {
  int tag; /* 0 for an exception handler, 1 for a region handle */
  struct _RuntimeStack *next;
};

/* Regions */
struct _RegionPage {
#ifdef CYC_REGION_PROFILE
  unsigned total_bytes;
  unsigned free_bytes;
#endif
  struct _RegionPage *next;
  char data[0];
};

struct _RegionHandle {
  struct _RuntimeStack s;
  struct _RegionPage *curr;
  char               *offset;
  char               *last_plus_one;
#ifdef CYC_REGION_PROFILE
  const char         *name;
#endif
};

extern struct _RegionHandle _new_region(const char *);
extern void * _region_malloc(struct _RegionHandle *, unsigned);
extern void * _region_calloc(struct _RegionHandle *, unsigned t, unsigned n);
extern void   _free_region(struct _RegionHandle *);
extern void   _reset_region(struct _RegionHandle *);

/* Exceptions */
struct _handler_cons {
  struct _RuntimeStack s;
  jmp_buf handler;
};
extern void _push_handler(struct _handler_cons *);
extern void _push_region(struct _RegionHandle *);
extern void _npop_handler(int);
extern void _pop_handler();
extern void _pop_region();

#ifndef _throw
extern int _throw_null();
extern int _throw_arraybounds();
extern int _throw_badalloc();
extern int _throw(void* e);
#endif

extern struct _xtunion_struct *_exn_thrown;

/* Built-in Exceptions */
extern struct _xtunion_struct ADD_PREFIX(Null_Exception_struct);
extern struct _xtunion_struct * ADD_PREFIX(Null_Exception);
extern struct _xtunion_struct ADD_PREFIX(Array_bounds_struct);
extern struct _xtunion_struct * ADD_PREFIX(Array_bounds);
extern struct _xtunion_struct ADD_PREFIX(Match_Exception_struct);
extern struct _xtunion_struct * ADD_PREFIX(Match_Exception);
extern struct _xtunion_struct ADD_PREFIX(Bad_alloc_struct);
extern struct _xtunion_struct * ADD_PREFIX(Bad_alloc);

/* Built-in Run-time Checks and company */
#ifdef __APPLE__
#define _INLINE_FUNCTIONS
#endif

#ifdef NO_CYC_NULL_CHECKS
#define _check_null(ptr) (ptr)
#else
#ifdef _INLINE_FUNCTIONS
static inline void *
_check_null(void *ptr) {
  void*_check_null_temp = (void*)(ptr);
  if (!_check_null_temp) _throw_null();
  return _check_null_temp;
}
#else
#define _check_null(ptr) \
  ({ void*_check_null_temp = (void*)(ptr); \
     if (!_check_null_temp) _throw_null(); \
     _check_null_temp; })
#endif
#endif

#ifdef NO_CYC_BOUNDS_CHECKS
#define _check_known_subscript_null(ptr,bound,elt_sz,index) ({ \
  ((char *)ptr) + (elt_sz)*(index); })
#else
#ifdef _INLINE_FUNCTIONS
static inline char *
_check_known_subscript_null(void *ptr, unsigned bound, unsigned elt_sz, unsigned index) {
  void*_cks_ptr = (void*)(ptr);
  unsigned _cks_bound = (bound);
  unsigned _cks_elt_sz = (elt_sz);
  unsigned _cks_index = (index);
  if (!_cks_ptr) _throw_null();
  if (_cks_index >= _cks_bound) _throw_arraybounds();
  return ((char *)_cks_ptr) + _cks_elt_sz*_cks_index;
}
#else
#define _check_known_subscript_null(ptr,bound,elt_sz,index) ({ \
  void*_cks_ptr = (void*)(ptr); \
  unsigned _cks_bound = (bound); \
  unsigned _cks_elt_sz = (elt_sz); \
  unsigned _cks_index = (index); \
  if (!_cks_ptr) _throw_null(); \
  if (_cks_index >= _cks_bound) _throw_arraybounds(); \
  ((char *)_cks_ptr) + _cks_elt_sz*_cks_index; })
#endif
#endif

#ifdef NO_CYC_BOUNDS_CHECKS
#define _check_known_subscript_notnull(bound,index) (index)
#else
#ifdef _INLINE_FUNCTIONS
static inline unsigned
_check_known_subscript_notnull(unsigned bound,unsigned index) { 
  unsigned _cksnn_bound = (bound); 
  unsigned _cksnn_index = (index); 
  if (_cksnn_index >= _cksnn_bound) _throw_arraybounds(); 
  return _cksnn_index;
}
#else
#define _check_known_subscript_notnull(bound,index) ({ \
  unsigned _cksnn_bound = (bound); \
  unsigned _cksnn_index = (index); \
  if (_cksnn_index >= _cksnn_bound) _throw_arraybounds(); \
  _cksnn_index; })
#endif
#endif

/* Add i to zero-terminated pointer x.  Checks for x being null and
   ensures that x[0..i-1] are not 0. */
#ifdef NO_CYC_BOUNDS_CHECK
#define _zero_arr_plus(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#else
#define _zero_arr_plus(orig_x,orig_sz,orig_i) ({ \
  typedef _czs_tx = (*orig_x); \
  _czs_tx *_czs_x = (_czs_tx *)(orig_x); \
  unsigned int _czs_sz = (orig_sz); \
  int _czs_i = (orig_i); \
  unsigned int _czs_temp; \
  if ((_czs_x) == 0) _throw_null(); \
  if (_czs_i < 0) _throw_arraybounds(); \
  for (_czs_temp=_czs_sz; _czs_temp < _czs_i; _czs_temp++) \
    if (_czs_x[_czs_temp] == 0) _throw_arraybounds(); \
  _czs_x+_czs_i; })
#endif

/* Calculates the number of elements in a zero-terminated, thin array.
   If non-null, the array is guaranteed to have orig_offset elements. */
#define _get_zero_arr_size(orig_x,orig_offset) ({ \
  typedef _gres_tx = (*orig_x); \
  _gres_tx *_gres_x = (_gres_tx *)(orig_x); \
  unsigned int _gres_offset = (orig_offset); \
  unsigned int _gres = 0; \
  if (_gres_x != 0) { \
     _gres = _gres_offset; \
     _gres_x += _gres_offset - 1; \
     while (*_gres_x != 0) { _gres_x++; _gres++; } \
  } _gres; })

/* Does in-place addition of a zero-terminated pointer (x += e and ++x).  
   Note that this expands to call _zero_arr_plus. */
#define _zero_arr_inplace_plus(x,orig_i) ({ \
  typedef _zap_tx = (*x); \
  _zap_tx **_zap_x = &((_zap_tx*)x); \
  *_zap_x = _zero_arr_plus(*_zap_x,1,(orig_i)); })

/* Does in-place increment of a zero-terminated pointer (e.g., x++).
   Note that this expands to call _zero_arr_plus. */
#define _zero_arr_inplace_plus_post(x,orig_i) ({ \
  typedef _zap_tx = (*x); \
  _zap_tx **_zap_x = &((_zap_tx*)x); \
  _zap_tx *_zap_res = *_zap_x; \
  *_zap_x = _zero_arr_plus(_zap_res,1,(orig_i)); \
  _zap_res; })
  


/* functions for dealing with dynamically sized pointers */
#ifdef NO_CYC_BOUNDS_CHECKS
#ifdef _INLINE_FUNCTIONS
static inline unsigned char *
_check_dyneither_subscript(struct _dyneither_ptr arr,unsigned elt_sz,unsigned index) {
  struct _dyneither_ptr _cus_arr = (arr);
  unsigned _cus_elt_sz = (elt_sz);
  unsigned _cus_index = (index);
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index;
  return _cus_ans;
}
static inline unsigned char *
_check_dynforward_subscript(struct _dynforward_ptr arr,unsigned elt_sz,unsigned index) {
  struct _dynforward_ptr _cus_arr = (arr);
  unsigned _cus_elt_sz = (elt_sz);
  unsigned _cus_index = (index);
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index;
  return _cus_ans;
}
#else
#define _check_dyneither_subscript(arr,elt_sz,index) ({ \
  struct _dyneither_ptr _cus_arr = (arr); \
  unsigned _cus_elt_sz = (elt_sz); \
  unsigned _cus_index = (index); \
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index; \
  _cus_ans; })
#define _check_dynforward_subscript(arr,elt_sz,index) ({ \
  struct _dynforward_ptr _cus_arr = (arr); \
  unsigned _cus_elt_sz = (elt_sz); \
  unsigned _cus_index = (index); \
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index; \
  _cus_ans; })
#endif
#else
#ifdef _INLINE_FUNCTIONS
static inline unsigned char *
_check_dyneither_subscript(struct _dyneither_ptr arr,unsigned elt_sz,unsigned index) {
  struct _dyneither_ptr _cus_arr = (arr);
  unsigned _cus_elt_sz = (elt_sz);
  unsigned _cus_index = (index);
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index;
  if (!_cus_arr.base) _throw_null();
  if (_cus_ans < _cus_arr.base || _cus_ans >= _cus_arr.last_plus_one)
    _throw_arraybounds();
  return _cus_ans;
}
static inline unsigned char *
_check_dynforward_subscript(struct _dynforward_ptr arr,unsigned elt_sz,unsigned index) {
  struct _dynforward_ptr _cus_arr = (arr);
  unsigned _cus_elt_sz = (elt_sz);
  unsigned _cus_index = (index);
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index;
  if (!_cus_arr.last_plus_one) _throw_null();
  if (_cus_ans >= _cus_arr.last_plus_one)
    _throw_arraybounds();
  return _cus_ans;
}
#else
#define _check_dyneither_subscript(arr,elt_sz,index) ({ \
  struct _dyneither_ptr _cus_arr = (arr); \
  unsigned _cus_elt_sz = (elt_sz); \
  unsigned _cus_index = (index); \
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index; \
  if (!_cus_arr.base) _throw_null(); \
  if (_cus_ans < _cus_arr.base || _cus_ans >= _cus_arr.last_plus_one) \
    _throw_arraybounds(); \
  _cus_ans; })
#define _check_dynforward_subscript(arr,elt_sz,index) ({ \
  struct _dynforward_ptr _cus_arr = (arr); \
  unsigned _cus_elt_sz = (elt_sz); \
  unsigned _cus_index = (index); \
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index; \
  if (!_cus_arr.last_plus_one) _throw_null(); \
  if (_cus_ans >= _cus_arr.last_plus_one) \
    _throw_arraybounds(); \
  _cus_ans; })
#endif
#endif

#ifdef _INLINE_FUNCTIONS
static inline struct _dyneither_ptr
_tag_dyneither(const void *tcurr,unsigned elt_sz,unsigned num_elts) {
  struct _dyneither_ptr _tag_arr_ans;
  _tag_arr_ans.base = _tag_arr_ans.curr = (void*)(tcurr);
  _tag_arr_ans.last_plus_one = _tag_arr_ans.base + (elt_sz) * (num_elts);
  return _tag_arr_ans;
}
static inline struct _dynforward_ptr
_tag_dynforward(const void *tcurr,unsigned elt_sz,unsigned num_elts) {
  struct _dynforward_ptr _tag_arr_ans;
  _tag_arr_ans.curr = (void*)(tcurr);
  _tag_arr_ans.last_plus_one = _tag_arr_ans.curr + (elt_sz) * (num_elts);
  return _tag_arr_ans;
}
#else
#define _tag_dyneither(tcurr,elt_sz,num_elts) ({ \
  struct _dyneither_ptr _tag_arr_ans; \
  _tag_arr_ans.base = _tag_arr_ans.curr = (void*)(tcurr); \
  _tag_arr_ans.last_plus_one = _tag_arr_ans.base + (elt_sz) * (num_elts); \
  _tag_arr_ans; })
#define _tag_dynforward(tcurr,elt_sz,num_elts) ({ \
  struct _dynforward_ptr _tag_arr_ans; \
  _tag_arr_ans.curr = (void*)(tcurr); \
  _tag_arr_ans.last_plus_one = _tag_arr_ans.curr + (elt_sz) * (num_elts); \
  _tag_arr_ans; })
#endif

#ifdef _INLINE_FUNCTIONS
static inline struct _dyneither_ptr *
_init_dyneither_ptr(struct _dyneither_ptr *arr_ptr,
                    void *arr, unsigned elt_sz, unsigned num_elts) {
  struct _dyneither_ptr *_itarr_ptr = (arr_ptr);
  void* _itarr = (arr);
  _itarr_ptr->base = _itarr_ptr->curr = _itarr;
  _itarr_ptr->last_plus_one = ((char *)_itarr) + (elt_sz) * (num_elts);
  return _itarr_ptr;
}
static inline struct _dynforward_ptr *
_init_dynforward_ptr(struct _dynforward_ptr *arr_ptr,
                    void *arr, unsigned elt_sz, unsigned num_elts) {
  struct _dynforward_ptr *_itarr_ptr = (arr_ptr);
  void* _itarr = (arr);
  _itarr_ptr->curr = _itarr;
  _itarr_ptr->last_plus_one = ((char *)_itarr) + (elt_sz) * (num_elts);
  return _itarr_ptr;
}
#else
#define _init_dyneither_ptr(arr_ptr,arr,elt_sz,num_elts) ({ \
  struct _dyneither_ptr *_itarr_ptr = (arr_ptr); \
  void* _itarr = (arr); \
  _itarr_ptr->base = _itarr_ptr->curr = _itarr; \
  _itarr_ptr->last_plus_one = ((char *)_itarr) + (elt_sz) * (num_elts); \
  _itarr_ptr; })
#define _init_dynforward_ptr(arr_ptr,arr,elt_sz,num_elts) ({ \
  struct _dynforward_ptr *_itarr_ptr = (arr_ptr); \
  void* _itarr = (arr); \
  _itarr_ptr->curr = _itarr; \
  _itarr_ptr->last_plus_one = ((char *)_itarr) + (elt_sz) * (num_elts); \
  _itarr_ptr; })
#endif

#ifdef NO_CYC_BOUNDS_CHECKS
#define _untag_dynforward_ptr(arr,elt_sz,num_elts) ((arr).curr)
#define _untag_dyneither_ptr(arr,elt_sz,num_elts) ((arr).curr)
#else
#ifdef _INLINE_FUNCTIONS
static inline unsigned char *
_untag_dyneither_ptr(struct _dyneither_ptr arr, 
                     unsigned elt_sz,unsigned num_elts) {
  struct _dyneither_ptr _arr = (arr);
  unsigned char *_curr = _arr.curr;
  if (_curr < _arr.base || _curr + (elt_sz) * (num_elts) > _arr.last_plus_one)
    _throw_arraybounds();
  return _curr;
}
static inline unsigned char *
_untag_dynforward_ptr(struct _dynforward_ptr arr, 
                      unsigned elt_sz,unsigned num_elts) {
  struct _dynforward_ptr _arr = (arr);
  unsigned char *_curr = _arr.curr;
  if (_curr + (elt_sz) * (num_elts) > _arr.last_plus_one)
    _throw_arraybounds();
  return _curr;
}
#else
#define _untag_dyneither_ptr(arr,elt_sz,num_elts) ({ \
  struct _dyneither_ptr _arr = (arr); \
  unsigned char *_curr = _arr.curr; \
  if (_curr < _arr.base || _curr + (elt_sz) * (num_elts) > _arr.last_plus_one)\
    _throw_arraybounds(); \
  _curr; })
#define _untag_dynforward_ptr(arr,elt_sz,num_elts) ({ \
  struct _dynforward_ptr _arr = (arr); \
  unsigned char *_curr = _arr.curr; \
  if (_curr + (elt_sz) * (num_elts) > _arr.last_plus_one)\
    _throw_arraybounds(); \
  _curr; })
#endif
#endif

#ifdef _INLINE_FUNCTIONS
static inline unsigned
_get_dyneither_size(struct _dyneither_ptr arr,unsigned elt_sz) {
  struct _dyneither_ptr _get_arr_size_temp = (arr);
  unsigned char *_get_arr_size_curr=_get_arr_size_temp.curr;
  unsigned char *_get_arr_size_last=_get_arr_size_temp.last_plus_one;
  return (_get_arr_size_curr < _get_arr_size_temp.base ||
          _get_arr_size_curr >= _get_arr_size_last) ? 0 :
    ((_get_arr_size_last - _get_arr_size_curr) / (elt_sz));
}
static inline unsigned
_get_dynforward_size(struct _dynforward_ptr arr,unsigned elt_sz) {
  struct _dynforward_ptr _get_arr_size_temp = (arr);
  unsigned char *_get_arr_size_curr=_get_arr_size_temp.curr;
  unsigned char *_get_arr_size_last=_get_arr_size_temp.last_plus_one;
  return (_get_arr_size_curr >= _get_arr_size_last) ? 0 :
    ((_get_arr_size_last - _get_arr_size_curr) / (elt_sz));
}
#else
#define _get_dyneither_size(arr,elt_sz) \
  ({struct _dyneither_ptr _get_arr_size_temp = (arr); \
    unsigned char *_get_arr_size_curr=_get_arr_size_temp.curr; \
    unsigned char *_get_arr_size_last=_get_arr_size_temp.last_plus_one; \
    (_get_arr_size_curr < _get_arr_size_temp.base || \
     _get_arr_size_curr >= _get_arr_size_last) ? 0 : \
    ((_get_arr_size_last - _get_arr_size_curr) / (elt_sz));})
#define _get_dynforward_size(arr,elt_sz) \
  ({struct _dynforward_ptr _get_arr_size_temp = (arr); \
    unsigned char *_get_arr_size_curr=_get_arr_size_temp.curr; \
    unsigned char *_get_arr_size_last=_get_arr_size_temp.last_plus_one; \
    (_get_arr_size_curr >= _get_arr_size_last) ? 0 : \
    ((_get_arr_size_last - _get_arr_size_curr) / (elt_sz));})
#endif

#ifdef _INLINE_FUNCTIONS
static inline struct _dyneither_ptr
_dyneither_ptr_plus(struct _dyneither_ptr arr,unsigned elt_sz,int change) {
  struct _dyneither_ptr _ans = (arr);
  _ans.curr += ((int)(elt_sz))*(change);
  return _ans;
}
/* Here we have to worry about wrapping around, so if we go past the
 * end, we set the end to 0. */
static inline struct _dynforward_ptr
_dynforward_ptr_plus(struct _dynforward_ptr arr,unsigned elt_sz,int change) {
  struct _dynforward_ptr _ans = (arr);
  unsigned int _dfpp_elts = (((unsigned)_ans.last_plus_one) - 
                             ((unsigned)_ans.curr)) / elt_sz;
  if (change < 0 || ((unsigned)change) > _dfpp_elts)
    _ans.last_plus_one = 0;
  _ans.curr += ((int)(elt_sz))*(change);
  return _ans;
}
#else
#define _dyneither_ptr_plus(arr,elt_sz,change) ({ \
  struct _dyneither_ptr _ans = (arr); \
  _ans.curr += ((int)(elt_sz))*(change); \
  _ans; })
#define _dynforward_ptr_plus(arr,elt_sz,change) ({ \
  struct _dynforward_ptr _ans = (arr); \
  unsigned _dfpp_elt_sz = (elt_sz); \
  int _dfpp_change = (change); \
  unsigned int _dfpp_elts = (((unsigned)_ans.last_plus_one) - \
                            ((unsigned)_ans.curr)) / _dfpp_elt_sz; \
  if (_dfpp_change < 0 || ((unsigned)_dfpp_change) > _dfpp_elts) \
    _ans.last_plus_one = 0; \
  _ans.curr += ((int)(_dfpp_elt_sz))*(_dfpp_change); \
  _ans; })
#endif

#ifdef _INLINE_FUNCTIONS
static inline struct _dyneither_ptr
_dyneither_ptr_inplace_plus(struct _dyneither_ptr *arr_ptr,unsigned elt_sz,
                            int change) {
  struct _dyneither_ptr * _arr_ptr = (arr_ptr);
  _arr_ptr->curr += ((int)(elt_sz))*(change);
  return *_arr_ptr;
}
static inline struct _dynforward_ptr
_dynforward_ptr_inplace_plus(struct _dynforward_ptr *arr_ptr,unsigned elt_sz,
                             int change) {
  struct _dynforward_ptr * _arr_ptr = (arr_ptr);
  unsigned int _dfpp_elts = (((unsigned)_arr_ptr->last_plus_one) - 
                             ((unsigned)_arr_ptr->curr)) / elt_sz;
  if (change < 0 || ((unsigned)change) > _dfpp_elts) 
    _arr_ptr->last_plus_one = 0;
  _arr_ptr->curr += ((int)(elt_sz))*(change);
  return *_arr_ptr;
}
#else
#define _dyneither_ptr_inplace_plus(arr_ptr,elt_sz,change) ({ \
  struct _dyneither_ptr * _arr_ptr = (arr_ptr); \
  _arr_ptr->curr += ((int)(elt_sz))*(change); \
  *_arr_ptr; })
#define _dynforward_ptr_inplace_plus(arr_ptr,elt_sz,change) ({ \
  struct _dynforward_ptr * _arr_ptr = (arr_ptr); \
  unsigned _dfpp_elt_sz = (elt_sz); \
  int _dfpp_change = (change); \
  unsigned int _dfpp_elts = (((unsigned)_arr_ptr->last_plus_one) - \
                            ((unsigned)_arr_ptr->curr)) / _dfpp_elt_sz; \
  if (_dfpp_change < 0 || ((unsigned)_dfpp_change) > _dfpp_elts) \
    _arr_ptr->last_plus_one = 0; \
  _arr_ptr->curr += ((int)(_dfpp_elt_sz))*(_dfpp_change); \
  *_arr_ptr; })
#endif

#ifdef _INLINE_FUNCTIONS
static inline struct _dyneither_ptr
_dyneither_ptr_inplace_plus_post(struct _dyneither_ptr *arr_ptr,unsigned elt_sz,int change) {
  struct _dyneither_ptr * _arr_ptr = (arr_ptr);
  struct _dyneither_ptr _ans = *_arr_ptr;
  _arr_ptr->curr += ((int)(elt_sz))*(change);
  return _ans;
}
static inline struct _dynforward_ptr
_dynforward_ptr_inplace_plus_post(struct _dynforward_ptr *arr_ptr,unsigned elt_sz,int change) {
  struct _dynforward_ptr * _arr_ptr = (arr_ptr);
  struct _dynforward_ptr _ans = *_arr_ptr;
  unsigned int _dfpp_elts = (((unsigned)_arr_ptr->last_plus_one) - 
                            ((unsigned)_arr_ptr->curr)) / elt_sz; 
  if (change < 0 || ((unsigned)change) > _dfpp_elts) 
    _arr_ptr->last_plus_one = 0; 
  _arr_ptr->curr += ((int)(elt_sz))*(change);
  return _ans;
}
#else
#define _dyneither_ptr_inplace_plus_post(arr_ptr,elt_sz,change) ({ \
  struct _dyneither_ptr * _arr_ptr = (arr_ptr); \
  struct _dyneither_ptr _ans = *_arr_ptr; \
  _arr_ptr->curr += ((int)(elt_sz))*(change); \
  _ans; })
#define _dynforward_ptr_inplace_plus_post(arr_ptr,elt_sz,change) ({ \
  struct _dynforward_ptr * _arr_ptr = (arr_ptr); \
  struct _dynforward_ptr _ans = *_arr_ptr; \
  unsigned _dfpp_elt_sz = (elt_sz); \
  int _dfpp_change = (change); \
  unsigned int _dfpp_elts = (((unsigned)_arr_ptr->last_plus_one) - \
                            ((unsigned)_arr_ptr->curr)) / _dfpp_elt_sz; \
  if (_dfpp_change < 0 || ((unsigned)_dfpp_change) > _dfpp_elts) \
    _arr_ptr->last_plus_one = 0; \
  _arr_ptr->curr += ((int)(elt_sz))*(change); \
  _ans; })
#endif

// Decrease the upper bound on a fat pointer by numelts where sz is
// the size of the pointer's type.  Note that this can't be a macro
// if we're to get initializers right.
static struct 
_dyneither_ptr _dyneither_ptr_decrease_size(struct _dyneither_ptr x,
                                            unsigned int sz,
                                            unsigned int numelts) {
  x.last_plus_one -= sz * numelts; 
  return x; 
}
static struct 
_dynforward_ptr _dynforward_ptr_decrease_size(struct _dynforward_ptr x,
                                            unsigned int sz,
                                            unsigned int numelts) {
  if (x.last_plus_one != 0)
    x.last_plus_one -= sz * numelts; 
  return x; 
}

/* Convert between the two forms of dynamic pointers */
#ifdef _INLINE_FUNCTIONS 
static struct _dynforward_ptr
_dyneither_to_dynforward(struct _dyneither_ptr p) {
  struct _dynforward_ptr res;
  res.curr = p.curr;
  res.last_plus_one = (p.base == 0) ? 0 : p.last_plus_one;
  return res;
}
static struct _dyneither_ptr
_dynforward_to_dyneither(struct _dynforward_ptr p) {
  struct _dyneither_ptr res;
  res.base = res.curr = p.curr;
  res.last_plus_one = p.last_plus_one;
  if (p.last_plus_one == 0) 
    res.base = 0;
  return res;
}
#else 
#define _dyneither_to_dynforward(_dnfptr) ({ \
  struct _dyneither_ptr _dnfp = (_dnfptr); \
  struct _dynforward_ptr _dnfpres; \
  _dnfpres.curr = _dnfp.curr; \
  _dnfpres.last_plus_one = (_dnfp.base == 0) ? 0 : _dnfp.last_plus_one; \
  _dnfpres; })
#define _dynforward_to_dyneither(_dfnptr) ({ \
  struct _dynforward_ptr _dfnp = (_dfnptr); \
  struct _dyneither_ptr _dfnres; \
  _dfnres.base = _dfnres.curr = _dfnp.curr; \
  _dfnres.last_plus_one = _dfnp.last_plus_one; \
  if (_dfnp.last_plus_one == 0) \
    _dfnres.base = 0; \
  _dfnres; })
#endif 


//// Allocation
extern void* GC_malloc(int);
extern void* GC_malloc_atomic(int);
extern void* GC_calloc(unsigned,unsigned);
extern void* GC_calloc_atomic(unsigned,unsigned);

static inline void* _cycalloc(int n) {
  void * ans = (void *)GC_malloc(n);
  if(!ans)
    _throw_badalloc();
  return ans;
}
static inline void* _cycalloc_atomic(int n) {
  void * ans = (void *)GC_malloc_atomic(n);
  if(!ans)
    _throw_badalloc();
  return ans;
}
static inline void* _cyccalloc(unsigned n, unsigned s) {
  void* ans = (void*)GC_calloc(n,s);
  if (!ans)
    _throw_badalloc();
  return ans;
}
static inline void* _cyccalloc_atomic(unsigned n, unsigned s) {
  void* ans = (void*)GC_calloc_atomic(n,s);
  if (!ans)
    _throw_badalloc();
  return ans;
}
#define MAX_MALLOC_SIZE (1 << 28)
static inline unsigned int _check_times(unsigned x, unsigned y) {
  unsigned long long whole_ans = 
    ((unsigned long long)x)*((unsigned long long)y);
  unsigned word_ans = (unsigned)whole_ans;
  if(word_ans < whole_ans || word_ans > MAX_MALLOC_SIZE)
    _throw_badalloc();
  return word_ans;
}

#if defined(CYC_REGION_PROFILE) 
extern void* _profile_GC_malloc(int,char *file,int lineno);
extern void* _profile_GC_malloc_atomic(int,char *file,int lineno);
extern void* _profile_region_malloc(struct _RegionHandle *, unsigned,
                                     char *file,int lineno);
extern struct _RegionHandle _profile_new_region(const char *rgn_name,
						char *file,int lineno);
extern void _profile_free_region(struct _RegionHandle *,
				 char *file,int lineno);
#  if !defined(RUNTIME_CYC)
#define _new_region(n) _profile_new_region(n,__FILE__ ":" __FUNCTION__,__LINE__)
#define _free_region(r) _profile_free_region(r,__FILE__ ":" __FUNCTION__,__LINE__)
#define _region_malloc(rh,n) _profile_region_malloc(rh,n,__FILE__ ":" __FUNCTION__,__LINE__)
#  endif
#define _cycalloc(n) _profile_GC_malloc(n,__FILE__ ":" __FUNCTION__,__LINE__)
#define _cycalloc_atomic(n) _profile_GC_malloc_atomic(n,__FILE__ ":" __FUNCTION__,__LINE__)
#endif
#endif
 void exit(int);void*abort();struct Cyc_Core_Opt{void*v;};extern char Cyc_Core_Invalid_argument[
21];struct Cyc_Core_Invalid_argument_struct{char*tag;struct _dynforward_ptr f1;};
extern char Cyc_Core_Failure[12];struct Cyc_Core_Failure_struct{char*tag;struct
_dynforward_ptr f1;};extern char Cyc_Core_Impossible[15];struct Cyc_Core_Impossible_struct{
char*tag;struct _dynforward_ptr f1;};extern char Cyc_Core_Not_found[14];extern char
Cyc_Core_Unreachable[16];struct Cyc_Core_Unreachable_struct{char*tag;struct
_dynforward_ptr f1;};extern struct _RegionHandle*Cyc_Core_heap_region;struct
_dynforward_ptr Cstring_to_string(char*);struct Cyc___cycFILE;extern struct Cyc___cycFILE*
Cyc_stderr;struct Cyc_Cstdio___abstractFILE;struct Cyc_String_pa_struct{int tag;
struct _dynforward_ptr f1;};struct Cyc_Int_pa_struct{int tag;unsigned long f1;};
struct Cyc_Double_pa_struct{int tag;double f1;};struct Cyc_LongDouble_pa_struct{int
tag;long double f1;};struct Cyc_ShortPtr_pa_struct{int tag;short*f1;};struct Cyc_IntPtr_pa_struct{
int tag;unsigned long*f1;};struct _dynforward_ptr Cyc_aprintf(struct _dynforward_ptr,
struct _dynforward_ptr);int Cyc_fclose(struct Cyc___cycFILE*);int Cyc_fflush(struct
Cyc___cycFILE*);struct Cyc___cycFILE*Cyc_fopen(const char*,const char*);int Cyc_fprintf(
struct Cyc___cycFILE*,struct _dynforward_ptr,struct _dynforward_ptr);int Cyc_fputc(
int,struct Cyc___cycFILE*);int Cyc_fputs(const char*,struct Cyc___cycFILE*);struct
Cyc_ShortPtr_sa_struct{int tag;short*f1;};struct Cyc_UShortPtr_sa_struct{int tag;
unsigned short*f1;};struct Cyc_IntPtr_sa_struct{int tag;int*f1;};struct Cyc_UIntPtr_sa_struct{
int tag;unsigned int*f1;};struct Cyc_StringPtr_sa_struct{int tag;struct
_dynforward_ptr f1;};struct Cyc_DoublePtr_sa_struct{int tag;double*f1;};struct Cyc_FloatPtr_sa_struct{
int tag;float*f1;};struct Cyc_CharPtr_sa_struct{int tag;struct _dynforward_ptr f1;};
int remove(const char*);int Cyc_vfprintf(struct Cyc___cycFILE*,struct _dynforward_ptr,
struct _dynforward_ptr);extern char Cyc_FileCloseError[19];extern char Cyc_FileOpenError[
18];struct Cyc_FileOpenError_struct{char*tag;struct _dynforward_ptr f1;};extern char
Cyc_Lexing_Error[10];struct Cyc_Lexing_Error_struct{char*tag;struct
_dynforward_ptr f1;};struct Cyc_Lexing_lexbuf{void(*refill_buff)(struct Cyc_Lexing_lexbuf*);
void*refill_state;struct _dynforward_ptr lex_buffer;int lex_buffer_len;int
lex_abs_pos;int lex_start_pos;int lex_curr_pos;int lex_last_pos;int lex_last_action;
int lex_eof_reached;};struct Cyc_Lexing_function_lexbuf_state{int(*read_fun)(
struct _dynforward_ptr,int,void*);void*read_fun_state;};struct Cyc_Lexing_lex_tables{
struct _dynforward_ptr lex_base;struct _dynforward_ptr lex_backtrk;struct
_dynforward_ptr lex_default;struct _dynforward_ptr lex_trans;struct _dynforward_ptr
lex_check;};struct Cyc_Lexing_lexbuf*Cyc_Lexing_from_file(struct Cyc___cycFILE*);
struct _dynforward_ptr Cyc_Lexing_lexeme(struct Cyc_Lexing_lexbuf*);char Cyc_Lexing_lexeme_char(
struct Cyc_Lexing_lexbuf*,int);int Cyc_Lexing_lexeme_start(struct Cyc_Lexing_lexbuf*);
int Cyc_Lexing_lexeme_end(struct Cyc_Lexing_lexbuf*);struct Cyc_List_List{void*hd;
struct Cyc_List_List*tl;};struct Cyc_List_List*Cyc_List_list(struct _dynforward_ptr);
extern char Cyc_List_List_mismatch[18];void Cyc_List_iter(void(*f)(void*),struct Cyc_List_List*
x);struct Cyc_List_List*Cyc_List_imp_rev(struct Cyc_List_List*x);struct Cyc_List_List*
Cyc_List_append(struct Cyc_List_List*x,struct Cyc_List_List*y);extern char Cyc_List_Nth[
8];int Cyc_List_mem(int(*compare)(void*,void*),struct Cyc_List_List*l,void*x);
struct Cyc_Iter_Iter{void*env;int(*next)(void*env,void*dest);};int Cyc_Iter_next(
struct Cyc_Iter_Iter,void*);struct Cyc_Set_Set;struct Cyc_Set_Set*Cyc_Set_empty(int(*
cmp)(void*,void*));struct Cyc_Set_Set*Cyc_Set_insert(struct Cyc_Set_Set*s,void*elt);
struct Cyc_Set_Set*Cyc_Set_union_two(struct Cyc_Set_Set*s1,struct Cyc_Set_Set*s2);
struct Cyc_Set_Set*Cyc_Set_diff(struct Cyc_Set_Set*s1,struct Cyc_Set_Set*s2);struct
Cyc_Set_Set*Cyc_Set_delete(struct Cyc_Set_Set*s,void*elt);int Cyc_Set_cardinality(
struct Cyc_Set_Set*s);int Cyc_Set_member(struct Cyc_Set_Set*s,void*elt);extern char
Cyc_Set_Absent[11];struct Cyc_Iter_Iter Cyc_Set_make_iter(struct _RegionHandle*rgn,
struct Cyc_Set_Set*s);unsigned int Cyc_strlen(struct _dynforward_ptr s);int Cyc_strptrcmp(
struct _dynforward_ptr*s1,struct _dynforward_ptr*s2);struct _dynforward_ptr Cyc_strconcat(
struct _dynforward_ptr,struct _dynforward_ptr);struct _dynforward_ptr Cyc_strdup(
struct _dynforward_ptr src);struct _dynforward_ptr Cyc_substring(struct
_dynforward_ptr,int ofs,unsigned int n);struct Cyc_Hashtable_Table;struct Cyc_Hashtable_Table*
Cyc_Hashtable_create(int sz,int(*cmp)(void*,void*),int(*hash)(void*));void Cyc_Hashtable_insert(
struct Cyc_Hashtable_Table*t,void*key,void*val);void*Cyc_Hashtable_lookup(struct
Cyc_Hashtable_Table*t,void*key);int Cyc_Hashtable_hash_stringptr(struct
_dynforward_ptr*p);struct _dynforward_ptr Cyc_Filename_concat(struct
_dynforward_ptr,struct _dynforward_ptr);struct _dynforward_ptr Cyc_Filename_chop_extension(
struct _dynforward_ptr);struct _dynforward_ptr Cyc_Filename_dirname(struct
_dynforward_ptr);struct _dynforward_ptr Cyc_Filename_basename(struct
_dynforward_ptr);struct Cyc_Lineno_Pos{struct _dynforward_ptr logical_file;struct
_dynforward_ptr line;int line_no;int col;};extern char Cyc_Position_Exit[9];void Cyc_Position_reset_position(
struct _dynforward_ptr);struct Cyc_Position_Segment;struct Cyc_Position_Error{
struct _dynforward_ptr source;struct Cyc_Position_Segment*seg;void*kind;struct
_dynforward_ptr desc;};extern char Cyc_Position_Nocontext[14];extern char Cyc_Arg_Bad[
8];struct Cyc_Arg_Bad_struct{char*tag;struct _dynforward_ptr f1;};extern char Cyc_Arg_Error[
10];struct Cyc_Arg_Unit_spec_struct{int tag;void(*f1)();};struct Cyc_Arg_Flag_spec_struct{
int tag;void(*f1)(struct _dynforward_ptr);};struct Cyc_Arg_FlagString_spec_struct{
int tag;void(*f1)(struct _dynforward_ptr,struct _dynforward_ptr);};struct Cyc_Arg_Set_spec_struct{
int tag;int*f1;};struct Cyc_Arg_Clear_spec_struct{int tag;int*f1;};struct Cyc_Arg_String_spec_struct{
int tag;void(*f1)(struct _dynforward_ptr);};struct Cyc_Arg_Int_spec_struct{int tag;
void(*f1)(int);};struct Cyc_Arg_Rest_spec_struct{int tag;void(*f1)(struct
_dynforward_ptr);};void Cyc_Arg_usage(struct Cyc_List_List*,struct _dynforward_ptr);
void Cyc_Arg_parse(struct Cyc_List_List*specs,void(*anonfun)(struct _dynforward_ptr),
struct _dynforward_ptr errmsg,struct _dynforward_ptr args);struct Cyc_Buffer_t;struct
Cyc_Buffer_t*Cyc_Buffer_create(unsigned int n);struct _dynforward_ptr Cyc_Buffer_contents(
struct Cyc_Buffer_t*);void Cyc_Buffer_add_char(struct Cyc_Buffer_t*,char);void Cyc_Buffer_add_string(
struct Cyc_Buffer_t*,struct _dynforward_ptr);struct Cyc_Absyn_Rel_n_struct{int tag;
struct Cyc_List_List*f1;};struct Cyc_Absyn_Abs_n_struct{int tag;struct Cyc_List_List*
f1;};struct _tuple0{void*f1;struct _dynforward_ptr*f2;};struct Cyc_Absyn_Conref;
struct Cyc_Absyn_Tqual{int print_const;int q_volatile;int q_restrict;int real_const;
struct Cyc_Position_Segment*loc;};struct Cyc_Absyn_Conref{void*v;};struct Cyc_Absyn_Eq_constr_struct{
int tag;void*f1;};struct Cyc_Absyn_Forward_constr_struct{int tag;struct Cyc_Absyn_Conref*
f1;};struct Cyc_Absyn_Eq_kb_struct{int tag;void*f1;};struct Cyc_Absyn_Unknown_kb_struct{
int tag;struct Cyc_Core_Opt*f1;};struct Cyc_Absyn_Less_kb_struct{int tag;struct Cyc_Core_Opt*
f1;void*f2;};struct Cyc_Absyn_Tvar{struct _dynforward_ptr*name;int*identity;void*
kind;};struct Cyc_Absyn_Upper_b_struct{int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_AbsUpper_b_struct{
int tag;void*f1;};struct Cyc_Absyn_PtrLoc{struct Cyc_Position_Segment*ptr_loc;
struct Cyc_Position_Segment*rgn_loc;struct Cyc_Position_Segment*zt_loc;};struct Cyc_Absyn_PtrAtts{
void*rgn;struct Cyc_Absyn_Conref*nullable;struct Cyc_Absyn_Conref*bounds;struct Cyc_Absyn_Conref*
zero_term;struct Cyc_Absyn_PtrLoc*ptrloc;};struct Cyc_Absyn_PtrInfo{void*elt_typ;
struct Cyc_Absyn_Tqual elt_tq;struct Cyc_Absyn_PtrAtts ptr_atts;};struct Cyc_Absyn_VarargInfo{
struct Cyc_Core_Opt*name;struct Cyc_Absyn_Tqual tq;void*type;int inject;};struct Cyc_Absyn_FnInfo{
struct Cyc_List_List*tvars;struct Cyc_Core_Opt*effect;void*ret_typ;struct Cyc_List_List*
args;int c_varargs;struct Cyc_Absyn_VarargInfo*cyc_varargs;struct Cyc_List_List*
rgn_po;struct Cyc_List_List*attributes;};struct Cyc_Absyn_UnknownTunionInfo{struct
_tuple0*name;int is_xtunion;};struct Cyc_Absyn_UnknownTunion_struct{int tag;struct
Cyc_Absyn_UnknownTunionInfo f1;};struct Cyc_Absyn_KnownTunion_struct{int tag;struct
Cyc_Absyn_Tuniondecl**f1;};struct Cyc_Absyn_TunionInfo{void*tunion_info;struct Cyc_List_List*
targs;void*rgn;};struct Cyc_Absyn_UnknownTunionFieldInfo{struct _tuple0*
tunion_name;struct _tuple0*field_name;int is_xtunion;};struct Cyc_Absyn_UnknownTunionfield_struct{
int tag;struct Cyc_Absyn_UnknownTunionFieldInfo f1;};struct Cyc_Absyn_KnownTunionfield_struct{
int tag;struct Cyc_Absyn_Tuniondecl*f1;struct Cyc_Absyn_Tunionfield*f2;};struct Cyc_Absyn_TunionFieldInfo{
void*field_info;struct Cyc_List_List*targs;};struct Cyc_Absyn_UnknownAggr_struct{
int tag;void*f1;struct _tuple0*f2;};struct Cyc_Absyn_KnownAggr_struct{int tag;struct
Cyc_Absyn_Aggrdecl**f1;};struct Cyc_Absyn_AggrInfo{void*aggr_info;struct Cyc_List_List*
targs;};struct Cyc_Absyn_ArrayInfo{void*elt_type;struct Cyc_Absyn_Tqual tq;struct
Cyc_Absyn_Exp*num_elts;struct Cyc_Absyn_Conref*zero_term;struct Cyc_Position_Segment*
zt_loc;};struct Cyc_Absyn_Evar_struct{int tag;struct Cyc_Core_Opt*f1;struct Cyc_Core_Opt*
f2;int f3;struct Cyc_Core_Opt*f4;};struct Cyc_Absyn_VarType_struct{int tag;struct Cyc_Absyn_Tvar*
f1;};struct Cyc_Absyn_TunionType_struct{int tag;struct Cyc_Absyn_TunionInfo f1;};
struct Cyc_Absyn_TunionFieldType_struct{int tag;struct Cyc_Absyn_TunionFieldInfo f1;
};struct Cyc_Absyn_PointerType_struct{int tag;struct Cyc_Absyn_PtrInfo f1;};struct
Cyc_Absyn_IntType_struct{int tag;void*f1;void*f2;};struct Cyc_Absyn_DoubleType_struct{
int tag;int f1;};struct Cyc_Absyn_ArrayType_struct{int tag;struct Cyc_Absyn_ArrayInfo
f1;};struct Cyc_Absyn_FnType_struct{int tag;struct Cyc_Absyn_FnInfo f1;};struct Cyc_Absyn_TupleType_struct{
int tag;struct Cyc_List_List*f1;};struct Cyc_Absyn_AggrType_struct{int tag;struct Cyc_Absyn_AggrInfo
f1;};struct Cyc_Absyn_AnonAggrType_struct{int tag;void*f1;struct Cyc_List_List*f2;}
;struct Cyc_Absyn_EnumType_struct{int tag;struct _tuple0*f1;struct Cyc_Absyn_Enumdecl*
f2;};struct Cyc_Absyn_AnonEnumType_struct{int tag;struct Cyc_List_List*f1;};struct
Cyc_Absyn_SizeofType_struct{int tag;void*f1;};struct Cyc_Absyn_RgnHandleType_struct{
int tag;void*f1;};struct Cyc_Absyn_TypedefType_struct{int tag;struct _tuple0*f1;
struct Cyc_List_List*f2;struct Cyc_Absyn_Typedefdecl*f3;void**f4;};struct Cyc_Absyn_TagType_struct{
int tag;void*f1;};struct Cyc_Absyn_TypeInt_struct{int tag;int f1;};struct Cyc_Absyn_AccessEff_struct{
int tag;void*f1;};struct Cyc_Absyn_JoinEff_struct{int tag;struct Cyc_List_List*f1;};
struct Cyc_Absyn_RgnsEff_struct{int tag;void*f1;};struct Cyc_Absyn_NoTypes_struct{
int tag;struct Cyc_List_List*f1;struct Cyc_Position_Segment*f2;};struct Cyc_Absyn_WithTypes_struct{
int tag;struct Cyc_List_List*f1;int f2;struct Cyc_Absyn_VarargInfo*f3;struct Cyc_Core_Opt*
f4;struct Cyc_List_List*f5;};struct Cyc_Absyn_Regparm_att_struct{int tag;int f1;};
struct Cyc_Absyn_Aligned_att_struct{int tag;int f1;};struct Cyc_Absyn_Section_att_struct{
int tag;struct _dynforward_ptr f1;};struct Cyc_Absyn_Format_att_struct{int tag;void*
f1;int f2;int f3;};struct Cyc_Absyn_Initializes_att_struct{int tag;int f1;};struct Cyc_Absyn_Mode_att_struct{
int tag;struct _dynforward_ptr f1;};struct Cyc_Absyn_Carray_mod_struct{int tag;struct
Cyc_Absyn_Conref*f1;struct Cyc_Position_Segment*f2;};struct Cyc_Absyn_ConstArray_mod_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Conref*f2;struct Cyc_Position_Segment*
f3;};struct Cyc_Absyn_Pointer_mod_struct{int tag;struct Cyc_Absyn_PtrAtts f1;struct
Cyc_Absyn_Tqual f2;};struct Cyc_Absyn_Function_mod_struct{int tag;void*f1;};struct
Cyc_Absyn_TypeParams_mod_struct{int tag;struct Cyc_List_List*f1;struct Cyc_Position_Segment*
f2;int f3;};struct Cyc_Absyn_Attributes_mod_struct{int tag;struct Cyc_Position_Segment*
f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_Char_c_struct{int tag;void*f1;char f2;
};struct Cyc_Absyn_Short_c_struct{int tag;void*f1;short f2;};struct Cyc_Absyn_Int_c_struct{
int tag;void*f1;int f2;};struct Cyc_Absyn_LongLong_c_struct{int tag;void*f1;
long long f2;};struct Cyc_Absyn_Float_c_struct{int tag;struct _dynforward_ptr f1;};
struct Cyc_Absyn_String_c_struct{int tag;struct _dynforward_ptr f1;};struct Cyc_Absyn_VarargCallInfo{
int num_varargs;struct Cyc_List_List*injectors;struct Cyc_Absyn_VarargInfo*vai;};
struct Cyc_Absyn_StructField_struct{int tag;struct _dynforward_ptr*f1;};struct Cyc_Absyn_TupleIndex_struct{
int tag;unsigned int f1;};struct Cyc_Absyn_MallocInfo{int is_calloc;struct Cyc_Absyn_Exp*
rgn;void**elt_type;struct Cyc_Absyn_Exp*num_elts;int fat_result;};struct Cyc_Absyn_Const_e_struct{
int tag;void*f1;};struct Cyc_Absyn_Var_e_struct{int tag;struct _tuple0*f1;void*f2;};
struct Cyc_Absyn_UnknownId_e_struct{int tag;struct _tuple0*f1;};struct Cyc_Absyn_Primop_e_struct{
int tag;void*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_AssignOp_e_struct{int tag;
struct Cyc_Absyn_Exp*f1;struct Cyc_Core_Opt*f2;struct Cyc_Absyn_Exp*f3;};struct Cyc_Absyn_Increment_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;void*f2;};struct Cyc_Absyn_Conditional_e_struct{int
tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;struct Cyc_Absyn_Exp*f3;};
struct Cyc_Absyn_And_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*
f2;};struct Cyc_Absyn_Or_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*
f2;};struct Cyc_Absyn_SeqExp_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*
f2;};struct Cyc_Absyn_UnknownCall_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct
Cyc_List_List*f2;};struct Cyc_Absyn_FnCall_e_struct{int tag;struct Cyc_Absyn_Exp*f1;
struct Cyc_List_List*f2;struct Cyc_Absyn_VarargCallInfo*f3;};struct Cyc_Absyn_Throw_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_NoInstantiate_e_struct{int tag;
struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Instantiate_e_struct{int tag;struct Cyc_Absyn_Exp*
f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_Cast_e_struct{int tag;void*f1;struct
Cyc_Absyn_Exp*f2;int f3;void*f4;};struct Cyc_Absyn_Address_e_struct{int tag;struct
Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_New_e_struct{int tag;struct Cyc_Absyn_Exp*f1;
struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_Sizeoftyp_e_struct{int tag;void*f1;};
struct Cyc_Absyn_Sizeofexp_e_struct{int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Offsetof_e_struct{
int tag;void*f1;void*f2;};struct Cyc_Absyn_Gentyp_e_struct{int tag;struct Cyc_List_List*
f1;void*f2;};struct Cyc_Absyn_Deref_e_struct{int tag;struct Cyc_Absyn_Exp*f1;};
struct Cyc_Absyn_AggrMember_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct
_dynforward_ptr*f2;};struct Cyc_Absyn_AggrArrow_e_struct{int tag;struct Cyc_Absyn_Exp*
f1;struct _dynforward_ptr*f2;};struct Cyc_Absyn_Subscript_e_struct{int tag;struct
Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_Tuple_e_struct{int tag;
struct Cyc_List_List*f1;};struct _tuple1{struct Cyc_Core_Opt*f1;struct Cyc_Absyn_Tqual
f2;void*f3;};struct Cyc_Absyn_CompoundLit_e_struct{int tag;struct _tuple1*f1;struct
Cyc_List_List*f2;};struct Cyc_Absyn_Array_e_struct{int tag;struct Cyc_List_List*f1;
};struct Cyc_Absyn_Comprehension_e_struct{int tag;struct Cyc_Absyn_Vardecl*f1;
struct Cyc_Absyn_Exp*f2;struct Cyc_Absyn_Exp*f3;int f4;};struct Cyc_Absyn_Struct_e_struct{
int tag;struct _tuple0*f1;struct Cyc_List_List*f2;struct Cyc_List_List*f3;struct Cyc_Absyn_Aggrdecl*
f4;};struct Cyc_Absyn_AnonStruct_e_struct{int tag;void*f1;struct Cyc_List_List*f2;}
;struct Cyc_Absyn_Tunion_e_struct{int tag;struct Cyc_List_List*f1;struct Cyc_Absyn_Tuniondecl*
f2;struct Cyc_Absyn_Tunionfield*f3;};struct Cyc_Absyn_Enum_e_struct{int tag;struct
_tuple0*f1;struct Cyc_Absyn_Enumdecl*f2;struct Cyc_Absyn_Enumfield*f3;};struct Cyc_Absyn_AnonEnum_e_struct{
int tag;struct _tuple0*f1;void*f2;struct Cyc_Absyn_Enumfield*f3;};struct Cyc_Absyn_Malloc_e_struct{
int tag;struct Cyc_Absyn_MallocInfo f1;};struct Cyc_Absyn_UnresolvedMem_e_struct{int
tag;struct Cyc_Core_Opt*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_StmtExp_e_struct{
int tag;struct Cyc_Absyn_Stmt*f1;};struct Cyc_Absyn_Exp{struct Cyc_Core_Opt*topt;
void*r;struct Cyc_Position_Segment*loc;void*annot;};struct Cyc_Absyn_Exp_s_struct{
int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Seq_s_struct{int tag;struct Cyc_Absyn_Stmt*
f1;struct Cyc_Absyn_Stmt*f2;};struct Cyc_Absyn_Return_s_struct{int tag;struct Cyc_Absyn_Exp*
f1;};struct Cyc_Absyn_IfThenElse_s_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Stmt*
f2;struct Cyc_Absyn_Stmt*f3;};struct _tuple2{struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_While_s_struct{int tag;struct _tuple2 f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_Break_s_struct{int tag;struct Cyc_Absyn_Stmt*f1;};struct Cyc_Absyn_Continue_s_struct{
int tag;struct Cyc_Absyn_Stmt*f1;};struct Cyc_Absyn_Goto_s_struct{int tag;struct
_dynforward_ptr*f1;struct Cyc_Absyn_Stmt*f2;};struct Cyc_Absyn_For_s_struct{int tag;
struct Cyc_Absyn_Exp*f1;struct _tuple2 f2;struct _tuple2 f3;struct Cyc_Absyn_Stmt*f4;}
;struct Cyc_Absyn_Switch_s_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_List_List*
f2;};struct Cyc_Absyn_Fallthru_s_struct{int tag;struct Cyc_List_List*f1;struct Cyc_Absyn_Switch_clause**
f2;};struct Cyc_Absyn_Decl_s_struct{int tag;struct Cyc_Absyn_Decl*f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_Label_s_struct{int tag;struct _dynforward_ptr*f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_Do_s_struct{int tag;struct Cyc_Absyn_Stmt*f1;struct _tuple2 f2;
};struct Cyc_Absyn_TryCatch_s_struct{int tag;struct Cyc_Absyn_Stmt*f1;struct Cyc_List_List*
f2;};struct Cyc_Absyn_Region_s_struct{int tag;struct Cyc_Absyn_Tvar*f1;struct Cyc_Absyn_Vardecl*
f2;int f3;struct Cyc_Absyn_Stmt*f4;};struct Cyc_Absyn_ResetRegion_s_struct{int tag;
struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Stmt{void*r;struct Cyc_Position_Segment*
loc;struct Cyc_List_List*non_local_preds;int try_depth;void*annot;};struct Cyc_Absyn_Var_p_struct{
int tag;struct Cyc_Absyn_Vardecl*f1;struct Cyc_Absyn_Pat*f2;};struct Cyc_Absyn_Reference_p_struct{
int tag;struct Cyc_Absyn_Vardecl*f1;struct Cyc_Absyn_Pat*f2;};struct Cyc_Absyn_TagInt_p_struct{
int tag;struct Cyc_Absyn_Tvar*f1;struct Cyc_Absyn_Vardecl*f2;};struct Cyc_Absyn_Tuple_p_struct{
int tag;struct Cyc_List_List*f1;int f2;};struct Cyc_Absyn_Pointer_p_struct{int tag;
struct Cyc_Absyn_Pat*f1;};struct Cyc_Absyn_Aggr_p_struct{int tag;struct Cyc_Absyn_AggrInfo
f1;struct Cyc_List_List*f2;struct Cyc_List_List*f3;int f4;};struct Cyc_Absyn_Tunion_p_struct{
int tag;struct Cyc_Absyn_Tuniondecl*f1;struct Cyc_Absyn_Tunionfield*f2;struct Cyc_List_List*
f3;int f4;};struct Cyc_Absyn_Int_p_struct{int tag;void*f1;int f2;};struct Cyc_Absyn_Char_p_struct{
int tag;char f1;};struct Cyc_Absyn_Float_p_struct{int tag;struct _dynforward_ptr f1;};
struct Cyc_Absyn_Enum_p_struct{int tag;struct Cyc_Absyn_Enumdecl*f1;struct Cyc_Absyn_Enumfield*
f2;};struct Cyc_Absyn_AnonEnum_p_struct{int tag;void*f1;struct Cyc_Absyn_Enumfield*
f2;};struct Cyc_Absyn_UnknownId_p_struct{int tag;struct _tuple0*f1;};struct Cyc_Absyn_UnknownCall_p_struct{
int tag;struct _tuple0*f1;struct Cyc_List_List*f2;int f3;};struct Cyc_Absyn_Exp_p_struct{
int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Pat{void*r;struct Cyc_Core_Opt*
topt;struct Cyc_Position_Segment*loc;};struct Cyc_Absyn_Switch_clause{struct Cyc_Absyn_Pat*
pattern;struct Cyc_Core_Opt*pat_vars;struct Cyc_Absyn_Exp*where_clause;struct Cyc_Absyn_Stmt*
body;struct Cyc_Position_Segment*loc;};struct Cyc_Absyn_Global_b_struct{int tag;
struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Funname_b_struct{int tag;struct Cyc_Absyn_Fndecl*
f1;};struct Cyc_Absyn_Param_b_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct
Cyc_Absyn_Local_b_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Pat_b_struct{
int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Vardecl{void*sc;struct
_tuple0*name;struct Cyc_Absyn_Tqual tq;void*type;struct Cyc_Absyn_Exp*initializer;
struct Cyc_Core_Opt*rgn;struct Cyc_List_List*attributes;int escapes;};struct Cyc_Absyn_Fndecl{
void*sc;int is_inline;struct _tuple0*name;struct Cyc_List_List*tvs;struct Cyc_Core_Opt*
effect;void*ret_type;struct Cyc_List_List*args;int c_varargs;struct Cyc_Absyn_VarargInfo*
cyc_varargs;struct Cyc_List_List*rgn_po;struct Cyc_Absyn_Stmt*body;struct Cyc_Core_Opt*
cached_typ;struct Cyc_Core_Opt*param_vardecls;struct Cyc_Absyn_Vardecl*fn_vardecl;
struct Cyc_List_List*attributes;};struct Cyc_Absyn_Aggrfield{struct _dynforward_ptr*
name;struct Cyc_Absyn_Tqual tq;void*type;struct Cyc_Absyn_Exp*width;struct Cyc_List_List*
attributes;};struct Cyc_Absyn_AggrdeclImpl{struct Cyc_List_List*exist_vars;struct
Cyc_List_List*rgn_po;struct Cyc_List_List*fields;};struct Cyc_Absyn_Aggrdecl{void*
kind;void*sc;struct _tuple0*name;struct Cyc_List_List*tvs;struct Cyc_Absyn_AggrdeclImpl*
impl;struct Cyc_List_List*attributes;};struct Cyc_Absyn_Tunionfield{struct _tuple0*
name;struct Cyc_List_List*typs;struct Cyc_Position_Segment*loc;void*sc;};struct Cyc_Absyn_Tuniondecl{
void*sc;struct _tuple0*name;struct Cyc_List_List*tvs;struct Cyc_Core_Opt*fields;int
is_xtunion;};struct Cyc_Absyn_Enumfield{struct _tuple0*name;struct Cyc_Absyn_Exp*
tag;struct Cyc_Position_Segment*loc;};struct Cyc_Absyn_Enumdecl{void*sc;struct
_tuple0*name;struct Cyc_Core_Opt*fields;};struct Cyc_Absyn_Typedefdecl{struct
_tuple0*name;struct Cyc_Absyn_Tqual tq;struct Cyc_List_List*tvs;struct Cyc_Core_Opt*
kind;struct Cyc_Core_Opt*defn;struct Cyc_List_List*atts;};struct Cyc_Absyn_Var_d_struct{
int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Fn_d_struct{int tag;struct Cyc_Absyn_Fndecl*
f1;};struct Cyc_Absyn_Let_d_struct{int tag;struct Cyc_Absyn_Pat*f1;struct Cyc_Core_Opt*
f2;struct Cyc_Absyn_Exp*f3;};struct Cyc_Absyn_Letv_d_struct{int tag;struct Cyc_List_List*
f1;};struct Cyc_Absyn_Aggr_d_struct{int tag;struct Cyc_Absyn_Aggrdecl*f1;};struct
Cyc_Absyn_Tunion_d_struct{int tag;struct Cyc_Absyn_Tuniondecl*f1;};struct Cyc_Absyn_Enum_d_struct{
int tag;struct Cyc_Absyn_Enumdecl*f1;};struct Cyc_Absyn_Typedef_d_struct{int tag;
struct Cyc_Absyn_Typedefdecl*f1;};struct Cyc_Absyn_Namespace_d_struct{int tag;
struct _dynforward_ptr*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_Using_d_struct{
int tag;struct _tuple0*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_ExternC_d_struct{
int tag;struct Cyc_List_List*f1;};struct Cyc_Absyn_ExternCinclude_d_struct{int tag;
struct Cyc_List_List*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_Decl{void*r;
struct Cyc_Position_Segment*loc;};struct Cyc_Absyn_ArrayElement_struct{int tag;
struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_FieldName_struct{int tag;struct
_dynforward_ptr*f1;};extern char Cyc_Absyn_EmptyAnnot[15];struct _tuple3{void*f1;
struct _tuple0*f2;};struct _tuple3 Cyc_Absyn_aggr_kinded_name(void*);void Cyc_Absyn_print_decls(
struct Cyc_List_List*);struct Cyc_PP_Ppstate;struct Cyc_PP_Out;struct Cyc_PP_Doc;
struct Cyc_Absynpp_Params{int expand_typedefs: 1;int qvar_to_Cids: 1;int
add_cyc_prefix: 1;int to_VC: 1;int decls_first: 1;int rewrite_temp_tvars: 1;int
print_all_tvars: 1;int print_all_kinds: 1;int print_all_effects: 1;int
print_using_stmts: 1;int print_externC_stmts: 1;int print_full_evars: 1;int
print_zeroterm: 1;int generate_line_directives: 1;int use_curr_namespace: 1;struct Cyc_List_List*
curr_namespace;};void Cyc_Absynpp_decllist2file(struct Cyc_List_List*tdl,struct Cyc___cycFILE*
f);struct Cyc_List_List*Cyc_Parse_parse_file(struct Cyc___cycFILE*f);struct Cyc_Declaration_spec;
struct Cyc_Declarator;struct Cyc_Abstractdeclarator;int Cyc_yyparse();extern char Cyc_AbstractDeclarator_tok[
27];struct Cyc_AbstractDeclarator_tok_struct{char*tag;struct Cyc_Abstractdeclarator*
f1;};extern char Cyc_AggrFieldDeclListList_tok[30];struct Cyc_AggrFieldDeclListList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_AggrFieldDeclList_tok[26];struct
Cyc_AggrFieldDeclList_tok_struct{char*tag;struct Cyc_List_List*f1;};extern char Cyc_AttributeList_tok[
22];struct Cyc_AttributeList_tok_struct{char*tag;struct Cyc_List_List*f1;};extern
char Cyc_Attribute_tok[18];struct Cyc_Attribute_tok_struct{char*tag;void*f1;};
extern char Cyc_Bool_tok[13];struct Cyc_Bool_tok_struct{char*tag;int f1;};extern char
Cyc_Char_tok[13];struct Cyc_Char_tok_struct{char*tag;char f1;};extern char Cyc_DeclList_tok[
17];struct Cyc_DeclList_tok_struct{char*tag;struct Cyc_List_List*f1;};extern char
Cyc_DeclSpec_tok[17];struct Cyc_DeclSpec_tok_struct{char*tag;struct Cyc_Declaration_spec*
f1;};extern char Cyc_Declarator_tok[19];struct Cyc_Declarator_tok_struct{char*tag;
struct Cyc_Declarator*f1;};extern char Cyc_DesignatorList_tok[23];struct Cyc_DesignatorList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_Designator_tok[19];struct Cyc_Designator_tok_struct{
char*tag;void*f1;};extern char Cyc_EnumfieldList_tok[22];struct Cyc_EnumfieldList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_Enumfield_tok[18];struct Cyc_Enumfield_tok_struct{
char*tag;struct Cyc_Absyn_Enumfield*f1;};extern char Cyc_ExpList_tok[16];struct Cyc_ExpList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_Exp_tok[12];struct Cyc_Exp_tok_struct{
char*tag;struct Cyc_Absyn_Exp*f1;};extern char Cyc_FieldPatternList_tok[25];struct
Cyc_FieldPatternList_tok_struct{char*tag;struct Cyc_List_List*f1;};extern char Cyc_FieldPattern_tok[
21];struct _tuple4{struct Cyc_List_List*f1;struct Cyc_Absyn_Pat*f2;};struct Cyc_FieldPattern_tok_struct{
char*tag;struct _tuple4*f1;};extern char Cyc_FnDecl_tok[15];struct Cyc_FnDecl_tok_struct{
char*tag;struct Cyc_Absyn_Fndecl*f1;};extern char Cyc_IdList_tok[15];struct Cyc_IdList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_InitDeclList_tok[21];struct Cyc_InitDeclList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_InitDecl_tok[17];struct _tuple5{
struct Cyc_Declarator*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_InitDecl_tok_struct{
char*tag;struct _tuple5*f1;};extern char Cyc_InitializerList_tok[24];struct Cyc_InitializerList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_Int_tok[12];struct _tuple6{void*
f1;int f2;};struct Cyc_Int_tok_struct{char*tag;struct _tuple6*f1;};extern char Cyc_Kind_tok[
13];struct Cyc_Kind_tok_struct{char*tag;void*f1;};extern char Cyc_Okay_tok[13];
extern char Cyc_ParamDeclListBool_tok[26];struct _tuple7{struct Cyc_List_List*f1;int
f2;struct Cyc_Absyn_VarargInfo*f3;struct Cyc_Core_Opt*f4;struct Cyc_List_List*f5;};
struct Cyc_ParamDeclListBool_tok_struct{char*tag;struct _tuple7*f1;};extern char Cyc_ParamDeclList_tok[
22];struct Cyc_ParamDeclList_tok_struct{char*tag;struct Cyc_List_List*f1;};extern
char Cyc_ParamDecl_tok[18];struct Cyc_ParamDecl_tok_struct{char*tag;struct _tuple1*
f1;};extern char Cyc_PatternList_tok[20];struct Cyc_PatternList_tok_struct{char*tag;
struct Cyc_List_List*f1;};extern char Cyc_Pattern_tok[16];struct Cyc_Pattern_tok_struct{
char*tag;struct Cyc_Absyn_Pat*f1;};extern char Cyc_Pointer_Sort_tok[21];struct Cyc_Pointer_Sort_tok_struct{
char*tag;void*f1;};extern char Cyc_Primop_tok[15];struct Cyc_Primop_tok_struct{char*
tag;void*f1;};extern char Cyc_Primopopt_tok[18];struct Cyc_Primopopt_tok_struct{
char*tag;struct Cyc_Core_Opt*f1;};extern char Cyc_QualId_tok[15];struct Cyc_QualId_tok_struct{
char*tag;struct _tuple0*f1;};extern char Cyc_QualSpecList_tok[21];struct _tuple8{
struct Cyc_Absyn_Tqual f1;struct Cyc_List_List*f2;struct Cyc_List_List*f3;};struct
Cyc_QualSpecList_tok_struct{char*tag;struct _tuple8*f1;};extern char Cyc_Rgnorder_tok[
17];struct Cyc_Rgnorder_tok_struct{char*tag;struct Cyc_List_List*f1;};extern char
Cyc_Scope_tok[14];struct Cyc_Scope_tok_struct{char*tag;void*f1;};extern char Cyc_Short_tok[
14];struct Cyc_Short_tok_struct{char*tag;short f1;};extern char Cyc_Stmt_tok[13];
struct Cyc_Stmt_tok_struct{char*tag;struct Cyc_Absyn_Stmt*f1;};extern char Cyc_StorageClass_tok[
21];struct Cyc_StorageClass_tok_struct{char*tag;void*f1;};extern char Cyc_String_tok[
15];struct Cyc_String_tok_struct{char*tag;struct _dynforward_ptr f1;};extern char Cyc_Stringopt_tok[
18];struct Cyc_Stringopt_tok_struct{char*tag;struct Cyc_Core_Opt*f1;};extern char
Cyc_StructOrUnion_tok[22];struct Cyc_StructOrUnion_tok_struct{char*tag;void*f1;};
extern char Cyc_SwitchClauseList_tok[25];struct Cyc_SwitchClauseList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_TunionFieldList_tok[24];struct
Cyc_TunionFieldList_tok_struct{char*tag;struct Cyc_List_List*f1;};extern char Cyc_TunionField_tok[
20];struct Cyc_TunionField_tok_struct{char*tag;struct Cyc_Absyn_Tunionfield*f1;};
extern char Cyc_TypeList_tok[17];struct Cyc_TypeList_tok_struct{char*tag;struct Cyc_List_List*
f1;};extern char Cyc_TypeModifierList_tok[25];struct Cyc_TypeModifierList_tok_struct{
char*tag;struct Cyc_List_List*f1;};extern char Cyc_TypeOpt_tok[16];struct Cyc_TypeOpt_tok_struct{
char*tag;struct Cyc_Core_Opt*f1;};extern char Cyc_TypeQual_tok[17];struct Cyc_TypeQual_tok_struct{
char*tag;struct Cyc_Absyn_Tqual f1;};extern char Cyc_TypeSpecifier_tok[22];struct Cyc_TypeSpecifier_tok_struct{
char*tag;void*f1;};extern char Cyc_Type_tok[13];struct Cyc_Type_tok_struct{char*tag;
void*f1;};int Cyc_yyparse();extern char Cyc_YY1[8];struct _tuple9{struct Cyc_Position_Segment*
f1;struct Cyc_Absyn_Conref*f2;struct Cyc_Absyn_Conref*f3;};struct Cyc_YY1_struct{
char*tag;struct _tuple9*f1;};extern char Cyc_YY2[8];struct Cyc_YY2_struct{char*tag;
struct Cyc_Absyn_Conref*f1;};extern char Cyc_YY3[8];struct _tuple10{struct Cyc_List_List*
f1;int f2;};struct Cyc_YY3_struct{char*tag;struct _tuple10*f1;};extern char Cyc_YY4[8];
struct Cyc_YY4_struct{char*tag;struct _tuple10*f1;};extern char Cyc_YY5[8];struct Cyc_YY5_struct{
char*tag;struct _tuple7*f1;};extern char Cyc_YY6[8];struct Cyc_YY6_struct{char*tag;
struct Cyc_Absyn_Conref*f1;};extern char Cyc_YY7[8];struct Cyc_YY7_struct{char*tag;
struct Cyc_List_List*f1;};extern char Cyc_YYINITIALSVAL[18];struct Cyc_Yyltype{int
timestamp;int first_line;int first_column;int last_line;int last_column;};struct Cyc_Dict_Dict;
extern char Cyc_Dict_Present[12];extern char Cyc_Dict_Absent[11];struct _tuple11{void*
f1;void*f2;};struct _tuple11*Cyc_Dict_rchoose(struct _RegionHandle*r,struct Cyc_Dict_Dict*
d);struct _tuple11*Cyc_Dict_rchoose(struct _RegionHandle*,struct Cyc_Dict_Dict*d);
struct Cyc_RgnOrder_RgnPO;struct Cyc_RgnOrder_RgnPO*Cyc_RgnOrder_initial_fn_po(
struct Cyc_List_List*tvs,struct Cyc_List_List*po,void*effect,struct Cyc_Absyn_Tvar*
fst_rgn);struct Cyc_RgnOrder_RgnPO*Cyc_RgnOrder_add_outlives_constraint(struct Cyc_RgnOrder_RgnPO*
po,void*eff,void*rgn);struct Cyc_RgnOrder_RgnPO*Cyc_RgnOrder_add_youngest(struct
Cyc_RgnOrder_RgnPO*po,struct Cyc_Absyn_Tvar*rgn,int resetable);int Cyc_RgnOrder_is_region_resetable(
struct Cyc_RgnOrder_RgnPO*po,struct Cyc_Absyn_Tvar*r);int Cyc_RgnOrder_effect_outlives(
struct Cyc_RgnOrder_RgnPO*po,void*eff,void*rgn);int Cyc_RgnOrder_satisfies_constraints(
struct Cyc_RgnOrder_RgnPO*po,struct Cyc_List_List*constraints,void*default_bound,
int do_pin);int Cyc_RgnOrder_eff_outlives_eff(struct Cyc_RgnOrder_RgnPO*po,void*
eff1,void*eff2);struct Cyc_Tcenv_VarRes_struct{int tag;void*f1;};struct Cyc_Tcenv_AggrRes_struct{
int tag;struct Cyc_Absyn_Aggrdecl*f1;};struct Cyc_Tcenv_TunionRes_struct{int tag;
struct Cyc_Absyn_Tuniondecl*f1;struct Cyc_Absyn_Tunionfield*f2;};struct Cyc_Tcenv_EnumRes_struct{
int tag;struct Cyc_Absyn_Enumdecl*f1;struct Cyc_Absyn_Enumfield*f2;};struct Cyc_Tcenv_AnonEnumRes_struct{
int tag;void*f1;struct Cyc_Absyn_Enumfield*f2;};struct Cyc_Tcenv_Genv{struct
_RegionHandle*grgn;struct Cyc_Set_Set*namespaces;struct Cyc_Dict_Dict*aggrdecls;
struct Cyc_Dict_Dict*tuniondecls;struct Cyc_Dict_Dict*enumdecls;struct Cyc_Dict_Dict*
typedefs;struct Cyc_Dict_Dict*ordinaries;struct Cyc_List_List*availables;};struct
Cyc_Tcenv_Fenv;struct Cyc_Tcenv_Stmt_j_struct{int tag;struct Cyc_Absyn_Stmt*f1;};
struct Cyc_Tcenv_Tenv{struct Cyc_List_List*ns;struct Cyc_Dict_Dict*ae;struct Cyc_Tcenv_Fenv*
le;};struct Cyc_Tcenv_Tenv*Cyc_Tcenv_tc_init(struct _RegionHandle*);void Cyc_Tc_tc(
struct _RegionHandle*,struct Cyc_Tcenv_Tenv*te,int var_default_init,struct Cyc_List_List*
ds);typedef struct{int quot;int rem;}Cyc_div_t;typedef struct{long quot;long rem;}Cyc_ldiv_t;
void*abort();void exit(int);int system(const char*);struct Cyc_stat{short st_dev;
unsigned long st_ino;int st_mode;unsigned short st_nlink;unsigned short __st_uid16;
unsigned short __st_gid16;short st_rdev;long __st_size32;long st_atime;unsigned long
__st_uid32;long st_mtime;unsigned long __st_gid32;long st_ctime;long st_spare3;long
st_blksize;long st_blocks;long long __st_size64;};int mkdir(const char*pathname,int
mode);struct Cyc_flock{short l_type;short l_whence;long l_start;long l_len;short l_pid;
short l_xxx;};struct Cyc_Flock_struct{int tag;struct Cyc_flock*f1;};struct Cyc_Long_struct{
int tag;long f1;};int Cyc_open(const char*,int,struct _dynforward_ptr);struct Cyc_option{
struct _dynforward_ptr name;int has_arg;int*flag;int val;};int chdir(const char*);int
close(int);struct _dynforward_ptr Cyc_getcwd(struct _dynforward_ptr buf,unsigned int
size);int isspace(int);int toupper(int);void Cyc_Lex_lex_init(int
use_cyclone_keywords);extern char*Ccomp;struct Cyc___cycFILE*Cyc_log_file=0;struct
Cyc___cycFILE*Cyc_cstubs_file=0;struct Cyc___cycFILE*Cyc_cycstubs_file=0;int Cyc_log(
struct _dynforward_ptr fmt,struct _dynforward_ptr ap){if(Cyc_log_file == 0){({void*
_tmp0[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp1="Internal error: log file is NULL\n";
_tag_dynforward(_tmp1,sizeof(char),_get_zero_arr_size(_tmp1,34));}),
_tag_dynforward(_tmp0,sizeof(void*),0));});exit(1);}{int _tmp2=Cyc_vfprintf((
struct Cyc___cycFILE*)_check_null(Cyc_log_file),fmt,ap);Cyc_fflush((struct Cyc___cycFILE*)((
struct Cyc___cycFILE*)_check_null(Cyc_log_file)));return _tmp2;}}static struct
_dynforward_ptr*Cyc_current_source=0;static struct Cyc_List_List*Cyc_current_args=
0;static struct Cyc_Set_Set**Cyc_current_targets=0;static void Cyc_add_target(struct
_dynforward_ptr*sptr){Cyc_current_targets=({struct Cyc_Set_Set**_tmp3=_cycalloc(
sizeof(*_tmp3));_tmp3[0]=((struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*s,struct
_dynforward_ptr*elt))Cyc_Set_insert)(*((struct Cyc_Set_Set**)_check_null(Cyc_current_targets)),
sptr);_tmp3;});}struct _tuple12{struct _dynforward_ptr*f1;struct Cyc_Set_Set*f2;};
struct _tuple12*Cyc_line(struct Cyc_Lexing_lexbuf*);int Cyc_macroname(struct Cyc_Lexing_lexbuf*);
int Cyc_args(struct Cyc_Lexing_lexbuf*);int Cyc_token(struct Cyc_Lexing_lexbuf*);int
Cyc_string(struct Cyc_Lexing_lexbuf*);struct Cyc___cycFILE*Cyc_slurp_out=0;int Cyc_slurp(
struct Cyc_Lexing_lexbuf*);int Cyc_slurp_string(struct Cyc_Lexing_lexbuf*);int Cyc_asm(
struct Cyc_Lexing_lexbuf*);int Cyc_asm_string(struct Cyc_Lexing_lexbuf*);int Cyc_asm_comment(
struct Cyc_Lexing_lexbuf*);struct _tuple13{struct _dynforward_ptr f1;struct
_dynforward_ptr*f2;};struct _tuple13*Cyc_suck_line(struct Cyc_Lexing_lexbuf*);int
Cyc_suck_macroname(struct Cyc_Lexing_lexbuf*);int Cyc_suck_restofline(struct Cyc_Lexing_lexbuf*);
struct _dynforward_ptr Cyc_current_line=(struct _dynforward_ptr){(void*)0,(void*)(0
+ 0)};struct _tuple14{struct _dynforward_ptr f1;struct _dynforward_ptr f2;};struct
_tuple15{struct _dynforward_ptr f1;struct Cyc_List_List*f2;struct Cyc_List_List*f3;
struct Cyc_List_List*f4;struct Cyc_List_List*f5;struct Cyc_List_List*f6;};struct
_tuple15*Cyc_spec(struct Cyc_Lexing_lexbuf*);int Cyc_commands(struct Cyc_Lexing_lexbuf*);
int Cyc_snarfsymbols(struct Cyc_Lexing_lexbuf*);int Cyc_block(struct Cyc_Lexing_lexbuf*);
int Cyc_block_string(struct Cyc_Lexing_lexbuf*);int Cyc_block_comment(struct Cyc_Lexing_lexbuf*);
struct _dynforward_ptr Cyc_current_headerfile=(struct _dynforward_ptr){(void*)0,(
void*)(0 + 0)};struct Cyc_List_List*Cyc_snarfed_symbols=0;struct Cyc_List_List*Cyc_current_symbols=
0;struct Cyc_List_List*Cyc_current_cstubs=0;struct Cyc_List_List*Cyc_current_cycstubs=
0;struct Cyc_List_List*Cyc_current_hstubs=0;struct Cyc_List_List*Cyc_current_omit_symbols=
0;struct Cyc_List_List*Cyc_current_cpp=0;struct Cyc_Buffer_t*Cyc_specbuf=0;int Cyc_braces_to_match=
0;int Cyc_parens_to_match=0;int Cyc_numdef=0;const int Cyc_lex_base[406]=(const int[
406]){0,0,75,192,305,310,311,166,312,91,27,384,28,523,637,715,283,325,92,- 3,0,- 1,
- 2,- 8,- 3,1,- 2,323,- 4,2,166,- 5,605,797,312,- 6,- 7,- 4,16,- 3,29,11,835,- 3,910,13,- 14,
223,12,- 2,216,20,26,28,33,23,48,70,54,64,74,100,91,107,94,370,386,111,103,95,122,
122,375,414,111,111,153,377,1024,1139,525,176,210,228,214,216,217,242,498,1253,
1368,- 9,654,- 10,224,245,508,1482,1597,684,- 8,720,- 11,432,510,515,1674,1751,1828,
1909,434,465,550,1984,249,249,249,248,244,254,0,13,4,2065,5,628,2073,2138,660,49,
467,6,2099,7,705,2161,2199,820,- 21,1051,1056,261,314,242,251,258,250,271,281,274,
275,278,288,295,282,- 19,292,296,300,313,321,326,309,325,319,315,326,365,400,417,
418,404,400,400,427,431,- 16,422,421,415,436,433,449,427,449,453,441,445,436,436,
- 18,444,438,442,453,464,447,449,482,489,490,1,4,6,491,492,505,504,516,516,524,
554,2,21,556,557,654,19,20,21,592,555,554,585,592,594,23,650,651,- 13,600,603,658,
659,660,622,623,678,679,686,636,637,693,697,698,645,648,703,704,705,- 12,654,655,
1030,- 20,1165,654,664,661,671,670,665,668,698,700,698,712,1144,730,731,730,743,
1258,1170,747,758,748,749,747,760,1370,752,753,765,778,1375,- 7,- 8,8,1263,2231,9,
996,2255,2293,1341,1279,- 49,1150,- 2,817,- 4,818,997,1028,819,993,1023,1448,820,
2320,2363,824,866,868,907,2433,870,991,- 36,- 42,- 37,2508,- 28,909,- 40,- 25,911,- 27,
- 45,- 39,- 48,2583,2612,1467,889,979,1563,2622,2652,1582,2281,2685,2716,2754,1001,
1090,2824,2862,1082,1092,1084,1127,1148,1204,- 6,- 34,927,2794,- 47,- 30,- 32,- 46,- 29,
- 31,- 33,962,2902,963,964,2128,965,1002,1003,1014,1018,1020,1024,1032,1043,2975,
3059,- 23,- 17,- 15,- 22,2239,1077,- 24,- 41,- 38,- 35,- 26,1282,3141,4,3224,1076,15,1051,
1055,1056,1058,1054,1071,1141};const int Cyc_lex_backtrk[406]=(const int[406]){- 1,-
1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,2,- 1,- 1,- 1,- 1,2,- 1,8,- 1,3,
5,- 1,- 1,6,5,- 1,- 1,- 1,6,- 1,5,1,0,- 1,0,1,- 1,12,13,- 1,13,13,13,13,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,11,12,2,4,4,- 1,0,0,0,2,0,- 1,- 1,-
1,- 1,- 1,- 1,- 1,2,2,8,3,5,- 1,6,5,6,5,2,8,3,5,- 1,6,5,- 1,20,20,20,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,14,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,16,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,6,1,9,2,4,- 1,5,4,- 1,- 1,2,- 1,48,- 1,48,48,48,48,48,48,48,48,5,7,48,
48,48,48,0,48,48,- 1,- 1,- 1,0,- 1,43,- 1,- 1,42,- 1,- 1,- 1,- 1,9,7,- 1,7,7,- 1,8,9,- 1,- 1,9,
5,6,5,5,- 1,4,4,4,6,6,5,5,- 1,- 1,- 1,9,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,2,- 1,- 1,2,1,1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1};const int Cyc_lex_default[406]=(const int[406]){- 1,- 1,- 1,297,286,138,
23,36,23,19,- 1,- 1,12,31,46,31,36,23,19,0,- 1,0,0,0,0,- 1,0,- 1,0,- 1,- 1,0,- 1,- 1,- 1,0,
0,0,- 1,0,40,- 1,- 1,0,- 1,- 1,0,- 1,- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,
- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,0,- 1,0,103,- 1,- 1,- 1,- 1,- 1,110,110,110,- 1,- 1,- 1,- 1,- 1,- 1,-
1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,130,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,-
1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,- 1,- 1,-
1,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,-
1,- 1,- 1,- 1,- 1,- 1,0,0,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,- 1,0,- 1,0,- 1,- 1,366,- 1,- 1,- 1,-
1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,0,0,- 1,0,- 1,0,0,- 1,0,0,0,0,- 1,- 1,- 1,- 1,- 1,- 1,-
1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,0,- 1,- 1,0,0,0,0,0,0,0,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,0,0,0,- 1,- 1,0,0,0,0,0,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1};const int Cyc_lex_trans[3481]=(const int[3481]){0,0,0,0,0,
0,0,0,0,0,22,19,28,398,19,28,19,28,100,19,45,45,45,45,45,22,45,0,0,0,0,0,21,202,
213,399,21,22,- 1,- 1,22,- 1,- 1,45,203,45,204,22,396,396,396,396,396,396,396,396,
396,396,31,103,22,214,114,40,227,396,396,396,396,396,396,396,396,396,396,396,396,
396,396,396,396,396,396,396,396,396,396,396,396,396,396,31,245,240,235,396,130,
396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,
396,396,396,396,396,396,394,394,394,394,394,394,394,394,394,394,121,20,74,67,54,
55,56,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,
394,394,394,394,394,394,394,394,57,58,59,60,394,61,394,394,394,394,394,394,394,
394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,62,
63,37,298,299,298,298,299,39,22,64,65,68,69,70,129,34,34,34,34,34,34,34,34,71,72,
298,300,301,75,76,302,303,304,104,104,305,306,104,307,308,309,310,311,311,311,
311,311,311,311,311,311,312,77,313,314,315,104,19,316,316,316,316,316,316,316,
316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,19,-
1,- 1,317,316,101,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,
316,316,316,316,316,316,316,316,316,316,287,318,37,288,139,139,24,24,139,131,122,
94,84,81,85,38,82,86,28,87,24,29,83,25,289,88,95,139,96,22,26,26,21,21,115,116,
117,140,118,119,120,142,191,192,26,35,35,35,35,35,35,35,35,177,171,162,30,30,30,
30,30,30,30,30,66,66,156,149,66,73,73,78,78,73,150,78,151,152,153,154,66,66,290,
155,66,157,158,66,132,123,141,39,73,22,78,159,143,144,145,160,146,161,27,66,147,
31,46,21,73,73,163,164,73,148,165,166,167,113,113,113,113,113,113,113,113,113,
113,- 1,32,- 1,- 1,73,- 1,22,113,113,113,113,113,113,113,113,113,113,113,113,113,113,
113,113,113,113,113,113,113,113,113,113,113,113,- 1,168,- 1,- 1,113,- 1,113,113,113,
113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,
113,113,113,89,89,28,169,89,170,100,172,173,174,97,97,104,104,97,175,104,112,112,
176,178,112,179,89,180,105,105,80,80,105,19,80,21,97,181,104,182,183,184,185,112,
186,187,188,189,190,251,193,105,194,80,195,112,112,91,196,112,197,198,21,21,21,
106,107,106,106,106,106,106,106,106,106,106,106,21,112,199,200,201,205,206,106,
106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,
106,106,106,106,106,207,208,209,210,106,211,106,106,106,106,106,106,106,106,106,
106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,47,47,35,212,
47,215,216,33,33,33,33,33,33,33,33,33,33,92,92,230,222,92,223,47,33,33,33,33,33,
33,128,128,128,128,128,128,128,128,48,224,92,225,- 1,226,- 1,228,229,99,99,231,49,
99,232,233,234,93,33,33,33,33,33,33,35,35,35,35,35,35,35,35,99,236,237,238,239,-
1,217,- 1,41,41,218,102,41,101,101,241,242,101,243,219,50,220,244,91,246,51,52,
247,248,249,250,41,53,252,253,268,101,137,137,137,137,137,137,137,137,263,259,42,
42,42,42,42,42,42,42,42,42,221,260,261,262,93,36,28,42,42,42,42,42,42,42,42,42,
42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,264,100,265,266,42,267,42,42,
42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,269,270,
43,271,272,102,281,33,33,33,33,33,33,33,33,33,33,276,277,278,279,280,282,283,33,
33,33,33,33,33,35,35,35,35,35,35,35,35,284,285,392,391,365,356,331,44,44,44,44,
44,44,44,44,44,44,21,33,33,33,33,33,33,44,44,44,44,44,44,44,44,44,44,44,44,44,44,
44,44,44,44,44,44,44,44,44,44,44,44,327,328,329,326,44,321,44,44,44,44,44,44,44,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,
44,44,323,324,325,28,330,359,100,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,
44,44,44,44,44,44,44,44,44,44,388,254,155,138,44,100,44,44,44,44,44,44,44,44,44,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,78,78,389,363,78,- 1,253,253,
190,102,253,295,295,295,295,295,295,295,295,319,250,364,100,78,229,390,46,273,
273,253,384,273,255,255,- 1,360,255,254,176,79,79,79,79,79,79,79,79,79,79,383,273,
361,362,35,100,255,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,320,385,21,35,79,367,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,31,80,80,274,400,80,267,267,256,401,267,402,
393,275,393,393,403,404,257,35,31,31,36,258,80,405,21,255,255,267,0,255,273,273,
0,393,273,19,0,0,79,79,79,79,79,79,79,79,79,79,255,35,31,31,36,273,36,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,0,0,0,355,
79,36,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,89,89,256,355,89,272,272,274,0,272,296,296,257,0,296,0,0,275,355,0,0,0,- 1,89,
0,0,296,296,272,393,296,393,393,296,0,21,31,0,0,90,90,90,90,90,90,90,90,90,90,
296,355,21,393,0,0,0,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,
90,90,90,90,90,90,0,0,0,0,90,0,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,
90,90,90,90,90,90,90,90,90,90,91,92,92,280,280,92,0,280,285,285,0,0,285,31,31,31,
31,31,31,31,31,0,0,0,92,0,280,0,0,0,0,285,0,0,28,0,0,0,0,35,90,90,90,90,90,90,90,
90,90,90,0,0,0,0,0,0,0,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,
90,90,90,90,90,90,90,0,0,0,0,90,0,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,
90,90,90,90,90,90,90,90,90,90,90,97,97,0,357,97,358,358,358,358,358,358,358,358,
358,358,0,0,0,0,337,0,337,0,97,338,338,338,338,338,338,338,338,338,338,0,0,0,0,0,
98,98,98,98,98,98,98,98,98,98,0,0,0,0,0,0,0,98,98,98,98,98,98,98,98,98,98,98,98,
98,98,98,98,98,98,98,98,98,98,98,98,98,98,0,0,0,0,98,0,98,98,98,98,98,98,98,98,
98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,36,99,99,0,0,99,338,338,
338,338,338,338,338,338,338,338,0,0,0,0,341,0,341,0,99,342,342,342,342,342,342,
342,342,342,342,0,0,0,0,0,98,98,98,98,98,98,98,98,98,98,0,0,0,0,0,0,0,98,98,98,
98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,0,0,0,0,98,
0,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,
108,108,108,108,108,108,108,108,108,108,108,108,22,0,0,0,0,0,0,108,108,108,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,
108,108,0,0,0,0,108,0,108,108,108,108,108,108,108,108,108,108,108,108,108,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,109,108,108,108,108,108,108,
108,108,108,108,22,0,0,0,0,0,0,108,108,108,108,108,108,108,108,108,108,108,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,0,0,0,0,108,0,108,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,22,0,0,0,0,0,0,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,
108,108,108,108,108,108,- 1,0,0,- 1,108,0,108,108,108,108,108,108,108,108,108,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,0,0,0,0,109,109,
109,109,109,109,109,109,109,109,109,109,111,0,0,0,0,0,0,109,109,109,109,109,109,
109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,
0,0,0,0,109,0,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,
109,109,109,109,109,109,109,109,109,109,113,113,113,113,113,113,113,113,113,113,
0,0,0,0,0,0,0,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,
113,113,113,113,113,113,113,113,113,113,28,0,0,124,113,0,113,113,113,113,113,113,
113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,
0,0,28,0,0,133,125,125,125,125,125,125,125,125,127,127,127,127,127,127,127,127,
127,127,0,0,0,0,0,0,0,127,127,127,127,127,127,0,0,0,134,134,134,134,134,134,134,
134,0,0,0,0,0,0,0,31,0,0,- 1,0,385,0,0,127,127,127,127,127,127,386,386,386,386,
386,386,386,386,0,126,127,127,127,127,127,127,127,127,127,127,31,0,0,0,0,0,0,127,
127,127,127,127,127,136,136,136,136,136,136,136,136,136,136,135,0,0,0,0,0,0,136,
136,136,136,136,136,0,0,0,127,127,127,127,127,127,19,0,0,291,0,0,136,136,136,136,
136,136,136,136,136,136,0,136,136,136,136,136,136,136,136,136,136,136,136,0,0,0,
0,0,0,0,0,385,292,292,292,292,292,292,292,292,387,387,387,387,387,387,387,387,0,
136,136,136,136,136,136,0,294,294,294,294,294,294,294,294,294,294,0,0,0,0,0,0,0,
294,294,294,294,294,294,0,0,28,342,342,342,342,342,342,342,342,342,342,0,0,294,
294,294,294,294,294,294,294,294,294,293,294,294,294,294,294,294,294,294,294,294,
294,294,0,0,332,0,343,343,343,343,343,343,343,343,344,344,0,0,0,0,0,0,0,0,0,0,0,
334,294,294,294,294,294,294,345,0,0,0,0,0,0,0,0,346,0,0,347,332,0,333,333,333,
333,333,333,333,333,333,333,334,0,0,0,0,0,0,345,0,0,0,334,0,0,0,0,346,0,335,347,
0,0,0,0,0,0,0,336,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,334,0,0,0,0,0,0,335,0,0,0,0,0,0,
0,0,336,322,322,322,322,322,322,322,322,322,322,0,0,0,0,0,0,0,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,0,0,0,0,322,0,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,0,0,0,0,0,0,0,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,0,0,0,0,322,0,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,339,339,339,339,339,339,339,339,339,339,0,0,0,0,0,0,0,0,0,0,0,340,93,0,0,
0,0,332,93,333,333,333,333,333,333,333,333,333,333,338,338,338,338,338,338,338,
338,338,338,0,334,0,0,340,93,0,0,335,0,0,93,91,0,0,0,0,336,91,0,339,339,339,339,
339,339,339,339,339,339,0,0,0,334,0,0,0,0,0,0,335,340,93,0,91,0,0,0,93,336,91,0,
0,342,342,342,342,342,342,342,342,342,342,0,0,0,0,0,0,0,0,0,0,340,93,93,0,0,0,0,
93,93,332,0,343,343,343,343,343,343,343,343,344,344,0,0,0,0,0,0,0,0,0,0,0,334,0,
93,0,0,0,0,353,93,0,0,0,0,0,0,332,354,344,344,344,344,344,344,344,344,344,344,0,
0,0,0,0,334,0,0,0,0,0,334,353,0,0,0,0,0,351,0,0,354,0,0,0,0,0,352,0,0,358,358,
358,358,358,358,358,358,358,358,0,0,0,334,0,0,0,0,0,0,351,340,93,0,0,0,0,0,93,
352,348,348,348,348,348,348,348,348,348,348,0,0,0,0,0,0,0,348,348,348,348,348,
348,340,93,0,0,0,0,0,93,0,0,0,0,0,0,0,348,348,348,348,348,348,348,348,348,348,0,
348,348,348,348,348,348,348,348,348,348,348,348,0,0,0,368,0,349,0,0,369,0,0,0,0,
0,350,0,0,370,370,370,370,370,370,370,370,0,348,348,348,348,348,348,371,0,0,0,0,
349,0,0,0,0,0,0,0,0,350,0,0,0,0,0,0,0,0,0,0,0,0,0,0,372,0,0,0,0,373,374,0,0,0,
375,0,0,0,0,0,0,0,376,0,0,0,377,0,378,0,379,0,380,381,381,381,381,381,381,381,
381,381,381,0,0,0,0,0,0,0,381,381,381,381,381,381,381,381,381,381,381,381,381,
381,381,381,381,381,381,381,381,381,381,381,381,381,0,0,0,0,0,0,381,381,381,381,
381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,
381,381,382,0,0,0,0,0,0,0,0,381,381,381,381,381,381,381,381,381,381,0,0,0,0,0,0,
0,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,
381,381,381,381,381,381,381,0,0,0,0,0,0,381,381,381,381,381,381,381,381,381,381,
381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,22,0,0,395,0,0,0,
394,394,394,394,394,394,394,394,394,394,0,0,0,0,0,0,0,394,394,394,394,394,394,
394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,
0,0,0,0,394,0,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,
394,394,394,394,394,394,394,394,394,394,397,0,0,0,0,0,0,0,396,396,396,396,396,
396,396,396,396,396,0,0,0,0,0,0,0,396,396,396,396,396,396,396,396,396,396,396,
396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,0,0,0,0,396,0,396,
396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,
396,396,396,396,396,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};const int Cyc_lex_check[3481]=(
const int[3481]){- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,0,25,29,0,122,124,131,133,288,291,
41,41,45,45,41,398,45,- 1,- 1,- 1,- 1,- 1,120,201,212,0,395,10,12,40,10,12,40,41,202,
45,203,20,1,1,1,1,1,1,1,1,1,1,38,48,121,213,10,38,226,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,129,217,218,219,1,129,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,9,18,51,52,53,54,55,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,56,57,58,59,2,60,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,2,2,2,2,2,2,2,2,2,61,62,7,3,3,3,3,3,7,7,63,64,67,68,69,7,30,30,30,30,30,30,30,
30,70,71,3,3,3,74,75,3,3,3,47,47,3,3,47,3,3,3,3,3,3,3,3,3,3,3,3,3,3,76,3,3,3,47,
0,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,10,12,40,3,3,81,3,3,3,3,3,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,3,16,4,5,5,6,8,5,6,8,82,83,50,84,16,
50,85,27,86,17,27,50,17,4,87,94,5,95,5,6,8,9,18,114,115,116,5,117,118,119,141,
143,143,17,34,34,34,34,34,34,34,34,144,145,146,27,27,27,27,27,27,27,27,65,65,147,
148,65,72,72,77,77,72,149,77,150,151,152,153,66,66,4,154,66,156,157,65,6,8,5,16,
72,16,77,158,142,142,142,159,142,160,17,66,142,27,161,7,73,73,162,163,73,142,164,
165,166,11,11,11,11,11,11,11,11,11,11,103,27,110,103,73,110,3,11,11,11,11,11,11,
11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,111,167,130,111,11,
130,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,
11,88,88,66,168,88,169,170,171,172,173,96,96,104,104,96,174,104,105,105,175,177,
105,178,88,179,13,13,80,80,13,73,80,16,96,180,104,181,182,183,184,105,185,186,
187,188,189,191,192,13,193,80,194,112,112,4,195,112,196,197,5,6,8,13,13,13,13,13,
13,13,13,13,13,13,13,17,112,198,199,200,204,205,13,13,13,13,13,13,13,13,13,13,13,
13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,206,207,208,209,13,210,13,13,13,13,
13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,13,14,14,80,211,
14,214,215,32,32,32,32,32,32,32,32,32,32,92,92,220,221,92,222,14,32,32,32,32,32,
32,125,125,125,125,125,125,125,125,14,223,92,224,103,225,110,227,228,99,99,230,
14,99,231,232,233,234,32,32,32,32,32,32,128,128,128,128,128,128,128,128,99,235,
236,237,238,111,216,130,15,15,216,239,15,101,101,240,241,101,242,216,14,216,243,
244,245,14,14,246,247,248,249,15,14,251,252,256,101,134,134,134,134,134,134,134,
134,257,258,15,15,15,15,15,15,15,15,15,15,216,259,260,261,92,262,13,15,15,15,15,
15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,263,99,264,265,
15,266,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,15,
15,15,268,269,15,270,271,101,274,33,33,33,33,33,33,33,33,33,33,275,276,277,278,
279,281,282,33,33,33,33,33,33,137,137,137,137,137,137,137,137,283,284,300,302,
305,309,312,42,42,42,42,42,42,42,42,42,42,14,33,33,33,33,33,33,42,42,42,42,42,42,
42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,313,313,313,314,42,
317,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,42,
42,44,44,44,44,44,44,44,44,44,44,315,315,324,15,327,357,335,44,44,44,44,44,44,44,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,366,368,369,371,44,335,
44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,44,78,
78,303,306,78,304,253,253,372,373,253,292,292,292,292,292,292,292,292,318,374,
306,336,78,375,303,376,139,139,253,377,139,140,140,304,307,140,253,378,78,78,78,
78,78,78,78,78,78,78,379,139,307,307,345,336,140,78,78,78,78,78,78,78,78,78,78,
78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,318,387,397,345,78,304,78,78,78,
78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,78,79,79,
139,399,79,267,267,140,400,267,401,298,139,298,298,402,403,140,346,349,350,351,
140,79,404,405,255,255,267,- 1,255,273,273,- 1,298,273,267,- 1,- 1,79,79,79,79,79,79,
79,79,79,79,255,346,349,350,351,273,352,79,79,79,79,79,79,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,- 1,- 1,- 1,353,79,352,79,79,79,79,79,79,79,
79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,79,89,89,255,353,89,272,
272,273,- 1,272,289,289,255,- 1,289,- 1,- 1,273,354,- 1,- 1,- 1,304,89,- 1,- 1,296,296,
272,393,296,393,393,289,- 1,289,272,- 1,- 1,89,89,89,89,89,89,89,89,89,89,296,354,
296,393,- 1,- 1,- 1,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,
89,89,89,89,89,- 1,- 1,- 1,- 1,89,- 1,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,89,
89,89,89,89,89,89,89,89,89,89,89,90,90,280,280,90,- 1,280,285,285,- 1,- 1,285,295,
295,295,295,295,295,295,295,- 1,- 1,- 1,90,- 1,280,- 1,- 1,- 1,- 1,285,- 1,- 1,280,- 1,- 1,-
1,- 1,285,90,90,90,90,90,90,90,90,90,90,- 1,- 1,- 1,- 1,- 1,- 1,- 1,90,90,90,90,90,90,90,
90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,- 1,- 1,- 1,- 1,90,- 1,90,90,
90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,90,97,97,- 1,
308,97,308,308,308,308,308,308,308,308,308,308,- 1,- 1,- 1,- 1,334,- 1,334,- 1,97,334,
334,334,334,334,334,334,334,334,334,- 1,- 1,- 1,- 1,- 1,97,97,97,97,97,97,97,97,97,97,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,
97,97,97,97,97,97,- 1,- 1,- 1,- 1,97,- 1,97,97,97,97,97,97,97,97,97,97,97,97,97,97,97,
97,97,97,97,97,97,97,97,97,97,97,97,98,98,- 1,- 1,98,337,337,337,337,337,337,337,
337,337,337,- 1,- 1,- 1,- 1,340,- 1,340,- 1,98,340,340,340,340,340,340,340,340,340,340,
- 1,- 1,- 1,- 1,- 1,98,98,98,98,98,98,98,98,98,98,- 1,- 1,- 1,- 1,- 1,- 1,- 1,98,98,98,98,98,
98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,- 1,- 1,- 1,- 1,98,- 1,
98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,98,
106,106,106,106,106,106,106,106,106,106,106,106,106,- 1,- 1,- 1,- 1,- 1,- 1,106,106,
106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,
106,106,106,106,- 1,- 1,- 1,- 1,106,- 1,106,106,106,106,106,106,106,106,106,106,106,
106,106,106,106,106,106,106,106,106,106,106,106,106,106,106,107,107,107,107,107,
107,107,107,107,107,107,107,107,- 1,- 1,- 1,- 1,- 1,- 1,107,107,107,107,107,107,107,
107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,- 1,-
1,- 1,- 1,107,- 1,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,107,
107,107,107,107,107,107,107,107,107,107,108,108,108,108,108,108,108,108,108,108,
108,108,108,- 1,- 1,- 1,- 1,- 1,- 1,108,108,108,108,108,108,108,108,108,108,108,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,109,- 1,- 1,109,108,- 1,108,
108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,108,
108,108,108,108,108,- 1,- 1,- 1,- 1,109,109,109,109,109,109,109,109,109,109,109,109,
109,- 1,- 1,- 1,- 1,- 1,- 1,109,109,109,109,109,109,109,109,109,109,109,109,109,109,
109,109,109,109,109,109,109,109,109,109,109,109,- 1,- 1,- 1,- 1,109,- 1,109,109,109,
109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,109,
109,109,109,113,113,113,113,113,113,113,113,113,113,- 1,- 1,- 1,- 1,- 1,- 1,- 1,113,113,
113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,
113,113,113,113,123,- 1,- 1,123,113,- 1,113,113,113,113,113,113,113,113,113,113,113,
113,113,113,113,113,113,113,113,113,113,113,113,113,113,113,- 1,- 1,132,- 1,- 1,132,
123,123,123,123,123,123,123,123,126,126,126,126,126,126,126,126,126,126,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,126,126,126,126,126,126,- 1,- 1,- 1,132,132,132,132,132,132,132,132,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,123,- 1,- 1,109,- 1,370,- 1,- 1,126,126,126,126,126,126,370,370,370,
370,370,370,370,370,- 1,123,127,127,127,127,127,127,127,127,127,127,132,- 1,- 1,- 1,
- 1,- 1,- 1,127,127,127,127,127,127,135,135,135,135,135,135,135,135,135,135,132,- 1,
- 1,- 1,- 1,- 1,- 1,135,135,135,135,135,135,- 1,- 1,- 1,127,127,127,127,127,127,290,- 1,-
1,290,- 1,- 1,136,136,136,136,136,136,136,136,136,136,- 1,135,135,135,135,135,135,
136,136,136,136,136,136,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,386,290,290,290,290,290,290,290,
290,386,386,386,386,386,386,386,386,- 1,136,136,136,136,136,136,- 1,293,293,293,
293,293,293,293,293,293,293,- 1,- 1,- 1,- 1,- 1,- 1,- 1,293,293,293,293,293,293,- 1,- 1,
290,341,341,341,341,341,341,341,341,341,341,- 1,- 1,294,294,294,294,294,294,294,
294,294,294,290,293,293,293,293,293,293,294,294,294,294,294,294,- 1,- 1,310,- 1,310,
310,310,310,310,310,310,310,310,310,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,310,294,294,
294,294,294,294,310,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,310,- 1,- 1,310,311,- 1,311,311,311,311,
311,311,311,311,311,311,310,- 1,- 1,- 1,- 1,- 1,- 1,310,- 1,- 1,- 1,311,- 1,- 1,- 1,- 1,310,-
1,311,310,- 1,- 1,- 1,- 1,- 1,- 1,- 1,311,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
311,- 1,- 1,- 1,- 1,- 1,- 1,311,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,311,316,316,316,316,316,316,
316,316,316,316,- 1,- 1,- 1,- 1,- 1,- 1,- 1,316,316,316,316,316,316,316,316,316,316,316,
316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,- 1,- 1,- 1,- 1,316,- 1,
316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,316,
316,316,316,316,316,316,322,322,322,322,322,322,322,322,322,322,- 1,- 1,- 1,- 1,- 1,-
1,- 1,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,- 1,- 1,- 1,- 1,322,- 1,322,322,322,322,322,322,322,322,
322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,322,332,332,
332,332,332,332,332,332,332,332,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,332,332,- 1,- 1,-
1,- 1,333,332,333,333,333,333,333,333,333,333,333,333,338,338,338,338,338,338,338,
338,338,338,- 1,333,- 1,- 1,332,332,- 1,- 1,333,- 1,- 1,332,338,- 1,- 1,- 1,- 1,333,338,- 1,
339,339,339,339,339,339,339,339,339,339,- 1,- 1,- 1,333,- 1,- 1,- 1,- 1,- 1,- 1,333,339,
339,- 1,338,- 1,- 1,- 1,339,333,338,- 1,- 1,342,342,342,342,342,342,342,342,342,342,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,339,339,342,- 1,- 1,- 1,- 1,339,342,343,- 1,343,343,343,
343,343,343,343,343,343,343,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,343,- 1,342,- 1,- 1,- 1,
- 1,343,342,- 1,- 1,- 1,- 1,- 1,- 1,344,343,344,344,344,344,344,344,344,344,344,344,- 1,
- 1,- 1,- 1,- 1,343,- 1,- 1,- 1,- 1,- 1,344,343,- 1,- 1,- 1,- 1,- 1,344,- 1,- 1,343,- 1,- 1,- 1,- 1,
- 1,344,- 1,- 1,358,358,358,358,358,358,358,358,358,358,- 1,- 1,- 1,344,- 1,- 1,- 1,- 1,- 1,
- 1,344,358,358,- 1,- 1,- 1,- 1,- 1,358,344,347,347,347,347,347,347,347,347,347,347,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,347,347,347,347,347,347,358,358,- 1,- 1,- 1,- 1,- 1,358,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,348,348,348,348,348,348,348,348,348,348,- 1,347,347,347,347,347,347,348,
348,348,348,348,348,- 1,- 1,- 1,367,- 1,348,- 1,- 1,367,- 1,- 1,- 1,- 1,- 1,348,- 1,- 1,367,
367,367,367,367,367,367,367,- 1,348,348,348,348,348,348,367,- 1,- 1,- 1,- 1,348,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,348,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,367,- 1,- 1,- 1,- 1,
367,367,- 1,- 1,- 1,367,- 1,- 1,- 1,- 1,- 1,- 1,- 1,367,- 1,- 1,- 1,367,- 1,367,- 1,367,- 1,367,
380,380,380,380,380,380,380,380,380,380,- 1,- 1,- 1,- 1,- 1,- 1,- 1,380,380,380,380,380,
380,380,380,380,380,380,380,380,380,380,380,380,380,380,380,380,380,380,380,380,
380,- 1,- 1,- 1,- 1,- 1,- 1,380,380,380,380,380,380,380,380,380,380,380,380,380,380,
380,380,380,380,380,380,380,380,380,380,380,380,381,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,381,
381,381,381,381,381,381,381,381,381,- 1,- 1,- 1,- 1,- 1,- 1,- 1,381,381,381,381,381,381,
381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,
- 1,- 1,- 1,- 1,- 1,- 1,381,381,381,381,381,381,381,381,381,381,381,381,381,381,381,
381,381,381,381,381,381,381,381,381,381,381,394,- 1,- 1,394,- 1,- 1,- 1,394,394,394,
394,394,394,394,394,394,394,- 1,- 1,- 1,- 1,- 1,- 1,- 1,394,394,394,394,394,394,394,394,
394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,- 1,- 1,- 1,
- 1,394,- 1,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,394,
394,394,394,394,394,394,394,394,394,396,- 1,- 1,- 1,- 1,- 1,- 1,- 1,396,396,396,396,396,
396,396,396,396,396,- 1,- 1,- 1,- 1,- 1,- 1,- 1,396,396,396,396,396,396,396,396,396,396,
396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,- 1,- 1,- 1,- 1,396,
- 1,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,396,
396,396,396,396,396,396,396,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,-
1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,
- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1,- 1};int Cyc_lex_engine(int start_state,struct Cyc_Lexing_lexbuf*
lbuf){int state;int base;int backtrk;int c;state=start_state;if(state >= 0){lbuf->lex_last_pos=(
lbuf->lex_start_pos=lbuf->lex_curr_pos);lbuf->lex_last_action=- 1;}else{state=(-
state)- 1;}while(1){base=Cyc_lex_base[_check_known_subscript_notnull(406,state)];
if(base < 0)return(- base)- 1;backtrk=Cyc_lex_backtrk[
_check_known_subscript_notnull(406,state)];if(backtrk >= 0){lbuf->lex_last_pos=
lbuf->lex_curr_pos;lbuf->lex_last_action=backtrk;}if(lbuf->lex_curr_pos >= lbuf->lex_buffer_len){
if(!lbuf->lex_eof_reached)return(- state)- 1;else{c=256;}}else{c=(int)*((char*)
_check_dynforward_subscript(lbuf->lex_buffer,sizeof(char),lbuf->lex_curr_pos ++));
if(c == - 1)c=256;}if(Cyc_lex_check[_check_known_subscript_notnull(3481,base + c)]
== state)state=Cyc_lex_trans[_check_known_subscript_notnull(3481,base + c)];else{
state=Cyc_lex_default[_check_known_subscript_notnull(406,state)];}if(state < 0){
lbuf->lex_curr_pos=lbuf->lex_last_pos;if(lbuf->lex_last_action == - 1)(int)_throw((
void*)({struct Cyc_Lexing_Error_struct*_tmp4=_cycalloc(sizeof(*_tmp4));_tmp4[0]=({
struct Cyc_Lexing_Error_struct _tmp5;_tmp5.tag=Cyc_Lexing_Error;_tmp5.f1=({const
char*_tmp6="empty token";_tag_dynforward(_tmp6,sizeof(char),_get_zero_arr_size(
_tmp6,12));});_tmp5;});_tmp4;}));else{return lbuf->lex_last_action;}}else{if(c == 
256)lbuf->lex_eof_reached=0;}}}struct _tuple12*Cyc_line_rec(struct Cyc_Lexing_lexbuf*
lexbuf,int lexstate){lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){
case 0: _LL0: Cyc_macroname(lexbuf);for(0;Cyc_current_args != 0;Cyc_current_args=((
struct Cyc_List_List*)_check_null(Cyc_current_args))->tl){Cyc_current_targets=({
struct Cyc_Set_Set**_tmp7=_cycalloc(sizeof(*_tmp7));_tmp7[0]=((struct Cyc_Set_Set*(*)(
struct Cyc_Set_Set*s,struct _dynforward_ptr*elt))Cyc_Set_delete)(*((struct Cyc_Set_Set**)
_check_null(Cyc_current_targets)),(struct _dynforward_ptr*)((struct Cyc_List_List*)
_check_null(Cyc_current_args))->hd);_tmp7;});}return({struct _tuple12*_tmp8=
_cycalloc(sizeof(*_tmp8));_tmp8->f1=(struct _dynforward_ptr*)_check_null(Cyc_current_source);
_tmp8->f2=*((struct Cyc_Set_Set**)_check_null(Cyc_current_targets));_tmp8;});case
1: _LL1: return Cyc_line(lexbuf);case 2: _LL2: return 0;default: _LL3:(lexbuf->refill_buff)(
lexbuf);return Cyc_line_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp9=_cycalloc(sizeof(*_tmp9));_tmp9[0]=({struct Cyc_Lexing_Error_struct _tmpA;
_tmpA.tag=Cyc_Lexing_Error;_tmpA.f1=({const char*_tmpB="some action didn't return!";
_tag_dynforward(_tmpB,sizeof(char),_get_zero_arr_size(_tmpB,27));});_tmpA;});
_tmp9;}));}struct _tuple12*Cyc_line(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_line_rec(
lexbuf,0);}int Cyc_macroname_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){
lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL5: Cyc_current_source=({
struct _dynforward_ptr*_tmpC=_cycalloc(sizeof(*_tmpC));_tmpC[0]=(struct
_dynforward_ptr)Cyc_substring((struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf),0,(
unsigned int)((Cyc_Lexing_lexeme_end(lexbuf)- Cyc_Lexing_lexeme_start(lexbuf))- 
2));_tmpC;});Cyc_current_args=0;Cyc_current_targets=({struct Cyc_Set_Set**_tmpD=
_cycalloc(sizeof(*_tmpD));_tmpD[0]=((struct Cyc_Set_Set*(*)(int(*cmp)(struct
_dynforward_ptr*,struct _dynforward_ptr*)))Cyc_Set_empty)(Cyc_strptrcmp);_tmpD;});
Cyc_token(lexbuf);return 0;case 1: _LL6: Cyc_current_source=({struct _dynforward_ptr*
_tmpE=_cycalloc(sizeof(*_tmpE));_tmpE[0]=(struct _dynforward_ptr)Cyc_substring((
struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf),0,(unsigned int)((Cyc_Lexing_lexeme_end(
lexbuf)- Cyc_Lexing_lexeme_start(lexbuf))- 1));_tmpE;});Cyc_current_args=0;Cyc_current_targets=({
struct Cyc_Set_Set**_tmpF=_cycalloc(sizeof(*_tmpF));_tmpF[0]=((struct Cyc_Set_Set*(*)(
int(*cmp)(struct _dynforward_ptr*,struct _dynforward_ptr*)))Cyc_Set_empty)(Cyc_strptrcmp);
_tmpF;});Cyc_args(lexbuf);return 0;case 2: _LL7: Cyc_current_source=({struct
_dynforward_ptr*_tmp10=_cycalloc(sizeof(*_tmp10));_tmp10[0]=(struct
_dynforward_ptr)Cyc_Lexing_lexeme(lexbuf);_tmp10;});Cyc_current_args=0;Cyc_current_targets=({
struct Cyc_Set_Set**_tmp11=_cycalloc(sizeof(*_tmp11));_tmp11[0]=((struct Cyc_Set_Set*(*)(
int(*cmp)(struct _dynforward_ptr*,struct _dynforward_ptr*)))Cyc_Set_empty)(Cyc_strptrcmp);
_tmp11;});Cyc_token(lexbuf);return 0;default: _LL8:(lexbuf->refill_buff)(lexbuf);
return Cyc_macroname_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp12=_cycalloc(sizeof(*_tmp12));_tmp12[0]=({struct Cyc_Lexing_Error_struct
_tmp13;_tmp13.tag=Cyc_Lexing_Error;_tmp13.f1=({const char*_tmp14="some action didn't return!";
_tag_dynforward(_tmp14,sizeof(char),_get_zero_arr_size(_tmp14,27));});_tmp13;});
_tmp12;}));}int Cyc_macroname(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_macroname_rec(
lexbuf,1);}int Cyc_args_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){lexstate=
Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LLA: {struct
_dynforward_ptr*_tmp15=({struct _dynforward_ptr*_tmp17=_cycalloc(sizeof(*_tmp17));
_tmp17[0]=(struct _dynforward_ptr)Cyc_substring((struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf),0,(unsigned int)((Cyc_Lexing_lexeme_end(lexbuf)- Cyc_Lexing_lexeme_start(
lexbuf))- 2));_tmp17;});Cyc_current_args=({struct Cyc_List_List*_tmp16=_cycalloc(
sizeof(*_tmp16));_tmp16->hd=_tmp15;_tmp16->tl=Cyc_current_args;_tmp16;});return
Cyc_args(lexbuf);}case 1: _LLB: {struct _dynforward_ptr*_tmp18=({struct
_dynforward_ptr*_tmp1A=_cycalloc(sizeof(*_tmp1A));_tmp1A[0]=(struct
_dynforward_ptr)Cyc_substring((struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf),0,(
unsigned int)((Cyc_Lexing_lexeme_end(lexbuf)- Cyc_Lexing_lexeme_start(lexbuf))- 
1));_tmp1A;});Cyc_current_args=({struct Cyc_List_List*_tmp19=_cycalloc(sizeof(*
_tmp19));_tmp19->hd=_tmp18;_tmp19->tl=Cyc_current_args;_tmp19;});return Cyc_token(
lexbuf);}default: _LLC:(lexbuf->refill_buff)(lexbuf);return Cyc_args_rec(lexbuf,
lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*_tmp1B=_cycalloc(
sizeof(*_tmp1B));_tmp1B[0]=({struct Cyc_Lexing_Error_struct _tmp1C;_tmp1C.tag=Cyc_Lexing_Error;
_tmp1C.f1=({const char*_tmp1D="some action didn't return!";_tag_dynforward(_tmp1D,
sizeof(char),_get_zero_arr_size(_tmp1D,27));});_tmp1C;});_tmp1B;}));}int Cyc_args(
struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_args_rec(lexbuf,2);}int Cyc_token_rec(
struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){lexstate=Cyc_lex_engine(lexstate,
lexbuf);switch(lexstate){case 0: _LLE: Cyc_add_target(({struct _dynforward_ptr*
_tmp1E=_cycalloc(sizeof(*_tmp1E));_tmp1E[0]=(struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf);_tmp1E;}));return Cyc_token(lexbuf);case 1: _LLF: return 0;case 2: _LL10: return
Cyc_token(lexbuf);case 3: _LL11: Cyc_string(lexbuf);return Cyc_token(lexbuf);case 4:
_LL12: return Cyc_token(lexbuf);case 5: _LL13: return Cyc_token(lexbuf);case 6: _LL14:
return Cyc_token(lexbuf);case 7: _LL15: return Cyc_token(lexbuf);case 8: _LL16: return
Cyc_token(lexbuf);case 9: _LL17: return Cyc_token(lexbuf);case 10: _LL18: return Cyc_token(
lexbuf);case 11: _LL19: return Cyc_token(lexbuf);case 12: _LL1A: return Cyc_token(lexbuf);
case 13: _LL1B: return Cyc_token(lexbuf);case 14: _LL1C: return Cyc_token(lexbuf);case 15:
_LL1D: return Cyc_token(lexbuf);case 16: _LL1E: return Cyc_token(lexbuf);case 17: _LL1F:
return Cyc_token(lexbuf);case 18: _LL20: return Cyc_token(lexbuf);case 19: _LL21: return
Cyc_token(lexbuf);case 20: _LL22: return Cyc_token(lexbuf);case 21: _LL23: return Cyc_token(
lexbuf);case 22: _LL24: return Cyc_token(lexbuf);case 23: _LL25: return Cyc_token(lexbuf);
case 24: _LL26: return Cyc_token(lexbuf);case 25: _LL27: return Cyc_token(lexbuf);case 26:
_LL28: return Cyc_token(lexbuf);case 27: _LL29: return Cyc_token(lexbuf);case 28: _LL2A:
return Cyc_token(lexbuf);case 29: _LL2B: return Cyc_token(lexbuf);case 30: _LL2C: return
Cyc_token(lexbuf);case 31: _LL2D: return Cyc_token(lexbuf);case 32: _LL2E: return Cyc_token(
lexbuf);case 33: _LL2F: return Cyc_token(lexbuf);case 34: _LL30: return Cyc_token(lexbuf);
case 35: _LL31: return Cyc_token(lexbuf);case 36: _LL32: return Cyc_token(lexbuf);case 37:
_LL33: return Cyc_token(lexbuf);case 38: _LL34: return Cyc_token(lexbuf);case 39: _LL35:
return Cyc_token(lexbuf);case 40: _LL36: return Cyc_token(lexbuf);case 41: _LL37: return
Cyc_token(lexbuf);case 42: _LL38: return Cyc_token(lexbuf);case 43: _LL39: return Cyc_token(
lexbuf);case 44: _LL3A: return Cyc_token(lexbuf);case 45: _LL3B: return Cyc_token(lexbuf);
case 46: _LL3C: return Cyc_token(lexbuf);case 47: _LL3D: return Cyc_token(lexbuf);case 48:
_LL3E: return Cyc_token(lexbuf);default: _LL3F:(lexbuf->refill_buff)(lexbuf);return
Cyc_token_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp1F=_cycalloc(sizeof(*_tmp1F));_tmp1F[0]=({struct Cyc_Lexing_Error_struct
_tmp20;_tmp20.tag=Cyc_Lexing_Error;_tmp20.f1=({const char*_tmp21="some action didn't return!";
_tag_dynforward(_tmp21,sizeof(char),_get_zero_arr_size(_tmp21,27));});_tmp20;});
_tmp1F;}));}int Cyc_token(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_token_rec(
lexbuf,3);}int Cyc_string_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){
lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL41: return Cyc_string(
lexbuf);case 1: _LL42: return 0;case 2: _LL43: return Cyc_string(lexbuf);case 3: _LL44:
return Cyc_string(lexbuf);case 4: _LL45: return Cyc_string(lexbuf);case 5: _LL46: return
Cyc_string(lexbuf);case 6: _LL47: return Cyc_string(lexbuf);case 7: _LL48: return 0;case
8: _LL49: return 0;case 9: _LL4A: return Cyc_string(lexbuf);default: _LL4B:(lexbuf->refill_buff)(
lexbuf);return Cyc_string_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp22=_cycalloc(sizeof(*_tmp22));_tmp22[0]=({struct Cyc_Lexing_Error_struct
_tmp23;_tmp23.tag=Cyc_Lexing_Error;_tmp23.f1=({const char*_tmp24="some action didn't return!";
_tag_dynforward(_tmp24,sizeof(char),_get_zero_arr_size(_tmp24,27));});_tmp23;});
_tmp22;}));}int Cyc_string(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_string_rec(
lexbuf,4);}int Cyc_slurp_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){lexstate=
Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL4D: return 0;case 1: _LL4E:
Cyc_fputc((int)'"',(struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));while(Cyc_slurp_string(
lexbuf)){;}return 1;case 2: _LL4F: Cyc_fputs((const char*)"*__IGNORE_FOR_CYCLONE_MALLOC(",(
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));({void*_tmp25[0]={};Cyc_log(({
const char*_tmp26="Warning: declaration of malloc sidestepped\n";_tag_dynforward(
_tmp26,sizeof(char),_get_zero_arr_size(_tmp26,44));}),_tag_dynforward(_tmp25,
sizeof(void*),0));});return 1;case 3: _LL50: Cyc_fputs((const char*)" __IGNORE_FOR_CYCLONE_MALLOC(",(
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));({void*_tmp27[0]={};Cyc_log(({
const char*_tmp28="Warning: declaration of malloc sidestepped\n";_tag_dynforward(
_tmp28,sizeof(char),_get_zero_arr_size(_tmp28,44));}),_tag_dynforward(_tmp27,
sizeof(void*),0));});return 1;case 4: _LL51: Cyc_fputs((const char*)"*__IGNORE_FOR_CYCLONE_CALLOC(",(
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));({void*_tmp29[0]={};Cyc_log(({
const char*_tmp2A="Warning: declaration of calloc sidestepped\n";_tag_dynforward(
_tmp2A,sizeof(char),_get_zero_arr_size(_tmp2A,44));}),_tag_dynforward(_tmp29,
sizeof(void*),0));});return 1;case 5: _LL52: Cyc_fputs((const char*)" __IGNORE_FOR_CYCLONE_CALLOC(",(
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));({void*_tmp2B[0]={};Cyc_log(({
const char*_tmp2C="Warning: declaration of calloc sidestepped\n";_tag_dynforward(
_tmp2C,sizeof(char),_get_zero_arr_size(_tmp2C,44));}),_tag_dynforward(_tmp2B,
sizeof(void*),0));});return 1;case 6: _LL53: Cyc_fputs((const char*)"__region",(
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));({void*_tmp2D[0]={};Cyc_log(({
const char*_tmp2E="Warning: use of region sidestepped\n";_tag_dynforward(_tmp2E,
sizeof(char),_get_zero_arr_size(_tmp2E,36));}),_tag_dynforward(_tmp2D,sizeof(
void*),0));});return 1;case 7: _LL54: return 1;case 8: _LL55: return 1;case 9: _LL56: return
1;case 10: _LL57: return 1;case 11: _LL58: return 1;case 12: _LL59: return 1;case 13: _LL5A:
Cyc_fputs((const char*)"inline",(struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));
return 1;case 14: _LL5B: Cyc_fputs((const char*)"inline",(struct Cyc___cycFILE*)
_check_null(Cyc_slurp_out));return 1;case 15: _LL5C: Cyc_fputs((const char*)"const",(
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));return 1;case 16: _LL5D: Cyc_fputs((
const char*)"const",(struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));return 1;
case 17: _LL5E: Cyc_fputs((const char*)"int",(struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));
return 1;case 18: _LL5F: return 1;case 19: _LL60: Cyc_parens_to_match=1;while(Cyc_asm(
lexbuf)){;}Cyc_fputs((const char*)"0",(struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));({
void*_tmp2F[0]={};Cyc_log(({const char*_tmp30="Warning: replacing use of __asm__ with 0\n";
_tag_dynforward(_tmp30,sizeof(char),_get_zero_arr_size(_tmp30,42));}),
_tag_dynforward(_tmp2F,sizeof(void*),0));});return 1;case 20: _LL61: Cyc_fputc((int)
Cyc_Lexing_lexeme_char(lexbuf,0),(struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));
return 1;default: _LL62:(lexbuf->refill_buff)(lexbuf);return Cyc_slurp_rec(lexbuf,
lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*_tmp31=_cycalloc(
sizeof(*_tmp31));_tmp31[0]=({struct Cyc_Lexing_Error_struct _tmp32;_tmp32.tag=Cyc_Lexing_Error;
_tmp32.f1=({const char*_tmp33="some action didn't return!";_tag_dynforward(_tmp33,
sizeof(char),_get_zero_arr_size(_tmp33,27));});_tmp32;});_tmp31;}));}int Cyc_slurp(
struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_slurp_rec(lexbuf,5);}int Cyc_slurp_string_rec(
struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){lexstate=Cyc_lex_engine(lexstate,
lexbuf);switch(lexstate){case 0: _LL64: return 0;case 1: _LL65: Cyc_fputc((int)'"',(
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out));return 0;case 2: _LL66:({void*
_tmp34[0]={};Cyc_log(({const char*_tmp35="Warning: unclosed string\n";
_tag_dynforward(_tmp35,sizeof(char),_get_zero_arr_size(_tmp35,26));}),
_tag_dynforward(_tmp34,sizeof(void*),0));});({struct Cyc_String_pa_struct _tmp38;
_tmp38.tag=0;_tmp38.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf));{void*_tmp36[1]={& _tmp38};Cyc_fprintf((struct Cyc___cycFILE*)_check_null(
Cyc_slurp_out),({const char*_tmp37="%s";_tag_dynforward(_tmp37,sizeof(char),
_get_zero_arr_size(_tmp37,3));}),_tag_dynforward(_tmp36,sizeof(void*),1));}});
return 1;case 3: _LL67:({struct Cyc_String_pa_struct _tmp3B;_tmp3B.tag=0;_tmp3B.f1=(
struct _dynforward_ptr)((struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));{void*
_tmp39[1]={& _tmp3B};Cyc_fprintf((struct Cyc___cycFILE*)_check_null(Cyc_slurp_out),({
const char*_tmp3A="%s";_tag_dynforward(_tmp3A,sizeof(char),_get_zero_arr_size(
_tmp3A,3));}),_tag_dynforward(_tmp39,sizeof(void*),1));}});return 1;case 4: _LL68:({
struct Cyc_String_pa_struct _tmp3E;_tmp3E.tag=0;_tmp3E.f1=(struct _dynforward_ptr)((
struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));{void*_tmp3C[1]={& _tmp3E};Cyc_fprintf((
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out),({const char*_tmp3D="%s";
_tag_dynforward(_tmp3D,sizeof(char),_get_zero_arr_size(_tmp3D,3));}),
_tag_dynforward(_tmp3C,sizeof(void*),1));}});return 1;case 5: _LL69:({struct Cyc_String_pa_struct
_tmp41;_tmp41.tag=0;_tmp41.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf));{void*_tmp3F[1]={& _tmp41};Cyc_fprintf((struct Cyc___cycFILE*)_check_null(
Cyc_slurp_out),({const char*_tmp40="%s";_tag_dynforward(_tmp40,sizeof(char),
_get_zero_arr_size(_tmp40,3));}),_tag_dynforward(_tmp3F,sizeof(void*),1));}});
return 1;case 6: _LL6A:({struct Cyc_String_pa_struct _tmp44;_tmp44.tag=0;_tmp44.f1=(
struct _dynforward_ptr)((struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));{void*
_tmp42[1]={& _tmp44};Cyc_fprintf((struct Cyc___cycFILE*)_check_null(Cyc_slurp_out),({
const char*_tmp43="%s";_tag_dynforward(_tmp43,sizeof(char),_get_zero_arr_size(
_tmp43,3));}),_tag_dynforward(_tmp42,sizeof(void*),1));}});return 1;case 7: _LL6B:({
struct Cyc_String_pa_struct _tmp47;_tmp47.tag=0;_tmp47.f1=(struct _dynforward_ptr)((
struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));{void*_tmp45[1]={& _tmp47};Cyc_fprintf((
struct Cyc___cycFILE*)_check_null(Cyc_slurp_out),({const char*_tmp46="%s";
_tag_dynforward(_tmp46,sizeof(char),_get_zero_arr_size(_tmp46,3));}),
_tag_dynforward(_tmp45,sizeof(void*),1));}});return 1;case 8: _LL6C:({struct Cyc_String_pa_struct
_tmp4A;_tmp4A.tag=0;_tmp4A.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf));{void*_tmp48[1]={& _tmp4A};Cyc_fprintf((struct Cyc___cycFILE*)_check_null(
Cyc_slurp_out),({const char*_tmp49="%s";_tag_dynforward(_tmp49,sizeof(char),
_get_zero_arr_size(_tmp49,3));}),_tag_dynforward(_tmp48,sizeof(void*),1));}});
return 1;default: _LL6D:(lexbuf->refill_buff)(lexbuf);return Cyc_slurp_string_rec(
lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*_tmp4B=
_cycalloc(sizeof(*_tmp4B));_tmp4B[0]=({struct Cyc_Lexing_Error_struct _tmp4C;
_tmp4C.tag=Cyc_Lexing_Error;_tmp4C.f1=({const char*_tmp4D="some action didn't return!";
_tag_dynforward(_tmp4D,sizeof(char),_get_zero_arr_size(_tmp4D,27));});_tmp4C;});
_tmp4B;}));}int Cyc_slurp_string(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_slurp_string_rec(
lexbuf,6);}int Cyc_asm_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){lexstate=
Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL6F: return 0;case 1: _LL70:
if(Cyc_parens_to_match == 1)return 0;Cyc_parens_to_match --;return 1;case 2: _LL71: Cyc_parens_to_match
++;return 1;case 3: _LL72: while(Cyc_asm_string(lexbuf)){;}return 1;case 4: _LL73:
while(Cyc_asm_comment(lexbuf)){;}return 1;case 5: _LL74: return 1;case 6: _LL75: return 1;
default: _LL76:(lexbuf->refill_buff)(lexbuf);return Cyc_asm_rec(lexbuf,lexstate);}(
int)_throw((void*)({struct Cyc_Lexing_Error_struct*_tmp4E=_cycalloc(sizeof(*
_tmp4E));_tmp4E[0]=({struct Cyc_Lexing_Error_struct _tmp4F;_tmp4F.tag=Cyc_Lexing_Error;
_tmp4F.f1=({const char*_tmp50="some action didn't return!";_tag_dynforward(_tmp50,
sizeof(char),_get_zero_arr_size(_tmp50,27));});_tmp4F;});_tmp4E;}));}int Cyc_asm(
struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_asm_rec(lexbuf,7);}int Cyc_asm_string_rec(
struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){lexstate=Cyc_lex_engine(lexstate,
lexbuf);switch(lexstate){case 0: _LL78:({void*_tmp51[0]={};Cyc_log(({const char*
_tmp52="Warning: unclosed string\n";_tag_dynforward(_tmp52,sizeof(char),
_get_zero_arr_size(_tmp52,26));}),_tag_dynforward(_tmp51,sizeof(void*),0));});
return 0;case 1: _LL79: return 0;case 2: _LL7A:({void*_tmp53[0]={};Cyc_log(({const char*
_tmp54="Warning: unclosed string\n";_tag_dynforward(_tmp54,sizeof(char),
_get_zero_arr_size(_tmp54,26));}),_tag_dynforward(_tmp53,sizeof(void*),0));});
return 1;case 3: _LL7B: return 1;case 4: _LL7C: return 1;case 5: _LL7D: return 1;case 6: _LL7E:
return 1;case 7: _LL7F: return 1;case 8: _LL80: return 1;default: _LL81:(lexbuf->refill_buff)(
lexbuf);return Cyc_asm_string_rec(lexbuf,lexstate);}(int)_throw((void*)({struct
Cyc_Lexing_Error_struct*_tmp55=_cycalloc(sizeof(*_tmp55));_tmp55[0]=({struct Cyc_Lexing_Error_struct
_tmp56;_tmp56.tag=Cyc_Lexing_Error;_tmp56.f1=({const char*_tmp57="some action didn't return!";
_tag_dynforward(_tmp57,sizeof(char),_get_zero_arr_size(_tmp57,27));});_tmp56;});
_tmp55;}));}int Cyc_asm_string(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_asm_string_rec(
lexbuf,8);}int Cyc_asm_comment_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){
lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL83:({void*
_tmp58[0]={};Cyc_log(({const char*_tmp59="Warning: unclosed comment\n";
_tag_dynforward(_tmp59,sizeof(char),_get_zero_arr_size(_tmp59,27));}),
_tag_dynforward(_tmp58,sizeof(void*),0));});return 0;case 1: _LL84: return 0;case 2:
_LL85: return 1;default: _LL86:(lexbuf->refill_buff)(lexbuf);return Cyc_asm_comment_rec(
lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*_tmp5A=
_cycalloc(sizeof(*_tmp5A));_tmp5A[0]=({struct Cyc_Lexing_Error_struct _tmp5B;
_tmp5B.tag=Cyc_Lexing_Error;_tmp5B.f1=({const char*_tmp5C="some action didn't return!";
_tag_dynforward(_tmp5C,sizeof(char),_get_zero_arr_size(_tmp5C,27));});_tmp5B;});
_tmp5A;}));}int Cyc_asm_comment(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_asm_comment_rec(
lexbuf,9);}struct _tuple13*Cyc_suck_line_rec(struct Cyc_Lexing_lexbuf*lexbuf,int
lexstate){lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL88:
Cyc_current_line=({const char*_tmp5D="#define ";_tag_dynforward(_tmp5D,sizeof(
char),_get_zero_arr_size(_tmp5D,9));});Cyc_suck_macroname(lexbuf);return({struct
_tuple13*_tmp5E=_cycalloc(sizeof(*_tmp5E));_tmp5E->f1=Cyc_current_line;_tmp5E->f2=(
struct _dynforward_ptr*)_check_null(Cyc_current_source);_tmp5E;});case 1: _LL89:
return Cyc_suck_line(lexbuf);case 2: _LL8A: return 0;default: _LL8B:(lexbuf->refill_buff)(
lexbuf);return Cyc_suck_line_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp5F=_cycalloc(sizeof(*_tmp5F));_tmp5F[0]=({struct Cyc_Lexing_Error_struct
_tmp60;_tmp60.tag=Cyc_Lexing_Error;_tmp60.f1=({const char*_tmp61="some action didn't return!";
_tag_dynforward(_tmp61,sizeof(char),_get_zero_arr_size(_tmp61,27));});_tmp60;});
_tmp5F;}));}struct _tuple13*Cyc_suck_line(struct Cyc_Lexing_lexbuf*lexbuf){return
Cyc_suck_line_rec(lexbuf,10);}int Cyc_suck_macroname_rec(struct Cyc_Lexing_lexbuf*
lexbuf,int lexstate){lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){
case 0: _LL8D: Cyc_current_source=({struct _dynforward_ptr*_tmp62=_cycalloc(sizeof(*
_tmp62));_tmp62[0]=(struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf);_tmp62;});
Cyc_current_line=(struct _dynforward_ptr)Cyc_strconcat((struct _dynforward_ptr)Cyc_current_line,(
struct _dynforward_ptr)*((struct _dynforward_ptr*)_check_null(Cyc_current_source)));
return Cyc_suck_restofline(lexbuf);default: _LL8E:(lexbuf->refill_buff)(lexbuf);
return Cyc_suck_macroname_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp63=_cycalloc(sizeof(*_tmp63));_tmp63[0]=({struct Cyc_Lexing_Error_struct
_tmp64;_tmp64.tag=Cyc_Lexing_Error;_tmp64.f1=({const char*_tmp65="some action didn't return!";
_tag_dynforward(_tmp65,sizeof(char),_get_zero_arr_size(_tmp65,27));});_tmp64;});
_tmp63;}));}int Cyc_suck_macroname(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_suck_macroname_rec(
lexbuf,11);}int Cyc_suck_restofline_rec(struct Cyc_Lexing_lexbuf*lexbuf,int
lexstate){lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL90:
Cyc_current_line=(struct _dynforward_ptr)Cyc_strconcat((struct _dynforward_ptr)Cyc_current_line,(
struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));return 0;default: _LL91:(lexbuf->refill_buff)(
lexbuf);return Cyc_suck_restofline_rec(lexbuf,lexstate);}(int)_throw((void*)({
struct Cyc_Lexing_Error_struct*_tmp66=_cycalloc(sizeof(*_tmp66));_tmp66[0]=({
struct Cyc_Lexing_Error_struct _tmp67;_tmp67.tag=Cyc_Lexing_Error;_tmp67.f1=({
const char*_tmp68="some action didn't return!";_tag_dynforward(_tmp68,sizeof(char),
_get_zero_arr_size(_tmp68,27));});_tmp67;});_tmp66;}));}int Cyc_suck_restofline(
struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_suck_restofline_rec(lexbuf,12);}struct
_tuple15*Cyc_spec_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){lexstate=Cyc_lex_engine(
lexstate,lexbuf);switch(lexstate){case 0: _LL93: return Cyc_spec(lexbuf);case 1: _LL94:
Cyc_current_headerfile=(struct _dynforward_ptr)Cyc_substring((struct
_dynforward_ptr)Cyc_Lexing_lexeme(lexbuf),0,(unsigned int)((Cyc_Lexing_lexeme_end(
lexbuf)- Cyc_Lexing_lexeme_start(lexbuf))- 1));Cyc_current_symbols=0;Cyc_current_omit_symbols=
0;Cyc_current_cstubs=0;Cyc_current_cycstubs=0;Cyc_current_hstubs=0;while(Cyc_commands(
lexbuf)){;}Cyc_current_hstubs=((struct Cyc_List_List*(*)(struct Cyc_List_List*x))
Cyc_List_imp_rev)(Cyc_current_hstubs);Cyc_current_cstubs=((struct Cyc_List_List*(*)(
struct Cyc_List_List*x))Cyc_List_imp_rev)(Cyc_current_cstubs);Cyc_current_cycstubs=((
struct Cyc_List_List*(*)(struct Cyc_List_List*x))Cyc_List_imp_rev)(Cyc_current_cycstubs);
return({struct _tuple15*_tmp69=_cycalloc(sizeof(*_tmp69));_tmp69->f1=Cyc_current_headerfile;
_tmp69->f2=Cyc_current_symbols;_tmp69->f3=Cyc_current_omit_symbols;_tmp69->f4=
Cyc_current_hstubs;_tmp69->f5=Cyc_current_cstubs;_tmp69->f6=Cyc_current_cycstubs;
_tmp69;});case 2: _LL95: return Cyc_spec(lexbuf);case 3: _LL96: return 0;case 4: _LL97:({
struct Cyc_Int_pa_struct _tmp6C;_tmp6C.tag=1;_tmp6C.f1=(unsigned long)((int)Cyc_Lexing_lexeme_char(
lexbuf,0));{void*_tmp6A[1]={& _tmp6C};Cyc_fprintf(Cyc_stderr,({const char*_tmp6B="Error in .cys file: expected header file name, found '%c' instead\n";
_tag_dynforward(_tmp6B,sizeof(char),_get_zero_arr_size(_tmp6B,67));}),
_tag_dynforward(_tmp6A,sizeof(void*),1));}});return 0;default: _LL98:(lexbuf->refill_buff)(
lexbuf);return Cyc_spec_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp6D=_cycalloc(sizeof(*_tmp6D));_tmp6D[0]=({struct Cyc_Lexing_Error_struct
_tmp6E;_tmp6E.tag=Cyc_Lexing_Error;_tmp6E.f1=({const char*_tmp6F="some action didn't return!";
_tag_dynforward(_tmp6F,sizeof(char),_get_zero_arr_size(_tmp6F,27));});_tmp6E;});
_tmp6D;}));}struct _tuple15*Cyc_spec(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_spec_rec(
lexbuf,13);}int Cyc_commands_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){
lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LL9A: return 0;
case 1: _LL9B: return 0;case 2: _LL9C: Cyc_snarfed_symbols=0;while(Cyc_snarfsymbols(
lexbuf)){;}Cyc_current_symbols=((struct Cyc_List_List*(*)(struct Cyc_List_List*x,
struct Cyc_List_List*y))Cyc_List_append)(Cyc_snarfed_symbols,Cyc_current_symbols);
return 1;case 3: _LL9D: Cyc_snarfed_symbols=0;while(Cyc_snarfsymbols(lexbuf)){;}Cyc_current_omit_symbols=((
struct Cyc_List_List*(*)(struct Cyc_List_List*x,struct Cyc_List_List*y))Cyc_List_append)(
Cyc_snarfed_symbols,Cyc_current_omit_symbols);return 1;case 4: _LL9E: Cyc_braces_to_match=
1;Cyc_specbuf=(struct Cyc_Buffer_t*)Cyc_Buffer_create(255);while(Cyc_block(lexbuf)){;}{
struct _tuple14*x=({struct _tuple14*_tmp71=_cycalloc(sizeof(*_tmp71));_tmp71->f1=(
struct _dynforward_ptr)_tag_dynforward(0,0,0);_tmp71->f2=(struct _dynforward_ptr)
Cyc_Buffer_contents((struct Cyc_Buffer_t*)_check_null(Cyc_specbuf));_tmp71;});Cyc_current_hstubs=({
struct Cyc_List_List*_tmp70=_cycalloc(sizeof(*_tmp70));_tmp70->hd=x;_tmp70->tl=
Cyc_current_hstubs;_tmp70;});return 1;}case 5: _LL9F: {struct _dynforward_ptr _tmp72=
Cyc_Lexing_lexeme(lexbuf);_dynforward_ptr_inplace_plus(& _tmp72,sizeof(char),(int)
Cyc_strlen(({const char*_tmp73="hstub";_tag_dynforward(_tmp73,sizeof(char),
_get_zero_arr_size(_tmp73,6));})));while(isspace((int)*((char*)
_check_dynforward_subscript(_tmp72,sizeof(char),0)))){
_dynforward_ptr_inplace_plus_post(& _tmp72,sizeof(char),1);}{struct
_dynforward_ptr t=_tmp72;while(!isspace((int)*((char*)_check_dynforward_subscript(
t,sizeof(char),0)))){_dynforward_ptr_inplace_plus_post(& t,sizeof(char),1);}{
struct _dynforward_ptr _tmp74=Cyc_substring((struct _dynforward_ptr)_tmp72,0,(
unsigned int)((t.curr - _tmp72.curr)/ sizeof(char)));Cyc_braces_to_match=1;Cyc_specbuf=(
struct Cyc_Buffer_t*)Cyc_Buffer_create(255);while(Cyc_block(lexbuf)){;}{struct
_tuple14*x=({struct _tuple14*_tmp76=_cycalloc(sizeof(*_tmp76));_tmp76->f1=(struct
_dynforward_ptr)_tmp74;_tmp76->f2=(struct _dynforward_ptr)Cyc_Buffer_contents((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf));_tmp76;});Cyc_current_hstubs=({
struct Cyc_List_List*_tmp75=_cycalloc(sizeof(*_tmp75));_tmp75->hd=x;_tmp75->tl=
Cyc_current_hstubs;_tmp75;});return 1;}}}}case 6: _LLA0: Cyc_braces_to_match=1;Cyc_specbuf=(
struct Cyc_Buffer_t*)Cyc_Buffer_create(255);while(Cyc_block(lexbuf)){;}{struct
_tuple14*x=({struct _tuple14*_tmp78=_cycalloc(sizeof(*_tmp78));_tmp78->f1=(struct
_dynforward_ptr)_tag_dynforward(0,0,0);_tmp78->f2=(struct _dynforward_ptr)Cyc_Buffer_contents((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf));_tmp78;});Cyc_current_cstubs=({
struct Cyc_List_List*_tmp77=_cycalloc(sizeof(*_tmp77));_tmp77->hd=x;_tmp77->tl=
Cyc_current_cstubs;_tmp77;});return 1;}case 7: _LLA1: {struct _dynforward_ptr _tmp79=
Cyc_Lexing_lexeme(lexbuf);_dynforward_ptr_inplace_plus(& _tmp79,sizeof(char),(int)
Cyc_strlen(({const char*_tmp7A="cstub";_tag_dynforward(_tmp7A,sizeof(char),
_get_zero_arr_size(_tmp7A,6));})));while(isspace((int)*((char*)
_check_dynforward_subscript(_tmp79,sizeof(char),0)))){
_dynforward_ptr_inplace_plus_post(& _tmp79,sizeof(char),1);}{struct
_dynforward_ptr t=_tmp79;while(!isspace((int)*((char*)_check_dynforward_subscript(
t,sizeof(char),0)))){_dynforward_ptr_inplace_plus_post(& t,sizeof(char),1);}{
struct _dynforward_ptr _tmp7B=Cyc_substring((struct _dynforward_ptr)_tmp79,0,(
unsigned int)((t.curr - _tmp79.curr)/ sizeof(char)));Cyc_braces_to_match=1;Cyc_specbuf=(
struct Cyc_Buffer_t*)Cyc_Buffer_create(255);while(Cyc_block(lexbuf)){;}{struct
_tuple14*x=({struct _tuple14*_tmp7D=_cycalloc(sizeof(*_tmp7D));_tmp7D->f1=(struct
_dynforward_ptr)_tmp7B;_tmp7D->f2=(struct _dynforward_ptr)Cyc_Buffer_contents((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf));_tmp7D;});Cyc_current_cstubs=({
struct Cyc_List_List*_tmp7C=_cycalloc(sizeof(*_tmp7C));_tmp7C->hd=x;_tmp7C->tl=
Cyc_current_cstubs;_tmp7C;});return 1;}}}}case 8: _LLA2: Cyc_braces_to_match=1;Cyc_specbuf=(
struct Cyc_Buffer_t*)Cyc_Buffer_create(255);while(Cyc_block(lexbuf)){;}{struct
_tuple14*x=({struct _tuple14*_tmp7F=_cycalloc(sizeof(*_tmp7F));_tmp7F->f1=(struct
_dynforward_ptr)_tag_dynforward(0,0,0);_tmp7F->f2=(struct _dynforward_ptr)Cyc_Buffer_contents((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf));_tmp7F;});Cyc_current_cycstubs=({
struct Cyc_List_List*_tmp7E=_cycalloc(sizeof(*_tmp7E));_tmp7E->hd=x;_tmp7E->tl=
Cyc_current_cycstubs;_tmp7E;});return 1;}case 9: _LLA3: {struct _dynforward_ptr
_tmp80=Cyc_Lexing_lexeme(lexbuf);_dynforward_ptr_inplace_plus(& _tmp80,sizeof(
char),(int)Cyc_strlen(({const char*_tmp81="cycstub";_tag_dynforward(_tmp81,
sizeof(char),_get_zero_arr_size(_tmp81,8));})));while(isspace((int)*((char*)
_check_dynforward_subscript(_tmp80,sizeof(char),0)))){
_dynforward_ptr_inplace_plus_post(& _tmp80,sizeof(char),1);}{struct
_dynforward_ptr t=_tmp80;while(!isspace((int)*((char*)_check_dynforward_subscript(
t,sizeof(char),0)))){_dynforward_ptr_inplace_plus_post(& t,sizeof(char),1);}{
struct _dynforward_ptr _tmp82=Cyc_substring((struct _dynforward_ptr)_tmp80,0,(
unsigned int)((t.curr - _tmp80.curr)/ sizeof(char)));Cyc_braces_to_match=1;Cyc_specbuf=(
struct Cyc_Buffer_t*)Cyc_Buffer_create(255);while(Cyc_block(lexbuf)){;}{struct
_tuple14*x=({struct _tuple14*_tmp84=_cycalloc(sizeof(*_tmp84));_tmp84->f1=(struct
_dynforward_ptr)_tmp82;_tmp84->f2=(struct _dynforward_ptr)Cyc_Buffer_contents((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf));_tmp84;});Cyc_current_cycstubs=({
struct Cyc_List_List*_tmp83=_cycalloc(sizeof(*_tmp83));_tmp83->hd=x;_tmp83->tl=
Cyc_current_cycstubs;_tmp83;});return 1;}}}}case 10: _LLA4: Cyc_braces_to_match=1;
Cyc_specbuf=(struct Cyc_Buffer_t*)Cyc_Buffer_create(255);while(Cyc_block(lexbuf)){;}{
struct _dynforward_ptr*x=({struct _dynforward_ptr*_tmp86=_cycalloc(sizeof(*_tmp86));
_tmp86[0]=(struct _dynforward_ptr)Cyc_Buffer_contents((struct Cyc_Buffer_t*)
_check_null(Cyc_specbuf));_tmp86;});Cyc_current_cpp=({struct Cyc_List_List*_tmp85=
_cycalloc(sizeof(*_tmp85));_tmp85->hd=x;_tmp85->tl=Cyc_current_cpp;_tmp85;});
return 1;}case 11: _LLA5: return 1;case 12: _LLA6: return 1;case 13: _LLA7:({struct Cyc_Int_pa_struct
_tmp89;_tmp89.tag=1;_tmp89.f1=(unsigned long)((int)Cyc_Lexing_lexeme_char(lexbuf,
0));{void*_tmp87[1]={& _tmp89};Cyc_fprintf(Cyc_stderr,({const char*_tmp88="Error in .cys file: expected command, found '%c' instead\n";
_tag_dynforward(_tmp88,sizeof(char),_get_zero_arr_size(_tmp88,58));}),
_tag_dynforward(_tmp87,sizeof(void*),1));}});return 0;default: _LLA8:(lexbuf->refill_buff)(
lexbuf);return Cyc_commands_rec(lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*
_tmp8A=_cycalloc(sizeof(*_tmp8A));_tmp8A[0]=({struct Cyc_Lexing_Error_struct
_tmp8B;_tmp8B.tag=Cyc_Lexing_Error;_tmp8B.f1=({const char*_tmp8C="some action didn't return!";
_tag_dynforward(_tmp8C,sizeof(char),_get_zero_arr_size(_tmp8C,27));});_tmp8B;});
_tmp8A;}));}int Cyc_commands(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_commands_rec(
lexbuf,14);}int Cyc_snarfsymbols_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){
lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LLAA: Cyc_snarfed_symbols=({
struct Cyc_List_List*_tmp8D=_cycalloc(sizeof(*_tmp8D));_tmp8D->hd=({struct
_dynforward_ptr*_tmp8E=_cycalloc(sizeof(*_tmp8E));_tmp8E[0]=(struct
_dynforward_ptr)Cyc_Lexing_lexeme(lexbuf);_tmp8E;});_tmp8D->tl=Cyc_snarfed_symbols;
_tmp8D;});return 1;case 1: _LLAB: return 1;case 2: _LLAC: return 0;case 3: _LLAD:({void*
_tmp8F[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp90="Error in .cys file: unexpected end-of-file\n";
_tag_dynforward(_tmp90,sizeof(char),_get_zero_arr_size(_tmp90,44));}),
_tag_dynforward(_tmp8F,sizeof(void*),0));});return 0;case 4: _LLAE:({struct Cyc_Int_pa_struct
_tmp93;_tmp93.tag=1;_tmp93.f1=(unsigned long)((int)Cyc_Lexing_lexeme_char(lexbuf,
0));{void*_tmp91[1]={& _tmp93};Cyc_fprintf(Cyc_stderr,({const char*_tmp92="Error in .cys file: expected symbol, found '%c' instead\n";
_tag_dynforward(_tmp92,sizeof(char),_get_zero_arr_size(_tmp92,57));}),
_tag_dynforward(_tmp91,sizeof(void*),1));}});return 0;default: _LLAF:(lexbuf->refill_buff)(
lexbuf);return Cyc_snarfsymbols_rec(lexbuf,lexstate);}(int)_throw((void*)({struct
Cyc_Lexing_Error_struct*_tmp94=_cycalloc(sizeof(*_tmp94));_tmp94[0]=({struct Cyc_Lexing_Error_struct
_tmp95;_tmp95.tag=Cyc_Lexing_Error;_tmp95.f1=({const char*_tmp96="some action didn't return!";
_tag_dynforward(_tmp96,sizeof(char),_get_zero_arr_size(_tmp96,27));});_tmp95;});
_tmp94;}));}int Cyc_snarfsymbols(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_snarfsymbols_rec(
lexbuf,15);}int Cyc_block_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){
lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LLB1:({void*
_tmp97[0]={};Cyc_log(({const char*_tmp98="Warning: unclosed brace\n";
_tag_dynforward(_tmp98,sizeof(char),_get_zero_arr_size(_tmp98,25));}),
_tag_dynforward(_tmp97,sizeof(void*),0));});return 0;case 1: _LLB2: if(Cyc_braces_to_match
== 1)return 0;Cyc_braces_to_match --;Cyc_Buffer_add_char((struct Cyc_Buffer_t*)
_check_null(Cyc_specbuf),'}');return 1;case 2: _LLB3: Cyc_braces_to_match ++;Cyc_Buffer_add_char((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),'{');return 1;case 3: _LLB4: Cyc_Buffer_add_char((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),'"');while(Cyc_block_string(lexbuf)){;}
return 1;case 4: _LLB5: Cyc_Buffer_add_string((struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),({
const char*_tmp99="/*";_tag_dynforward(_tmp99,sizeof(char),_get_zero_arr_size(
_tmp99,3));}));while(Cyc_block_comment(lexbuf)){;}return 1;case 5: _LLB6: Cyc_Buffer_add_string((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),(struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf));return 1;case 6: _LLB7: Cyc_Buffer_add_char((struct Cyc_Buffer_t*)
_check_null(Cyc_specbuf),Cyc_Lexing_lexeme_char(lexbuf,0));return 1;default: _LLB8:(
lexbuf->refill_buff)(lexbuf);return Cyc_block_rec(lexbuf,lexstate);}(int)_throw((
void*)({struct Cyc_Lexing_Error_struct*_tmp9A=_cycalloc(sizeof(*_tmp9A));_tmp9A[0]=({
struct Cyc_Lexing_Error_struct _tmp9B;_tmp9B.tag=Cyc_Lexing_Error;_tmp9B.f1=({
const char*_tmp9C="some action didn't return!";_tag_dynforward(_tmp9C,sizeof(char),
_get_zero_arr_size(_tmp9C,27));});_tmp9B;});_tmp9A;}));}int Cyc_block(struct Cyc_Lexing_lexbuf*
lexbuf){return Cyc_block_rec(lexbuf,16);}int Cyc_block_string_rec(struct Cyc_Lexing_lexbuf*
lexbuf,int lexstate){lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){
case 0: _LLBA:({void*_tmp9D[0]={};Cyc_log(({const char*_tmp9E="Warning: unclosed string\n";
_tag_dynforward(_tmp9E,sizeof(char),_get_zero_arr_size(_tmp9E,26));}),
_tag_dynforward(_tmp9D,sizeof(void*),0));});return 0;case 1: _LLBB: Cyc_Buffer_add_char((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),'"');return 0;case 2: _LLBC:({void*
_tmp9F[0]={};Cyc_log(({const char*_tmpA0="Warning: unclosed string\n";
_tag_dynforward(_tmpA0,sizeof(char),_get_zero_arr_size(_tmpA0,26));}),
_tag_dynforward(_tmp9F,sizeof(void*),0));});Cyc_Buffer_add_string((struct Cyc_Buffer_t*)
_check_null(Cyc_specbuf),(struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));
return 1;case 3: _LLBD: Cyc_Buffer_add_string((struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),(
struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));return 1;case 4: _LLBE: Cyc_Buffer_add_string((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),(struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf));return 1;case 5: _LLBF: Cyc_Buffer_add_string((struct Cyc_Buffer_t*)
_check_null(Cyc_specbuf),(struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));
return 1;case 6: _LLC0: Cyc_Buffer_add_string((struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),(
struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));return 1;case 7: _LLC1: Cyc_Buffer_add_string((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),(struct _dynforward_ptr)Cyc_Lexing_lexeme(
lexbuf));return 1;case 8: _LLC2: Cyc_Buffer_add_string((struct Cyc_Buffer_t*)
_check_null(Cyc_specbuf),(struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));
return 1;default: _LLC3:(lexbuf->refill_buff)(lexbuf);return Cyc_block_string_rec(
lexbuf,lexstate);}(int)_throw((void*)({struct Cyc_Lexing_Error_struct*_tmpA1=
_cycalloc(sizeof(*_tmpA1));_tmpA1[0]=({struct Cyc_Lexing_Error_struct _tmpA2;
_tmpA2.tag=Cyc_Lexing_Error;_tmpA2.f1=({const char*_tmpA3="some action didn't return!";
_tag_dynforward(_tmpA3,sizeof(char),_get_zero_arr_size(_tmpA3,27));});_tmpA2;});
_tmpA1;}));}int Cyc_block_string(struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_block_string_rec(
lexbuf,17);}int Cyc_block_comment_rec(struct Cyc_Lexing_lexbuf*lexbuf,int lexstate){
lexstate=Cyc_lex_engine(lexstate,lexbuf);switch(lexstate){case 0: _LLC5:({void*
_tmpA4[0]={};Cyc_log(({const char*_tmpA5="Warning: unclosed comment\n";
_tag_dynforward(_tmpA5,sizeof(char),_get_zero_arr_size(_tmpA5,27));}),
_tag_dynforward(_tmpA4,sizeof(void*),0));});return 0;case 1: _LLC6: Cyc_Buffer_add_string((
struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),({const char*_tmpA6="*/";
_tag_dynforward(_tmpA6,sizeof(char),_get_zero_arr_size(_tmpA6,3));}));return 0;
case 2: _LLC7: Cyc_Buffer_add_string((struct Cyc_Buffer_t*)_check_null(Cyc_specbuf),(
struct _dynforward_ptr)Cyc_Lexing_lexeme(lexbuf));return 1;default: _LLC8:(lexbuf->refill_buff)(
lexbuf);return Cyc_block_comment_rec(lexbuf,lexstate);}(int)_throw((void*)({
struct Cyc_Lexing_Error_struct*_tmpA7=_cycalloc(sizeof(*_tmpA7));_tmpA7[0]=({
struct Cyc_Lexing_Error_struct _tmpA8;_tmpA8.tag=Cyc_Lexing_Error;_tmpA8.f1=({
const char*_tmpA9="some action didn't return!";_tag_dynforward(_tmpA9,sizeof(char),
_get_zero_arr_size(_tmpA9,27));});_tmpA8;});_tmpA7;}));}int Cyc_block_comment(
struct Cyc_Lexing_lexbuf*lexbuf){return Cyc_block_comment_rec(lexbuf,18);}void Cyc_scan_type(
void*t);struct _tuple16{struct Cyc_List_List*f1;struct Cyc_Absyn_Exp*f2;};void Cyc_scan_exp(
struct Cyc_Absyn_Exp*e){void*_tmpAA=(void*)((struct Cyc_Absyn_Exp*)_check_null(e))->r;
struct _tuple0*_tmpAB;struct _tuple0 _tmpAC;struct _dynforward_ptr*_tmpAD;struct
_tuple0*_tmpAE;struct _tuple0 _tmpAF;struct _dynforward_ptr*_tmpB0;struct Cyc_List_List*
_tmpB1;struct Cyc_Absyn_Exp*_tmpB2;struct Cyc_Absyn_Exp*_tmpB3;struct Cyc_Absyn_Exp*
_tmpB4;struct Cyc_Absyn_Exp*_tmpB5;struct Cyc_Absyn_Exp*_tmpB6;struct Cyc_Absyn_Exp*
_tmpB7;struct Cyc_Absyn_Exp*_tmpB8;struct Cyc_Absyn_Exp*_tmpB9;struct Cyc_Absyn_Exp*
_tmpBA;struct Cyc_Absyn_Exp*_tmpBB;struct Cyc_Absyn_Exp*_tmpBC;struct Cyc_Absyn_Exp*
_tmpBD;struct Cyc_Absyn_Exp*_tmpBE;struct Cyc_Absyn_Exp*_tmpBF;struct Cyc_Absyn_Exp*
_tmpC0;struct Cyc_Absyn_Exp*_tmpC1;struct Cyc_Absyn_Exp*_tmpC2;struct Cyc_Absyn_Exp*
_tmpC3;struct Cyc_List_List*_tmpC4;struct Cyc_Absyn_Exp*_tmpC5;struct Cyc_List_List*
_tmpC6;void*_tmpC7;struct Cyc_Absyn_Exp*_tmpC8;struct Cyc_Absyn_MallocInfo _tmpC9;
int _tmpCA;struct Cyc_Absyn_Exp*_tmpCB;void**_tmpCC;struct Cyc_Absyn_Exp*_tmpCD;
void*_tmpCE;struct Cyc_Absyn_Exp*_tmpCF;struct _dynforward_ptr*_tmpD0;struct Cyc_Absyn_Exp*
_tmpD1;struct _dynforward_ptr*_tmpD2;void*_tmpD3;void*_tmpD4;struct Cyc_List_List*
_tmpD5;_LLCB: if(*((int*)_tmpAA)!= 1)goto _LLCD;_tmpAB=((struct Cyc_Absyn_Var_e_struct*)
_tmpAA)->f1;_tmpAC=*_tmpAB;_tmpAD=_tmpAC.f2;_LLCC: _tmpB0=_tmpAD;goto _LLCE;_LLCD:
if(*((int*)_tmpAA)!= 2)goto _LLCF;_tmpAE=((struct Cyc_Absyn_UnknownId_e_struct*)
_tmpAA)->f1;_tmpAF=*_tmpAE;_tmpB0=_tmpAF.f2;_LLCE: Cyc_add_target(_tmpB0);return;
_LLCF: if(*((int*)_tmpAA)!= 3)goto _LLD1;_tmpB1=((struct Cyc_Absyn_Primop_e_struct*)
_tmpAA)->f2;_LLD0: for(0;_tmpB1 != 0;_tmpB1=_tmpB1->tl){Cyc_scan_exp((struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_Exp*)_tmpB1->hd));}return;_LLD1: if(*((int*)_tmpAA)!= 25)goto
_LLD3;_tmpB2=((struct Cyc_Absyn_Subscript_e_struct*)_tmpAA)->f1;_tmpB3=((struct
Cyc_Absyn_Subscript_e_struct*)_tmpAA)->f2;_LLD2: _tmpB4=_tmpB2;_tmpB5=_tmpB3;goto
_LLD4;_LLD3: if(*((int*)_tmpAA)!= 9)goto _LLD5;_tmpB4=((struct Cyc_Absyn_SeqExp_e_struct*)
_tmpAA)->f1;_tmpB5=((struct Cyc_Absyn_SeqExp_e_struct*)_tmpAA)->f2;_LLD4: _tmpB6=
_tmpB4;_tmpB7=_tmpB5;goto _LLD6;_LLD5: if(*((int*)_tmpAA)!= 4)goto _LLD7;_tmpB6=((
struct Cyc_Absyn_AssignOp_e_struct*)_tmpAA)->f1;_tmpB7=((struct Cyc_Absyn_AssignOp_e_struct*)
_tmpAA)->f3;_LLD6: Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpB6);Cyc_scan_exp((
struct Cyc_Absyn_Exp*)_tmpB7);return;_LLD7: if(*((int*)_tmpAA)!= 22)goto _LLD9;
_tmpB8=((struct Cyc_Absyn_Deref_e_struct*)_tmpAA)->f1;_LLD8: _tmpB9=_tmpB8;goto
_LLDA;_LLD9: if(*((int*)_tmpAA)!= 19)goto _LLDB;_tmpB9=((struct Cyc_Absyn_Sizeofexp_e_struct*)
_tmpAA)->f1;_LLDA: _tmpBA=_tmpB9;goto _LLDC;_LLDB: if(*((int*)_tmpAA)!= 16)goto
_LLDD;_tmpBA=((struct Cyc_Absyn_Address_e_struct*)_tmpAA)->f1;_LLDC: _tmpBB=_tmpBA;
goto _LLDE;_LLDD: if(*((int*)_tmpAA)!= 5)goto _LLDF;_tmpBB=((struct Cyc_Absyn_Increment_e_struct*)
_tmpAA)->f1;_LLDE: Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpBB);return;_LLDF: if(*((
int*)_tmpAA)!= 6)goto _LLE1;_tmpBC=((struct Cyc_Absyn_Conditional_e_struct*)_tmpAA)->f1;
_tmpBD=((struct Cyc_Absyn_Conditional_e_struct*)_tmpAA)->f2;_tmpBE=((struct Cyc_Absyn_Conditional_e_struct*)
_tmpAA)->f3;_LLE0: Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpBC);Cyc_scan_exp((
struct Cyc_Absyn_Exp*)_tmpBD);Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpBE);return;
_LLE1: if(*((int*)_tmpAA)!= 7)goto _LLE3;_tmpBF=((struct Cyc_Absyn_And_e_struct*)
_tmpAA)->f1;_tmpC0=((struct Cyc_Absyn_And_e_struct*)_tmpAA)->f2;_LLE2: _tmpC1=
_tmpBF;_tmpC2=_tmpC0;goto _LLE4;_LLE3: if(*((int*)_tmpAA)!= 8)goto _LLE5;_tmpC1=((
struct Cyc_Absyn_Or_e_struct*)_tmpAA)->f1;_tmpC2=((struct Cyc_Absyn_Or_e_struct*)
_tmpAA)->f2;_LLE4: Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpC1);Cyc_scan_exp((
struct Cyc_Absyn_Exp*)_tmpC2);return;_LLE5: if(*((int*)_tmpAA)!= 11)goto _LLE7;
_tmpC3=((struct Cyc_Absyn_FnCall_e_struct*)_tmpAA)->f1;_tmpC4=((struct Cyc_Absyn_FnCall_e_struct*)
_tmpAA)->f2;_LLE6: _tmpC5=_tmpC3;_tmpC6=_tmpC4;goto _LLE8;_LLE7: if(*((int*)_tmpAA)
!= 10)goto _LLE9;_tmpC5=((struct Cyc_Absyn_UnknownCall_e_struct*)_tmpAA)->f1;
_tmpC6=((struct Cyc_Absyn_UnknownCall_e_struct*)_tmpAA)->f2;_LLE8: Cyc_scan_exp((
struct Cyc_Absyn_Exp*)_tmpC5);for(0;_tmpC6 != 0;_tmpC6=_tmpC6->tl){Cyc_scan_exp((
struct Cyc_Absyn_Exp*)((struct Cyc_Absyn_Exp*)_tmpC6->hd));}return;_LLE9: if(*((int*)
_tmpAA)!= 15)goto _LLEB;_tmpC7=(void*)((struct Cyc_Absyn_Cast_e_struct*)_tmpAA)->f1;
_tmpC8=((struct Cyc_Absyn_Cast_e_struct*)_tmpAA)->f2;_LLEA: Cyc_scan_type(_tmpC7);
Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpC8);return;_LLEB: if(*((int*)_tmpAA)!= 35)
goto _LLED;_tmpC9=((struct Cyc_Absyn_Malloc_e_struct*)_tmpAA)->f1;_tmpCA=_tmpC9.is_calloc;
_tmpCB=_tmpC9.rgn;_tmpCC=_tmpC9.elt_type;_tmpCD=_tmpC9.num_elts;_LLEC: if(_tmpCB
!= 0)Cyc_scan_exp((struct Cyc_Absyn_Exp*)((struct Cyc_Absyn_Exp*)_tmpCB));if(
_tmpCC != 0)Cyc_scan_type(*_tmpCC);Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpCD);
return;_LLED: if(*((int*)_tmpAA)!= 18)goto _LLEF;_tmpCE=(void*)((struct Cyc_Absyn_Sizeoftyp_e_struct*)
_tmpAA)->f1;_LLEE: Cyc_scan_type(_tmpCE);return;_LLEF: if(*((int*)_tmpAA)!= 23)
goto _LLF1;_tmpCF=((struct Cyc_Absyn_AggrMember_e_struct*)_tmpAA)->f1;_tmpD0=((
struct Cyc_Absyn_AggrMember_e_struct*)_tmpAA)->f2;_LLF0: _tmpD1=_tmpCF;_tmpD2=
_tmpD0;goto _LLF2;_LLF1: if(*((int*)_tmpAA)!= 24)goto _LLF3;_tmpD1=((struct Cyc_Absyn_AggrArrow_e_struct*)
_tmpAA)->f1;_tmpD2=((struct Cyc_Absyn_AggrArrow_e_struct*)_tmpAA)->f2;_LLF2: Cyc_scan_exp((
struct Cyc_Absyn_Exp*)_tmpD1);Cyc_add_target(_tmpD2);return;_LLF3: if(*((int*)
_tmpAA)!= 20)goto _LLF5;_tmpD3=(void*)((struct Cyc_Absyn_Offsetof_e_struct*)_tmpAA)->f1;
_tmpD4=(void*)((struct Cyc_Absyn_Offsetof_e_struct*)_tmpAA)->f2;_LLF4: Cyc_scan_type(
_tmpD3);{void*_tmpD6=_tmpD4;struct _dynforward_ptr*_tmpD7;_LL118: if(*((int*)
_tmpD6)!= 0)goto _LL11A;_tmpD7=((struct Cyc_Absyn_StructField_struct*)_tmpD6)->f1;
_LL119: Cyc_add_target(_tmpD7);goto _LL117;_LL11A: if(*((int*)_tmpD6)!= 1)goto
_LL117;_LL11B: goto _LL117;_LL117:;}return;_LLF5: if(*((int*)_tmpAA)!= 0)goto _LLF7;
_LLF6: return;_LLF7: if(*((int*)_tmpAA)!= 36)goto _LLF9;_tmpD5=((struct Cyc_Absyn_UnresolvedMem_e_struct*)
_tmpAA)->f2;_LLF8: for(0;_tmpD5 != 0;_tmpD5=_tmpD5->tl){struct _tuple16 _tmpD9;
struct Cyc_Absyn_Exp*_tmpDA;struct _tuple16*_tmpD8=(struct _tuple16*)_tmpD5->hd;
_tmpD9=*_tmpD8;_tmpDA=_tmpD9.f2;Cyc_scan_exp((struct Cyc_Absyn_Exp*)_tmpDA);}
return;_LLF9: if(*((int*)_tmpAA)!= 37)goto _LLFB;_LLFA:({void*_tmpDB[0]={};Cyc_fprintf(
Cyc_stderr,({const char*_tmpDC="Error: unexpected Stmt_e\n";_tag_dynforward(
_tmpDC,sizeof(char),_get_zero_arr_size(_tmpDC,26));}),_tag_dynforward(_tmpDB,
sizeof(void*),0));});exit(1);return;_LLFB: if(*((int*)_tmpAA)!= 12)goto _LLFD;
_LLFC:({void*_tmpDD[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmpDE="Error: unexpected Throw_e\n";
_tag_dynforward(_tmpDE,sizeof(char),_get_zero_arr_size(_tmpDE,27));}),
_tag_dynforward(_tmpDD,sizeof(void*),0));});exit(1);return;_LLFD: if(*((int*)
_tmpAA)!= 13)goto _LLFF;_LLFE:({void*_tmpDF[0]={};Cyc_fprintf(Cyc_stderr,({const
char*_tmpE0="Error: unexpected NoInstantiate_e\n";_tag_dynforward(_tmpE0,sizeof(
char),_get_zero_arr_size(_tmpE0,35));}),_tag_dynforward(_tmpDF,sizeof(void*),0));});
exit(1);return;_LLFF: if(*((int*)_tmpAA)!= 14)goto _LL101;_LL100:({void*_tmpE1[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmpE2="Error: unexpected Instantiate_e\n";
_tag_dynforward(_tmpE2,sizeof(char),_get_zero_arr_size(_tmpE2,33));}),
_tag_dynforward(_tmpE1,sizeof(void*),0));});exit(1);return;_LL101: if(*((int*)
_tmpAA)!= 17)goto _LL103;_LL102:({void*_tmpE3[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmpE4="Error: unexpected New_e\n";_tag_dynforward(_tmpE4,sizeof(char),
_get_zero_arr_size(_tmpE4,25));}),_tag_dynforward(_tmpE3,sizeof(void*),0));});
exit(1);return;_LL103: if(*((int*)_tmpAA)!= 21)goto _LL105;_LL104:({void*_tmpE5[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmpE6="Error: unexpected Gentyp_e\n";
_tag_dynforward(_tmpE6,sizeof(char),_get_zero_arr_size(_tmpE6,28));}),
_tag_dynforward(_tmpE5,sizeof(void*),0));});exit(1);return;_LL105: if(*((int*)
_tmpAA)!= 26)goto _LL107;_LL106:({void*_tmpE7[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmpE8="Error: unexpected Tuple_e\n";_tag_dynforward(_tmpE8,sizeof(
char),_get_zero_arr_size(_tmpE8,27));}),_tag_dynforward(_tmpE7,sizeof(void*),0));});
exit(1);return;_LL107: if(*((int*)_tmpAA)!= 27)goto _LL109;_LL108:({void*_tmpE9[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmpEA="Error: unexpected CompoundLit_e\n";
_tag_dynforward(_tmpEA,sizeof(char),_get_zero_arr_size(_tmpEA,33));}),
_tag_dynforward(_tmpE9,sizeof(void*),0));});exit(1);return;_LL109: if(*((int*)
_tmpAA)!= 28)goto _LL10B;_LL10A:({void*_tmpEB[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmpEC="Error: unexpected Array_e\n";_tag_dynforward(_tmpEC,sizeof(
char),_get_zero_arr_size(_tmpEC,27));}),_tag_dynforward(_tmpEB,sizeof(void*),0));});
exit(1);return;_LL10B: if(*((int*)_tmpAA)!= 29)goto _LL10D;_LL10C:({void*_tmpED[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmpEE="Error: unexpected Comprehension_e\n";
_tag_dynforward(_tmpEE,sizeof(char),_get_zero_arr_size(_tmpEE,35));}),
_tag_dynforward(_tmpED,sizeof(void*),0));});exit(1);return;_LL10D: if(*((int*)
_tmpAA)!= 30)goto _LL10F;_LL10E:({void*_tmpEF[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmpF0="Error: unexpected Struct_e\n";_tag_dynforward(_tmpF0,sizeof(
char),_get_zero_arr_size(_tmpF0,28));}),_tag_dynforward(_tmpEF,sizeof(void*),0));});
exit(1);return;_LL10F: if(*((int*)_tmpAA)!= 31)goto _LL111;_LL110:({void*_tmpF1[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmpF2="Error: unexpected AnonStruct_e\n";
_tag_dynforward(_tmpF2,sizeof(char),_get_zero_arr_size(_tmpF2,32));}),
_tag_dynforward(_tmpF1,sizeof(void*),0));});exit(1);return;_LL111: if(*((int*)
_tmpAA)!= 32)goto _LL113;_LL112:({void*_tmpF3[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmpF4="Error: unexpected Tunion_e\n";_tag_dynforward(_tmpF4,sizeof(
char),_get_zero_arr_size(_tmpF4,28));}),_tag_dynforward(_tmpF3,sizeof(void*),0));});
exit(1);return;_LL113: if(*((int*)_tmpAA)!= 33)goto _LL115;_LL114:({void*_tmpF5[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmpF6="Error: unexpected Enum_e\n";
_tag_dynforward(_tmpF6,sizeof(char),_get_zero_arr_size(_tmpF6,26));}),
_tag_dynforward(_tmpF5,sizeof(void*),0));});exit(1);return;_LL115: if(*((int*)
_tmpAA)!= 34)goto _LLCA;_LL116:({void*_tmpF7[0]={};Cyc_fprintf(Cyc_stderr,({const
char*_tmpF8="Error: unexpected AnonEnum_e\n";_tag_dynforward(_tmpF8,sizeof(char),
_get_zero_arr_size(_tmpF8,30));}),_tag_dynforward(_tmpF7,sizeof(void*),0));});
exit(1);return;_LLCA:;}void Cyc_scan_exp_opt(struct Cyc_Absyn_Exp*eo){if((
unsigned int)eo)Cyc_scan_exp(eo);return;}void Cyc_scan_type(void*t){void*_tmpF9=t;
struct Cyc_Absyn_PtrInfo _tmpFA;struct Cyc_Absyn_ArrayInfo _tmpFB;void*_tmpFC;struct
Cyc_Absyn_Exp*_tmpFD;struct Cyc_Absyn_Conref*_tmpFE;struct Cyc_Absyn_FnInfo _tmpFF;
struct Cyc_List_List*_tmp100;struct Cyc_Absyn_AggrInfo _tmp101;void*_tmp102;struct
_tuple0*_tmp103;struct _tuple0 _tmp104;struct _dynforward_ptr*_tmp105;struct _tuple0*
_tmp106;struct _tuple0 _tmp107;struct _dynforward_ptr*_tmp108;_LL11D: if((int)_tmpF9
!= 0)goto _LL11F;_LL11E: goto _LL120;_LL11F: if(_tmpF9 <= (void*)4)goto _LL121;if(*((
int*)_tmpF9)!= 5)goto _LL121;_LL120: goto _LL122;_LL121: if((int)_tmpF9 != 1)goto
_LL123;_LL122: goto _LL124;_LL123: if(_tmpF9 <= (void*)4)goto _LL141;if(*((int*)
_tmpF9)!= 6)goto _LL125;_LL124: return;_LL125: if(*((int*)_tmpF9)!= 4)goto _LL127;
_tmpFA=((struct Cyc_Absyn_PointerType_struct*)_tmpF9)->f1;_LL126: Cyc_scan_type((
void*)_tmpFA.elt_typ);return;_LL127: if(*((int*)_tmpF9)!= 7)goto _LL129;_tmpFB=((
struct Cyc_Absyn_ArrayType_struct*)_tmpF9)->f1;_tmpFC=(void*)_tmpFB.elt_type;
_tmpFD=_tmpFB.num_elts;_tmpFE=_tmpFB.zero_term;_LL128: Cyc_scan_type(_tmpFC);Cyc_scan_exp_opt(
_tmpFD);return;_LL129: if(*((int*)_tmpF9)!= 8)goto _LL12B;_tmpFF=((struct Cyc_Absyn_FnType_struct*)
_tmpF9)->f1;_LL12A: Cyc_scan_type((void*)_tmpFF.ret_typ);{struct Cyc_List_List*
_tmp109=_tmpFF.args;for(0;_tmp109 != 0;_tmp109=_tmp109->tl){struct _tuple1 _tmp10B;
void*_tmp10C;struct _tuple1*_tmp10A=(struct _tuple1*)_tmp109->hd;_tmp10B=*_tmp10A;
_tmp10C=_tmp10B.f3;Cyc_scan_type(_tmp10C);}}if(_tmpFF.cyc_varargs != 0)Cyc_scan_type((
void*)(_tmpFF.cyc_varargs)->type);return;_LL12B: if(*((int*)_tmpF9)!= 11)goto
_LL12D;_tmp100=((struct Cyc_Absyn_AnonAggrType_struct*)_tmpF9)->f2;_LL12C: for(0;
_tmp100 != 0;_tmp100=_tmp100->tl){Cyc_scan_type((void*)((struct Cyc_Absyn_Aggrfield*)
_tmp100->hd)->type);Cyc_scan_exp_opt(((struct Cyc_Absyn_Aggrfield*)_tmp100->hd)->width);}
return;_LL12D: if(*((int*)_tmpF9)!= 13)goto _LL12F;_LL12E: return;_LL12F: if(*((int*)
_tmpF9)!= 10)goto _LL131;_tmp101=((struct Cyc_Absyn_AggrType_struct*)_tmpF9)->f1;
_tmp102=(void*)_tmp101.aggr_info;_LL130: {struct _tuple0*_tmp10E;struct _tuple0
_tmp10F;struct _dynforward_ptr*_tmp110;struct _tuple3 _tmp10D=Cyc_Absyn_aggr_kinded_name(
_tmp102);_tmp10E=_tmp10D.f2;_tmp10F=*_tmp10E;_tmp110=_tmp10F.f2;_tmp105=_tmp110;
goto _LL132;}_LL131: if(*((int*)_tmpF9)!= 12)goto _LL133;_tmp103=((struct Cyc_Absyn_EnumType_struct*)
_tmpF9)->f1;_tmp104=*_tmp103;_tmp105=_tmp104.f2;_LL132: _tmp108=_tmp105;goto
_LL134;_LL133: if(*((int*)_tmpF9)!= 16)goto _LL135;_tmp106=((struct Cyc_Absyn_TypedefType_struct*)
_tmpF9)->f1;_tmp107=*_tmp106;_tmp108=_tmp107.f2;_LL134: Cyc_add_target(_tmp108);
return;_LL135: if(*((int*)_tmpF9)!= 0)goto _LL137;_LL136:({void*_tmp111[0]={};Cyc_fprintf(
Cyc_stderr,({const char*_tmp112="Error: unexpected Evar\n";_tag_dynforward(
_tmp112,sizeof(char),_get_zero_arr_size(_tmp112,24));}),_tag_dynforward(_tmp111,
sizeof(void*),0));});exit(1);return;_LL137: if(*((int*)_tmpF9)!= 1)goto _LL139;
_LL138:({void*_tmp113[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp114="Error: unexpected VarType\n";
_tag_dynforward(_tmp114,sizeof(char),_get_zero_arr_size(_tmp114,27));}),
_tag_dynforward(_tmp113,sizeof(void*),0));});exit(1);return;_LL139: if(*((int*)
_tmpF9)!= 2)goto _LL13B;_LL13A:({void*_tmp115[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp116="Error: unexpected TunionType\n";_tag_dynforward(_tmp116,
sizeof(char),_get_zero_arr_size(_tmp116,30));}),_tag_dynforward(_tmp115,sizeof(
void*),0));});exit(1);return;_LL13B: if(*((int*)_tmpF9)!= 3)goto _LL13D;_LL13C:({
void*_tmp117[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp118="Error: unexpected TunionFieldType\n";
_tag_dynforward(_tmp118,sizeof(char),_get_zero_arr_size(_tmp118,35));}),
_tag_dynforward(_tmp117,sizeof(void*),0));});exit(1);return;_LL13D: if(*((int*)
_tmpF9)!= 9)goto _LL13F;_LL13E:({void*_tmp119[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp11A="Error: unexpected TupleType\n";_tag_dynforward(_tmp11A,
sizeof(char),_get_zero_arr_size(_tmp11A,29));}),_tag_dynforward(_tmp119,sizeof(
void*),0));});exit(1);return;_LL13F: if(*((int*)_tmpF9)!= 15)goto _LL141;_LL140:({
void*_tmp11B[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp11C="Error: unexpected RgnHandleType\n";
_tag_dynforward(_tmp11C,sizeof(char),_get_zero_arr_size(_tmp11C,33));}),
_tag_dynforward(_tmp11B,sizeof(void*),0));});exit(1);return;_LL141: if((int)
_tmpF9 != 2)goto _LL143;_LL142:({void*_tmp11D[0]={};Cyc_fprintf(Cyc_stderr,({const
char*_tmp11E="Error: unexpected HeapRgn\n";_tag_dynforward(_tmp11E,sizeof(char),
_get_zero_arr_size(_tmp11E,27));}),_tag_dynforward(_tmp11D,sizeof(void*),0));});
exit(1);return;_LL143: if((int)_tmpF9 != 3)goto _LL145;_LL144:({void*_tmp11F[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmp120="Error: unexpected UniqueRgn\n";
_tag_dynforward(_tmp120,sizeof(char),_get_zero_arr_size(_tmp120,29));}),
_tag_dynforward(_tmp11F,sizeof(void*),0));});exit(1);return;_LL145: if(_tmpF9 <= (
void*)4)goto _LL147;if(*((int*)_tmpF9)!= 19)goto _LL147;_LL146:({void*_tmp121[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmp122="Error: unexpected AccessEff\n";
_tag_dynforward(_tmp122,sizeof(char),_get_zero_arr_size(_tmp122,29));}),
_tag_dynforward(_tmp121,sizeof(void*),0));});exit(1);return;_LL147: if(_tmpF9 <= (
void*)4)goto _LL149;if(*((int*)_tmpF9)!= 20)goto _LL149;_LL148:({void*_tmp123[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmp124="Error: unexpected JoinEff\n";
_tag_dynforward(_tmp124,sizeof(char),_get_zero_arr_size(_tmp124,27));}),
_tag_dynforward(_tmp123,sizeof(void*),0));});exit(1);return;_LL149: if(_tmpF9 <= (
void*)4)goto _LL14B;if(*((int*)_tmpF9)!= 21)goto _LL14B;_LL14A:({void*_tmp125[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmp126="Error: unexpected RgnsEff\n";
_tag_dynforward(_tmp126,sizeof(char),_get_zero_arr_size(_tmp126,27));}),
_tag_dynforward(_tmp125,sizeof(void*),0));});exit(1);return;_LL14B: if(_tmpF9 <= (
void*)4)goto _LL14D;if(*((int*)_tmpF9)!= 14)goto _LL14D;_LL14C:({void*_tmp127[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmp128="Error: unexpected sizeof_t\n";
_tag_dynforward(_tmp128,sizeof(char),_get_zero_arr_size(_tmp128,28));}),
_tag_dynforward(_tmp127,sizeof(void*),0));});exit(1);return;_LL14D: if(_tmpF9 <= (
void*)4)goto _LL14F;if(*((int*)_tmpF9)!= 18)goto _LL14F;_LL14E:({void*_tmp129[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmp12A="Error: unexpected type integer\n";
_tag_dynforward(_tmp12A,sizeof(char),_get_zero_arr_size(_tmp12A,32));}),
_tag_dynforward(_tmp129,sizeof(void*),0));});exit(1);return;_LL14F: if(_tmpF9 <= (
void*)4)goto _LL11C;if(*((int*)_tmpF9)!= 17)goto _LL11C;_LL150:({void*_tmp12B[0]={};
Cyc_fprintf(Cyc_stderr,({const char*_tmp12C="Error: unexpected tag_t\n";
_tag_dynforward(_tmp12C,sizeof(char),_get_zero_arr_size(_tmp12C,25));}),
_tag_dynforward(_tmp12B,sizeof(void*),0));});exit(1);return;_LL11C:;}struct
_tuple17{struct _dynforward_ptr*f1;struct Cyc_Absyn_Tqual f2;void*f3;};struct
_tuple12*Cyc_scan_decl(struct Cyc_Absyn_Decl*d){Cyc_current_targets=({struct Cyc_Set_Set**
_tmp12D=_cycalloc(sizeof(*_tmp12D));_tmp12D[0]=((struct Cyc_Set_Set*(*)(int(*cmp)(
struct _dynforward_ptr*,struct _dynforward_ptr*)))Cyc_Set_empty)(Cyc_strptrcmp);
_tmp12D;});{void*_tmp12E=(void*)d->r;struct Cyc_Absyn_Vardecl*_tmp12F;struct Cyc_Absyn_Fndecl*
_tmp130;struct Cyc_Absyn_Aggrdecl*_tmp131;struct Cyc_Absyn_Enumdecl*_tmp132;struct
Cyc_Absyn_Typedefdecl*_tmp133;_LL152: if(_tmp12E <= (void*)2)goto _LL15C;if(*((int*)
_tmp12E)!= 0)goto _LL154;_tmp12F=((struct Cyc_Absyn_Var_d_struct*)_tmp12E)->f1;
_LL153: {struct _tuple0 _tmp135;struct _dynforward_ptr*_tmp136;struct _tuple0*
_tmp134=_tmp12F->name;_tmp135=*_tmp134;_tmp136=_tmp135.f2;Cyc_current_source=(
struct _dynforward_ptr*)_tmp136;Cyc_scan_type((void*)_tmp12F->type);Cyc_scan_exp_opt(
_tmp12F->initializer);goto _LL151;}_LL154: if(*((int*)_tmp12E)!= 1)goto _LL156;
_tmp130=((struct Cyc_Absyn_Fn_d_struct*)_tmp12E)->f1;_LL155: {struct _tuple0
_tmp138;struct _dynforward_ptr*_tmp139;struct _tuple0*_tmp137=_tmp130->name;
_tmp138=*_tmp137;_tmp139=_tmp138.f2;Cyc_current_source=(struct _dynforward_ptr*)
_tmp139;Cyc_scan_type((void*)_tmp130->ret_type);{struct Cyc_List_List*_tmp13A=
_tmp130->args;for(0;_tmp13A != 0;_tmp13A=_tmp13A->tl){struct _tuple17 _tmp13C;void*
_tmp13D;struct _tuple17*_tmp13B=(struct _tuple17*)_tmp13A->hd;_tmp13C=*_tmp13B;
_tmp13D=_tmp13C.f3;Cyc_scan_type(_tmp13D);}}if(_tmp130->cyc_varargs != 0)Cyc_scan_type((
void*)((struct Cyc_Absyn_VarargInfo*)_check_null(_tmp130->cyc_varargs))->type);
if(_tmp130->is_inline)({void*_tmp13E[0]={};Cyc_fprintf(Cyc_stderr,({const char*
_tmp13F="Warning: ignoring inline function\n";_tag_dynforward(_tmp13F,sizeof(
char),_get_zero_arr_size(_tmp13F,35));}),_tag_dynforward(_tmp13E,sizeof(void*),0));});
goto _LL151;}_LL156: if(*((int*)_tmp12E)!= 4)goto _LL158;_tmp131=((struct Cyc_Absyn_Aggr_d_struct*)
_tmp12E)->f1;_LL157: {struct _tuple0 _tmp141;struct _dynforward_ptr*_tmp142;struct
_tuple0*_tmp140=_tmp131->name;_tmp141=*_tmp140;_tmp142=_tmp141.f2;Cyc_current_source=(
struct _dynforward_ptr*)_tmp142;if((unsigned int)_tmp131->impl){{struct Cyc_List_List*
_tmp143=((struct Cyc_Absyn_AggrdeclImpl*)_check_null(_tmp131->impl))->fields;for(
0;_tmp143 != 0;_tmp143=_tmp143->tl){struct Cyc_Absyn_Aggrfield*_tmp144=(struct Cyc_Absyn_Aggrfield*)
_tmp143->hd;Cyc_scan_type((void*)_tmp144->type);Cyc_scan_exp_opt(_tmp144->width);}}{
struct Cyc_List_List*_tmp145=((struct Cyc_Absyn_AggrdeclImpl*)_check_null(_tmp131->impl))->fields;
for(0;_tmp145 != 0;_tmp145=_tmp145->tl){;}}}goto _LL151;}_LL158: if(*((int*)_tmp12E)
!= 6)goto _LL15A;_tmp132=((struct Cyc_Absyn_Enum_d_struct*)_tmp12E)->f1;_LL159: {
struct _tuple0 _tmp147;struct _dynforward_ptr*_tmp148;struct _tuple0*_tmp146=_tmp132->name;
_tmp147=*_tmp146;_tmp148=_tmp147.f2;Cyc_current_source=(struct _dynforward_ptr*)
_tmp148;if((unsigned int)_tmp132->fields){{struct Cyc_List_List*_tmp149=(struct
Cyc_List_List*)((struct Cyc_Core_Opt*)_check_null(_tmp132->fields))->v;for(0;
_tmp149 != 0;_tmp149=_tmp149->tl){struct Cyc_Absyn_Enumfield*_tmp14A=(struct Cyc_Absyn_Enumfield*)
_tmp149->hd;Cyc_scan_exp_opt(_tmp14A->tag);}}{struct Cyc_List_List*_tmp14B=(
struct Cyc_List_List*)((struct Cyc_Core_Opt*)_check_null(_tmp132->fields))->v;for(
0;_tmp14B != 0;_tmp14B=_tmp14B->tl){;}}}goto _LL151;}_LL15A: if(*((int*)_tmp12E)!= 
7)goto _LL15C;_tmp133=((struct Cyc_Absyn_Typedef_d_struct*)_tmp12E)->f1;_LL15B: {
struct _tuple0 _tmp14D;struct _dynforward_ptr*_tmp14E;struct _tuple0*_tmp14C=_tmp133->name;
_tmp14D=*_tmp14C;_tmp14E=_tmp14D.f2;Cyc_current_source=(struct _dynforward_ptr*)
_tmp14E;if((unsigned int)_tmp133->defn)Cyc_scan_type((void*)((struct Cyc_Core_Opt*)
_check_null(_tmp133->defn))->v);goto _LL151;}_LL15C: if((int)_tmp12E != 0)goto
_LL15E;_LL15D:({void*_tmp14F[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp150="Error: unexpected __cyclone_port_on__";
_tag_dynforward(_tmp150,sizeof(char),_get_zero_arr_size(_tmp150,38));}),
_tag_dynforward(_tmp14F,sizeof(void*),0));});exit(1);return 0;_LL15E: if((int)
_tmp12E != 1)goto _LL160;_LL15F:({void*_tmp151[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp152="Error: unexpected __cyclone_port_off__";_tag_dynforward(
_tmp152,sizeof(char),_get_zero_arr_size(_tmp152,39));}),_tag_dynforward(_tmp151,
sizeof(void*),0));});exit(1);return 0;_LL160: if(_tmp12E <= (void*)2)goto _LL162;if(*((
int*)_tmp12E)!= 2)goto _LL162;_LL161:({void*_tmp153[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp154="Error: unexpected let declaration\n";_tag_dynforward(_tmp154,
sizeof(char),_get_zero_arr_size(_tmp154,35));}),_tag_dynforward(_tmp153,sizeof(
void*),0));});exit(1);return 0;_LL162: if(_tmp12E <= (void*)2)goto _LL164;if(*((int*)
_tmp12E)!= 5)goto _LL164;_LL163:({void*_tmp155[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp156="Error: unexpected tunion declaration\n";_tag_dynforward(
_tmp156,sizeof(char),_get_zero_arr_size(_tmp156,38));}),_tag_dynforward(_tmp155,
sizeof(void*),0));});exit(1);return 0;_LL164: if(_tmp12E <= (void*)2)goto _LL166;if(*((
int*)_tmp12E)!= 3)goto _LL166;_LL165:({void*_tmp157[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp158="Error: unexpected let declaration\n";_tag_dynforward(_tmp158,
sizeof(char),_get_zero_arr_size(_tmp158,35));}),_tag_dynforward(_tmp157,sizeof(
void*),0));});exit(1);return 0;_LL166: if(_tmp12E <= (void*)2)goto _LL168;if(*((int*)
_tmp12E)!= 8)goto _LL168;_LL167:({void*_tmp159[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp15A="Error: unexpected namespace declaration\n";_tag_dynforward(
_tmp15A,sizeof(char),_get_zero_arr_size(_tmp15A,41));}),_tag_dynforward(_tmp159,
sizeof(void*),0));});exit(1);return 0;_LL168: if(_tmp12E <= (void*)2)goto _LL16A;if(*((
int*)_tmp12E)!= 9)goto _LL16A;_LL169:({void*_tmp15B[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp15C="Error: unexpected using declaration\n";_tag_dynforward(
_tmp15C,sizeof(char),_get_zero_arr_size(_tmp15C,37));}),_tag_dynforward(_tmp15B,
sizeof(void*),0));});exit(1);return 0;_LL16A: if(_tmp12E <= (void*)2)goto _LL16C;if(*((
int*)_tmp12E)!= 10)goto _LL16C;_LL16B:({void*_tmp15D[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp15E="Error: unexpected extern \"C\" declaration\n";_tag_dynforward(
_tmp15E,sizeof(char),_get_zero_arr_size(_tmp15E,42));}),_tag_dynforward(_tmp15D,
sizeof(void*),0));});exit(1);return 0;_LL16C: if(_tmp12E <= (void*)2)goto _LL151;if(*((
int*)_tmp12E)!= 11)goto _LL151;_LL16D:({void*_tmp15F[0]={};Cyc_fprintf(Cyc_stderr,({
const char*_tmp160="Error: unexpected extern \"C include\" declaration\n";
_tag_dynforward(_tmp160,sizeof(char),_get_zero_arr_size(_tmp160,50));}),
_tag_dynforward(_tmp15F,sizeof(void*),0));});exit(1);return 0;_LL151:;}return({
struct _tuple12*_tmp161=_cycalloc(sizeof(*_tmp161));_tmp161->f1=(struct
_dynforward_ptr*)_check_null(Cyc_current_source);_tmp161->f2=*((struct Cyc_Set_Set**)
_check_null(Cyc_current_targets));_tmp161;});}struct Cyc_Hashtable_Table*Cyc_new_deps(){
return((struct Cyc_Hashtable_Table*(*)(int sz,int(*cmp)(struct _dynforward_ptr*,
struct _dynforward_ptr*),int(*hash)(struct _dynforward_ptr*)))Cyc_Hashtable_create)(
107,Cyc_strptrcmp,Cyc_Hashtable_hash_stringptr);}struct Cyc_Set_Set*Cyc_find(
struct Cyc_Hashtable_Table*t,struct _dynforward_ptr*x){struct _handler_cons _tmp162;
_push_handler(& _tmp162);{int _tmp164=0;if(setjmp(_tmp162.handler))_tmp164=1;if(!
_tmp164){{struct Cyc_Set_Set*_tmp165=((struct Cyc_Set_Set*(*)(struct Cyc_Hashtable_Table*
t,struct _dynforward_ptr*key))Cyc_Hashtable_lookup)(t,x);_npop_handler(0);return
_tmp165;};_pop_handler();}else{void*_tmp163=(void*)_exn_thrown;void*_tmp167=
_tmp163;_LL16F: if(_tmp167 != Cyc_Core_Not_found)goto _LL171;_LL170: return((struct
Cyc_Set_Set*(*)(int(*cmp)(struct _dynforward_ptr*,struct _dynforward_ptr*)))Cyc_Set_empty)(
Cyc_strptrcmp);_LL171:;_LL172:(void)_throw(_tmp167);_LL16E:;}}}struct Cyc_Set_Set*
Cyc_reachable(struct Cyc_List_List*init,struct Cyc_Hashtable_Table*t){struct Cyc_Set_Set*
emptyset=((struct Cyc_Set_Set*(*)(int(*cmp)(struct _dynforward_ptr*,struct
_dynforward_ptr*)))Cyc_Set_empty)(Cyc_strptrcmp);struct Cyc_Set_Set*curr;for(curr=
emptyset;init != 0;init=init->tl){curr=((struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*
s,struct _dynforward_ptr*elt))Cyc_Set_insert)(curr,(struct _dynforward_ptr*)init->hd);}{
struct Cyc_Set_Set*_tmp168=curr;struct _dynforward_ptr*_tmp169=
_init_dynforward_ptr(_cycalloc(sizeof(struct _dynforward_ptr)),"",sizeof(char),1);
while(((int(*)(struct Cyc_Set_Set*s))Cyc_Set_cardinality)(_tmp168)> 0){struct Cyc_Set_Set*
_tmp16A=emptyset;struct Cyc_Iter_Iter _tmp16B=((struct Cyc_Iter_Iter(*)(struct
_RegionHandle*rgn,struct Cyc_Set_Set*s))Cyc_Set_make_iter)(Cyc_Core_heap_region,
_tmp168);while(((int(*)(struct Cyc_Iter_Iter,struct _dynforward_ptr**))Cyc_Iter_next)(
_tmp16B,& _tmp169)){_tmp16A=((struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*s1,struct
Cyc_Set_Set*s2))Cyc_Set_union_two)(_tmp16A,Cyc_find(t,_tmp169));}_tmp168=((
struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*s1,struct Cyc_Set_Set*s2))Cyc_Set_diff)(
_tmp16A,curr);curr=((struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*s1,struct Cyc_Set_Set*
s2))Cyc_Set_union_two)(curr,_tmp168);}return curr;}}static void*Cyc_mode=(void*)0;
static int Cyc_gathering(){return Cyc_mode == (void*)1  || Cyc_mode == (void*)2;}
static struct Cyc___cycFILE*Cyc_script_file=0;int Cyc_prscript(struct
_dynforward_ptr fmt,struct _dynforward_ptr ap){if(Cyc_script_file == 0){({void*
_tmp16D[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp16E="Internal error: script file is NULL\n";
_tag_dynforward(_tmp16E,sizeof(char),_get_zero_arr_size(_tmp16E,37));}),
_tag_dynforward(_tmp16D,sizeof(void*),0));});exit(1);}return Cyc_vfprintf((struct
Cyc___cycFILE*)_check_null(Cyc_script_file),fmt,ap);}int Cyc_force_directory(
struct _dynforward_ptr d){if(Cyc_mode == (void*)2)({struct Cyc_String_pa_struct
_tmp172;_tmp172.tag=0;_tmp172.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
d);{struct Cyc_String_pa_struct _tmp171;_tmp171.tag=0;_tmp171.f1=(struct
_dynforward_ptr)((struct _dynforward_ptr)d);{void*_tmp16F[2]={& _tmp171,& _tmp172};
Cyc_prscript(({const char*_tmp170="if ! test -e %s; then mkdir %s; fi\n";
_tag_dynforward(_tmp170,sizeof(char),_get_zero_arr_size(_tmp170,36));}),
_tag_dynforward(_tmp16F,sizeof(void*),2));}}});else{int _tmp173=({int _tmp177[0];
Cyc_open((const char*)_check_null(_untag_dynforward_ptr(d,sizeof(char),1)),0,
_tag_dynforward(_tmp177,sizeof(int),0));});if(_tmp173 == - 1){if(mkdir((const char*)
_untag_dynforward_ptr(d,sizeof(char),1),448)== - 1){({struct Cyc_String_pa_struct
_tmp176;_tmp176.tag=0;_tmp176.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
d);{void*_tmp174[1]={& _tmp176};Cyc_fprintf(Cyc_stderr,({const char*_tmp175="Error: could not create directory %s\n";
_tag_dynforward(_tmp175,sizeof(char),_get_zero_arr_size(_tmp175,38));}),
_tag_dynforward(_tmp174,sizeof(void*),1));}});return 1;}}else{close(_tmp173);}}
return 0;}int Cyc_force_directory_prefixes(struct _dynforward_ptr file){struct
_dynforward_ptr _tmp178=Cyc_strdup((struct _dynforward_ptr)file);struct Cyc_List_List*
_tmp179=0;while(1){_tmp178=Cyc_Filename_dirname((struct _dynforward_ptr)_tmp178);
if(Cyc_strlen((struct _dynforward_ptr)_tmp178)== 0)break;_tmp179=({struct Cyc_List_List*
_tmp17A=_cycalloc(sizeof(*_tmp17A));_tmp17A->hd=({struct _dynforward_ptr*_tmp17B=
_cycalloc(sizeof(*_tmp17B));_tmp17B[0]=(struct _dynforward_ptr)_tmp178;_tmp17B;});
_tmp17A->tl=_tmp179;_tmp17A;});}for(0;_tmp179 != 0;_tmp179=_tmp179->tl){if(Cyc_force_directory(*((
struct _dynforward_ptr*)_tmp179->hd)))return 1;}return 0;}char Cyc_NO_SUPPORT[15]="\000\000\000\000NO_SUPPORT\000";
struct Cyc_NO_SUPPORT_struct{char*tag;struct _dynforward_ptr f1;};struct _tuple18{
struct Cyc_List_List*f1;struct Cyc_List_List*f2;};int Cyc_process_file(const char*
filename,struct Cyc_List_List*start_symbols,struct Cyc_List_List*omit_symbols,
struct Cyc_List_List*hstubs,struct Cyc_List_List*cstubs,struct Cyc_List_List*
cycstubs){struct Cyc___cycFILE*maybe;struct Cyc___cycFILE*in_file;struct Cyc___cycFILE*
out_file;int errorcode=0;({struct Cyc_String_pa_struct _tmp17E;_tmp17E.tag=0;
_tmp17E.f1=(struct _dynforward_ptr)({const char*_tmp17F=filename;_tag_dynforward(
_tmp17F,sizeof(char),_get_zero_arr_size(_tmp17F,1));});{void*_tmp17C[1]={&
_tmp17E};Cyc_fprintf(Cyc_stderr,({const char*_tmp17D="********************************* %s...\n";
_tag_dynforward(_tmp17D,sizeof(char),_get_zero_arr_size(_tmp17D,41));}),
_tag_dynforward(_tmp17C,sizeof(void*),1));}});if(!Cyc_gathering())({struct Cyc_String_pa_struct
_tmp182;_tmp182.tag=0;_tmp182.f1=(struct _dynforward_ptr)({const char*_tmp183=
filename;_tag_dynforward(_tmp183,sizeof(char),_get_zero_arr_size(_tmp183,1));});{
void*_tmp180[1]={& _tmp182};Cyc_log(({const char*_tmp181="\n%s:\n";_tag_dynforward(
_tmp181,sizeof(char),_get_zero_arr_size(_tmp181,6));}),_tag_dynforward(_tmp180,
sizeof(void*),1));}});{struct _dynforward_ptr _tmp184=Cyc_Filename_basename(({
const char*_tmp2A3=filename;_tag_dynforward(_tmp2A3,sizeof(char),
_get_zero_arr_size(_tmp2A3,1));}));struct _dynforward_ptr _tmp185=Cyc_Filename_dirname(({
const char*_tmp2A2=filename;_tag_dynforward(_tmp2A2,sizeof(char),
_get_zero_arr_size(_tmp2A2,1));}));struct _dynforward_ptr _tmp186=Cyc_Filename_chop_extension((
struct _dynforward_ptr)_tmp184);const char*_tmp187=(const char*)
_untag_dynforward_ptr(Cyc_strconcat((struct _dynforward_ptr)_tmp186,({const char*
_tmp2A1=".iA";_tag_dynforward(_tmp2A1,sizeof(char),_get_zero_arr_size(_tmp2A1,4));})),
sizeof(char),1);const char*_tmp188=(const char*)_untag_dynforward_ptr(
_get_dynforward_size(_tmp185,sizeof(char))== 0?({struct Cyc_String_pa_struct
_tmp29D;_tmp29D.tag=0;_tmp29D.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
_tmp186);{void*_tmp29B[1]={& _tmp29D};Cyc_aprintf(({const char*_tmp29C="%s.iB";
_tag_dynforward(_tmp29C,sizeof(char),_get_zero_arr_size(_tmp29C,6));}),
_tag_dynforward(_tmp29B,sizeof(void*),1));}}): Cyc_Filename_concat((struct
_dynforward_ptr)_tmp185,(struct _dynforward_ptr)({struct Cyc_String_pa_struct
_tmp2A0;_tmp2A0.tag=0;_tmp2A0.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
_tmp186);{void*_tmp29E[1]={& _tmp2A0};Cyc_aprintf(({const char*_tmp29F="%s.iB";
_tag_dynforward(_tmp29F,sizeof(char),_get_zero_arr_size(_tmp29F,6));}),
_tag_dynforward(_tmp29E,sizeof(void*),1));}})),sizeof(char),1);const char*_tmp189=(
const char*)_untag_dynforward_ptr(_get_dynforward_size(_tmp185,sizeof(char))== 0?({
struct Cyc_String_pa_struct _tmp297;_tmp297.tag=0;_tmp297.f1=(struct
_dynforward_ptr)((struct _dynforward_ptr)_tmp186);{void*_tmp295[1]={& _tmp297};Cyc_aprintf(({
const char*_tmp296="%s.iC";_tag_dynforward(_tmp296,sizeof(char),
_get_zero_arr_size(_tmp296,6));}),_tag_dynforward(_tmp295,sizeof(void*),1));}}):
Cyc_Filename_concat((struct _dynforward_ptr)_tmp185,(struct _dynforward_ptr)({
struct Cyc_String_pa_struct _tmp29A;_tmp29A.tag=0;_tmp29A.f1=(struct
_dynforward_ptr)((struct _dynforward_ptr)_tmp186);{void*_tmp298[1]={& _tmp29A};Cyc_aprintf(({
const char*_tmp299="%s.iC";_tag_dynforward(_tmp299,sizeof(char),
_get_zero_arr_size(_tmp299,6));}),_tag_dynforward(_tmp298,sizeof(void*),1));}})),
sizeof(char),1);const char*_tmp18A=(const char*)_untag_dynforward_ptr(
_get_dynforward_size(_tmp185,sizeof(char))== 0?({struct Cyc_String_pa_struct
_tmp291;_tmp291.tag=0;_tmp291.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
_tmp186);{void*_tmp28F[1]={& _tmp291};Cyc_aprintf(({const char*_tmp290="%s.iD";
_tag_dynforward(_tmp290,sizeof(char),_get_zero_arr_size(_tmp290,6));}),
_tag_dynforward(_tmp28F,sizeof(void*),1));}}): Cyc_Filename_concat((struct
_dynforward_ptr)_tmp185,(struct _dynforward_ptr)({struct Cyc_String_pa_struct
_tmp294;_tmp294.tag=0;_tmp294.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
_tmp186);{void*_tmp292[1]={& _tmp294};Cyc_aprintf(({const char*_tmp293="%s.iD";
_tag_dynforward(_tmp293,sizeof(char),_get_zero_arr_size(_tmp293,6));}),
_tag_dynforward(_tmp292,sizeof(void*),1));}})),sizeof(char),1);struct
_handler_cons _tmp18B;_push_handler(& _tmp18B);{int _tmp18D=0;if(setjmp(_tmp18B.handler))
_tmp18D=1;if(!_tmp18D){if(Cyc_force_directory_prefixes(({const char*_tmp18E=
filename;_tag_dynforward(_tmp18E,sizeof(char),_get_zero_arr_size(_tmp18E,1));}))){
int _tmp18F=1;_npop_handler(0);return _tmp18F;}if(Cyc_mode != (void*)3){Cyc_current_cpp=((
struct Cyc_List_List*(*)(struct Cyc_List_List*x))Cyc_List_imp_rev)(Cyc_current_cpp);
if(Cyc_mode == (void*)2){({struct Cyc_String_pa_struct _tmp192;_tmp192.tag=0;
_tmp192.f1=(struct _dynforward_ptr)({const char*_tmp193=_tmp187;_tag_dynforward(
_tmp193,sizeof(char),_get_zero_arr_size(_tmp193,1));});{void*_tmp190[1]={&
_tmp192};Cyc_prscript(({const char*_tmp191="cat >%s <<XXX\n";_tag_dynforward(
_tmp191,sizeof(char),_get_zero_arr_size(_tmp191,15));}),_tag_dynforward(_tmp190,
sizeof(void*),1));}});{struct Cyc_List_List*_tmp194=Cyc_current_cpp;for(0;_tmp194
!= 0;_tmp194=_tmp194->tl){({struct Cyc_String_pa_struct _tmp197;_tmp197.tag=0;
_tmp197.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)*((struct
_dynforward_ptr*)_tmp194->hd));{void*_tmp195[1]={& _tmp197};Cyc_prscript(({const
char*_tmp196="%s";_tag_dynforward(_tmp196,sizeof(char),_get_zero_arr_size(
_tmp196,3));}),_tag_dynforward(_tmp195,sizeof(void*),1));}});}}({struct Cyc_String_pa_struct
_tmp19A;_tmp19A.tag=0;_tmp19A.f1=(struct _dynforward_ptr)({const char*_tmp19B=
filename;_tag_dynforward(_tmp19B,sizeof(char),_get_zero_arr_size(_tmp19B,1));});{
void*_tmp198[1]={& _tmp19A};Cyc_prscript(({const char*_tmp199="#include <%s>\n";
_tag_dynforward(_tmp199,sizeof(char),_get_zero_arr_size(_tmp199,15));}),
_tag_dynforward(_tmp198,sizeof(void*),1));}});({void*_tmp19C[0]={};Cyc_prscript(({
const char*_tmp19D="XXX\n";_tag_dynforward(_tmp19D,sizeof(char),
_get_zero_arr_size(_tmp19D,5));}),_tag_dynforward(_tmp19C,sizeof(void*),0));});({
struct Cyc_String_pa_struct _tmp1A1;_tmp1A1.tag=0;_tmp1A1.f1=(struct
_dynforward_ptr)({const char*_tmp1A3=_tmp187;_tag_dynforward(_tmp1A3,sizeof(char),
_get_zero_arr_size(_tmp1A3,1));});{struct Cyc_String_pa_struct _tmp1A0;_tmp1A0.tag=
0;_tmp1A0.f1=(struct _dynforward_ptr)({const char*_tmp1A2=_tmp188;_tag_dynforward(
_tmp1A2,sizeof(char),_get_zero_arr_size(_tmp1A2,1));});{void*_tmp19E[2]={&
_tmp1A0,& _tmp1A1};Cyc_prscript(({const char*_tmp19F="$GCC -E -dM -o %s -x c %s && \\\n";
_tag_dynforward(_tmp19F,sizeof(char),_get_zero_arr_size(_tmp19F,32));}),
_tag_dynforward(_tmp19E,sizeof(void*),2));}}});({struct Cyc_String_pa_struct
_tmp1A7;_tmp1A7.tag=0;_tmp1A7.f1=(struct _dynforward_ptr)({const char*_tmp1A9=
_tmp187;_tag_dynforward(_tmp1A9,sizeof(char),_get_zero_arr_size(_tmp1A9,1));});{
struct Cyc_String_pa_struct _tmp1A6;_tmp1A6.tag=0;_tmp1A6.f1=(struct
_dynforward_ptr)({const char*_tmp1A8=_tmp189;_tag_dynforward(_tmp1A8,sizeof(char),
_get_zero_arr_size(_tmp1A8,1));});{void*_tmp1A4[2]={& _tmp1A6,& _tmp1A7};Cyc_prscript(({
const char*_tmp1A5="$GCC -E     -o %s -x c %s;\n";_tag_dynforward(_tmp1A5,sizeof(
char),_get_zero_arr_size(_tmp1A5,28));}),_tag_dynforward(_tmp1A4,sizeof(void*),2));}}});({
struct Cyc_String_pa_struct _tmp1AC;_tmp1AC.tag=0;_tmp1AC.f1=(struct
_dynforward_ptr)({const char*_tmp1AD=_tmp187;_tag_dynforward(_tmp1AD,sizeof(char),
_get_zero_arr_size(_tmp1AD,1));});{void*_tmp1AA[1]={& _tmp1AC};Cyc_prscript(({
const char*_tmp1AB="rm %s\n";_tag_dynforward(_tmp1AB,sizeof(char),
_get_zero_arr_size(_tmp1AB,7));}),_tag_dynforward(_tmp1AA,sizeof(void*),1));}});}
else{maybe=Cyc_fopen(_tmp187,(const char*)"w");if(!((unsigned int)maybe)){({
struct Cyc_String_pa_struct _tmp1B0;_tmp1B0.tag=0;_tmp1B0.f1=(struct
_dynforward_ptr)({const char*_tmp1B1=_tmp187;_tag_dynforward(_tmp1B1,sizeof(char),
_get_zero_arr_size(_tmp1B1,1));});{void*_tmp1AE[1]={& _tmp1B0};Cyc_fprintf(Cyc_stderr,({
const char*_tmp1AF="Error: could not create file %s\n";_tag_dynforward(_tmp1AF,
sizeof(char),_get_zero_arr_size(_tmp1AF,33));}),_tag_dynforward(_tmp1AE,sizeof(
void*),1));}});{int _tmp1B2=1;_npop_handler(0);return _tmp1B2;}}out_file=(struct
Cyc___cycFILE*)maybe;{struct Cyc_List_List*_tmp1B3=Cyc_current_cpp;for(0;_tmp1B3
!= 0;_tmp1B3=_tmp1B3->tl){Cyc_fputs((const char*)_untag_dynforward_ptr(*((struct
_dynforward_ptr*)_tmp1B3->hd),sizeof(char),1),out_file);}}({struct Cyc_String_pa_struct
_tmp1B6;_tmp1B6.tag=0;_tmp1B6.f1=(struct _dynforward_ptr)({const char*_tmp1B7=
filename;_tag_dynforward(_tmp1B7,sizeof(char),_get_zero_arr_size(_tmp1B7,1));});{
void*_tmp1B4[1]={& _tmp1B6};Cyc_fprintf(out_file,({const char*_tmp1B5="#include <%s>\n";
_tag_dynforward(_tmp1B5,sizeof(char),_get_zero_arr_size(_tmp1B5,15));}),
_tag_dynforward(_tmp1B4,sizeof(void*),1));}});Cyc_fclose(out_file);{struct
_dynforward_ptr _tmp1B8=Cstring_to_string(Ccomp);char*cmd=(char*)
_untag_dynforward_ptr(({struct Cyc_String_pa_struct _tmp1C4;_tmp1C4.tag=0;_tmp1C4.f1=(
struct _dynforward_ptr)({const char*_tmp1C6=_tmp187;_tag_dynforward(_tmp1C6,
sizeof(char),_get_zero_arr_size(_tmp1C6,1));});{struct Cyc_String_pa_struct
_tmp1C3;_tmp1C3.tag=0;_tmp1C3.f1=(struct _dynforward_ptr)({const char*_tmp1C5=
_tmp188;_tag_dynforward(_tmp1C5,sizeof(char),_get_zero_arr_size(_tmp1C5,1));});{
struct Cyc_String_pa_struct _tmp1C2;_tmp1C2.tag=0;_tmp1C2.f1=(struct
_dynforward_ptr)((struct _dynforward_ptr)_tmp1B8);{void*_tmp1C0[3]={& _tmp1C2,&
_tmp1C3,& _tmp1C4};Cyc_aprintf(({const char*_tmp1C1="%s -E -dM -o %s -x c %s";
_tag_dynforward(_tmp1C1,sizeof(char),_get_zero_arr_size(_tmp1C1,24));}),
_tag_dynforward(_tmp1C0,sizeof(void*),3));}}}}),sizeof(char),1);if(!system((
const char*)cmd)){cmd=(char*)_untag_dynforward_ptr(({struct Cyc_String_pa_struct
_tmp1BD;_tmp1BD.tag=0;_tmp1BD.f1=(struct _dynforward_ptr)({const char*_tmp1BF=
_tmp187;_tag_dynforward(_tmp1BF,sizeof(char),_get_zero_arr_size(_tmp1BF,1));});{
struct Cyc_String_pa_struct _tmp1BC;_tmp1BC.tag=0;_tmp1BC.f1=(struct
_dynforward_ptr)({const char*_tmp1BE=_tmp189;_tag_dynforward(_tmp1BE,sizeof(char),
_get_zero_arr_size(_tmp1BE,1));});{struct Cyc_String_pa_struct _tmp1BB;_tmp1BB.tag=
0;_tmp1BB.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)_tmp1B8);{void*
_tmp1B9[3]={& _tmp1BB,& _tmp1BC,& _tmp1BD};Cyc_aprintf(({const char*_tmp1BA="%s -E -o %s -x c %s";
_tag_dynforward(_tmp1BA,sizeof(char),_get_zero_arr_size(_tmp1BA,20));}),
_tag_dynforward(_tmp1B9,sizeof(void*),3));}}}}),sizeof(char),1);system((const
char*)cmd);}remove(_tmp187);}}}if(Cyc_gathering()){int _tmp1C7=0;_npop_handler(0);
return _tmp1C7;}{struct Cyc_Hashtable_Table*t=Cyc_new_deps();maybe=Cyc_fopen(
_tmp188,(const char*)"r");if(!((unsigned int)maybe))(int)_throw((void*)({struct
Cyc_NO_SUPPORT_struct*_tmp1C8=_cycalloc(sizeof(*_tmp1C8));_tmp1C8[0]=({struct Cyc_NO_SUPPORT_struct
_tmp1C9;_tmp1C9.tag=Cyc_NO_SUPPORT;_tmp1C9.f1=(struct _dynforward_ptr)({struct Cyc_String_pa_struct
_tmp1CC;_tmp1CC.tag=0;_tmp1CC.f1=(struct _dynforward_ptr)({const char*_tmp1CD=
_tmp188;_tag_dynforward(_tmp1CD,sizeof(char),_get_zero_arr_size(_tmp1CD,1));});{
void*_tmp1CA[1]={& _tmp1CC};Cyc_aprintf(({const char*_tmp1CB="can't open macrosfile %s";
_tag_dynforward(_tmp1CB,sizeof(char),_get_zero_arr_size(_tmp1CB,25));}),
_tag_dynforward(_tmp1CA,sizeof(void*),1));}});_tmp1C9;});_tmp1C8;}));in_file=(
struct Cyc___cycFILE*)maybe;{struct Cyc_Lexing_lexbuf*_tmp1CE=Cyc_Lexing_from_file(
in_file);struct _tuple12*entry;while((entry=((struct _tuple12*(*)(struct Cyc_Lexing_lexbuf*
lexbuf))Cyc_line)(_tmp1CE))!= 0){struct _tuple12 _tmp1D0;struct _dynforward_ptr*
_tmp1D1;struct Cyc_Set_Set*_tmp1D2;struct _tuple12*_tmp1CF=(struct _tuple12*)
_check_null(entry);_tmp1D0=*_tmp1CF;_tmp1D1=_tmp1D0.f1;_tmp1D2=_tmp1D0.f2;((void(*)(
struct Cyc_Hashtable_Table*t,struct _dynforward_ptr*key,struct Cyc_Set_Set*val))Cyc_Hashtable_insert)(
t,_tmp1D1,_tmp1D2);}Cyc_fclose(in_file);maybe=Cyc_fopen(_tmp189,(const char*)"r");
if(!((unsigned int)maybe))(int)_throw((void*)({struct Cyc_NO_SUPPORT_struct*
_tmp1D3=_cycalloc(sizeof(*_tmp1D3));_tmp1D3[0]=({struct Cyc_NO_SUPPORT_struct
_tmp1D4;_tmp1D4.tag=Cyc_NO_SUPPORT;_tmp1D4.f1=(struct _dynforward_ptr)({struct Cyc_String_pa_struct
_tmp1D7;_tmp1D7.tag=0;_tmp1D7.f1=(struct _dynforward_ptr)({const char*_tmp1D8=
_tmp189;_tag_dynforward(_tmp1D8,sizeof(char),_get_zero_arr_size(_tmp1D8,1));});{
void*_tmp1D5[1]={& _tmp1D7};Cyc_aprintf(({const char*_tmp1D6="can't open declsfile %s";
_tag_dynforward(_tmp1D6,sizeof(char),_get_zero_arr_size(_tmp1D6,24));}),
_tag_dynforward(_tmp1D5,sizeof(void*),1));}});_tmp1D4;});_tmp1D3;}));in_file=(
struct Cyc___cycFILE*)maybe;_tmp1CE=Cyc_Lexing_from_file(in_file);Cyc_slurp_out=
Cyc_fopen(_tmp18A,(const char*)"w");if(!((unsigned int)Cyc_slurp_out)){int _tmp1D9=
1;_npop_handler(0);return _tmp1D9;}while(((int(*)(struct Cyc_Lexing_lexbuf*lexbuf))
Cyc_slurp)(_tmp1CE)){;}Cyc_fclose(in_file);Cyc_fclose((struct Cyc___cycFILE*)
_check_null(Cyc_slurp_out));if(Cyc_mode != (void*)3)remove(_tmp189);maybe=Cyc_fopen(
_tmp18A,(const char*)"r");if(!((unsigned int)maybe)){int _tmp1DA=1;_npop_handler(0);
return _tmp1DA;}in_file=(struct Cyc___cycFILE*)maybe;Cyc_Position_reset_position(({
const char*_tmp1DB=_tmp18A;_tag_dynforward(_tmp1DB,sizeof(char),
_get_zero_arr_size(_tmp1DB,1));}));Cyc_Lex_lex_init(0);{struct Cyc_List_List*
_tmp1DC=Cyc_Parse_parse_file(in_file);Cyc_Lex_lex_init(0);Cyc_fclose(in_file);
remove(_tmp18A);{struct Cyc_List_List*_tmp1DD=_tmp1DC;for(0;_tmp1DD != 0;_tmp1DD=
_tmp1DD->tl){struct _tuple12*_tmp1DE=Cyc_scan_decl((struct Cyc_Absyn_Decl*)_tmp1DD->hd);
if(_tmp1DE == 0)continue;{struct _tuple12 _tmp1E0;struct _dynforward_ptr*_tmp1E1;
struct Cyc_Set_Set*_tmp1E2;struct _tuple12*_tmp1DF=(struct _tuple12*)_tmp1DE;
_tmp1E0=*_tmp1DF;_tmp1E1=_tmp1E0.f1;_tmp1E2=_tmp1E0.f2;{struct Cyc_Set_Set*old;{
struct _handler_cons _tmp1E3;_push_handler(& _tmp1E3);{int _tmp1E5=0;if(setjmp(
_tmp1E3.handler))_tmp1E5=1;if(!_tmp1E5){old=((struct Cyc_Set_Set*(*)(struct Cyc_Hashtable_Table*
t,struct _dynforward_ptr*key))Cyc_Hashtable_lookup)(t,_tmp1E1);;_pop_handler();}
else{void*_tmp1E4=(void*)_exn_thrown;void*_tmp1E7=_tmp1E4;_LL174: if(_tmp1E7 != 
Cyc_Core_Not_found)goto _LL176;_LL175: old=((struct Cyc_Set_Set*(*)(int(*cmp)(
struct _dynforward_ptr*,struct _dynforward_ptr*)))Cyc_Set_empty)(Cyc_strptrcmp);
goto _LL173;_LL176:;_LL177:(void)_throw(_tmp1E7);_LL173:;}}}((void(*)(struct Cyc_Hashtable_Table*
t,struct _dynforward_ptr*key,struct Cyc_Set_Set*val))Cyc_Hashtable_insert)(t,
_tmp1E1,((struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*s1,struct Cyc_Set_Set*s2))Cyc_Set_union_two)(
_tmp1E2,old));}}}}{struct Cyc_Set_Set*_tmp1E8=Cyc_reachable(start_symbols,t);
struct Cyc_List_List*_tmp1E9=0;struct Cyc_Set_Set*defined_symbols=((struct Cyc_Set_Set*(*)(
int(*cmp)(struct _dynforward_ptr*,struct _dynforward_ptr*)))Cyc_Set_empty)(Cyc_strptrcmp);{
struct Cyc_List_List*_tmp1EA=_tmp1DC;for(0;_tmp1EA != 0;_tmp1EA=_tmp1EA->tl){
struct Cyc_Absyn_Decl*_tmp1EB=(struct Cyc_Absyn_Decl*)_tmp1EA->hd;struct
_dynforward_ptr*name;{void*_tmp1EC=(void*)_tmp1EB->r;struct Cyc_Absyn_Vardecl*
_tmp1ED;struct Cyc_Absyn_Fndecl*_tmp1EE;struct Cyc_Absyn_Aggrdecl*_tmp1EF;struct
Cyc_Absyn_Enumdecl*_tmp1F0;struct Cyc_Absyn_Typedefdecl*_tmp1F1;_LL179: if(_tmp1EC
<= (void*)2)goto _LL183;if(*((int*)_tmp1EC)!= 0)goto _LL17B;_tmp1ED=((struct Cyc_Absyn_Var_d_struct*)
_tmp1EC)->f1;_LL17A: {struct _tuple0 _tmp1F3;struct _dynforward_ptr*_tmp1F4;struct
_tuple0*_tmp1F2=_tmp1ED->name;_tmp1F3=*_tmp1F2;_tmp1F4=_tmp1F3.f2;
defined_symbols=((struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*s,struct
_dynforward_ptr*elt))Cyc_Set_insert)(defined_symbols,_tmp1F4);if(((int(*)(int(*
compare)(struct _dynforward_ptr*,struct _dynforward_ptr*),struct Cyc_List_List*l,
struct _dynforward_ptr*x))Cyc_List_mem)(Cyc_strptrcmp,omit_symbols,_tmp1F4))name=
0;else{name=(struct _dynforward_ptr*)_tmp1F4;}goto _LL178;}_LL17B: if(*((int*)
_tmp1EC)!= 1)goto _LL17D;_tmp1EE=((struct Cyc_Absyn_Fn_d_struct*)_tmp1EC)->f1;
_LL17C: {struct _tuple0 _tmp1F6;struct _dynforward_ptr*_tmp1F7;struct _tuple0*
_tmp1F5=_tmp1EE->name;_tmp1F6=*_tmp1F5;_tmp1F7=_tmp1F6.f2;defined_symbols=((
struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*s,struct _dynforward_ptr*elt))Cyc_Set_insert)(
defined_symbols,_tmp1F7);if(((int(*)(int(*compare)(struct _dynforward_ptr*,struct
_dynforward_ptr*),struct Cyc_List_List*l,struct _dynforward_ptr*x))Cyc_List_mem)(
Cyc_strptrcmp,omit_symbols,_tmp1F7))name=0;else{name=(struct _dynforward_ptr*)
_tmp1F7;}goto _LL178;}_LL17D: if(*((int*)_tmp1EC)!= 4)goto _LL17F;_tmp1EF=((struct
Cyc_Absyn_Aggr_d_struct*)_tmp1EC)->f1;_LL17E: {struct _tuple0 _tmp1F9;struct
_dynforward_ptr*_tmp1FA;struct _tuple0*_tmp1F8=_tmp1EF->name;_tmp1F9=*_tmp1F8;
_tmp1FA=_tmp1F9.f2;name=(struct _dynforward_ptr*)_tmp1FA;goto _LL178;}_LL17F: if(*((
int*)_tmp1EC)!= 6)goto _LL181;_tmp1F0=((struct Cyc_Absyn_Enum_d_struct*)_tmp1EC)->f1;
_LL180: {struct _tuple0 _tmp1FC;struct _dynforward_ptr*_tmp1FD;struct _tuple0*
_tmp1FB=_tmp1F0->name;_tmp1FC=*_tmp1FB;_tmp1FD=_tmp1FC.f2;name=(struct
_dynforward_ptr*)_tmp1FD;if(name != 0  && ((int(*)(struct Cyc_Set_Set*s,struct
_dynforward_ptr*elt))Cyc_Set_member)(_tmp1E8,(struct _dynforward_ptr*)name))
_tmp1E9=({struct Cyc_List_List*_tmp1FE=_cycalloc(sizeof(*_tmp1FE));_tmp1FE->hd=
_tmp1EB;_tmp1FE->tl=_tmp1E9;_tmp1FE;});else{if((unsigned int)_tmp1F0->fields){
struct Cyc_List_List*_tmp1FF=(struct Cyc_List_List*)((struct Cyc_Core_Opt*)
_check_null(_tmp1F0->fields))->v;for(0;_tmp1FF != 0;_tmp1FF=_tmp1FF->tl){struct
Cyc_Absyn_Enumfield*_tmp200=(struct Cyc_Absyn_Enumfield*)_tmp1FF->hd;struct
_tuple0 _tmp202;struct _dynforward_ptr*_tmp203;struct _tuple0*_tmp201=_tmp200->name;
_tmp202=*_tmp201;_tmp203=_tmp202.f2;if(((int(*)(struct Cyc_Set_Set*s,struct
_dynforward_ptr*elt))Cyc_Set_member)(_tmp1E8,_tmp203)){_tmp1E9=({struct Cyc_List_List*
_tmp204=_cycalloc(sizeof(*_tmp204));_tmp204->hd=_tmp1EB;_tmp204->tl=_tmp1E9;
_tmp204;});break;}}}}name=0;goto _LL178;}_LL181: if(*((int*)_tmp1EC)!= 7)goto
_LL183;_tmp1F1=((struct Cyc_Absyn_Typedef_d_struct*)_tmp1EC)->f1;_LL182: {struct
_tuple0 _tmp206;struct _dynforward_ptr*_tmp207;struct _tuple0*_tmp205=_tmp1F1->name;
_tmp206=*_tmp205;_tmp207=_tmp206.f2;name=(struct _dynforward_ptr*)_tmp207;goto
_LL178;}_LL183: if((int)_tmp1EC != 0)goto _LL185;_LL184: goto _LL186;_LL185: if((int)
_tmp1EC != 1)goto _LL187;_LL186: goto _LL188;_LL187: if(_tmp1EC <= (void*)2)goto _LL189;
if(*((int*)_tmp1EC)!= 2)goto _LL189;_LL188: goto _LL18A;_LL189: if(_tmp1EC <= (void*)
2)goto _LL18B;if(*((int*)_tmp1EC)!= 5)goto _LL18B;_LL18A: goto _LL18C;_LL18B: if(
_tmp1EC <= (void*)2)goto _LL18D;if(*((int*)_tmp1EC)!= 3)goto _LL18D;_LL18C: goto
_LL18E;_LL18D: if(_tmp1EC <= (void*)2)goto _LL18F;if(*((int*)_tmp1EC)!= 8)goto
_LL18F;_LL18E: goto _LL190;_LL18F: if(_tmp1EC <= (void*)2)goto _LL191;if(*((int*)
_tmp1EC)!= 9)goto _LL191;_LL190: goto _LL192;_LL191: if(_tmp1EC <= (void*)2)goto
_LL193;if(*((int*)_tmp1EC)!= 10)goto _LL193;_LL192: goto _LL194;_LL193: if(_tmp1EC <= (
void*)2)goto _LL178;if(*((int*)_tmp1EC)!= 11)goto _LL178;_LL194: name=0;goto _LL178;
_LL178:;}if(name != 0  && ((int(*)(struct Cyc_Set_Set*s,struct _dynforward_ptr*elt))
Cyc_Set_member)(_tmp1E8,(struct _dynforward_ptr*)name))_tmp1E9=({struct Cyc_List_List*
_tmp208=_cycalloc(sizeof(*_tmp208));_tmp208->hd=_tmp1EB;_tmp208->tl=_tmp1E9;
_tmp208;});}}maybe=Cyc_fopen(filename,(const char*)"w");if(!((unsigned int)maybe)){
int _tmp209=1;_npop_handler(0);return _tmp209;}out_file=(struct Cyc___cycFILE*)
maybe;{struct _dynforward_ptr ifdefmacro=({struct Cyc_String_pa_struct _tmp279;
_tmp279.tag=0;_tmp279.f1=(struct _dynforward_ptr)({const char*_tmp27A=filename;
_tag_dynforward(_tmp27A,sizeof(char),_get_zero_arr_size(_tmp27A,1));});{void*
_tmp277[1]={& _tmp279};Cyc_aprintf(({const char*_tmp278="_%s_";_tag_dynforward(
_tmp278,sizeof(char),_get_zero_arr_size(_tmp278,5));}),_tag_dynforward(_tmp277,
sizeof(void*),1));}});{int _tmp20A=0;for(0;_tmp20A < _get_dynforward_size(
ifdefmacro,sizeof(char));_tmp20A ++){if(((char*)ifdefmacro.curr)[_tmp20A]== '.'
 || ((char*)ifdefmacro.curr)[_tmp20A]== '/')({struct _dynforward_ptr _tmp20B=
_dynforward_ptr_plus(ifdefmacro,sizeof(char),_tmp20A);char _tmp20C=*((char*)
_check_dynforward_subscript(_tmp20B,sizeof(char),0));char _tmp20D='_';if(
_get_dynforward_size(_tmp20B,sizeof(char))== 1  && (_tmp20C == '\000'  && _tmp20D != '\000'))
_throw_arraybounds();*((char*)_tmp20B.curr)=_tmp20D;});else{if(((char*)
ifdefmacro.curr)[_tmp20A]!= '_'  && ((char*)ifdefmacro.curr)[_tmp20A]!= '/')({
struct _dynforward_ptr _tmp20E=_dynforward_ptr_plus(ifdefmacro,sizeof(char),
_tmp20A);char _tmp20F=*((char*)_check_dynforward_subscript(_tmp20E,sizeof(char),0));
char _tmp210=(char)toupper((int)((char*)ifdefmacro.curr)[_tmp20A]);if(
_get_dynforward_size(_tmp20E,sizeof(char))== 1  && (_tmp20F == '\000'  && _tmp210 != '\000'))
_throw_arraybounds();*((char*)_tmp20E.curr)=_tmp210;});}}}({struct Cyc_String_pa_struct
_tmp214;_tmp214.tag=0;_tmp214.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
ifdefmacro);{struct Cyc_String_pa_struct _tmp213;_tmp213.tag=0;_tmp213.f1=(struct
_dynforward_ptr)((struct _dynforward_ptr)ifdefmacro);{void*_tmp211[2]={& _tmp213,&
_tmp214};Cyc_fprintf(out_file,({const char*_tmp212="#ifndef %s\n#define %s\n";
_tag_dynforward(_tmp212,sizeof(char),_get_zero_arr_size(_tmp212,23));}),
_tag_dynforward(_tmp211,sizeof(void*),2));}}});{struct Cyc_List_List*_tmp215=0;
struct Cyc_List_List*_tmp216=0;{struct Cyc_List_List*_tmp217=_tmp1E9;for(0;_tmp217
!= 0;_tmp217=_tmp217->tl){struct Cyc_Absyn_Decl*_tmp218=(struct Cyc_Absyn_Decl*)
_tmp217->hd;int _tmp219=0;struct _dynforward_ptr*name;{void*_tmp21A=(void*)_tmp218->r;
struct Cyc_Absyn_Vardecl*_tmp21B;struct Cyc_Absyn_Fndecl*_tmp21C;struct Cyc_Absyn_Aggrdecl*
_tmp21D;struct Cyc_Absyn_Enumdecl*_tmp21E;struct Cyc_Absyn_Typedefdecl*_tmp21F;
_LL196: if(_tmp21A <= (void*)2)goto _LL1A0;if(*((int*)_tmp21A)!= 0)goto _LL198;
_tmp21B=((struct Cyc_Absyn_Var_d_struct*)_tmp21A)->f1;_LL197: {struct _tuple0
_tmp221;struct _dynforward_ptr*_tmp222;struct _tuple0*_tmp220=_tmp21B->name;
_tmp221=*_tmp220;_tmp222=_tmp221.f2;name=(struct _dynforward_ptr*)_tmp222;goto
_LL195;}_LL198: if(*((int*)_tmp21A)!= 1)goto _LL19A;_tmp21C=((struct Cyc_Absyn_Fn_d_struct*)
_tmp21A)->f1;_LL199: {struct _tuple0 _tmp224;struct _dynforward_ptr*_tmp225;struct
_tuple0*_tmp223=_tmp21C->name;_tmp224=*_tmp223;_tmp225=_tmp224.f2;name=(struct
_dynforward_ptr*)_tmp225;goto _LL195;}_LL19A: if(*((int*)_tmp21A)!= 4)goto _LL19C;
_tmp21D=((struct Cyc_Absyn_Aggr_d_struct*)_tmp21A)->f1;_LL19B: {struct _tuple0
_tmp227;struct _dynforward_ptr*_tmp228;struct _tuple0*_tmp226=_tmp21D->name;
_tmp227=*_tmp226;_tmp228=_tmp227.f2;name=(struct _dynforward_ptr*)_tmp228;goto
_LL195;}_LL19C: if(*((int*)_tmp21A)!= 6)goto _LL19E;_tmp21E=((struct Cyc_Absyn_Enum_d_struct*)
_tmp21A)->f1;_LL19D: {struct _tuple0 _tmp22A;struct _dynforward_ptr*_tmp22B;struct
_tuple0*_tmp229=_tmp21E->name;_tmp22A=*_tmp229;_tmp22B=_tmp22A.f2;name=(struct
_dynforward_ptr*)_tmp22B;goto _LL195;}_LL19E: if(*((int*)_tmp21A)!= 7)goto _LL1A0;
_tmp21F=((struct Cyc_Absyn_Typedef_d_struct*)_tmp21A)->f1;_LL19F: {struct _tuple0
_tmp22D;struct _dynforward_ptr*_tmp22E;struct _tuple0*_tmp22C=_tmp21F->name;
_tmp22D=*_tmp22C;_tmp22E=_tmp22D.f2;name=(struct _dynforward_ptr*)_tmp22E;goto
_LL195;}_LL1A0: if((int)_tmp21A != 0)goto _LL1A2;_LL1A1: goto _LL1A3;_LL1A2: if((int)
_tmp21A != 1)goto _LL1A4;_LL1A3: goto _LL1A5;_LL1A4: if(_tmp21A <= (void*)2)goto _LL1A6;
if(*((int*)_tmp21A)!= 2)goto _LL1A6;_LL1A5: goto _LL1A7;_LL1A6: if(_tmp21A <= (void*)
2)goto _LL1A8;if(*((int*)_tmp21A)!= 5)goto _LL1A8;_LL1A7: goto _LL1A9;_LL1A8: if(
_tmp21A <= (void*)2)goto _LL1AA;if(*((int*)_tmp21A)!= 3)goto _LL1AA;_LL1A9: goto
_LL1AB;_LL1AA: if(_tmp21A <= (void*)2)goto _LL1AC;if(*((int*)_tmp21A)!= 8)goto
_LL1AC;_LL1AB: goto _LL1AD;_LL1AC: if(_tmp21A <= (void*)2)goto _LL1AE;if(*((int*)
_tmp21A)!= 9)goto _LL1AE;_LL1AD: goto _LL1AF;_LL1AE: if(_tmp21A <= (void*)2)goto
_LL1B0;if(*((int*)_tmp21A)!= 10)goto _LL1B0;_LL1AF: goto _LL1B1;_LL1B0: if(_tmp21A <= (
void*)2)goto _LL195;if(*((int*)_tmp21A)!= 11)goto _LL195;_LL1B1: name=0;goto _LL195;
_LL195:;}if(!((unsigned int)name) && !_tmp219)continue;_tmp215=({struct Cyc_List_List*
_tmp22F=_cycalloc(sizeof(*_tmp22F));_tmp22F->hd=_tmp218;_tmp22F->tl=_tmp215;
_tmp22F;});_tmp216=({struct Cyc_List_List*_tmp230=_cycalloc(sizeof(*_tmp230));
_tmp230->hd=name;_tmp230->tl=_tmp216;_tmp230;});}}{struct _RegionHandle _tmp231=
_new_region("tc_rgn");struct _RegionHandle*tc_rgn=& _tmp231;_push_region(tc_rgn);{
struct Cyc_Tcenv_Tenv*_tmp232=Cyc_Tcenv_tc_init(tc_rgn);Cyc_Tc_tc(tc_rgn,_tmp232,
1,_tmp215);};_pop_region(tc_rgn);}{struct Cyc_List_List*_tmp235;struct Cyc_List_List*
_tmp236;struct _tuple18 _tmp234=({struct _tuple18 _tmp233;_tmp233.f1=_tmp215;_tmp233.f2=
_tmp216;_tmp233;});_tmp235=_tmp234.f1;_tmp236=_tmp234.f2;for(0;_tmp235 != 0  && 
_tmp236 != 0;(_tmp235=_tmp235->tl,_tmp236=_tmp236->tl)){struct Cyc_Absyn_Decl*
_tmp237=(struct Cyc_Absyn_Decl*)_tmp235->hd;struct _dynforward_ptr*_tmp238=(struct
_dynforward_ptr*)_tmp236->hd;int _tmp239=0;if(!((unsigned int)_tmp238))_tmp239=1;
if((unsigned int)_tmp238){ifdefmacro=({struct Cyc_String_pa_struct _tmp23C;_tmp23C.tag=
0;_tmp23C.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)*_tmp238);{void*
_tmp23A[1]={& _tmp23C};Cyc_aprintf(({const char*_tmp23B="_%s_def_";_tag_dynforward(
_tmp23B,sizeof(char),_get_zero_arr_size(_tmp23B,9));}),_tag_dynforward(_tmp23A,
sizeof(void*),1));}});({struct Cyc_String_pa_struct _tmp23F;_tmp23F.tag=0;_tmp23F.f1=(
struct _dynforward_ptr)((struct _dynforward_ptr)ifdefmacro);{void*_tmp23D[1]={&
_tmp23F};Cyc_fprintf(out_file,({const char*_tmp23E="#ifndef %s\n";_tag_dynforward(
_tmp23E,sizeof(char),_get_zero_arr_size(_tmp23E,12));}),_tag_dynforward(_tmp23D,
sizeof(void*),1));}});({struct Cyc_String_pa_struct _tmp242;_tmp242.tag=0;_tmp242.f1=(
struct _dynforward_ptr)((struct _dynforward_ptr)ifdefmacro);{void*_tmp240[1]={&
_tmp242};Cyc_fprintf(out_file,({const char*_tmp241="#define %s\n";_tag_dynforward(
_tmp241,sizeof(char),_get_zero_arr_size(_tmp241,12));}),_tag_dynforward(_tmp240,
sizeof(void*),1));}});Cyc_Absynpp_decllist2file(({struct Cyc_Absyn_Decl*_tmp243[1];
_tmp243[0]=_tmp237;((struct Cyc_List_List*(*)(struct _dynforward_ptr))Cyc_List_list)(
_tag_dynforward(_tmp243,sizeof(struct Cyc_Absyn_Decl*),1));}),out_file);({void*
_tmp244[0]={};Cyc_fprintf(out_file,({const char*_tmp245="#endif\n";
_tag_dynforward(_tmp245,sizeof(char),_get_zero_arr_size(_tmp245,8));}),
_tag_dynforward(_tmp244,sizeof(void*),0));});}else{Cyc_Absynpp_decllist2file(({
struct Cyc_Absyn_Decl*_tmp246[1];_tmp246[0]=_tmp237;((struct Cyc_List_List*(*)(
struct _dynforward_ptr))Cyc_List_list)(_tag_dynforward(_tmp246,sizeof(struct Cyc_Absyn_Decl*),
1));}),out_file);}}}maybe=Cyc_fopen(_tmp188,(const char*)"r");if(!((unsigned int)
maybe))(int)_throw((void*)({struct Cyc_NO_SUPPORT_struct*_tmp247=_cycalloc(
sizeof(*_tmp247));_tmp247[0]=({struct Cyc_NO_SUPPORT_struct _tmp248;_tmp248.tag=
Cyc_NO_SUPPORT;_tmp248.f1=(struct _dynforward_ptr)({struct Cyc_String_pa_struct
_tmp24B;_tmp24B.tag=0;_tmp24B.f1=(struct _dynforward_ptr)({const char*_tmp24C=
_tmp188;_tag_dynforward(_tmp24C,sizeof(char),_get_zero_arr_size(_tmp24C,1));});{
void*_tmp249[1]={& _tmp24B};Cyc_aprintf(({const char*_tmp24A="can't open macrosfile %s";
_tag_dynforward(_tmp24A,sizeof(char),_get_zero_arr_size(_tmp24A,25));}),
_tag_dynforward(_tmp249,sizeof(void*),1));}});_tmp248;});_tmp247;}));in_file=(
struct Cyc___cycFILE*)maybe;_tmp1CE=Cyc_Lexing_from_file(in_file);{struct _tuple13*
entry2;while((entry2=((struct _tuple13*(*)(struct Cyc_Lexing_lexbuf*lexbuf))Cyc_suck_line)(
_tmp1CE))!= 0){struct _tuple13 _tmp24E;struct _dynforward_ptr _tmp24F;struct
_dynforward_ptr*_tmp250;struct _tuple13*_tmp24D=(struct _tuple13*)_check_null(
entry2);_tmp24E=*_tmp24D;_tmp24F=_tmp24E.f1;_tmp250=_tmp24E.f2;if(((int(*)(
struct Cyc_Set_Set*s,struct _dynforward_ptr*elt))Cyc_Set_member)(_tmp1E8,_tmp250)){({
struct Cyc_String_pa_struct _tmp253;_tmp253.tag=0;_tmp253.f1=(struct
_dynforward_ptr)((struct _dynforward_ptr)*_tmp250);{void*_tmp251[1]={& _tmp253};
Cyc_fprintf(out_file,({const char*_tmp252="#ifndef %s\n";_tag_dynforward(_tmp252,
sizeof(char),_get_zero_arr_size(_tmp252,12));}),_tag_dynforward(_tmp251,sizeof(
void*),1));}});({struct Cyc_String_pa_struct _tmp256;_tmp256.tag=0;_tmp256.f1=(
struct _dynforward_ptr)((struct _dynforward_ptr)_tmp24F);{void*_tmp254[1]={&
_tmp256};Cyc_fprintf(out_file,({const char*_tmp255="%s\n";_tag_dynforward(_tmp255,
sizeof(char),_get_zero_arr_size(_tmp255,4));}),_tag_dynforward(_tmp254,sizeof(
void*),1));}});({void*_tmp257[0]={};Cyc_fprintf(out_file,({const char*_tmp258="#endif\n";
_tag_dynforward(_tmp258,sizeof(char),_get_zero_arr_size(_tmp258,8));}),
_tag_dynforward(_tmp257,sizeof(void*),0));});}}Cyc_fclose(in_file);if(Cyc_mode != (
void*)3)remove(_tmp188);if(hstubs != 0){struct Cyc_List_List*_tmp259=hstubs;for(0;
_tmp259 != 0;_tmp259=_tmp259->tl){struct _tuple14 _tmp25B;struct _dynforward_ptr
_tmp25C;struct _dynforward_ptr _tmp25D;struct _tuple14*_tmp25A=(struct _tuple14*)
_tmp259->hd;_tmp25B=*_tmp25A;_tmp25C=_tmp25B.f1;_tmp25D=_tmp25B.f2;if(_tmp25D.curr
!= ((struct _dynforward_ptr)_tag_dynforward(0,0,0)).curr  && (_tmp25C.curr == ((
struct _dynforward_ptr)_tag_dynforward(0,0,0)).curr  || ((int(*)(struct Cyc_Set_Set*
s,struct _dynforward_ptr*elt))Cyc_Set_member)(defined_symbols,({struct
_dynforward_ptr*_tmp25E=_cycalloc(sizeof(*_tmp25E));_tmp25E[0]=_tmp25C;_tmp25E;}))))
Cyc_fputs((const char*)_untag_dynforward_ptr(_tmp25D,sizeof(char),1),out_file);
else{({struct Cyc_String_pa_struct _tmp261;_tmp261.tag=0;_tmp261.f1=(struct
_dynforward_ptr)((struct _dynforward_ptr)_tmp25C);{void*_tmp25F[1]={& _tmp261};Cyc_log(({
const char*_tmp260="%s is not supported on this platform\n";_tag_dynforward(
_tmp260,sizeof(char),_get_zero_arr_size(_tmp260,38));}),_tag_dynforward(_tmp25F,
sizeof(void*),1));}});}}}({void*_tmp262[0]={};Cyc_fprintf(out_file,({const char*
_tmp263="#endif\n";_tag_dynforward(_tmp263,sizeof(char),_get_zero_arr_size(
_tmp263,8));}),_tag_dynforward(_tmp262,sizeof(void*),0));});Cyc_fclose(out_file);
if(cstubs != 0){out_file=(struct Cyc___cycFILE*)_check_null(Cyc_cstubs_file);{
struct Cyc_List_List*_tmp264=cstubs;for(0;_tmp264 != 0;_tmp264=_tmp264->tl){struct
_tuple14 _tmp266;struct _dynforward_ptr _tmp267;struct _dynforward_ptr _tmp268;struct
_tuple14*_tmp265=(struct _tuple14*)_tmp264->hd;_tmp266=*_tmp265;_tmp267=_tmp266.f1;
_tmp268=_tmp266.f2;if(_tmp268.curr != ((struct _dynforward_ptr)_tag_dynforward(0,0,
0)).curr  && (_tmp267.curr == ((struct _dynforward_ptr)_tag_dynforward(0,0,0)).curr
 || ((int(*)(struct Cyc_Set_Set*s,struct _dynforward_ptr*elt))Cyc_Set_member)(
defined_symbols,({struct _dynforward_ptr*_tmp269=_cycalloc(sizeof(*_tmp269));
_tmp269[0]=_tmp267;_tmp269;}))))Cyc_fputs((const char*)_untag_dynforward_ptr(
_tmp268,sizeof(char),1),out_file);}}}out_file=(struct Cyc___cycFILE*)_check_null(
Cyc_cycstubs_file);({struct Cyc_String_pa_struct _tmp26C;_tmp26C.tag=0;_tmp26C.f1=(
struct _dynforward_ptr)({const char*_tmp26D=filename;_tag_dynforward(_tmp26D,
sizeof(char),_get_zero_arr_size(_tmp26D,1));});{void*_tmp26A[1]={& _tmp26C};Cyc_fprintf(
out_file,({const char*_tmp26B="#include <%s>\n\n";_tag_dynforward(_tmp26B,sizeof(
char),_get_zero_arr_size(_tmp26B,16));}),_tag_dynforward(_tmp26A,sizeof(void*),1));}});
if(cycstubs != 0){out_file=(struct Cyc___cycFILE*)_check_null(Cyc_cycstubs_file);{
struct Cyc_List_List*_tmp26E=cycstubs;for(0;_tmp26E != 0;_tmp26E=_tmp26E->tl){
struct _tuple14 _tmp270;struct _dynforward_ptr _tmp271;struct _dynforward_ptr _tmp272;
struct _tuple14*_tmp26F=(struct _tuple14*)_tmp26E->hd;_tmp270=*_tmp26F;_tmp271=
_tmp270.f1;_tmp272=_tmp270.f2;if(_tmp272.curr != ((struct _dynforward_ptr)
_tag_dynforward(0,0,0)).curr  && (_tmp271.curr == ((struct _dynforward_ptr)
_tag_dynforward(0,0,0)).curr  || ((int(*)(struct Cyc_Set_Set*s,struct
_dynforward_ptr*elt))Cyc_Set_member)(defined_symbols,({struct _dynforward_ptr*
_tmp273=_cycalloc(sizeof(*_tmp273));_tmp273[0]=_tmp271;_tmp273;}))))Cyc_fputs((
const char*)_untag_dynforward_ptr(_tmp272,sizeof(char),1),out_file);}}({void*
_tmp274[0]={};Cyc_fprintf(out_file,({const char*_tmp275="\n";_tag_dynforward(
_tmp275,sizeof(char),_get_zero_arr_size(_tmp275,2));}),_tag_dynforward(_tmp274,
sizeof(void*),0));});}{int _tmp276=0;_npop_handler(0);return _tmp276;}}}}}}}};
_pop_handler();}else{void*_tmp18C=(void*)_exn_thrown;void*_tmp27C=_tmp18C;struct
_dynforward_ptr _tmp27D;_LL1B3: if(*((void**)_tmp27C)!= Cyc_NO_SUPPORT)goto _LL1B5;
_tmp27D=((struct Cyc_NO_SUPPORT_struct*)_tmp27C)->f1;_LL1B4:({struct Cyc_String_pa_struct
_tmp280;_tmp280.tag=0;_tmp280.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
_tmp27D);{void*_tmp27E[1]={& _tmp280};Cyc_fprintf(Cyc_stderr,({const char*_tmp27F="No support because %s\n";
_tag_dynforward(_tmp27F,sizeof(char),_get_zero_arr_size(_tmp27F,23));}),
_tag_dynforward(_tmp27E,sizeof(void*),1));}});goto _LL1B6;_LL1B5:;_LL1B6: maybe=
Cyc_fopen(filename,(const char*)"w");if(!((unsigned int)maybe)){({struct Cyc_String_pa_struct
_tmp283;_tmp283.tag=0;_tmp283.f1=(struct _dynforward_ptr)({const char*_tmp284=
filename;_tag_dynforward(_tmp284,sizeof(char),_get_zero_arr_size(_tmp284,1));});{
void*_tmp281[1]={& _tmp283};Cyc_fprintf(Cyc_stderr,({const char*_tmp282="Error: could not create file %s\n";
_tag_dynforward(_tmp282,sizeof(char),_get_zero_arr_size(_tmp282,33));}),
_tag_dynforward(_tmp281,sizeof(void*),1));}});return 1;}out_file=(struct Cyc___cycFILE*)
maybe;({struct Cyc_String_pa_struct _tmp287;_tmp287.tag=0;_tmp287.f1=(struct
_dynforward_ptr)({const char*_tmp288=filename;_tag_dynforward(_tmp288,sizeof(char),
_get_zero_arr_size(_tmp288,1));});{void*_tmp285[1]={& _tmp287};Cyc_fprintf(
out_file,({const char*_tmp286="#error -- %s is not supported on this platform\n";
_tag_dynforward(_tmp286,sizeof(char),_get_zero_arr_size(_tmp286,48));}),
_tag_dynforward(_tmp285,sizeof(void*),1));}});Cyc_fclose(out_file);({struct Cyc_String_pa_struct
_tmp28B;_tmp28B.tag=0;_tmp28B.f1=(struct _dynforward_ptr)({const char*_tmp28C=
filename;_tag_dynforward(_tmp28C,sizeof(char),_get_zero_arr_size(_tmp28C,1));});{
void*_tmp289[1]={& _tmp28B};Cyc_fprintf(Cyc_stderr,({const char*_tmp28A="Warning: %s will not be supported on this platform\n";
_tag_dynforward(_tmp28A,sizeof(char),_get_zero_arr_size(_tmp28A,52));}),
_tag_dynforward(_tmp289,sizeof(void*),1));}});({void*_tmp28D[0]={};Cyc_log(({
const char*_tmp28E="Not supported on this platform\n";_tag_dynforward(_tmp28E,
sizeof(char),_get_zero_arr_size(_tmp28E,32));}),_tag_dynforward(_tmp28D,sizeof(
void*),0));});remove(_tmp188);remove(_tmp189);remove(_tmp18A);return 0;_LL1B7:;
_LL1B8:(void)_throw(_tmp27C);_LL1B2:;}}}}int Cyc_process_specfile(const char*file,
const char*dir){struct Cyc___cycFILE*_tmp2A4=Cyc_fopen(file,(const char*)"r");if(!((
unsigned int)_tmp2A4)){({struct Cyc_String_pa_struct _tmp2A7;_tmp2A7.tag=0;_tmp2A7.f1=(
struct _dynforward_ptr)({const char*_tmp2A8=file;_tag_dynforward(_tmp2A8,sizeof(
char),_get_zero_arr_size(_tmp2A8,1));});{void*_tmp2A5[1]={& _tmp2A7};Cyc_fprintf(
Cyc_stderr,({const char*_tmp2A6="Error: could not open %s\n";_tag_dynforward(
_tmp2A6,sizeof(char),_get_zero_arr_size(_tmp2A6,26));}),_tag_dynforward(_tmp2A5,
sizeof(void*),1));}});return 1;}{struct Cyc___cycFILE*_tmp2A9=(struct Cyc___cycFILE*)
_tmp2A4;struct _dynforward_ptr buf=({char*_tmp2C2=({unsigned int _tmp2BF=(
unsigned int)1024;char*_tmp2C0=(char*)_cycalloc_atomic(_check_times(sizeof(char),
_tmp2BF + 1));{unsigned int _tmp2C1=_tmp2BF;unsigned int i;for(i=0;i < _tmp2C1;i ++){
_tmp2C0[i]='\000';}_tmp2C0[_tmp2C1]=(char)0;}_tmp2C0;});_tag_dynforward(_tmp2C2,
sizeof(char),_get_zero_arr_size(_tmp2C2,(unsigned int)1024 + 1));});struct
_dynforward_ptr _tmp2AA=Cyc_getcwd(buf,_get_dynforward_size(buf,sizeof(char)));
if(Cyc_mode != (void*)2){if(chdir(dir)){({struct Cyc_String_pa_struct _tmp2AD;
_tmp2AD.tag=0;_tmp2AD.f1=(struct _dynforward_ptr)({const char*_tmp2AE=dir;
_tag_dynforward(_tmp2AE,sizeof(char),_get_zero_arr_size(_tmp2AE,1));});{void*
_tmp2AB[1]={& _tmp2AD};Cyc_fprintf(Cyc_stderr,({const char*_tmp2AC="Error: can't change directory to %s\n";
_tag_dynforward(_tmp2AC,sizeof(char),_get_zero_arr_size(_tmp2AC,37));}),
_tag_dynforward(_tmp2AB,sizeof(void*),1));}});return 1;}}if(Cyc_mode == (void*)1){
struct _dynforward_ptr _tmp2AF=Cstring_to_string(Ccomp);system((const char*)
_untag_dynforward_ptr(({struct Cyc_String_pa_struct _tmp2B2;_tmp2B2.tag=0;_tmp2B2.f1=(
struct _dynforward_ptr)((struct _dynforward_ptr)_tmp2AF);{void*_tmp2B0[1]={&
_tmp2B2};Cyc_aprintf(({const char*_tmp2B1="echo | %s -E -dM - -o INITMACROS.h\n";
_tag_dynforward(_tmp2B1,sizeof(char),_get_zero_arr_size(_tmp2B1,36));}),
_tag_dynforward(_tmp2B0,sizeof(void*),1));}}),sizeof(char),1));}{struct Cyc_Lexing_lexbuf*
_tmp2B3=Cyc_Lexing_from_file(_tmp2A9);struct _tuple15*entry;while((entry=((struct
_tuple15*(*)(struct Cyc_Lexing_lexbuf*lexbuf))Cyc_spec)(_tmp2B3))!= 0){struct
_tuple15 _tmp2B5;struct _dynforward_ptr _tmp2B6;struct Cyc_List_List*_tmp2B7;struct
Cyc_List_List*_tmp2B8;struct Cyc_List_List*_tmp2B9;struct Cyc_List_List*_tmp2BA;
struct Cyc_List_List*_tmp2BB;struct _tuple15*_tmp2B4=(struct _tuple15*)_check_null(
entry);_tmp2B5=*_tmp2B4;_tmp2B6=_tmp2B5.f1;_tmp2B7=_tmp2B5.f2;_tmp2B8=_tmp2B5.f3;
_tmp2B9=_tmp2B5.f4;_tmp2BA=_tmp2B5.f5;_tmp2BB=_tmp2B5.f6;if(Cyc_process_file((
const char*)_untag_dynforward_ptr(_tmp2B6,sizeof(char),1),_tmp2B7,_tmp2B8,_tmp2B9,
_tmp2BA,_tmp2BB))return 1;}Cyc_fclose(_tmp2A9);if(Cyc_mode != (void*)2){if(chdir((
const char*)((char*)_untag_dynforward_ptr(_tmp2AA,sizeof(char),1)))){({struct Cyc_String_pa_struct
_tmp2BE;_tmp2BE.tag=0;_tmp2BE.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
_tmp2AA);{void*_tmp2BC[1]={& _tmp2BE};Cyc_fprintf(Cyc_stderr,({const char*_tmp2BD="Error: could not change directory to %s\n";
_tag_dynforward(_tmp2BD,sizeof(char),_get_zero_arr_size(_tmp2BD,41));}),
_tag_dynforward(_tmp2BC,sizeof(void*),1));}});return 1;}}return 0;}}}static char
_tmp2C3[13]="BUILDLIB.OUT";static struct _dynforward_ptr Cyc_output_dir={_tmp2C3,
_tmp2C3 + 13};static void Cyc_set_output_dir(struct _dynforward_ptr s){Cyc_output_dir=
s;}static struct Cyc_List_List*Cyc_spec_files=0;static void Cyc_add_spec_file(struct
_dynforward_ptr s){Cyc_spec_files=({struct Cyc_List_List*_tmp2C4=_cycalloc(sizeof(*
_tmp2C4));_tmp2C4->hd=(const char*)_untag_dynforward_ptr(s,sizeof(char),1);
_tmp2C4->tl=Cyc_spec_files;_tmp2C4;});}static void Cyc_set_GATHER(){Cyc_mode=(void*)
1;}static void Cyc_set_GATHERSCRIPT(){Cyc_mode=(void*)2;}static void Cyc_set_FINISH(){
Cyc_mode=(void*)3;}static int Cyc_badparse=0;static void Cyc_unsupported_option(
struct _dynforward_ptr s){({struct Cyc_String_pa_struct _tmp2C7;_tmp2C7.tag=0;
_tmp2C7.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)s);{void*_tmp2C5[1]={&
_tmp2C7};Cyc_fprintf(Cyc_stderr,({const char*_tmp2C6="Unsupported option %s\n";
_tag_dynforward(_tmp2C6,sizeof(char),_get_zero_arr_size(_tmp2C6,23));}),
_tag_dynforward(_tmp2C5,sizeof(void*),1));}});Cyc_badparse=1;}void
GC_blacklist_warn_clear();struct _tuple19{struct _dynforward_ptr f1;int f2;struct
_dynforward_ptr f3;void*f4;struct _dynforward_ptr f5;};int Cyc_main(int argc,struct
_dynforward_ptr argv){GC_blacklist_warn_clear();{struct Cyc_List_List*options=({
struct _tuple19*_tmp2E8[5];_tmp2E8[4]=({struct _tuple19*_tmp301=_cycalloc(sizeof(*
_tmp301));_tmp301->f1=({const char*_tmp306="-";_tag_dynforward(_tmp306,sizeof(
char),_get_zero_arr_size(_tmp306,2));});_tmp301->f2=1;_tmp301->f3=({const char*
_tmp305="";_tag_dynforward(_tmp305,sizeof(char),_get_zero_arr_size(_tmp305,1));});
_tmp301->f4=(void*)({struct Cyc_Arg_Flag_spec_struct*_tmp303=_cycalloc(sizeof(*
_tmp303));_tmp303[0]=({struct Cyc_Arg_Flag_spec_struct _tmp304;_tmp304.tag=1;
_tmp304.f1=Cyc_unsupported_option;_tmp304;});_tmp303;});_tmp301->f5=({const char*
_tmp302="";_tag_dynforward(_tmp302,sizeof(char),_get_zero_arr_size(_tmp302,1));});
_tmp301;});_tmp2E8[3]=({struct _tuple19*_tmp2FB=_cycalloc(sizeof(*_tmp2FB));
_tmp2FB->f1=({const char*_tmp300="-finish";_tag_dynforward(_tmp300,sizeof(char),
_get_zero_arr_size(_tmp300,8));});_tmp2FB->f2=0;_tmp2FB->f3=({const char*_tmp2FF="";
_tag_dynforward(_tmp2FF,sizeof(char),_get_zero_arr_size(_tmp2FF,1));});_tmp2FB->f4=(
void*)({struct Cyc_Arg_Unit_spec_struct*_tmp2FD=_cycalloc(sizeof(*_tmp2FD));
_tmp2FD[0]=({struct Cyc_Arg_Unit_spec_struct _tmp2FE;_tmp2FE.tag=0;_tmp2FE.f1=Cyc_set_FINISH;
_tmp2FE;});_tmp2FD;});_tmp2FB->f5=({const char*_tmp2FC="Produce Cyclone headers from pre-gathered C library info";
_tag_dynforward(_tmp2FC,sizeof(char),_get_zero_arr_size(_tmp2FC,57));});_tmp2FB;});
_tmp2E8[2]=({struct _tuple19*_tmp2F5=_cycalloc(sizeof(*_tmp2F5));_tmp2F5->f1=({
const char*_tmp2FA="-gatherscript";_tag_dynforward(_tmp2FA,sizeof(char),
_get_zero_arr_size(_tmp2FA,14));});_tmp2F5->f2=0;_tmp2F5->f3=({const char*_tmp2F9="";
_tag_dynforward(_tmp2F9,sizeof(char),_get_zero_arr_size(_tmp2F9,1));});_tmp2F5->f4=(
void*)({struct Cyc_Arg_Unit_spec_struct*_tmp2F7=_cycalloc(sizeof(*_tmp2F7));
_tmp2F7[0]=({struct Cyc_Arg_Unit_spec_struct _tmp2F8;_tmp2F8.tag=0;_tmp2F8.f1=Cyc_set_GATHERSCRIPT;
_tmp2F8;});_tmp2F7;});_tmp2F5->f5=({const char*_tmp2F6="Produce a script to gather C library info";
_tag_dynforward(_tmp2F6,sizeof(char),_get_zero_arr_size(_tmp2F6,42));});_tmp2F5;});
_tmp2E8[1]=({struct _tuple19*_tmp2EF=_cycalloc(sizeof(*_tmp2EF));_tmp2EF->f1=({
const char*_tmp2F4="-gather";_tag_dynforward(_tmp2F4,sizeof(char),
_get_zero_arr_size(_tmp2F4,8));});_tmp2EF->f2=0;_tmp2EF->f3=({const char*_tmp2F3="";
_tag_dynforward(_tmp2F3,sizeof(char),_get_zero_arr_size(_tmp2F3,1));});_tmp2EF->f4=(
void*)({struct Cyc_Arg_Unit_spec_struct*_tmp2F1=_cycalloc(sizeof(*_tmp2F1));
_tmp2F1[0]=({struct Cyc_Arg_Unit_spec_struct _tmp2F2;_tmp2F2.tag=0;_tmp2F2.f1=Cyc_set_GATHER;
_tmp2F2;});_tmp2F1;});_tmp2EF->f5=({const char*_tmp2F0="Gather C library info but don't produce Cyclone headers";
_tag_dynforward(_tmp2F0,sizeof(char),_get_zero_arr_size(_tmp2F0,56));});_tmp2EF;});
_tmp2E8[0]=({struct _tuple19*_tmp2E9=_cycalloc(sizeof(*_tmp2E9));_tmp2E9->f1=({
const char*_tmp2EE="-d";_tag_dynforward(_tmp2EE,sizeof(char),_get_zero_arr_size(
_tmp2EE,3));});_tmp2E9->f2=0;_tmp2E9->f3=({const char*_tmp2ED=" <file>";
_tag_dynforward(_tmp2ED,sizeof(char),_get_zero_arr_size(_tmp2ED,8));});_tmp2E9->f4=(
void*)({struct Cyc_Arg_String_spec_struct*_tmp2EB=_cycalloc(sizeof(*_tmp2EB));
_tmp2EB[0]=({struct Cyc_Arg_String_spec_struct _tmp2EC;_tmp2EC.tag=5;_tmp2EC.f1=
Cyc_set_output_dir;_tmp2EC;});_tmp2EB;});_tmp2E9->f5=({const char*_tmp2EA="Set the output directory to <file>";
_tag_dynforward(_tmp2EA,sizeof(char),_get_zero_arr_size(_tmp2EA,35));});_tmp2E9;});((
struct Cyc_List_List*(*)(struct _dynforward_ptr))Cyc_List_list)(_tag_dynforward(
_tmp2E8,sizeof(struct _tuple19*),5));});Cyc_Arg_parse(options,Cyc_add_spec_file,({
const char*_tmp2C8="Options:";_tag_dynforward(_tmp2C8,sizeof(char),
_get_zero_arr_size(_tmp2C8,9));}),argv);if(Cyc_badparse  || Cyc_spec_files == 0){
Cyc_Arg_usage(options,({const char*_tmp2C9="Usage: buildlib [options] specfile1 specfile2 ...\nOptions:";
_tag_dynforward(_tmp2C9,sizeof(char),_get_zero_arr_size(_tmp2C9,59));}));return 1;}
if(Cyc_mode == (void*)2){Cyc_script_file=Cyc_fopen((const char*)"BUILDLIB.sh",(
const char*)"w");if(!((unsigned int)Cyc_script_file)){({void*_tmp2CA[0]={};Cyc_fprintf(
Cyc_stderr,({const char*_tmp2CB="Could not create file BUILDLIB.sh\n";
_tag_dynforward(_tmp2CB,sizeof(char),_get_zero_arr_size(_tmp2CB,35));}),
_tag_dynforward(_tmp2CA,sizeof(void*),0));});exit(1);}({void*_tmp2CC[0]={};Cyc_prscript(({
const char*_tmp2CD="#!/bin/sh\n";_tag_dynforward(_tmp2CD,sizeof(char),
_get_zero_arr_size(_tmp2CD,11));}),_tag_dynforward(_tmp2CC,sizeof(void*),0));});({
void*_tmp2CE[0]={};Cyc_prscript(({const char*_tmp2CF="GCC=\"gcc\"\n";
_tag_dynforward(_tmp2CF,sizeof(char),_get_zero_arr_size(_tmp2CF,11));}),
_tag_dynforward(_tmp2CE,sizeof(void*),0));});}if(Cyc_force_directory_prefixes(
Cyc_output_dir) || Cyc_force_directory(Cyc_output_dir)){({struct Cyc_String_pa_struct
_tmp2D2;_tmp2D2.tag=0;_tmp2D2.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
Cyc_output_dir);{void*_tmp2D0[1]={& _tmp2D2};Cyc_fprintf(Cyc_stderr,({const char*
_tmp2D1="Error: could not create directory %s\n";_tag_dynforward(_tmp2D1,sizeof(
char),_get_zero_arr_size(_tmp2D1,38));}),_tag_dynforward(_tmp2D0,sizeof(void*),1));}});
return 1;}if(Cyc_mode == (void*)2){({struct Cyc_String_pa_struct _tmp2D5;_tmp2D5.tag=
0;_tmp2D5.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)Cyc_output_dir);{
void*_tmp2D3[1]={& _tmp2D5};Cyc_prscript(({const char*_tmp2D4="cd %s\n";
_tag_dynforward(_tmp2D4,sizeof(char),_get_zero_arr_size(_tmp2D4,7));}),
_tag_dynforward(_tmp2D3,sizeof(void*),1));}});({void*_tmp2D6[0]={};Cyc_prscript(({
const char*_tmp2D7="echo | $GCC -E -dM - -o INITMACROS.h\n";_tag_dynforward(
_tmp2D7,sizeof(char),_get_zero_arr_size(_tmp2D7,38));}),_tag_dynforward(_tmp2D6,
sizeof(void*),0));});}if(!Cyc_gathering()){Cyc_log_file=Cyc_fopen((const char*)
_untag_dynforward_ptr(Cyc_Filename_concat(Cyc_output_dir,({const char*_tmp2D8="BUILDLIB.LOG";
_tag_dynforward(_tmp2D8,sizeof(char),_get_zero_arr_size(_tmp2D8,13));})),sizeof(
char),1),(const char*)"w");if(!((unsigned int)Cyc_log_file)){({struct Cyc_String_pa_struct
_tmp2DB;_tmp2DB.tag=0;_tmp2DB.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
Cyc_output_dir);{void*_tmp2D9[1]={& _tmp2DB};Cyc_fprintf(Cyc_stderr,({const char*
_tmp2DA="Error: could not create log file in directory %s\n";_tag_dynforward(
_tmp2DA,sizeof(char),_get_zero_arr_size(_tmp2DA,50));}),_tag_dynforward(_tmp2D9,
sizeof(void*),1));}});return 1;}Cyc_cstubs_file=Cyc_fopen((const char*)
_untag_dynforward_ptr(Cyc_Filename_concat(Cyc_output_dir,({const char*_tmp2DC="cstubs.c";
_tag_dynforward(_tmp2DC,sizeof(char),_get_zero_arr_size(_tmp2DC,9));})),sizeof(
char),1),(const char*)"w");if(!((unsigned int)Cyc_cstubs_file)){({struct Cyc_String_pa_struct
_tmp2DF;_tmp2DF.tag=0;_tmp2DF.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
Cyc_output_dir);{void*_tmp2DD[1]={& _tmp2DF};Cyc_fprintf(Cyc_stderr,({const char*
_tmp2DE="Error: could not create cstubs.c in directory %s\n";_tag_dynforward(
_tmp2DE,sizeof(char),_get_zero_arr_size(_tmp2DE,50));}),_tag_dynforward(_tmp2DD,
sizeof(void*),1));}});return 1;}Cyc_cycstubs_file=Cyc_fopen((const char*)
_untag_dynforward_ptr(Cyc_Filename_concat(Cyc_output_dir,({const char*_tmp2E0="cycstubs.cyc";
_tag_dynforward(_tmp2E0,sizeof(char),_get_zero_arr_size(_tmp2E0,13));})),sizeof(
char),1),(const char*)"w");if(!((unsigned int)Cyc_cycstubs_file)){({struct Cyc_String_pa_struct
_tmp2E3;_tmp2E3.tag=0;_tmp2E3.f1=(struct _dynforward_ptr)((struct _dynforward_ptr)
Cyc_output_dir);{void*_tmp2E1[1]={& _tmp2E3};Cyc_fprintf(Cyc_stderr,({const char*
_tmp2E2="Error: could not create cycstubs.c in directory %s\n";_tag_dynforward(
_tmp2E2,sizeof(char),_get_zero_arr_size(_tmp2E2,52));}),_tag_dynforward(_tmp2E1,
sizeof(void*),1));}});return 1;}({void*_tmp2E4[0]={};Cyc_fprintf((struct Cyc___cycFILE*)
_check_null(Cyc_cycstubs_file),({const char*_tmp2E5="#include <core.h>\nusing Core;\n\n";
_tag_dynforward(_tmp2E5,sizeof(char),_get_zero_arr_size(_tmp2E5,32));}),
_tag_dynforward(_tmp2E4,sizeof(void*),0));});}{const char*outdir=(const char*)
_untag_dynforward_ptr(Cyc_output_dir,sizeof(char),1);for(0;Cyc_spec_files != 0;
Cyc_spec_files=((struct Cyc_List_List*)_check_null(Cyc_spec_files))->tl){if(Cyc_process_specfile((
const char*)((struct Cyc_List_List*)_check_null(Cyc_spec_files))->hd,outdir)){({
void*_tmp2E6[0]={};Cyc_fprintf(Cyc_stderr,({const char*_tmp2E7="FATAL ERROR -- QUIT!\n";
_tag_dynforward(_tmp2E7,sizeof(char),_get_zero_arr_size(_tmp2E7,22));}),
_tag_dynforward(_tmp2E6,sizeof(void*),0));});exit(1);}}if(Cyc_mode == (void*)2)
Cyc_fclose((struct Cyc___cycFILE*)_check_null(Cyc_script_file));else{if(!Cyc_gathering()){
Cyc_fclose((struct Cyc___cycFILE*)_check_null(Cyc_log_file));Cyc_fclose((struct
Cyc___cycFILE*)_check_null(Cyc_cstubs_file));Cyc_fclose((struct Cyc___cycFILE*)
_check_null(Cyc_cycstubs_file));}}return 0;}}}