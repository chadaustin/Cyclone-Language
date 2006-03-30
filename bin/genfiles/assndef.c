#include <setjmp.h>
/* This is a C header used by the output of the Cyclone to
   C translator.  Corresponding definitions are in file lib/runtime_*.c */
#ifndef _CYC_INCLUDE_H_
#define _CYC_INCLUDE_H_

/* Need one of these per thread (see runtime_stack.c). The runtime maintains 
   a stack that contains either _handler_cons structs or _RegionHandle structs.
   The tag is 0 for a handler_cons and 1 for a region handle.  */
struct _RuntimeStack {
  int tag; 
  struct _RuntimeStack *next;
  void (*cleanup)(struct _RuntimeStack *frame);
};

#ifndef offsetof
/* should be size_t but int is fine */
#define offsetof(t,n) ((int)(&(((t*)0)->n)))
#endif

/* Fat pointers */
struct _fat_ptr {
  unsigned char *curr; 
  unsigned char *base; 
  unsigned char *last_plus_one; 
};  

/* Regions */
struct _RegionPage
{ 
#ifdef CYC_REGION_PROFILE
  unsigned total_bytes;
  unsigned free_bytes;
#endif
  struct _RegionPage *next;
  char data[1];
};

struct _pool;
struct bget_region_key;
struct _RegionAllocFunctions;

struct _RegionHandle {
  struct _RuntimeStack s;
  struct _RegionPage *curr;
#if(defined(__linux__) && defined(__KERNEL__))
  struct _RegionPage *vpage;
#endif 
  struct _RegionAllocFunctions *fcns;
  char               *offset;
  char               *last_plus_one;
  struct _pool *released_ptrs;
  struct bget_region_key *key;
#ifdef CYC_REGION_PROFILE
  const char *name;
#endif
  unsigned used_bytes;
  unsigned wasted_bytes;
};


// A dynamic region is just a region handle.  The wrapper struct is for type
// abstraction.
struct Cyc_Core_DynamicRegion {
  struct _RegionHandle h;
};

/* Alias qualifier stuff */
typedef unsigned int _AliasQualHandle_t; // must match aqualt_type() in toc.cyc

struct _RegionHandle _new_region(unsigned int, const char*);
void* _region_malloc(struct _RegionHandle*, _AliasQualHandle_t, unsigned);
void* _region_calloc(struct _RegionHandle*, _AliasQualHandle_t, unsigned t, unsigned n);
void* _region_vmalloc(struct _RegionHandle*, unsigned);
void * _aqual_malloc(_AliasQualHandle_t aq, unsigned int s);
void * _aqual_calloc(_AliasQualHandle_t aq, unsigned int n, unsigned int t);
void _free_region(struct _RegionHandle*);

/* Exceptions */
struct _handler_cons {
  struct _RuntimeStack s;
  jmp_buf handler;
};
void _push_handler(struct _handler_cons*);
void _push_region(struct _RegionHandle*);
void _npop_handler(int);
void _pop_handler();
void _pop_region();


#ifndef _throw
void* _throw_null_fn(const char*,unsigned);
void* _throw_arraybounds_fn(const char*,unsigned);
void* _throw_badalloc_fn(const char*,unsigned);
void* _throw_match_fn(const char*,unsigned);
void* _throw_assert_fn(const char *,unsigned);
void* _throw_fn(void*,const char*,unsigned);
void* _rethrow(void*);
#define _throw_null() (_throw_null_fn(__FILE__,__LINE__))
#define _throw_arraybounds() (_throw_arraybounds_fn(__FILE__,__LINE__))
#define _throw_badalloc() (_throw_badalloc_fn(__FILE__,__LINE__))
#define _throw_match() (_throw_match_fn(__FILE__,__LINE__))
#define _throw_assert() (_throw_assert_fn(__FILE__,__LINE__))
#define _throw(e) (_throw_fn((e),__FILE__,__LINE__))
#endif

void* Cyc_Core_get_exn_thrown();
/* Built-in Exceptions */
struct Cyc_Null_Exception_exn_struct { char *tag; };
struct Cyc_Array_bounds_exn_struct { char *tag; };
struct Cyc_Match_Exception_exn_struct { char *tag; };
struct Cyc_Bad_alloc_exn_struct { char *tag; };
struct Cyc_Assert_exn_struct { char *tag; };
extern char Cyc_Null_Exception[];
extern char Cyc_Array_bounds[];
extern char Cyc_Match_Exception[];
extern char Cyc_Bad_alloc[];
extern char Cyc_Assert[];

/* Built-in Run-time Checks and company */
#ifdef NO_CYC_NULL_CHECKS
#define _check_null(ptr) (ptr)
#else
#define _check_null(ptr) \
  ({ typeof(ptr) _cks_null = (ptr); \
     if (!_cks_null) _throw_null(); \
     _cks_null; })
#endif

#ifdef NO_CYC_BOUNDS_CHECKS
#define _check_known_subscript_notnull(ptr,bound,elt_sz,index)\
   (((char*)ptr) + (elt_sz)*(index))
#ifdef NO_CYC_NULL_CHECKS
#define _check_known_subscript_null _check_known_subscript_notnull
#else
#define _check_known_subscript_null(ptr,bound,elt_sz,index) ({ \
  char*_cks_ptr = (char*)(ptr);\
  int _index = (index);\
  if (!_cks_ptr) _throw_null(); \
  _cks_ptr + (elt_sz)*_index; })
#endif
#define _zero_arr_plus_char_fn(orig_x,orig_sz,orig_i,f,l) ((orig_x)+(orig_i))
#define _zero_arr_plus_other_fn(t_sz,orig_x,orig_sz,orig_i,f,l)((orig_x)+(orig_i))
#else
#define _check_known_subscript_null(ptr,bound,elt_sz,index) ({ \
  char*_cks_ptr = (char*)(ptr); \
  unsigned _cks_index = (index); \
  if (!_cks_ptr) _throw_null(); \
  if (_cks_index >= (bound)) _throw_arraybounds(); \
  _cks_ptr + (elt_sz)*_cks_index; })
#define _check_known_subscript_notnull(ptr,bound,elt_sz,index) ({ \
  char*_cks_ptr = (char*)(ptr); \
  unsigned _cks_index = (index); \
  if (_cks_index >= (bound)) _throw_arraybounds(); \
  _cks_ptr + (elt_sz)*_cks_index; })

/* _zero_arr_plus_*_fn(x,sz,i,filename,lineno) adds i to zero-terminated ptr
   x that has at least sz elements */
char* _zero_arr_plus_char_fn(char*,unsigned,int,const char*,unsigned);
void* _zero_arr_plus_other_fn(unsigned,void*,unsigned,int,const char*,unsigned);
#endif

/* _get_zero_arr_size_*(x,sz) returns the number of elements in a
   zero-terminated array that is NULL or has at least sz elements */
unsigned _get_zero_arr_size_char(const char*,unsigned);
unsigned _get_zero_arr_size_other(unsigned,const void*,unsigned);

/* _zero_arr_inplace_plus_*_fn(x,i,filename,lineno) sets
   zero-terminated pointer *x to *x + i */
char* _zero_arr_inplace_plus_char_fn(char**,int,const char*,unsigned);
char* _zero_arr_inplace_plus_post_char_fn(char**,int,const char*,unsigned);
// note: must cast result in toc.cyc
void* _zero_arr_inplace_plus_other_fn(unsigned,void**,int,const char*,unsigned);
void* _zero_arr_inplace_plus_post_other_fn(unsigned,void**,int,const char*,unsigned);
#define _zero_arr_plus_char(x,s,i) \
  (_zero_arr_plus_char_fn(x,s,i,__FILE__,__LINE__))
#define _zero_arr_inplace_plus_char(x,i) \
  _zero_arr_inplace_plus_char_fn((char**)(x),i,__FILE__,__LINE__)
#define _zero_arr_inplace_plus_post_char(x,i) \
  _zero_arr_inplace_plus_post_char_fn((char**)(x),(i),__FILE__,__LINE__)
#define _zero_arr_plus_other(t,x,s,i) \
  (_zero_arr_plus_other_fn(t,x,s,i,__FILE__,__LINE__))
#define _zero_arr_inplace_plus_other(t,x,i) \
  _zero_arr_inplace_plus_other_fn(t,(void**)(x),i,__FILE__,__LINE__)
#define _zero_arr_inplace_plus_post_other(t,x,i) \
  _zero_arr_inplace_plus_post_other_fn(t,(void**)(x),(i),__FILE__,__LINE__)

#ifdef NO_CYC_BOUNDS_CHECKS
#define _check_fat_subscript(arr,elt_sz,index) ((arr).curr + (elt_sz) * (index))
#define _untag_fat_ptr(arr,elt_sz,num_elts) ((arr).curr)
#define _untag_fat_ptr_check_bound(arr,elt_sz,num_elts) ((arr).curr)
#define _check_fat_at_base(arr) (arr)
#else
#define _check_fat_subscript(arr,elt_sz,index) ({ \
  struct _fat_ptr _cus_arr = (arr); \
  unsigned char *_cus_ans = _cus_arr.curr + (elt_sz) * (index); \
  /* JGM: not needed! if (!_cus_arr.base) _throw_null();*/ \
  if (_cus_ans < _cus_arr.base || _cus_ans >= _cus_arr.last_plus_one) \
    _throw_arraybounds(); \
  _cus_ans; })
#define _untag_fat_ptr(arr,elt_sz,num_elts) ((arr).curr)
#define _untag_fat_ptr_check_bound(arr,elt_sz,num_elts) ({ \
  struct _fat_ptr _arr = (arr); \
  unsigned char *_curr = _arr.curr; \
  if ((_curr < _arr.base || _curr + (elt_sz) * (num_elts) > _arr.last_plus_one) &&\
      _curr != (unsigned char*)0) \
    _throw_arraybounds(); \
  _curr; })
#define _check_fat_at_base(arr) ({ \
  struct _fat_ptr _arr = (arr); \
  if (_arr.base != _arr.curr) _throw_arraybounds(); \
  _arr; })
#endif

#define _tag_fat(tcurr,elt_sz,num_elts) ({ \
  struct _fat_ptr _ans; \
  unsigned _num_elts = (num_elts);\
  _ans.base = _ans.curr = (void*)(tcurr); \
  /* JGM: if we're tagging NULL, ignore num_elts */ \
  _ans.last_plus_one = _ans.base ? (_ans.base + (elt_sz) * _num_elts) : 0; \
  _ans; })

#define _get_fat_size(arr,elt_sz) \
  ({struct _fat_ptr _arr = (arr); \
    unsigned char *_arr_curr=_arr.curr; \
    unsigned char *_arr_last=_arr.last_plus_one; \
    (_arr_curr < _arr.base || _arr_curr >= _arr_last) ? 0 : \
    ((_arr_last - _arr_curr) / (elt_sz));})

#define _fat_ptr_plus(arr,elt_sz,change) ({ \
  struct _fat_ptr _ans = (arr); \
  int _change = (change);\
  _ans.curr += (elt_sz) * _change;\
  _ans; })
#define _fat_ptr_inplace_plus(arr_ptr,elt_sz,change) ({ \
  struct _fat_ptr * _arr_ptr = (arr_ptr); \
  _arr_ptr->curr += (elt_sz) * (change);\
  *_arr_ptr; })
#define _fat_ptr_inplace_plus_post(arr_ptr,elt_sz,change) ({ \
  struct _fat_ptr * _arr_ptr = (arr_ptr); \
  struct _fat_ptr _ans = *_arr_ptr; \
  _arr_ptr->curr += (elt_sz) * (change);\
  _ans; })

//Not a macro since initialization order matters. Defined in runtime_zeroterm.c.
struct _fat_ptr _fat_ptr_decrease_size(struct _fat_ptr,unsigned sz,unsigned numelts);

#ifdef CYC_GC_PTHREAD_REDIRECTS
# define pthread_create GC_pthread_create
# define pthread_sigmask GC_pthread_sigmask
# define pthread_join GC_pthread_join
# define pthread_detach GC_pthread_detach
# define dlopen GC_dlopen
#endif
/* Allocation */
void* GC_malloc(int);
void* GC_malloc_atomic(int);
void* GC_calloc(unsigned,unsigned);
void* GC_calloc_atomic(unsigned,unsigned);

#if(defined(__linux__) && defined(__KERNEL__))
void *cyc_vmalloc(unsigned);
void cyc_vfree(void*);
#endif
// bound the allocation size to be < MAX_ALLOC_SIZE. See macros below for usage.
#define MAX_MALLOC_SIZE (1 << 28)
void* _bounded_GC_malloc(int,const char*,int);
void* _bounded_GC_malloc_atomic(int,const char*,int);
void* _bounded_GC_calloc(unsigned,unsigned,const char*,int);
void* _bounded_GC_calloc_atomic(unsigned,unsigned,const char*,int);
/* these macros are overridden below ifdef CYC_REGION_PROFILE */
#ifndef CYC_REGION_PROFILE
#define _cycalloc(n) _bounded_GC_malloc(n,__FILE__,__LINE__)
#define _cycalloc_atomic(n) _bounded_GC_malloc_atomic(n,__FILE__,__LINE__)
#define _cyccalloc(n,s) _bounded_GC_calloc(n,s,__FILE__,__LINE__)
#define _cyccalloc_atomic(n,s) _bounded_GC_calloc_atomic(n,s,__FILE__,__LINE__)
#endif

static inline unsigned int _check_times(unsigned x, unsigned y) {
  unsigned long long whole_ans = 
    ((unsigned long long) x)*((unsigned long long)y);
  unsigned word_ans = (unsigned)whole_ans;
  if(word_ans < whole_ans || word_ans > MAX_MALLOC_SIZE)
    _throw_badalloc();
  return word_ans;
}

#define _CYC_MAX_REGION_CONST 0
#define _CYC_MIN_ALIGNMENT (sizeof(double))

#ifdef CYC_REGION_PROFILE
extern int rgn_total_bytes;
#endif

static inline void*_fast_region_malloc(struct _RegionHandle*r, _AliasQualHandle_t aq, unsigned orig_s) {  
  if (r > (struct _RegionHandle*)_CYC_MAX_REGION_CONST && r->curr != 0) { 
#ifdef CYC_NOALIGN
    unsigned s =  orig_s;
#else
    unsigned s =  (orig_s + _CYC_MIN_ALIGNMENT - 1) & (~(_CYC_MIN_ALIGNMENT -1)); 
#endif
    char *result; 
    result = r->offset; 
    if (s <= (r->last_plus_one - result)) {
      r->offset = result + s; 
#ifdef CYC_REGION_PROFILE
    r->curr->free_bytes = r->curr->free_bytes - s;
    rgn_total_bytes += s;
#endif
      return result;
    }
  } 
  return _region_malloc(r,aq,orig_s); 
}

//doesn't make sense to fast malloc with reaps
#ifndef DISABLE_REAPS
#define _fast_region_malloc _region_malloc
#endif

#ifdef CYC_REGION_PROFILE
/* see macros below for usage. defined in runtime_memory.c */
void* _profile_GC_malloc(int,const char*,const char*,int);
void* _profile_GC_malloc_atomic(int,const char*,const char*,int);
void* _profile_GC_calloc(unsigned,unsigned,const char*,const char*,int);
void* _profile_GC_calloc_atomic(unsigned,unsigned,const char*,const char*,int);
void* _profile_region_malloc(struct _RegionHandle*,_AliasQualHandle_t,unsigned,const char*,const char*,int);
void* _profile_region_calloc(struct _RegionHandle*,_AliasQualHandle_t,unsigned,unsigned,const char *,const char*,int);
void * _profile_aqual_malloc(_AliasQualHandle_t aq, unsigned int s,const char *file, const char *func, int lineno);
void * _profile_aqual_calloc(_AliasQualHandle_t aq, unsigned int t1,unsigned int t2,const char *file, const char *func, int lineno);
struct _RegionHandle _profile_new_region(unsigned int i, const char*,const char*,const char*,int);
void _profile_free_region(struct _RegionHandle*,const char*,const char*,int);
#ifndef RUNTIME_CYC
#define _new_region(i,n) _profile_new_region(i,n,__FILE__,__FUNCTION__,__LINE__)
#define _free_region(r) _profile_free_region(r,__FILE__,__FUNCTION__,__LINE__)
#define _region_malloc(rh,aq,n) _profile_region_malloc(rh,aq,n,__FILE__,__FUNCTION__,__LINE__)
#define _region_calloc(rh,aq,n,t) _profile_region_calloc(rh,aq,n,t,__FILE__,__FUNCTION__,__LINE__)
#define _aqual_malloc(aq,n) _profile_aqual_malloc(aq,n,__FILE__,__FUNCTION__,__LINE__)
#define _aqual_calloc(aq,n,t) _profile_aqual_calloc(aq,n,t,__FILE__,__FUNCTION__,__LINE__)
#endif
#define _cycalloc(n) _profile_GC_malloc(n,__FILE__,__FUNCTION__,__LINE__)
#define _cycalloc_atomic(n) _profile_GC_malloc_atomic(n,__FILE__,__FUNCTION__,__LINE__)
#define _cyccalloc(n,s) _profile_GC_calloc(n,s,__FILE__,__FUNCTION__,__LINE__)
#define _cyccalloc_atomic(n,s) _profile_GC_calloc_atomic(n,s,__FILE__,__FUNCTION__,__LINE__)
#endif //CYC_REGION_PROFILE
#endif //_CYC_INCLUDE_H
 struct Cyc_Core_Opt{void*v;};
