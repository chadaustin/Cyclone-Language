#include <setjmp.h>
/* This is a C header file to be used by the output of the Cyclone to
   C translator.  The corresponding definitions are in file
   lib/runtime_cyc.c
*/
#ifndef _CYC_INCLUDE_H_
#define _CYC_INCLUDE_H_

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
  char data[1];  /*FJS: used to be size 0, but that's forbidden in ansi c*/
};

struct _RegionHandle {
  struct _RuntimeStack s;
  struct _RegionPage *curr;
  char               *offset;
  char               *last_plus_one;
  struct _DynRegionHandle *sub_regions;
#ifdef CYC_REGION_PROFILE
  const char         *name;
#endif
};

struct _DynRegionFrame {
  struct _RuntimeStack s;
  struct _DynRegionHandle *x;
};

extern struct _RegionHandle _new_region(const char *);
extern void * _region_malloc(struct _RegionHandle *, unsigned);
extern void * _region_calloc(struct _RegionHandle *, unsigned t, unsigned n);
extern void   _free_region(struct _RegionHandle *);
extern void   _reset_region(struct _RegionHandle *);
extern struct _RegionHandle *_open_dynregion(struct _DynRegionFrame *f,
                                             struct _DynRegionHandle *h);
extern void   _pop_dynregion();

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
struct Cyc_Null_Exception_struct { char *tag; };
struct Cyc_Array_bounds_struct { char *tag; };
struct Cyc_Match_Exception_struct { char *tag; };
struct Cyc_Bad_alloc_struct { char *tag; };
extern char Cyc_Null_Exception[];
extern char Cyc_Array_bounds[];
extern char Cyc_Match_Exception[];
extern char Cyc_Bad_alloc[];

/* Built-in Run-time Checks and company */
#ifdef __APPLE__
#define _INLINE_FUNCTIONS
#endif

#ifdef CYC_ANSI_OUTPUT
#define _INLINE  
#define _INLINE_FUNCTIONS
#else
#define _INLINE inline
#endif

#ifdef VC_C
#define _CYC_U_LONG_LONG_T __int64
#else
#ifdef GCC_C
#define _CYC_U_LONG_LONG_T unsigned long long
#else
#define _CYC_U_LONG_LONG_T unsigned long long
#endif
#endif

#ifdef NO_CYC_NULL_CHECKS
#define _check_null(ptr) (ptr)
#else
#ifdef _INLINE_FUNCTIONS
static _INLINE void *
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
static _INLINE char *
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
static _INLINE unsigned
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
#define _zero_arr_plus_char(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#define _zero_arr_plus_short(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#define _zero_arr_plus_int(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#define _zero_arr_plus_float(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#define _zero_arr_plus_double(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#define _zero_arr_plus_longdouble(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#define _zero_arr_plus_voidstar(orig_x,orig_sz,orig_i) ((orig_x)+(orig_i))
#else
static _INLINE char *
_zero_arr_plus_char(char *orig_x, int orig_sz, int orig_i) {
  unsigned int _czs_temp;
  if ((orig_x) == 0) _throw_null();
  if (orig_i < 0) _throw_arraybounds();
  for (_czs_temp=orig_sz; _czs_temp < orig_i; _czs_temp++)
    if (orig_x[_czs_temp] == 0) _throw_arraybounds();
  return orig_x + orig_i;
}
static _INLINE short *
_zero_arr_plus_short(short *orig_x, int orig_sz, int orig_i) {
  unsigned int _czs_temp;
  if ((orig_x) == 0) _throw_null();
  if (orig_i < 0) _throw_arraybounds();
  for (_czs_temp=orig_sz; _czs_temp < orig_i; _czs_temp++)
    if (orig_x[_czs_temp] == 0) _throw_arraybounds();
  return orig_x + orig_i;
}
static _INLINE int *
_zero_arr_plus_int(int *orig_x, int orig_sz, int orig_i) {
  unsigned int _czs_temp;
  if ((orig_x) == 0) _throw_null();
  if (orig_i < 0) _throw_arraybounds();
  for (_czs_temp=orig_sz; _czs_temp < orig_i; _czs_temp++)
    if (orig_x[_czs_temp] == 0) _throw_arraybounds();
  return orig_x + orig_i;
}
static _INLINE float *
_zero_arr_plus_float(float *orig_x, int orig_sz, int orig_i) {
  unsigned int _czs_temp;
  if ((orig_x) == 0) _throw_null();
  if (orig_i < 0) _throw_arraybounds();
  for (_czs_temp=orig_sz; _czs_temp < orig_i; _czs_temp++)
    if (orig_x[_czs_temp] == 0) _throw_arraybounds();
  return orig_x + orig_i;
}
static _INLINE double *
_zero_arr_plus_double(double *orig_x, int orig_sz, int orig_i) {
  unsigned int _czs_temp;
  if ((orig_x) == 0) _throw_null();
  if (orig_i < 0) _throw_arraybounds();
  for (_czs_temp=orig_sz; _czs_temp < orig_i; _czs_temp++)
    if (orig_x[_czs_temp] == 0) _throw_arraybounds();
  return orig_x + orig_i;
}
static _INLINE long double *
_zero_arr_plus_longdouble(long double *orig_x, int orig_sz, int orig_i) {
  unsigned int _czs_temp;
  if ((orig_x) == 0) _throw_null();
  if (orig_i < 0) _throw_arraybounds();
  for (_czs_temp=orig_sz; _czs_temp < orig_i; _czs_temp++)
    if (orig_x[_czs_temp] == 0) _throw_arraybounds();
  return orig_x + orig_i;
}
static _INLINE void *
_zero_arr_plus_voidstar(void **orig_x, int orig_sz, int orig_i) {
  unsigned int _czs_temp;
  if ((orig_x) == 0) _throw_null();
  if (orig_i < 0) _throw_arraybounds();
  for (_czs_temp=orig_sz; _czs_temp < orig_i; _czs_temp++)
    if (orig_x[_czs_temp] == 0) _throw_arraybounds();
  return orig_x + orig_i;
}
#endif


/* Calculates the number of elements in a zero-terminated, thin array.
   If non-null, the array is guaranteed to have orig_offset elements. */
static _INLINE int
_get_zero_arr_size_char(const char *orig_x, unsigned int orig_offset) {
  const char *_gres_x = orig_x;
  unsigned int _gres = 0;
  if (_gres_x != 0) {
     _gres = orig_offset;
     _gres_x += orig_offset - 1;
     while (*_gres_x != 0) { _gres_x++; _gres++; }
  }
  return _gres; 
}
static _INLINE int
_get_zero_arr_size_short(const short *orig_x, unsigned int orig_offset) {
  const short *_gres_x = orig_x;
  unsigned int _gres = 0;
  if (_gres_x != 0) {
     _gres = orig_offset;
     _gres_x += orig_offset - 1;
     while (*_gres_x != 0) { _gres_x++; _gres++; }
  }
  return _gres; 
}
static _INLINE int
_get_zero_arr_size_int(const int *orig_x, unsigned int orig_offset) {
  const int *_gres_x = orig_x;
  unsigned int _gres = 0;
  if (_gres_x != 0) {
     _gres = orig_offset;
     _gres_x += orig_offset - 1;
     while (*_gres_x != 0) { _gres_x++; _gres++; }
  }
  return _gres; 
}
static _INLINE int
_get_zero_arr_size_float(const float *orig_x, unsigned int orig_offset) {
  const float *_gres_x = orig_x;
  unsigned int _gres = 0;
  if (_gres_x != 0) {
     _gres = orig_offset;
     _gres_x += orig_offset - 1;
     while (*_gres_x != 0) { _gres_x++; _gres++; }
  }
  return _gres; 
}
static _INLINE int
_get_zero_arr_size_double(const double *orig_x, unsigned int orig_offset) {
  const double *_gres_x = orig_x;
  unsigned int _gres = 0;
  if (_gres_x != 0) {
     _gres = orig_offset;
     _gres_x += orig_offset - 1;
     while (*_gres_x != 0) { _gres_x++; _gres++; }
  }
  return _gres; 
}
static _INLINE int
_get_zero_arr_size_longdouble(const long double *orig_x, unsigned int orig_offset) {
  const long double *_gres_x = orig_x;
  unsigned int _gres = 0;
  if (_gres_x != 0) {
     _gres = orig_offset;
     _gres_x += orig_offset - 1;
     while (*_gres_x != 0) { _gres_x++; _gres++; }
  }
  return _gres; 
}
static _INLINE int
_get_zero_arr_size_voidstar(const void **orig_x, unsigned int orig_offset) {
  const void **_gres_x = orig_x;
  unsigned int _gres = 0;
  if (_gres_x != 0) {
     _gres = orig_offset;
     _gres_x += orig_offset - 1;
     while (*_gres_x != 0) { _gres_x++; _gres++; }
  }
  return _gres; 
}


/* Does in-place addition of a zero-terminated pointer (x += e and ++x).  
   Note that this expands to call _zero_arr_plus. */
/*#define _zero_arr_inplace_plus(x,orig_i) ({ \
  typedef _zap_tx = (*x); \
  _zap_tx **_zap_x = &((_zap_tx*)x); \
  *_zap_x = _zero_arr_plus(*_zap_x,1,(orig_i)); })
  */
static _INLINE void 
_zero_arr_inplace_plus_char(char *x, int orig_i) {
  char **_zap_x = &x;
  *_zap_x = _zero_arr_plus_char(*_zap_x,1,orig_i);
}
static _INLINE void 
_zero_arr_inplace_plus_short(short *x, int orig_i) {
  short **_zap_x = &x;
  *_zap_x = _zero_arr_plus_short(*_zap_x,1,orig_i);
}
static _INLINE void 
_zero_arr_inplace_plus_int(int *x, int orig_i) {
  int **_zap_x = &x;
  *_zap_x = _zero_arr_plus_int(*_zap_x,1,orig_i);
}
static _INLINE void 
_zero_arr_inplace_plus_float(float *x, int orig_i) {
  float **_zap_x = &x;
  *_zap_x = _zero_arr_plus_float(*_zap_x,1,orig_i);
}
static _INLINE void 
_zero_arr_inplace_plus_double(double *x, int orig_i) {
  double **_zap_x = &x;
  *_zap_x = _zero_arr_plus_double(*_zap_x,1,orig_i);
}
static _INLINE void 
_zero_arr_inplace_plus_longdouble(long double *x, int orig_i) {
  long double **_zap_x = &x;
  *_zap_x = _zero_arr_plus_longdouble(*_zap_x,1,orig_i);
}
static _INLINE void 
_zero_arr_inplace_plus_voidstar(void **x, int orig_i) {
  void ***_zap_x = &x;
  *_zap_x = _zero_arr_plus_voidstar(*_zap_x,1,orig_i);
}




/* Does in-place increment of a zero-terminated pointer (e.g., x++).
   Note that this expands to call _zero_arr_plus. */
/*#define _zero_arr_inplace_plus_post(x,orig_i) ({ \
  typedef _zap_tx = (*x); \
  _zap_tx **_zap_x = &((_zap_tx*)x); \
  _zap_tx *_zap_res = *_zap_x; \
  *_zap_x = _zero_arr_plus(_zap_res,1,(orig_i)); \
  _zap_res; })*/
  
static _INLINE char *
_zero_arr_inplace_plus_post_char(char *x, int orig_i){
  char ** _zap_x = &x;
  char * _zap_res = *_zap_x;
  *_zap_x = _zero_arr_plus_char(_zap_res,1,orig_i);
  return _zap_res;
}
static _INLINE short *
_zero_arr_inplace_plus_post_short(short *x, int orig_i){
  short **_zap_x = &x;
  short * _zap_res = *_zap_x;
  *_zap_x = _zero_arr_plus_short(_zap_res,1,orig_i);
  return _zap_res;
}
static _INLINE int *
_zero_arr_inplace_plus_post_int(int *x, int orig_i){
  int **_zap_x = &x;
  int * _zap_res = *_zap_x;
  *_zap_x = _zero_arr_plus_int(_zap_res,1,orig_i);
  return _zap_res;
}
static _INLINE float *
_zero_arr_inplace_plus_post_float(float *x, int orig_i){
  float **_zap_x = &x;
  float * _zap_res = *_zap_x;
  *_zap_x = _zero_arr_plus_float(_zap_res,1,orig_i);
  return _zap_res;
}
static _INLINE double *
_zero_arr_inplace_plus_post_double(double *x, int orig_i){
  double **_zap_x = &x;
  double * _zap_res = *_zap_x;
  *_zap_x = _zero_arr_plus_double(_zap_res,1,orig_i);
  return _zap_res;
}
static _INLINE long double *
_zero_arr_inplace_plus_post_longdouble(long double *x, int orig_i){
  long double **_zap_x = &x;
  long double * _zap_res = *_zap_x;
  *_zap_x = _zero_arr_plus_longdouble(_zap_res,1,orig_i);
  return _zap_res;
}
static _INLINE void **
_zero_arr_inplace_plus_post_voidstar(void **x, int orig_i){
  void ***_zap_x = &x;
  void ** _zap_res = *_zap_x;
  *_zap_x = _zero_arr_plus_voidstar(_zap_res,1,orig_i);
  return _zap_res;
}



/* functions for dealing with dynamically sized pointers */
#ifdef NO_CYC_BOUNDS_CHECKS
#ifdef _INLINE_FUNCTIONS
static _INLINE unsigned char *
_check_dyneither_subscript(struct _dyneither_ptr arr,unsigned elt_sz,unsigned index) {
  struct _dyneither_ptr _cus_arr = (arr);
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
#endif
#else
#ifdef _INLINE_FUNCTIONS
static _INLINE unsigned char *
_check_dyneither_subscript(struct _dyneither_ptr arr,unsigned elt_sz,unsigned index) {
  struct _dyneither_ptr _cus_arr = (arr);
  unsigned _cus_elt_sz = (elt_sz);
  unsigned _cus_index = (index);
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index;
  /* JGM: not needed! if (!_cus_arr.base) _throw_null(); */ 
  if (_cus_ans < _cus_arr.base || _cus_ans >= _cus_arr.last_plus_one)
    _throw_arraybounds();
  return _cus_ans;
}
#else
#define _check_dyneither_subscript(arr,elt_sz,index) ({ \
  struct _dyneither_ptr _cus_arr = (arr); \
  unsigned _cus_elt_sz = (elt_sz); \
  unsigned _cus_index = (index); \
  unsigned char *_cus_ans = _cus_arr.curr + _cus_elt_sz * _cus_index; \
  /* JGM: not needed! if (!_cus_arr.base) _throw_null();*/ \
  if (_cus_ans < _cus_arr.base || _cus_ans >= _cus_arr.last_plus_one) \
    _throw_arraybounds(); \
  _cus_ans; })
#endif
#endif

#ifdef _INLINE_FUNCTIONS
static _INLINE struct _dyneither_ptr
_tag_dyneither(const void *tcurr,unsigned elt_sz,unsigned num_elts) {
  struct _dyneither_ptr _tag_arr_ans;
  _tag_arr_ans.base = _tag_arr_ans.curr = (void*)(tcurr);
  _tag_arr_ans.last_plus_one = _tag_arr_ans.base + (elt_sz) * (num_elts);
  return _tag_arr_ans;
}
#else
#define _tag_dyneither(tcurr,elt_sz,num_elts) ({ \
  struct _dyneither_ptr _tag_arr_ans; \
  _tag_arr_ans.base = _tag_arr_ans.curr = (void*)(tcurr); \
  _tag_arr_ans.last_plus_one = _tag_arr_ans.base + (elt_sz) * (num_elts); \
  _tag_arr_ans; })
#endif

#ifdef _INLINE_FUNCTIONS
static _INLINE struct _dyneither_ptr *
_init_dyneither_ptr(struct _dyneither_ptr *arr_ptr,
                    void *arr, unsigned elt_sz, unsigned num_elts) {
  struct _dyneither_ptr *_itarr_ptr = (arr_ptr);
  void* _itarr = (arr);
  _itarr_ptr->base = _itarr_ptr->curr = _itarr;
  _itarr_ptr->last_plus_one = ((unsigned char *)_itarr) + (elt_sz) * (num_elts);
  return _itarr_ptr;
}
#else
#define _init_dyneither_ptr(arr_ptr,arr,elt_sz,num_elts) ({ \
  struct _dyneither_ptr *_itarr_ptr = (arr_ptr); \
  void* _itarr = (arr); \
  _itarr_ptr->base = _itarr_ptr->curr = _itarr; \
  _itarr_ptr->last_plus_one = ((char *)_itarr) + (elt_sz) * (num_elts); \
  _itarr_ptr; })
#endif

#ifdef NO_CYC_BOUNDS_CHECKS
#define _untag_dyneither_ptr(arr,elt_sz,num_elts) ((arr).curr)
#else
#ifdef _INLINE_FUNCTIONS
static _INLINE unsigned char *
_untag_dyneither_ptr(struct _dyneither_ptr arr, 
                     unsigned elt_sz,unsigned num_elts) {
  struct _dyneither_ptr _arr = (arr);
  unsigned char *_curr = _arr.curr;
  if (_curr < _arr.base || _curr + (elt_sz) * (num_elts) > _arr.last_plus_one)
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
#endif
#endif

#ifdef _INLINE_FUNCTIONS
static _INLINE unsigned
_get_dyneither_size(struct _dyneither_ptr arr,unsigned elt_sz) {
  struct _dyneither_ptr _get_arr_size_temp = (arr);
  unsigned char *_get_arr_size_curr=_get_arr_size_temp.curr;
  unsigned char *_get_arr_size_last=_get_arr_size_temp.last_plus_one;
  return (_get_arr_size_curr < _get_arr_size_temp.base ||
          _get_arr_size_curr >= _get_arr_size_last) ? 0 :
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
#endif

#ifdef _INLINE_FUNCTIONS
static _INLINE struct _dyneither_ptr
_dyneither_ptr_plus(struct _dyneither_ptr arr,unsigned elt_sz,int change) {
  struct _dyneither_ptr _ans = (arr);
  _ans.curr += ((int)(elt_sz))*(change);
  return _ans;
}
#else
#define _dyneither_ptr_plus(arr,elt_sz,change) ({ \
  struct _dyneither_ptr _ans = (arr); \
  _ans.curr += ((int)(elt_sz))*(change); \
  _ans; })
#endif

#ifdef _INLINE_FUNCTIONS
static _INLINE struct _dyneither_ptr
_dyneither_ptr_inplace_plus(struct _dyneither_ptr *arr_ptr,unsigned elt_sz,
                            int change) {
  struct _dyneither_ptr * _arr_ptr = (arr_ptr);
  _arr_ptr->curr += ((int)(elt_sz))*(change);
  return *_arr_ptr;
}
#else
#define _dyneither_ptr_inplace_plus(arr_ptr,elt_sz,change) ({ \
  struct _dyneither_ptr * _arr_ptr = (arr_ptr); \
  _arr_ptr->curr += ((int)(elt_sz))*(change); \
  *_arr_ptr; })
#endif

#ifdef _INLINE_FUNCTIONS
static _INLINE struct _dyneither_ptr
_dyneither_ptr_inplace_plus_post(struct _dyneither_ptr *arr_ptr,unsigned elt_sz,int change) {
  struct _dyneither_ptr * _arr_ptr = (arr_ptr);
  struct _dyneither_ptr _ans = *_arr_ptr;
  _arr_ptr->curr += ((int)(elt_sz))*(change);
  return _ans;
}
#else
#define _dyneither_ptr_inplace_plus_post(arr_ptr,elt_sz,change) ({ \
  struct _dyneither_ptr * _arr_ptr = (arr_ptr); \
  struct _dyneither_ptr _ans = *_arr_ptr; \
  _arr_ptr->curr += ((int)(elt_sz))*(change); \
  _ans; })
#endif

/* Decrease the upper bound on a fat pointer by numelts where sz is
   the size of the pointer's type.  Note that this can't be a macro
   if we're to get initializers right. */
static struct 
_dyneither_ptr _dyneither_ptr_decrease_size(struct _dyneither_ptr x,
                                            unsigned int sz,
                                            unsigned int numelts) {
  x.last_plus_one -= sz * numelts; 
  return x; 
}

/* Allocation */
extern void* GC_malloc(int);
extern void* GC_malloc_atomic(int);
extern void* GC_calloc(unsigned,unsigned);
extern void* GC_calloc_atomic(unsigned,unsigned);

