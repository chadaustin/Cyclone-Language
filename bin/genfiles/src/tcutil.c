#include "cyc_include.h"

 struct _tuple0{ struct Cyc_List_List* f1; struct Cyc_List_List* f2; } ; struct
_tuple1{ void* f1; struct _tagged_string* f2; } ; struct _tuple2{ struct Cyc_Core_Opt*
f1; struct Cyc_Absyn_Tqual* f2; void* f3; } ; struct _tuple3{ struct Cyc_Absyn_Exp*
f1; struct Cyc_Absyn_Stmt* f2; } ; struct _tuple4{ struct Cyc_Absyn_Tqual* f1;
void* f2; } ; struct _tuple5{ struct Cyc_Absyn_Tvar* f1; void* f2; } ; struct
_tuple6{ int f1; void* f2; } ; struct _tuple7{ void* f1; void* f2; } ; struct
_tuple8{ void* f1; struct Cyc_List_List* f2; } ; struct _tuple9{ struct _tuple8*
f1; struct _tuple8* f2; } ; struct _tuple10{ struct _tagged_string* f1; struct
Cyc_Absyn_Tqual* f2; void* f3; } ; struct _tuple11{ void* f1; void* f2; void* f3;
} ; struct _tuple12{ struct Cyc_Core_Opt* f1; struct Cyc_Absyn_Tqual* f2; } ;
struct _tuple13{ struct _tuple12* f1; void* f2; } ; struct _tuple14{ struct Cyc_Absyn_Structfield*
f1; int f2; } ; struct _tuple15{ struct Cyc_List_List* f1; void* f2; } ; struct
_tuple16{ struct Cyc_Absyn_Structfield* f1; void* f2; } ; typedef unsigned int
Cyc_uint; typedef char* Cyc_Cstring; typedef struct _tagged_string Cyc_string;
typedef struct _tagged_string Cyc_string_t; typedef struct _tagged_string* Cyc_stringptr;
typedef int Cyc_bool; extern void* exit( int); extern void* abort(); struct Cyc_Core_Opt{
void* v; } ; typedef struct Cyc_Core_Opt* Cyc_Core_opt_t; extern int Cyc_Core_intcmp(
int, int); extern char Cyc_Core_InvalidArg_tag[ 11u]; struct Cyc_Core_InvalidArg_struct{
char* tag; struct _tagged_string f1; } ; extern char Cyc_Core_Failure_tag[ 8u];
struct Cyc_Core_Failure_struct{ char* tag; struct _tagged_string f1; } ; extern
char Cyc_Core_Impossible_tag[ 11u]; struct Cyc_Core_Impossible_struct{ char* tag;
struct _tagged_string f1; } ; extern char Cyc_Core_Not_found_tag[ 10u]; struct
Cyc_Core_Not_found_struct{ char* tag; } ; extern char Cyc_Core_Unreachable_tag[
12u]; struct Cyc_Core_Unreachable_struct{ char* tag; struct _tagged_string f1; }
; extern char* string_to_Cstring( struct _tagged_string); extern char*
underlying_Cstring( struct _tagged_string); extern struct _tagged_string
Cstring_to_string( char*); extern int system( char*); struct Cyc_Stdio___sFILE;
typedef struct Cyc_Stdio___sFILE Cyc_Stdio_FILE; extern struct Cyc_Stdio___sFILE*
Cyc_Stdio_stderr; typedef unsigned int Cyc_Stdio_size_t; typedef int Cyc_Stdio_fpos_t;
extern int Cyc_Stdio_fflush( struct Cyc_Stdio___sFILE*); extern char Cyc_Stdio_FileOpenError_tag[
14u]; struct Cyc_Stdio_FileOpenError_struct{ char* tag; struct _tagged_string f1;
} ; extern char Cyc_Stdio_FileCloseError_tag[ 15u]; struct Cyc_Stdio_FileCloseError_struct{
char* tag; } ; struct Cyc_List_List{ void* hd; struct Cyc_List_List* tl; } ;
typedef struct Cyc_List_List* Cyc_List_glist_t; typedef struct Cyc_List_List*
Cyc_List_list_t; typedef struct Cyc_List_List* Cyc_List_List_t; extern int Cyc_List_length(
struct Cyc_List_List* x); extern char Cyc_List_List_empty_tag[ 11u]; struct Cyc_List_List_empty_struct{
char* tag; } ; extern struct Cyc_List_List* Cyc_List_map( void*(* f)( void*),
struct Cyc_List_List* x); extern struct Cyc_List_List* Cyc_List_map_c( void*(* f)(
void*, void*), void* env, struct Cyc_List_List* x); extern char Cyc_List_List_mismatch_tag[
14u]; struct Cyc_List_List_mismatch_struct{ char* tag; } ; extern void Cyc_List_iter2(
void(* f)( void*, void*), struct Cyc_List_List* x, struct Cyc_List_List* y);
extern struct Cyc_List_List* Cyc_List_revappend( struct Cyc_List_List* x, struct
Cyc_List_List* y); extern struct Cyc_List_List* Cyc_List_imp_rev( struct Cyc_List_List*
x); extern struct Cyc_List_List* Cyc_List_append( struct Cyc_List_List* x,
struct Cyc_List_List* y); extern char Cyc_List_Nth_tag[ 4u]; struct Cyc_List_Nth_struct{
char* tag; } ; extern int Cyc_List_exists_c( int(* pred)( void*, void*), void*
env, struct Cyc_List_List* x); extern struct Cyc_List_List* Cyc_List_zip( struct
Cyc_List_List* x, struct Cyc_List_List* y); extern struct _tuple0 Cyc_List_split(
struct Cyc_List_List* x); extern void* Cyc_List_assoc_cmp( int(* compare)( void*,
void*), struct Cyc_List_List* l, void* x); struct Cyc_Lineno_Pos{ struct
_tagged_string logical_file; struct _tagged_string line; int line_no; int col; }
; typedef struct Cyc_Lineno_Pos* Cyc_Lineno_pos_t; extern char Cyc_Position_Exit_tag[
5u]; struct Cyc_Position_Exit_struct{ char* tag; } ; struct Cyc_Position_Segment;
typedef struct Cyc_Position_Segment* Cyc_Position_seg_t; extern struct Cyc_List_List*
Cyc_Position_strings_of_segments( struct Cyc_List_List*); typedef void* Cyc_Position_Error_kind;
extern void* Cyc_Position_Lex; extern void* Cyc_Position_Parse; extern void* Cyc_Position_Elab;
typedef void* Cyc_Position_error_kind_t; struct Cyc_Position_Error{ struct
_tagged_string source; struct Cyc_Position_Segment* seg; void* kind; struct
_tagged_string desc; } ; typedef struct Cyc_Position_Error* Cyc_Position_error_t;
extern struct Cyc_Position_Error* Cyc_Position_mk_err_elab( struct Cyc_Position_Segment*,
struct _tagged_string); extern char Cyc_Position_Nocontext_tag[ 10u]; struct Cyc_Position_Nocontext_struct{
char* tag; } ; extern void Cyc_Position_post_error( struct Cyc_Position_Error*);
typedef struct _tagged_string* Cyc_Absyn_field_name; typedef struct
_tagged_string* Cyc_Absyn_var; typedef struct _tagged_string* Cyc_Absyn_tvarname_t;
typedef void* Cyc_Absyn_Nmspace; typedef struct _tuple1* Cyc_Absyn_qvar; typedef
struct _tuple1* Cyc_Absyn_qvar_opt_t; typedef struct _tuple1* Cyc_Absyn_typedef_name_t;
typedef struct _tuple1* Cyc_Absyn_typedef_name_opt_t; struct Cyc_Absyn_Tvar;
typedef void* Cyc_Absyn_Scope; struct Cyc_Absyn_Tqual; typedef void* Cyc_Absyn_Size_of;
typedef void* Cyc_Absyn_Kind; typedef void* Cyc_Absyn_Array_kind; typedef void*
Cyc_Absyn_Sign; struct Cyc_Absyn_Conref; typedef void* Cyc_Absyn_Constraint;
typedef void* Cyc_Absyn_Bounds; struct Cyc_Absyn_PtrInfo; struct Cyc_Absyn_FnInfo;
typedef void* Cyc_Absyn_Typ; typedef void* Cyc_Absyn_Funcparams; typedef void*
Cyc_Absyn_Type_modifier; typedef void* Cyc_Absyn_Cnst; typedef void* Cyc_Absyn_Primop;
typedef void* Cyc_Absyn_Incrementor; typedef void* Cyc_Absyn_Raw_exp; struct Cyc_Absyn_Exp;
typedef void* Cyc_Absyn_Raw_stmt; struct Cyc_Absyn_Stmt; typedef void* Cyc_Absyn_Raw_pat;
struct Cyc_Absyn_Pat; typedef void* Cyc_Absyn_Binding; struct Cyc_Absyn_Switch_clause;
struct Cyc_Absyn_Fndecl; struct Cyc_Absyn_Structdecl; struct Cyc_Absyn_Enumfield;
struct Cyc_Absyn_Enumdecl; struct Cyc_Absyn_Xenumdecl; struct Cyc_Absyn_Typedefdecl;
struct Cyc_Absyn_Vardecl; typedef void* Cyc_Absyn_Raw_decl; struct Cyc_Absyn_Decl;
typedef void* Cyc_Absyn_Designator; typedef struct _xenum_struct* Cyc_Absyn_StmtAnnot;
typedef void* Cyc_Absyn_Attribute; struct Cyc_Absyn_Structfield; typedef void*
Cyc_Absyn_scope; typedef struct Cyc_Absyn_Tqual* Cyc_Absyn_tqual; typedef void*
Cyc_Absyn_size_of_t; typedef void* Cyc_Absyn_kind_t; typedef struct Cyc_Absyn_Tvar*
Cyc_Absyn_tvar; typedef void* Cyc_Absyn_sign_t; typedef struct Cyc_Absyn_Conref*
Cyc_Absyn_conref; typedef void* Cyc_Absyn_constraint_t; typedef void* Cyc_Absyn_bounds_t;
typedef struct Cyc_Absyn_PtrInfo Cyc_Absyn_ptr_info_t; typedef struct Cyc_Absyn_FnInfo
Cyc_Absyn_fn_info_t; typedef void* Cyc_Absyn_typ; typedef void* Cyc_Absyn_funcparams_t;
typedef void* Cyc_Absyn_type_modifier; typedef void* Cyc_Absyn_cnst_t; typedef
void* Cyc_Absyn_primop; typedef void* Cyc_Absyn_incrementor_t; typedef void* Cyc_Absyn_raw_exp_t;
typedef struct Cyc_Absyn_Exp* Cyc_Absyn_exp; typedef struct Cyc_Absyn_Exp* Cyc_Absyn_exp_opt;
typedef void* Cyc_Absyn_raw_stmt_t; typedef struct Cyc_Absyn_Stmt* Cyc_Absyn_stmt;
typedef struct Cyc_Absyn_Stmt* Cyc_Absyn_stmt_opt; typedef void* Cyc_Absyn_raw_pat_t;
typedef struct Cyc_Absyn_Pat* Cyc_Absyn_pat; typedef void* Cyc_Absyn_binding_t;
typedef struct Cyc_Absyn_Switch_clause* Cyc_Absyn_switch_clause; typedef struct
Cyc_Absyn_Fndecl* Cyc_Absyn_fndecl; typedef struct Cyc_Absyn_Structdecl* Cyc_Absyn_structdecl;
typedef struct Cyc_Absyn_Enumfield* Cyc_Absyn_enumfield; typedef struct Cyc_Absyn_Enumdecl*
Cyc_Absyn_enumdecl; typedef struct Cyc_Absyn_Xenumdecl* Cyc_Absyn_xenumdecl;
typedef struct Cyc_Absyn_Typedefdecl* Cyc_Absyn_typedefdecl; typedef struct Cyc_Absyn_Vardecl*
Cyc_Absyn_vardecl; typedef void* Cyc_Absyn_raw_decl; typedef struct Cyc_Absyn_Decl*
Cyc_Absyn_decl; typedef void* Cyc_Absyn_designator; typedef struct _xenum_struct*
Cyc_Absyn_stmt_annot_t; typedef void* Cyc_Absyn_attribute_t; typedef struct Cyc_List_List*
Cyc_Absyn_attributes_t; typedef struct Cyc_Absyn_Structfield* Cyc_Absyn_structfield_t;
extern void* Cyc_Absyn_Loc_n; extern const int Cyc_Absyn_Rel_n_tag; struct Cyc_Absyn_Rel_n_struct{
int tag; struct Cyc_List_List* f1; } ; extern const int Cyc_Absyn_Abs_n_tag;
struct Cyc_Absyn_Abs_n_struct{ int tag; struct Cyc_List_List* f1; } ; extern
void* Cyc_Absyn_Static; extern void* Cyc_Absyn_Abstract; extern void* Cyc_Absyn_Public;
extern void* Cyc_Absyn_Extern; extern void* Cyc_Absyn_ExternC; struct Cyc_Absyn_Tqual{
int q_const; int q_volatile; int q_restrict; } ; extern void* Cyc_Absyn_B1;
extern void* Cyc_Absyn_B2; extern void* Cyc_Absyn_B4; extern void* Cyc_Absyn_B8;
extern void* Cyc_Absyn_AnyKind; extern void* Cyc_Absyn_MemKind; extern void* Cyc_Absyn_BoxKind;
extern void* Cyc_Absyn_RgnKind; extern void* Cyc_Absyn_EffKind; extern void* Cyc_Absyn_Signed;
extern void* Cyc_Absyn_Unsigned; struct Cyc_Absyn_Conref{ void* v; } ; extern
const int Cyc_Absyn_Eq_constr_tag; struct Cyc_Absyn_Eq_constr_struct{ int tag;
void* f1; } ; extern const int Cyc_Absyn_Forward_constr_tag; struct Cyc_Absyn_Forward_constr_struct{
int tag; struct Cyc_Absyn_Conref* f1; } ; extern void* Cyc_Absyn_No_constr;
struct Cyc_Absyn_Tvar{ struct _tagged_string* name; struct Cyc_Absyn_Conref*
kind; } ; extern void* Cyc_Absyn_Unknown_b; extern const int Cyc_Absyn_Upper_b_tag;
struct Cyc_Absyn_Upper_b_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ; struct
Cyc_Absyn_PtrInfo{ void* elt_typ; void* rgn_typ; struct Cyc_Absyn_Conref*
nullable; struct Cyc_Absyn_Tqual* tq; struct Cyc_Absyn_Conref* bounds; } ;
struct Cyc_Absyn_FnInfo{ struct Cyc_List_List* tvars; struct Cyc_Core_Opt*
effect; void* ret_typ; struct Cyc_List_List* args; int varargs; struct Cyc_List_List*
attributes; } ; extern void* Cyc_Absyn_VoidType; extern const int Cyc_Absyn_Evar_tag;
struct Cyc_Absyn_Evar_struct{ int tag; void* f1; struct Cyc_Core_Opt* f2; int f3;
} ; extern const int Cyc_Absyn_VarType_tag; struct Cyc_Absyn_VarType_struct{ int
tag; struct Cyc_Absyn_Tvar* f1; } ; extern const int Cyc_Absyn_EnumType_tag;
struct Cyc_Absyn_EnumType_struct{ int tag; struct _tuple1* f1; struct Cyc_List_List*
f2; struct Cyc_Absyn_Enumdecl** f3; } ; extern const int Cyc_Absyn_XenumType_tag;
struct Cyc_Absyn_XenumType_struct{ int tag; struct _tuple1* f1; struct Cyc_Absyn_Xenumdecl**
f2; } ; extern const int Cyc_Absyn_PointerType_tag; struct Cyc_Absyn_PointerType_struct{
int tag; struct Cyc_Absyn_PtrInfo f1; } ; extern const int Cyc_Absyn_IntType_tag;
struct Cyc_Absyn_IntType_struct{ int tag; void* f1; void* f2; } ; extern void*
Cyc_Absyn_FloatType; extern void* Cyc_Absyn_DoubleType; extern const int Cyc_Absyn_ArrayType_tag;
struct Cyc_Absyn_ArrayType_struct{ int tag; void* f1; struct Cyc_Absyn_Tqual* f2;
struct Cyc_Absyn_Exp* f3; } ; extern const int Cyc_Absyn_FnType_tag; struct Cyc_Absyn_FnType_struct{
int tag; struct Cyc_Absyn_FnInfo f1; } ; extern const int Cyc_Absyn_TupleType_tag;
struct Cyc_Absyn_TupleType_struct{ int tag; struct Cyc_List_List* f1; } ; extern
const int Cyc_Absyn_StructType_tag; struct Cyc_Absyn_StructType_struct{ int tag;
struct _tuple1* f1; struct Cyc_List_List* f2; struct Cyc_Absyn_Structdecl** f3;
} ; extern void* Cyc_Absyn_UnionType; extern const int Cyc_Absyn_RgnHandleType_tag;
struct Cyc_Absyn_RgnHandleType_struct{ int tag; void* f1; } ; extern const int
Cyc_Absyn_TypedefType_tag; struct Cyc_Absyn_TypedefType_struct{ int tag; struct
_tuple1* f1; struct Cyc_List_List* f2; struct Cyc_Core_Opt* f3; } ; extern void*
Cyc_Absyn_HeapRgn; extern const int Cyc_Absyn_AccessEff_tag; struct Cyc_Absyn_AccessEff_struct{
int tag; void* f1; } ; extern const int Cyc_Absyn_JoinEff_tag; struct Cyc_Absyn_JoinEff_struct{
int tag; struct Cyc_List_List* f1; } ; extern const int Cyc_Absyn_NoTypes_tag;
struct Cyc_Absyn_NoTypes_struct{ int tag; struct Cyc_List_List* f1; struct Cyc_Position_Segment*
f2; } ; extern const int Cyc_Absyn_WithTypes_tag; struct Cyc_Absyn_WithTypes_struct{
int tag; struct Cyc_List_List* f1; int f2; struct Cyc_Core_Opt* f3; } ; typedef
void* Cyc_Absyn_Pointer_Sort; extern const int Cyc_Absyn_NonNullable_ps_tag;
struct Cyc_Absyn_NonNullable_ps_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
extern const int Cyc_Absyn_Nullable_ps_tag; struct Cyc_Absyn_Nullable_ps_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; extern void* Cyc_Absyn_TaggedArray_ps;
extern const int Cyc_Absyn_Regparm_att_tag; struct Cyc_Absyn_Regparm_att_struct{
int tag; int f1; } ; extern void* Cyc_Absyn_Stdcall_att; extern void* Cyc_Absyn_Cdecl_att;
extern void* Cyc_Absyn_Noreturn_att; extern void* Cyc_Absyn_Const_att; extern
const int Cyc_Absyn_Aligned_att_tag; struct Cyc_Absyn_Aligned_att_struct{ int
tag; int f1; } ; extern void* Cyc_Absyn_Packed_att; extern const int Cyc_Absyn_Section_att_tag;
struct Cyc_Absyn_Section_att_struct{ int tag; struct _tagged_string f1; } ;
extern void* Cyc_Absyn_Nocommon_att; extern void* Cyc_Absyn_Shared_att; extern
void* Cyc_Absyn_Unused_att; extern void* Cyc_Absyn_Weak_att; extern void* Cyc_Absyn_Dllimport_att;
extern void* Cyc_Absyn_Dllexport_att; extern void* Cyc_Absyn_No_instrument_function_att;
extern void* Cyc_Absyn_Constructor_att; extern void* Cyc_Absyn_Destructor_att;
extern void* Cyc_Absyn_No_check_memory_usage_att; extern void* Cyc_Absyn_Carray_mod;
extern const int Cyc_Absyn_ConstArray_mod_tag; struct Cyc_Absyn_ConstArray_mod_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; extern const int Cyc_Absyn_Pointer_mod_tag;
struct Cyc_Absyn_Pointer_mod_struct{ int tag; void* f1; void* f2; struct Cyc_Absyn_Tqual*
f3; } ; extern const int Cyc_Absyn_Function_mod_tag; struct Cyc_Absyn_Function_mod_struct{
int tag; void* f1; } ; extern const int Cyc_Absyn_TypeParams_mod_tag; struct Cyc_Absyn_TypeParams_mod_struct{
int tag; struct Cyc_List_List* f1; struct Cyc_Position_Segment* f2; int f3; } ;
extern const int Cyc_Absyn_Attributes_mod_tag; struct Cyc_Absyn_Attributes_mod_struct{
int tag; struct Cyc_Position_Segment* f1; struct Cyc_List_List* f2; } ; extern
const int Cyc_Absyn_Char_c_tag; struct Cyc_Absyn_Char_c_struct{ int tag; void*
f1; char f2; } ; extern const int Cyc_Absyn_Short_c_tag; struct Cyc_Absyn_Short_c_struct{
int tag; void* f1; short f2; } ; extern const int Cyc_Absyn_Int_c_tag; struct
Cyc_Absyn_Int_c_struct{ int tag; void* f1; int f2; } ; extern const int Cyc_Absyn_LongLong_c_tag;
struct Cyc_Absyn_LongLong_c_struct{ int tag; void* f1; long long f2; } ; extern
const int Cyc_Absyn_Float_c_tag; struct Cyc_Absyn_Float_c_struct{ int tag;
struct _tagged_string f1; } ; extern const int Cyc_Absyn_String_c_tag; struct
Cyc_Absyn_String_c_struct{ int tag; int f1; struct _tagged_string f2; } ; extern
void* Cyc_Absyn_Null_c; extern void* Cyc_Absyn_Plus; extern void* Cyc_Absyn_Times;
extern void* Cyc_Absyn_Minus; extern void* Cyc_Absyn_Div; extern void* Cyc_Absyn_Mod;
extern void* Cyc_Absyn_Eq; extern void* Cyc_Absyn_Neq; extern void* Cyc_Absyn_Gt;
extern void* Cyc_Absyn_Lt; extern void* Cyc_Absyn_Gte; extern void* Cyc_Absyn_Lte;
extern void* Cyc_Absyn_Not; extern void* Cyc_Absyn_Bitnot; extern void* Cyc_Absyn_Bitand;
extern void* Cyc_Absyn_Bitor; extern void* Cyc_Absyn_Bitxor; extern void* Cyc_Absyn_Bitlshift;
extern void* Cyc_Absyn_Bitlrshift; extern void* Cyc_Absyn_Bitarshift; extern
void* Cyc_Absyn_Size; extern void* Cyc_Absyn_Printf; extern void* Cyc_Absyn_Fprintf;
extern void* Cyc_Absyn_Xprintf; extern void* Cyc_Absyn_Scanf; extern void* Cyc_Absyn_Fscanf;
extern void* Cyc_Absyn_Sscanf; extern void* Cyc_Absyn_PreInc; extern void* Cyc_Absyn_PostInc;
extern void* Cyc_Absyn_PreDec; extern void* Cyc_Absyn_PostDec; extern const int
Cyc_Absyn_Const_e_tag; struct Cyc_Absyn_Const_e_struct{ int tag; void* f1; } ;
extern const int Cyc_Absyn_Var_e_tag; struct Cyc_Absyn_Var_e_struct{ int tag;
struct _tuple1* f1; void* f2; } ; extern const int Cyc_Absyn_UnknownId_e_tag;
struct Cyc_Absyn_UnknownId_e_struct{ int tag; struct _tuple1* f1; } ; extern
const int Cyc_Absyn_Primop_e_tag; struct Cyc_Absyn_Primop_e_struct{ int tag;
void* f1; struct Cyc_List_List* f2; } ; extern const int Cyc_Absyn_AssignOp_e_tag;
struct Cyc_Absyn_AssignOp_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; struct
Cyc_Core_Opt* f2; struct Cyc_Absyn_Exp* f3; } ; extern const int Cyc_Absyn_Increment_e_tag;
struct Cyc_Absyn_Increment_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; void* f2;
} ; extern const int Cyc_Absyn_Conditional_e_tag; struct Cyc_Absyn_Conditional_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Exp* f2; struct Cyc_Absyn_Exp*
f3; } ; extern const int Cyc_Absyn_SeqExp_e_tag; struct Cyc_Absyn_SeqExp_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Exp* f2; } ; extern const
int Cyc_Absyn_UnknownCall_e_tag; struct Cyc_Absyn_UnknownCall_e_struct{ int tag;
struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; extern const int Cyc_Absyn_FnCall_e_tag;
struct Cyc_Absyn_FnCall_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_List_List*
f2; } ; extern const int Cyc_Absyn_Throw_e_tag; struct Cyc_Absyn_Throw_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; extern const int Cyc_Absyn_NoInstantiate_e_tag;
struct Cyc_Absyn_NoInstantiate_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
extern const int Cyc_Absyn_Instantiate_e_tag; struct Cyc_Absyn_Instantiate_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; extern const
int Cyc_Absyn_Cast_e_tag; struct Cyc_Absyn_Cast_e_struct{ int tag; void* f1;
struct Cyc_Absyn_Exp* f2; } ; extern const int Cyc_Absyn_Address_e_tag; struct
Cyc_Absyn_Address_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ; extern const
int Cyc_Absyn_Sizeof_e_tag; struct Cyc_Absyn_Sizeof_e_struct{ int tag; void* f1;
} ; extern const int Cyc_Absyn_Deref_e_tag; struct Cyc_Absyn_Deref_e_struct{ int
tag; struct Cyc_Absyn_Exp* f1; } ; extern const int Cyc_Absyn_StructMember_e_tag;
struct Cyc_Absyn_StructMember_e_struct{ int tag; struct Cyc_Absyn_Exp* f1;
struct _tagged_string* f2; } ; extern const int Cyc_Absyn_StructArrow_e_tag;
struct Cyc_Absyn_StructArrow_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; struct
_tagged_string* f2; } ; extern const int Cyc_Absyn_Subscript_e_tag; struct Cyc_Absyn_Subscript_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Exp* f2; } ; extern const
int Cyc_Absyn_Tuple_e_tag; struct Cyc_Absyn_Tuple_e_struct{ int tag; struct Cyc_List_List*
f1; } ; extern const int Cyc_Absyn_CompoundLit_e_tag; struct Cyc_Absyn_CompoundLit_e_struct{
int tag; struct _tuple2* f1; struct Cyc_List_List* f2; } ; extern const int Cyc_Absyn_Array_e_tag;
struct Cyc_Absyn_Array_e_struct{ int tag; int f1; struct Cyc_List_List* f2; } ;
extern const int Cyc_Absyn_Comprehension_e_tag; struct Cyc_Absyn_Comprehension_e_struct{
int tag; struct Cyc_Absyn_Vardecl* f1; struct Cyc_Absyn_Exp* f2; struct Cyc_Absyn_Exp*
f3; } ; extern const int Cyc_Absyn_Struct_e_tag; struct Cyc_Absyn_Struct_e_struct{
int tag; struct _tuple1* f1; struct Cyc_Core_Opt* f2; struct Cyc_List_List* f3;
struct Cyc_Absyn_Structdecl* f4; } ; extern const int Cyc_Absyn_Enum_e_tag;
struct Cyc_Absyn_Enum_e_struct{ int tag; struct Cyc_Core_Opt* f1; struct Cyc_Core_Opt*
f2; struct Cyc_List_List* f3; struct Cyc_Absyn_Enumdecl* f4; struct Cyc_Absyn_Enumfield*
f5; } ; extern const int Cyc_Absyn_Xenum_e_tag; struct Cyc_Absyn_Xenum_e_struct{
int tag; struct Cyc_Core_Opt* f1; struct Cyc_List_List* f2; struct Cyc_Absyn_Xenumdecl*
f3; struct Cyc_Absyn_Enumfield* f4; } ; extern const int Cyc_Absyn_UnresolvedMem_e_tag;
struct Cyc_Absyn_UnresolvedMem_e_struct{ int tag; struct Cyc_Core_Opt* f1;
struct Cyc_List_List* f2; } ; extern const int Cyc_Absyn_StmtExp_e_tag; struct
Cyc_Absyn_StmtExp_e_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; extern const
int Cyc_Absyn_Codegen_e_tag; struct Cyc_Absyn_Codegen_e_struct{ int tag; struct
Cyc_Absyn_Fndecl* f1; } ; extern const int Cyc_Absyn_Fill_e_tag; struct Cyc_Absyn_Fill_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; struct Cyc_Absyn_Exp{ struct Cyc_Core_Opt*
topt; void* r; struct Cyc_Position_Segment* loc; } ; extern void* Cyc_Absyn_Skip_s;
extern const int Cyc_Absyn_Exp_s_tag; struct Cyc_Absyn_Exp_s_struct{ int tag;
struct Cyc_Absyn_Exp* f1; } ; extern const int Cyc_Absyn_Seq_s_tag; struct Cyc_Absyn_Seq_s_struct{
int tag; struct Cyc_Absyn_Stmt* f1; struct Cyc_Absyn_Stmt* f2; } ; extern const
int Cyc_Absyn_Return_s_tag; struct Cyc_Absyn_Return_s_struct{ int tag; struct
Cyc_Absyn_Exp* f1; } ; extern const int Cyc_Absyn_IfThenElse_s_tag; struct Cyc_Absyn_IfThenElse_s_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Stmt* f2; struct Cyc_Absyn_Stmt*
f3; } ; extern const int Cyc_Absyn_While_s_tag; struct Cyc_Absyn_While_s_struct{
int tag; struct _tuple3 f1; struct Cyc_Absyn_Stmt* f2; } ; extern const int Cyc_Absyn_Break_s_tag;
struct Cyc_Absyn_Break_s_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; extern
const int Cyc_Absyn_Continue_s_tag; struct Cyc_Absyn_Continue_s_struct{ int tag;
struct Cyc_Absyn_Stmt* f1; } ; extern const int Cyc_Absyn_Goto_s_tag; struct Cyc_Absyn_Goto_s_struct{
int tag; struct _tagged_string* f1; struct Cyc_Absyn_Stmt* f2; } ; extern const
int Cyc_Absyn_For_s_tag; struct Cyc_Absyn_For_s_struct{ int tag; struct Cyc_Absyn_Exp*
f1; struct _tuple3 f2; struct _tuple3 f3; struct Cyc_Absyn_Stmt* f4; } ; extern
const int Cyc_Absyn_Switch_s_tag; struct Cyc_Absyn_Switch_s_struct{ int tag;
struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; extern const int Cyc_Absyn_Fallthru_s_tag;
struct Cyc_Absyn_Fallthru_s_struct{ int tag; struct Cyc_List_List* f1; struct
Cyc_Absyn_Switch_clause** f2; } ; extern const int Cyc_Absyn_Decl_s_tag; struct
Cyc_Absyn_Decl_s_struct{ int tag; struct Cyc_Absyn_Decl* f1; struct Cyc_Absyn_Stmt*
f2; } ; extern const int Cyc_Absyn_Cut_s_tag; struct Cyc_Absyn_Cut_s_struct{ int
tag; struct Cyc_Absyn_Stmt* f1; } ; extern const int Cyc_Absyn_Splice_s_tag;
struct Cyc_Absyn_Splice_s_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; extern
const int Cyc_Absyn_Label_s_tag; struct Cyc_Absyn_Label_s_struct{ int tag;
struct _tagged_string* f1; struct Cyc_Absyn_Stmt* f2; } ; extern const int Cyc_Absyn_Do_s_tag;
struct Cyc_Absyn_Do_s_struct{ int tag; struct Cyc_Absyn_Stmt* f1; struct _tuple3
f2; } ; extern const int Cyc_Absyn_TryCatch_s_tag; struct Cyc_Absyn_TryCatch_s_struct{
int tag; struct Cyc_Absyn_Stmt* f1; struct Cyc_List_List* f2; } ; struct Cyc_Absyn_Stmt{
void* r; struct Cyc_Position_Segment* loc; struct Cyc_List_List* non_local_preds;
int try_depth; struct _xenum_struct* annot; } ; extern void* Cyc_Absyn_Wild_p;
extern const int Cyc_Absyn_Var_p_tag; struct Cyc_Absyn_Var_p_struct{ int tag;
struct Cyc_Absyn_Vardecl* f1; } ; extern void* Cyc_Absyn_Null_p; extern const
int Cyc_Absyn_Int_p_tag; struct Cyc_Absyn_Int_p_struct{ int tag; void* f1; int
f2; } ; extern const int Cyc_Absyn_Char_p_tag; struct Cyc_Absyn_Char_p_struct{
int tag; char f1; } ; extern const int Cyc_Absyn_Float_p_tag; struct Cyc_Absyn_Float_p_struct{
int tag; struct _tagged_string f1; } ; extern const int Cyc_Absyn_Tuple_p_tag;
struct Cyc_Absyn_Tuple_p_struct{ int tag; struct Cyc_List_List* f1; } ; extern
const int Cyc_Absyn_Pointer_p_tag; struct Cyc_Absyn_Pointer_p_struct{ int tag;
struct Cyc_Absyn_Pat* f1; } ; extern const int Cyc_Absyn_Reference_p_tag; struct
Cyc_Absyn_Reference_p_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ; extern
const int Cyc_Absyn_Struct_p_tag; struct Cyc_Absyn_Struct_p_struct{ int tag;
struct Cyc_Absyn_Structdecl* f1; struct Cyc_Core_Opt* f2; struct Cyc_List_List*
f3; struct Cyc_List_List* f4; } ; extern const int Cyc_Absyn_Enum_p_tag; struct
Cyc_Absyn_Enum_p_struct{ int tag; struct _tuple1* f1; struct Cyc_Core_Opt* f2;
struct Cyc_List_List* f3; struct Cyc_List_List* f4; struct Cyc_Absyn_Enumdecl*
f5; struct Cyc_Absyn_Enumfield* f6; } ; extern const int Cyc_Absyn_Xenum_p_tag;
struct Cyc_Absyn_Xenum_p_struct{ int tag; struct _tuple1* f1; struct Cyc_List_List*
f2; struct Cyc_List_List* f3; struct Cyc_Absyn_Xenumdecl* f4; struct Cyc_Absyn_Enumfield*
f5; } ; extern const int Cyc_Absyn_UnknownId_p_tag; struct Cyc_Absyn_UnknownId_p_struct{
int tag; struct _tuple1* f1; } ; extern const int Cyc_Absyn_UnknownCall_p_tag;
struct Cyc_Absyn_UnknownCall_p_struct{ int tag; struct _tuple1* f1; struct Cyc_List_List*
f2; struct Cyc_List_List* f3; } ; extern const int Cyc_Absyn_UnknownFields_p_tag;
struct Cyc_Absyn_UnknownFields_p_struct{ int tag; struct _tuple1* f1; struct Cyc_List_List*
f2; struct Cyc_List_List* f3; } ; struct Cyc_Absyn_Pat{ void* r; struct Cyc_Core_Opt*
topt; struct Cyc_Position_Segment* loc; } ; struct Cyc_Absyn_Switch_clause{
struct Cyc_Absyn_Pat* pattern; struct Cyc_Core_Opt* pat_vars; struct Cyc_Absyn_Exp*
where_clause; struct Cyc_Absyn_Stmt* body; struct Cyc_Position_Segment* loc; } ;
extern void* Cyc_Absyn_Unresolved_b; extern const int Cyc_Absyn_Global_b_tag;
struct Cyc_Absyn_Global_b_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ;
extern const int Cyc_Absyn_Funname_b_tag; struct Cyc_Absyn_Funname_b_struct{ int
tag; struct Cyc_Absyn_Fndecl* f1; } ; extern const int Cyc_Absyn_Param_b_tag;
struct Cyc_Absyn_Param_b_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ;
extern const int Cyc_Absyn_Local_b_tag; struct Cyc_Absyn_Local_b_struct{ int tag;
struct Cyc_Absyn_Vardecl* f1; } ; extern const int Cyc_Absyn_Pat_b_tag; struct
Cyc_Absyn_Pat_b_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ; struct Cyc_Absyn_Vardecl{
void* sc; struct _tuple1* name; struct Cyc_Absyn_Tqual* tq; void* type; struct
Cyc_Absyn_Exp* initializer; int shadow; struct Cyc_Core_Opt* region; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_Fndecl{ void* sc; int is_inline; struct _tuple1*
name; struct Cyc_List_List* tvs; struct Cyc_Core_Opt* effect; void* ret_type;
struct Cyc_List_List* args; int varargs; struct Cyc_Absyn_Stmt* body; struct Cyc_Core_Opt*
cached_typ; struct Cyc_Core_Opt* param_vardecls; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_Structfield{ struct _tagged_string* name;
struct Cyc_Absyn_Tqual* tq; void* type; struct Cyc_List_List* attributes; } ;
struct Cyc_Absyn_Structdecl{ void* sc; struct Cyc_Core_Opt* name; struct Cyc_List_List*
tvs; struct Cyc_Core_Opt* fields; struct Cyc_List_List* attributes; } ; struct
Cyc_Absyn_Enumfield{ struct _tuple1* name; struct Cyc_Absyn_Exp* tag; struct Cyc_List_List*
tvs; struct Cyc_List_List* typs; struct Cyc_Position_Segment* loc; } ; struct
Cyc_Absyn_Enumdecl{ void* sc; struct Cyc_Core_Opt* name; struct Cyc_List_List*
tvs; struct Cyc_Core_Opt* fields; } ; struct Cyc_Absyn_Xenumdecl{ void* sc;
struct _tuple1* name; struct Cyc_List_List* fields; } ; struct Cyc_Absyn_Typedefdecl{
struct _tuple1* name; struct Cyc_List_List* tvs; void* defn; } ; extern const
int Cyc_Absyn_Var_d_tag; struct Cyc_Absyn_Var_d_struct{ int tag; struct Cyc_Absyn_Vardecl*
f1; } ; extern const int Cyc_Absyn_Fn_d_tag; struct Cyc_Absyn_Fn_d_struct{ int
tag; struct Cyc_Absyn_Fndecl* f1; } ; extern const int Cyc_Absyn_Let_d_tag;
struct Cyc_Absyn_Let_d_struct{ int tag; struct Cyc_Absyn_Pat* f1; struct Cyc_Core_Opt*
f2; struct Cyc_Core_Opt* f3; struct Cyc_Absyn_Exp* f4; int f5; } ; extern const
int Cyc_Absyn_Struct_d_tag; struct Cyc_Absyn_Struct_d_struct{ int tag; struct
Cyc_Absyn_Structdecl* f1; } ; extern void* Cyc_Absyn_Union_d; extern const int
Cyc_Absyn_Enum_d_tag; struct Cyc_Absyn_Enum_d_struct{ int tag; struct Cyc_Absyn_Enumdecl*
f1; } ; extern const int Cyc_Absyn_Xenum_d_tag; struct Cyc_Absyn_Xenum_d_struct{
int tag; struct Cyc_Absyn_Xenumdecl* f1; } ; extern const int Cyc_Absyn_Typedef_d_tag;
struct Cyc_Absyn_Typedef_d_struct{ int tag; struct Cyc_Absyn_Typedefdecl* f1; }
; extern const int Cyc_Absyn_Namespace_d_tag; struct Cyc_Absyn_Namespace_d_struct{
int tag; struct _tagged_string* f1; struct Cyc_List_List* f2; } ; extern const
int Cyc_Absyn_Using_d_tag; struct Cyc_Absyn_Using_d_struct{ int tag; struct
_tuple1* f1; struct Cyc_List_List* f2; } ; extern const int Cyc_Absyn_ExternC_d_tag;
struct Cyc_Absyn_ExternC_d_struct{ int tag; struct Cyc_List_List* f1; } ; struct
Cyc_Absyn_Decl{ void* r; struct Cyc_Position_Segment* loc; } ; extern const int
Cyc_Absyn_ArrayElement_tag; struct Cyc_Absyn_ArrayElement_struct{ int tag;
struct Cyc_Absyn_Exp* f1; } ; extern const int Cyc_Absyn_FieldName_tag; struct
Cyc_Absyn_FieldName_struct{ int tag; struct _tagged_string* f1; } ; extern char
Cyc_Absyn_EmptyAnnot_tag[ 11u]; struct Cyc_Absyn_EmptyAnnot_struct{ char* tag; }
; extern int Cyc_Absyn_qvar_cmp( struct _tuple1*, struct _tuple1*); extern int
Cyc_Absyn_tvar_cmp( struct Cyc_Absyn_Tvar*, struct Cyc_Absyn_Tvar*); extern
struct Cyc_Absyn_Tqual* Cyc_Absyn_empty_tqual(); extern struct Cyc_Absyn_Conref*
Cyc_Absyn_new_conref( void* x); extern struct Cyc_Absyn_Conref* Cyc_Absyn_compress_conref(
struct Cyc_Absyn_Conref* x); extern void* Cyc_Absyn_conref_val( struct Cyc_Absyn_Conref*
x); extern void* Cyc_Absyn_new_evar( void*); extern void* Cyc_Absyn_uint_t;
extern void* Cyc_Absyn_ulong_t; extern void* Cyc_Absyn_sint_t; extern void* Cyc_Absyn_slong_t;
extern void* Cyc_Absyn_float_t; extern void* Cyc_Absyn_double_t; extern void*
Cyc_Absyn_atb_typ( void* t, void* rgn, struct Cyc_Absyn_Tqual* tq, void* b);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_new_exp( void*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_copy_exp( struct Cyc_Absyn_Exp*); extern
struct Cyc_Absyn_Exp* Cyc_Absyn_signed_int_exp( int, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_uint_exp( unsigned int, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Structfield* Cyc_Absyn_lookup_struct_field( struct Cyc_Absyn_Structdecl*,
struct _tagged_string*); extern struct _tuple4* Cyc_Absyn_lookup_tuple_field(
struct Cyc_List_List*, int); extern struct _tagged_string Cyc_Absyn_attribute2string(
void*); struct Cyc_PP_Ppstate; typedef struct Cyc_PP_Ppstate* Cyc_PP_ppstate_t;
struct Cyc_PP_Out; typedef struct Cyc_PP_Out* Cyc_PP_out_t; struct Cyc_PP_Doc;
typedef struct Cyc_PP_Doc* Cyc_PP_doc_t; extern struct _tagged_string Cyc_Absynpp_typ2string(
void*); extern struct _tagged_string Cyc_Absynpp_kind2string( void*); extern
struct _tagged_string Cyc_Absynpp_ckind2string( struct Cyc_Absyn_Conref*);
extern struct _tagged_string Cyc_Absynpp_qvar2string( struct _tuple1*); struct
Cyc_Set_Set; typedef struct Cyc_Set_Set* Cyc_Set_gset_t; typedef struct Cyc_Set_Set*
Cyc_Set_hset_t; typedef struct Cyc_Set_Set* Cyc_Set_set_t; extern char Cyc_Set_Absent_tag[
7u]; struct Cyc_Set_Absent_struct{ char* tag; } ; struct Cyc_Dict_Dict; typedef
struct Cyc_Dict_Dict* Cyc_Dict_hdict_t; typedef struct Cyc_Dict_Dict* Cyc_Dict_dict_t;
extern char Cyc_Dict_Present_tag[ 8u]; struct Cyc_Dict_Present_struct{ char* tag;
} ; extern char Cyc_Dict_Absent_tag[ 7u]; typedef void* Cyc_Tcenv_Resolved;
extern const int Cyc_Tcenv_VarRes_tag; struct Cyc_Tcenv_VarRes_struct{ int tag;
void* f1; } ; extern const int Cyc_Tcenv_StructRes_tag; struct Cyc_Tcenv_StructRes_struct{
int tag; struct Cyc_Absyn_Structdecl* f1; } ; extern const int Cyc_Tcenv_EnumRes_tag;
struct Cyc_Tcenv_EnumRes_struct{ int tag; struct Cyc_Absyn_Enumdecl* f1; struct
Cyc_Absyn_Enumfield* f2; } ; extern const int Cyc_Tcenv_XenumRes_tag; struct Cyc_Tcenv_XenumRes_struct{
int tag; struct Cyc_Absyn_Xenumdecl* f1; struct Cyc_Absyn_Enumfield* f2; } ;
typedef void* Cyc_Tcenv_resolved_t; struct Cyc_Tcenv_Genv{ struct Cyc_Set_Set*
namespaces; struct Cyc_Dict_Dict* structdecls; struct Cyc_Dict_Dict* enumdecls;
struct Cyc_Dict_Dict* xenumdecls; struct Cyc_Dict_Dict* typedefs; struct Cyc_Dict_Dict*
ordinaries; struct Cyc_List_List* availables; } ; typedef struct Cyc_Tcenv_Genv*
Cyc_Tcenv_genv_t; struct Cyc_Tcenv_Fenv; typedef struct Cyc_Tcenv_Fenv* Cyc_Tcenv_fenv_t;
typedef void* Cyc_Tcenv_Jumpee; extern void* Cyc_Tcenv_NotLoop_j; extern void*
Cyc_Tcenv_CaseEnd_j; extern void* Cyc_Tcenv_FnEnd_j; extern const int Cyc_Tcenv_Stmt_j_tag;
struct Cyc_Tcenv_Stmt_j_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; typedef
void* Cyc_Tcenv_jumpee_t; typedef void* Cyc_Tcenv_Frames; extern const int Cyc_Tcenv_Outermost_tag;
struct Cyc_Tcenv_Outermost_struct{ int tag; void* f1; } ; extern const int Cyc_Tcenv_Frame_tag;
struct Cyc_Tcenv_Frame_struct{ int tag; void* f1; void* f2; } ; extern const int
Cyc_Tcenv_Hidden_tag; struct Cyc_Tcenv_Hidden_struct{ int tag; void* f1; void*
f2; } ; typedef void* Cyc_Tcenv_frames; struct Cyc_Tcenv_Tenv{ struct Cyc_List_List*
ns; struct Cyc_Dict_Dict* ae; struct Cyc_Core_Opt* le; } ; typedef struct Cyc_Tcenv_Tenv*
Cyc_Tcenv_tenv; typedef struct Cyc_Tcenv_Tenv* Cyc_Tcenv_tenv_t; extern struct
Cyc_Absyn_Structdecl** Cyc_Tcenv_lookup_structdecl( struct Cyc_Tcenv_Tenv*,
struct Cyc_Position_Segment*, struct _tuple1*); extern struct Cyc_Absyn_Enumdecl**
Cyc_Tcenv_lookup_enumdecl( struct Cyc_Tcenv_Tenv*, struct Cyc_Position_Segment*,
struct _tuple1*); extern struct Cyc_Core_Opt* Cyc_Tcenv_lookup_xenumdecl( struct
Cyc_Tcenv_Tenv*, struct Cyc_Position_Segment*, struct _tuple1*); extern struct
Cyc_Absyn_Typedefdecl* Cyc_Tcenv_lookup_typedefdecl( struct Cyc_Tcenv_Tenv*,
struct Cyc_Position_Segment*, struct _tuple1*); extern int Cyc_String_strcmp(
struct _tagged_string s1, struct _tagged_string s2); extern int Cyc_String_zstrptrcmp(
struct _tagged_string*, struct _tagged_string*); extern unsigned int Cyc_Evexp_eval_const_uint_exp(
struct Cyc_Absyn_Exp* e); extern char Cyc_Tcutil_TypeErr_tag[ 8u]; struct Cyc_Tcutil_TypeErr_struct{
char* tag; } ; extern void* Cyc_Tcutil_impos( struct _tagged_string); extern
void Cyc_Tcutil_terr( struct Cyc_Position_Segment*, struct _tagged_string);
extern void Cyc_Tcutil_warn( struct Cyc_Position_Segment*, struct _tagged_string);
extern void Cyc_Tcutil_flush_warnings(); extern struct Cyc_Core_Opt* Cyc_Tcutil_empty_var_set;
extern void* Cyc_Tcutil_typ_kind( void* t); extern void* Cyc_Tcutil_compress(
void* t); extern void Cyc_Tcutil_unchecked_cast( struct Cyc_Tcenv_Tenv*, struct
Cyc_Absyn_Exp*, void*); extern int Cyc_Tcutil_coerce_arg( struct Cyc_Tcenv_Tenv*,
struct Cyc_Absyn_Exp*, void*); extern int Cyc_Tcutil_coerce_assign( struct Cyc_Tcenv_Tenv*,
struct Cyc_Absyn_Exp*, void*); extern int Cyc_Tcutil_coerce_to_bool( struct Cyc_Tcenv_Tenv*,
struct Cyc_Absyn_Exp*); extern int Cyc_Tcutil_coerce_list( struct Cyc_Tcenv_Tenv*,
void*, struct Cyc_List_List*); extern int Cyc_Tcutil_coerce_uint_typ( struct Cyc_Tcenv_Tenv*,
struct Cyc_Absyn_Exp*); extern int Cyc_Tcutil_coerce_sint_typ( struct Cyc_Tcenv_Tenv*,
struct Cyc_Absyn_Exp*); extern int Cyc_Tcutil_coerce_use( struct Cyc_Tcenv_Tenv*,
struct Cyc_Absyn_Exp*, void*); extern int Cyc_Tcutil_coerceable( void*); extern
int Cyc_Tcutil_silent_castable( struct Cyc_Tcenv_Tenv*, struct Cyc_Position_Segment*,
void*, void*); extern int Cyc_Tcutil_castable( struct Cyc_Tcenv_Tenv*, struct
Cyc_Position_Segment*, void*, void*); extern int Cyc_Tcutil_integral_promote(
struct Cyc_Tcenv_Tenv*, struct Cyc_Absyn_Exp*); extern int Cyc_Tcutil_arithmetic_promote(
struct Cyc_Tcenv_Tenv*, struct Cyc_Absyn_Exp*); extern int Cyc_Tcutil_comparison_promote(
struct Cyc_Tcenv_Tenv*, struct Cyc_Absyn_Exp*); extern void* Cyc_Tcutil_max_arithmetic_type(
void*, void*); extern int Cyc_Tcutil_unify( void*, void*); extern void* Cyc_Tcutil_substitute(
struct Cyc_List_List*, void*); extern int Cyc_Tcutil_subset_effect( int
set_to_empty, void* e1, void* e2); extern int Cyc_Tcutil_region_in_effect( int
constrain, void* r, void* e); extern void* Cyc_Tcutil_fndecl2typ( struct Cyc_Absyn_Fndecl*);
extern struct Cyc_Absyn_Exp* Cyc_Tcutil_default_initializer( struct Cyc_Tcenv_Tenv*,
void*, struct Cyc_Position_Segment*); extern struct _tuple5* Cyc_Tcutil_make_inst_var(
struct Cyc_Absyn_Tvar*); extern void Cyc_Tcutil_check_contains_assign( struct
Cyc_Absyn_Exp*); extern struct Cyc_List_List* Cyc_Tcutil_check_valid_type(
struct Cyc_Position_Segment*, struct Cyc_Tcenv_Tenv*, struct Cyc_List_List*,
void* k, void*); extern void Cyc_Tcutil_check_valid_toplevel_type( struct Cyc_Position_Segment*,
struct Cyc_Tcenv_Tenv*, void*); extern void Cyc_Tcutil_check_fndecl_valid_type(
struct Cyc_Position_Segment*, struct Cyc_Tcenv_Tenv*, struct Cyc_Absyn_Fndecl*);
extern void Cyc_Tcutil_check_type( struct Cyc_Position_Segment*, struct Cyc_Tcenv_Tenv*,
struct Cyc_List_List* bound_tvars, void* k, void*); extern void Cyc_Tcutil_check_unique_vars(
struct Cyc_List_List* vs, struct Cyc_Position_Segment* loc, struct
_tagged_string err_msg); extern void Cyc_Tcutil_check_unique_tvars( struct Cyc_Position_Segment*,
struct Cyc_List_List*); extern void Cyc_Tcutil_check_nonzero_bound( struct Cyc_Position_Segment*,
struct Cyc_Absyn_Conref*); extern void Cyc_Tcutil_check_bound( struct Cyc_Position_Segment*,
unsigned int i, struct Cyc_Absyn_Conref*); extern int Cyc_Tcutil_equal_tqual(
struct Cyc_Absyn_Tqual* tq1, struct Cyc_Absyn_Tqual* tq2); extern struct Cyc_List_List*
Cyc_Tcutil_resolve_struct_designators( struct Cyc_Position_Segment* loc, struct
Cyc_List_List* des, struct Cyc_Absyn_Structdecl* sd); extern int Cyc_Tcutil_is_tagged_pointer_typ(
void*); extern void* Cyc_Tcutil_array_to_ptr( struct Cyc_Tcenv_Tenv*, void* t,
struct Cyc_Absyn_Exp* e); extern struct _tuple6 Cyc_Tcutil_addressof_props(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e); extern struct Cyc_Absyn_Tvar*
Cyc_Tcutil_new_tvar( void* k); extern int Cyc_Tcutil_same_atts( struct Cyc_List_List*,
struct Cyc_List_List*); char Cyc_Tcutil_TypeErr_tag[ 8u]="TypeErr"; extern void
Cyc_Tcutil_unify_it( void* t1, void* t2); void Cyc_Tcutil_terr( struct Cyc_Position_Segment*
loc, struct _tagged_string s){ Cyc_Position_post_error( Cyc_Position_mk_err_elab(
loc, s));} void* Cyc_Tcutil_impos( struct _tagged_string msg){({ struct
_tagged_string _temp0= msg; fprintf( Cyc_Stdio_stderr,"Error: %.*s\n", _temp0.last_plus_one
- _temp0.curr, _temp0.curr);}); Cyc_Stdio_fflush(( struct Cyc_Stdio___sFILE*)
Cyc_Stdio_stderr);( void) _throw(({ struct Cyc_Tcutil_TypeErr_struct* _temp1=(
struct Cyc_Tcutil_TypeErr_struct*) GC_malloc_atomic( sizeof( struct Cyc_Tcutil_TypeErr_struct));*
_temp1=( struct Cyc_Tcutil_TypeErr_struct){.tag= Cyc_Tcutil_TypeErr_tag};(
struct _xenum_struct*) _temp1;}));} static struct _tagged_string Cyc_Tcutil_tvar2string(
struct Cyc_Absyn_Tvar* tv){ return* tv->name;} void Cyc_Tcutil_print_tvars(
struct Cyc_List_List* tvs){ for( 0; tvs != 0; tvs= tvs->tl){({ struct
_tagged_string _temp2= Cyc_Tcutil_tvar2string(( struct Cyc_Absyn_Tvar*) tvs->hd);
struct _tagged_string _temp3= Cyc_Absynpp_ckind2string((( struct Cyc_Absyn_Tvar*)
tvs->hd)->kind); fprintf( Cyc_Stdio_stderr,"%.*s::%.*s ", _temp2.last_plus_one -
_temp2.curr, _temp2.curr, _temp3.last_plus_one - _temp3.curr, _temp3.curr);});}
fprintf( Cyc_Stdio_stderr,"\n"); Cyc_Stdio_fflush(( struct Cyc_Stdio___sFILE*)
Cyc_Stdio_stderr);} static struct Cyc_List_List* Cyc_Tcutil_warning_segs= 0;
static struct Cyc_List_List* Cyc_Tcutil_warning_msgs= 0; void Cyc_Tcutil_warn(
struct Cyc_Position_Segment* sg, struct _tagged_string msg){ Cyc_Tcutil_warning_segs=({
struct Cyc_List_List* _temp4=( struct Cyc_List_List*) GC_malloc( sizeof( struct
Cyc_List_List)); _temp4->hd=( void*) sg; _temp4->tl= Cyc_Tcutil_warning_segs;
_temp4;}); Cyc_Tcutil_warning_msgs=({ struct Cyc_List_List* _temp5=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5->hd=( void*)(( struct
_tagged_string*)({ struct _tagged_string* _temp6=( struct _tagged_string*)
GC_malloc( sizeof( struct _tagged_string) * 1); _temp6[ 0]= msg; _temp6;}));
_temp5->tl= Cyc_Tcutil_warning_msgs; _temp5;});} void Cyc_Tcutil_flush_warnings(){
if( Cyc_Tcutil_warning_segs == 0){ return;} fprintf( Cyc_Stdio_stderr,"***Warnings***\n");{
struct Cyc_List_List* seg_strs= Cyc_Position_strings_of_segments( Cyc_Tcutil_warning_segs);
Cyc_Tcutil_warning_segs= 0; Cyc_Tcutil_warning_msgs=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_Tcutil_warning_msgs); while(
Cyc_Tcutil_warning_msgs != 0) {({ struct _tagged_string _temp7=*(( struct
_tagged_string*) seg_strs->hd); struct _tagged_string _temp8=*(( struct
_tagged_string*) Cyc_Tcutil_warning_msgs->hd); fprintf( Cyc_Stdio_stderr,"%.*s: %.*s\n",
_temp7.last_plus_one - _temp7.curr, _temp7.curr, _temp8.last_plus_one - _temp8.curr,
_temp8.curr);}); seg_strs= seg_strs->tl; Cyc_Tcutil_warning_msgs= Cyc_Tcutil_warning_msgs->tl;}
fprintf( Cyc_Stdio_stderr,"**************\n"); Cyc_Stdio_fflush(( struct Cyc_Stdio___sFILE*)
Cyc_Stdio_stderr);}} struct Cyc_Core_Opt* Cyc_Tcutil_empty_var_set= 0; void* Cyc_Tcutil_compress(
void* t){ void* _temp9= t; int _temp21; struct Cyc_Core_Opt* _temp23; void*
_temp25; int _temp27; struct Cyc_Core_Opt* _temp29; struct Cyc_Core_Opt**
_temp31; void* _temp32; struct Cyc_Core_Opt* _temp34; struct Cyc_List_List*
_temp36; struct _tuple1* _temp38; struct Cyc_Core_Opt* _temp40; struct Cyc_Core_Opt**
_temp42; struct Cyc_List_List* _temp43; struct _tuple1* _temp45; _LL11: if((
unsigned int) _temp9 > 5u?(( struct _enum_struct*) _temp9)->tag == Cyc_Absyn_Evar_tag:
0){ _LL26: _temp25=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp9)->f1; goto
_LL24; _LL24: _temp23=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp9)->f2; if( _temp23 == 0){ goto _LL22;} else{ goto _LL13;} _LL22: _temp21=(
int)(( struct Cyc_Absyn_Evar_struct*) _temp9)->f3; goto _LL12;} else{ goto _LL13;}
_LL13: if(( unsigned int) _temp9 > 5u?(( struct _enum_struct*) _temp9)->tag ==
Cyc_Absyn_Evar_tag: 0){ _LL33: _temp32=( void*)(( struct Cyc_Absyn_Evar_struct*)
_temp9)->f1; goto _LL30; _LL30: _temp29=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp9)->f2; _temp31=&(( struct Cyc_Absyn_Evar_struct*) _temp9)->f2; goto _LL28;
_LL28: _temp27=( int)(( struct Cyc_Absyn_Evar_struct*) _temp9)->f3; goto _LL14;}
else{ goto _LL15;} _LL15: if(( unsigned int) _temp9 > 5u?(( struct _enum_struct*)
_temp9)->tag == Cyc_Absyn_TypedefType_tag: 0){ _LL39: _temp38=( struct _tuple1*)((
struct Cyc_Absyn_TypedefType_struct*) _temp9)->f1; goto _LL37; _LL37: _temp36=(
struct Cyc_List_List*)(( struct Cyc_Absyn_TypedefType_struct*) _temp9)->f2; goto
_LL35; _LL35: _temp34=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp9)->f3; if( _temp34 == 0){ goto _LL16;} else{ goto _LL17;}} else{ goto
_LL17;} _LL17: if(( unsigned int) _temp9 > 5u?(( struct _enum_struct*) _temp9)->tag
== Cyc_Absyn_TypedefType_tag: 0){ _LL46: _temp45=( struct _tuple1*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp9)->f1; goto _LL44; _LL44: _temp43=( struct Cyc_List_List*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp9)->f2; goto _LL41; _LL41: _temp40=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp9)->f3; _temp42=&(( struct Cyc_Absyn_TypedefType_struct*) _temp9)->f3; goto
_LL18;} else{ goto _LL19;} _LL19: goto _LL20; _LL12: return t; _LL14: { void* t2=
Cyc_Tcutil_compress(( void*)(* _temp31)->v); if( t2 !=( void*)(* _temp31)->v){*
_temp31=({ struct Cyc_Core_Opt* _temp47=( struct Cyc_Core_Opt*) GC_malloc(
sizeof( struct Cyc_Core_Opt)); _temp47->v=( void*) t2; _temp47;});} return t2;}
_LL16: return t; _LL18: { void* t2= Cyc_Tcutil_compress(( void*)(* _temp42)->v);
if( t2 !=( void*)(* _temp42)->v){* _temp42=({ struct Cyc_Core_Opt* _temp48=(
struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp48->v=(
void*) t2; _temp48;});} return t2;} _LL20: return t; _LL10:;} static int Cyc_Tcutil_kind_leq(
void* k1, void* k2){ if( k1 == k2){ return 1;}{ struct _tuple7 _temp50=({ struct
_tuple7 _temp49; _temp49.f1= k1; _temp49.f2= k2; _temp49;}); void* _temp60; void*
_temp62; void* _temp64; void* _temp66; void* _temp68; void* _temp70; _LL52:
_LL63: _temp62= _temp50.f1; if( _temp62 == Cyc_Absyn_BoxKind){ goto _LL61;}
else{ goto _LL54;} _LL61: _temp60= _temp50.f2; if( _temp60 == Cyc_Absyn_MemKind){
goto _LL53;} else{ goto _LL54;} _LL54: _LL67: _temp66= _temp50.f1; if( _temp66
== Cyc_Absyn_BoxKind){ goto _LL65;} else{ goto _LL56;} _LL65: _temp64= _temp50.f2;
if( _temp64 == Cyc_Absyn_AnyKind){ goto _LL55;} else{ goto _LL56;} _LL56: _LL71:
_temp70= _temp50.f1; if( _temp70 == Cyc_Absyn_MemKind){ goto _LL69;} else{ goto
_LL58;} _LL69: _temp68= _temp50.f2; if( _temp68 == Cyc_Absyn_AnyKind){ goto
_LL57;} else{ goto _LL58;} _LL58: goto _LL59; _LL53: return 1; _LL55: return 1;
_LL57: return 1; _LL59: return 0; _LL51:;}} void* Cyc_Tcutil_typ_kind( void* t){
void* _temp72= Cyc_Tcutil_compress( t); int _temp114; struct Cyc_Core_Opt*
_temp116; void* _temp118; struct Cyc_Absyn_Tvar* _temp120; void* _temp122; void*
_temp124; struct Cyc_Absyn_FnInfo _temp126; void* _temp128; struct Cyc_Absyn_Enumdecl**
_temp130; struct Cyc_List_List* _temp132; struct _tuple1* _temp134; struct Cyc_Absyn_Xenumdecl**
_temp136; struct _tuple1* _temp138; struct Cyc_Absyn_Structdecl** _temp140;
struct Cyc_List_List* _temp142; struct _tuple1* _temp144; struct Cyc_Absyn_Structdecl**
_temp146; struct Cyc_List_List* _temp148; struct _tuple1* _temp150; struct Cyc_Absyn_PtrInfo
_temp152; struct Cyc_Absyn_Exp* _temp154; struct Cyc_Absyn_Tqual* _temp156; void*
_temp158; struct Cyc_List_List* _temp160; struct Cyc_Core_Opt* _temp162; struct
Cyc_List_List* _temp164; struct _tuple1* _temp166; void* _temp168; struct Cyc_List_List*
_temp170; _LL74: if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*)
_temp72)->tag == Cyc_Absyn_Evar_tag: 0){ _LL119: _temp118=( void*)(( struct Cyc_Absyn_Evar_struct*)
_temp72)->f1; goto _LL117; _LL117: _temp116=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp72)->f2; goto _LL115; _LL115: _temp114=( int)(( struct Cyc_Absyn_Evar_struct*)
_temp72)->f3; goto _LL75;} else{ goto _LL76;} _LL76: if(( unsigned int) _temp72
> 5u?(( struct _enum_struct*) _temp72)->tag == Cyc_Absyn_VarType_tag: 0){ _LL121:
_temp120=( struct Cyc_Absyn_Tvar*)(( struct Cyc_Absyn_VarType_struct*) _temp72)->f1;
goto _LL77;} else{ goto _LL78;} _LL78: if( _temp72 == Cyc_Absyn_VoidType){ goto
_LL79;} else{ goto _LL80;} _LL80: if(( unsigned int) _temp72 > 5u?(( struct
_enum_struct*) _temp72)->tag == Cyc_Absyn_IntType_tag: 0){ _LL125: _temp124=(
void*)(( struct Cyc_Absyn_IntType_struct*) _temp72)->f1; goto _LL123; _LL123:
_temp122=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp72)->f2; goto _LL81;}
else{ goto _LL82;} _LL82: if( _temp72 == Cyc_Absyn_FloatType){ goto _LL83;}
else{ goto _LL84;} _LL84: if( _temp72 == Cyc_Absyn_DoubleType){ goto _LL85;}
else{ goto _LL86;} _LL86: if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*)
_temp72)->tag == Cyc_Absyn_FnType_tag: 0){ _LL127: _temp126=( struct Cyc_Absyn_FnInfo)((
struct Cyc_Absyn_FnType_struct*) _temp72)->f1; goto _LL87;} else{ goto _LL88;}
_LL88: if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*) _temp72)->tag ==
Cyc_Absyn_RgnHandleType_tag: 0){ _LL129: _temp128=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*)
_temp72)->f1; goto _LL89;} else{ goto _LL90;} _LL90: if( _temp72 == Cyc_Absyn_HeapRgn){
goto _LL91;} else{ goto _LL92;} _LL92: if(( unsigned int) _temp72 > 5u?(( struct
_enum_struct*) _temp72)->tag == Cyc_Absyn_EnumType_tag: 0){ _LL135: _temp134=(
struct _tuple1*)(( struct Cyc_Absyn_EnumType_struct*) _temp72)->f1; goto _LL133;
_LL133: _temp132=( struct Cyc_List_List*)(( struct Cyc_Absyn_EnumType_struct*)
_temp72)->f2; goto _LL131; _LL131: _temp130=( struct Cyc_Absyn_Enumdecl**)((
struct Cyc_Absyn_EnumType_struct*) _temp72)->f3; goto _LL93;} else{ goto _LL94;}
_LL94: if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*) _temp72)->tag ==
Cyc_Absyn_XenumType_tag: 0){ _LL139: _temp138=( struct _tuple1*)(( struct Cyc_Absyn_XenumType_struct*)
_temp72)->f1; goto _LL137; _LL137: _temp136=( struct Cyc_Absyn_Xenumdecl**)((
struct Cyc_Absyn_XenumType_struct*) _temp72)->f2; goto _LL95;} else{ goto _LL96;}
_LL96: if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*) _temp72)->tag ==
Cyc_Absyn_StructType_tag: 0){ _LL145: _temp144=( struct _tuple1*)(( struct Cyc_Absyn_StructType_struct*)
_temp72)->f1; goto _LL143; _LL143: _temp142=( struct Cyc_List_List*)(( struct
Cyc_Absyn_StructType_struct*) _temp72)->f2; goto _LL141; _LL141: _temp140=(
struct Cyc_Absyn_Structdecl**)(( struct Cyc_Absyn_StructType_struct*) _temp72)->f3;
if( _temp140 == 0){ goto _LL97;} else{ goto _LL98;}} else{ goto _LL98;} _LL98:
if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*) _temp72)->tag == Cyc_Absyn_StructType_tag:
0){ _LL151: _temp150=( struct _tuple1*)(( struct Cyc_Absyn_StructType_struct*)
_temp72)->f1; goto _LL149; _LL149: _temp148=( struct Cyc_List_List*)(( struct
Cyc_Absyn_StructType_struct*) _temp72)->f2; goto _LL147; _LL147: _temp146=(
struct Cyc_Absyn_Structdecl**)(( struct Cyc_Absyn_StructType_struct*) _temp72)->f3;
goto _LL99;} else{ goto _LL100;} _LL100: if(( unsigned int) _temp72 > 5u?((
struct _enum_struct*) _temp72)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL153:
_temp152=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp72)->f1; goto _LL101;} else{ goto _LL102;} _LL102: if(( unsigned int)
_temp72 > 5u?(( struct _enum_struct*) _temp72)->tag == Cyc_Absyn_ArrayType_tag:
0){ _LL159: _temp158=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp72)->f1;
goto _LL157; _LL157: _temp156=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp72)->f2; goto _LL155; _LL155: _temp154=( struct Cyc_Absyn_Exp*)(( struct
Cyc_Absyn_ArrayType_struct*) _temp72)->f3; goto _LL103;} else{ goto _LL104;}
_LL104: if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*) _temp72)->tag
== Cyc_Absyn_TupleType_tag: 0){ _LL161: _temp160=( struct Cyc_List_List*)((
struct Cyc_Absyn_TupleType_struct*) _temp72)->f1; goto _LL105;} else{ goto
_LL106;} _LL106: if(( unsigned int) _temp72 > 5u?(( struct _enum_struct*)
_temp72)->tag == Cyc_Absyn_TypedefType_tag: 0){ _LL167: _temp166=( struct
_tuple1*)(( struct Cyc_Absyn_TypedefType_struct*) _temp72)->f1; goto _LL165;
_LL165: _temp164=( struct Cyc_List_List*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp72)->f2; goto _LL163; _LL163: _temp162=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp72)->f3; goto _LL107;} else{ goto _LL108;} _LL108: if( _temp72 == Cyc_Absyn_UnionType){
goto _LL109;} else{ goto _LL110;} _LL110: if(( unsigned int) _temp72 > 5u?((
struct _enum_struct*) _temp72)->tag == Cyc_Absyn_AccessEff_tag: 0){ _LL169:
_temp168=( void*)(( struct Cyc_Absyn_AccessEff_struct*) _temp72)->f1; goto
_LL111;} else{ goto _LL112;} _LL112: if(( unsigned int) _temp72 > 5u?(( struct
_enum_struct*) _temp72)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL171: _temp170=(
struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*) _temp72)->f1; goto
_LL113;} else{ goto _LL73;} _LL75: return _temp118; _LL77: return(( void*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)( _temp120->kind); _LL79:
return Cyc_Absyn_MemKind; _LL81: return _temp122 == Cyc_Absyn_B4? Cyc_Absyn_BoxKind:
Cyc_Absyn_MemKind; _LL83: return Cyc_Absyn_MemKind; _LL85: return Cyc_Absyn_MemKind;
_LL87: return Cyc_Absyn_MemKind; _LL89: return Cyc_Absyn_BoxKind; _LL91: return
Cyc_Absyn_RgnKind; _LL93: return Cyc_Absyn_BoxKind; _LL95: return Cyc_Absyn_BoxKind;
_LL97: return Cyc_Absyn_AnyKind; _LL99: return Cyc_Absyn_MemKind; _LL101: { void*
_temp172=( void*)((( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x))
Cyc_Absyn_compress_conref)( _temp152.bounds))->v; void* _temp182; void* _temp184;
struct Cyc_Absyn_Exp* _temp186; struct Cyc_Absyn_Conref* _temp188; _LL174: if((
unsigned int) _temp172 > 1u?(( struct _enum_struct*) _temp172)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL183: _temp182=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp172)->f1;
if( _temp182 == Cyc_Absyn_Unknown_b){ goto _LL175;} else{ goto _LL176;}} else{
goto _LL176;} _LL176: if(( unsigned int) _temp172 > 1u?(( struct _enum_struct*)
_temp172)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL185: _temp184=( void*)((
struct Cyc_Absyn_Eq_constr_struct*) _temp172)->f1; if(( unsigned int) _temp184 >
1u?(( struct _enum_struct*) _temp184)->tag == Cyc_Absyn_Upper_b_tag: 0){ _LL187:
_temp186=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*) _temp184)->f1;
goto _LL177;} else{ goto _LL178;}} else{ goto _LL178;} _LL178: if( _temp172 ==
Cyc_Absyn_No_constr){ goto _LL179;} else{ goto _LL180;} _LL180: if((
unsigned int) _temp172 > 1u?(( struct _enum_struct*) _temp172)->tag == Cyc_Absyn_Forward_constr_tag:
0){ _LL189: _temp188=( struct Cyc_Absyn_Conref*)(( struct Cyc_Absyn_Forward_constr_struct*)
_temp172)->f1; goto _LL181;} else{ goto _LL173;} _LL175: return Cyc_Absyn_MemKind;
_LL177: return Cyc_Absyn_BoxKind; _LL179: return Cyc_Absyn_MemKind; _LL181:
return(( void*(*)( struct _tagged_string msg)) Cyc_Tcutil_impos)(( struct
_tagged_string)({ char* _temp190=( char*)"typ_kind: forward constraint in ptr bounds";
struct _tagged_string _temp191; _temp191.curr= _temp190; _temp191.base= _temp190;
_temp191.last_plus_one= _temp190 + 43; _temp191;})); _LL173:;} _LL103: return
Cyc_Absyn_MemKind; _LL105: return Cyc_Absyn_MemKind; _LL107: return(( void*(*)(
struct _tagged_string msg)) Cyc_Tcutil_impos)(({ struct _tagged_string _temp192=
Cyc_Absynpp_typ2string( t); xprintf("typ_kind: typedef found: %.*s", _temp192.last_plus_one
- _temp192.curr, _temp192.curr);})); _LL109: return(( void*(*)( struct
_tagged_string msg)) Cyc_Tcutil_impos)(( struct _tagged_string)({ char* _temp193=(
char*)"union type"; struct _tagged_string _temp194; _temp194.curr= _temp193;
_temp194.base= _temp193; _temp194.last_plus_one= _temp193 + 11; _temp194;}));
_LL111: return Cyc_Absyn_EffKind; _LL113: return Cyc_Absyn_EffKind; _LL73:;}
char Cyc_Tcutil_Unify_tag[ 6u]="Unify"; struct Cyc_Tcutil_Unify_struct{ char*
tag; } ; int Cyc_Tcutil_unify( void* t1, void* t2){ struct _handler_cons
_temp195; _push_handler(& _temp195);{ struct _xenum_struct* _temp196=( struct
_xenum_struct*) setjmp( _temp195.handler); if( ! _temp196){ Cyc_Tcutil_unify_it(
t1, t2);{ int _temp197= 1; _npop_handler( 0u); return _temp197;}; _pop_handler();}
else{ struct _xenum_struct* _temp199= _temp196; _LL201: if( _temp199->tag == Cyc_Tcutil_Unify_tag){
goto _LL202;} else{ goto _LL203;} _LL203: goto _LL204; _LL202: return 0; _LL204:(
void) _throw( _temp199); _LL200:;}}} static void Cyc_Tcutil_occurslist( void*
evar, struct Cyc_List_List* ts); static void Cyc_Tcutil_occurs( void* evar, void*
t){ void* _temp205= Cyc_Tcutil_compress( t); int _temp231; struct Cyc_Core_Opt*
_temp233; void* _temp235; struct Cyc_Absyn_PtrInfo _temp237; struct Cyc_Absyn_Exp*
_temp239; struct Cyc_Absyn_Tqual* _temp241; void* _temp243; struct Cyc_Absyn_FnInfo
_temp245; struct Cyc_List_List* _temp247; int _temp249; struct Cyc_List_List*
_temp251; void* _temp253; struct Cyc_Core_Opt* _temp255; struct Cyc_List_List*
_temp257; struct Cyc_List_List* _temp259; void* _temp261; struct Cyc_Core_Opt*
_temp263; struct Cyc_List_List* _temp265; struct _tuple1* _temp267; struct Cyc_Absyn_Enumdecl**
_temp269; struct Cyc_List_List* _temp271; struct _tuple1* _temp273; struct Cyc_Absyn_Structdecl**
_temp275; struct Cyc_List_List* _temp277; struct _tuple1* _temp279; void*
_temp281; struct Cyc_List_List* _temp283; _LL207: if(( unsigned int) _temp205 >
5u?(( struct _enum_struct*) _temp205)->tag == Cyc_Absyn_Evar_tag: 0){ _LL236:
_temp235=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp205)->f1; goto _LL234;
_LL234: _temp233=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp205)->f2; goto _LL232; _LL232: _temp231=( int)(( struct Cyc_Absyn_Evar_struct*)
_temp205)->f3; goto _LL208;} else{ goto _LL209;} _LL209: if(( unsigned int)
_temp205 > 5u?(( struct _enum_struct*) _temp205)->tag == Cyc_Absyn_PointerType_tag:
0){ _LL238: _temp237=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp205)->f1; goto _LL210;} else{ goto _LL211;} _LL211: if(( unsigned int)
_temp205 > 5u?(( struct _enum_struct*) _temp205)->tag == Cyc_Absyn_ArrayType_tag:
0){ _LL244: _temp243=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp205)->f1;
goto _LL242; _LL242: _temp241=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp205)->f2; goto _LL240; _LL240: _temp239=( struct Cyc_Absyn_Exp*)(( struct
Cyc_Absyn_ArrayType_struct*) _temp205)->f3; goto _LL212;} else{ goto _LL213;}
_LL213: if(( unsigned int) _temp205 > 5u?(( struct _enum_struct*) _temp205)->tag
== Cyc_Absyn_FnType_tag: 0){ _LL246: _temp245=( struct Cyc_Absyn_FnInfo)((
struct Cyc_Absyn_FnType_struct*) _temp205)->f1; _LL258: _temp257=( struct Cyc_List_List*)
_temp245.tvars; goto _LL256; _LL256: _temp255=( struct Cyc_Core_Opt*) _temp245.effect;
goto _LL254; _LL254: _temp253=( void*) _temp245.ret_typ; goto _LL252; _LL252:
_temp251=( struct Cyc_List_List*) _temp245.args; goto _LL250; _LL250: _temp249=(
int) _temp245.varargs; goto _LL248; _LL248: _temp247=( struct Cyc_List_List*)
_temp245.attributes; goto _LL214;} else{ goto _LL215;} _LL215: if(( unsigned int)
_temp205 > 5u?(( struct _enum_struct*) _temp205)->tag == Cyc_Absyn_TupleType_tag:
0){ _LL260: _temp259=( struct Cyc_List_List*)(( struct Cyc_Absyn_TupleType_struct*)
_temp205)->f1; goto _LL216;} else{ goto _LL217;} _LL217: if(( unsigned int)
_temp205 > 5u?(( struct _enum_struct*) _temp205)->tag == Cyc_Absyn_RgnHandleType_tag:
0){ _LL262: _temp261=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*) _temp205)->f1;
goto _LL218;} else{ goto _LL219;} _LL219: if(( unsigned int) _temp205 > 5u?((
struct _enum_struct*) _temp205)->tag == Cyc_Absyn_TypedefType_tag: 0){ _LL268:
_temp267=( struct _tuple1*)(( struct Cyc_Absyn_TypedefType_struct*) _temp205)->f1;
goto _LL266; _LL266: _temp265=( struct Cyc_List_List*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp205)->f2; goto _LL264; _LL264: _temp263=( struct Cyc_Core_Opt*)(( struct
Cyc_Absyn_TypedefType_struct*) _temp205)->f3; goto _LL220;} else{ goto _LL221;}
_LL221: if(( unsigned int) _temp205 > 5u?(( struct _enum_struct*) _temp205)->tag
== Cyc_Absyn_EnumType_tag: 0){ _LL274: _temp273=( struct _tuple1*)(( struct Cyc_Absyn_EnumType_struct*)
_temp205)->f1; goto _LL272; _LL272: _temp271=( struct Cyc_List_List*)(( struct
Cyc_Absyn_EnumType_struct*) _temp205)->f2; goto _LL270; _LL270: _temp269=(
struct Cyc_Absyn_Enumdecl**)(( struct Cyc_Absyn_EnumType_struct*) _temp205)->f3;
goto _LL222;} else{ goto _LL223;} _LL223: if(( unsigned int) _temp205 > 5u?((
struct _enum_struct*) _temp205)->tag == Cyc_Absyn_StructType_tag: 0){ _LL280:
_temp279=( struct _tuple1*)(( struct Cyc_Absyn_StructType_struct*) _temp205)->f1;
goto _LL278; _LL278: _temp277=( struct Cyc_List_List*)(( struct Cyc_Absyn_StructType_struct*)
_temp205)->f2; goto _LL276; _LL276: _temp275=( struct Cyc_Absyn_Structdecl**)((
struct Cyc_Absyn_StructType_struct*) _temp205)->f3; goto _LL224;} else{ goto
_LL225;} _LL225: if(( unsigned int) _temp205 > 5u?(( struct _enum_struct*)
_temp205)->tag == Cyc_Absyn_AccessEff_tag: 0){ _LL282: _temp281=( void*)((
struct Cyc_Absyn_AccessEff_struct*) _temp205)->f1; goto _LL226;} else{ goto
_LL227;} _LL227: if(( unsigned int) _temp205 > 5u?(( struct _enum_struct*)
_temp205)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL284: _temp283=( struct Cyc_List_List*)((
struct Cyc_Absyn_JoinEff_struct*) _temp205)->f1; goto _LL228;} else{ goto _LL229;}
_LL229: goto _LL230; _LL208: if( t == evar){( void) _throw(({ struct Cyc_Tcutil_Unify_struct*
_temp285=( struct Cyc_Tcutil_Unify_struct*) GC_malloc_atomic( sizeof( struct Cyc_Tcutil_Unify_struct));*
_temp285=( struct Cyc_Tcutil_Unify_struct){.tag= Cyc_Tcutil_Unify_tag};( struct
_xenum_struct*) _temp285;}));} else{ if( _temp233 != 0){ Cyc_Tcutil_occurs( evar,(
void*) _temp233->v);}} goto _LL206; _LL210: Cyc_Tcutil_occurs( evar,( void*)
_temp237.elt_typ); Cyc_Tcutil_occurs( evar,( void*) _temp237.rgn_typ); goto
_LL206; _LL212: Cyc_Tcutil_occurs( evar, _temp243); goto _LL206; _LL214: if(
_temp255 != 0){ Cyc_Tcutil_occurs( evar,( void*) _temp255->v);} Cyc_Tcutil_occurs(
evar, _temp253); for( 0; _temp251 != 0; _temp251= _temp251->tl){ Cyc_Tcutil_occurs(
evar,(*(( struct _tuple2*) _temp251->hd)).f3);} goto _LL206; _LL216: for( 0;
_temp259 != 0; _temp259= _temp259->tl){ Cyc_Tcutil_occurs( evar,(*(( struct
_tuple4*) _temp259->hd)).f2);} goto _LL206; _LL218: Cyc_Tcutil_occurs( evar,
_temp261); goto _LL206; _LL220: _temp271= _temp265; goto _LL222; _LL222:
_temp277= _temp271; goto _LL224; _LL224: Cyc_Tcutil_occurslist( evar, _temp277);
goto _LL206; _LL226: Cyc_Tcutil_occurs( evar, _temp281); goto _LL206; _LL228:
Cyc_Tcutil_occurslist( evar, _temp283); goto _LL206; _LL230: goto _LL206; _LL206:;}
static void Cyc_Tcutil_occurslist( void* evar, struct Cyc_List_List* ts){ for( 0;
ts != 0; ts= ts->tl){ Cyc_Tcutil_occurs( evar,( void*) ts->hd);}} static void
Cyc_Tcutil_unify_list( struct Cyc_List_List* t1, struct Cyc_List_List* t2){
struct _handler_cons _temp286; _push_handler(& _temp286);{ struct _xenum_struct*
_temp287=( struct _xenum_struct*) setjmp( _temp286.handler); if( ! _temp287){((
void(*)( void(* f)( void*, void*), struct Cyc_List_List* x, struct Cyc_List_List*
y)) Cyc_List_iter2)( Cyc_Tcutil_unify_it, t1, t2);; _pop_handler();} else{
struct _xenum_struct* _temp289= _temp287; _LL291: if( _temp289->tag == Cyc_List_List_mismatch_tag){
goto _LL292;} else{ goto _LL293;} _LL293: goto _LL294; _LL292:( void) _throw(({
struct Cyc_Tcutil_Unify_struct* _temp295=( struct Cyc_Tcutil_Unify_struct*)
GC_malloc_atomic( sizeof( struct Cyc_Tcutil_Unify_struct));* _temp295=( struct
Cyc_Tcutil_Unify_struct){.tag= Cyc_Tcutil_Unify_tag};( struct _xenum_struct*)
_temp295;})); _LL294:( void) _throw( _temp289); _LL290:;}}} static void Cyc_Tcutil_unify_tqual(
struct Cyc_Absyn_Tqual* tq1, struct Cyc_Absyn_Tqual* tq2){ if(( tq1->q_const !=
tq2->q_const? 1: tq1->q_volatile != tq2->q_volatile)? 1: tq1->q_restrict != tq2->q_restrict){(
void) _throw(({ struct Cyc_Tcutil_Unify_struct* _temp296=( struct Cyc_Tcutil_Unify_struct*)
GC_malloc_atomic( sizeof( struct Cyc_Tcutil_Unify_struct));* _temp296=( struct
Cyc_Tcutil_Unify_struct){.tag= Cyc_Tcutil_Unify_tag};( struct _xenum_struct*)
_temp296;}));}} int Cyc_Tcutil_equal_tqual( struct Cyc_Absyn_Tqual* tq1, struct
Cyc_Absyn_Tqual* tq2){ return( tq1->q_const == tq2->q_const? tq1->q_volatile ==
tq2->q_volatile: 0)? tq1->q_restrict == tq2->q_restrict: 0;} static void Cyc_Tcutil_unify_it_conrefs(
int(* cmp)( void*, void*), struct Cyc_Absyn_Conref* x, struct Cyc_Absyn_Conref*
y){ x=(( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)(
x); y=(( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)(
y); if( x == y){ return;}{ void* _temp297=( void*) x->v; struct Cyc_Absyn_Conref*
_temp305; void* _temp307; _LL299: if( _temp297 == Cyc_Absyn_No_constr){ goto
_LL300;} else{ goto _LL301;} _LL301: if(( unsigned int) _temp297 > 1u?(( struct
_enum_struct*) _temp297)->tag == Cyc_Absyn_Forward_constr_tag: 0){ _LL306:
_temp305=( struct Cyc_Absyn_Conref*)(( struct Cyc_Absyn_Forward_constr_struct*)
_temp297)->f1; goto _LL302;} else{ goto _LL303;} _LL303: if(( unsigned int)
_temp297 > 1u?(( struct _enum_struct*) _temp297)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL308: _temp307=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp297)->f1;
goto _LL304;} else{ goto _LL298;} _LL300:( void*)( x->v=( void*)({ struct Cyc_Absyn_Forward_constr_struct*
_temp309=( struct Cyc_Absyn_Forward_constr_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_Forward_constr_struct)); _temp309->tag= Cyc_Absyn_Forward_constr_tag;
_temp309->f1= y;( void*) _temp309;})); return; _LL302:( void) _throw((( struct
_xenum_struct*(*)( struct _tagged_string msg)) Cyc_Tcutil_impos)(( struct
_tagged_string)({ char* _temp310=( char*)"unify_conref: forward after compress";
struct _tagged_string _temp311; _temp311.curr= _temp310; _temp311.base= _temp310;
_temp311.last_plus_one= _temp310 + 37; _temp311;}))); _LL304: { void* _temp312=(
void*) y->v; struct Cyc_Absyn_Conref* _temp320; void* _temp322; _LL314: if(
_temp312 == Cyc_Absyn_No_constr){ goto _LL315;} else{ goto _LL316;} _LL316: if((
unsigned int) _temp312 > 1u?(( struct _enum_struct*) _temp312)->tag == Cyc_Absyn_Forward_constr_tag:
0){ _LL321: _temp320=( struct Cyc_Absyn_Conref*)(( struct Cyc_Absyn_Forward_constr_struct*)
_temp312)->f1; goto _LL317;} else{ goto _LL318;} _LL318: if(( unsigned int)
_temp312 > 1u?(( struct _enum_struct*) _temp312)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL323: _temp322=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp312)->f1;
goto _LL319;} else{ goto _LL313;} _LL315:( void*)( y->v=( void*)(( void*) x->v));
return; _LL317:( void) _throw((( struct _xenum_struct*(*)( struct _tagged_string
msg)) Cyc_Tcutil_impos)(( struct _tagged_string)({ char* _temp324=( char*)"unify_conref: forward after compress(2)";
struct _tagged_string _temp325; _temp325.curr= _temp324; _temp325.base= _temp324;
_temp325.last_plus_one= _temp324 + 40; _temp325;}))); _LL319: if( cmp( _temp307,
_temp322) != 0){( void) _throw(({ struct Cyc_Tcutil_Unify_struct* _temp326=(
struct Cyc_Tcutil_Unify_struct*) GC_malloc_atomic( sizeof( struct Cyc_Tcutil_Unify_struct));*
_temp326=( struct Cyc_Tcutil_Unify_struct){.tag= Cyc_Tcutil_Unify_tag};( struct
_xenum_struct*) _temp326;}));} return; _LL313:;} _LL298:;}} static int Cyc_Tcutil_unify_conrefs(
int(* cmp)( void*, void*), struct Cyc_Absyn_Conref* x, struct Cyc_Absyn_Conref*
y){ struct _handler_cons _temp327; _push_handler(& _temp327);{ struct
_xenum_struct* _temp328=( struct _xenum_struct*) setjmp( _temp327.handler); if(
! _temp328){(( void(*)( int(* cmp)( void*, void*), struct Cyc_Absyn_Conref* x,
struct Cyc_Absyn_Conref* y)) Cyc_Tcutil_unify_it_conrefs)( cmp, x, y);{ int
_temp329= 1; _npop_handler( 0u); return _temp329;}; _pop_handler();} else{
struct _xenum_struct* _temp331= _temp328; _LL333: if( _temp331->tag == Cyc_Tcutil_Unify_tag){
goto _LL334;} else{ goto _LL335;} _LL335: goto _LL336; _LL334: return 0; _LL336:(
void) _throw( _temp331); _LL332:;}}} static int Cyc_Tcutil_boundscmp( void* b1,
void* b2){ struct _tuple7 _temp338=({ struct _tuple7 _temp337; _temp337.f1= b1;
_temp337.f2= b2; _temp337;}); void* _temp348; void* _temp350; void* _temp352;
void* _temp354; void* _temp356; void* _temp358; void* _temp360; struct Cyc_Absyn_Exp*
_temp362; void* _temp364; struct Cyc_Absyn_Exp* _temp366; _LL340: _LL351:
_temp350= _temp338.f1; if( _temp350 == Cyc_Absyn_Unknown_b){ goto _LL349;} else{
goto _LL342;} _LL349: _temp348= _temp338.f2; if( _temp348 == Cyc_Absyn_Unknown_b){
goto _LL341;} else{ goto _LL342;} _LL342: _LL355: _temp354= _temp338.f1; if(
_temp354 == Cyc_Absyn_Unknown_b){ goto _LL353;} else{ goto _LL344;} _LL353:
_temp352= _temp338.f2; goto _LL343; _LL344: _LL359: _temp358= _temp338.f1; goto
_LL357; _LL357: _temp356= _temp338.f2; if( _temp356 == Cyc_Absyn_Unknown_b){
goto _LL345;} else{ goto _LL346;} _LL346: _LL365: _temp364= _temp338.f1; if((
unsigned int) _temp364 > 1u?(( struct _enum_struct*) _temp364)->tag == Cyc_Absyn_Upper_b_tag:
0){ _LL367: _temp366=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*)
_temp364)->f1; goto _LL361;} else{ goto _LL339;} _LL361: _temp360= _temp338.f2;
if(( unsigned int) _temp360 > 1u?(( struct _enum_struct*) _temp360)->tag == Cyc_Absyn_Upper_b_tag:
0){ _LL363: _temp362=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*)
_temp360)->f1; goto _LL347;} else{ goto _LL339;} _LL341: return 0; _LL343:
return - 1; _LL345: return 1; _LL347: { int i1=( int) Cyc_Evexp_eval_const_uint_exp(
_temp366); int i2=( int) Cyc_Evexp_eval_const_uint_exp( _temp362); if( i1 == i2){
return 0;} if( i1 < i2){ return - 1;} return 1;} _LL339:;} static int Cyc_Tcutil_equal_att(
void* a1, void* a2){ if( a1 == a2){ return 1;}{ struct _tuple7 _temp369=({
struct _tuple7 _temp368; _temp368.f1= a1; _temp368.f2= a2; _temp368;}); void*
_temp379; int _temp381; void* _temp383; int _temp385; void* _temp387; int
_temp389; void* _temp391; int _temp393; void* _temp395; struct _tagged_string
_temp397; void* _temp399; struct _tagged_string _temp401; _LL371: _LL384:
_temp383= _temp369.f1; if(( unsigned int) _temp383 > 15u?(( struct _enum_struct*)
_temp383)->tag == Cyc_Absyn_Regparm_att_tag: 0){ _LL386: _temp385=( int)((
struct Cyc_Absyn_Regparm_att_struct*) _temp383)->f1; goto _LL380;} else{ goto
_LL373;} _LL380: _temp379= _temp369.f2; if(( unsigned int) _temp379 > 15u?((
struct _enum_struct*) _temp379)->tag == Cyc_Absyn_Regparm_att_tag: 0){ _LL382:
_temp381=( int)(( struct Cyc_Absyn_Regparm_att_struct*) _temp379)->f1; goto
_LL372;} else{ goto _LL373;} _LL373: _LL392: _temp391= _temp369.f1; if((
unsigned int) _temp391 > 15u?(( struct _enum_struct*) _temp391)->tag == Cyc_Absyn_Aligned_att_tag:
0){ _LL394: _temp393=( int)(( struct Cyc_Absyn_Aligned_att_struct*) _temp391)->f1;
goto _LL388;} else{ goto _LL375;} _LL388: _temp387= _temp369.f2; if((
unsigned int) _temp387 > 15u?(( struct _enum_struct*) _temp387)->tag == Cyc_Absyn_Aligned_att_tag:
0){ _LL390: _temp389=( int)(( struct Cyc_Absyn_Aligned_att_struct*) _temp387)->f1;
goto _LL374;} else{ goto _LL375;} _LL375: _LL400: _temp399= _temp369.f1; if((
unsigned int) _temp399 > 15u?(( struct _enum_struct*) _temp399)->tag == Cyc_Absyn_Section_att_tag:
0){ _LL402: _temp401=( struct _tagged_string)(( struct Cyc_Absyn_Section_att_struct*)
_temp399)->f1; goto _LL396;} else{ goto _LL377;} _LL396: _temp395= _temp369.f2;
if(( unsigned int) _temp395 > 15u?(( struct _enum_struct*) _temp395)->tag == Cyc_Absyn_Section_att_tag:
0){ _LL398: _temp397=( struct _tagged_string)(( struct Cyc_Absyn_Section_att_struct*)
_temp395)->f1; goto _LL376;} else{ goto _LL377;} _LL377: goto _LL378; _LL372:
_temp393= _temp385; _temp389= _temp381; goto _LL374; _LL374: return _temp393 ==
_temp389; _LL376: return Cyc_String_strcmp( _temp401, _temp397) == 0; _LL378:
return 0; _LL370:;}} int Cyc_Tcutil_same_atts( struct Cyc_List_List* a1, struct
Cyc_List_List* a2){{ struct Cyc_List_List* a= a1; for( 0; a != 0; a= a->tl){ if(
!(( int(*)( int(* pred)( void*, void*), void* env, struct Cyc_List_List* x)) Cyc_List_exists_c)(
Cyc_Tcutil_equal_att,( void*) a->hd, a2)){ return 0;}}}{ struct Cyc_List_List* a=
a2; for( 0; a != 0; a= a->tl){ if( !(( int(*)( int(* pred)( void*, void*), void*
env, struct Cyc_List_List* x)) Cyc_List_exists_c)( Cyc_Tcutil_equal_att,( void*)
a->hd, a1)){ return 0;}}} return 1;} static void Cyc_Tcutil_normalize_effect(
void* e){ e= Cyc_Tcutil_compress( e);{ void* _temp403= e; struct Cyc_List_List*
_temp409; struct Cyc_List_List** _temp411; _LL405: if(( unsigned int) _temp403 >
5u?(( struct _enum_struct*) _temp403)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL410:
_temp409=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*) _temp403)->f1;
_temp411=&(( struct Cyc_Absyn_JoinEff_struct*) _temp403)->f1; goto _LL406;}
else{ goto _LL407;} _LL407: goto _LL408; _LL406: { int nested_join= 0;{ struct
Cyc_List_List* effs=* _temp411; for( 0; effs != 0; effs= effs->tl){ void* eff=(
void*) effs->hd; Cyc_Tcutil_normalize_effect( eff);{ void* _temp412= Cyc_Tcutil_compress(
eff); struct Cyc_List_List* _temp418; _LL414: if(( unsigned int) _temp412 > 5u?((
struct _enum_struct*) _temp412)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL419:
_temp418=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*) _temp412)->f1;
goto _LL415;} else{ goto _LL416;} _LL416: goto _LL417; _LL415: nested_join= 1;
goto _LL413; _LL417: goto _LL413; _LL413:;}}} if( ! nested_join){ return;}{
struct Cyc_List_List* effects= 0;{ struct Cyc_List_List* effs=* _temp411; for( 0;
effs != 0; effs= effs->tl){ void* _temp420= Cyc_Tcutil_compress(( void*) effs->hd);
struct Cyc_List_List* _temp426; _LL422: if(( unsigned int) _temp420 > 5u?((
struct _enum_struct*) _temp420)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL427:
_temp426=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*) _temp420)->f1;
goto _LL423;} else{ goto _LL424;} _LL424: goto _LL425; _LL423: effects=(( struct
Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_revappend)(
_temp426, effects); goto _LL421; _LL425: effects=({ struct Cyc_List_List*
_temp428=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp428->hd=( void*) _temp420; _temp428->tl= effects; _temp428;}); goto _LL421;
_LL421:;}}* _temp411=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
effects); goto _LL404;}} _LL408: goto _LL404; _LL404:;}} static struct _tuple8*
Cyc_Tcutil_get_effect_evar( void* t){ void* _temp429= Cyc_Tcutil_compress( t);
struct Cyc_List_List* _temp437; struct Cyc_List_List _temp439; struct Cyc_List_List*
_temp440; void* _temp442; int _temp444; struct Cyc_Core_Opt* _temp446; struct
Cyc_Core_Opt** _temp448; void* _temp449; void** _temp451; _LL431: if((
unsigned int) _temp429 > 5u?(( struct _enum_struct*) _temp429)->tag == Cyc_Absyn_JoinEff_tag:
0){ _LL438: _temp437=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*)
_temp429)->f1; if( _temp437 == 0){ goto _LL433;} else{ _temp439=* _temp437;
_LL443: _temp442=( void*) _temp439.hd; goto _LL441; _LL441: _temp440=( struct
Cyc_List_List*) _temp439.tl; goto _LL432;}} else{ goto _LL433;} _LL433: if((
unsigned int) _temp429 > 5u?(( struct _enum_struct*) _temp429)->tag == Cyc_Absyn_Evar_tag:
0){ _LL450: _temp449=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp429)->f1;
_temp451=&(( struct Cyc_Absyn_Evar_struct*) _temp429)->f1; goto _LL447; _LL447:
_temp446=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*) _temp429)->f2;
_temp448=&(( struct Cyc_Absyn_Evar_struct*) _temp429)->f2; goto _LL445; _LL445:
_temp444=( int)(( struct Cyc_Absyn_Evar_struct*) _temp429)->f3; goto _LL434;}
else{ goto _LL435;} _LL435: goto _LL436; _LL432: { void* _temp452= Cyc_Tcutil_compress(
_temp442); int _temp458; struct Cyc_Core_Opt* _temp460; void* _temp462; _LL454:
if(( unsigned int) _temp452 > 5u?(( struct _enum_struct*) _temp452)->tag == Cyc_Absyn_Evar_tag:
0){ _LL463: _temp462=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp452)->f1;
goto _LL461; _LL461: _temp460=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp452)->f2; goto _LL459; _LL459: _temp458=( int)(( struct Cyc_Absyn_Evar_struct*)
_temp452)->f3; goto _LL455;} else{ goto _LL456;} _LL456: goto _LL457; _LL455:
return({ struct _tuple8* _temp464=( struct _tuple8*) GC_malloc( sizeof( struct
_tuple8)); _temp464->f1= _temp442; _temp464->f2= _temp440; _temp464;}); _LL457:
return 0; _LL453:;} _LL434: if(* _temp451 != Cyc_Absyn_EffKind){(( void(*)(
struct _tagged_string msg)) Cyc_Tcutil_impos)(( struct _tagged_string)({ char*
_temp465=( char*)"effect evar has wrong kind"; struct _tagged_string _temp466;
_temp466.curr= _temp465; _temp466.base= _temp465; _temp466.last_plus_one=
_temp465 + 27; _temp466;}));} return({ struct _tuple8* _temp467=( struct _tuple8*)
GC_malloc( sizeof( struct _tuple8)); _temp467->f1= t; _temp467->f2= 0; _temp467;});
_LL436: return 0; _LL430:;} int Cyc_Tcutil_region_in_effect( int constrain, void*
r, void* e){ r= Cyc_Tcutil_compress( r); if( r == Cyc_Absyn_HeapRgn){ return 1;}{
void* _temp468= Cyc_Tcutil_compress( e); void* _temp478; struct Cyc_List_List*
_temp480; int _temp482; struct Cyc_Core_Opt* _temp484; struct Cyc_Core_Opt**
_temp486; void* _temp487; void** _temp489; _LL470: if(( unsigned int) _temp468 >
5u?(( struct _enum_struct*) _temp468)->tag == Cyc_Absyn_AccessEff_tag: 0){
_LL479: _temp478=( void*)(( struct Cyc_Absyn_AccessEff_struct*) _temp468)->f1;
goto _LL471;} else{ goto _LL472;} _LL472: if(( unsigned int) _temp468 > 5u?((
struct _enum_struct*) _temp468)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL481:
_temp480=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*) _temp468)->f1;
goto _LL473;} else{ goto _LL474;} _LL474: if(( unsigned int) _temp468 > 5u?((
struct _enum_struct*) _temp468)->tag == Cyc_Absyn_Evar_tag: 0){ _LL488: _temp487=(
void*)(( struct Cyc_Absyn_Evar_struct*) _temp468)->f1; _temp489=&(( struct Cyc_Absyn_Evar_struct*)
_temp468)->f1; goto _LL485; _LL485: _temp484=( struct Cyc_Core_Opt*)(( struct
Cyc_Absyn_Evar_struct*) _temp468)->f2; _temp486=&(( struct Cyc_Absyn_Evar_struct*)
_temp468)->f2; goto _LL483; _LL483: _temp482=( int)(( struct Cyc_Absyn_Evar_struct*)
_temp468)->f3; goto _LL475;} else{ goto _LL476;} _LL476: goto _LL477; _LL471:
if( constrain){ return Cyc_Tcutil_unify( r, _temp478);} Cyc_Tcutil_compress(
_temp478); if( r == _temp478){ return 1;}{ struct _tuple7 _temp491=({ struct
_tuple7 _temp490; _temp490.f1= r; _temp490.f2= _temp478; _temp490;}); void*
_temp497; struct Cyc_Absyn_Tvar* _temp499; void* _temp501; struct Cyc_Absyn_Tvar*
_temp503; _LL493: _LL502: _temp501= _temp491.f1; if(( unsigned int) _temp501 > 5u?((
struct _enum_struct*) _temp501)->tag == Cyc_Absyn_VarType_tag: 0){ _LL504:
_temp503=( struct Cyc_Absyn_Tvar*)(( struct Cyc_Absyn_VarType_struct*) _temp501)->f1;
goto _LL498;} else{ goto _LL495;} _LL498: _temp497= _temp491.f2; if((
unsigned int) _temp497 > 5u?(( struct _enum_struct*) _temp497)->tag == Cyc_Absyn_VarType_tag:
0){ _LL500: _temp499=( struct Cyc_Absyn_Tvar*)(( struct Cyc_Absyn_VarType_struct*)
_temp497)->f1; goto _LL494;} else{ goto _LL495;} _LL495: goto _LL496; _LL494:
return Cyc_Absyn_tvar_cmp( _temp503, _temp499) == 0; _LL496: return 0; _LL492:;}
_LL473: for( 0; _temp480 != 0; _temp480= _temp480->tl){ if( Cyc_Tcutil_region_in_effect(
constrain, r,( void*) _temp480->hd)){ return 1;}} return 0; _LL475: if(*
_temp489 != Cyc_Absyn_EffKind){(( void(*)( struct _tagged_string msg)) Cyc_Tcutil_impos)((
struct _tagged_string)({ char* _temp505=( char*)"effect evar has wrong kind";
struct _tagged_string _temp506; _temp506.curr= _temp505; _temp506.base= _temp505;
_temp506.last_plus_one= _temp505 + 27; _temp506;}));} if( ! constrain){ return 0;}{
void* ev= Cyc_Absyn_new_evar( Cyc_Absyn_EffKind); void* new_typ=({ struct Cyc_Absyn_JoinEff_struct*
_temp507=( struct Cyc_Absyn_JoinEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct));
_temp507->tag= Cyc_Absyn_JoinEff_tag; _temp507->f1=({ struct Cyc_List_List*
_temp508=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp508->hd=( void*) ev; _temp508->tl=({ struct Cyc_List_List* _temp509=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp509->hd=(
void*)({ struct Cyc_Absyn_AccessEff_struct* _temp510=( struct Cyc_Absyn_AccessEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_AccessEff_struct)); _temp510->tag= Cyc_Absyn_AccessEff_tag;
_temp510->f1=( void*) r;( void*) _temp510;}); _temp509->tl= 0; _temp509;});
_temp508;});( void*) _temp507;});* _temp486=({ struct Cyc_Core_Opt* _temp511=(
struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp511->v=(
void*) new_typ; _temp511;}); return 1;} _LL477: return 0; _LL469:;}} static int
Cyc_Tcutil_variable_in_effect( int constrain, struct Cyc_Absyn_Tvar* v, void* e){
e= Cyc_Tcutil_compress( e);{ void* _temp512= e; struct Cyc_Absyn_Tvar* _temp522;
struct Cyc_List_List* _temp524; int _temp526; struct Cyc_Core_Opt* _temp528;
struct Cyc_Core_Opt** _temp530; void* _temp531; void** _temp533; _LL514: if((
unsigned int) _temp512 > 5u?(( struct _enum_struct*) _temp512)->tag == Cyc_Absyn_VarType_tag:
0){ _LL523: _temp522=( struct Cyc_Absyn_Tvar*)(( struct Cyc_Absyn_VarType_struct*)
_temp512)->f1; goto _LL515;} else{ goto _LL516;} _LL516: if(( unsigned int)
_temp512 > 5u?(( struct _enum_struct*) _temp512)->tag == Cyc_Absyn_JoinEff_tag:
0){ _LL525: _temp524=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*)
_temp512)->f1; goto _LL517;} else{ goto _LL518;} _LL518: if(( unsigned int)
_temp512 > 5u?(( struct _enum_struct*) _temp512)->tag == Cyc_Absyn_Evar_tag: 0){
_LL532: _temp531=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp512)->f1;
_temp533=&(( struct Cyc_Absyn_Evar_struct*) _temp512)->f1; goto _LL529; _LL529:
_temp528=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*) _temp512)->f2;
_temp530=&(( struct Cyc_Absyn_Evar_struct*) _temp512)->f2; goto _LL527; _LL527:
_temp526=( int)(( struct Cyc_Absyn_Evar_struct*) _temp512)->f3; goto _LL519;}
else{ goto _LL520;} _LL520: goto _LL521; _LL515: return Cyc_Absyn_tvar_cmp( v,
_temp522) == 0; _LL517: for( 0; _temp524 != 0; _temp524= _temp524->tl){ if( Cyc_Tcutil_variable_in_effect(
constrain, v,( void*) _temp524->hd)){ return 1;}} return 0; _LL519: if(*
_temp533 != Cyc_Absyn_EffKind){(( void(*)( struct _tagged_string msg)) Cyc_Tcutil_impos)((
struct _tagged_string)({ char* _temp534=( char*)"effect evar has wrong kind";
struct _tagged_string _temp535; _temp535.curr= _temp534; _temp535.base= _temp534;
_temp535.last_plus_one= _temp534 + 27; _temp535;}));}{ void* ev= Cyc_Absyn_new_evar(
Cyc_Absyn_EffKind); void* new_typ=({ struct Cyc_Absyn_JoinEff_struct* _temp536=(
struct Cyc_Absyn_JoinEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct));
_temp536->tag= Cyc_Absyn_JoinEff_tag; _temp536->f1=({ struct Cyc_List_List*
_temp537=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp537->hd=( void*) ev; _temp537->tl=({ struct Cyc_List_List* _temp538=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp538->hd=(
void*)({ struct Cyc_Absyn_VarType_struct* _temp539=( struct Cyc_Absyn_VarType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct)); _temp539->tag= Cyc_Absyn_VarType_tag;
_temp539->f1= v;( void*) _temp539;}); _temp538->tl= 0; _temp538;}); _temp537;});(
void*) _temp536;});* _temp530=({ struct Cyc_Core_Opt* _temp540=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp540->v=( void*) new_typ; _temp540;});
return 1;} _LL521: return 0; _LL513:;}} static int Cyc_Tcutil_evar_in_effect(
void* evar, void* e){ e= Cyc_Tcutil_compress( e);{ void* _temp541= e; struct Cyc_List_List*
_temp549; int _temp551; struct Cyc_Core_Opt* _temp553; void* _temp555; _LL543:
if(( unsigned int) _temp541 > 5u?(( struct _enum_struct*) _temp541)->tag == Cyc_Absyn_JoinEff_tag:
0){ _LL550: _temp549=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*)
_temp541)->f1; goto _LL544;} else{ goto _LL545;} _LL545: if(( unsigned int)
_temp541 > 5u?(( struct _enum_struct*) _temp541)->tag == Cyc_Absyn_Evar_tag: 0){
_LL556: _temp555=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp541)->f1; goto
_LL554; _LL554: _temp553=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp541)->f2; goto _LL552; _LL552: _temp551=( int)(( struct Cyc_Absyn_Evar_struct*)
_temp541)->f3; goto _LL546;} else{ goto _LL547;} _LL547: goto _LL548; _LL544:
for( 0; _temp549 != 0; _temp549= _temp549->tl){ if( Cyc_Tcutil_evar_in_effect(
evar,( void*) _temp549->hd)){ return 1;}} return 0; _LL546: return evar == e;
_LL548: return 0; _LL542:;}} int Cyc_Tcutil_subset_effect( int set_to_empty,
void* e1, void* e2){{ struct _tuple8* _temp557= Cyc_Tcutil_get_effect_evar( e2);
struct _tuple8 _temp563; struct Cyc_List_List* _temp564; void* _temp566; _LL559:
if( _temp557 == 0){ goto _LL561;} else{ _temp563=* _temp557; _LL567: _temp566=
_temp563.f1; goto _LL565; _LL565: _temp564= _temp563.f2; goto _LL560;} _LL561:
goto _LL562; _LL560: { void* ev= Cyc_Absyn_new_evar( Cyc_Absyn_EffKind); void*
new_typ=({ struct Cyc_Absyn_JoinEff_struct* _temp568=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp568->tag= Cyc_Absyn_JoinEff_tag;
_temp568->f1=({ struct Cyc_List_List* _temp569=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp569->hd=( void*) ev; _temp569->tl=({
struct Cyc_List_List* _temp570=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp570->hd=( void*) e1; _temp570->tl= 0; _temp570;});
_temp569;});( void*) _temp568;}); return Cyc_Tcutil_unify( _temp566, new_typ);}
_LL562: goto _LL558; _LL558:;}{ void* _temp571= Cyc_Tcutil_compress( e1); struct
Cyc_List_List* _temp583; void* _temp585; struct Cyc_Absyn_Tvar* _temp587; int
_temp589; struct Cyc_Core_Opt* _temp591; struct Cyc_Core_Opt** _temp593; void*
_temp594; _LL573: if(( unsigned int) _temp571 > 5u?(( struct _enum_struct*)
_temp571)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL584: _temp583=( struct Cyc_List_List*)((
struct Cyc_Absyn_JoinEff_struct*) _temp571)->f1; goto _LL574;} else{ goto _LL575;}
_LL575: if(( unsigned int) _temp571 > 5u?(( struct _enum_struct*) _temp571)->tag
== Cyc_Absyn_AccessEff_tag: 0){ _LL586: _temp585=( void*)(( struct Cyc_Absyn_AccessEff_struct*)
_temp571)->f1; goto _LL576;} else{ goto _LL577;} _LL577: if(( unsigned int)
_temp571 > 5u?(( struct _enum_struct*) _temp571)->tag == Cyc_Absyn_VarType_tag:
0){ _LL588: _temp587=( struct Cyc_Absyn_Tvar*)(( struct Cyc_Absyn_VarType_struct*)
_temp571)->f1; goto _LL578;} else{ goto _LL579;} _LL579: if(( unsigned int)
_temp571 > 5u?(( struct _enum_struct*) _temp571)->tag == Cyc_Absyn_Evar_tag: 0){
_LL595: _temp594=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp571)->f1; goto
_LL592; _LL592: _temp591=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp571)->f2; _temp593=&(( struct Cyc_Absyn_Evar_struct*) _temp571)->f2; goto
_LL590; _LL590: _temp589=( int)(( struct Cyc_Absyn_Evar_struct*) _temp571)->f3;
goto _LL580;} else{ goto _LL581;} _LL581: goto _LL582; _LL574: for( 0; _temp583
!= 0; _temp583= _temp583->tl){ if( ! Cyc_Tcutil_subset_effect( set_to_empty,(
void*) _temp583->hd, e2)){ return 0;}} return 1; _LL576: return( Cyc_Tcutil_region_in_effect(
0, _temp585, e2)? 1: Cyc_Tcutil_region_in_effect( 1, _temp585, e2))? 1: Cyc_Tcutil_unify(
_temp585, Cyc_Absyn_HeapRgn); _LL578: return Cyc_Tcutil_variable_in_effect( 0,
_temp587, e2)? 1: Cyc_Tcutil_variable_in_effect( 1, _temp587, e2); _LL580: if( !
Cyc_Tcutil_evar_in_effect( e1, e2)){ if( set_to_empty){* _temp593=({ struct Cyc_Core_Opt*
_temp596=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp596->v=( void*)({ struct Cyc_Absyn_JoinEff_struct* _temp597=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp597->tag= Cyc_Absyn_JoinEff_tag;
_temp597->f1= 0;( void*) _temp597;}); _temp596;});} else{* _temp593=({ struct
Cyc_Core_Opt* _temp598=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp598->v=( void*) e2; _temp598;});}} return 1; _LL582: return(( int(*)(
struct _tagged_string msg)) Cyc_Tcutil_impos)(({ struct _tagged_string _temp599=
Cyc_Absynpp_typ2string( e1); xprintf("subset_effect: bad effect: %.*s", _temp599.last_plus_one
- _temp599.curr, _temp599.curr);})); _LL572:;}} static int Cyc_Tcutil_unify_effect(
void* e1, void* e2){ e1= Cyc_Tcutil_compress( e1); e2= Cyc_Tcutil_compress( e2);
Cyc_Tcutil_normalize_effect( e1); Cyc_Tcutil_normalize_effect( e2);{ struct
_tuple9 _temp601=({ struct _tuple9 _temp600; _temp600.f1= Cyc_Tcutil_get_effect_evar(
e1); _temp600.f2= Cyc_Tcutil_get_effect_evar( e2); _temp600;}); struct _tuple8*
_temp607; struct _tuple8 _temp609; struct Cyc_List_List* _temp610; void*
_temp612; struct _tuple8* _temp614; struct _tuple8 _temp616; struct Cyc_List_List*
_temp617; void* _temp619; _LL603: _LL615: _temp614= _temp601.f1; if( _temp614 ==
0){ goto _LL605;} else{ _temp616=* _temp614; _LL620: _temp619= _temp616.f1; goto
_LL618; _LL618: _temp617= _temp616.f2; goto _LL608;} _LL608: _temp607= _temp601.f2;
if( _temp607 == 0){ goto _LL605;} else{ _temp609=* _temp607; _LL613: _temp612=
_temp609.f1; goto _LL611; _LL611: _temp610= _temp609.f2; goto _LL604;} _LL605:
goto _LL606; _LL604: { void* ev= Cyc_Absyn_new_evar( Cyc_Absyn_EffKind); void*
new_typ=({ struct Cyc_Absyn_JoinEff_struct* _temp621=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp621->tag= Cyc_Absyn_JoinEff_tag;
_temp621->f1=({ struct Cyc_List_List* _temp622=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp622->hd=( void*) ev; _temp622->tl=((
struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_append)(
_temp617, _temp610); _temp622;});( void*) _temp621;}); return Cyc_Tcutil_unify(
_temp619, new_typ)? Cyc_Tcutil_unify( _temp612, new_typ): 0;} _LL606: return Cyc_Tcutil_subset_effect(
0, e1, e2)? Cyc_Tcutil_subset_effect( 0, e2, e1): 0; _LL602:;}} void Cyc_Tcutil_unify_it(
void* t1, void* t2){ t1= Cyc_Tcutil_compress( t1); t2= Cyc_Tcutil_compress( t2);
if( t1 == t2){ return;}{ void* _temp623= t1; int _temp629; struct Cyc_Core_Opt*
_temp631; struct Cyc_Core_Opt** _temp633; void* _temp634; _LL625: if((
unsigned int) _temp623 > 5u?(( struct _enum_struct*) _temp623)->tag == Cyc_Absyn_Evar_tag:
0){ _LL635: _temp634=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp623)->f1;
goto _LL632; _LL632: _temp631=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp623)->f2; _temp633=&(( struct Cyc_Absyn_Evar_struct*) _temp623)->f2; goto
_LL630; _LL630: _temp629=( int)(( struct Cyc_Absyn_Evar_struct*) _temp623)->f3;
goto _LL626;} else{ goto _LL627;} _LL627: goto _LL628; _LL626: Cyc_Tcutil_occurs(
t1, t2);{ void* kind2= Cyc_Tcutil_typ_kind( t2); if( Cyc_Tcutil_kind_leq( kind2,
_temp634)){* _temp633=({ struct Cyc_Core_Opt* _temp636=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp636->v=( void*) t2; _temp636;});
return;} else{{ void* _temp637= t2; int _temp645; struct Cyc_Core_Opt* _temp647;
struct Cyc_Core_Opt** _temp649; void* _temp650; struct Cyc_Absyn_PtrInfo
_temp653; _LL639: if(( unsigned int) _temp637 > 5u?(( struct _enum_struct*)
_temp637)->tag == Cyc_Absyn_Evar_tag: 0){ _LL651: _temp650=( void*)(( struct Cyc_Absyn_Evar_struct*)
_temp637)->f1; goto _LL648; _LL648: _temp647=( struct Cyc_Core_Opt*)(( struct
Cyc_Absyn_Evar_struct*) _temp637)->f2; _temp649=&(( struct Cyc_Absyn_Evar_struct*)
_temp637)->f2; goto _LL646; _LL646: _temp645=( int)(( struct Cyc_Absyn_Evar_struct*)
_temp637)->f3; goto _LL640;} else{ goto _LL641;} _LL641: if(( unsigned int)
_temp637 > 5u?(( struct _enum_struct*) _temp637)->tag == Cyc_Absyn_PointerType_tag:
0){ _LL654: _temp653=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp637)->f1; goto _LL652;} else{ goto _LL643;} _LL652: if( _temp634 == Cyc_Absyn_BoxKind){
goto _LL642;} else{ goto _LL643;} _LL643: goto _LL644; _LL640: if( Cyc_Tcutil_kind_leq(
_temp634, kind2)){* _temp649=({ struct Cyc_Core_Opt* _temp655=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp655->v=( void*) t1; _temp655;});
return;} goto _LL638; _LL642: { struct Cyc_Absyn_Conref* c=(( struct Cyc_Absyn_Conref*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)( _temp653.bounds);{ void*
_temp656=( void*) c->v; _LL658: if( _temp656 == Cyc_Absyn_No_constr){ goto
_LL659;} else{ goto _LL660;} _LL660: goto _LL661; _LL659:( void*)( c->v=( void*)({
struct Cyc_Absyn_Eq_constr_struct* _temp662=( struct Cyc_Absyn_Eq_constr_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct)); _temp662->tag= Cyc_Absyn_Eq_constr_tag;
_temp662->f1=( void*)({ struct Cyc_Absyn_Upper_b_struct* _temp663=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp663->tag= Cyc_Absyn_Upper_b_tag;
_temp663->f1= Cyc_Absyn_signed_int_exp( 1, 0);( void*) _temp663;});( void*)
_temp662;}));* _temp633=({ struct Cyc_Core_Opt* _temp664=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp664->v=( void*) t2; _temp664;});
return; _LL661: goto _LL657; _LL657:;} goto _LL638;} _LL644: goto _LL638; _LL638:;}(
void) _throw(({ struct Cyc_Tcutil_Unify_struct* _temp665=( struct Cyc_Tcutil_Unify_struct*)
GC_malloc_atomic( sizeof( struct Cyc_Tcutil_Unify_struct));* _temp665=( struct
Cyc_Tcutil_Unify_struct){.tag= Cyc_Tcutil_Unify_tag};( struct _xenum_struct*)
_temp665;}));}} _LL628: goto _LL624; _LL624:;}{ struct _tuple7 _temp667=({
struct _tuple7 _temp666; _temp666.f1= t2; _temp666.f2= t1; _temp666;}); void*
_temp709; void* _temp711; int _temp713; struct Cyc_Core_Opt* _temp715; void*
_temp717; void* _temp719; void* _temp721; void* _temp723; struct Cyc_Absyn_Tvar*
_temp725; void* _temp727; struct Cyc_Absyn_Tvar* _temp729; void* _temp731;
struct Cyc_Absyn_Structdecl** _temp733; struct Cyc_List_List* _temp735; struct
_tuple1* _temp737; void* _temp739; struct Cyc_Absyn_Structdecl** _temp741;
struct Cyc_List_List* _temp743; struct _tuple1* _temp745; void* _temp747; struct
Cyc_Absyn_Enumdecl** _temp749; struct Cyc_List_List* _temp751; struct _tuple1*
_temp753; void* _temp755; struct Cyc_Absyn_Enumdecl** _temp757; struct Cyc_List_List*
_temp759; struct _tuple1* _temp761; void* _temp763; struct Cyc_Absyn_Xenumdecl**
_temp765; struct _tuple1* _temp767; void* _temp769; struct Cyc_Absyn_Xenumdecl**
_temp771; struct _tuple1* _temp773; void* _temp775; struct Cyc_Absyn_PtrInfo
_temp777; struct Cyc_Absyn_Conref* _temp779; struct Cyc_Absyn_Tqual* _temp781;
struct Cyc_Absyn_Conref* _temp783; void* _temp785; void* _temp787; void*
_temp789; struct Cyc_Absyn_PtrInfo _temp791; struct Cyc_Absyn_Conref* _temp793;
struct Cyc_Absyn_Tqual* _temp795; struct Cyc_Absyn_Conref* _temp797; void*
_temp799; void* _temp801; void* _temp803; void* _temp805; void* _temp807; void*
_temp809; void* _temp811; void* _temp813; void* _temp815; void* _temp817; void*
_temp819; void* _temp821; void* _temp823; struct Cyc_Absyn_Exp* _temp825; struct
Cyc_Absyn_Tqual* _temp827; void* _temp829; void* _temp831; struct Cyc_Absyn_Exp*
_temp833; struct Cyc_Absyn_Tqual* _temp835; void* _temp837; void* _temp839;
struct Cyc_Absyn_FnInfo _temp841; struct Cyc_List_List* _temp843; int _temp845;
struct Cyc_List_List* _temp847; void* _temp849; struct Cyc_Core_Opt* _temp851;
struct Cyc_List_List* _temp853; void* _temp855; struct Cyc_Absyn_FnInfo _temp857;
struct Cyc_List_List* _temp859; int _temp861; struct Cyc_List_List* _temp863;
void* _temp865; struct Cyc_Core_Opt* _temp867; struct Cyc_List_List* _temp869;
void* _temp871; struct Cyc_List_List* _temp873; void* _temp875; struct Cyc_List_List*
_temp877; void* _temp879; void* _temp881; void* _temp883; void* _temp885; void*
_temp887; void* _temp889; void* _temp891; void* _temp893; struct Cyc_List_List*
_temp895; void* _temp897; struct Cyc_List_List* _temp899; void* _temp901; void*
_temp903; void* _temp905; void* _temp907; void* _temp909; void* _temp911; void*
_temp913; _LL669: _LL712: _temp711= _temp667.f1; if(( unsigned int) _temp711 > 5u?((
struct _enum_struct*) _temp711)->tag == Cyc_Absyn_Evar_tag: 0){ _LL718: _temp717=(
void*)(( struct Cyc_Absyn_Evar_struct*) _temp711)->f1; goto _LL716; _LL716:
_temp715=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*) _temp711)->f2;
goto _LL714; _LL714: _temp713=( int)(( struct Cyc_Absyn_Evar_struct*) _temp711)->f3;
goto _LL710;} else{ goto _LL671;} _LL710: _temp709= _temp667.f2; goto _LL670;
_LL671: _LL722: _temp721= _temp667.f1; if( _temp721 == Cyc_Absyn_VoidType){ goto
_LL720;} else{ goto _LL673;} _LL720: _temp719= _temp667.f2; if( _temp719 == Cyc_Absyn_VoidType){
goto _LL672;} else{ goto _LL673;} _LL673: _LL728: _temp727= _temp667.f1; if((
unsigned int) _temp727 > 5u?(( struct _enum_struct*) _temp727)->tag == Cyc_Absyn_VarType_tag:
0){ _LL730: _temp729=( struct Cyc_Absyn_Tvar*)(( struct Cyc_Absyn_VarType_struct*)
_temp727)->f1; goto _LL724;} else{ goto _LL675;} _LL724: _temp723= _temp667.f2;
if(( unsigned int) _temp723 > 5u?(( struct _enum_struct*) _temp723)->tag == Cyc_Absyn_VarType_tag:
0){ _LL726: _temp725=( struct Cyc_Absyn_Tvar*)(( struct Cyc_Absyn_VarType_struct*)
_temp723)->f1; goto _LL674;} else{ goto _LL675;} _LL675: _LL740: _temp739=
_temp667.f1; if(( unsigned int) _temp739 > 5u?(( struct _enum_struct*) _temp739)->tag
== Cyc_Absyn_StructType_tag: 0){ _LL746: _temp745=( struct _tuple1*)(( struct
Cyc_Absyn_StructType_struct*) _temp739)->f1; goto _LL744; _LL744: _temp743=(
struct Cyc_List_List*)(( struct Cyc_Absyn_StructType_struct*) _temp739)->f2;
goto _LL742; _LL742: _temp741=( struct Cyc_Absyn_Structdecl**)(( struct Cyc_Absyn_StructType_struct*)
_temp739)->f3; goto _LL732;} else{ goto _LL677;} _LL732: _temp731= _temp667.f2;
if(( unsigned int) _temp731 > 5u?(( struct _enum_struct*) _temp731)->tag == Cyc_Absyn_StructType_tag:
0){ _LL738: _temp737=( struct _tuple1*)(( struct Cyc_Absyn_StructType_struct*)
_temp731)->f1; goto _LL736; _LL736: _temp735=( struct Cyc_List_List*)(( struct
Cyc_Absyn_StructType_struct*) _temp731)->f2; goto _LL734; _LL734: _temp733=(
struct Cyc_Absyn_Structdecl**)(( struct Cyc_Absyn_StructType_struct*) _temp731)->f3;
goto _LL676;} else{ goto _LL677;} _LL677: _LL756: _temp755= _temp667.f1; if((
unsigned int) _temp755 > 5u?(( struct _enum_struct*) _temp755)->tag == Cyc_Absyn_EnumType_tag:
0){ _LL762: _temp761=( struct _tuple1*)(( struct Cyc_Absyn_EnumType_struct*)
_temp755)->f1; goto _LL760; _LL760: _temp759=( struct Cyc_List_List*)(( struct
Cyc_Absyn_EnumType_struct*) _temp755)->f2; goto _LL758; _LL758: _temp757=(
struct Cyc_Absyn_Enumdecl**)(( struct Cyc_Absyn_EnumType_struct*) _temp755)->f3;
goto _LL748;} else{ goto _LL679;} _LL748: _temp747= _temp667.f2; if((
unsigned int) _temp747 > 5u?(( struct _enum_struct*) _temp747)->tag == Cyc_Absyn_EnumType_tag:
0){ _LL754: _temp753=( struct _tuple1*)(( struct Cyc_Absyn_EnumType_struct*)
_temp747)->f1; goto _LL752; _LL752: _temp751=( struct Cyc_List_List*)(( struct
Cyc_Absyn_EnumType_struct*) _temp747)->f2; goto _LL750; _LL750: _temp749=(
struct Cyc_Absyn_Enumdecl**)(( struct Cyc_Absyn_EnumType_struct*) _temp747)->f3;
goto _LL678;} else{ goto _LL679;} _LL679: _LL770: _temp769= _temp667.f1; if((
unsigned int) _temp769 > 5u?(( struct _enum_struct*) _temp769)->tag == Cyc_Absyn_XenumType_tag:
0){ _LL774: _temp773=( struct _tuple1*)(( struct Cyc_Absyn_XenumType_struct*)
_temp769)->f1; goto _LL772; _LL772: _temp771=( struct Cyc_Absyn_Xenumdecl**)((
struct Cyc_Absyn_XenumType_struct*) _temp769)->f2; goto _LL764;} else{ goto
_LL681;} _LL764: _temp763= _temp667.f2; if(( unsigned int) _temp763 > 5u?((
struct _enum_struct*) _temp763)->tag == Cyc_Absyn_XenumType_tag: 0){ _LL768:
_temp767=( struct _tuple1*)(( struct Cyc_Absyn_XenumType_struct*) _temp763)->f1;
goto _LL766; _LL766: _temp765=( struct Cyc_Absyn_Xenumdecl**)(( struct Cyc_Absyn_XenumType_struct*)
_temp763)->f2; goto _LL680;} else{ goto _LL681;} _LL681: _LL790: _temp789=
_temp667.f1; if(( unsigned int) _temp789 > 5u?(( struct _enum_struct*) _temp789)->tag
== Cyc_Absyn_PointerType_tag: 0){ _LL792: _temp791=( struct Cyc_Absyn_PtrInfo)((
struct Cyc_Absyn_PointerType_struct*) _temp789)->f1; _LL802: _temp801=( void*)
_temp791.elt_typ; goto _LL800; _LL800: _temp799=( void*) _temp791.rgn_typ; goto
_LL798; _LL798: _temp797=( struct Cyc_Absyn_Conref*) _temp791.nullable; goto
_LL796; _LL796: _temp795=( struct Cyc_Absyn_Tqual*) _temp791.tq; goto _LL794;
_LL794: _temp793=( struct Cyc_Absyn_Conref*) _temp791.bounds; goto _LL776;}
else{ goto _LL683;} _LL776: _temp775= _temp667.f2; if(( unsigned int) _temp775 >
5u?(( struct _enum_struct*) _temp775)->tag == Cyc_Absyn_PointerType_tag: 0){
_LL778: _temp777=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp775)->f1; _LL788: _temp787=( void*) _temp777.elt_typ; goto _LL786; _LL786:
_temp785=( void*) _temp777.rgn_typ; goto _LL784; _LL784: _temp783=( struct Cyc_Absyn_Conref*)
_temp777.nullable; goto _LL782; _LL782: _temp781=( struct Cyc_Absyn_Tqual*)
_temp777.tq; goto _LL780; _LL780: _temp779=( struct Cyc_Absyn_Conref*) _temp777.bounds;
goto _LL682;} else{ goto _LL683;} _LL683: _LL810: _temp809= _temp667.f1; if((
unsigned int) _temp809 > 5u?(( struct _enum_struct*) _temp809)->tag == Cyc_Absyn_IntType_tag:
0){ _LL814: _temp813=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp809)->f1;
goto _LL812; _LL812: _temp811=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp809)->f2; goto _LL804;} else{ goto _LL685;} _LL804: _temp803= _temp667.f2;
if(( unsigned int) _temp803 > 5u?(( struct _enum_struct*) _temp803)->tag == Cyc_Absyn_IntType_tag:
0){ _LL808: _temp807=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp803)->f1;
goto _LL806; _LL806: _temp805=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp803)->f2; goto _LL684;} else{ goto _LL685;} _LL685: _LL818: _temp817=
_temp667.f1; if( _temp817 == Cyc_Absyn_FloatType){ goto _LL816;} else{ goto
_LL687;} _LL816: _temp815= _temp667.f2; if( _temp815 == Cyc_Absyn_FloatType){
goto _LL686;} else{ goto _LL687;} _LL687: _LL822: _temp821= _temp667.f1; if(
_temp821 == Cyc_Absyn_DoubleType){ goto _LL820;} else{ goto _LL689;} _LL820:
_temp819= _temp667.f2; if( _temp819 == Cyc_Absyn_DoubleType){ goto _LL688;}
else{ goto _LL689;} _LL689: _LL832: _temp831= _temp667.f1; if(( unsigned int)
_temp831 > 5u?(( struct _enum_struct*) _temp831)->tag == Cyc_Absyn_ArrayType_tag:
0){ _LL838: _temp837=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp831)->f1;
goto _LL836; _LL836: _temp835=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp831)->f2; goto _LL834; _LL834: _temp833=( struct Cyc_Absyn_Exp*)(( struct
Cyc_Absyn_ArrayType_struct*) _temp831)->f3; goto _LL824;} else{ goto _LL691;}
_LL824: _temp823= _temp667.f2; if(( unsigned int) _temp823 > 5u?(( struct
_enum_struct*) _temp823)->tag == Cyc_Absyn_ArrayType_tag: 0){ _LL830: _temp829=(
void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp823)->f1; goto _LL828; _LL828:
_temp827=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp823)->f2; goto _LL826; _LL826: _temp825=( struct Cyc_Absyn_Exp*)(( struct
Cyc_Absyn_ArrayType_struct*) _temp823)->f3; goto _LL690;} else{ goto _LL691;}
_LL691: _LL856: _temp855= _temp667.f1; if(( unsigned int) _temp855 > 5u?((
struct _enum_struct*) _temp855)->tag == Cyc_Absyn_FnType_tag: 0){ _LL858:
_temp857=( struct Cyc_Absyn_FnInfo)(( struct Cyc_Absyn_FnType_struct*) _temp855)->f1;
_LL870: _temp869=( struct Cyc_List_List*) _temp857.tvars; goto _LL868; _LL868:
_temp867=( struct Cyc_Core_Opt*) _temp857.effect; goto _LL866; _LL866: _temp865=(
void*) _temp857.ret_typ; goto _LL864; _LL864: _temp863=( struct Cyc_List_List*)
_temp857.args; goto _LL862; _LL862: _temp861=( int) _temp857.varargs; goto
_LL860; _LL860: _temp859=( struct Cyc_List_List*) _temp857.attributes; goto
_LL840;} else{ goto _LL693;} _LL840: _temp839= _temp667.f2; if(( unsigned int)
_temp839 > 5u?(( struct _enum_struct*) _temp839)->tag == Cyc_Absyn_FnType_tag: 0){
_LL842: _temp841=( struct Cyc_Absyn_FnInfo)(( struct Cyc_Absyn_FnType_struct*)
_temp839)->f1; _LL854: _temp853=( struct Cyc_List_List*) _temp841.tvars; goto
_LL852; _LL852: _temp851=( struct Cyc_Core_Opt*) _temp841.effect; goto _LL850;
_LL850: _temp849=( void*) _temp841.ret_typ; goto _LL848; _LL848: _temp847=(
struct Cyc_List_List*) _temp841.args; goto _LL846; _LL846: _temp845=( int)
_temp841.varargs; goto _LL844; _LL844: _temp843=( struct Cyc_List_List*)
_temp841.attributes; goto _LL692;} else{ goto _LL693;} _LL693: _LL876: _temp875=
_temp667.f1; if(( unsigned int) _temp875 > 5u?(( struct _enum_struct*) _temp875)->tag
== Cyc_Absyn_TupleType_tag: 0){ _LL878: _temp877=( struct Cyc_List_List*)((
struct Cyc_Absyn_TupleType_struct*) _temp875)->f1; goto _LL872;} else{ goto
_LL695;} _LL872: _temp871= _temp667.f2; if(( unsigned int) _temp871 > 5u?((
struct _enum_struct*) _temp871)->tag == Cyc_Absyn_TupleType_tag: 0){ _LL874:
_temp873=( struct Cyc_List_List*)(( struct Cyc_Absyn_TupleType_struct*) _temp871)->f1;
goto _LL694;} else{ goto _LL695;} _LL695: _LL882: _temp881= _temp667.f1; if(
_temp881 == Cyc_Absyn_HeapRgn){ goto _LL880;} else{ goto _LL697;} _LL880:
_temp879= _temp667.f2; if( _temp879 == Cyc_Absyn_HeapRgn){ goto _LL696;} else{
goto _LL697;} _LL697: _LL888: _temp887= _temp667.f1; if(( unsigned int) _temp887
> 5u?(( struct _enum_struct*) _temp887)->tag == Cyc_Absyn_RgnHandleType_tag: 0){
_LL890: _temp889=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*) _temp887)->f1;
goto _LL884;} else{ goto _LL699;} _LL884: _temp883= _temp667.f2; if((
unsigned int) _temp883 > 5u?(( struct _enum_struct*) _temp883)->tag == Cyc_Absyn_RgnHandleType_tag:
0){ _LL886: _temp885=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*) _temp883)->f1;
goto _LL698;} else{ goto _LL699;} _LL699: _LL894: _temp893= _temp667.f1; if((
unsigned int) _temp893 > 5u?(( struct _enum_struct*) _temp893)->tag == Cyc_Absyn_JoinEff_tag:
0){ _LL896: _temp895=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*)
_temp893)->f1; goto _LL892;} else{ goto _LL701;} _LL892: _temp891= _temp667.f2;
goto _LL700; _LL701: _LL902: _temp901= _temp667.f1; goto _LL898; _LL898:
_temp897= _temp667.f2; if(( unsigned int) _temp897 > 5u?(( struct _enum_struct*)
_temp897)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL900: _temp899=( struct Cyc_List_List*)((
struct Cyc_Absyn_JoinEff_struct*) _temp897)->f1; goto _LL702;} else{ goto _LL703;}
_LL703: _LL906: _temp905= _temp667.f1; if(( unsigned int) _temp905 > 5u?((
struct _enum_struct*) _temp905)->tag == Cyc_Absyn_AccessEff_tag: 0){ _LL908:
_temp907=( void*)(( struct Cyc_Absyn_AccessEff_struct*) _temp905)->f1; goto
_LL904;} else{ goto _LL705;} _LL904: _temp903= _temp667.f2; goto _LL704; _LL705:
_LL914: _temp913= _temp667.f1; goto _LL910; _LL910: _temp909= _temp667.f2; if((
unsigned int) _temp909 > 5u?(( struct _enum_struct*) _temp909)->tag == Cyc_Absyn_AccessEff_tag:
0){ _LL912: _temp911=( void*)(( struct Cyc_Absyn_AccessEff_struct*) _temp909)->f1;
goto _LL706;} else{ goto _LL707;} _LL707: goto _LL708; _LL670: Cyc_Tcutil_unify_it(
t2, t1); return; _LL672: return; _LL674: { struct _tagged_string* x2= _temp729->name;
struct _tagged_string* x1= _temp725->name; void* k2=(( void*(*)( struct Cyc_Absyn_Conref*
x)) Cyc_Absyn_conref_val)( _temp729->kind); void* k1=(( void*(*)( struct Cyc_Absyn_Conref*
x)) Cyc_Absyn_conref_val)( _temp725->kind); if( Cyc_String_zstrptrcmp( x2, x1)
== 0){ if( k2 != k1){(( void(*)( struct _tagged_string msg)) Cyc_Tcutil_impos)(({
struct _tagged_string _temp915=* x2; struct _tagged_string _temp916= Cyc_Absynpp_kind2string(
k2); struct _tagged_string _temp917= Cyc_Absynpp_kind2string( k1); xprintf("same type variable %.*s has kinds %.*s and %.*s",
_temp915.last_plus_one - _temp915.curr, _temp915.curr, _temp916.last_plus_one -
_temp916.curr, _temp916.curr, _temp917.last_plus_one - _temp917.curr, _temp917.curr);}));}
return;} goto _LL668;} _LL676: if((( _temp737 != 0? _temp745 != 0: 0)? Cyc_Absyn_qvar_cmp((
struct _tuple1*)({ struct _tuple1* _temp918= _temp737; if( _temp918 == 0){
_throw( Null_Exception);} _temp918;}),( struct _tuple1*)({ struct _tuple1*
_temp919= _temp745; if( _temp919 == 0){ _throw( Null_Exception);} _temp919;}))
== 0: 0)? 1:( _temp737 == 0? _temp745 == 0: 0)){ Cyc_Tcutil_unify_list( _temp735,
_temp743); return;} goto _LL668; _LL678: if((( _temp753 != 0? _temp761 != 0: 0)?
Cyc_Absyn_qvar_cmp(( struct _tuple1*)({ struct _tuple1* _temp920= _temp753; if(
_temp920 == 0){ _throw( Null_Exception);} _temp920;}),( struct _tuple1*)({
struct _tuple1* _temp921= _temp761; if( _temp921 == 0){ _throw( Null_Exception);}
_temp921;})) == 0: 0)? 1:( _temp753 == 0? _temp761 == 0: 0)){ Cyc_Tcutil_unify_list(
_temp751, _temp759); return;} goto _LL668; _LL680: if(* _temp771 ==* _temp765){
return;} goto _LL668; _LL682: Cyc_Tcutil_unify_it( _temp787, _temp801); Cyc_Tcutil_unify_it(
_temp799, _temp785); Cyc_Tcutil_unify_tqual( _temp781, _temp795);(( void(*)( int(*
cmp)( void*, void*), struct Cyc_Absyn_Conref* x, struct Cyc_Absyn_Conref* y))
Cyc_Tcutil_unify_it_conrefs)( Cyc_Tcutil_boundscmp, _temp779, _temp793);{ void*
_temp922=( void*)((( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x))
Cyc_Absyn_compress_conref)( _temp779))->v; void* _temp928; _LL924: if((
unsigned int) _temp922 > 1u?(( struct _enum_struct*) _temp922)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL929: _temp928=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp922)->f1;
if( _temp928 == Cyc_Absyn_Unknown_b){ goto _LL925;} else{ goto _LL926;}} else{
goto _LL926;} _LL926: goto _LL927; _LL925: return; _LL927: goto _LL923; _LL923:;}((
void(*)( int(* cmp)( int, int), struct Cyc_Absyn_Conref* x, struct Cyc_Absyn_Conref*
y)) Cyc_Tcutil_unify_it_conrefs)( Cyc_Core_intcmp, _temp783, _temp797); return;
_LL684: if( _temp807 == _temp813? _temp805 == _temp811: 0){ return;} goto _LL668;
_LL686: return; _LL688: return; _LL690: Cyc_Tcutil_unify_it( _temp829, _temp837);
Cyc_Tcutil_unify_tqual( _temp827, _temp835); if( Cyc_Evexp_eval_const_uint_exp(
_temp833) == Cyc_Evexp_eval_const_uint_exp( _temp825)){ return;} goto _LL668;
_LL692: { struct Cyc_List_List* inst= 0; while( _temp853 != 0) { if( _temp869 ==
0){ break;} inst=({ struct Cyc_List_List* _temp930=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp930->hd=( void*)({ struct
_tuple5* _temp931=( struct _tuple5*) GC_malloc( sizeof( struct _tuple5));
_temp931->f1=( struct Cyc_Absyn_Tvar*) _temp869->hd; _temp931->f2=({ struct Cyc_Absyn_VarType_struct*
_temp932=( struct Cyc_Absyn_VarType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct));
_temp932->tag= Cyc_Absyn_VarType_tag; _temp932->f1=( struct Cyc_Absyn_Tvar*)
_temp853->hd;( void*) _temp932;}); _temp931;}); _temp930->tl= inst; _temp930;});
_temp853= _temp853->tl; _temp869= _temp869->tl;} if( _temp869 != 0){ goto _LL668;}
if( inst != 0){ Cyc_Tcutil_unify_it(({ struct Cyc_Absyn_FnType_struct* _temp933=(
struct Cyc_Absyn_FnType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_FnType_struct));
_temp933->tag= Cyc_Absyn_FnType_tag; _temp933->f1=({ struct Cyc_Absyn_FnInfo
_temp934; _temp934.tvars= 0; _temp934.effect= _temp851; _temp934.ret_typ=( void*)
_temp849; _temp934.args= _temp847; _temp934.varargs= _temp845; _temp934.attributes=
_temp843; _temp934;});( void*) _temp933;}), Cyc_Tcutil_substitute( inst,({
struct Cyc_Absyn_FnType_struct* _temp935=( struct Cyc_Absyn_FnType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_FnType_struct)); _temp935->tag= Cyc_Absyn_FnType_tag;
_temp935->f1=({ struct Cyc_Absyn_FnInfo _temp936; _temp936.tvars= 0; _temp936.effect=
_temp867; _temp936.ret_typ=( void*) _temp865; _temp936.args= _temp863; _temp936.varargs=
_temp861; _temp936.attributes= _temp859; _temp936;});( void*) _temp935;})));
return;} Cyc_Tcutil_unify_it( _temp849, _temp865); for( 0; _temp847 != 0?
_temp863 != 0: 0; _temp847= _temp847->tl, _temp863= _temp863->tl){ Cyc_Tcutil_unify_tqual((*((
struct _tuple2*) _temp847->hd)).f2,(*(( struct _tuple2*) _temp863->hd)).f2); Cyc_Tcutil_unify_it((*((
struct _tuple2*) _temp847->hd)).f3,(*(( struct _tuple2*) _temp863->hd)).f3);}
if( _temp847 != 0? 1: _temp863 != 0){ goto _LL668;} if( _temp845 != _temp861){
goto _LL668;} if(( _temp851 == 0? _temp867 != 0: 0)? 1:( _temp851 != 0? _temp867
== 0: 0)){ goto _LL668;} if( ! Cyc_Tcutil_unify_effect(( void*) _temp851->v,(
void*) _temp867->v)){ goto _LL668;} if( ! Cyc_Tcutil_same_atts( _temp859,
_temp843)){ goto _LL668;} return;} _LL694: for( 0; _temp873 != 0? _temp877 != 0:
0; _temp873= _temp873->tl, _temp877= _temp877->tl){ Cyc_Tcutil_unify_tqual((*((
struct _tuple4*) _temp873->hd)).f1,(*(( struct _tuple4*) _temp877->hd)).f1); Cyc_Tcutil_unify_it((*((
struct _tuple4*) _temp873->hd)).f2,(*(( struct _tuple4*) _temp877->hd)).f2);}
if( _temp873 == 0? _temp877 == 0: 0){ return;} goto _LL668; _LL696: return;
_LL698: Cyc_Tcutil_unify_it( _temp889, _temp885); return; _LL700: goto _LL702;
_LL702: goto _LL704; _LL704: goto _LL706; _LL706: if( Cyc_Tcutil_unify_effect(
t1, t2)){ return;} else{ goto _LL668;} _LL708: goto _LL668; _LL668:;}( void)
_throw(({ struct Cyc_Tcutil_Unify_struct* _temp937=( struct Cyc_Tcutil_Unify_struct*)
GC_malloc_atomic( sizeof( struct Cyc_Tcutil_Unify_struct));* _temp937=( struct
Cyc_Tcutil_Unify_struct){.tag= Cyc_Tcutil_Unify_tag};( struct _xenum_struct*)
_temp937;}));} int Cyc_Tcutil_is_arithmetic_type( void* t){ void* _temp938= Cyc_Tcutil_compress(
t); void* _temp948; void* _temp950; _LL940: if(( unsigned int) _temp938 > 5u?((
struct _enum_struct*) _temp938)->tag == Cyc_Absyn_IntType_tag: 0){ _LL951:
_temp950=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp938)->f1; goto _LL949;
_LL949: _temp948=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp938)->f2;
goto _LL941;} else{ goto _LL942;} _LL942: if( _temp938 == Cyc_Absyn_FloatType){
goto _LL943;} else{ goto _LL944;} _LL944: if( _temp938 == Cyc_Absyn_DoubleType){
goto _LL945;} else{ goto _LL946;} _LL946: goto _LL947; _LL941: return 1; _LL943:
return 1; _LL945: return 1; _LL947: return 0; _LL939:;} int Cyc_Tcutil_will_lose_precision(
void* t1, void* t2){ t1= Cyc_Tcutil_compress( t1); t2= Cyc_Tcutil_compress( t2);{
struct _tuple7 _temp953=({ struct _tuple7 _temp952; _temp952.f1= t1; _temp952.f2=
t2; _temp952;}); void* _temp975; void* _temp977; void* _temp979; void* _temp981;
void* _temp983; void* _temp985; void* _temp987; void* _temp989; void* _temp991;
void* _temp993; void* _temp995; void* _temp997; void* _temp999; void* _temp1001;
void* _temp1003; void* _temp1005; void* _temp1007; void* _temp1009; void*
_temp1011; void* _temp1013; void* _temp1015; void* _temp1017; void* _temp1019;
void* _temp1021; void* _temp1023; void* _temp1025; void* _temp1027; void*
_temp1029; void* _temp1031; void* _temp1033; void* _temp1035; void* _temp1037;
void* _temp1039; void* _temp1041; void* _temp1043; void* _temp1045; void*
_temp1047; void* _temp1049; void* _temp1051; void* _temp1053; void* _temp1055;
void* _temp1057; _LL955: _LL978: _temp977= _temp953.f1; if( _temp977 == Cyc_Absyn_DoubleType){
goto _LL976;} else{ goto _LL957;} _LL976: _temp975= _temp953.f2; if( _temp975 ==
Cyc_Absyn_FloatType){ goto _LL956;} else{ goto _LL957;} _LL957: _LL986: _temp985=
_temp953.f1; if( _temp985 == Cyc_Absyn_DoubleType){ goto _LL980;} else{ goto
_LL959;} _LL980: _temp979= _temp953.f2; if(( unsigned int) _temp979 > 5u?((
struct _enum_struct*) _temp979)->tag == Cyc_Absyn_IntType_tag: 0){ _LL984:
_temp983=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp979)->f1; goto _LL982;
_LL982: _temp981=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp979)->f2;
goto _LL958;} else{ goto _LL959;} _LL959: _LL994: _temp993= _temp953.f1; if(
_temp993 == Cyc_Absyn_FloatType){ goto _LL988;} else{ goto _LL961;} _LL988:
_temp987= _temp953.f2; if(( unsigned int) _temp987 > 5u?(( struct _enum_struct*)
_temp987)->tag == Cyc_Absyn_IntType_tag: 0){ _LL992: _temp991=( void*)(( struct
Cyc_Absyn_IntType_struct*) _temp987)->f1; goto _LL990; _LL990: _temp989=( void*)((
struct Cyc_Absyn_IntType_struct*) _temp987)->f2; goto _LL960;} else{ goto _LL961;}
_LL961: _LL1002: _temp1001= _temp953.f1; if(( unsigned int) _temp1001 > 5u?((
struct _enum_struct*) _temp1001)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1006:
_temp1005=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1001)->f1; goto
_LL1004; _LL1004: _temp1003=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1001)->f2; if( _temp1003 == Cyc_Absyn_B8){ goto _LL996;} else{ goto _LL963;}}
else{ goto _LL963;} _LL996: _temp995= _temp953.f2; if(( unsigned int) _temp995 >
5u?(( struct _enum_struct*) _temp995)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1000:
_temp999=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp995)->f1; goto _LL998;
_LL998: _temp997=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp995)->f2; if(
_temp997 == Cyc_Absyn_B8){ goto _LL962;} else{ goto _LL963;}} else{ goto _LL963;}
_LL963: _LL1010: _temp1009= _temp953.f1; if(( unsigned int) _temp1009 > 5u?((
struct _enum_struct*) _temp1009)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1014:
_temp1013=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1009)->f1; goto
_LL1012; _LL1012: _temp1011=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1009)->f2; if( _temp1011 == Cyc_Absyn_B8){ goto _LL1008;} else{ goto _LL965;}}
else{ goto _LL965;} _LL1008: _temp1007= _temp953.f2; goto _LL964; _LL965:
_LL1018: _temp1017= _temp953.f1; if(( unsigned int) _temp1017 > 5u?(( struct
_enum_struct*) _temp1017)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1022: _temp1021=(
void*)(( struct Cyc_Absyn_IntType_struct*) _temp1017)->f1; goto _LL1020; _LL1020:
_temp1019=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1017)->f2; if(
_temp1019 == Cyc_Absyn_B4){ goto _LL1016;} else{ goto _LL967;}} else{ goto
_LL967;} _LL1016: _temp1015= _temp953.f2; if( _temp1015 == Cyc_Absyn_FloatType){
goto _LL966;} else{ goto _LL967;} _LL967: _LL1030: _temp1029= _temp953.f1; if((
unsigned int) _temp1029 > 5u?(( struct _enum_struct*) _temp1029)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1034: _temp1033=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1029)->f1;
goto _LL1032; _LL1032: _temp1031=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1029)->f2; if( _temp1031 == Cyc_Absyn_B4){ goto _LL1024;} else{ goto _LL969;}}
else{ goto _LL969;} _LL1024: _temp1023= _temp953.f2; if(( unsigned int)
_temp1023 > 5u?(( struct _enum_struct*) _temp1023)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1028: _temp1027=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1023)->f1;
goto _LL1026; _LL1026: _temp1025=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1023)->f2; if( _temp1025 == Cyc_Absyn_B2){ goto _LL968;} else{ goto _LL969;}}
else{ goto _LL969;} _LL969: _LL1042: _temp1041= _temp953.f1; if(( unsigned int)
_temp1041 > 5u?(( struct _enum_struct*) _temp1041)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1046: _temp1045=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1041)->f1;
goto _LL1044; _LL1044: _temp1043=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1041)->f2; if( _temp1043 == Cyc_Absyn_B4){ goto _LL1036;} else{ goto _LL971;}}
else{ goto _LL971;} _LL1036: _temp1035= _temp953.f2; if(( unsigned int)
_temp1035 > 5u?(( struct _enum_struct*) _temp1035)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1040: _temp1039=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1035)->f1;
goto _LL1038; _LL1038: _temp1037=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1035)->f2; if( _temp1037 == Cyc_Absyn_B1){ goto _LL970;} else{ goto _LL971;}}
else{ goto _LL971;} _LL971: _LL1054: _temp1053= _temp953.f1; if(( unsigned int)
_temp1053 > 5u?(( struct _enum_struct*) _temp1053)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1058: _temp1057=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1053)->f1;
goto _LL1056; _LL1056: _temp1055=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1053)->f2; if( _temp1055 == Cyc_Absyn_B2){ goto _LL1048;} else{ goto _LL973;}}
else{ goto _LL973;} _LL1048: _temp1047= _temp953.f2; if(( unsigned int)
_temp1047 > 5u?(( struct _enum_struct*) _temp1047)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1052: _temp1051=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1047)->f1;
goto _LL1050; _LL1050: _temp1049=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1047)->f2; if( _temp1049 == Cyc_Absyn_B1){ goto _LL972;} else{ goto _LL973;}}
else{ goto _LL973;} _LL973: goto _LL974; _LL956: return 1; _LL958: return 1;
_LL960: return 1; _LL962: return 0; _LL964: return 1; _LL966: return 1; _LL968:
return 1; _LL970: return 1; _LL972: return 1; _LL974: return 0; _LL954:;}} int
Cyc_Tcutil_coerce_list( struct Cyc_Tcenv_Tenv* te, void* t, struct Cyc_List_List*
es){ struct Cyc_Core_Opt* max_arith_type= 0;{ struct Cyc_List_List* el= es; for(
0; el != 0; el= el->tl){ void* t1= Cyc_Tcutil_compress(( void*)((( struct Cyc_Absyn_Exp*)
el->hd)->topt)->v); if( Cyc_Tcutil_is_arithmetic_type( t1)){ if( max_arith_type
== 0? 1: Cyc_Tcutil_will_lose_precision( t1,( void*) max_arith_type->v)){
max_arith_type=({ struct Cyc_Core_Opt* _temp1059=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1059->v=( void*) t1; _temp1059;});}}}}
if( max_arith_type != 0){ if( ! Cyc_Tcutil_unify( t,( void*) max_arith_type->v)){
return 0;}}{ struct Cyc_List_List* el= es; for( 0; el != 0; el= el->tl){ if( !
Cyc_Tcutil_coerce_assign( te,( struct Cyc_Absyn_Exp*) el->hd, t)){ Cyc_Tcutil_terr(((
struct Cyc_Absyn_Exp*) el->hd)->loc,({ struct _tagged_string _temp1060= Cyc_Absynpp_typ2string(
t); struct _tagged_string _temp1061= Cyc_Absynpp_typ2string(( void*)((( struct
Cyc_Absyn_Exp*) el->hd)->topt)->v); xprintf("type mismatch: expecting %.*s but found %.*s",
_temp1060.last_plus_one - _temp1060.curr, _temp1060.curr, _temp1061.last_plus_one
- _temp1061.curr, _temp1061.curr);})); return 0;}}} return 1;} int Cyc_Tcutil_coerce_to_bool(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e){ if( ! Cyc_Tcutil_coerce_sint_typ(
te, e)){ void* _temp1062= Cyc_Tcutil_compress(( void*)( e->topt)->v); struct Cyc_Absyn_PtrInfo
_temp1068; _LL1064: if(( unsigned int) _temp1062 > 5u?(( struct _enum_struct*)
_temp1062)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL1069: _temp1068=( struct
Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*) _temp1062)->f1; goto
_LL1065;} else{ goto _LL1066;} _LL1066: goto _LL1067; _LL1065: Cyc_Tcutil_unchecked_cast(
te, e, Cyc_Absyn_uint_t); goto _LL1063; _LL1067: return 0; _LL1063:;} return 1;}
int Cyc_Tcutil_is_integral_type( void* t){ void* _temp1070= Cyc_Tcutil_compress(
t); void* _temp1076; void* _temp1078; _LL1072: if(( unsigned int) _temp1070 > 5u?((
struct _enum_struct*) _temp1070)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1079:
_temp1078=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1070)->f1; goto
_LL1077; _LL1077: _temp1076=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1070)->f2; goto _LL1073;} else{ goto _LL1074;} _LL1074: goto _LL1075;
_LL1073: return 1; _LL1075: return 0; _LL1071:;} int Cyc_Tcutil_coerce_uint_typ(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e){ if( Cyc_Tcutil_unify(( void*)(
e->topt)->v, Cyc_Absyn_uint_t)){ return 1;} if( Cyc_Tcutil_is_integral_type((
void*)( e->topt)->v)){ if( Cyc_Tcutil_will_lose_precision(( void*)( e->topt)->v,
Cyc_Absyn_uint_t)){ Cyc_Tcutil_warn( e->loc,( struct _tagged_string)({ char*
_temp1080=( char*)"integral size mismatch; conversion supplied"; struct
_tagged_string _temp1081; _temp1081.curr= _temp1080; _temp1081.base= _temp1080;
_temp1081.last_plus_one= _temp1080 + 44; _temp1081;}));} Cyc_Tcutil_unchecked_cast(
te, e, Cyc_Absyn_uint_t); return 1;} return 0;} int Cyc_Tcutil_coerce_sint_typ(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e){ if( Cyc_Tcutil_unify(( void*)(
e->topt)->v, Cyc_Absyn_sint_t)){ return 1;} if( Cyc_Tcutil_is_integral_type((
void*)( e->topt)->v)){ if( Cyc_Tcutil_will_lose_precision(( void*)( e->topt)->v,
Cyc_Absyn_sint_t)){ Cyc_Tcutil_warn( e->loc,( struct _tagged_string)({ char*
_temp1082=( char*)"integral size mismatch; conversion supplied"; struct
_tagged_string _temp1083; _temp1083.curr= _temp1082; _temp1083.base= _temp1082;
_temp1083.last_plus_one= _temp1082 + 44; _temp1083;}));} Cyc_Tcutil_unchecked_cast(
te, e, Cyc_Absyn_sint_t); return 1;} return 0;} int Cyc_Tcutil_silent_castable(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void* t1, void* t2){
t1= Cyc_Tcutil_compress( t1); t2= Cyc_Tcutil_compress( t2);{ struct _tuple7
_temp1085=({ struct _tuple7 _temp1084; _temp1084.f1= t1; _temp1084.f2= t2;
_temp1084;}); void* _temp1093; struct Cyc_Absyn_PtrInfo _temp1095; void*
_temp1097; struct Cyc_Absyn_PtrInfo _temp1099; void* _temp1101; struct Cyc_Absyn_Exp*
_temp1103; struct Cyc_Absyn_Tqual* _temp1105; void* _temp1107; void* _temp1109;
struct Cyc_Absyn_Exp* _temp1111; struct Cyc_Absyn_Tqual* _temp1113; void*
_temp1115; _LL1087: _LL1098: _temp1097= _temp1085.f1; if(( unsigned int)
_temp1097 > 5u?(( struct _enum_struct*) _temp1097)->tag == Cyc_Absyn_PointerType_tag:
0){ _LL1100: _temp1099=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp1097)->f1; goto _LL1094;} else{ goto _LL1089;} _LL1094: _temp1093=
_temp1085.f2; if(( unsigned int) _temp1093 > 5u?(( struct _enum_struct*)
_temp1093)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL1096: _temp1095=( struct
Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*) _temp1093)->f1; goto
_LL1088;} else{ goto _LL1089;} _LL1089: _LL1110: _temp1109= _temp1085.f1; if((
unsigned int) _temp1109 > 5u?(( struct _enum_struct*) _temp1109)->tag == Cyc_Absyn_ArrayType_tag:
0){ _LL1116: _temp1115=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1109)->f1;
goto _LL1114; _LL1114: _temp1113=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1109)->f2; goto _LL1112; _LL1112: _temp1111=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1109)->f3; goto _LL1102;} else{ goto
_LL1091;} _LL1102: _temp1101= _temp1085.f2; if(( unsigned int) _temp1101 > 5u?((
struct _enum_struct*) _temp1101)->tag == Cyc_Absyn_ArrayType_tag: 0){ _LL1108:
_temp1107=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1101)->f1; goto
_LL1106; _LL1106: _temp1105=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1101)->f2; goto _LL1104; _LL1104: _temp1103=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1101)->f3; goto _LL1090;} else{ goto
_LL1091;} _LL1091: goto _LL1092; _LL1088: { int okay= 1; if( !(( int(*)( int(*
cmp)( int, int), struct Cyc_Absyn_Conref* x, struct Cyc_Absyn_Conref* y)) Cyc_Tcutil_unify_conrefs)(
Cyc_Core_intcmp, _temp1099.nullable, _temp1095.nullable)){ void* _temp1117=(
void*)((( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)(
_temp1099.nullable))->v; int _temp1123; _LL1119: if(( unsigned int) _temp1117 >
1u?(( struct _enum_struct*) _temp1117)->tag == Cyc_Absyn_Eq_constr_tag: 0){
_LL1124: _temp1123=( int)(( struct Cyc_Absyn_Eq_constr_struct*) _temp1117)->f1;
goto _LL1120;} else{ goto _LL1121;} _LL1121: goto _LL1122; _LL1120: okay= !
_temp1123; goto _LL1118; _LL1122:( void) _throw((( struct _xenum_struct*(*)(
struct _tagged_string msg)) Cyc_Tcutil_impos)(( struct _tagged_string)({ char*
_temp1125=( char*)"silent_castable conref not eq"; struct _tagged_string
_temp1126; _temp1126.curr= _temp1125; _temp1126.base= _temp1125; _temp1126.last_plus_one=
_temp1125 + 30; _temp1126;}))); _LL1118:;} if( !(( int(*)( int(* cmp)( void*,
void*), struct Cyc_Absyn_Conref* x, struct Cyc_Absyn_Conref* y)) Cyc_Tcutil_unify_conrefs)(
Cyc_Tcutil_boundscmp, _temp1099.bounds, _temp1095.bounds)){ struct _tuple7
_temp1128=({ struct _tuple7 _temp1127; _temp1127.f1=( void*)((( struct Cyc_Absyn_Conref*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)( _temp1099.bounds))->v;
_temp1127.f2=( void*)((( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x))
Cyc_Absyn_compress_conref)( _temp1095.bounds))->v; _temp1127;}); void* _temp1136;
void* _temp1138; void* _temp1140; void* _temp1142; struct Cyc_Absyn_Exp*
_temp1144; void* _temp1146; void* _temp1148; void* _temp1150; void* _temp1152;
_LL1130: _LL1141: _temp1140= _temp1128.f1; if(( unsigned int) _temp1140 > 1u?((
struct _enum_struct*) _temp1140)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL1143:
_temp1142=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp1140)->f1; if((
unsigned int) _temp1142 > 1u?(( struct _enum_struct*) _temp1142)->tag == Cyc_Absyn_Upper_b_tag:
0){ _LL1145: _temp1144=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*)
_temp1142)->f1; goto _LL1137;} else{ goto _LL1132;}} else{ goto _LL1132;}
_LL1137: _temp1136= _temp1128.f2; if(( unsigned int) _temp1136 > 1u?(( struct
_enum_struct*) _temp1136)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL1139:
_temp1138=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp1136)->f1; if(
_temp1138 == Cyc_Absyn_Unknown_b){ goto _LL1131;} else{ goto _LL1132;}} else{
goto _LL1132;} _LL1132: _LL1151: _temp1150= _temp1128.f1; if(( unsigned int)
_temp1150 > 1u?(( struct _enum_struct*) _temp1150)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL1153: _temp1152=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp1150)->f1;
if( _temp1152 == Cyc_Absyn_Unknown_b){ goto _LL1147;} else{ goto _LL1134;}}
else{ goto _LL1134;} _LL1147: _temp1146= _temp1128.f2; if(( unsigned int)
_temp1146 > 1u?(( struct _enum_struct*) _temp1146)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL1149: _temp1148=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp1146)->f1;
if( _temp1148 == Cyc_Absyn_Unknown_b){ goto _LL1133;} else{ goto _LL1134;}}
else{ goto _LL1134;} _LL1134: goto _LL1135; _LL1131: okay= 1; goto _LL1129;
_LL1133: okay= 1; goto _LL1129; _LL1135: okay= 0; goto _LL1129; _LL1129:;}
return(( okay? Cyc_Tcutil_unify(( void*) _temp1099.elt_typ,( void*) _temp1095.elt_typ):
0)? Cyc_Tcutil_unify(( void*) _temp1099.rgn_typ,( void*) _temp1095.rgn_typ): 0)?
!( _temp1099.tq)->q_const? 1:( _temp1095.tq)->q_const: 0;} _LL1090: { int okay;
okay= Cyc_Evexp_eval_const_uint_exp( _temp1111) >= Cyc_Evexp_eval_const_uint_exp(
_temp1103); return( okay? Cyc_Tcutil_unify( _temp1115, _temp1107): 0)? !
_temp1113->q_const? 1: _temp1105->q_const: 0;} _LL1092: return Cyc_Tcutil_unify(
t1, t2); _LL1086:;}} int Cyc_Tcutil_coerce_arg( struct Cyc_Tcenv_Tenv* te,
struct Cyc_Absyn_Exp* e, void* t2){ void* t1= Cyc_Tcutil_compress(( void*)( e->topt)->v);
if( Cyc_Tcutil_unify( t1, t2)){ return 1;} if( Cyc_Tcutil_is_arithmetic_type( t1)?
Cyc_Tcutil_is_arithmetic_type( t2): 0){ if( Cyc_Tcutil_will_lose_precision( t1,
t2)){ Cyc_Tcutil_warn( e->loc,( struct _tagged_string)({ char* _temp1154=( char*)"integral size mismatch; conversion supplied";
struct _tagged_string _temp1155; _temp1155.curr= _temp1154; _temp1155.base=
_temp1154; _temp1155.last_plus_one= _temp1154 + 44; _temp1155;}));} Cyc_Tcutil_unchecked_cast(
te, e, t2); return 1;} else{ if( Cyc_Tcutil_silent_castable( te, e->loc, t1, t2)){
Cyc_Tcutil_unchecked_cast( te, e, t2); return 1;} else{ if( Cyc_Tcutil_castable(
te, e->loc, t1, t2)){ Cyc_Tcutil_unchecked_cast( te, e, t2); Cyc_Tcutil_warn( e->loc,({
struct _tagged_string _temp1156= Cyc_Absynpp_typ2string( t1); struct
_tagged_string _temp1157= Cyc_Absynpp_typ2string( t2); xprintf("implicit cast from %.*s to %.*s",
_temp1156.last_plus_one - _temp1156.curr, _temp1156.curr, _temp1157.last_plus_one
- _temp1157.curr, _temp1157.curr);})); return 1;} else{ return 0;}}}} int Cyc_Tcutil_coerce_assign(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e, void* t){ return Cyc_Tcutil_coerce_arg(
te, e, t);} static int Cyc_Tcutil_any_promote( struct Cyc_Tcenv_Tenv* te, struct
Cyc_Absyn_Exp* e){ void* old_typ= Cyc_Tcutil_compress(( void*)( e->topt)->v);
void* t;{ void* _temp1158= old_typ; void* _temp1168; void* _temp1170; _LL1160:
if(( unsigned int) _temp1158 > 5u?(( struct _enum_struct*) _temp1158)->tag ==
Cyc_Absyn_IntType_tag: 0){ _LL1171: _temp1170=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1158)->f1; goto _LL1169; _LL1169: _temp1168=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1158)->f2; goto _LL1161;} else{ goto _LL1162;} _LL1162: if( _temp1158 ==
Cyc_Absyn_FloatType){ goto _LL1163;} else{ goto _LL1164;} _LL1164: if( _temp1158
== Cyc_Absyn_DoubleType){ goto _LL1165;} else{ goto _LL1166;} _LL1166: goto
_LL1167; _LL1161:{ void* _temp1172= _temp1168; _LL1174: if( _temp1172 == Cyc_Absyn_B1){
goto _LL1175;} else{ goto _LL1176;} _LL1176: if( _temp1172 == Cyc_Absyn_B2){
goto _LL1177;} else{ goto _LL1178;} _LL1178: if( _temp1172 == Cyc_Absyn_B4){
goto _LL1179;} else{ goto _LL1180;} _LL1180: if( _temp1172 == Cyc_Absyn_B8){
goto _LL1181;} else{ goto _LL1173;} _LL1175: t= Cyc_Absyn_sint_t; goto _LL1173;
_LL1177: t= Cyc_Absyn_sint_t; goto _LL1173; _LL1179: t= _temp1170 == Cyc_Absyn_Unsigned?
Cyc_Absyn_uint_t: Cyc_Absyn_sint_t; goto _LL1173; _LL1181: t= _temp1170 == Cyc_Absyn_Unsigned?
Cyc_Absyn_ulong_t: Cyc_Absyn_slong_t; goto _LL1173; _LL1173:;} goto _LL1159;
_LL1163: t= Cyc_Absyn_float_t; goto _LL1159; _LL1165: t= Cyc_Absyn_double_t;
goto _LL1159; _LL1167: return 0; _LL1159:;} Cyc_Tcutil_unchecked_cast( te, e, t);
return 1;} int Cyc_Tcutil_coerce_use( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp*
e, void* t2){ void* t1= Cyc_Tcutil_compress(( void*)( e->topt)->v); if( Cyc_Tcutil_unify(
t1, t2)){ return 1;} Cyc_Tcutil_any_promote( te, e); if( Cyc_Tcutil_unify(( void*)(
e->topt)->v, t2)){ return 1;} else{ if( Cyc_Tcutil_silent_castable( te, e->loc,
t1, t2)){ Cyc_Tcutil_unchecked_cast( te, e, t2); return 1;} else{ if( Cyc_Tcutil_castable(
te, e->loc, t1, t2)){ Cyc_Tcutil_unchecked_cast( te, e, t2); Cyc_Tcutil_warn( e->loc,({
struct _tagged_string _temp1182= Cyc_Absynpp_typ2string( t1); struct
_tagged_string _temp1183= Cyc_Absynpp_typ2string( t2); xprintf("implicit cast from %.*s to %.*s",
_temp1182.last_plus_one - _temp1182.curr, _temp1182.curr, _temp1183.last_plus_one
- _temp1183.curr, _temp1183.curr);})); return 1;} else{ return 0;}}}} int Cyc_Tcutil_coerceable(
void* t){ void* _temp1184= Cyc_Tcutil_compress( t); void* _temp1194; void*
_temp1196; _LL1186: if(( unsigned int) _temp1184 > 5u?(( struct _enum_struct*)
_temp1184)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1197: _temp1196=( void*)((
struct Cyc_Absyn_IntType_struct*) _temp1184)->f1; goto _LL1195; _LL1195:
_temp1194=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1184)->f2; goto
_LL1187;} else{ goto _LL1188;} _LL1188: if( _temp1184 == Cyc_Absyn_FloatType){
goto _LL1189;} else{ goto _LL1190;} _LL1190: if( _temp1184 == Cyc_Absyn_DoubleType){
goto _LL1191;} else{ goto _LL1192;} _LL1192: goto _LL1193; _LL1187: return 1;
_LL1189: return 1; _LL1191: return 1; _LL1193: return 0; _LL1185:;} static
struct _tuple4* Cyc_Tcutil_flatten_typ_f( struct Cyc_List_List* inst, struct Cyc_Absyn_Structfield*
x){ return({ struct _tuple4* _temp1198=( struct _tuple4*) GC_malloc( sizeof(
struct _tuple4)); _temp1198->f1= x->tq; _temp1198->f2= Cyc_Tcutil_substitute(
inst,( void*) x->type); _temp1198;});} static struct Cyc_List_List* Cyc_Tcutil_flatten_typ(
struct Cyc_Tcenv_Tenv* te, void* t1){ t1= Cyc_Tcutil_compress( t1);{ void*
_temp1199= t1; struct Cyc_List_List* _temp1209; struct Cyc_Absyn_Structdecl**
_temp1211; struct Cyc_List_List* _temp1213; struct _tuple1* _temp1215; _LL1201:
if( _temp1199 == Cyc_Absyn_VoidType){ goto _LL1202;} else{ goto _LL1203;}
_LL1203: if(( unsigned int) _temp1199 > 5u?(( struct _enum_struct*) _temp1199)->tag
== Cyc_Absyn_TupleType_tag: 0){ _LL1210: _temp1209=( struct Cyc_List_List*)((
struct Cyc_Absyn_TupleType_struct*) _temp1199)->f1; goto _LL1204;} else{ goto
_LL1205;} _LL1205: if(( unsigned int) _temp1199 > 5u?(( struct _enum_struct*)
_temp1199)->tag == Cyc_Absyn_StructType_tag: 0){ _LL1216: _temp1215=( struct
_tuple1*)(( struct Cyc_Absyn_StructType_struct*) _temp1199)->f1; goto _LL1214;
_LL1214: _temp1213=( struct Cyc_List_List*)(( struct Cyc_Absyn_StructType_struct*)
_temp1199)->f2; goto _LL1212; _LL1212: _temp1211=( struct Cyc_Absyn_Structdecl**)((
struct Cyc_Absyn_StructType_struct*) _temp1199)->f3; goto _LL1206;} else{ goto
_LL1207;} _LL1207: goto _LL1208; _LL1202: return 0; _LL1204: return _temp1209;
_LL1206: if( _temp1211 == 0? 1: _temp1215 == 0){ return({ struct Cyc_List_List*
_temp1217=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1217->hd=( void*)({ struct _tuple4* _temp1218=( struct _tuple4*) GC_malloc(
sizeof( struct _tuple4)); _temp1218->f1= Cyc_Absyn_empty_tqual(); _temp1218->f2=
t1; _temp1218;}); _temp1217->tl= 0; _temp1217;});}{ struct Cyc_Absyn_Structdecl*
sd=* _temp1211; struct _tuple1 n=* _temp1215; struct Cyc_List_List* inst=((
struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_zip)(
sd->tvs, _temp1213); if( sd->fields == 0){ return({ struct Cyc_List_List*
_temp1219=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1219->hd=( void*)({ struct _tuple4* _temp1220=( struct _tuple4*) GC_malloc(
sizeof( struct _tuple4)); _temp1220->f1= Cyc_Absyn_empty_tqual(); _temp1220->f2=
t1; _temp1220;}); _temp1219->tl= 0; _temp1219;});} return(( struct Cyc_List_List*(*)(
struct _tuple4*(* f)( struct Cyc_List_List*, struct Cyc_Absyn_Structfield*),
struct Cyc_List_List* env, struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Tcutil_flatten_typ_f,
inst,( struct Cyc_List_List*)( sd->fields)->v);} _LL1208: return({ struct Cyc_List_List*
_temp1221=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1221->hd=( void*)({ struct _tuple4* _temp1222=( struct _tuple4*) GC_malloc(
sizeof( struct _tuple4)); _temp1222->f1= Cyc_Absyn_empty_tqual(); _temp1222->f2=
t1; _temp1222;}); _temp1221->tl= 0; _temp1221;}); _LL1200:;}} static int Cyc_Tcutil_ptrsubtype(
struct Cyc_Tcenv_Tenv* te, struct Cyc_List_List* assume, void* t1, void* t2);
static int Cyc_Tcutil_subtype( struct Cyc_Tcenv_Tenv* te, struct Cyc_List_List*
assume, void* t1, void* t2){ if( Cyc_Tcutil_unify( t1, t2)){ return 1;}{ struct
Cyc_List_List* a= assume; for( 0; a != 0; a= a->tl){ if( Cyc_Tcutil_unify( t1,(*((
struct _tuple7*) a->hd)).f1)? Cyc_Tcutil_unify( t2,(*(( struct _tuple7*) a->hd)).f2):
0){ return 1;}}} t1= Cyc_Tcutil_compress( t1); t2= Cyc_Tcutil_compress( t2);{
struct _tuple7 _temp1224=({ struct _tuple7 _temp1223; _temp1223.f1= t1;
_temp1223.f2= t2; _temp1223;}); void* _temp1230; struct Cyc_Absyn_PtrInfo
_temp1232; struct Cyc_Absyn_Conref* _temp1234; struct Cyc_Absyn_Tqual* _temp1236;
struct Cyc_Absyn_Conref* _temp1238; void* _temp1240; void* _temp1242; void*
_temp1244; struct Cyc_Absyn_PtrInfo _temp1246; struct Cyc_Absyn_Conref*
_temp1248; struct Cyc_Absyn_Tqual* _temp1250; struct Cyc_Absyn_Conref* _temp1252;
void* _temp1254; void* _temp1256; _LL1226: _LL1245: _temp1244= _temp1224.f1; if((
unsigned int) _temp1244 > 5u?(( struct _enum_struct*) _temp1244)->tag == Cyc_Absyn_PointerType_tag:
0){ _LL1247: _temp1246=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp1244)->f1; _LL1257: _temp1256=( void*) _temp1246.elt_typ; goto _LL1255;
_LL1255: _temp1254=( void*) _temp1246.rgn_typ; goto _LL1253; _LL1253: _temp1252=(
struct Cyc_Absyn_Conref*) _temp1246.nullable; goto _LL1251; _LL1251: _temp1250=(
struct Cyc_Absyn_Tqual*) _temp1246.tq; goto _LL1249; _LL1249: _temp1248=( struct
Cyc_Absyn_Conref*) _temp1246.bounds; goto _LL1231;} else{ goto _LL1228;} _LL1231:
_temp1230= _temp1224.f2; if(( unsigned int) _temp1230 > 5u?(( struct
_enum_struct*) _temp1230)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL1233:
_temp1232=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp1230)->f1; _LL1243: _temp1242=( void*) _temp1232.elt_typ; goto _LL1241;
_LL1241: _temp1240=( void*) _temp1232.rgn_typ; goto _LL1239; _LL1239: _temp1238=(
struct Cyc_Absyn_Conref*) _temp1232.nullable; goto _LL1237; _LL1237: _temp1236=(
struct Cyc_Absyn_Tqual*) _temp1232.tq; goto _LL1235; _LL1235: _temp1234=( struct
Cyc_Absyn_Conref*) _temp1232.bounds; goto _LL1227;} else{ goto _LL1228;} _LL1228:
goto _LL1229; _LL1227: if( _temp1250->q_const? ! _temp1236->q_const: 0){ return
0;} if(( !(( int(*)( int(* cmp)( int, int), struct Cyc_Absyn_Conref* x, struct
Cyc_Absyn_Conref* y)) Cyc_Tcutil_unify_conrefs)( Cyc_Core_intcmp, _temp1252,
_temp1238)?(( int(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(
_temp1252): 0)? !(( int(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(
_temp1238): 0){ return 0;}{ void* _temp1258= _temp1254; _LL1260: if( _temp1258
== Cyc_Absyn_HeapRgn){ goto _LL1261;} else{ goto _LL1262;} _LL1262: goto _LL1263;
_LL1261: goto _LL1259; _LL1263: Cyc_Tcutil_unify( _temp1254, _temp1240); goto
_LL1259; _LL1259:;} if( !(( int(*)( int(* cmp)( void*, void*), struct Cyc_Absyn_Conref*
x, struct Cyc_Absyn_Conref* y)) Cyc_Tcutil_unify_conrefs)( Cyc_Tcutil_boundscmp,
_temp1248, _temp1234)){ struct _tuple7 _temp1265=({ struct _tuple7 _temp1264;
_temp1264.f1=(( void*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(
_temp1248); _temp1264.f2=(( void*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(
_temp1234); _temp1264;}); void* _temp1273; void* _temp1275; struct Cyc_Absyn_Exp*
_temp1277; void* _temp1279; struct Cyc_Absyn_Exp* _temp1281; void* _temp1283;
struct Cyc_Absyn_Exp* _temp1285; _LL1267: _LL1276: _temp1275= _temp1265.f1; if((
unsigned int) _temp1275 > 1u?(( struct _enum_struct*) _temp1275)->tag == Cyc_Absyn_Upper_b_tag:
0){ _LL1278: _temp1277=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*)
_temp1275)->f1; goto _LL1274;} else{ goto _LL1269;} _LL1274: _temp1273=
_temp1265.f2; if( _temp1273 == Cyc_Absyn_Unknown_b){ goto _LL1268;} else{ goto
_LL1269;} _LL1269: _LL1284: _temp1283= _temp1265.f1; if(( unsigned int)
_temp1283 > 1u?(( struct _enum_struct*) _temp1283)->tag == Cyc_Absyn_Upper_b_tag:
0){ _LL1286: _temp1285=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*)
_temp1283)->f1; goto _LL1280;} else{ goto _LL1271;} _LL1280: _temp1279=
_temp1265.f2; if(( unsigned int) _temp1279 > 1u?(( struct _enum_struct*)
_temp1279)->tag == Cyc_Absyn_Upper_b_tag: 0){ _LL1282: _temp1281=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_Upper_b_struct*) _temp1279)->f1; goto _LL1270;} else{ goto
_LL1271;} _LL1271: goto _LL1272; _LL1268: goto _LL1266; _LL1270: if( Cyc_Evexp_eval_const_uint_exp(
_temp1285) < Cyc_Evexp_eval_const_uint_exp( _temp1281)){ return 0;} goto _LL1266;
_LL1272: return 0; _LL1266:;} return Cyc_Tcutil_ptrsubtype( te,({ struct Cyc_List_List*
_temp1287=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1287->hd=( void*)({ struct _tuple7* _temp1288=( struct _tuple7*) GC_malloc(
sizeof( struct _tuple7)); _temp1288->f1= t1; _temp1288->f2= t2; _temp1288;});
_temp1287->tl= assume; _temp1287;}), _temp1256, _temp1242); _LL1229: return 0;
_LL1225:;}} static int Cyc_Tcutil_ptrsubtype( struct Cyc_Tcenv_Tenv* te, struct
Cyc_List_List* assume, void* t1, void* t2){ struct Cyc_List_List* tqs1= Cyc_Tcutil_flatten_typ(
te, t1); struct Cyc_List_List* tqs2= Cyc_Tcutil_flatten_typ( te, t2); for( 0;
tqs2 != 0; tqs2= tqs2->tl, tqs1= tqs1->tl){ if( tqs1 == 0){ return 0;}{ struct
_tuple4 _temp1291; void* _temp1292; struct Cyc_Absyn_Tqual* _temp1294; struct
_tuple4* _temp1289=( struct _tuple4*) tqs1->hd; _temp1291=* _temp1289; _LL1295:
_temp1294= _temp1291.f1; goto _LL1293; _LL1293: _temp1292= _temp1291.f2; goto
_LL1290; _LL1290: { struct _tuple4 _temp1298; void* _temp1299; struct Cyc_Absyn_Tqual*
_temp1301; struct _tuple4* _temp1296=( struct _tuple4*) tqs2->hd; _temp1298=*
_temp1296; _LL1302: _temp1301= _temp1298.f1; goto _LL1300; _LL1300: _temp1299=
_temp1298.f2; goto _LL1297; _LL1297: if( _temp1301->q_const? Cyc_Tcutil_subtype(
te, assume, _temp1292, _temp1299): 0){ continue;} else{ if( Cyc_Tcutil_unify(
_temp1292, _temp1299)){ continue;} else{ return 0;}}}}} return 1;} int Cyc_Tcutil_castable(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void* t1, void* t2){
t1= Cyc_Tcutil_compress( t1); t2= Cyc_Tcutil_compress( t2); if( Cyc_Tcutil_unify(
t1, t2)){ return 1;}{ void* _temp1303= t1; struct Cyc_Absyn_Enumdecl** _temp1319;
struct Cyc_List_List* _temp1321; struct _tuple1* _temp1323; struct Cyc_Absyn_PtrInfo
_temp1325; struct Cyc_Absyn_Conref* _temp1327; struct Cyc_Absyn_Tqual* _temp1329;
struct Cyc_Absyn_Conref* _temp1331; void* _temp1333; void* _temp1335; struct Cyc_Absyn_Exp*
_temp1337; struct Cyc_Absyn_Tqual* _temp1339; void* _temp1341; void* _temp1343;
void* _temp1345; _LL1305: if(( unsigned int) _temp1303 > 5u?(( struct
_enum_struct*) _temp1303)->tag == Cyc_Absyn_EnumType_tag: 0){ _LL1324: _temp1323=(
struct _tuple1*)(( struct Cyc_Absyn_EnumType_struct*) _temp1303)->f1; goto
_LL1322; _LL1322: _temp1321=( struct Cyc_List_List*)(( struct Cyc_Absyn_EnumType_struct*)
_temp1303)->f2; goto _LL1320; _LL1320: _temp1319=( struct Cyc_Absyn_Enumdecl**)((
struct Cyc_Absyn_EnumType_struct*) _temp1303)->f3; goto _LL1306;} else{ goto
_LL1307;} _LL1307: if(( unsigned int) _temp1303 > 5u?(( struct _enum_struct*)
_temp1303)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL1326: _temp1325=( struct
Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*) _temp1303)->f1;
_LL1336: _temp1335=( void*) _temp1325.elt_typ; goto _LL1334; _LL1334: _temp1333=(
void*) _temp1325.rgn_typ; goto _LL1332; _LL1332: _temp1331=( struct Cyc_Absyn_Conref*)
_temp1325.nullable; goto _LL1330; _LL1330: _temp1329=( struct Cyc_Absyn_Tqual*)
_temp1325.tq; goto _LL1328; _LL1328: _temp1327=( struct Cyc_Absyn_Conref*)
_temp1325.bounds; goto _LL1308;} else{ goto _LL1309;} _LL1309: if(( unsigned int)
_temp1303 > 5u?(( struct _enum_struct*) _temp1303)->tag == Cyc_Absyn_ArrayType_tag:
0){ _LL1342: _temp1341=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1303)->f1;
goto _LL1340; _LL1340: _temp1339=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1303)->f2; goto _LL1338; _LL1338: _temp1337=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1303)->f3; goto _LL1310;} else{ goto
_LL1311;} _LL1311: if(( unsigned int) _temp1303 > 5u?(( struct _enum_struct*)
_temp1303)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1346: _temp1345=( void*)((
struct Cyc_Absyn_IntType_struct*) _temp1303)->f1; goto _LL1344; _LL1344:
_temp1343=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1303)->f2; goto
_LL1312;} else{ goto _LL1313;} _LL1313: if( _temp1303 == Cyc_Absyn_FloatType){
goto _LL1314;} else{ goto _LL1315;} _LL1315: if( _temp1303 == Cyc_Absyn_DoubleType){
goto _LL1316;} else{ goto _LL1317;} _LL1317: goto _LL1318; _LL1306: return Cyc_Tcutil_coerceable(
t2); _LL1308: { void* _temp1347= t2; struct Cyc_Absyn_PtrInfo _temp1353; struct
Cyc_Absyn_Conref* _temp1355; struct Cyc_Absyn_Tqual* _temp1357; struct Cyc_Absyn_Conref*
_temp1359; void* _temp1361; void* _temp1363; _LL1349: if(( unsigned int)
_temp1347 > 5u?(( struct _enum_struct*) _temp1347)->tag == Cyc_Absyn_PointerType_tag:
0){ _LL1354: _temp1353=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp1347)->f1; _LL1364: _temp1363=( void*) _temp1353.elt_typ; goto _LL1362;
_LL1362: _temp1361=( void*) _temp1353.rgn_typ; goto _LL1360; _LL1360: _temp1359=(
struct Cyc_Absyn_Conref*) _temp1353.nullable; goto _LL1358; _LL1358: _temp1357=(
struct Cyc_Absyn_Tqual*) _temp1353.tq; goto _LL1356; _LL1356: _temp1355=( struct
Cyc_Absyn_Conref*) _temp1353.bounds; goto _LL1350;} else{ goto _LL1351;} _LL1351:
goto _LL1352; _LL1350: { struct Cyc_List_List* assump=({ struct Cyc_List_List*
_temp1365=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1365->hd=( void*)({ struct _tuple7* _temp1366=( struct _tuple7*) GC_malloc(
sizeof( struct _tuple7)); _temp1366->f1= t1; _temp1366->f2= t2; _temp1366;});
_temp1365->tl= 0; _temp1365;}); int ptrsub= Cyc_Tcutil_ptrsubtype( te,( struct
Cyc_List_List*) assump, _temp1335, _temp1363)? ! _temp1329->q_const? 1:
_temp1357->q_const: 0; int bounds_ok=(( int(*)( int(* cmp)( void*, void*),
struct Cyc_Absyn_Conref* x, struct Cyc_Absyn_Conref* y)) Cyc_Tcutil_unify_conrefs)(
Cyc_Tcutil_boundscmp, _temp1327, _temp1355); if( ! bounds_ok){ struct _tuple7
_temp1368=({ struct _tuple7 _temp1367; _temp1367.f1=(( void*(*)( struct Cyc_Absyn_Conref*
x)) Cyc_Absyn_conref_val)( _temp1327); _temp1367.f2=(( void*(*)( struct Cyc_Absyn_Conref*
x)) Cyc_Absyn_conref_val)( _temp1355); _temp1367;}); void* _temp1374; struct Cyc_Absyn_Exp*
_temp1376; void* _temp1378; struct Cyc_Absyn_Exp* _temp1380; _LL1370: _LL1379:
_temp1378= _temp1368.f1; if(( unsigned int) _temp1378 > 1u?(( struct
_enum_struct*) _temp1378)->tag == Cyc_Absyn_Upper_b_tag: 0){ _LL1381: _temp1380=(
struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*) _temp1378)->f1; goto
_LL1375;} else{ goto _LL1372;} _LL1375: _temp1374= _temp1368.f2; if((
unsigned int) _temp1374 > 1u?(( struct _enum_struct*) _temp1374)->tag == Cyc_Absyn_Upper_b_tag:
0){ _LL1377: _temp1376=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*)
_temp1374)->f1; goto _LL1371;} else{ goto _LL1372;} _LL1372: goto _LL1373;
_LL1371: if( Cyc_Evexp_eval_const_uint_exp( _temp1380) >= Cyc_Evexp_eval_const_uint_exp(
_temp1376)){ bounds_ok= 1;} goto _LL1369; _LL1373: bounds_ok= 1; goto _LL1369;
_LL1369:;} return( bounds_ok? ptrsub: 0)? _temp1333 == Cyc_Absyn_HeapRgn? 1: Cyc_Tcutil_unify(
_temp1333, _temp1361): 0;} _LL1352: return 0; _LL1348:;} _LL1310: { void*
_temp1382= t2; struct Cyc_Absyn_Exp* _temp1388; struct Cyc_Absyn_Tqual*
_temp1390; void* _temp1392; _LL1384: if(( unsigned int) _temp1382 > 5u?(( struct
_enum_struct*) _temp1382)->tag == Cyc_Absyn_ArrayType_tag: 0){ _LL1393:
_temp1392=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1382)->f1; goto
_LL1391; _LL1391: _temp1390=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1382)->f2; goto _LL1389; _LL1389: _temp1388=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1382)->f3; goto _LL1385;} else{ goto
_LL1386;} _LL1386: goto _LL1387; _LL1385: { int okay; okay= Cyc_Evexp_eval_const_uint_exp(
_temp1337) >= Cyc_Evexp_eval_const_uint_exp( _temp1388); return( okay? Cyc_Tcutil_unify(
_temp1341, _temp1392): 0)? ! _temp1339->q_const? 1: _temp1390->q_const: 0;}
_LL1387: return 0; _LL1383:;} _LL1312: goto _LL1314; _LL1314: goto _LL1316;
_LL1316: return Cyc_Tcutil_coerceable( t2); _LL1318: return 0; _LL1304:;}} void
Cyc_Tcutil_unchecked_cast( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e,
void* t){ if( ! Cyc_Tcutil_unify(( void*)( e->topt)->v, t)){ struct Cyc_Absyn_Exp*
inner= Cyc_Absyn_copy_exp( e);( void*)( e->r=( void*)({ struct Cyc_Absyn_Cast_e_struct*
_temp1394=( struct Cyc_Absyn_Cast_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Cast_e_struct));
_temp1394->tag= Cyc_Absyn_Cast_e_tag; _temp1394->f1=( void*) t; _temp1394->f2=
inner;( void*) _temp1394;})); e->topt=({ struct Cyc_Core_Opt* _temp1395=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1395->v=( void*) t;
_temp1395;});}} int Cyc_Tcutil_comparison_promote( struct Cyc_Tcenv_Tenv* te,
struct Cyc_Absyn_Exp* e){ void* t;{ void* _temp1396= Cyc_Tcutil_compress(( void*)(
e->topt)->v); void* _temp1406; void* _temp1408; _LL1398: if(( unsigned int)
_temp1396 > 5u?(( struct _enum_struct*) _temp1396)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1409: _temp1408=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1396)->f1;
goto _LL1407; _LL1407: _temp1406=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1396)->f2; goto _LL1399;} else{ goto _LL1400;} _LL1400: if( _temp1396 ==
Cyc_Absyn_FloatType){ goto _LL1401;} else{ goto _LL1402;} _LL1402: if( _temp1396
== Cyc_Absyn_DoubleType){ goto _LL1403;} else{ goto _LL1404;} _LL1404: goto
_LL1405; _LL1399:{ void* _temp1410= _temp1406; _LL1412: if( _temp1410 == Cyc_Absyn_B1){
goto _LL1413;} else{ goto _LL1414;} _LL1414: if( _temp1410 == Cyc_Absyn_B2){
goto _LL1415;} else{ goto _LL1416;} _LL1416: if( _temp1410 == Cyc_Absyn_B4){
goto _LL1417;} else{ goto _LL1418;} _LL1418: if( _temp1410 == Cyc_Absyn_B8){
goto _LL1419;} else{ goto _LL1411;} _LL1413: t= Cyc_Absyn_sint_t; goto _LL1411;
_LL1415: t= Cyc_Absyn_sint_t; goto _LL1411; _LL1417: t= _temp1408 == Cyc_Absyn_Unsigned?
Cyc_Absyn_uint_t: Cyc_Absyn_sint_t; goto _LL1411; _LL1419: return 1; _LL1411:;}
goto _LL1397; _LL1401: t= Cyc_Absyn_float_t; goto _LL1397; _LL1403: return 1;
_LL1405: return 0; _LL1397:;} Cyc_Tcutil_unchecked_cast( te, e, t); return 1;}
int Cyc_Tcutil_arithmetic_promote( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp*
e){ void* old_typ= Cyc_Tcutil_compress(( void*)( e->topt)->v); void* t;{ void*
_temp1420= old_typ; void* _temp1434; void* _temp1436; struct Cyc_Absyn_Enumdecl**
_temp1438; struct Cyc_List_List* _temp1440; struct _tuple1* _temp1442; int
_temp1444; struct Cyc_Core_Opt* _temp1446; void* _temp1448; _LL1422: if((
unsigned int) _temp1420 > 5u?(( struct _enum_struct*) _temp1420)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1437: _temp1436=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1420)->f1;
goto _LL1435; _LL1435: _temp1434=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1420)->f2; goto _LL1423;} else{ goto _LL1424;} _LL1424: if( _temp1420 ==
Cyc_Absyn_FloatType){ goto _LL1425;} else{ goto _LL1426;} _LL1426: if( _temp1420
== Cyc_Absyn_DoubleType){ goto _LL1427;} else{ goto _LL1428;} _LL1428: if((
unsigned int) _temp1420 > 5u?(( struct _enum_struct*) _temp1420)->tag == Cyc_Absyn_EnumType_tag:
0){ _LL1443: _temp1442=( struct _tuple1*)(( struct Cyc_Absyn_EnumType_struct*)
_temp1420)->f1; goto _LL1441; _LL1441: _temp1440=( struct Cyc_List_List*)((
struct Cyc_Absyn_EnumType_struct*) _temp1420)->f2; goto _LL1439; _LL1439:
_temp1438=( struct Cyc_Absyn_Enumdecl**)(( struct Cyc_Absyn_EnumType_struct*)
_temp1420)->f3; goto _LL1429;} else{ goto _LL1430;} _LL1430: if(( unsigned int)
_temp1420 > 5u?(( struct _enum_struct*) _temp1420)->tag == Cyc_Absyn_Evar_tag: 0){
_LL1449: _temp1448=( void*)(( struct Cyc_Absyn_Evar_struct*) _temp1420)->f1;
goto _LL1447; _LL1447: _temp1446=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*)
_temp1420)->f2; goto _LL1445; _LL1445: _temp1444=( int)(( struct Cyc_Absyn_Evar_struct*)
_temp1420)->f3; goto _LL1431;} else{ goto _LL1432;} _LL1432: goto _LL1433;
_LL1423:{ void* _temp1450= _temp1434; _LL1452: if( _temp1450 == Cyc_Absyn_B1){
goto _LL1453;} else{ goto _LL1454;} _LL1454: if( _temp1450 == Cyc_Absyn_B2){
goto _LL1455;} else{ goto _LL1456;} _LL1456: if( _temp1450 == Cyc_Absyn_B4){
goto _LL1457;} else{ goto _LL1458;} _LL1458: if( _temp1450 == Cyc_Absyn_B8){
goto _LL1459;} else{ goto _LL1451;} _LL1453: t= Cyc_Absyn_sint_t; goto _LL1451;
_LL1455: t= Cyc_Absyn_sint_t; goto _LL1451; _LL1457: t= _temp1436 == Cyc_Absyn_Unsigned?
Cyc_Absyn_uint_t: Cyc_Absyn_sint_t; goto _LL1451; _LL1459: t= _temp1436 == Cyc_Absyn_Unsigned?
Cyc_Absyn_ulong_t: Cyc_Absyn_slong_t; goto _LL1451; _LL1451:;} goto _LL1421;
_LL1425: t= Cyc_Absyn_float_t; goto _LL1421; _LL1427: t= Cyc_Absyn_double_t;
goto _LL1421; _LL1429: t= Cyc_Absyn_sint_t; goto _LL1421; _LL1431: t= Cyc_Absyn_sint_t;
if( ! Cyc_Tcutil_unify( old_typ, t)){ return 0;} goto _LL1421; _LL1433: return 0;
_LL1421:;} Cyc_Tcutil_unchecked_cast( te, e, t); return 1;} int Cyc_Tcutil_integral_promote(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e){ void* old_typ= Cyc_Tcutil_compress((
void*)( e->topt)->v); void* t;{ void* _temp1460= old_typ; void* _temp1470; void*
_temp1472; struct Cyc_Absyn_Enumdecl** _temp1474; struct Cyc_List_List*
_temp1476; struct _tuple1* _temp1478; int _temp1480; struct Cyc_Core_Opt*
_temp1482; void* _temp1484; _LL1462: if(( unsigned int) _temp1460 > 5u?(( struct
_enum_struct*) _temp1460)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1473: _temp1472=(
void*)(( struct Cyc_Absyn_IntType_struct*) _temp1460)->f1; goto _LL1471; _LL1471:
_temp1470=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1460)->f2; goto
_LL1463;} else{ goto _LL1464;} _LL1464: if(( unsigned int) _temp1460 > 5u?((
struct _enum_struct*) _temp1460)->tag == Cyc_Absyn_EnumType_tag: 0){ _LL1479:
_temp1478=( struct _tuple1*)(( struct Cyc_Absyn_EnumType_struct*) _temp1460)->f1;
goto _LL1477; _LL1477: _temp1476=( struct Cyc_List_List*)(( struct Cyc_Absyn_EnumType_struct*)
_temp1460)->f2; goto _LL1475; _LL1475: _temp1474=( struct Cyc_Absyn_Enumdecl**)((
struct Cyc_Absyn_EnumType_struct*) _temp1460)->f3; goto _LL1465;} else{ goto
_LL1466;} _LL1466: if(( unsigned int) _temp1460 > 5u?(( struct _enum_struct*)
_temp1460)->tag == Cyc_Absyn_Evar_tag: 0){ _LL1485: _temp1484=( void*)(( struct
Cyc_Absyn_Evar_struct*) _temp1460)->f1; goto _LL1483; _LL1483: _temp1482=(
struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*) _temp1460)->f2; goto
_LL1481; _LL1481: _temp1480=( int)(( struct Cyc_Absyn_Evar_struct*) _temp1460)->f3;
goto _LL1467;} else{ goto _LL1468;} _LL1468: goto _LL1469; _LL1463:{ void*
_temp1486= _temp1470; _LL1488: if( _temp1486 == Cyc_Absyn_B1){ goto _LL1489;}
else{ goto _LL1490;} _LL1490: if( _temp1486 == Cyc_Absyn_B2){ goto _LL1491;}
else{ goto _LL1492;} _LL1492: if( _temp1486 == Cyc_Absyn_B4){ goto _LL1493;}
else{ goto _LL1494;} _LL1494: if( _temp1486 == Cyc_Absyn_B8){ goto _LL1495;}
else{ goto _LL1487;} _LL1489: t= Cyc_Absyn_sint_t; goto _LL1487; _LL1491: t= Cyc_Absyn_sint_t;
goto _LL1487; _LL1493: t= _temp1472 == Cyc_Absyn_Unsigned? Cyc_Absyn_uint_t: Cyc_Absyn_sint_t;
goto _LL1487; _LL1495: t= _temp1472 == Cyc_Absyn_Unsigned? Cyc_Absyn_ulong_t:
Cyc_Absyn_slong_t; goto _LL1487; _LL1487:;} goto _LL1461; _LL1465: t= Cyc_Absyn_sint_t;
goto _LL1461; _LL1467: t= Cyc_Absyn_sint_t; if( ! Cyc_Tcutil_unify( old_typ, t)){
return 0;} goto _LL1461; _LL1469: return 0; _LL1461:;} Cyc_Tcutil_unchecked_cast(
te, e, t); return 1;} void* Cyc_Tcutil_max_arithmetic_type( void* t1, void* t2){
struct _tuple7 _temp1497=({ struct _tuple7 _temp1496; _temp1496.f1= t1;
_temp1496.f2= t2; _temp1496;}); void* _temp1521; void* _temp1523; void*
_temp1525; void* _temp1527; void* _temp1529; void* _temp1531; void* _temp1533;
void* _temp1535; void* _temp1537; void* _temp1539; void* _temp1541; void*
_temp1543; void* _temp1545; void* _temp1547; void* _temp1549; void* _temp1551;
void* _temp1553; void* _temp1555; void* _temp1557; void* _temp1559; void*
_temp1561; void* _temp1563; void* _temp1565; void* _temp1567; void* _temp1569;
void* _temp1571; void* _temp1573; void* _temp1575; void* _temp1577; void*
_temp1579; void* _temp1581; void* _temp1583; _LL1499: _LL1524: _temp1523=
_temp1497.f1; if( _temp1523 == Cyc_Absyn_DoubleType){ goto _LL1522;} else{ goto
_LL1501;} _LL1522: _temp1521= _temp1497.f2; goto _LL1500; _LL1501: _LL1528:
_temp1527= _temp1497.f1; goto _LL1526; _LL1526: _temp1525= _temp1497.f2; if(
_temp1525 == Cyc_Absyn_DoubleType){ goto _LL1502;} else{ goto _LL1503;} _LL1503:
_LL1532: _temp1531= _temp1497.f1; if( _temp1531 == Cyc_Absyn_FloatType){ goto
_LL1530;} else{ goto _LL1505;} _LL1530: _temp1529= _temp1497.f2; goto _LL1504;
_LL1505: _LL1536: _temp1535= _temp1497.f1; goto _LL1534; _LL1534: _temp1533=
_temp1497.f2; if( _temp1533 == Cyc_Absyn_FloatType){ goto _LL1506;} else{ goto
_LL1507;} _LL1507: _LL1540: _temp1539= _temp1497.f1; if(( unsigned int)
_temp1539 > 5u?(( struct _enum_struct*) _temp1539)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1544: _temp1543=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1539)->f1;
if( _temp1543 == Cyc_Absyn_Unsigned){ goto _LL1542;} else{ goto _LL1509;}
_LL1542: _temp1541=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1539)->f2;
if( _temp1541 == Cyc_Absyn_B8){ goto _LL1538;} else{ goto _LL1509;}} else{ goto
_LL1509;} _LL1538: _temp1537= _temp1497.f2; goto _LL1508; _LL1509: _LL1552:
_temp1551= _temp1497.f1; goto _LL1546; _LL1546: _temp1545= _temp1497.f2; if((
unsigned int) _temp1545 > 5u?(( struct _enum_struct*) _temp1545)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1550: _temp1549=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1545)->f1;
if( _temp1549 == Cyc_Absyn_Unsigned){ goto _LL1548;} else{ goto _LL1511;}
_LL1548: _temp1547=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1545)->f2;
if( _temp1547 == Cyc_Absyn_B8){ goto _LL1510;} else{ goto _LL1511;}} else{ goto
_LL1511;} _LL1511: _LL1556: _temp1555= _temp1497.f1; if(( unsigned int)
_temp1555 > 5u?(( struct _enum_struct*) _temp1555)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1560: _temp1559=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1555)->f1;
if( _temp1559 == Cyc_Absyn_Signed){ goto _LL1558;} else{ goto _LL1513;} _LL1558:
_temp1557=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1555)->f2; if(
_temp1557 == Cyc_Absyn_B8){ goto _LL1554;} else{ goto _LL1513;}} else{ goto
_LL1513;} _LL1554: _temp1553= _temp1497.f2; goto _LL1512; _LL1513: _LL1568:
_temp1567= _temp1497.f1; goto _LL1562; _LL1562: _temp1561= _temp1497.f2; if((
unsigned int) _temp1561 > 5u?(( struct _enum_struct*) _temp1561)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1566: _temp1565=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1561)->f1;
if( _temp1565 == Cyc_Absyn_Signed){ goto _LL1564;} else{ goto _LL1515;} _LL1564:
_temp1563=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1561)->f2; if(
_temp1563 == Cyc_Absyn_B8){ goto _LL1514;} else{ goto _LL1515;}} else{ goto
_LL1515;} _LL1515: _LL1572: _temp1571= _temp1497.f1; if(( unsigned int)
_temp1571 > 5u?(( struct _enum_struct*) _temp1571)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1576: _temp1575=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1571)->f1;
if( _temp1575 == Cyc_Absyn_Unsigned){ goto _LL1574;} else{ goto _LL1517;}
_LL1574: _temp1573=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1571)->f2;
if( _temp1573 == Cyc_Absyn_B4){ goto _LL1570;} else{ goto _LL1517;}} else{ goto
_LL1517;} _LL1570: _temp1569= _temp1497.f2; goto _LL1516; _LL1517: _LL1584:
_temp1583= _temp1497.f1; goto _LL1578; _LL1578: _temp1577= _temp1497.f2; if((
unsigned int) _temp1577 > 5u?(( struct _enum_struct*) _temp1577)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1582: _temp1581=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1577)->f1;
if( _temp1581 == Cyc_Absyn_Unsigned){ goto _LL1580;} else{ goto _LL1519;}
_LL1580: _temp1579=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1577)->f2;
if( _temp1579 == Cyc_Absyn_B4){ goto _LL1518;} else{ goto _LL1519;}} else{ goto
_LL1519;} _LL1519: goto _LL1520; _LL1500: goto _LL1502; _LL1502: return Cyc_Absyn_DoubleType;
_LL1504: goto _LL1506; _LL1506: return Cyc_Absyn_FloatType; _LL1508: goto
_LL1510; _LL1510: return({ struct Cyc_Absyn_IntType_struct* _temp1585=( struct
Cyc_Absyn_IntType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_IntType_struct));
_temp1585->tag= Cyc_Absyn_IntType_tag; _temp1585->f1=( void*) Cyc_Absyn_Unsigned;
_temp1585->f2=( void*) Cyc_Absyn_B8;( void*) _temp1585;}); _LL1512: goto _LL1514;
_LL1514: return({ struct Cyc_Absyn_IntType_struct* _temp1586=( struct Cyc_Absyn_IntType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_IntType_struct)); _temp1586->tag= Cyc_Absyn_IntType_tag;
_temp1586->f1=( void*) Cyc_Absyn_Signed; _temp1586->f2=( void*) Cyc_Absyn_B8;(
void*) _temp1586;}); _LL1516: goto _LL1518; _LL1518: return({ struct Cyc_Absyn_IntType_struct*
_temp1587=( struct Cyc_Absyn_IntType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_IntType_struct));
_temp1587->tag= Cyc_Absyn_IntType_tag; _temp1587->f1=( void*) Cyc_Absyn_Unsigned;
_temp1587->f2=( void*) Cyc_Absyn_B4;( void*) _temp1587;}); _LL1520: return({
struct Cyc_Absyn_IntType_struct* _temp1588=( struct Cyc_Absyn_IntType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_IntType_struct)); _temp1588->tag= Cyc_Absyn_IntType_tag;
_temp1588->f1=( void*) Cyc_Absyn_Signed; _temp1588->f2=( void*) Cyc_Absyn_B4;(
void*) _temp1588;}); _LL1498:;} void Cyc_Tcutil_check_contains_assign( struct
Cyc_Absyn_Exp* e){ void* _temp1589=( void*) e->r; struct Cyc_Absyn_Exp*
_temp1595; struct Cyc_Core_Opt* _temp1597; struct Cyc_Absyn_Exp* _temp1599;
_LL1591: if((( struct _enum_struct*) _temp1589)->tag == Cyc_Absyn_AssignOp_e_tag){
_LL1600: _temp1599=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_AssignOp_e_struct*)
_temp1589)->f1; goto _LL1598; _LL1598: _temp1597=( struct Cyc_Core_Opt*)((
struct Cyc_Absyn_AssignOp_e_struct*) _temp1589)->f2; if( _temp1597 == 0){ goto
_LL1596;} else{ goto _LL1593;} _LL1596: _temp1595=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_AssignOp_e_struct*) _temp1589)->f3; goto _LL1592;} else{ goto
_LL1593;} _LL1593: goto _LL1594; _LL1592: Cyc_Tcutil_warn( e->loc,( struct
_tagged_string)({ char* _temp1601=( char*)"assignment in test"; struct
_tagged_string _temp1602; _temp1602.curr= _temp1601; _temp1602.base= _temp1601;
_temp1602.last_plus_one= _temp1601 + 19; _temp1602;})); goto _LL1590; _LL1594:
goto _LL1590; _LL1590:;} static int Cyc_Tcutil_constrain_kinds( struct Cyc_Absyn_Conref*
c1, struct Cyc_Absyn_Conref* c2){ c1=(( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref*
x)) Cyc_Absyn_compress_conref)( c1); c2=(( struct Cyc_Absyn_Conref*(*)( struct
Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)( c2); if( c1 == c2){ return 1;}
if(( void*) c1->v == Cyc_Absyn_No_constr){( void*)( c1->v=( void*)({ struct Cyc_Absyn_Forward_constr_struct*
_temp1603=( struct Cyc_Absyn_Forward_constr_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_Forward_constr_struct)); _temp1603->tag= Cyc_Absyn_Forward_constr_tag;
_temp1603->f1= c2;( void*) _temp1603;})); return 1;} else{ if(( void*) c2->v ==
Cyc_Absyn_No_constr){( void*)( c2->v=( void*)({ struct Cyc_Absyn_Forward_constr_struct*
_temp1604=( struct Cyc_Absyn_Forward_constr_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_Forward_constr_struct)); _temp1604->tag= Cyc_Absyn_Forward_constr_tag;
_temp1604->f1= c1;( void*) _temp1604;})); return 1;} else{ void* k1=(( void*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)( c1); void* k2=(( void*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)( c2); if( Cyc_Tcutil_kind_leq(
k1, k2)){( void*)( c2->v=( void*)({ struct Cyc_Absyn_Forward_constr_struct*
_temp1605=( struct Cyc_Absyn_Forward_constr_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_Forward_constr_struct)); _temp1605->tag= Cyc_Absyn_Forward_constr_tag;
_temp1605->f1= c1;( void*) _temp1605;})); return 1;} else{ if( Cyc_Tcutil_kind_leq(
k2, k1)){( void*)( c1->v=( void*)({ struct Cyc_Absyn_Forward_constr_struct*
_temp1606=( struct Cyc_Absyn_Forward_constr_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_Forward_constr_struct)); _temp1606->tag= Cyc_Absyn_Forward_constr_tag;
_temp1606->f1= c2;( void*) _temp1606;})); return 1;} else{ return 0;}}}}} static
struct Cyc_List_List* Cyc_Tcutil_add_free_tvar( struct Cyc_Position_Segment* loc,
struct Cyc_List_List* tvs, struct Cyc_Absyn_Tvar* tv){ if( tvs == 0){ return({
struct Cyc_List_List* _temp1607=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp1607->hd=( void*) tv; _temp1607->tl= 0; _temp1607;});}
else{{ struct Cyc_List_List* tvs2= tvs; for( 0; tvs2 != 0; tvs2= tvs2->tl){ if(
Cyc_String_zstrptrcmp((( struct Cyc_Absyn_Tvar*) tvs2->hd)->name, tv->name) == 0){
struct Cyc_Absyn_Conref* k1=(( struct Cyc_Absyn_Tvar*) tvs2->hd)->kind; struct
Cyc_Absyn_Conref* k2= tv->kind; if( ! Cyc_Tcutil_constrain_kinds( k1, k2)){ Cyc_Tcutil_terr(
loc,({ struct _tagged_string _temp1608=* tv->name; struct _tagged_string
_temp1609= Cyc_Absynpp_ckind2string( k1); struct _tagged_string _temp1610= Cyc_Absynpp_ckind2string(
k2); xprintf("type variable %.*s is used with inconsistent kinds %.*s and %.*s",
_temp1608.last_plus_one - _temp1608.curr, _temp1608.curr, _temp1609.last_plus_one
- _temp1609.curr, _temp1609.curr, _temp1610.last_plus_one - _temp1610.curr,
_temp1610.curr);}));} return tvs;} else{ if( tvs2->tl == 0){ tvs2->tl=({ struct
Cyc_List_List* _temp1611=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1611->hd=( void*) tv; _temp1611->tl= 0; _temp1611;}); return tvs;}}}}
return(( struct Cyc_List_List*(*)( struct _tagged_string msg)) Cyc_Tcutil_impos)((
struct _tagged_string)({ char* _temp1612=( char*)"Tcutil::add_free_tvar:expecting to have returned.";
struct _tagged_string _temp1613; _temp1613.curr= _temp1612; _temp1613.base=
_temp1612; _temp1613.last_plus_one= _temp1612 + 50; _temp1613;}));}} static
struct Cyc_List_List* Cyc_Tcutil_remove_bound_tvars( struct Cyc_List_List* tvs,
struct Cyc_List_List* btvs){ struct Cyc_List_List* r= 0; for( 0; tvs != 0; tvs=
tvs->tl){ int present= 0;{ struct Cyc_List_List* b= btvs; for( 0; b != 0; b= b->tl){
if( Cyc_String_zstrptrcmp((( struct Cyc_Absyn_Tvar*) tvs->hd)->name,(( struct
Cyc_Absyn_Tvar*) b->hd)->name) == 0){ present= 1; break;}}} if( ! present){ r=({
struct Cyc_List_List* _temp1614=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp1614->hd=( void*)(( struct Cyc_Absyn_Tvar*) tvs->hd);
_temp1614->tl= r; _temp1614;});}} r=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x)) Cyc_List_imp_rev)( r); return r;} static int Cyc_Tcutil_tvar_counter= 0;
struct Cyc_Absyn_Tvar* Cyc_Tcutil_new_tvar( void* k){ struct _tagged_string s=
xprintf("#%d",( Cyc_Tcutil_tvar_counter ++)); return({ struct Cyc_Absyn_Tvar*
_temp1615=( struct Cyc_Absyn_Tvar*) GC_malloc( sizeof( struct Cyc_Absyn_Tvar));
_temp1615->name=({ struct _tagged_string* _temp1616=( struct _tagged_string*)
GC_malloc( sizeof( struct _tagged_string) * 1); _temp1616[ 0]= s; _temp1616;});
_temp1615->kind=(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(
k); _temp1615;});} static struct _tuple2* Cyc_Tcutil_fndecl2typ_f( struct
_tuple10* x){ return({ struct _tuple2* _temp1617=( struct _tuple2*) GC_malloc(
sizeof( struct _tuple2)); _temp1617->f1=( struct Cyc_Core_Opt*)({ struct Cyc_Core_Opt*
_temp1618=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp1618->v=( void*)(* x).f1; _temp1618;}); _temp1617->f2=(* x).f2; _temp1617->f3=(*
x).f3; _temp1617;});} int Cyc_Tcutil_fntype_att( void* a){ void* _temp1619= a;
int _temp1633; _LL1621: if(( unsigned int) _temp1619 > 15u?(( struct
_enum_struct*) _temp1619)->tag == Cyc_Absyn_Regparm_att_tag: 0){ _LL1634:
_temp1633=( int)(( struct Cyc_Absyn_Regparm_att_struct*) _temp1619)->f1; goto
_LL1622;} else{ goto _LL1623;} _LL1623: if( _temp1619 == Cyc_Absyn_Stdcall_att){
goto _LL1624;} else{ goto _LL1625;} _LL1625: if( _temp1619 == Cyc_Absyn_Cdecl_att){
goto _LL1626;} else{ goto _LL1627;} _LL1627: if( _temp1619 == Cyc_Absyn_Noreturn_att){
goto _LL1628;} else{ goto _LL1629;} _LL1629: if( _temp1619 == Cyc_Absyn_Const_att){
goto _LL1630;} else{ goto _LL1631;} _LL1631: goto _LL1632; _LL1622: goto _LL1624;
_LL1624: goto _LL1626; _LL1626: goto _LL1628; _LL1628: goto _LL1630; _LL1630:
return 1; _LL1632: return 0; _LL1620:;} void* Cyc_Tcutil_fndecl2typ( struct Cyc_Absyn_Fndecl*
fd){ if( fd->cached_typ == 0){ struct Cyc_List_List* fn_type_atts= 0; struct Cyc_List_List*
fd_atts= 0;{ struct Cyc_List_List* atts= fd->attributes; for( 0; atts != 0; atts=
atts->tl){ if( Cyc_Tcutil_fntype_att(( void*) atts->hd)){ fn_type_atts=({ struct
Cyc_List_List* _temp1635=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1635->hd=( void*)(( void*) atts->hd); _temp1635->tl= fn_type_atts;
_temp1635;});} else{ fd_atts=({ struct Cyc_List_List* _temp1636=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp1636->hd=( void*)(( void*) atts->hd);
_temp1636->tl= fd_atts; _temp1636;});}}} fd->attributes= fd_atts; return({
struct Cyc_Absyn_FnType_struct* _temp1637=( struct Cyc_Absyn_FnType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_FnType_struct)); _temp1637->tag= Cyc_Absyn_FnType_tag;
_temp1637->f1=({ struct Cyc_Absyn_FnInfo _temp1638; _temp1638.tvars= fd->tvs;
_temp1638.effect= fd->effect; _temp1638.ret_typ=( void*)(( void*) fd->ret_type);
_temp1638.args=(( struct Cyc_List_List*(*)( struct _tuple2*(* f)( struct
_tuple10*), struct Cyc_List_List* x)) Cyc_List_map)( Cyc_Tcutil_fndecl2typ_f, fd->args);
_temp1638.varargs= fd->varargs; _temp1638.attributes= fn_type_atts; _temp1638;});(
void*) _temp1637;});} return( void*)( fd->cached_typ)->v;} static void* Cyc_Tcutil_fst3(
struct _tuple11* t){ return(* t).f1;} void Cyc_Tcutil_check_fndecl_valid_type(
struct Cyc_Position_Segment* loc, struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Fndecl*
fd){ void* t= Cyc_Tcutil_fndecl2typ( fd); Cyc_Tcutil_check_valid_toplevel_type(
loc, te, t);{ void* _temp1639= Cyc_Tcutil_compress( t); struct Cyc_Absyn_FnInfo
_temp1645; struct Cyc_List_List* _temp1647; int _temp1649; struct Cyc_List_List*
_temp1651; void* _temp1653; struct Cyc_Core_Opt* _temp1655; struct Cyc_List_List*
_temp1657; _LL1641: if(( unsigned int) _temp1639 > 5u?(( struct _enum_struct*)
_temp1639)->tag == Cyc_Absyn_FnType_tag: 0){ _LL1646: _temp1645=( struct Cyc_Absyn_FnInfo)((
struct Cyc_Absyn_FnType_struct*) _temp1639)->f1; _LL1658: _temp1657=( struct Cyc_List_List*)
_temp1645.tvars; goto _LL1656; _LL1656: _temp1655=( struct Cyc_Core_Opt*)
_temp1645.effect; goto _LL1654; _LL1654: _temp1653=( void*) _temp1645.ret_typ;
goto _LL1652; _LL1652: _temp1651=( struct Cyc_List_List*) _temp1645.args; goto
_LL1650; _LL1650: _temp1649=( int) _temp1645.varargs; goto _LL1648; _LL1648:
_temp1647=( struct Cyc_List_List*) _temp1645.attributes; goto _LL1642;} else{
goto _LL1643;} _LL1643: goto _LL1644; _LL1642: fd->tvs= _temp1657; fd->effect=
_temp1655; goto _LL1640; _LL1644:(( void(*)( struct _tagged_string msg)) Cyc_Tcutil_impos)((
struct _tagged_string)({ char* _temp1659=( char*)"check_fndecl_valid_type: not a FnType";
struct _tagged_string _temp1660; _temp1660.curr= _temp1659; _temp1660.base=
_temp1659; _temp1660.last_plus_one= _temp1659 + 38; _temp1660;})); return;
_LL1640:;} Cyc_Tcutil_check_unique_vars((( struct Cyc_List_List*(*)( struct
_tagged_string*(* f)( struct _tuple10*), struct Cyc_List_List* x)) Cyc_List_map)((
struct _tagged_string*(*)( struct _tuple10* t)) Cyc_Tcutil_fst3, fd->args), loc,(
struct _tagged_string)({ char* _temp1661=( char*)"function declaration has repeated parameter";
struct _tagged_string _temp1662; _temp1662.curr= _temp1661; _temp1662.base=
_temp1661; _temp1662.last_plus_one= _temp1661 + 44; _temp1662;})); fd->cached_typ=({
struct Cyc_Core_Opt* _temp1663=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp1663->v=( void*) t; _temp1663;});} static struct _tuple13*
Cyc_Tcutil_substitute_f1( struct _tuple2* y){ return({ struct _tuple13*
_temp1664=( struct _tuple13*) GC_malloc( sizeof( struct _tuple13)); _temp1664->f1=({
struct _tuple12* _temp1665=( struct _tuple12*) GC_malloc( sizeof( struct
_tuple12)); _temp1665->f1=(* y).f1; _temp1665->f2=(* y).f2; _temp1665;});
_temp1664->f2=(* y).f3; _temp1664;});} static struct _tuple2* Cyc_Tcutil_substitute_f2(
struct _tuple13* w){ void* _temp1668; struct _tuple12* _temp1670; struct
_tuple13 _temp1666=* w; _LL1671: _temp1670= _temp1666.f1; goto _LL1669; _LL1669:
_temp1668= _temp1666.f2; goto _LL1667; _LL1667: { struct Cyc_Absyn_Tqual*
_temp1674; struct Cyc_Core_Opt* _temp1676; struct _tuple12 _temp1672=* _temp1670;
_LL1677: _temp1676= _temp1672.f1; goto _LL1675; _LL1675: _temp1674= _temp1672.f2;
goto _LL1673; _LL1673: return({ struct _tuple2* _temp1678=( struct _tuple2*)
GC_malloc( sizeof( struct _tuple2)); _temp1678->f1= _temp1676; _temp1678->f2=
_temp1674; _temp1678->f3= _temp1668; _temp1678;});}} static struct Cyc_List_List*
Cyc_Tcutil_substs( struct Cyc_List_List* inst, struct Cyc_List_List* ts); void*
Cyc_Tcutil_substitute( struct Cyc_List_List* inst, void* t){ void* _temp1679=
Cyc_Tcutil_compress( t); struct Cyc_Absyn_Tvar* _temp1719; struct Cyc_Absyn_Structdecl**
_temp1721; struct Cyc_List_List* _temp1723; struct _tuple1* _temp1725; struct
Cyc_Absyn_Enumdecl** _temp1727; struct Cyc_List_List* _temp1729; struct _tuple1*
_temp1731; struct Cyc_Core_Opt* _temp1733; struct Cyc_List_List* _temp1735;
struct _tuple1* _temp1737; struct Cyc_Absyn_Exp* _temp1739; struct Cyc_Absyn_Tqual*
_temp1741; void* _temp1743; struct Cyc_Absyn_PtrInfo _temp1745; struct Cyc_Absyn_Conref*
_temp1747; struct Cyc_Absyn_Tqual* _temp1749; struct Cyc_Absyn_Conref* _temp1751;
void* _temp1753; void* _temp1755; struct Cyc_Absyn_FnInfo _temp1757; struct Cyc_List_List*
_temp1759; int _temp1761; struct Cyc_List_List* _temp1763; void* _temp1765;
struct Cyc_Core_Opt* _temp1767; struct Cyc_List_List* _temp1769; struct Cyc_List_List*
_temp1771; int _temp1773; struct Cyc_Core_Opt* _temp1775; void* _temp1777; void*
_temp1779; struct Cyc_Absyn_Xenumdecl** _temp1781; struct _tuple1* _temp1783;
void* _temp1785; void* _temp1787; void* _temp1789; struct Cyc_List_List*
_temp1791; _LL1681: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*)
_temp1679)->tag == Cyc_Absyn_VarType_tag: 0){ _LL1720: _temp1719=( struct Cyc_Absyn_Tvar*)((
struct Cyc_Absyn_VarType_struct*) _temp1679)->f1; goto _LL1682;} else{ goto
_LL1683;} _LL1683: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*)
_temp1679)->tag == Cyc_Absyn_StructType_tag: 0){ _LL1726: _temp1725=( struct
_tuple1*)(( struct Cyc_Absyn_StructType_struct*) _temp1679)->f1; goto _LL1724;
_LL1724: _temp1723=( struct Cyc_List_List*)(( struct Cyc_Absyn_StructType_struct*)
_temp1679)->f2; goto _LL1722; _LL1722: _temp1721=( struct Cyc_Absyn_Structdecl**)((
struct Cyc_Absyn_StructType_struct*) _temp1679)->f3; goto _LL1684;} else{ goto
_LL1685;} _LL1685: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*)
_temp1679)->tag == Cyc_Absyn_EnumType_tag: 0){ _LL1732: _temp1731=( struct
_tuple1*)(( struct Cyc_Absyn_EnumType_struct*) _temp1679)->f1; goto _LL1730;
_LL1730: _temp1729=( struct Cyc_List_List*)(( struct Cyc_Absyn_EnumType_struct*)
_temp1679)->f2; goto _LL1728; _LL1728: _temp1727=( struct Cyc_Absyn_Enumdecl**)((
struct Cyc_Absyn_EnumType_struct*) _temp1679)->f3; goto _LL1686;} else{ goto
_LL1687;} _LL1687: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*)
_temp1679)->tag == Cyc_Absyn_TypedefType_tag: 0){ _LL1738: _temp1737=( struct
_tuple1*)(( struct Cyc_Absyn_TypedefType_struct*) _temp1679)->f1; goto _LL1736;
_LL1736: _temp1735=( struct Cyc_List_List*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp1679)->f2; goto _LL1734; _LL1734: _temp1733=( struct Cyc_Core_Opt*)((
struct Cyc_Absyn_TypedefType_struct*) _temp1679)->f3; goto _LL1688;} else{ goto
_LL1689;} _LL1689: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*)
_temp1679)->tag == Cyc_Absyn_ArrayType_tag: 0){ _LL1744: _temp1743=( void*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1679)->f1; goto _LL1742; _LL1742:
_temp1741=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1679)->f2; goto _LL1740; _LL1740: _temp1739=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1679)->f3; goto _LL1690;} else{ goto
_LL1691;} _LL1691: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*)
_temp1679)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL1746: _temp1745=( struct
Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*) _temp1679)->f1;
_LL1756: _temp1755=( void*) _temp1745.elt_typ; goto _LL1754; _LL1754: _temp1753=(
void*) _temp1745.rgn_typ; goto _LL1752; _LL1752: _temp1751=( struct Cyc_Absyn_Conref*)
_temp1745.nullable; goto _LL1750; _LL1750: _temp1749=( struct Cyc_Absyn_Tqual*)
_temp1745.tq; goto _LL1748; _LL1748: _temp1747=( struct Cyc_Absyn_Conref*)
_temp1745.bounds; goto _LL1692;} else{ goto _LL1693;} _LL1693: if(( unsigned int)
_temp1679 > 5u?(( struct _enum_struct*) _temp1679)->tag == Cyc_Absyn_FnType_tag:
0){ _LL1758: _temp1757=( struct Cyc_Absyn_FnInfo)(( struct Cyc_Absyn_FnType_struct*)
_temp1679)->f1; _LL1770: _temp1769=( struct Cyc_List_List*) _temp1757.tvars;
goto _LL1768; _LL1768: _temp1767=( struct Cyc_Core_Opt*) _temp1757.effect; goto
_LL1766; _LL1766: _temp1765=( void*) _temp1757.ret_typ; goto _LL1764; _LL1764:
_temp1763=( struct Cyc_List_List*) _temp1757.args; goto _LL1762; _LL1762:
_temp1761=( int) _temp1757.varargs; goto _LL1760; _LL1760: _temp1759=( struct
Cyc_List_List*) _temp1757.attributes; goto _LL1694;} else{ goto _LL1695;}
_LL1695: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*) _temp1679)->tag
== Cyc_Absyn_TupleType_tag: 0){ _LL1772: _temp1771=( struct Cyc_List_List*)((
struct Cyc_Absyn_TupleType_struct*) _temp1679)->f1; goto _LL1696;} else{ goto
_LL1697;} _LL1697: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*)
_temp1679)->tag == Cyc_Absyn_Evar_tag: 0){ _LL1778: _temp1777=( void*)(( struct
Cyc_Absyn_Evar_struct*) _temp1679)->f1; goto _LL1776; _LL1776: _temp1775=(
struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Evar_struct*) _temp1679)->f2; goto
_LL1774; _LL1774: _temp1773=( int)(( struct Cyc_Absyn_Evar_struct*) _temp1679)->f3;
goto _LL1698;} else{ goto _LL1699;} _LL1699: if(( unsigned int) _temp1679 > 5u?((
struct _enum_struct*) _temp1679)->tag == Cyc_Absyn_RgnHandleType_tag: 0){
_LL1780: _temp1779=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*) _temp1679)->f1;
goto _LL1700;} else{ goto _LL1701;} _LL1701: if( _temp1679 == Cyc_Absyn_VoidType){
goto _LL1702;} else{ goto _LL1703;} _LL1703: if(( unsigned int) _temp1679 > 5u?((
struct _enum_struct*) _temp1679)->tag == Cyc_Absyn_XenumType_tag: 0){ _LL1784:
_temp1783=( struct _tuple1*)(( struct Cyc_Absyn_XenumType_struct*) _temp1679)->f1;
goto _LL1782; _LL1782: _temp1781=( struct Cyc_Absyn_Xenumdecl**)(( struct Cyc_Absyn_XenumType_struct*)
_temp1679)->f2; goto _LL1704;} else{ goto _LL1705;} _LL1705: if(( unsigned int)
_temp1679 > 5u?(( struct _enum_struct*) _temp1679)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1788: _temp1787=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1679)->f1;
goto _LL1786; _LL1786: _temp1785=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1679)->f2; goto _LL1706;} else{ goto _LL1707;} _LL1707: if( _temp1679 ==
Cyc_Absyn_FloatType){ goto _LL1708;} else{ goto _LL1709;} _LL1709: if( _temp1679
== Cyc_Absyn_DoubleType){ goto _LL1710;} else{ goto _LL1711;} _LL1711: if(
_temp1679 == Cyc_Absyn_HeapRgn){ goto _LL1712;} else{ goto _LL1713;} _LL1713:
if( _temp1679 == Cyc_Absyn_UnionType){ goto _LL1714;} else{ goto _LL1715;}
_LL1715: if(( unsigned int) _temp1679 > 5u?(( struct _enum_struct*) _temp1679)->tag
== Cyc_Absyn_AccessEff_tag: 0){ _LL1790: _temp1789=( void*)(( struct Cyc_Absyn_AccessEff_struct*)
_temp1679)->f1; goto _LL1716;} else{ goto _LL1717;} _LL1717: if(( unsigned int)
_temp1679 > 5u?(( struct _enum_struct*) _temp1679)->tag == Cyc_Absyn_JoinEff_tag:
0){ _LL1792: _temp1791=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*)
_temp1679)->f1; goto _LL1718;} else{ goto _LL1680;} _LL1682: { struct
_handler_cons _temp1793; _push_handler(& _temp1793);{ struct _xenum_struct*
_temp1794=( struct _xenum_struct*) setjmp( _temp1793.handler); if( ! _temp1794){{
void* _temp1795=(( void*(*)( int(* compare)( struct Cyc_Absyn_Tvar*, struct Cyc_Absyn_Tvar*),
struct Cyc_List_List* l, struct Cyc_Absyn_Tvar* x)) Cyc_List_assoc_cmp)( Cyc_Absyn_tvar_cmp,
inst, _temp1719); _npop_handler( 0u); return _temp1795;}; _pop_handler();} else{
struct _xenum_struct* _temp1797= _temp1794; _LL1799: if( _temp1797->tag == Cyc_Core_Not_found_tag){
goto _LL1800;} else{ goto _LL1801;} _LL1801: goto _LL1802; _LL1800: return t;
_LL1802:( void) _throw( _temp1797); _LL1798:;}}} _LL1684: { struct Cyc_List_List*
new_ts= Cyc_Tcutil_substs( inst, _temp1723); return new_ts == _temp1723? t:({
struct Cyc_Absyn_StructType_struct* _temp1803=( struct Cyc_Absyn_StructType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_StructType_struct)); _temp1803->tag= Cyc_Absyn_StructType_tag;
_temp1803->f1= _temp1725; _temp1803->f2= new_ts; _temp1803->f3= _temp1721;( void*)
_temp1803;});} _LL1686: { struct Cyc_List_List* new_ts= Cyc_Tcutil_substs( inst,
_temp1729); return new_ts == _temp1729? t:({ struct Cyc_Absyn_EnumType_struct*
_temp1804=( struct Cyc_Absyn_EnumType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_EnumType_struct));
_temp1804->tag= Cyc_Absyn_EnumType_tag; _temp1804->f1= _temp1731; _temp1804->f2=
new_ts; _temp1804->f3= _temp1727;( void*) _temp1804;});} _LL1688: { struct Cyc_List_List*
new_ts= Cyc_Tcutil_substs( inst, _temp1735); return new_ts == _temp1735? t:({
struct Cyc_Absyn_TypedefType_struct* _temp1805=( struct Cyc_Absyn_TypedefType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TypedefType_struct)); _temp1805->tag= Cyc_Absyn_TypedefType_tag;
_temp1805->f1= _temp1737; _temp1805->f2= new_ts; _temp1805->f3= _temp1733;( void*)
_temp1805;});} _LL1690: { void* new_t1= Cyc_Tcutil_substitute( inst, _temp1743);
return new_t1 == _temp1743? t:({ struct Cyc_Absyn_ArrayType_struct* _temp1806=(
struct Cyc_Absyn_ArrayType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_ArrayType_struct));
_temp1806->tag= Cyc_Absyn_ArrayType_tag; _temp1806->f1=( void*) new_t1;
_temp1806->f2= _temp1741; _temp1806->f3= _temp1739;( void*) _temp1806;});}
_LL1692: { void* new_t1= Cyc_Tcutil_substitute( inst, _temp1755); void* new_r=
Cyc_Tcutil_substitute( inst, _temp1753); if( new_t1 == _temp1755? new_r ==
_temp1753: 0){ return t;} return({ struct Cyc_Absyn_PointerType_struct*
_temp1807=( struct Cyc_Absyn_PointerType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct));
_temp1807->tag= Cyc_Absyn_PointerType_tag; _temp1807->f1=({ struct Cyc_Absyn_PtrInfo
_temp1808; _temp1808.elt_typ=( void*) new_t1; _temp1808.rgn_typ=( void*) new_r;
_temp1808.nullable= _temp1751; _temp1808.tq= _temp1749; _temp1808.bounds=
_temp1747; _temp1808;});( void*) _temp1807;});} _LL1694:{ struct Cyc_List_List*
p= _temp1769; for( 0; p != 0; p= p->tl){ inst=({ struct Cyc_List_List* _temp1809=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp1809->hd=(
void*)({ struct _tuple5* _temp1810=( struct _tuple5*) GC_malloc( sizeof( struct
_tuple5)); _temp1810->f1=( struct Cyc_Absyn_Tvar*) p->hd; _temp1810->f2=({
struct Cyc_Absyn_VarType_struct* _temp1811=( struct Cyc_Absyn_VarType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct)); _temp1811->tag= Cyc_Absyn_VarType_tag;
_temp1811->f1=( struct Cyc_Absyn_Tvar*) p->hd;( void*) _temp1811;}); _temp1810;});
_temp1809->tl= inst; _temp1809;});}}{ struct Cyc_List_List* _temp1814; struct
Cyc_List_List* _temp1816; struct _tuple0 _temp1812=(( struct _tuple0(*)( struct
Cyc_List_List* x)) Cyc_List_split)((( struct Cyc_List_List*(*)( struct _tuple13*(*
f)( struct _tuple2*), struct Cyc_List_List* x)) Cyc_List_map)( Cyc_Tcutil_substitute_f1,
_temp1763)); _LL1817: _temp1816= _temp1812.f1; goto _LL1815; _LL1815: _temp1814=
_temp1812.f2; goto _LL1813; _LL1813: { struct Cyc_List_List* ts2= Cyc_Tcutil_substs(
inst, _temp1814); struct Cyc_List_List* args2=(( struct Cyc_List_List*(*)(
struct _tuple2*(* f)( struct _tuple13*), struct Cyc_List_List* x)) Cyc_List_map)(
Cyc_Tcutil_substitute_f2,(( struct Cyc_List_List*(*)( struct Cyc_List_List* x,
struct Cyc_List_List* y)) Cyc_List_zip)( _temp1816, ts2)); struct Cyc_Core_Opt*
eff2; if( _temp1767 == 0){ eff2= 0;} else{ void* new_eff= Cyc_Tcutil_substitute(
inst,( void*) _temp1767->v); if( new_eff ==( void*) _temp1767->v){ eff2=
_temp1767;} else{ eff2=( struct Cyc_Core_Opt*)({ struct Cyc_Core_Opt* _temp1818=(
struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt) * 1); _temp1818[ 0]=({
struct Cyc_Core_Opt _temp1819; _temp1819.v=( void*) new_eff; _temp1819;});
_temp1818;});}} return({ struct Cyc_Absyn_FnType_struct* _temp1820=( struct Cyc_Absyn_FnType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_FnType_struct)); _temp1820->tag= Cyc_Absyn_FnType_tag;
_temp1820->f1=({ struct Cyc_Absyn_FnInfo _temp1821; _temp1821.tvars= _temp1769;
_temp1821.effect= eff2; _temp1821.ret_typ=( void*) Cyc_Tcutil_substitute( inst,
_temp1765); _temp1821.args= args2; _temp1821.varargs= _temp1761; _temp1821.attributes=
_temp1759; _temp1821;});( void*) _temp1820;});}} _LL1696: { struct Cyc_List_List*
_temp1824; struct Cyc_List_List* _temp1826; struct _tuple0 _temp1822=(( struct
_tuple0(*)( struct Cyc_List_List* x)) Cyc_List_split)( _temp1771); _LL1827:
_temp1826= _temp1822.f1; goto _LL1825; _LL1825: _temp1824= _temp1822.f2; goto
_LL1823; _LL1823: { struct Cyc_List_List* ts2= Cyc_Tcutil_substs( inst,
_temp1824); if( ts2 == _temp1824){ return t;}{ struct Cyc_List_List* tqts2=((
struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_zip)(
_temp1826, ts2); return({ struct Cyc_Absyn_TupleType_struct* _temp1828=( struct
Cyc_Absyn_TupleType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_TupleType_struct));
_temp1828->tag= Cyc_Absyn_TupleType_tag; _temp1828->f1= tqts2;( void*) _temp1828;});}}}
_LL1698: if( _temp1775 != 0){ return Cyc_Tcutil_substitute( inst,( void*)
_temp1775->v);} else{ return t;} _LL1700: { void* new_rt= Cyc_Tcutil_substitute(
inst, _temp1779); return new_rt == _temp1779? t:({ struct Cyc_Absyn_RgnHandleType_struct*
_temp1829=( struct Cyc_Absyn_RgnHandleType_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_RgnHandleType_struct)); _temp1829->tag= Cyc_Absyn_RgnHandleType_tag;
_temp1829->f1=( void*) new_rt;( void*) _temp1829;});} _LL1702: return t; _LL1704:
return t; _LL1706: return t; _LL1708: return t; _LL1710: return t; _LL1712:
return t; _LL1714: return t; _LL1716: { void* new_r= Cyc_Tcutil_substitute( inst,
_temp1789); return new_r == _temp1789? t:({ struct Cyc_Absyn_AccessEff_struct*
_temp1830=( struct Cyc_Absyn_AccessEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_AccessEff_struct));
_temp1830->tag= Cyc_Absyn_AccessEff_tag; _temp1830->f1=( void*) new_r;( void*)
_temp1830;});} _LL1718: { struct Cyc_List_List* new_es= Cyc_Tcutil_substs( inst,
_temp1791); return new_es == _temp1791? t:({ struct Cyc_Absyn_JoinEff_struct*
_temp1831=( struct Cyc_Absyn_JoinEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct));
_temp1831->tag= Cyc_Absyn_JoinEff_tag; _temp1831->f1= new_es;( void*) _temp1831;});}
_LL1680:;} static struct Cyc_List_List* Cyc_Tcutil_substs( struct Cyc_List_List*
inst, struct Cyc_List_List* ts){ if( ts == 0){ return 0;}{ void* old_hd=( void*)
ts->hd; struct Cyc_List_List* old_tl= ts->tl; void* new_hd= Cyc_Tcutil_substitute(
inst, old_hd); struct Cyc_List_List* new_tl= Cyc_Tcutil_substs( inst, old_tl);
if( old_hd == new_hd? old_tl == new_tl: 0){ return ts;} return( struct Cyc_List_List*)({
struct Cyc_List_List* _temp1832=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List) * 1); _temp1832[ 0]=({ struct Cyc_List_List _temp1833;
_temp1833.hd=( void*) new_hd; _temp1833.tl= new_tl; _temp1833;}); _temp1832;});}}
struct Cyc_Absyn_Exp* Cyc_Tcutil_default_initializer( struct Cyc_Tcenv_Tenv* te,
void* t, struct Cyc_Position_Segment* loc){ struct Cyc_Absyn_Exp* e= Cyc_Absyn_new_exp(({
struct Cyc_Absyn_Const_e_struct* _temp1834=( struct Cyc_Absyn_Const_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct)); _temp1834->tag= Cyc_Absyn_Const_e_tag;
_temp1834->f1=( void*) Cyc_Absyn_Null_c;( void*) _temp1834;}), loc);{ void*
_temp1835= Cyc_Tcutil_compress( t); struct Cyc_Absyn_PtrInfo _temp1849; void*
_temp1851; void* _temp1853; void* _temp1855; void* _temp1857; _LL1837: if((
unsigned int) _temp1835 > 5u?(( struct _enum_struct*) _temp1835)->tag == Cyc_Absyn_PointerType_tag:
0){ _LL1850: _temp1849=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp1835)->f1; goto _LL1838;} else{ goto _LL1839;} _LL1839: if(( unsigned int)
_temp1835 > 5u?(( struct _enum_struct*) _temp1835)->tag == Cyc_Absyn_IntType_tag:
0){ _LL1854: _temp1853=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1835)->f1;
goto _LL1852; _LL1852: _temp1851=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1835)->f2; if( _temp1851 == Cyc_Absyn_B1){ goto _LL1840;} else{ goto
_LL1841;}} else{ goto _LL1841;} _LL1841: if(( unsigned int) _temp1835 > 5u?((
struct _enum_struct*) _temp1835)->tag == Cyc_Absyn_IntType_tag: 0){ _LL1858:
_temp1857=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp1835)->f1; goto
_LL1856; _LL1856: _temp1855=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1835)->f2; goto _LL1842;} else{ goto _LL1843;} _LL1843: if( _temp1835 ==
Cyc_Absyn_FloatType){ goto _LL1844;} else{ goto _LL1845;} _LL1845: if( _temp1835
== Cyc_Absyn_DoubleType){ goto _LL1846;} else{ goto _LL1847;} _LL1847: goto
_LL1848; _LL1838: goto _LL1836; _LL1840:( void*)( e->r=( void*)({ struct Cyc_Absyn_Const_e_struct*
_temp1859=( struct Cyc_Absyn_Const_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct));
_temp1859->tag= Cyc_Absyn_Const_e_tag; _temp1859->f1=( void*)({ struct Cyc_Absyn_Char_c_struct*
_temp1860=( struct Cyc_Absyn_Char_c_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Char_c_struct));
_temp1860->tag= Cyc_Absyn_Char_c_tag; _temp1860->f1=( void*) Cyc_Absyn_Signed;
_temp1860->f2='\000';( void*) _temp1860;});( void*) _temp1859;})); goto _LL1836;
_LL1842:( void*)( e->r=( void*)({ struct Cyc_Absyn_Const_e_struct* _temp1861=(
struct Cyc_Absyn_Const_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct));
_temp1861->tag= Cyc_Absyn_Const_e_tag; _temp1861->f1=( void*)({ struct Cyc_Absyn_Int_c_struct*
_temp1862=( struct Cyc_Absyn_Int_c_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Int_c_struct));
_temp1862->tag= Cyc_Absyn_Int_c_tag; _temp1862->f1=( void*) _temp1857; _temp1862->f2=
0;( void*) _temp1862;});( void*) _temp1861;})); if( _temp1855 != Cyc_Absyn_B4){
e= Cyc_Absyn_new_exp(({ struct Cyc_Absyn_Cast_e_struct* _temp1863=( struct Cyc_Absyn_Cast_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Cast_e_struct)); _temp1863->tag= Cyc_Absyn_Cast_e_tag;
_temp1863->f1=( void*) t; _temp1863->f2= e;( void*) _temp1863;}), loc);} goto
_LL1836; _LL1844:( void*)( e->r=( void*)({ struct Cyc_Absyn_Const_e_struct*
_temp1864=( struct Cyc_Absyn_Const_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct));
_temp1864->tag= Cyc_Absyn_Const_e_tag; _temp1864->f1=( void*)({ struct Cyc_Absyn_Float_c_struct*
_temp1865=( struct Cyc_Absyn_Float_c_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Float_c_struct));
_temp1865->tag= Cyc_Absyn_Float_c_tag; _temp1865->f1=( struct _tagged_string)({
char* _temp1866=( char*)"0.0"; struct _tagged_string _temp1867; _temp1867.curr=
_temp1866; _temp1867.base= _temp1866; _temp1867.last_plus_one= _temp1866 + 4;
_temp1867;});( void*) _temp1865;});( void*) _temp1864;})); goto _LL1836; _LL1846:(
void*)( e->r=( void*)({ struct Cyc_Absyn_Cast_e_struct* _temp1868=( struct Cyc_Absyn_Cast_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Cast_e_struct)); _temp1868->tag= Cyc_Absyn_Cast_e_tag;
_temp1868->f1=( void*) t; _temp1868->f2= Cyc_Absyn_new_exp(({ struct Cyc_Absyn_Const_e_struct*
_temp1869=( struct Cyc_Absyn_Const_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct));
_temp1869->tag= Cyc_Absyn_Const_e_tag; _temp1869->f1=( void*)({ struct Cyc_Absyn_Float_c_struct*
_temp1870=( struct Cyc_Absyn_Float_c_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Float_c_struct));
_temp1870->tag= Cyc_Absyn_Float_c_tag; _temp1870->f1=( struct _tagged_string)({
char* _temp1871=( char*)"0.0"; struct _tagged_string _temp1872; _temp1872.curr=
_temp1871; _temp1872.base= _temp1871; _temp1872.last_plus_one= _temp1871 + 4;
_temp1872;});( void*) _temp1870;});( void*) _temp1869;}), loc);( void*)
_temp1868;})); goto _LL1836; _LL1848: Cyc_Tcutil_terr( loc,({ struct
_tagged_string _temp1873= Cyc_Absynpp_typ2string( t); xprintf("declaration of type %.*s requires initializer",
_temp1873.last_plus_one - _temp1873.curr, _temp1873.curr);})); goto _LL1836;
_LL1836:;} return e;} struct _tuple5* Cyc_Tcutil_make_inst_var( struct Cyc_Absyn_Tvar*
tv){ void* k=(( void*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)( tv->kind);
return({ struct _tuple5* _temp1874=( struct _tuple5*) GC_malloc( sizeof( struct
_tuple5)); _temp1874->f1= tv; _temp1874->f2= Cyc_Absyn_new_evar( k); _temp1874;});}
struct Cyc_List_List* Cyc_Tcutil_check_valid_type( struct Cyc_Position_Segment*
loc, struct Cyc_Tcenv_Tenv* te, struct Cyc_List_List* free_vars, void*
expected_kind, void* t){{ void* _temp1875= Cyc_Tcutil_compress( t); int
_temp1915; struct Cyc_Core_Opt* _temp1917; void* _temp1919; struct Cyc_Absyn_Tvar*
_temp1921; struct Cyc_Absyn_Enumdecl** _temp1923; struct Cyc_Absyn_Enumdecl***
_temp1925; struct Cyc_List_List* _temp1926; struct _tuple1* _temp1928; struct
Cyc_Absyn_Xenumdecl** _temp1930; struct Cyc_Absyn_Xenumdecl*** _temp1932; struct
_tuple1* _temp1933; struct Cyc_Absyn_PtrInfo _temp1935; struct Cyc_Absyn_Conref*
_temp1937; struct Cyc_Absyn_Tqual* _temp1939; struct Cyc_Absyn_Conref* _temp1941;
void* _temp1943; void* _temp1945; void* _temp1947; void* _temp1949; struct Cyc_Absyn_Exp*
_temp1951; struct Cyc_Absyn_Tqual* _temp1953; void* _temp1955; struct Cyc_Absyn_FnInfo
_temp1957; struct Cyc_List_List* _temp1959; int _temp1961; struct Cyc_List_List*
_temp1963; void* _temp1965; struct Cyc_Core_Opt* _temp1967; struct Cyc_Core_Opt**
_temp1969; struct Cyc_List_List* _temp1970; struct Cyc_List_List** _temp1972;
struct Cyc_List_List* _temp1973; struct Cyc_Absyn_Structdecl** _temp1975; struct
Cyc_Absyn_Structdecl*** _temp1977; struct Cyc_List_List* _temp1978; struct
_tuple1* _temp1980; struct Cyc_Core_Opt* _temp1982; struct Cyc_Core_Opt**
_temp1984; struct Cyc_List_List* _temp1985; struct _tuple1* _temp1987; void*
_temp1989; void* _temp1991; struct Cyc_List_List* _temp1993; _LL1877: if(
_temp1875 == Cyc_Absyn_VoidType){ goto _LL1878;} else{ goto _LL1879;} _LL1879:
if(( unsigned int) _temp1875 > 5u?(( struct _enum_struct*) _temp1875)->tag ==
Cyc_Absyn_Evar_tag: 0){ _LL1920: _temp1919=( void*)(( struct Cyc_Absyn_Evar_struct*)
_temp1875)->f1; goto _LL1918; _LL1918: _temp1917=( struct Cyc_Core_Opt*)((
struct Cyc_Absyn_Evar_struct*) _temp1875)->f2; goto _LL1916; _LL1916: _temp1915=(
int)(( struct Cyc_Absyn_Evar_struct*) _temp1875)->f3; goto _LL1880;} else{ goto
_LL1881;} _LL1881: if(( unsigned int) _temp1875 > 5u?(( struct _enum_struct*)
_temp1875)->tag == Cyc_Absyn_VarType_tag: 0){ _LL1922: _temp1921=( struct Cyc_Absyn_Tvar*)((
struct Cyc_Absyn_VarType_struct*) _temp1875)->f1; goto _LL1882;} else{ goto
_LL1883;} _LL1883: if(( unsigned int) _temp1875 > 5u?(( struct _enum_struct*)
_temp1875)->tag == Cyc_Absyn_EnumType_tag: 0){ _LL1929: _temp1928=( struct
_tuple1*)(( struct Cyc_Absyn_EnumType_struct*) _temp1875)->f1; goto _LL1927;
_LL1927: _temp1926=( struct Cyc_List_List*)(( struct Cyc_Absyn_EnumType_struct*)
_temp1875)->f2; goto _LL1924; _LL1924: _temp1923=( struct Cyc_Absyn_Enumdecl**)((
struct Cyc_Absyn_EnumType_struct*) _temp1875)->f3; _temp1925=&(( struct Cyc_Absyn_EnumType_struct*)
_temp1875)->f3; goto _LL1884;} else{ goto _LL1885;} _LL1885: if(( unsigned int)
_temp1875 > 5u?(( struct _enum_struct*) _temp1875)->tag == Cyc_Absyn_XenumType_tag:
0){ _LL1934: _temp1933=( struct _tuple1*)(( struct Cyc_Absyn_XenumType_struct*)
_temp1875)->f1; goto _LL1931; _LL1931: _temp1930=( struct Cyc_Absyn_Xenumdecl**)((
struct Cyc_Absyn_XenumType_struct*) _temp1875)->f2; _temp1932=&(( struct Cyc_Absyn_XenumType_struct*)
_temp1875)->f2; goto _LL1886;} else{ goto _LL1887;} _LL1887: if(( unsigned int)
_temp1875 > 5u?(( struct _enum_struct*) _temp1875)->tag == Cyc_Absyn_PointerType_tag:
0){ _LL1936: _temp1935=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp1875)->f1; _LL1946: _temp1945=( void*) _temp1935.elt_typ; goto _LL1944;
_LL1944: _temp1943=( void*) _temp1935.rgn_typ; goto _LL1942; _LL1942: _temp1941=(
struct Cyc_Absyn_Conref*) _temp1935.nullable; goto _LL1940; _LL1940: _temp1939=(
struct Cyc_Absyn_Tqual*) _temp1935.tq; goto _LL1938; _LL1938: _temp1937=( struct
Cyc_Absyn_Conref*) _temp1935.bounds; goto _LL1888;} else{ goto _LL1889;} _LL1889:
if(( unsigned int) _temp1875 > 5u?(( struct _enum_struct*) _temp1875)->tag ==
Cyc_Absyn_IntType_tag: 0){ _LL1950: _temp1949=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1875)->f1; goto _LL1948; _LL1948: _temp1947=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp1875)->f2; goto _LL1890;} else{ goto _LL1891;} _LL1891: if( _temp1875 ==
Cyc_Absyn_FloatType){ goto _LL1892;} else{ goto _LL1893;} _LL1893: if( _temp1875
== Cyc_Absyn_DoubleType){ goto _LL1894;} else{ goto _LL1895;} _LL1895: if((
unsigned int) _temp1875 > 5u?(( struct _enum_struct*) _temp1875)->tag == Cyc_Absyn_ArrayType_tag:
0){ _LL1956: _temp1955=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1875)->f1;
goto _LL1954; _LL1954: _temp1953=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1875)->f2; goto _LL1952; _LL1952: _temp1951=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1875)->f3; goto _LL1896;} else{ goto
_LL1897;} _LL1897: if(( unsigned int) _temp1875 > 5u?(( struct _enum_struct*)
_temp1875)->tag == Cyc_Absyn_FnType_tag: 0){ _LL1958: _temp1957=( struct Cyc_Absyn_FnInfo)((
struct Cyc_Absyn_FnType_struct*) _temp1875)->f1; _LL1971: _temp1970=( struct Cyc_List_List*)
_temp1957.tvars; _temp1972=&((( struct Cyc_Absyn_FnType_struct*) _temp1875)->f1).tvars;
goto _LL1968; _LL1968: _temp1967=( struct Cyc_Core_Opt*) _temp1957.effect;
_temp1969=&((( struct Cyc_Absyn_FnType_struct*) _temp1875)->f1).effect; goto
_LL1966; _LL1966: _temp1965=( void*) _temp1957.ret_typ; goto _LL1964; _LL1964:
_temp1963=( struct Cyc_List_List*) _temp1957.args; goto _LL1962; _LL1962:
_temp1961=( int) _temp1957.varargs; goto _LL1960; _LL1960: _temp1959=( struct
Cyc_List_List*) _temp1957.attributes; goto _LL1898;} else{ goto _LL1899;}
_LL1899: if(( unsigned int) _temp1875 > 5u?(( struct _enum_struct*) _temp1875)->tag
== Cyc_Absyn_TupleType_tag: 0){ _LL1974: _temp1973=( struct Cyc_List_List*)((
struct Cyc_Absyn_TupleType_struct*) _temp1875)->f1; goto _LL1900;} else{ goto
_LL1901;} _LL1901: if(( unsigned int) _temp1875 > 5u?(( struct _enum_struct*)
_temp1875)->tag == Cyc_Absyn_StructType_tag: 0){ _LL1981: _temp1980=( struct
_tuple1*)(( struct Cyc_Absyn_StructType_struct*) _temp1875)->f1; goto _LL1979;
_LL1979: _temp1978=( struct Cyc_List_List*)(( struct Cyc_Absyn_StructType_struct*)
_temp1875)->f2; goto _LL1976; _LL1976: _temp1975=( struct Cyc_Absyn_Structdecl**)((
struct Cyc_Absyn_StructType_struct*) _temp1875)->f3; _temp1977=&(( struct Cyc_Absyn_StructType_struct*)
_temp1875)->f3; goto _LL1902;} else{ goto _LL1903;} _LL1903: if(( unsigned int)
_temp1875 > 5u?(( struct _enum_struct*) _temp1875)->tag == Cyc_Absyn_TypedefType_tag:
0){ _LL1988: _temp1987=( struct _tuple1*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp1875)->f1; goto _LL1986; _LL1986: _temp1985=( struct Cyc_List_List*)((
struct Cyc_Absyn_TypedefType_struct*) _temp1875)->f2; goto _LL1983; _LL1983:
_temp1982=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_TypedefType_struct*)
_temp1875)->f3; _temp1984=&(( struct Cyc_Absyn_TypedefType_struct*) _temp1875)->f3;
goto _LL1904;} else{ goto _LL1905;} _LL1905: if( _temp1875 == Cyc_Absyn_UnionType){
goto _LL1906;} else{ goto _LL1907;} _LL1907: if( _temp1875 == Cyc_Absyn_HeapRgn){
goto _LL1908;} else{ goto _LL1909;} _LL1909: if(( unsigned int) _temp1875 > 5u?((
struct _enum_struct*) _temp1875)->tag == Cyc_Absyn_RgnHandleType_tag: 0){
_LL1990: _temp1989=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*) _temp1875)->f1;
goto _LL1910;} else{ goto _LL1911;} _LL1911: if(( unsigned int) _temp1875 > 5u?((
struct _enum_struct*) _temp1875)->tag == Cyc_Absyn_AccessEff_tag: 0){ _LL1992:
_temp1991=( void*)(( struct Cyc_Absyn_AccessEff_struct*) _temp1875)->f1; goto
_LL1912;} else{ goto _LL1913;} _LL1913: if(( unsigned int) _temp1875 > 5u?((
struct _enum_struct*) _temp1875)->tag == Cyc_Absyn_JoinEff_tag: 0){ _LL1994:
_temp1993=( struct Cyc_List_List*)(( struct Cyc_Absyn_JoinEff_struct*) _temp1875)->f1;
goto _LL1914;} else{ goto _LL1876;} _LL1878: goto _LL1876; _LL1880: goto _LL1876;
_LL1882: { struct Cyc_Absyn_Conref* c=(( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref*
x)) Cyc_Absyn_compress_conref)( _temp1921->kind); if(( void*) c->v == Cyc_Absyn_No_constr){(
void*)( c->v=( void*)({ struct Cyc_Absyn_Eq_constr_struct* _temp1995=( struct
Cyc_Absyn_Eq_constr_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct));
_temp1995->tag= Cyc_Absyn_Eq_constr_tag; _temp1995->f1=( void*) expected_kind;(
void*) _temp1995;}));} free_vars= Cyc_Tcutil_add_free_tvar( loc, free_vars,
_temp1921); goto _LL1876;} _LL1884: if( _temp1928 == 0){ Cyc_Tcutil_terr( loc,(
struct _tagged_string)({ char* _temp1996=( char*)"missing enum name"; struct
_tagged_string _temp1997; _temp1997.curr= _temp1996; _temp1997.base= _temp1996;
_temp1997.last_plus_one= _temp1996 + 18; _temp1997;})); return free_vars;} if(*
_temp1925 == 0){ struct _handler_cons _temp1998; _push_handler(& _temp1998);{
struct _xenum_struct* _temp1999=( struct _xenum_struct*) setjmp( _temp1998.handler);
if( ! _temp1999){* _temp1925=( struct Cyc_Absyn_Enumdecl**) Cyc_Tcenv_lookup_enumdecl(
te, loc,( struct _tuple1*)({ struct _tuple1* _temp2000= _temp1928; if( _temp2000
== 0){ _throw( Null_Exception);} _temp2000;}));; _pop_handler();} else{ struct
_xenum_struct* _temp2002= _temp1999; _LL2004: if( _temp2002->tag == Cyc_Dict_Absent_tag){
goto _LL2005;} else{ goto _LL2006;} _LL2006: goto _LL2007; _LL2005: Cyc_Tcutil_terr(
loc,({ struct _tagged_string _temp2009= Cyc_Absynpp_qvar2string(( struct _tuple1*)({
struct _tuple1* _temp2008= _temp1928; if( _temp2008 == 0){ _throw(
Null_Exception);} _temp2008;})); xprintf("unbound type enum %.*s", _temp2009.last_plus_one
- _temp2009.curr, _temp2009.curr);})); return free_vars; _LL2007:( void) _throw(
_temp2002); _LL2003:;}}}{ struct Cyc_Absyn_Enumdecl* ed=*(* _temp1925); if( ed->name
!= 0){* _temp1928=({ struct _tuple1* _temp2010=( struct _tuple1*)( ed->name)->v;
unsigned int _temp2011= 0; if( _temp2011 >= 1u){ _throw( Null_Exception);}
_temp2010[ _temp2011];});}{ struct Cyc_List_List* tvs= ed->tvs; int lvs=(( int(*)(
struct Cyc_List_List* x)) Cyc_List_length)( tvs); int largs=(( int(*)( struct
Cyc_List_List* x)) Cyc_List_length)( _temp1926); if( lvs != largs){ Cyc_Tcutil_terr(
loc,({ struct _tagged_string _temp2013= Cyc_Absynpp_qvar2string(( struct _tuple1*)({
struct _tuple1* _temp2012= _temp1928; if( _temp2012 == 0){ _throw(
Null_Exception);} _temp2012;})); int _temp2014= lvs; int _temp2015= largs;
xprintf("enum %.*s expects %d type arguments, not %d", _temp2013.last_plus_one -
_temp2013.curr, _temp2013.curr, _temp2014, _temp2015);}));} for( 0; _temp1926 !=
0; _temp1926= _temp1926->tl, tvs= tvs->tl){ void* t1=( void*) _temp1926->hd;
void* k1=(( void*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(((
struct Cyc_Absyn_Tvar*) tvs->hd)->kind); free_vars= Cyc_Tcutil_check_valid_type(
loc, te, free_vars, k1, t1);} goto _LL1876;}} _LL1886: if(* _temp1932 == 0){
struct _handler_cons _temp2016; _push_handler(& _temp2016);{ struct
_xenum_struct* _temp2017=( struct _xenum_struct*) setjmp( _temp2016.handler);
if( ! _temp2017){{ struct Cyc_Core_Opt* xed= Cyc_Tcenv_lookup_xenumdecl( te, loc,
_temp1933); if( xed == 0){ Cyc_Tcutil_terr( loc,({ struct _tagged_string
_temp2018= Cyc_Absynpp_qvar2string( _temp1933); xprintf("unbound xenum %.*s",
_temp2018.last_plus_one - _temp2018.curr, _temp2018.curr);}));{ struct Cyc_List_List*
_temp2019= free_vars; _npop_handler( 0u); return _temp2019;}}* _temp1932=(
struct Cyc_Absyn_Xenumdecl**)(( struct Cyc_Absyn_Xenumdecl**) xed->v);};
_pop_handler();} else{ struct _xenum_struct* _temp2021= _temp2017; _LL2023: if(
_temp2021->tag == Cyc_Dict_Absent_tag){ goto _LL2024;} else{ goto _LL2025;}
_LL2025: goto _LL2026; _LL2024: Cyc_Tcutil_terr( loc,({ struct _tagged_string
_temp2027= Cyc_Absynpp_qvar2string( _temp1933); xprintf("unbound xenum %.*s",
_temp2027.last_plus_one - _temp2027.curr, _temp2027.curr);})); return free_vars;
_LL2026:( void) _throw( _temp2021); _LL2022:;}}}{ struct Cyc_Absyn_Xenumdecl*
xed=*(* _temp1932);({ struct _tuple1* _temp2028= _temp1933; unsigned int
_temp2029= 0; if( _temp2029 >= 1u){ _throw( Null_Exception);} _temp2028[
_temp2029]=({ struct _tuple1* _temp2030= xed->name; unsigned int _temp2031= 0;
if( _temp2031 >= 1u){ _throw( Null_Exception);} _temp2030[ _temp2031];});});
goto _LL1876;} _LL1888: free_vars= Cyc_Tcutil_check_valid_type( loc, te,
free_vars, Cyc_Absyn_AnyKind, _temp1945); free_vars= Cyc_Tcutil_check_valid_type(
loc, te, free_vars, Cyc_Absyn_RgnKind, _temp1943);{ void* _temp2032=( void*)(((
struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)(
_temp1937))->v; void* _temp2038; struct Cyc_Absyn_Exp* _temp2040; _LL2034: if((
unsigned int) _temp2032 > 1u?(( struct _enum_struct*) _temp2032)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL2039: _temp2038=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp2032)->f1;
if(( unsigned int) _temp2038 > 1u?(( struct _enum_struct*) _temp2038)->tag ==
Cyc_Absyn_Upper_b_tag: 0){ _LL2041: _temp2040=( struct Cyc_Absyn_Exp*)(( struct
Cyc_Absyn_Upper_b_struct*) _temp2038)->f1; goto _LL2035;} else{ goto _LL2036;}}
else{ goto _LL2036;} _LL2036: goto _LL2037; _LL2035: Cyc_Evexp_eval_const_uint_exp(
_temp2040); goto _LL2033; _LL2037: goto _LL2033; _LL2033:;} goto _LL1876;
_LL1890: goto _LL1876; _LL1892: goto _LL1876; _LL1894: goto _LL1876; _LL1896:
free_vars= Cyc_Tcutil_check_valid_type( loc, te, free_vars, Cyc_Absyn_MemKind,
_temp1955); Cyc_Evexp_eval_const_uint_exp( _temp1951); goto _LL1876; _LL1898:
if( _temp1959 != 0){ int seen_cdecl= 0; int seen_stdcall= 0; for( 0; _temp1959
!= 0; _temp1959= _temp1959->tl){ if( ! Cyc_Tcutil_fntype_att(( void*) _temp1959->hd)){
Cyc_Tcutil_terr( loc,({ struct _tagged_string _temp2042= Cyc_Absyn_attribute2string((
void*) _temp1959->hd); xprintf("bad function type attribute %.*s", _temp2042.last_plus_one
- _temp2042.curr, _temp2042.curr);}));} if(( void*) _temp1959->hd == Cyc_Absyn_Stdcall_att){
if( seen_cdecl){ Cyc_Tcutil_terr( loc, xprintf("function can't be both cdecl and stdcall"));}
seen_stdcall= 1;} else{ if(( void*) _temp1959->hd == Cyc_Absyn_Cdecl_att){ if(
seen_stdcall){ Cyc_Tcutil_terr( loc, xprintf("function can't be both cdecl and stdcall"));}
seen_cdecl= 1;}}}} Cyc_Tcutil_check_unique_tvars( loc,* _temp1972);{ struct Cyc_List_List*
b=* _temp1972; for( 0; b != 0; b= b->tl){ void* _temp2043=( void*)((( struct Cyc_Absyn_Conref*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)((( struct Cyc_Absyn_Tvar*)
b->hd)->kind))->v; void* _temp2049; _LL2045: if(( unsigned int) _temp2043 > 1u?((
struct _enum_struct*) _temp2043)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL2050:
_temp2049=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp2043)->f1; if(
_temp2049 == Cyc_Absyn_MemKind){ goto _LL2046;} else{ goto _LL2047;}} else{ goto
_LL2047;} _LL2047: goto _LL2048; _LL2046: Cyc_Tcutil_terr( loc,({ struct
_tagged_string _temp2051=*(( struct Cyc_Absyn_Tvar*) b->hd)->name; xprintf("function attempts to abstract Mem type variable %.*s",
_temp2051.last_plus_one - _temp2051.curr, _temp2051.curr);})); goto _LL2044;
_LL2048: goto _LL2044; _LL2044:;}}{ struct Cyc_List_List* new_free_vars= 0;
new_free_vars= Cyc_Tcutil_check_valid_type( loc, te, new_free_vars, Cyc_Absyn_MemKind,
_temp1965); for( 0; _temp1963 != 0; _temp1963= _temp1963->tl){ new_free_vars=
Cyc_Tcutil_check_valid_type( loc, te, new_free_vars, Cyc_Absyn_MemKind,(*((
struct _tuple2*) _temp1963->hd)).f3);} if(* _temp1969 != 0){ new_free_vars= Cyc_Tcutil_check_valid_type(
loc, te, new_free_vars, Cyc_Absyn_EffKind,( void*)(* _temp1969)->v);} else{
struct Cyc_Absyn_Tvar* e= Cyc_Tcutil_new_tvar( Cyc_Absyn_EffKind); new_free_vars=({
struct Cyc_List_List* _temp2052=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp2052->hd=( void*) e; _temp2052->tl= new_free_vars;
_temp2052;});{ struct Cyc_List_List* effect= 0;{ struct Cyc_List_List* tvs=
new_free_vars; for( 0; tvs != 0; tvs= tvs->tl){ void* _temp2053=( void*)(((
struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)(((
struct Cyc_Absyn_Tvar*) tvs->hd)->kind))->v; void* _temp2061; void* _temp2063;
_LL2055: if(( unsigned int) _temp2053 > 1u?(( struct _enum_struct*) _temp2053)->tag
== Cyc_Absyn_Eq_constr_tag: 0){ _LL2062: _temp2061=( void*)(( struct Cyc_Absyn_Eq_constr_struct*)
_temp2053)->f1; if( _temp2061 == Cyc_Absyn_RgnKind){ goto _LL2056;} else{ goto
_LL2057;}} else{ goto _LL2057;} _LL2057: if(( unsigned int) _temp2053 > 1u?((
struct _enum_struct*) _temp2053)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL2064:
_temp2063=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp2053)->f1; if(
_temp2063 == Cyc_Absyn_EffKind){ goto _LL2058;} else{ goto _LL2059;}} else{ goto
_LL2059;} _LL2059: goto _LL2060; _LL2056: effect=({ struct Cyc_List_List*
_temp2065=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp2065->hd=( void*)({ struct Cyc_Absyn_AccessEff_struct* _temp2066=( struct
Cyc_Absyn_AccessEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_AccessEff_struct));
_temp2066->tag= Cyc_Absyn_AccessEff_tag; _temp2066->f1=( void*)({ struct Cyc_Absyn_VarType_struct*
_temp2067=( struct Cyc_Absyn_VarType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct));
_temp2067->tag= Cyc_Absyn_VarType_tag; _temp2067->f1=( struct Cyc_Absyn_Tvar*)
tvs->hd;( void*) _temp2067;});( void*) _temp2066;}); _temp2065->tl= effect;
_temp2065;}); goto _LL2054; _LL2058: effect=({ struct Cyc_List_List* _temp2068=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp2068->hd=(
void*)({ struct Cyc_Absyn_VarType_struct* _temp2069=( struct Cyc_Absyn_VarType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct)); _temp2069->tag= Cyc_Absyn_VarType_tag;
_temp2069->f1=( struct Cyc_Absyn_Tvar*) tvs->hd;( void*) _temp2069;}); _temp2068->tl=
effect; _temp2068;}); goto _LL2054; _LL2060: goto _LL2054; _LL2054:;}}*
_temp1969=({ struct Cyc_Core_Opt* _temp2070=( struct Cyc_Core_Opt*) GC_malloc(
sizeof( struct Cyc_Core_Opt)); _temp2070->v=( void*)({ struct Cyc_Absyn_JoinEff_struct*
_temp2071=( struct Cyc_Absyn_JoinEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct));
_temp2071->tag= Cyc_Absyn_JoinEff_tag; _temp2071->f1=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( effect);( void*) _temp2071;});
_temp2070;});}} if(* _temp1972 != 0){ struct Cyc_List_List* new_btvs= 0;{ struct
Cyc_List_List* bs=* _temp1972; for( 0; bs != 0; bs= bs->tl){ new_free_vars= Cyc_Tcutil_add_free_tvar(
loc, new_free_vars,( struct Cyc_Absyn_Tvar*) bs->hd);{ struct Cyc_Absyn_Conref*
c=(( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)(((
struct Cyc_Absyn_Tvar*) bs->hd)->kind); void* _temp2072=( void*) c->v; void*
_temp2080; _LL2074: if( _temp2072 == Cyc_Absyn_No_constr){ goto _LL2075;} else{
goto _LL2076;} _LL2076: if(( unsigned int) _temp2072 > 1u?(( struct _enum_struct*)
_temp2072)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL2081: _temp2080=( void*)((
struct Cyc_Absyn_Eq_constr_struct*) _temp2072)->f1; if( _temp2080 == Cyc_Absyn_MemKind){
goto _LL2077;} else{ goto _LL2078;}} else{ goto _LL2078;} _LL2078: goto _LL2079;
_LL2075: Cyc_Tcutil_warn( loc,({ struct _tagged_string _temp2082=*(( struct Cyc_Absyn_Tvar*)
bs->hd)->name; xprintf("Type variable %.*s unconstrained, assuming boxed",
_temp2082.last_plus_one - _temp2082.curr, _temp2082.curr);})); goto _LL2077;
_LL2077:( void*)( c->v=( void*)({ struct Cyc_Absyn_Eq_constr_struct* _temp2083=(
struct Cyc_Absyn_Eq_constr_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct));
_temp2083->tag= Cyc_Absyn_Eq_constr_tag; _temp2083->f1=( void*) Cyc_Absyn_BoxKind;(
void*) _temp2083;})); goto _LL2073; _LL2079: goto _LL2073; _LL2073:;}}}
new_free_vars= Cyc_Tcutil_remove_bound_tvars( new_free_vars,* _temp1972);} for(
0; new_free_vars != 0; new_free_vars= new_free_vars->tl){ free_vars= Cyc_Tcutil_add_free_tvar(
loc, free_vars,( struct Cyc_Absyn_Tvar*) new_free_vars->hd);} goto _LL1876;}
_LL1900: for( 0; _temp1973 != 0; _temp1973= _temp1973->tl){ free_vars= Cyc_Tcutil_check_valid_type(
loc, te, free_vars, Cyc_Absyn_MemKind,(*(( struct _tuple4*) _temp1973->hd)).f2);}
goto _LL1876; _LL1902: if( _temp1980 == 0){ Cyc_Tcutil_terr( loc,( struct
_tagged_string)({ char* _temp2084=( char*)"missing struct name"; struct
_tagged_string _temp2085; _temp2085.curr= _temp2084; _temp2085.base= _temp2084;
_temp2085.last_plus_one= _temp2084 + 20; _temp2085;})); return free_vars;} if(*
_temp1977 == 0){ struct _handler_cons _temp2086; _push_handler(& _temp2086);{
struct _xenum_struct* _temp2087=( struct _xenum_struct*) setjmp( _temp2086.handler);
if( ! _temp2087){* _temp1977=( struct Cyc_Absyn_Structdecl**) Cyc_Tcenv_lookup_structdecl(
te, loc,( struct _tuple1*)({ struct _tuple1* _temp2088= _temp1980; if( _temp2088
== 0){ _throw( Null_Exception);} _temp2088;}));; _pop_handler();} else{ struct
_xenum_struct* _temp2090= _temp2087; _LL2092: if( _temp2090->tag == Cyc_Dict_Absent_tag){
goto _LL2093;} else{ goto _LL2094;} _LL2094: goto _LL2095; _LL2093: Cyc_Tcutil_terr(
loc,({ struct _tagged_string _temp2097= Cyc_Absynpp_qvar2string(( struct _tuple1*)({
struct _tuple1* _temp2096= _temp1980; if( _temp2096 == 0){ _throw(
Null_Exception);} _temp2096;})); xprintf("unbound type struct %.*s", _temp2097.last_plus_one
- _temp2097.curr, _temp2097.curr);})); return free_vars; _LL2095:( void) _throw(
_temp2090); _LL2091:;}}}{ struct Cyc_Absyn_Structdecl* sd=*(* _temp1977); if( sd->name
!= 0){* _temp1980=({ struct _tuple1* _temp2098=( struct _tuple1*)( sd->name)->v;
unsigned int _temp2099= 0; if( _temp2099 >= 1u){ _throw( Null_Exception);}
_temp2098[ _temp2099];});}{ struct Cyc_List_List* tvs= sd->tvs; int lvs=(( int(*)(
struct Cyc_List_List* x)) Cyc_List_length)( tvs); int largs=(( int(*)( struct
Cyc_List_List* x)) Cyc_List_length)( _temp1978); if( lvs != largs){ Cyc_Tcutil_terr(
loc,({ struct _tagged_string _temp2101= Cyc_Absynpp_qvar2string(( struct _tuple1*)({
struct _tuple1* _temp2100= _temp1980; if( _temp2100 == 0){ _throw(
Null_Exception);} _temp2100;})); int _temp2102= lvs; int _temp2103= largs;
xprintf("struct %.*s expects %d type arguments but was given %d", _temp2101.last_plus_one
- _temp2101.curr, _temp2101.curr, _temp2102, _temp2103);}));} for( 0; _temp1978
!= 0; _temp1978= _temp1978->tl, tvs= tvs->tl){ void* t1=( void*) _temp1978->hd;
void* k1=(( void*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(((
struct Cyc_Absyn_Tvar*) tvs->hd)->kind); free_vars= Cyc_Tcutil_check_valid_type(
loc, te, free_vars, k1, t1);} goto _LL1876;}} _LL1904: { struct Cyc_Absyn_Typedefdecl*
td;{ struct _handler_cons _temp2104; _push_handler(& _temp2104);{ struct
_xenum_struct* _temp2105=( struct _xenum_struct*) setjmp( _temp2104.handler);
if( ! _temp2105){ td= Cyc_Tcenv_lookup_typedefdecl( te, loc, _temp1987);;
_pop_handler();} else{ struct _xenum_struct* _temp2107= _temp2105; _LL2109: if(
_temp2107->tag == Cyc_Dict_Absent_tag){ goto _LL2110;} else{ goto _LL2111;}
_LL2111: goto _LL2112; _LL2110: Cyc_Tcutil_terr( loc,({ struct _tagged_string
_temp2113= Cyc_Absynpp_qvar2string( _temp1987); xprintf("unbound typedef name %.*s",
_temp2113.last_plus_one - _temp2113.curr, _temp2113.curr);})); return free_vars;
_LL2112:( void) _throw( _temp2107); _LL2108:;}}}({ struct _tuple1* _temp2114=
_temp1987; unsigned int _temp2115= 0; if( _temp2115 >= 1u){ _throw(
Null_Exception);} _temp2114[ _temp2115]=({ struct _tuple1* _temp2116= td->name;
unsigned int _temp2117= 0; if( _temp2117 >= 1u){ _throw( Null_Exception);}
_temp2116[ _temp2117];});});{ struct Cyc_List_List* tvs= td->tvs; struct Cyc_List_List*
ts= _temp1985; struct Cyc_List_List* inst= 0; for( 0; ts != 0? tvs != 0: 0; ts=
ts->tl, tvs= tvs->tl){ void* k=(( void*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(((
struct Cyc_Absyn_Tvar*) tvs->hd)->kind); free_vars= Cyc_Tcutil_check_valid_type(
loc, te, free_vars, k,( void*) ts->hd); inst=({ struct Cyc_List_List* _temp2118=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp2118->hd=(
void*)({ struct _tuple5* _temp2119=( struct _tuple5*) GC_malloc( sizeof( struct
_tuple5)); _temp2119->f1=( struct Cyc_Absyn_Tvar*) tvs->hd; _temp2119->f2=( void*)
ts->hd; _temp2119;}); _temp2118->tl= inst; _temp2118;});} if( tvs != 0? 1: ts !=
0){ Cyc_Tcutil_terr( loc,({ struct _tagged_string _temp2120= Cyc_Absynpp_qvar2string(
_temp1987); xprintf("typedef %.*s expects a different number of arguments",
_temp2120.last_plus_one - _temp2120.curr, _temp2120.curr);})); return free_vars;}{
void* new_typ= Cyc_Tcutil_substitute( inst,( void*) td->defn);* _temp1984=({
struct Cyc_Core_Opt* _temp2121=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp2121->v=( void*) new_typ; _temp2121;}); goto _LL1876;}}}
_LL1906: Cyc_Tcutil_terr( loc,( struct _tagged_string)({ char* _temp2122=( char*)"union type unsupported";
struct _tagged_string _temp2123; _temp2123.curr= _temp2122; _temp2123.base=
_temp2122; _temp2123.last_plus_one= _temp2122 + 23; _temp2123;})); goto _LL1876;
_LL1908: goto _LL1876; _LL1910: _temp1991= _temp1989; goto _LL1912; _LL1912:
free_vars= Cyc_Tcutil_check_valid_type( loc, te, free_vars, Cyc_Absyn_RgnKind,
_temp1991); goto _LL1876; _LL1914: for( 0; _temp1993 != 0; _temp1993= _temp1993->tl){
free_vars= Cyc_Tcutil_check_valid_type( loc, te, free_vars, Cyc_Absyn_EffKind,(
void*) _temp1993->hd);} goto _LL1876; _LL1876:;} if( ! Cyc_Tcutil_kind_leq( Cyc_Tcutil_typ_kind(
t), expected_kind)){ Cyc_Tcutil_terr( loc,({ struct _tagged_string _temp2124=
Cyc_Absynpp_typ2string( t); struct _tagged_string _temp2125= Cyc_Absynpp_kind2string(
Cyc_Tcutil_typ_kind( t)); struct _tagged_string _temp2126= Cyc_Absynpp_kind2string(
expected_kind); xprintf("type %.*s has kind %.*s but as used here needs kind %.*s",
_temp2124.last_plus_one - _temp2124.curr, _temp2124.curr, _temp2125.last_plus_one
- _temp2125.curr, _temp2125.curr, _temp2126.last_plus_one - _temp2126.curr,
_temp2126.curr);}));} return free_vars;} void Cyc_Tcutil_check_valid_toplevel_type(
struct Cyc_Position_Segment* loc, struct Cyc_Tcenv_Tenv* te, void* t){ struct
Cyc_List_List* free_tvars= Cyc_Tcutil_check_valid_type( loc, te, 0, Cyc_Absyn_MemKind,
t);{ struct Cyc_List_List* x= free_tvars; for( 0; x != 0; x= x->tl){ struct Cyc_Absyn_Conref*
c=(( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)(((
struct Cyc_Absyn_Tvar*) x->hd)->kind); void* _temp2127=( void*) c->v; void*
_temp2135; _LL2129: if( _temp2127 == Cyc_Absyn_No_constr){ goto _LL2130;} else{
goto _LL2131;} _LL2131: if(( unsigned int) _temp2127 > 1u?(( struct _enum_struct*)
_temp2127)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL2136: _temp2135=( void*)((
struct Cyc_Absyn_Eq_constr_struct*) _temp2127)->f1; if( _temp2135 == Cyc_Absyn_MemKind){
goto _LL2132;} else{ goto _LL2133;}} else{ goto _LL2133;} _LL2133: goto _LL2134;
_LL2130: goto _LL2132; _LL2132:( void*)( c->v=( void*)({ struct Cyc_Absyn_Eq_constr_struct*
_temp2137=( struct Cyc_Absyn_Eq_constr_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct));
_temp2137->tag= Cyc_Absyn_Eq_constr_tag; _temp2137->f1=( void*) Cyc_Absyn_BoxKind;(
void*) _temp2137;})); goto _LL2128; _LL2134: goto _LL2128; _LL2128:;}} if(
free_tvars != 0){ void* _temp2138= Cyc_Tcutil_compress( t); struct Cyc_Absyn_FnInfo
_temp2144; struct Cyc_List_List* _temp2146; int _temp2148; struct Cyc_List_List*
_temp2150; void* _temp2152; struct Cyc_Core_Opt* _temp2154; struct Cyc_List_List*
_temp2156; struct Cyc_List_List** _temp2158; _LL2140: if(( unsigned int)
_temp2138 > 5u?(( struct _enum_struct*) _temp2138)->tag == Cyc_Absyn_FnType_tag:
0){ _LL2145: _temp2144=( struct Cyc_Absyn_FnInfo)(( struct Cyc_Absyn_FnType_struct*)
_temp2138)->f1; _LL2157: _temp2156=( struct Cyc_List_List*) _temp2144.tvars;
_temp2158=&((( struct Cyc_Absyn_FnType_struct*) _temp2138)->f1).tvars; goto
_LL2155; _LL2155: _temp2154=( struct Cyc_Core_Opt*) _temp2144.effect; goto
_LL2153; _LL2153: _temp2152=( void*) _temp2144.ret_typ; goto _LL2151; _LL2151:
_temp2150=( struct Cyc_List_List*) _temp2144.args; goto _LL2149; _LL2149:
_temp2148=( int) _temp2144.varargs; goto _LL2147; _LL2147: _temp2146=( struct
Cyc_List_List*) _temp2144.attributes; goto _LL2141;} else{ goto _LL2142;}
_LL2142: goto _LL2143; _LL2141: if(* _temp2158 == 0){* _temp2158= free_tvars;}
else{ if( free_tvars != 0){ struct _tagged_string s=*(( struct Cyc_Absyn_Tvar*)
free_tvars->hd)->name; if(( int)({ struct _tagged_string _temp2159= s; char*
_temp2161= _temp2159.curr + 0; if( _temp2161 < _temp2159.base? 1: _temp2161 >=
_temp2159.last_plus_one){ _throw( Null_Exception);}* _temp2161;}) ==( int)'?'){
Cyc_Tcutil_terr( loc, xprintf("You failed to abstract over the generated type variables. \nRemove the bound type variables or else make the effects of the type explicit\nand then abstract the free type variables properly."));}
else{ Cyc_Tcutil_terr( loc,({ struct _tagged_string _temp2162= s; xprintf("unbound type variable %.*s",
_temp2162.last_plus_one - _temp2162.curr, _temp2162.curr);}));}}} goto _LL2139;
_LL2143: Cyc_Tcutil_terr( loc,({ struct _tagged_string _temp2163=*(( struct Cyc_Absyn_Tvar*)
free_tvars->hd)->name; xprintf("unbound type variable %.*s", _temp2163.last_plus_one
- _temp2163.curr, _temp2163.curr);})); return; _LL2139:;}} void Cyc_Tcutil_check_type(
struct Cyc_Position_Segment* loc, struct Cyc_Tcenv_Tenv* te, struct Cyc_List_List*
bound_tvars, void* expected_kind, void* t){ struct Cyc_List_List* free_tvars=
Cyc_Tcutil_check_valid_type( loc, te, 0, expected_kind, t); struct Cyc_List_List*
fs= free_tvars; for( 0; fs != 0; fs= fs->tl){ struct Cyc_Absyn_Tvar* ftv=(
struct Cyc_Absyn_Tvar*) fs->hd; struct _tagged_string* ftvn= ftv->name; struct
Cyc_Absyn_Conref* ftvk= ftv->kind; int present= 0;{ struct Cyc_List_List* bs=
bound_tvars; for( 0; bs != 0; bs= bs->tl){ struct Cyc_Absyn_Tvar* btv=( struct
Cyc_Absyn_Tvar*) bs->hd; struct _tagged_string* btvn= btv->name; struct Cyc_Absyn_Conref*
btvk= btv->kind; if( Cyc_String_zstrptrcmp( ftvn, btvn) == 0){ present= 1; if( !
Cyc_Tcutil_constrain_kinds( btvk, ftvk)){ Cyc_Tcutil_terr( loc,({ struct
_tagged_string _temp2164=* ftvn; struct _tagged_string _temp2165= Cyc_Absynpp_ckind2string(
btvk); struct _tagged_string _temp2166= Cyc_Absynpp_ckind2string( ftvk); xprintf("type variable %.*s has kind %.*s but is used here atkind %.*s",
_temp2164.last_plus_one - _temp2164.curr, _temp2164.curr, _temp2165.last_plus_one
- _temp2165.curr, _temp2165.curr, _temp2166.last_plus_one - _temp2166.curr,
_temp2166.curr);}));} break;}}} if( ! present){ Cyc_Tcutil_terr( loc,({ struct
_tagged_string _temp2167=* ftvn; struct _tagged_string _temp2168= Cyc_Absynpp_typ2string(
t); xprintf("unbound type variable %.*s in type %.*s", _temp2167.last_plus_one -
_temp2167.curr, _temp2167.curr, _temp2168.last_plus_one - _temp2168.curr,
_temp2168.curr);}));}}} static void Cyc_Tcutil_check_unique_unsorted( int(* cmp)(
void*, void*), struct Cyc_List_List* vs, struct Cyc_Position_Segment* loc,
struct _tagged_string(* a2string)( void*), struct _tagged_string msg){ for( 0;
vs != 0; vs= vs->tl){ struct Cyc_List_List* vs2= vs->tl; for( 0; vs2 != 0; vs2=
vs2->tl){ if( cmp(( void*) vs->hd,( void*) vs2->hd) == 0){ Cyc_Tcutil_terr( loc,({
struct _tagged_string _temp2169= msg; struct _tagged_string _temp2170= a2string((
void*) vs->hd); xprintf("%.*s: %.*s", _temp2169.last_plus_one - _temp2169.curr,
_temp2169.curr, _temp2170.last_plus_one - _temp2170.curr, _temp2170.curr);}));}}}}
static struct _tagged_string Cyc_Tcutil_strptr2string( struct _tagged_string* s){
return* s;} void Cyc_Tcutil_check_unique_vars( struct Cyc_List_List* vs, struct
Cyc_Position_Segment* loc, struct _tagged_string msg){(( void(*)( int(* cmp)(
struct _tagged_string*, struct _tagged_string*), struct Cyc_List_List* vs,
struct Cyc_Position_Segment* loc, struct _tagged_string(* a2string)( struct
_tagged_string*), struct _tagged_string msg)) Cyc_Tcutil_check_unique_unsorted)(
Cyc_String_zstrptrcmp, vs, loc, Cyc_Tcutil_strptr2string, msg);} void Cyc_Tcutil_check_unique_tvars(
struct Cyc_Position_Segment* loc, struct Cyc_List_List* tvs){(( void(*)( int(*
cmp)( struct Cyc_Absyn_Tvar*, struct Cyc_Absyn_Tvar*), struct Cyc_List_List* vs,
struct Cyc_Position_Segment* loc, struct _tagged_string(* a2string)( struct Cyc_Absyn_Tvar*),
struct _tagged_string msg)) Cyc_Tcutil_check_unique_unsorted)( Cyc_Absyn_tvar_cmp,
tvs, loc, Cyc_Tcutil_tvar2string,( struct _tagged_string)({ char* _temp2171=(
char*)"duplicate type variable"; struct _tagged_string _temp2172; _temp2172.curr=
_temp2171; _temp2172.base= _temp2171; _temp2172.last_plus_one= _temp2171 + 24;
_temp2172;}));} struct Cyc_List_List* Cyc_Tcutil_resolve_struct_designators(
struct Cyc_Position_Segment* loc, struct Cyc_List_List* des, struct Cyc_Absyn_Structdecl*
sd){ if( sd->fields == 0){ Cyc_Tcutil_terr( loc,( struct _tagged_string)({ char*
_temp2173=( char*)"inappropriate use of abstract struct"; struct _tagged_string
_temp2174; _temp2174.curr= _temp2173; _temp2174.base= _temp2173; _temp2174.last_plus_one=
_temp2173 + 37; _temp2174;}));}{ struct Cyc_List_List* fields= 0;{ struct Cyc_List_List*
sd_fields=( struct Cyc_List_List*)( sd->fields)->v; for( 0; sd_fields != 0;
sd_fields= sd_fields->tl){ fields=({ struct Cyc_List_List* _temp2175=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp2175->hd=( void*)({
struct _tuple14* _temp2176=( struct _tuple14*) GC_malloc( sizeof( struct
_tuple14)); _temp2176->f1=( struct Cyc_Absyn_Structfield*) sd_fields->hd;
_temp2176->f2= 0; _temp2176;}); _temp2175->tl= fields; _temp2175;});}} fields=((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( fields);{
struct Cyc_List_List* ans= 0; for( 0; des != 0; des= des->tl){ struct _tuple15
_temp2179; void* _temp2180; struct Cyc_List_List* _temp2182; struct _tuple15*
_temp2177=( struct _tuple15*) des->hd; _temp2179=* _temp2177; _LL2183: _temp2182=
_temp2179.f1; goto _LL2181; _LL2181: _temp2180= _temp2179.f2; goto _LL2178;
_LL2178: if( _temp2182 == 0){ struct Cyc_List_List* fields2= fields; for( 0;
fields2 != 0; fields2= fields2->tl){ if( !(*(( struct _tuple14*) fields2->hd)).f2){(*((
struct _tuple14*) fields2->hd)).f2= 1;(*(( struct _tuple15*) des->hd)).f1=({
struct Cyc_List_List* _temp2184=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp2184->hd=( void*)({ struct Cyc_Absyn_FieldName_struct*
_temp2185=( struct Cyc_Absyn_FieldName_struct*) GC_malloc( sizeof( struct Cyc_Absyn_FieldName_struct));
_temp2185->tag= Cyc_Absyn_FieldName_tag; _temp2185->f1=((*(( struct _tuple14*)
fields2->hd)).f1)->name;( void*) _temp2185;}); _temp2184->tl= 0; _temp2184;});
ans=({ struct Cyc_List_List* _temp2186=( struct Cyc_List_List*) GC_malloc(
sizeof( struct Cyc_List_List)); _temp2186->hd=( void*)({ struct _tuple16*
_temp2187=( struct _tuple16*) GC_malloc( sizeof( struct _tuple16)); _temp2187->f1=(*((
struct _tuple14*) fields2->hd)).f1; _temp2187->f2= _temp2180; _temp2187;});
_temp2186->tl= ans; _temp2186;}); break;}} if( fields2 == 0){ Cyc_Tcutil_terr(
loc,( struct _tagged_string)({ char* _temp2188=( char*)"too many arguments to struct";
struct _tagged_string _temp2189; _temp2189.curr= _temp2188; _temp2189.base=
_temp2188; _temp2189.last_plus_one= _temp2188 + 29; _temp2189;}));}} else{ if(
_temp2182->tl != 0){ Cyc_Tcutil_terr( loc,( struct _tagged_string)({ char*
_temp2190=( char*)"multiple designators are not supported"; struct
_tagged_string _temp2191; _temp2191.curr= _temp2190; _temp2191.base= _temp2190;
_temp2191.last_plus_one= _temp2190 + 39; _temp2191;}));} else{ void* _temp2192=(
void*) _temp2182->hd; struct Cyc_Absyn_Exp* _temp2198; struct _tagged_string*
_temp2200; _LL2194: if((( struct _enum_struct*) _temp2192)->tag == Cyc_Absyn_ArrayElement_tag){
_LL2199: _temp2198=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_ArrayElement_struct*)
_temp2192)->f1; goto _LL2195;} else{ goto _LL2196;} _LL2196: if((( struct
_enum_struct*) _temp2192)->tag == Cyc_Absyn_FieldName_tag){ _LL2201: _temp2200=(
struct _tagged_string*)(( struct Cyc_Absyn_FieldName_struct*) _temp2192)->f1;
goto _LL2197;} else{ goto _LL2193;} _LL2195: Cyc_Tcutil_terr( loc,( struct
_tagged_string)({ char* _temp2202=( char*)"array designator used in argument to struct";
struct _tagged_string _temp2203; _temp2203.curr= _temp2202; _temp2203.base=
_temp2202; _temp2203.last_plus_one= _temp2202 + 44; _temp2203;})); goto _LL2193;
_LL2197: { struct Cyc_List_List* fields2= fields; for( 0; fields2 != 0; fields2=
fields2->tl){ if( Cyc_String_zstrptrcmp( _temp2200,((*(( struct _tuple14*)
fields2->hd)).f1)->name) == 0){ if((*(( struct _tuple14*) fields2->hd)).f2){ Cyc_Tcutil_terr(
loc,({ struct _tagged_string _temp2204=* _temp2200; xprintf("field %.*s has already been used as an argument",
_temp2204.last_plus_one - _temp2204.curr, _temp2204.curr);}));}(*(( struct
_tuple14*) fields2->hd)).f2= 1; ans=({ struct Cyc_List_List* _temp2205=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp2205->hd=( void*)({
struct _tuple16* _temp2206=( struct _tuple16*) GC_malloc( sizeof( struct
_tuple16)); _temp2206->f1=(*(( struct _tuple14*) fields2->hd)).f1; _temp2206->f2=
_temp2180; _temp2206;}); _temp2205->tl= ans; _temp2205;}); break;}} if( fields2
== 0){ Cyc_Tcutil_terr( loc,({ struct _tagged_string _temp2207=* _temp2200;
xprintf("bad field designator %.*s", _temp2207.last_plus_one - _temp2207.curr,
_temp2207.curr);}));} goto _LL2193;} _LL2193:;}}} for( 0; fields != 0; fields=
fields->tl){ if( !(*(( struct _tuple14*) fields->hd)).f2){ Cyc_Tcutil_terr( loc,(
struct _tagged_string)({ char* _temp2208=( char*)"too few arguments to struct";
struct _tagged_string _temp2209; _temp2209.curr= _temp2208; _temp2209.base=
_temp2208; _temp2209.last_plus_one= _temp2208 + 28; _temp2209;})); break;}}
return(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
ans);}}} int Cyc_Tcutil_is_tagged_pointer_typ( void* t){ void* _temp2210= Cyc_Tcutil_compress(
t); struct Cyc_Absyn_PtrInfo _temp2216; struct Cyc_Absyn_Conref* _temp2218;
struct Cyc_Absyn_Tqual* _temp2220; struct Cyc_Absyn_Conref* _temp2222; void*
_temp2224; void* _temp2226; _LL2212: if(( unsigned int) _temp2210 > 5u?(( struct
_enum_struct*) _temp2210)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL2217:
_temp2216=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp2210)->f1; _LL2227: _temp2226=( void*) _temp2216.elt_typ; goto _LL2225;
_LL2225: _temp2224=( void*) _temp2216.rgn_typ; goto _LL2223; _LL2223: _temp2222=(
struct Cyc_Absyn_Conref*) _temp2216.nullable; goto _LL2221; _LL2221: _temp2220=(
struct Cyc_Absyn_Tqual*) _temp2216.tq; goto _LL2219; _LL2219: _temp2218=( struct
Cyc_Absyn_Conref*) _temp2216.bounds; goto _LL2213;} else{ goto _LL2214;} _LL2214:
goto _LL2215; _LL2213: { struct Cyc_Absyn_Conref* b=(( struct Cyc_Absyn_Conref*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)( _temp2218); void*
_temp2228=( void*)((( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref* x))
Cyc_Absyn_compress_conref)( b))->v; void* _temp2236; _LL2230: if(( unsigned int)
_temp2228 > 1u?(( struct _enum_struct*) _temp2228)->tag == Cyc_Absyn_Eq_constr_tag:
0){ _LL2237: _temp2236=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp2228)->f1;
if( _temp2236 == Cyc_Absyn_Unknown_b){ goto _LL2231;} else{ goto _LL2232;}}
else{ goto _LL2232;} _LL2232: if( _temp2228 == Cyc_Absyn_No_constr){ goto
_LL2233;} else{ goto _LL2234;} _LL2234: goto _LL2235; _LL2231: return 1; _LL2233:(
void*)( b->v=( void*)({ struct Cyc_Absyn_Eq_constr_struct* _temp2238=( struct
Cyc_Absyn_Eq_constr_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct));
_temp2238->tag= Cyc_Absyn_Eq_constr_tag; _temp2238->f1=( void*) Cyc_Absyn_Unknown_b;(
void*) _temp2238;})); return 1; _LL2235: return 0; _LL2229:;} _LL2215: return 0;
_LL2211:;} struct _tuple6 Cyc_Tcutil_addressof_props( struct Cyc_Tcenv_Tenv* te,
struct Cyc_Absyn_Exp* e){ struct _tuple6 bogus_ans=({ struct _tuple6 _temp2239;
_temp2239.f1= 0; _temp2239.f2= Cyc_Absyn_HeapRgn; _temp2239;}); void* _temp2240=(
void*) e->r; void* _temp2254; struct _tuple1* _temp2256; struct _tagged_string*
_temp2258; struct Cyc_Absyn_Exp* _temp2260; struct _tagged_string* _temp2262;
struct Cyc_Absyn_Exp* _temp2264; struct Cyc_Absyn_Exp* _temp2266; struct Cyc_Absyn_Exp*
_temp2268; struct Cyc_Absyn_Exp* _temp2270; _LL2242: if((( struct _enum_struct*)
_temp2240)->tag == Cyc_Absyn_Var_e_tag){ _LL2257: _temp2256=( struct _tuple1*)((
struct Cyc_Absyn_Var_e_struct*) _temp2240)->f1; goto _LL2255; _LL2255: _temp2254=(
void*)(( struct Cyc_Absyn_Var_e_struct*) _temp2240)->f2; goto _LL2243;} else{
goto _LL2244;} _LL2244: if((( struct _enum_struct*) _temp2240)->tag == Cyc_Absyn_StructMember_e_tag){
_LL2261: _temp2260=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_StructMember_e_struct*)
_temp2240)->f1; goto _LL2259; _LL2259: _temp2258=( struct _tagged_string*)((
struct Cyc_Absyn_StructMember_e_struct*) _temp2240)->f2; goto _LL2245;} else{
goto _LL2246;} _LL2246: if((( struct _enum_struct*) _temp2240)->tag == Cyc_Absyn_StructArrow_e_tag){
_LL2265: _temp2264=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_StructArrow_e_struct*)
_temp2240)->f1; goto _LL2263; _LL2263: _temp2262=( struct _tagged_string*)((
struct Cyc_Absyn_StructArrow_e_struct*) _temp2240)->f2; goto _LL2247;} else{
goto _LL2248;} _LL2248: if((( struct _enum_struct*) _temp2240)->tag == Cyc_Absyn_Deref_e_tag){
_LL2267: _temp2266=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Deref_e_struct*)
_temp2240)->f1; goto _LL2249;} else{ goto _LL2250;} _LL2250: if((( struct
_enum_struct*) _temp2240)->tag == Cyc_Absyn_Subscript_e_tag){ _LL2271: _temp2270=(
struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Subscript_e_struct*) _temp2240)->f1;
goto _LL2269; _LL2269: _temp2268=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Subscript_e_struct*)
_temp2240)->f2; goto _LL2251;} else{ goto _LL2252;} _LL2252: goto _LL2253;
_LL2243: { void* _temp2272= _temp2254; struct Cyc_Absyn_Fndecl* _temp2286;
struct Cyc_Absyn_Vardecl* _temp2288; struct Cyc_Absyn_Vardecl* _temp2290; struct
Cyc_Absyn_Vardecl* _temp2292; struct Cyc_Absyn_Vardecl* _temp2294; _LL2274: if(
_temp2272 == Cyc_Absyn_Unresolved_b){ goto _LL2275;} else{ goto _LL2276;}
_LL2276: if(( unsigned int) _temp2272 > 1u?(( struct _enum_struct*) _temp2272)->tag
== Cyc_Absyn_Funname_b_tag: 0){ _LL2287: _temp2286=( struct Cyc_Absyn_Fndecl*)((
struct Cyc_Absyn_Funname_b_struct*) _temp2272)->f1; goto _LL2277;} else{ goto
_LL2278;} _LL2278: if(( unsigned int) _temp2272 > 1u?(( struct _enum_struct*)
_temp2272)->tag == Cyc_Absyn_Global_b_tag: 0){ _LL2289: _temp2288=( struct Cyc_Absyn_Vardecl*)((
struct Cyc_Absyn_Global_b_struct*) _temp2272)->f1; goto _LL2279;} else{ goto
_LL2280;} _LL2280: if(( unsigned int) _temp2272 > 1u?(( struct _enum_struct*)
_temp2272)->tag == Cyc_Absyn_Local_b_tag: 0){ _LL2291: _temp2290=( struct Cyc_Absyn_Vardecl*)((
struct Cyc_Absyn_Local_b_struct*) _temp2272)->f1; goto _LL2281;} else{ goto
_LL2282;} _LL2282: if(( unsigned int) _temp2272 > 1u?(( struct _enum_struct*)
_temp2272)->tag == Cyc_Absyn_Pat_b_tag: 0){ _LL2293: _temp2292=( struct Cyc_Absyn_Vardecl*)((
struct Cyc_Absyn_Pat_b_struct*) _temp2272)->f1; goto _LL2283;} else{ goto
_LL2284;} _LL2284: if(( unsigned int) _temp2272 > 1u?(( struct _enum_struct*)
_temp2272)->tag == Cyc_Absyn_Param_b_tag: 0){ _LL2295: _temp2294=( struct Cyc_Absyn_Vardecl*)((
struct Cyc_Absyn_Param_b_struct*) _temp2272)->f1; goto _LL2285;} else{ goto
_LL2273;} _LL2275: return bogus_ans; _LL2277: return({ struct _tuple6 _temp2296;
_temp2296.f1= 1; _temp2296.f2= Cyc_Absyn_HeapRgn; _temp2296;}); _LL2279: { void*
_temp2297= Cyc_Tcutil_compress(( void*)( e->topt)->v); struct Cyc_Absyn_Exp*
_temp2303; struct Cyc_Absyn_Tqual* _temp2305; void* _temp2307; _LL2299: if((
unsigned int) _temp2297 > 5u?(( struct _enum_struct*) _temp2297)->tag == Cyc_Absyn_ArrayType_tag:
0){ _LL2308: _temp2307=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp2297)->f1;
goto _LL2306; _LL2306: _temp2305=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp2297)->f2; goto _LL2304; _LL2304: _temp2303=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp2297)->f3; goto _LL2300;} else{ goto
_LL2301;} _LL2301: goto _LL2302; _LL2300: return({ struct _tuple6 _temp2309;
_temp2309.f1= 1; _temp2309.f2= Cyc_Absyn_HeapRgn; _temp2309;}); _LL2302: return({
struct _tuple6 _temp2310; _temp2310.f1=( _temp2288->tq)->q_const; _temp2310.f2=
Cyc_Absyn_HeapRgn; _temp2310;}); _LL2298:;} _LL2281: { void* _temp2311= Cyc_Tcutil_compress((
void*)( e->topt)->v); struct Cyc_Absyn_Exp* _temp2317; struct Cyc_Absyn_Tqual*
_temp2319; void* _temp2321; _LL2313: if(( unsigned int) _temp2311 > 5u?(( struct
_enum_struct*) _temp2311)->tag == Cyc_Absyn_ArrayType_tag: 0){ _LL2322:
_temp2321=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp2311)->f1; goto
_LL2320; _LL2320: _temp2319=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp2311)->f2; goto _LL2318; _LL2318: _temp2317=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp2311)->f3; goto _LL2314;} else{ goto
_LL2315;} _LL2315: goto _LL2316; _LL2314: return({ struct _tuple6 _temp2323;
_temp2323.f1= 1; _temp2323.f2=( void*)( _temp2290->region)->v; _temp2323;});
_LL2316: return({ struct _tuple6 _temp2324; _temp2324.f1=( _temp2290->tq)->q_const;
_temp2324.f2=( void*)( _temp2290->region)->v; _temp2324;}); _LL2312:;} _LL2283:
_temp2294= _temp2292; goto _LL2285; _LL2285: return({ struct _tuple6 _temp2325;
_temp2325.f1=( _temp2294->tq)->q_const; _temp2325.f2=( void*)( _temp2294->region)->v;
_temp2325;}); _LL2273:;} _LL2245: { void* _temp2326= Cyc_Tcutil_compress(( void*)(
_temp2260->topt)->v); struct Cyc_Absyn_Structdecl** _temp2332; struct Cyc_Absyn_Structdecl*
_temp2334; struct Cyc_List_List* _temp2335; struct _tuple1* _temp2337; _LL2328:
if(( unsigned int) _temp2326 > 5u?(( struct _enum_struct*) _temp2326)->tag ==
Cyc_Absyn_StructType_tag: 0){ _LL2338: _temp2337=( struct _tuple1*)(( struct Cyc_Absyn_StructType_struct*)
_temp2326)->f1; goto _LL2336; _LL2336: _temp2335=( struct Cyc_List_List*)((
struct Cyc_Absyn_StructType_struct*) _temp2326)->f2; goto _LL2333; _LL2333:
_temp2332=( struct Cyc_Absyn_Structdecl**)(( struct Cyc_Absyn_StructType_struct*)
_temp2326)->f3; if( _temp2332 == 0){ goto _LL2330;} else{ _temp2334=* _temp2332;
goto _LL2329;}} else{ goto _LL2330;} _LL2330: goto _LL2331; _LL2329: { struct
Cyc_Absyn_Structfield* finfo= Cyc_Absyn_lookup_struct_field( _temp2334,
_temp2258); if( finfo != 0){ return({ struct _tuple6 _temp2339; _temp2339.f1=(
finfo->tq)->q_const; _temp2339.f2=( Cyc_Tcutil_addressof_props( te, _temp2260)).f2;
_temp2339;});} goto _LL2331;} _LL2331: return bogus_ans; _LL2327:;} _LL2247: {
void* _temp2340= Cyc_Tcutil_compress(( void*)( _temp2264->topt)->v); struct Cyc_Absyn_PtrInfo
_temp2346; struct Cyc_Absyn_Conref* _temp2348; struct Cyc_Absyn_Tqual* _temp2350;
struct Cyc_Absyn_Conref* _temp2352; void* _temp2354; void* _temp2356; _LL2342:
if(( unsigned int) _temp2340 > 5u?(( struct _enum_struct*) _temp2340)->tag ==
Cyc_Absyn_PointerType_tag: 0){ _LL2347: _temp2346=( struct Cyc_Absyn_PtrInfo)((
struct Cyc_Absyn_PointerType_struct*) _temp2340)->f1; _LL2357: _temp2356=( void*)
_temp2346.elt_typ; goto _LL2355; _LL2355: _temp2354=( void*) _temp2346.rgn_typ;
goto _LL2353; _LL2353: _temp2352=( struct Cyc_Absyn_Conref*) _temp2346.nullable;
goto _LL2351; _LL2351: _temp2350=( struct Cyc_Absyn_Tqual*) _temp2346.tq; goto
_LL2349; _LL2349: _temp2348=( struct Cyc_Absyn_Conref*) _temp2346.bounds; goto
_LL2343;} else{ goto _LL2344;} _LL2344: goto _LL2345; _LL2343: { void* _temp2358=
Cyc_Tcutil_compress( _temp2356); struct Cyc_Absyn_Structdecl** _temp2364; struct
Cyc_Absyn_Structdecl* _temp2366; struct Cyc_List_List* _temp2367; struct _tuple1*
_temp2369; _LL2360: if(( unsigned int) _temp2358 > 5u?(( struct _enum_struct*)
_temp2358)->tag == Cyc_Absyn_StructType_tag: 0){ _LL2370: _temp2369=( struct
_tuple1*)(( struct Cyc_Absyn_StructType_struct*) _temp2358)->f1; goto _LL2368;
_LL2368: _temp2367=( struct Cyc_List_List*)(( struct Cyc_Absyn_StructType_struct*)
_temp2358)->f2; goto _LL2365; _LL2365: _temp2364=( struct Cyc_Absyn_Structdecl**)((
struct Cyc_Absyn_StructType_struct*) _temp2358)->f3; if( _temp2364 == 0){ goto
_LL2362;} else{ _temp2366=* _temp2364; goto _LL2361;}} else{ goto _LL2362;}
_LL2362: goto _LL2363; _LL2361: { struct Cyc_Absyn_Structfield* finfo= Cyc_Absyn_lookup_struct_field(
_temp2366, _temp2262); if( finfo != 0){ return({ struct _tuple6 _temp2371;
_temp2371.f1=( finfo->tq)->q_const; _temp2371.f2= _temp2354; _temp2371;});} goto
_LL2363;} _LL2363: return bogus_ans; _LL2359:;} _LL2345: return bogus_ans;
_LL2341:;} _LL2249: { void* _temp2372= Cyc_Tcutil_compress(( void*)( _temp2266->topt)->v);
struct Cyc_Absyn_PtrInfo _temp2378; struct Cyc_Absyn_Conref* _temp2380; struct
Cyc_Absyn_Tqual* _temp2382; struct Cyc_Absyn_Conref* _temp2384; void* _temp2386;
void* _temp2388; _LL2374: if(( unsigned int) _temp2372 > 5u?(( struct
_enum_struct*) _temp2372)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL2379:
_temp2378=( struct Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*)
_temp2372)->f1; _LL2389: _temp2388=( void*) _temp2378.elt_typ; goto _LL2387;
_LL2387: _temp2386=( void*) _temp2378.rgn_typ; goto _LL2385; _LL2385: _temp2384=(
struct Cyc_Absyn_Conref*) _temp2378.nullable; goto _LL2383; _LL2383: _temp2382=(
struct Cyc_Absyn_Tqual*) _temp2378.tq; goto _LL2381; _LL2381: _temp2380=( struct
Cyc_Absyn_Conref*) _temp2378.bounds; goto _LL2375;} else{ goto _LL2376;} _LL2376:
goto _LL2377; _LL2375: return({ struct _tuple6 _temp2390; _temp2390.f1=
_temp2382->q_const; _temp2390.f2= _temp2386; _temp2390;}); _LL2377: return
bogus_ans; _LL2373:;} _LL2251: { void* t= Cyc_Tcutil_compress(( void*)(
_temp2270->topt)->v); void* _temp2391= t; struct Cyc_Absyn_Exp* _temp2401;
struct Cyc_Absyn_Tqual* _temp2403; void* _temp2405; struct Cyc_List_List*
_temp2407; struct Cyc_Absyn_PtrInfo _temp2409; struct Cyc_Absyn_Conref*
_temp2411; struct Cyc_Absyn_Tqual* _temp2413; struct Cyc_Absyn_Conref* _temp2415;
void* _temp2417; void* _temp2419; _LL2393: if(( unsigned int) _temp2391 > 5u?((
struct _enum_struct*) _temp2391)->tag == Cyc_Absyn_ArrayType_tag: 0){ _LL2406:
_temp2405=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp2391)->f1; goto
_LL2404; _LL2404: _temp2403=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp2391)->f2; goto _LL2402; _LL2402: _temp2401=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp2391)->f3; goto _LL2394;} else{ goto
_LL2395;} _LL2395: if(( unsigned int) _temp2391 > 5u?(( struct _enum_struct*)
_temp2391)->tag == Cyc_Absyn_TupleType_tag: 0){ _LL2408: _temp2407=( struct Cyc_List_List*)((
struct Cyc_Absyn_TupleType_struct*) _temp2391)->f1; goto _LL2396;} else{ goto
_LL2397;} _LL2397: if(( unsigned int) _temp2391 > 5u?(( struct _enum_struct*)
_temp2391)->tag == Cyc_Absyn_PointerType_tag: 0){ _LL2410: _temp2409=( struct
Cyc_Absyn_PtrInfo)(( struct Cyc_Absyn_PointerType_struct*) _temp2391)->f1;
_LL2420: _temp2419=( void*) _temp2409.elt_typ; goto _LL2418; _LL2418: _temp2417=(
void*) _temp2409.rgn_typ; goto _LL2416; _LL2416: _temp2415=( struct Cyc_Absyn_Conref*)
_temp2409.nullable; goto _LL2414; _LL2414: _temp2413=( struct Cyc_Absyn_Tqual*)
_temp2409.tq; goto _LL2412; _LL2412: _temp2411=( struct Cyc_Absyn_Conref*)
_temp2409.bounds; goto _LL2398;} else{ goto _LL2399;} _LL2399: goto _LL2400;
_LL2394: return({ struct _tuple6 _temp2421; _temp2421.f1= _temp2403->q_const;
_temp2421.f2=( Cyc_Tcutil_addressof_props( te, _temp2270)).f2; _temp2421;});
_LL2396: { struct _tuple4* finfo= Cyc_Absyn_lookup_tuple_field( _temp2407,( int)
Cyc_Evexp_eval_const_uint_exp( _temp2268)); if( finfo != 0){ return({ struct
_tuple6 _temp2422; _temp2422.f1=((* finfo).f1)->q_const; _temp2422.f2=( Cyc_Tcutil_addressof_props(
te, _temp2270)).f2; _temp2422;});} return bogus_ans;} _LL2398: return({ struct
_tuple6 _temp2423; _temp2423.f1= _temp2413->q_const; _temp2423.f2= _temp2417;
_temp2423;}); _LL2400: return bogus_ans; _LL2392:;} _LL2253: Cyc_Tcutil_terr( e->loc,(
struct _tagged_string)({ char* _temp2424=( char*)"unary & applied to non-lvalue";
struct _tagged_string _temp2425; _temp2425.curr= _temp2424; _temp2425.base=
_temp2424; _temp2425.last_plus_one= _temp2424 + 30; _temp2425;})); return
bogus_ans; _LL2241:;} void* Cyc_Tcutil_array_to_ptr( struct Cyc_Tcenv_Tenv* te,
void* e_typ, struct Cyc_Absyn_Exp* e){ void* _temp2426= Cyc_Tcutil_compress(
e_typ); struct Cyc_Absyn_Exp* _temp2432; struct Cyc_Absyn_Tqual* _temp2434; void*
_temp2436; _LL2428: if(( unsigned int) _temp2426 > 5u?(( struct _enum_struct*)
_temp2426)->tag == Cyc_Absyn_ArrayType_tag: 0){ _LL2437: _temp2436=( void*)((
struct Cyc_Absyn_ArrayType_struct*) _temp2426)->f1; goto _LL2435; _LL2435:
_temp2434=( struct Cyc_Absyn_Tqual*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp2426)->f2; goto _LL2433; _LL2433: _temp2432=( struct Cyc_Absyn_Exp*)((
struct Cyc_Absyn_ArrayType_struct*) _temp2426)->f3; goto _LL2429;} else{ goto
_LL2430;} _LL2430: goto _LL2431; _LL2429: { void* _temp2440; int _temp2442;
struct _tuple6 _temp2438= Cyc_Tcutil_addressof_props( te, e); _LL2443: _temp2442=
_temp2438.f1; goto _LL2441; _LL2441: _temp2440= _temp2438.f2; goto _LL2439;
_LL2439: return Cyc_Absyn_atb_typ( _temp2436, _temp2440, _temp2434,({ struct Cyc_Absyn_Upper_b_struct*
_temp2444=( struct Cyc_Absyn_Upper_b_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct));
_temp2444->tag= Cyc_Absyn_Upper_b_tag; _temp2444->f1= e;( void*) _temp2444;}));}
_LL2431: return e_typ; _LL2427:;} void Cyc_Tcutil_check_bound( struct Cyc_Position_Segment*
loc, unsigned int i, struct Cyc_Absyn_Conref* b){ b=(( struct Cyc_Absyn_Conref*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)( b);{ void* _temp2445=(
void*) b->v; void* _temp2453; void* _temp2455; struct Cyc_Absyn_Exp* _temp2457;
_LL2447: if(( unsigned int) _temp2445 > 1u?(( struct _enum_struct*) _temp2445)->tag
== Cyc_Absyn_Eq_constr_tag: 0){ _LL2454: _temp2453=( void*)(( struct Cyc_Absyn_Eq_constr_struct*)
_temp2445)->f1; if( _temp2453 == Cyc_Absyn_Unknown_b){ goto _LL2448;} else{ goto
_LL2449;}} else{ goto _LL2449;} _LL2449: if(( unsigned int) _temp2445 > 1u?((
struct _enum_struct*) _temp2445)->tag == Cyc_Absyn_Eq_constr_tag: 0){ _LL2456:
_temp2455=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp2445)->f1; if((
unsigned int) _temp2455 > 1u?(( struct _enum_struct*) _temp2455)->tag == Cyc_Absyn_Upper_b_tag:
0){ _LL2458: _temp2457=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Upper_b_struct*)
_temp2455)->f1; goto _LL2450;} else{ goto _LL2451;}} else{ goto _LL2451;}
_LL2451: goto _LL2452; _LL2448: return; _LL2450: if( Cyc_Evexp_eval_const_uint_exp(
_temp2457) <= i){ Cyc_Tcutil_terr( loc,( struct _tagged_string)({ char*
_temp2459=( char*)"dereference is out of bounds"; struct _tagged_string
_temp2460; _temp2460.curr= _temp2459; _temp2460.base= _temp2459; _temp2460.last_plus_one=
_temp2459 + 29; _temp2460;}));} return; _LL2452:( void*)( b->v=( void*)({ struct
Cyc_Absyn_Eq_constr_struct* _temp2461=( struct Cyc_Absyn_Eq_constr_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct)); _temp2461->tag= Cyc_Absyn_Eq_constr_tag;
_temp2461->f1=( void*)({ struct Cyc_Absyn_Upper_b_struct* _temp2462=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp2462->tag= Cyc_Absyn_Upper_b_tag;
_temp2462->f1= Cyc_Absyn_uint_exp( i +( unsigned int) 1, 0);( void*) _temp2462;});(
void*) _temp2461;})); return; _LL2446:;}} void Cyc_Tcutil_check_nonzero_bound(
struct Cyc_Position_Segment* loc, struct Cyc_Absyn_Conref* b){ Cyc_Tcutil_check_bound(
loc, 0, b);}