# 128 "core.h"
int Cyc_Core_ptrcmp(void*,void*);struct Cyc_List_List{void*hd;struct Cyc_List_List*tl;};
# 54 "list.h"
extern struct Cyc_List_List*Cyc_List_list(struct _fat_ptr);
# 61
extern int Cyc_List_length(struct Cyc_List_List*);
# 76
extern struct Cyc_List_List*Cyc_List_map(void*(*)(void*),struct Cyc_List_List*);
# 83
extern struct Cyc_List_List*Cyc_List_map_c(void*(*)(void*,void*),void*,struct Cyc_List_List*);
# 145
extern void*Cyc_List_fold_left(void*(*)(void*,void*),void*,struct Cyc_List_List*);
# 161
extern struct Cyc_List_List*Cyc_List_revappend(struct Cyc_List_List*,struct Cyc_List_List*);
# 178
extern struct Cyc_List_List*Cyc_List_imp_rev(struct Cyc_List_List*);
# 234
extern struct Cyc_List_List*Cyc_List_imp_merge(int(*)(void*,void*),struct Cyc_List_List*,struct Cyc_List_List*);
# 242
extern void*Cyc_List_nth(struct Cyc_List_List*,int);
# 270
extern struct Cyc_List_List*Cyc_List_zip(struct Cyc_List_List*,struct Cyc_List_List*);struct Cyc_AssnDef_ExistAssnFn;struct _union_Nmspace_Rel_n{int tag;struct Cyc_List_List*val;};struct _union_Nmspace_Abs_n{int tag;struct Cyc_List_List*val;};struct _union_Nmspace_C_n{int tag;struct Cyc_List_List*val;};struct _union_Nmspace_Loc_n{int tag;int val;};union Cyc_Absyn_Nmspace{struct _union_Nmspace_Rel_n Rel_n;struct _union_Nmspace_Abs_n Abs_n;struct _union_Nmspace_C_n C_n;struct _union_Nmspace_Loc_n Loc_n;};struct _tuple0{union Cyc_Absyn_Nmspace f0;struct _fat_ptr*f1;};
# 145 "absyn.h"
enum Cyc_Absyn_Scope{Cyc_Absyn_Static =0U,Cyc_Absyn_Abstract =1U,Cyc_Absyn_Public =2U,Cyc_Absyn_Extern =3U,Cyc_Absyn_ExternC =4U,Cyc_Absyn_Register =5U};struct Cyc_Absyn_Tqual{int print_const: 1;int q_volatile: 1;int q_restrict: 1;int real_const: 1;unsigned loc;};
# 167
enum Cyc_Absyn_Sign{Cyc_Absyn_Signed =0U,Cyc_Absyn_Unsigned =1U,Cyc_Absyn_None =2U};
enum Cyc_Absyn_AggrKind{Cyc_Absyn_StructA =0U,Cyc_Absyn_UnionA =1U};struct Cyc_Absyn_Tvar{struct _fat_ptr*name;int identity;void*kind;void*aquals_bound;};struct Cyc_Absyn_VarargInfo{struct _fat_ptr*name;struct Cyc_Absyn_Tqual tq;void*type;int inject;};struct Cyc_Absyn_FnInfo{struct Cyc_List_List*tvars;void*effect;struct Cyc_Absyn_Tqual ret_tqual;void*ret_type;struct Cyc_List_List*args;int c_varargs;struct Cyc_Absyn_VarargInfo*cyc_varargs;struct Cyc_List_List*qual_bnd;struct Cyc_List_List*attributes;struct Cyc_Absyn_Exp*checks_clause;struct Cyc_AssnDef_ExistAssnFn*checks_assn;struct Cyc_Absyn_Exp*requires_clause;struct Cyc_AssnDef_ExistAssnFn*requires_assn;struct Cyc_Absyn_Exp*ensures_clause;struct Cyc_AssnDef_ExistAssnFn*ensures_assn;struct Cyc_Absyn_Exp*throws_clause;struct Cyc_AssnDef_ExistAssnFn*throws_assn;struct Cyc_Absyn_Vardecl*return_value;struct Cyc_List_List*arg_vardecls;struct Cyc_List_List*effconstr;};struct _tuple2{enum Cyc_Absyn_AggrKind f0;struct _tuple0*f1;struct Cyc_Core_Opt*f2;};struct _union_AggrInfo_UnknownAggr{int tag;struct _tuple2 val;};struct _union_AggrInfo_KnownAggr{int tag;struct Cyc_Absyn_Aggrdecl**val;};union Cyc_Absyn_AggrInfo{struct _union_AggrInfo_UnknownAggr UnknownAggr;struct _union_AggrInfo_KnownAggr KnownAggr;};struct Cyc_Absyn_ArrayInfo{void*elt_type;struct Cyc_Absyn_Tqual tq;struct Cyc_Absyn_Exp*num_elts;void*zero_term;unsigned zt_loc;};struct Cyc_Absyn_VoidCon_Absyn_TyCon_struct{int tag;};struct Cyc_Absyn_AggrCon_Absyn_TyCon_struct{int tag;union Cyc_Absyn_AggrInfo f1;};struct Cyc_Absyn_AppType_Absyn_Type_struct{int tag;void*f1;struct Cyc_List_List*f2;};struct Cyc_Absyn_ArrayType_Absyn_Type_struct{int tag;struct Cyc_Absyn_ArrayInfo f1;};struct Cyc_Absyn_AnonAggrType_Absyn_Type_struct{int tag;enum Cyc_Absyn_AggrKind f1;int f2;struct Cyc_List_List*f3;};struct _union_Cnst_Null_c{int tag;int val;};struct _tuple3{enum Cyc_Absyn_Sign f0;char f1;};struct _union_Cnst_Char_c{int tag;struct _tuple3 val;};struct _union_Cnst_Wchar_c{int tag;struct _fat_ptr val;};struct _tuple4{enum Cyc_Absyn_Sign f0;short f1;};struct _union_Cnst_Short_c{int tag;struct _tuple4 val;};struct _tuple5{enum Cyc_Absyn_Sign f0;int f1;};struct _union_Cnst_Int_c{int tag;struct _tuple5 val;};struct _tuple6{enum Cyc_Absyn_Sign f0;long long f1;};struct _union_Cnst_LongLong_c{int tag;struct _tuple6 val;};struct _tuple7{struct _fat_ptr f0;int f1;};struct _union_Cnst_Float_c{int tag;struct _tuple7 val;};struct _union_Cnst_String_c{int tag;struct _fat_ptr val;};struct _union_Cnst_Wstring_c{int tag;struct _fat_ptr val;};union Cyc_Absyn_Cnst{struct _union_Cnst_Null_c Null_c;struct _union_Cnst_Char_c Char_c;struct _union_Cnst_Wchar_c Wchar_c;struct _union_Cnst_Short_c Short_c;struct _union_Cnst_Int_c Int_c;struct _union_Cnst_LongLong_c LongLong_c;struct _union_Cnst_Float_c Float_c;struct _union_Cnst_String_c String_c;struct _union_Cnst_Wstring_c Wstring_c;};
# 529 "absyn.h"
enum Cyc_Absyn_Primop{Cyc_Absyn_Plus =0U,Cyc_Absyn_Times =1U,Cyc_Absyn_Minus =2U,Cyc_Absyn_Div =3U,Cyc_Absyn_Mod =4U,Cyc_Absyn_Eq =5U,Cyc_Absyn_Neq =6U,Cyc_Absyn_Gt =7U,Cyc_Absyn_Lt =8U,Cyc_Absyn_Gte =9U,Cyc_Absyn_Lte =10U,Cyc_Absyn_Not =11U,Cyc_Absyn_Bitnot =12U,Cyc_Absyn_Bitand =13U,Cyc_Absyn_Bitor =14U,Cyc_Absyn_Bitxor =15U,Cyc_Absyn_Bitlshift =16U,Cyc_Absyn_Bitlrshift =17U,Cyc_Absyn_Numelts =18U,Cyc_Absyn_Tagof =19U,Cyc_Absyn_UDiv =20U,Cyc_Absyn_UMod =21U,Cyc_Absyn_UGt =22U,Cyc_Absyn_ULt =23U,Cyc_Absyn_UGte =24U,Cyc_Absyn_ULte =25U};
# 536
enum Cyc_Absyn_Incrementor{Cyc_Absyn_PreInc =0U,Cyc_Absyn_PostInc =1U,Cyc_Absyn_PreDec =2U,Cyc_Absyn_PostDec =3U};struct Cyc_Absyn_Const_e_Absyn_Raw_exp_struct{int tag;union Cyc_Absyn_Cnst f1;};struct Cyc_Absyn_Var_e_Absyn_Raw_exp_struct{int tag;void*f1;};struct Cyc_Absyn_AssignOp_e_Absyn_Raw_exp_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Core_Opt*f2;struct Cyc_Absyn_Exp*f3;};struct Cyc_Absyn_Increment_e_Absyn_Raw_exp_struct{int tag;struct Cyc_Absyn_Exp*f1;enum Cyc_Absyn_Incrementor f2;};struct Cyc_Absyn_Comprehension_e_Absyn_Raw_exp_struct{int tag;struct Cyc_Absyn_Vardecl*f1;struct Cyc_Absyn_Exp*f2;struct Cyc_Absyn_Exp*f3;int f4;};struct Cyc_Absyn_Swap_e_Absyn_Raw_exp_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_Absyn_Exp*f2;};struct Cyc_Absyn_Exp{void*topt;void*r;unsigned loc;void*annot;};struct Cyc_Absyn_Switch_s_Absyn_Raw_stmt_struct{int tag;struct Cyc_Absyn_Exp*f1;struct Cyc_List_List*f2;void*f3;};struct Cyc_Absyn_Decl_s_Absyn_Raw_stmt_struct{int tag;struct Cyc_Absyn_Decl*f1;struct Cyc_Absyn_Stmt*f2;};struct Cyc_Absyn_TryCatch_s_Absyn_Raw_stmt_struct{int tag;struct Cyc_Absyn_Stmt*f1;struct Cyc_List_List*f2;void*f3;};struct Cyc_Absyn_Stmt{void*r;unsigned loc;void*annot;};struct Cyc_Absyn_Var_p_Absyn_Raw_pat_struct{int tag;struct Cyc_Absyn_Vardecl*f1;struct Cyc_Absyn_Pat*f2;};struct Cyc_Absyn_AliasVar_p_Absyn_Raw_pat_struct{int tag;struct Cyc_Absyn_Tvar*f1;struct Cyc_Absyn_Vardecl*f2;};struct Cyc_Absyn_Reference_p_Absyn_Raw_pat_struct{int tag;struct Cyc_Absyn_Vardecl*f1;struct Cyc_Absyn_Pat*f2;};struct Cyc_Absyn_TagInt_p_Absyn_Raw_pat_struct{int tag;struct Cyc_Absyn_Tvar*f1;struct Cyc_Absyn_Vardecl*f2;};struct Cyc_Absyn_Pointer_p_Absyn_Raw_pat_struct{int tag;struct Cyc_Absyn_Pat*f1;};struct Cyc_Absyn_Aggr_p_Absyn_Raw_pat_struct{int tag;void*f1;int f2;struct Cyc_List_List*f3;struct Cyc_List_List*f4;int f5;};struct Cyc_Absyn_Datatype_p_Absyn_Raw_pat_struct{int tag;struct Cyc_Absyn_Datatypedecl*f1;struct Cyc_Absyn_Datatypefield*f2;struct Cyc_List_List*f3;int f4;};struct Cyc_Absyn_Pat{void*r;void*topt;unsigned loc;};struct Cyc_Absyn_Switch_clause{struct Cyc_Absyn_Pat*pattern;struct Cyc_Core_Opt*pat_vars;struct Cyc_Absyn_Exp*where_clause;struct Cyc_Absyn_Stmt*body;unsigned loc;};struct Cyc_Absyn_Unresolved_b_Absyn_Binding_struct{int tag;struct _tuple0*f1;};struct Cyc_Absyn_Global_b_Absyn_Binding_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Funname_b_Absyn_Binding_struct{int tag;struct Cyc_Absyn_Fndecl*f1;};struct Cyc_Absyn_Param_b_Absyn_Binding_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Local_b_Absyn_Binding_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Pat_b_Absyn_Binding_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Vardecl{enum Cyc_Absyn_Scope sc;struct _tuple0*name;unsigned varloc;struct Cyc_Absyn_Tqual tq;void*type;struct Cyc_Absyn_Exp*initializer;void*rgn;struct Cyc_List_List*attributes;int escapes;int is_proto;struct Cyc_Absyn_Exp*rename;};struct Cyc_Absyn_Fndecl{enum Cyc_Absyn_Scope sc;int is_inline;struct _tuple0*name;struct Cyc_Absyn_Stmt*body;struct Cyc_Absyn_FnInfo i;void*cached_type;struct Cyc_Core_Opt*param_vardecls;struct Cyc_Absyn_Vardecl*fn_vardecl;enum Cyc_Absyn_Scope orig_scope;int escapes;};struct Cyc_Absyn_Aggrfield{struct _fat_ptr*name;struct Cyc_Absyn_Tqual tq;void*type;struct Cyc_Absyn_Exp*width;struct Cyc_List_List*attributes;struct Cyc_Absyn_Exp*requires_clause;};struct Cyc_Absyn_AggrdeclImpl{struct Cyc_List_List*exist_vars;struct Cyc_List_List*qual_bnd;struct Cyc_List_List*fields;int tagged;struct Cyc_List_List*effconstr;};struct Cyc_Absyn_Aggrdecl{enum Cyc_Absyn_AggrKind kind;enum Cyc_Absyn_Scope sc;struct _tuple0*name;struct Cyc_List_List*tvs;struct Cyc_Absyn_AggrdeclImpl*impl;struct Cyc_List_List*attributes;int expected_mem_kind;};struct Cyc_Absyn_Datatypefield{struct _tuple0*name;struct Cyc_List_List*typs;unsigned loc;enum Cyc_Absyn_Scope sc;};struct Cyc_Absyn_Datatypedecl{enum Cyc_Absyn_Scope sc;struct _tuple0*name;struct Cyc_List_List*tvs;struct Cyc_Core_Opt*fields;int is_extensible;};struct Cyc_Absyn_Var_d_Absyn_Raw_decl_struct{int tag;struct Cyc_Absyn_Vardecl*f1;};struct Cyc_Absyn_Let_d_Absyn_Raw_decl_struct{int tag;struct Cyc_Absyn_Pat*f1;struct Cyc_Core_Opt*f2;struct Cyc_Absyn_Exp*f3;void*f4;};struct Cyc_Absyn_Letv_d_Absyn_Raw_decl_struct{int tag;struct Cyc_List_List*f1;};struct Cyc_Absyn_Region_d_Absyn_Raw_decl_struct{int tag;struct Cyc_Absyn_Tvar*f1;struct Cyc_Absyn_Vardecl*f2;struct Cyc_Absyn_Exp*f3;};struct Cyc_Absyn_Decl{void*r;unsigned loc;};
# 938 "absyn.h"
struct Cyc_Absyn_Tqual Cyc_Absyn_empty_tqual(unsigned);
# 944
void*Cyc_Absyn_compress(void*);
# 962
extern void*Cyc_Absyn_uint_type;
# 964
extern void*Cyc_Absyn_sint_type;
# 971
extern void*Cyc_Absyn_heap_rgn_type;
# 973
extern void*Cyc_Absyn_al_qual_type;
# 977
extern void*Cyc_Absyn_false_type;
# 1002
void*Cyc_Absyn_exn_type (void);
# 1028
void*Cyc_Absyn_at_type(void*,void*,void*,struct Cyc_Absyn_Tqual,void*,void*);
# 1243
void Cyc_Absyn_visit_stmt(int(*)(void*,struct Cyc_Absyn_Exp*),int(*)(void*,struct Cyc_Absyn_Stmt*),void*,struct Cyc_Absyn_Stmt*);
void Cyc_Absyn_visit_exp(int(*)(void*,struct Cyc_Absyn_Exp*),int(*)(void*,struct Cyc_Absyn_Stmt*),void*,struct Cyc_Absyn_Exp*);struct Cyc_String_pa_PrintArg_struct{int tag;struct _fat_ptr f1;};struct Cyc_Int_pa_PrintArg_struct{int tag;unsigned long f1;};
# 73 "cycboot.h"
extern struct _fat_ptr Cyc_aprintf(struct _fat_ptr,struct _fat_ptr);
# 63 "absynpp.h"
struct _fat_ptr Cyc_Absynpp_typ2string(void*);
# 69
struct _fat_ptr Cyc_Absynpp_exp2string(struct Cyc_Absyn_Exp*);
# 71
struct _fat_ptr Cyc_Absynpp_qvar2string(struct _tuple0*);
# 74
struct _fat_ptr Cyc_Absynpp_prim2string(enum Cyc_Absyn_Primop);struct _tuple11{unsigned f0;int f1;};
# 28 "evexp.h"
extern struct _tuple11 Cyc_Evexp_eval_const_uint_exp(struct Cyc_Absyn_Exp*);
# 46 "evexp.h"
extern int Cyc_Evexp_exp_cmp(struct Cyc_Absyn_Exp*,struct Cyc_Absyn_Exp*);
# 35 "tcutil.h"
int Cyc_Tcutil_is_integral_type(void*);
# 42
int Cyc_Tcutil_is_pointer_type(void*);
# 60
void*Cyc_Tcutil_pointer_elt_type(void*);
# 129 "tcutil.h"
int Cyc_Tcutil_typecmp(void*,void*);
# 132
void*Cyc_Tcutil_substitute(struct Cyc_List_List*,void*);
# 40 "warn.h"
void*Cyc_Warn_impos(struct _fat_ptr,struct _fat_ptr);struct Cyc_Dict_T;struct Cyc_Dict_Dict{int(*rel)(void*,void*);struct _RegionHandle*r;const struct Cyc_Dict_T*t;};
# 62 "dict.h"
extern struct Cyc_Dict_Dict Cyc_Dict_empty(int(*)(void*,void*));
# 77
extern int Cyc_Dict_is_empty(struct Cyc_Dict_Dict);
# 87
extern struct Cyc_Dict_Dict Cyc_Dict_insert(struct Cyc_Dict_Dict,void*,void*);
# 122 "dict.h"
extern void**Cyc_Dict_lookup_opt(struct Cyc_Dict_Dict,void*);
# 131
extern void*Cyc_Dict_fold(void*(*)(void*,void*,void*),struct Cyc_Dict_Dict,void*);
# 135
extern void*Cyc_Dict_fold_c(void*(*)(void*,void*,void*,void*),void*,struct Cyc_Dict_Dict,void*);
# 184
extern struct Cyc_Dict_Dict Cyc_Dict_map_c(void*(*)(void*,void*),void*,struct Cyc_Dict_Dict);
# 257
extern struct Cyc_Dict_Dict Cyc_Dict_difference(struct Cyc_Dict_Dict,struct Cyc_Dict_Dict);
# 64 "string.h"
extern struct _fat_ptr Cyc_strconcat_l(struct Cyc_List_List*);struct Cyc_Set_Set;
# 51 "set.h"
extern struct Cyc_Set_Set*Cyc_Set_empty(int(*)(void*,void*));
# 57
extern struct Cyc_Set_Set*Cyc_Set_singleton(int(*)(void*,void*),void*);
# 60
extern struct Cyc_Set_Set*Cyc_Set_from_list(int(*)(void*,void*),struct Cyc_List_List*);
# 65
extern struct Cyc_Set_Set*Cyc_Set_insert(struct Cyc_Set_Set*,void*);
# 77
extern struct Cyc_Set_Set*Cyc_Set_union_two(struct Cyc_Set_Set*,struct Cyc_Set_Set*);
# 81
extern struct Cyc_Set_Set*Cyc_Set_intersect(struct Cyc_Set_Set*,struct Cyc_Set_Set*);
# 87
extern struct Cyc_Set_Set*Cyc_Set_delete(struct Cyc_Set_Set*,void*);
# 102
extern int Cyc_Set_member(struct Cyc_Set_Set*,void*);
# 116
extern void*Cyc_Set_fold(void*(*)(void*,void*),struct Cyc_Set_Set*,void*);struct Cyc_Hashtable_Table;
# 39 "hashtable.h"
extern struct Cyc_Hashtable_Table*Cyc_Hashtable_create(int,int(*)(void*,void*),int(*)(void*));
# 50
extern void Cyc_Hashtable_insert(struct Cyc_Hashtable_Table*,void*,void*);
# 56
extern void**Cyc_Hashtable_lookup_opt(struct Cyc_Hashtable_Table*,void*);
# 59
extern void**Cyc_Hashtable_lookup_other_opt(struct Cyc_Hashtable_Table*,void*,int(*)(void*,void*),int(*)(void*));
# 82
extern int Cyc_Hashtable_hash_string(struct _fat_ptr);
# 92
extern void Cyc_Hashtable_iter_c(void(*)(void*,void*,void*),struct Cyc_Hashtable_Table*,void*);struct Cyc_AssnDef_Uint_AssnDef_Term_struct{int tag;unsigned f1;void*f2;};struct Cyc_AssnDef_Const_AssnDef_Term_struct{int tag;struct Cyc_Absyn_Exp*f1;};struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct{int tag;struct Cyc_Absyn_Vardecl*f1;int f2;void*f3;};struct Cyc_AssnDef_Unop_AssnDef_Term_struct{int tag;enum Cyc_Absyn_Primop f1;void*f2;void*f3;};struct Cyc_AssnDef_Binop_AssnDef_Term_struct{int tag;enum Cyc_Absyn_Primop f1;void*f2;void*f3;void*f4;};struct Cyc_AssnDef_Cast_AssnDef_Term_struct{int tag;void*f1;void*f2;};struct Cyc_AssnDef_Select_AssnDef_Term_struct{int tag;void*f1;void*f2;void*f3;};struct Cyc_AssnDef_Update_AssnDef_Term_struct{int tag;void*f1;void*f2;void*f3;};struct Cyc_AssnDef_Aggr_AssnDef_Term_struct{int tag;int f1;unsigned f2;struct Cyc_List_List*f3;void*f4;};struct Cyc_AssnDef_Proj_AssnDef_Term_struct{int tag;void*f1;unsigned f2;void*f3;};struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct{int tag;void*f1;unsigned f2;void*f3;};struct Cyc_AssnDef_Addr_AssnDef_Term_struct{int tag;struct Cyc_Absyn_Vardecl*f1;void*f2;void*f3;};struct Cyc_AssnDef_Alloc_AssnDef_Term_struct{int tag;struct Cyc_Absyn_Exp*f1;int f2;void*f3;void*f4;void*f5;};struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct{int tag;void*f1;unsigned f2;void*f3;};struct Cyc_AssnDef_Offseti_AssnDef_Term_struct{int tag;void*f1;void*f2;void*f3;};struct Cyc_AssnDef_Tagof_AssnDef_Term_struct{int tag;void*f1;};
# 142 "assndef.h"
int Cyc_AssnDef_termcmp(void*,void*);
# 144
unsigned Cyc_AssnDef_term_size(void*);
# 151
extern struct Cyc_Absyn_Vardecl*Cyc_AssnDef_memory;
# 166
void*Cyc_AssnDef_select(void*,void*,void*);
# 170
void*Cyc_AssnDef_binop(enum Cyc_Absyn_Primop,void*,void*,void*);
# 172
void*Cyc_AssnDef_aggr(int,unsigned,struct Cyc_List_List*,void*);
# 174
void*Cyc_AssnDef_proj(void*,unsigned,void*);
void*Cyc_AssnDef_aggr_update(void*,unsigned,void*);
# 184
void*Cyc_AssnDef_plus(void*,void*,void*);struct _tuple12{void*f0;struct Cyc_List_List*f1;};
# 204
void*Cyc_AssnDef_get_term_type(void*);
# 217 "assndef.h"
enum Cyc_AssnDef_Primreln{Cyc_AssnDef_Eq =0U,Cyc_AssnDef_Neq =1U,Cyc_AssnDef_SLt =2U,Cyc_AssnDef_SLte =3U,Cyc_AssnDef_ULt =4U,Cyc_AssnDef_ULte =5U};struct Cyc_AssnDef_True_AssnDef_Assn_struct{int tag;};struct Cyc_AssnDef_False_AssnDef_Assn_struct{int tag;};struct Cyc_AssnDef_Prim_AssnDef_Assn_struct{int tag;void*f1;enum Cyc_AssnDef_Primreln f2;void*f3;};struct Cyc_AssnDef_And_AssnDef_Assn_struct{int tag;void*f1;void*f2;};struct Cyc_AssnDef_Or_AssnDef_Assn_struct{int tag;void*f1;void*f2;};
# 229
int Cyc_AssnDef_assncmp(void*,void*);
# 233
extern struct Cyc_AssnDef_True_AssnDef_Assn_struct Cyc_AssnDef_true_assn;
extern struct Cyc_AssnDef_False_AssnDef_Assn_struct Cyc_AssnDef_false_assn;
# 238
void*Cyc_AssnDef_not(void*);struct Cyc_AssnDef_AssnFn{struct Cyc_List_List*actuals;void*assn;};struct Cyc_AssnDef_ExistAssnFn{struct Cyc_AssnDef_AssnFn*af;struct Cyc_Set_Set*existvars;};struct Cyc_AssnDef_AssnMap{void*assn;struct Cyc_Dict_Dict map;};struct _tuple13{void*f0;struct Cyc_AssnDef_AssnMap f1;};
# 293
struct _tuple13 Cyc_AssnDef_lookup_var_map(struct Cyc_Absyn_Vardecl*,struct Cyc_AssnDef_AssnMap);struct _tuple14{void*f0;void*f1;struct Cyc_Dict_Dict f2;};
# 356 "assndef.h"
struct Cyc_Dict_Dict Cyc_AssnDef_empty_term_dict (void);
# 29 "unify.h"
int Cyc_Unify_unify(void*,void*);struct Cyc_Hashtable_Table{struct _RegionHandle*r;int(*cmp)(void*,void*);int(*hash)(void*);int max_len;struct _fat_ptr tab;};
# 71 "assndef.cyc"
struct _fat_ptr Cyc_AssnDef_typopt2string(void*tp){
if(tp==0)return _tag_fat("NULL",sizeof(char),5U);
return Cyc_Absynpp_typ2string(tp);}static char _TmpG0[2U]=",";static char _TmpG1[2U]="}";static char _TmpG2[2U]="{";
# 76
static struct _fat_ptr Cyc_AssnDef_term2string_i(void*t,struct Cyc_Set_Set**seen,int*depth){
struct _fat_ptr res;
int seen_it=0;
if(*depth==0)
return _tag_fat("<depth>",sizeof(char),8U);
*depth=*depth - 1;
if(Cyc_Set_member(*seen,t))
seen_it=1;{
# 85
struct Cyc_Set_Set*old_seen=*seen;
({struct Cyc_Set_Set*_Tmp0=Cyc_Set_insert(old_seen,t);*seen=_Tmp0;});
{enum Cyc_Absyn_Primop _Tmp0;int _Tmp1;void*_Tmp2;void*_Tmp3;void*_Tmp4;unsigned _Tmp5;switch(*((int*)t)){case 0: _Tmp5=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)t)->f1;{unsigned i=_Tmp5;
res=({struct Cyc_Int_pa_PrintArg_struct _Tmp6=({struct Cyc_Int_pa_PrintArg_struct _Tmp7;_Tmp7.tag=1,_Tmp7.f1=i;_Tmp7;});void*_Tmp7[1];_Tmp7[0]=& _Tmp6;Cyc_aprintf(_tag_fat("0x%x",sizeof(char),5U),_tag_fat(_Tmp7,sizeof(void*),1));});goto _LL0;}case 1: _Tmp4=((struct Cyc_AssnDef_Const_AssnDef_Term_struct*)t)->f1;{struct Cyc_Absyn_Exp*e=_Tmp4;
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_Absynpp_exp2string(e);_Tmp7.f1=_Tmp8;});_Tmp7;});void*_Tmp7[1];_Tmp7[0]=& _Tmp6;Cyc_aprintf(_tag_fat("%s",sizeof(char),3U),_tag_fat(_Tmp7,sizeof(void*),1));});goto _LL0;}case 15: _Tmp4=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)t)->f1;{void*t=_Tmp4;
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_AssnDef_term2string_i(t,seen,depth);_Tmp7.f1=_Tmp8;});_Tmp7;});void*_Tmp7[1];_Tmp7[0]=& _Tmp6;Cyc_aprintf(_tag_fat("tagof_tm(%s)",sizeof(char),13U),_tag_fat(_Tmp7,sizeof(void*),1));});goto _LL0;}case 6: _Tmp4=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f1;_Tmp3=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f2;_Tmp2=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp4;void*t2=_Tmp3;void*tp=_Tmp2;
# 93
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_AssnDef_term2string_i(t1,seen,depth);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,({struct _fat_ptr _Tmp9=Cyc_AssnDef_term2string_i(t2,seen,depth);_Tmp8.f1=_Tmp9;});_Tmp8;});void*_Tmp8[2];_Tmp8[0]=& _Tmp6,_Tmp8[1]=& _Tmp7;Cyc_aprintf(_tag_fat("Sel(%s,%s)",sizeof(char),11U),_tag_fat(_Tmp8,sizeof(void*),2));});
goto _LL0;}case 7: _Tmp4=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f1;_Tmp3=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f2;_Tmp2=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp4;void*t2=_Tmp3;void*t3=_Tmp2;
# 96
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_AssnDef_term2string_i(t1,seen,depth);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,({struct _fat_ptr _Tmp9=Cyc_AssnDef_term2string_i(t2,seen,depth);_Tmp8.f1=_Tmp9;});_Tmp8;});struct Cyc_String_pa_PrintArg_struct _Tmp8=({struct Cyc_String_pa_PrintArg_struct _Tmp9;_Tmp9.tag=0,({struct _fat_ptr _TmpA=Cyc_AssnDef_term2string_i(t3,seen,depth);_Tmp9.f1=_TmpA;});_Tmp9;});void*_Tmp9[3];_Tmp9[0]=& _Tmp6,_Tmp9[1]=& _Tmp7,_Tmp9[2]=& _Tmp8;Cyc_aprintf(_tag_fat("Upd(%s,%s,%s)",sizeof(char),14U),_tag_fat(_Tmp9,sizeof(void*),3));});
goto _LL0;}case 2: if(((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f1==0){_Tmp1=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f3;{int i=_Tmp1;void*topt=_Tmp4;
# 102
res=({struct Cyc_Int_pa_PrintArg_struct _Tmp6=({struct Cyc_Int_pa_PrintArg_struct _Tmp7;_Tmp7.tag=1,_Tmp7.f1=(unsigned long)i;_Tmp7;});void*_Tmp7[1];_Tmp7[0]=& _Tmp6;Cyc_aprintf(_tag_fat("_X%d",sizeof(char),5U),_tag_fat(_Tmp7,sizeof(void*),1));});
goto _LL0;}}else{_Tmp4=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f1;_Tmp1=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f3;{struct Cyc_Absyn_Vardecl*vd=_Tmp4;int i=_Tmp1;void*topt=_Tmp3;
# 108
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_Absynpp_qvar2string(vd->name);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_Int_pa_PrintArg_struct _Tmp7=({struct Cyc_Int_pa_PrintArg_struct _Tmp8;_Tmp8.tag=1,_Tmp8.f1=(unsigned long)i;_Tmp8;});void*_Tmp8[2];_Tmp8[0]=& _Tmp6,_Tmp8[1]=& _Tmp7;Cyc_aprintf(_tag_fat("_%s%d",sizeof(char),6U),_tag_fat(_Tmp8,sizeof(void*),2));});goto _LL0;}}case 3: _Tmp0=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f2;{enum Cyc_Absyn_Primop p=_Tmp0;void*t1=_Tmp4;
# 110
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_Absynpp_prim2string(p);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,({struct _fat_ptr _Tmp9=Cyc_AssnDef_term2string_i(t1,seen,depth);_Tmp8.f1=_Tmp9;});_Tmp8;});void*_Tmp8[2];_Tmp8[0]=& _Tmp6,_Tmp8[1]=& _Tmp7;Cyc_aprintf(_tag_fat("%s(%s)",sizeof(char),7U),_tag_fat(_Tmp8,sizeof(void*),2));});goto _LL0;}case 4: _Tmp0=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;{enum Cyc_Absyn_Primop p=_Tmp0;void*t1=_Tmp4;void*t2=_Tmp3;
# 112
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_AssnDef_term2string_i(t1,seen,depth);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,({struct _fat_ptr _Tmp9=Cyc_Absynpp_prim2string(p);_Tmp8.f1=_Tmp9;});_Tmp8;});struct Cyc_String_pa_PrintArg_struct _Tmp8=({struct Cyc_String_pa_PrintArg_struct _Tmp9;_Tmp9.tag=0,({
struct _fat_ptr _TmpA=Cyc_AssnDef_term2string_i(t2,seen,depth);_Tmp9.f1=_TmpA;});_Tmp9;});void*_Tmp9[3];_Tmp9[0]=& _Tmp6,_Tmp9[1]=& _Tmp7,_Tmp9[2]=& _Tmp8;Cyc_aprintf(_tag_fat("(%s%s%s)",sizeof(char),9U),_tag_fat(_Tmp9,sizeof(void*),3));});
goto _LL0;}case 5: _Tmp4=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f1;_Tmp3=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f2;{void*tp=_Tmp4;void*tm=_Tmp3;
# 116
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_Absynpp_typ2string(tp);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,({struct _fat_ptr _Tmp9=Cyc_AssnDef_term2string_i(tm,seen,depth);_Tmp8.f1=_Tmp9;});_Tmp8;});void*_Tmp8[2];_Tmp8[0]=& _Tmp6,_Tmp8[1]=& _Tmp7;Cyc_aprintf(_tag_fat("(%s)%s",sizeof(char),7U),_tag_fat(_Tmp8,sizeof(void*),2));});goto _LL0;}case 8: _Tmp1=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f2;_Tmp4=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f3;{int is_union=_Tmp1;unsigned tag=_Tmp5;struct Cyc_List_List*tms=_Tmp4;
# 118
static struct _fat_ptr lb={_TmpG2,_TmpG2,_TmpG2 + 2U};
static struct _fat_ptr rb={_TmpG1,_TmpG1,_TmpG1 + 2U};
static struct _fat_ptr comma={_TmpG0,_TmpG0,_TmpG0 + 2U};
struct Cyc_List_List*ss;ss=_cycalloc(sizeof(struct Cyc_List_List)),ss->hd=& lb,ss->tl=0;
for(1;tms!=0;tms=tms->tl){
struct _fat_ptr s=Cyc_AssnDef_term2string_i((void*)tms->hd,seen,depth);
ss=({struct Cyc_List_List*_Tmp6=_cycalloc(sizeof(struct Cyc_List_List));({struct _fat_ptr*_Tmp7=({struct _fat_ptr*_Tmp8=_cycalloc(sizeof(struct _fat_ptr));*_Tmp8=s;_Tmp8;});_Tmp6->hd=_Tmp7;}),_Tmp6->tl=ss;_Tmp6;});
if(tms->tl!=0)ss=({struct Cyc_List_List*_Tmp6=_cycalloc(sizeof(struct Cyc_List_List));_Tmp6->hd=& comma,_Tmp6->tl=ss;_Tmp6;});}
# 127
ss=({struct Cyc_List_List*_Tmp6=_cycalloc(sizeof(struct Cyc_List_List));_Tmp6->hd=& rb,_Tmp6->tl=ss;_Tmp6;});
ss=Cyc_List_imp_rev(ss);
res=Cyc_strconcat_l(ss);
if(tag!=4294967295U)res=({struct Cyc_Int_pa_PrintArg_struct _Tmp6=({struct Cyc_Int_pa_PrintArg_struct _Tmp7;_Tmp7.tag=1,_Tmp7.f1=(unsigned long)((int)tag);_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,_Tmp8.f1=res;_Tmp8;});void*_Tmp8[2];_Tmp8[0]=& _Tmp6,_Tmp8[1]=& _Tmp7;Cyc_aprintf(_tag_fat("tag(%d)%s",sizeof(char),10U),_tag_fat(_Tmp8,sizeof(void*),2));});
if(is_union)res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,_Tmp7.f1=res;_Tmp7;});void*_Tmp7[1];_Tmp7[0]=& _Tmp6;Cyc_aprintf(_tag_fat("union%s",sizeof(char),8U),_tag_fat(_Tmp7,sizeof(void*),1));});
goto _LL0;}case 9: _Tmp4=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f3;{void*t=_Tmp4;unsigned i=_Tmp5;void*tp=_Tmp3;
# 134
res=({struct Cyc_Int_pa_PrintArg_struct _Tmp6=({struct Cyc_Int_pa_PrintArg_struct _Tmp7;_Tmp7.tag=1,_Tmp7.f1=(unsigned long)((int)i);_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,({struct _fat_ptr _Tmp9=Cyc_AssnDef_term2string_i(t,seen,depth);_Tmp8.f1=_Tmp9;});_Tmp8;});void*_Tmp8[2];_Tmp8[0]=& _Tmp6,_Tmp8[1]=& _Tmp7;Cyc_aprintf(_tag_fat("#%d(%s)",sizeof(char),8U),_tag_fat(_Tmp8,sizeof(void*),2));});
goto _LL0;}case 10: _Tmp4=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f3;{void*a=_Tmp4;unsigned i=_Tmp5;void*v=_Tmp3;
# 137
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_AssnDef_term2string_i(a,seen,depth);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_Int_pa_PrintArg_struct _Tmp7=({struct Cyc_Int_pa_PrintArg_struct _Tmp8;_Tmp8.tag=1,_Tmp8.f1=(unsigned long)((int)i);_Tmp8;});struct Cyc_String_pa_PrintArg_struct _Tmp8=({struct Cyc_String_pa_PrintArg_struct _Tmp9;_Tmp9.tag=0,({struct _fat_ptr _TmpA=Cyc_AssnDef_term2string_i(v,seen,depth);_Tmp9.f1=_TmpA;});_Tmp9;});void*_Tmp9[3];_Tmp9[0]=& _Tmp6,_Tmp9[1]=& _Tmp7,_Tmp9[2]=& _Tmp8;Cyc_aprintf(_tag_fat("Aupd(%s,%d,%s)",sizeof(char),15U),_tag_fat(_Tmp9,sizeof(void*),3));});
goto _LL0;}case 11: _Tmp4=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f1;_Tmp3=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f2;{struct Cyc_Absyn_Vardecl*vd=_Tmp4;void*invoke=_Tmp3;
# 142
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_Absynpp_qvar2string(vd->name);_Tmp7.f1=_Tmp8;});_Tmp7;});void*_Tmp7[1];_Tmp7[0]=& _Tmp6;Cyc_aprintf(_tag_fat("&%s",sizeof(char),4U),_tag_fat(_Tmp7,sizeof(void*),1));});
goto _LL0;}case 12: _Tmp4=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f1;_Tmp1=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f3;_Tmp2=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f4;{struct Cyc_Absyn_Exp*e=_Tmp4;int id=_Tmp1;void*nelts=_Tmp3;void*invoke=_Tmp2;
# 145
res=({struct Cyc_Int_pa_PrintArg_struct _Tmp6=({struct Cyc_Int_pa_PrintArg_struct _Tmp7;_Tmp7.tag=1,_Tmp7.f1=(unsigned long)((int)e);_Tmp7;});struct Cyc_Int_pa_PrintArg_struct _Tmp7=({struct Cyc_Int_pa_PrintArg_struct _Tmp8;_Tmp8.tag=1,_Tmp8.f1=(unsigned long)id;_Tmp8;});struct Cyc_String_pa_PrintArg_struct _Tmp8=({struct Cyc_String_pa_PrintArg_struct _Tmp9;_Tmp9.tag=0,({struct _fat_ptr _TmpA=Cyc_AssnDef_term2string_i(nelts,seen,depth);_Tmp9.f1=_TmpA;});_Tmp9;});struct Cyc_String_pa_PrintArg_struct _Tmp9=({struct Cyc_String_pa_PrintArg_struct _TmpA;_TmpA.tag=0,({struct _fat_ptr _TmpB=Cyc_AssnDef_term2string_i(invoke,seen,depth);_TmpA.f1=_TmpB;});_TmpA;});void*_TmpA[4];_TmpA[0]=& _Tmp6,_TmpA[1]=& _Tmp7,_TmpA[2]=& _Tmp8,_TmpA[3]=& _Tmp9;Cyc_aprintf(_tag_fat("Alloc(%d,%d,%s,%s)",sizeof(char),19U),_tag_fat(_TmpA,sizeof(void*),4));});
goto _LL0;}case 13: _Tmp4=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f3;{void*t=_Tmp4;unsigned i=_Tmp5;void*tp=_Tmp3;
# 148
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_AssnDef_term2string_i(t,seen,depth);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_Int_pa_PrintArg_struct _Tmp7=({struct Cyc_Int_pa_PrintArg_struct _Tmp8;_Tmp8.tag=1,_Tmp8.f1=(unsigned long)((int)i);_Tmp8;});struct Cyc_String_pa_PrintArg_struct _Tmp8=({struct Cyc_String_pa_PrintArg_struct _Tmp9;_Tmp9.tag=0,({struct _fat_ptr _TmpA=Cyc_AssnDef_typopt2string(tp);_Tmp9.f1=_TmpA;});_Tmp9;});void*_Tmp9[3];_Tmp9[0]=& _Tmp6,_Tmp9[1]=& _Tmp7,_Tmp9[2]=& _Tmp8;Cyc_aprintf(_tag_fat("Offsetf(%s,%d,%s)",sizeof(char),18U),_tag_fat(_Tmp9,sizeof(void*),3));});
goto _LL0;}default: _Tmp4=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f1;_Tmp3=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f2;{void*t1=_Tmp4;void*t2=_Tmp3;
# 151
res=({struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,({struct _fat_ptr _Tmp8=Cyc_AssnDef_term2string_i(t1,seen,depth);_Tmp7.f1=_Tmp8;});_Tmp7;});struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,({struct _fat_ptr _Tmp9=Cyc_AssnDef_term2string_i(t2,seen,depth);_Tmp8.f1=_Tmp9;});_Tmp8;});void*_Tmp8[2];_Tmp8[0]=& _Tmp6,_Tmp8[1]=& _Tmp7;Cyc_aprintf(_tag_fat("%s.+.%s",sizeof(char),8U),_tag_fat(_Tmp8,sizeof(void*),2));});
goto _LL0;}}_LL0:;}
# 154
*seen=old_seen;
*depth=*depth + 1;
if(seen_it)res=({struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,_Tmp1.f1=res;_Tmp1;});void*_Tmp1[1];_Tmp1[0]=& _Tmp0;Cyc_aprintf(_tag_fat("<loop: %s>\n",sizeof(char),12U),_tag_fat(_Tmp1,sizeof(void*),1));});
return res;}}
# 160
struct _fat_ptr Cyc_AssnDef_term2string(void*t){
struct Cyc_Set_Set*s=Cyc_Set_empty(Cyc_AssnDef_termcmp);
int d=100;
return Cyc_AssnDef_term2string_i(t,& s,& d);}
# 166
static int Cyc_AssnDef_hash_const(union Cyc_Absyn_Cnst c){
struct _fat_ptr _Tmp0;long long _Tmp1;int _Tmp2;short _Tmp3;char _Tmp4;switch(c.String_c.tag){case 1:
 return 0;case 2: _Tmp4=c.Char_c.val.f1;{char c=_Tmp4;
return(int)c;}case 4: _Tmp3=c.Short_c.val.f1;{short c=_Tmp3;
return(int)c;}case 5: _Tmp2=c.Int_c.val.f1;{int i=_Tmp2;
return i;}case 6: _Tmp1=c.LongLong_c.val.f1;{long long i=_Tmp1;
return(int)i;}case 7: _Tmp0=c.Float_c.val.f0;{struct _fat_ptr s=_Tmp0;
_Tmp0=s;goto _LLE;}case 3: _Tmp0=c.Wchar_c.val;_LLE: {struct _fat_ptr s=_Tmp0;
_Tmp0=s;goto _LL10;}case 8: _Tmp0=c.String_c.val;_LL10: {struct _fat_ptr s=_Tmp0;
_Tmp0=s;goto _LL12;}default: _Tmp0=c.Wstring_c.val;_LL12: {struct _fat_ptr s=_Tmp0;
# 177
return Cyc_Hashtable_hash_string(s);}};}
# 181
static int Cyc_AssnDef_hash_binding(void*b){
void*_Tmp0;switch(*((int*)b)){case 4: _Tmp0=((struct Cyc_Absyn_Local_b_Absyn_Binding_struct*)b)->f1;{struct Cyc_Absyn_Vardecl*vd=_Tmp0;
return(int)(((unsigned)vd >> 4)+ 21U);}case 5: _Tmp0=((struct Cyc_Absyn_Pat_b_Absyn_Binding_struct*)b)->f1;{struct Cyc_Absyn_Vardecl*vd=_Tmp0;
return(int)(((unsigned)vd >> 4)+ 23U);}case 3: _Tmp0=((struct Cyc_Absyn_Param_b_Absyn_Binding_struct*)b)->f1;{struct Cyc_Absyn_Vardecl*vd=_Tmp0;
return(int)(((unsigned)vd >> 4)+ 27U);}case 2: _Tmp0=((struct Cyc_Absyn_Funname_b_Absyn_Binding_struct*)b)->f1;{struct Cyc_Absyn_Fndecl*vd=_Tmp0;
return(int)(((unsigned)vd >> 4)+ 29U);}case 1: _Tmp0=((struct Cyc_Absyn_Global_b_Absyn_Binding_struct*)b)->f1;{struct Cyc_Absyn_Vardecl*vd=_Tmp0;
return(int)(((unsigned)vd >> 4)+ 31U);}default: _Tmp0=((struct Cyc_Absyn_Unresolved_b_Absyn_Binding_struct*)b)->f1;{struct _tuple0*q=_Tmp0;
return 1;}};}
# 192
static int Cyc_AssnDef_hash_exp(struct Cyc_Absyn_Exp*e){
void*_Tmp0=e->r;void*_Tmp1;union Cyc_Absyn_Cnst _Tmp2;switch(*((int*)_Tmp0)){case 0: _Tmp2=((struct Cyc_Absyn_Const_e_Absyn_Raw_exp_struct*)_Tmp0)->f1;{union Cyc_Absyn_Cnst c=_Tmp2;
return Cyc_AssnDef_hash_const(c);}case 1: _Tmp1=(void*)((struct Cyc_Absyn_Var_e_Absyn_Raw_exp_struct*)_Tmp0)->f1;{void*b=_Tmp1;
return Cyc_AssnDef_hash_binding(b);}default:
 return(int)(*((const unsigned*)e->r)+ 1U);};}