static _INLINE void* _cycalloc(int n) {
  void * ans = (void *)GC_malloc(n);
  if(!ans)
    _throw_badalloc();
  return ans;
}
static _INLINE void* _cycalloc_atomic(int n) {
  void * ans = (void *)GC_malloc_atomic(n);
  if(!ans)
    _throw_badalloc();
  return ans;
}
static _INLINE void* _cyccalloc(unsigned n, unsigned s) {
  void* ans = (void*)GC_calloc(n,s);
  if (!ans)
    _throw_badalloc();
  return ans;
}
static _INLINE void* _cyccalloc_atomic(unsigned n, unsigned s) {
  void* ans = (void*)GC_calloc_atomic(n,s);
  if (!ans)
    _throw_badalloc();
  return ans;
}
#define MAX_MALLOC_SIZE (1 << 28)
static _INLINE unsigned int _check_times(unsigned x, unsigned y) {
  _CYC_U_LONG_LONG_T whole_ans = 
    ((_CYC_U_LONG_LONG_T)x)*((_CYC_U_LONG_LONG_T)y);
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

/* the next two routines swap [x] and [y]; not thread safe! */
static _INLINE void _swap_word(void *x, void *y) {
  unsigned long *lx = (unsigned long *)x, *ly = (unsigned long *)y, tmp;
  tmp = *lx;
  *lx = *ly;
  *ly = tmp;
}
static _INLINE void _swap_dyneither(struct _dyneither_ptr *x, 
				   struct _dyneither_ptr *y) {
  struct _dyneither_ptr tmp = *x;
  *x = *y;
  *y = tmp;
}
 struct Cyc_Core_NewRegion{struct _DynRegionHandle*dynregion;};struct Cyc___cycFILE;
extern struct Cyc___cycFILE*Cyc_stdout;struct Cyc_String_pa_struct{int tag;struct
_dyneither_ptr f1;};struct Cyc_Int_pa_struct{int tag;unsigned long f1;};struct Cyc_Double_pa_struct{
int tag;double f1;};struct Cyc_LongDouble_pa_struct{int tag;long double f1;};struct
Cyc_ShortPtr_pa_struct{int tag;short*f1;};struct Cyc_IntPtr_pa_struct{int tag;
unsigned long*f1;};struct _dyneither_ptr Cyc_aprintf(struct _dyneither_ptr,struct
_dyneither_ptr);int Cyc_fprintf(struct Cyc___cycFILE*,struct _dyneither_ptr,struct
_dyneither_ptr);int Cyc_fputc(int,struct Cyc___cycFILE*);struct Cyc_ShortPtr_sa_struct{
int tag;short*f1;};struct Cyc_UShortPtr_sa_struct{int tag;unsigned short*f1;};
struct Cyc_IntPtr_sa_struct{int tag;int*f1;};struct Cyc_UIntPtr_sa_struct{int tag;
unsigned int*f1;};struct Cyc_StringPtr_sa_struct{int tag;struct _dyneither_ptr f1;};
struct Cyc_DoublePtr_sa_struct{int tag;double*f1;};struct Cyc_FloatPtr_sa_struct{
int tag;float*f1;};struct Cyc_CharPtr_sa_struct{int tag;struct _dyneither_ptr f1;};
extern char Cyc_FileCloseError[15];struct Cyc_FileCloseError_struct{char*tag;};
extern char Cyc_FileOpenError[14];struct Cyc_FileOpenError_struct{char*tag;struct
_dyneither_ptr f1;};int Cyc_file_string_write(struct Cyc___cycFILE*,struct
_dyneither_ptr src,int src_offset,int max_count);struct Cyc_Core_Opt{void*v;};extern
char Cyc_Core_Invalid_argument[17];struct Cyc_Core_Invalid_argument_struct{char*
tag;struct _dyneither_ptr f1;};extern char Cyc_Core_Failure[8];struct Cyc_Core_Failure_struct{
char*tag;struct _dyneither_ptr f1;};extern char Cyc_Core_Impossible[11];struct Cyc_Core_Impossible_struct{
char*tag;struct _dyneither_ptr f1;};extern char Cyc_Core_Not_found[10];struct Cyc_Core_Not_found_struct{
char*tag;};extern char Cyc_Core_Unreachable[12];struct Cyc_Core_Unreachable_struct{
char*tag;struct _dyneither_ptr f1;};extern char Cyc_Core_Open_Region[12];struct Cyc_Core_Open_Region_struct{
char*tag;};extern char Cyc_Core_Free_Region[12];struct Cyc_Core_Free_Region_struct{
char*tag;};struct Cyc_List_List{void*hd;struct Cyc_List_List*tl;};int Cyc_List_length(
struct Cyc_List_List*x);struct Cyc_List_List*Cyc_List_map(void*(*f)(void*),struct
Cyc_List_List*x);extern char Cyc_List_List_mismatch[14];struct Cyc_List_List_mismatch_struct{
char*tag;};struct Cyc_List_List*Cyc_List_imp_rev(struct Cyc_List_List*x);struct Cyc_List_List*
Cyc_List_imp_append(struct Cyc_List_List*x,struct Cyc_List_List*y);extern char Cyc_List_Nth[
4];struct Cyc_List_Nth_struct{char*tag;};int Cyc_List_exists(int(*pred)(void*),
struct Cyc_List_List*x);unsigned long Cyc_strlen(struct _dyneither_ptr s);struct Cyc_Lineno_Pos{
struct _dyneither_ptr logical_file;struct _dyneither_ptr line;int line_no;int col;};
extern char Cyc_Position_Exit[5];struct Cyc_Position_Exit_struct{char*tag;};struct
Cyc_Position_Segment;struct Cyc_Position_Lex_struct{int tag;};struct Cyc_Position_Parse_struct{
int tag;};struct Cyc_Position_Elab_struct{int tag;};struct Cyc_Position_Error{struct
_dyneither_ptr source;struct Cyc_Position_Segment*seg;void*kind;struct
_dyneither_ptr desc;};extern char Cyc_Position_Nocontext[10];struct Cyc_Position_Nocontext_struct{
char*tag;};struct _dyneither_ptr Cyc_Position_get_line_directive(struct Cyc_Position_Segment*
loc);struct _union_Nmspace_Rel_n{int tag;struct Cyc_List_List*val;};struct
_union_Nmspace_Abs_n{int tag;struct Cyc_List_List*val;};struct _union_Nmspace_Loc_n{
int tag;int val;};union Cyc_Absyn_Nmspace{struct _union_Nmspace_Rel_n Rel_n;struct
_union_Nmspace_Abs_n Abs_n;struct _union_Nmspace_Loc_n Loc_n;};union Cyc_Absyn_Nmspace
Cyc_Absyn_Loc_n;union Cyc_Absyn_Nmspace Cyc_Absyn_Rel_n(struct Cyc_List_List*);
union Cyc_Absyn_Nmspace Cyc_Absyn_Abs_n(struct Cyc_List_List*);struct _tuple0{union
Cyc_Absyn_Nmspace f1;struct _dyneither_ptr*f2;};enum Cyc_Absyn_Scope{Cyc_Absyn_Static
 = 0,Cyc_Absyn_Abstract  = 1,Cyc_Absyn_Public  = 2,Cyc_Absyn_Extern  = 3,Cyc_Absyn_ExternC
 = 4,Cyc_Absyn_Register  = 5};struct Cyc_Absyn_Tqual{int print_const;int q_volatile;
int q_restrict;int real_const;struct Cyc_Position_Segment*loc;};enum Cyc_Absyn_Size_of{
Cyc_Absyn_Char_sz  = 0,Cyc_Absyn_Short_sz  = 1,Cyc_Absyn_Int_sz  = 2,Cyc_Absyn_Long_sz
 = 3,Cyc_Absyn_LongLong_sz  = 4};enum Cyc_Absyn_Kind{Cyc_Absyn_AnyKind  = 0,Cyc_Absyn_MemKind
 = 1,Cyc_Absyn_BoxKind  = 2,Cyc_Absyn_RgnKind  = 3,Cyc_Absyn_UniqueRgnKind  = 4,Cyc_Absyn_TopRgnKind
 = 5,Cyc_Absyn_EffKind  = 6,Cyc_Absyn_IntKind  = 7};enum Cyc_Absyn_Sign{Cyc_Absyn_Signed
 = 0,Cyc_Absyn_Unsigned  = 1,Cyc_Absyn_None  = 2};enum Cyc_Absyn_AggrKind{Cyc_Absyn_StructA
 = 0,Cyc_Absyn_UnionA  = 1};struct _union_Constraint_Eq_constr{int tag;void*val;};
struct _union_Constraint_Forward_constr{int tag;union Cyc_Absyn_Constraint*val;};
struct _union_Constraint_No_constr{int tag;int val;};union Cyc_Absyn_Constraint{
struct _union_Constraint_Eq_constr Eq_constr;struct
_union_Constraint_Forward_constr Forward_constr;struct _union_Constraint_No_constr
No_constr;};struct Cyc_Absyn_Eq_kb_struct{int tag;enum Cyc_Absyn_Kind f1;};struct
Cyc_Absyn_Unknown_kb_struct{int tag;struct Cyc_Core_Opt*f1;};struct Cyc_Absyn_Less_kb_struct{
int tag;struct Cyc_Core_Opt*f1;enum Cyc_Absyn_Kind f2;};struct Cyc_Absyn_Tvar{struct
_dyneither_ptr*name;int identity;void*kind;};struct Cyc_Absyn_DynEither_b_struct{
int tag;};struct Cyc_Absyn_Upper_b_struct{int tag;struct Cyc_Absyn_Exp*f1;};struct
Cyc_Absyn_PtrLoc{struct Cyc_Position_Segment*ptr_loc;struct Cyc_Position_Segment*
rgn_loc;struct Cyc_Position_Segment*zt_loc;};struct Cyc_Absyn_PtrAtts{void*rgn;
union Cyc_Absyn_Constraint*nullable;union Cyc_Absyn_Constraint*bounds;union Cyc_Absyn_Constraint*
zero_term;struct Cyc_Absyn_PtrLoc*ptrloc;};struct Cyc_Absyn_PtrInfo{void*elt_typ;
struct Cyc_Absyn_Tqual elt_tq;struct Cyc_Absyn_PtrAtts ptr_atts;};struct Cyc_Absyn_Numelts_ptrqual_struct{
int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Region_ptrqual_struct{int tag;
void*f1;};struct Cyc_Absyn_Thin_ptrqual_struct{int tag;};struct Cyc_Absyn_Fat_ptrqual_struct{
int tag;};struct Cyc_Absyn_Zeroterm_ptrqual_struct{int tag;};struct Cyc_Absyn_Nozeroterm_ptrqual_struct{
int tag;};struct Cyc_Absyn_Notnull_ptrqual_struct{int tag;};struct Cyc_Absyn_Nullable_ptrqual_struct{
int tag;};struct Cyc_Absyn_VarargInfo{struct Cyc_Core_Opt*name;struct Cyc_Absyn_Tqual
tq;void*type;int inject;};struct Cyc_Absyn_FnInfo{struct Cyc_List_List*tvars;struct
Cyc_Core_Opt*effect;void*ret_typ;struct Cyc_List_List*args;int c_varargs;struct Cyc_Absyn_VarargInfo*
cyc_varargs;struct Cyc_List_List*rgn_po;struct Cyc_List_List*attributes;};struct
Cyc_Absyn_UnknownDatatypeInfo{struct _tuple0*name;int is_extensible;};struct
_union_DatatypeInfoU_UnknownDatatype{int tag;struct Cyc_Absyn_UnknownDatatypeInfo
val;};struct _union_DatatypeInfoU_KnownDatatype{int tag;struct Cyc_Absyn_Datatypedecl**
val;};union Cyc_Absyn_DatatypeInfoU{struct _union_DatatypeInfoU_UnknownDatatype
UnknownDatatype;struct _union_DatatypeInfoU_KnownDatatype KnownDatatype;};struct
Cyc_Absyn_DatatypeInfo{union Cyc_Absyn_DatatypeInfoU datatype_info;struct Cyc_List_List*
targs;};struct Cyc_Absyn_UnknownDatatypeFieldInfo{struct _tuple0*datatype_name;
struct _tuple0*field_name;int is_extensible;};struct
_union_DatatypeFieldInfoU_UnknownDatatypefield{int tag;struct Cyc_Absyn_UnknownDatatypeFieldInfo
val;};struct _tuple1{struct Cyc_Absyn_Datatypedecl*f1;struct Cyc_Absyn_Datatypefield*
f2;};struct _union_DatatypeFieldInfoU_KnownDatatypefield{int tag;struct _tuple1 val;
};union Cyc_Absyn_DatatypeFieldInfoU{struct
_union_DatatypeFieldInfoU_UnknownDatatypefield UnknownDatatypefield;struct
_union_DatatypeFieldInfoU_KnownDatatypefield KnownDatatypefield;};struct Cyc_Absyn_DatatypeFieldInfo{
union Cyc_Absyn_DatatypeFieldInfoU field_info;struct Cyc_List_List*targs;};struct
_tuple2{enum Cyc_Absyn_AggrKind f1;struct _tuple0*f2;struct Cyc_Core_Opt*f3;};
struct _union_AggrInfoU_UnknownAggr{int tag;struct _tuple2 val;};struct
_union_AggrInfoU_KnownAggr{int tag;struct Cyc_Absyn_Aggrdecl**val;};union Cyc_Absyn_AggrInfoU{
struct _union_AggrInfoU_UnknownAggr UnknownAggr;struct _union_AggrInfoU_KnownAggr
KnownAggr;};struct Cyc_Absyn_AggrInfo{union Cyc_Absyn_AggrInfoU aggr_info;struct Cyc_List_List*
targs;};struct Cyc_Absyn_ArrayInfo{void*elt_type;struct Cyc_Absyn_Tqual tq;struct
Cyc_Absyn_Exp*num_elts;union Cyc_Absyn_Constraint*zero_term;struct Cyc_Position_Segment*
zt_loc;};struct Cyc_Absyn_VoidType_struct{int tag;};struct Cyc_Absyn_Evar_struct{
int tag;struct Cyc_Core_Opt*f1;struct Cyc_Core_Opt*f2;int f3;struct Cyc_Core_Opt*f4;}
;struct Cyc_Absyn_VarType_struct{int tag;struct Cyc_Absyn_Tvar*f1;};struct Cyc_Absyn_DatatypeType_struct{
int tag;struct Cyc_Absyn_DatatypeInfo f1;};struct Cyc_Absyn_DatatypeFieldType_struct{
int tag;struct Cyc_Absyn_DatatypeFieldInfo f1;};struct Cyc_Absyn_PointerType_struct{
int tag;struct Cyc_Absyn_PtrInfo f1;};struct Cyc_Absyn_IntType_struct{int tag;enum 
Cyc_Absyn_Sign f1;enum Cyc_Absyn_Size_of f2;};struct Cyc_Absyn_FloatType_struct{int
tag;};struct Cyc_Absyn_DoubleType_struct{int tag;int f1;};struct Cyc_Absyn_ArrayType_struct{
int tag;struct Cyc_Absyn_ArrayInfo f1;};struct Cyc_Absyn_FnType_struct{int tag;struct
Cyc_Absyn_FnInfo f1;};struct Cyc_Absyn_TupleType_struct{int tag;struct Cyc_List_List*
f1;};struct Cyc_Absyn_AggrType_struct{int tag;struct Cyc_Absyn_AggrInfo f1;};struct
Cyc_Absyn_AnonAggrType_struct{int tag;enum Cyc_Absyn_AggrKind f1;struct Cyc_List_List*
f2;};struct Cyc_Absyn_EnumType_struct{int tag;struct _tuple0*f1;struct Cyc_Absyn_Enumdecl*
f2;};struct Cyc_Absyn_AnonEnumType_struct{int tag;struct Cyc_List_List*f1;};struct
Cyc_Absyn_RgnHandleType_struct{int tag;void*f1;};struct Cyc_Absyn_DynRgnType_struct{
int tag;void*f1;void*f2;};struct Cyc_Absyn_TypedefType_struct{int tag;struct _tuple0*
f1;struct Cyc_List_List*f2;struct Cyc_Absyn_Typedefdecl*f3;void**f4;};struct Cyc_Absyn_ValueofType_struct{
int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_TagType_struct{int tag;void*f1;};
struct Cyc_Absyn_HeapRgn_struct{int tag;};struct Cyc_Absyn_UniqueRgn_struct{int tag;
};struct Cyc_Absyn_AccessEff_struct{int tag;void*f1;};struct Cyc_Absyn_JoinEff_struct{
int tag;struct Cyc_List_List*f1;};struct Cyc_Absyn_RgnsEff_struct{int tag;void*f1;};
struct Cyc_Absyn_NoTypes_struct{int tag;struct Cyc_List_List*f1;struct Cyc_Position_Segment*
f2;};struct Cyc_Absyn_WithTypes_struct{int tag;struct Cyc_List_List*f1;int f2;struct
Cyc_Absyn_VarargInfo*f3;struct Cyc_Core_Opt*f4;struct Cyc_List_List*f5;};enum Cyc_Absyn_Format_Type{
Cyc_Absyn_Printf_ft  = 0,Cyc_Absyn_Scanf_ft  = 1};struct Cyc_Absyn_Regparm_att_struct{
int tag;int f1;};struct Cyc_Absyn_Stdcall_att_struct{int tag;};struct Cyc_Absyn_Cdecl_att_struct{
int tag;};struct Cyc_Absyn_Fastcall_att_struct{int tag;};struct Cyc_Absyn_Noreturn_att_struct{
int tag;};struct Cyc_Absyn_Const_att_struct{int tag;};struct Cyc_Absyn_Aligned_att_struct{
int tag;int f1;};struct Cyc_Absyn_Packed_att_struct{int tag;};struct Cyc_Absyn_Section_att_struct{
int tag;struct _dyneither_ptr f1;};struct Cyc_Absyn_Nocommon_att_struct{int tag;};
struct Cyc_Absyn_Shared_att_struct{int tag;};struct Cyc_Absyn_Unused_att_struct{int
tag;};struct Cyc_Absyn_Weak_att_struct{int tag;};struct Cyc_Absyn_Dllimport_att_struct{
int tag;};struct Cyc_Absyn_Dllexport_att_struct{int tag;};struct Cyc_Absyn_No_instrument_function_att_struct{
int tag;};struct Cyc_Absyn_Constructor_att_struct{int tag;};struct Cyc_Absyn_Destructor_att_struct{
int tag;};struct Cyc_Absyn_No_check_memory_usage_att_struct{int tag;};struct Cyc_Absyn_Format_att_struct{
int tag;enum Cyc_Absyn_Format_Type f1;int f2;int f3;};struct Cyc_Absyn_Initializes_att_struct{
int tag;int f1;};struct Cyc_Absyn_Pure_att_struct{int tag;};struct Cyc_Absyn_Mode_att_struct{
int tag;struct _dyneither_ptr f1;};extern struct Cyc_Absyn_Stdcall_att_struct Cyc_Absyn_Stdcall_att_val;
extern struct Cyc_Absyn_Cdecl_att_struct Cyc_Absyn_Cdecl_att_val;extern struct Cyc_Absyn_Fastcall_att_struct
Cyc_Absyn_Fastcall_att_val;extern struct Cyc_Absyn_Unused_att_struct Cyc_Absyn_Unused_att_val;
struct Cyc_Absyn_Carray_mod_struct{int tag;union Cyc_Absyn_Constraint*f1;struct Cyc_Position_Segment*
f2;};struct Cyc_Absyn_ConstArray_mod_struct{int tag;struct Cyc_Absyn_Exp*f1;union
Cyc_Absyn_Constraint*f2;struct Cyc_Position_Segment*f3;};struct Cyc_Absyn_Pointer_mod_struct{
int tag;struct Cyc_Absyn_PtrAtts f1;struct Cyc_Absyn_Tqual f2;};struct Cyc_Absyn_Function_mod_struct{
int tag;void*f1;};struct Cyc_Absyn_TypeParams_mod_struct{int tag;struct Cyc_List_List*
f1;struct Cyc_Position_Segment*f2;int f3;};struct Cyc_Absyn_Attributes_mod_struct{
int tag;struct Cyc_Position_Segment*f1;struct Cyc_List_List*f2;};struct
_union_Cnst_Null_c{int tag;int val;};struct _tuple3{enum Cyc_Absyn_Sign f1;char f2;};
struct _union_Cnst_Char_c{int tag;struct _tuple3 val;};struct _tuple4{enum Cyc_Absyn_Sign
f1;short f2;};struct _union_Cnst_Short_c{int tag;struct _tuple4 val;};struct _tuple5{
enum Cyc_Absyn_Sign f1;int f2;};struct _union_Cnst_Int_c{int tag;struct _tuple5 val;};
struct _tuple6{enum Cyc_Absyn_Sign f1;long long f2;};struct _union_Cnst_LongLong_c{
int tag;struct _tuple6 val;};struct _union_Cnst_Float_c{int tag;struct _dyneither_ptr
val;};struct _union_Cnst_String_c{int tag;struct _dyneither_ptr val;};union Cyc_Absyn_Cnst{
struct _union_Cnst_Null_c Null_c;struct _union_Cnst_Char_c Char_c;struct
_union_Cnst_Short_c Short_c;struct _union_Cnst_Int_c Int_c;struct
_union_Cnst_LongLong_c LongLong_c;struct _union_Cnst_Float_c Float_c;struct
_union_Cnst_String_c String_c;};enum Cyc_Absyn_Primop{Cyc_Absyn_Plus  = 0,Cyc_Absyn_Times
 = 1,Cyc_Absyn_Minus  = 2,Cyc_Absyn_Div  = 3,Cyc_Absyn_Mod  = 4,Cyc_Absyn_Eq  = 5,
Cyc_Absyn_Neq  = 6,Cyc_Absyn_Gt  = 7,Cyc_Absyn_Lt  = 8,Cyc_Absyn_Gte  = 9,Cyc_Absyn_Lte
 = 10,Cyc_Absyn_Not  = 11,Cyc_Absyn_Bitnot  = 12,Cyc_Absyn_Bitand  = 13,Cyc_Absyn_Bitor
 = 14,Cyc_Absyn_Bitxor  = 15,Cyc_Absyn_Bitlshift  = 16,Cyc_Absyn_Bitlrshift  = 17,
Cyc_Absyn_Bitarshift  = 18,Cyc_Absyn_Numelts  = 19};enum Cyc_Absyn_Incrementor{Cyc_Absyn_PreInc
 = 0,Cyc_Absyn_PostInc  = 1,Cyc_Absyn_PreDec  = 2,Cyc_Absyn_PostDec  = 3};struct Cyc_Absyn_VarargCallInfo{
int num_varargs;struct Cyc_List_List*injectors;struct Cyc_Absyn_VarargInfo*vai;};
struct Cyc_Absyn_StructField_struct{int tag;struct _dyneither_ptr*f1;};struct Cyc_Absyn_TupleIndex_struct{
int tag;unsigned int f1;};enum Cyc_Absyn_Coercion{Cyc_Absyn_Unknown_coercion  = 0,
Cyc_Absyn_No_coercion  = 1,Cyc_Absyn_NonNull_to_Null  = 2,Cyc_Absyn_Other_coercion
 = 3};struct Cyc_Absyn_MallocInfo{int is_calloc;struct Cyc_Absyn_Exp*rgn;void**
elt_type;struct Cyc_Absyn_Exp*num_elts;int fat_result;};struct Cyc_Absyn_Const_e_struct{
int tag;union Cyc_Absyn_Cnst f1;};struct Cyc_Absyn_Var_e_struct{int tag;struct _tuple0*
f1;void*f2;};struct Cyc_Absyn_UnknownId_e_struct{int tag;struct _tuple0*f1;};struct
Cyc_Absyn_Primop_e_struct{int tag;enum Cyc_Absyn_Primop f1;struct Cyc_List_List*f2;
};struct Cyc_Absyn_AssignOp_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Core_Opt*
f2;struct Cyc_Absyn_Exp*f3;};struct Cyc_Absyn_Increment_e_struct{int tag;struct Cyc_Absyn_Exp*
f1;enum Cyc_Absyn_Incrementor f2;};struct Cyc_Absyn_Conditional_e_struct{int tag;
struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;struct Cyc_Absyn_Exp*f3;};struct Cyc_Absyn_And_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_Or_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_SeqExp_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_UnknownCall_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_FnCall_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_List_List*f2;struct Cyc_Absyn_VarargCallInfo*
f3;};struct Cyc_Absyn_Throw_e_struct{int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_NoInstantiate_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Instantiate_e_struct{int tag;
struct Cyc_Absyn_Exp*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_Cast_e_struct{
int tag;void*f1;struct Cyc_Absyn_Exp*f2;int f3;enum Cyc_Absyn_Coercion f4;};struct
Cyc_Absyn_Address_e_struct{int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_New_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_Sizeoftyp_e_struct{
int tag;void*f1;};struct Cyc_Absyn_Sizeofexp_e_struct{int tag;struct Cyc_Absyn_Exp*
f1;};struct Cyc_Absyn_Offsetof_e_struct{int tag;void*f1;void*f2;};struct Cyc_Absyn_Deref_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_AggrMember_e_struct{int tag;
struct Cyc_Absyn_Exp*f1;struct _dyneither_ptr*f2;int f3;int f4;};struct Cyc_Absyn_AggrArrow_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct _dyneither_ptr*f2;int f3;int f4;};struct Cyc_Absyn_Subscript_e_struct{
int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_Tuple_e_struct{
int tag;struct Cyc_List_List*f1;};struct _tuple7{struct Cyc_Core_Opt*f1;struct Cyc_Absyn_Tqual
f2;void*f3;};struct Cyc_Absyn_CompoundLit_e_struct{int tag;struct _tuple7*f1;struct
Cyc_List_List*f2;};struct Cyc_Absyn_Array_e_struct{int tag;struct Cyc_List_List*f1;
};struct Cyc_Absyn_Comprehension_e_struct{int tag;struct Cyc_Absyn_Vardecl*f1;
struct Cyc_Absyn_Exp*f2;struct Cyc_Absyn_Exp*f3;int f4;};struct Cyc_Absyn_Aggregate_e_struct{
int tag;struct _tuple0*f1;struct Cyc_List_List*f2;struct Cyc_List_List*f3;struct Cyc_Absyn_Aggrdecl*
f4;};struct Cyc_Absyn_AnonStruct_e_struct{int tag;void*f1;struct Cyc_List_List*f2;}
;struct Cyc_Absyn_Datatype_e_struct{int tag;struct Cyc_List_List*f1;struct Cyc_Absyn_Datatypedecl*
f2;struct Cyc_Absyn_Datatypefield*f3;};struct Cyc_Absyn_Enum_e_struct{int tag;
struct _tuple0*f1;struct Cyc_Absyn_Enumdecl*f2;struct Cyc_Absyn_Enumfield*f3;};
struct Cyc_Absyn_AnonEnum_e_struct{int tag;struct _tuple0*f1;void*f2;struct Cyc_Absyn_Enumfield*
f3;};struct Cyc_Absyn_Malloc_e_struct{int tag;struct Cyc_Absyn_MallocInfo f1;};
struct Cyc_Absyn_Swap_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*
f2;};struct Cyc_Absyn_UnresolvedMem_e_struct{int tag;struct Cyc_Core_Opt*f1;struct
Cyc_List_List*f2;};struct Cyc_Absyn_StmtExp_e_struct{int tag;struct Cyc_Absyn_Stmt*
f1;};struct Cyc_Absyn_Tagcheck_e_struct{int tag;struct Cyc_Absyn_Exp*f1;struct
_dyneither_ptr*f2;};struct Cyc_Absyn_Valueof_e_struct{int tag;void*f1;};struct Cyc_Absyn_Exp{
struct Cyc_Core_Opt*topt;void*r;struct Cyc_Position_Segment*loc;void*annot;};
struct Cyc_Absyn_Skip_s_struct{int tag;};struct Cyc_Absyn_Exp_s_struct{int tag;
struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_Seq_s_struct{int tag;struct Cyc_Absyn_Stmt*
f1;struct Cyc_Absyn_Stmt*f2;};struct Cyc_Absyn_Return_s_struct{int tag;struct Cyc_Absyn_Exp*
f1;};struct Cyc_Absyn_IfThenElse_s_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Stmt*
f2;struct Cyc_Absyn_Stmt*f3;};struct _tuple8{struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_While_s_struct{int tag;struct _tuple8 f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_Break_s_struct{int tag;struct Cyc_Absyn_Stmt*f1;};struct Cyc_Absyn_Continue_s_struct{
int tag;struct Cyc_Absyn_Stmt*f1;};struct Cyc_Absyn_Goto_s_struct{int tag;struct
_dyneither_ptr*f1;struct Cyc_Absyn_Stmt*f2;};struct Cyc_Absyn_For_s_struct{int tag;
struct Cyc_Absyn_Exp*f1;struct _tuple8 f2;struct _tuple8 f3;struct Cyc_Absyn_Stmt*f4;}
;struct Cyc_Absyn_Switch_s_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_List_List*
f2;};struct Cyc_Absyn_Fallthru_s_struct{int tag;struct Cyc_List_List*f1;struct Cyc_Absyn_Switch_clause**
f2;};struct Cyc_Absyn_Decl_s_struct{int tag;struct Cyc_Absyn_Decl*f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_Label_s_struct{int tag;struct _dyneither_ptr*f1;struct Cyc_Absyn_Stmt*
f2;};struct Cyc_Absyn_Do_s_struct{int tag;struct Cyc_Absyn_Stmt*f1;struct _tuple8 f2;
};struct Cyc_Absyn_TryCatch_s_struct{int tag;struct Cyc_Absyn_Stmt*f1;struct Cyc_List_List*
f2;};struct Cyc_Absyn_ResetRegion_s_struct{int tag;struct Cyc_Absyn_Exp*f1;};struct
Cyc_Absyn_Stmt{void*r;struct Cyc_Position_Segment*loc;struct Cyc_List_List*
non_local_preds;int try_depth;void*annot;};struct Cyc_Absyn_Wild_p_struct{int tag;}
;struct Cyc_Absyn_Var_p_struct{int tag;struct Cyc_Absyn_Vardecl*f1;struct Cyc_Absyn_Pat*
f2;};struct Cyc_Absyn_Reference_p_struct{int tag;struct Cyc_Absyn_Vardecl*f1;struct
Cyc_Absyn_Pat*f2;};struct Cyc_Absyn_TagInt_p_struct{int tag;struct Cyc_Absyn_Tvar*
f1;struct Cyc_Absyn_Vardecl*f2;};struct Cyc_Absyn_Tuple_p_struct{int tag;struct Cyc_List_List*
f1;int f2;};struct Cyc_Absyn_Pointer_p_struct{int tag;struct Cyc_Absyn_Pat*f1;};
struct Cyc_Absyn_Aggr_p_struct{int tag;struct Cyc_Absyn_AggrInfo*f1;struct Cyc_List_List*
f2;struct Cyc_List_List*f3;int f4;};struct Cyc_Absyn_Datatype_p_struct{int tag;
struct Cyc_Absyn_Datatypedecl*f1;struct Cyc_Absyn_Datatypefield*f2;struct Cyc_List_List*
f3;int f4;};struct Cyc_Absyn_Null_p_struct{int tag;};struct Cyc_Absyn_Int_p_struct{
int tag;enum Cyc_Absyn_Sign f1;int f2;};struct Cyc_Absyn_Char_p_struct{int tag;char f1;
};struct Cyc_Absyn_Float_p_struct{int tag;struct _dyneither_ptr f1;};struct Cyc_Absyn_Enum_p_struct{
int tag;struct Cyc_Absyn_Enumdecl*f1;struct Cyc_Absyn_Enumfield*f2;};struct Cyc_Absyn_AnonEnum_p_struct{
int tag;void*f1;struct Cyc_Absyn_Enumfield*f2;};struct Cyc_Absyn_UnknownId_p_struct{
int tag;struct _tuple0*f1;};struct Cyc_Absyn_UnknownCall_p_struct{int tag;struct
_tuple0*f1;struct Cyc_List_List*f2;int f3;};struct Cyc_Absyn_Exp_p_struct{int tag;
struct Cyc_Absyn_Exp*f1;};extern struct Cyc_Absyn_Wild_p_struct Cyc_Absyn_Wild_p_val;
struct Cyc_Absyn_Pat{void*r;struct Cyc_Core_Opt*topt;struct Cyc_Position_Segment*
loc;};struct Cyc_Absyn_Switch_clause{struct Cyc_Absyn_Pat*pattern;struct Cyc_Core_Opt*
pat_vars;struct Cyc_Absyn_Exp*where_clause;struct Cyc_Absyn_Stmt*body;struct Cyc_Position_Segment*
loc;};struct Cyc_Absyn_Unresolved_b_struct{int tag;};struct Cyc_Absyn_Global_b_struct{
int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Funname_b_struct{int tag;
struct Cyc_Absyn_Fndecl*f1;};struct Cyc_Absyn_Param_b_struct{int tag;struct Cyc_Absyn_Vardecl*
f1;};struct Cyc_Absyn_Local_b_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct
Cyc_Absyn_Pat_b_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Vardecl{
enum Cyc_Absyn_Scope sc;struct _tuple0*name;struct Cyc_Absyn_Tqual tq;void*type;
struct Cyc_Absyn_Exp*initializer;struct Cyc_Core_Opt*rgn;struct Cyc_List_List*
attributes;int escapes;};struct Cyc_Absyn_Fndecl{enum Cyc_Absyn_Scope sc;int
is_inline;struct _tuple0*name;struct Cyc_List_List*tvs;struct Cyc_Core_Opt*effect;
void*ret_type;struct Cyc_List_List*args;int c_varargs;struct Cyc_Absyn_VarargInfo*
cyc_varargs;struct Cyc_List_List*rgn_po;struct Cyc_Absyn_Stmt*body;struct Cyc_Core_Opt*
cached_typ;struct Cyc_Core_Opt*param_vardecls;struct Cyc_Absyn_Vardecl*fn_vardecl;
struct Cyc_List_List*attributes;};struct Cyc_Absyn_Aggrfield{struct _dyneither_ptr*
name;struct Cyc_Absyn_Tqual tq;void*type;struct Cyc_Absyn_Exp*width;struct Cyc_List_List*
attributes;};struct Cyc_Absyn_AggrdeclImpl{struct Cyc_List_List*exist_vars;struct
Cyc_List_List*rgn_po;struct Cyc_List_List*fields;int tagged;};struct Cyc_Absyn_Aggrdecl{
enum Cyc_Absyn_AggrKind kind;enum Cyc_Absyn_Scope sc;struct _tuple0*name;struct Cyc_List_List*
tvs;struct Cyc_Absyn_AggrdeclImpl*impl;struct Cyc_List_List*attributes;};struct Cyc_Absyn_Datatypefield{
struct _tuple0*name;struct Cyc_List_List*typs;struct Cyc_Position_Segment*loc;enum 
Cyc_Absyn_Scope sc;};struct Cyc_Absyn_Datatypedecl{enum Cyc_Absyn_Scope sc;struct
_tuple0*name;struct Cyc_List_List*tvs;struct Cyc_Core_Opt*fields;int is_extensible;
};struct Cyc_Absyn_Enumfield{struct _tuple0*name;struct Cyc_Absyn_Exp*tag;struct Cyc_Position_Segment*
loc;};struct Cyc_Absyn_Enumdecl{enum Cyc_Absyn_Scope sc;struct _tuple0*name;struct
Cyc_Core_Opt*fields;};struct Cyc_Absyn_Typedefdecl{struct _tuple0*name;struct Cyc_Absyn_Tqual
tq;struct Cyc_List_List*tvs;struct Cyc_Core_Opt*kind;struct Cyc_Core_Opt*defn;
struct Cyc_List_List*atts;};struct Cyc_Absyn_Var_d_struct{int tag;struct Cyc_Absyn_Vardecl*
f1;};struct Cyc_Absyn_Fn_d_struct{int tag;struct Cyc_Absyn_Fndecl*f1;};struct Cyc_Absyn_Let_d_struct{
int tag;struct Cyc_Absyn_Pat*f1;struct Cyc_Core_Opt*f2;struct Cyc_Absyn_Exp*f3;};
struct Cyc_Absyn_Letv_d_struct{int tag;struct Cyc_List_List*f1;};struct Cyc_Absyn_Region_d_struct{
int tag;struct Cyc_Absyn_Tvar*f1;struct Cyc_Absyn_Vardecl*f2;int f3;struct Cyc_Absyn_Exp*
f4;};struct Cyc_Absyn_Alias_d_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Tvar*
f2;struct Cyc_Absyn_Vardecl*f3;};struct Cyc_Absyn_Aggr_d_struct{int tag;struct Cyc_Absyn_Aggrdecl*
f1;};struct Cyc_Absyn_Datatype_d_struct{int tag;struct Cyc_Absyn_Datatypedecl*f1;};
struct Cyc_Absyn_Enum_d_struct{int tag;struct Cyc_Absyn_Enumdecl*f1;};struct Cyc_Absyn_Typedef_d_struct{
int tag;struct Cyc_Absyn_Typedefdecl*f1;};struct Cyc_Absyn_Namespace_d_struct{int
tag;struct _dyneither_ptr*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_Using_d_struct{
int tag;struct _tuple0*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_ExternC_d_struct{
int tag;struct Cyc_List_List*f1;};struct Cyc_Absyn_ExternCinclude_d_struct{int tag;
struct Cyc_List_List*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_Porton_d_struct{
int tag;};struct Cyc_Absyn_Portoff_d_struct{int tag;};struct Cyc_Absyn_Decl{void*r;
struct Cyc_Position_Segment*loc;};struct Cyc_Absyn_ArrayElement_struct{int tag;
struct Cyc_Absyn_Exp*f1;};struct Cyc_Absyn_FieldName_struct{int tag;struct
_dyneither_ptr*f1;};extern char Cyc_Absyn_EmptyAnnot[11];struct Cyc_Absyn_EmptyAnnot_struct{
char*tag;};struct Cyc_Absyn_Tqual Cyc_Absyn_empty_tqual(struct Cyc_Position_Segment*);
void*Cyc_Absyn_conref_def(void*y,union Cyc_Absyn_Constraint*x);void*Cyc_Absyn_compress_kb(
void*);void*Cyc_Absyn_new_evar(struct Cyc_Core_Opt*k,struct Cyc_Core_Opt*tenv);
extern void*Cyc_Absyn_bounds_one;struct Cyc_Absyn_Exp*Cyc_Absyn_times_exp(struct
Cyc_Absyn_Exp*,struct Cyc_Absyn_Exp*,struct Cyc_Position_Segment*);struct Cyc_Absyn_Exp*
Cyc_Absyn_sizeoftyp_exp(void*t,struct Cyc_Position_Segment*);struct _dyneither_ptr
Cyc_Absyn_attribute2string(void*);struct _tuple9{enum Cyc_Absyn_AggrKind f1;struct
_tuple0*f2;};struct _tuple9 Cyc_Absyn_aggr_kinded_name(union Cyc_Absyn_AggrInfoU);
struct Cyc_PP_Ppstate;struct Cyc_PP_Out;struct Cyc_PP_Doc;struct Cyc_Absynpp_Params{
int expand_typedefs: 1;int qvar_to_Cids: 1;int add_cyc_prefix: 1;int to_VC: 1;int
decls_first: 1;int rewrite_temp_tvars: 1;int print_all_tvars: 1;int print_all_kinds: 1;
int print_all_effects: 1;int print_using_stmts: 1;int print_externC_stmts: 1;int
print_full_evars: 1;int print_zeroterm: 1;int generate_line_directives: 1;int
use_curr_namespace: 1;struct Cyc_List_List*curr_namespace;};void Cyc_Absynpp_set_params(
struct Cyc_Absynpp_Params*fs);int Cyc_Absynpp_is_anon_aggrtype(void*t);extern
struct _dyneither_ptr*Cyc_Absynpp_cyc_stringptr;int Cyc_Absynpp_exp_prec(struct Cyc_Absyn_Exp*);
struct _dyneither_ptr Cyc_Absynpp_char_escape(char);struct _dyneither_ptr Cyc_Absynpp_string_escape(
struct _dyneither_ptr);struct _dyneither_ptr Cyc_Absynpp_prim2str(enum Cyc_Absyn_Primop
p);int Cyc_Absynpp_is_declaration(struct Cyc_Absyn_Stmt*s);struct _tuple10{struct
_dyneither_ptr*f1;struct Cyc_Absyn_Tqual f2;void*f3;};struct _tuple7*Cyc_Absynpp_arg_mk_opt(
struct _tuple10*arg);struct _tuple11{struct Cyc_Absyn_Tqual f1;void*f2;struct Cyc_List_List*
f3;};struct _tuple11 Cyc_Absynpp_to_tms(struct _RegionHandle*,struct Cyc_Absyn_Tqual
tq,void*t);struct _tuple12{unsigned int f1;int f2;};struct _tuple12 Cyc_Evexp_eval_const_uint_exp(
struct Cyc_Absyn_Exp*e);struct Cyc_Iter_Iter{void*env;int(*next)(void*env,void*
dest);};int Cyc_Iter_next(struct Cyc_Iter_Iter,void*);struct Cyc_Set_Set;extern char
Cyc_Set_Absent[7];struct Cyc_Set_Absent_struct{char*tag;};struct Cyc_Dict_T;struct
Cyc_Dict_Dict{int(*rel)(void*,void*);struct _RegionHandle*r;struct Cyc_Dict_T*t;};
extern char Cyc_Dict_Present[8];struct Cyc_Dict_Present_struct{char*tag;};extern
char Cyc_Dict_Absent[7];struct Cyc_Dict_Absent_struct{char*tag;};struct Cyc_RgnOrder_RgnPO;
struct Cyc_RgnOrder_RgnPO*Cyc_RgnOrder_initial_fn_po(struct _RegionHandle*,struct
Cyc_List_List*tvs,struct Cyc_List_List*po,void*effect,struct Cyc_Absyn_Tvar*
fst_rgn,struct Cyc_Position_Segment*);struct Cyc_RgnOrder_RgnPO*Cyc_RgnOrder_add_outlives_constraint(
struct _RegionHandle*,struct Cyc_RgnOrder_RgnPO*po,void*eff,void*rgn,struct Cyc_Position_Segment*
loc);struct Cyc_RgnOrder_RgnPO*Cyc_RgnOrder_add_youngest(struct _RegionHandle*,
struct Cyc_RgnOrder_RgnPO*po,struct Cyc_Absyn_Tvar*rgn,int resetable,int opened);int
Cyc_RgnOrder_is_region_resetable(struct Cyc_RgnOrder_RgnPO*po,struct Cyc_Absyn_Tvar*
r);int Cyc_RgnOrder_effect_outlives(struct Cyc_RgnOrder_RgnPO*po,void*eff,void*rgn);
int Cyc_RgnOrder_satisfies_constraints(struct Cyc_RgnOrder_RgnPO*po,struct Cyc_List_List*
constraints,void*default_bound,int do_pin);int Cyc_RgnOrder_eff_outlives_eff(
struct Cyc_RgnOrder_RgnPO*po,void*eff1,void*eff2);void Cyc_RgnOrder_print_region_po(
struct Cyc_RgnOrder_RgnPO*po);struct Cyc_Tcenv_CList{void*hd;struct Cyc_Tcenv_CList*
tl;};struct Cyc_Tcenv_VarRes_struct{int tag;void*f1;};struct Cyc_Tcenv_AggrRes_struct{
int tag;struct Cyc_Absyn_Aggrdecl*f1;};struct Cyc_Tcenv_DatatypeRes_struct{int tag;
struct Cyc_Absyn_Datatypedecl*f1;struct Cyc_Absyn_Datatypefield*f2;};struct Cyc_Tcenv_EnumRes_struct{
int tag;struct Cyc_Absyn_Enumdecl*f1;struct Cyc_Absyn_Enumfield*f2;};struct Cyc_Tcenv_AnonEnumRes_struct{
int tag;void*f1;struct Cyc_Absyn_Enumfield*f2;};struct Cyc_Tcenv_Genv{struct
_RegionHandle*grgn;struct Cyc_Set_Set*namespaces;struct Cyc_Dict_Dict aggrdecls;
struct Cyc_Dict_Dict datatypedecls;struct Cyc_Dict_Dict enumdecls;struct Cyc_Dict_Dict
typedefs;struct Cyc_Dict_Dict ordinaries;struct Cyc_List_List*availables;};struct
Cyc_Tcenv_Fenv;struct Cyc_Tcenv_NotLoop_j_struct{int tag;};struct Cyc_Tcenv_CaseEnd_j_struct{
int tag;};struct Cyc_Tcenv_FnEnd_j_struct{int tag;};struct Cyc_Tcenv_Stmt_j_struct{
int tag;struct Cyc_Absyn_Stmt*f1;};struct Cyc_Tcenv_Tenv{struct Cyc_List_List*ns;
struct Cyc_Dict_Dict ae;struct Cyc_Tcenv_Fenv*le;int allow_valueof;};void*Cyc_Tcutil_impos(
struct _dyneither_ptr fmt,struct _dyneither_ptr ap);void*Cyc_Tcutil_compress(void*t);
enum Cyc_Cyclone_C_Compilers{Cyc_Cyclone_Gcc_c  = 0,Cyc_Cyclone_Vc_c  = 1};extern
enum Cyc_Cyclone_C_Compilers Cyc_Cyclone_c_compiler;static int Cyc_Absyndump_expand_typedefs;
static int Cyc_Absyndump_qvar_to_Cids;static int Cyc_Absyndump_add_cyc_prefix;static
int Cyc_Absyndump_generate_line_directives;static int Cyc_Absyndump_to_VC;void Cyc_Absyndump_set_params(
struct Cyc_Absynpp_Params*fs);void Cyc_Absyndump_set_params(struct Cyc_Absynpp_Params*
fs){Cyc_Absyndump_expand_typedefs=fs->expand_typedefs;Cyc_Absyndump_qvar_to_Cids=
fs->qvar_to_Cids;Cyc_Absyndump_add_cyc_prefix=fs->add_cyc_prefix;Cyc_Absyndump_to_VC=
fs->to_VC;Cyc_Absyndump_generate_line_directives=fs->generate_line_directives;
Cyc_Absynpp_set_params(fs);}void Cyc_Absyndump_dumptyp(void*);void Cyc_Absyndump_dumpntyp(
void*t);void Cyc_Absyndump_dumpexp(struct Cyc_Absyn_Exp*);void Cyc_Absyndump_dumpexp_prec(
int,struct Cyc_Absyn_Exp*);void Cyc_Absyndump_dumppat(struct Cyc_Absyn_Pat*);void
Cyc_Absyndump_dumpstmt(struct Cyc_Absyn_Stmt*,int expstmt);void Cyc_Absyndump_dumpvardecl(
struct Cyc_Absyn_Vardecl*,struct Cyc_Position_Segment*);void Cyc_Absyndump_dumpdecl(
struct Cyc_Absyn_Decl*);void Cyc_Absyndump_dumptms(struct Cyc_List_List*tms,void(*f)(
void*),void*a);void Cyc_Absyndump_dumptqtd(struct Cyc_Absyn_Tqual,void*,void(*f)(
void*),void*);void Cyc_Absyndump_dumpaggrfields(struct Cyc_List_List*fields);void
Cyc_Absyndump_dumpenumfields(struct Cyc_List_List*fields);void Cyc_Absyndump_dumploc(
struct Cyc_Position_Segment*);struct Cyc___cycFILE**Cyc_Absyndump_dump_file=& Cyc_stdout;
void Cyc_Absyndump_ignore(void*x);void Cyc_Absyndump_ignore(void*x){return;}static
unsigned int Cyc_Absyndump_pos=0;static char Cyc_Absyndump_prev_char='x';int Cyc_Absyndump_need_space_before();
int Cyc_Absyndump_need_space_before(){switch(Cyc_Absyndump_prev_char){case '{':
_LL0: goto _LL1;case '}': _LL1: goto _LL2;case '(': _LL2: goto _LL3;case ')': _LL3: goto _LL4;
case '[': _LL4: goto _LL5;case ']': _LL5: goto _LL6;case ';': _LL6: goto _LL7;case ',': _LL7:
goto _LL8;case '=': _LL8: goto _LL9;case '?': _LL9: goto _LLA;case '!': _LLA: goto _LLB;case ' ':
_LLB: goto _LLC;case '\n': _LLC: goto _LLD;case '*': _LLD: return 0;default: _LLE: return 1;}}
void Cyc_Absyndump_dump(struct _dyneither_ptr s);void Cyc_Absyndump_dump(struct
_dyneither_ptr s){int sz=(int)Cyc_strlen((struct _dyneither_ptr)s);Cyc_Absyndump_pos
+=sz;if(Cyc_Absyndump_pos > 80){Cyc_Absyndump_pos=(unsigned int)sz;Cyc_fputc((int)'\n',*
Cyc_Absyndump_dump_file);}else{if(Cyc_Absyndump_need_space_before())Cyc_fputc((
int)' ',*Cyc_Absyndump_dump_file);}if(sz >= 1){Cyc_Absyndump_prev_char=*((const
char*)_check_dyneither_subscript(s,sizeof(char),sz - 1));Cyc_file_string_write(*
Cyc_Absyndump_dump_file,s,0,sz);}}void Cyc_Absyndump_dump_nospace(struct
_dyneither_ptr s);void Cyc_Absyndump_dump_nospace(struct _dyneither_ptr s){int sz=(
int)Cyc_strlen((struct _dyneither_ptr)s);Cyc_Absyndump_pos +=sz;if(sz >= 1){Cyc_file_string_write(*
Cyc_Absyndump_dump_file,s,0,sz);Cyc_Absyndump_prev_char=*((const char*)
_check_dyneither_subscript(s,sizeof(char),sz - 1));}}void Cyc_Absyndump_dump_char(
int c);void Cyc_Absyndump_dump_char(int c){++ Cyc_Absyndump_pos;Cyc_fputc(c,*Cyc_Absyndump_dump_file);
Cyc_Absyndump_prev_char=(char)c;}void Cyc_Absyndump_dumploc(struct Cyc_Position_Segment*
loc);void Cyc_Absyndump_dumploc(struct Cyc_Position_Segment*loc){if(loc == 0)
return;if(!Cyc_Absyndump_generate_line_directives)return;{struct _dyneither_ptr
_tmp0=Cyc_Position_get_line_directive(loc);Cyc_Absyndump_dump(_tmp0);};}void Cyc_Absyndump_dump_str(
struct _dyneither_ptr*s);void Cyc_Absyndump_dump_str(struct _dyneither_ptr*s){Cyc_Absyndump_dump(*
s);}void Cyc_Absyndump_dump_semi();void Cyc_Absyndump_dump_semi(){Cyc_Absyndump_dump_char((
int)';');}void Cyc_Absyndump_dump_sep(void(*f)(void*),struct Cyc_List_List*l,
struct _dyneither_ptr sep);void Cyc_Absyndump_dump_sep(void(*f)(void*),struct Cyc_List_List*
l,struct _dyneither_ptr sep){if(l == 0)return;for(0;l->tl != 0;l=l->tl){f((void*)l->hd);
Cyc_Absyndump_dump_nospace(sep);}f((void*)l->hd);}void Cyc_Absyndump_dump_sep_c(
void(*f)(void*,void*),void*env,struct Cyc_List_List*l,struct _dyneither_ptr sep);
void Cyc_Absyndump_dump_sep_c(void(*f)(void*,void*),void*env,struct Cyc_List_List*
l,struct _dyneither_ptr sep){if(l == 0)return;for(0;l->tl != 0;l=l->tl){f(env,(void*)
l->hd);Cyc_Absyndump_dump_nospace(sep);}f(env,(void*)l->hd);}void Cyc_Absyndump_group(
void(*f)(void*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep);void Cyc_Absyndump_group(void(*f)(void*),
struct Cyc_List_List*l,struct _dyneither_ptr start,struct _dyneither_ptr end,struct
_dyneither_ptr sep){Cyc_Absyndump_dump_nospace(start);Cyc_Absyndump_dump_sep(f,l,
sep);Cyc_Absyndump_dump_nospace(end);}void Cyc_Absyndump_group_c(void(*f)(void*,
void*),void*env,struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep);void Cyc_Absyndump_group_c(void(*f)(
void*,void*),void*env,struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep){Cyc_Absyndump_dump_nospace(start);Cyc_Absyndump_dump_sep_c(
f,env,l,sep);Cyc_Absyndump_dump_nospace(end);}void Cyc_Absyndump_egroup(void(*f)(
void*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct _dyneither_ptr end,
struct _dyneither_ptr sep);void Cyc_Absyndump_egroup(void(*f)(void*),struct Cyc_List_List*
l,struct _dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep){if(
l != 0)Cyc_Absyndump_group(f,l,start,end,sep);}void Cyc_Absyndump_dumpqvar(struct
_tuple0*v);void Cyc_Absyndump_dumpqvar(struct _tuple0*v){struct Cyc_List_List*_tmp1=
0;struct _dyneither_ptr**prefix=0;{union Cyc_Absyn_Nmspace _tmp2=(*v).f1;int _tmp3;
struct Cyc_List_List*_tmp4;struct Cyc_List_List*_tmp5;_LL11: if((_tmp2.Loc_n).tag != 
3)goto _LL13;_tmp3=(int)(_tmp2.Loc_n).val;_LL12: _tmp4=0;goto _LL14;_LL13: if((_tmp2.Rel_n).tag
!= 1)goto _LL15;_tmp4=(struct Cyc_List_List*)(_tmp2.Rel_n).val;_LL14: _tmp1=_tmp4;
goto _LL10;_LL15: if((_tmp2.Abs_n).tag != 2)goto _LL10;_tmp5=(struct Cyc_List_List*)(
_tmp2.Abs_n).val;_LL16: if(Cyc_Absyndump_qvar_to_Cids  && Cyc_Absyndump_add_cyc_prefix)
prefix=(struct _dyneither_ptr**)& Cyc_Absynpp_cyc_stringptr;_tmp1=_tmp5;goto _LL10;
_LL10:;}if(prefix != 0){Cyc_Absyndump_dump_str(*prefix);if(Cyc_Absyndump_qvar_to_Cids)
Cyc_Absyndump_dump_char((int)'_');else{const char*_tmp393;Cyc_Absyndump_dump_nospace(((
_tmp393="::",_tag_dyneither(_tmp393,sizeof(char),3))));}}if(_tmp1 != 0){Cyc_Absyndump_dump_nospace(*((
struct _dyneither_ptr*)_tmp1->hd));for(_tmp1=_tmp1->tl;_tmp1 != 0;_tmp1=_tmp1->tl){
if(Cyc_Absyndump_qvar_to_Cids)Cyc_Absyndump_dump_char((int)'_');else{const char*
_tmp394;Cyc_Absyndump_dump_nospace(((_tmp394="::",_tag_dyneither(_tmp394,sizeof(
char),3))));}Cyc_Absyndump_dump_nospace(*((struct _dyneither_ptr*)_tmp1->hd));}
if(Cyc_Absyndump_qvar_to_Cids){const char*_tmp395;Cyc_Absyndump_dump_nospace(((
_tmp395="_",_tag_dyneither(_tmp395,sizeof(char),2))));}else{const char*_tmp396;
Cyc_Absyndump_dump_nospace(((_tmp396="::",_tag_dyneither(_tmp396,sizeof(char),3))));}
Cyc_Absyndump_dump_nospace(*(*v).f2);}else{if(prefix != 0)Cyc_Absyndump_dump_nospace(*(*
v).f2);else{Cyc_Absyndump_dump_str((*v).f2);}}}void Cyc_Absyndump_dumptq(struct
Cyc_Absyn_Tqual tq);void Cyc_Absyndump_dumptq(struct Cyc_Absyn_Tqual tq){if(tq.q_restrict){
const char*_tmp397;Cyc_Absyndump_dump(((_tmp397="restrict",_tag_dyneither(_tmp397,
sizeof(char),9))));}if(tq.q_volatile){const char*_tmp398;Cyc_Absyndump_dump(((
_tmp398="volatile",_tag_dyneither(_tmp398,sizeof(char),9))));}if(tq.print_const){
const char*_tmp399;Cyc_Absyndump_dump(((_tmp399="const",_tag_dyneither(_tmp399,
sizeof(char),6))));}}void Cyc_Absyndump_dumpscope(enum Cyc_Absyn_Scope sc);void Cyc_Absyndump_dumpscope(
enum Cyc_Absyn_Scope sc){switch(sc){case Cyc_Absyn_Static: _LL17:{const char*_tmp39A;
Cyc_Absyndump_dump(((_tmp39A="static",_tag_dyneither(_tmp39A,sizeof(char),7))));}
return;case Cyc_Absyn_Public: _LL18: return;case Cyc_Absyn_Extern: _LL19:{const char*
_tmp39B;Cyc_Absyndump_dump(((_tmp39B="extern",_tag_dyneither(_tmp39B,sizeof(char),
7))));}return;case Cyc_Absyn_ExternC: _LL1A:{const char*_tmp39C;Cyc_Absyndump_dump(((
_tmp39C="extern \"C\"",_tag_dyneither(_tmp39C,sizeof(char),11))));}return;case
Cyc_Absyn_Abstract: _LL1B:{const char*_tmp39D;Cyc_Absyndump_dump(((_tmp39D="abstract",
_tag_dyneither(_tmp39D,sizeof(char),9))));}return;case Cyc_Absyn_Register: _LL1C:{
const char*_tmp39E;Cyc_Absyndump_dump(((_tmp39E="register",_tag_dyneither(_tmp39E,
sizeof(char),9))));}return;}}void Cyc_Absyndump_dumpkind(enum Cyc_Absyn_Kind k);
void Cyc_Absyndump_dumpkind(enum Cyc_Absyn_Kind k){switch(k){case Cyc_Absyn_AnyKind:
_LL1E:{const char*_tmp39F;Cyc_Absyndump_dump(((_tmp39F="A",_tag_dyneither(_tmp39F,
sizeof(char),2))));}return;case Cyc_Absyn_MemKind: _LL1F:{const char*_tmp3A0;Cyc_Absyndump_dump(((
_tmp3A0="M",_tag_dyneither(_tmp3A0,sizeof(char),2))));}return;case Cyc_Absyn_BoxKind:
_LL20:{const char*_tmp3A1;Cyc_Absyndump_dump(((_tmp3A1="B",_tag_dyneither(_tmp3A1,
sizeof(char),2))));}return;case Cyc_Absyn_RgnKind: _LL21:{const char*_tmp3A2;Cyc_Absyndump_dump(((
_tmp3A2="R",_tag_dyneither(_tmp3A2,sizeof(char),2))));}return;case Cyc_Absyn_UniqueRgnKind:
_LL22:{const char*_tmp3A3;Cyc_Absyndump_dump(((_tmp3A3="UR",_tag_dyneither(
_tmp3A3,sizeof(char),3))));}return;case Cyc_Absyn_TopRgnKind: _LL23:{const char*
_tmp3A4;Cyc_Absyndump_dump(((_tmp3A4="TR",_tag_dyneither(_tmp3A4,sizeof(char),3))));}
return;case Cyc_Absyn_EffKind: _LL24:{const char*_tmp3A5;Cyc_Absyndump_dump(((
_tmp3A5="E",_tag_dyneither(_tmp3A5,sizeof(char),2))));}return;case Cyc_Absyn_IntKind:
_LL25:{const char*_tmp3A6;Cyc_Absyndump_dump(((_tmp3A6="I",_tag_dyneither(_tmp3A6,
sizeof(char),2))));}return;}}void Cyc_Absyndump_dumpaggr_kind(enum Cyc_Absyn_AggrKind
k);void Cyc_Absyndump_dumpaggr_kind(enum Cyc_Absyn_AggrKind k){switch(k){case Cyc_Absyn_StructA:
_LL27:{const char*_tmp3A7;Cyc_Absyndump_dump(((_tmp3A7="struct",_tag_dyneither(
_tmp3A7,sizeof(char),7))));}return;case Cyc_Absyn_UnionA: _LL28:{const char*_tmp3A8;
Cyc_Absyndump_dump(((_tmp3A8="union",_tag_dyneither(_tmp3A8,sizeof(char),6))));}
return;}}void Cyc_Absyndump_dumptps(struct Cyc_List_List*ts);void Cyc_Absyndump_dumptps(
struct Cyc_List_List*ts){const char*_tmp3AB;const char*_tmp3AA;const char*_tmp3A9;((
void(*)(void(*f)(void*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(Cyc_Absyndump_dumptyp,
ts,((_tmp3A9="<",_tag_dyneither(_tmp3A9,sizeof(char),2))),((_tmp3AA=">",
_tag_dyneither(_tmp3AA,sizeof(char),2))),((_tmp3AB=",",_tag_dyneither(_tmp3AB,
sizeof(char),2))));}void Cyc_Absyndump_dumptvar(struct Cyc_Absyn_Tvar*tv);void Cyc_Absyndump_dumptvar(
struct Cyc_Absyn_Tvar*tv){Cyc_Absyndump_dump_str(tv->name);}void Cyc_Absyndump_dumpkindedtvar(
struct Cyc_Absyn_Tvar*tv);void Cyc_Absyndump_dumpkindedtvar(struct Cyc_Absyn_Tvar*
tv){Cyc_Absyndump_dump_str(tv->name);{void*_tmp1F=Cyc_Absyn_compress_kb(tv->kind);
enum Cyc_Absyn_Kind _tmp21;enum Cyc_Absyn_Kind _tmp25;_LL2B: {struct Cyc_Absyn_Eq_kb_struct*
_tmp20=(struct Cyc_Absyn_Eq_kb_struct*)_tmp1F;if(_tmp20->tag != 0)goto _LL2D;else{
_tmp21=_tmp20->f1;if(_tmp21 != Cyc_Absyn_BoxKind)goto _LL2D;}}_LL2C: goto _LL2E;
_LL2D: {struct Cyc_Absyn_Less_kb_struct*_tmp22=(struct Cyc_Absyn_Less_kb_struct*)
_tmp1F;if(_tmp22->tag != 2)goto _LL2F;}_LL2E: goto _LL30;_LL2F: {struct Cyc_Absyn_Unknown_kb_struct*
_tmp23=(struct Cyc_Absyn_Unknown_kb_struct*)_tmp1F;if(_tmp23->tag != 1)goto _LL31;}
_LL30:{const char*_tmp3AC;Cyc_Absyndump_dump(((_tmp3AC="::?",_tag_dyneither(
_tmp3AC,sizeof(char),4))));}goto _LL2A;_LL31: {struct Cyc_Absyn_Eq_kb_struct*
_tmp24=(struct Cyc_Absyn_Eq_kb_struct*)_tmp1F;if(_tmp24->tag != 0)goto _LL2A;else{
_tmp25=_tmp24->f1;}}_LL32:{const char*_tmp3AD;Cyc_Absyndump_dump(((_tmp3AD="::",
_tag_dyneither(_tmp3AD,sizeof(char),3))));}Cyc_Absyndump_dumpkind(_tmp25);goto
_LL2A;_LL2A:;};}void Cyc_Absyndump_dumptvars(struct Cyc_List_List*tvs);void Cyc_Absyndump_dumptvars(
struct Cyc_List_List*tvs){const char*_tmp3B0;const char*_tmp3AF;const char*_tmp3AE;((
void(*)(void(*f)(struct Cyc_Absyn_Tvar*),struct Cyc_List_List*l,struct
_dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(
Cyc_Absyndump_dumptvar,tvs,((_tmp3AE="<",_tag_dyneither(_tmp3AE,sizeof(char),2))),((
_tmp3AF=">",_tag_dyneither(_tmp3AF,sizeof(char),2))),((_tmp3B0=",",
_tag_dyneither(_tmp3B0,sizeof(char),2))));}void Cyc_Absyndump_dumpkindedtvars(
struct Cyc_List_List*tvs);void Cyc_Absyndump_dumpkindedtvars(struct Cyc_List_List*
tvs){const char*_tmp3B3;const char*_tmp3B2;const char*_tmp3B1;((void(*)(void(*f)(
struct Cyc_Absyn_Tvar*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(Cyc_Absyndump_dumpkindedtvar,
tvs,((_tmp3B1="<",_tag_dyneither(_tmp3B1,sizeof(char),2))),((_tmp3B2=">",
_tag_dyneither(_tmp3B2,sizeof(char),2))),((_tmp3B3=",",_tag_dyneither(_tmp3B3,
sizeof(char),2))));}struct _tuple13{struct Cyc_Absyn_Tqual f1;void*f2;};void Cyc_Absyndump_dumparg(
struct _tuple13*pr);void Cyc_Absyndump_dumparg(struct _tuple13*pr){((void(*)(struct
Cyc_Absyn_Tqual,void*,void(*f)(int),int))Cyc_Absyndump_dumptqtd)((*pr).f1,(*pr).f2,(
void(*)(int x))Cyc_Absyndump_ignore,0);}void Cyc_Absyndump_dumpargs(struct Cyc_List_List*
ts);void Cyc_Absyndump_dumpargs(struct Cyc_List_List*ts){const char*_tmp3B6;const
char*_tmp3B5;const char*_tmp3B4;((void(*)(void(*f)(struct _tuple13*),struct Cyc_List_List*
l,struct _dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dumparg,ts,((_tmp3B4="(",_tag_dyneither(_tmp3B4,sizeof(char),2))),((
_tmp3B5=")",_tag_dyneither(_tmp3B5,sizeof(char),2))),((_tmp3B6=",",
_tag_dyneither(_tmp3B6,sizeof(char),2))));}void Cyc_Absyndump_dump_callconv(
struct Cyc_List_List*atts);void Cyc_Absyndump_dump_callconv(struct Cyc_List_List*
atts){for(0;atts != 0;atts=atts->tl){void*_tmp31=(void*)atts->hd;_LL34: {struct
Cyc_Absyn_Stdcall_att_struct*_tmp32=(struct Cyc_Absyn_Stdcall_att_struct*)_tmp31;
if(_tmp32->tag != 1)goto _LL36;}_LL35:{const char*_tmp3B7;Cyc_Absyndump_dump(((
_tmp3B7="_stdcall",_tag_dyneither(_tmp3B7,sizeof(char),9))));}return;_LL36: {
struct Cyc_Absyn_Cdecl_att_struct*_tmp33=(struct Cyc_Absyn_Cdecl_att_struct*)
_tmp31;if(_tmp33->tag != 2)goto _LL38;}_LL37:{const char*_tmp3B8;Cyc_Absyndump_dump(((
_tmp3B8="_cdecl",_tag_dyneither(_tmp3B8,sizeof(char),7))));}return;_LL38: {
struct Cyc_Absyn_Fastcall_att_struct*_tmp34=(struct Cyc_Absyn_Fastcall_att_struct*)
_tmp31;if(_tmp34->tag != 3)goto _LL3A;}_LL39:{const char*_tmp3B9;Cyc_Absyndump_dump(((
_tmp3B9="_fastcall",_tag_dyneither(_tmp3B9,sizeof(char),10))));}return;_LL3A:;
_LL3B: goto _LL33;_LL33:;}}void Cyc_Absyndump_dump_noncallconv(struct Cyc_List_List*
atts);void Cyc_Absyndump_dump_noncallconv(struct Cyc_List_List*atts){int hasatt=0;{
struct Cyc_List_List*atts2=atts;for(0;atts2 != 0;atts2=atts2->tl){void*_tmp38=(
void*)((struct Cyc_List_List*)_check_null(atts))->hd;_LL3D: {struct Cyc_Absyn_Stdcall_att_struct*
_tmp39=(struct Cyc_Absyn_Stdcall_att_struct*)_tmp38;if(_tmp39->tag != 1)goto _LL3F;}
_LL3E: goto _LL40;_LL3F: {struct Cyc_Absyn_Cdecl_att_struct*_tmp3A=(struct Cyc_Absyn_Cdecl_att_struct*)
_tmp38;if(_tmp3A->tag != 2)goto _LL41;}_LL40: goto _LL42;_LL41: {struct Cyc_Absyn_Fastcall_att_struct*
_tmp3B=(struct Cyc_Absyn_Fastcall_att_struct*)_tmp38;if(_tmp3B->tag != 3)goto _LL43;}
_LL42: goto _LL3C;_LL43:;_LL44: hasatt=1;goto _LL3C;_LL3C:;}}if(!hasatt)return;{
const char*_tmp3BA;Cyc_Absyndump_dump(((_tmp3BA="__declspec(",_tag_dyneither(
_tmp3BA,sizeof(char),12))));}for(0;atts != 0;atts=atts->tl){void*_tmp3D=(void*)
atts->hd;_LL46: {struct Cyc_Absyn_Stdcall_att_struct*_tmp3E=(struct Cyc_Absyn_Stdcall_att_struct*)
_tmp3D;if(_tmp3E->tag != 1)goto _LL48;}_LL47: goto _LL49;_LL48: {struct Cyc_Absyn_Cdecl_att_struct*
_tmp3F=(struct Cyc_Absyn_Cdecl_att_struct*)_tmp3D;if(_tmp3F->tag != 2)goto _LL4A;}
_LL49: goto _LL4B;_LL4A: {struct Cyc_Absyn_Fastcall_att_struct*_tmp40=(struct Cyc_Absyn_Fastcall_att_struct*)
_tmp3D;if(_tmp40->tag != 3)goto _LL4C;}_LL4B: goto _LL45;_LL4C:;_LL4D: Cyc_Absyndump_dump(
Cyc_Absyn_attribute2string((void*)atts->hd));goto _LL45;_LL45:;}Cyc_Absyndump_dump_char((
int)')');}void Cyc_Absyndump_dumpatts(struct Cyc_List_List*atts);void Cyc_Absyndump_dumpatts(
struct Cyc_List_List*atts){if(atts == 0)return;switch(Cyc_Cyclone_c_compiler){case
Cyc_Cyclone_Gcc_c: _LL4E:{const char*_tmp3BB;Cyc_Absyndump_dump(((_tmp3BB=" __attribute__((",
_tag_dyneither(_tmp3BB,sizeof(char),17))));}for(0;atts != 0;atts=atts->tl){Cyc_Absyndump_dump(
Cyc_Absyn_attribute2string((void*)atts->hd));if(atts->tl != 0){const char*_tmp3BC;
Cyc_Absyndump_dump(((_tmp3BC=",",_tag_dyneither(_tmp3BC,sizeof(char),2))));}}{
const char*_tmp3BD;Cyc_Absyndump_dump(((_tmp3BD=")) ",_tag_dyneither(_tmp3BD,
sizeof(char),4))));}return;case Cyc_Cyclone_Vc_c: _LL4F: Cyc_Absyndump_dump_noncallconv(
atts);return;}}int Cyc_Absyndump_next_is_pointer(struct Cyc_List_List*tms);int Cyc_Absyndump_next_is_pointer(
struct Cyc_List_List*tms){if(tms == 0)return 0;{void*_tmp44=(void*)tms->hd;_LL52: {
struct Cyc_Absyn_Pointer_mod_struct*_tmp45=(struct Cyc_Absyn_Pointer_mod_struct*)
_tmp44;if(_tmp45->tag != 2)goto _LL54;}_LL53: return 1;_LL54:;_LL55: return 0;_LL51:;};}
static void Cyc_Absyndump_dumprgn(void*t);static void Cyc_Absyndump_dumprgn(void*t){
void*_tmp46=Cyc_Tcutil_compress(t);_LL57: {struct Cyc_Absyn_HeapRgn_struct*_tmp47=(
struct Cyc_Absyn_HeapRgn_struct*)_tmp46;if(_tmp47->tag != 21)goto _LL59;}_LL58:{
const char*_tmp3BE;Cyc_Absyndump_dump(((_tmp3BE="`H",_tag_dyneither(_tmp3BE,
sizeof(char),3))));}goto _LL56;_LL59:;_LL5A: Cyc_Absyndump_dumpntyp(t);goto _LL56;
_LL56:;}struct _tuple14{struct Cyc_List_List*f1;struct Cyc_List_List*f2;};static
struct _tuple14 Cyc_Absyndump_effects_split(void*t);static struct _tuple14 Cyc_Absyndump_effects_split(
void*t){struct Cyc_List_List*rgions=0;struct Cyc_List_List*effects=0;{void*_tmp49=
Cyc_Tcutil_compress(t);void*_tmp4B;struct Cyc_List_List*_tmp4D;_LL5C: {struct Cyc_Absyn_AccessEff_struct*
_tmp4A=(struct Cyc_Absyn_AccessEff_struct*)_tmp49;if(_tmp4A->tag != 23)goto _LL5E;
else{_tmp4B=(void*)_tmp4A->f1;}}_LL5D:{struct Cyc_List_List*_tmp3BF;rgions=((
_tmp3BF=_cycalloc(sizeof(*_tmp3BF)),((_tmp3BF->hd=_tmp4B,((_tmp3BF->tl=rgions,
_tmp3BF))))));}goto _LL5B;_LL5E: {struct Cyc_Absyn_JoinEff_struct*_tmp4C=(struct
Cyc_Absyn_JoinEff_struct*)_tmp49;if(_tmp4C->tag != 24)goto _LL60;else{_tmp4D=
_tmp4C->f1;}}_LL5F: for(0;_tmp4D != 0;_tmp4D=_tmp4D->tl){struct Cyc_List_List*
_tmp50;struct Cyc_List_List*_tmp51;struct _tuple14 _tmp4F=Cyc_Absyndump_effects_split((
void*)_tmp4D->hd);_tmp50=_tmp4F.f1;_tmp51=_tmp4F.f2;rgions=((struct Cyc_List_List*(*)(
struct Cyc_List_List*x,struct Cyc_List_List*y))Cyc_List_imp_append)(_tmp50,rgions);
effects=((struct Cyc_List_List*(*)(struct Cyc_List_List*x,struct Cyc_List_List*y))
Cyc_List_imp_append)(_tmp51,effects);}goto _LL5B;_LL60:;_LL61:{struct Cyc_List_List*
_tmp3C0;effects=((_tmp3C0=_cycalloc(sizeof(*_tmp3C0)),((_tmp3C0->hd=t,((_tmp3C0->tl=
effects,_tmp3C0))))));}goto _LL5B;_LL5B:;}{struct _tuple14 _tmp3C1;return(_tmp3C1.f1=
rgions,((_tmp3C1.f2=effects,_tmp3C1)));};}static void Cyc_Absyndump_dumpeff(void*t);
static void Cyc_Absyndump_dumpeff(void*t){struct Cyc_List_List*_tmp55;struct Cyc_List_List*
_tmp56;struct _tuple14 _tmp54=Cyc_Absyndump_effects_split(t);_tmp55=_tmp54.f1;
_tmp56=_tmp54.f2;_tmp55=((struct Cyc_List_List*(*)(struct Cyc_List_List*x))Cyc_List_imp_rev)(
_tmp55);_tmp56=((struct Cyc_List_List*(*)(struct Cyc_List_List*x))Cyc_List_imp_rev)(
_tmp56);for(0;_tmp56 != 0;_tmp56=_tmp56->tl){Cyc_Absyndump_dumpntyp((void*)_tmp56->hd);
Cyc_Absyndump_dump_char((int)'+');}Cyc_Absyndump_dump_char((int)'{');for(0;
_tmp55 != 0;_tmp55=_tmp55->tl){Cyc_Absyndump_dumprgn((void*)_tmp55->hd);if(_tmp55->tl
!= 0)Cyc_Absyndump_dump_char((int)',');}Cyc_Absyndump_dump_char((int)'}');}void
Cyc_Absyndump_dumpntyp(void*t);void Cyc_Absyndump_dumpntyp(void*t){void*_tmp57=t;
struct Cyc_Absyn_Tvar*_tmp5D;struct Cyc_Core_Opt*_tmp5F;struct Cyc_Core_Opt*_tmp60;
int _tmp61;struct Cyc_Core_Opt*_tmp63;struct Cyc_Core_Opt*_tmp64;struct Cyc_Core_Opt
_tmp65;void*_tmp66;int _tmp67;struct Cyc_Absyn_DatatypeInfo _tmp69;union Cyc_Absyn_DatatypeInfoU
_tmp6A;struct Cyc_List_List*_tmp6B;struct Cyc_Absyn_DatatypeFieldInfo _tmp6D;union
Cyc_Absyn_DatatypeFieldInfoU _tmp6E;struct Cyc_List_List*_tmp6F;enum Cyc_Absyn_Sign
_tmp71;enum Cyc_Absyn_Size_of _tmp72;enum Cyc_Absyn_Sign _tmp74;enum Cyc_Absyn_Size_of
_tmp75;enum Cyc_Absyn_Sign _tmp77;enum Cyc_Absyn_Size_of _tmp78;enum Cyc_Absyn_Sign
_tmp7A;enum Cyc_Absyn_Size_of _tmp7B;enum Cyc_Absyn_Sign _tmp7D;enum Cyc_Absyn_Size_of
_tmp7E;enum Cyc_Absyn_Sign _tmp80;enum Cyc_Absyn_Size_of _tmp81;enum Cyc_Absyn_Sign
_tmp83;enum Cyc_Absyn_Size_of _tmp84;enum Cyc_Absyn_Sign _tmp86;enum Cyc_Absyn_Size_of
_tmp87;enum Cyc_Absyn_Sign _tmp89;enum Cyc_Absyn_Size_of _tmp8A;enum Cyc_Absyn_Sign
_tmp8C;enum Cyc_Absyn_Size_of _tmp8D;enum Cyc_Absyn_Sign _tmp8F;enum Cyc_Absyn_Size_of
_tmp90;enum Cyc_Absyn_Sign _tmp92;enum Cyc_Absyn_Size_of _tmp93;enum Cyc_Absyn_Sign
_tmp95;enum Cyc_Absyn_Size_of _tmp96;enum Cyc_Absyn_Sign _tmp98;enum Cyc_Absyn_Size_of
_tmp99;enum Cyc_Absyn_Sign _tmp9B;enum Cyc_Absyn_Size_of _tmp9C;int _tmp9F;struct
Cyc_List_List*_tmpA1;struct Cyc_Absyn_AggrInfo _tmpA3;union Cyc_Absyn_AggrInfoU
_tmpA4;struct Cyc_List_List*_tmpA5;enum Cyc_Absyn_AggrKind _tmpA7;struct Cyc_List_List*
_tmpA8;struct _tuple0*_tmpAA;struct Cyc_List_List*_tmpAC;struct _tuple0*_tmpAE;
struct Cyc_List_List*_tmpAF;struct Cyc_Absyn_Exp*_tmpB1;void*_tmpB3;void*_tmpB5;
void*_tmpB6;void*_tmpB8;_LL63: {struct Cyc_Absyn_ArrayType_struct*_tmp58=(struct
Cyc_Absyn_ArrayType_struct*)_tmp57;if(_tmp58->tag != 9)goto _LL65;}_LL64: goto _LL66;
_LL65: {struct Cyc_Absyn_FnType_struct*_tmp59=(struct Cyc_Absyn_FnType_struct*)
_tmp57;if(_tmp59->tag != 10)goto _LL67;}_LL66: goto _LL68;_LL67: {struct Cyc_Absyn_PointerType_struct*
_tmp5A=(struct Cyc_Absyn_PointerType_struct*)_tmp57;if(_tmp5A->tag != 5)goto _LL69;}
_LL68: return;_LL69: {struct Cyc_Absyn_VoidType_struct*_tmp5B=(struct Cyc_Absyn_VoidType_struct*)
_tmp57;if(_tmp5B->tag != 0)goto _LL6B;}_LL6A:{const char*_tmp3C2;Cyc_Absyndump_dump(((
_tmp3C2="void",_tag_dyneither(_tmp3C2,sizeof(char),5))));}return;_LL6B: {struct
Cyc_Absyn_VarType_struct*_tmp5C=(struct Cyc_Absyn_VarType_struct*)_tmp57;if(
_tmp5C->tag != 2)goto _LL6D;else{_tmp5D=_tmp5C->f1;}}_LL6C: Cyc_Absyndump_dump_str(
_tmp5D->name);return;_LL6D: {struct Cyc_Absyn_Evar_struct*_tmp5E=(struct Cyc_Absyn_Evar_struct*)
_tmp57;if(_tmp5E->tag != 1)goto _LL6F;else{_tmp5F=_tmp5E->f1;_tmp60=_tmp5E->f2;if(
_tmp60 != 0)goto _LL6F;_tmp61=_tmp5E->f3;}}_LL6E:{const char*_tmp3C3;Cyc_Absyndump_dump(((
_tmp3C3="%",_tag_dyneither(_tmp3C3,sizeof(char),2))));}if(_tmp5F == 0){const char*
_tmp3C4;Cyc_Absyndump_dump(((_tmp3C4="?",_tag_dyneither(_tmp3C4,sizeof(char),2))));}
else{Cyc_Absyndump_dumpkind((enum Cyc_Absyn_Kind)_tmp5F->v);}{const char*_tmp3C8;
void*_tmp3C7[1];struct Cyc_Int_pa_struct _tmp3C6;Cyc_Absyndump_dump((struct
_dyneither_ptr)((_tmp3C6.tag=1,((_tmp3C6.f1=(unsigned long)_tmp61,((_tmp3C7[0]=&
_tmp3C6,Cyc_aprintf(((_tmp3C8="(%d)",_tag_dyneither(_tmp3C8,sizeof(char),5))),
_tag_dyneither(_tmp3C7,sizeof(void*),1)))))))));}return;_LL6F: {struct Cyc_Absyn_Evar_struct*
_tmp62=(struct Cyc_Absyn_Evar_struct*)_tmp57;if(_tmp62->tag != 1)goto _LL71;else{
_tmp63=_tmp62->f1;_tmp64=_tmp62->f2;if(_tmp64 == 0)goto _LL71;_tmp65=*_tmp64;
_tmp66=(void*)_tmp65.v;_tmp67=_tmp62->f3;}}_LL70: Cyc_Absyndump_dumpntyp(_tmp66);
return;_LL71: {struct Cyc_Absyn_DatatypeType_struct*_tmp68=(struct Cyc_Absyn_DatatypeType_struct*)
_tmp57;if(_tmp68->tag != 3)goto _LL73;else{_tmp69=_tmp68->f1;_tmp6A=_tmp69.datatype_info;
_tmp6B=_tmp69.targs;}}_LL72:{union Cyc_Absyn_DatatypeInfoU _tmpC4=_tmp6A;struct Cyc_Absyn_UnknownDatatypeInfo
_tmpC5;struct _tuple0*_tmpC6;int _tmpC7;struct Cyc_Absyn_Datatypedecl**_tmpC8;
struct Cyc_Absyn_Datatypedecl*_tmpC9;struct Cyc_Absyn_Datatypedecl _tmpCA;struct
_tuple0*_tmpCB;int _tmpCC;_LLB6: if((_tmpC4.UnknownDatatype).tag != 1)goto _LLB8;
_tmpC5=(struct Cyc_Absyn_UnknownDatatypeInfo)(_tmpC4.UnknownDatatype).val;_tmpC6=
_tmpC5.name;_tmpC7=_tmpC5.is_extensible;_LLB7: _tmpCB=_tmpC6;_tmpCC=_tmpC7;goto
_LLB9;_LLB8: if((_tmpC4.KnownDatatype).tag != 2)goto _LLB5;_tmpC8=(struct Cyc_Absyn_Datatypedecl**)(
_tmpC4.KnownDatatype).val;_tmpC9=*_tmpC8;_tmpCA=*_tmpC9;_tmpCB=_tmpCA.name;
_tmpCC=_tmpCA.is_extensible;_LLB9: if(_tmpCC){const char*_tmp3C9;Cyc_Absyndump_dump(((
_tmp3C9="@extensible ",_tag_dyneither(_tmp3C9,sizeof(char),13))));}{const char*
_tmp3CA;Cyc_Absyndump_dump(((_tmp3CA="datatype ",_tag_dyneither(_tmp3CA,sizeof(
char),10))));}Cyc_Absyndump_dumpqvar(_tmpCB);Cyc_Absyndump_dumptps(_tmp6B);goto
_LLB5;_LLB5:;}goto _LL62;_LL73: {struct Cyc_Absyn_DatatypeFieldType_struct*_tmp6C=(
struct Cyc_Absyn_DatatypeFieldType_struct*)_tmp57;if(_tmp6C->tag != 4)goto _LL75;
else{_tmp6D=_tmp6C->f1;_tmp6E=_tmp6D.field_info;_tmp6F=_tmp6D.targs;}}_LL74:{
union Cyc_Absyn_DatatypeFieldInfoU _tmpCF=_tmp6E;struct Cyc_Absyn_UnknownDatatypeFieldInfo
_tmpD0;struct _tuple0*_tmpD1;struct _tuple0*_tmpD2;int _tmpD3;struct _tuple1 _tmpD4;
struct Cyc_Absyn_Datatypedecl*_tmpD5;struct Cyc_Absyn_Datatypedecl _tmpD6;struct
_tuple0*_tmpD7;int _tmpD8;struct Cyc_Absyn_Datatypefield*_tmpD9;struct Cyc_Absyn_Datatypefield
_tmpDA;struct _tuple0*_tmpDB;_LLBB: if((_tmpCF.UnknownDatatypefield).tag != 1)goto
_LLBD;_tmpD0=(struct Cyc_Absyn_UnknownDatatypeFieldInfo)(_tmpCF.UnknownDatatypefield).val;
_tmpD1=_tmpD0.datatype_name;_tmpD2=_tmpD0.field_name;_tmpD3=_tmpD0.is_extensible;
_LLBC: _tmpD7=_tmpD1;_tmpD8=_tmpD3;_tmpDB=_tmpD2;goto _LLBE;_LLBD: if((_tmpCF.KnownDatatypefield).tag
!= 2)goto _LLBA;_tmpD4=(struct _tuple1)(_tmpCF.KnownDatatypefield).val;_tmpD5=
_tmpD4.f1;_tmpD6=*_tmpD5;_tmpD7=_tmpD6.name;_tmpD8=_tmpD6.is_extensible;_tmpD9=
_tmpD4.f2;_tmpDA=*_tmpD9;_tmpDB=_tmpDA.name;_LLBE: if(_tmpD8){const char*_tmp3CB;
Cyc_Absyndump_dump(((_tmp3CB="@extensible ",_tag_dyneither(_tmp3CB,sizeof(char),
13))));}{const char*_tmp3CC;Cyc_Absyndump_dump(((_tmp3CC="datatype ",
_tag_dyneither(_tmp3CC,sizeof(char),10))));}Cyc_Absyndump_dumpqvar(_tmpD7);{
const char*_tmp3CD;Cyc_Absyndump_dump(((_tmp3CD=".",_tag_dyneither(_tmp3CD,
sizeof(char),2))));}Cyc_Absyndump_dumpqvar(_tmpDB);Cyc_Absyndump_dumptps(_tmp6F);
goto _LLBA;_LLBA:;}goto _LL62;_LL75: {struct Cyc_Absyn_IntType_struct*_tmp70=(
struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp70->tag != 6)goto _LL77;else{_tmp71=
_tmp70->f1;if(_tmp71 != Cyc_Absyn_None)goto _LL77;_tmp72=_tmp70->f2;if(_tmp72 != 
Cyc_Absyn_Int_sz)goto _LL77;}}_LL76: goto _LL78;_LL77: {struct Cyc_Absyn_IntType_struct*
_tmp73=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp73->tag != 6)goto _LL79;
else{_tmp74=_tmp73->f1;if(_tmp74 != Cyc_Absyn_Signed)goto _LL79;_tmp75=_tmp73->f2;
if(_tmp75 != Cyc_Absyn_Int_sz)goto _LL79;}}_LL78:{const char*_tmp3CE;Cyc_Absyndump_dump(((
_tmp3CE="int",_tag_dyneither(_tmp3CE,sizeof(char),4))));}return;_LL79: {struct
Cyc_Absyn_IntType_struct*_tmp76=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(
_tmp76->tag != 6)goto _LL7B;else{_tmp77=_tmp76->f1;if(_tmp77 != Cyc_Absyn_None)goto
_LL7B;_tmp78=_tmp76->f2;if(_tmp78 != Cyc_Absyn_Long_sz)goto _LL7B;}}_LL7A: goto
_LL7C;_LL7B: {struct Cyc_Absyn_IntType_struct*_tmp79=(struct Cyc_Absyn_IntType_struct*)
_tmp57;if(_tmp79->tag != 6)goto _LL7D;else{_tmp7A=_tmp79->f1;if(_tmp7A != Cyc_Absyn_Signed)
goto _LL7D;_tmp7B=_tmp79->f2;if(_tmp7B != Cyc_Absyn_Long_sz)goto _LL7D;}}_LL7C:{
const char*_tmp3CF;Cyc_Absyndump_dump(((_tmp3CF="long",_tag_dyneither(_tmp3CF,
sizeof(char),5))));}return;_LL7D: {struct Cyc_Absyn_IntType_struct*_tmp7C=(struct
Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp7C->tag != 6)goto _LL7F;else{_tmp7D=_tmp7C->f1;
if(_tmp7D != Cyc_Absyn_None)goto _LL7F;_tmp7E=_tmp7C->f2;if(_tmp7E != Cyc_Absyn_Char_sz)
goto _LL7F;}}_LL7E:{const char*_tmp3D0;Cyc_Absyndump_dump(((_tmp3D0="char",
_tag_dyneither(_tmp3D0,sizeof(char),5))));}return;_LL7F: {struct Cyc_Absyn_IntType_struct*
_tmp7F=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp7F->tag != 6)goto _LL81;
else{_tmp80=_tmp7F->f1;if(_tmp80 != Cyc_Absyn_Signed)goto _LL81;_tmp81=_tmp7F->f2;
if(_tmp81 != Cyc_Absyn_Char_sz)goto _LL81;}}_LL80:{const char*_tmp3D1;Cyc_Absyndump_dump(((
_tmp3D1="signed char",_tag_dyneither(_tmp3D1,sizeof(char),12))));}return;_LL81: {
struct Cyc_Absyn_IntType_struct*_tmp82=(struct Cyc_Absyn_IntType_struct*)_tmp57;
if(_tmp82->tag != 6)goto _LL83;else{_tmp83=_tmp82->f1;if(_tmp83 != Cyc_Absyn_Unsigned)
goto _LL83;_tmp84=_tmp82->f2;if(_tmp84 != Cyc_Absyn_Char_sz)goto _LL83;}}_LL82:{
const char*_tmp3D2;Cyc_Absyndump_dump(((_tmp3D2="unsigned char",_tag_dyneither(
_tmp3D2,sizeof(char),14))));}return;_LL83: {struct Cyc_Absyn_IntType_struct*
_tmp85=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp85->tag != 6)goto _LL85;
else{_tmp86=_tmp85->f1;if(_tmp86 != Cyc_Absyn_None)goto _LL85;_tmp87=_tmp85->f2;
if(_tmp87 != Cyc_Absyn_Short_sz)goto _LL85;}}_LL84: goto _LL86;_LL85: {struct Cyc_Absyn_IntType_struct*
_tmp88=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp88->tag != 6)goto _LL87;
else{_tmp89=_tmp88->f1;if(_tmp89 != Cyc_Absyn_Signed)goto _LL87;_tmp8A=_tmp88->f2;
if(_tmp8A != Cyc_Absyn_Short_sz)goto _LL87;}}_LL86:{const char*_tmp3D3;Cyc_Absyndump_dump(((
_tmp3D3="short",_tag_dyneither(_tmp3D3,sizeof(char),6))));}return;_LL87: {struct
Cyc_Absyn_IntType_struct*_tmp8B=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(
_tmp8B->tag != 6)goto _LL89;else{_tmp8C=_tmp8B->f1;if(_tmp8C != Cyc_Absyn_Unsigned)
goto _LL89;_tmp8D=_tmp8B->f2;if(_tmp8D != Cyc_Absyn_Short_sz)goto _LL89;}}_LL88:{
const char*_tmp3D4;Cyc_Absyndump_dump(((_tmp3D4="unsigned short",_tag_dyneither(
_tmp3D4,sizeof(char),15))));}return;_LL89: {struct Cyc_Absyn_IntType_struct*
_tmp8E=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp8E->tag != 6)goto _LL8B;
else{_tmp8F=_tmp8E->f1;if(_tmp8F != Cyc_Absyn_Unsigned)goto _LL8B;_tmp90=_tmp8E->f2;
if(_tmp90 != Cyc_Absyn_Int_sz)goto _LL8B;}}_LL8A:{const char*_tmp3D5;Cyc_Absyndump_dump(((
_tmp3D5="unsigned int",_tag_dyneither(_tmp3D5,sizeof(char),13))));}return;_LL8B: {
struct Cyc_Absyn_IntType_struct*_tmp91=(struct Cyc_Absyn_IntType_struct*)_tmp57;
if(_tmp91->tag != 6)goto _LL8D;else{_tmp92=_tmp91->f1;if(_tmp92 != Cyc_Absyn_Unsigned)
goto _LL8D;_tmp93=_tmp91->f2;if(_tmp93 != Cyc_Absyn_Long_sz)goto _LL8D;}}_LL8C:{
const char*_tmp3D6;Cyc_Absyndump_dump(((_tmp3D6="unsigned long",_tag_dyneither(
_tmp3D6,sizeof(char),14))));}return;_LL8D: {struct Cyc_Absyn_IntType_struct*
_tmp94=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp94->tag != 6)goto _LL8F;
else{_tmp95=_tmp94->f1;if(_tmp95 != Cyc_Absyn_None)goto _LL8F;_tmp96=_tmp94->f2;
if(_tmp96 != Cyc_Absyn_LongLong_sz)goto _LL8F;}}_LL8E: goto _LL90;_LL8F: {struct Cyc_Absyn_IntType_struct*
_tmp97=(struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp97->tag != 6)goto _LL91;
else{_tmp98=_tmp97->f1;if(_tmp98 != Cyc_Absyn_Signed)goto _LL91;_tmp99=_tmp97->f2;
if(_tmp99 != Cyc_Absyn_LongLong_sz)goto _LL91;}}_LL90: switch(Cyc_Cyclone_c_compiler){
case Cyc_Cyclone_Gcc_c: _LLBF:{const char*_tmp3D7;Cyc_Absyndump_dump(((_tmp3D7="long long",
_tag_dyneither(_tmp3D7,sizeof(char),10))));}return;case Cyc_Cyclone_Vc_c: _LLC0:{
const char*_tmp3D8;Cyc_Absyndump_dump(((_tmp3D8="__int64",_tag_dyneither(_tmp3D8,
sizeof(char),8))));}return;}_LL91: {struct Cyc_Absyn_IntType_struct*_tmp9A=(
struct Cyc_Absyn_IntType_struct*)_tmp57;if(_tmp9A->tag != 6)goto _LL93;else{_tmp9B=
_tmp9A->f1;if(_tmp9B != Cyc_Absyn_Unsigned)goto _LL93;_tmp9C=_tmp9A->f2;if(_tmp9C
!= Cyc_Absyn_LongLong_sz)goto _LL93;}}_LL92: switch(Cyc_Cyclone_c_compiler){case
Cyc_Cyclone_Vc_c: _LLC2:{const char*_tmp3D9;Cyc_Absyndump_dump(((_tmp3D9="unsigned __int64",
_tag_dyneither(_tmp3D9,sizeof(char),17))));}return;case Cyc_Cyclone_Gcc_c: _LLC3:{
const char*_tmp3DA;Cyc_Absyndump_dump(((_tmp3DA="unsigned long long",
_tag_dyneither(_tmp3DA,sizeof(char),19))));}return;}_LL93: {struct Cyc_Absyn_FloatType_struct*
_tmp9D=(struct Cyc_Absyn_FloatType_struct*)_tmp57;if(_tmp9D->tag != 7)goto _LL95;}
_LL94:{const char*_tmp3DB;Cyc_Absyndump_dump(((_tmp3DB="float",_tag_dyneither(
_tmp3DB,sizeof(char),6))));}return;_LL95: {struct Cyc_Absyn_DoubleType_struct*
_tmp9E=(struct Cyc_Absyn_DoubleType_struct*)_tmp57;if(_tmp9E->tag != 8)goto _LL97;
else{_tmp9F=_tmp9E->f1;}}_LL96: if(_tmp9F){const char*_tmp3DC;Cyc_Absyndump_dump(((
_tmp3DC="long double",_tag_dyneither(_tmp3DC,sizeof(char),12))));}else{const char*
_tmp3DD;Cyc_Absyndump_dump(((_tmp3DD="double",_tag_dyneither(_tmp3DD,sizeof(char),
7))));}return;_LL97: {struct Cyc_Absyn_TupleType_struct*_tmpA0=(struct Cyc_Absyn_TupleType_struct*)
_tmp57;if(_tmpA0->tag != 11)goto _LL99;else{_tmpA1=_tmpA0->f1;}}_LL98: Cyc_Absyndump_dump_char((
int)'$');Cyc_Absyndump_dumpargs(_tmpA1);return;_LL99: {struct Cyc_Absyn_AggrType_struct*
_tmpA2=(struct Cyc_Absyn_AggrType_struct*)_tmp57;if(_tmpA2->tag != 12)goto _LL9B;
else{_tmpA3=_tmpA2->f1;_tmpA4=_tmpA3.aggr_info;_tmpA5=_tmpA3.targs;}}_LL9A: {
enum Cyc_Absyn_AggrKind _tmpF0;struct _tuple0*_tmpF1;struct _tuple9 _tmpEF=Cyc_Absyn_aggr_kinded_name(
_tmpA4);_tmpF0=_tmpEF.f1;_tmpF1=_tmpEF.f2;Cyc_Absyndump_dumpaggr_kind(_tmpF0);
Cyc_Absyndump_dumpqvar(_tmpF1);Cyc_Absyndump_dumptps(_tmpA5);return;}_LL9B: {
struct Cyc_Absyn_AnonAggrType_struct*_tmpA6=(struct Cyc_Absyn_AnonAggrType_struct*)
_tmp57;if(_tmpA6->tag != 13)goto _LL9D;else{_tmpA7=_tmpA6->f1;_tmpA8=_tmpA6->f2;}}
_LL9C: Cyc_Absyndump_dumpaggr_kind(_tmpA7);Cyc_Absyndump_dump_char((int)'{');Cyc_Absyndump_dumpaggrfields(
_tmpA8);Cyc_Absyndump_dump_char((int)'}');return;_LL9D: {struct Cyc_Absyn_EnumType_struct*
_tmpA9=(struct Cyc_Absyn_EnumType_struct*)_tmp57;if(_tmpA9->tag != 14)goto _LL9F;
else{_tmpAA=_tmpA9->f1;}}_LL9E:{const char*_tmp3DE;Cyc_Absyndump_dump(((_tmp3DE="enum ",
_tag_dyneither(_tmp3DE,sizeof(char),6))));}Cyc_Absyndump_dumpqvar(_tmpAA);
return;_LL9F: {struct Cyc_Absyn_AnonEnumType_struct*_tmpAB=(struct Cyc_Absyn_AnonEnumType_struct*)
_tmp57;if(_tmpAB->tag != 15)goto _LLA1;else{_tmpAC=_tmpAB->f1;}}_LLA0:{const char*
_tmp3DF;Cyc_Absyndump_dump(((_tmp3DF="enum {",_tag_dyneither(_tmp3DF,sizeof(char),
7))));}Cyc_Absyndump_dumpenumfields(_tmpAC);{const char*_tmp3E0;Cyc_Absyndump_dump(((
_tmp3E0="}",_tag_dyneither(_tmp3E0,sizeof(char),2))));}return;_LLA1: {struct Cyc_Absyn_TypedefType_struct*
_tmpAD=(struct Cyc_Absyn_TypedefType_struct*)_tmp57;if(_tmpAD->tag != 18)goto _LLA3;
else{_tmpAE=_tmpAD->f1;_tmpAF=_tmpAD->f2;}}_LLA2:(Cyc_Absyndump_dumpqvar(_tmpAE),
Cyc_Absyndump_dumptps(_tmpAF));return;_LLA3: {struct Cyc_Absyn_ValueofType_struct*
_tmpB0=(struct Cyc_Absyn_ValueofType_struct*)_tmp57;if(_tmpB0->tag != 19)goto _LLA5;
else{_tmpB1=_tmpB0->f1;}}_LLA4:{const char*_tmp3E1;Cyc_Absyndump_dump(((_tmp3E1="valueof_t(",
_tag_dyneither(_tmp3E1,sizeof(char),11))));}Cyc_Absyndump_dumpexp(_tmpB1);{const
char*_tmp3E2;Cyc_Absyndump_dump(((_tmp3E2=")",_tag_dyneither(_tmp3E2,sizeof(char),
2))));}return;_LLA5: {struct Cyc_Absyn_RgnHandleType_struct*_tmpB2=(struct Cyc_Absyn_RgnHandleType_struct*)
_tmp57;if(_tmpB2->tag != 16)goto _LLA7;else{_tmpB3=(void*)_tmpB2->f1;}}_LLA6:{
const char*_tmp3E3;Cyc_Absyndump_dump(((_tmp3E3="region_t<",_tag_dyneither(
_tmp3E3,sizeof(char),10))));}Cyc_Absyndump_dumprgn(_tmpB3);{const char*_tmp3E4;
Cyc_Absyndump_dump(((_tmp3E4=">",_tag_dyneither(_tmp3E4,sizeof(char),2))));}
return;_LLA7: {struct Cyc_Absyn_DynRgnType_struct*_tmpB4=(struct Cyc_Absyn_DynRgnType_struct*)
_tmp57;if(_tmpB4->tag != 17)goto _LLA9;else{_tmpB5=(void*)_tmpB4->f1;_tmpB6=(void*)
_tmpB4->f2;}}_LLA8:{const char*_tmp3E5;Cyc_Absyndump_dump(((_tmp3E5="dynregion_t<",
_tag_dyneither(_tmp3E5,sizeof(char),13))));}Cyc_Absyndump_dumprgn(_tmpB5);{const
char*_tmp3E6;Cyc_Absyndump_dump(((_tmp3E6=",",_tag_dyneither(_tmp3E6,sizeof(char),
2))));}Cyc_Absyndump_dumprgn(_tmpB6);{const char*_tmp3E7;Cyc_Absyndump_dump(((
_tmp3E7=">",_tag_dyneither(_tmp3E7,sizeof(char),2))));}return;_LLA9: {struct Cyc_Absyn_TagType_struct*
_tmpB7=(struct Cyc_Absyn_TagType_struct*)_tmp57;if(_tmpB7->tag != 20)goto _LLAB;
else{_tmpB8=(void*)_tmpB7->f1;}}_LLAA:{const char*_tmp3E8;Cyc_Absyndump_dump(((
_tmp3E8="tag_t<",_tag_dyneither(_tmp3E8,sizeof(char),7))));}Cyc_Absyndump_dumpntyp(
_tmpB8);{const char*_tmp3E9;Cyc_Absyndump_dump(((_tmp3E9=">",_tag_dyneither(
_tmp3E9,sizeof(char),2))));}return;_LLAB: {struct Cyc_Absyn_UniqueRgn_struct*
_tmpB9=(struct Cyc_Absyn_UniqueRgn_struct*)_tmp57;if(_tmpB9->tag != 22)goto _LLAD;}
_LLAC:{const char*_tmp3EA;Cyc_Absyndump_dump(((_tmp3EA="`U",_tag_dyneither(
_tmp3EA,sizeof(char),3))));}goto _LL62;_LLAD: {struct Cyc_Absyn_HeapRgn_struct*
_tmpBA=(struct Cyc_Absyn_HeapRgn_struct*)_tmp57;if(_tmpBA->tag != 21)goto _LLAF;}
_LLAE: goto _LLB0;_LLAF: {struct Cyc_Absyn_AccessEff_struct*_tmpBB=(struct Cyc_Absyn_AccessEff_struct*)
_tmp57;if(_tmpBB->tag != 23)goto _LLB1;}_LLB0: goto _LLB2;_LLB1: {struct Cyc_Absyn_RgnsEff_struct*
_tmpBC=(struct Cyc_Absyn_RgnsEff_struct*)_tmp57;if(_tmpBC->tag != 25)goto _LLB3;}
_LLB2: goto _LLB4;_LLB3: {struct Cyc_Absyn_JoinEff_struct*_tmpBD=(struct Cyc_Absyn_JoinEff_struct*)
_tmp57;if(_tmpBD->tag != 24)goto _LL62;}_LLB4: return;_LL62:;}void Cyc_Absyndump_dumpvaropt(
struct Cyc_Core_Opt*vo);void Cyc_Absyndump_dumpvaropt(struct Cyc_Core_Opt*vo){if(vo
!= 0)Cyc_Absyndump_dump_str((struct _dyneither_ptr*)vo->v);}void Cyc_Absyndump_dumpfunarg(
struct _tuple7*t);void Cyc_Absyndump_dumpfunarg(struct _tuple7*t){((void(*)(struct
Cyc_Absyn_Tqual,void*,void(*f)(struct Cyc_Core_Opt*),struct Cyc_Core_Opt*))Cyc_Absyndump_dumptqtd)((*
t).f2,(*t).f3,Cyc_Absyndump_dumpvaropt,(*t).f1);}struct _tuple15{void*f1;void*f2;
};void Cyc_Absyndump_dump_rgncmp(struct _tuple15*cmp);void Cyc_Absyndump_dump_rgncmp(
struct _tuple15*cmp){struct _tuple15 _tmp100;void*_tmp101;void*_tmp102;struct
_tuple15*_tmpFF=cmp;_tmp100=*_tmpFF;_tmp101=_tmp100.f1;_tmp102=_tmp100.f2;Cyc_Absyndump_dumpeff(
_tmp101);Cyc_Absyndump_dump_char((int)'>');Cyc_Absyndump_dumprgn(_tmp102);}void
Cyc_Absyndump_dump_rgnpo(struct Cyc_List_List*rgn_po);void Cyc_Absyndump_dump_rgnpo(
struct Cyc_List_List*rgn_po){const char*_tmp3EB;((void(*)(void(*f)(struct _tuple15*),
struct Cyc_List_List*l,struct _dyneither_ptr sep))Cyc_Absyndump_dump_sep)(Cyc_Absyndump_dump_rgncmp,
rgn_po,((_tmp3EB=",",_tag_dyneither(_tmp3EB,sizeof(char),2))));}void Cyc_Absyndump_dumpfunargs(
struct Cyc_List_List*args,int c_varargs,struct Cyc_Absyn_VarargInfo*cyc_varargs,
struct Cyc_Core_Opt*effopt,struct Cyc_List_List*rgn_po);void Cyc_Absyndump_dumpfunargs(
struct Cyc_List_List*args,int c_varargs,struct Cyc_Absyn_VarargInfo*cyc_varargs,
struct Cyc_Core_Opt*effopt,struct Cyc_List_List*rgn_po){Cyc_Absyndump_dump_char((
int)'(');for(0;args != 0;args=args->tl){Cyc_Absyndump_dumpfunarg((struct _tuple7*)
args->hd);if((args->tl != 0  || c_varargs) || cyc_varargs != 0)Cyc_Absyndump_dump_char((
int)',');}if(c_varargs){const char*_tmp3EC;Cyc_Absyndump_dump(((_tmp3EC="...",
_tag_dyneither(_tmp3EC,sizeof(char),4))));}else{if(cyc_varargs != 0){struct
_tuple7*_tmp3ED;struct _tuple7*_tmp105=(_tmp3ED=_cycalloc(sizeof(*_tmp3ED)),((
_tmp3ED->f1=cyc_varargs->name,((_tmp3ED->f2=cyc_varargs->tq,((_tmp3ED->f3=
cyc_varargs->type,_tmp3ED)))))));{const char*_tmp3EE;Cyc_Absyndump_dump(((_tmp3EE="...",
_tag_dyneither(_tmp3EE,sizeof(char),4))));}if(cyc_varargs->inject){const char*
_tmp3EF;Cyc_Absyndump_dump(((_tmp3EF=" inject ",_tag_dyneither(_tmp3EF,sizeof(
char),9))));}Cyc_Absyndump_dumpfunarg(_tmp105);}}if(effopt != 0){Cyc_Absyndump_dump_semi();
Cyc_Absyndump_dumpeff((void*)effopt->v);}if(rgn_po != 0){Cyc_Absyndump_dump_char((
int)':');Cyc_Absyndump_dump_rgnpo(rgn_po);}Cyc_Absyndump_dump_char((int)')');}
void Cyc_Absyndump_dumptyp(void*t);void Cyc_Absyndump_dumptyp(void*t){((void(*)(
struct Cyc_Absyn_Tqual,void*,void(*f)(int),int))Cyc_Absyndump_dumptqtd)(Cyc_Absyn_empty_tqual(
0),t,(void(*)(int x))Cyc_Absyndump_ignore,0);}void Cyc_Absyndump_dumpdesignator(
void*d);void Cyc_Absyndump_dumpdesignator(void*d){void*_tmp109=d;struct Cyc_Absyn_Exp*
_tmp10B;struct _dyneither_ptr*_tmp10D;_LLC6: {struct Cyc_Absyn_ArrayElement_struct*
_tmp10A=(struct Cyc_Absyn_ArrayElement_struct*)_tmp109;if(_tmp10A->tag != 0)goto
_LLC8;else{_tmp10B=_tmp10A->f1;}}_LLC7:{const char*_tmp3F0;Cyc_Absyndump_dump(((
_tmp3F0=".[",_tag_dyneither(_tmp3F0,sizeof(char),3))));}Cyc_Absyndump_dumpexp(
_tmp10B);Cyc_Absyndump_dump_char((int)']');goto _LLC5;_LLC8: {struct Cyc_Absyn_FieldName_struct*
_tmp10C=(struct Cyc_Absyn_FieldName_struct*)_tmp109;if(_tmp10C->tag != 1)goto _LLC5;
else{_tmp10D=_tmp10C->f1;}}_LLC9: Cyc_Absyndump_dump_char((int)'.');Cyc_Absyndump_dump_nospace(*
_tmp10D);goto _LLC5;_LLC5:;}struct _tuple16{struct Cyc_List_List*f1;struct Cyc_Absyn_Exp*
f2;};void Cyc_Absyndump_dumpde(struct _tuple16*de);void Cyc_Absyndump_dumpde(struct
_tuple16*de){{const char*_tmp3F3;const char*_tmp3F2;const char*_tmp3F1;((void(*)(
void(*f)(void*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(Cyc_Absyndump_dumpdesignator,(*
de).f1,((_tmp3F1="",_tag_dyneither(_tmp3F1,sizeof(char),1))),((_tmp3F2="=",
_tag_dyneither(_tmp3F2,sizeof(char),2))),((_tmp3F3="=",_tag_dyneither(_tmp3F3,
sizeof(char),2))));}Cyc_Absyndump_dumpexp((*de).f2);}void Cyc_Absyndump_dumpexps_prec(
int inprec,struct Cyc_List_List*es);void Cyc_Absyndump_dumpexps_prec(int inprec,
struct Cyc_List_List*es){const char*_tmp3F6;const char*_tmp3F5;const char*_tmp3F4;((
void(*)(void(*f)(int,struct Cyc_Absyn_Exp*),int env,struct Cyc_List_List*l,struct
_dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group_c)(
Cyc_Absyndump_dumpexp_prec,inprec,es,((_tmp3F4="",_tag_dyneither(_tmp3F4,sizeof(
char),1))),((_tmp3F5="",_tag_dyneither(_tmp3F5,sizeof(char),1))),((_tmp3F6=",",
_tag_dyneither(_tmp3F6,sizeof(char),2))));}void Cyc_Absyndump_dumpexp_prec(int
inprec,struct Cyc_Absyn_Exp*e);void Cyc_Absyndump_dumpexp_prec(int inprec,struct Cyc_Absyn_Exp*
e){int myprec=Cyc_Absynpp_exp_prec(e);if(inprec >= myprec){const char*_tmp3F7;Cyc_Absyndump_dump_nospace(((
_tmp3F7="(",_tag_dyneither(_tmp3F7,sizeof(char),2))));}{void*_tmp116=e->r;union
Cyc_Absyn_Cnst _tmp118;struct _tuple3 _tmp119;enum Cyc_Absyn_Sign _tmp11A;char
_tmp11B;union Cyc_Absyn_Cnst _tmp11D;struct _tuple4 _tmp11E;enum Cyc_Absyn_Sign
_tmp11F;short _tmp120;union Cyc_Absyn_Cnst _tmp122;struct _tuple5 _tmp123;enum Cyc_Absyn_Sign
_tmp124;int _tmp125;union Cyc_Absyn_Cnst _tmp127;struct _tuple5 _tmp128;enum Cyc_Absyn_Sign
_tmp129;int _tmp12A;union Cyc_Absyn_Cnst _tmp12C;struct _tuple5 _tmp12D;enum Cyc_Absyn_Sign
_tmp12E;int _tmp12F;union Cyc_Absyn_Cnst _tmp131;struct _tuple6 _tmp132;enum Cyc_Absyn_Sign
_tmp133;long long _tmp134;union Cyc_Absyn_Cnst _tmp136;struct _dyneither_ptr _tmp137;
union Cyc_Absyn_Cnst _tmp139;int _tmp13A;union Cyc_Absyn_Cnst _tmp13C;struct
_dyneither_ptr _tmp13D;struct _tuple0*_tmp13F;struct _tuple0*_tmp141;enum Cyc_Absyn_Primop
_tmp143;struct Cyc_List_List*_tmp144;struct Cyc_Absyn_Exp*_tmp146;struct Cyc_Core_Opt*
_tmp147;struct Cyc_Absyn_Exp*_tmp148;struct Cyc_Absyn_Exp*_tmp14A;enum Cyc_Absyn_Incrementor
_tmp14B;struct Cyc_Absyn_Exp*_tmp14D;enum Cyc_Absyn_Incrementor _tmp14E;struct Cyc_Absyn_Exp*
_tmp150;enum Cyc_Absyn_Incrementor _tmp151;struct Cyc_Absyn_Exp*_tmp153;enum Cyc_Absyn_Incrementor
_tmp154;struct Cyc_Absyn_Exp*_tmp156;struct Cyc_Absyn_Exp*_tmp157;struct Cyc_Absyn_Exp*
_tmp158;struct Cyc_Absyn_Exp*_tmp15A;struct Cyc_Absyn_Exp*_tmp15B;struct Cyc_Absyn_Exp*
_tmp15D;struct Cyc_Absyn_Exp*_tmp15E;struct Cyc_Absyn_Exp*_tmp160;struct Cyc_Absyn_Exp*
_tmp161;struct Cyc_Absyn_Exp*_tmp163;struct Cyc_List_List*_tmp164;struct Cyc_Absyn_Exp*
_tmp166;struct Cyc_List_List*_tmp167;struct Cyc_Absyn_Exp*_tmp169;struct Cyc_Absyn_Exp*
_tmp16B;struct Cyc_Absyn_Exp*_tmp16D;void*_tmp16F;struct Cyc_Absyn_Exp*_tmp170;
struct Cyc_Absyn_Exp*_tmp172;struct Cyc_Absyn_Exp*_tmp174;struct Cyc_Absyn_Exp*
_tmp175;void*_tmp177;struct Cyc_Absyn_Exp*_tmp179;void*_tmp17B;struct Cyc_Absyn_Exp*
_tmp17D;struct _dyneither_ptr*_tmp17E;void*_tmp180;void*_tmp181;struct
_dyneither_ptr*_tmp183;void*_tmp185;void*_tmp186;unsigned int _tmp188;struct Cyc_Absyn_Exp*
_tmp18A;struct Cyc_Absyn_Exp*_tmp18C;struct _dyneither_ptr*_tmp18D;struct Cyc_Absyn_Exp*
_tmp18F;struct _dyneither_ptr*_tmp190;struct Cyc_Absyn_Exp*_tmp192;struct Cyc_Absyn_Exp*
_tmp193;struct Cyc_List_List*_tmp195;struct _tuple7*_tmp197;struct Cyc_List_List*
_tmp198;struct Cyc_List_List*_tmp19A;struct Cyc_Absyn_Vardecl*_tmp19C;struct Cyc_Absyn_Exp*
_tmp19D;struct Cyc_Absyn_Exp*_tmp19E;struct _tuple0*_tmp1A0;struct Cyc_List_List*
_tmp1A1;struct Cyc_List_List*_tmp1A2;struct Cyc_List_List*_tmp1A4;struct Cyc_List_List*
_tmp1A6;struct Cyc_Absyn_Datatypefield*_tmp1A7;struct _tuple0*_tmp1A9;struct
_tuple0*_tmp1AB;struct Cyc_Absyn_MallocInfo _tmp1AD;int _tmp1AE;struct Cyc_Absyn_Exp*
_tmp1AF;void**_tmp1B0;struct Cyc_Absyn_Exp*_tmp1B1;struct Cyc_Absyn_Exp*_tmp1B3;
struct Cyc_Absyn_Exp*_tmp1B4;struct Cyc_Core_Opt*_tmp1B6;struct Cyc_List_List*
_tmp1B7;struct Cyc_Absyn_Stmt*_tmp1B9;_LLCB: {struct Cyc_Absyn_Const_e_struct*
_tmp117=(struct Cyc_Absyn_Const_e_struct*)_tmp116;if(_tmp117->tag != 0)goto _LLCD;
else{_tmp118=_tmp117->f1;if((_tmp118.Char_c).tag != 2)goto _LLCD;_tmp119=(struct
_tuple3)(_tmp118.Char_c).val;_tmp11A=_tmp119.f1;_tmp11B=_tmp119.f2;}}_LLCC: Cyc_Absyndump_dump_char((
int)'\'');Cyc_Absyndump_dump_nospace(Cyc_Absynpp_char_escape(_tmp11B));Cyc_Absyndump_dump_char((
int)'\'');goto _LLCA;_LLCD: {struct Cyc_Absyn_Const_e_struct*_tmp11C=(struct Cyc_Absyn_Const_e_struct*)
_tmp116;if(_tmp11C->tag != 0)goto _LLCF;else{_tmp11D=_tmp11C->f1;if((_tmp11D.Short_c).tag
!= 3)goto _LLCF;_tmp11E=(struct _tuple4)(_tmp11D.Short_c).val;_tmp11F=_tmp11E.f1;
_tmp120=_tmp11E.f2;}}_LLCE:{const char*_tmp3FB;void*_tmp3FA[1];struct Cyc_Int_pa_struct
_tmp3F9;Cyc_Absyndump_dump((struct _dyneither_ptr)((_tmp3F9.tag=1,((_tmp3F9.f1=(
unsigned long)((int)_tmp120),((_tmp3FA[0]=& _tmp3F9,Cyc_aprintf(((_tmp3FB="%d",
_tag_dyneither(_tmp3FB,sizeof(char),3))),_tag_dyneither(_tmp3FA,sizeof(void*),1)))))))));}
goto _LLCA;_LLCF: {struct Cyc_Absyn_Const_e_struct*_tmp121=(struct Cyc_Absyn_Const_e_struct*)
_tmp116;if(_tmp121->tag != 0)goto _LLD1;else{_tmp122=_tmp121->f1;if((_tmp122.Int_c).tag
!= 4)goto _LLD1;_tmp123=(struct _tuple5)(_tmp122.Int_c).val;_tmp124=_tmp123.f1;if(
_tmp124 != Cyc_Absyn_None)goto _LLD1;_tmp125=_tmp123.f2;}}_LLD0: _tmp12A=_tmp125;
goto _LLD2;_LLD1: {struct Cyc_Absyn_Const_e_struct*_tmp126=(struct Cyc_Absyn_Const_e_struct*)
_tmp116;if(_tmp126->tag != 0)goto _LLD3;else{_tmp127=_tmp126->f1;if((_tmp127.Int_c).tag
!= 4)goto _LLD3;_tmp128=(struct _tuple5)(_tmp127.Int_c).val;_tmp129=_tmp128.f1;if(
_tmp129 != Cyc_Absyn_Signed)goto _LLD3;_tmp12A=_tmp128.f2;}}_LLD2:{const char*
_tmp3FF;void*_tmp3FE[1];struct Cyc_Int_pa_struct _tmp3FD;Cyc_Absyndump_dump((
struct _dyneither_ptr)((_tmp3FD.tag=1,((_tmp3FD.f1=(unsigned long)_tmp12A,((
_tmp3FE[0]=& _tmp3FD,Cyc_aprintf(((_tmp3FF="%d",_tag_dyneither(_tmp3FF,sizeof(
char),3))),_tag_dyneither(_tmp3FE,sizeof(void*),1)))))))));}goto _LLCA;_LLD3: {
struct Cyc_Absyn_Const_e_struct*_tmp12B=(struct Cyc_Absyn_Const_e_struct*)_tmp116;
if(_tmp12B->tag != 0)goto _LLD5;else{_tmp12C=_tmp12B->f1;if((_tmp12C.Int_c).tag != 
4)goto _LLD5;_tmp12D=(struct _tuple5)(_tmp12C.Int_c).val;_tmp12E=_tmp12D.f1;if(
_tmp12E != Cyc_Absyn_Unsigned)goto _LLD5;_tmp12F=_tmp12D.f2;}}_LLD4:{const char*
_tmp403;void*_tmp402[1];struct Cyc_Int_pa_struct _tmp401;Cyc_Absyndump_dump((
struct _dyneither_ptr)((_tmp401.tag=1,((_tmp401.f1=(unsigned int)_tmp12F,((
_tmp402[0]=& _tmp401,Cyc_aprintf(((_tmp403="%u",_tag_dyneither(_tmp403,sizeof(
char),3))),_tag_dyneither(_tmp402,sizeof(void*),1)))))))));}goto _LLCA;_LLD5: {
struct Cyc_Absyn_Const_e_struct*_tmp130=(struct Cyc_Absyn_Const_e_struct*)_tmp116;
if(_tmp130->tag != 0)goto _LLD7;else{_tmp131=_tmp130->f1;if((_tmp131.LongLong_c).tag
!= 5)goto _LLD7;_tmp132=(struct _tuple6)(_tmp131.LongLong_c).val;_tmp133=_tmp132.f1;
_tmp134=_tmp132.f2;}}_LLD6:{const char*_tmp404;Cyc_Absyndump_dump(((_tmp404="<<FIX LONG LONG CONSTANT>>",
_tag_dyneither(_tmp404,sizeof(char),27))));}goto _LLCA;_LLD7: {struct Cyc_Absyn_Const_e_struct*
_tmp135=(struct Cyc_Absyn_Const_e_struct*)_tmp116;if(_tmp135->tag != 0)goto _LLD9;
else{_tmp136=_tmp135->f1;if((_tmp136.Float_c).tag != 6)goto _LLD9;_tmp137=(struct
_dyneither_ptr)(_tmp136.Float_c).val;}}_LLD8: Cyc_Absyndump_dump(_tmp137);goto
_LLCA;_LLD9: {struct Cyc_Absyn_Const_e_struct*_tmp138=(struct Cyc_Absyn_Const_e_struct*)
_tmp116;if(_tmp138->tag != 0)goto _LLDB;else{_tmp139=_tmp138->f1;if((_tmp139.Null_c).tag
!= 1)goto _LLDB;_tmp13A=(int)(_tmp139.Null_c).val;}}_LLDA:{const char*_tmp405;Cyc_Absyndump_dump(((
_tmp405="NULL",_tag_dyneither(_tmp405,sizeof(char),5))));}goto _LLCA;_LLDB: {
struct Cyc_Absyn_Const_e_struct*_tmp13B=(struct Cyc_Absyn_Const_e_struct*)_tmp116;
if(_tmp13B->tag != 0)goto _LLDD;else{_tmp13C=_tmp13B->f1;if((_tmp13C.String_c).tag
!= 7)goto _LLDD;_tmp13D=(struct _dyneither_ptr)(_tmp13C.String_c).val;}}_LLDC: Cyc_Absyndump_dump_char((
int)'"');Cyc_Absyndump_dump_nospace(Cyc_Absynpp_string_escape(_tmp13D));Cyc_Absyndump_dump_char((
int)'"');goto _LLCA;_LLDD: {struct Cyc_Absyn_UnknownId_e_struct*_tmp13E=(struct Cyc_Absyn_UnknownId_e_struct*)
_tmp116;if(_tmp13E->tag != 2)goto _LLDF;else{_tmp13F=_tmp13E->f1;}}_LLDE: _tmp141=
_tmp13F;goto _LLE0;_LLDF: {struct Cyc_Absyn_Var_e_struct*_tmp140=(struct Cyc_Absyn_Var_e_struct*)
_tmp116;if(_tmp140->tag != 1)goto _LLE1;else{_tmp141=_tmp140->f1;}}_LLE0: Cyc_Absyndump_dumpqvar(
_tmp141);goto _LLCA;_LLE1: {struct Cyc_Absyn_Primop_e_struct*_tmp142=(struct Cyc_Absyn_Primop_e_struct*)
_tmp116;if(_tmp142->tag != 3)goto _LLE3;else{_tmp143=_tmp142->f1;_tmp144=_tmp142->f2;}}
_LLE2: {struct _dyneither_ptr _tmp1C5=Cyc_Absynpp_prim2str(_tmp143);switch(((int(*)(
struct Cyc_List_List*x))Cyc_List_length)(_tmp144)){case 1: _LL133: if(_tmp143 == (
enum Cyc_Absyn_Primop)Cyc_Absyn_Numelts){{const char*_tmp406;Cyc_Absyndump_dump(((
_tmp406="numelts(",_tag_dyneither(_tmp406,sizeof(char),9))));}Cyc_Absyndump_dumpexp((
struct Cyc_Absyn_Exp*)((struct Cyc_List_List*)_check_null(_tmp144))->hd);{const
char*_tmp407;Cyc_Absyndump_dump(((_tmp407=")",_tag_dyneither(_tmp407,sizeof(char),
2))));};}else{Cyc_Absyndump_dump(_tmp1C5);Cyc_Absyndump_dumpexp_prec(myprec,(
struct Cyc_Absyn_Exp*)((struct Cyc_List_List*)_check_null(_tmp144))->hd);}break;
case 2: _LL134: Cyc_Absyndump_dumpexp_prec(myprec,(struct Cyc_Absyn_Exp*)((struct Cyc_List_List*)
_check_null(_tmp144))->hd);Cyc_Absyndump_dump(_tmp1C5);Cyc_Absyndump_dump_char((
int)' ');Cyc_Absyndump_dumpexp_prec(myprec,(struct Cyc_Absyn_Exp*)((struct Cyc_List_List*)
_check_null(_tmp144->tl))->hd);break;default: _LL135: {struct Cyc_Core_Failure_struct
_tmp40D;const char*_tmp40C;struct Cyc_Core_Failure_struct*_tmp40B;(int)_throw((
void*)((_tmp40B=_cycalloc(sizeof(*_tmp40B)),((_tmp40B[0]=((_tmp40D.tag=Cyc_Core_Failure,((
_tmp40D.f1=((_tmp40C="Absyndump -- Bad number of arguments to primop",
_tag_dyneither(_tmp40C,sizeof(char),47))),_tmp40D)))),_tmp40B)))));}}goto _LLCA;}
_LLE3: {struct Cyc_Absyn_AssignOp_e_struct*_tmp145=(struct Cyc_Absyn_AssignOp_e_struct*)
_tmp116;if(_tmp145->tag != 4)goto _LLE5;else{_tmp146=_tmp145->f1;_tmp147=_tmp145->f2;
_tmp148=_tmp145->f3;}}_LLE4: Cyc_Absyndump_dumpexp_prec(myprec,_tmp146);if(
_tmp147 != 0)Cyc_Absyndump_dump(Cyc_Absynpp_prim2str((enum Cyc_Absyn_Primop)
_tmp147->v));{const char*_tmp40E;Cyc_Absyndump_dump_nospace(((_tmp40E="=",
_tag_dyneither(_tmp40E,sizeof(char),2))));}Cyc_Absyndump_dumpexp_prec(myprec,
_tmp148);goto _LLCA;_LLE5: {struct Cyc_Absyn_Increment_e_struct*_tmp149=(struct Cyc_Absyn_Increment_e_struct*)
_tmp116;if(_tmp149->tag != 5)goto _LLE7;else{_tmp14A=_tmp149->f1;_tmp14B=_tmp149->f2;
if(_tmp14B != Cyc_Absyn_PreInc)goto _LLE7;}}_LLE6:{const char*_tmp40F;Cyc_Absyndump_dump(((
_tmp40F="++",_tag_dyneither(_tmp40F,sizeof(char),3))));}Cyc_Absyndump_dumpexp_prec(
myprec,_tmp14A);goto _LLCA;_LLE7: {struct Cyc_Absyn_Increment_e_struct*_tmp14C=(
struct Cyc_Absyn_Increment_e_struct*)_tmp116;if(_tmp14C->tag != 5)goto _LLE9;else{
_tmp14D=_tmp14C->f1;_tmp14E=_tmp14C->f2;if(_tmp14E != Cyc_Absyn_PreDec)goto _LLE9;}}
_LLE8:{const char*_tmp410;Cyc_Absyndump_dump(((_tmp410="--",_tag_dyneither(
_tmp410,sizeof(char),3))));}Cyc_Absyndump_dumpexp_prec(myprec,_tmp14D);goto _LLCA;
_LLE9: {struct Cyc_Absyn_Increment_e_struct*_tmp14F=(struct Cyc_Absyn_Increment_e_struct*)
_tmp116;if(_tmp14F->tag != 5)goto _LLEB;else{_tmp150=_tmp14F->f1;_tmp151=_tmp14F->f2;
if(_tmp151 != Cyc_Absyn_PostInc)goto _LLEB;}}_LLEA: Cyc_Absyndump_dumpexp_prec(
myprec,_tmp150);{const char*_tmp411;Cyc_Absyndump_dump(((_tmp411="++",
_tag_dyneither(_tmp411,sizeof(char),3))));}goto _LLCA;_LLEB: {struct Cyc_Absyn_Increment_e_struct*
_tmp152=(struct Cyc_Absyn_Increment_e_struct*)_tmp116;if(_tmp152->tag != 5)goto
_LLED;else{_tmp153=_tmp152->f1;_tmp154=_tmp152->f2;if(_tmp154 != Cyc_Absyn_PostDec)
goto _LLED;}}_LLEC: Cyc_Absyndump_dumpexp_prec(myprec,_tmp153);{const char*_tmp412;
Cyc_Absyndump_dump(((_tmp412="--",_tag_dyneither(_tmp412,sizeof(char),3))));}
goto _LLCA;_LLED: {struct Cyc_Absyn_Conditional_e_struct*_tmp155=(struct Cyc_Absyn_Conditional_e_struct*)
_tmp116;if(_tmp155->tag != 6)goto _LLEF;else{_tmp156=_tmp155->f1;_tmp157=_tmp155->f2;
_tmp158=_tmp155->f3;}}_LLEE: Cyc_Absyndump_dumpexp_prec(myprec,_tmp156);Cyc_Absyndump_dump_char((
int)'?');Cyc_Absyndump_dumpexp_prec(0,_tmp157);Cyc_Absyndump_dump_char((int)':');
Cyc_Absyndump_dumpexp_prec(myprec,_tmp158);goto _LLCA;_LLEF: {struct Cyc_Absyn_And_e_struct*
_tmp159=(struct Cyc_Absyn_And_e_struct*)_tmp116;if(_tmp159->tag != 7)goto _LLF1;
else{_tmp15A=_tmp159->f1;_tmp15B=_tmp159->f2;}}_LLF0: Cyc_Absyndump_dumpexp_prec(
myprec,_tmp15A);{const char*_tmp413;Cyc_Absyndump_dump(((_tmp413=" && ",
_tag_dyneither(_tmp413,sizeof(char),5))));}Cyc_Absyndump_dumpexp_prec(myprec,
_tmp15B);goto _LLCA;_LLF1: {struct Cyc_Absyn_Or_e_struct*_tmp15C=(struct Cyc_Absyn_Or_e_struct*)
_tmp116;if(_tmp15C->tag != 8)goto _LLF3;else{_tmp15D=_tmp15C->f1;_tmp15E=_tmp15C->f2;}}
_LLF2: Cyc_Absyndump_dumpexp_prec(myprec,_tmp15D);{const char*_tmp414;Cyc_Absyndump_dump(((
_tmp414=" || ",_tag_dyneither(_tmp414,sizeof(char),5))));}Cyc_Absyndump_dumpexp_prec(
myprec,_tmp15E);goto _LLCA;_LLF3: {struct Cyc_Absyn_SeqExp_e_struct*_tmp15F=(
struct Cyc_Absyn_SeqExp_e_struct*)_tmp116;if(_tmp15F->tag != 9)goto _LLF5;else{
_tmp160=_tmp15F->f1;_tmp161=_tmp15F->f2;}}_LLF4: Cyc_Absyndump_dump_char((int)'(');
Cyc_Absyndump_dumpexp_prec(myprec,_tmp160);Cyc_Absyndump_dump_char((int)',');Cyc_Absyndump_dumpexp_prec(
myprec,_tmp161);Cyc_Absyndump_dump_char((int)')');goto _LLCA;_LLF5: {struct Cyc_Absyn_UnknownCall_e_struct*
_tmp162=(struct Cyc_Absyn_UnknownCall_e_struct*)_tmp116;if(_tmp162->tag != 10)goto
_LLF7;else{_tmp163=_tmp162->f1;_tmp164=_tmp162->f2;}}_LLF6: _tmp166=_tmp163;
_tmp167=_tmp164;goto _LLF8;_LLF7: {struct Cyc_Absyn_FnCall_e_struct*_tmp165=(
struct Cyc_Absyn_FnCall_e_struct*)_tmp116;if(_tmp165->tag != 11)goto _LLF9;else{
_tmp166=_tmp165->f1;_tmp167=_tmp165->f2;}}_LLF8: Cyc_Absyndump_dumpexp_prec(
myprec,_tmp166);{const char*_tmp415;Cyc_Absyndump_dump_nospace(((_tmp415="(",
_tag_dyneither(_tmp415,sizeof(char),2))));}Cyc_Absyndump_dumpexps_prec(20,
_tmp167);{const char*_tmp416;Cyc_Absyndump_dump_nospace(((_tmp416=")",
_tag_dyneither(_tmp416,sizeof(char),2))));}goto _LLCA;_LLF9: {struct Cyc_Absyn_Throw_e_struct*
_tmp168=(struct Cyc_Absyn_Throw_e_struct*)_tmp116;if(_tmp168->tag != 12)goto _LLFB;
else{_tmp169=_tmp168->f1;}}_LLFA:{const char*_tmp417;Cyc_Absyndump_dump(((_tmp417="throw",
_tag_dyneither(_tmp417,sizeof(char),6))));}Cyc_Absyndump_dumpexp_prec(myprec,
_tmp169);goto _LLCA;_LLFB: {struct Cyc_Absyn_NoInstantiate_e_struct*_tmp16A=(
struct Cyc_Absyn_NoInstantiate_e_struct*)_tmp116;if(_tmp16A->tag != 13)goto _LLFD;
else{_tmp16B=_tmp16A->f1;}}_LLFC: _tmp16D=_tmp16B;goto _LLFE;_LLFD: {struct Cyc_Absyn_Instantiate_e_struct*
_tmp16C=(struct Cyc_Absyn_Instantiate_e_struct*)_tmp116;if(_tmp16C->tag != 14)goto
_LLFF;else{_tmp16D=_tmp16C->f1;}}_LLFE: Cyc_Absyndump_dumpexp_prec(inprec,_tmp16D);
goto _LLCA;_LLFF: {struct Cyc_Absyn_Cast_e_struct*_tmp16E=(struct Cyc_Absyn_Cast_e_struct*)
_tmp116;if(_tmp16E->tag != 15)goto _LL101;else{_tmp16F=(void*)_tmp16E->f1;_tmp170=
_tmp16E->f2;}}_LL100: Cyc_Absyndump_dump_char((int)'(');Cyc_Absyndump_dumptyp(
_tmp16F);Cyc_Absyndump_dump_char((int)')');Cyc_Absyndump_dumpexp_prec(myprec,
_tmp170);goto _LLCA;_LL101: {struct Cyc_Absyn_Address_e_struct*_tmp171=(struct Cyc_Absyn_Address_e_struct*)
_tmp116;if(_tmp171->tag != 16)goto _LL103;else{_tmp172=_tmp171->f1;}}_LL102: Cyc_Absyndump_dump_char((
int)'&');Cyc_Absyndump_dumpexp_prec(myprec,_tmp172);goto _LLCA;_LL103: {struct Cyc_Absyn_New_e_struct*
_tmp173=(struct Cyc_Absyn_New_e_struct*)_tmp116;if(_tmp173->tag != 17)goto _LL105;
else{_tmp174=_tmp173->f1;_tmp175=_tmp173->f2;}}_LL104:{const char*_tmp418;Cyc_Absyndump_dump(((
_tmp418="new ",_tag_dyneither(_tmp418,sizeof(char),5))));}Cyc_Absyndump_dumpexp_prec(
myprec,_tmp175);goto _LLCA;_LL105: {struct Cyc_Absyn_Sizeoftyp_e_struct*_tmp176=(
struct Cyc_Absyn_Sizeoftyp_e_struct*)_tmp116;if(_tmp176->tag != 18)goto _LL107;
else{_tmp177=(void*)_tmp176->f1;}}_LL106:{const char*_tmp419;Cyc_Absyndump_dump(((
_tmp419="sizeof(",_tag_dyneither(_tmp419,sizeof(char),8))));}Cyc_Absyndump_dumptyp(
_tmp177);Cyc_Absyndump_dump_char((int)')');goto _LLCA;_LL107: {struct Cyc_Absyn_Sizeofexp_e_struct*
_tmp178=(struct Cyc_Absyn_Sizeofexp_e_struct*)_tmp116;if(_tmp178->tag != 19)goto
_LL109;else{_tmp179=_tmp178->f1;}}_LL108:{const char*_tmp41A;Cyc_Absyndump_dump(((
_tmp41A="sizeof(",_tag_dyneither(_tmp41A,sizeof(char),8))));}Cyc_Absyndump_dumpexp(
_tmp179);Cyc_Absyndump_dump_char((int)')');goto _LLCA;_LL109: {struct Cyc_Absyn_Valueof_e_struct*
_tmp17A=(struct Cyc_Absyn_Valueof_e_struct*)_tmp116;if(_tmp17A->tag != 39)goto
_LL10B;else{_tmp17B=(void*)_tmp17A->f1;}}_LL10A:{const char*_tmp41B;Cyc_Absyndump_dump(((
_tmp41B="valueof(",_tag_dyneither(_tmp41B,sizeof(char),9))));}Cyc_Absyndump_dumptyp(
_tmp17B);Cyc_Absyndump_dump_char((int)')');goto _LLCA;_LL10B: {struct Cyc_Absyn_Tagcheck_e_struct*
_tmp17C=(struct Cyc_Absyn_Tagcheck_e_struct*)_tmp116;if(_tmp17C->tag != 38)goto
_LL10D;else{_tmp17D=_tmp17C->f1;_tmp17E=_tmp17C->f2;}}_LL10C:{const char*_tmp41C;
Cyc_Absyndump_dump(((_tmp41C="tagcheck(",_tag_dyneither(_tmp41C,sizeof(char),10))));}
Cyc_Absyndump_dumpexp(_tmp17D);Cyc_Absyndump_dump_char((int)'.');Cyc_Absyndump_dump_nospace(*
_tmp17E);Cyc_Absyndump_dump_char((int)')');goto _LLCA;_LL10D: {struct Cyc_Absyn_Offsetof_e_struct*
_tmp17F=(struct Cyc_Absyn_Offsetof_e_struct*)_tmp116;if(_tmp17F->tag != 20)goto
_LL10F;else{_tmp180=(void*)_tmp17F->f1;_tmp181=(void*)_tmp17F->f2;{struct Cyc_Absyn_StructField_struct*
_tmp182=(struct Cyc_Absyn_StructField_struct*)_tmp181;if(_tmp182->tag != 0)goto
_LL10F;else{_tmp183=_tmp182->f1;}};}}_LL10E:{const char*_tmp41D;Cyc_Absyndump_dump(((
_tmp41D="offsetof(",_tag_dyneither(_tmp41D,sizeof(char),10))));}Cyc_Absyndump_dumptyp(
_tmp180);Cyc_Absyndump_dump_char((int)',');Cyc_Absyndump_dump_nospace(*_tmp183);
Cyc_Absyndump_dump_char((int)')');goto _LLCA;_LL10F: {struct Cyc_Absyn_Offsetof_e_struct*
_tmp184=(struct Cyc_Absyn_Offsetof_e_struct*)_tmp116;if(_tmp184->tag != 20)goto
_LL111;else{_tmp185=(void*)_tmp184->f1;_tmp186=(void*)_tmp184->f2;{struct Cyc_Absyn_TupleIndex_struct*
_tmp187=(struct Cyc_Absyn_TupleIndex_struct*)_tmp186;if(_tmp187->tag != 1)goto
_LL111;else{_tmp188=_tmp187->f1;}};}}_LL110:{const char*_tmp41E;Cyc_Absyndump_dump(((
_tmp41E="offsetof(",_tag_dyneither(_tmp41E,sizeof(char),10))));}Cyc_Absyndump_dumptyp(
_tmp185);Cyc_Absyndump_dump_char((int)',');{const char*_tmp422;void*_tmp421[1];
struct Cyc_Int_pa_struct _tmp420;Cyc_Absyndump_dump((struct _dyneither_ptr)((
_tmp420.tag=1,((_tmp420.f1=(unsigned long)((int)_tmp188),((_tmp421[0]=& _tmp420,
Cyc_aprintf(((_tmp422="%d",_tag_dyneither(_tmp422,sizeof(char),3))),
_tag_dyneither(_tmp421,sizeof(void*),1)))))))));}Cyc_Absyndump_dump_char((int)')');
goto _LLCA;_LL111: {struct Cyc_Absyn_Deref_e_struct*_tmp189=(struct Cyc_Absyn_Deref_e_struct*)
_tmp116;if(_tmp189->tag != 21)goto _LL113;else{_tmp18A=_tmp189->f1;}}_LL112: Cyc_Absyndump_dump_char((
int)'*');Cyc_Absyndump_dumpexp_prec(myprec,_tmp18A);goto _LLCA;_LL113: {struct Cyc_Absyn_AggrMember_e_struct*
_tmp18B=(struct Cyc_Absyn_AggrMember_e_struct*)_tmp116;if(_tmp18B->tag != 22)goto
_LL115;else{_tmp18C=_tmp18B->f1;_tmp18D=_tmp18B->f2;}}_LL114: Cyc_Absyndump_dumpexp_prec(
myprec,_tmp18C);Cyc_Absyndump_dump_char((int)'.');Cyc_Absyndump_dump_nospace(*
_tmp18D);goto _LLCA;_LL115: {struct Cyc_Absyn_AggrArrow_e_struct*_tmp18E=(struct
Cyc_Absyn_AggrArrow_e_struct*)_tmp116;if(_tmp18E->tag != 23)goto _LL117;else{
_tmp18F=_tmp18E->f1;_tmp190=_tmp18E->f2;}}_LL116: Cyc_Absyndump_dumpexp_prec(
myprec,_tmp18F);{const char*_tmp423;Cyc_Absyndump_dump_nospace(((_tmp423="->",
_tag_dyneither(_tmp423,sizeof(char),3))));}Cyc_Absyndump_dump_nospace(*_tmp190);
goto _LLCA;_LL117: {struct Cyc_Absyn_Subscript_e_struct*_tmp191=(struct Cyc_Absyn_Subscript_e_struct*)
_tmp116;if(_tmp191->tag != 24)goto _LL119;else{_tmp192=_tmp191->f1;_tmp193=_tmp191->f2;}}
_LL118: Cyc_Absyndump_dumpexp_prec(myprec,_tmp192);Cyc_Absyndump_dump_char((int)'[');
Cyc_Absyndump_dumpexp(_tmp193);Cyc_Absyndump_dump_char((int)']');goto _LLCA;
_LL119: {struct Cyc_Absyn_Tuple_e_struct*_tmp194=(struct Cyc_Absyn_Tuple_e_struct*)
_tmp116;if(_tmp194->tag != 25)goto _LL11B;else{_tmp195=_tmp194->f1;}}_LL11A:{const
char*_tmp424;Cyc_Absyndump_dump(((_tmp424="$(",_tag_dyneither(_tmp424,sizeof(
char),3))));}Cyc_Absyndump_dumpexps_prec(20,_tmp195);Cyc_Absyndump_dump_char((
int)')');goto _LLCA;_LL11B: {struct Cyc_Absyn_CompoundLit_e_struct*_tmp196=(struct
Cyc_Absyn_CompoundLit_e_struct*)_tmp116;if(_tmp196->tag != 26)goto _LL11D;else{
_tmp197=_tmp196->f1;_tmp198=_tmp196->f2;}}_LL11C: Cyc_Absyndump_dump_char((int)'(');
Cyc_Absyndump_dumptyp((*_tmp197).f3);Cyc_Absyndump_dump_char((int)')');{const
char*_tmp427;const char*_tmp426;const char*_tmp425;((void(*)(void(*f)(struct
_tuple16*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct _dyneither_ptr
end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(Cyc_Absyndump_dumpde,_tmp198,((
_tmp425="{",_tag_dyneither(_tmp425,sizeof(char),2))),((_tmp426="}",
_tag_dyneither(_tmp426,sizeof(char),2))),((_tmp427=",",_tag_dyneither(_tmp427,
sizeof(char),2))));}goto _LLCA;_LL11D: {struct Cyc_Absyn_Array_e_struct*_tmp199=(
struct Cyc_Absyn_Array_e_struct*)_tmp116;if(_tmp199->tag != 27)goto _LL11F;else{
_tmp19A=_tmp199->f1;}}_LL11E:{const char*_tmp42A;const char*_tmp429;const char*
_tmp428;((void(*)(void(*f)(struct _tuple16*),struct Cyc_List_List*l,struct
_dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dumpde,_tmp19A,((_tmp428="{",_tag_dyneither(_tmp428,sizeof(char),2))),((
_tmp429="}",_tag_dyneither(_tmp429,sizeof(char),2))),((_tmp42A=",",
_tag_dyneither(_tmp42A,sizeof(char),2))));}goto _LLCA;_LL11F: {struct Cyc_Absyn_Comprehension_e_struct*
_tmp19B=(struct Cyc_Absyn_Comprehension_e_struct*)_tmp116;if(_tmp19B->tag != 28)
goto _LL121;else{_tmp19C=_tmp19B->f1;_tmp19D=_tmp19B->f2;_tmp19E=_tmp19B->f3;}}
_LL120:{const char*_tmp42B;Cyc_Absyndump_dump(((_tmp42B="new {for",_tag_dyneither(
_tmp42B,sizeof(char),9))));}Cyc_Absyndump_dump_str((*_tmp19C->name).f2);Cyc_Absyndump_dump_char((
int)'<');Cyc_Absyndump_dumpexp(_tmp19D);Cyc_Absyndump_dump_char((int)':');Cyc_Absyndump_dumpexp(
_tmp19E);Cyc_Absyndump_dump_char((int)'}');goto _LLCA;_LL121: {struct Cyc_Absyn_Aggregate_e_struct*
_tmp19F=(struct Cyc_Absyn_Aggregate_e_struct*)_tmp116;if(_tmp19F->tag != 29)goto
_LL123;else{_tmp1A0=_tmp19F->f1;_tmp1A1=_tmp19F->f2;_tmp1A2=_tmp19F->f3;}}_LL122:
Cyc_Absyndump_dumpqvar(_tmp1A0);Cyc_Absyndump_dump_char((int)'{');if(_tmp1A1 != 0)
Cyc_Absyndump_dumptps(_tmp1A1);{const char*_tmp42E;const char*_tmp42D;const char*
_tmp42C;((void(*)(void(*f)(struct _tuple16*),struct Cyc_List_List*l,struct
_dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dumpde,_tmp1A2,((_tmp42C="",_tag_dyneither(_tmp42C,sizeof(char),1))),((
_tmp42D="}",_tag_dyneither(_tmp42D,sizeof(char),2))),((_tmp42E=",",
_tag_dyneither(_tmp42E,sizeof(char),2))));}goto _LLCA;_LL123: {struct Cyc_Absyn_AnonStruct_e_struct*
_tmp1A3=(struct Cyc_Absyn_AnonStruct_e_struct*)_tmp116;if(_tmp1A3->tag != 30)goto
_LL125;else{_tmp1A4=_tmp1A3->f2;}}_LL124:{const char*_tmp431;const char*_tmp430;
const char*_tmp42F;((void(*)(void(*f)(struct _tuple16*),struct Cyc_List_List*l,
struct _dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dumpde,_tmp1A4,((_tmp42F="{",_tag_dyneither(_tmp42F,sizeof(char),2))),((
_tmp430="}",_tag_dyneither(_tmp430,sizeof(char),2))),((_tmp431=",",
_tag_dyneither(_tmp431,sizeof(char),2))));}goto _LLCA;_LL125: {struct Cyc_Absyn_Datatype_e_struct*
_tmp1A5=(struct Cyc_Absyn_Datatype_e_struct*)_tmp116;if(_tmp1A5->tag != 31)goto
_LL127;else{_tmp1A6=_tmp1A5->f1;_tmp1A7=_tmp1A5->f3;}}_LL126: Cyc_Absyndump_dumpqvar(
_tmp1A7->name);if(_tmp1A6 != 0){const char*_tmp434;const char*_tmp433;const char*
_tmp432;((void(*)(void(*f)(struct Cyc_Absyn_Exp*),struct Cyc_List_List*l,struct
_dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dumpexp,_tmp1A6,((_tmp432="(",_tag_dyneither(_tmp432,sizeof(char),
2))),((_tmp433=")",_tag_dyneither(_tmp433,sizeof(char),2))),((_tmp434=",",
_tag_dyneither(_tmp434,sizeof(char),2))));}goto _LLCA;_LL127: {struct Cyc_Absyn_Enum_e_struct*
_tmp1A8=(struct Cyc_Absyn_Enum_e_struct*)_tmp116;if(_tmp1A8->tag != 32)goto _LL129;
else{_tmp1A9=_tmp1A8->f1;}}_LL128: Cyc_Absyndump_dumpqvar(_tmp1A9);goto _LLCA;
_LL129: {struct Cyc_Absyn_AnonEnum_e_struct*_tmp1AA=(struct Cyc_Absyn_AnonEnum_e_struct*)
_tmp116;if(_tmp1AA->tag != 33)goto _LL12B;else{_tmp1AB=_tmp1AA->f1;}}_LL12A: Cyc_Absyndump_dumpqvar(
_tmp1AB);goto _LLCA;_LL12B: {struct Cyc_Absyn_Malloc_e_struct*_tmp1AC=(struct Cyc_Absyn_Malloc_e_struct*)
_tmp116;if(_tmp1AC->tag != 34)goto _LL12D;else{_tmp1AD=_tmp1AC->f1;_tmp1AE=_tmp1AD.is_calloc;
_tmp1AF=_tmp1AD.rgn;_tmp1B0=_tmp1AD.elt_type;_tmp1B1=_tmp1AD.num_elts;}}_LL12C:
if(_tmp1AE){if(_tmp1AF != 0){{const char*_tmp435;Cyc_Absyndump_dump(((_tmp435="rcalloc(",
_tag_dyneither(_tmp435,sizeof(char),9))));}Cyc_Absyndump_dumpexp((struct Cyc_Absyn_Exp*)
_tmp1AF);{const char*_tmp436;Cyc_Absyndump_dump(((_tmp436=",",_tag_dyneither(
_tmp436,sizeof(char),2))));};}else{const char*_tmp437;Cyc_Absyndump_dump(((
_tmp437="calloc",_tag_dyneither(_tmp437,sizeof(char),7))));}Cyc_Absyndump_dumpexp(
_tmp1B1);{const char*_tmp438;Cyc_Absyndump_dump(((_tmp438=",",_tag_dyneither(
_tmp438,sizeof(char),2))));}Cyc_Absyndump_dumpexp(Cyc_Absyn_sizeoftyp_exp(*((
void**)_check_null(_tmp1B0)),0));{const char*_tmp439;Cyc_Absyndump_dump(((_tmp439=")",
_tag_dyneither(_tmp439,sizeof(char),2))));};}else{if(_tmp1AF != 0){{const char*
_tmp43A;Cyc_Absyndump_dump(((_tmp43A="rmalloc(",_tag_dyneither(_tmp43A,sizeof(
char),9))));}Cyc_Absyndump_dumpexp((struct Cyc_Absyn_Exp*)_tmp1AF);{const char*
_tmp43B;Cyc_Absyndump_dump(((_tmp43B=",",_tag_dyneither(_tmp43B,sizeof(char),2))));};}
else{const char*_tmp43C;Cyc_Absyndump_dump(((_tmp43C="malloc(",_tag_dyneither(
_tmp43C,sizeof(char),8))));}if(_tmp1B0 != 0)Cyc_Absyndump_dumpexp(Cyc_Absyn_times_exp(
Cyc_Absyn_sizeoftyp_exp(*_tmp1B0,0),_tmp1B1,0));else{Cyc_Absyndump_dumpexp(
_tmp1B1);}{const char*_tmp43D;Cyc_Absyndump_dump(((_tmp43D=")",_tag_dyneither(
_tmp43D,sizeof(char),2))));};}goto _LLCA;_LL12D: {struct Cyc_Absyn_Swap_e_struct*
_tmp1B2=(struct Cyc_Absyn_Swap_e_struct*)_tmp116;if(_tmp1B2->tag != 35)goto _LL12F;
else{_tmp1B3=_tmp1B2->f1;_tmp1B4=_tmp1B2->f2;}}_LL12E:{const char*_tmp43E;Cyc_Absyndump_dump(((
_tmp43E="cycswap(",_tag_dyneither(_tmp43E,sizeof(char),9))));}Cyc_Absyndump_dumpexp_prec(
myprec,_tmp1B3);Cyc_Absyndump_dump_char((int)',');Cyc_Absyndump_dumpexp_prec(
myprec,_tmp1B4);Cyc_Absyndump_dump_char((int)')');goto _LLCA;_LL12F: {struct Cyc_Absyn_UnresolvedMem_e_struct*
_tmp1B5=(struct Cyc_Absyn_UnresolvedMem_e_struct*)_tmp116;if(_tmp1B5->tag != 36)
goto _LL131;else{_tmp1B6=_tmp1B5->f1;_tmp1B7=_tmp1B5->f2;}}_LL130:{const char*
_tmp441;const char*_tmp440;const char*_tmp43F;((void(*)(void(*f)(struct _tuple16*),
struct Cyc_List_List*l,struct _dyneither_ptr start,struct _dyneither_ptr end,struct
_dyneither_ptr sep))Cyc_Absyndump_group)(Cyc_Absyndump_dumpde,_tmp1B7,((_tmp43F="{",
_tag_dyneither(_tmp43F,sizeof(char),2))),((_tmp440="}",_tag_dyneither(_tmp440,
sizeof(char),2))),((_tmp441=",",_tag_dyneither(_tmp441,sizeof(char),2))));}goto
_LLCA;_LL131: {struct Cyc_Absyn_StmtExp_e_struct*_tmp1B8=(struct Cyc_Absyn_StmtExp_e_struct*)
_tmp116;if(_tmp1B8->tag != 37)goto _LLCA;else{_tmp1B9=_tmp1B8->f1;}}_LL132:{const
char*_tmp442;Cyc_Absyndump_dump_nospace(((_tmp442="({",_tag_dyneither(_tmp442,
sizeof(char),3))));}Cyc_Absyndump_dumpstmt(_tmp1B9,1);{const char*_tmp443;Cyc_Absyndump_dump_nospace(((
_tmp443="})",_tag_dyneither(_tmp443,sizeof(char),3))));}goto _LLCA;_LLCA:;}if(
inprec >= myprec)Cyc_Absyndump_dump_char((int)')');}void Cyc_Absyndump_dumpexp(
struct Cyc_Absyn_Exp*e);void Cyc_Absyndump_dumpexp(struct Cyc_Absyn_Exp*e){Cyc_Absyndump_dumpexp_prec(
0,e);}void Cyc_Absyndump_dumpswitchclauses(struct Cyc_List_List*scs);void Cyc_Absyndump_dumpswitchclauses(
struct Cyc_List_List*scs){for(0;scs != 0;scs=scs->tl){struct Cyc_Absyn_Switch_clause*
_tmp200=(struct Cyc_Absyn_Switch_clause*)scs->hd;if(_tmp200->where_clause == 0  && (
_tmp200->pattern)->r == (void*)& Cyc_Absyn_Wild_p_val){const char*_tmp444;Cyc_Absyndump_dump(((
_tmp444="default:",_tag_dyneither(_tmp444,sizeof(char),9))));}else{{const char*
_tmp445;Cyc_Absyndump_dump(((_tmp445="case",_tag_dyneither(_tmp445,sizeof(char),
5))));}Cyc_Absyndump_dumppat(_tmp200->pattern);if(_tmp200->where_clause != 0){{
const char*_tmp446;Cyc_Absyndump_dump(((_tmp446="&&",_tag_dyneither(_tmp446,
sizeof(char),3))));}Cyc_Absyndump_dumpexp((struct Cyc_Absyn_Exp*)_check_null(
_tmp200->where_clause));}{const char*_tmp447;Cyc_Absyndump_dump_nospace(((_tmp447=":",
_tag_dyneither(_tmp447,sizeof(char),2))));};}Cyc_Absyndump_dumpstmt(_tmp200->body,
0);}}void Cyc_Absyndump_dumpstmt(struct Cyc_Absyn_Stmt*s,int expstmt);void Cyc_Absyndump_dumpstmt(
struct Cyc_Absyn_Stmt*s,int expstmt){void*_tmp205=s->r;struct Cyc_Absyn_Exp*_tmp208;
struct Cyc_Absyn_Stmt*_tmp20A;struct Cyc_Absyn_Stmt*_tmp20B;struct Cyc_Absyn_Exp*
_tmp20D;struct Cyc_Absyn_Exp*_tmp20F;struct Cyc_Absyn_Exp*_tmp211;struct Cyc_Absyn_Stmt*
_tmp212;struct Cyc_Absyn_Stmt*_tmp213;struct _tuple8 _tmp215;struct Cyc_Absyn_Exp*
_tmp216;struct Cyc_Absyn_Stmt*_tmp217;struct _dyneither_ptr*_tmp21B;struct Cyc_Absyn_Exp*
_tmp21D;struct _tuple8 _tmp21E;struct Cyc_Absyn_Exp*_tmp21F;struct _tuple8 _tmp220;
struct Cyc_Absyn_Exp*_tmp221;struct Cyc_Absyn_Stmt*_tmp222;struct Cyc_Absyn_Exp*
_tmp224;struct Cyc_List_List*_tmp225;struct Cyc_Absyn_Decl*_tmp227;struct Cyc_Absyn_Stmt*
_tmp228;struct _dyneither_ptr*_tmp22A;struct Cyc_Absyn_Stmt*_tmp22B;struct Cyc_Absyn_Stmt*
_tmp22D;struct _tuple8 _tmp22E;struct Cyc_Absyn_Exp*_tmp22F;struct Cyc_List_List*
_tmp231;struct Cyc_List_List*_tmp233;struct Cyc_Absyn_Stmt*_tmp235;struct Cyc_List_List*
_tmp236;struct Cyc_Absyn_Exp*_tmp238;_LL138: {struct Cyc_Absyn_Skip_s_struct*
_tmp206=(struct Cyc_Absyn_Skip_s_struct*)_tmp205;if(_tmp206->tag != 0)goto _LL13A;}
_LL139: Cyc_Absyndump_dump_semi();goto _LL137;_LL13A: {struct Cyc_Absyn_Exp_s_struct*
_tmp207=(struct Cyc_Absyn_Exp_s_struct*)_tmp205;if(_tmp207->tag != 1)goto _LL13C;
else{_tmp208=_tmp207->f1;}}_LL13B: Cyc_Absyndump_dumploc(s->loc);Cyc_Absyndump_dumpexp(
_tmp208);Cyc_Absyndump_dump_semi();goto _LL137;_LL13C: {struct Cyc_Absyn_Seq_s_struct*
_tmp209=(struct Cyc_Absyn_Seq_s_struct*)_tmp205;if(_tmp209->tag != 2)goto _LL13E;
else{_tmp20A=_tmp209->f1;_tmp20B=_tmp209->f2;}}_LL13D: if(Cyc_Absynpp_is_declaration(
_tmp20A)){Cyc_Absyndump_dump_char((int)'{');Cyc_Absyndump_dumpstmt(_tmp20A,0);
Cyc_Absyndump_dump_char((int)'}');}else{Cyc_Absyndump_dumpstmt(_tmp20A,0);}if(
Cyc_Absynpp_is_declaration(_tmp20B)){if(expstmt)Cyc_Absyndump_dump_char((int)'(');
Cyc_Absyndump_dump_char((int)'{');Cyc_Absyndump_dumpstmt(_tmp20B,expstmt);Cyc_Absyndump_dump_char((
int)'}');if(expstmt)Cyc_Absyndump_dump_char((int)')');Cyc_Absyndump_dump_semi();}
else{Cyc_Absyndump_dumpstmt(_tmp20B,expstmt);}goto _LL137;_LL13E: {struct Cyc_Absyn_Return_s_struct*
_tmp20C=(struct Cyc_Absyn_Return_s_struct*)_tmp205;if(_tmp20C->tag != 3)goto _LL140;
else{_tmp20D=_tmp20C->f1;if(_tmp20D != 0)goto _LL140;}}_LL13F: Cyc_Absyndump_dumploc(
s->loc);{const char*_tmp448;Cyc_Absyndump_dump(((_tmp448="return;",_tag_dyneither(
_tmp448,sizeof(char),8))));}goto _LL137;_LL140: {struct Cyc_Absyn_Return_s_struct*
_tmp20E=(struct Cyc_Absyn_Return_s_struct*)_tmp205;if(_tmp20E->tag != 3)goto _LL142;
else{_tmp20F=_tmp20E->f1;}}_LL141: Cyc_Absyndump_dumploc(s->loc);{const char*
_tmp449;Cyc_Absyndump_dump(((_tmp449="return",_tag_dyneither(_tmp449,sizeof(char),
7))));}Cyc_Absyndump_dumpexp((struct Cyc_Absyn_Exp*)_check_null(_tmp20F));Cyc_Absyndump_dump_semi();
goto _LL137;_LL142: {struct Cyc_Absyn_IfThenElse_s_struct*_tmp210=(struct Cyc_Absyn_IfThenElse_s_struct*)
_tmp205;if(_tmp210->tag != 4)goto _LL144;else{_tmp211=_tmp210->f1;_tmp212=_tmp210->f2;
_tmp213=_tmp210->f3;}}_LL143: Cyc_Absyndump_dumploc(s->loc);{const char*_tmp44A;
Cyc_Absyndump_dump(((_tmp44A="if(",_tag_dyneither(_tmp44A,sizeof(char),4))));}
Cyc_Absyndump_dumpexp(_tmp211);{void*_tmp23C=_tmp212->r;_LL15F: {struct Cyc_Absyn_Seq_s_struct*
_tmp23D=(struct Cyc_Absyn_Seq_s_struct*)_tmp23C;if(_tmp23D->tag != 2)goto _LL161;}
_LL160: goto _LL162;_LL161: {struct Cyc_Absyn_Decl_s_struct*_tmp23E=(struct Cyc_Absyn_Decl_s_struct*)
_tmp23C;if(_tmp23E->tag != 12)goto _LL163;}_LL162: goto _LL164;_LL163: {struct Cyc_Absyn_IfThenElse_s_struct*
_tmp23F=(struct Cyc_Absyn_IfThenElse_s_struct*)_tmp23C;if(_tmp23F->tag != 4)goto
_LL165;}_LL164: goto _LL166;_LL165: {struct Cyc_Absyn_Label_s_struct*_tmp240=(
struct Cyc_Absyn_Label_s_struct*)_tmp23C;if(_tmp240->tag != 13)goto _LL167;}_LL166:{
const char*_tmp44B;Cyc_Absyndump_dump_nospace(((_tmp44B="){",_tag_dyneither(
_tmp44B,sizeof(char),3))));}Cyc_Absyndump_dumpstmt(_tmp212,0);Cyc_Absyndump_dump_char((
int)'}');goto _LL15E;_LL167:;_LL168: Cyc_Absyndump_dump_char((int)')');Cyc_Absyndump_dumpstmt(
_tmp212,0);_LL15E:;}{void*_tmp242=_tmp213->r;_LL16A: {struct Cyc_Absyn_Skip_s_struct*
_tmp243=(struct Cyc_Absyn_Skip_s_struct*)_tmp242;if(_tmp243->tag != 0)goto _LL16C;}
_LL16B: goto _LL169;_LL16C:;_LL16D:{const char*_tmp44C;Cyc_Absyndump_dump(((_tmp44C="else{",
_tag_dyneither(_tmp44C,sizeof(char),6))));}Cyc_Absyndump_dumpstmt(_tmp213,0);Cyc_Absyndump_dump_char((
int)'}');goto _LL169;_LL169:;}goto _LL137;_LL144: {struct Cyc_Absyn_While_s_struct*
_tmp214=(struct Cyc_Absyn_While_s_struct*)_tmp205;if(_tmp214->tag != 5)goto _LL146;
else{_tmp215=_tmp214->f1;_tmp216=_tmp215.f1;_tmp217=_tmp214->f2;}}_LL145: Cyc_Absyndump_dumploc(
s->loc);{const char*_tmp44D;Cyc_Absyndump_dump(((_tmp44D="while(",_tag_dyneither(
_tmp44D,sizeof(char),7))));}Cyc_Absyndump_dumpexp(_tmp216);{const char*_tmp44E;
Cyc_Absyndump_dump_nospace(((_tmp44E="){",_tag_dyneither(_tmp44E,sizeof(char),3))));}
Cyc_Absyndump_dumpstmt(_tmp217,0);Cyc_Absyndump_dump_char((int)'}');goto _LL137;
_LL146: {struct Cyc_Absyn_Break_s_struct*_tmp218=(struct Cyc_Absyn_Break_s_struct*)
_tmp205;if(_tmp218->tag != 6)goto _LL148;}_LL147: Cyc_Absyndump_dumploc(s->loc);{
const char*_tmp44F;Cyc_Absyndump_dump(((_tmp44F="break;",_tag_dyneither(_tmp44F,
sizeof(char),7))));}goto _LL137;_LL148: {struct Cyc_Absyn_Continue_s_struct*
_tmp219=(struct Cyc_Absyn_Continue_s_struct*)_tmp205;if(_tmp219->tag != 7)goto
_LL14A;}_LL149: Cyc_Absyndump_dumploc(s->loc);{const char*_tmp450;Cyc_Absyndump_dump(((
_tmp450="continue;",_tag_dyneither(_tmp450,sizeof(char),10))));}goto _LL137;
_LL14A: {struct Cyc_Absyn_Goto_s_struct*_tmp21A=(struct Cyc_Absyn_Goto_s_struct*)
_tmp205;if(_tmp21A->tag != 8)goto _LL14C;else{_tmp21B=_tmp21A->f1;}}_LL14B: Cyc_Absyndump_dumploc(
s->loc);{const char*_tmp451;Cyc_Absyndump_dump(((_tmp451="goto",_tag_dyneither(
_tmp451,sizeof(char),5))));}Cyc_Absyndump_dump_str(_tmp21B);Cyc_Absyndump_dump_semi();
goto _LL137;_LL14C: {struct Cyc_Absyn_For_s_struct*_tmp21C=(struct Cyc_Absyn_For_s_struct*)
_tmp205;if(_tmp21C->tag != 9)goto _LL14E;else{_tmp21D=_tmp21C->f1;_tmp21E=_tmp21C->f2;
_tmp21F=_tmp21E.f1;_tmp220=_tmp21C->f3;_tmp221=_tmp220.f1;_tmp222=_tmp21C->f4;}}
_LL14D: Cyc_Absyndump_dumploc(s->loc);{const char*_tmp452;Cyc_Absyndump_dump(((
_tmp452="for(",_tag_dyneither(_tmp452,sizeof(char),5))));}Cyc_Absyndump_dumpexp(
_tmp21D);Cyc_Absyndump_dump_semi();Cyc_Absyndump_dumpexp(_tmp21F);Cyc_Absyndump_dump_semi();
Cyc_Absyndump_dumpexp(_tmp221);{const char*_tmp453;Cyc_Absyndump_dump_nospace(((
_tmp453="){",_tag_dyneither(_tmp453,sizeof(char),3))));}Cyc_Absyndump_dumpstmt(
_tmp222,0);Cyc_Absyndump_dump_char((int)'}');goto _LL137;_LL14E: {struct Cyc_Absyn_Switch_s_struct*
_tmp223=(struct Cyc_Absyn_Switch_s_struct*)_tmp205;if(_tmp223->tag != 10)goto
_LL150;else{_tmp224=_tmp223->f1;_tmp225=_tmp223->f2;}}_LL14F: Cyc_Absyndump_dumploc(
s->loc);{const char*_tmp454;Cyc_Absyndump_dump(((_tmp454="switch(",_tag_dyneither(
_tmp454,sizeof(char),8))));}Cyc_Absyndump_dumpexp(_tmp224);{const char*_tmp455;
Cyc_Absyndump_dump_nospace(((_tmp455="){",_tag_dyneither(_tmp455,sizeof(char),3))));}
Cyc_Absyndump_dumpswitchclauses(_tmp225);Cyc_Absyndump_dump_char((int)'}');goto
_LL137;_LL150: {struct Cyc_Absyn_Decl_s_struct*_tmp226=(struct Cyc_Absyn_Decl_s_struct*)
_tmp205;if(_tmp226->tag != 12)goto _LL152;else{_tmp227=_tmp226->f1;_tmp228=_tmp226->f2;}}
_LL151: Cyc_Absyndump_dumpdecl(_tmp227);Cyc_Absyndump_dumpstmt(_tmp228,expstmt);
goto _LL137;_LL152: {struct Cyc_Absyn_Label_s_struct*_tmp229=(struct Cyc_Absyn_Label_s_struct*)
_tmp205;if(_tmp229->tag != 13)goto _LL154;else{_tmp22A=_tmp229->f1;_tmp22B=_tmp229->f2;}}
_LL153: if(Cyc_Absynpp_is_declaration(_tmp22B)){Cyc_Absyndump_dump_str(_tmp22A);
if(expstmt){const char*_tmp456;Cyc_Absyndump_dump_nospace(((_tmp456=": ({",
_tag_dyneither(_tmp456,sizeof(char),5))));}else{const char*_tmp457;Cyc_Absyndump_dump_nospace(((
_tmp457=": {",_tag_dyneither(_tmp457,sizeof(char),4))));}Cyc_Absyndump_dumpstmt(
_tmp22B,expstmt);if(expstmt){const char*_tmp458;Cyc_Absyndump_dump_nospace(((
_tmp458="});}",_tag_dyneither(_tmp458,sizeof(char),5))));}else{Cyc_Absyndump_dump_char((
int)'}');}}else{Cyc_Absyndump_dump_str(_tmp22A);Cyc_Absyndump_dump_char((int)':');
Cyc_Absyndump_dumpstmt(_tmp22B,expstmt);}goto _LL137;_LL154: {struct Cyc_Absyn_Do_s_struct*
_tmp22C=(struct Cyc_Absyn_Do_s_struct*)_tmp205;if(_tmp22C->tag != 14)goto _LL156;
else{_tmp22D=_tmp22C->f1;_tmp22E=_tmp22C->f2;_tmp22F=_tmp22E.f1;}}_LL155: Cyc_Absyndump_dumploc(
s->loc);{const char*_tmp459;Cyc_Absyndump_dump(((_tmp459="do{",_tag_dyneither(
_tmp459,sizeof(char),4))));}Cyc_Absyndump_dumpstmt(_tmp22D,0);{const char*_tmp45A;
Cyc_Absyndump_dump_nospace(((_tmp45A="}while(",_tag_dyneither(_tmp45A,sizeof(
char),8))));}Cyc_Absyndump_dumpexp(_tmp22F);{const char*_tmp45B;Cyc_Absyndump_dump_nospace(((
_tmp45B=");",_tag_dyneither(_tmp45B,sizeof(char),3))));}goto _LL137;_LL156: {
struct Cyc_Absyn_Fallthru_s_struct*_tmp230=(struct Cyc_Absyn_Fallthru_s_struct*)
_tmp205;if(_tmp230->tag != 11)goto _LL158;else{_tmp231=_tmp230->f1;if(_tmp231 != 0)
goto _LL158;}}_LL157:{const char*_tmp45C;Cyc_Absyndump_dump(((_tmp45C="fallthru;",
_tag_dyneither(_tmp45C,sizeof(char),10))));}goto _LL137;_LL158: {struct Cyc_Absyn_Fallthru_s_struct*
_tmp232=(struct Cyc_Absyn_Fallthru_s_struct*)_tmp205;if(_tmp232->tag != 11)goto
_LL15A;else{_tmp233=_tmp232->f1;}}_LL159:{const char*_tmp45D;Cyc_Absyndump_dump(((
_tmp45D="fallthru(",_tag_dyneither(_tmp45D,sizeof(char),10))));}Cyc_Absyndump_dumpexps_prec(
20,_tmp233);{const char*_tmp45E;Cyc_Absyndump_dump_nospace(((_tmp45E=");",
_tag_dyneither(_tmp45E,sizeof(char),3))));}goto _LL137;_LL15A: {struct Cyc_Absyn_TryCatch_s_struct*
_tmp234=(struct Cyc_Absyn_TryCatch_s_struct*)_tmp205;if(_tmp234->tag != 15)goto
_LL15C;else{_tmp235=_tmp234->f1;_tmp236=_tmp234->f2;}}_LL15B: Cyc_Absyndump_dumploc(
s->loc);{const char*_tmp45F;Cyc_Absyndump_dump(((_tmp45F="try",_tag_dyneither(
_tmp45F,sizeof(char),4))));}Cyc_Absyndump_dumpstmt(_tmp235,0);{const char*_tmp460;
Cyc_Absyndump_dump(((_tmp460="catch{",_tag_dyneither(_tmp460,sizeof(char),7))));}
Cyc_Absyndump_dumpswitchclauses(_tmp236);Cyc_Absyndump_dump_char((int)'}');goto
_LL137;_LL15C: {struct Cyc_Absyn_ResetRegion_s_struct*_tmp237=(struct Cyc_Absyn_ResetRegion_s_struct*)
_tmp205;if(_tmp237->tag != 16)goto _LL137;else{_tmp238=_tmp237->f1;}}_LL15D: Cyc_Absyndump_dumploc(
s->loc);{const char*_tmp461;Cyc_Absyndump_dump(((_tmp461="reset_region(",
_tag_dyneither(_tmp461,sizeof(char),14))));}Cyc_Absyndump_dumpexp(_tmp238);{
const char*_tmp462;Cyc_Absyndump_dump(((_tmp462=");",_tag_dyneither(_tmp462,
sizeof(char),3))));}goto _LL137;_LL137:;}struct _tuple17{struct Cyc_List_List*f1;
struct Cyc_Absyn_Pat*f2;};void Cyc_Absyndump_dumpdp(struct _tuple17*dp);void Cyc_Absyndump_dumpdp(
struct _tuple17*dp){{const char*_tmp465;const char*_tmp464;const char*_tmp463;((void(*)(
void(*f)(void*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(Cyc_Absyndump_dumpdesignator,(*
dp).f1,((_tmp463="",_tag_dyneither(_tmp463,sizeof(char),1))),((_tmp464="=",
_tag_dyneither(_tmp464,sizeof(char),2))),((_tmp465="=",_tag_dyneither(_tmp465,
sizeof(char),2))));}Cyc_Absyndump_dumppat((*dp).f2);}void Cyc_Absyndump_dumppat(
struct Cyc_Absyn_Pat*p);void Cyc_Absyndump_dumppat(struct Cyc_Absyn_Pat*p){void*
_tmp25E=p->r;enum Cyc_Absyn_Sign _tmp262;int _tmp263;enum Cyc_Absyn_Sign _tmp265;
int _tmp266;enum Cyc_Absyn_Sign _tmp268;int _tmp269;char _tmp26B;struct
_dyneither_ptr _tmp26D;struct Cyc_Absyn_Vardecl*_tmp26F;struct Cyc_Absyn_Pat*
_tmp270;struct Cyc_Absyn_Pat _tmp271;void*_tmp272;struct Cyc_Absyn_Vardecl*_tmp275;
struct Cyc_Absyn_Pat*_tmp276;struct Cyc_List_List*_tmp278;int _tmp279;struct Cyc_Absyn_Pat*
_tmp27B;struct Cyc_Absyn_Vardecl*_tmp27D;struct Cyc_Absyn_Pat*_tmp27E;struct Cyc_Absyn_Pat
_tmp27F;void*_tmp280;struct Cyc_Absyn_Vardecl*_tmp283;struct Cyc_Absyn_Pat*_tmp284;
struct Cyc_Absyn_Tvar*_tmp286;struct Cyc_Absyn_Vardecl*_tmp287;struct _tuple0*
_tmp289;struct _tuple0*_tmp28B;struct Cyc_List_List*_tmp28C;int _tmp28D;struct Cyc_Absyn_AggrInfo*
_tmp28F;struct Cyc_Absyn_AggrInfo _tmp290;union Cyc_Absyn_AggrInfoU _tmp291;struct
Cyc_List_List*_tmp292;struct Cyc_List_List*_tmp293;int _tmp294;struct Cyc_Absyn_AggrInfo*
_tmp296;struct Cyc_List_List*_tmp297;struct Cyc_List_List*_tmp298;int _tmp299;
struct Cyc_Absyn_Datatypefield*_tmp29B;struct Cyc_List_List*_tmp29C;int _tmp29D;
struct Cyc_Absyn_Enumfield*_tmp29F;struct Cyc_Absyn_Enumfield*_tmp2A1;struct Cyc_Absyn_Exp*
_tmp2A3;_LL16F: {struct Cyc_Absyn_Wild_p_struct*_tmp25F=(struct Cyc_Absyn_Wild_p_struct*)
_tmp25E;if(_tmp25F->tag != 0)goto _LL171;}_LL170: Cyc_Absyndump_dump_char((int)'_');
goto _LL16E;_LL171: {struct Cyc_Absyn_Null_p_struct*_tmp260=(struct Cyc_Absyn_Null_p_struct*)
_tmp25E;if(_tmp260->tag != 8)goto _LL173;}_LL172:{const char*_tmp466;Cyc_Absyndump_dump(((
_tmp466="NULL",_tag_dyneither(_tmp466,sizeof(char),5))));}goto _LL16E;_LL173: {
struct Cyc_Absyn_Int_p_struct*_tmp261=(struct Cyc_Absyn_Int_p_struct*)_tmp25E;if(
_tmp261->tag != 9)goto _LL175;else{_tmp262=_tmp261->f1;if(_tmp262 != Cyc_Absyn_None)
goto _LL175;_tmp263=_tmp261->f2;}}_LL174: _tmp266=_tmp263;goto _LL176;_LL175: {
struct Cyc_Absyn_Int_p_struct*_tmp264=(struct Cyc_Absyn_Int_p_struct*)_tmp25E;if(
_tmp264->tag != 9)goto _LL177;else{_tmp265=_tmp264->f1;if(_tmp265 != Cyc_Absyn_Signed)
goto _LL177;_tmp266=_tmp264->f2;}}_LL176:{const char*_tmp46A;void*_tmp469[1];
struct Cyc_Int_pa_struct _tmp468;Cyc_Absyndump_dump((struct _dyneither_ptr)((
_tmp468.tag=1,((_tmp468.f1=(unsigned long)_tmp266,((_tmp469[0]=& _tmp468,Cyc_aprintf(((
_tmp46A="%d",_tag_dyneither(_tmp46A,sizeof(char),3))),_tag_dyneither(_tmp469,
sizeof(void*),1)))))))));}goto _LL16E;_LL177: {struct Cyc_Absyn_Int_p_struct*
_tmp267=(struct Cyc_Absyn_Int_p_struct*)_tmp25E;if(_tmp267->tag != 9)goto _LL179;
else{_tmp268=_tmp267->f1;if(_tmp268 != Cyc_Absyn_Unsigned)goto _LL179;_tmp269=
_tmp267->f2;}}_LL178:{const char*_tmp46E;void*_tmp46D[1];struct Cyc_Int_pa_struct
_tmp46C;Cyc_Absyndump_dump((struct _dyneither_ptr)((_tmp46C.tag=1,((_tmp46C.f1=(
unsigned int)_tmp269,((_tmp46D[0]=& _tmp46C,Cyc_aprintf(((_tmp46E="%u",
_tag_dyneither(_tmp46E,sizeof(char),3))),_tag_dyneither(_tmp46D,sizeof(void*),1)))))))));}
goto _LL16E;_LL179: {struct Cyc_Absyn_Char_p_struct*_tmp26A=(struct Cyc_Absyn_Char_p_struct*)
_tmp25E;if(_tmp26A->tag != 10)goto _LL17B;else{_tmp26B=_tmp26A->f1;}}_LL17A:{const
char*_tmp46F;Cyc_Absyndump_dump(((_tmp46F="'",_tag_dyneither(_tmp46F,sizeof(char),
2))));}Cyc_Absyndump_dump_nospace(Cyc_Absynpp_char_escape(_tmp26B));{const char*
_tmp470;Cyc_Absyndump_dump_nospace(((_tmp470="'",_tag_dyneither(_tmp470,sizeof(
char),2))));}goto _LL16E;_LL17B: {struct Cyc_Absyn_Float_p_struct*_tmp26C=(struct
Cyc_Absyn_Float_p_struct*)_tmp25E;if(_tmp26C->tag != 11)goto _LL17D;else{_tmp26D=
_tmp26C->f1;}}_LL17C: Cyc_Absyndump_dump(_tmp26D);goto _LL16E;_LL17D: {struct Cyc_Absyn_Var_p_struct*
_tmp26E=(struct Cyc_Absyn_Var_p_struct*)_tmp25E;if(_tmp26E->tag != 1)goto _LL17F;
else{_tmp26F=_tmp26E->f1;_tmp270=_tmp26E->f2;_tmp271=*_tmp270;_tmp272=_tmp271.r;{
struct Cyc_Absyn_Wild_p_struct*_tmp273=(struct Cyc_Absyn_Wild_p_struct*)_tmp272;
if(_tmp273->tag != 0)goto _LL17F;};}}_LL17E: Cyc_Absyndump_dumpqvar(_tmp26F->name);
goto _LL16E;_LL17F: {struct Cyc_Absyn_Var_p_struct*_tmp274=(struct Cyc_Absyn_Var_p_struct*)
_tmp25E;if(_tmp274->tag != 1)goto _LL181;else{_tmp275=_tmp274->f1;_tmp276=_tmp274->f2;}}
_LL180: Cyc_Absyndump_dumpqvar(_tmp275->name);{const char*_tmp471;Cyc_Absyndump_dump(((
_tmp471=" as ",_tag_dyneither(_tmp471,sizeof(char),5))));}Cyc_Absyndump_dumppat(
_tmp276);goto _LL16E;_LL181: {struct Cyc_Absyn_Tuple_p_struct*_tmp277=(struct Cyc_Absyn_Tuple_p_struct*)
_tmp25E;if(_tmp277->tag != 4)goto _LL183;else{_tmp278=_tmp277->f1;_tmp279=_tmp277->f2;}}
_LL182: {const char*_tmp473;const char*_tmp472;struct _dyneither_ptr term=_tmp279?(
_tmp473=", ...)",_tag_dyneither(_tmp473,sizeof(char),7)):((_tmp472=")",
_tag_dyneither(_tmp472,sizeof(char),2)));{const char*_tmp475;const char*_tmp474;((
void(*)(void(*f)(struct Cyc_Absyn_Pat*),struct Cyc_List_List*l,struct
_dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dumppat,_tmp278,((_tmp474="$(",_tag_dyneither(_tmp474,sizeof(char),
3))),term,((_tmp475=",",_tag_dyneither(_tmp475,sizeof(char),2))));}goto _LL16E;}
_LL183: {struct Cyc_Absyn_Pointer_p_struct*_tmp27A=(struct Cyc_Absyn_Pointer_p_struct*)
_tmp25E;if(_tmp27A->tag != 5)goto _LL185;else{_tmp27B=_tmp27A->f1;}}_LL184:{const
char*_tmp476;Cyc_Absyndump_dump(((_tmp476="&",_tag_dyneither(_tmp476,sizeof(char),
2))));}Cyc_Absyndump_dumppat(_tmp27B);goto _LL16E;_LL185: {struct Cyc_Absyn_Reference_p_struct*
_tmp27C=(struct Cyc_Absyn_Reference_p_struct*)_tmp25E;if(_tmp27C->tag != 2)goto
_LL187;else{_tmp27D=_tmp27C->f1;_tmp27E=_tmp27C->f2;_tmp27F=*_tmp27E;_tmp280=
_tmp27F.r;{struct Cyc_Absyn_Wild_p_struct*_tmp281=(struct Cyc_Absyn_Wild_p_struct*)
_tmp280;if(_tmp281->tag != 0)goto _LL187;};}}_LL186:{const char*_tmp477;Cyc_Absyndump_dump(((
_tmp477="*",_tag_dyneither(_tmp477,sizeof(char),2))));}Cyc_Absyndump_dumpqvar(
_tmp27D->name);goto _LL16E;_LL187: {struct Cyc_Absyn_Reference_p_struct*_tmp282=(
struct Cyc_Absyn_Reference_p_struct*)_tmp25E;if(_tmp282->tag != 2)goto _LL189;else{
_tmp283=_tmp282->f1;_tmp284=_tmp282->f2;}}_LL188:{const char*_tmp478;Cyc_Absyndump_dump(((
_tmp478="*",_tag_dyneither(_tmp478,sizeof(char),2))));}Cyc_Absyndump_dumpqvar(
_tmp283->name);{const char*_tmp479;Cyc_Absyndump_dump(((_tmp479=" as ",
_tag_dyneither(_tmp479,sizeof(char),5))));}Cyc_Absyndump_dumppat(_tmp284);goto
_LL16E;_LL189: {struct Cyc_Absyn_TagInt_p_struct*_tmp285=(struct Cyc_Absyn_TagInt_p_struct*)
_tmp25E;if(_tmp285->tag != 3)goto _LL18B;else{_tmp286=_tmp285->f1;_tmp287=_tmp285->f2;}}
_LL18A: Cyc_Absyndump_dumpqvar(_tmp287->name);Cyc_Absyndump_dump_char((int)'<');
Cyc_Absyndump_dumptvar(_tmp286);Cyc_Absyndump_dump_char((int)'>');goto _LL16E;
_LL18B: {struct Cyc_Absyn_UnknownId_p_struct*_tmp288=(struct Cyc_Absyn_UnknownId_p_struct*)
_tmp25E;if(_tmp288->tag != 14)goto _LL18D;else{_tmp289=_tmp288->f1;}}_LL18C: Cyc_Absyndump_dumpqvar(
_tmp289);goto _LL16E;_LL18D: {struct Cyc_Absyn_UnknownCall_p_struct*_tmp28A=(
struct Cyc_Absyn_UnknownCall_p_struct*)_tmp25E;if(_tmp28A->tag != 15)goto _LL18F;
else{_tmp28B=_tmp28A->f1;_tmp28C=_tmp28A->f2;_tmp28D=_tmp28A->f3;}}_LL18E: {
const char*_tmp47B;const char*_tmp47A;struct _dyneither_ptr term=_tmp28D?(_tmp47B=", ...)",
_tag_dyneither(_tmp47B,sizeof(char),7)):((_tmp47A=")",_tag_dyneither(_tmp47A,
sizeof(char),2)));Cyc_Absyndump_dumpqvar(_tmp28B);{const char*_tmp47D;const char*
_tmp47C;((void(*)(void(*f)(struct Cyc_Absyn_Pat*),struct Cyc_List_List*l,struct
_dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dumppat,_tmp28C,((_tmp47C="(",_tag_dyneither(_tmp47C,sizeof(char),
2))),term,((_tmp47D=",",_tag_dyneither(_tmp47D,sizeof(char),2))));}goto _LL16E;}
_LL18F: {struct Cyc_Absyn_Aggr_p_struct*_tmp28E=(struct Cyc_Absyn_Aggr_p_struct*)
_tmp25E;if(_tmp28E->tag != 6)goto _LL191;else{_tmp28F=_tmp28E->f1;if(_tmp28F == 0)
goto _LL191;_tmp290=*_tmp28F;_tmp291=_tmp290.aggr_info;_tmp292=_tmp28E->f2;
_tmp293=_tmp28E->f3;_tmp294=_tmp28E->f4;}}_LL190: {struct _tuple0*_tmp2BB;struct
_tuple9 _tmp2BA=Cyc_Absyn_aggr_kinded_name(_tmp291);_tmp2BB=_tmp2BA.f2;{const char*
_tmp47F;const char*_tmp47E;struct _dyneither_ptr term=_tmp294?(_tmp47F=", ...)",
_tag_dyneither(_tmp47F,sizeof(char),7)):((_tmp47E=")",_tag_dyneither(_tmp47E,
sizeof(char),2)));Cyc_Absyndump_dumpqvar(_tmp2BB);Cyc_Absyndump_dump_char((int)'{');{
const char*_tmp482;const char*_tmp481;const char*_tmp480;((void(*)(void(*f)(struct
Cyc_Absyn_Tvar*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(Cyc_Absyndump_dumptvar,
_tmp292,((_tmp480="[",_tag_dyneither(_tmp480,sizeof(char),2))),((_tmp481="]",
_tag_dyneither(_tmp481,sizeof(char),2))),((_tmp482=",",_tag_dyneither(_tmp482,
sizeof(char),2))));}{const char*_tmp484;const char*_tmp483;((void(*)(void(*f)(
struct _tuple17*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(Cyc_Absyndump_dumpdp,
_tmp293,((_tmp483="",_tag_dyneither(_tmp483,sizeof(char),1))),term,((_tmp484=",",
_tag_dyneither(_tmp484,sizeof(char),2))));}goto _LL16E;};}_LL191: {struct Cyc_Absyn_Aggr_p_struct*
_tmp295=(struct Cyc_Absyn_Aggr_p_struct*)_tmp25E;if(_tmp295->tag != 6)goto _LL193;
else{_tmp296=_tmp295->f1;if(_tmp296 != 0)goto _LL193;_tmp297=_tmp295->f2;_tmp298=
_tmp295->f3;_tmp299=_tmp295->f4;}}_LL192: {const char*_tmp486;const char*_tmp485;
struct _dyneither_ptr term=_tmp299?(_tmp486=", ...)",_tag_dyneither(_tmp486,
sizeof(char),7)):((_tmp485=")",_tag_dyneither(_tmp485,sizeof(char),2)));Cyc_Absyndump_dump_char((
int)'{');{const char*_tmp489;const char*_tmp488;const char*_tmp487;((void(*)(void(*
f)(struct Cyc_Absyn_Tvar*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(Cyc_Absyndump_dumptvar,
_tmp297,((_tmp487="[",_tag_dyneither(_tmp487,sizeof(char),2))),((_tmp488="]",
_tag_dyneither(_tmp488,sizeof(char),2))),((_tmp489=",",_tag_dyneither(_tmp489,
sizeof(char),2))));}{const char*_tmp48B;const char*_tmp48A;((void(*)(void(*f)(
struct _tuple17*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(Cyc_Absyndump_dumpdp,
_tmp298,((_tmp48A="",_tag_dyneither(_tmp48A,sizeof(char),1))),term,((_tmp48B=",",
_tag_dyneither(_tmp48B,sizeof(char),2))));}goto _LL16E;}_LL193: {struct Cyc_Absyn_Datatype_p_struct*
_tmp29A=(struct Cyc_Absyn_Datatype_p_struct*)_tmp25E;if(_tmp29A->tag != 7)goto
_LL195;else{_tmp29B=_tmp29A->f2;_tmp29C=_tmp29A->f3;_tmp29D=_tmp29A->f4;}}_LL194: {
const char*_tmp48D;const char*_tmp48C;struct _dyneither_ptr term=_tmp29D?(_tmp48D=", ...)",
_tag_dyneither(_tmp48D,sizeof(char),7)):((_tmp48C=")",_tag_dyneither(_tmp48C,
sizeof(char),2)));Cyc_Absyndump_dumpqvar(_tmp29B->name);if(_tmp29C != 0){const
char*_tmp48F;const char*_tmp48E;((void(*)(void(*f)(struct Cyc_Absyn_Pat*),struct
Cyc_List_List*l,struct _dyneither_ptr start,struct _dyneither_ptr end,struct
_dyneither_ptr sep))Cyc_Absyndump_group)(Cyc_Absyndump_dumppat,_tmp29C,((_tmp48E="(",
_tag_dyneither(_tmp48E,sizeof(char),2))),term,((_tmp48F=",",_tag_dyneither(
_tmp48F,sizeof(char),2))));}goto _LL16E;}_LL195: {struct Cyc_Absyn_Enum_p_struct*
_tmp29E=(struct Cyc_Absyn_Enum_p_struct*)_tmp25E;if(_tmp29E->tag != 12)goto _LL197;
else{_tmp29F=_tmp29E->f2;}}_LL196: _tmp2A1=_tmp29F;goto _LL198;_LL197: {struct Cyc_Absyn_AnonEnum_p_struct*
_tmp2A0=(struct Cyc_Absyn_AnonEnum_p_struct*)_tmp25E;if(_tmp2A0->tag != 13)goto
_LL199;else{_tmp2A1=_tmp2A0->f2;}}_LL198: Cyc_Absyndump_dumpqvar(_tmp2A1->name);
goto _LL16E;_LL199: {struct Cyc_Absyn_Exp_p_struct*_tmp2A2=(struct Cyc_Absyn_Exp_p_struct*)
_tmp25E;if(_tmp2A2->tag != 16)goto _LL16E;else{_tmp2A3=_tmp2A2->f1;}}_LL19A: Cyc_Absyndump_dumpexp(
_tmp2A3);goto _LL16E;_LL16E:;}void Cyc_Absyndump_dumpdatatypefield(struct Cyc_Absyn_Datatypefield*
ef);void Cyc_Absyndump_dumpdatatypefield(struct Cyc_Absyn_Datatypefield*ef){Cyc_Absyndump_dumpqvar(
ef->name);if(ef->typs != 0)Cyc_Absyndump_dumpargs(ef->typs);}void Cyc_Absyndump_dumpdatatypefields(
struct Cyc_List_List*fields);void Cyc_Absyndump_dumpdatatypefields(struct Cyc_List_List*
fields){const char*_tmp490;((void(*)(void(*f)(struct Cyc_Absyn_Datatypefield*),
struct Cyc_List_List*l,struct _dyneither_ptr sep))Cyc_Absyndump_dump_sep)(Cyc_Absyndump_dumpdatatypefield,
fields,((_tmp490=",",_tag_dyneither(_tmp490,sizeof(char),2))));}void Cyc_Absyndump_dumpenumfield(
struct Cyc_Absyn_Enumfield*ef);void Cyc_Absyndump_dumpenumfield(struct Cyc_Absyn_Enumfield*
ef){Cyc_Absyndump_dumpqvar(ef->name);if(ef->tag != 0){{const char*_tmp491;Cyc_Absyndump_dump(((
_tmp491=" = ",_tag_dyneither(_tmp491,sizeof(char),4))));}Cyc_Absyndump_dumpexp((
struct Cyc_Absyn_Exp*)_check_null(ef->tag));}}void Cyc_Absyndump_dumpenumfields(
struct Cyc_List_List*fields);void Cyc_Absyndump_dumpenumfields(struct Cyc_List_List*
fields){const char*_tmp492;((void(*)(void(*f)(struct Cyc_Absyn_Enumfield*),struct
Cyc_List_List*l,struct _dyneither_ptr sep))Cyc_Absyndump_dump_sep)(Cyc_Absyndump_dumpenumfield,
fields,((_tmp492=",",_tag_dyneither(_tmp492,sizeof(char),2))));}void Cyc_Absyndump_dumpaggrfields(
struct Cyc_List_List*fields);void Cyc_Absyndump_dumpaggrfields(struct Cyc_List_List*
fields){for(0;fields != 0;fields=fields->tl){struct Cyc_Absyn_Aggrfield _tmp2D2;
struct _dyneither_ptr*_tmp2D3;struct Cyc_Absyn_Tqual _tmp2D4;void*_tmp2D5;struct Cyc_Absyn_Exp*
_tmp2D6;struct Cyc_List_List*_tmp2D7;struct Cyc_Absyn_Aggrfield*_tmp2D1=(struct Cyc_Absyn_Aggrfield*)
fields->hd;_tmp2D2=*_tmp2D1;_tmp2D3=_tmp2D2.name;_tmp2D4=_tmp2D2.tq;_tmp2D5=
_tmp2D2.type;_tmp2D6=_tmp2D2.width;_tmp2D7=_tmp2D2.attributes;switch(Cyc_Cyclone_c_compiler){
case Cyc_Cyclone_Gcc_c: _LL19B:((void(*)(struct Cyc_Absyn_Tqual,void*,void(*f)(
struct _dyneither_ptr*),struct _dyneither_ptr*))Cyc_Absyndump_dumptqtd)(_tmp2D4,
_tmp2D5,Cyc_Absyndump_dump_str,_tmp2D3);Cyc_Absyndump_dumpatts(_tmp2D7);break;
case Cyc_Cyclone_Vc_c: _LL19C: Cyc_Absyndump_dumpatts(_tmp2D7);((void(*)(struct Cyc_Absyn_Tqual,
void*,void(*f)(struct _dyneither_ptr*),struct _dyneither_ptr*))Cyc_Absyndump_dumptqtd)(
_tmp2D4,_tmp2D5,Cyc_Absyndump_dump_str,_tmp2D3);break;}if(_tmp2D6 != 0){Cyc_Absyndump_dump_char((
int)':');Cyc_Absyndump_dumpexp((struct Cyc_Absyn_Exp*)_tmp2D6);}Cyc_Absyndump_dump_semi();}}
void Cyc_Absyndump_dumptypedefname(struct Cyc_Absyn_Typedefdecl*td);void Cyc_Absyndump_dumptypedefname(
struct Cyc_Absyn_Typedefdecl*td){Cyc_Absyndump_dumpqvar(td->name);Cyc_Absyndump_dumptvars(
td->tvs);}static void Cyc_Absyndump_dump_atts_qvar(struct Cyc_Absyn_Fndecl*fd);
static void Cyc_Absyndump_dump_atts_qvar(struct Cyc_Absyn_Fndecl*fd){Cyc_Absyndump_dumpatts(
fd->attributes);Cyc_Absyndump_dumpqvar(fd->name);}struct _tuple18{void*f1;struct
_tuple0*f2;};static void Cyc_Absyndump_dump_callconv_qvar(struct _tuple18*pr);
static void Cyc_Absyndump_dump_callconv_qvar(struct _tuple18*pr){{void*_tmp2D8=(*pr).f1;
_LL19F: {struct Cyc_Absyn_Unused_att_struct*_tmp2D9=(struct Cyc_Absyn_Unused_att_struct*)
_tmp2D8;if(_tmp2D9->tag != 11)goto _LL1A1;}_LL1A0: goto _LL19E;_LL1A1: {struct Cyc_Absyn_Stdcall_att_struct*
_tmp2DA=(struct Cyc_Absyn_Stdcall_att_struct*)_tmp2D8;if(_tmp2DA->tag != 1)goto
_LL1A3;}_LL1A2:{const char*_tmp493;Cyc_Absyndump_dump(((_tmp493="_stdcall",
_tag_dyneither(_tmp493,sizeof(char),9))));}goto _LL19E;_LL1A3: {struct Cyc_Absyn_Cdecl_att_struct*
_tmp2DB=(struct Cyc_Absyn_Cdecl_att_struct*)_tmp2D8;if(_tmp2DB->tag != 2)goto
_LL1A5;}_LL1A4:{const char*_tmp494;Cyc_Absyndump_dump(((_tmp494="_cdecl",
_tag_dyneither(_tmp494,sizeof(char),7))));}goto _LL19E;_LL1A5: {struct Cyc_Absyn_Fastcall_att_struct*
_tmp2DC=(struct Cyc_Absyn_Fastcall_att_struct*)_tmp2D8;if(_tmp2DC->tag != 3)goto
_LL1A7;}_LL1A6:{const char*_tmp495;Cyc_Absyndump_dump(((_tmp495="_fastcall",
_tag_dyneither(_tmp495,sizeof(char),10))));}goto _LL19E;_LL1A7:;_LL1A8: goto _LL19E;
_LL19E:;}Cyc_Absyndump_dumpqvar((*pr).f2);}static void Cyc_Absyndump_dump_callconv_fdqvar(
struct Cyc_Absyn_Fndecl*fd);static void Cyc_Absyndump_dump_callconv_fdqvar(struct
Cyc_Absyn_Fndecl*fd){Cyc_Absyndump_dump_callconv(fd->attributes);Cyc_Absyndump_dumpqvar(
fd->name);}static void Cyc_Absyndump_dumpids(struct Cyc_List_List*vds);static void
Cyc_Absyndump_dumpids(struct Cyc_List_List*vds){for(0;vds != 0;vds=vds->tl){Cyc_Absyndump_dumpqvar(((
struct Cyc_Absyn_Vardecl*)vds->hd)->name);if(vds->tl != 0)Cyc_Absyndump_dump_char((
int)',');}}void Cyc_Absyndump_dumpvardecl(struct Cyc_Absyn_Vardecl*vd,struct Cyc_Position_Segment*
loc);void Cyc_Absyndump_dumpvardecl(struct Cyc_Absyn_Vardecl*vd,struct Cyc_Position_Segment*
loc){struct Cyc_Absyn_Vardecl _tmp2E1;enum Cyc_Absyn_Scope _tmp2E2;struct _tuple0*
_tmp2E3;struct Cyc_Absyn_Tqual _tmp2E4;void*_tmp2E5;struct Cyc_Absyn_Exp*_tmp2E6;
struct Cyc_List_List*_tmp2E7;struct Cyc_Absyn_Vardecl*_tmp2E0=vd;_tmp2E1=*_tmp2E0;
_tmp2E2=_tmp2E1.sc;_tmp2E3=_tmp2E1.name;_tmp2E4=_tmp2E1.tq;_tmp2E5=_tmp2E1.type;
_tmp2E6=_tmp2E1.initializer;_tmp2E7=_tmp2E1.attributes;Cyc_Absyndump_dumploc(loc);
switch(Cyc_Cyclone_c_compiler){case Cyc_Cyclone_Gcc_c: _LL1A9: if(_tmp2E2 == Cyc_Absyn_Extern
 && Cyc_Absyndump_qvar_to_Cids){void*_tmp2E8=Cyc_Tcutil_compress(_tmp2E5);_LL1AC: {
struct Cyc_Absyn_FnType_struct*_tmp2E9=(struct Cyc_Absyn_FnType_struct*)_tmp2E8;
if(_tmp2E9->tag != 10)goto _LL1AE;}_LL1AD: goto _LL1AB;_LL1AE:;_LL1AF: Cyc_Absyndump_dumpscope(
_tmp2E2);_LL1AB:;}else{Cyc_Absyndump_dumpscope(_tmp2E2);}((void(*)(struct Cyc_Absyn_Tqual,
void*,void(*f)(struct _tuple0*),struct _tuple0*))Cyc_Absyndump_dumptqtd)(_tmp2E4,
_tmp2E5,Cyc_Absyndump_dumpqvar,_tmp2E3);Cyc_Absyndump_dumpatts(_tmp2E7);break;
case Cyc_Cyclone_Vc_c: _LL1AA: Cyc_Absyndump_dumpatts(_tmp2E7);Cyc_Absyndump_dumpscope(
_tmp2E2);{struct _RegionHandle _tmp2EA=_new_region("temp");struct _RegionHandle*
temp=& _tmp2EA;_push_region(temp);{struct Cyc_Absyn_Tqual _tmp2EC;void*_tmp2ED;
struct Cyc_List_List*_tmp2EE;struct _tuple11 _tmp2EB=Cyc_Absynpp_to_tms(temp,
_tmp2E4,_tmp2E5);_tmp2EC=_tmp2EB.f1;_tmp2ED=_tmp2EB.f2;_tmp2EE=_tmp2EB.f3;{void*
call_conv=(void*)& Cyc_Absyn_Unused_att_val;{struct Cyc_List_List*tms2=_tmp2EE;
for(0;tms2 != 0;tms2=tms2->tl){void*_tmp2EF=(void*)tms2->hd;struct Cyc_List_List*
_tmp2F1;_LL1B2: {struct Cyc_Absyn_Attributes_mod_struct*_tmp2F0=(struct Cyc_Absyn_Attributes_mod_struct*)
_tmp2EF;if(_tmp2F0->tag != 5)goto _LL1B4;else{_tmp2F1=_tmp2F0->f2;}}_LL1B3: for(0;
_tmp2F1 != 0;_tmp2F1=_tmp2F1->tl){void*_tmp2F2=(void*)_tmp2F1->hd;_LL1B7: {struct
Cyc_Absyn_Stdcall_att_struct*_tmp2F3=(struct Cyc_Absyn_Stdcall_att_struct*)
_tmp2F2;if(_tmp2F3->tag != 1)goto _LL1B9;}_LL1B8: call_conv=(void*)& Cyc_Absyn_Stdcall_att_val;
goto _LL1B6;_LL1B9: {struct Cyc_Absyn_Cdecl_att_struct*_tmp2F4=(struct Cyc_Absyn_Cdecl_att_struct*)
_tmp2F2;if(_tmp2F4->tag != 2)goto _LL1BB;}_LL1BA: call_conv=(void*)& Cyc_Absyn_Cdecl_att_val;
goto _LL1B6;_LL1BB: {struct Cyc_Absyn_Fastcall_att_struct*_tmp2F5=(struct Cyc_Absyn_Fastcall_att_struct*)
_tmp2F2;if(_tmp2F5->tag != 3)goto _LL1BD;}_LL1BC: call_conv=(void*)& Cyc_Absyn_Fastcall_att_val;
goto _LL1B6;_LL1BD:;_LL1BE: goto _LL1B6;_LL1B6:;}goto _LL1B1;_LL1B4:;_LL1B5: goto
_LL1B1;_LL1B1:;}}Cyc_Absyndump_dumptq(_tmp2EC);Cyc_Absyndump_dumpntyp(_tmp2ED);{
struct _tuple18 _tmp496;struct _tuple18 _tmp2F6=(_tmp496.f1=call_conv,((_tmp496.f2=
_tmp2E3,_tmp496)));((void(*)(struct Cyc_List_List*tms,void(*f)(struct _tuple18*),
struct _tuple18*a))Cyc_Absyndump_dumptms)(((struct Cyc_List_List*(*)(struct Cyc_List_List*
x))Cyc_List_imp_rev)(_tmp2EE),Cyc_Absyndump_dump_callconv_qvar,& _tmp2F6);};};}
_npop_handler(0);break;;_pop_region(temp);};}if(_tmp2E6 != 0){Cyc_Absyndump_dump_char((
int)'=');Cyc_Absyndump_dumpexp((struct Cyc_Absyn_Exp*)_tmp2E6);}Cyc_Absyndump_dump_semi();}
struct _tuple19{struct Cyc_Position_Segment*f1;struct _tuple0*f2;int f3;};void Cyc_Absyndump_dumpdecl(
struct Cyc_Absyn_Decl*d);void Cyc_Absyndump_dumpdecl(struct Cyc_Absyn_Decl*d){void*
_tmp2F8=d->r;struct Cyc_Absyn_Vardecl*_tmp2FA;struct Cyc_Absyn_Fndecl*_tmp2FC;
struct Cyc_Absyn_Aggrdecl*_tmp2FE;struct Cyc_Absyn_Datatypedecl*_tmp300;struct Cyc_Absyn_Datatypedecl
_tmp301;enum Cyc_Absyn_Scope _tmp302;struct _tuple0*_tmp303;struct Cyc_List_List*
_tmp304;struct Cyc_Core_Opt*_tmp305;int _tmp306;struct Cyc_Absyn_Enumdecl*_tmp308;
struct Cyc_Absyn_Enumdecl _tmp309;enum Cyc_Absyn_Scope _tmp30A;struct _tuple0*
_tmp30B;struct Cyc_Core_Opt*_tmp30C;struct Cyc_Absyn_Pat*_tmp30E;struct Cyc_Absyn_Exp*
_tmp30F;struct Cyc_List_List*_tmp311;struct Cyc_Absyn_Tvar*_tmp313;struct Cyc_Absyn_Vardecl*
_tmp314;int _tmp315;struct Cyc_Absyn_Exp*_tmp316;struct Cyc_Absyn_Exp*_tmp318;
struct Cyc_Absyn_Tvar*_tmp319;struct Cyc_Absyn_Vardecl*_tmp31A;struct Cyc_Absyn_Typedefdecl*
_tmp31C;struct _dyneither_ptr*_tmp31E;struct Cyc_List_List*_tmp31F;struct _tuple0*
_tmp321;struct Cyc_List_List*_tmp322;struct Cyc_List_List*_tmp324;struct Cyc_List_List*
_tmp326;struct Cyc_List_List*_tmp327;_LL1C0: {struct Cyc_Absyn_Var_d_struct*
_tmp2F9=(struct Cyc_Absyn_Var_d_struct*)_tmp2F8;if(_tmp2F9->tag != 0)goto _LL1C2;
else{_tmp2FA=_tmp2F9->f1;}}_LL1C1: Cyc_Absyndump_dumpvardecl(_tmp2FA,d->loc);goto
_LL1BF;_LL1C2: {struct Cyc_Absyn_Fn_d_struct*_tmp2FB=(struct Cyc_Absyn_Fn_d_struct*)
_tmp2F8;if(_tmp2FB->tag != 1)goto _LL1C4;else{_tmp2FC=_tmp2FB->f1;}}_LL1C3: Cyc_Absyndump_dumploc(
d->loc);switch(Cyc_Cyclone_c_compiler){case Cyc_Cyclone_Vc_c: _LL1E0: Cyc_Absyndump_dumpatts(
_tmp2FC->attributes);break;case Cyc_Cyclone_Gcc_c: _LL1E1: break;}if(_tmp2FC->is_inline){
enum Cyc_Cyclone_C_Compilers _tmp32A=Cyc_Cyclone_c_compiler;_LL1E4: if(_tmp32A != 
Cyc_Cyclone_Vc_c)goto _LL1E6;_LL1E5:{const char*_tmp497;Cyc_Absyndump_dump(((
_tmp497="__inline",_tag_dyneither(_tmp497,sizeof(char),9))));}goto _LL1E3;_LL1E6:;
_LL1E7:{const char*_tmp498;Cyc_Absyndump_dump(((_tmp498="inline",_tag_dyneither(
_tmp498,sizeof(char),7))));}goto _LL1E3;_LL1E3:;}Cyc_Absyndump_dumpscope(_tmp2FC->sc);{
struct Cyc_Absyn_FnType_struct _tmp49E;struct Cyc_Absyn_FnInfo _tmp49D;struct Cyc_Absyn_FnType_struct*
_tmp49C;void*t=(void*)((_tmp49C=_cycalloc(sizeof(*_tmp49C)),((_tmp49C[0]=((
_tmp49E.tag=10,((_tmp49E.f1=((_tmp49D.tvars=_tmp2FC->tvs,((_tmp49D.effect=
_tmp2FC->effect,((_tmp49D.ret_typ=_tmp2FC->ret_type,((_tmp49D.args=((struct Cyc_List_List*(*)(
struct _tuple7*(*f)(struct _tuple10*),struct Cyc_List_List*x))Cyc_List_map)(Cyc_Absynpp_arg_mk_opt,
_tmp2FC->args),((_tmp49D.c_varargs=_tmp2FC->c_varargs,((_tmp49D.cyc_varargs=
_tmp2FC->cyc_varargs,((_tmp49D.rgn_po=_tmp2FC->rgn_po,((_tmp49D.attributes=0,
_tmp49D)))))))))))))))),_tmp49E)))),_tmp49C))));switch(Cyc_Cyclone_c_compiler){
case Cyc_Cyclone_Gcc_c: _LL1E8:((void(*)(struct Cyc_Absyn_Tqual,void*,void(*f)(
struct Cyc_Absyn_Fndecl*),struct Cyc_Absyn_Fndecl*))Cyc_Absyndump_dumptqtd)(Cyc_Absyn_empty_tqual(
0),t,Cyc_Absyndump_dump_atts_qvar,_tmp2FC);break;case Cyc_Cyclone_Vc_c: _LL1E9:((
void(*)(struct Cyc_Absyn_Tqual,void*,void(*f)(struct Cyc_Absyn_Fndecl*),struct Cyc_Absyn_Fndecl*))
Cyc_Absyndump_dumptqtd)(Cyc_Absyn_empty_tqual(0),t,Cyc_Absyndump_dump_callconv_fdqvar,
_tmp2FC);break;}Cyc_Absyndump_dump_char((int)'{');Cyc_Absyndump_dumpstmt(_tmp2FC->body,
0);Cyc_Absyndump_dump_char((int)'}');goto _LL1BF;};_LL1C4: {struct Cyc_Absyn_Aggr_d_struct*
_tmp2FD=(struct Cyc_Absyn_Aggr_d_struct*)_tmp2F8;if(_tmp2FD->tag != 6)goto _LL1C6;
else{_tmp2FE=_tmp2FD->f1;}}_LL1C5: Cyc_Absyndump_dumpscope(_tmp2FE->sc);Cyc_Absyndump_dumpaggr_kind(
_tmp2FE->kind);Cyc_Absyndump_dumpqvar(_tmp2FE->name);Cyc_Absyndump_dumptvars(
_tmp2FE->tvs);if(_tmp2FE->impl == 0)Cyc_Absyndump_dump_semi();else{Cyc_Absyndump_dump_char((
int)'{');if(((struct Cyc_Absyn_AggrdeclImpl*)_check_null(_tmp2FE->impl))->exist_vars
!= 0){const char*_tmp4A1;const char*_tmp4A0;const char*_tmp49F;((void(*)(void(*f)(
struct Cyc_Absyn_Tvar*),struct Cyc_List_List*l,struct _dyneither_ptr start,struct
_dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_egroup)(Cyc_Absyndump_dumpkindedtvar,((
struct Cyc_Absyn_AggrdeclImpl*)_check_null(_tmp2FE->impl))->exist_vars,((_tmp49F="<",
_tag_dyneither(_tmp49F,sizeof(char),2))),((_tmp4A0=">",_tag_dyneither(_tmp4A0,
sizeof(char),2))),((_tmp4A1=",",_tag_dyneither(_tmp4A1,sizeof(char),2))));}if(((
struct Cyc_Absyn_AggrdeclImpl*)_check_null(_tmp2FE->impl))->rgn_po != 0){Cyc_Absyndump_dump_char((
int)':');Cyc_Absyndump_dump_rgnpo(((struct Cyc_Absyn_AggrdeclImpl*)_check_null(
_tmp2FE->impl))->rgn_po);}Cyc_Absyndump_dumpaggrfields(((struct Cyc_Absyn_AggrdeclImpl*)
_check_null(_tmp2FE->impl))->fields);{const char*_tmp4A2;Cyc_Absyndump_dump(((
_tmp4A2="}",_tag_dyneither(_tmp4A2,sizeof(char),2))));}Cyc_Absyndump_dumpatts(
_tmp2FE->attributes);{const char*_tmp4A3;Cyc_Absyndump_dump(((_tmp4A3=";",
_tag_dyneither(_tmp4A3,sizeof(char),2))));};}goto _LL1BF;_LL1C6: {struct Cyc_Absyn_Datatype_d_struct*
_tmp2FF=(struct Cyc_Absyn_Datatype_d_struct*)_tmp2F8;if(_tmp2FF->tag != 7)goto
_LL1C8;else{_tmp300=_tmp2FF->f1;_tmp301=*_tmp300;_tmp302=_tmp301.sc;_tmp303=
_tmp301.name;_tmp304=_tmp301.tvs;_tmp305=_tmp301.fields;_tmp306=_tmp301.is_extensible;}}
_LL1C7: Cyc_Absyndump_dumpscope(_tmp302);if(_tmp306){const char*_tmp4A4;Cyc_Absyndump_dump(((
_tmp4A4="@extensible ",_tag_dyneither(_tmp4A4,sizeof(char),13))));}{const char*
_tmp4A5;Cyc_Absyndump_dump(((_tmp4A5="datatype ",_tag_dyneither(_tmp4A5,sizeof(
char),10))));}Cyc_Absyndump_dumpqvar(_tmp303);Cyc_Absyndump_dumptvars(_tmp304);
if(_tmp305 == 0)Cyc_Absyndump_dump_semi();else{Cyc_Absyndump_dump_char((int)'{');
Cyc_Absyndump_dumpdatatypefields((struct Cyc_List_List*)_tmp305->v);{const char*
_tmp4A6;Cyc_Absyndump_dump_nospace(((_tmp4A6="};",_tag_dyneither(_tmp4A6,sizeof(
char),3))));};}goto _LL1BF;_LL1C8: {struct Cyc_Absyn_Enum_d_struct*_tmp307=(struct
Cyc_Absyn_Enum_d_struct*)_tmp2F8;if(_tmp307->tag != 8)goto _LL1CA;else{_tmp308=
_tmp307->f1;_tmp309=*_tmp308;_tmp30A=_tmp309.sc;_tmp30B=_tmp309.name;_tmp30C=
_tmp309.fields;}}_LL1C9: Cyc_Absyndump_dumpscope(_tmp30A);{const char*_tmp4A7;Cyc_Absyndump_dump(((
_tmp4A7="enum ",_tag_dyneither(_tmp4A7,sizeof(char),6))));}Cyc_Absyndump_dumpqvar(
_tmp30B);if(_tmp30C == 0)Cyc_Absyndump_dump_semi();else{Cyc_Absyndump_dump_char((
int)'{');Cyc_Absyndump_dumpenumfields((struct Cyc_List_List*)_tmp30C->v);{const
char*_tmp4A8;Cyc_Absyndump_dump_nospace(((_tmp4A8="};",_tag_dyneither(_tmp4A8,
sizeof(char),3))));};}return;_LL1CA: {struct Cyc_Absyn_Let_d_struct*_tmp30D=(
struct Cyc_Absyn_Let_d_struct*)_tmp2F8;if(_tmp30D->tag != 2)goto _LL1CC;else{
_tmp30E=_tmp30D->f1;_tmp30F=_tmp30D->f3;}}_LL1CB:{const char*_tmp4A9;Cyc_Absyndump_dump(((
_tmp4A9="let",_tag_dyneither(_tmp4A9,sizeof(char),4))));}Cyc_Absyndump_dumppat(
_tmp30E);Cyc_Absyndump_dump_char((int)'=');Cyc_Absyndump_dumpexp(_tmp30F);Cyc_Absyndump_dump_semi();
goto _LL1BF;_LL1CC: {struct Cyc_Absyn_Letv_d_struct*_tmp310=(struct Cyc_Absyn_Letv_d_struct*)
_tmp2F8;if(_tmp310->tag != 3)goto _LL1CE;else{_tmp311=_tmp310->f1;}}_LL1CD:{const
char*_tmp4AA;Cyc_Absyndump_dump(((_tmp4AA="let ",_tag_dyneither(_tmp4AA,sizeof(
char),5))));}Cyc_Absyndump_dumpids(_tmp311);Cyc_Absyndump_dump_semi();goto _LL1BF;
_LL1CE: {struct Cyc_Absyn_Region_d_struct*_tmp312=(struct Cyc_Absyn_Region_d_struct*)
_tmp2F8;if(_tmp312->tag != 4)goto _LL1D0;else{_tmp313=_tmp312->f1;_tmp314=_tmp312->f2;
_tmp315=_tmp312->f3;_tmp316=_tmp312->f4;}}_LL1CF:{const char*_tmp4AB;Cyc_Absyndump_dump(((
_tmp4AB="region",_tag_dyneither(_tmp4AB,sizeof(char),7))));}{const char*_tmp4AC;
Cyc_Absyndump_dump(((_tmp4AC="<",_tag_dyneither(_tmp4AC,sizeof(char),2))));}Cyc_Absyndump_dumptvar(
_tmp313);{const char*_tmp4AD;Cyc_Absyndump_dump(((_tmp4AD="> ",_tag_dyneither(
_tmp4AD,sizeof(char),3))));}Cyc_Absyndump_dumpqvar(_tmp314->name);if(_tmp315){
const char*_tmp4AE;Cyc_Absyndump_dump(((_tmp4AE="@resetable",_tag_dyneither(
_tmp4AE,sizeof(char),11))));}if(_tmp316 != 0){{const char*_tmp4AF;Cyc_Absyndump_dump(((
_tmp4AF=" = open(",_tag_dyneither(_tmp4AF,sizeof(char),9))));}Cyc_Absyndump_dumpexp((
struct Cyc_Absyn_Exp*)_tmp316);{const char*_tmp4B0;Cyc_Absyndump_dump(((_tmp4B0=")",
_tag_dyneither(_tmp4B0,sizeof(char),2))));};}Cyc_Absyndump_dump_semi();goto
_LL1BF;_LL1D0: {struct Cyc_Absyn_Alias_d_struct*_tmp317=(struct Cyc_Absyn_Alias_d_struct*)
_tmp2F8;if(_tmp317->tag != 5)goto _LL1D2;else{_tmp318=_tmp317->f1;_tmp319=_tmp317->f2;
_tmp31A=_tmp317->f3;}}_LL1D1:{const char*_tmp4B1;Cyc_Absyndump_dump(((_tmp4B1="alias ",
_tag_dyneither(_tmp4B1,sizeof(char),7))));}{const char*_tmp4B2;Cyc_Absyndump_dump(((
_tmp4B2="<",_tag_dyneither(_tmp4B2,sizeof(char),2))));}Cyc_Absyndump_dumptvar(
_tmp319);{const char*_tmp4B3;Cyc_Absyndump_dump(((_tmp4B3=">",_tag_dyneither(
_tmp4B3,sizeof(char),2))));}Cyc_Absyndump_dumpqvar(_tmp31A->name);{const char*
_tmp4B4;Cyc_Absyndump_dump(((_tmp4B4=" = ",_tag_dyneither(_tmp4B4,sizeof(char),4))));}
Cyc_Absyndump_dumpexp(_tmp318);Cyc_Absyndump_dump_semi();goto _LL1BF;_LL1D2: {
struct Cyc_Absyn_Typedef_d_struct*_tmp31B=(struct Cyc_Absyn_Typedef_d_struct*)
_tmp2F8;if(_tmp31B->tag != 9)goto _LL1D4;else{_tmp31C=_tmp31B->f1;}}_LL1D3: if(!Cyc_Absyndump_expand_typedefs
 || _tmp31C->defn != 0  && Cyc_Absynpp_is_anon_aggrtype((void*)((struct Cyc_Core_Opt*)
_check_null(_tmp31C->defn))->v)){{const char*_tmp4B5;Cyc_Absyndump_dump(((_tmp4B5="typedef",
_tag_dyneither(_tmp4B5,sizeof(char),8))));}{void*t;if(_tmp31C->defn == 0)t=Cyc_Absyn_new_evar(
_tmp31C->kind,0);else{t=(void*)((struct Cyc_Core_Opt*)_check_null(_tmp31C->defn))->v;}((
void(*)(struct Cyc_Absyn_Tqual,void*,void(*f)(struct Cyc_Absyn_Typedefdecl*),
struct Cyc_Absyn_Typedefdecl*))Cyc_Absyndump_dumptqtd)(_tmp31C->tq,t,Cyc_Absyndump_dumptypedefname,
_tmp31C);Cyc_Absyndump_dumpatts(_tmp31C->atts);Cyc_Absyndump_dump_semi();};}goto
_LL1BF;_LL1D4: {struct Cyc_Absyn_Namespace_d_struct*_tmp31D=(struct Cyc_Absyn_Namespace_d_struct*)
_tmp2F8;if(_tmp31D->tag != 10)goto _LL1D6;else{_tmp31E=_tmp31D->f1;_tmp31F=_tmp31D->f2;}}
_LL1D5:{const char*_tmp4B6;Cyc_Absyndump_dump(((_tmp4B6="namespace",
_tag_dyneither(_tmp4B6,sizeof(char),10))));}Cyc_Absyndump_dump_str(_tmp31E);Cyc_Absyndump_dump_char((
int)'{');for(0;_tmp31F != 0;_tmp31F=_tmp31F->tl){Cyc_Absyndump_dumpdecl((struct
Cyc_Absyn_Decl*)_tmp31F->hd);}Cyc_Absyndump_dump_char((int)'}');goto _LL1BF;
_LL1D6: {struct Cyc_Absyn_Using_d_struct*_tmp320=(struct Cyc_Absyn_Using_d_struct*)
_tmp2F8;if(_tmp320->tag != 11)goto _LL1D8;else{_tmp321=_tmp320->f1;_tmp322=_tmp320->f2;}}
_LL1D7:{const char*_tmp4B7;Cyc_Absyndump_dump(((_tmp4B7="using",_tag_dyneither(
_tmp4B7,sizeof(char),6))));}Cyc_Absyndump_dumpqvar(_tmp321);Cyc_Absyndump_dump_char((
int)'{');for(0;_tmp322 != 0;_tmp322=_tmp322->tl){Cyc_Absyndump_dumpdecl((struct
Cyc_Absyn_Decl*)_tmp322->hd);}Cyc_Absyndump_dump_char((int)'}');goto _LL1BF;
_LL1D8: {struct Cyc_Absyn_ExternC_d_struct*_tmp323=(struct Cyc_Absyn_ExternC_d_struct*)
_tmp2F8;if(_tmp323->tag != 12)goto _LL1DA;else{_tmp324=_tmp323->f1;}}_LL1D9:{const
char*_tmp4B8;Cyc_Absyndump_dump(((_tmp4B8="extern \"C\" {",_tag_dyneither(
_tmp4B8,sizeof(char),13))));}for(0;_tmp324 != 0;_tmp324=_tmp324->tl){Cyc_Absyndump_dumpdecl((
struct Cyc_Absyn_Decl*)_tmp324->hd);}Cyc_Absyndump_dump_char((int)'}');goto _LL1BF;
_LL1DA: {struct Cyc_Absyn_ExternCinclude_d_struct*_tmp325=(struct Cyc_Absyn_ExternCinclude_d_struct*)
_tmp2F8;if(_tmp325->tag != 13)goto _LL1DC;else{_tmp326=_tmp325->f1;_tmp327=_tmp325->f2;}}
_LL1DB:{const char*_tmp4B9;Cyc_Absyndump_dump(((_tmp4B9="extern \"C include\" {",
_tag_dyneither(_tmp4B9,sizeof(char),21))));}for(0;_tmp326 != 0;_tmp326=_tmp326->tl){
Cyc_Absyndump_dumpdecl((struct Cyc_Absyn_Decl*)_tmp326->hd);}Cyc_Absyndump_dump_char((
int)'}');if(_tmp327 != 0){{const char*_tmp4BA;Cyc_Absyndump_dump(((_tmp4BA=" export {",
_tag_dyneither(_tmp4BA,sizeof(char),10))));}for(0;_tmp327 != 0;_tmp327=_tmp327->tl){
struct _tuple0*_tmp34D;struct _tuple19 _tmp34C=*((struct _tuple19*)_tmp327->hd);
_tmp34D=_tmp34C.f2;Cyc_Absyndump_dumpqvar(_tmp34D);if(_tmp327->tl != 0)Cyc_Absyndump_dump_char((
int)',');}{const char*_tmp4BB;Cyc_Absyndump_dump(((_tmp4BB="}",_tag_dyneither(
_tmp4BB,sizeof(char),2))));};}goto _LL1BF;_LL1DC: {struct Cyc_Absyn_Porton_d_struct*
_tmp328=(struct Cyc_Absyn_Porton_d_struct*)_tmp2F8;if(_tmp328->tag != 14)goto
_LL1DE;}_LL1DD:{const char*_tmp4BC;Cyc_Absyndump_dump(((_tmp4BC=" __cyclone_port_on__; ",
_tag_dyneither(_tmp4BC,sizeof(char),23))));}goto _LL1BF;_LL1DE: {struct Cyc_Absyn_Portoff_d_struct*
_tmp329=(struct Cyc_Absyn_Portoff_d_struct*)_tmp2F8;if(_tmp329->tag != 15)goto
_LL1BF;}_LL1DF:{const char*_tmp4BD;Cyc_Absyndump_dump(((_tmp4BD=" __cyclone_port_off__; ",
_tag_dyneither(_tmp4BD,sizeof(char),24))));}goto _LL1BF;_LL1BF:;}static void Cyc_Absyndump_dump_upperbound(
struct Cyc_Absyn_Exp*e);static void Cyc_Absyndump_dump_upperbound(struct Cyc_Absyn_Exp*
e){struct _tuple12 pr=Cyc_Evexp_eval_const_uint_exp(e);if(pr.f1 != 1  || !pr.f2){Cyc_Absyndump_dump_char((
int)'{');Cyc_Absyndump_dumpexp(e);Cyc_Absyndump_dump_char((int)'}');}}void Cyc_Absyndump_dumptms(
struct Cyc_List_List*tms,void(*f)(void*),void*a);void Cyc_Absyndump_dumptms(struct
Cyc_List_List*tms,void(*f)(void*),void*a){if(tms == 0){f(a);return;}{void*_tmp351=(
void*)tms->hd;struct Cyc_Absyn_PtrAtts _tmp353;void*_tmp354;union Cyc_Absyn_Constraint*
_tmp355;union Cyc_Absyn_Constraint*_tmp356;union Cyc_Absyn_Constraint*_tmp357;
struct Cyc_Absyn_Tqual _tmp358;_LL1EC: {struct Cyc_Absyn_Pointer_mod_struct*_tmp352=(
struct Cyc_Absyn_Pointer_mod_struct*)_tmp351;if(_tmp352->tag != 2)goto _LL1EE;else{
_tmp353=_tmp352->f1;_tmp354=_tmp353.rgn;_tmp355=_tmp353.nullable;_tmp356=_tmp353.bounds;
_tmp357=_tmp353.zero_term;_tmp358=_tmp352->f2;}}_LL1ED:{void*_tmp359=((void*(*)(
void*y,union Cyc_Absyn_Constraint*x))Cyc_Absyn_conref_def)(Cyc_Absyn_bounds_one,
_tmp356);struct Cyc_Absyn_Exp*_tmp35C;_LL1F1: {struct Cyc_Absyn_DynEither_b_struct*
_tmp35A=(struct Cyc_Absyn_DynEither_b_struct*)_tmp359;if(_tmp35A->tag != 0)goto
_LL1F3;}_LL1F2: Cyc_Absyndump_dump_char((int)'?');goto _LL1F0;_LL1F3: {struct Cyc_Absyn_Upper_b_struct*
_tmp35B=(struct Cyc_Absyn_Upper_b_struct*)_tmp359;if(_tmp35B->tag != 1)goto _LL1F0;
else{_tmp35C=_tmp35B->f1;}}_LL1F4: Cyc_Absyndump_dump_char((int)(((int(*)(int y,
union Cyc_Absyn_Constraint*x))Cyc_Absyn_conref_def)(1,_tmp355)?'*':'@'));Cyc_Absyndump_dump_upperbound(
_tmp35C);goto _LL1F0;_LL1F0:;}if(((int(*)(int y,union Cyc_Absyn_Constraint*x))Cyc_Absyn_conref_def)(
0,_tmp357)){const char*_tmp4BE;Cyc_Absyndump_dump(((_tmp4BE="@zeroterm",
_tag_dyneither(_tmp4BE,sizeof(char),10))));}{void*_tmp35E=Cyc_Tcutil_compress(
_tmp354);struct Cyc_Absyn_Tvar*_tmp362;struct Cyc_Core_Opt*_tmp364;_LL1F6: {struct
Cyc_Absyn_HeapRgn_struct*_tmp35F=(struct Cyc_Absyn_HeapRgn_struct*)_tmp35E;if(
_tmp35F->tag != 21)goto _LL1F8;}_LL1F7: goto _LL1F5;_LL1F8: {struct Cyc_Absyn_UniqueRgn_struct*
_tmp360=(struct Cyc_Absyn_UniqueRgn_struct*)_tmp35E;if(_tmp360->tag != 22)goto
_LL1FA;}_LL1F9:{const char*_tmp4BF;Cyc_Absyndump_dump(((_tmp4BF="`U",
_tag_dyneither(_tmp4BF,sizeof(char),3))));}goto _LL1F5;_LL1FA: {struct Cyc_Absyn_VarType_struct*
_tmp361=(struct Cyc_Absyn_VarType_struct*)_tmp35E;if(_tmp361->tag != 2)goto _LL1FC;
else{_tmp362=_tmp361->f1;}}_LL1FB: Cyc_Absyndump_dump_str(_tmp362->name);goto
_LL1F5;_LL1FC: {struct Cyc_Absyn_Evar_struct*_tmp363=(struct Cyc_Absyn_Evar_struct*)
_tmp35E;if(_tmp363->tag != 1)goto _LL1FE;else{_tmp364=_tmp363->f2;if(_tmp364 != 0)
goto _LL1FE;}}_LL1FD: Cyc_Absyndump_dumpntyp(Cyc_Tcutil_compress(_tmp354));goto
_LL1F5;_LL1FE:;_LL1FF: {const char*_tmp4C2;void*_tmp4C1;(_tmp4C1=0,Cyc_Tcutil_impos(((
_tmp4C2="dumptms: bad rgn type in Pointer_mod",_tag_dyneither(_tmp4C2,sizeof(
char),37))),_tag_dyneither(_tmp4C1,sizeof(void*),0)));}_LL1F5:;}Cyc_Absyndump_dumptq(
_tmp358);Cyc_Absyndump_dumptms(tms->tl,f,a);return;_LL1EE:;_LL1EF: {int
next_is_pointer=0;if(tms->tl != 0){void*_tmp368=(void*)((struct Cyc_List_List*)
_check_null(tms->tl))->hd;_LL201: {struct Cyc_Absyn_Pointer_mod_struct*_tmp369=(
struct Cyc_Absyn_Pointer_mod_struct*)_tmp368;if(_tmp369->tag != 2)goto _LL203;}
_LL202: next_is_pointer=1;goto _LL200;_LL203:;_LL204: goto _LL200;_LL200:;}if(
next_is_pointer)Cyc_Absyndump_dump_char((int)'(');Cyc_Absyndump_dumptms(tms->tl,
f,a);if(next_is_pointer)Cyc_Absyndump_dump_char((int)')');{void*_tmp36A=(void*)
tms->hd;union Cyc_Absyn_Constraint*_tmp36C;struct Cyc_Absyn_Exp*_tmp36E;union Cyc_Absyn_Constraint*
_tmp36F;void*_tmp371;struct Cyc_List_List*_tmp373;int _tmp374;struct Cyc_Absyn_VarargInfo*
_tmp375;struct Cyc_Core_Opt*_tmp376;struct Cyc_List_List*_tmp377;void*_tmp379;
struct Cyc_List_List*_tmp37B;struct Cyc_Position_Segment*_tmp37C;struct Cyc_List_List*
_tmp37E;struct Cyc_Position_Segment*_tmp37F;int _tmp380;struct Cyc_List_List*
_tmp382;_LL206: {struct Cyc_Absyn_Carray_mod_struct*_tmp36B=(struct Cyc_Absyn_Carray_mod_struct*)
_tmp36A;if(_tmp36B->tag != 0)goto _LL208;else{_tmp36C=_tmp36B->f1;}}_LL207:{const
char*_tmp4C3;Cyc_Absyndump_dump(((_tmp4C3="[]",_tag_dyneither(_tmp4C3,sizeof(
char),3))));}if(((int(*)(int y,union Cyc_Absyn_Constraint*x))Cyc_Absyn_conref_def)(
0,_tmp36C)){const char*_tmp4C4;Cyc_Absyndump_dump(((_tmp4C4="@zeroterm",
_tag_dyneither(_tmp4C4,sizeof(char),10))));}goto _LL205;_LL208: {struct Cyc_Absyn_ConstArray_mod_struct*
_tmp36D=(struct Cyc_Absyn_ConstArray_mod_struct*)_tmp36A;if(_tmp36D->tag != 1)goto
_LL20A;else{_tmp36E=_tmp36D->f1;_tmp36F=_tmp36D->f2;}}_LL209: Cyc_Absyndump_dump_char((
int)'[');Cyc_Absyndump_dumpexp(_tmp36E);Cyc_Absyndump_dump_char((int)']');if(((
int(*)(int y,union Cyc_Absyn_Constraint*x))Cyc_Absyn_conref_def)(0,_tmp36F)){const
char*_tmp4C5;Cyc_Absyndump_dump(((_tmp4C5="@zeroterm",_tag_dyneither(_tmp4C5,
sizeof(char),10))));}goto _LL205;_LL20A: {struct Cyc_Absyn_Function_mod_struct*
_tmp370=(struct Cyc_Absyn_Function_mod_struct*)_tmp36A;if(_tmp370->tag != 3)goto
_LL20C;else{_tmp371=(void*)_tmp370->f1;{struct Cyc_Absyn_WithTypes_struct*_tmp372=(
struct Cyc_Absyn_WithTypes_struct*)_tmp371;if(_tmp372->tag != 1)goto _LL20C;else{
_tmp373=_tmp372->f1;_tmp374=_tmp372->f2;_tmp375=_tmp372->f3;_tmp376=_tmp372->f4;
_tmp377=_tmp372->f5;}};}}_LL20B: Cyc_Absyndump_dumpfunargs(_tmp373,_tmp374,
_tmp375,_tmp376,_tmp377);goto _LL205;_LL20C: {struct Cyc_Absyn_Function_mod_struct*
_tmp378=(struct Cyc_Absyn_Function_mod_struct*)_tmp36A;if(_tmp378->tag != 3)goto
_LL20E;else{_tmp379=(void*)_tmp378->f1;{struct Cyc_Absyn_NoTypes_struct*_tmp37A=(
struct Cyc_Absyn_NoTypes_struct*)_tmp379;if(_tmp37A->tag != 0)goto _LL20E;else{
_tmp37B=_tmp37A->f1;_tmp37C=_tmp37A->f2;}};}}_LL20D:{const char*_tmp4C8;const char*
_tmp4C7;const char*_tmp4C6;((void(*)(void(*f)(struct _dyneither_ptr*),struct Cyc_List_List*
l,struct _dyneither_ptr start,struct _dyneither_ptr end,struct _dyneither_ptr sep))Cyc_Absyndump_group)(
Cyc_Absyndump_dump_str,_tmp37B,((_tmp4C6="(",_tag_dyneither(_tmp4C6,sizeof(char),
2))),((_tmp4C7=")",_tag_dyneither(_tmp4C7,sizeof(char),2))),((_tmp4C8=",",
_tag_dyneither(_tmp4C8,sizeof(char),2))));}goto _LL205;_LL20E: {struct Cyc_Absyn_TypeParams_mod_struct*
_tmp37D=(struct Cyc_Absyn_TypeParams_mod_struct*)_tmp36A;if(_tmp37D->tag != 4)goto
_LL210;else{_tmp37E=_tmp37D->f1;_tmp37F=_tmp37D->f2;_tmp380=_tmp37D->f3;}}_LL20F:
if(_tmp380)Cyc_Absyndump_dumpkindedtvars(_tmp37E);else{Cyc_Absyndump_dumptvars(
_tmp37E);}goto _LL205;_LL210: {struct Cyc_Absyn_Attributes_mod_struct*_tmp381=(
struct Cyc_Absyn_Attributes_mod_struct*)_tmp36A;if(_tmp381->tag != 5)goto _LL212;
else{_tmp382=_tmp381->f2;}}_LL211: Cyc_Absyndump_dumpatts(_tmp382);goto _LL205;
_LL212: {struct Cyc_Absyn_Pointer_mod_struct*_tmp383=(struct Cyc_Absyn_Pointer_mod_struct*)
_tmp36A;if(_tmp383->tag != 2)goto _LL205;}_LL213: {const char*_tmp4CB;void*_tmp4CA;(
_tmp4CA=0,Cyc_Tcutil_impos(((_tmp4CB="dumptms",_tag_dyneither(_tmp4CB,sizeof(
char),8))),_tag_dyneither(_tmp4CA,sizeof(void*),0)));}_LL205:;}return;}_LL1EB:;};}
void Cyc_Absyndump_dumptqtd(struct Cyc_Absyn_Tqual tq,void*t,void(*f)(void*),void*a);
void Cyc_Absyndump_dumptqtd(struct Cyc_Absyn_Tqual tq,void*t,void(*f)(void*),void*a){
struct _RegionHandle _tmp38C=_new_region("temp");struct _RegionHandle*temp=& _tmp38C;
_push_region(temp);{struct Cyc_Absyn_Tqual _tmp38E;void*_tmp38F;struct Cyc_List_List*
_tmp390;struct _tuple11 _tmp38D=Cyc_Absynpp_to_tms(temp,tq,t);_tmp38E=_tmp38D.f1;
_tmp38F=_tmp38D.f2;_tmp390=_tmp38D.f3;Cyc_Absyndump_dumptq(_tmp38E);Cyc_Absyndump_dumpntyp(
_tmp38F);Cyc_Absyndump_dumptms(((struct Cyc_List_List*(*)(struct Cyc_List_List*x))
Cyc_List_imp_rev)(_tmp390),f,a);};_pop_region(temp);}void Cyc_Absyndump_dumpdecllist2file(
struct Cyc_List_List*tdl,struct Cyc___cycFILE*f);void Cyc_Absyndump_dumpdecllist2file(
struct Cyc_List_List*tdl,struct Cyc___cycFILE*f){Cyc_Absyndump_pos=0;*Cyc_Absyndump_dump_file=
f;for(0;tdl != 0;tdl=tdl->tl){Cyc_Absyndump_dumpdecl((struct Cyc_Absyn_Decl*)tdl->hd);}{
const char*_tmp4CE;void*_tmp4CD;(_tmp4CD=0,Cyc_fprintf(f,((_tmp4CE="\n",
_tag_dyneither(_tmp4CE,sizeof(char),2))),_tag_dyneither(_tmp4CD,sizeof(void*),0)));};}