# 200
int Cyc_AssnDef_termhash(void*t){
void*_Tmp0;void*_Tmp1;enum Cyc_Absyn_Primop _Tmp2;int _Tmp3;void*_Tmp4;unsigned _Tmp5;switch(*((int*)t)){case 0: _Tmp5=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)t)->f1;{unsigned i=_Tmp5;
return(int)i;}case 1: _Tmp4=((struct Cyc_AssnDef_Const_AssnDef_Term_struct*)t)->f1;{struct Cyc_Absyn_Exp*e=_Tmp4;
return Cyc_AssnDef_hash_exp(e)+ 61;}case 2: _Tmp4=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f1;_Tmp3=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f2;{struct Cyc_Absyn_Vardecl*vd=_Tmp4;int i=_Tmp3;
return(int)(((unsigned)vd >> 4)+ (unsigned)(i + 1));}case 3: _Tmp2=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f2;{enum Cyc_Absyn_Primop p=_Tmp2;void*t1=_Tmp4;
return(int)(((unsigned)p + ((unsigned)t1 >> 4))+ 1U);}case 4: _Tmp2=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;{enum Cyc_Absyn_Primop p=_Tmp2;void*t1=_Tmp4;void*t2=_Tmp1;
# 207
return(int)((unsigned)p + ((unsigned)t1 + (unsigned)t2 >> 4));}case 5: _Tmp4=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f2;{void*t=_Tmp4;
return Cyc_AssnDef_termhash(t)+ 1;}case 6: _Tmp4=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f2;{void*t1=_Tmp4;void*t2=_Tmp1;
# 210
return(int)(((unsigned)t1 + (unsigned)t2 >> 4)+ 2U);}case 7: _Tmp4=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp4;void*t2=_Tmp1;void*t3=_Tmp0;
# 212
return(int)((((unsigned)t1 + (unsigned)t2)+ (unsigned)t3 >> 4)+ 3U);}case 9: _Tmp4=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f2;{void*t=_Tmp4;unsigned i=_Tmp5;
return(int)((((unsigned)t >> 4)+ i)+ 23U);}case 8: _Tmp3=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f2;_Tmp4=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f3;{int is_union=_Tmp3;unsigned tag=_Tmp5;struct Cyc_List_List*ts=_Tmp4;
# 215
unsigned res=(37U + tag)+ (unsigned)is_union;
for(1;ts!=0;ts=ts->tl){
res=res + ((unsigned)((void*)ts->hd)>> 4);}
return(int)res;}case 10: _Tmp4=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f3;{void*a=_Tmp4;unsigned i=_Tmp5;void*v=_Tmp1;
# 220
return(int)((((unsigned)a + (unsigned)v >> 4)+ i)+ 17U);}case 11: _Tmp4=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f2;{struct Cyc_Absyn_Vardecl*vd=_Tmp4;void*invok=_Tmp1;
# 222
return(int)(((unsigned)invok + (unsigned)vd >> 4)+ 7U);}case 12: _Tmp4=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f1;_Tmp3=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f3;_Tmp0=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f4;{struct Cyc_Absyn_Exp*e=_Tmp4;int i=_Tmp3;void*n=_Tmp1;void*invok=_Tmp0;
# 224
return(int)((((unsigned)e + (unsigned)n)+ (unsigned)invok >> 4)+ (unsigned)i);}case 13: _Tmp4=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f1;_Tmp5=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f2;{void*t=_Tmp4;unsigned i=_Tmp5;
return(int)((((unsigned)t >> 4)+ i)+ 11U);}case 14: _Tmp4=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f2;{void*t=_Tmp4;void*index=_Tmp1;
# 227
return(int)(((unsigned)index + (unsigned)t >> 4)+ 13U);}default: _Tmp4=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)t)->f1;{void*t=_Tmp4;
return(int)(((unsigned)t >> 4)+ 741U);}};}struct _tuple15{void*f0;void*f1;};
# 232
int Cyc_AssnDef_termcmp(void*_t1,void*_t2){
void*t1=_t1;
void*t2=_t2;
LOOP: {
int c=(int)(*((const unsigned*)t1)- *((const unsigned*)t2));
if(c!=0)return c;
if(t1==t2)return 0;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});unsigned _Tmp1;unsigned _Tmp2;int _Tmp3;int _Tmp4;void*_Tmp5;void*_Tmp6;void*_Tmp7;enum Cyc_Absyn_Primop _Tmp8;void*_Tmp9;void*_TmpA;void*_TmpB;enum Cyc_Absyn_Primop _TmpC;switch(*((int*)_Tmp0.f0)){case 4: if(*((int*)_Tmp0.f1)==4){_TmpC=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpB=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp9=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f4;_Tmp8=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp6=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f3;_Tmp5=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f4;{enum Cyc_Absyn_Primop p1=_TmpC;void*t11=_TmpB;void*t12=_TmpA;void*tp1=_Tmp9;enum Cyc_Absyn_Primop p2=_Tmp8;void*t21=_Tmp7;void*t22=_Tmp6;void*tp2=_Tmp5;
# 241
int c=(int)p1 - (int)p2;
c=Cyc_AssnDef_termcmp(t11,t21);
if(c!=0)return c;
t1=t12;
t2=t22;
goto LOOP;}}else{goto _LL21;}case 2: if(*((int*)_Tmp0.f1)==2){_TmpB=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp4=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp3=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)_Tmp0.f1)->f2;{struct Cyc_Absyn_Vardecl*vd1=_TmpB;int i=_Tmp4;struct Cyc_Absyn_Vardecl*vd2=_TmpA;int j=_Tmp3;
# 248
int c=i - j;
if(c!=0)return c;
return(int)vd1 - (int)vd2;}}else{goto _LL21;}case 0: if(*((int*)_Tmp0.f1)==0){_Tmp2=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp1=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;{unsigned i1=_Tmp2;unsigned i2=_Tmp1;
return(int)(i1 - i2);}}else{goto _LL21;}case 1: if(*((int*)_Tmp0.f1)==1){_TmpB=((struct Cyc_AssnDef_Const_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=((struct Cyc_AssnDef_Const_AssnDef_Term_struct*)_Tmp0.f1)->f1;{struct Cyc_Absyn_Exp*e1=_TmpB;struct Cyc_Absyn_Exp*e2=_TmpA;
# 253
return Cyc_Evexp_exp_cmp(e1,e2);}}else{goto _LL21;}case 11: if(*((int*)_Tmp0.f1)==11){_TmpB=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp9=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f1)->f2;{struct Cyc_Absyn_Vardecl*vd1=_TmpB;void*i1=_TmpA;struct Cyc_Absyn_Vardecl*vd2=_Tmp9;void*i2=_Tmp7;
# 255
int c=(int)vd1 - (int)vd2;
if(c!=0)return c;
t1=i1;
t2=i2;
goto LOOP;}}else{goto _LL21;}case 3: if(*((int*)_Tmp0.f1)==3){_TmpC=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpB=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f2;{enum Cyc_Absyn_Primop p1=_TmpC;void*t1a=_TmpB;enum Cyc_Absyn_Primop p2=_Tmp8;void*t2a=_TmpA;
# 261
int c=(int)p1 - (int)p2;
if(c!=0)return c;
t1=t1a;
t2=t2a;
goto LOOP;}}else{goto _LL21;}case 5: if(*((int*)_Tmp0.f1)==5){_TmpB=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp9=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*tp1=_TmpB;void*tm1=_TmpA;void*tp2=_Tmp9;void*tm2=_Tmp7;
# 267
int c=Cyc_Tcutil_typecmp(tp1,tp2);
if(c!=0)return c;
t1=tm1;
t2=tm2;
goto LOOP;}}else{goto _LL21;}case 6: if(*((int*)_Tmp0.f1)==6){_TmpB=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp9=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*t11=_TmpB;void*t12=_TmpA;void*t21=_Tmp9;void*t22=_Tmp7;
# 273
int c=Cyc_AssnDef_termcmp(t11,t21);
if(c!=0)return c;
t1=t12;
t2=t22;
goto LOOP;}}else{goto _LL21;}case 7: if(*((int*)_Tmp0.f1)==7){_TmpB=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp9=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp7=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f1)->f3;{void*t11=_TmpB;void*t12=_TmpA;void*t13=_Tmp9;void*t21=_Tmp7;void*t22=_Tmp6;void*t23=_Tmp5;
# 279
int c=Cyc_AssnDef_termcmp(t11,t21);
if(c!=0)return c;
c=Cyc_AssnDef_termcmp(t12,t22);
if(c!=0)return c;
t1=t13;
t2=t23;
goto LOOP;}}else{goto _LL21;}case 15: if(*((int*)_Tmp0.f1)==15){_TmpB=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)_Tmp0.f1)->f1;{void*tm1=_TmpB;void*tm2=_TmpA;
# 287
t1=tm1;
t2=tm2;
goto LOOP;}}else{goto _LL21;}case 9: if(*((int*)_Tmp0.f1)==9){_TmpB=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp2=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*tm1=_TmpB;unsigned i1=_Tmp2;void*tm2=_TmpA;unsigned i2=_Tmp1;
# 291
int c=(int)(i1 - i2);
if(c!=0)return c;
t1=tm1;
t2=tm2;
goto LOOP;}}else{goto _LL21;}case 10: if(*((int*)_Tmp0.f1)==10){_TmpB=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp2=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp9=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp7=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f1)->f3;{void*tm1=_TmpB;unsigned i1=_Tmp2;void*v1=_TmpA;void*tm2=_Tmp9;unsigned i2=_Tmp1;void*v2=_Tmp7;
# 297
int c=(int)(i1 - i2);
if(c!=0)return c;
c=Cyc_AssnDef_termcmp(tm1,tm2);
if(c!=0)return c;
t1=v1;
t2=v2;
goto LOOP;}}else{goto _LL21;}case 12: if(*((int*)_Tmp0.f1)==12){_TmpB=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp4=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp9=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f4;_Tmp7=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp3=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp6=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f3;_Tmp5=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f4;{struct Cyc_Absyn_Exp*e1=_TmpB;int i1=_Tmp4;void*n1=_TmpA;void*v1=_Tmp9;struct Cyc_Absyn_Exp*e2=_Tmp7;int i2=_Tmp3;void*n2=_Tmp6;void*v2=_Tmp5;
# 305
int c=(int)e1 - (int)e2;
if(c!=0)return c;
c=i1 - i2;
if(c!=0)return c;
c=Cyc_AssnDef_termcmp(n1,n2);
if(c!=0)return c;
t1=v1;
t2=v2;
goto LOOP;}}else{goto _LL21;}case 13: if(*((int*)_Tmp0.f1)==13){_TmpB=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp2=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*tm1=_TmpB;unsigned i1=_Tmp2;void*tm2=_TmpA;unsigned i2=_Tmp1;
# 315
int c=(int)(i1 - i2);
if(c!=0)return c;
t1=tm1;
t2=tm2;
goto LOOP;}}else{goto _LL21;}case 14: if(*((int*)_Tmp0.f1)==14){_TmpB=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp9=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*tm1=_TmpB;void*i1=_TmpA;void*tm2=_Tmp9;void*i2=_Tmp7;
# 321
int c=Cyc_AssnDef_termcmp(i1,i2);
if(c!=0)return c;
t1=tm1;
t2=tm2;
goto LOOP;}}else{goto _LL21;}default: if(*((int*)_Tmp0.f1)==8){_Tmp4=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp2=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpB=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp3=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f1)->f2;_TmpA=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f1)->f3;{int is_union1=_Tmp4;unsigned tag1=_Tmp2;struct Cyc_List_List*ts1=_TmpB;int is_union2=_Tmp3;unsigned tag2=_Tmp1;struct Cyc_List_List*ts2=_TmpA;
# 327
int c=(int)(tag1 - tag2);
if(c!=0)return c;
c=is_union2 - is_union1;
if(c!=0)return c;
for(1;ts1!=0 && ts2!=0;(ts1=ts1->tl,ts2=ts2->tl)){
c=Cyc_AssnDef_termcmp((void*)ts1->hd,(void*)ts2->hd);
if(c!=0)return c;}
# 335
if(ts1==ts2)return 0;
if(ts1==0)return -1;
return 1;}}else{_LL21:
({int(*_TmpD)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_TmpD;})(_tag_fat("different terms but same codes!",sizeof(char),32U),_tag_fat(0U,sizeof(void*),0));}};}}}
# 342
static void*Cyc_AssnDef_copy_term(void*t,unsigned*size){
void*_Tmp0;enum Cyc_Absyn_Primop _Tmp1;int _Tmp2;void*_Tmp3;void*_Tmp4;void*_Tmp5;unsigned _Tmp6;switch(*((int*)t)){case 0: _Tmp6=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)t)->f2;{unsigned i=_Tmp6;void*tp=_Tmp5;
*size=1U;return(void*)({struct Cyc_AssnDef_Uint_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Uint_AssnDef_Term_struct));_Tmp7->tag=0,_Tmp7->f1=i,_Tmp7->f2=tp;_Tmp7;});}case 1: _Tmp5=((struct Cyc_AssnDef_Const_AssnDef_Term_struct*)t)->f1;{struct Cyc_Absyn_Exp*e=_Tmp5;
*size=1U;return(void*)({struct Cyc_AssnDef_Const_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Const_AssnDef_Term_struct));_Tmp7->tag=1,_Tmp7->f1=e;_Tmp7;});}case 11: _Tmp5=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f3;{struct Cyc_Absyn_Vardecl*vd=_Tmp5;void*t=_Tmp4;void*tp=_Tmp3;
# 347
({unsigned _Tmp7=1U + Cyc_AssnDef_term_size(t);*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Addr_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Addr_AssnDef_Term_struct));_Tmp7->tag=11,_Tmp7->f1=vd,_Tmp7->f2=t,_Tmp7->f3=tp;_Tmp7;});}case 2: _Tmp5=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f1;_Tmp2=((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f3;{struct Cyc_Absyn_Vardecl*vd=_Tmp5;int i=_Tmp2;void*tp=_Tmp4;
# 350
*size=1U;
return(void*)({struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct));_Tmp7->tag=2,_Tmp7->f1=vd,_Tmp7->f2=i,_Tmp7->f3=tp;_Tmp7;});}case 4: _Tmp1=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;_Tmp3=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f4;{enum Cyc_Absyn_Primop p=_Tmp1;void*t1=_Tmp5;void*t2=_Tmp4;void*tp=_Tmp3;
# 353
({unsigned _Tmp7=({unsigned _Tmp8=1U + Cyc_AssnDef_term_size(t1);_Tmp8 + Cyc_AssnDef_term_size(t2);});*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Binop_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Binop_AssnDef_Term_struct));_Tmp7->tag=4,_Tmp7->f1=p,_Tmp7->f2=t1,_Tmp7->f3=t2,_Tmp7->f4=tp;_Tmp7;});}case 3: _Tmp1=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f3;{enum Cyc_Absyn_Primop p=_Tmp1;void*t=_Tmp5;void*tp=_Tmp4;
# 356
({unsigned _Tmp7=1U + Cyc_AssnDef_term_size(t);*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Unop_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Unop_AssnDef_Term_struct));_Tmp7->tag=3,_Tmp7->f1=p,_Tmp7->f2=t,_Tmp7->f3=tp;_Tmp7;});}case 5: _Tmp5=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f2;{void*tp=_Tmp5;void*t=_Tmp4;
# 359
({unsigned _Tmp7=1U + Cyc_AssnDef_term_size(t);*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Cast_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Cast_AssnDef_Term_struct));_Tmp7->tag=5,_Tmp7->f1=tp,_Tmp7->f2=t;_Tmp7;});}case 6: _Tmp5=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp5;void*t2=_Tmp4;void*tp=_Tmp3;
# 362
({unsigned _Tmp7=({unsigned _Tmp8=1U + Cyc_AssnDef_term_size(t1);_Tmp8 + Cyc_AssnDef_term_size(t2);});*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Select_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Select_AssnDef_Term_struct));_Tmp7->tag=6,_Tmp7->f1=t1,_Tmp7->f2=t2,_Tmp7->f3=tp;_Tmp7;});}case 7: _Tmp5=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp5;void*t2=_Tmp4;void*t3=_Tmp3;
# 365
({unsigned _Tmp7=({unsigned _Tmp8=({unsigned _Tmp9=1U + Cyc_AssnDef_term_size(t1);_Tmp9 + Cyc_AssnDef_term_size(t2);});_Tmp8 + Cyc_AssnDef_term_size(t3);});*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Update_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Update_AssnDef_Term_struct));_Tmp7->tag=7,_Tmp7->f1=t1,_Tmp7->f2=t2,_Tmp7->f3=t3;_Tmp7;});}case 9: _Tmp5=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f1;_Tmp6=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f3;{void*t=_Tmp5;unsigned i=_Tmp6;void*tp=_Tmp4;
# 368
({unsigned _Tmp7=1U + Cyc_AssnDef_term_size(t);*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Proj_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Proj_AssnDef_Term_struct));_Tmp7->tag=9,_Tmp7->f1=t,_Tmp7->f2=i,_Tmp7->f3=tp;_Tmp7;});}case 10: _Tmp5=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f1;_Tmp6=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f3;{void*t=_Tmp5;unsigned i=_Tmp6;void*v=_Tmp4;
# 371
({unsigned _Tmp7=({unsigned _Tmp8=1U + Cyc_AssnDef_term_size(t);_Tmp8 + Cyc_AssnDef_term_size(v);});*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct));_Tmp7->tag=10,_Tmp7->f1=t,_Tmp7->f2=i,_Tmp7->f3=v;_Tmp7;});}case 8: _Tmp2=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f1;_Tmp6=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f2;_Tmp5=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f3;_Tmp4=(void*)((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f4;{int is_union=_Tmp2;unsigned tag=_Tmp6;struct Cyc_List_List*ts=_Tmp5;void*tp=_Tmp4;
# 374
*size=1U;
{struct Cyc_List_List*p=ts;for(0;p!=0;p=p->tl){({unsigned _Tmp7=Cyc_AssnDef_term_size((void*)p->hd);*size +=_Tmp7;});}}
return(void*)({struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Aggr_AssnDef_Term_struct));_Tmp7->tag=8,_Tmp7->f1=is_union,_Tmp7->f2=tag,_Tmp7->f3=ts,_Tmp7->f4=tp;_Tmp7;});}case 12: _Tmp5=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f1;_Tmp2=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f3;_Tmp3=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f4;_Tmp0=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f5;{struct Cyc_Absyn_Exp*e=_Tmp5;int i=_Tmp2;void*n=_Tmp4;void*v=_Tmp3;void*tp=_Tmp0;
# 378
({unsigned _Tmp7=({unsigned _Tmp8=1U + Cyc_AssnDef_term_size(v);_Tmp8 + Cyc_AssnDef_term_size(n);});*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Alloc_AssnDef_Term_struct));_Tmp7->tag=12,_Tmp7->f1=e,_Tmp7->f2=i,_Tmp7->f3=n,_Tmp7->f4=v,_Tmp7->f5=tp;_Tmp7;});}case 13: _Tmp5=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f1;_Tmp6=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f3;{void*t=_Tmp5;unsigned i=_Tmp6;void*tp=_Tmp4;
# 381
({unsigned _Tmp7=1U + Cyc_AssnDef_term_size(t);*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct));_Tmp7->tag=13,_Tmp7->f1=t,_Tmp7->f2=i,_Tmp7->f3=tp;_Tmp7;});}case 14: _Tmp5=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f1;_Tmp4=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f3;{void*t=_Tmp5;void*i=_Tmp4;void*tp=_Tmp3;
# 384
({unsigned _Tmp7=({unsigned _Tmp8=1U + Cyc_AssnDef_term_size(t);_Tmp8 + Cyc_AssnDef_term_size(i);});*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Offseti_AssnDef_Term_struct));_Tmp7->tag=14,_Tmp7->f1=t,_Tmp7->f2=i,_Tmp7->f3=tp;_Tmp7;});}default: _Tmp5=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)t)->f1;{void*t=_Tmp5;
# 387
({unsigned _Tmp7=1U + Cyc_AssnDef_term_size(t);*size=_Tmp7;});
return(void*)({struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*_Tmp7=_cycalloc(sizeof(struct Cyc_AssnDef_Tagof_AssnDef_Term_struct));_Tmp7->tag=15,_Tmp7->f1=t;_Tmp7;});}};}
# 392
struct Cyc_AssnDef_Uint_AssnDef_Term_struct Cyc_AssnDef_zero_value={0,0U,0};
struct Cyc_AssnDef_Uint_AssnDef_Term_struct Cyc_AssnDef_one_value={0,1U,0};
# 395
static struct Cyc_Set_Set*Cyc_AssnDef_empty_term_set (void){
static struct Cyc_Set_Set**term_set=0;
if(term_set==0)
term_set=({struct Cyc_Set_Set**_Tmp0=_cycalloc(sizeof(struct Cyc_Set_Set*));({struct Cyc_Set_Set*_Tmp1=Cyc_Set_empty(Cyc_AssnDef_termcmp);*_Tmp0=_Tmp1;});_Tmp0;});
# 400
return*term_set;}struct Cyc_AssnDef_TermHashedInfo{void*term;unsigned size;struct Cyc_Set_Set**free_logicvar_set;};
# 410
static struct Cyc_Hashtable_Table*Cyc_AssnDef_term_hash_cons_table=0;
# 413
static struct Cyc_Hashtable_Table*Cyc_AssnDef_get_term_hash_cons_table (void){
# 415
struct Cyc_Hashtable_Table*h;
if(Cyc_AssnDef_term_hash_cons_table==0){
h=Cyc_Hashtable_create(221,Cyc_AssnDef_termcmp,Cyc_AssnDef_termhash);
Cyc_AssnDef_term_hash_cons_table=h;{
struct Cyc_Set_Set*tst=Cyc_AssnDef_empty_term_set();
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=h;_Tmp0(_Tmp1,(void*)& Cyc_AssnDef_zero_value,({struct Cyc_AssnDef_TermHashedInfo*_Tmp2=_cycalloc(sizeof(struct Cyc_AssnDef_TermHashedInfo));_Tmp2->term=(void*)& Cyc_AssnDef_zero_value,_Tmp2->size=1U,({struct Cyc_Set_Set**_Tmp3=({struct Cyc_Set_Set**_Tmp4=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp4=tst;_Tmp4;});_Tmp2->free_logicvar_set=_Tmp3;});_Tmp2;}));});
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=h;_Tmp0(_Tmp1,(void*)& Cyc_AssnDef_one_value,({struct Cyc_AssnDef_TermHashedInfo*_Tmp2=_cycalloc(sizeof(struct Cyc_AssnDef_TermHashedInfo));_Tmp2->term=(void*)& Cyc_AssnDef_one_value,_Tmp2->size=1U,({struct Cyc_Set_Set**_Tmp3=({struct Cyc_Set_Set**_Tmp4=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp4=tst;_Tmp4;});_Tmp2->free_logicvar_set=_Tmp3;});_Tmp2;}));});}}else{
# 423
h=Cyc_AssnDef_term_hash_cons_table;}
# 425
return h;}
# 428
static void*Cyc_AssnDef_hash_cons_term(void*t){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_term_hash_cons_table();
struct Cyc_AssnDef_TermHashedInfo**resopt=({struct Cyc_AssnDef_TermHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,int(*)(void*,void*),int(*)(void*))=(struct Cyc_AssnDef_TermHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*,int(*)(void*,void*),int(*)(void*)))Cyc_Hashtable_lookup_other_opt;_Tmp0;})(h,t,Cyc_AssnDef_termcmp,Cyc_AssnDef_termhash);
if(resopt==0){
unsigned size=0U;
void*t2=Cyc_AssnDef_copy_term(t,& size);
# 435
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_TermHashedInfo*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=h;void*_Tmp2=t2;_Tmp0(_Tmp1,_Tmp2,({struct Cyc_AssnDef_TermHashedInfo*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_TermHashedInfo));_Tmp3->term=t2,_Tmp3->size=size,_Tmp3->free_logicvar_set=0;_Tmp3;}));});
# 438
return t2;}else{
# 440
return(*resopt)->term;}}
# 444
unsigned Cyc_AssnDef_term_size(void*t){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_term_hash_cons_table();
struct Cyc_AssnDef_TermHashedInfo**resopt=({struct Cyc_AssnDef_TermHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_TermHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,t);
if(resopt==0){
Cyc_AssnDef_hash_cons_term(t);
return Cyc_AssnDef_term_size(t);}{
# 451
struct Cyc_AssnDef_TermHashedInfo*res=*resopt;
return res->size;}}
# 458
struct Cyc_Set_Set*Cyc_AssnDef_term_fr_logicvar(void*t){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_term_hash_cons_table();
struct Cyc_AssnDef_TermHashedInfo**thinfo=({struct Cyc_AssnDef_TermHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_TermHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,t);
# 462
if(thinfo==0){
t=Cyc_AssnDef_hash_cons_term(t);
thinfo=({struct Cyc_AssnDef_TermHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_TermHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,t);}
# 466
if((*_check_null(thinfo))->free_logicvar_set!=0)
return*(*thinfo)->free_logicvar_set;{
struct Cyc_Set_Set*res;
{void*_Tmp0;void*_Tmp1;void*_Tmp2;switch(*((int*)t)){case 0:
 goto _LL4;case 1: _LL4:
# 472
 res=Cyc_AssnDef_empty_term_set();goto _LL0;case 2:
# 474
 res=Cyc_Set_singleton(Cyc_AssnDef_termcmp,t);
goto _LL0;case 12: _Tmp2=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f3;_Tmp1=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f4;{void*t1=_Tmp2;void*t2=_Tmp1;
# 477
_Tmp2=t1;_Tmp1=t2;goto _LLA;}case 6: _Tmp2=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f2;_LLA: {void*t1=_Tmp2;void*t2=_Tmp1;
# 479
_Tmp2=t1;_Tmp1=t2;goto _LLC;}case 10: _Tmp2=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f3;_LLC: {void*t1=_Tmp2;void*t2=_Tmp1;
# 481
_Tmp2=t1;_Tmp1=t2;goto _LLE;}case 4: _Tmp2=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;_LLE: {void*t1=_Tmp2;void*t2=_Tmp1;
# 483
_Tmp2=t1;_Tmp1=t2;goto _LL10;}case 14: _Tmp2=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f2;_LL10: {void*t1=_Tmp2;void*t2=_Tmp1;
# 485
res=({struct Cyc_Set_Set*_Tmp3=Cyc_AssnDef_term_fr_logicvar(t1);Cyc_Set_union_two(_Tmp3,Cyc_AssnDef_term_fr_logicvar(t2));});
goto _LL0;}case 7: _Tmp2=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp2;void*t2=_Tmp1;void*t3=_Tmp0;
# 488
res=({struct Cyc_Set_Set*_Tmp3=({struct Cyc_Set_Set*_Tmp4=Cyc_AssnDef_term_fr_logicvar(t1);Cyc_Set_union_two(_Tmp4,
Cyc_AssnDef_term_fr_logicvar(t2));});
# 488
Cyc_Set_union_two(_Tmp3,
# 490
Cyc_AssnDef_term_fr_logicvar(t3));});
goto _LL0;}case 11: _Tmp2=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f2;{void*t1=_Tmp2;
# 493
_Tmp2=t1;goto _LL16;}case 3: _Tmp2=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f2;_LL16: {void*t1=_Tmp2;
# 495
_Tmp2=t1;goto _LL18;}case 9: _Tmp2=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f1;_LL18: {void*t1=_Tmp2;
# 497
_Tmp2=t1;goto _LL1A;}case 13: _Tmp2=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f1;_LL1A: {void*t1=_Tmp2;
# 499
_Tmp2=t1;goto _LL1C;}case 15: _Tmp2=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)t)->f1;_LL1C: {void*t1=_Tmp2;
# 501
_Tmp2=t1;goto _LL1E;}case 5: _Tmp2=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f2;_LL1E: {void*t1=_Tmp2;
# 503
res=Cyc_AssnDef_term_fr_logicvar(t1);
goto _LL0;}default: _Tmp2=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f3;{struct Cyc_List_List*ts=_Tmp2;
# 506
struct Cyc_List_List*tsets=({struct Cyc_List_List*(*_Tmp3)(struct Cyc_Set_Set*(*)(void*),struct Cyc_List_List*)=(struct Cyc_List_List*(*)(struct Cyc_Set_Set*(*)(void*),struct Cyc_List_List*))Cyc_List_map;_Tmp3;})(Cyc_AssnDef_term_fr_logicvar,ts);
res=({struct Cyc_Set_Set*(*_Tmp3)(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Set_Set*),struct Cyc_Set_Set*,struct Cyc_List_List*)=({struct Cyc_Set_Set*(*_Tmp4)(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Set_Set*),struct Cyc_Set_Set*,struct Cyc_List_List*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Set_Set*),struct Cyc_Set_Set*,struct Cyc_List_List*))Cyc_List_fold_left;_Tmp4;});struct Cyc_Set_Set*_Tmp4=Cyc_AssnDef_empty_term_set();_Tmp3(Cyc_Set_union_two,_Tmp4,tsets);});
goto _LL0;}}_LL0:;}
# 510
({struct Cyc_Set_Set**_Tmp0=({struct Cyc_Set_Set**_Tmp1=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp1=res;_Tmp1;});(*thinfo)->free_logicvar_set=_Tmp0;});
return res;}}
# 514
static int Cyc_AssnDef_logicvar_in_term(void*lvar,void*t){
struct Cyc_Set_Set*lvset=Cyc_AssnDef_term_fr_logicvar(t);
return Cyc_Set_member(lvset,lvar);}
# 519
void*Cyc_AssnDef_uint(unsigned i){
struct Cyc_AssnDef_Uint_AssnDef_Term_struct t=({struct Cyc_AssnDef_Uint_AssnDef_Term_struct _Tmp0;_Tmp0.tag=0,_Tmp0.f1=i,_Tmp0.f2=0;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}
# 523
void*Cyc_AssnDef_zero (void){
return(void*)& Cyc_AssnDef_zero_value;}
# 526
void*Cyc_AssnDef_one (void){
return(void*)& Cyc_AssnDef_one_value;}
# 529
void*Cyc_AssnDef_cnst(struct Cyc_Absyn_Exp*e){
struct _tuple11 _Tmp0=Cyc_Evexp_eval_const_uint_exp(e);int _Tmp1;unsigned _Tmp2;_Tmp2=_Tmp0.f0;_Tmp1=_Tmp0.f1;{unsigned c=_Tmp2;int known=_Tmp1;
if(known)return Cyc_AssnDef_uint(c);{
struct Cyc_AssnDef_Const_AssnDef_Term_struct t=({struct Cyc_AssnDef_Const_AssnDef_Term_struct _Tmp3;_Tmp3.tag=1,_Tmp3.f1=e;_Tmp3;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}}
# 535
void*Cyc_AssnDef_addr(struct Cyc_Absyn_Vardecl*vd,void*invok){
void*tp=vd->type;
{void*_Tmp0=Cyc_Absyn_compress(tp);if(*((int*)_Tmp0)==5)
goto _LL0;else{
# 540
void*rgn=(unsigned)vd->rgn?vd->rgn: Cyc_Absyn_heap_rgn_type;
tp=({void*_Tmp1=tp;void*_Tmp2=rgn;void*_Tmp3=Cyc_Absyn_al_qual_type;struct Cyc_Absyn_Tqual _Tmp4=Cyc_Absyn_empty_tqual(0U);void*_Tmp5=Cyc_Absyn_false_type;Cyc_Absyn_at_type(_Tmp1,_Tmp2,_Tmp3,_Tmp4,_Tmp5,Cyc_Absyn_false_type);});}_LL0:;}{
# 543
struct Cyc_AssnDef_Addr_AssnDef_Term_struct t=({struct Cyc_AssnDef_Addr_AssnDef_Term_struct _Tmp0;_Tmp0.tag=11,_Tmp0.f1=vd,_Tmp0.f2=invok,_Tmp0.f3=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}
# 546
void*Cyc_AssnDef_logicvar(struct Cyc_Absyn_Vardecl*vd,int i,void*tp){
struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct t=({struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct _Tmp0;_Tmp0.tag=2,_Tmp0.f1=vd,_Tmp0.f2=i,_Tmp0.f3=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}
# 550
void*Cyc_AssnDef_update(void*t1,void*t2,void*t3){
LOOP1: {
# 558
void*_Tmp0;unsigned _Tmp1;void*_Tmp2;if(*((int*)t2)==13){_Tmp2=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t2)->f1;_Tmp1=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t2)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t2)->f3;{void*a=_Tmp2;unsigned i=_Tmp1;void*tp=_Tmp0;
# 560
t2=a;{
void*tpopt=0;
if(tp!=0 && Cyc_Tcutil_is_pointer_type(tp))
tpopt=Cyc_Tcutil_pointer_elt_type(tp);
t3=({void*_Tmp3=Cyc_AssnDef_select(t1,a,tp);unsigned _Tmp4=i;Cyc_AssnDef_aggr_update(_Tmp3,_Tmp4,t3);});
goto LOOP1;}}}else{
# 567
goto _LL0;}_LL0:;}
# 570
LOOP2: {
void*_Tmp0;void*_Tmp1;if(*((int*)t1)==7){_Tmp1=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t1)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t1)->f2;if((void*)_Tmp0==t2){void*m=_Tmp1;void*t=_Tmp0;
# 573
t1=m;
goto LOOP2;}else{goto _LL8;}}else{_LL8:
 goto _LL5;}_LL5:;}{
# 577
struct Cyc_AssnDef_Update_AssnDef_Term_struct t=({struct Cyc_AssnDef_Update_AssnDef_Term_struct _Tmp0;_Tmp0.tag=7,_Tmp0.f1=t1,_Tmp0.f2=t2,_Tmp0.f3=t3;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}
# 581
void*Cyc_AssnDef_aggr_update(void*t1,unsigned i,void*t2){
LOOP: {
int _Tmp0;void*_Tmp1;unsigned _Tmp2;void*_Tmp3;switch(*((int*)t1)){case 10: _Tmp3=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f1;_Tmp2=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f3;{void*t=_Tmp3;unsigned j=_Tmp2;void*t3=_Tmp1;
# 585
if(i==j){
# 587
t1=t;
goto LOOP;}
# 590
if(i < j){
# 593
void*_Tmp4=Cyc_AssnDef_aggr_update(t,i,t2);unsigned _Tmp5=j;return Cyc_AssnDef_aggr_update(_Tmp4,_Tmp5,t3);}
# 595
goto _LL0;}case 8: _Tmp0=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f1;_Tmp2=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f2;_Tmp3=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f3;_Tmp1=(void*)((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f4;{int is_union=_Tmp0;unsigned tag=_Tmp2;struct Cyc_List_List*ts=_Tmp3;void*tp=_Tmp1;
# 598
if(is_union){int _Tmp4=is_union;unsigned _Tmp5=i;struct Cyc_List_List*_Tmp6=({void*_Tmp7[1];_Tmp7[0]=t2;Cyc_List_list(_tag_fat(_Tmp7,sizeof(void*),1));});return Cyc_AssnDef_aggr(_Tmp4,_Tmp5,_Tmp6,tp);}{
# 600
struct Cyc_List_List*revnewts=0;
for(1;i!=0U;-- i){
if(ts==0)goto _LL6;
revnewts=({struct Cyc_List_List*_Tmp4=_cycalloc(sizeof(struct Cyc_List_List));_Tmp4->hd=(void*)ts->hd,_Tmp4->tl=revnewts;_Tmp4;});
ts=ts->tl;}
# 606
if(ts==0)goto _LL6;{
struct Cyc_List_List*newts=({struct Cyc_List_List*_Tmp4=revnewts;Cyc_List_revappend(_Tmp4,({struct Cyc_List_List*_Tmp5=_cycalloc(sizeof(struct Cyc_List_List));_Tmp5->hd=t2,_Tmp5->tl=ts->tl;_Tmp5;}));});
void*res=Cyc_AssnDef_aggr(is_union,tag,newts,tp);
return res;}}}default: _LL6:
# 611
 goto _LL0;}_LL0:;}{
# 613
struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct t=({struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct _Tmp0;_Tmp0.tag=10,_Tmp0.f1=t1,_Tmp0.f2=i,_Tmp0.f3=t2;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}
# 617
static int Cyc_AssnDef_address_disjoint(void*,void*);
# 620
static int Cyc_AssnDef_term_neq(void*t1,void*t2){
LOOP: {
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});void*_Tmp1;void*_Tmp2;void*_Tmp3;void*_Tmp4;unsigned _Tmp5;unsigned _Tmp6;switch(*((int*)_Tmp0.f0)){case 0: switch(*((int*)_Tmp0.f1)){case 0: _Tmp6=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp5=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;{unsigned i=_Tmp6;unsigned j=_Tmp5;
return i!=j;}case 4: if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Plus)goto _LL7;else{goto _LLD;}case 3: if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Bitnot)goto _LLB;else{goto _LLD;}default: goto _LLD;}case 4: if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f1==Cyc_Absyn_Plus){if(*((int*)_Tmp0.f1)==4){if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Plus){_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp2=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f3;if((void*)_Tmp4==(void*)_Tmp2){void*t11=_Tmp4;void*t12=_Tmp3;void*t21=_Tmp2;void*t22=_Tmp1;
# 626
t1=t12;
t2=t22;
goto LOOP;}else{goto _LL5;}}else{goto _LL5;}}else{_LL5: _Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp2=_Tmp0.f1;if((void*)_Tmp4==(void*)_Tmp2){void*t11=_Tmp4;void*t12=_Tmp3;void*t21=_Tmp2;
# 630
t1=t12;
t2=Cyc_AssnDef_zero();
goto LOOP;}else{if(*((int*)_Tmp0.f1)==3){if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Bitnot)goto _LLB;else{goto _LLD;}}else{goto _LLD;}}}}else{switch(*((int*)_Tmp0.f1)){case 4: if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Plus)goto _LL7;else{goto _LLD;}case 3: if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Bitnot)goto _LLB;else{goto _LLD;}default: goto _LLD;}}default: if(*((int*)_Tmp0.f1)==4){if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Plus){_LL7: _Tmp4=_Tmp0.f0;_Tmp3=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp2=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f3;if((void*)_Tmp4==(void*)_Tmp3){void*t11=_Tmp4;void*t21=_Tmp3;void*t22=_Tmp2;
# 634
t1=Cyc_AssnDef_zero();
t2=t22;
goto LOOP;}else{if(*((int*)_Tmp0.f0)==3){if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f1==Cyc_Absyn_Bitnot)goto _LL9;else{goto _LLD;}}else{goto _LLD;}}}else{if(*((int*)_Tmp0.f0)==3){if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f1==Cyc_Absyn_Bitnot)goto _LL9;else{goto _LLD;}}else{goto _LLD;}}}else{if(*((int*)_Tmp0.f0)==3){if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f1==Cyc_Absyn_Bitnot){_LL9: _Tmp4=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp3=_Tmp0.f1;if((void*)_Tmp4==(void*)_Tmp3){void*t1=_Tmp4;void*t2=_Tmp3;
return 1;}else{if(*((int*)_Tmp0.f1)==3){if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Bitnot)goto _LLB;else{goto _LLD;}}else{goto _LLD;}}}else{if(*((int*)_Tmp0.f1)==3){if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Bitnot)goto _LLB;else{goto _LLD;}}else{goto _LLD;}}}else{if(*((int*)_Tmp0.f1)==3){if(((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1==Cyc_Absyn_Bitnot){_LLB: _Tmp4=_Tmp0.f0;_Tmp3=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f2;if((void*)_Tmp4==(void*)_Tmp3){void*t1=_Tmp4;void*t2=_Tmp3;
return 1;}else{goto _LLD;}}else{goto _LLD;}}else{_LLD:
# 641
 return Cyc_AssnDef_address_disjoint(t1,t2);}}}};}}
# 647
static int Cyc_AssnDef_address_disjoint(void*t1,void*t2){
LOOP:
 if(t1==t2)return 0;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});unsigned _Tmp1;unsigned _Tmp2;void*_Tmp3;void*_Tmp4;int _Tmp5;int _Tmp6;void*_Tmp7;void*_Tmp8;void*_Tmp9;void*_TmpA;switch(*((int*)_Tmp0.f0)){case 11: switch(*((int*)_Tmp0.f1)){case 11: _TmpA=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp9=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f1)->f2;{struct Cyc_Absyn_Vardecl*x=_TmpA;void*nv1=_Tmp9;struct Cyc_Absyn_Vardecl*y=_Tmp8;void*nv2=_Tmp7;
# 653
return x!=y;}case 12:
 return 1;case 13: goto _LLF;case 14: goto _LL13;default: goto _LL15;}case 12: switch(*((int*)_Tmp0.f1)){case 11:
 return 1;case 12: _TmpA=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp6=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp9=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp8=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f0)->f4;_Tmp7=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp5=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f3;_Tmp3=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)_Tmp0.f1)->f4;{struct Cyc_Absyn_Exp*exp1=_TmpA;int i1=_Tmp6;void*tm1=_Tmp9;void*nv1=_Tmp8;struct Cyc_Absyn_Exp*exp2=_Tmp7;int i2=_Tmp5;void*tm2=_Tmp4;void*nv2=_Tmp3;
# 660
return exp1!=exp2 || i1!=i2;}case 13: goto _LLF;case 14: goto _LL13;default: goto _LL15;}case 13: if(*((int*)_Tmp0.f1)==13){_TmpA=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp2=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp9=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*tm1=_TmpA;unsigned i=_Tmp2;void*tm2=_Tmp9;unsigned j=_Tmp1;
# 664
if(tm1==tm2 && i!=j)return 1;
t1=tm1;
t2=tm2;
goto LOOP;}}else{_TmpA=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f1;{void*tm1=_TmpA;
# 676
t1=tm1;
goto LOOP;}}case 14: switch(*((int*)_Tmp0.f1)){case 14: _TmpA=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp9=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*tm1=_TmpA;void*i1=_Tmp9;void*tm2=_Tmp8;void*i2=_Tmp7;
# 669
if(tm1==tm2 && Cyc_AssnDef_term_neq(i1,i2))return 1;
t1=tm1;
t2=tm2;
goto LOOP;}case 13: goto _LLF;default: _TmpA=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f1;{void*tm1=_TmpA;
# 682
t1=tm1;
goto LOOP;}}default: switch(*((int*)_Tmp0.f1)){case 13: _LLF: _TmpA=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f1;{void*tm2=_TmpA;
# 679
t2=tm2;
goto LOOP;}case 14: _LL13: _TmpA=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f1;{void*tm2=_TmpA;
# 685
t2=tm2;
goto LOOP;}default: _LL15:
 return 0;}};}}struct _tuple16{int f0;void*f1;};
# 691
struct _tuple12 Cyc_AssnDef_split_addr(void*a){
struct Cyc_List_List*fields=0;
while(1){
{void*_Tmp0;unsigned _Tmp1;void*_Tmp2;if(*((int*)a)==13){_Tmp2=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)a)->f1;_Tmp1=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)a)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)a)->f3;{void*r=_Tmp2;unsigned i=_Tmp1;void*tp=_Tmp0;
# 696
fields=({struct Cyc_List_List*_Tmp3=_cycalloc(sizeof(struct Cyc_List_List));({struct _tuple16*_Tmp4=({struct _tuple16*_Tmp5=_cycalloc(sizeof(struct _tuple16));_Tmp5->f0=(int)i,_Tmp5->f1=tp;_Tmp5;});_Tmp3->hd=_Tmp4;}),_Tmp3->tl=fields;_Tmp3;});
a=r;
continue;}}else{
# 700
struct _tuple12 _Tmp3;_Tmp3.f0=a,_Tmp3.f1=fields;return _Tmp3;};}
# 694
1U;}}
# 705
void*Cyc_AssnDef_apply_aggr_update(void*a,struct Cyc_List_List*fields,void*v){
if(fields==0)return v;{
struct _tuple16*_Tmp0=(struct _tuple16*)fields->hd;void*_Tmp1;int _Tmp2;_Tmp2=_Tmp0->f0;_Tmp1=_Tmp0->f1;{int i=_Tmp2;void*tpopt=_Tmp1;
void*tp=0;
if(tpopt!=0 && Cyc_Tcutil_is_pointer_type(tpopt))
tp=Cyc_Tcutil_pointer_elt_type(tpopt);{
# 712
void*res=({void*_Tmp3=a;unsigned _Tmp4=(unsigned)i;Cyc_AssnDef_aggr_update(_Tmp3,_Tmp4,({
void*_Tmp5=Cyc_AssnDef_proj(a,(unsigned)i,tp);struct Cyc_List_List*_Tmp6=fields->tl;Cyc_AssnDef_apply_aggr_update(_Tmp5,_Tmp6,v);}));});
return res;}}}}
# 717
static void*Cyc_AssnDef_proj_fields(void*v,struct Cyc_List_List*fs){
for(1;fs!=0;fs=fs->tl){
struct _tuple16*_Tmp0=(struct _tuple16*)fs->hd;void*_Tmp1;int _Tmp2;_Tmp2=_Tmp0->f0;_Tmp1=_Tmp0->f1;{int i=_Tmp2;void*tpopt=_Tmp1;
if(tpopt!=0 && Cyc_Tcutil_is_pointer_type(tpopt))
v=({void*_Tmp3=v;unsigned _Tmp4=(unsigned)i;Cyc_AssnDef_proj(_Tmp3,_Tmp4,Cyc_Tcutil_pointer_elt_type(tpopt));});else{
# 723
v=Cyc_AssnDef_proj(v,(unsigned)i,0);}}}
# 725
return v;}
# 730
static int Cyc_AssnDef_only_pointers(void*t){
void*_Tmp0=Cyc_Absyn_compress(t);void*_Tmp1;void*_Tmp2;struct Cyc_Absyn_ArrayInfo _Tmp3;switch(*((int*)_Tmp0)){case 4:
 return 1;case 5: _Tmp3=((struct Cyc_Absyn_ArrayType_Absyn_Type_struct*)_Tmp0)->f1;{struct Cyc_Absyn_ArrayInfo ai=_Tmp3;
return Cyc_AssnDef_only_pointers(ai.elt_type);}case 0: if(*((int*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)==24){if(((struct Cyc_Absyn_AggrCon_Absyn_TyCon_struct*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)->f1.KnownAggr.tag==2){_Tmp2=*((struct Cyc_Absyn_AggrCon_Absyn_TyCon_struct*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)->f1.KnownAggr.val;_Tmp1=((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f2;{struct Cyc_Absyn_Aggrdecl*ad=_Tmp2;struct Cyc_List_List*ts=_Tmp1;
# 735
if(ad->impl==0)return 0;{
struct Cyc_List_List*subst=Cyc_List_zip(ad->tvs,ts);
{struct Cyc_List_List*fs=_check_null(ad->impl)->fields;for(0;fs!=0;fs=fs->tl){
void*t=Cyc_Tcutil_substitute(subst,((struct Cyc_Absyn_Aggrfield*)fs->hd)->type);
if(!Cyc_AssnDef_only_pointers(t))return 0;}}
# 741
return 1;}}}else{goto _LL9;}}else{goto _LL9;}case 7: _Tmp2=((struct Cyc_Absyn_AnonAggrType_Absyn_Type_struct*)_Tmp0)->f3;{struct Cyc_List_List*fs=_Tmp2;
# 743
for(1;fs!=0;fs=fs->tl){
if(!Cyc_AssnDef_only_pointers(((struct Cyc_Absyn_Aggrfield*)fs->hd)->type))return 0;}
return 1;}default: _LL9:
 return 0;};}
# 751
static int Cyc_AssnDef_only_bits(void*t){
void*_Tmp0=Cyc_Absyn_compress(t);struct Cyc_Absyn_ArrayInfo _Tmp1;void*_Tmp2;void*_Tmp3;switch(*((int*)_Tmp0)){case 0: switch(*((int*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)){case 0:
 goto _LL4;case 1: _LL4:
 goto _LL6;case 2: _LL6:
 goto _LL8;case 19: _LL8:
 goto _LLA;case 20: _LLA:
 goto _LLC;case 5: _LLC:
 goto _LLE;case 3: _LLE:
 return 1;case 24: if(((struct Cyc_Absyn_AggrCon_Absyn_TyCon_struct*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)->f1.KnownAggr.tag==2){_Tmp3=*((struct Cyc_Absyn_AggrCon_Absyn_TyCon_struct*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)->f1.KnownAggr.val;_Tmp2=((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f2;{struct Cyc_Absyn_Aggrdecl*ad=_Tmp3;struct Cyc_List_List*ts=_Tmp2;
# 762
if(ad->impl==0)return 0;{
struct Cyc_List_List*subst=Cyc_List_zip(ad->tvs,ts);
{struct Cyc_List_List*fs=_check_null(ad->impl)->fields;for(0;fs!=0;fs=fs->tl){
void*t=Cyc_Tcutil_substitute(subst,((struct Cyc_Absyn_Aggrfield*)fs->hd)->type);
if(!Cyc_AssnDef_only_bits(t))return 0;}}
# 768
return 1;}}}else{goto _LL15;}default: goto _LL15;}case 5: _Tmp1=((struct Cyc_Absyn_ArrayType_Absyn_Type_struct*)_Tmp0)->f1;{struct Cyc_Absyn_ArrayInfo ai=_Tmp1;
# 760
return Cyc_AssnDef_only_bits(ai.elt_type);}case 7: _Tmp3=((struct Cyc_Absyn_AnonAggrType_Absyn_Type_struct*)_Tmp0)->f3;{struct Cyc_List_List*fs=_Tmp3;
# 770
for(1;fs!=0;fs=fs->tl){
if(!Cyc_AssnDef_only_bits(((struct Cyc_Absyn_Aggrfield*)fs->hd)->type))return 0;}
return 1;}default: _LL15:
 return 0;};}
# 777
void*Cyc_AssnDef_select(void*t1,void*t2,void*tp){
LOOP: {
void*_Tmp0;void*_Tmp1;void*_Tmp2;if(*((int*)t1)==7){_Tmp2=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t1)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t1)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t1)->f3;{void*m=_Tmp2;void*a1=_Tmp1;void*v=_Tmp0;
# 781
if(a1==t2)return v;
if(Cyc_AssnDef_address_disjoint(a1,t2)){
t1=m;
goto LOOP;}
# 793
if(tp!=0){
void*_Tmp3=tp;void*tp=_Tmp3;
if(Cyc_AssnDef_only_pointers(tp)){
void*vtopt=Cyc_AssnDef_get_term_type(v);
if(vtopt!=0){
void*vt=vtopt;
if(Cyc_AssnDef_only_bits(vt)){
t1=m;
goto LOOP;}}{
# 804
void*a1opt=Cyc_AssnDef_get_term_type(a1);
if(a1opt!=0 && Cyc_Tcutil_is_pointer_type(a1opt)){
void*vt=Cyc_Tcutil_pointer_elt_type(a1opt);
if(Cyc_AssnDef_only_bits(vt)){
t1=m;
goto LOOP;}}}}}
# 814
goto _LL0;}}else{
goto _LL0;}_LL0:;}{
# 817
struct _tuple12 _Tmp0=Cyc_AssnDef_split_addr(t2);void*_Tmp1;void*_Tmp2;_Tmp2=_Tmp0.f0;_Tmp1=_Tmp0.f1;{void*root=_Tmp2;struct Cyc_List_List*fields=_Tmp1;
if(fields!=0){
void*topt=Cyc_AssnDef_get_term_type(t1);
if(topt!=0 && Cyc_Tcutil_is_pointer_type(topt))
topt=Cyc_Tcutil_pointer_elt_type(topt);{
# 823
void*_Tmp3=Cyc_AssnDef_select(t1,root,topt);return Cyc_AssnDef_proj_fields(_Tmp3,fields);}}{
# 825
struct Cyc_AssnDef_Select_AssnDef_Term_struct t=({struct Cyc_AssnDef_Select_AssnDef_Term_struct _Tmp3;_Tmp3.tag=6,_Tmp3.f1=t1,_Tmp3.f2=t2,_Tmp3.f3=tp;_Tmp3;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}}}
# 836 "assndef.cyc"
void*Cyc_AssnDef_proj(void*t1,unsigned i,void*tp){
LOOP: {
void*_Tmp0;void*_Tmp1;unsigned _Tmp2;int _Tmp3;switch(*((int*)t1)){case 8: _Tmp3=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f1;_Tmp2=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f2;_Tmp1=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f3;{int is_union=_Tmp3;unsigned tag=_Tmp2;struct Cyc_List_List*ts=_Tmp1;
# 840
int n=Cyc_List_length(ts);
if(!is_union && i < (unsigned)n)
return Cyc_List_nth(ts,(int)i);else{
if(tag==i && n >= 1)
return(void*)_check_null(ts)->hd;else{
goto _LL0;}}}case 10: _Tmp1=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f1;_Tmp2=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f3;{void*t=_Tmp1;unsigned j=_Tmp2;void*t2=_Tmp0;
# 847
if(i==j)return t2;{
# 850
void*topt=Cyc_AssnDef_get_term_type(t1);
if(topt==0)goto NOREDUCE;
{void*_Tmp4=Cyc_Absyn_compress(topt);union Cyc_Absyn_AggrInfo _Tmp5;switch(*((int*)_Tmp4)){case 0: if(*((int*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp4)->f1)==24){_Tmp5=((struct Cyc_Absyn_AggrCon_Absyn_TyCon_struct*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp4)->f1)->f1;{union Cyc_Absyn_AggrInfo ai=_Tmp5;
# 854
{void*_Tmp6;if(ai.KnownAggr.tag==2){_Tmp6=*ai.KnownAggr.val;{struct Cyc_Absyn_Aggrdecl*ad=_Tmp6;
# 856
if((int)ad->kind==1)goto NOREDUCE;goto _LLE;}}else{if(ai.UnknownAggr.val.f0==Cyc_Absyn_UnionA)
goto NOREDUCE;else{
goto _LLE;}}_LLE:;}
# 860
goto _LL7;}}else{goto _LLC;}case 7: if(((struct Cyc_Absyn_AnonAggrType_Absyn_Type_struct*)_Tmp4)->f1==Cyc_Absyn_UnionA)
goto NOREDUCE;else{goto _LLC;}default: _LLC:
 goto _LL7;}_LL7:;}
# 864
t1=t;
goto LOOP;}}default:
# 867
 goto _LL0;}_LL0:;}
# 869
NOREDUCE: {
struct Cyc_AssnDef_Proj_AssnDef_Term_struct t=({struct Cyc_AssnDef_Proj_AssnDef_Term_struct _Tmp0;_Tmp0.tag=9,_Tmp0.f1=t1,_Tmp0.f2=i,_Tmp0.f3=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}
# 874
void*Cyc_AssnDef_aggr(int is_union,unsigned tag,struct Cyc_List_List*ts,void*tp){
# 877
struct Cyc_AssnDef_Aggr_AssnDef_Term_struct t=({struct Cyc_AssnDef_Aggr_AssnDef_Term_struct _Tmp0;_Tmp0.tag=8,_Tmp0.f1=is_union,_Tmp0.f2=tag,_Tmp0.f3=ts,_Tmp0.f4=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}
# 880
void*Cyc_AssnDef_struct_aggr(struct Cyc_List_List*ts,void*tp){
return Cyc_AssnDef_aggr(0,-1,ts,tp);}
# 883
void*Cyc_AssnDef_datatype_aggr(unsigned tag,struct Cyc_List_List*ts,void*tp){
return Cyc_AssnDef_aggr(0,tag,ts,tp);}
# 886
void*Cyc_AssnDef_union_aggr(unsigned tag,struct Cyc_List_List*ts,void*tp){
return Cyc_AssnDef_aggr(1,tag,ts,tp);}
# 889
void*Cyc_AssnDef_tagof_tm(void*t1){
{void*_Tmp0;unsigned _Tmp1;switch(*((int*)t1)){case 8: _Tmp1=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t1)->f2;{unsigned tag=_Tmp1;
return Cyc_AssnDef_uint(tag);}case 10: _Tmp0=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f1;_Tmp1=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t1)->f2;{void*t=_Tmp0;unsigned j=_Tmp1;
# 894
void*topt=Cyc_AssnDef_get_term_type(t1);
if(topt==0)goto _LL0;
{void*_Tmp2=Cyc_Absyn_compress(topt);union Cyc_Absyn_AggrInfo _Tmp3;switch(*((int*)_Tmp2)){case 0: if(*((int*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp2)->f1)==24){_Tmp3=((struct Cyc_Absyn_AggrCon_Absyn_TyCon_struct*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp2)->f1)->f1;{union Cyc_Absyn_AggrInfo ai=_Tmp3;
# 898
{void*_Tmp4;if(ai.KnownAggr.tag==2){_Tmp4=*ai.KnownAggr.val;{struct Cyc_Absyn_Aggrdecl*ad=_Tmp4;
# 900
if((int)ad->kind==1)return Cyc_AssnDef_uint(j);
goto _LLE;}}else{if(ai.UnknownAggr.val.f0==Cyc_Absyn_UnionA)
return Cyc_AssnDef_uint(j);else{
goto _LLE;}}_LLE:;}
# 905
goto _LL7;}}else{goto _LLC;}case 7: if(((struct Cyc_Absyn_AnonAggrType_Absyn_Type_struct*)_Tmp2)->f1==Cyc_Absyn_UnionA)
return Cyc_AssnDef_uint(j);else{goto _LLC;}default: _LLC:
 goto _LL7;}_LL7:;}
# 909
goto _LL0;}default:
 goto _LL0;}_LL0:;}{
# 912
struct Cyc_AssnDef_Tagof_AssnDef_Term_struct t=({struct Cyc_AssnDef_Tagof_AssnDef_Term_struct _Tmp0;_Tmp0.tag=15,_Tmp0.f1=t1;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}
# 916
void*Cyc_AssnDef_cast(void*tp,void*tm){
struct Cyc_AssnDef_Cast_AssnDef_Term_struct t=({struct Cyc_AssnDef_Cast_AssnDef_Term_struct _Tmp0;_Tmp0.tag=5,_Tmp0.f1=tp,_Tmp0.f2=tm;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}
# 921
void*Cyc_AssnDef_raw_alloc(struct Cyc_Absyn_Exp*e,int id,void*nelts,void*invok,void*tp){
struct Cyc_AssnDef_Alloc_AssnDef_Term_struct t=({struct Cyc_AssnDef_Alloc_AssnDef_Term_struct _Tmp0;_Tmp0.tag=12,_Tmp0.f1=e,_Tmp0.f2=id,_Tmp0.f3=nelts,_Tmp0.f4=invok,_Tmp0.f5=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}
# 926
void*Cyc_AssnDef_alloc(struct Cyc_Absyn_Exp*e,void*nelts,void*invok,void*tp){
static int counter=0;
return Cyc_AssnDef_raw_alloc(e,counter ++,nelts,invok,tp);}
# 931
void*Cyc_AssnDef_offsetf(void*tm,unsigned i,void*tp){
struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct t=({struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct _Tmp0;_Tmp0.tag=13,_Tmp0.f1=tm,_Tmp0.f2=i,_Tmp0.f3=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}
# 936
void*Cyc_AssnDef_offseti(void*tm,void*i,void*tp){
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=tm,_Tmp1.f1=i;_Tmp1;});void*_Tmp1;void*_Tmp2;void*_Tmp3;if(*((int*)_Tmp0.f1)==0){if(((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1==0)
return tm;else{if(*((int*)_Tmp0.f0)==14)goto _LL3;else{goto _LL5;}}}else{if(*((int*)_Tmp0.f0)==14){_LL3: _Tmp3=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp2=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f3;{void*t=_Tmp3;void*j=_Tmp2;void*tp2=_Tmp1;
# 940
if((tp!=0 && tp2!=0)&& Cyc_Unify_unify(tp,tp2)){
void*_Tmp4=t;void*_Tmp5=Cyc_AssnDef_plus(i,j,Cyc_Absyn_sint_type);return Cyc_AssnDef_offseti(_Tmp4,_Tmp5,tp);}
goto _LL6;}}else{_LL5: _LL6: {
# 944
struct Cyc_AssnDef_Offseti_AssnDef_Term_struct t=({struct Cyc_AssnDef_Offseti_AssnDef_Term_struct _Tmp4;_Tmp4.tag=14,_Tmp4.f1=tm,_Tmp4.f2=i,_Tmp4.f3=tp;_Tmp4;});
return Cyc_AssnDef_hash_cons_term((void*)& t);}}};}
# 948
void*Cyc_AssnDef_fresh_var(struct Cyc_Absyn_Vardecl*vd,void*tp){
static int counter=0;
void*t=Cyc_AssnDef_logicvar(vd,counter,tp);
++ counter;
return t;}
# 955
void*Cyc_AssnDef_plus(void*t1,void*t2,void*tp){
return Cyc_AssnDef_binop(0U,t1,t2,tp);}
# 958
void*Cyc_AssnDef_minus(void*t1,void*t2,void*tp){
return Cyc_AssnDef_binop(2U,t1,t2,tp);}
# 962
void*Cyc_AssnDef_unop(enum Cyc_Absyn_Primop p,void*t,void*tp){
# 964
if((int)p==0)return t;
# 966
if((int)p==2){void*_Tmp0=t;void*_Tmp1=Cyc_AssnDef_uint(-1);return Cyc_AssnDef_binop(1U,_Tmp0,_Tmp1,tp);}{
struct Cyc_AssnDef_Unop_AssnDef_Term_struct ptr=({struct Cyc_AssnDef_Unop_AssnDef_Term_struct _Tmp0;_Tmp0.tag=3,_Tmp0.f1=p,_Tmp0.f2=t,_Tmp0.f3=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& ptr);}}
# 971
void*Cyc_AssnDef_numelts_term(void*t){
return Cyc_AssnDef_unop(18U,t,Cyc_Absyn_uint_type);}static char _TmpG3[5U]="#Mem";
# 977
static struct _fat_ptr Cyc_AssnDef_memory_var={_TmpG3,_TmpG3,_TmpG3 + 5U};static char _TmpG4[9U]="#Pre_Mem";
static struct _fat_ptr Cyc_AssnDef_pre_memory_var={_TmpG4,_TmpG4,_TmpG4 + 9U};
static struct _tuple0 Cyc_AssnDef_memvar={.f0={.Loc_n={4,0}},.f1=& Cyc_AssnDef_memory_var};
static struct _tuple0 Cyc_AssnDef_pre_memvar={.f0={.Loc_n={4,0}},.f1=& Cyc_AssnDef_pre_memory_var};
static struct Cyc_Absyn_VoidCon_Absyn_TyCon_struct Cyc_AssnDef_void_con={0};
static struct Cyc_Absyn_AppType_Absyn_Type_struct Cyc_AssnDef_vd_type={0,(void*)& Cyc_AssnDef_void_con,0};
# 984
struct Cyc_Absyn_Vardecl Cyc_AssnDef_memory_struct={Cyc_Absyn_Public,& Cyc_AssnDef_memvar,0U,{0,0,0,0,0U},(void*)& Cyc_AssnDef_vd_type,0,0,0,0,0,0};
# 997
struct Cyc_Absyn_Vardecl*Cyc_AssnDef_memory=& Cyc_AssnDef_memory_struct;
struct Cyc_Absyn_Vardecl Cyc_AssnDef_pre_memory_struct={Cyc_Absyn_Public,& Cyc_AssnDef_pre_memvar,0U,{0,0,0,0,0U},(void*)& Cyc_AssnDef_vd_type,0,0,0,0,0,0};
# 1011
struct Cyc_Absyn_Vardecl*Cyc_AssnDef_pre_memory=& Cyc_AssnDef_pre_memory_struct;static char _TmpG5[5U]="#Exn";
# 1013
static struct _fat_ptr Cyc_AssnDef_exception_var={_TmpG5,_TmpG5,_TmpG5 + 5U};
static struct _tuple0 Cyc_AssnDef_exnvar={.f0={.Loc_n={4,0}},.f1=& Cyc_AssnDef_exception_var};
# 1016
struct Cyc_Absyn_Vardecl Cyc_AssnDef_exception_struct={Cyc_Absyn_Public,& Cyc_AssnDef_exnvar,0U,{0,0,0,0,0U},(void*)& Cyc_AssnDef_vd_type,0,0,0,0,0,0};
# 1030
struct Cyc_Absyn_Vardecl*Cyc_AssnDef_exception_vardecl (void){
struct Cyc_Absyn_Vardecl*vd=& Cyc_AssnDef_exception_struct;
({void*_Tmp0=Cyc_Absyn_exn_type();vd->type=_Tmp0;});
return vd;}struct _tuple17{struct Cyc_List_List*f0;int f1;};
# 1047
struct _tuple17 Cyc_AssnDef_get_coefficient_term_list(void*t){
struct Cyc_List_List*coefficient_term_list=0;
int res=0;
LOOP: {
void*_Tmp0;void*_Tmp1;unsigned _Tmp2;switch(*((int*)t)){case 0: _Tmp2=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)t)->f1;{unsigned i=_Tmp2;
res=(int)i;goto _LL0;}case 4: if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1==Cyc_Absyn_Plus){if(*((int*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3)==0){_Tmp1=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp2=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3)->f1;{void*t1=_Tmp1;unsigned i=_Tmp2;
# 1054
res=(int)i;
t=t1;
goto LOOP;}}else{_Tmp1=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp1;void*t2=_Tmp0;
# 1058
{unsigned _Tmp3;void*_Tmp4;if(*((int*)t2)==4)switch((int)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t2)->f1){case Cyc_Absyn_Times: if(*((int*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t2)->f3)==0){_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t2)->f2;_Tmp3=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t2)->f3)->f1;{void*t21=_Tmp4;unsigned c2=_Tmp3;
# 1060
coefficient_term_list=({struct Cyc_List_List*_Tmp5=_cycalloc(sizeof(struct Cyc_List_List));({struct _tuple16*_Tmp6=({struct _tuple16*_Tmp7=_cycalloc(sizeof(struct _tuple16));_Tmp7->f0=(int)c2,_Tmp7->f1=t21;_Tmp7;});_Tmp5->hd=_Tmp6;}),_Tmp5->tl=coefficient_term_list;_Tmp5;});
goto _LL9;}}else{goto _LLE;}case Cyc_Absyn_Plus:
# 1063
({int(*_Tmp5)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp5;})(_tag_fat("Plus in the right branch, not a normal form",sizeof(char),44U),_tag_fat(0U,sizeof(void*),0));
goto _LL9;default: goto _LLE;}else{_LLE:
# 1066
 coefficient_term_list=({struct Cyc_List_List*_Tmp5=_cycalloc(sizeof(struct Cyc_List_List));({struct _tuple16*_Tmp6=({struct _tuple16*_Tmp7=_cycalloc(sizeof(struct _tuple16));_Tmp7->f0=1,_Tmp7->f1=t2;_Tmp7;});_Tmp5->hd=_Tmp6;}),_Tmp5->tl=coefficient_term_list;_Tmp5;});
goto _LL9;}_LL9:;}
# 1069
t=t1;
goto LOOP;}}}else{goto _LL7;}default: _LL7:
# 1072
{unsigned _Tmp3;void*_Tmp4;if(*((int*)t)==4){if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1==Cyc_Absyn_Times){if(*((int*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3)==0){_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp3=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3)->f1;{void*t21=_Tmp4;unsigned c2=_Tmp3;
# 1074
coefficient_term_list=({struct Cyc_List_List*_Tmp5=_cycalloc(sizeof(struct Cyc_List_List));({struct _tuple16*_Tmp6=({struct _tuple16*_Tmp7=_cycalloc(sizeof(struct _tuple16));_Tmp7->f0=(int)c2,_Tmp7->f1=t21;_Tmp7;});_Tmp5->hd=_Tmp6;}),_Tmp5->tl=coefficient_term_list;_Tmp5;});
goto _LL10;}}else{goto _LL13;}}else{goto _LL13;}}else{_LL13:
# 1077
 coefficient_term_list=({struct Cyc_List_List*_Tmp5=_cycalloc(sizeof(struct Cyc_List_List));({struct _tuple16*_Tmp6=({struct _tuple16*_Tmp7=_cycalloc(sizeof(struct _tuple16));_Tmp7->f0=1,_Tmp7->f1=t;_Tmp7;});_Tmp5->hd=_Tmp6;}),_Tmp5->tl=coefficient_term_list;_Tmp5;});
goto _LL10;}_LL10:;}
# 1080
goto _LL0;}_LL0:;}{
# 1082
struct _tuple17 _Tmp0;_Tmp0.f0=coefficient_term_list,_Tmp0.f1=res;return _Tmp0;}}
# 1092 "assndef.cyc"
static struct Cyc_List_List*Cyc_AssnDef_imp_merge_coefficient_term_list(int(*less_eq)(void*,void*),struct Cyc_List_List*termlist1,struct Cyc_List_List*termlist2){
# 1096
struct Cyc_List_List*res_tail=0;
struct Cyc_List_List*res=0;
if(termlist1==0)return termlist2;
if(termlist2==0)return termlist1;{
int cmp_result=less_eq(((struct _tuple16*)termlist1->hd)->f1,((struct _tuple16*)termlist2->hd)->f1);
while(termlist1!=0 && termlist2!=0){
{int cmp_result=less_eq(((struct _tuple16*)termlist1->hd)->f1,((struct _tuple16*)termlist2->hd)->f1);
if(cmp_result < 0){
if(res_tail==0){
res_tail=termlist1;
termlist1=termlist1->tl;
res=res_tail;}else{
# 1109
res_tail->tl=termlist1;
res_tail=termlist1;
termlist1=termlist1->tl;}}else{
# 1113
if(cmp_result > 0){
if(res_tail==0){
res_tail=termlist2;
termlist2=termlist2->tl;
res=res_tail;}else{
# 1119
res_tail->tl=termlist2;
res_tail=termlist2;
termlist2=termlist2->tl;}}else{
# 1125
int i=((struct _tuple16*)termlist1->hd)->f0 + ((struct _tuple16*)termlist2->hd)->f0;
if(i!=0){
((struct _tuple16*)termlist1->hd)->f0=i;
if(res_tail==0){
res_tail=termlist1;
res=res_tail;}else{
# 1132
res_tail->tl=termlist1;
res_tail=termlist1;}}
# 1136
termlist1=termlist1->tl;
termlist2=termlist2->tl;}}}
# 1102
1U;}
# 1140
if(res_tail==0){
res_tail=termlist1==0?termlist2: termlist1;
res=res_tail;}else{
# 1144
res_tail->tl=termlist1==0?termlist2: termlist1;}
# 1146
return res;}}
# 1152
inline static unsigned Cyc_AssnDef_id_of_primop(enum Cyc_Absyn_Primop p){
switch((int)p){case Cyc_Absyn_Plus:
 return 0U;case Cyc_Absyn_Times:
 return 1U;case Cyc_Absyn_Bitand:
 return 4294967295U;case Cyc_Absyn_Bitor:
 return 0U;case Cyc_Absyn_Bitxor:
 return 0U;default:
({struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,({struct _fat_ptr _Tmp2=Cyc_Absynpp_prim2string(p);_Tmp1.f1=_Tmp2;});_Tmp1;});void*_Tmp1[1];_Tmp1[0]=& _Tmp0;({int(*_Tmp2)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp2;})(_tag_fat("no id for primop %s",sizeof(char),20U),_tag_fat(_Tmp1,sizeof(void*),1));});};}
# 1166
static void*Cyc_AssnDef_termlist2term(struct Cyc_List_List*termlist,int newc,enum Cyc_Absyn_Primop p,void*tp){
unsigned id=Cyc_AssnDef_id_of_primop(p);
if(termlist==0)return Cyc_AssnDef_uint((unsigned)newc);{
void*t=(void*)termlist->hd;
termlist=termlist->tl;
while(termlist!=0){
{struct Cyc_AssnDef_Binop_AssnDef_Term_struct newterm=({struct Cyc_AssnDef_Binop_AssnDef_Term_struct _Tmp0;_Tmp0.tag=4,_Tmp0.f1=p,_Tmp0.f2=t,_Tmp0.f3=(void*)termlist->hd,_Tmp0.f4=tp;_Tmp0;});
t=Cyc_AssnDef_hash_cons_term((void*)& newterm);
termlist=termlist->tl;}
# 1172
1U;}
# 1176
if(id==(unsigned)newc)return t;else{
# 1190 "assndef.cyc"
struct Cyc_AssnDef_Binop_AssnDef_Term_struct newterm=({struct Cyc_AssnDef_Binop_AssnDef_Term_struct _Tmp0;_Tmp0.tag=4,_Tmp0.f1=p,_Tmp0.f2=t,({void*_Tmp1=Cyc_AssnDef_uint((unsigned)newc);_Tmp0.f3=_Tmp1;}),_Tmp0.f4=tp;_Tmp0;});
return Cyc_AssnDef_hash_cons_term((void*)& newterm);}}}
# 1197
static void*Cyc_AssnDef_compute_factor(void*tp,struct _tuple16*coefficient_term){
void*_Tmp0;int _Tmp1;_Tmp1=coefficient_term->f0;_Tmp0=coefficient_term->f1;{int c=_Tmp1;void*t=_Tmp0;
if(c==1)return t;else{
# 1201
struct Cyc_AssnDef_Binop_AssnDef_Term_struct newfactor=({struct Cyc_AssnDef_Binop_AssnDef_Term_struct _Tmp2;_Tmp2.tag=4,_Tmp2.f1=1U,_Tmp2.f2=t,({void*_Tmp3=Cyc_AssnDef_uint((unsigned)c);_Tmp2.f3=_Tmp3;}),_Tmp2.f4=tp;_Tmp2;});
return Cyc_AssnDef_hash_cons_term((void*)& newfactor);}}}
# 1206
static int Cyc_AssnDef_inv_termcmp(void*t1,void*t2){
return - Cyc_AssnDef_termcmp(t1,t2);}
# 1217 "assndef.cyc"
static void*Cyc_AssnDef_normalize_plus(void*t1,void*t2,void*tp){
struct _tuple17 _Tmp0=Cyc_AssnDef_get_coefficient_term_list(t1);int _Tmp1;void*_Tmp2;_Tmp2=_Tmp0.f0;_Tmp1=_Tmp0.f1;{struct Cyc_List_List*coefficient_term_list1=_Tmp2;int i1=_Tmp1;
struct _tuple17 _Tmp3=Cyc_AssnDef_get_coefficient_term_list(t2);int _Tmp4;void*_Tmp5;_Tmp5=_Tmp3.f0;_Tmp4=_Tmp3.f1;{struct Cyc_List_List*coefficient_term_list2=_Tmp5;int i2=_Tmp4;
struct Cyc_List_List*coefficient_term_list=
Cyc_AssnDef_imp_merge_coefficient_term_list(Cyc_AssnDef_inv_termcmp,coefficient_term_list1,coefficient_term_list2);
# 1225
struct Cyc_List_List*term_list=({struct Cyc_List_List*(*_Tmp6)(void*(*)(void*,struct _tuple16*),void*,struct Cyc_List_List*)=(struct Cyc_List_List*(*)(void*(*)(void*,struct _tuple16*),void*,struct Cyc_List_List*))Cyc_List_map_c;_Tmp6;})(Cyc_AssnDef_compute_factor,tp,coefficient_term_list);
void*res=Cyc_AssnDef_termlist2term(term_list,i1 + i2,0U,tp);
return res;}}}
# 1235
static struct _tuple17 Cyc_AssnDef_term2termlist(enum Cyc_Absyn_Primop p,void*t){
struct Cyc_List_List*termlist=0;
int res=(int)Cyc_AssnDef_id_of_primop(p);
LOOP: {
void*_Tmp0;void*_Tmp1;enum Cyc_Absyn_Primop _Tmp2;unsigned _Tmp3;switch(*((int*)t)){case 0: _Tmp3=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)t)->f1;{unsigned i=_Tmp3;
res=(int)i;goto _LL0;}case 4: if(*((int*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3)==0){_Tmp2=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp3=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3)->f1;if((int)((enum Cyc_Absyn_Primop)_Tmp2)==(int)p){enum Cyc_Absyn_Primop p1=_Tmp2;void*t1=_Tmp1;unsigned i=_Tmp3;
# 1242
res=(int)i;
t=t1;
goto LOOP;}else{goto _LL5;}}else{_LL5: _Tmp2=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;if((int)((enum Cyc_Absyn_Primop)_Tmp2)==(int)p){enum Cyc_Absyn_Primop p1=_Tmp2;void*t1=_Tmp1;void*t2=_Tmp0;
# 1246
termlist=({struct Cyc_List_List*_Tmp4=_cycalloc(sizeof(struct Cyc_List_List));_Tmp4->hd=t2,_Tmp4->tl=termlist;_Tmp4;});
t=t1;
goto LOOP;}else{goto _LL7;}}default: _LL7:
# 1250
 termlist=({struct Cyc_List_List*_Tmp4=_cycalloc(sizeof(struct Cyc_List_List));_Tmp4->hd=t,_Tmp4->tl=termlist;_Tmp4;});
goto _LL0;}_LL0:;}{
# 1253
struct _tuple17 _Tmp0;_Tmp0.f0=termlist,_Tmp0.f1=res;return _Tmp0;}}
# 1257
inline static unsigned Cyc_AssnDef_eval_binop(enum Cyc_Absyn_Primop p,unsigned i,unsigned j){
switch((int)p){case Cyc_Absyn_Plus:
 return i + j;case Cyc_Absyn_Times:
 return i * j;case Cyc_Absyn_Bitand:
 return i & j;case Cyc_Absyn_Bitor:
 return i | j;case Cyc_Absyn_Bitxor:
 return i ^ j;default:
({int(*_Tmp0)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp0;})(_tag_fat("Error in evaluating binop",sizeof(char),26U),_tag_fat(0U,sizeof(void*),0));};}
# 1269
static void*Cyc_AssnDef_normalize_assoc_commu(enum Cyc_Absyn_Primop p,void*t1,void*t2,void*tp){
struct _tuple17 _Tmp0=Cyc_AssnDef_term2termlist(p,t1);int _Tmp1;void*_Tmp2;_Tmp2=_Tmp0.f0;_Tmp1=_Tmp0.f1;{struct Cyc_List_List*term_list1=_Tmp2;int c1=_Tmp1;
struct _tuple17 _Tmp3=Cyc_AssnDef_term2termlist(p,t2);int _Tmp4;void*_Tmp5;_Tmp5=_Tmp3.f0;_Tmp4=_Tmp3.f1;{struct Cyc_List_List*term_list2=_Tmp5;int c2=_Tmp4;
struct Cyc_List_List*term_list=Cyc_List_imp_merge(Cyc_AssnDef_inv_termcmp,term_list1,term_list2);
unsigned c=Cyc_AssnDef_eval_binop(p,(unsigned)c1,(unsigned)c2);
return Cyc_AssnDef_termlist2term(term_list,(int)c,p,tp);}}}
# 1277
inline static int Cyc_AssnDef_is_nonassociative_commutative(enum Cyc_Absyn_Primop p,void*tp){
switch((int)p){case Cyc_Absyn_Plus:
 goto _LL4;case Cyc_Absyn_Times: _LL4:
# 1281
 if(tp!=0){
void*_Tmp0=Cyc_Absyn_compress(tp);if(*((int*)_Tmp0)==0){if(*((int*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)==2)
return 1;else{goto _LLE;}}else{_LLE:
 return 0;};}
# 1287
return 0;case Cyc_Absyn_Eq:
 goto _LL8;case Cyc_Absyn_Neq: _LL8:
 return 1;default:
 return 0;};}
# 1294
inline static int Cyc_AssnDef_is_associative_commutative(enum Cyc_Absyn_Primop p,void*tp){
switch((int)p){case Cyc_Absyn_Plus:
 goto _LL4;case Cyc_Absyn_Times: _LL4:
# 1298
 if(tp!=0){
void*_Tmp0=Cyc_Absyn_compress(tp);if(*((int*)_Tmp0)==0){if(*((int*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)_Tmp0)->f1)==1)
# 1301
return 1;else{goto _LL10;}}else{_LL10:
 return 0;};}
# 1305
return 0;case Cyc_Absyn_Bitand:
 goto _LL8;case Cyc_Absyn_Bitor: _LL8:
 goto _LLA;case Cyc_Absyn_Bitxor: _LLA:
 return 1;default:
 return 0;};}struct _tuple18{enum Cyc_Absyn_Primop f0;void*f1;void*f2;};
# 1314
void*Cyc_AssnDef_binop(enum Cyc_Absyn_Primop p,void*t1,void*t2,void*tp){
{struct _tuple18 _Tmp0=({struct _tuple18 _Tmp1;_Tmp1.f0=p,_Tmp1.f1=t1,_Tmp1.f2=t2;_Tmp1;});void*_Tmp1;void*_Tmp2;unsigned _Tmp3;unsigned _Tmp4;if(*((int*)_Tmp0.f1)==0){if(*((int*)_Tmp0.f2)==0){_Tmp4=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp3=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f2)->f1;{unsigned i=_Tmp4;unsigned j=_Tmp3;
# 1318
switch((int)p){case Cyc_Absyn_Plus:
 return Cyc_AssnDef_uint(i + j);case Cyc_Absyn_Minus:
 return Cyc_AssnDef_uint(i - j);case Cyc_Absyn_Bitand:
 return Cyc_AssnDef_uint(i & j);case Cyc_Absyn_Bitor:
 return Cyc_AssnDef_uint(i | j);case Cyc_Absyn_Bitxor:
 return Cyc_AssnDef_uint(i ^ j);case Cyc_Absyn_Bitlshift:
 return Cyc_AssnDef_uint(i << j);case Cyc_Absyn_Bitlrshift:
 return Cyc_AssnDef_uint(i >> j);case Cyc_Absyn_Div:
 if(j!=0U)return Cyc_AssnDef_uint((unsigned)((int)i / (int)j));goto _LL7;case Cyc_Absyn_UDiv:
 if(j!=0U)return Cyc_AssnDef_uint(i / j);goto _LL7;case Cyc_Absyn_Mod:
 if(j!=0U)return Cyc_AssnDef_uint((unsigned)((int)i % (int)j));goto _LL7;case Cyc_Absyn_UMod:
 if(j!=0U)return Cyc_AssnDef_uint(i % j);goto _LL7;case Cyc_Absyn_Times:
 return Cyc_AssnDef_uint(i * j);default:
 goto _LL7;}_LL7:;
# 1333
goto _LL0;}}else{if(_Tmp0.f0==Cyc_Absyn_Minus)goto _LL3;else{goto _LL5;}}}else{if(_Tmp0.f0==Cyc_Absyn_Minus){_LL3: _Tmp2=_Tmp0.f1;_Tmp1=_Tmp0.f2;{void*t1=_Tmp2;void*t2=_Tmp1;
# 1335
if(tp!=0){if(*((int*)tp)==0){if(*((int*)((struct Cyc_Absyn_AppType_Absyn_Type_struct*)tp)->f1)==1){
# 1338
if(Cyc_AssnDef_termcmp(t1,t2)==0)return Cyc_AssnDef_uint(0U);
# 1340
t2=({void*_Tmp5=t2;void*_Tmp6=Cyc_AssnDef_uint(-1);Cyc_AssnDef_binop(1U,_Tmp5,_Tmp6,tp);});
return Cyc_AssnDef_binop(0U,t1,t2,tp);}else{goto _LL25;}}else{goto _LL25;}}else{_LL25:
 goto _LL22;}_LL22:;
# 1344
goto _LL0;}}else{_LL5:
# 1349
 if(Cyc_AssnDef_is_associative_commutative(p,tp)){
# 1354
if((int)p==0)return Cyc_AssnDef_normalize_plus(t1,t2,tp);else{
return Cyc_AssnDef_normalize_assoc_commu(p,t1,t2,tp);}}
# 1357
if(Cyc_AssnDef_is_nonassociative_commutative(p,tp)){
if(Cyc_AssnDef_termcmp(t1,t2)> 0){
void*tmpt=t1;
t1=t2;
t2=tmpt;}}else{
# 1363
if((int)p==0){
struct _tuple15 _Tmp5=({struct _tuple15 _Tmp6;_Tmp6.f0=t1,_Tmp6.f1=t2;_Tmp6;});unsigned _Tmp6;void*_Tmp7;unsigned _Tmp8;void*_Tmp9;if(*((int*)_Tmp5.f0)==4){if(((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp5.f0)->f1==Cyc_Absyn_Plus){if(*((int*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp5.f0)->f3)==0){if(*((int*)_Tmp5.f1)==0){_Tmp9=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp5.f0)->f2;_Tmp8=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp5.f0)->f3)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp5.f0)->f4;_Tmp6=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp5.f1)->f1;{void*t1=_Tmp9;unsigned i=_Tmp8;void*tp2=_Tmp7;unsigned j=_Tmp6;
# 1366
if((tp!=0 && tp2!=0)&& Cyc_Unify_unify(tp,tp2)){
void*_TmpA=t1;void*_TmpB=Cyc_AssnDef_uint(i + j);return Cyc_AssnDef_plus(_TmpA,_TmpB,tp);}
goto _LL27;}}else{goto _LL2A;}}else{goto _LL2A;}}else{goto _LL2A;}}else{_LL2A:
 goto _LL27;}_LL27:;}}
# 1372
goto _LL0;}}_LL0:;}{
# 1374
struct Cyc_AssnDef_Binop_AssnDef_Term_struct _Tmp0=({struct Cyc_AssnDef_Binop_AssnDef_Term_struct _Tmp1;_Tmp1.tag=4,_Tmp1.f1=p,_Tmp1.f2=t1,_Tmp1.f3=t2,_Tmp1.f4=tp;_Tmp1;});struct Cyc_AssnDef_Binop_AssnDef_Term_struct p=_Tmp0;
return Cyc_AssnDef_hash_cons_term((void*)& p);}}
# 1378
void*Cyc_AssnDef_get_term_type(void*t){
LOOP: {
void*_Tmp0;unsigned _Tmp1;void*_Tmp2;switch(*((int*)t)){case 0: _Tmp2=(void*)((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)t)->f2;{void*tp=_Tmp2;
return tp;}case 1: _Tmp2=((struct Cyc_AssnDef_Const_AssnDef_Term_struct*)t)->f1;{struct Cyc_Absyn_Exp*e=_Tmp2;
return e->topt;}case 2: _Tmp2=(void*)((struct Cyc_AssnDef_LogicVar_AssnDef_Term_struct*)t)->f3;{void*topt=_Tmp2;
return topt;}case 4: _Tmp2=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f4;{void*tp=_Tmp2;
return tp;}case 3: _Tmp2=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f3;{void*tp=_Tmp2;
return tp;}case 5: _Tmp2=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f1;{void*tp=_Tmp2;
return tp;}case 6: _Tmp2=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f3;{void*tp=_Tmp2;
return tp;}case 8: _Tmp2=(void*)((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f4;{void*tp=_Tmp2;
return tp;}case 9: _Tmp2=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f1;_Tmp1=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp2;unsigned i=_Tmp1;void*tp=_Tmp0;
return tp;}case 10: _Tmp2=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f1;{void*t1=_Tmp2;
t=t1;goto LOOP;}case 11: _Tmp2=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f3;{struct Cyc_Absyn_Vardecl*vd=_Tmp2;void*tp=_Tmp0;
return tp;}case 7:
 return 0;case 12: _Tmp2=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f5;{void*tp=_Tmp2;
return tp;}case 13: _Tmp2=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f3;{void*tp=_Tmp2;
return tp;}case 14: _Tmp2=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f3;{void*tp=_Tmp2;
return tp;}default:
 return Cyc_Absyn_uint_type;};}}
# 1400
static void*Cyc_AssnDef_subst_term(struct Cyc_Dict_Dict dict,void*t,struct Cyc_Hashtable_Table*term_h){
# 1402
void**t1=Cyc_Hashtable_lookup_opt(term_h,t);
if(t1!=0)
# 1408
return*t1;{
# 1410
void*res;
{unsigned _Tmp0;enum Cyc_Absyn_Primop _Tmp1;void*_Tmp2;int _Tmp3;void*_Tmp4;void*_Tmp5;void*_Tmp6;switch(*((int*)t)){case 0:
 goto _LL4;case 1: _LL4:
# 1414
 res=t;goto _LL0;case 11: _Tmp6=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f3;{struct Cyc_Absyn_Vardecl*vd=_Tmp6;void*t1=_Tmp5;void*tp=_Tmp4;
# 1416
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
struct Cyc_AssnDef_Addr_AssnDef_Term_struct addr_term=({struct Cyc_AssnDef_Addr_AssnDef_Term_struct _Tmp7;_Tmp7.tag=11,_Tmp7.f1=vd,_Tmp7.f2=s1,_Tmp7.f3=tp;_Tmp7;});
res=Cyc_AssnDef_hash_cons_term((void*)& addr_term);
goto _LL0;}case 12: _Tmp6=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f1;_Tmp3=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f3;_Tmp4=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f4;_Tmp2=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f5;{struct Cyc_Absyn_Exp*e1=_Tmp6;int i=_Tmp3;void*t1=_Tmp5;void*t2=_Tmp4;void*tp=_Tmp2;
# 1421
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
void*s2=Cyc_AssnDef_subst_term(dict,t2,term_h);
struct Cyc_AssnDef_Alloc_AssnDef_Term_struct alloc_term=({struct Cyc_AssnDef_Alloc_AssnDef_Term_struct _Tmp7;_Tmp7.tag=12,_Tmp7.f1=e1,_Tmp7.f2=i,_Tmp7.f3=s1,_Tmp7.f4=s2,_Tmp7.f5=tp;_Tmp7;});
res=Cyc_AssnDef_hash_cons_term((void*)& alloc_term);
goto _LL0;}case 6: _Tmp6=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;void*t2=_Tmp5;void*tp=_Tmp4;
# 1427
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
void*s2=Cyc_AssnDef_subst_term(dict,t2,term_h);
res=Cyc_AssnDef_select(s1,s2,tp);
goto _LL0;}case 7: _Tmp6=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;void*t2=_Tmp5;void*t3=_Tmp4;
# 1432
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
void*s2=Cyc_AssnDef_subst_term(dict,t2,term_h);
void*s3=Cyc_AssnDef_subst_term(dict,t3,term_h);
res=Cyc_AssnDef_update(s1,s2,s3);
goto _LL0;}case 2:  {
# 1438
void**t1=Cyc_Dict_lookup_opt(dict,t);
if(t1!=0)res=*t1;else{
res=t;}
goto _LL0;}case 3: _Tmp1=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f3;{enum Cyc_Absyn_Primop p=_Tmp1;void*t1=_Tmp6;void*tp=_Tmp5;
# 1443
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
res=Cyc_AssnDef_unop(p,s1,tp);
goto _LL0;}case 4: _Tmp1=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f4;{enum Cyc_Absyn_Primop p=_Tmp1;void*t1=_Tmp6;void*t2=_Tmp5;void*tp=_Tmp4;
# 1447
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
void*s2=Cyc_AssnDef_subst_term(dict,t2,term_h);
res=Cyc_AssnDef_binop(p,s1,s2,tp);
goto _LL0;}case 5: _Tmp6=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f2;{void*tp=_Tmp6;void*t1=_Tmp5;
# 1452
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
res=Cyc_AssnDef_cast(tp,s1);
goto _LL0;}case 8: _Tmp3=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f2;_Tmp6=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f3;_Tmp5=(void*)((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f4;{int b=_Tmp3;unsigned tag=_Tmp0;struct Cyc_List_List*tlist=_Tmp6;void*tp=_Tmp5;
# 1456
struct Cyc_List_List*slist=0;
for(1;tlist!=0;tlist=tlist->tl){
slist=({struct Cyc_List_List*_Tmp7=_cycalloc(sizeof(struct Cyc_List_List));({void*_Tmp8=Cyc_AssnDef_subst_term(dict,(void*)tlist->hd,term_h);_Tmp7->hd=_Tmp8;}),_Tmp7->tl=slist;_Tmp7;});}
# 1460
Cyc_List_imp_rev(slist);
res=Cyc_AssnDef_aggr(b,tag,slist,tp);
goto _LL0;}case 9: _Tmp6=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;unsigned i=_Tmp0;void*tp=_Tmp5;
# 1464
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
res=Cyc_AssnDef_proj(s1,i,tp);
goto _LL0;}case 10: _Tmp6=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;unsigned i=_Tmp0;void*t2=_Tmp5;
# 1468
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
void*s2=Cyc_AssnDef_subst_term(dict,t2,term_h);
res=Cyc_AssnDef_aggr_update(s1,i,s2);
goto _LL0;}case 13: _Tmp6=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;unsigned i=_Tmp0;void*tp=_Tmp5;
# 1473
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
res=Cyc_AssnDef_offsetf(s1,i,tp);
goto _LL0;}case 14: _Tmp6=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;void*t2=_Tmp5;void*tp=_Tmp4;
# 1477
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
void*s2=Cyc_AssnDef_subst_term(dict,t2,term_h);
res=Cyc_AssnDef_offseti(s1,s2,tp);
goto _LL0;}default: _Tmp6=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)t)->f1;{void*t1=_Tmp6;
# 1482
res=Cyc_AssnDef_tagof_tm(Cyc_AssnDef_subst_term(dict,t1,term_h));
goto _LL0;}}_LL0:;}
# 1485
Cyc_Hashtable_insert(term_h,t,res);
return res;}}
# 1489
static int Cyc_AssnDef_hash_ptr(void*s){return(int)s;}
# 1492
void*Cyc_AssnDef_subst_t(struct Cyc_Dict_Dict dict,void*t){
struct Cyc_Hashtable_Table*term_h=Cyc_Hashtable_create(137,Cyc_Core_ptrcmp,Cyc_AssnDef_hash_ptr);
return Cyc_AssnDef_subst_term(dict,t,term_h);}struct _tuple19{struct _fat_ptr f0;unsigned f1;};
# 1499
static struct _tuple19 Cyc_AssnDef_a2dag(void*a,int*ctr,struct Cyc_Hashtable_Table*t,struct Cyc_List_List**decls){
# 1503
struct _tuple19**resopt=({struct _tuple19**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct _tuple19**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(t,a);
if(resopt!=0)
return*(*resopt);{
# 1507
int c=*ctr;
*ctr=c + 1;{
struct _fat_ptr name=({struct Cyc_Int_pa_PrintArg_struct _Tmp0=({struct Cyc_Int_pa_PrintArg_struct _Tmp1;_Tmp1.tag=1,_Tmp1.f1=(unsigned long)c;_Tmp1;});void*_Tmp1[1];_Tmp1[0]=& _Tmp0;Cyc_aprintf(_tag_fat("A%d",sizeof(char),4U),_tag_fat(_Tmp1,sizeof(void*),1));});
struct _fat_ptr s;
unsigned size=1U;
{void*_Tmp0;enum Cyc_AssnDef_Primreln _Tmp1;void*_Tmp2;switch(*((int*)a)){case 0:
 s=_tag_fat("true",sizeof(char),5U);goto _LL0;case 1:
 s=_tag_fat("false",sizeof(char),6U);goto _LL0;case 2: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp1=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp1;void*t2=_Tmp0;
# 1516
struct _fat_ptr ps;
switch((int)p){case Cyc_AssnDef_Eq:
 ps=_tag_fat("==",sizeof(char),3U);goto _LLB;case Cyc_AssnDef_Neq:
 ps=_tag_fat("!=",sizeof(char),3U);goto _LLB;case Cyc_AssnDef_SLt:
 ps=_tag_fat(" S< ",sizeof(char),5U);goto _LLB;case Cyc_AssnDef_SLte:
 ps=_tag_fat(" S<= ",sizeof(char),6U);goto _LLB;case Cyc_AssnDef_ULt:
 ps=_tag_fat(" U< ",sizeof(char),5U);goto _LLB;case Cyc_AssnDef_ULte:
 ps=_tag_fat(" U<= ",sizeof(char),6U);goto _LLB;default:
({int(*_Tmp3)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp3;})(_tag_fat("assn2string primop",sizeof(char),19U),_tag_fat(0U,sizeof(void*),0));}_LLB:;
# 1526
s=({struct Cyc_String_pa_PrintArg_struct _Tmp3=({struct Cyc_String_pa_PrintArg_struct _Tmp4;_Tmp4.tag=0,({struct _fat_ptr _Tmp5=Cyc_AssnDef_term2string(t1);_Tmp4.f1=_Tmp5;});_Tmp4;});struct Cyc_String_pa_PrintArg_struct _Tmp4=({struct Cyc_String_pa_PrintArg_struct _Tmp5;_Tmp5.tag=0,_Tmp5.f1=ps;_Tmp5;});struct Cyc_String_pa_PrintArg_struct _Tmp5=({struct Cyc_String_pa_PrintArg_struct _Tmp6;_Tmp6.tag=0,({struct _fat_ptr _Tmp7=Cyc_AssnDef_term2string(t2);_Tmp6.f1=_Tmp7;});_Tmp6;});void*_Tmp6[3];_Tmp6[0]=& _Tmp3,_Tmp6[1]=& _Tmp4,_Tmp6[2]=& _Tmp5;Cyc_aprintf(_tag_fat("%s%s%s",sizeof(char),7U),_tag_fat(_Tmp6,sizeof(void*),3));});
goto _LL0;}case 4: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 1529
struct _tuple19 _Tmp3=Cyc_AssnDef_a2dag(a1,ctr,t,decls);unsigned _Tmp4;struct _fat_ptr _Tmp5;_Tmp5=_Tmp3.f0;_Tmp4=_Tmp3.f1;{struct _fat_ptr s1=_Tmp5;unsigned n1=_Tmp4;
struct _tuple19 _Tmp6=Cyc_AssnDef_a2dag(a2,ctr,t,decls);unsigned _Tmp7;struct _fat_ptr _Tmp8;_Tmp8=_Tmp6.f0;_Tmp7=_Tmp6.f1;{struct _fat_ptr s2=_Tmp8;unsigned n2=_Tmp7;
s=({struct Cyc_String_pa_PrintArg_struct _Tmp9=({struct Cyc_String_pa_PrintArg_struct _TmpA;_TmpA.tag=0,_TmpA.f1=s1;_TmpA;});struct Cyc_String_pa_PrintArg_struct _TmpA=({struct Cyc_String_pa_PrintArg_struct _TmpB;_TmpB.tag=0,_TmpB.f1=s2;_TmpB;});void*_TmpB[2];_TmpB[0]=& _Tmp9,_TmpB[1]=& _TmpA;Cyc_aprintf(_tag_fat("%s || %s",sizeof(char),9U),_tag_fat(_TmpB,sizeof(void*),2));});
size +=n1 + n2;
goto _LL0;}}}default: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 1535
struct _tuple19 _Tmp3=Cyc_AssnDef_a2dag(a1,ctr,t,decls);unsigned _Tmp4;struct _fat_ptr _Tmp5;_Tmp5=_Tmp3.f0;_Tmp4=_Tmp3.f1;{struct _fat_ptr s1=_Tmp5;unsigned n1=_Tmp4;
struct _tuple19 _Tmp6=Cyc_AssnDef_a2dag(a2,ctr,t,decls);unsigned _Tmp7;struct _fat_ptr _Tmp8;_Tmp8=_Tmp6.f0;_Tmp7=_Tmp6.f1;{struct _fat_ptr s2=_Tmp8;unsigned n2=_Tmp7;
s=({struct Cyc_String_pa_PrintArg_struct _Tmp9=({struct Cyc_String_pa_PrintArg_struct _TmpA;_TmpA.tag=0,_TmpA.f1=s1;_TmpA;});struct Cyc_String_pa_PrintArg_struct _TmpA=({struct Cyc_String_pa_PrintArg_struct _TmpB;_TmpB.tag=0,_TmpB.f1=s2;_TmpB;});void*_TmpB[2];_TmpB[0]=& _Tmp9,_TmpB[1]=& _TmpA;Cyc_aprintf(_tag_fat("%s && %s",sizeof(char),9U),_tag_fat(_TmpB,sizeof(void*),2));});
size +=n1 + n2;
goto _LL0;}}}}_LL0:;}
# 1541
({struct Cyc_List_List*_Tmp0=({struct Cyc_List_List*_Tmp1=_cycalloc(sizeof(struct Cyc_List_List));({struct _fat_ptr*_Tmp2=({struct _fat_ptr*_Tmp3=_cycalloc(sizeof(struct _fat_ptr));({struct _fat_ptr _Tmp4=(struct _fat_ptr)({struct Cyc_String_pa_PrintArg_struct _Tmp5=({struct Cyc_String_pa_PrintArg_struct _Tmp6;_Tmp6.tag=0,_Tmp6.f1=name;_Tmp6;});struct Cyc_String_pa_PrintArg_struct _Tmp6=({struct Cyc_String_pa_PrintArg_struct _Tmp7;_Tmp7.tag=0,_Tmp7.f1=s;_Tmp7;});void*_Tmp7[2];_Tmp7[0]=& _Tmp5,_Tmp7[1]=& _Tmp6;Cyc_aprintf(_tag_fat("%s = %s\n",sizeof(char),9U),_tag_fat(_Tmp7,sizeof(void*),2));});*_Tmp3=_Tmp4;});_Tmp3;});_Tmp1->hd=_Tmp2;}),_Tmp1->tl=*decls;_Tmp1;});*decls=_Tmp0;});
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct _tuple19*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct _tuple19*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct _tuple19*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=t;void*_Tmp2=a;_Tmp0(_Tmp1,_Tmp2,({struct _tuple19*_Tmp3=_cycalloc(sizeof(struct _tuple19));_Tmp3->f0=name,_Tmp3->f1=size;_Tmp3;}));});{
struct _tuple19 _Tmp0;_Tmp0.f0=name,_Tmp0.f1=size;return _Tmp0;}}}}
# 1546
int Cyc_AssnDef_assnhash(void*);
# 1548
struct _fat_ptr Cyc_AssnDef_assn2dag(void*a){
struct Cyc_List_List*decls=0;
struct Cyc_Hashtable_Table*t=
Cyc_Hashtable_create(221,Cyc_AssnDef_assncmp,Cyc_AssnDef_assnhash);
int ctr=0;
struct _tuple19 _Tmp0=Cyc_AssnDef_a2dag(a,& ctr,t,& decls);unsigned _Tmp1;struct _fat_ptr _Tmp2;_Tmp2=_Tmp0.f0;_Tmp1=_Tmp0.f1;{struct _fat_ptr s=_Tmp2;unsigned n=_Tmp1;
decls=Cyc_List_imp_rev(({struct Cyc_List_List*_Tmp3=_cycalloc(sizeof(struct Cyc_List_List));({struct _fat_ptr*_Tmp4=({struct _fat_ptr*_Tmp5=_cycalloc(sizeof(struct _fat_ptr));({struct _fat_ptr _Tmp6=(struct _fat_ptr)({struct Cyc_String_pa_PrintArg_struct _Tmp7=({struct Cyc_String_pa_PrintArg_struct _Tmp8;_Tmp8.tag=0,_Tmp8.f1=s;_Tmp8;});struct Cyc_Int_pa_PrintArg_struct _Tmp8=({struct Cyc_Int_pa_PrintArg_struct _Tmp9;_Tmp9.tag=1,_Tmp9.f1=(unsigned long)((int)n);_Tmp9;});void*_Tmp9[2];_Tmp9[0]=& _Tmp7,_Tmp9[1]=& _Tmp8;Cyc_aprintf(_tag_fat("in %s (%d nodes as tree)\n",sizeof(char),26U),_tag_fat(_Tmp9,sizeof(void*),2));});*_Tmp5=_Tmp6;});_Tmp5;});_Tmp3->hd=_Tmp4;}),_Tmp3->tl=decls;_Tmp3;}));
return Cyc_strconcat_l(decls);}}
# 1561
static struct _fat_ptr Cyc_AssnDef_a2string(void*a,int inprec){
int myprec=10;
struct _fat_ptr s;
{void*_Tmp0;enum Cyc_AssnDef_Primreln _Tmp1;void*_Tmp2;switch(*((int*)a)){case 0:
 s=_tag_fat("true",sizeof(char),5U);goto _LL0;case 1:
 s=_tag_fat("false",sizeof(char),6U);goto _LL0;case 2: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp1=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp1;void*t2=_Tmp0;
# 1568
struct _fat_ptr ps;
switch((int)p){case Cyc_AssnDef_Eq:
 ps=_tag_fat("==",sizeof(char),3U);goto _LLB;case Cyc_AssnDef_Neq:
 ps=_tag_fat("!=",sizeof(char),3U);goto _LLB;case Cyc_AssnDef_SLt:
 ps=_tag_fat(" S< ",sizeof(char),5U);goto _LLB;case Cyc_AssnDef_SLte:
 ps=_tag_fat(" S<= ",sizeof(char),6U);goto _LLB;case Cyc_AssnDef_ULt:
 ps=_tag_fat(" U< ",sizeof(char),5U);goto _LLB;case Cyc_AssnDef_ULte:
 ps=_tag_fat(" U<= ",sizeof(char),6U);goto _LLB;default:
({int(*_Tmp3)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp3;})(_tag_fat("assn2string primop",sizeof(char),19U),_tag_fat(0U,sizeof(void*),0));}_LLB:;
# 1578
s=({struct Cyc_String_pa_PrintArg_struct _Tmp3=({struct Cyc_String_pa_PrintArg_struct _Tmp4;_Tmp4.tag=0,({struct _fat_ptr _Tmp5=Cyc_AssnDef_term2string(t1);_Tmp4.f1=_Tmp5;});_Tmp4;});struct Cyc_String_pa_PrintArg_struct _Tmp4=({struct Cyc_String_pa_PrintArg_struct _Tmp5;_Tmp5.tag=0,_Tmp5.f1=ps;_Tmp5;});struct Cyc_String_pa_PrintArg_struct _Tmp5=({struct Cyc_String_pa_PrintArg_struct _Tmp6;_Tmp6.tag=0,({struct _fat_ptr _Tmp7=Cyc_AssnDef_term2string(t2);_Tmp6.f1=_Tmp7;});_Tmp6;});void*_Tmp6[3];_Tmp6[0]=& _Tmp3,_Tmp6[1]=& _Tmp4,_Tmp6[2]=& _Tmp5;Cyc_aprintf(_tag_fat("%s%s%s",sizeof(char),7U),_tag_fat(_Tmp6,sizeof(void*),3));});
goto _LL0;}case 4: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 1581
myprec=5;
s=({struct Cyc_String_pa_PrintArg_struct _Tmp3=({struct Cyc_String_pa_PrintArg_struct _Tmp4;_Tmp4.tag=0,({struct _fat_ptr _Tmp5=Cyc_AssnDef_a2string(a1,myprec);_Tmp4.f1=_Tmp5;});_Tmp4;});struct Cyc_String_pa_PrintArg_struct _Tmp4=({struct Cyc_String_pa_PrintArg_struct _Tmp5;_Tmp5.tag=0,({struct _fat_ptr _Tmp6=Cyc_AssnDef_a2string(a2,myprec);_Tmp5.f1=_Tmp6;});_Tmp5;});void*_Tmp5[2];_Tmp5[0]=& _Tmp3,_Tmp5[1]=& _Tmp4;Cyc_aprintf(_tag_fat("%s || %s",sizeof(char),9U),_tag_fat(_Tmp5,sizeof(void*),2));});
goto _LL0;}default: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 1585
myprec=10;
s=({struct Cyc_String_pa_PrintArg_struct _Tmp3=({struct Cyc_String_pa_PrintArg_struct _Tmp4;_Tmp4.tag=0,({struct _fat_ptr _Tmp5=Cyc_AssnDef_a2string(a1,10);_Tmp4.f1=_Tmp5;});_Tmp4;});struct Cyc_String_pa_PrintArg_struct _Tmp4=({struct Cyc_String_pa_PrintArg_struct _Tmp5;_Tmp5.tag=0,({struct _fat_ptr _Tmp6=Cyc_AssnDef_a2string(a2,10);_Tmp5.f1=_Tmp6;});_Tmp5;});void*_Tmp5[2];_Tmp5[0]=& _Tmp3,_Tmp5[1]=& _Tmp4;Cyc_aprintf(_tag_fat("%s && %s",sizeof(char),9U),_tag_fat(_Tmp5,sizeof(void*),2));});
goto _LL0;}}_LL0:;}
# 1589
if(myprec < inprec)
s=({struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,_Tmp1.f1=s;_Tmp1;});void*_Tmp1[1];_Tmp1[0]=& _Tmp0;Cyc_aprintf(_tag_fat("(%s)",sizeof(char),5U),_tag_fat(_Tmp1,sizeof(void*),1));});
return s;}
# 1595
struct _fat_ptr Cyc_AssnDef_assn2string(void*a){
return Cyc_AssnDef_a2string(a,10);}
# 1607 "assndef.cyc"
int Cyc_AssnDef_assnhash(void*a){
void*_Tmp0;enum Cyc_AssnDef_Primreln _Tmp1;void*_Tmp2;switch(*((int*)a)){case 1:
 return 0;case 0:
 return 1;case 2: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp1=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp1;void*t2=_Tmp0;
# 1612
int _Tmp3=({int _Tmp4=Cyc_AssnDef_termhash(t1);_Tmp4 + (int)p;});return _Tmp3 + Cyc_AssnDef_termhash(t2);}case 3: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 1614
return(int)(((unsigned)a1 + (unsigned)a2 >> 4)+ 3U);}default: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 1616
return(int)(((unsigned)a2 + (unsigned)a1 >> 4)+ 5U);}};}
# 1622
int Cyc_AssnDef_assncmp(void*_a1,void*_a2){
void*a1=_a1;
void*a2=_a2;
LOOP:
 if(a1==a2)return 0;{
int c=(int)(*((const unsigned*)a2)- *((const unsigned*)a1));
if(c!=0)return c;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=a1,_Tmp1.f1=a2;_Tmp1;});enum Cyc_AssnDef_Primreln _Tmp1;enum Cyc_AssnDef_Primreln _Tmp2;void*_Tmp3;void*_Tmp4;void*_Tmp5;void*_Tmp6;switch(*((int*)_Tmp0.f0)){case 3: if(*((int*)_Tmp0.f1)==3){_Tmp6=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)_Tmp0.f0)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)_Tmp0.f0)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)_Tmp0.f1)->f1;_Tmp3=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)_Tmp0.f1)->f2;{void*a11=_Tmp6;void*a12=_Tmp5;void*a21=_Tmp4;void*a22=_Tmp3;
_Tmp6=a11;_Tmp5=a12;_Tmp4=a21;_Tmp3=a22;goto _LL4;}}else{goto _LL7;}case 4: if(*((int*)_Tmp0.f1)==4){_Tmp6=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)_Tmp0.f0)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)_Tmp0.f0)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)_Tmp0.f1)->f1;_Tmp3=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)_Tmp0.f1)->f2;_LL4: {void*a11=_Tmp6;void*a12=_Tmp5;void*a21=_Tmp4;void*a22=_Tmp3;
# 1632
int c=Cyc_AssnDef_assncmp(a11,a21);
if(c!=0)return c;
a1=a12;
a2=a22;
goto LOOP;}}else{goto _LL7;}case 2: if(*((int*)_Tmp0.f1)==2){_Tmp6=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)_Tmp0.f0)->f1;_Tmp2=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)_Tmp0.f0)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)_Tmp0.f0)->f3;_Tmp4=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)_Tmp0.f1)->f2;_Tmp3=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)_Tmp0.f1)->f3;{void*t11=_Tmp6;enum Cyc_AssnDef_Primreln p1=_Tmp2;void*t12=_Tmp5;void*t21=_Tmp4;enum Cyc_AssnDef_Primreln p2=_Tmp1;void*t22=_Tmp3;
# 1638
int c=(int)p1 - (int)p2;
if(c!=0)return c;
c=Cyc_AssnDef_termcmp(t11,t21);
if(c!=0)return c;
return Cyc_AssnDef_termcmp(t12,t22);}}else{goto _LL7;}default: _LL7:
({int(*_Tmp7)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp7;})(_tag_fat("assncmp:  tagof failure",sizeof(char),24U),_tag_fat(0U,sizeof(void*),0));};}}}
# 1650
static void*Cyc_AssnDef_copy_assn(void*a){
enum Cyc_AssnDef_Primreln _Tmp0;void*_Tmp1;void*_Tmp2;switch(*((int*)a)){case 0:
# 1653
({int(*_Tmp3)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp3;})(_tag_fat("True assertion should be in the table",sizeof(char),38U),_tag_fat(0U,sizeof(void*),0));case 1:
# 1655
({int(*_Tmp3)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp3;})(_tag_fat("False assertion should be in the table",sizeof(char),39U),_tag_fat(0U,sizeof(void*),0));case 3: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp1;
return(void*)({struct Cyc_AssnDef_And_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_And_AssnDef_Assn_struct));_Tmp3->tag=3,_Tmp3->f1=a1,_Tmp3->f2=a2;_Tmp3;});}case 4: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp1;
return(void*)({struct Cyc_AssnDef_Or_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Or_AssnDef_Assn_struct));_Tmp3->tag=4,_Tmp3->f1=a1,_Tmp3->f2=a2;_Tmp3;});}default: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp0=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp0;void*t2=_Tmp1;
return(void*)({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Prim_AssnDef_Assn_struct));_Tmp3->tag=2,_Tmp3->f1=t1,_Tmp3->f2=p,_Tmp3->f3=t2;_Tmp3;});}};}
# 1664
struct Cyc_AssnDef_True_AssnDef_Assn_struct Cyc_AssnDef_true_assn={0};
struct Cyc_AssnDef_False_AssnDef_Assn_struct Cyc_AssnDef_false_assn={1};
# 1672
static void*Cyc_AssnDef_neg_assn(void*a){
enum Cyc_AssnDef_Primreln _Tmp0;void*_Tmp1;void*_Tmp2;switch(*((int*)a)){case 0:
 return(void*)& Cyc_AssnDef_false_assn;case 1:
 return(void*)& Cyc_AssnDef_true_assn;case 3: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp1;
return(void*)({struct Cyc_AssnDef_Or_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Or_AssnDef_Assn_struct));_Tmp3->tag=4,({void*_Tmp4=Cyc_AssnDef_not(a1);_Tmp3->f1=_Tmp4;}),({void*_Tmp4=Cyc_AssnDef_not(a2);_Tmp3->f2=_Tmp4;});_Tmp3;});}case 4: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp1;
return(void*)({struct Cyc_AssnDef_And_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_And_AssnDef_Assn_struct));_Tmp3->tag=3,({void*_Tmp4=Cyc_AssnDef_not(a1);_Tmp3->f1=_Tmp4;}),({void*_Tmp4=Cyc_AssnDef_not(a2);_Tmp3->f2=_Tmp4;});_Tmp3;});}default: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp0=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp0;void*t2=_Tmp1;
# 1679
switch((int)p){case Cyc_AssnDef_Eq:
 return(void*)({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Prim_AssnDef_Assn_struct));_Tmp3->tag=2,_Tmp3->f1=t1,_Tmp3->f2=1U,_Tmp3->f3=t2;_Tmp3;});case Cyc_AssnDef_Neq:
 return(void*)({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Prim_AssnDef_Assn_struct));_Tmp3->tag=2,_Tmp3->f1=t1,_Tmp3->f2=0U,_Tmp3->f3=t2;_Tmp3;});case Cyc_AssnDef_SLt:
 return(void*)({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Prim_AssnDef_Assn_struct));_Tmp3->tag=2,_Tmp3->f1=t2,_Tmp3->f2=3U,_Tmp3->f3=t1;_Tmp3;});case Cyc_AssnDef_SLte:
 return(void*)({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Prim_AssnDef_Assn_struct));_Tmp3->tag=2,_Tmp3->f1=t2,_Tmp3->f2=2U,_Tmp3->f3=t1;_Tmp3;});case Cyc_AssnDef_ULt:
 return(void*)({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Prim_AssnDef_Assn_struct));_Tmp3->tag=2,_Tmp3->f1=t2,_Tmp3->f2=5U,_Tmp3->f3=t1;_Tmp3;});case Cyc_AssnDef_ULte:
 return(void*)({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_Prim_AssnDef_Assn_struct));_Tmp3->tag=2,_Tmp3->f1=t2,_Tmp3->f2=4U,_Tmp3->f3=t1;_Tmp3;});default:
({int(*_Tmp3)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp3;})(_tag_fat("undefined prim relation",sizeof(char),24U),_tag_fat(0U,sizeof(void*),0));};}};}struct Cyc_AssnDef_AssnHashedInfo{void*assn;void*negation;struct Cyc_Set_Set**widened_set;struct Cyc_Set_Set**free_logicvar_set;};
# 1702
static struct Cyc_Hashtable_Table*Cyc_AssnDef_assn_hash_cons_table;
# 1704
static struct Cyc_Hashtable_Table*Cyc_AssnDef_get_assn_hash_cons_table (void){
# 1706
struct Cyc_Hashtable_Table*h;
if(Cyc_AssnDef_assn_hash_cons_table==0){
h=Cyc_Hashtable_create(221,Cyc_AssnDef_assncmp,Cyc_AssnDef_assnhash);
Cyc_AssnDef_assn_hash_cons_table=h;{
struct Cyc_Set_Set*ast=Cyc_Set_empty(Cyc_AssnDef_assncmp);
struct Cyc_Set_Set*tst=Cyc_AssnDef_empty_term_set();
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=h;_Tmp0(_Tmp1,(void*)& Cyc_AssnDef_true_assn,({struct Cyc_AssnDef_AssnHashedInfo*_Tmp2=_cycalloc(sizeof(struct Cyc_AssnDef_AssnHashedInfo));_Tmp2->assn=(void*)& Cyc_AssnDef_true_assn,_Tmp2->negation=(void*)& Cyc_AssnDef_false_assn,({struct Cyc_Set_Set**_Tmp3=({struct Cyc_Set_Set**_Tmp4=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp4=ast;_Tmp4;});_Tmp2->widened_set=_Tmp3;}),({struct Cyc_Set_Set**_Tmp3=({struct Cyc_Set_Set**_Tmp4=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp4=tst;_Tmp4;});_Tmp2->free_logicvar_set=_Tmp3;});_Tmp2;}));});
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=h;_Tmp0(_Tmp1,(void*)& Cyc_AssnDef_false_assn,({struct Cyc_AssnDef_AssnHashedInfo*_Tmp2=_cycalloc(sizeof(struct Cyc_AssnDef_AssnHashedInfo));_Tmp2->assn=(void*)& Cyc_AssnDef_false_assn,_Tmp2->negation=(void*)& Cyc_AssnDef_true_assn,({struct Cyc_Set_Set**_Tmp3=({struct Cyc_Set_Set**_Tmp4=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp4=0;_Tmp4;});_Tmp2->widened_set=_Tmp3;}),({struct Cyc_Set_Set**_Tmp3=({struct Cyc_Set_Set**_Tmp4=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp4=tst;_Tmp4;});_Tmp2->free_logicvar_set=_Tmp3;});_Tmp2;}));});}}else{
# 1715
h=Cyc_AssnDef_assn_hash_cons_table;}
# 1717
return h;}
# 1719
static void*Cyc_AssnDef_hash_cons_assn(void*a){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_assn_hash_cons_table();
struct Cyc_AssnDef_AssnHashedInfo**resopt=({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,int(*)(void*,void*),int(*)(void*))=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*,int(*)(void*,void*),int(*)(void*)))Cyc_Hashtable_lookup_other_opt;_Tmp0;})(h,a,Cyc_AssnDef_assncmp,Cyc_AssnDef_assnhash);
if(resopt==0){
# 1725
void*a2=Cyc_AssnDef_copy_assn(a);
void*nega2=Cyc_AssnDef_neg_assn(a);
# 1728
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=h;void*_Tmp2=a2;_Tmp0(_Tmp1,_Tmp2,({struct Cyc_AssnDef_AssnHashedInfo*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_AssnHashedInfo));_Tmp3->assn=a2,_Tmp3->negation=nega2,_Tmp3->widened_set=0,_Tmp3->free_logicvar_set=0;_Tmp3;}));});
({void(*_Tmp0)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=({void(*_Tmp1)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*)=(void(*)(struct Cyc_Hashtable_Table*,void*,struct Cyc_AssnDef_AssnHashedInfo*))Cyc_Hashtable_insert;_Tmp1;});struct Cyc_Hashtable_Table*_Tmp1=h;void*_Tmp2=nega2;_Tmp0(_Tmp1,_Tmp2,({struct Cyc_AssnDef_AssnHashedInfo*_Tmp3=_cycalloc(sizeof(struct Cyc_AssnDef_AssnHashedInfo));_Tmp3->assn=nega2,_Tmp3->negation=a2,_Tmp3->widened_set=0,_Tmp3->free_logicvar_set=0;_Tmp3;}));});
# 1732
return a2;}else{
# 1734
return(*resopt)->assn;}}
# 1737
void*Cyc_AssnDef_and(void*a1,void*a2){
if(a1==a2)return a1;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=a1,_Tmp1.f1=a2;_Tmp1;});if(*((int*)_Tmp0.f0)==0)
return a2;else{if(*((int*)_Tmp0.f1)==0)
return a1;else{if(*((int*)_Tmp0.f0)==1)
return a1;else{if(*((int*)_Tmp0.f1)==1)
return a2;else{
# 1747
struct Cyc_AssnDef_And_AssnDef_Assn_struct a=({struct Cyc_AssnDef_And_AssnDef_Assn_struct _Tmp1;_Tmp1.tag=3,_Tmp1.f1=a1,_Tmp1.f2=a2;_Tmp1;});
return Cyc_AssnDef_hash_cons_assn((void*)& a);}}}};}}
# 1752
void*Cyc_AssnDef_or(void*a1,void*a2){
if(a1==a2)return a1;{
# 1755
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=a1,_Tmp1.f1=a2;_Tmp1;});if(*((int*)_Tmp0.f0)==0)
return a1;else{if(*((int*)_Tmp0.f1)==0)
return a2;else{if(*((int*)_Tmp0.f0)==1)
return a2;else{if(*((int*)_Tmp0.f1)==1)
return a1;else{
# 1763
struct Cyc_AssnDef_Or_AssnDef_Assn_struct a=({struct Cyc_AssnDef_Or_AssnDef_Assn_struct _Tmp1;_Tmp1.tag=4,_Tmp1.f1=a1,_Tmp1.f2=a2;_Tmp1;});
return Cyc_AssnDef_hash_cons_assn((void*)& a);}}}};}}
# 1777 "assndef.cyc"
static void*Cyc_AssnDef_reinsert(void*a){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_assn_hash_cons_table();
void*_Tmp0;void*_Tmp1;switch(*((int*)a)){case 0:
 goto _LL4;case 1: _LL4:
 return a;case 3: _Tmp1=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp1;void*a2=_Tmp0;
# 1783
if(({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp2)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp2;})(h,a1)==0)
a1=Cyc_AssnDef_reinsert(a1);
if(({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp2)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp2;})(h,a2)==0)
a2=Cyc_AssnDef_reinsert(a2);{
struct Cyc_AssnDef_And_AssnDef_Assn_struct a=({struct Cyc_AssnDef_And_AssnDef_Assn_struct _Tmp2;_Tmp2.tag=3,_Tmp2.f1=a1,_Tmp2.f2=a2;_Tmp2;});
return Cyc_AssnDef_hash_cons_assn((void*)& a);}}case 4: _Tmp1=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp1;void*a2=_Tmp0;
# 1790
if(({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp2)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp2;})(h,a1)==0)
a1=Cyc_AssnDef_reinsert(a1);
if(({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp2)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp2;})(h,a2)==0)
a2=Cyc_AssnDef_reinsert(a2);{
struct Cyc_AssnDef_Or_AssnDef_Assn_struct a=({struct Cyc_AssnDef_Or_AssnDef_Assn_struct _Tmp2;_Tmp2.tag=4,_Tmp2.f1=a1,_Tmp2.f2=a2;_Tmp2;});
return Cyc_AssnDef_hash_cons_assn((void*)& a);}}default:
# 1797
 return Cyc_AssnDef_hash_cons_assn(a);};}
# 1803
struct Cyc_Set_Set*Cyc_AssnDef_assn_fr_logicvar(void*a){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_assn_hash_cons_table();
struct Cyc_AssnDef_AssnHashedInfo**ahinfo=({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,a);
if(ahinfo==0){
a=Cyc_AssnDef_reinsert(a);
ahinfo=({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,a);}
# 1810
if((*_check_null(ahinfo))->free_logicvar_set!=0)
return*(*ahinfo)->free_logicvar_set;{
struct Cyc_Set_Set*res;
{void*_Tmp0;void*_Tmp1;switch(*((int*)a)){case 0:
 goto _LL4;case 1: _LL4:
# 1816
 res=Cyc_AssnDef_empty_term_set();
goto _LL0;case 3: _Tmp1=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp1;void*a2=_Tmp0;
# 1819
_Tmp1=a1;_Tmp0=a2;goto _LL8;}case 4: _Tmp1=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;_LL8: {void*a1=_Tmp1;void*a2=_Tmp0;
# 1821
res=({struct Cyc_Set_Set*_Tmp2=Cyc_AssnDef_assn_fr_logicvar(a1);Cyc_Set_union_two(_Tmp2,Cyc_AssnDef_assn_fr_logicvar(a2));});
goto _LL0;}default: _Tmp1=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp1;void*t2=_Tmp0;
# 1824
res=({struct Cyc_Set_Set*_Tmp2=Cyc_AssnDef_term_fr_logicvar(t1);Cyc_Set_union_two(_Tmp2,Cyc_AssnDef_term_fr_logicvar(t2));});
goto _LL0;}}_LL0:;}
# 1827
({struct Cyc_Set_Set**_Tmp0=({struct Cyc_Set_Set**_Tmp1=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp1=res;_Tmp1;});(*ahinfo)->free_logicvar_set=_Tmp0;});
return res;}}
# 1832
static int Cyc_AssnDef_logicvar_in_assn(void*lvar,void*a){
struct Cyc_Set_Set*lvset=Cyc_AssnDef_assn_fr_logicvar(a);
return Cyc_Set_member(lvset,lvar);}
# 1839
void*Cyc_AssnDef_not(void*a){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_assn_hash_cons_table();
struct Cyc_AssnDef_AssnHashedInfo**ahinfo=({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,a);
if(ahinfo==0){
a=Cyc_AssnDef_reinsert(a);
ahinfo=({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,a);}
# 1846
return(*_check_null(ahinfo))->negation;}
# 1849
void*Cyc_AssnDef_prim(void*t1,enum Cyc_AssnDef_Primreln p,void*t2){
struct Cyc_AssnDef_Prim_AssnDef_Assn_struct ptr=({struct Cyc_AssnDef_Prim_AssnDef_Assn_struct _Tmp0;_Tmp0.tag=2,_Tmp0.f1=t1,_Tmp0.f2=p,_Tmp0.f3=t2;_Tmp0;});
return Cyc_AssnDef_hash_cons_assn((void*)& ptr);}
# 1854
void*Cyc_AssnDef_eq(void*t1,void*t2){
if(t1==t2)return(void*)& Cyc_AssnDef_true_assn;
if(Cyc_AssnDef_term_neq(t1,t2))return(void*)& Cyc_AssnDef_false_assn;
if(Cyc_AssnDef_termcmp(t1,t2)> 0)
({void*_Tmp0=t1;void*_Tmp1=t2;t1=_Tmp1;t2=_Tmp0;});
# 1860
return Cyc_AssnDef_prim(t1,0U,t2);}
# 1863
void*Cyc_AssnDef_slt(void*t1,void*t2){
if(t1==t2)return(void*)& Cyc_AssnDef_false_assn;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});unsigned _Tmp1;unsigned _Tmp2;if(*((int*)_Tmp0.f0)==0){if(*((int*)_Tmp0.f1)==0){_Tmp2=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp1=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;{unsigned i=_Tmp2;unsigned j=_Tmp1;
# 1867
if((int)i < (int)j)return(void*)& Cyc_AssnDef_true_assn;else{return(void*)& Cyc_AssnDef_false_assn;}}}else{goto _LL3;}}else{_LL3:
 return Cyc_AssnDef_prim(t1,2U,t2);};}}
# 1872
void*Cyc_AssnDef_slte(void*t1,void*t2){
if(t1==t2)return(void*)& Cyc_AssnDef_true_assn;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});unsigned _Tmp1;unsigned _Tmp2;if(*((int*)_Tmp0.f0)==0){if(*((int*)_Tmp0.f1)==0){_Tmp2=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp1=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;{unsigned i=_Tmp2;unsigned j=_Tmp1;
# 1876
if((int)i <= (int)j)return(void*)& Cyc_AssnDef_true_assn;else{return(void*)& Cyc_AssnDef_false_assn;}}}else{goto _LL3;}}else{_LL3:
 return Cyc_AssnDef_prim(t1,3U,t2);};}}
# 1881
void*Cyc_AssnDef_ult(void*t1,void*t2){
if(t1==t2)return(void*)& Cyc_AssnDef_false_assn;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});unsigned _Tmp1;unsigned _Tmp2;if(*((int*)_Tmp0.f0)==0){if(*((int*)_Tmp0.f1)==0){_Tmp2=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp1=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;{unsigned i=_Tmp2;unsigned j=_Tmp1;
# 1885
if(i < j)return(void*)& Cyc_AssnDef_true_assn;else{return(void*)& Cyc_AssnDef_false_assn;}}}else{goto _LL3;}}else{_LL3:
 return Cyc_AssnDef_prim(t1,4U,t2);};}}
# 1890
void*Cyc_AssnDef_ulte(void*t1,void*t2){
if(t1==t2)return(void*)& Cyc_AssnDef_true_assn;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});unsigned _Tmp1;unsigned _Tmp2;if(*((int*)_Tmp0.f0)==0){if(*((int*)_Tmp0.f1)==0){_Tmp2=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp1=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;{unsigned i=_Tmp2;unsigned j=_Tmp1;
# 1894
if(i <= j)return(void*)& Cyc_AssnDef_true_assn;else{return(void*)& Cyc_AssnDef_false_assn;}}}else{goto _LL3;}}else{_LL3:
 return Cyc_AssnDef_prim(t1,5U,t2);};}}
# 1899
void*Cyc_AssnDef_neq(void*t1,void*t2){
if(t1==t2)return(void*)& Cyc_AssnDef_false_assn;
if(Cyc_AssnDef_term_neq(t1,t2))return(void*)& Cyc_AssnDef_true_assn;{
struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t1,_Tmp1.f1=t2;_Tmp1;});unsigned _Tmp1;if(*((int*)_Tmp0.f0)==0){_Tmp1=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f0)->f1;if((unsigned)_Tmp1==0U){unsigned i=_Tmp1;
# 1904
void*_Tmp2=Cyc_AssnDef_zero();return Cyc_AssnDef_ult(_Tmp2,t2);}else{if(*((int*)_Tmp0.f1)==0)goto _LL3;else{goto _LL5;}}}else{if(*((int*)_Tmp0.f1)==0){_LL3: _Tmp1=((struct Cyc_AssnDef_Uint_AssnDef_Term_struct*)_Tmp0.f1)->f1;if((unsigned)_Tmp1==0U){unsigned j=_Tmp1;
# 1906
void*_Tmp2=Cyc_AssnDef_zero();return Cyc_AssnDef_ult(_Tmp2,t1);}else{goto _LL5;}}else{_LL5:
# 1908
 if(Cyc_AssnDef_termcmp(t1,t2)> 0)
({void*_Tmp2=t1;void*_Tmp3=t2;t1=_Tmp3;t2=_Tmp2;});
# 1911
return Cyc_AssnDef_prim(t1,1U,t2);}};}}
# 1915
struct Cyc_Set_Set*Cyc_AssnDef_widen_it(void*a){
struct Cyc_Hashtable_Table*h=Cyc_AssnDef_get_assn_hash_cons_table();
struct Cyc_AssnDef_AssnHashedInfo**ahinfo=({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,a);
if(ahinfo==0){
a=Cyc_AssnDef_reinsert(a);
ahinfo=({struct Cyc_AssnDef_AssnHashedInfo**(*_Tmp0)(struct Cyc_Hashtable_Table*,void*)=(struct Cyc_AssnDef_AssnHashedInfo**(*)(struct Cyc_Hashtable_Table*,void*))Cyc_Hashtable_lookup_opt;_Tmp0;})(h,a);}
# 1922
if((*_check_null(ahinfo))->widened_set!=0)return*(*ahinfo)->widened_set;{
struct Cyc_Set_Set*s;
{enum Cyc_AssnDef_Primreln _Tmp0;void*_Tmp1;void*_Tmp2;switch(*((int*)a)){case 0:
 goto _LL4;case 1: _LL4:
# 1927
({int(*_Tmp3)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp3;})(_tag_fat("true and false should have widened_set",sizeof(char),39U),_tag_fat(0U,sizeof(void*),0));case 3: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp1;
# 1929
struct Cyc_Set_Set*s1=Cyc_AssnDef_widen_it(a1);
struct Cyc_Set_Set*s2=Cyc_AssnDef_widen_it(a2);
if(s1==0 || s2==0)
s=0;else{
# 1934
s=Cyc_Set_union_two(s1,s2);}
goto _LL0;}case 4: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp1=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp1;
# 1937
struct Cyc_Set_Set*s1=Cyc_AssnDef_widen_it(a1);
struct Cyc_Set_Set*s2=Cyc_AssnDef_widen_it(a2);
if(s1==0)
s=s2;else{
if(s2==0)
s=s1;else{
# 1944
s=Cyc_Set_intersect(s1,s2);}}
goto _LL0;}default: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp0=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp1=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp0;void*t2=_Tmp1;
# 1947
s=Cyc_Set_singleton(Cyc_AssnDef_assncmp,a);
switch((int)p){case Cyc_AssnDef_Eq:  {
# 1953
void*topt1=Cyc_AssnDef_get_term_type(t1);
void*topt2=Cyc_AssnDef_get_term_type(t2);
if(topt1!=0 && Cyc_Tcutil_is_integral_type(topt1)||
 topt2!=0 && Cyc_Tcutil_is_integral_type(topt2)){
s=({struct Cyc_Set_Set*_Tmp3=s;Cyc_Set_insert(_Tmp3,Cyc_AssnDef_slte(t1,t2));});
s=({struct Cyc_Set_Set*_Tmp3=s;Cyc_Set_insert(_Tmp3,Cyc_AssnDef_slte(t2,t1));});
s=({struct Cyc_Set_Set*_Tmp3=s;Cyc_Set_insert(_Tmp3,Cyc_AssnDef_ulte(t1,t2));});
s=({struct Cyc_Set_Set*_Tmp3=s;Cyc_Set_insert(_Tmp3,Cyc_AssnDef_ulte(t2,t1));});}
# 1962
goto _LLB;}case Cyc_AssnDef_SLt:
# 1964
 s=({struct Cyc_Set_Set*_Tmp3=s;Cyc_Set_insert(_Tmp3,Cyc_AssnDef_slte(t1,t2));});
goto _LLB;case Cyc_AssnDef_ULt:
# 1967
 s=({struct Cyc_Set_Set*_Tmp3=s;Cyc_Set_insert(_Tmp3,Cyc_AssnDef_ulte(t1,t2));});
goto _LLB;default:
 goto _LLB;}_LLB:;
# 1971
goto _LL0;}}_LL0:;}
# 1973
({struct Cyc_Set_Set**_Tmp0=({struct Cyc_Set_Set**_Tmp1=_cycalloc(sizeof(struct Cyc_Set_Set*));*_Tmp1=s;_Tmp1;});(*ahinfo)->widened_set=_Tmp0;});
return s;}}
# 1978
void*Cyc_AssnDef_widen(void*a){
# 1980
struct Cyc_Set_Set*sopt=Cyc_AssnDef_widen_it(a);
if(sopt==0)return(void*)& Cyc_AssnDef_false_assn;{
void*res=Cyc_Set_fold(Cyc_AssnDef_and,sopt,(void*)& Cyc_AssnDef_true_assn);
return res;}}
# 1986
static void*Cyc_AssnDef_subst_assn(struct Cyc_Dict_Dict dict,void*a,struct Cyc_Hashtable_Table*assn_h,struct Cyc_Hashtable_Table*term_h){
# 1989
void**a1=Cyc_Hashtable_lookup_opt(assn_h,a);
if(a1!=0)
# 1995
return*a1;{
# 1997
void*res;
{void*_Tmp0;enum Cyc_AssnDef_Primreln _Tmp1;void*_Tmp2;switch(*((int*)a)){case 0:
 goto _LL4;case 1: _LL4:
 res=a;goto _LL0;case 2: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp1=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp1;void*t2=_Tmp0;
# 2002
void*s1=Cyc_AssnDef_subst_term(dict,t1,term_h);
void*s2=Cyc_AssnDef_subst_term(dict,t2,term_h);
res=Cyc_AssnDef_prim(s1,p,s2);
goto _LL0;}case 3: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 2007
void*b1=Cyc_AssnDef_subst_assn(dict,a1,assn_h,term_h);
void*b2=Cyc_AssnDef_subst_assn(dict,a2,assn_h,term_h);
res=Cyc_AssnDef_and(b1,b2);
goto _LL0;}default: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 2012
void*b1=Cyc_AssnDef_subst_assn(dict,a1,assn_h,term_h);
void*b2=Cyc_AssnDef_subst_assn(dict,a2,assn_h,term_h);
res=Cyc_AssnDef_or(b1,b2);
goto _LL0;}}_LL0:;}
# 2017
Cyc_Hashtable_insert(assn_h,a,res);
return res;}}
# 2021
void*Cyc_AssnDef_subst_a(struct Cyc_Dict_Dict dict,void*a){
# 2024
struct Cyc_Hashtable_Table*assn_h=Cyc_Hashtable_create(107,Cyc_Core_ptrcmp,Cyc_AssnDef_hash_ptr);
struct Cyc_Hashtable_Table*term_h=Cyc_Hashtable_create(137,Cyc_Core_ptrcmp,Cyc_AssnDef_hash_ptr);
return Cyc_AssnDef_subst_assn(dict,a,assn_h,term_h);}
# 2041 "assndef.cyc"
static int Cyc_AssnDef_simple_prv(struct Cyc_Set_Set*ctxt,void*a){
while(1){
{void*_Tmp0;enum Cyc_AssnDef_Primreln _Tmp1;void*_Tmp2;switch(*((int*)a)){case 2: _Tmp2=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f1;_Tmp1=((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f2;_Tmp0=(void*)((struct Cyc_AssnDef_Prim_AssnDef_Assn_struct*)a)->f3;{void*t1=_Tmp2;enum Cyc_AssnDef_Primreln p=_Tmp1;void*t2=_Tmp0;
# 2045
if(Cyc_Set_member(ctxt,a))return 1;
# 2052
switch((int)p){case Cyc_AssnDef_Neq:
# 2054
 return((({struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_ult(t2,t1));})||({
struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_ult(t1,t2));}))||({
struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_slt(t2,t1));}))||({
struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_slt(t1,t2));});case Cyc_AssnDef_SLte:
# 2059
 return({struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_slt(t1,t2));})||({
struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_eq(t1,t2));});case Cyc_AssnDef_ULte:
# 2062
 return({struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_ult(t1,t2));})||({
struct Cyc_Set_Set*_Tmp3=ctxt;Cyc_Set_member(_Tmp3,Cyc_AssnDef_eq(t1,t2));});default:
 return 0;};}case 0:
# 2066
 return 1;case 1:
 return 0;case 3: _Tmp2=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_And_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 2069
if(!Cyc_AssnDef_simple_prv(ctxt,a1))
return 0;
# 2075
a=a2;
continue;}default: _Tmp2=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f1;_Tmp0=(void*)((struct Cyc_AssnDef_Or_AssnDef_Assn_struct*)a)->f2;{void*a1=_Tmp2;void*a2=_Tmp0;
# 2078
if(Cyc_AssnDef_simple_prv(ctxt,a1))return 1;
a=a2;
continue;}};}
# 2043
1U;}}
# 2088
int Cyc_AssnDef_simple_prove(void*ctxt,void*a){
if(ctxt==a)return 1;{
struct Cyc_Set_Set*sopt=Cyc_AssnDef_widen_it(ctxt);
if(sopt==0)return 1;
return Cyc_AssnDef_simple_prv(sopt,a);}}
# 2095
struct Cyc_Set_Set*Cyc_AssnDef_assnfn_fr_logicvar(struct Cyc_AssnDef_AssnFn*af){
struct Cyc_Set_Set*fvs=Cyc_AssnDef_assn_fr_logicvar(af->assn);
{struct Cyc_List_List*as=af->actuals;for(0;as!=0;as=as->tl){
fvs=Cyc_Set_delete(fvs,(void*)as->hd);}}
return fvs;}
# 2102
static struct _fat_ptr Cyc_AssnDef_assnfn2string(struct Cyc_AssnDef_AssnFn*af){
if(af->actuals==0)return Cyc_AssnDef_assn2string(af->assn);{
struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,({struct _fat_ptr _Tmp2=Cyc_AssnDef_term2string((void*)af->actuals->hd);_Tmp1.f1=_Tmp2;});_Tmp1;});struct Cyc_String_pa_PrintArg_struct _Tmp1=({struct Cyc_String_pa_PrintArg_struct _Tmp2;_Tmp2.tag=0,({struct _fat_ptr _Tmp3=Cyc_AssnDef_assnfn2string(({struct Cyc_AssnDef_AssnFn*_Tmp4=_cycalloc(sizeof(struct Cyc_AssnDef_AssnFn));_Tmp4->actuals=_check_null(af->actuals)->tl,_Tmp4->assn=af->assn;_Tmp4;}));_Tmp2.f1=_Tmp3;});_Tmp2;});void*_Tmp2[2];_Tmp2[0]=& _Tmp0,_Tmp2[1]=& _Tmp1;return Cyc_aprintf(_tag_fat("/\\ %s .\n%s",sizeof(char),11U),_tag_fat(_Tmp2,sizeof(void*),2));}}
# 2106
struct _fat_ptr Cyc_AssnDef_existassnfn2string(struct Cyc_AssnDef_ExistAssnFn*eaf){
return Cyc_AssnDef_assnfn2string(eaf->af);}
# 2112
struct Cyc_AssnDef_ExistAssnFn*Cyc_AssnDef_assnmap2existassnfn(struct Cyc_AssnDef_AssnMap am,struct Cyc_List_List*vds){
struct Cyc_List_List*actuals=0;
for(1;vds!=0;vds=vds->tl){
if((struct Cyc_Absyn_Vardecl*)vds->hd!=0){
struct _tuple13 _Tmp0=Cyc_AssnDef_lookup_var_map((struct Cyc_Absyn_Vardecl*)vds->hd,am);void*_Tmp1;_Tmp1=_Tmp0.f0;{void*v=_Tmp1;
if(*((int*)v)==2)
goto _LL3;else{
({int(*_Tmp2)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp2;})(_tag_fat("term to be bound is not a logic var",sizeof(char),36U),_tag_fat(0U,sizeof(void*),0));}_LL3:;
# 2121
actuals=({struct Cyc_List_List*_Tmp2=_cycalloc(sizeof(struct Cyc_List_List));_Tmp2->hd=v,_Tmp2->tl=actuals;_Tmp2;});}}else{
# 2123
void*x;
if((struct Cyc_Absyn_Vardecl*)vds->hd==0)
x=Cyc_AssnDef_fresh_var(0,0);else{
# 2127
x=Cyc_AssnDef_fresh_var((struct Cyc_Absyn_Vardecl*)vds->hd,((struct Cyc_Absyn_Vardecl*)vds->hd)->type);}
actuals=({struct Cyc_List_List*_Tmp0=_cycalloc(sizeof(struct Cyc_List_List));_Tmp0->hd=x,_Tmp0->tl=actuals;_Tmp0;});}}
# 2131
actuals=Cyc_List_imp_rev(actuals);{
# 2133
struct Cyc_AssnDef_AssnFn*af;af=_cycalloc(sizeof(struct Cyc_AssnDef_AssnFn)),af->actuals=actuals,af->assn=am.assn;{
# 2135
struct Cyc_Set_Set*fvs=Cyc_AssnDef_assnfn_fr_logicvar(af);
struct Cyc_AssnDef_ExistAssnFn*_Tmp0=_cycalloc(sizeof(struct Cyc_AssnDef_ExistAssnFn));_Tmp0->af=af,_Tmp0->existvars=fvs;return _Tmp0;}}}
# 2143
struct Cyc_AssnDef_ExistAssnFn*Cyc_AssnDef_bound_ts_in_assn(void*a,struct Cyc_List_List*ts){
# 2145
struct Cyc_List_List*vs=0;
for(1;ts!=0;ts=ts->tl){
void*_Tmp0=(void*)ts->hd;if(*((int*)_Tmp0)==2){
# 2151
int occured=0;
{struct Cyc_List_List*xs=vs;for(0;xs!=0;xs=xs->tl){
if(Cyc_AssnDef_termcmp((void*)ts->hd,(void*)xs->hd)==0){
occured=1;
break;}}}
# 2158
if(!occured)vs=({struct Cyc_List_List*_Tmp1=_cycalloc(sizeof(struct Cyc_List_List));_Tmp1->hd=(void*)ts->hd,_Tmp1->tl=vs;_Tmp1;});else{
# 2160
void*v=Cyc_AssnDef_fresh_var(0,Cyc_AssnDef_get_term_type((void*)ts->hd));
a=({void*_Tmp1=a;Cyc_AssnDef_and(_Tmp1,Cyc_AssnDef_eq(v,(void*)ts->hd));});
vs=({struct Cyc_List_List*_Tmp1=_cycalloc(sizeof(struct Cyc_List_List));_Tmp1->hd=v,_Tmp1->tl=vs;_Tmp1;});}
# 2164
goto _LL0;}else{
# 2166
void*v=Cyc_AssnDef_fresh_var(0,Cyc_AssnDef_get_term_type((void*)ts->hd));
a=({void*_Tmp1=a;Cyc_AssnDef_and(_Tmp1,Cyc_AssnDef_eq(v,(void*)ts->hd));});
vs=({struct Cyc_List_List*_Tmp1=_cycalloc(sizeof(struct Cyc_List_List));_Tmp1->hd=v,_Tmp1->tl=vs;_Tmp1;});
goto _LL0;}_LL0:;}
# 2172
vs=Cyc_List_imp_rev(vs);{
# 2174
struct Cyc_AssnDef_AssnFn*af;af=_cycalloc(sizeof(struct Cyc_AssnDef_AssnFn)),af->actuals=vs,af->assn=a;{
# 2176
struct Cyc_Set_Set*fvs=Cyc_AssnDef_assnfn_fr_logicvar(af);
struct Cyc_AssnDef_ExistAssnFn*_Tmp0=_cycalloc(sizeof(struct Cyc_AssnDef_ExistAssnFn));_Tmp0->af=af,_Tmp0->existvars=fvs;return _Tmp0;}}}
# 2180
static struct Cyc_Dict_Dict*Cyc_AssnDef_insertnewmap(void*t,struct Cyc_Dict_Dict*dict){
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict _Tmp1=*dict;void*_Tmp2=t;Cyc_Dict_insert(_Tmp1,_Tmp2,Cyc_AssnDef_fresh_var(0,Cyc_AssnDef_get_term_type(t)));});*dict=_Tmp0;});
return dict;}
# 2187
void*Cyc_AssnDef_existassnfn2assn(struct Cyc_AssnDef_ExistAssnFn*eaf,struct Cyc_List_List*ts){
struct Cyc_Dict_Dict dict=Cyc_AssnDef_empty_term_dict();
# 2190
dict=*({struct Cyc_Dict_Dict*(*_Tmp0)(struct Cyc_Dict_Dict*(*)(void*,struct Cyc_Dict_Dict*),struct Cyc_Set_Set*,struct Cyc_Dict_Dict*)=(struct Cyc_Dict_Dict*(*)(struct Cyc_Dict_Dict*(*)(void*,struct Cyc_Dict_Dict*),struct Cyc_Set_Set*,struct Cyc_Dict_Dict*))Cyc_Set_fold;_Tmp0;})(Cyc_AssnDef_insertnewmap,eaf->existvars,& dict);{
struct Cyc_List_List*vs=eaf->af->actuals;
void*a=eaf->af->assn;
# 2194
for(1;vs!=0 && ts!=0;(vs=vs->tl,ts=ts->tl)){
dict=Cyc_Dict_insert(dict,(void*)vs->hd,(void*)ts->hd);}
if(vs!=0 || ts!=0)
({int(*_Tmp0)(struct _fat_ptr,struct _fat_ptr)=(int(*)(struct _fat_ptr,struct _fat_ptr))Cyc_Warn_impos;_Tmp0;})(_tag_fat("wrong number of arguments to existassnfn2assn",sizeof(char),46U),_tag_fat(0U,sizeof(void*),0));
# 2200
return Cyc_AssnDef_subst_a(dict,a);}}
# 2204
static struct Cyc_List_List*Cyc_AssnDef_m2string(struct Cyc_Absyn_Vardecl*vd,void*value,struct Cyc_List_List*stringlist){
struct _fat_ptr res=({struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,({struct _fat_ptr _Tmp2=Cyc_Absynpp_qvar2string(vd->name);_Tmp1.f1=_Tmp2;});_Tmp1;});struct Cyc_String_pa_PrintArg_struct _Tmp1=({struct Cyc_String_pa_PrintArg_struct _Tmp2;_Tmp2.tag=0,({struct _fat_ptr _Tmp3=Cyc_AssnDef_term2string(value);_Tmp2.f1=_Tmp3;});_Tmp2;});void*_Tmp2[2];_Tmp2[0]=& _Tmp0,_Tmp2[1]=& _Tmp1;Cyc_aprintf(_tag_fat("%s == %s",sizeof(char),9U),_tag_fat(_Tmp2,sizeof(void*),2));});
struct Cyc_List_List*_Tmp0=_cycalloc(sizeof(struct Cyc_List_List));({struct _fat_ptr*_Tmp1=({struct _fat_ptr*_Tmp2=_cycalloc(sizeof(struct _fat_ptr));*_Tmp2=res;_Tmp2;});_Tmp0->hd=_Tmp1;}),_Tmp0->tl=stringlist;return _Tmp0;}
# 2209
struct _fat_ptr Cyc_AssnDef_map2string(struct Cyc_Dict_Dict m){
struct Cyc_List_List*stringlist=({struct Cyc_List_List*(*_Tmp0)(struct Cyc_List_List*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_List_List*),struct Cyc_Dict_Dict,struct Cyc_List_List*)=(struct Cyc_List_List*(*)(struct Cyc_List_List*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_List_List*),struct Cyc_Dict_Dict,struct Cyc_List_List*))Cyc_Dict_fold;_Tmp0;})(Cyc_AssnDef_m2string,m,0);
struct _fat_ptr s;
if(stringlist==0)return Cyc_aprintf(_tag_fat(" ",sizeof(char),2U),_tag_fat(0U,sizeof(void*),0));else{
s=({struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,_Tmp1.f1=*((struct _fat_ptr*)stringlist->hd);_Tmp1;});void*_Tmp1[1];_Tmp1[0]=& _Tmp0;Cyc_aprintf(_tag_fat("%s",sizeof(char),3U),_tag_fat(_Tmp1,sizeof(void*),1));});}
while(stringlist->tl!=0){
stringlist=stringlist->tl;
s=({struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,_Tmp1.f1=s;_Tmp1;});struct Cyc_String_pa_PrintArg_struct _Tmp1=({struct Cyc_String_pa_PrintArg_struct _Tmp2;_Tmp2.tag=0,_Tmp2.f1=*((struct _fat_ptr*)stringlist->hd);_Tmp2;});void*_Tmp2[2];_Tmp2[0]=& _Tmp0,_Tmp2[1]=& _Tmp1;Cyc_aprintf(_tag_fat("%s && %s",sizeof(char),9U),_tag_fat(_Tmp2,sizeof(void*),2));});
# 2215
1U;}
# 2218
return s;}
# 2222
struct _fat_ptr Cyc_AssnDef_assnmap2string(struct Cyc_AssnDef_AssnMap am){
struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,({struct _fat_ptr _Tmp2=Cyc_AssnDef_map2string(am.map);_Tmp1.f1=_Tmp2;});_Tmp1;});struct Cyc_String_pa_PrintArg_struct _Tmp1=({struct Cyc_String_pa_PrintArg_struct _Tmp2;_Tmp2.tag=0,({struct _fat_ptr _Tmp3=Cyc_AssnDef_assn2string(am.assn);_Tmp2.f1=_Tmp3;});_Tmp2;});void*_Tmp2[2];_Tmp2[0]=& _Tmp0,_Tmp2[1]=& _Tmp1;return Cyc_aprintf(_tag_fat("{%s}&&\n%s",sizeof(char),10U),_tag_fat(_Tmp2,sizeof(void*),2));}
# 2226
struct _fat_ptr Cyc_AssnDef_assnmap2dag(struct Cyc_AssnDef_AssnMap am){
struct Cyc_String_pa_PrintArg_struct _Tmp0=({struct Cyc_String_pa_PrintArg_struct _Tmp1;_Tmp1.tag=0,({struct _fat_ptr _Tmp2=Cyc_AssnDef_map2string(am.map);_Tmp1.f1=_Tmp2;});_Tmp1;});struct Cyc_String_pa_PrintArg_struct _Tmp1=({struct Cyc_String_pa_PrintArg_struct _Tmp2;_Tmp2.tag=0,({struct _fat_ptr _Tmp3=Cyc_AssnDef_assn2dag(am.assn);_Tmp2.f1=_Tmp3;});_Tmp2;});void*_Tmp2[2];_Tmp2[0]=& _Tmp0,_Tmp2[1]=& _Tmp1;return Cyc_aprintf(_tag_fat("{%s}\n%s",sizeof(char),8U),_tag_fat(_Tmp2,sizeof(void*),2));}
# 2230
static struct Cyc_Dict_Dict Cyc_AssnDef_empty_map (void){
static struct Cyc_Dict_Dict*mt=0;
if(mt==0){
struct Cyc_Dict_Dict d=({struct Cyc_Dict_Dict(*_Tmp0)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*))=(struct Cyc_Dict_Dict(*)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*)))Cyc_Dict_empty;_Tmp0;})(({int(*_Tmp0)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*)=(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*))Cyc_Core_ptrcmp;_Tmp0;}));
mt=({struct Cyc_Dict_Dict*_Tmp0=_cycalloc(sizeof(struct Cyc_Dict_Dict));*_Tmp0=d;_Tmp0;});
return d;}else{
# 2237
return*mt;}}
# 2240
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_false_assnmap (void){
struct Cyc_AssnDef_AssnMap _Tmp0;_Tmp0.assn=(void*)& Cyc_AssnDef_false_assn,({struct Cyc_Dict_Dict _Tmp1=Cyc_AssnDef_empty_map();_Tmp0.map=_Tmp1;});return _Tmp0;}
# 2244
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_true_assnmap (void){
struct Cyc_AssnDef_AssnMap _Tmp0;_Tmp0.assn=(void*)& Cyc_AssnDef_true_assn,({struct Cyc_Dict_Dict _Tmp1=Cyc_AssnDef_empty_map();_Tmp0.map=_Tmp1;});return _Tmp0;}
# 2251
struct _tuple13 Cyc_AssnDef_lookup_var_map(struct Cyc_Absyn_Vardecl*vd,struct Cyc_AssnDef_AssnMap am){
void**t=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(am.map,vd);
if(t!=0){struct _tuple13 _Tmp0;_Tmp0.f0=*t,_Tmp0.f1=am;return _Tmp0;}{
void*newt=Cyc_AssnDef_fresh_var(vd,vd->type);
struct Cyc_Dict_Dict newm=({struct Cyc_Dict_Dict(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp0;})(am.map,vd,newt);
struct _tuple13 _Tmp0;_Tmp0.f0=newt,_Tmp0.f1.assn=am.assn,_Tmp0.f1.map=newm;return _Tmp0;}}
# 2261
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_update_var_map(struct Cyc_Absyn_Vardecl*vd,void*newt,struct Cyc_AssnDef_AssnMap am){
struct Cyc_Dict_Dict newm=({struct Cyc_Dict_Dict(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp0;})(am.map,vd,newt);
struct Cyc_AssnDef_AssnMap _Tmp0;_Tmp0.assn=am.assn,_Tmp0.map=newm;return _Tmp0;}
# 2267
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_widen_assnmap(struct Cyc_AssnDef_AssnMap am){
struct Cyc_AssnDef_AssnMap _Tmp0;({void*_Tmp1=Cyc_AssnDef_widen(am.assn);_Tmp0.assn=_Tmp1;}),_Tmp0.map=am.map;return _Tmp0;}
# 2272
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_or_assnmap_assn(struct Cyc_AssnDef_AssnMap am,void*a){
struct Cyc_AssnDef_AssnMap _Tmp0;({void*_Tmp1=Cyc_AssnDef_or(am.assn,a);_Tmp0.assn=_Tmp1;}),_Tmp0.map=am.map;return _Tmp0;}
# 2277
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_and_assnmap_assn(struct Cyc_AssnDef_AssnMap am,void*a){
struct Cyc_AssnDef_AssnMap _Tmp0;({void*_Tmp1=Cyc_AssnDef_and(am.assn,a);_Tmp0.assn=_Tmp1;}),_Tmp0.map=am.map;return _Tmp0;}
# 2281
void*Cyc_AssnDef_merge(struct Cyc_Absyn_Vardecl*vd,void*t1,void*t2){
if(t1==t2)return t1;else{
return Cyc_AssnDef_fresh_var(vd,vd->type);}}struct _tuple20{struct Cyc_Hashtable_Table*f0;struct Cyc_Dict_Dict f1;};
# 2286
static void*Cyc_AssnDef_subst_term_internal(struct _tuple20*env,void*t){
return Cyc_AssnDef_subst_term(env->f1,t,env->f0);}
# 2290
static struct Cyc_AssnDef_AssnMap Cyc_AssnDef_subst_am(struct Cyc_Dict_Dict dict,struct Cyc_AssnDef_AssnMap am){
# 2293
struct Cyc_Hashtable_Table*assn_h=Cyc_Hashtable_create(107,Cyc_Core_ptrcmp,Cyc_AssnDef_hash_ptr);
struct Cyc_Hashtable_Table*term_h=Cyc_Hashtable_create(137,Cyc_Core_ptrcmp,Cyc_AssnDef_hash_ptr);
void*assn=Cyc_AssnDef_subst_assn(dict,am.assn,assn_h,term_h);
struct Cyc_Dict_Dict map=({struct Cyc_Dict_Dict(*_Tmp0)(void*(*)(struct _tuple20*,void*),struct _tuple20*,struct Cyc_Dict_Dict)=({struct Cyc_Dict_Dict(*_Tmp1)(void*(*)(struct _tuple20*,void*),struct _tuple20*,struct Cyc_Dict_Dict)=(struct Cyc_Dict_Dict(*)(void*(*)(struct _tuple20*,void*),struct _tuple20*,struct Cyc_Dict_Dict))Cyc_Dict_map_c;_Tmp1;});struct _tuple20*_Tmp1=({struct _tuple20*_Tmp2=_cycalloc(sizeof(struct _tuple20));_Tmp2->f0=term_h,_Tmp2->f1=dict;_Tmp2;});_Tmp0(Cyc_AssnDef_subst_term_internal,_Tmp1,am.map);});
struct Cyc_AssnDef_AssnMap _Tmp0;_Tmp0.assn=assn,_Tmp0.map=map;return _Tmp0;}struct Cyc_AssnDef_Accum{void*a1;void*a2;struct Cyc_Dict_Dict m1;struct Cyc_Dict_Dict m2;struct Cyc_Dict_Dict m;};
# 2307
static int Cyc_AssnDef_logicvar_in_map_internal(void*lvar,struct Cyc_Absyn_Vardecl*dummy,void*value,int in_map){
return in_map || Cyc_AssnDef_logicvar_in_term(lvar,value);}
# 2311
static int Cyc_AssnDef_logicvar_in_map(void*lv,struct Cyc_Dict_Dict m){
return({int(*_Tmp0)(int(*)(void*,struct Cyc_Absyn_Vardecl*,void*,int),void*,struct Cyc_Dict_Dict,int)=(int(*)(int(*)(void*,struct Cyc_Absyn_Vardecl*,void*,int),void*,struct Cyc_Dict_Dict,int))Cyc_Dict_fold_c;_Tmp0;})(Cyc_AssnDef_logicvar_in_map_internal,lv,m,0);}
# 2321
static void*Cyc_AssnDef_unify_term(struct Cyc_AssnDef_Accum*accum,void*ta,void*tb){
if(ta==tb)return ta;
{struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=ta,_Tmp1.f1=tb;_Tmp1;});unsigned _Tmp1;int _Tmp2;unsigned _Tmp3;int _Tmp4;void*_Tmp5;void*_Tmp6;void*_Tmp7;void*_Tmp8;enum Cyc_Absyn_Primop _Tmp9;void*_TmpA;void*_TmpB;enum Cyc_Absyn_Primop _TmpC;switch(*((int*)_Tmp0.f0)){case 3: if(*((int*)_Tmp0.f1)==3){_TmpC=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpB=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp9=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp8=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp7=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)_Tmp0.f1)->f3;if((int)((enum Cyc_Absyn_Primop)_TmpC)==(int)((enum Cyc_Absyn_Primop)_Tmp9)){enum Cyc_Absyn_Primop pa=_TmpC;void*ta1=_TmpB;void*topta=_TmpA;enum Cyc_Absyn_Primop pb=_Tmp9;void*tb1=_Tmp8;void*toptb=_Tmp7;
# 2325
void*t1=Cyc_AssnDef_unify_term(accum,ta1,tb1);
return Cyc_AssnDef_unop(pa,t1,topta);}else{goto _LL19;}}else{goto _LL19;}case 4: if(*((int*)_Tmp0.f1)==4){_TmpC=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpB=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp8=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f0)->f4;_Tmp9=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp6=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f3;_Tmp5=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)_Tmp0.f1)->f4;if((int)((enum Cyc_Absyn_Primop)_TmpC)==(int)((enum Cyc_Absyn_Primop)_Tmp9)){enum Cyc_Absyn_Primop pa=_TmpC;void*ta1=_TmpB;void*ta2=_TmpA;void*topta=_Tmp8;enum Cyc_Absyn_Primop pb=_Tmp9;void*tb1=_Tmp7;void*tb2=_Tmp6;void*toptb=_Tmp5;
# 2328
void*t1=Cyc_AssnDef_unify_term(accum,ta1,tb1);
void*t2=Cyc_AssnDef_unify_term(accum,ta2,tb2);
return Cyc_AssnDef_binop(pa,t1,t2,topta);}else{goto _LL19;}}else{goto _LL19;}case 5: if(*((int*)_Tmp0.f1)==5){_TmpB=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp7=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)_Tmp0.f1)->f2;{void*atype=_TmpB;void*ta1=_TmpA;void*btype=_Tmp8;void*tb1=_Tmp7;
# 2332
if(!Cyc_Unify_unify(atype,btype))goto _LL0;{
void*t1=Cyc_AssnDef_unify_term(accum,ta1,tb1);
return Cyc_AssnDef_cast(atype,t1);}}}else{goto _LL19;}case 6: if(*((int*)_Tmp0.f1)==6){_TmpB=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp7=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)_Tmp0.f1)->f3;{void*ma=_TmpB;void*aa=_TmpA;void*ta=_Tmp8;void*mb=_Tmp7;void*ab=_Tmp6;void*tb=_Tmp5;
# 2336
void*m=Cyc_AssnDef_unify_term(accum,ma,mb);
void*a=Cyc_AssnDef_unify_term(accum,aa,ab);
return Cyc_AssnDef_select(m,a,ta);}}else{goto _LL19;}case 7: if(*((int*)_Tmp0.f1)==7){_TmpB=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp7=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)_Tmp0.f1)->f3;{void*ma=_TmpB;void*aa=_TmpA;void*va=_Tmp8;void*mb=_Tmp7;void*ab=_Tmp6;void*vb=_Tmp5;
# 2340
if(aa==ab){
void*m=Cyc_AssnDef_unify_term(accum,ma,mb);
void*v=Cyc_AssnDef_unify_term(accum,va,vb);
return Cyc_AssnDef_update(m,aa,v);}else{
# 2345
void*t1=({void*_TmpD=({void*_TmpE=ma;void*_TmpF=ab;Cyc_AssnDef_update(_TmpE,_TmpF,({void*_Tmp10=ma;void*_Tmp11=ab;Cyc_AssnDef_select(_Tmp10,_Tmp11,Cyc_AssnDef_get_term_type(vb));}));});void*_TmpE=aa;Cyc_AssnDef_update(_TmpD,_TmpE,va);});
void*t2=({void*_TmpD=Cyc_AssnDef_update(mb,ab,vb);void*_TmpE=aa;Cyc_AssnDef_update(_TmpD,_TmpE,({void*_TmpF=Cyc_AssnDef_update(mb,ab,vb);void*_Tmp10=aa;Cyc_AssnDef_select(_TmpF,_Tmp10,Cyc_AssnDef_get_term_type(va));}));});
return Cyc_AssnDef_unify_term(accum,t1,t2);}}}else{goto _LL19;}case 8: if(*((int*)_Tmp0.f1)==8){_Tmp4=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp3=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpB=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f0)->f3;_TmpA=(void*)((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f0)->f4;_Tmp2=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp8=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f1)->f3;_Tmp7=(void*)((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)_Tmp0.f1)->f4;{int aisu=_Tmp4;unsigned atag=_Tmp3;struct Cyc_List_List*ats=_TmpB;void*atopt=_TmpA;int bisu=_Tmp2;unsigned btag=_Tmp1;struct Cyc_List_List*bts=_Tmp8;void*btopt=_Tmp7;
# 2356
if((aisu!=bisu || atag!=btag)||({int _TmpD=Cyc_List_length(ats);_TmpD!=Cyc_List_length(bts);}))goto _LL0;{
struct Cyc_List_List*ts=0;
for(1;ats!=0 && bts!=0;(ats=ats->tl,bts=bts->tl)){
ts=({struct Cyc_List_List*_TmpD=_cycalloc(sizeof(struct Cyc_List_List));({void*_TmpE=Cyc_AssnDef_unify_term(accum,(void*)ats->hd,(void*)bts->hd);_TmpD->hd=_TmpE;}),_TmpD->tl=ts;_TmpD;});}{
int _TmpD=aisu;unsigned _TmpE=atag;struct Cyc_List_List*_TmpF=Cyc_List_imp_rev(ts);return Cyc_AssnDef_aggr(_TmpD,_TmpE,_TmpF,atopt);}}}}else{goto _LL19;}case 9: if(*((int*)_Tmp0.f1)==9){_TmpB=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp3=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp8=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp7=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)_Tmp0.f1)->f3;if((unsigned)_Tmp3==(unsigned)_Tmp1){void*at=_TmpB;unsigned ai=_Tmp3;void*atopt=_TmpA;void*bt=_Tmp8;unsigned bi=_Tmp1;void*btopt=_Tmp7;
# 2362
void*t=Cyc_AssnDef_unify_term(accum,at,bt);
return Cyc_AssnDef_proj(t,ai,atopt);}else{goto _LL19;}}else{goto _LL19;}case 10: if(*((int*)_Tmp0.f1)==10){_TmpB=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp3=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp8=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp7=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)_Tmp0.f1)->f3;{void*at=_TmpB;unsigned ai=_Tmp3;void*av=_TmpA;void*bt=_Tmp8;unsigned bi=_Tmp1;void*bv=_Tmp7;
# 2365
if(ai==bi){
void*t=Cyc_AssnDef_unify_term(accum,at,bt);
void*v=Cyc_AssnDef_unify_term(accum,av,bv);
return Cyc_AssnDef_aggr_update(t,ai,v);}else{
# 2370
void*t1=({void*_TmpD=({void*_TmpE=ta;unsigned _TmpF=bi;Cyc_AssnDef_aggr_update(_TmpE,_TmpF,({void*_Tmp10=ta;unsigned _Tmp11=bi;Cyc_AssnDef_proj(_Tmp10,_Tmp11,Cyc_AssnDef_get_term_type(bv));}));});unsigned _TmpE=ai;Cyc_AssnDef_aggr_update(_TmpD,_TmpE,av);});
void*t2=({void*_TmpD=Cyc_AssnDef_aggr_update(tb,bi,bv);unsigned _TmpE=ai;Cyc_AssnDef_aggr_update(_TmpD,_TmpE,({void*_TmpF=Cyc_AssnDef_aggr_update(tb,bi,bv);unsigned _Tmp10=ai;Cyc_AssnDef_proj(_TmpF,_Tmp10,Cyc_AssnDef_get_term_type(av));}));});
return Cyc_AssnDef_unify_term(accum,t1,t2);}}}else{goto _LL19;}case 11: if(*((int*)_Tmp0.f1)==11){_TmpB=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp7=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)_Tmp0.f1)->f3;if((int)((struct Cyc_Absyn_Vardecl*)_TmpB)==(int)((struct Cyc_Absyn_Vardecl*)_Tmp7)){struct Cyc_Absyn_Vardecl*ax=_TmpB;void*ai=_TmpA;void*atopt=_Tmp8;struct Cyc_Absyn_Vardecl*bx=_Tmp7;void*bi=_Tmp6;void*btopt=_Tmp5;
# 2375
void*i=Cyc_AssnDef_unify_term(accum,ai,bi);
return Cyc_AssnDef_addr(ax,i);}else{goto _LL19;}}else{goto _LL19;}case 13: if(*((int*)_Tmp0.f1)==13){_TmpB=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f1;_Tmp3=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f2;_TmpA=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp8=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp1=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp7=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)_Tmp0.f1)->f3;if((unsigned)_Tmp3==(unsigned)_Tmp1){void*at=_TmpB;unsigned ai=_Tmp3;void*atopt=_TmpA;void*bt=_Tmp8;unsigned bi=_Tmp1;void*btopt=_Tmp7;
# 2381
void*t=Cyc_AssnDef_unify_term(accum,at,bt);
return Cyc_AssnDef_offsetf(t,ai,atopt);}else{goto _LL19;}}else{goto _LL19;}case 14: if(*((int*)_Tmp0.f1)==14){_TmpB=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f2;_Tmp8=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f0)->f3;_Tmp7=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)_Tmp0.f1)->f3;{void*at=_TmpB;void*ai=_TmpA;void*atopt=_Tmp8;void*bt=_Tmp7;void*bi=_Tmp6;void*btopt=_Tmp5;
# 2384
void*t=Cyc_AssnDef_unify_term(accum,at,bt);
void*i=Cyc_AssnDef_unify_term(accum,ai,bi);
return Cyc_AssnDef_offseti(t,i,atopt);}}else{goto _LL19;}case 15: if(*((int*)_Tmp0.f1)==15){_TmpB=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)_Tmp0.f0)->f1;_TmpA=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)_Tmp0.f1)->f1;{void*at=_TmpB;void*bt=_TmpA;
# 2388
void*t=Cyc_AssnDef_unify_term(accum,at,bt);
return Cyc_AssnDef_tagof_tm(t);}}else{goto _LL19;}default: _LL19:
 goto _LL0;}_LL0:;}{
# 2392
void*topta=Cyc_AssnDef_get_term_type(ta);
void*toptb=Cyc_AssnDef_get_term_type(tb);
void*topt=0;
if((topta!=0 && toptb!=0)&& Cyc_Unify_unify(topta,toptb))
# 2397
topt=topta;{
void*v=Cyc_AssnDef_fresh_var(0,topt);
({void*_Tmp0=({void*_Tmp1=accum->a1;Cyc_AssnDef_and(_Tmp1,Cyc_AssnDef_eq(v,ta));});accum->a1=_Tmp0;});
({void*_Tmp0=({void*_Tmp1=accum->a2;Cyc_AssnDef_and(_Tmp1,Cyc_AssnDef_eq(v,tb));});accum->a2=_Tmp0;});
return v;}}}
# 2408
static struct Cyc_AssnDef_Accum*Cyc_AssnDef_foldm1(struct Cyc_Absyn_Vardecl*vd,void*t,struct Cyc_AssnDef_Accum*accum){
void**t2=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(accum->m2,vd);
# 2412
if(t2==0){
if(*((int*)t)==2){
# 2415
if(!Cyc_AssnDef_logicvar_in_assn(t,accum->a2)&& !Cyc_AssnDef_logicvar_in_map(t,accum->m2)){
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m2,vd,t);accum->m2=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m,vd,t);accum->m=_Tmp0;});
return accum;}
# 2420
goto _LL0;}else{
# 2422
goto _LL0;}_LL0:;{
# 2424
void*v=Cyc_AssnDef_fresh_var(vd,vd->type);
({void*_Tmp0=({void*_Tmp1=accum->a1;Cyc_AssnDef_and(_Tmp1,Cyc_AssnDef_eq(v,t));});accum->a1=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m1,vd,v);accum->m1=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m2,vd,v);accum->m2=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m,vd,v);accum->m=_Tmp0;});
return accum;}}
# 2432
if(t==*t2){
# 2435
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m,vd,t);accum->m=_Tmp0;});
return accum;}
# 2440
{struct _tuple15 _Tmp0=({struct _tuple15 _Tmp1;_Tmp1.f0=t,_Tmp1.f1=*t2;_Tmp1;});if(*((int*)_Tmp0.f0)==2){if(*((int*)_Tmp0.f1)==2){
# 2442
if(!Cyc_AssnDef_logicvar_in_assn(t,accum->a2)&& !Cyc_AssnDef_logicvar_in_map(t,accum->m2)){
# 2444
({void*_Tmp1=({void*_Tmp2=accum->a2;Cyc_AssnDef_and(_Tmp2,Cyc_AssnDef_eq(t,*t2));});accum->a2=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m2,vd,t);accum->m2=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m,vd,t);accum->m=_Tmp1;});
return accum;}else{
if(!Cyc_AssnDef_logicvar_in_assn(*t2,accum->a1)&& !Cyc_AssnDef_logicvar_in_map(*t2,accum->m1)){
# 2450
({void*_Tmp1=({void*_Tmp2=accum->a1;Cyc_AssnDef_and(_Tmp2,Cyc_AssnDef_eq(t,*t2));});accum->a1=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m1,vd,*t2);accum->m1=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m,vd,*t2);accum->m=_Tmp1;});
return accum;}}
# 2455
goto _LL5;}else{
# 2457
if(!Cyc_AssnDef_logicvar_in_assn(t,accum->a2)&& !Cyc_AssnDef_logicvar_in_map(t,accum->m2)){
# 2459
({void*_Tmp1=({void*_Tmp2=accum->a2;Cyc_AssnDef_and(_Tmp2,Cyc_AssnDef_eq(t,*t2));});accum->a2=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m2,vd,t);accum->m2=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m,vd,t);accum->m=_Tmp1;});
return accum;}
# 2464
goto _LL5;}}else{if(*((int*)_Tmp0.f1)==2){
# 2466
if(!Cyc_AssnDef_logicvar_in_assn(*t2,accum->a1)&& !Cyc_AssnDef_logicvar_in_map(*t2,accum->m1)){
# 2468
({void*_Tmp1=({void*_Tmp2=accum->a1;Cyc_AssnDef_and(_Tmp2,Cyc_AssnDef_eq(t,*t2));});accum->a1=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m1,vd,*t2);accum->m1=_Tmp1;});
({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict(*_Tmp2)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp2;})(accum->m,vd,*t2);accum->m=_Tmp1;});
return accum;}
# 2473
goto _LL5;}else{
# 2475
goto _LL5;}}_LL5:;}{
# 2477
void*newt=Cyc_AssnDef_unify_term(accum,t,*t2);
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m1,vd,newt);accum->m1=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m2,vd,newt);accum->m2=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m,vd,newt);accum->m=_Tmp0;});
return accum;}}
# 2488
static struct Cyc_AssnDef_Accum*Cyc_AssnDef_foldm2(struct Cyc_Absyn_Vardecl*vd,void*t,struct Cyc_AssnDef_Accum*accum){
{
# 2494
void*v=Cyc_AssnDef_fresh_var(vd,vd->type);
({void*_Tmp0=({void*_Tmp1=Cyc_AssnDef_eq(v,t);Cyc_AssnDef_and(_Tmp1,accum->a2);});accum->a2=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->m,vd,v);accum->m=_Tmp0;});
return accum;};}
# 2501
struct Cyc_Dict_Dict Cyc_AssnDef_empty_term_dict (void){
static struct Cyc_Dict_Dict*term_dict=0;
if(term_dict==0)
term_dict=({struct Cyc_Dict_Dict*_Tmp0=_cycalloc(sizeof(struct Cyc_Dict_Dict));({struct Cyc_Dict_Dict _Tmp1=Cyc_Dict_empty(Cyc_Core_ptrcmp);*_Tmp0=_Tmp1;});_Tmp0;});
# 2506
return*term_dict;}
# 2514
struct _tuple14 Cyc_AssnDef_unify_var_maps(struct Cyc_AssnDef_AssnMap am1,struct Cyc_AssnDef_AssnMap am2){
if(am1.assn==(void*)& Cyc_AssnDef_false_assn){struct _tuple14 _Tmp0;_Tmp0.f0=am1.assn,_Tmp0.f1=am2.assn,_Tmp0.f2=am2.map;return _Tmp0;}
if(am2.assn==(void*)& Cyc_AssnDef_false_assn){struct _tuple14 _Tmp0;_Tmp0.f0=am1.assn,_Tmp0.f1=am2.assn,_Tmp0.f2=am1.map;return _Tmp0;}{
struct Cyc_AssnDef_Accum accum=({struct Cyc_AssnDef_Accum _Tmp0;_Tmp0.a1=am1.assn,_Tmp0.a2=am2.assn,_Tmp0.m1=am1.map,_Tmp0.m2=am2.map,({struct Cyc_Dict_Dict _Tmp1=Cyc_AssnDef_empty_map();_Tmp0.m=_Tmp1;});_Tmp0;});
({struct Cyc_AssnDef_Accum*(*_Tmp0)(struct Cyc_AssnDef_Accum*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_AssnDef_Accum*),struct Cyc_Dict_Dict,struct Cyc_AssnDef_Accum*)=(struct Cyc_AssnDef_Accum*(*)(struct Cyc_AssnDef_Accum*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_AssnDef_Accum*),struct Cyc_Dict_Dict,struct Cyc_AssnDef_Accum*))Cyc_Dict_fold;_Tmp0;})(Cyc_AssnDef_foldm1,am1.map,& accum);
({struct Cyc_AssnDef_Accum*(*_Tmp0)(struct Cyc_AssnDef_Accum*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_AssnDef_Accum*),struct Cyc_Dict_Dict,struct Cyc_AssnDef_Accum*)=({struct Cyc_AssnDef_Accum*(*_Tmp1)(struct Cyc_AssnDef_Accum*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_AssnDef_Accum*),struct Cyc_Dict_Dict,struct Cyc_AssnDef_Accum*)=(struct Cyc_AssnDef_Accum*(*)(struct Cyc_AssnDef_Accum*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_AssnDef_Accum*),struct Cyc_Dict_Dict,struct Cyc_AssnDef_Accum*))Cyc_Dict_fold;_Tmp1;});_Tmp0(Cyc_AssnDef_foldm2,Cyc_Dict_difference(am2.map,am1.map),& accum);});{
struct _tuple14 _Tmp0;_Tmp0.f0=accum.a1,_Tmp0.f1=accum.a2,_Tmp0.f2=accum.m;return _Tmp0;}}}
# 2524
static struct Cyc_Dict_Dict*Cyc_AssnDef_collect_subst(struct Cyc_Dict_Dict*map2,struct Cyc_Absyn_Vardecl*vd,void*value,struct Cyc_Dict_Dict*dict){
if(*((int*)value)==2){
# 2530
void**v=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(*map2,vd);
# 2533
if(Cyc_Dict_lookup_opt(*dict,value)==0){
if(v!=0 &&*v==value){
struct Cyc_Dict_Dict*_Tmp0=_cycalloc(sizeof(struct Cyc_Dict_Dict));({struct Cyc_Dict_Dict _Tmp1=Cyc_Dict_insert(*dict,value,*v);*_Tmp0=_Tmp1;});return _Tmp0;}{
struct Cyc_Dict_Dict*_Tmp0=_cycalloc(sizeof(struct Cyc_Dict_Dict));({struct Cyc_Dict_Dict _Tmp1=({struct Cyc_Dict_Dict _Tmp2=*dict;void*_Tmp3=value;Cyc_Dict_insert(_Tmp2,_Tmp3,Cyc_AssnDef_fresh_var(vd,vd->type));});*_Tmp0=_Tmp1;});return _Tmp0;}}
# 2538
goto _LL0;}else{
# 2540
goto _LL0;}_LL0:;
# 2542
return dict;}
# 2552 "assndef.cyc"
struct _tuple14 Cyc_AssnDef_unify_var_maps_subst(struct Cyc_AssnDef_AssnMap am1,struct Cyc_AssnDef_AssnMap am2){
if(am1.assn==(void*)& Cyc_AssnDef_false_assn){struct _tuple14 _Tmp0;_Tmp0.f0=am1.assn,_Tmp0.f1=am2.assn,_Tmp0.f2=am2.map;return _Tmp0;}
if(am2.assn==(void*)& Cyc_AssnDef_false_assn){struct _tuple14 _Tmp0;_Tmp0.f0=am1.assn,_Tmp0.f1=am2.assn,_Tmp0.f2=am1.map;return _Tmp0;}{
# 2558
struct Cyc_Dict_Dict subst_dict=*({struct Cyc_Dict_Dict*(*_Tmp0)(struct Cyc_Dict_Dict*(*)(struct Cyc_Dict_Dict*,struct Cyc_Absyn_Vardecl*,void*,struct Cyc_Dict_Dict*),struct Cyc_Dict_Dict*,struct Cyc_Dict_Dict,struct Cyc_Dict_Dict*)=({struct Cyc_Dict_Dict*(*_Tmp1)(struct Cyc_Dict_Dict*(*)(struct Cyc_Dict_Dict*,struct Cyc_Absyn_Vardecl*,void*,struct Cyc_Dict_Dict*),struct Cyc_Dict_Dict*,struct Cyc_Dict_Dict,struct Cyc_Dict_Dict*)=(struct Cyc_Dict_Dict*(*)(struct Cyc_Dict_Dict*(*)(struct Cyc_Dict_Dict*,struct Cyc_Absyn_Vardecl*,void*,struct Cyc_Dict_Dict*),struct Cyc_Dict_Dict*,struct Cyc_Dict_Dict,struct Cyc_Dict_Dict*))Cyc_Dict_fold_c;_Tmp1;});struct Cyc_Dict_Dict*_Tmp1=& am2.map;struct Cyc_Dict_Dict _Tmp2=am1.map;_Tmp0(Cyc_AssnDef_collect_subst,_Tmp1,_Tmp2,({struct Cyc_Dict_Dict*_Tmp3=_cycalloc(sizeof(struct Cyc_Dict_Dict));({struct Cyc_Dict_Dict _Tmp4=Cyc_AssnDef_empty_term_dict();*_Tmp3=_Tmp4;});_Tmp3;}));});
struct Cyc_AssnDef_AssnMap _Tmp0=Cyc_AssnDef_subst_am(subst_dict,am2);struct Cyc_AssnDef_AssnMap am2=_Tmp0;
return Cyc_AssnDef_unify_var_maps(am1,am2);}}
# 2563
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_or_assnmap_assnmap(struct Cyc_AssnDef_AssnMap am1,struct Cyc_AssnDef_AssnMap am2){
struct _tuple14 _Tmp0=Cyc_AssnDef_unify_var_maps(am1,am2);struct Cyc_Dict_Dict _Tmp1;void*_Tmp2;void*_Tmp3;_Tmp3=_Tmp0.f0;_Tmp2=_Tmp0.f1;_Tmp1=_Tmp0.f2;{void*a1=_Tmp3;void*a2=_Tmp2;struct Cyc_Dict_Dict map=_Tmp1;
struct Cyc_AssnDef_AssnMap _Tmp4;({void*_Tmp5=Cyc_AssnDef_or(a1,a2);_Tmp4.assn=_Tmp5;}),_Tmp4.map=map;return _Tmp4;}}struct Cyc_AssnDef_Canonical_am_accum{void*assn;struct Cyc_Dict_Dict map;struct Cyc_Set_Set*used_lvars;};
# 2575
static struct Cyc_AssnDef_Canonical_am_accum*Cyc_AssnDef_fold_canonical(struct Cyc_Absyn_Vardecl*vd,void*value,struct Cyc_AssnDef_Canonical_am_accum*accum){
if(*((int*)value)==2){
# 2578
if(!Cyc_Set_member(accum->used_lvars,value)){
({struct Cyc_Set_Set*_Tmp0=Cyc_Set_insert(accum->used_lvars,value);accum->used_lvars=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->map,vd,value);accum->map=_Tmp0;});
return accum;}
# 2583
goto _LL0;}else{
# 2585
goto _LL0;}_LL0:;{
# 2587
void*v=Cyc_AssnDef_fresh_var(vd,vd->type);
({struct Cyc_Set_Set*_Tmp0=Cyc_Set_insert(accum->used_lvars,v);accum->used_lvars=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(accum->map,vd,v);accum->map=_Tmp0;});
({void*_Tmp0=({void*_Tmp1=accum->assn;Cyc_AssnDef_and(_Tmp1,Cyc_AssnDef_eq(v,value));});accum->assn=_Tmp0;});
return accum;}}
# 2598
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_canonical_assnmap(struct Cyc_AssnDef_AssnMap am){
struct Cyc_AssnDef_Canonical_am_accum*accum;accum=_cycalloc(sizeof(struct Cyc_AssnDef_Canonical_am_accum)),accum->assn=am.assn,({struct Cyc_Dict_Dict _Tmp0=Cyc_AssnDef_empty_map();accum->map=_Tmp0;}),({struct Cyc_Set_Set*_Tmp0=Cyc_Set_empty(Cyc_Core_ptrcmp);accum->used_lvars=_Tmp0;});
({struct Cyc_AssnDef_Canonical_am_accum*(*_Tmp0)(struct Cyc_AssnDef_Canonical_am_accum*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_AssnDef_Canonical_am_accum*),struct Cyc_Dict_Dict,struct Cyc_AssnDef_Canonical_am_accum*)=(struct Cyc_AssnDef_Canonical_am_accum*(*)(struct Cyc_AssnDef_Canonical_am_accum*(*)(struct Cyc_Absyn_Vardecl*,void*,struct Cyc_AssnDef_Canonical_am_accum*),struct Cyc_Dict_Dict,struct Cyc_AssnDef_Canonical_am_accum*))Cyc_Dict_fold;_Tmp0;})(Cyc_AssnDef_fold_canonical,am.map,accum);{
struct Cyc_AssnDef_AssnMap _Tmp0;_Tmp0.assn=accum->assn,_Tmp0.map=accum->map;return _Tmp0;}}struct _tuple21{void*f0;struct Cyc_Set_Set*f1;};
# 2604
static struct Cyc_Dict_Dict*Cyc_AssnDef_force_it(struct _tuple21*env,struct Cyc_Absyn_Vardecl*vd,void*t,struct Cyc_Dict_Dict*accum){
if(({int(*_Tmp0)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(int(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_member;_Tmp0;})(env->f1,vd)){
void*new_term=Cyc_AssnDef_fresh_var(vd,vd->type);
({void*_Tmp0=({void*_Tmp1=env->f0;Cyc_AssnDef_and(_Tmp1,Cyc_AssnDef_eq(new_term,t));});env->f0=_Tmp0;});
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(*accum,vd,new_term);*accum=_Tmp0;});}else{
# 2610
({struct Cyc_Dict_Dict _Tmp0=({struct Cyc_Dict_Dict(*_Tmp1)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp1;})(*accum,vd,t);*accum=_Tmp0;});}
# 2612
return accum;}
# 2616
struct Cyc_AssnDef_AssnMap Cyc_AssnDef_force_canonical(struct Cyc_Set_Set*vds,struct Cyc_AssnDef_AssnMap am){
vds=({struct Cyc_Set_Set*(*_Tmp0)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_insert;_Tmp0;})(vds,Cyc_AssnDef_memory);
vds=({struct Cyc_Set_Set*(*_Tmp0)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=({struct Cyc_Set_Set*(*_Tmp1)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_insert;_Tmp1;});struct Cyc_Set_Set*_Tmp1=vds;_Tmp0(_Tmp1,Cyc_AssnDef_exception_vardecl());});{
void*assn=am.assn;
struct _tuple21 env=({struct _tuple21 _Tmp0;_Tmp0.f0=assn,_Tmp0.f1=vds;_Tmp0;});
struct Cyc_Dict_Dict map=Cyc_AssnDef_empty_map();
({struct Cyc_Dict_Dict*(*_Tmp0)(struct Cyc_Dict_Dict*(*)(struct _tuple21*,struct Cyc_Absyn_Vardecl*,void*,struct Cyc_Dict_Dict*),struct _tuple21*,struct Cyc_Dict_Dict,struct Cyc_Dict_Dict*)=(struct Cyc_Dict_Dict*(*)(struct Cyc_Dict_Dict*(*)(struct _tuple21*,struct Cyc_Absyn_Vardecl*,void*,struct Cyc_Dict_Dict*),struct _tuple21*,struct Cyc_Dict_Dict,struct Cyc_Dict_Dict*))Cyc_Dict_fold_c;_Tmp0;})(Cyc_AssnDef_force_it,& env,am.map,& map);{
struct Cyc_AssnDef_AssnMap _Tmp0;_Tmp0.assn=env.f0,_Tmp0.map=map;return _Tmp0;}}}
# 2634 "assndef.cyc"
void*Cyc_AssnDef_merge_assnmaps(struct Cyc_List_List*vds1,struct Cyc_AssnDef_AssnMap a1,struct Cyc_List_List*vds2,struct Cyc_AssnDef_AssnMap a2){
# 2636
struct Cyc_Dict_Dict dict=Cyc_AssnDef_empty_term_dict();
# 2638
void**v1=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(a1.map,Cyc_AssnDef_memory);
void**v2=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(a2.map,Cyc_AssnDef_memory);
if(v1!=0 && v2!=0)
dict=Cyc_Dict_insert(dict,*v2,*v1);
# 2643
for(1;vds1!=0 && vds2!=0;(vds1=vds1->tl,vds2=vds2->tl)){
if((struct Cyc_Absyn_Vardecl*)vds1->hd!=0 &&(struct Cyc_Absyn_Vardecl*)vds2->hd!=0){
void**v1=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(a1.map,(struct Cyc_Absyn_Vardecl*)vds1->hd);
void**v2=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(a2.map,_check_null((struct Cyc_Absyn_Vardecl*)vds2->hd));
if(v1!=0 && v2!=0)
dict=Cyc_Dict_insert(dict,*v2,*v1);}}
# 2658
if(Cyc_Dict_is_empty(dict))return a2.assn;else{
return Cyc_AssnDef_subst_a(dict,a2.assn);}}
# 2670 "assndef.cyc"
extern struct Cyc_AssnDef_AssnMap*Cyc_AssnDef_subst_vardecls(struct Cyc_List_List*vds1,struct Cyc_List_List*vds2,struct Cyc_AssnDef_AssnMap*a){
# 2673
if(a==0)return 0;{
struct Cyc_Dict_Dict newmap=Cyc_AssnDef_empty_map();
struct Cyc_Dict_Dict dict=Cyc_AssnDef_empty_term_dict();
# 2677
void**v=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(a->map,Cyc_AssnDef_memory);
if(v!=0){
void*u=Cyc_AssnDef_fresh_var(Cyc_AssnDef_memory,0);
newmap=({struct Cyc_Dict_Dict(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp0;})(newmap,Cyc_AssnDef_memory,u);
dict=Cyc_Dict_insert(dict,*v,u);}
# 2683
for(1;vds1!=0 && vds2!=0;(vds1=vds1->tl,vds2=vds2->tl)){
if((struct Cyc_Absyn_Vardecl*)vds1->hd!=0 &&(struct Cyc_Absyn_Vardecl*)vds2->hd!=0){
void**v=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(a->map,(struct Cyc_Absyn_Vardecl*)vds1->hd);
if(v!=0){
void*u=Cyc_AssnDef_fresh_var((struct Cyc_Absyn_Vardecl*)vds2->hd,_check_null((struct Cyc_Absyn_Vardecl*)vds2->hd)->type);
# 2689
newmap=({struct Cyc_Dict_Dict(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*)=(struct Cyc_Dict_Dict(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*,void*))Cyc_Dict_insert;_Tmp0;})(newmap,_check_null((struct Cyc_Absyn_Vardecl*)vds2->hd),u);
# 2691
dict=Cyc_Dict_insert(dict,*v,u);}}}{
# 2696
void*newa=Cyc_AssnDef_subst_a(dict,a->assn);
struct Cyc_AssnDef_AssnMap*_Tmp0=_cycalloc(sizeof(struct Cyc_AssnDef_AssnMap));_Tmp0->assn=newa,_Tmp0->map=newmap;return _Tmp0;}}}
# 2705
void*Cyc_AssnDef_subst_args(struct Cyc_List_List*args,struct Cyc_Absyn_Vardecl*res,struct Cyc_List_List*actual_args,void*actual_res,void*mem,struct Cyc_AssnDef_AssnMap am){
# 2709
struct Cyc_Dict_Dict dict=Cyc_AssnDef_empty_term_dict();
void**mem_val=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(am.map,Cyc_AssnDef_memory);
if(mem_val!=0)
dict=Cyc_Dict_insert(dict,*mem_val,mem);
if(res!=0 && actual_res!=0){
void**res_val=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(am.map,res);
if(res_val!=0)
dict=Cyc_Dict_insert(dict,*res_val,actual_res);}
# 2718
for(1;args!=0 && actual_args!=0;(args=args->tl,actual_args=actual_args->tl)){
if((struct Cyc_Absyn_Vardecl*)args->hd!=0 &&(void*)actual_args->hd!=0){
void**arg_val=({void**(*_Tmp0)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*)=(void**(*)(struct Cyc_Dict_Dict,struct Cyc_Absyn_Vardecl*))Cyc_Dict_lookup_opt;_Tmp0;})(am.map,(struct Cyc_Absyn_Vardecl*)args->hd);
if(arg_val!=0)
dict=Cyc_Dict_insert(dict,*arg_val,(void*)actual_args->hd);}}
# 2725
return Cyc_AssnDef_subst_a(dict,am.assn);}
# 2728
void Cyc_AssnDef_reset_hash_cons_table (void){
# 2731
Cyc_AssnDef_term_hash_cons_table=0;
Cyc_AssnDef_assn_hash_cons_table=0;}
# 2735
static void Cyc_AssnDef_f_sizeof_hashtable(void*key,void*value,int*counter){
++(*counter);}
# 2739
int Cyc_AssnDef_sizeof_hash_cons_table (void){
int size=0;
if(Cyc_AssnDef_term_hash_cons_table!=0)
({void(*_Tmp0)(void(*)(void*,struct Cyc_AssnDef_TermHashedInfo*,int*),struct Cyc_Hashtable_Table*,int*)=(void(*)(void(*)(void*,struct Cyc_AssnDef_TermHashedInfo*,int*),struct Cyc_Hashtable_Table*,int*))Cyc_Hashtable_iter_c;_Tmp0;})(({void(*_Tmp0)(void*,struct Cyc_AssnDef_TermHashedInfo*,int*)=(void(*)(void*,struct Cyc_AssnDef_TermHashedInfo*,int*))Cyc_AssnDef_f_sizeof_hashtable;_Tmp0;}),Cyc_AssnDef_term_hash_cons_table,& size);
# 2744
if(Cyc_AssnDef_assn_hash_cons_table!=0)
({void(*_Tmp0)(void(*)(void*,struct Cyc_AssnDef_AssnHashedInfo*,int*),struct Cyc_Hashtable_Table*,int*)=(void(*)(void(*)(void*,struct Cyc_AssnDef_AssnHashedInfo*,int*),struct Cyc_Hashtable_Table*,int*))Cyc_Hashtable_iter_c;_Tmp0;})(({void(*_Tmp0)(void*,struct Cyc_AssnDef_AssnHashedInfo*,int*)=(void(*)(void*,struct Cyc_AssnDef_AssnHashedInfo*,int*))Cyc_AssnDef_f_sizeof_hashtable;_Tmp0;}),Cyc_AssnDef_assn_hash_cons_table,& size);
# 2747
return size;}
# 2750
struct Cyc_Hashtable_Table*Cyc_AssnDef_empty_term_table (void){
return Cyc_Hashtable_create(33,Cyc_AssnDef_termcmp,Cyc_AssnDef_termhash);}
# 2754
void*Cyc_AssnDef_subst_table(struct Cyc_Hashtable_Table*table,void*t){
void**sopt=Cyc_Hashtable_lookup_opt(table,t);
void*told=t;
if(sopt!=0)return*sopt;
{unsigned _Tmp0;enum Cyc_Absyn_Primop _Tmp1;void*_Tmp2;int _Tmp3;void*_Tmp4;void*_Tmp5;void*_Tmp6;switch(*((int*)t)){case 2:
 goto _LL0;case 0:
 goto _LL0;case 1:
 goto _LL0;case 11: _Tmp6=((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Addr_AssnDef_Term_struct*)t)->f3;{struct Cyc_Absyn_Vardecl*vd=_Tmp6;void*t1=_Tmp5;void*tp=_Tmp4;
# 2763
void*s1=Cyc_AssnDef_subst_table(table,t1);
if(s1!=t1){
struct Cyc_AssnDef_Addr_AssnDef_Term_struct a=({struct Cyc_AssnDef_Addr_AssnDef_Term_struct _Tmp7;_Tmp7.tag=11,_Tmp7.f1=vd,_Tmp7.f2=s1,_Tmp7.f3=tp;_Tmp7;});
t=Cyc_AssnDef_hash_cons_term((void*)& a);}
# 2768
goto _LL0;}case 12: _Tmp6=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f1;_Tmp3=((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f3;_Tmp4=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f4;_Tmp2=(void*)((struct Cyc_AssnDef_Alloc_AssnDef_Term_struct*)t)->f5;{struct Cyc_Absyn_Exp*e1=_Tmp6;int i=_Tmp3;void*t1=_Tmp5;void*t2=_Tmp4;void*tp=_Tmp2;
# 2770
void*s1=Cyc_AssnDef_subst_table(table,t1);
void*s2=Cyc_AssnDef_subst_table(table,t2);
if(s1!=t1 || s2!=t2){
struct Cyc_AssnDef_Alloc_AssnDef_Term_struct a=({struct Cyc_AssnDef_Alloc_AssnDef_Term_struct _Tmp7;_Tmp7.tag=12,_Tmp7.f1=e1,_Tmp7.f2=i,_Tmp7.f3=s1,_Tmp7.f4=s2,_Tmp7.f5=tp;_Tmp7;});
t=Cyc_AssnDef_hash_cons_term((void*)& a);}
# 2776
goto _LL0;}case 6: _Tmp6=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Select_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;void*t2=_Tmp5;void*tp=_Tmp4;
# 2778
void*s1=Cyc_AssnDef_subst_table(table,t1);
void*s2=Cyc_AssnDef_subst_table(table,t2);
if(s1!=t1 || s2!=t2)t=Cyc_AssnDef_select(s1,s2,tp);
goto _LL0;}case 7: _Tmp6=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Update_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;void*t2=_Tmp5;void*t3=_Tmp4;
# 2783
void*s1=Cyc_AssnDef_subst_table(table,t1);
void*s2=Cyc_AssnDef_subst_table(table,t2);
void*s3=Cyc_AssnDef_subst_table(table,t3);
if((s1!=t1 || s2!=t2)|| s3!=t3)t=Cyc_AssnDef_update(s1,s2,s3);
goto _LL0;}case 3: _Tmp1=((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Unop_AssnDef_Term_struct*)t)->f3;{enum Cyc_Absyn_Primop p=_Tmp1;void*t1=_Tmp6;void*tp=_Tmp5;
# 2789
void*s1=Cyc_AssnDef_subst_table(table,t1);
if(s1!=t1)t=Cyc_AssnDef_unop(p,s1,tp);
goto _LL0;}case 4: _Tmp1=((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f1;_Tmp6=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f3;_Tmp4=(void*)((struct Cyc_AssnDef_Binop_AssnDef_Term_struct*)t)->f4;{enum Cyc_Absyn_Primop p=_Tmp1;void*t1=_Tmp6;void*t2=_Tmp5;void*tp=_Tmp4;
# 2793
void*s1=Cyc_AssnDef_subst_table(table,t1);
void*s2=Cyc_AssnDef_subst_table(table,t2);
if(s1!=t1 || s2!=t2)t=Cyc_AssnDef_binop(p,s1,s2,tp);
goto _LL0;}case 5: _Tmp6=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Cast_AssnDef_Term_struct*)t)->f2;{void*tp=_Tmp6;void*t1=_Tmp5;
# 2798
void*s1=Cyc_AssnDef_subst_table(table,t1);
if(s1!=t1)t=Cyc_AssnDef_cast(tp,s1);
goto _LL0;}case 8: _Tmp3=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f2;_Tmp6=((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f3;_Tmp5=(void*)((struct Cyc_AssnDef_Aggr_AssnDef_Term_struct*)t)->f4;{int b=_Tmp3;unsigned tag=_Tmp0;struct Cyc_List_List*tlist=_Tmp6;void*tp=_Tmp5;
# 2802
struct Cyc_List_List*slist=0;
int changed=0;
for(1;tlist!=0;tlist=tlist->tl){
void*t1=(void*)tlist->hd;
void*s1=Cyc_AssnDef_subst_table(table,t1);
if(s1!=t1)changed=1;
slist=({struct Cyc_List_List*_Tmp7=_cycalloc(sizeof(struct Cyc_List_List));_Tmp7->hd=s1,_Tmp7->tl=slist;_Tmp7;});}
# 2810
if(changed){
Cyc_List_imp_rev(slist);
t=Cyc_AssnDef_aggr(b,tag,slist,tp);}
# 2814
goto _LL0;}case 9: _Tmp6=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Proj_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;unsigned i=_Tmp0;void*tp=_Tmp5;
# 2816
void*s1=Cyc_AssnDef_subst_table(table,t1);
if(s1!=t1)t=Cyc_AssnDef_proj(s1,i,tp);
goto _LL0;}case 10: _Tmp6=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_AggrUpdate_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;unsigned i=_Tmp0;void*t2=_Tmp5;
# 2820
void*s1=Cyc_AssnDef_subst_table(table,t1);
void*s2=Cyc_AssnDef_subst_table(table,t2);
if(s1!=t1 || s2!=t2)t=Cyc_AssnDef_aggr_update(s1,i,s2);
goto _LL0;}case 13: _Tmp6=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f1;_Tmp0=((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f2;_Tmp5=(void*)((struct Cyc_AssnDef_Offsetf_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;unsigned i=_Tmp0;void*tp=_Tmp5;
# 2825
void*s1=Cyc_AssnDef_subst_table(table,t1);
if(s1!=t1)t=Cyc_AssnDef_offsetf(s1,i,tp);
goto _LL0;}case 14: _Tmp6=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f1;_Tmp5=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f2;_Tmp4=(void*)((struct Cyc_AssnDef_Offseti_AssnDef_Term_struct*)t)->f3;{void*t1=_Tmp6;void*t2=_Tmp5;void*tp=_Tmp4;
# 2829
void*s1=Cyc_AssnDef_subst_table(table,t1);
void*s2=Cyc_AssnDef_subst_table(table,t2);
if(s1!=t1 || s2!=t2)t=Cyc_AssnDef_offseti(s1,s2,tp);
goto _LL0;}default: _Tmp6=(void*)((struct Cyc_AssnDef_Tagof_AssnDef_Term_struct*)t)->f1;{void*t1=_Tmp6;
# 2834
void*s1=Cyc_AssnDef_subst_table(table,t1);
if(s1!=t1)t=Cyc_AssnDef_tagof_tm(s1);
goto _LL0;}}_LL0:;}
# 2838
Cyc_Hashtable_insert(table,told,t);
return t;}
# 2847
static void Cyc_AssnDef_changed_lhs(struct Cyc_Set_Set**vds,struct Cyc_Absyn_Exp*e){
void*_Tmp0=e->r;void*_Tmp1;if(*((int*)_Tmp0)==1)switch(*((int*)((struct Cyc_Absyn_Var_e_Absyn_Raw_exp_struct*)_Tmp0)->f1)){case 3: _Tmp1=((struct Cyc_Absyn_Param_b_Absyn_Binding_struct*)((struct Cyc_Absyn_Var_e_Absyn_Raw_exp_struct*)_Tmp0)->f1)->f1;{struct Cyc_Absyn_Vardecl*vd=_Tmp1;
_Tmp1=vd;goto _LL4;}case 4: _Tmp1=((struct Cyc_Absyn_Local_b_Absyn_Binding_struct*)((struct Cyc_Absyn_Var_e_Absyn_Raw_exp_struct*)_Tmp0)->f1)->f1;_LL4: {struct Cyc_Absyn_Vardecl*vd=_Tmp1;
_Tmp1=vd;goto _LL6;}case 5: _Tmp1=((struct Cyc_Absyn_Pat_b_Absyn_Binding_struct*)((struct Cyc_Absyn_Var_e_Absyn_Raw_exp_struct*)_Tmp0)->f1)->f1;_LL6: {struct Cyc_Absyn_Vardecl*vd=_Tmp1;
# 2852
({struct Cyc_Set_Set*_Tmp2=({struct Cyc_Set_Set*(*_Tmp3)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_insert;_Tmp3;})(*vds,vd);*vds=_Tmp2;});
goto _LL0;}default: goto _LL7;}else{_LL7:
 goto _LL0;}_LL0:;}struct _tuple22{struct Cyc_List_List*f0;struct Cyc_Absyn_Pat*f1;};
# 2858
static void Cyc_AssnDef_changed_pat(struct Cyc_Set_Set**vds,struct Cyc_Absyn_Pat*p){
LOOP: {
void*_Tmp0=p->r;void*_Tmp1;void*_Tmp2;switch(*((int*)_Tmp0)){case 3: _Tmp2=((struct Cyc_Absyn_Reference_p_Absyn_Raw_pat_struct*)_Tmp0)->f1;_Tmp1=((struct Cyc_Absyn_Reference_p_Absyn_Raw_pat_struct*)_Tmp0)->f2;{struct Cyc_Absyn_Vardecl*vd=_Tmp2;struct Cyc_Absyn_Pat*p1=_Tmp1;
_Tmp2=vd;_Tmp1=p1;goto _LL4;}case 1: _Tmp2=((struct Cyc_Absyn_Var_p_Absyn_Raw_pat_struct*)_Tmp0)->f1;_Tmp1=((struct Cyc_Absyn_Var_p_Absyn_Raw_pat_struct*)_Tmp0)->f2;_LL4: {struct Cyc_Absyn_Vardecl*vd=_Tmp2;struct Cyc_Absyn_Pat*p1=_Tmp1;
({struct Cyc_Set_Set*(*_Tmp3)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_insert;_Tmp3;})(*vds,vd);p=p1;goto LOOP;}case 4: _Tmp2=((struct Cyc_Absyn_TagInt_p_Absyn_Raw_pat_struct*)_Tmp0)->f2;{struct Cyc_Absyn_Vardecl*vd=_Tmp2;
_Tmp2=vd;goto _LL8;}case 2: _Tmp2=((struct Cyc_Absyn_AliasVar_p_Absyn_Raw_pat_struct*)_Tmp0)->f2;_LL8: {struct Cyc_Absyn_Vardecl*vd=_Tmp2;
({struct Cyc_Set_Set*(*_Tmp3)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_insert;_Tmp3;})(*vds,vd);goto _LL0;}case 5: _Tmp2=((struct Cyc_Absyn_Pointer_p_Absyn_Raw_pat_struct*)_Tmp0)->f1;{struct Cyc_Absyn_Pat*p1=_Tmp2;
p=p1;goto LOOP;}case 6: _Tmp2=((struct Cyc_Absyn_Aggr_p_Absyn_Raw_pat_struct*)_Tmp0)->f4;{struct Cyc_List_List*dlps=_Tmp2;
# 2867
for(1;dlps!=0;dlps=dlps->tl){
Cyc_AssnDef_changed_pat(vds,((struct _tuple22*)dlps->hd)->f1);}
goto _LL0;}case 7: _Tmp2=((struct Cyc_Absyn_Datatype_p_Absyn_Raw_pat_struct*)_Tmp0)->f3;{struct Cyc_List_List*ps=_Tmp2;
# 2871
for(1;ps!=0;ps=ps->tl){
Cyc_AssnDef_changed_pat(vds,(struct Cyc_Absyn_Pat*)ps->hd);}
goto _LL0;}default:
 goto _LL0;}_LL0:;}}
# 2878
static int Cyc_AssnDef_changed_exp(struct Cyc_Set_Set**vds,struct Cyc_Absyn_Exp*e){
{void*_Tmp0=e->r;void*_Tmp1;void*_Tmp2;switch(*((int*)_Tmp0)){case 4: _Tmp2=((struct Cyc_Absyn_AssignOp_e_Absyn_Raw_exp_struct*)_Tmp0)->f1;{struct Cyc_Absyn_Exp*e=_Tmp2;
_Tmp2=e;goto _LL4;}case 5: _Tmp2=((struct Cyc_Absyn_Increment_e_Absyn_Raw_exp_struct*)_Tmp0)->f1;_LL4: {struct Cyc_Absyn_Exp*e=_Tmp2;
# 2882
Cyc_AssnDef_changed_lhs(vds,e);
goto _LL0;}case 26: _Tmp2=((struct Cyc_Absyn_Comprehension_e_Absyn_Raw_exp_struct*)_Tmp0)->f1;{struct Cyc_Absyn_Vardecl*vd=_Tmp2;
# 2885
({struct Cyc_Set_Set*_Tmp3=({struct Cyc_Set_Set*(*_Tmp4)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_insert;_Tmp4;})(*vds,vd);*vds=_Tmp3;});
goto _LL0;}case 34: _Tmp2=((struct Cyc_Absyn_Swap_e_Absyn_Raw_exp_struct*)_Tmp0)->f1;_Tmp1=((struct Cyc_Absyn_Swap_e_Absyn_Raw_exp_struct*)_Tmp0)->f2;{struct Cyc_Absyn_Exp*e1=_Tmp2;struct Cyc_Absyn_Exp*e2=_Tmp1;
# 2888
Cyc_AssnDef_changed_lhs(vds,e1);
Cyc_AssnDef_changed_lhs(vds,e2);
goto _LL0;}default:
 goto _LL0;}_LL0:;}
# 2893
return 1;}
# 2896
static int Cyc_AssnDef_changed_stmt(struct Cyc_Set_Set**vds,struct Cyc_Absyn_Stmt*s){
{void*_Tmp0=s->r;void*_Tmp1;switch(*((int*)_Tmp0)){case 12: _Tmp1=((struct Cyc_Absyn_Decl_s_Absyn_Raw_stmt_struct*)_Tmp0)->f1;{struct Cyc_Absyn_Decl*d=_Tmp1;
# 2899
{void*_Tmp2=d->r;void*_Tmp3;switch(*((int*)_Tmp2)){case 0: _Tmp3=((struct Cyc_Absyn_Var_d_Absyn_Raw_decl_struct*)_Tmp2)->f1;{struct Cyc_Absyn_Vardecl*vd=_Tmp3;
_Tmp3=vd;goto _LLD;}case 4: _Tmp3=((struct Cyc_Absyn_Region_d_Absyn_Raw_decl_struct*)_Tmp2)->f2;_LLD: {struct Cyc_Absyn_Vardecl*vd=_Tmp3;
({struct Cyc_Set_Set*_Tmp4=({struct Cyc_Set_Set*(*_Tmp5)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*)=(struct Cyc_Set_Set*(*)(struct Cyc_Set_Set*,struct Cyc_Absyn_Vardecl*))Cyc_Set_insert;_Tmp5;})(*vds,vd);*vds=_Tmp4;});goto _LL9;}case 2: _Tmp3=((struct Cyc_Absyn_Let_d_Absyn_Raw_decl_struct*)_Tmp2)->f1;{struct Cyc_Absyn_Pat*p=_Tmp3;
# 2903
Cyc_AssnDef_changed_pat(vds,p);goto _LL9;}case 3: _Tmp3=((struct Cyc_Absyn_Letv_d_Absyn_Raw_decl_struct*)_Tmp2)->f1;{struct Cyc_List_List*vds2=_Tmp3;
# 2905
({struct Cyc_Set_Set*_Tmp4=({struct Cyc_Set_Set*_Tmp5=*vds;Cyc_Set_union_two(_Tmp5,({struct Cyc_Set_Set*(*_Tmp6)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*),struct Cyc_List_List*)=(struct Cyc_Set_Set*(*)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*),struct Cyc_List_List*))Cyc_Set_from_list;_Tmp6;})(({int(*_Tmp6)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*)=(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*))Cyc_Core_ptrcmp;_Tmp6;}),vds2));});*vds=_Tmp4;});goto _LL9;}default:
 goto _LL9;}_LL9:;}
# 2908
goto _LL0;}case 10: _Tmp1=((struct Cyc_Absyn_Switch_s_Absyn_Raw_stmt_struct*)_Tmp0)->f2;{struct Cyc_List_List*scs=_Tmp1;
_Tmp1=scs;goto _LL6;}case 15: _Tmp1=((struct Cyc_Absyn_TryCatch_s_Absyn_Raw_stmt_struct*)_Tmp0)->f2;_LL6: {struct Cyc_List_List*scs=_Tmp1;
# 2911
for(1;scs!=0;scs=scs->tl){
Cyc_AssnDef_changed_pat(vds,((struct Cyc_Absyn_Switch_clause*)scs->hd)->pattern);}
goto _LL0;}default:
 goto _LL0;}_LL0:;}
# 2916
return 1;}
# 2919
struct Cyc_Set_Set*Cyc_AssnDef_calc_changed_vars_exp(struct Cyc_Absyn_Exp*e){
struct Cyc_Set_Set*vds=({struct Cyc_Set_Set*(*_Tmp0)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*))=(struct Cyc_Set_Set*(*)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*)))Cyc_Set_empty;_Tmp0;})(({int(*_Tmp0)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*)=(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*))Cyc_Core_ptrcmp;_Tmp0;}));
({void(*_Tmp0)(int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Exp*),int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Stmt*),struct Cyc_Set_Set**,struct Cyc_Absyn_Exp*)=(void(*)(int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Exp*),int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Stmt*),struct Cyc_Set_Set**,struct Cyc_Absyn_Exp*))Cyc_Absyn_visit_exp;_Tmp0;})(Cyc_AssnDef_changed_exp,Cyc_AssnDef_changed_stmt,& vds,e);
return vds;}
# 2924
struct Cyc_Set_Set*Cyc_AssnDef_calc_changed_vars_stmt(struct Cyc_Absyn_Stmt*s){
struct Cyc_Set_Set*vds=({struct Cyc_Set_Set*(*_Tmp0)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*))=(struct Cyc_Set_Set*(*)(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*)))Cyc_Set_empty;_Tmp0;})(({int(*_Tmp0)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*)=(int(*)(struct Cyc_Absyn_Vardecl*,struct Cyc_Absyn_Vardecl*))Cyc_Core_ptrcmp;_Tmp0;}));
({void(*_Tmp0)(int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Exp*),int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Stmt*),struct Cyc_Set_Set**,struct Cyc_Absyn_Stmt*)=(void(*)(int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Exp*),int(*)(struct Cyc_Set_Set**,struct Cyc_Absyn_Stmt*),struct Cyc_Set_Set**,struct Cyc_Absyn_Stmt*))Cyc_Absyn_visit_stmt;_Tmp0;})(Cyc_AssnDef_changed_exp,Cyc_AssnDef_changed_stmt,& vds,s);
return vds;}
