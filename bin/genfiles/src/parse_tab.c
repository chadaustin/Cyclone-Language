#include "cyc_include.h"

 typedef int Cyc_ptrdiff_t; typedef unsigned int Cyc_size_t; typedef
unsigned short Cyc_wchar_t; typedef unsigned int Cyc_wint_t; typedef char Cyc_u_char;
typedef unsigned short Cyc_u_short; typedef unsigned int Cyc_u_int; typedef
unsigned int Cyc_u_long; typedef unsigned short Cyc_ushort; typedef unsigned int
Cyc_uint; typedef unsigned int Cyc_clock_t; typedef int Cyc_time_t; struct Cyc_timespec{
int tv_sec; int tv_nsec; } ; struct Cyc_itimerspec{ struct Cyc_timespec
it_interval; struct Cyc_timespec it_value; } ; typedef int Cyc_daddr_t; typedef
char* Cyc_caddr_t; typedef unsigned int Cyc_ino_t; typedef unsigned int Cyc_vm_offset_t;
typedef unsigned int Cyc_vm_size_t; typedef char Cyc_int8_t; typedef char Cyc_u_int8_t;
typedef short Cyc_int16_t; typedef unsigned short Cyc_u_int16_t; typedef int Cyc_int32_t;
typedef unsigned int Cyc_u_int32_t; typedef long long Cyc_int64_t; typedef
unsigned long long Cyc_u_int64_t; typedef int Cyc_register_t; typedef short Cyc_dev_t;
typedef int Cyc_off_t; typedef unsigned short Cyc_uid_t; typedef unsigned short
Cyc_gid_t; typedef int Cyc_pid_t; typedef int Cyc_key_t; typedef int Cyc_ssize_t;
typedef char* Cyc_addr_t; typedef int Cyc_mode_t; typedef unsigned short Cyc_nlink_t;
typedef int Cyc_fd_mask; struct Cyc__types_fd_set{ int fds_bits[ 8u]; } ;
typedef struct Cyc__types_fd_set Cyc__types_fd_set; typedef char* Cyc_Cstring;
typedef struct _tagged_string Cyc_string; typedef struct _tagged_string Cyc_string_t;
typedef struct _tagged_string* Cyc_stringptr; typedef int Cyc_bool; extern void*
exit( int); extern void* abort(); struct Cyc_Core_Opt{ void* v; } ; typedef
struct Cyc_Core_Opt* Cyc_Core_opt_t; extern char Cyc_Core_InvalidArg[ 15u];
struct Cyc_Core_InvalidArg_struct{ char* tag; struct _tagged_string f1; } ;
extern char Cyc_Core_Failure[ 12u]; struct Cyc_Core_Failure_struct{ char* tag;
struct _tagged_string f1; } ; extern char Cyc_Core_Impossible[ 15u]; struct Cyc_Core_Impossible_struct{
char* tag; struct _tagged_string f1; } ; extern char Cyc_Core_Not_found[ 14u];
extern char Cyc_Core_Unreachable[ 16u]; struct Cyc_Core_Unreachable_struct{ char*
tag; struct _tagged_string f1; } ; extern char* string_to_Cstring( struct
_tagged_string); extern char* underlying_Cstring( struct _tagged_string); extern
struct _tagged_string Cstring_to_string( char*); extern int system( char*);
struct Cyc_Stdio___sFILE; typedef struct Cyc_Stdio___sFILE Cyc_Stdio_FILE;
extern struct Cyc_Stdio___sFILE* Cyc_Stdio_stderr; typedef int Cyc_Stdio_fpos_t;
extern char Cyc_Stdio_FileOpenError[ 18u]; struct Cyc_Stdio_FileOpenError_struct{
char* tag; struct _tagged_string f1; } ; extern char Cyc_Stdio_FileCloseError[
19u]; extern char Cyc_Lexing_Error[ 10u]; struct Cyc_Lexing_Error_struct{ char*
tag; struct _tagged_string f1; } ; struct Cyc_Lexing_lexbuf{ void(* refill_buff)(
struct Cyc_Lexing_lexbuf*); void* refill_state; struct _tagged_string lex_buffer;
int lex_buffer_len; int lex_abs_pos; int lex_start_pos; int lex_curr_pos; int
lex_last_pos; int lex_last_action; int lex_eof_reached; } ; typedef struct Cyc_Lexing_lexbuf*
Cyc_Lexing_Lexbuf; struct Cyc_Lexing_function_lexbuf_state{ int(* read_fun)(
struct _tagged_string, int, void*); void* read_fun_state; } ; typedef struct Cyc_Lexing_function_lexbuf_state*
Cyc_Lexing_Function_lexbuf_state; struct _tagged_ptr0{ int* curr; int* base; int*
last_plus_one; } ; struct Cyc_Lexing_lex_tables{ struct _tagged_ptr0 lex_base;
struct _tagged_ptr0 lex_backtrk; struct _tagged_ptr0 lex_default; struct
_tagged_ptr0 lex_trans; struct _tagged_ptr0 lex_check; } ; typedef struct Cyc_Lexing_lex_tables*
Cyc_Lexing_LexTables; extern struct Cyc_Lexing_lexbuf* Cyc_Lexing_from_file(
struct Cyc_Stdio___sFILE*); struct Cyc_List_List{ void* hd; struct Cyc_List_List*
tl; } ; typedef struct Cyc_List_List* Cyc_List_glist_t; typedef struct Cyc_List_List*
Cyc_List_list_t; typedef struct Cyc_List_List* Cyc_List_List_t; extern char Cyc_List_List_empty[
15u]; extern struct Cyc_List_List* Cyc_List_map( void*(* f)( void*), struct Cyc_List_List*
x); extern struct Cyc_List_List* Cyc_List_map_c( void*(* f)( void*, void*), void*
env, struct Cyc_List_List* x); extern char Cyc_List_List_mismatch[ 18u]; extern
void Cyc_List_iter( void(* f)( void*), struct Cyc_List_List* x); extern void Cyc_List_iter_c(
void(* f)( void*, void*), void* env, struct Cyc_List_List* x); extern void* Cyc_List_fold_right(
void*(* f)( void*, void*), struct Cyc_List_List* x, void* accum); extern struct
Cyc_List_List* Cyc_List_imp_rev( struct Cyc_List_List* x); extern struct Cyc_List_List*
Cyc_List_append( struct Cyc_List_List* x, struct Cyc_List_List* y); extern
struct Cyc_List_List* Cyc_List_imp_append( struct Cyc_List_List* x, struct Cyc_List_List*
y); extern struct Cyc_List_List* Cyc_List_flatten( struct Cyc_List_List* x);
extern char Cyc_List_Nth[ 8u]; extern struct Cyc_List_List* Cyc_List_zip( struct
Cyc_List_List* x, struct Cyc_List_List* y); struct _tuple0{ struct Cyc_List_List*
f1; struct Cyc_List_List* f2; } ; extern struct _tuple0 Cyc_List_split( struct
Cyc_List_List* x); extern unsigned int Cyc_String_strlen( struct _tagged_string
s); extern int Cyc_String_strcmp( struct _tagged_string s1, struct
_tagged_string s2); extern int Cyc_String_zstrcmp( struct _tagged_string, struct
_tagged_string); extern int Cyc_String_zstrptrcmp( struct _tagged_string*,
struct _tagged_string*); extern struct _tagged_string Cyc_String_strcat( struct
_tagged_string dest, struct _tagged_string src); extern struct _tagged_string
Cyc_String_strcpy( struct _tagged_string dest, struct _tagged_string src);
struct Cyc_Set_Set; typedef struct Cyc_Set_Set* Cyc_Set_gset_t; typedef struct
Cyc_Set_Set* Cyc_Set_hset_t; typedef struct Cyc_Set_Set* Cyc_Set_set_t; extern
char Cyc_Set_Absent[ 11u]; struct Cyc_Lineno_Pos{ struct _tagged_string
logical_file; struct _tagged_string line; int line_no; int col; } ; typedef
struct Cyc_Lineno_Pos* Cyc_Lineno_pos_t; extern char Cyc_Position_Exit[ 9u];
struct Cyc_Position_Segment; typedef struct Cyc_Position_Segment* Cyc_Position_seg_t;
extern struct Cyc_Position_Segment* Cyc_Position_segment_of_abs( int, int);
extern struct Cyc_Position_Segment* Cyc_Position_segment_join( struct Cyc_Position_Segment*,
struct Cyc_Position_Segment*); extern struct _tagged_string Cyc_Position_string_of_segment(
struct Cyc_Position_Segment*); static const int Cyc_Position_Lex= 0; static
const int Cyc_Position_Parse= 1; static const int Cyc_Position_Elab= 2; typedef
void* Cyc_Position_error_kind_t; struct Cyc_Position_Error{ struct
_tagged_string source; struct Cyc_Position_Segment* seg; void* kind; struct
_tagged_string desc; } ; typedef struct Cyc_Position_Error* Cyc_Position_error_t;
extern struct Cyc_Position_Error* Cyc_Position_mk_err_parse( struct Cyc_Position_Segment*,
struct _tagged_string); extern char Cyc_Position_Nocontext[ 14u]; extern void
Cyc_Position_post_error( struct Cyc_Position_Error*); typedef struct
_tagged_string* Cyc_Absyn_field_name_t; typedef struct _tagged_string* Cyc_Absyn_var_t;
typedef struct _tagged_string* Cyc_Absyn_tvarname_t; typedef void* Cyc_Absyn_nmspace_t;
struct _tuple1{ void* f1; struct _tagged_string* f2; } ; typedef struct _tuple1*
Cyc_Absyn_qvar_t; typedef struct _tuple1* Cyc_Absyn_qvar_opt_t; typedef struct
_tuple1* Cyc_Absyn_typedef_name_t; typedef struct _tuple1* Cyc_Absyn_typedef_name_opt_t;
struct Cyc_Absyn_Tvar; struct Cyc_Absyn_Tqual; struct Cyc_Absyn_Conref; struct
Cyc_Absyn_PtrInfo; struct Cyc_Absyn_FnInfo; struct Cyc_Absyn_TunionInfo; struct
Cyc_Absyn_TunionFieldInfo; struct Cyc_Absyn_Exp; struct Cyc_Absyn_Stmt; struct
Cyc_Absyn_Pat; struct Cyc_Absyn_Switch_clause; struct Cyc_Absyn_Fndecl; struct
Cyc_Absyn_Structdecl; struct Cyc_Absyn_Uniondecl; struct Cyc_Absyn_Tuniondecl;
struct Cyc_Absyn_Tunionfield; struct Cyc_Absyn_Enumfield; struct Cyc_Absyn_Enumdecl;
struct Cyc_Absyn_Typedefdecl; struct Cyc_Absyn_Vardecl; struct Cyc_Absyn_Decl;
struct Cyc_Absyn_Structfield; typedef void* Cyc_Absyn_scope_t; typedef struct
Cyc_Absyn_Tqual Cyc_Absyn_tqual_t; typedef void* Cyc_Absyn_size_of_t; typedef
void* Cyc_Absyn_kind_t; typedef struct Cyc_Absyn_Tvar* Cyc_Absyn_tvar_t; typedef
void* Cyc_Absyn_sign_t; typedef struct Cyc_Absyn_Conref* Cyc_Absyn_conref_t;
typedef void* Cyc_Absyn_constraint_t; typedef void* Cyc_Absyn_bounds_t; typedef
struct Cyc_Absyn_PtrInfo Cyc_Absyn_ptr_info_t; typedef struct Cyc_Absyn_FnInfo
Cyc_Absyn_fn_info_t; typedef struct Cyc_Absyn_TunionInfo Cyc_Absyn_tunion_info_t;
typedef struct Cyc_Absyn_TunionFieldInfo Cyc_Absyn_tunion_field_info_t; typedef
void* Cyc_Absyn_type_t; typedef void* Cyc_Absyn_rgntype_t; typedef void* Cyc_Absyn_funcparams_t;
typedef void* Cyc_Absyn_type_modifier_t; typedef void* Cyc_Absyn_cnst_t; typedef
void* Cyc_Absyn_primop_t; typedef void* Cyc_Absyn_incrementor_t; typedef void*
Cyc_Absyn_raw_exp_t; typedef struct Cyc_Absyn_Exp* Cyc_Absyn_exp_t; typedef
struct Cyc_Absyn_Exp* Cyc_Absyn_exp_opt_t; typedef void* Cyc_Absyn_raw_stmt_t;
typedef struct Cyc_Absyn_Stmt* Cyc_Absyn_stmt_t; typedef struct Cyc_Absyn_Stmt*
Cyc_Absyn_stmt_opt_t; typedef void* Cyc_Absyn_raw_pat_t; typedef struct Cyc_Absyn_Pat*
Cyc_Absyn_pat_t; typedef void* Cyc_Absyn_binding_t; typedef struct Cyc_Absyn_Switch_clause*
Cyc_Absyn_switch_clause_t; typedef struct Cyc_Absyn_Fndecl* Cyc_Absyn_fndecl_t;
typedef struct Cyc_Absyn_Structdecl* Cyc_Absyn_structdecl_t; typedef struct Cyc_Absyn_Uniondecl*
Cyc_Absyn_uniondecl_t; typedef struct Cyc_Absyn_Tunionfield* Cyc_Absyn_tunionfield_t;
typedef struct Cyc_Absyn_Tuniondecl* Cyc_Absyn_tuniondecl_t; typedef struct Cyc_Absyn_Typedefdecl*
Cyc_Absyn_typedefdecl_t; typedef struct Cyc_Absyn_Enumfield* Cyc_Absyn_enumfield_t;
typedef struct Cyc_Absyn_Enumdecl* Cyc_Absyn_enumdecl_t; typedef struct Cyc_Absyn_Vardecl*
Cyc_Absyn_vardecl_t; typedef void* Cyc_Absyn_raw_decl_t; typedef struct Cyc_Absyn_Decl*
Cyc_Absyn_decl_t; typedef void* Cyc_Absyn_designator_t; typedef void* Cyc_Absyn_stmt_annot_t;
typedef void* Cyc_Absyn_attribute_t; typedef struct Cyc_List_List* Cyc_Absyn_attributes_t;
typedef struct Cyc_Absyn_Structfield* Cyc_Absyn_structfield_t; static const int
Cyc_Absyn_Loc_n= 0; static const int Cyc_Absyn_Rel_n= 0; struct Cyc_Absyn_Rel_n_struct{
int tag; struct Cyc_List_List* f1; } ; static const int Cyc_Absyn_Abs_n= 1;
struct Cyc_Absyn_Abs_n_struct{ int tag; struct Cyc_List_List* f1; } ; static
const int Cyc_Absyn_Static= 0; static const int Cyc_Absyn_Abstract= 1; static
const int Cyc_Absyn_Public= 2; static const int Cyc_Absyn_Extern= 3; static
const int Cyc_Absyn_ExternC= 4; struct Cyc_Absyn_Tqual{ int q_const: 1; int
q_volatile: 1; int q_restrict: 1; } ; static const int Cyc_Absyn_B1= 0; static
const int Cyc_Absyn_B2= 1; static const int Cyc_Absyn_B4= 2; static const int
Cyc_Absyn_B8= 3; static const int Cyc_Absyn_AnyKind= 0; static const int Cyc_Absyn_MemKind=
1; static const int Cyc_Absyn_BoxKind= 2; static const int Cyc_Absyn_RgnKind= 3;
static const int Cyc_Absyn_EffKind= 4; static const int Cyc_Absyn_Signed= 0;
static const int Cyc_Absyn_Unsigned= 1; struct Cyc_Absyn_Conref{ void* v; } ;
static const int Cyc_Absyn_Eq_constr= 0; struct Cyc_Absyn_Eq_constr_struct{ int
tag; void* f1; } ; static const int Cyc_Absyn_Forward_constr= 1; struct Cyc_Absyn_Forward_constr_struct{
int tag; struct Cyc_Absyn_Conref* f1; } ; static const int Cyc_Absyn_No_constr=
0; struct Cyc_Absyn_Tvar{ struct _tagged_string* name; struct Cyc_Absyn_Conref*
kind; } ; static const int Cyc_Absyn_Unknown_b= 0; static const int Cyc_Absyn_Upper_b=
0; struct Cyc_Absyn_Upper_b_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
struct Cyc_Absyn_PtrInfo{ void* elt_typ; void* rgn_typ; struct Cyc_Absyn_Conref*
nullable; struct Cyc_Absyn_Tqual tq; struct Cyc_Absyn_Conref* bounds; } ; struct
Cyc_Absyn_FnInfo{ struct Cyc_List_List* tvars; struct Cyc_Core_Opt* effect; void*
ret_typ; struct Cyc_List_List* args; int varargs; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_UnknownTunionInfo{ struct _tuple1* name; int
is_xtunion; } ; static const int Cyc_Absyn_UnknownTunion= 0; struct Cyc_Absyn_UnknownTunion_struct{
int tag; struct Cyc_Absyn_UnknownTunionInfo f1; } ; static const int Cyc_Absyn_KnownTunion=
1; struct Cyc_Absyn_KnownTunion_struct{ int tag; struct Cyc_Absyn_Tuniondecl* f1;
} ; struct Cyc_Absyn_TunionInfo{ void* tunion_info; struct Cyc_List_List* targs;
void* rgn; } ; struct Cyc_Absyn_UnknownTunionFieldInfo{ struct _tuple1*
tunion_name; struct _tuple1* field_name; int is_xtunion; } ; static const int
Cyc_Absyn_UnknownTunionfield= 0; struct Cyc_Absyn_UnknownTunionfield_struct{ int
tag; struct Cyc_Absyn_UnknownTunionFieldInfo f1; } ; static const int Cyc_Absyn_KnownTunionfield=
1; struct Cyc_Absyn_KnownTunionfield_struct{ int tag; struct Cyc_Absyn_Tuniondecl*
f1; struct Cyc_Absyn_Tunionfield* f2; } ; struct Cyc_Absyn_TunionFieldInfo{ void*
field_info; struct Cyc_List_List* targs; } ; static const int Cyc_Absyn_VoidType=
0; static const int Cyc_Absyn_Evar= 0; struct Cyc_Absyn_Evar_struct{ int tag;
void* f1; struct Cyc_Core_Opt* f2; int f3; } ; static const int Cyc_Absyn_VarType=
1; struct Cyc_Absyn_VarType_struct{ int tag; struct Cyc_Absyn_Tvar* f1; } ;
static const int Cyc_Absyn_TunionType= 2; struct Cyc_Absyn_TunionType_struct{
int tag; struct Cyc_Absyn_TunionInfo f1; } ; static const int Cyc_Absyn_TunionFieldType=
3; struct Cyc_Absyn_TunionFieldType_struct{ int tag; struct Cyc_Absyn_TunionFieldInfo
f1; } ; static const int Cyc_Absyn_PointerType= 4; struct Cyc_Absyn_PointerType_struct{
int tag; struct Cyc_Absyn_PtrInfo f1; } ; static const int Cyc_Absyn_IntType= 5;
struct Cyc_Absyn_IntType_struct{ int tag; void* f1; void* f2; } ; static const
int Cyc_Absyn_FloatType= 1; static const int Cyc_Absyn_DoubleType= 2; static
const int Cyc_Absyn_ArrayType= 6; struct Cyc_Absyn_ArrayType_struct{ int tag;
void* f1; struct Cyc_Absyn_Tqual f2; struct Cyc_Absyn_Exp* f3; } ; static const
int Cyc_Absyn_FnType= 7; struct Cyc_Absyn_FnType_struct{ int tag; struct Cyc_Absyn_FnInfo
f1; } ; static const int Cyc_Absyn_TupleType= 8; struct Cyc_Absyn_TupleType_struct{
int tag; struct Cyc_List_List* f1; } ; static const int Cyc_Absyn_StructType= 9;
struct Cyc_Absyn_StructType_struct{ int tag; struct _tuple1* f1; struct Cyc_List_List*
f2; struct Cyc_Absyn_Structdecl** f3; } ; static const int Cyc_Absyn_UnionType=
10; struct Cyc_Absyn_UnionType_struct{ int tag; struct _tuple1* f1; struct Cyc_List_List*
f2; struct Cyc_Absyn_Uniondecl** f3; } ; static const int Cyc_Absyn_AnonStructType=
11; struct Cyc_Absyn_AnonStructType_struct{ int tag; struct Cyc_List_List* f1; }
; static const int Cyc_Absyn_AnonUnionType= 12; struct Cyc_Absyn_AnonUnionType_struct{
int tag; struct Cyc_List_List* f1; } ; static const int Cyc_Absyn_EnumType= 13;
struct Cyc_Absyn_EnumType_struct{ int tag; struct _tuple1* f1; struct Cyc_Absyn_Enumdecl*
f2; } ; static const int Cyc_Absyn_RgnHandleType= 14; struct Cyc_Absyn_RgnHandleType_struct{
int tag; void* f1; } ; static const int Cyc_Absyn_TypedefType= 15; struct Cyc_Absyn_TypedefType_struct{
int tag; struct _tuple1* f1; struct Cyc_List_List* f2; struct Cyc_Core_Opt* f3;
} ; static const int Cyc_Absyn_HeapRgn= 3; static const int Cyc_Absyn_AccessEff=
16; struct Cyc_Absyn_AccessEff_struct{ int tag; void* f1; } ; static const int
Cyc_Absyn_JoinEff= 17; struct Cyc_Absyn_JoinEff_struct{ int tag; struct Cyc_List_List*
f1; } ; static const int Cyc_Absyn_NoTypes= 0; struct Cyc_Absyn_NoTypes_struct{
int tag; struct Cyc_List_List* f1; struct Cyc_Position_Segment* f2; } ; static
const int Cyc_Absyn_WithTypes= 1; struct Cyc_Absyn_WithTypes_struct{ int tag;
struct Cyc_List_List* f1; int f2; struct Cyc_Core_Opt* f3; } ; static const int
Cyc_Absyn_NonNullable_ps= 0; struct Cyc_Absyn_NonNullable_ps_struct{ int tag;
struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_Nullable_ps= 1; struct
Cyc_Absyn_Nullable_ps_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ; static
const int Cyc_Absyn_TaggedArray_ps= 0; static const int Cyc_Absyn_Regparm_att= 0;
struct Cyc_Absyn_Regparm_att_struct{ int tag; int f1; } ; static const int Cyc_Absyn_Stdcall_att=
0; static const int Cyc_Absyn_Cdecl_att= 1; static const int Cyc_Absyn_Noreturn_att=
2; static const int Cyc_Absyn_Const_att= 3; static const int Cyc_Absyn_Aligned_att=
1; struct Cyc_Absyn_Aligned_att_struct{ int tag; int f1; } ; static const int
Cyc_Absyn_Packed_att= 4; static const int Cyc_Absyn_Section_att= 2; struct Cyc_Absyn_Section_att_struct{
int tag; struct _tagged_string f1; } ; static const int Cyc_Absyn_Nocommon_att=
5; static const int Cyc_Absyn_Shared_att= 6; static const int Cyc_Absyn_Unused_att=
7; static const int Cyc_Absyn_Weak_att= 8; static const int Cyc_Absyn_Dllimport_att=
9; static const int Cyc_Absyn_Dllexport_att= 10; static const int Cyc_Absyn_No_instrument_function_att=
11; static const int Cyc_Absyn_Constructor_att= 12; static const int Cyc_Absyn_Destructor_att=
13; static const int Cyc_Absyn_No_check_memory_usage_att= 14; static const int
Cyc_Absyn_Carray_mod= 0; static const int Cyc_Absyn_ConstArray_mod= 0; struct
Cyc_Absyn_ConstArray_mod_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ; static
const int Cyc_Absyn_Pointer_mod= 1; struct Cyc_Absyn_Pointer_mod_struct{ int tag;
void* f1; void* f2; struct Cyc_Absyn_Tqual f3; } ; static const int Cyc_Absyn_Function_mod=
2; struct Cyc_Absyn_Function_mod_struct{ int tag; void* f1; } ; static const int
Cyc_Absyn_TypeParams_mod= 3; struct Cyc_Absyn_TypeParams_mod_struct{ int tag;
struct Cyc_List_List* f1; struct Cyc_Position_Segment* f2; int f3; } ; static
const int Cyc_Absyn_Attributes_mod= 4; struct Cyc_Absyn_Attributes_mod_struct{
int tag; struct Cyc_Position_Segment* f1; struct Cyc_List_List* f2; } ; static
const int Cyc_Absyn_Char_c= 0; struct Cyc_Absyn_Char_c_struct{ int tag; void* f1;
char f2; } ; static const int Cyc_Absyn_Short_c= 1; struct Cyc_Absyn_Short_c_struct{
int tag; void* f1; short f2; } ; static const int Cyc_Absyn_Int_c= 2; struct Cyc_Absyn_Int_c_struct{
int tag; void* f1; int f2; } ; static const int Cyc_Absyn_LongLong_c= 3; struct
Cyc_Absyn_LongLong_c_struct{ int tag; void* f1; long long f2; } ; static const
int Cyc_Absyn_Float_c= 4; struct Cyc_Absyn_Float_c_struct{ int tag; struct
_tagged_string f1; } ; static const int Cyc_Absyn_String_c= 5; struct Cyc_Absyn_String_c_struct{
int tag; struct _tagged_string f1; } ; static const int Cyc_Absyn_Null_c= 0;
static const int Cyc_Absyn_Plus= 0; static const int Cyc_Absyn_Times= 1; static
const int Cyc_Absyn_Minus= 2; static const int Cyc_Absyn_Div= 3; static const
int Cyc_Absyn_Mod= 4; static const int Cyc_Absyn_Eq= 5; static const int Cyc_Absyn_Neq=
6; static const int Cyc_Absyn_Gt= 7; static const int Cyc_Absyn_Lt= 8; static
const int Cyc_Absyn_Gte= 9; static const int Cyc_Absyn_Lte= 10; static const int
Cyc_Absyn_Not= 11; static const int Cyc_Absyn_Bitnot= 12; static const int Cyc_Absyn_Bitand=
13; static const int Cyc_Absyn_Bitor= 14; static const int Cyc_Absyn_Bitxor= 15;
static const int Cyc_Absyn_Bitlshift= 16; static const int Cyc_Absyn_Bitlrshift=
17; static const int Cyc_Absyn_Bitarshift= 18; static const int Cyc_Absyn_Size=
19; static const int Cyc_Absyn_Printf= 20; static const int Cyc_Absyn_Fprintf=
21; static const int Cyc_Absyn_Xprintf= 22; static const int Cyc_Absyn_Scanf= 23;
static const int Cyc_Absyn_Fscanf= 24; static const int Cyc_Absyn_Sscanf= 25;
static const int Cyc_Absyn_PreInc= 0; static const int Cyc_Absyn_PostInc= 1;
static const int Cyc_Absyn_PreDec= 2; static const int Cyc_Absyn_PostDec= 3;
static const int Cyc_Absyn_Const_e= 0; struct Cyc_Absyn_Const_e_struct{ int tag;
void* f1; } ; static const int Cyc_Absyn_Var_e= 1; struct Cyc_Absyn_Var_e_struct{
int tag; struct _tuple1* f1; void* f2; } ; static const int Cyc_Absyn_UnknownId_e=
2; struct Cyc_Absyn_UnknownId_e_struct{ int tag; struct _tuple1* f1; } ; static
const int Cyc_Absyn_Primop_e= 3; struct Cyc_Absyn_Primop_e_struct{ int tag; void*
f1; struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_AssignOp_e= 4;
struct Cyc_Absyn_AssignOp_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; struct
Cyc_Core_Opt* f2; struct Cyc_Absyn_Exp* f3; } ; static const int Cyc_Absyn_Increment_e=
5; struct Cyc_Absyn_Increment_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; void*
f2; } ; static const int Cyc_Absyn_Conditional_e= 6; struct Cyc_Absyn_Conditional_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Exp* f2; struct Cyc_Absyn_Exp*
f3; } ; static const int Cyc_Absyn_SeqExp_e= 7; struct Cyc_Absyn_SeqExp_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Exp* f2; } ; static const
int Cyc_Absyn_UnknownCall_e= 8; struct Cyc_Absyn_UnknownCall_e_struct{ int tag;
struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_FnCall_e=
9; struct Cyc_Absyn_FnCall_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; struct
Cyc_List_List* f2; } ; static const int Cyc_Absyn_Throw_e= 10; struct Cyc_Absyn_Throw_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_NoInstantiate_e=
11; struct Cyc_Absyn_NoInstantiate_e_struct{ int tag; struct Cyc_Absyn_Exp* f1;
} ; static const int Cyc_Absyn_Instantiate_e= 12; struct Cyc_Absyn_Instantiate_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_Cast_e= 13; struct Cyc_Absyn_Cast_e_struct{ int tag; void* f1;
struct Cyc_Absyn_Exp* f2; } ; static const int Cyc_Absyn_Address_e= 14; struct
Cyc_Absyn_Address_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ; static const
int Cyc_Absyn_New_e= 15; struct Cyc_Absyn_New_e_struct{ int tag; struct Cyc_Absyn_Exp*
f1; struct Cyc_Absyn_Exp* f2; } ; static const int Cyc_Absyn_Sizeoftyp_e= 16;
struct Cyc_Absyn_Sizeoftyp_e_struct{ int tag; void* f1; } ; static const int Cyc_Absyn_Sizeofexp_e=
17; struct Cyc_Absyn_Sizeofexp_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
static const int Cyc_Absyn_Deref_e= 18; struct Cyc_Absyn_Deref_e_struct{ int tag;
struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_StructMember_e= 19;
struct Cyc_Absyn_StructMember_e_struct{ int tag; struct Cyc_Absyn_Exp* f1;
struct _tagged_string* f2; } ; static const int Cyc_Absyn_StructArrow_e= 20;
struct Cyc_Absyn_StructArrow_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; struct
_tagged_string* f2; } ; static const int Cyc_Absyn_Subscript_e= 21; struct Cyc_Absyn_Subscript_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Exp* f2; } ; static const
int Cyc_Absyn_Tuple_e= 22; struct Cyc_Absyn_Tuple_e_struct{ int tag; struct Cyc_List_List*
f1; } ; static const int Cyc_Absyn_CompoundLit_e= 23; struct _tuple2{ struct Cyc_Core_Opt*
f1; struct Cyc_Absyn_Tqual f2; void* f3; } ; struct Cyc_Absyn_CompoundLit_e_struct{
int tag; struct _tuple2* f1; struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_Array_e=
24; struct Cyc_Absyn_Array_e_struct{ int tag; struct Cyc_List_List* f1; } ;
static const int Cyc_Absyn_Comprehension_e= 25; struct Cyc_Absyn_Comprehension_e_struct{
int tag; struct Cyc_Absyn_Vardecl* f1; struct Cyc_Absyn_Exp* f2; struct Cyc_Absyn_Exp*
f3; } ; static const int Cyc_Absyn_Struct_e= 26; struct Cyc_Absyn_Struct_e_struct{
int tag; struct _tuple1* f1; struct Cyc_Core_Opt* f2; struct Cyc_List_List* f3;
struct Cyc_Absyn_Structdecl* f4; } ; static const int Cyc_Absyn_AnonStruct_e= 27;
struct Cyc_Absyn_AnonStruct_e_struct{ int tag; void* f1; struct Cyc_List_List*
f2; } ; static const int Cyc_Absyn_Tunion_e= 28; struct Cyc_Absyn_Tunion_e_struct{
int tag; struct Cyc_Core_Opt* f1; struct Cyc_Core_Opt* f2; struct Cyc_List_List*
f3; struct Cyc_Absyn_Tuniondecl* f4; struct Cyc_Absyn_Tunionfield* f5; } ;
static const int Cyc_Absyn_Enum_e= 29; struct Cyc_Absyn_Enum_e_struct{ int tag;
struct _tuple1* f1; struct Cyc_Absyn_Enumdecl* f2; struct Cyc_Absyn_Enumfield*
f3; } ; static const int Cyc_Absyn_Malloc_e= 30; struct Cyc_Absyn_Malloc_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; void* f2; } ; static const int Cyc_Absyn_UnresolvedMem_e=
31; struct Cyc_Absyn_UnresolvedMem_e_struct{ int tag; struct Cyc_Core_Opt* f1;
struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_StmtExp_e= 32; struct
Cyc_Absyn_StmtExp_e_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; static const
int Cyc_Absyn_Codegen_e= 33; struct Cyc_Absyn_Codegen_e_struct{ int tag; struct
Cyc_Absyn_Fndecl* f1; } ; static const int Cyc_Absyn_Fill_e= 34; struct Cyc_Absyn_Fill_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; struct Cyc_Absyn_Exp{ struct Cyc_Core_Opt*
topt; void* r; struct Cyc_Position_Segment* loc; } ; static const int Cyc_Absyn_Skip_s=
0; static const int Cyc_Absyn_Exp_s= 0; struct Cyc_Absyn_Exp_s_struct{ int tag;
struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_Seq_s= 1; struct Cyc_Absyn_Seq_s_struct{
int tag; struct Cyc_Absyn_Stmt* f1; struct Cyc_Absyn_Stmt* f2; } ; static const
int Cyc_Absyn_Return_s= 2; struct Cyc_Absyn_Return_s_struct{ int tag; struct Cyc_Absyn_Exp*
f1; } ; static const int Cyc_Absyn_IfThenElse_s= 3; struct Cyc_Absyn_IfThenElse_s_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Absyn_Stmt* f2; struct Cyc_Absyn_Stmt*
f3; } ; static const int Cyc_Absyn_While_s= 4; struct _tuple3{ struct Cyc_Absyn_Exp*
f1; struct Cyc_Absyn_Stmt* f2; } ; struct Cyc_Absyn_While_s_struct{ int tag;
struct _tuple3 f1; struct Cyc_Absyn_Stmt* f2; } ; static const int Cyc_Absyn_Break_s=
5; struct Cyc_Absyn_Break_s_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ;
static const int Cyc_Absyn_Continue_s= 6; struct Cyc_Absyn_Continue_s_struct{
int tag; struct Cyc_Absyn_Stmt* f1; } ; static const int Cyc_Absyn_Goto_s= 7;
struct Cyc_Absyn_Goto_s_struct{ int tag; struct _tagged_string* f1; struct Cyc_Absyn_Stmt*
f2; } ; static const int Cyc_Absyn_For_s= 8; struct Cyc_Absyn_For_s_struct{ int
tag; struct Cyc_Absyn_Exp* f1; struct _tuple3 f2; struct _tuple3 f3; struct Cyc_Absyn_Stmt*
f4; } ; static const int Cyc_Absyn_Switch_s= 9; struct Cyc_Absyn_Switch_s_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_Fallthru_s= 10; struct Cyc_Absyn_Fallthru_s_struct{ int tag;
struct Cyc_List_List* f1; struct Cyc_Absyn_Switch_clause** f2; } ; static const
int Cyc_Absyn_Decl_s= 11; struct Cyc_Absyn_Decl_s_struct{ int tag; struct Cyc_Absyn_Decl*
f1; struct Cyc_Absyn_Stmt* f2; } ; static const int Cyc_Absyn_Cut_s= 12; struct
Cyc_Absyn_Cut_s_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; static const int
Cyc_Absyn_Splice_s= 13; struct Cyc_Absyn_Splice_s_struct{ int tag; struct Cyc_Absyn_Stmt*
f1; } ; static const int Cyc_Absyn_Label_s= 14; struct Cyc_Absyn_Label_s_struct{
int tag; struct _tagged_string* f1; struct Cyc_Absyn_Stmt* f2; } ; static const
int Cyc_Absyn_Do_s= 15; struct Cyc_Absyn_Do_s_struct{ int tag; struct Cyc_Absyn_Stmt*
f1; struct _tuple3 f2; } ; static const int Cyc_Absyn_TryCatch_s= 16; struct Cyc_Absyn_TryCatch_s_struct{
int tag; struct Cyc_Absyn_Stmt* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_Region_s= 17; struct Cyc_Absyn_Region_s_struct{ int tag; struct
Cyc_Absyn_Tvar* f1; struct Cyc_Absyn_Vardecl* f2; struct Cyc_Absyn_Stmt* f3; } ;
struct Cyc_Absyn_Stmt{ void* r; struct Cyc_Position_Segment* loc; struct Cyc_List_List*
non_local_preds; int try_depth; void* annot; } ; static const int Cyc_Absyn_Wild_p=
0; static const int Cyc_Absyn_Var_p= 0; struct Cyc_Absyn_Var_p_struct{ int tag;
struct Cyc_Absyn_Vardecl* f1; } ; static const int Cyc_Absyn_Null_p= 1; static
const int Cyc_Absyn_Int_p= 1; struct Cyc_Absyn_Int_p_struct{ int tag; void* f1;
int f2; } ; static const int Cyc_Absyn_Char_p= 2; struct Cyc_Absyn_Char_p_struct{
int tag; char f1; } ; static const int Cyc_Absyn_Float_p= 3; struct Cyc_Absyn_Float_p_struct{
int tag; struct _tagged_string f1; } ; static const int Cyc_Absyn_Tuple_p= 4;
struct Cyc_Absyn_Tuple_p_struct{ int tag; struct Cyc_List_List* f1; } ; static
const int Cyc_Absyn_Pointer_p= 5; struct Cyc_Absyn_Pointer_p_struct{ int tag;
struct Cyc_Absyn_Pat* f1; } ; static const int Cyc_Absyn_Reference_p= 6; struct
Cyc_Absyn_Reference_p_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ; static
const int Cyc_Absyn_Struct_p= 7; struct Cyc_Absyn_Struct_p_struct{ int tag;
struct Cyc_Absyn_Structdecl* f1; struct Cyc_Core_Opt* f2; struct Cyc_List_List*
f3; struct Cyc_List_List* f4; } ; static const int Cyc_Absyn_Tunion_p= 8; struct
Cyc_Absyn_Tunion_p_struct{ int tag; struct Cyc_Absyn_Tuniondecl* f1; struct Cyc_Absyn_Tunionfield*
f2; struct Cyc_List_List* f3; struct Cyc_List_List* f4; } ; static const int Cyc_Absyn_Enum_p=
9; struct Cyc_Absyn_Enum_p_struct{ int tag; struct Cyc_Absyn_Enumdecl* f1;
struct Cyc_Absyn_Enumfield* f2; } ; static const int Cyc_Absyn_UnknownId_p= 10;
struct Cyc_Absyn_UnknownId_p_struct{ int tag; struct _tuple1* f1; } ; static
const int Cyc_Absyn_UnknownCall_p= 11; struct Cyc_Absyn_UnknownCall_p_struct{
int tag; struct _tuple1* f1; struct Cyc_List_List* f2; struct Cyc_List_List* f3;
} ; static const int Cyc_Absyn_UnknownFields_p= 12; struct Cyc_Absyn_UnknownFields_p_struct{
int tag; struct _tuple1* f1; struct Cyc_List_List* f2; struct Cyc_List_List* f3;
} ; struct Cyc_Absyn_Pat{ void* r; struct Cyc_Core_Opt* topt; struct Cyc_Position_Segment*
loc; } ; struct Cyc_Absyn_Switch_clause{ struct Cyc_Absyn_Pat* pattern; struct
Cyc_Core_Opt* pat_vars; struct Cyc_Absyn_Exp* where_clause; struct Cyc_Absyn_Stmt*
body; struct Cyc_Position_Segment* loc; } ; static const int Cyc_Absyn_Unresolved_b=
0; static const int Cyc_Absyn_Global_b= 0; struct Cyc_Absyn_Global_b_struct{ int
tag; struct Cyc_Absyn_Vardecl* f1; } ; static const int Cyc_Absyn_Funname_b= 1;
struct Cyc_Absyn_Funname_b_struct{ int tag; struct Cyc_Absyn_Fndecl* f1; } ;
static const int Cyc_Absyn_Param_b= 2; struct Cyc_Absyn_Param_b_struct{ int tag;
struct Cyc_Absyn_Vardecl* f1; } ; static const int Cyc_Absyn_Local_b= 3; struct
Cyc_Absyn_Local_b_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ; static
const int Cyc_Absyn_Pat_b= 4; struct Cyc_Absyn_Pat_b_struct{ int tag; struct Cyc_Absyn_Vardecl*
f1; } ; struct Cyc_Absyn_Vardecl{ void* sc; struct _tuple1* name; struct Cyc_Absyn_Tqual
tq; void* type; struct Cyc_Absyn_Exp* initializer; struct Cyc_Core_Opt* rgn;
struct Cyc_List_List* attributes; } ; struct Cyc_Absyn_Fndecl{ void* sc; int
is_inline; struct _tuple1* name; struct Cyc_List_List* tvs; struct Cyc_Core_Opt*
effect; void* ret_type; struct Cyc_List_List* args; int varargs; struct Cyc_Absyn_Stmt*
body; struct Cyc_Core_Opt* cached_typ; struct Cyc_Core_Opt* param_vardecls;
struct Cyc_List_List* attributes; } ; struct Cyc_Absyn_Structfield{ struct
_tagged_string* name; struct Cyc_Absyn_Tqual tq; void* type; struct Cyc_Core_Opt*
width; struct Cyc_List_List* attributes; } ; struct Cyc_Absyn_Structdecl{ void*
sc; struct Cyc_Core_Opt* name; struct Cyc_List_List* tvs; struct Cyc_Core_Opt*
fields; struct Cyc_List_List* attributes; } ; struct Cyc_Absyn_Uniondecl{ void*
sc; struct Cyc_Core_Opt* name; struct Cyc_List_List* tvs; struct Cyc_Core_Opt*
fields; struct Cyc_List_List* attributes; } ; struct Cyc_Absyn_Tunionfield{
struct _tuple1* name; struct Cyc_List_List* tvs; struct Cyc_List_List* typs;
struct Cyc_Position_Segment* loc; } ; struct Cyc_Absyn_Tuniondecl{ void* sc;
struct _tuple1* name; struct Cyc_List_List* tvs; struct Cyc_Core_Opt* fields;
int is_xtunion; } ; struct Cyc_Absyn_Enumfield{ struct _tuple1* name; struct Cyc_Absyn_Exp*
tag; struct Cyc_Position_Segment* loc; } ; struct Cyc_Absyn_Enumdecl{ void* sc;
struct _tuple1* name; struct Cyc_List_List* fields; } ; struct Cyc_Absyn_Typedefdecl{
struct _tuple1* name; struct Cyc_List_List* tvs; void* defn; } ; static const
int Cyc_Absyn_Var_d= 0; struct Cyc_Absyn_Var_d_struct{ int tag; struct Cyc_Absyn_Vardecl*
f1; } ; static const int Cyc_Absyn_Fn_d= 1; struct Cyc_Absyn_Fn_d_struct{ int
tag; struct Cyc_Absyn_Fndecl* f1; } ; static const int Cyc_Absyn_Let_d= 2;
struct Cyc_Absyn_Let_d_struct{ int tag; struct Cyc_Absyn_Pat* f1; struct Cyc_Core_Opt*
f2; struct Cyc_Core_Opt* f3; struct Cyc_Absyn_Exp* f4; int f5; } ; static const
int Cyc_Absyn_Struct_d= 3; struct Cyc_Absyn_Struct_d_struct{ int tag; struct Cyc_Absyn_Structdecl*
f1; } ; static const int Cyc_Absyn_Union_d= 4; struct Cyc_Absyn_Union_d_struct{
int tag; struct Cyc_Absyn_Uniondecl* f1; } ; static const int Cyc_Absyn_Tunion_d=
5; struct Cyc_Absyn_Tunion_d_struct{ int tag; struct Cyc_Absyn_Tuniondecl* f1; }
; static const int Cyc_Absyn_Enum_d= 6; struct Cyc_Absyn_Enum_d_struct{ int tag;
struct Cyc_Absyn_Enumdecl* f1; } ; static const int Cyc_Absyn_Typedef_d= 7;
struct Cyc_Absyn_Typedef_d_struct{ int tag; struct Cyc_Absyn_Typedefdecl* f1; }
; static const int Cyc_Absyn_Namespace_d= 8; struct Cyc_Absyn_Namespace_d_struct{
int tag; struct _tagged_string* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_Using_d= 9; struct Cyc_Absyn_Using_d_struct{ int tag; struct
_tuple1* f1; struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_ExternC_d=
10; struct Cyc_Absyn_ExternC_d_struct{ int tag; struct Cyc_List_List* f1; } ;
struct Cyc_Absyn_Decl{ void* r; struct Cyc_Position_Segment* loc; } ; static
const int Cyc_Absyn_ArrayElement= 0; struct Cyc_Absyn_ArrayElement_struct{ int
tag; struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_FieldName= 1;
struct Cyc_Absyn_FieldName_struct{ int tag; struct _tagged_string* f1; } ;
extern char Cyc_Absyn_EmptyAnnot[ 15u]; extern struct Cyc_Absyn_Tqual Cyc_Absyn_combine_tqual(
struct Cyc_Absyn_Tqual x, struct Cyc_Absyn_Tqual y); extern struct Cyc_Absyn_Tqual
Cyc_Absyn_empty_tqual(); extern struct Cyc_Absyn_Conref* Cyc_Absyn_new_conref(
void* x); extern struct Cyc_Absyn_Conref* Cyc_Absyn_empty_conref(); extern void*
Cyc_Absyn_new_evar( void*); extern void* Cyc_Absyn_uchar_t; extern void* Cyc_Absyn_uint_t;
extern void* Cyc_Absyn_sint_t; extern void* Cyc_Absyn_float_t; extern void* Cyc_Absyn_double_t;
extern void* Cyc_Absyn_starb_typ( void* t, void* rgn, struct Cyc_Absyn_Tqual tq,
void* b); extern void* Cyc_Absyn_atb_typ( void* t, void* rgn, struct Cyc_Absyn_Tqual
tq, void* b); extern void* Cyc_Absyn_tagged_typ( void* t, void* rgn, struct Cyc_Absyn_Tqual
tq); extern struct Cyc_Absyn_Exp* Cyc_Absyn_new_exp( void*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_New_exp( struct Cyc_Absyn_Exp* rgn_handle,
struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_null_exp( struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_true_exp( struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_false_exp( struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_int_exp( void*, int, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_signed_int_exp( int, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_uint_exp( unsigned int, struct Cyc_Position_Segment*); extern struct
Cyc_Absyn_Exp* Cyc_Absyn_char_exp( char c, struct Cyc_Position_Segment*); extern
struct Cyc_Absyn_Exp* Cyc_Absyn_float_exp( struct _tagged_string f, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_string_exp( struct _tagged_string s,
struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_primop_exp(
void*, struct Cyc_List_List* es, struct Cyc_Position_Segment*); extern struct
Cyc_Absyn_Exp* Cyc_Absyn_prim1_exp( void*, struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_prim2_exp( void*, struct Cyc_Absyn_Exp*,
struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_eq_exp( struct Cyc_Absyn_Exp*, struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_neq_exp( struct Cyc_Absyn_Exp*, struct
Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_gt_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_lt_exp( struct Cyc_Absyn_Exp*, struct Cyc_Absyn_Exp*,
struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_gte_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_lte_exp( struct Cyc_Absyn_Exp*, struct
Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_assignop_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Core_Opt*, struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_post_inc_exp( struct Cyc_Absyn_Exp*,
struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_post_dec_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_pre_inc_exp( struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_pre_dec_exp( struct Cyc_Absyn_Exp*,
struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_conditional_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Absyn_Exp*, struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_and_exp( struct Cyc_Absyn_Exp*, struct
Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_or_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_seq_exp( struct Cyc_Absyn_Exp*, struct
Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_unknowncall_exp(
struct Cyc_Absyn_Exp*, struct Cyc_List_List*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_throw_exp( struct Cyc_Absyn_Exp*, struct
Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_noinstantiate_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_instantiate_exp( struct Cyc_Absyn_Exp*, struct Cyc_List_List*, struct
Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_cast_exp( void*,
struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_address_exp( struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_sizeoftyp_exp( void* t, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_sizeofexp_exp( struct Cyc_Absyn_Exp* e,
struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_deref_exp(
struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_structmember_exp( struct Cyc_Absyn_Exp*, struct _tagged_string*,
struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_structarrow_exp(
struct Cyc_Absyn_Exp*, struct _tagged_string*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_subscript_exp( struct Cyc_Absyn_Exp*,
struct Cyc_Absyn_Exp*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp*
Cyc_Absyn_tuple_exp( struct Cyc_List_List*, struct Cyc_Position_Segment*);
extern struct Cyc_Absyn_Exp* Cyc_Absyn_stmt_exp( struct Cyc_Absyn_Stmt*, struct
Cyc_Position_Segment*); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_new_stmt( void*
s, struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_skip_stmt(
struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_exp_stmt(
struct Cyc_Absyn_Exp* e, struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt*
Cyc_Absyn_seq_stmt( struct Cyc_Absyn_Stmt* s1, struct Cyc_Absyn_Stmt* s2, struct
Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_return_stmt(
struct Cyc_Absyn_Exp* e, struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt*
Cyc_Absyn_ifthenelse_stmt( struct Cyc_Absyn_Exp* e, struct Cyc_Absyn_Stmt* s1,
struct Cyc_Absyn_Stmt* s2, struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt*
Cyc_Absyn_while_stmt( struct Cyc_Absyn_Exp* e, struct Cyc_Absyn_Stmt* s, struct
Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_break_stmt(
struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_continue_stmt(
struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_for_stmt(
struct Cyc_Absyn_Exp* e1, struct Cyc_Absyn_Exp* e2, struct Cyc_Absyn_Exp* e3,
struct Cyc_Absyn_Stmt* s, struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt*
Cyc_Absyn_switch_stmt( struct Cyc_Absyn_Exp* e, struct Cyc_List_List*, struct
Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_fallthru_stmt(
struct Cyc_List_List* el, struct Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Stmt*
Cyc_Absyn_do_stmt( struct Cyc_Absyn_Stmt* s, struct Cyc_Absyn_Exp* e, struct Cyc_Position_Segment*
loc); extern struct Cyc_Absyn_Stmt* Cyc_Absyn_trycatch_stmt( struct Cyc_Absyn_Stmt*
s, struct Cyc_List_List* scs, struct Cyc_Position_Segment* loc); extern struct
Cyc_Absyn_Stmt* Cyc_Absyn_goto_stmt( struct _tagged_string* lab, struct Cyc_Position_Segment*
loc); extern struct Cyc_Absyn_Pat* Cyc_Absyn_new_pat( void* p, struct Cyc_Position_Segment*
s); extern struct Cyc_Absyn_Decl* Cyc_Absyn_new_decl( void* r, struct Cyc_Position_Segment*
loc); extern struct Cyc_Absyn_Decl* Cyc_Absyn_let_decl( struct Cyc_Absyn_Pat* p,
struct Cyc_Core_Opt* t_opt, struct Cyc_Absyn_Exp* e, struct Cyc_Position_Segment*
loc); extern struct Cyc_Absyn_Vardecl* Cyc_Absyn_new_vardecl( struct _tuple1* x,
void* t, struct Cyc_Absyn_Exp* init); extern struct Cyc_Absyn_Decl* Cyc_Absyn_struct_decl(
void* s, struct Cyc_Core_Opt* n, struct Cyc_List_List* ts, struct Cyc_Core_Opt*
fs, struct Cyc_List_List* atts, struct Cyc_Position_Segment* loc); extern struct
Cyc_Absyn_Decl* Cyc_Absyn_union_decl( void* s, struct Cyc_Core_Opt* n, struct
Cyc_List_List* ts, struct Cyc_Core_Opt* fs, struct Cyc_List_List* atts, struct
Cyc_Position_Segment* loc); extern struct Cyc_Absyn_Decl* Cyc_Absyn_tunion_decl(
void* s, struct _tuple1* n, struct Cyc_List_List* ts, struct Cyc_Core_Opt* fs,
int is_xtunion, struct Cyc_Position_Segment* loc); extern void* Cyc_Absyn_function_typ(
struct Cyc_List_List* tvs, struct Cyc_Core_Opt* eff_typ, void* ret_typ, struct
Cyc_List_List* args, int varargs, struct Cyc_List_List*); extern struct
_tagged_string Cyc_Absyn_attribute2string( void*); struct Cyc_PP_Ppstate;
typedef struct Cyc_PP_Ppstate* Cyc_PP_ppstate_t; struct Cyc_PP_Out; typedef
struct Cyc_PP_Out* Cyc_PP_out_t; struct Cyc_PP_Doc; typedef struct Cyc_PP_Doc*
Cyc_PP_doc_t; extern void Cyc_Lex_register_typedef( struct _tuple1* s); extern
void Cyc_Lex_enter_namespace( struct _tagged_string*); extern void Cyc_Lex_leave_namespace();
extern void Cyc_Lex_enter_using( struct _tuple1*); extern void Cyc_Lex_leave_using();
static const int Cyc_Parse_Struct_su= 0; static const int Cyc_Parse_Union_su= 1;
typedef void* Cyc_Parse_struct_or_union_t; static const int Cyc_Parse_TopDecls_bl=
0; struct Cyc_Parse_TopDecls_bl_struct{ int tag; struct Cyc_List_List* f1; } ;
static const int Cyc_Parse_Stmt_bl= 1; struct Cyc_Parse_Stmt_bl_struct{ int tag;
struct Cyc_Absyn_Stmt* f1; } ; static const int Cyc_Parse_FnDecl_bl= 2; struct
Cyc_Parse_FnDecl_bl_struct{ int tag; struct Cyc_Absyn_Fndecl* f1; } ; typedef
void* Cyc_Parse_blockitem_t; static const int Cyc_Parse_Signed_spec= 0; struct
Cyc_Parse_Signed_spec_struct{ int tag; struct Cyc_Position_Segment* f1; } ;
static const int Cyc_Parse_Unsigned_spec= 1; struct Cyc_Parse_Unsigned_spec_struct{
int tag; struct Cyc_Position_Segment* f1; } ; static const int Cyc_Parse_Short_spec=
2; struct Cyc_Parse_Short_spec_struct{ int tag; struct Cyc_Position_Segment* f1;
} ; static const int Cyc_Parse_Long_spec= 3; struct Cyc_Parse_Long_spec_struct{
int tag; struct Cyc_Position_Segment* f1; } ; static const int Cyc_Parse_Type_spec=
4; struct Cyc_Parse_Type_spec_struct{ int tag; void* f1; struct Cyc_Position_Segment*
f2; } ; static const int Cyc_Parse_Decl_spec= 5; struct Cyc_Parse_Decl_spec_struct{
int tag; struct Cyc_Absyn_Decl* f1; } ; typedef void* Cyc_Parse_type_specifier_t;
static const int Cyc_Parse_Typedef_sc= 0; static const int Cyc_Parse_Extern_sc=
1; static const int Cyc_Parse_ExternC_sc= 2; static const int Cyc_Parse_Static_sc=
3; static const int Cyc_Parse_Auto_sc= 4; static const int Cyc_Parse_Register_sc=
5; static const int Cyc_Parse_Abstract_sc= 6; typedef void* Cyc_Parse_storage_class_t;
struct Cyc_Parse_Declaration_spec{ struct Cyc_Core_Opt* sc; struct Cyc_Absyn_Tqual
tq; struct Cyc_List_List* type_specs; int is_inline; struct Cyc_List_List*
attributes; } ; typedef struct Cyc_Parse_Declaration_spec* Cyc_Parse_decl_spec_t;
struct Cyc_Parse_Declarator{ struct _tuple1* id; struct Cyc_List_List* tms; } ;
typedef struct Cyc_Parse_Declarator* Cyc_Parse_declarator_t; struct Cyc_Parse_Abstractdeclarator{
struct Cyc_List_List* tms; } ; typedef struct Cyc_Parse_Abstractdeclarator* Cyc_Parse_abstractdeclarator_t;
struct _tuple4{ struct _tagged_string* f1; struct Cyc_Absyn_Tqual f2; void* f3;
} ; static struct _tuple4* Cyc_Parse_fnargspec_to_arg( struct Cyc_Position_Segment*
loc, struct _tuple2* t); struct _tuple5{ void* f1; struct Cyc_Core_Opt* f2; } ;
static struct _tuple5 Cyc_Parse_collapse_type_specifiers( struct Cyc_List_List*
ts, struct Cyc_Position_Segment* loc); struct _tuple6{ struct Cyc_Absyn_Tqual f1;
void* f2; struct Cyc_List_List* f3; struct Cyc_List_List* f4; } ; static struct
_tuple6 Cyc_Parse_apply_tms( struct Cyc_Absyn_Tqual, void*, struct Cyc_List_List*,
struct Cyc_List_List*); struct _tuple7{ struct _tuple1* f1; struct Cyc_Absyn_Tqual
f2; void* f3; struct Cyc_List_List* f4; struct Cyc_List_List* f5; } ; static
struct Cyc_Absyn_Decl* Cyc_Parse_v_typ_to_typedef( struct Cyc_Position_Segment*
loc, struct _tuple7* t); struct Cyc_Core_Opt* Cyc_Parse_lbuf= 0; static struct
Cyc_List_List* Cyc_Parse_parse_result= 0; static void Cyc_Parse_err( struct
_tagged_string msg, struct Cyc_Position_Segment* sg){ Cyc_Position_post_error(
Cyc_Position_mk_err_parse( sg, msg));} static void* Cyc_Parse_abort( struct
_tagged_string msg, struct Cyc_Position_Segment* sg){ Cyc_Parse_err( msg, sg);(
void) _throw(( void*) Cyc_Position_Exit);} static void Cyc_Parse_warn( struct
_tagged_string msg, struct Cyc_Position_Segment* sg){({ struct _tagged_string
_temp0= Cyc_Position_string_of_segment( sg); struct _tagged_string _temp1= msg;
fprintf( Cyc_Stdio_stderr,"%.*s: Warning: %.*s\n", _temp0.last_plus_one - _temp0.curr,
_temp0.curr, _temp1.last_plus_one - _temp1.curr, _temp1.curr);}); return;}
static void* Cyc_Parse_unimp( struct _tagged_string msg, struct Cyc_Position_Segment*
sg){ return(( void*(*)( struct _tagged_string msg, struct Cyc_Position_Segment*
sg)) Cyc_Parse_abort)(({ struct _tagged_string _temp2= msg; xprintf("%.*s unimplemented",
_temp2.last_plus_one - _temp2.curr, _temp2.curr);}), sg);} static void Cyc_Parse_unimp2(
struct _tagged_string msg, struct Cyc_Position_Segment* sg){({ struct
_tagged_string _temp3= Cyc_Position_string_of_segment( sg); struct
_tagged_string _temp4= msg; fprintf( Cyc_Stdio_stderr,"%.*s: Warning: Cyclone does not yet support %.*s\n",
_temp3.last_plus_one - _temp3.curr, _temp3.curr, _temp4.last_plus_one - _temp4.curr,
_temp4.curr);}); return;} struct _tuple8{ struct _tuple7* f1; struct Cyc_Core_Opt*
f2; } ; static struct Cyc_Absyn_Structfield* Cyc_Parse_make_struct_field( struct
Cyc_Position_Segment* loc, struct _tuple8* field_info){ struct Cyc_Core_Opt*
_temp7; struct _tuple7* _temp9; struct _tuple8 _temp5=* field_info; _LL10:
_temp9= _temp5.f1; goto _LL8; _LL8: _temp7= _temp5.f2; goto _LL6; _LL6: if((*
_temp9).f4 != 0){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp11=( char*)"bad type params in struct field";
struct _tagged_string _temp12; _temp12.curr= _temp11; _temp12.base= _temp11;
_temp12.last_plus_one= _temp11 + 32; _temp12;}), loc);}{ struct _tuple1* qid=(*
_temp9).f1;{ void* _temp13=(* qid).f1; struct Cyc_List_List* _temp23; struct Cyc_List_List*
_temp25; _LL15: if(( unsigned int) _temp13 > 1u?*(( int*) _temp13) == Cyc_Absyn_Rel_n:
0){ _LL24: _temp23=( struct Cyc_List_List*)(( struct Cyc_Absyn_Rel_n_struct*)
_temp13)->f1; if( _temp23 == 0){ goto _LL16;} else{ goto _LL17;}} else{ goto
_LL17;} _LL17: if(( unsigned int) _temp13 > 1u?*(( int*) _temp13) == Cyc_Absyn_Abs_n:
0){ _LL26: _temp25=( struct Cyc_List_List*)(( struct Cyc_Absyn_Abs_n_struct*)
_temp13)->f1; if( _temp25 == 0){ goto _LL18;} else{ goto _LL19;}} else{ goto
_LL19;} _LL19: if( _temp13 ==( void*) Cyc_Absyn_Loc_n){ goto _LL20;} else{ goto
_LL21;} _LL21: goto _LL22; _LL16: goto _LL14; _LL18: goto _LL14; _LL20: goto
_LL14; _LL22: Cyc_Parse_err(( struct _tagged_string)({ char* _temp27=( char*)"struct field cannot be qualified with a module name";
struct _tagged_string _temp28; _temp28.curr= _temp27; _temp28.base= _temp27;
_temp28.last_plus_one= _temp27 + 52; _temp28;}), loc); goto _LL14; _LL14:;}{
struct Cyc_List_List* atts=(* _temp9).f5; return({ struct Cyc_Absyn_Structfield*
_temp29=( struct Cyc_Absyn_Structfield*) GC_malloc( sizeof( struct Cyc_Absyn_Structfield));
_temp29->name=(* qid).f2; _temp29->tq=(* _temp9).f2; _temp29->type=( void*)(*
_temp9).f3; _temp29->width= _temp7; _temp29->attributes= atts; _temp29;});}}}
struct _tuple9{ struct Cyc_Core_Opt* f1; struct Cyc_Absyn_Tqual f2; void* f3;
struct Cyc_List_List* f4; } ; static struct _tuple2* Cyc_Parse_make_param(
struct Cyc_Position_Segment* loc, struct _tuple9* field){ struct _tuple9 _temp32;
struct Cyc_List_List* _temp33; void* _temp35; struct Cyc_Absyn_Tqual _temp37;
struct Cyc_Core_Opt* _temp39; struct _tuple9* _temp30= field; _temp32=* _temp30;
_LL40: _temp39= _temp32.f1; goto _LL38; _LL38: _temp37= _temp32.f2; goto _LL36;
_LL36: _temp35= _temp32.f3; goto _LL34; _LL34: _temp33= _temp32.f4; goto _LL31;
_LL31: { struct Cyc_Core_Opt* idopt= 0; if( _temp39 != 0){ idopt=({ struct Cyc_Core_Opt*
_temp41=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp41->v=( void*)(*(( struct _tuple1*)({ struct Cyc_Core_Opt* _temp42= _temp39;
if( _temp42 == 0){ _throw( Null_Exception);} _temp42->v;}))).f2; _temp41;});{
void* _temp44=(*(( struct _tuple1*)({ struct Cyc_Core_Opt* _temp43= _temp39; if(
_temp43 == 0){ _throw( Null_Exception);} _temp43->v;}))).f1; struct Cyc_List_List*
_temp54; struct Cyc_List_List* _temp56; _LL46: if(( unsigned int) _temp44 > 1u?*((
int*) _temp44) == Cyc_Absyn_Rel_n: 0){ _LL55: _temp54=( struct Cyc_List_List*)((
struct Cyc_Absyn_Rel_n_struct*) _temp44)->f1; if( _temp54 == 0){ goto _LL47;}
else{ goto _LL48;}} else{ goto _LL48;} _LL48: if(( unsigned int) _temp44 > 1u?*((
int*) _temp44) == Cyc_Absyn_Abs_n: 0){ _LL57: _temp56=( struct Cyc_List_List*)((
struct Cyc_Absyn_Abs_n_struct*) _temp44)->f1; if( _temp56 == 0){ goto _LL49;}
else{ goto _LL50;}} else{ goto _LL50;} _LL50: if( _temp44 ==( void*) Cyc_Absyn_Loc_n){
goto _LL51;} else{ goto _LL52;} _LL52: goto _LL53; _LL47: goto _LL45; _LL49:
goto _LL45; _LL51: goto _LL45; _LL53: Cyc_Parse_err(( struct _tagged_string)({
char* _temp58=( char*)"parameter cannot be qualified with a module name"; struct
_tagged_string _temp59; _temp59.curr= _temp58; _temp59.base= _temp58; _temp59.last_plus_one=
_temp58 + 49; _temp59;}), loc); goto _LL45; _LL45:;}} if( _temp33 != 0){(( void(*)(
struct _tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)((
struct _tagged_string)({ char* _temp60=( char*)"parameter should have no type parameters";
struct _tagged_string _temp61; _temp61.curr= _temp60; _temp61.base= _temp60;
_temp61.last_plus_one= _temp60 + 41; _temp61;}), loc);} return({ struct _tuple2*
_temp62=( struct _tuple2*) GC_malloc( sizeof( struct _tuple2)); _temp62->f1=
idopt; _temp62->f2= _temp37; _temp62->f3= _temp35; _temp62;});}} static void*
Cyc_Parse_type_spec( void* t, struct Cyc_Position_Segment* loc){ return( void*)({
struct Cyc_Parse_Type_spec_struct* _temp63=( struct Cyc_Parse_Type_spec_struct*)
GC_malloc( sizeof( struct Cyc_Parse_Type_spec_struct)); _temp63[ 0]=({ struct
Cyc_Parse_Type_spec_struct _temp64; _temp64.tag= Cyc_Parse_Type_spec; _temp64.f1=(
void*) t; _temp64.f2= loc; _temp64;}); _temp63;});} static void* Cyc_Parse_array2ptr(
void* t){ void* _temp65= t; struct Cyc_Absyn_Exp* _temp71; struct Cyc_Absyn_Tqual
_temp73; void* _temp75; _LL67: if(( unsigned int) _temp65 > 4u?*(( int*) _temp65)
== Cyc_Absyn_ArrayType: 0){ _LL76: _temp75=( void*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp65)->f1; goto _LL74; _LL74: _temp73=( struct Cyc_Absyn_Tqual)(( struct Cyc_Absyn_ArrayType_struct*)
_temp65)->f2; goto _LL72; _LL72: _temp71=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp65)->f3; goto _LL68;} else{ goto _LL69;} _LL69: goto _LL70; _LL68: return
Cyc_Absyn_starb_typ( _temp75,( void*) Cyc_Absyn_HeapRgn, _temp73, _temp71 == 0?(
void*) Cyc_Absyn_Unknown_b:( void*)({ struct Cyc_Absyn_Upper_b_struct* _temp77=(
struct Cyc_Absyn_Upper_b_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct));
_temp77[ 0]=({ struct Cyc_Absyn_Upper_b_struct _temp78; _temp78.tag= Cyc_Absyn_Upper_b;
_temp78.f1=( struct Cyc_Absyn_Exp*)({ struct Cyc_Absyn_Exp* _temp79= _temp71;
if( _temp79 == 0){ _throw( Null_Exception);} _temp79;}); _temp78;}); _temp77;}));
_LL70: return t; _LL66:;} static void Cyc_Parse_arg_array2ptr( struct _tuple2* x){(*
x).f3= Cyc_Parse_array2ptr((* x).f3);} struct _tuple10{ struct Cyc_Absyn_Tqual
f1; void* f2; } ; static struct _tuple10* Cyc_Parse_get_tqual_typ( struct Cyc_Position_Segment*
loc, struct _tuple2* t){ return({ struct _tuple10* _temp80=( struct _tuple10*)
GC_malloc( sizeof( struct _tuple10)); _temp80->f1=(* t).f2; _temp80->f2=(* t).f3;
_temp80;});} static void Cyc_Parse_only_vardecl( struct Cyc_List_List* params,
struct Cyc_Absyn_Decl* x){ struct _tagged_string decl_kind;{ void* _temp81=(
void*) x->r; struct Cyc_Absyn_Vardecl* _temp105; int _temp107; struct Cyc_Absyn_Exp*
_temp109; struct Cyc_Core_Opt* _temp111; struct Cyc_Core_Opt* _temp113; struct
Cyc_Absyn_Pat* _temp115; struct Cyc_Absyn_Fndecl* _temp117; struct Cyc_Absyn_Structdecl*
_temp119; struct Cyc_Absyn_Uniondecl* _temp121; struct Cyc_Absyn_Tuniondecl*
_temp123; struct Cyc_Absyn_Typedefdecl* _temp125; struct Cyc_Absyn_Enumdecl*
_temp127; struct Cyc_List_List* _temp129; struct _tagged_string* _temp131;
struct Cyc_List_List* _temp133; struct _tuple1* _temp135; struct Cyc_List_List*
_temp137; _LL83: if(*(( int*) _temp81) == Cyc_Absyn_Var_d){ _LL106: _temp105=(
struct Cyc_Absyn_Vardecl*)(( struct Cyc_Absyn_Var_d_struct*) _temp81)->f1; goto
_LL84;} else{ goto _LL85;} _LL85: if(*(( int*) _temp81) == Cyc_Absyn_Let_d){
_LL116: _temp115=( struct Cyc_Absyn_Pat*)(( struct Cyc_Absyn_Let_d_struct*)
_temp81)->f1; goto _LL114; _LL114: _temp113=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Let_d_struct*)
_temp81)->f2; goto _LL112; _LL112: _temp111=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_Let_d_struct*)
_temp81)->f3; goto _LL110; _LL110: _temp109=( struct Cyc_Absyn_Exp*)(( struct
Cyc_Absyn_Let_d_struct*) _temp81)->f4; goto _LL108; _LL108: _temp107=( int)((
struct Cyc_Absyn_Let_d_struct*) _temp81)->f5; goto _LL86;} else{ goto _LL87;}
_LL87: if(*(( int*) _temp81) == Cyc_Absyn_Fn_d){ _LL118: _temp117=( struct Cyc_Absyn_Fndecl*)((
struct Cyc_Absyn_Fn_d_struct*) _temp81)->f1; goto _LL88;} else{ goto _LL89;}
_LL89: if(*(( int*) _temp81) == Cyc_Absyn_Struct_d){ _LL120: _temp119=( struct
Cyc_Absyn_Structdecl*)(( struct Cyc_Absyn_Struct_d_struct*) _temp81)->f1; goto
_LL90;} else{ goto _LL91;} _LL91: if(*(( int*) _temp81) == Cyc_Absyn_Union_d){
_LL122: _temp121=( struct Cyc_Absyn_Uniondecl*)(( struct Cyc_Absyn_Union_d_struct*)
_temp81)->f1; goto _LL92;} else{ goto _LL93;} _LL93: if(*(( int*) _temp81) ==
Cyc_Absyn_Tunion_d){ _LL124: _temp123=( struct Cyc_Absyn_Tuniondecl*)(( struct
Cyc_Absyn_Tunion_d_struct*) _temp81)->f1; goto _LL94;} else{ goto _LL95;} _LL95:
if(*(( int*) _temp81) == Cyc_Absyn_Typedef_d){ _LL126: _temp125=( struct Cyc_Absyn_Typedefdecl*)((
struct Cyc_Absyn_Typedef_d_struct*) _temp81)->f1; goto _LL96;} else{ goto _LL97;}
_LL97: if(*(( int*) _temp81) == Cyc_Absyn_Enum_d){ _LL128: _temp127=( struct Cyc_Absyn_Enumdecl*)((
struct Cyc_Absyn_Enum_d_struct*) _temp81)->f1; goto _LL98;} else{ goto _LL99;}
_LL99: if(*(( int*) _temp81) == Cyc_Absyn_Namespace_d){ _LL132: _temp131=(
struct _tagged_string*)(( struct Cyc_Absyn_Namespace_d_struct*) _temp81)->f1;
goto _LL130; _LL130: _temp129=( struct Cyc_List_List*)(( struct Cyc_Absyn_Namespace_d_struct*)
_temp81)->f2; goto _LL100;} else{ goto _LL101;} _LL101: if(*(( int*) _temp81) ==
Cyc_Absyn_Using_d){ _LL136: _temp135=( struct _tuple1*)(( struct Cyc_Absyn_Using_d_struct*)
_temp81)->f1; goto _LL134; _LL134: _temp133=( struct Cyc_List_List*)(( struct
Cyc_Absyn_Using_d_struct*) _temp81)->f2; goto _LL102;} else{ goto _LL103;}
_LL103: if(*(( int*) _temp81) == Cyc_Absyn_ExternC_d){ _LL138: _temp137=( struct
Cyc_List_List*)(( struct Cyc_Absyn_ExternC_d_struct*) _temp81)->f1; goto _LL104;}
else{ goto _LL82;} _LL84: if( _temp105->initializer != 0){(( void(*)( struct
_tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)(( struct
_tagged_string)({ char* _temp139=( char*)"initializers are not allowed in parameter declarations";
struct _tagged_string _temp140; _temp140.curr= _temp139; _temp140.base= _temp139;
_temp140.last_plus_one= _temp139 + 55; _temp140;}), x->loc);}{ void* _temp141=(*
_temp105->name).f1; struct Cyc_List_List* _temp151; struct Cyc_List_List*
_temp153; _LL143: if( _temp141 ==( void*) Cyc_Absyn_Loc_n){ goto _LL144;} else{
goto _LL145;} _LL145: if(( unsigned int) _temp141 > 1u?*(( int*) _temp141) ==
Cyc_Absyn_Rel_n: 0){ _LL152: _temp151=( struct Cyc_List_List*)(( struct Cyc_Absyn_Rel_n_struct*)
_temp141)->f1; if( _temp151 == 0){ goto _LL146;} else{ goto _LL147;}} else{ goto
_LL147;} _LL147: if(( unsigned int) _temp141 > 1u?*(( int*) _temp141) == Cyc_Absyn_Abs_n:
0){ _LL154: _temp153=( struct Cyc_List_List*)(( struct Cyc_Absyn_Abs_n_struct*)
_temp141)->f1; if( _temp153 == 0){ goto _LL148;} else{ goto _LL149;}} else{ goto
_LL149;} _LL149: goto _LL150; _LL144: goto _LL142; _LL146: goto _LL142; _LL148:
goto _LL142; _LL150: Cyc_Parse_err(( struct _tagged_string)({ char* _temp155=(
char*)"module names not allowed on parameter declarations"; struct
_tagged_string _temp156; _temp156.curr= _temp155; _temp156.base= _temp155;
_temp156.last_plus_one= _temp155 + 51; _temp156;}), x->loc); goto _LL142; _LL142:;}{
int found= 0; for( 0; params != 0; params=({ struct Cyc_List_List* _temp157=
params; if( _temp157 == 0){ _throw( Null_Exception);} _temp157->tl;})){ if( Cyc_String_zstrptrcmp((*
_temp105->name).f2,( struct _tagged_string*)({ struct Cyc_List_List* _temp158=
params; if( _temp158 == 0){ _throw( Null_Exception);} _temp158->hd;})) == 0){
found= 1; break;}} if( ! found){(( void(*)( struct _tagged_string msg, struct
Cyc_Position_Segment* sg)) Cyc_Parse_abort)(({ struct _tagged_string _temp159=*(*
_temp105->name).f2; xprintf("%.*s is not listed as a parameter", _temp159.last_plus_one
- _temp159.curr, _temp159.curr);}), x->loc);} return;} _LL86: decl_kind=( struct
_tagged_string)({ char* _temp160=( char*)"let declaration"; struct
_tagged_string _temp161; _temp161.curr= _temp160; _temp161.base= _temp160;
_temp161.last_plus_one= _temp160 + 16; _temp161;}); goto _LL82; _LL88: decl_kind=(
struct _tagged_string)({ char* _temp162=( char*)"function declaration"; struct
_tagged_string _temp163; _temp163.curr= _temp162; _temp163.base= _temp162;
_temp163.last_plus_one= _temp162 + 21; _temp163;}); goto _LL82; _LL90: decl_kind=(
struct _tagged_string)({ char* _temp164=( char*)"struct declaration"; struct
_tagged_string _temp165; _temp165.curr= _temp164; _temp165.base= _temp164;
_temp165.last_plus_one= _temp164 + 19; _temp165;}); goto _LL82; _LL92: decl_kind=(
struct _tagged_string)({ char* _temp166=( char*)"union declaration"; struct
_tagged_string _temp167; _temp167.curr= _temp166; _temp167.base= _temp166;
_temp167.last_plus_one= _temp166 + 18; _temp167;}); goto _LL82; _LL94: decl_kind=(
struct _tagged_string)({ char* _temp168=( char*)"tunion declaration"; struct
_tagged_string _temp169; _temp169.curr= _temp168; _temp169.base= _temp168;
_temp169.last_plus_one= _temp168 + 19; _temp169;}); goto _LL82; _LL96: decl_kind=(
struct _tagged_string)({ char* _temp170=( char*)"typedef"; struct _tagged_string
_temp171; _temp171.curr= _temp170; _temp171.base= _temp170; _temp171.last_plus_one=
_temp170 + 8; _temp171;}); goto _LL82; _LL98: decl_kind=( struct _tagged_string)({
char* _temp172=( char*)"enum declaration"; struct _tagged_string _temp173;
_temp173.curr= _temp172; _temp173.base= _temp172; _temp173.last_plus_one=
_temp172 + 17; _temp173;}); goto _LL82; _LL100: decl_kind=( struct
_tagged_string)({ char* _temp174=( char*)"namespace declaration"; struct
_tagged_string _temp175; _temp175.curr= _temp174; _temp175.base= _temp174;
_temp175.last_plus_one= _temp174 + 22; _temp175;}); goto _LL82; _LL102:
decl_kind=( struct _tagged_string)({ char* _temp176=( char*)"using declaration";
struct _tagged_string _temp177; _temp177.curr= _temp176; _temp177.base= _temp176;
_temp177.last_plus_one= _temp176 + 18; _temp177;}); goto _LL82; _LL104:
decl_kind=( struct _tagged_string)({ char* _temp178=( char*)"extern C declaration";
struct _tagged_string _temp179; _temp179.curr= _temp178; _temp179.base= _temp178;
_temp179.last_plus_one= _temp178 + 21; _temp179;}); goto _LL82; _LL82:;}(( void(*)(
struct _tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)(({
struct _tagged_string _temp180= decl_kind; xprintf("%.*s appears in parameter type",
_temp180.last_plus_one - _temp180.curr, _temp180.curr);}), x->loc); return;}
struct _tuple11{ struct Cyc_List_List* f1; struct Cyc_Position_Segment* f2; } ;
static struct _tuple2* Cyc_Parse_get_param_type( struct _tuple11* env, struct
_tagged_string* x){ struct _tuple11 _temp183; struct Cyc_Position_Segment*
_temp184; struct Cyc_List_List* _temp186; struct _tuple11* _temp181= env;
_temp183=* _temp181; _LL187: _temp186= _temp183.f1; goto _LL185; _LL185:
_temp184= _temp183.f2; goto _LL182; _LL182: if( _temp186 == 0){ return(( struct
_tuple2*(*)( struct _tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)(({
struct _tagged_string _temp188=* x; xprintf("missing type for parameter %.*s",
_temp188.last_plus_one - _temp188.curr, _temp188.curr);}), _temp184);}{ void*
_temp190=( void*)(( struct Cyc_Absyn_Decl*)({ struct Cyc_List_List* _temp189=
_temp186; if( _temp189 == 0){ _throw( Null_Exception);} _temp189->hd;}))->r;
struct Cyc_Absyn_Vardecl* _temp196; _LL192: if(*(( int*) _temp190) == Cyc_Absyn_Var_d){
_LL197: _temp196=( struct Cyc_Absyn_Vardecl*)(( struct Cyc_Absyn_Var_d_struct*)
_temp190)->f1; goto _LL193;} else{ goto _LL194;} _LL194: goto _LL195; _LL193:{
void* _temp198=(* _temp196->name).f1; struct Cyc_List_List* _temp208; struct Cyc_List_List*
_temp210; _LL200: if( _temp198 ==( void*) Cyc_Absyn_Loc_n){ goto _LL201;} else{
goto _LL202;} _LL202: if(( unsigned int) _temp198 > 1u?*(( int*) _temp198) ==
Cyc_Absyn_Rel_n: 0){ _LL209: _temp208=( struct Cyc_List_List*)(( struct Cyc_Absyn_Rel_n_struct*)
_temp198)->f1; if( _temp208 == 0){ goto _LL203;} else{ goto _LL204;}} else{ goto
_LL204;} _LL204: if(( unsigned int) _temp198 > 1u?*(( int*) _temp198) == Cyc_Absyn_Abs_n:
0){ _LL211: _temp210=( struct Cyc_List_List*)(( struct Cyc_Absyn_Abs_n_struct*)
_temp198)->f1; if( _temp210 == 0){ goto _LL205;} else{ goto _LL206;}} else{ goto
_LL206;} _LL206: goto _LL207; _LL201: goto _LL199; _LL203: goto _LL199; _LL205:
goto _LL199; _LL207: Cyc_Parse_err(( struct _tagged_string)({ char* _temp212=(
char*)"module name not allowed on parameter"; struct _tagged_string _temp213;
_temp213.curr= _temp212; _temp213.base= _temp212; _temp213.last_plus_one=
_temp212 + 37; _temp213;}), _temp184); goto _LL199; _LL199:;} if( Cyc_String_zstrptrcmp((*
_temp196->name).f2, x) == 0){ return({ struct _tuple2* _temp214=( struct _tuple2*)
GC_malloc( sizeof( struct _tuple2) * 1); _temp214[ 0]=({ struct _tuple2 _temp215;
_temp215.f1=({ struct Cyc_Core_Opt* _temp216=( struct Cyc_Core_Opt*) GC_malloc(
sizeof( struct Cyc_Core_Opt) * 1); _temp216[ 0]=({ struct Cyc_Core_Opt _temp217;
_temp217.v=( void*)(* _temp196->name).f2; _temp217;}); _temp216;}); _temp215.f2=
_temp196->tq; _temp215.f3=( void*) _temp196->type; _temp215;}); _temp214;});}
else{ return Cyc_Parse_get_param_type(({ struct _tuple11* _temp218=( struct
_tuple11*) GC_malloc( sizeof( struct _tuple11)); _temp218->f1=({ struct Cyc_List_List*
_temp219= _temp186; if( _temp219 == 0){ _throw( Null_Exception);} _temp219->tl;});
_temp218->f2= _temp184; _temp218;}), x);} _LL195: return(( struct _tuple2*(*)(
struct _tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)((
struct _tagged_string)({ char* _temp220=( char*)"non-variable declaration";
struct _tagged_string _temp221; _temp221.curr= _temp220; _temp221.base= _temp220;
_temp221.last_plus_one= _temp220 + 25; _temp221;}),(( struct Cyc_Absyn_Decl*)({
struct Cyc_List_List* _temp222= _temp186; if( _temp222 == 0){ _throw(
Null_Exception);} _temp222->hd;}))->loc); _LL191:;}} static int Cyc_Parse_is_typeparam(
void* tm){ void* _temp223= tm; int _temp229; struct Cyc_Position_Segment*
_temp231; struct Cyc_List_List* _temp233; _LL225: if(( unsigned int) _temp223 >
1u?*(( int*) _temp223) == Cyc_Absyn_TypeParams_mod: 0){ _LL234: _temp233=(
struct Cyc_List_List*)(( struct Cyc_Absyn_TypeParams_mod_struct*) _temp223)->f1;
goto _LL232; _LL232: _temp231=( struct Cyc_Position_Segment*)(( struct Cyc_Absyn_TypeParams_mod_struct*)
_temp223)->f2; goto _LL230; _LL230: _temp229=( int)(( struct Cyc_Absyn_TypeParams_mod_struct*)
_temp223)->f3; goto _LL226;} else{ goto _LL227;} _LL227: goto _LL228; _LL226:
return 1; _LL228: return 0; _LL224:;} static void* Cyc_Parse_id2type( struct
_tagged_string s, struct Cyc_Absyn_Conref* k){ if( Cyc_String_zstrcmp( s,(
struct _tagged_string)({ char* _temp235=( char*)"`H"; struct _tagged_string
_temp236; _temp236.curr= _temp235; _temp236.base= _temp235; _temp236.last_plus_one=
_temp235 + 3; _temp236;})) == 0){ return( void*) Cyc_Absyn_HeapRgn;} else{
return( void*)({ struct Cyc_Absyn_VarType_struct* _temp237=( struct Cyc_Absyn_VarType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct)); _temp237[ 0]=({ struct Cyc_Absyn_VarType_struct
_temp238; _temp238.tag= Cyc_Absyn_VarType; _temp238.f1=({ struct Cyc_Absyn_Tvar*
_temp239=( struct Cyc_Absyn_Tvar*) GC_malloc( sizeof( struct Cyc_Absyn_Tvar));
_temp239->name=({ struct _tagged_string* _temp240=( struct _tagged_string*)
GC_malloc( sizeof( struct _tagged_string) * 1); _temp240[ 0]= s; _temp240;});
_temp239->kind= k; _temp239;}); _temp238;}); _temp237;});}} static struct Cyc_Absyn_Tvar*
Cyc_Parse_typ2tvar( struct Cyc_Position_Segment* loc, void* t){ void* _temp241=
t; struct Cyc_Absyn_Tvar* _temp247; _LL243: if(( unsigned int) _temp241 > 4u?*((
int*) _temp241) == Cyc_Absyn_VarType: 0){ _LL248: _temp247=( struct Cyc_Absyn_Tvar*)((
struct Cyc_Absyn_VarType_struct*) _temp241)->f1; goto _LL244;} else{ goto _LL245;}
_LL245: goto _LL246; _LL244: return _temp247; _LL246: return(( struct Cyc_Absyn_Tvar*(*)(
struct _tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)((
struct _tagged_string)({ char* _temp249=( char*)"expecting a list of type variables, not types";
struct _tagged_string _temp250; _temp250.curr= _temp249; _temp250.base= _temp249;
_temp250.last_plus_one= _temp249 + 46; _temp250;}), loc); _LL242:;} static void*
Cyc_Parse_tvar2typ( struct Cyc_Absyn_Tvar* pr){ return( void*)({ struct Cyc_Absyn_VarType_struct*
_temp251=( struct Cyc_Absyn_VarType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct));
_temp251[ 0]=({ struct Cyc_Absyn_VarType_struct _temp252; _temp252.tag= Cyc_Absyn_VarType;
_temp252.f1= pr; _temp252;}); _temp251;});} static struct Cyc_List_List* Cyc_Parse_oldstyle2newstyle(
struct Cyc_List_List* tms, struct Cyc_List_List* tds, struct Cyc_Position_Segment*
loc){ if( tds == 0){ return tms;} if( tms == 0){ return 0;}{ void* _temp254=(
void*)({ struct Cyc_List_List* _temp253= tms; if( _temp253 == 0){ _throw(
Null_Exception);} _temp253->hd;}); void* _temp260; _LL256: if(( unsigned int)
_temp254 > 1u?*(( int*) _temp254) == Cyc_Absyn_Function_mod: 0){ _LL261:
_temp260=( void*)(( struct Cyc_Absyn_Function_mod_struct*) _temp254)->f1; goto
_LL257;} else{ goto _LL258;} _LL258: goto _LL259; _LL257: if(({ struct Cyc_List_List*
_temp262= tms; if( _temp262 == 0){ _throw( Null_Exception);} _temp262->tl;}) ==
0? 1:( Cyc_Parse_is_typeparam(( void*)({ struct Cyc_List_List* _temp264=({
struct Cyc_List_List* _temp263= tms; if( _temp263 == 0){ _throw( Null_Exception);}
_temp263->tl;}); if( _temp264 == 0){ _throw( Null_Exception);} _temp264->hd;}))?({
struct Cyc_List_List* _temp266=({ struct Cyc_List_List* _temp265= tms; if(
_temp265 == 0){ _throw( Null_Exception);} _temp265->tl;}); if( _temp266 == 0){
_throw( Null_Exception);} _temp266->tl;}) == 0: 0)){ void* _temp267= _temp260;
struct Cyc_Core_Opt* _temp273; int _temp275; struct Cyc_List_List* _temp277;
struct Cyc_Position_Segment* _temp279; struct Cyc_List_List* _temp281; _LL269:
if(*(( int*) _temp267) == Cyc_Absyn_WithTypes){ _LL278: _temp277=( struct Cyc_List_List*)((
struct Cyc_Absyn_WithTypes_struct*) _temp267)->f1; goto _LL276; _LL276: _temp275=(
int)(( struct Cyc_Absyn_WithTypes_struct*) _temp267)->f2; goto _LL274; _LL274:
_temp273=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_WithTypes_struct*) _temp267)->f3;
goto _LL270;} else{ goto _LL271;} _LL271: if(*(( int*) _temp267) == Cyc_Absyn_NoTypes){
_LL282: _temp281=( struct Cyc_List_List*)(( struct Cyc_Absyn_NoTypes_struct*)
_temp267)->f1; goto _LL280; _LL280: _temp279=( struct Cyc_Position_Segment*)((
struct Cyc_Absyn_NoTypes_struct*) _temp267)->f2; goto _LL272;} else{ goto _LL268;}
_LL270: Cyc_Parse_warn(( struct _tagged_string)({ char* _temp283=( char*)"function declaration with both new- and old-style parameterdeclarations; ignoring old-style";
struct _tagged_string _temp284; _temp284.curr= _temp283; _temp284.base= _temp283;
_temp284.last_plus_one= _temp283 + 92; _temp284;}), loc); return tms; _LL272:((
void(*)( void(* f)( struct Cyc_List_List*, struct Cyc_Absyn_Decl*), struct Cyc_List_List*
env, struct Cyc_List_List* x)) Cyc_List_iter_c)( Cyc_Parse_only_vardecl,
_temp281, tds);{ struct _tuple11* env=({ struct _tuple11* _temp290=( struct
_tuple11*) GC_malloc( sizeof( struct _tuple11)); _temp290->f1= tds; _temp290->f2=
loc; _temp290;}); return({ struct Cyc_List_List* _temp285=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp285->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp286=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp286[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp287; _temp287.tag= Cyc_Absyn_Function_mod;
_temp287.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp288=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp288[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp289; _temp289.tag= Cyc_Absyn_WithTypes;
_temp289.f1=(( struct Cyc_List_List*(*)( struct _tuple2*(* f)( struct _tuple11*,
struct _tagged_string*), struct _tuple11* env, struct Cyc_List_List* x)) Cyc_List_map_c)(
Cyc_Parse_get_param_type, env, _temp281); _temp289.f2= 0; _temp289.f3= 0;
_temp289;}); _temp288;})); _temp287;}); _temp286;})); _temp285->tl= 0; _temp285;});}
_LL268:;} else{ return({ struct Cyc_List_List* _temp291=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp291->hd=( void*)(( void*)({
struct Cyc_List_List* _temp293= tms; if( _temp293 == 0){ _throw( Null_Exception);}
_temp293->hd;})); _temp291->tl= Cyc_Parse_oldstyle2newstyle(({ struct Cyc_List_List*
_temp292= tms; if( _temp292 == 0){ _throw( Null_Exception);} _temp292->tl;}),
tds, loc); _temp291;});} _LL259: return({ struct Cyc_List_List* _temp294=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp294->hd=(
void*)(( void*)({ struct Cyc_List_List* _temp296= tms; if( _temp296 == 0){
_throw( Null_Exception);} _temp296->hd;})); _temp294->tl= Cyc_Parse_oldstyle2newstyle(({
struct Cyc_List_List* _temp295= tms; if( _temp295 == 0){ _throw( Null_Exception);}
_temp295->tl;}), tds, loc); _temp294;}); _LL255:;}} static struct Cyc_Absyn_Fndecl*
Cyc_Parse_make_function( struct Cyc_Core_Opt* dso, struct Cyc_Parse_Declarator*
d, struct Cyc_List_List* tds, struct Cyc_Absyn_Stmt* body, struct Cyc_Position_Segment*
loc){ if( tds != 0){ d=({ struct Cyc_Parse_Declarator* _temp297=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp297->id= d->id; _temp297->tms=
Cyc_Parse_oldstyle2newstyle( d->tms, tds, loc); _temp297;});}{ void* sc=( void*)
Cyc_Absyn_Public; struct Cyc_List_List* tss= 0; struct Cyc_Absyn_Tqual tq= Cyc_Absyn_empty_tqual();
int is_inline= 0; struct Cyc_List_List* atts= 0; if( dso != 0){ tss=(( struct
Cyc_Parse_Declaration_spec*)({ struct Cyc_Core_Opt* _temp298= dso; if( _temp298
== 0){ _throw( Null_Exception);} _temp298->v;}))->type_specs; tq=(( struct Cyc_Parse_Declaration_spec*)({
struct Cyc_Core_Opt* _temp299= dso; if( _temp299 == 0){ _throw( Null_Exception);}
_temp299->v;}))->tq; is_inline=(( struct Cyc_Parse_Declaration_spec*)({ struct
Cyc_Core_Opt* _temp300= dso; if( _temp300 == 0){ _throw( Null_Exception);}
_temp300->v;}))->is_inline; atts=(( struct Cyc_Parse_Declaration_spec*)({ struct
Cyc_Core_Opt* _temp301= dso; if( _temp301 == 0){ _throw( Null_Exception);}
_temp301->v;}))->attributes; if((( struct Cyc_Parse_Declaration_spec*)({ struct
Cyc_Core_Opt* _temp302= dso; if( _temp302 == 0){ _throw( Null_Exception);}
_temp302->v;}))->sc != 0){ void* _temp305=( void*)({ struct Cyc_Core_Opt*
_temp304=(( struct Cyc_Parse_Declaration_spec*)({ struct Cyc_Core_Opt* _temp303=
dso; if( _temp303 == 0){ _throw( Null_Exception);} _temp303->v;}))->sc; if(
_temp304 == 0){ _throw( Null_Exception);} _temp304->v;}); _LL307: if( _temp305
==( void*) Cyc_Parse_Extern_sc){ goto _LL308;} else{ goto _LL309;} _LL309: if(
_temp305 ==( void*) Cyc_Parse_ExternC_sc){ goto _LL310;} else{ goto _LL311;}
_LL311: if( _temp305 ==( void*) Cyc_Parse_Static_sc){ goto _LL312;} else{ goto
_LL313;} _LL313: goto _LL314; _LL308: sc=( void*) Cyc_Absyn_Extern; goto _LL306;
_LL310: sc=( void*) Cyc_Absyn_ExternC; goto _LL306; _LL312: sc=( void*) Cyc_Absyn_Static;
goto _LL306; _LL314: Cyc_Parse_err(( struct _tagged_string)({ char* _temp315=(
char*)"bad storage class on function"; struct _tagged_string _temp316; _temp316.curr=
_temp315; _temp316.base= _temp315; _temp316.last_plus_one= _temp315 + 30;
_temp316;}), loc); goto _LL306; _LL306:;}}{ struct Cyc_Core_Opt* _temp319; void*
_temp321; struct _tuple5 _temp317= Cyc_Parse_collapse_type_specifiers( tss, loc);
_LL322: _temp321= _temp317.f1; goto _LL320; _LL320: _temp319= _temp317.f2; goto
_LL318; _LL318: { struct Cyc_List_List* _temp325; struct Cyc_List_List* _temp327;
void* _temp329; struct Cyc_Absyn_Tqual _temp331; struct _tuple6 _temp323= Cyc_Parse_apply_tms(
tq, _temp321, atts, d->tms); _LL332: _temp331= _temp323.f1; goto _LL330; _LL330:
_temp329= _temp323.f2; goto _LL328; _LL328: _temp327= _temp323.f3; goto _LL326;
_LL326: _temp325= _temp323.f4; goto _LL324; _LL324: if( _temp319 != 0){ Cyc_Parse_warn((
struct _tagged_string)({ char* _temp333=( char*)"nested type declaration within function prototype";
struct _tagged_string _temp334; _temp334.curr= _temp333; _temp334.base= _temp333;
_temp334.last_plus_one= _temp333 + 50; _temp334;}), loc);} if( _temp327 != 0){
Cyc_Parse_warn(( struct _tagged_string)({ char* _temp335=( char*)"bad type params, ignoring";
struct _tagged_string _temp336; _temp336.curr= _temp335; _temp336.base= _temp335;
_temp336.last_plus_one= _temp335 + 26; _temp336;}), loc);}{ void* _temp337=
_temp329; struct Cyc_Absyn_FnInfo _temp343; struct Cyc_List_List* _temp345; int
_temp347; struct Cyc_List_List* _temp349; void* _temp351; struct Cyc_Core_Opt*
_temp353; struct Cyc_List_List* _temp355; _LL339: if(( unsigned int) _temp337 >
4u?*(( int*) _temp337) == Cyc_Absyn_FnType: 0){ _LL344: _temp343=( struct Cyc_Absyn_FnInfo)((
struct Cyc_Absyn_FnType_struct*) _temp337)->f1; _LL356: _temp355=( struct Cyc_List_List*)
_temp343.tvars; goto _LL354; _LL354: _temp353=( struct Cyc_Core_Opt*) _temp343.effect;
goto _LL352; _LL352: _temp351=( void*) _temp343.ret_typ; goto _LL350; _LL350:
_temp349=( struct Cyc_List_List*) _temp343.args; goto _LL348; _LL348: _temp347=(
int) _temp343.varargs; goto _LL346; _LL346: _temp345=( struct Cyc_List_List*)
_temp343.attributes; goto _LL340;} else{ goto _LL341;} _LL341: goto _LL342;
_LL340: { struct Cyc_List_List* args2=(( struct Cyc_List_List*(*)( struct
_tuple4*(* f)( struct Cyc_Position_Segment*, struct _tuple2*), struct Cyc_Position_Segment*
env, struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_fnargspec_to_arg, loc,
_temp349); return({ struct Cyc_Absyn_Fndecl* _temp357=( struct Cyc_Absyn_Fndecl*)
GC_malloc( sizeof( struct Cyc_Absyn_Fndecl)); _temp357->sc=( void*) sc; _temp357->name=
d->id; _temp357->tvs= _temp355; _temp357->is_inline= is_inline; _temp357->effect=
_temp353; _temp357->ret_type=( void*) _temp351; _temp357->args= args2; _temp357->varargs=
_temp347; _temp357->body= body; _temp357->cached_typ= 0; _temp357->param_vardecls=
0; _temp357->attributes=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x,
struct Cyc_List_List* y)) Cyc_List_append)( _temp345, _temp325); _temp357;});}
_LL342: return(( struct Cyc_Absyn_Fndecl*(*)( struct _tagged_string msg, struct
Cyc_Position_Segment* sg)) Cyc_Parse_abort)(( struct _tagged_string)({ char*
_temp358=( char*)"declarator is not a function prototype"; struct _tagged_string
_temp359; _temp359.curr= _temp358; _temp359.base= _temp358; _temp359.last_plus_one=
_temp358 + 39; _temp359;}), loc); _LL338:;}}}}} static struct _tuple4* Cyc_Parse_fnargspec_to_arg(
struct Cyc_Position_Segment* loc, struct _tuple2* t){ if((* t).f1 == 0){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp360=( char*)"missing argument variable in function prototype";
struct _tagged_string _temp361; _temp361.curr= _temp360; _temp361.base= _temp360;
_temp361.last_plus_one= _temp360 + 48; _temp361;}), loc); return({ struct
_tuple4* _temp362=( struct _tuple4*) GC_malloc( sizeof( struct _tuple4));
_temp362->f1=({ struct _tagged_string* _temp363=( struct _tagged_string*)
GC_malloc( sizeof( struct _tagged_string) * 1); _temp363[ 0]=( struct
_tagged_string)({ char* _temp364=( char*)"?"; struct _tagged_string _temp365;
_temp365.curr= _temp364; _temp365.base= _temp364; _temp365.last_plus_one=
_temp364 + 2; _temp365;}); _temp363;}); _temp362->f2=(* t).f2; _temp362->f3=(* t).f3;
_temp362;});} else{ return({ struct _tuple4* _temp366=( struct _tuple4*)
GC_malloc( sizeof( struct _tuple4)); _temp366->f1=( struct _tagged_string*)({
struct Cyc_Core_Opt* _temp367=(* t).f1; if( _temp367 == 0){ _throw(
Null_Exception);} _temp367->v;}); _temp366->f2=(* t).f2; _temp366->f3=(* t).f3;
_temp366;});}} static char _temp370[ 52u]="at most one type may appear within a type specifier";
static struct _tagged_string Cyc_Parse_msg1=( struct _tagged_string){ _temp370,
_temp370, _temp370 + 52u}; static char _temp373[ 63u]="const or volatile may appear only once within a type specifier";
static struct _tagged_string Cyc_Parse_msg2=( struct _tagged_string){ _temp373,
_temp373, _temp373 + 63u}; static char _temp376[ 50u]="type specifier includes more than one declaration";
static struct _tagged_string Cyc_Parse_msg3=( struct _tagged_string){ _temp376,
_temp376, _temp376 + 50u}; static char _temp379[ 60u]="sign specifier may appear only once within a type specifier";
static struct _tagged_string Cyc_Parse_msg4=( struct _tagged_string){ _temp379,
_temp379, _temp379 + 60u}; static struct _tuple5 Cyc_Parse_collapse_type_specifiers(
struct Cyc_List_List* ts, struct Cyc_Position_Segment* loc){ struct Cyc_Core_Opt*
declopt= 0; int seen_type= 0; int seen_sign= 0; int seen_size= 0; void* t=( void*)
Cyc_Absyn_VoidType; void* sz=( void*) Cyc_Absyn_B4; void* sgn=( void*) Cyc_Absyn_Signed;
struct Cyc_Position_Segment* last_loc= loc; for( 0; ts != 0; ts=({ struct Cyc_List_List*
_temp380= ts; if( _temp380 == 0){ _throw( Null_Exception);} _temp380->tl;})){
void* _temp382=( void*)({ struct Cyc_List_List* _temp381= ts; if( _temp381 == 0){
_throw( Null_Exception);} _temp381->hd;}); struct Cyc_Position_Segment* _temp396;
void* _temp398; struct Cyc_Position_Segment* _temp400; struct Cyc_Position_Segment*
_temp402; struct Cyc_Position_Segment* _temp404; struct Cyc_Position_Segment*
_temp406; struct Cyc_Absyn_Decl* _temp408; _LL384: if(*(( int*) _temp382) == Cyc_Parse_Type_spec){
_LL399: _temp398=( void*)(( struct Cyc_Parse_Type_spec_struct*) _temp382)->f1;
goto _LL397; _LL397: _temp396=( struct Cyc_Position_Segment*)(( struct Cyc_Parse_Type_spec_struct*)
_temp382)->f2; goto _LL385;} else{ goto _LL386;} _LL386: if(*(( int*) _temp382)
== Cyc_Parse_Signed_spec){ _LL401: _temp400=( struct Cyc_Position_Segment*)((
struct Cyc_Parse_Signed_spec_struct*) _temp382)->f1; goto _LL387;} else{ goto
_LL388;} _LL388: if(*(( int*) _temp382) == Cyc_Parse_Unsigned_spec){ _LL403:
_temp402=( struct Cyc_Position_Segment*)(( struct Cyc_Parse_Unsigned_spec_struct*)
_temp382)->f1; goto _LL389;} else{ goto _LL390;} _LL390: if(*(( int*) _temp382)
== Cyc_Parse_Short_spec){ _LL405: _temp404=( struct Cyc_Position_Segment*)((
struct Cyc_Parse_Short_spec_struct*) _temp382)->f1; goto _LL391;} else{ goto
_LL392;} _LL392: if(*(( int*) _temp382) == Cyc_Parse_Long_spec){ _LL407:
_temp406=( struct Cyc_Position_Segment*)(( struct Cyc_Parse_Long_spec_struct*)
_temp382)->f1; goto _LL393;} else{ goto _LL394;} _LL394: if(*(( int*) _temp382)
== Cyc_Parse_Decl_spec){ _LL409: _temp408=( struct Cyc_Absyn_Decl*)(( struct Cyc_Parse_Decl_spec_struct*)
_temp382)->f1; goto _LL395;} else{ goto _LL383;} _LL385: if( seen_type){ Cyc_Parse_err(
Cyc_Parse_msg1, _temp396);} last_loc= _temp396; seen_type= 1; t= _temp398; goto
_LL383; _LL387: if( seen_sign){ Cyc_Parse_err( Cyc_Parse_msg4, _temp400);} if(
seen_type){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp410=( char*)"signed qualifier must come before type";
struct _tagged_string _temp411; _temp411.curr= _temp410; _temp411.base= _temp410;
_temp411.last_plus_one= _temp410 + 39; _temp411;}), _temp400);} last_loc=
_temp400; seen_sign= 1; sgn=( void*) Cyc_Absyn_Signed; goto _LL383; _LL389: if(
seen_sign){ Cyc_Parse_err( Cyc_Parse_msg4, _temp402);} if( seen_type){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp412=( char*)"signed qualifier must come before type";
struct _tagged_string _temp413; _temp413.curr= _temp412; _temp413.base= _temp412;
_temp413.last_plus_one= _temp412 + 39; _temp413;}), _temp402);} last_loc=
_temp402; seen_sign= 1; sgn=( void*) Cyc_Absyn_Unsigned; goto _LL383; _LL391:
if( seen_size){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp414=( char*)"integral size may appear only once within a type specifier";
struct _tagged_string _temp415; _temp415.curr= _temp414; _temp415.base= _temp414;
_temp415.last_plus_one= _temp414 + 59; _temp415;}), _temp404);} if( seen_type){
Cyc_Parse_err(( struct _tagged_string)({ char* _temp416=( char*)"short modifier must come before base type";
struct _tagged_string _temp417; _temp417.curr= _temp416; _temp417.base= _temp416;
_temp417.last_plus_one= _temp416 + 42; _temp417;}), _temp404);} last_loc=
_temp404; seen_size= 1; sz=( void*) Cyc_Absyn_B2; goto _LL383; _LL393: if(
seen_type){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp418=( char*)"long modifier must come before base type";
struct _tagged_string _temp419; _temp419.curr= _temp418; _temp419.base= _temp418;
_temp419.last_plus_one= _temp418 + 41; _temp419;}), _temp406);} if( seen_size){
void* _temp420= sz; _LL422: if( _temp420 ==( void*) Cyc_Absyn_B4){ goto _LL423;}
else{ goto _LL424;} _LL424: goto _LL425; _LL423: sz=( void*) Cyc_Absyn_B8; goto
_LL421; _LL425: Cyc_Parse_err(( struct _tagged_string)({ char* _temp426=( char*)"extra long in type specifier";
struct _tagged_string _temp427; _temp427.curr= _temp426; _temp427.base= _temp426;
_temp427.last_plus_one= _temp426 + 29; _temp427;}), _temp406); goto _LL421;
_LL421:;} last_loc= _temp406; seen_size= 1; goto _LL383; _LL395: last_loc=
_temp408->loc; if( declopt == 0? ! seen_type: 0){ seen_type= 1;{ void* _temp428=(
void*) _temp408->r; struct Cyc_Absyn_Structdecl* _temp440; struct Cyc_Absyn_Tuniondecl*
_temp442; struct Cyc_Absyn_Uniondecl* _temp444; struct Cyc_Absyn_Enumdecl*
_temp446; _LL430: if(*(( int*) _temp428) == Cyc_Absyn_Struct_d){ _LL441:
_temp440=( struct Cyc_Absyn_Structdecl*)(( struct Cyc_Absyn_Struct_d_struct*)
_temp428)->f1; goto _LL431;} else{ goto _LL432;} _LL432: if(*(( int*) _temp428)
== Cyc_Absyn_Tunion_d){ _LL443: _temp442=( struct Cyc_Absyn_Tuniondecl*)((
struct Cyc_Absyn_Tunion_d_struct*) _temp428)->f1; goto _LL433;} else{ goto
_LL434;} _LL434: if(*(( int*) _temp428) == Cyc_Absyn_Union_d){ _LL445: _temp444=(
struct Cyc_Absyn_Uniondecl*)(( struct Cyc_Absyn_Union_d_struct*) _temp428)->f1;
goto _LL435;} else{ goto _LL436;} _LL436: if(*(( int*) _temp428) == Cyc_Absyn_Enum_d){
_LL447: _temp446=( struct Cyc_Absyn_Enumdecl*)(( struct Cyc_Absyn_Enum_d_struct*)
_temp428)->f1; goto _LL437;} else{ goto _LL438;} _LL438: goto _LL439; _LL431: {
struct Cyc_List_List* args=(( struct Cyc_List_List*(*)( void*(* f)( struct Cyc_Absyn_Tvar*),
struct Cyc_List_List* x)) Cyc_List_map)( Cyc_Parse_tvar2typ, _temp440->tvs); t=(
void*)({ struct Cyc_Absyn_StructType_struct* _temp448=( struct Cyc_Absyn_StructType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_StructType_struct)); _temp448[ 0]=({ struct
Cyc_Absyn_StructType_struct _temp449; _temp449.tag= Cyc_Absyn_StructType;
_temp449.f1=( struct _tuple1*)(( struct _tuple1*)({ struct Cyc_Core_Opt*
_temp450= _temp440->name; if( _temp450 == 0){ _throw( Null_Exception);} _temp450->v;}));
_temp449.f2= args; _temp449.f3= 0; _temp449;}); _temp448;}); if( _temp440->fields
!= 0){ declopt=({ struct Cyc_Core_Opt* _temp451=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp451->v=( void*) _temp408;
_temp451;});} goto _LL429;} _LL433: { struct Cyc_List_List* args=(( struct Cyc_List_List*(*)(
void*(* f)( struct Cyc_Absyn_Tvar*), struct Cyc_List_List* x)) Cyc_List_map)(
Cyc_Parse_tvar2typ, _temp442->tvs); t=( void*)({ struct Cyc_Absyn_TunionType_struct*
_temp452=( struct Cyc_Absyn_TunionType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_TunionType_struct));
_temp452[ 0]=({ struct Cyc_Absyn_TunionType_struct _temp453; _temp453.tag= Cyc_Absyn_TunionType;
_temp453.f1=({ struct Cyc_Absyn_TunionInfo _temp454; _temp454.tunion_info=( void*)((
void*)({ struct Cyc_Absyn_KnownTunion_struct* _temp455=( struct Cyc_Absyn_KnownTunion_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_KnownTunion_struct)); _temp455[ 0]=({ struct
Cyc_Absyn_KnownTunion_struct _temp456; _temp456.tag= Cyc_Absyn_KnownTunion;
_temp456.f1= _temp442; _temp456;}); _temp455;})); _temp454.targs= args; _temp454.rgn=(
void*)(( void*) Cyc_Absyn_HeapRgn); _temp454;}); _temp453;}); _temp452;}); if(
_temp442->fields != 0){ declopt=({ struct Cyc_Core_Opt* _temp457=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp457->v=( void*) _temp408;
_temp457;});} goto _LL429;} _LL435: { struct Cyc_List_List* args=(( struct Cyc_List_List*(*)(
void*(* f)( struct Cyc_Absyn_Tvar*), struct Cyc_List_List* x)) Cyc_List_map)(
Cyc_Parse_tvar2typ, _temp444->tvs); t=( void*)({ struct Cyc_Absyn_UnionType_struct*
_temp458=( struct Cyc_Absyn_UnionType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_UnionType_struct));
_temp458[ 0]=({ struct Cyc_Absyn_UnionType_struct _temp459; _temp459.tag= Cyc_Absyn_UnionType;
_temp459.f1=( struct _tuple1*)(( struct _tuple1*)({ struct Cyc_Core_Opt*
_temp460= _temp444->name; if( _temp460 == 0){ _throw( Null_Exception);} _temp460->v;}));
_temp459.f2= args; _temp459.f3= 0; _temp459;}); _temp458;}); if( _temp444->fields
!= 0){ declopt=({ struct Cyc_Core_Opt* _temp461=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp461->v=( void*) _temp408;
_temp461;});} goto _LL429;} _LL437: t=( void*)({ struct Cyc_Absyn_EnumType_struct*
_temp462=( struct Cyc_Absyn_EnumType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_EnumType_struct));
_temp462[ 0]=({ struct Cyc_Absyn_EnumType_struct _temp463; _temp463.tag= Cyc_Absyn_EnumType;
_temp463.f1= _temp446->name; _temp463.f2= 0; _temp463;}); _temp462;}); declopt=({
struct Cyc_Core_Opt* _temp464=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp464->v=( void*) _temp408; _temp464;}); goto _LL429; _LL439:((
void(*)( struct _tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)((
struct _tagged_string)({ char* _temp465=( char*)"bad declaration within type specifier";
struct _tagged_string _temp466; _temp466.curr= _temp465; _temp466.base= _temp465;
_temp466.last_plus_one= _temp465 + 38; _temp466;}), _temp408->loc); goto _LL429;
_LL429:;}} else{ Cyc_Parse_err( Cyc_Parse_msg3, _temp408->loc);} goto _LL383;
_LL383:;} if( ! seen_type){ if( ! seen_sign? ! seen_size: 0){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp467=( char*)"missing type withing specifier";
struct _tagged_string _temp468; _temp468.curr= _temp467; _temp468.base= _temp467;
_temp468.last_plus_one= _temp467 + 31; _temp468;}), last_loc);} t=( void*)({
struct Cyc_Absyn_IntType_struct* _temp469=( struct Cyc_Absyn_IntType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_IntType_struct)); _temp469[ 0]=({ struct Cyc_Absyn_IntType_struct
_temp470; _temp470.tag= Cyc_Absyn_IntType; _temp470.f1=( void*) sgn; _temp470.f2=(
void*) sz; _temp470;}); _temp469;});} else{ if( seen_sign){ void* _temp471= t;
void* _temp477; void* _temp479; _LL473: if(( unsigned int) _temp471 > 4u?*(( int*)
_temp471) == Cyc_Absyn_IntType: 0){ _LL480: _temp479=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp471)->f1; goto _LL478; _LL478: _temp477=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp471)->f2; goto _LL474;} else{ goto _LL475;} _LL475: goto _LL476; _LL474: t=(
void*)({ struct Cyc_Absyn_IntType_struct* _temp481=( struct Cyc_Absyn_IntType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_IntType_struct)); _temp481[ 0]=({ struct Cyc_Absyn_IntType_struct
_temp482; _temp482.tag= Cyc_Absyn_IntType; _temp482.f1=( void*) sgn; _temp482.f2=(
void*) _temp477; _temp482;}); _temp481;}); goto _LL472; _LL476: Cyc_Parse_err((
struct _tagged_string)({ char* _temp483=( char*)"sign specification on non-integral type";
struct _tagged_string _temp484; _temp484.curr= _temp483; _temp484.base= _temp483;
_temp484.last_plus_one= _temp483 + 40; _temp484;}), last_loc); goto _LL472;
_LL472:;} if( seen_size){ void* _temp485= t; void* _temp491; void* _temp493;
_LL487: if(( unsigned int) _temp485 > 4u?*(( int*) _temp485) == Cyc_Absyn_IntType:
0){ _LL494: _temp493=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp485)->f1;
goto _LL492; _LL492: _temp491=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp485)->f2; goto _LL488;} else{ goto _LL489;} _LL489: goto _LL490; _LL488: t=(
void*)({ struct Cyc_Absyn_IntType_struct* _temp495=( struct Cyc_Absyn_IntType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_IntType_struct)); _temp495[ 0]=({ struct Cyc_Absyn_IntType_struct
_temp496; _temp496.tag= Cyc_Absyn_IntType; _temp496.f1=( void*) _temp493;
_temp496.f2=( void*) sz; _temp496;}); _temp495;}); goto _LL486; _LL490: Cyc_Parse_err((
struct _tagged_string)({ char* _temp497=( char*)"size qualifier on non-integral type";
struct _tagged_string _temp498; _temp498.curr= _temp497; _temp498.base= _temp497;
_temp498.last_plus_one= _temp497 + 36; _temp498;}), last_loc); goto _LL486;
_LL486:;}} return({ struct _tuple5 _temp499; _temp499.f1= t; _temp499.f2=
declopt; _temp499;});} static struct Cyc_List_List* Cyc_Parse_apply_tmss( struct
Cyc_Absyn_Tqual tq, void* t, struct Cyc_List_List* ds, struct Cyc_List_List*
shared_atts){ if( ds == 0){ return 0;}{ struct Cyc_Parse_Declarator* d=( struct
Cyc_Parse_Declarator*)({ struct Cyc_List_List* _temp513= ds; if( _temp513 == 0){
_throw( Null_Exception);} _temp513->hd;}); struct _tuple1* q= d->id; struct Cyc_List_List*
_temp502; struct Cyc_List_List* _temp504; void* _temp506; struct Cyc_Absyn_Tqual
_temp508; struct _tuple6 _temp500= Cyc_Parse_apply_tms( tq, t, shared_atts, d->tms);
_LL509: _temp508= _temp500.f1; goto _LL507; _LL507: _temp506= _temp500.f2; goto
_LL505; _LL505: _temp504= _temp500.f3; goto _LL503; _LL503: _temp502= _temp500.f4;
goto _LL501; _LL501: return({ struct Cyc_List_List* _temp510=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp510->hd=( void*)({ struct
_tuple7* _temp512=( struct _tuple7*) GC_malloc( sizeof( struct _tuple7));
_temp512->f1= q; _temp512->f2= _temp508; _temp512->f3= _temp506; _temp512->f4=
_temp504; _temp512->f5= _temp502; _temp512;}); _temp510->tl= Cyc_Parse_apply_tmss(
_temp508, t,({ struct Cyc_List_List* _temp511= ds; if( _temp511 == 0){ _throw(
Null_Exception);} _temp511->tl;}), shared_atts); _temp510;});}} static int Cyc_Parse_fn_type_att(
void* a){ void* _temp514= a; int _temp528; _LL516: if(( unsigned int) _temp514 >
15u?*(( int*) _temp514) == Cyc_Absyn_Regparm_att: 0){ _LL529: _temp528=( int)((
struct Cyc_Absyn_Regparm_att_struct*) _temp514)->f1; goto _LL517;} else{ goto
_LL518;} _LL518: if( _temp514 ==( void*) Cyc_Absyn_Stdcall_att){ goto _LL519;}
else{ goto _LL520;} _LL520: if( _temp514 ==( void*) Cyc_Absyn_Cdecl_att){ goto
_LL521;} else{ goto _LL522;} _LL522: if( _temp514 ==( void*) Cyc_Absyn_Noreturn_att){
goto _LL523;} else{ goto _LL524;} _LL524: if( _temp514 ==( void*) Cyc_Absyn_Const_att){
goto _LL525;} else{ goto _LL526;} _LL526: goto _LL527; _LL517: goto _LL519;
_LL519: goto _LL521; _LL521: goto _LL523; _LL523: goto _LL525; _LL525: return 1;
_LL527: return 0; _LL515:;} static struct _tuple6 Cyc_Parse_apply_tms( struct
Cyc_Absyn_Tqual tq, void* t, struct Cyc_List_List* atts, struct Cyc_List_List*
tms){ if( tms == 0){ return({ struct _tuple6 _temp530; _temp530.f1= tq; _temp530.f2=
t; _temp530.f3= 0; _temp530.f4= atts; _temp530;});}{ void* _temp532=( void*)({
struct Cyc_List_List* _temp531= tms; if( _temp531 == 0){ _throw( Null_Exception);}
_temp531->hd;}); struct Cyc_Absyn_Exp* _temp546; void* _temp548; int _temp550;
struct Cyc_Position_Segment* _temp552; struct Cyc_List_List* _temp554; struct
Cyc_Absyn_Tqual _temp556; void* _temp558; void* _temp560; struct Cyc_List_List*
_temp562; struct Cyc_Position_Segment* _temp564; _LL534: if( _temp532 ==( void*)
Cyc_Absyn_Carray_mod){ goto _LL535;} else{ goto _LL536;} _LL536: if((
unsigned int) _temp532 > 1u?*(( int*) _temp532) == Cyc_Absyn_ConstArray_mod: 0){
_LL547: _temp546=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_ConstArray_mod_struct*)
_temp532)->f1; goto _LL537;} else{ goto _LL538;} _LL538: if(( unsigned int)
_temp532 > 1u?*(( int*) _temp532) == Cyc_Absyn_Function_mod: 0){ _LL549:
_temp548=( void*)(( struct Cyc_Absyn_Function_mod_struct*) _temp532)->f1; goto
_LL539;} else{ goto _LL540;} _LL540: if(( unsigned int) _temp532 > 1u?*(( int*)
_temp532) == Cyc_Absyn_TypeParams_mod: 0){ _LL555: _temp554=( struct Cyc_List_List*)((
struct Cyc_Absyn_TypeParams_mod_struct*) _temp532)->f1; goto _LL553; _LL553:
_temp552=( struct Cyc_Position_Segment*)(( struct Cyc_Absyn_TypeParams_mod_struct*)
_temp532)->f2; goto _LL551; _LL551: _temp550=( int)(( struct Cyc_Absyn_TypeParams_mod_struct*)
_temp532)->f3; goto _LL541;} else{ goto _LL542;} _LL542: if(( unsigned int)
_temp532 > 1u?*(( int*) _temp532) == Cyc_Absyn_Pointer_mod: 0){ _LL561: _temp560=(
void*)(( struct Cyc_Absyn_Pointer_mod_struct*) _temp532)->f1; goto _LL559;
_LL559: _temp558=( void*)(( struct Cyc_Absyn_Pointer_mod_struct*) _temp532)->f2;
goto _LL557; _LL557: _temp556=( struct Cyc_Absyn_Tqual)(( struct Cyc_Absyn_Pointer_mod_struct*)
_temp532)->f3; goto _LL543;} else{ goto _LL544;} _LL544: if(( unsigned int)
_temp532 > 1u?*(( int*) _temp532) == Cyc_Absyn_Attributes_mod: 0){ _LL565:
_temp564=( struct Cyc_Position_Segment*)(( struct Cyc_Absyn_Attributes_mod_struct*)
_temp532)->f1; goto _LL563; _LL563: _temp562=( struct Cyc_List_List*)(( struct
Cyc_Absyn_Attributes_mod_struct*) _temp532)->f2; goto _LL545;} else{ goto _LL533;}
_LL535: return Cyc_Parse_apply_tms( Cyc_Absyn_empty_tqual(),( void*)({ struct
Cyc_Absyn_ArrayType_struct* _temp566=( struct Cyc_Absyn_ArrayType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_ArrayType_struct)); _temp566[ 0]=({ struct
Cyc_Absyn_ArrayType_struct _temp567; _temp567.tag= Cyc_Absyn_ArrayType; _temp567.f1=(
void*) t; _temp567.f2= tq; _temp567.f3= 0; _temp567;}); _temp566;}), atts,({
struct Cyc_List_List* _temp568= tms; if( _temp568 == 0){ _throw( Null_Exception);}
_temp568->tl;})); _LL537: return Cyc_Parse_apply_tms( Cyc_Absyn_empty_tqual(),(
void*)({ struct Cyc_Absyn_ArrayType_struct* _temp569=( struct Cyc_Absyn_ArrayType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_ArrayType_struct)); _temp569[ 0]=({ struct
Cyc_Absyn_ArrayType_struct _temp570; _temp570.tag= Cyc_Absyn_ArrayType; _temp570.f1=(
void*) t; _temp570.f2= tq; _temp570.f3=( struct Cyc_Absyn_Exp*) _temp546;
_temp570;}); _temp569;}), atts,({ struct Cyc_List_List* _temp571= tms; if(
_temp571 == 0){ _throw( Null_Exception);} _temp571->tl;})); _LL539: { void*
_temp572= _temp548; struct Cyc_Core_Opt* _temp578; int _temp580; struct Cyc_List_List*
_temp582; struct Cyc_Position_Segment* _temp584; struct Cyc_List_List* _temp586;
_LL574: if(*(( int*) _temp572) == Cyc_Absyn_WithTypes){ _LL583: _temp582=(
struct Cyc_List_List*)(( struct Cyc_Absyn_WithTypes_struct*) _temp572)->f1; goto
_LL581; _LL581: _temp580=( int)(( struct Cyc_Absyn_WithTypes_struct*) _temp572)->f2;
goto _LL579; _LL579: _temp578=( struct Cyc_Core_Opt*)(( struct Cyc_Absyn_WithTypes_struct*)
_temp572)->f3; goto _LL575;} else{ goto _LL576;} _LL576: if(*(( int*) _temp572)
== Cyc_Absyn_NoTypes){ _LL587: _temp586=( struct Cyc_List_List*)(( struct Cyc_Absyn_NoTypes_struct*)
_temp572)->f1; goto _LL585; _LL585: _temp584=( struct Cyc_Position_Segment*)((
struct Cyc_Absyn_NoTypes_struct*) _temp572)->f2; goto _LL577;} else{ goto _LL573;}
_LL575: { struct Cyc_List_List* typvars= 0; struct Cyc_List_List* fn_atts= 0;
struct Cyc_List_List* new_atts= 0;{ struct Cyc_List_List* as= atts; for( 0; as
!= 0; as=({ struct Cyc_List_List* _temp588= as; if( _temp588 == 0){ _throw(
Null_Exception);} _temp588->tl;})){ if( Cyc_Parse_fn_type_att(( void*)({ struct
Cyc_List_List* _temp589= as; if( _temp589 == 0){ _throw( Null_Exception);}
_temp589->hd;}))){ fn_atts=({ struct Cyc_List_List* _temp590=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp590->hd=( void*)(( void*)({
struct Cyc_List_List* _temp591= as; if( _temp591 == 0){ _throw( Null_Exception);}
_temp591->hd;})); _temp590->tl= fn_atts; _temp590;});} else{ new_atts=({ struct
Cyc_List_List* _temp592=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp592->hd=( void*)(( void*)({ struct Cyc_List_List* _temp593= as; if(
_temp593 == 0){ _throw( Null_Exception);} _temp593->hd;})); _temp592->tl=
new_atts; _temp592;});}}} if(({ struct Cyc_List_List* _temp594= tms; if(
_temp594 == 0){ _throw( Null_Exception);} _temp594->tl;}) != 0){ void* _temp597=(
void*)({ struct Cyc_List_List* _temp596=({ struct Cyc_List_List* _temp595= tms;
if( _temp595 == 0){ _throw( Null_Exception);} _temp595->tl;}); if( _temp596 == 0){
_throw( Null_Exception);} _temp596->hd;}); int _temp603; struct Cyc_Position_Segment*
_temp605; struct Cyc_List_List* _temp607; _LL599: if(( unsigned int) _temp597 >
1u?*(( int*) _temp597) == Cyc_Absyn_TypeParams_mod: 0){ _LL608: _temp607=(
struct Cyc_List_List*)(( struct Cyc_Absyn_TypeParams_mod_struct*) _temp597)->f1;
goto _LL606; _LL606: _temp605=( struct Cyc_Position_Segment*)(( struct Cyc_Absyn_TypeParams_mod_struct*)
_temp597)->f2; goto _LL604; _LL604: _temp603=( int)(( struct Cyc_Absyn_TypeParams_mod_struct*)
_temp597)->f3; goto _LL600;} else{ goto _LL601;} _LL601: goto _LL602; _LL600:
typvars= _temp607; tms=({ struct Cyc_List_List* _temp609= tms; if( _temp609 == 0){
_throw( Null_Exception);} _temp609->tl;}); goto _LL598; _LL602: goto _LL598;
_LL598:;} if(((( ! _temp580? _temp582 != 0: 0)?({ struct Cyc_List_List* _temp610=
_temp582; if( _temp610 == 0){ _throw( Null_Exception);} _temp610->tl;}) == 0: 0)?(*((
struct _tuple2*)({ struct Cyc_List_List* _temp611= _temp582; if( _temp611 == 0){
_throw( Null_Exception);} _temp611->hd;}))).f1 == 0: 0)?(*(( struct _tuple2*)({
struct Cyc_List_List* _temp612= _temp582; if( _temp612 == 0){ _throw(
Null_Exception);} _temp612->hd;}))).f3 ==( void*) Cyc_Absyn_VoidType: 0){
_temp582= 0; _temp580= 0;} t= Cyc_Parse_array2ptr( t);(( void(*)( void(* f)(
struct _tuple2*), struct Cyc_List_List* x)) Cyc_List_iter)( Cyc_Parse_arg_array2ptr,
_temp582); return Cyc_Parse_apply_tms( Cyc_Absyn_empty_tqual(), Cyc_Absyn_function_typ(
typvars, _temp578, t, _temp582, _temp580, fn_atts), new_atts,({ struct Cyc_List_List*
_temp613= tms; if( _temp613 == 0){ _throw( Null_Exception);} _temp613->tl;}));}
_LL577:( void) _throw((( void*(*)( struct _tagged_string msg, struct Cyc_Position_Segment*
sg)) Cyc_Parse_abort)(( struct _tagged_string)({ char* _temp614=( char*)"function declaration without parameter types";
struct _tagged_string _temp615; _temp615.curr= _temp614; _temp615.base= _temp614;
_temp615.last_plus_one= _temp614 + 45; _temp615;}), _temp584)); _LL573:;} _LL541:
if(({ struct Cyc_List_List* _temp616= tms; if( _temp616 == 0){ _throw(
Null_Exception);} _temp616->tl;}) == 0){ return({ struct _tuple6 _temp617;
_temp617.f1= tq; _temp617.f2= t; _temp617.f3= _temp554; _temp617.f4= atts;
_temp617;});}( void) _throw((( void*(*)( struct _tagged_string msg, struct Cyc_Position_Segment*
sg)) Cyc_Parse_abort)(( struct _tagged_string)({ char* _temp618=( char*)"type parameters must appear before function arguments in declarator";
struct _tagged_string _temp619; _temp619.curr= _temp618; _temp619.base= _temp618;
_temp619.last_plus_one= _temp618 + 68; _temp619;}), _temp552)); _LL543: { void*
_temp620= _temp560; struct Cyc_Absyn_Exp* _temp628; struct Cyc_Absyn_Exp*
_temp630; _LL622: if(( unsigned int) _temp620 > 1u?*(( int*) _temp620) == Cyc_Absyn_NonNullable_ps:
0){ _LL629: _temp628=( struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_NonNullable_ps_struct*)
_temp620)->f1; goto _LL623;} else{ goto _LL624;} _LL624: if(( unsigned int)
_temp620 > 1u?*(( int*) _temp620) == Cyc_Absyn_Nullable_ps: 0){ _LL631: _temp630=(
struct Cyc_Absyn_Exp*)(( struct Cyc_Absyn_Nullable_ps_struct*) _temp620)->f1;
goto _LL625;} else{ goto _LL626;} _LL626: if( _temp620 ==( void*) Cyc_Absyn_TaggedArray_ps){
goto _LL627;} else{ goto _LL621;} _LL623: return Cyc_Parse_apply_tms( _temp556,
Cyc_Absyn_atb_typ( t, _temp558, tq,( void*)({ struct Cyc_Absyn_Upper_b_struct*
_temp632=( struct Cyc_Absyn_Upper_b_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct));
_temp632[ 0]=({ struct Cyc_Absyn_Upper_b_struct _temp633; _temp633.tag= Cyc_Absyn_Upper_b;
_temp633.f1= _temp628; _temp633;}); _temp632;})), atts,({ struct Cyc_List_List*
_temp634= tms; if( _temp634 == 0){ _throw( Null_Exception);} _temp634->tl;}));
_LL625: return Cyc_Parse_apply_tms( _temp556, Cyc_Absyn_starb_typ( t, _temp558,
tq,( void*)({ struct Cyc_Absyn_Upper_b_struct* _temp635=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp635[ 0]=({ struct Cyc_Absyn_Upper_b_struct
_temp636; _temp636.tag= Cyc_Absyn_Upper_b; _temp636.f1= _temp630; _temp636;});
_temp635;})), atts,({ struct Cyc_List_List* _temp637= tms; if( _temp637 == 0){
_throw( Null_Exception);} _temp637->tl;})); _LL627: return Cyc_Parse_apply_tms(
_temp556, Cyc_Absyn_tagged_typ( t, _temp558, tq), atts,({ struct Cyc_List_List*
_temp638= tms; if( _temp638 == 0){ _throw( Null_Exception);} _temp638->tl;}));
_LL621:;} _LL545: return Cyc_Parse_apply_tms( tq, t,(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_append)( atts,
_temp562),({ struct Cyc_List_List* _temp639= tms; if( _temp639 == 0){ _throw(
Null_Exception);} _temp639->tl;})); _LL533:;}} void* Cyc_Parse_speclist2typ(
struct Cyc_List_List* tss, struct Cyc_Position_Segment* loc){ struct Cyc_Core_Opt*
_temp642; void* _temp644; struct _tuple5 _temp640= Cyc_Parse_collapse_type_specifiers(
tss, loc); _LL645: _temp644= _temp640.f1; goto _LL643; _LL643: _temp642=
_temp640.f2; goto _LL641; _LL641: if( _temp642 != 0){ Cyc_Parse_warn(( struct
_tagged_string)({ char* _temp646=( char*)"ignoring nested type declaration(s) in specifier list";
struct _tagged_string _temp647; _temp647.curr= _temp646; _temp647.base= _temp646;
_temp647.last_plus_one= _temp646 + 54; _temp647;}), loc);} return _temp644;}
static struct Cyc_Absyn_Stmt* Cyc_Parse_flatten_decl( struct Cyc_Absyn_Decl* d,
struct Cyc_Absyn_Stmt* s){ return Cyc_Absyn_new_stmt(( void*)({ struct Cyc_Absyn_Decl_s_struct*
_temp648=( struct Cyc_Absyn_Decl_s_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Decl_s_struct));
_temp648[ 0]=({ struct Cyc_Absyn_Decl_s_struct _temp649; _temp649.tag= Cyc_Absyn_Decl_s;
_temp649.f1= d; _temp649.f2= s; _temp649;}); _temp648;}), Cyc_Position_segment_join(
d->loc, s->loc));} static struct Cyc_Absyn_Stmt* Cyc_Parse_flatten_declarations(
struct Cyc_List_List* ds, struct Cyc_Absyn_Stmt* s){ return(( struct Cyc_Absyn_Stmt*(*)(
struct Cyc_Absyn_Stmt*(* f)( struct Cyc_Absyn_Decl*, struct Cyc_Absyn_Stmt*),
struct Cyc_List_List* x, struct Cyc_Absyn_Stmt* accum)) Cyc_List_fold_right)(
Cyc_Parse_flatten_decl, ds, s);} static struct Cyc_List_List* Cyc_Parse_make_declarations(
struct Cyc_Parse_Declaration_spec* ds, struct Cyc_List_List* ids, struct Cyc_Position_Segment*
loc){ struct Cyc_List_List* tss= ds->type_specs; struct Cyc_Absyn_Tqual tq= ds->tq;
int istypedef= 0; void* s=( void*) Cyc_Absyn_Public; struct Cyc_List_List* atts=
ds->attributes; if( ds->is_inline){ Cyc_Parse_err(( struct _tagged_string)({
char* _temp650=( char*)"inline is only allowed on function definitions"; struct
_tagged_string _temp651; _temp651.curr= _temp650; _temp651.base= _temp650;
_temp651.last_plus_one= _temp650 + 47; _temp651;}), loc);} if( tss == 0){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp652=( char*)"missing type specifiers in declaration";
struct _tagged_string _temp653; _temp653.curr= _temp652; _temp653.base= _temp652;
_temp653.last_plus_one= _temp652 + 39; _temp653;}), loc); return 0;} if( ds->sc
!= 0){ void* _temp655=( void*)({ struct Cyc_Core_Opt* _temp654= ds->sc; if(
_temp654 == 0){ _throw( Null_Exception);} _temp654->v;}); _LL657: if( _temp655
==( void*) Cyc_Parse_Typedef_sc){ goto _LL658;} else{ goto _LL659;} _LL659: if(
_temp655 ==( void*) Cyc_Parse_Extern_sc){ goto _LL660;} else{ goto _LL661;}
_LL661: if( _temp655 ==( void*) Cyc_Parse_ExternC_sc){ goto _LL662;} else{ goto
_LL663;} _LL663: if( _temp655 ==( void*) Cyc_Parse_Static_sc){ goto _LL664;}
else{ goto _LL665;} _LL665: if( _temp655 ==( void*) Cyc_Parse_Auto_sc){ goto
_LL666;} else{ goto _LL667;} _LL667: if( _temp655 ==( void*) Cyc_Parse_Register_sc){
goto _LL668;} else{ goto _LL669;} _LL669: if( _temp655 ==( void*) Cyc_Parse_Abstract_sc){
goto _LL670;} else{ goto _LL656;} _LL658: istypedef= 1; goto _LL656; _LL660: s=(
void*) Cyc_Absyn_Extern; goto _LL656; _LL662: s=( void*) Cyc_Absyn_ExternC; goto
_LL656; _LL664: s=( void*) Cyc_Absyn_Static; goto _LL656; _LL666: s=( void*) Cyc_Absyn_Public;
goto _LL656; _LL668: s=( void*) Cyc_Absyn_Public; goto _LL656; _LL670: s=( void*)
Cyc_Absyn_Abstract; goto _LL656; _LL656:;}{ struct Cyc_List_List* _temp673;
struct Cyc_List_List* _temp675; struct _tuple0 _temp671=(( struct _tuple0(*)(
struct Cyc_List_List* x)) Cyc_List_split)( ids); _LL676: _temp675= _temp671.f1;
goto _LL674; _LL674: _temp673= _temp671.f2; goto _LL672; _LL672: { int
exps_empty= 1;{ struct Cyc_List_List* es= _temp673; for( 0; es != 0; es=({
struct Cyc_List_List* _temp677= es; if( _temp677 == 0){ _throw( Null_Exception);}
_temp677->tl;})){ if(( struct Cyc_Absyn_Exp*)({ struct Cyc_List_List* _temp678=
es; if( _temp678 == 0){ _throw( Null_Exception);} _temp678->hd;}) != 0){
exps_empty= 0; break;}}}{ struct _tuple5 ts_info= Cyc_Parse_collapse_type_specifiers(
tss, loc); if( _temp675 == 0){ struct Cyc_Core_Opt* _temp681; void* _temp683;
struct _tuple5 _temp679= ts_info; _LL684: _temp683= _temp679.f1; goto _LL682;
_LL682: _temp681= _temp679.f2; goto _LL680; _LL680: if( _temp681 != 0){ struct
Cyc_Absyn_Decl* d=( struct Cyc_Absyn_Decl*)({ struct Cyc_Core_Opt* _temp712=
_temp681; if( _temp712 == 0){ _throw( Null_Exception);} _temp712->v;});{ void*
_temp685=( void*) d->r; struct Cyc_Absyn_Enumdecl* _temp697; struct Cyc_Absyn_Structdecl*
_temp699; struct Cyc_Absyn_Uniondecl* _temp701; struct Cyc_Absyn_Tuniondecl*
_temp703; _LL687: if(*(( int*) _temp685) == Cyc_Absyn_Enum_d){ _LL698: _temp697=(
struct Cyc_Absyn_Enumdecl*)(( struct Cyc_Absyn_Enum_d_struct*) _temp685)->f1;
goto _LL688;} else{ goto _LL689;} _LL689: if(*(( int*) _temp685) == Cyc_Absyn_Struct_d){
_LL700: _temp699=( struct Cyc_Absyn_Structdecl*)(( struct Cyc_Absyn_Struct_d_struct*)
_temp685)->f1; goto _LL690;} else{ goto _LL691;} _LL691: if(*(( int*) _temp685)
== Cyc_Absyn_Union_d){ _LL702: _temp701=( struct Cyc_Absyn_Uniondecl*)(( struct
Cyc_Absyn_Union_d_struct*) _temp685)->f1; goto _LL692;} else{ goto _LL693;}
_LL693: if(*(( int*) _temp685) == Cyc_Absyn_Tunion_d){ _LL704: _temp703=( struct
Cyc_Absyn_Tuniondecl*)(( struct Cyc_Absyn_Tunion_d_struct*) _temp685)->f1; goto
_LL694;} else{ goto _LL695;} _LL695: goto _LL696; _LL688:( void*)( _temp697->sc=(
void*) s); if( atts != 0){ Cyc_Parse_err(( struct _tagged_string)({ char*
_temp705=( char*)"bad attributes on enum"; struct _tagged_string _temp706;
_temp706.curr= _temp705; _temp706.base= _temp705; _temp706.last_plus_one=
_temp705 + 23; _temp706;}), loc);} goto _LL686; _LL690:( void*)( _temp699->sc=(
void*) s); _temp699->attributes= atts; goto _LL686; _LL692:( void*)( _temp701->sc=(
void*) s); _temp701->attributes= atts; goto _LL686; _LL694:( void*)( _temp703->sc=(
void*) s); if( atts != 0){ Cyc_Parse_err(( struct _tagged_string)({ char*
_temp707=( char*)"bad attributes on tunion"; struct _tagged_string _temp708;
_temp708.curr= _temp707; _temp708.base= _temp707; _temp708.last_plus_one=
_temp707 + 25; _temp708;}), loc);} goto _LL686; _LL696: Cyc_Parse_err(( struct
_tagged_string)({ char* _temp709=( char*)"bad declaration"; struct
_tagged_string _temp710; _temp710.curr= _temp709; _temp710.base= _temp709;
_temp710.last_plus_one= _temp709 + 16; _temp710;}), loc); return 0; _LL686:;}
return({ struct Cyc_List_List* _temp711=( struct Cyc_List_List*) GC_malloc(
sizeof( struct Cyc_List_List)); _temp711->hd=( void*) d; _temp711->tl= 0;
_temp711;});} else{ void* _temp713= _temp683; struct Cyc_Absyn_Structdecl**
_temp727; struct Cyc_List_List* _temp729; struct _tuple1* _temp731; struct Cyc_Absyn_TunionInfo
_temp733; void* _temp735; struct Cyc_List_List* _temp737; void* _temp739; struct
Cyc_Absyn_Tuniondecl* _temp741; struct Cyc_Absyn_TunionInfo _temp743; void*
_temp745; struct Cyc_List_List* _temp747; void* _temp749; struct Cyc_Absyn_UnknownTunionInfo
_temp751; int _temp753; struct _tuple1* _temp755; struct Cyc_Absyn_Uniondecl**
_temp757; struct Cyc_List_List* _temp759; struct _tuple1* _temp761; struct Cyc_Absyn_Enumdecl*
_temp763; struct _tuple1* _temp765; _LL715: if(( unsigned int) _temp713 > 4u?*((
int*) _temp713) == Cyc_Absyn_StructType: 0){ _LL732: _temp731=( struct _tuple1*)((
struct Cyc_Absyn_StructType_struct*) _temp713)->f1; goto _LL730; _LL730:
_temp729=( struct Cyc_List_List*)(( struct Cyc_Absyn_StructType_struct*)
_temp713)->f2; goto _LL728; _LL728: _temp727=( struct Cyc_Absyn_Structdecl**)((
struct Cyc_Absyn_StructType_struct*) _temp713)->f3; goto _LL716;} else{ goto
_LL717;} _LL717: if(( unsigned int) _temp713 > 4u?*(( int*) _temp713) == Cyc_Absyn_TunionType:
0){ _LL734: _temp733=( struct Cyc_Absyn_TunionInfo)(( struct Cyc_Absyn_TunionType_struct*)
_temp713)->f1; _LL740: _temp739=( void*) _temp733.tunion_info; if(*(( int*)
_temp739) == Cyc_Absyn_KnownTunion){ _LL742: _temp741=( struct Cyc_Absyn_Tuniondecl*)((
struct Cyc_Absyn_KnownTunion_struct*) _temp739)->f1; goto _LL738;} else{ goto
_LL719;} _LL738: _temp737=( struct Cyc_List_List*) _temp733.targs; goto _LL736;
_LL736: _temp735=( void*) _temp733.rgn; goto _LL718;} else{ goto _LL719;} _LL719:
if(( unsigned int) _temp713 > 4u?*(( int*) _temp713) == Cyc_Absyn_TunionType: 0){
_LL744: _temp743=( struct Cyc_Absyn_TunionInfo)(( struct Cyc_Absyn_TunionType_struct*)
_temp713)->f1; _LL750: _temp749=( void*) _temp743.tunion_info; if(*(( int*)
_temp749) == Cyc_Absyn_UnknownTunion){ _LL752: _temp751=( struct Cyc_Absyn_UnknownTunionInfo)((
struct Cyc_Absyn_UnknownTunion_struct*) _temp749)->f1; _LL756: _temp755=( struct
_tuple1*) _temp751.name; goto _LL754; _LL754: _temp753=( int) _temp751.is_xtunion;
goto _LL748;} else{ goto _LL721;} _LL748: _temp747=( struct Cyc_List_List*)
_temp743.targs; goto _LL746; _LL746: _temp745=( void*) _temp743.rgn; goto _LL720;}
else{ goto _LL721;} _LL721: if(( unsigned int) _temp713 > 4u?*(( int*) _temp713)
== Cyc_Absyn_UnionType: 0){ _LL762: _temp761=( struct _tuple1*)(( struct Cyc_Absyn_UnionType_struct*)
_temp713)->f1; goto _LL760; _LL760: _temp759=( struct Cyc_List_List*)(( struct
Cyc_Absyn_UnionType_struct*) _temp713)->f2; goto _LL758; _LL758: _temp757=(
struct Cyc_Absyn_Uniondecl**)(( struct Cyc_Absyn_UnionType_struct*) _temp713)->f3;
goto _LL722;} else{ goto _LL723;} _LL723: if(( unsigned int) _temp713 > 4u?*((
int*) _temp713) == Cyc_Absyn_EnumType: 0){ _LL766: _temp765=( struct _tuple1*)((
struct Cyc_Absyn_EnumType_struct*) _temp713)->f1; goto _LL764; _LL764: _temp763=(
struct Cyc_Absyn_Enumdecl*)(( struct Cyc_Absyn_EnumType_struct*) _temp713)->f2;
goto _LL724;} else{ goto _LL725;} _LL725: goto _LL726; _LL716: { struct Cyc_List_List*
ts2=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(* f)( struct Cyc_Position_Segment*,
void*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x)) Cyc_List_map_c)(
Cyc_Parse_typ2tvar, loc, _temp729); struct Cyc_Absyn_Structdecl* sd=({ struct
Cyc_Absyn_Structdecl* _temp772=( struct Cyc_Absyn_Structdecl*) GC_malloc(
sizeof( struct Cyc_Absyn_Structdecl)); _temp772->sc=( void*) s; _temp772->name=({
struct Cyc_Core_Opt* _temp773=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp773->v=( void*)(( struct _tuple1*)({ struct _tuple1*
_temp774= _temp731; if( _temp774 == 0){ _throw( Null_Exception);} _temp774;}));
_temp773;}); _temp772->tvs= ts2; _temp772->fields= 0; _temp772->attributes= 0;
_temp772;}); if( atts != 0){ Cyc_Parse_err(( struct _tagged_string)({ char*
_temp767=( char*)"bad attributes on struct"; struct _tagged_string _temp768;
_temp768.curr= _temp767; _temp768.base= _temp767; _temp768.last_plus_one=
_temp767 + 25; _temp768;}), loc);} return({ struct Cyc_List_List* _temp769=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp769->hd=(
void*) Cyc_Absyn_new_decl(( void*)({ struct Cyc_Absyn_Struct_d_struct* _temp770=(
struct Cyc_Absyn_Struct_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Struct_d_struct));
_temp770[ 0]=({ struct Cyc_Absyn_Struct_d_struct _temp771; _temp771.tag= Cyc_Absyn_Struct_d;
_temp771.f1= sd; _temp771;}); _temp770;}), loc); _temp769->tl= 0; _temp769;});}
_LL718: if( atts != 0){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp775=(
char*)"bad attributes on tunion"; struct _tagged_string _temp776; _temp776.curr=
_temp775; _temp776.base= _temp775; _temp776.last_plus_one= _temp775 + 25;
_temp776;}), loc);} return({ struct Cyc_List_List* _temp777=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp777->hd=( void*) Cyc_Absyn_new_decl((
void*)({ struct Cyc_Absyn_Tunion_d_struct* _temp778=( struct Cyc_Absyn_Tunion_d_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Tunion_d_struct)); _temp778[ 0]=({ struct
Cyc_Absyn_Tunion_d_struct _temp779; _temp779.tag= Cyc_Absyn_Tunion_d; _temp779.f1=
_temp741; _temp779;}); _temp778;}), loc); _temp777->tl= 0; _temp777;}); _LL720: {
struct Cyc_List_List* ts2=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(*
f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment* env,
struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, loc, _temp747);
struct Cyc_Absyn_Decl* tud= Cyc_Absyn_tunion_decl( s, _temp755, ts2, 0, _temp753,
loc); if( atts != 0){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp780=(
char*)"bad attributes on tunion"; struct _tagged_string _temp781; _temp781.curr=
_temp780; _temp781.base= _temp780; _temp781.last_plus_one= _temp780 + 25;
_temp781;}), loc);} return({ struct Cyc_List_List* _temp782=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp782->hd=( void*) tud; _temp782->tl=
0; _temp782;});} _LL722: { struct Cyc_List_List* ts2=(( struct Cyc_List_List*(*)(
struct Cyc_Absyn_Tvar*(* f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment*
env, struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, loc,
_temp759); struct Cyc_Absyn_Uniondecl* ud=({ struct Cyc_Absyn_Uniondecl*
_temp789=( struct Cyc_Absyn_Uniondecl*) GC_malloc( sizeof( struct Cyc_Absyn_Uniondecl));
_temp789->sc=( void*) s; _temp789->name=({ struct Cyc_Core_Opt* _temp790=(
struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp790->v=(
void*)(( struct _tuple1*)({ struct _tuple1* _temp791= _temp761; if( _temp791 ==
0){ _throw( Null_Exception);} _temp791;})); _temp790;}); _temp789->tvs= ts2;
_temp789->fields= 0; _temp789->attributes= 0; _temp789;}); if( atts != 0){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp783=( char*)"bad attributes on union";
struct _tagged_string _temp784; _temp784.curr= _temp783; _temp784.base= _temp783;
_temp784.last_plus_one= _temp783 + 24; _temp784;}), loc);} return({ struct Cyc_List_List*
_temp785=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp785->hd=( void*)({ struct Cyc_Absyn_Decl* _temp786=( struct Cyc_Absyn_Decl*)
GC_malloc( sizeof( struct Cyc_Absyn_Decl)); _temp786->r=( void*)(( void*)({
struct Cyc_Absyn_Union_d_struct* _temp787=( struct Cyc_Absyn_Union_d_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Union_d_struct)); _temp787[ 0]=({ struct Cyc_Absyn_Union_d_struct
_temp788; _temp788.tag= Cyc_Absyn_Union_d; _temp788.f1= ud; _temp788;});
_temp787;})); _temp786->loc= loc; _temp786;}); _temp785->tl= 0; _temp785;});}
_LL724: { struct Cyc_Absyn_Enumdecl* ed=({ struct Cyc_Absyn_Enumdecl* _temp798=(
struct Cyc_Absyn_Enumdecl*) GC_malloc( sizeof( struct Cyc_Absyn_Enumdecl));
_temp798->sc=( void*) s; _temp798->name= _temp765; _temp798->fields= 0; _temp798;});
if( atts != 0){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp792=( char*)"bad attributes on enum";
struct _tagged_string _temp793; _temp793.curr= _temp792; _temp793.base= _temp792;
_temp793.last_plus_one= _temp792 + 23; _temp793;}), loc);} return({ struct Cyc_List_List*
_temp794=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp794->hd=( void*)({ struct Cyc_Absyn_Decl* _temp795=( struct Cyc_Absyn_Decl*)
GC_malloc( sizeof( struct Cyc_Absyn_Decl)); _temp795->r=( void*)(( void*)({
struct Cyc_Absyn_Enum_d_struct* _temp796=( struct Cyc_Absyn_Enum_d_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Enum_d_struct)); _temp796[ 0]=({ struct Cyc_Absyn_Enum_d_struct
_temp797; _temp797.tag= Cyc_Absyn_Enum_d; _temp797.f1= ed; _temp797;}); _temp796;}));
_temp795->loc= loc; _temp795;}); _temp794->tl= 0; _temp794;});} _LL726: Cyc_Parse_err((
struct _tagged_string)({ char* _temp799=( char*)"missing declarator"; struct
_tagged_string _temp800; _temp800.curr= _temp799; _temp800.base= _temp799;
_temp800.last_plus_one= _temp799 + 19; _temp800;}), loc); return 0; _LL714:;}}
else{ void* t= ts_info.f1; struct Cyc_List_List* fields= Cyc_Parse_apply_tmss(
tq, t, _temp675, atts); if( istypedef){ if( ! exps_empty){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp801=( char*)"initializer in typedef declaration";
struct _tagged_string _temp802; _temp802.curr= _temp801; _temp802.base= _temp801;
_temp802.last_plus_one= _temp801 + 35; _temp802;}), loc);}{ struct Cyc_List_List*
decls=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Decl*(* f)( struct Cyc_Position_Segment*,
struct _tuple7*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x))
Cyc_List_map_c)( Cyc_Parse_v_typ_to_typedef, loc, fields); if( ts_info.f2 != 0){
struct Cyc_Absyn_Decl* d=( struct Cyc_Absyn_Decl*)({ struct Cyc_Core_Opt*
_temp826= ts_info.f2; if( _temp826 == 0){ _throw( Null_Exception);} _temp826->v;});{
void* _temp803=( void*) d->r; struct Cyc_Absyn_Structdecl* _temp815; struct Cyc_Absyn_Tuniondecl*
_temp817; struct Cyc_Absyn_Uniondecl* _temp819; struct Cyc_Absyn_Enumdecl*
_temp821; _LL805: if(*(( int*) _temp803) == Cyc_Absyn_Struct_d){ _LL816:
_temp815=( struct Cyc_Absyn_Structdecl*)(( struct Cyc_Absyn_Struct_d_struct*)
_temp803)->f1; goto _LL806;} else{ goto _LL807;} _LL807: if(*(( int*) _temp803)
== Cyc_Absyn_Tunion_d){ _LL818: _temp817=( struct Cyc_Absyn_Tuniondecl*)((
struct Cyc_Absyn_Tunion_d_struct*) _temp803)->f1; goto _LL808;} else{ goto
_LL809;} _LL809: if(*(( int*) _temp803) == Cyc_Absyn_Union_d){ _LL820: _temp819=(
struct Cyc_Absyn_Uniondecl*)(( struct Cyc_Absyn_Union_d_struct*) _temp803)->f1;
goto _LL810;} else{ goto _LL811;} _LL811: if(*(( int*) _temp803) == Cyc_Absyn_Enum_d){
_LL822: _temp821=( struct Cyc_Absyn_Enumdecl*)(( struct Cyc_Absyn_Enum_d_struct*)
_temp803)->f1; goto _LL812;} else{ goto _LL813;} _LL813: goto _LL814; _LL806:(
void*)( _temp815->sc=( void*) s); _temp815->attributes= atts; atts= 0; goto
_LL804; _LL808:( void*)( _temp817->sc=( void*) s); goto _LL804; _LL810:( void*)(
_temp819->sc=( void*) s); goto _LL804; _LL812:( void*)( _temp821->sc=( void*) s);
goto _LL804; _LL814: Cyc_Parse_err(( struct _tagged_string)({ char* _temp823=(
char*)"declaration within typedef is not a struct, union, tunion, or xtunion";
struct _tagged_string _temp824; _temp824.curr= _temp823; _temp824.base= _temp823;
_temp824.last_plus_one= _temp823 + 70; _temp824;}), loc); goto _LL804; _LL804:;}
decls=({ struct Cyc_List_List* _temp825=( struct Cyc_List_List*) GC_malloc(
sizeof( struct Cyc_List_List)); _temp825->hd=( void*) d; _temp825->tl= decls;
_temp825;});} if( atts != 0){ Cyc_Parse_err(({ struct _tagged_string _temp828=
Cyc_Absyn_attribute2string(( void*)({ struct Cyc_List_List* _temp827= atts; if(
_temp827 == 0){ _throw( Null_Exception);} _temp827->hd;})); xprintf("bad attribute %.*s in typedef",
_temp828.last_plus_one - _temp828.curr, _temp828.curr);}), loc);} return decls;}}
else{ if( ts_info.f2 != 0){ Cyc_Parse_unimp2(( struct _tagged_string)({ char*
_temp829=( char*)"nested type declaration within declarator"; struct
_tagged_string _temp830; _temp830.curr= _temp829; _temp830.base= _temp829;
_temp830.last_plus_one= _temp829 + 42; _temp830;}), loc);}{ struct Cyc_List_List*
decls= 0;{ struct Cyc_List_List* ds= fields; for( 0; ds != 0; ds=({ struct Cyc_List_List*
_temp831= ds; if( _temp831 == 0){ _throw( Null_Exception);} _temp831->tl;}),
_temp673=({ struct Cyc_List_List* _temp832= _temp673; if( _temp832 == 0){ _throw(
Null_Exception);} _temp832->tl;})){ struct _tuple7 _temp836; struct Cyc_List_List*
_temp837; struct Cyc_List_List* _temp839; void* _temp841; struct Cyc_Absyn_Tqual
_temp843; struct _tuple1* _temp845; struct _tuple7* _temp834=( struct _tuple7*)({
struct Cyc_List_List* _temp833= ds; if( _temp833 == 0){ _throw( Null_Exception);}
_temp833->hd;}); _temp836=* _temp834; _LL846: _temp845= _temp836.f1; goto _LL844;
_LL844: _temp843= _temp836.f2; goto _LL842; _LL842: _temp841= _temp836.f3; goto
_LL840; _LL840: _temp839= _temp836.f4; goto _LL838; _LL838: _temp837= _temp836.f5;
goto _LL835; _LL835: if( _temp839 != 0){ Cyc_Parse_warn(( struct _tagged_string)({
char* _temp847=( char*)"bad type params, ignoring"; struct _tagged_string
_temp848; _temp848.curr= _temp847; _temp848.base= _temp847; _temp848.last_plus_one=
_temp847 + 26; _temp848;}), loc);} if( _temp673 == 0){(( void(*)( struct
_tagged_string msg, struct Cyc_Position_Segment* sg)) Cyc_Parse_abort)(( struct
_tagged_string)({ char* _temp849=( char*)"unexpected null in parse!"; struct
_tagged_string _temp850; _temp850.curr= _temp849; _temp850.base= _temp849;
_temp850.last_plus_one= _temp849 + 26; _temp850;}), loc);}{ struct Cyc_Absyn_Exp*
eopt=( struct Cyc_Absyn_Exp*)({ struct Cyc_List_List* _temp855= _temp673; if(
_temp855 == 0){ _throw( Null_Exception);} _temp855->hd;}); struct Cyc_Absyn_Vardecl*
vd= Cyc_Absyn_new_vardecl( _temp845, _temp841, eopt); vd->tq= _temp843;( void*)(
vd->sc=( void*) s); vd->attributes= _temp837;{ struct Cyc_Absyn_Decl* d=({
struct Cyc_Absyn_Decl* _temp852=( struct Cyc_Absyn_Decl*) GC_malloc( sizeof(
struct Cyc_Absyn_Decl)); _temp852->r=( void*)(( void*)({ struct Cyc_Absyn_Var_d_struct*
_temp853=( struct Cyc_Absyn_Var_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Var_d_struct));
_temp853[ 0]=({ struct Cyc_Absyn_Var_d_struct _temp854; _temp854.tag= Cyc_Absyn_Var_d;
_temp854.f1= vd; _temp854;}); _temp853;})); _temp852->loc= loc; _temp852;});
decls=({ struct Cyc_List_List* _temp851=( struct Cyc_List_List*) GC_malloc(
sizeof( struct Cyc_List_List)); _temp851->hd=( void*) d; _temp851->tl= decls;
_temp851;});}}}} return(( struct Cyc_List_List*(*)( struct Cyc_List_List* x))
Cyc_List_imp_rev)( decls);}}}}}}} static void* Cyc_Parse_id_to_kind( struct
_tagged_string s, struct Cyc_Position_Segment* loc){ if( Cyc_String_strlen( s)
!= 1){ Cyc_Parse_err(({ struct _tagged_string _temp856= s; xprintf("bad kind: %.*s",
_temp856.last_plus_one - _temp856.curr, _temp856.curr);}), loc); return( void*)
Cyc_Absyn_BoxKind;} else{ switch(({ struct _tagged_string _temp857= s; char*
_temp859= _temp857.curr + 0; if( _temp857.base == 0? 1:( _temp859 < _temp857.base?
1: _temp859 >= _temp857.last_plus_one)){ _throw( Null_Exception);}* _temp859;})){
case 'A': _LL860: return( void*) Cyc_Absyn_AnyKind; case 'M': _LL861: return(
void*) Cyc_Absyn_MemKind; case 'B': _LL862: return( void*) Cyc_Absyn_BoxKind;
case 'R': _LL863: return( void*) Cyc_Absyn_RgnKind; case 'E': _LL864: return(
void*) Cyc_Absyn_EffKind; default: _LL865: Cyc_Parse_err(({ struct
_tagged_string _temp867= s; xprintf("bad kind: %.*s", _temp867.last_plus_one -
_temp867.curr, _temp867.curr);}), loc); return( void*) Cyc_Absyn_BoxKind;}}}
static struct Cyc_List_List* Cyc_Parse_attopt_to_tms( struct Cyc_Position_Segment*
loc, struct Cyc_List_List* atts, struct Cyc_List_List* tms){ if( atts == 0){
return tms;} else{ return({ struct Cyc_List_List* _temp868=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp868->hd=( void*)(( void*)({
struct Cyc_Absyn_Attributes_mod_struct* _temp869=( struct Cyc_Absyn_Attributes_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Attributes_mod_struct)); _temp869[ 0]=({
struct Cyc_Absyn_Attributes_mod_struct _temp870; _temp870.tag= Cyc_Absyn_Attributes_mod;
_temp870.f1= loc; _temp870.f2= atts; _temp870;}); _temp869;})); _temp868->tl=
tms; _temp868;});}} static struct Cyc_Absyn_Decl* Cyc_Parse_v_typ_to_typedef(
struct Cyc_Position_Segment* loc, struct _tuple7* t){ struct _tuple1* x=(* t).f1;
Cyc_Lex_register_typedef( x); if((* t).f5 != 0){ Cyc_Parse_err(({ struct
_tagged_string _temp872= Cyc_Absyn_attribute2string(( void*)({ struct Cyc_List_List*
_temp871=(* t).f5; if( _temp871 == 0){ _throw( Null_Exception);} _temp871->hd;}));
xprintf("bad attribute %.*s within typedef", _temp872.last_plus_one - _temp872.curr,
_temp872.curr);}), loc);} return Cyc_Absyn_new_decl(( void*)({ struct Cyc_Absyn_Typedef_d_struct*
_temp873=( struct Cyc_Absyn_Typedef_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Typedef_d_struct));
_temp873[ 0]=({ struct Cyc_Absyn_Typedef_d_struct _temp874; _temp874.tag= Cyc_Absyn_Typedef_d;
_temp874.f1=({ struct Cyc_Absyn_Typedefdecl* _temp875=( struct Cyc_Absyn_Typedefdecl*)
GC_malloc( sizeof( struct Cyc_Absyn_Typedefdecl)); _temp875->name= x; _temp875->tvs=(*
t).f4; _temp875->defn=( void*)(* t).f3; _temp875;}); _temp874;}); _temp873;}),
loc);} char Cyc_Okay_tok[ 13u]="\000\000\000\000Okay_tok"; char Cyc_Bool_tok[ 13u]="\000\000\000\000Bool_tok";
struct Cyc_Bool_tok_struct{ char* tag; int f1; } ; char Cyc_Int_tok[ 12u]="\000\000\000\000Int_tok";
struct _tuple12{ void* f1; int f2; } ; struct Cyc_Int_tok_struct{ char* tag;
struct _tuple12* f1; } ; char Cyc_Char_tok[ 13u]="\000\000\000\000Char_tok";
struct Cyc_Char_tok_struct{ char* tag; char f1; } ; char Cyc_Pointer_Sort_tok[
21u]="\000\000\000\000Pointer_Sort_tok"; struct Cyc_Pointer_Sort_tok_struct{
char* tag; void* f1; } ; char Cyc_Short_tok[ 14u]="\000\000\000\000Short_tok";
struct Cyc_Short_tok_struct{ char* tag; short f1; } ; char Cyc_String_tok[ 15u]="\000\000\000\000String_tok";
struct Cyc_String_tok_struct{ char* tag; struct _tagged_string f1; } ; char Cyc_Stringopt_tok[
18u]="\000\000\000\000Stringopt_tok"; struct Cyc_Stringopt_tok_struct{ char* tag;
struct Cyc_Core_Opt* f1; } ; char Cyc_Type_tok[ 13u]="\000\000\000\000Type_tok";
struct Cyc_Type_tok_struct{ char* tag; void* f1; } ; char Cyc_TypeList_tok[ 17u]="\000\000\000\000TypeList_tok";
struct Cyc_TypeList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ; char
Cyc_Exp_tok[ 12u]="\000\000\000\000Exp_tok"; struct Cyc_Exp_tok_struct{ char*
tag; struct Cyc_Absyn_Exp* f1; } ; char Cyc_ExpList_tok[ 16u]="\000\000\000\000ExpList_tok";
struct Cyc_ExpList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ; char Cyc_Primop_tok[
15u]="\000\000\000\000Primop_tok"; struct Cyc_Primop_tok_struct{ char* tag; void*
f1; } ; char Cyc_Primopopt_tok[ 18u]="\000\000\000\000Primopopt_tok"; struct Cyc_Primopopt_tok_struct{
char* tag; struct Cyc_Core_Opt* f1; } ; char Cyc_QualId_tok[ 15u]="\000\000\000\000QualId_tok";
struct Cyc_QualId_tok_struct{ char* tag; struct _tuple1* f1; } ; char Cyc_Stmt_tok[
13u]="\000\000\000\000Stmt_tok"; struct Cyc_Stmt_tok_struct{ char* tag; struct
Cyc_Absyn_Stmt* f1; } ; char Cyc_SwitchClauseList_tok[ 25u]="\000\000\000\000SwitchClauseList_tok";
struct Cyc_SwitchClauseList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ;
char Cyc_Pattern_tok[ 16u]="\000\000\000\000Pattern_tok"; struct Cyc_Pattern_tok_struct{
char* tag; struct Cyc_Absyn_Pat* f1; } ; char Cyc_PatternList_tok[ 20u]="\000\000\000\000PatternList_tok";
struct Cyc_PatternList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ; char
Cyc_FnDecl_tok[ 15u]="\000\000\000\000FnDecl_tok"; struct Cyc_FnDecl_tok_struct{
char* tag; struct Cyc_Absyn_Fndecl* f1; } ; char Cyc_DeclList_tok[ 17u]="\000\000\000\000DeclList_tok";
struct Cyc_DeclList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ; char
Cyc_DeclSpec_tok[ 17u]="\000\000\000\000DeclSpec_tok"; struct Cyc_DeclSpec_tok_struct{
char* tag; struct Cyc_Parse_Declaration_spec* f1; } ; char Cyc_InitDecl_tok[ 17u]="\000\000\000\000InitDecl_tok";
struct _tuple13{ struct Cyc_Parse_Declarator* f1; struct Cyc_Absyn_Exp* f2; } ;
struct Cyc_InitDecl_tok_struct{ char* tag; struct _tuple13* f1; } ; char Cyc_InitDeclList_tok[
21u]="\000\000\000\000InitDeclList_tok"; struct Cyc_InitDeclList_tok_struct{
char* tag; struct Cyc_List_List* f1; } ; char Cyc_StorageClass_tok[ 21u]="\000\000\000\000StorageClass_tok";
struct Cyc_StorageClass_tok_struct{ char* tag; void* f1; } ; char Cyc_TypeSpecifier_tok[
22u]="\000\000\000\000TypeSpecifier_tok"; struct Cyc_TypeSpecifier_tok_struct{
char* tag; void* f1; } ; char Cyc_QualSpecList_tok[ 21u]="\000\000\000\000QualSpecList_tok";
struct _tuple14{ struct Cyc_Absyn_Tqual f1; struct Cyc_List_List* f2; struct Cyc_List_List*
f3; } ; struct Cyc_QualSpecList_tok_struct{ char* tag; struct _tuple14* f1; } ;
char Cyc_TypeQual_tok[ 17u]="\000\000\000\000TypeQual_tok"; struct Cyc_TypeQual_tok_struct{
char* tag; struct Cyc_Absyn_Tqual f1; } ; char Cyc_StructFieldDeclList_tok[ 28u]="\000\000\000\000StructFieldDeclList_tok";
struct Cyc_StructFieldDeclList_tok_struct{ char* tag; struct Cyc_List_List* f1;
} ; char Cyc_StructFieldDeclListList_tok[ 32u]="\000\000\000\000StructFieldDeclListList_tok";
struct Cyc_StructFieldDeclListList_tok_struct{ char* tag; struct Cyc_List_List*
f1; } ; char Cyc_Declarator_tok[ 19u]="\000\000\000\000Declarator_tok"; struct
Cyc_Declarator_tok_struct{ char* tag; struct Cyc_Parse_Declarator* f1; } ; char
Cyc_DeclaratorExpopt_tok[ 25u]="\000\000\000\000DeclaratorExpopt_tok"; struct
_tuple15{ struct Cyc_Parse_Declarator* f1; struct Cyc_Core_Opt* f2; } ; struct
Cyc_DeclaratorExpopt_tok_struct{ char* tag; struct _tuple15* f1; } ; char Cyc_DeclaratorExpoptList_tok[
29u]="\000\000\000\000DeclaratorExpoptList_tok"; struct Cyc_DeclaratorExpoptList_tok_struct{
char* tag; struct Cyc_List_List* f1; } ; char Cyc_AbstractDeclarator_tok[ 27u]="\000\000\000\000AbstractDeclarator_tok";
struct Cyc_AbstractDeclarator_tok_struct{ char* tag; struct Cyc_Parse_Abstractdeclarator*
f1; } ; char Cyc_TunionField_tok[ 20u]="\000\000\000\000TunionField_tok"; struct
Cyc_TunionField_tok_struct{ char* tag; struct Cyc_Absyn_Tunionfield* f1; } ;
char Cyc_TunionFieldList_tok[ 24u]="\000\000\000\000TunionFieldList_tok"; struct
Cyc_TunionFieldList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ; char
Cyc_ParamDecl_tok[ 18u]="\000\000\000\000ParamDecl_tok"; struct Cyc_ParamDecl_tok_struct{
char* tag; struct _tuple2* f1; } ; char Cyc_ParamDeclList_tok[ 22u]="\000\000\000\000ParamDeclList_tok";
struct Cyc_ParamDeclList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ;
char Cyc_ParamDeclListBool_tok[ 26u]="\000\000\000\000ParamDeclListBool_tok";
struct _tuple16{ struct Cyc_List_List* f1; int f2; struct Cyc_Core_Opt* f3; } ;
struct Cyc_ParamDeclListBool_tok_struct{ char* tag; struct _tuple16* f1; } ;
char Cyc_StructOrUnion_tok[ 22u]="\000\000\000\000StructOrUnion_tok"; struct Cyc_StructOrUnion_tok_struct{
char* tag; void* f1; } ; char Cyc_IdList_tok[ 15u]="\000\000\000\000IdList_tok";
struct Cyc_IdList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ; char Cyc_Designator_tok[
19u]="\000\000\000\000Designator_tok"; struct Cyc_Designator_tok_struct{ char*
tag; void* f1; } ; char Cyc_DesignatorList_tok[ 23u]="\000\000\000\000DesignatorList_tok";
struct Cyc_DesignatorList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ;
char Cyc_TypeModifierList_tok[ 25u]="\000\000\000\000TypeModifierList_tok";
struct Cyc_TypeModifierList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ;
char Cyc_Rgn_tok[ 12u]="\000\000\000\000Rgn_tok"; struct Cyc_Rgn_tok_struct{
char* tag; void* f1; } ; char Cyc_InitializerList_tok[ 24u]="\000\000\000\000InitializerList_tok";
struct Cyc_InitializerList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ;
char Cyc_FieldPattern_tok[ 21u]="\000\000\000\000FieldPattern_tok"; struct
_tuple17{ struct Cyc_List_List* f1; struct Cyc_Absyn_Pat* f2; } ; struct Cyc_FieldPattern_tok_struct{
char* tag; struct _tuple17* f1; } ; char Cyc_FieldPatternList_tok[ 25u]="\000\000\000\000FieldPatternList_tok";
struct Cyc_FieldPatternList_tok_struct{ char* tag; struct Cyc_List_List* f1; } ;
char Cyc_BlockItem_tok[ 18u]="\000\000\000\000BlockItem_tok"; struct Cyc_BlockItem_tok_struct{
char* tag; void* f1; } ; char Cyc_Kind_tok[ 13u]="\000\000\000\000Kind_tok";
struct Cyc_Kind_tok_struct{ char* tag; void* f1; } ; char Cyc_Attribute_tok[ 18u]="\000\000\000\000Attribute_tok";
struct Cyc_Attribute_tok_struct{ char* tag; void* f1; } ; char Cyc_AttributeList_tok[
22u]="\000\000\000\000AttributeList_tok"; struct Cyc_AttributeList_tok_struct{
char* tag; struct Cyc_List_List* f1; } ; char Cyc_Enumfield_tok[ 18u]="\000\000\000\000Enumfield_tok";
struct Cyc_Enumfield_tok_struct{ char* tag; struct Cyc_Absyn_Enumfield* f1; } ;
char Cyc_EnumfieldList_tok[ 22u]="\000\000\000\000EnumfieldList_tok"; struct Cyc_EnumfieldList_tok_struct{
char* tag; struct Cyc_List_List* f1; } ; static char _temp879[ 8u]="Int_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_Int_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp879, _temp879, _temp879 + 8u}}; struct _tuple12*
Cyc_yyget_Int_tok( void* yy1){ void* _temp880= yy1; struct _tuple12* _temp886;
_LL882: if(*(( void**) _temp880) == Cyc_Int_tok){ _LL887: _temp886=( struct
_tuple12*)(( struct Cyc_Int_tok_struct*) _temp880)->f1; goto _LL883;} else{ goto
_LL884;} _LL884: goto _LL885; _LL883: return _temp886; _LL885:( void) _throw((
void*)& Cyc_yyfail_Int_tok); _LL881:;} static char _temp891[ 11u]="String_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_String_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp891, _temp891, _temp891 + 11u}}; struct
_tagged_string Cyc_yyget_String_tok( void* yy1){ void* _temp892= yy1; struct
_tagged_string _temp898; _LL894: if(*(( void**) _temp892) == Cyc_String_tok){
_LL899: _temp898=( struct _tagged_string)(( struct Cyc_String_tok_struct*)
_temp892)->f1; goto _LL895;} else{ goto _LL896;} _LL896: goto _LL897; _LL895:
return _temp898; _LL897:( void) _throw(( void*)& Cyc_yyfail_String_tok); _LL893:;}
static char _temp903[ 9u]="Char_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_Char_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp903, _temp903, _temp903 + 9u}};
char Cyc_yyget_Char_tok( void* yy1){ void* _temp904= yy1; char _temp910; _LL906:
if(*(( void**) _temp904) == Cyc_Char_tok){ _LL911: _temp910=( char)(( struct Cyc_Char_tok_struct*)
_temp904)->f1; goto _LL907;} else{ goto _LL908;} _LL908: goto _LL909; _LL907:
return _temp910; _LL909:( void) _throw(( void*)& Cyc_yyfail_Char_tok); _LL905:;}
static char _temp915[ 17u]="Pointer_Sort_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_Pointer_Sort_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp915, _temp915, _temp915 + 17u}}; void* Cyc_yyget_Pointer_Sort_tok( void*
yy1){ void* _temp916= yy1; void* _temp922; _LL918: if(*(( void**) _temp916) ==
Cyc_Pointer_Sort_tok){ _LL923: _temp922=( void*)(( struct Cyc_Pointer_Sort_tok_struct*)
_temp916)->f1; goto _LL919;} else{ goto _LL920;} _LL920: goto _LL921; _LL919:
return _temp922; _LL921:( void) _throw(( void*)& Cyc_yyfail_Pointer_Sort_tok);
_LL917:;} static char _temp927[ 8u]="Exp_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_Exp_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp927,
_temp927, _temp927 + 8u}}; struct Cyc_Absyn_Exp* Cyc_yyget_Exp_tok( void* yy1){
void* _temp928= yy1; struct Cyc_Absyn_Exp* _temp934; _LL930: if(*(( void**)
_temp928) == Cyc_Exp_tok){ _LL935: _temp934=( struct Cyc_Absyn_Exp*)(( struct
Cyc_Exp_tok_struct*) _temp928)->f1; goto _LL931;} else{ goto _LL932;} _LL932:
goto _LL933; _LL931: return _temp934; _LL933:( void) _throw(( void*)& Cyc_yyfail_Exp_tok);
_LL929:;} static char _temp939[ 12u]="ExpList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_ExpList_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp939,
_temp939, _temp939 + 12u}}; struct Cyc_List_List* Cyc_yyget_ExpList_tok( void*
yy1){ void* _temp940= yy1; struct Cyc_List_List* _temp946; _LL942: if(*(( void**)
_temp940) == Cyc_ExpList_tok){ _LL947: _temp946=( struct Cyc_List_List*)((
struct Cyc_ExpList_tok_struct*) _temp940)->f1; goto _LL943;} else{ goto _LL944;}
_LL944: goto _LL945; _LL943: return _temp946; _LL945:( void) _throw(( void*)&
Cyc_yyfail_ExpList_tok); _LL941:;} static char _temp951[ 20u]="InitializerList_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_InitializerList_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp951, _temp951, _temp951 + 20u}}; struct Cyc_List_List*
Cyc_yyget_InitializerList_tok( void* yy1){ void* _temp952= yy1; struct Cyc_List_List*
_temp958; _LL954: if(*(( void**) _temp952) == Cyc_InitializerList_tok){ _LL959:
_temp958=( struct Cyc_List_List*)(( struct Cyc_InitializerList_tok_struct*)
_temp952)->f1; goto _LL955;} else{ goto _LL956;} _LL956: goto _LL957; _LL955:
return _temp958; _LL957:( void) _throw(( void*)& Cyc_yyfail_InitializerList_tok);
_LL953:;} static char _temp963[ 11u]="Primop_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_Primop_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp963,
_temp963, _temp963 + 11u}}; void* Cyc_yyget_Primop_tok( void* yy1){ void*
_temp964= yy1; void* _temp970; _LL966: if(*(( void**) _temp964) == Cyc_Primop_tok){
_LL971: _temp970=( void*)(( struct Cyc_Primop_tok_struct*) _temp964)->f1; goto
_LL967;} else{ goto _LL968;} _LL968: goto _LL969; _LL967: return _temp970;
_LL969:( void) _throw(( void*)& Cyc_yyfail_Primop_tok); _LL965:;} static char
_temp975[ 14u]="Primopopt_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_Primopopt_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp975, _temp975, _temp975 + 14u}};
struct Cyc_Core_Opt* Cyc_yyget_Primopopt_tok( void* yy1){ void* _temp976= yy1;
struct Cyc_Core_Opt* _temp982; _LL978: if(*(( void**) _temp976) == Cyc_Primopopt_tok){
_LL983: _temp982=( struct Cyc_Core_Opt*)(( struct Cyc_Primopopt_tok_struct*)
_temp976)->f1; goto _LL979;} else{ goto _LL980;} _LL980: goto _LL981; _LL979:
return _temp982; _LL981:( void) _throw(( void*)& Cyc_yyfail_Primopopt_tok);
_LL977:;} static char _temp987[ 11u]="QualId_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_QualId_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp987,
_temp987, _temp987 + 11u}}; struct _tuple1* Cyc_yyget_QualId_tok( void* yy1){
void* _temp988= yy1; struct _tuple1* _temp994; _LL990: if(*(( void**) _temp988)
== Cyc_QualId_tok){ _LL995: _temp994=( struct _tuple1*)(( struct Cyc_QualId_tok_struct*)
_temp988)->f1; goto _LL991;} else{ goto _LL992;} _LL992: goto _LL993; _LL991:
return _temp994; _LL993:( void) _throw(( void*)& Cyc_yyfail_QualId_tok); _LL989:;}
static char _temp999[ 9u]="Stmt_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_Stmt_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp999, _temp999, _temp999 + 9u}};
struct Cyc_Absyn_Stmt* Cyc_yyget_Stmt_tok( void* yy1){ void* _temp1000= yy1;
struct Cyc_Absyn_Stmt* _temp1006; _LL1002: if(*(( void**) _temp1000) == Cyc_Stmt_tok){
_LL1007: _temp1006=( struct Cyc_Absyn_Stmt*)(( struct Cyc_Stmt_tok_struct*)
_temp1000)->f1; goto _LL1003;} else{ goto _LL1004;} _LL1004: goto _LL1005;
_LL1003: return _temp1006; _LL1005:( void) _throw(( void*)& Cyc_yyfail_Stmt_tok);
_LL1001:;} static char _temp1011[ 14u]="BlockItem_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_BlockItem_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1011,
_temp1011, _temp1011 + 14u}}; void* Cyc_yyget_BlockItem_tok( void* yy1){ void*
_temp1012= yy1; void* _temp1018; _LL1014: if(*(( void**) _temp1012) == Cyc_BlockItem_tok){
_LL1019: _temp1018=( void*)(( struct Cyc_BlockItem_tok_struct*) _temp1012)->f1;
goto _LL1015;} else{ goto _LL1016;} _LL1016: goto _LL1017; _LL1015: return
_temp1018; _LL1017:( void) _throw(( void*)& Cyc_yyfail_BlockItem_tok); _LL1013:;}
static char _temp1023[ 21u]="SwitchClauseList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_SwitchClauseList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1023, _temp1023, _temp1023 + 21u}}; struct Cyc_List_List* Cyc_yyget_SwitchClauseList_tok(
void* yy1){ void* _temp1024= yy1; struct Cyc_List_List* _temp1030; _LL1026: if(*((
void**) _temp1024) == Cyc_SwitchClauseList_tok){ _LL1031: _temp1030=( struct Cyc_List_List*)((
struct Cyc_SwitchClauseList_tok_struct*) _temp1024)->f1; goto _LL1027;} else{
goto _LL1028;} _LL1028: goto _LL1029; _LL1027: return _temp1030; _LL1029:( void)
_throw(( void*)& Cyc_yyfail_SwitchClauseList_tok); _LL1025:;} static char
_temp1035[ 12u]="Pattern_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_Pattern_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1035, _temp1035, _temp1035 + 12u}};
struct Cyc_Absyn_Pat* Cyc_yyget_Pattern_tok( void* yy1){ void* _temp1036= yy1;
struct Cyc_Absyn_Pat* _temp1042; _LL1038: if(*(( void**) _temp1036) == Cyc_Pattern_tok){
_LL1043: _temp1042=( struct Cyc_Absyn_Pat*)(( struct Cyc_Pattern_tok_struct*)
_temp1036)->f1; goto _LL1039;} else{ goto _LL1040;} _LL1040: goto _LL1041;
_LL1039: return _temp1042; _LL1041:( void) _throw(( void*)& Cyc_yyfail_Pattern_tok);
_LL1037:;} static char _temp1047[ 16u]="PatternList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_PatternList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1047, _temp1047, _temp1047 + 16u}}; struct Cyc_List_List* Cyc_yyget_PatternList_tok(
void* yy1){ void* _temp1048= yy1; struct Cyc_List_List* _temp1054; _LL1050: if(*((
void**) _temp1048) == Cyc_PatternList_tok){ _LL1055: _temp1054=( struct Cyc_List_List*)((
struct Cyc_PatternList_tok_struct*) _temp1048)->f1; goto _LL1051;} else{ goto
_LL1052;} _LL1052: goto _LL1053; _LL1051: return _temp1054; _LL1053:( void)
_throw(( void*)& Cyc_yyfail_PatternList_tok); _LL1049:;} static char _temp1059[
17u]="FieldPattern_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_FieldPattern_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1059, _temp1059, _temp1059 + 17u}};
struct _tuple17* Cyc_yyget_FieldPattern_tok( void* yy1){ void* _temp1060= yy1;
struct _tuple17* _temp1066; _LL1062: if(*(( void**) _temp1060) == Cyc_FieldPattern_tok){
_LL1067: _temp1066=( struct _tuple17*)(( struct Cyc_FieldPattern_tok_struct*)
_temp1060)->f1; goto _LL1063;} else{ goto _LL1064;} _LL1064: goto _LL1065;
_LL1063: return _temp1066; _LL1065:( void) _throw(( void*)& Cyc_yyfail_FieldPattern_tok);
_LL1061:;} static char _temp1071[ 21u]="FieldPatternList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_FieldPatternList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1071, _temp1071, _temp1071 + 21u}}; struct Cyc_List_List* Cyc_yyget_FieldPatternList_tok(
void* yy1){ void* _temp1072= yy1; struct Cyc_List_List* _temp1078; _LL1074: if(*((
void**) _temp1072) == Cyc_FieldPatternList_tok){ _LL1079: _temp1078=( struct Cyc_List_List*)((
struct Cyc_FieldPatternList_tok_struct*) _temp1072)->f1; goto _LL1075;} else{
goto _LL1076;} _LL1076: goto _LL1077; _LL1075: return _temp1078; _LL1077:( void)
_throw(( void*)& Cyc_yyfail_FieldPatternList_tok); _LL1073:;} static char
_temp1083[ 11u]="FnDecl_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_FnDecl_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1083, _temp1083, _temp1083 + 11u}};
struct Cyc_Absyn_Fndecl* Cyc_yyget_FnDecl_tok( void* yy1){ void* _temp1084= yy1;
struct Cyc_Absyn_Fndecl* _temp1090; _LL1086: if(*(( void**) _temp1084) == Cyc_FnDecl_tok){
_LL1091: _temp1090=( struct Cyc_Absyn_Fndecl*)(( struct Cyc_FnDecl_tok_struct*)
_temp1084)->f1; goto _LL1087;} else{ goto _LL1088;} _LL1088: goto _LL1089;
_LL1087: return _temp1090; _LL1089:( void) _throw(( void*)& Cyc_yyfail_FnDecl_tok);
_LL1085:;} static char _temp1095[ 13u]="DeclList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_DeclList_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1095,
_temp1095, _temp1095 + 13u}}; struct Cyc_List_List* Cyc_yyget_DeclList_tok( void*
yy1){ void* _temp1096= yy1; struct Cyc_List_List* _temp1102; _LL1098: if(*((
void**) _temp1096) == Cyc_DeclList_tok){ _LL1103: _temp1102=( struct Cyc_List_List*)((
struct Cyc_DeclList_tok_struct*) _temp1096)->f1; goto _LL1099;} else{ goto
_LL1100;} _LL1100: goto _LL1101; _LL1099: return _temp1102; _LL1101:( void)
_throw(( void*)& Cyc_yyfail_DeclList_tok); _LL1097:;} static char _temp1107[ 13u]="DeclSpec_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_DeclSpec_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1107, _temp1107, _temp1107 + 13u}}; struct Cyc_Parse_Declaration_spec*
Cyc_yyget_DeclSpec_tok( void* yy1){ void* _temp1108= yy1; struct Cyc_Parse_Declaration_spec*
_temp1114; _LL1110: if(*(( void**) _temp1108) == Cyc_DeclSpec_tok){ _LL1115:
_temp1114=( struct Cyc_Parse_Declaration_spec*)(( struct Cyc_DeclSpec_tok_struct*)
_temp1108)->f1; goto _LL1111;} else{ goto _LL1112;} _LL1112: goto _LL1113;
_LL1111: return _temp1114; _LL1113:( void) _throw(( void*)& Cyc_yyfail_DeclSpec_tok);
_LL1109:;} static char _temp1119[ 13u]="InitDecl_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_InitDecl_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1119,
_temp1119, _temp1119 + 13u}}; struct _tuple13* Cyc_yyget_InitDecl_tok( void* yy1){
void* _temp1120= yy1; struct _tuple13* _temp1126; _LL1122: if(*(( void**)
_temp1120) == Cyc_InitDecl_tok){ _LL1127: _temp1126=( struct _tuple13*)(( struct
Cyc_InitDecl_tok_struct*) _temp1120)->f1; goto _LL1123;} else{ goto _LL1124;}
_LL1124: goto _LL1125; _LL1123: return _temp1126; _LL1125:( void) _throw(( void*)&
Cyc_yyfail_InitDecl_tok); _LL1121:;} static char _temp1131[ 17u]="InitDeclList_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_InitDeclList_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1131, _temp1131, _temp1131 + 17u}}; struct Cyc_List_List*
Cyc_yyget_InitDeclList_tok( void* yy1){ void* _temp1132= yy1; struct Cyc_List_List*
_temp1138; _LL1134: if(*(( void**) _temp1132) == Cyc_InitDeclList_tok){ _LL1139:
_temp1138=( struct Cyc_List_List*)(( struct Cyc_InitDeclList_tok_struct*)
_temp1132)->f1; goto _LL1135;} else{ goto _LL1136;} _LL1136: goto _LL1137;
_LL1135: return _temp1138; _LL1137:( void) _throw(( void*)& Cyc_yyfail_InitDeclList_tok);
_LL1133:;} static char _temp1143[ 17u]="StorageClass_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_StorageClass_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1143, _temp1143, _temp1143 + 17u}}; void* Cyc_yyget_StorageClass_tok( void*
yy1){ void* _temp1144= yy1; void* _temp1150; _LL1146: if(*(( void**) _temp1144)
== Cyc_StorageClass_tok){ _LL1151: _temp1150=( void*)(( struct Cyc_StorageClass_tok_struct*)
_temp1144)->f1; goto _LL1147;} else{ goto _LL1148;} _LL1148: goto _LL1149;
_LL1147: return _temp1150; _LL1149:( void) _throw(( void*)& Cyc_yyfail_StorageClass_tok);
_LL1145:;} static char _temp1155[ 18u]="TypeSpecifier_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_TypeSpecifier_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1155, _temp1155, _temp1155 + 18u}}; void* Cyc_yyget_TypeSpecifier_tok( void*
yy1){ void* _temp1156= yy1; void* _temp1162; _LL1158: if(*(( void**) _temp1156)
== Cyc_TypeSpecifier_tok){ _LL1163: _temp1162=( void*)(( struct Cyc_TypeSpecifier_tok_struct*)
_temp1156)->f1; goto _LL1159;} else{ goto _LL1160;} _LL1160: goto _LL1161;
_LL1159: return _temp1162; _LL1161:( void) _throw(( void*)& Cyc_yyfail_TypeSpecifier_tok);
_LL1157:;} static char _temp1167[ 18u]="StructOrUnion_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_StructOrUnion_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1167, _temp1167, _temp1167 + 18u}}; void* Cyc_yyget_StructOrUnion_tok( void*
yy1){ void* _temp1168= yy1; void* _temp1174; _LL1170: if(*(( void**) _temp1168)
== Cyc_StructOrUnion_tok){ _LL1175: _temp1174=( void*)(( struct Cyc_StructOrUnion_tok_struct*)
_temp1168)->f1; goto _LL1171;} else{ goto _LL1172;} _LL1172: goto _LL1173;
_LL1171: return _temp1174; _LL1173:( void) _throw(( void*)& Cyc_yyfail_StructOrUnion_tok);
_LL1169:;} static char _temp1179[ 13u]="TypeQual_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_TypeQual_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1179,
_temp1179, _temp1179 + 13u}}; struct Cyc_Absyn_Tqual Cyc_yyget_TypeQual_tok(
void* yy1){ void* _temp1180= yy1; struct Cyc_Absyn_Tqual _temp1186; _LL1182: if(*((
void**) _temp1180) == Cyc_TypeQual_tok){ _LL1187: _temp1186=( struct Cyc_Absyn_Tqual)((
struct Cyc_TypeQual_tok_struct*) _temp1180)->f1; goto _LL1183;} else{ goto
_LL1184;} _LL1184: goto _LL1185; _LL1183: return _temp1186; _LL1185:( void)
_throw(( void*)& Cyc_yyfail_TypeQual_tok); _LL1181:;} static char _temp1191[ 24u]="StructFieldDeclList_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_StructFieldDeclList_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1191, _temp1191, _temp1191 + 24u}}; struct Cyc_List_List*
Cyc_yyget_StructFieldDeclList_tok( void* yy1){ void* _temp1192= yy1; struct Cyc_List_List*
_temp1198; _LL1194: if(*(( void**) _temp1192) == Cyc_StructFieldDeclList_tok){
_LL1199: _temp1198=( struct Cyc_List_List*)(( struct Cyc_StructFieldDeclList_tok_struct*)
_temp1192)->f1; goto _LL1195;} else{ goto _LL1196;} _LL1196: goto _LL1197;
_LL1195: return _temp1198; _LL1197:( void) _throw(( void*)& Cyc_yyfail_StructFieldDeclList_tok);
_LL1193:;} static char _temp1203[ 28u]="StructFieldDeclListList_tok"; static
struct Cyc_Core_Failure_struct Cyc_yyfail_StructFieldDeclListList_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1203, _temp1203, _temp1203 + 28u}}; struct Cyc_List_List*
Cyc_yyget_StructFieldDeclListList_tok( void* yy1){ void* _temp1204= yy1; struct
Cyc_List_List* _temp1210; _LL1206: if(*(( void**) _temp1204) == Cyc_StructFieldDeclListList_tok){
_LL1211: _temp1210=( struct Cyc_List_List*)(( struct Cyc_StructFieldDeclListList_tok_struct*)
_temp1204)->f1; goto _LL1207;} else{ goto _LL1208;} _LL1208: goto _LL1209;
_LL1207: return _temp1210; _LL1209:( void) _throw(( void*)& Cyc_yyfail_StructFieldDeclListList_tok);
_LL1205:;} static char _temp1215[ 21u]="TypeModifierList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_TypeModifierList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1215, _temp1215, _temp1215 + 21u}}; struct Cyc_List_List* Cyc_yyget_TypeModifierList_tok(
void* yy1){ void* _temp1216= yy1; struct Cyc_List_List* _temp1222; _LL1218: if(*((
void**) _temp1216) == Cyc_TypeModifierList_tok){ _LL1223: _temp1222=( struct Cyc_List_List*)((
struct Cyc_TypeModifierList_tok_struct*) _temp1216)->f1; goto _LL1219;} else{
goto _LL1220;} _LL1220: goto _LL1221; _LL1219: return _temp1222; _LL1221:( void)
_throw(( void*)& Cyc_yyfail_TypeModifierList_tok); _LL1217:;} static char
_temp1227[ 8u]="Rgn_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_Rgn_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1227, _temp1227, _temp1227 + 8u}};
void* Cyc_yyget_Rgn_tok( void* yy1){ void* _temp1228= yy1; void* _temp1234;
_LL1230: if(*(( void**) _temp1228) == Cyc_Rgn_tok){ _LL1235: _temp1234=( void*)((
struct Cyc_Rgn_tok_struct*) _temp1228)->f1; goto _LL1231;} else{ goto _LL1232;}
_LL1232: goto _LL1233; _LL1231: return _temp1234; _LL1233:( void) _throw(( void*)&
Cyc_yyfail_Rgn_tok); _LL1229:;} static char _temp1239[ 15u]="Declarator_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_Declarator_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1239, _temp1239, _temp1239 + 15u}}; struct Cyc_Parse_Declarator*
Cyc_yyget_Declarator_tok( void* yy1){ void* _temp1240= yy1; struct Cyc_Parse_Declarator*
_temp1246; _LL1242: if(*(( void**) _temp1240) == Cyc_Declarator_tok){ _LL1247:
_temp1246=( struct Cyc_Parse_Declarator*)(( struct Cyc_Declarator_tok_struct*)
_temp1240)->f1; goto _LL1243;} else{ goto _LL1244;} _LL1244: goto _LL1245;
_LL1243: return _temp1246; _LL1245:( void) _throw(( void*)& Cyc_yyfail_Declarator_tok);
_LL1241:;} static char _temp1251[ 21u]="DeclaratorExpopt_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_DeclaratorExpopt_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1251, _temp1251, _temp1251 + 21u}}; struct _tuple15* Cyc_yyget_DeclaratorExpopt_tok(
void* yy1){ void* _temp1252= yy1; struct _tuple15* _temp1258; _LL1254: if(*((
void**) _temp1252) == Cyc_DeclaratorExpopt_tok){ _LL1259: _temp1258=( struct
_tuple15*)(( struct Cyc_DeclaratorExpopt_tok_struct*) _temp1252)->f1; goto
_LL1255;} else{ goto _LL1256;} _LL1256: goto _LL1257; _LL1255: return _temp1258;
_LL1257:( void) _throw(( void*)& Cyc_yyfail_DeclaratorExpopt_tok); _LL1253:;}
static char _temp1263[ 25u]="DeclaratorExpoptList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_DeclaratorExpoptList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1263, _temp1263, _temp1263 + 25u}}; struct Cyc_List_List* Cyc_yyget_DeclaratorExpoptList_tok(
void* yy1){ void* _temp1264= yy1; struct Cyc_List_List* _temp1270; _LL1266: if(*((
void**) _temp1264) == Cyc_DeclaratorExpoptList_tok){ _LL1271: _temp1270=( struct
Cyc_List_List*)(( struct Cyc_DeclaratorExpoptList_tok_struct*) _temp1264)->f1;
goto _LL1267;} else{ goto _LL1268;} _LL1268: goto _LL1269; _LL1267: return
_temp1270; _LL1269:( void) _throw(( void*)& Cyc_yyfail_DeclaratorExpoptList_tok);
_LL1265:;} static char _temp1275[ 23u]="AbstractDeclarator_tok"; static struct
Cyc_Core_Failure_struct Cyc_yyfail_AbstractDeclarator_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1275, _temp1275, _temp1275 + 23u}}; struct Cyc_Parse_Abstractdeclarator*
Cyc_yyget_AbstractDeclarator_tok( void* yy1){ void* _temp1276= yy1; struct Cyc_Parse_Abstractdeclarator*
_temp1282; _LL1278: if(*(( void**) _temp1276) == Cyc_AbstractDeclarator_tok){
_LL1283: _temp1282=( struct Cyc_Parse_Abstractdeclarator*)(( struct Cyc_AbstractDeclarator_tok_struct*)
_temp1276)->f1; goto _LL1279;} else{ goto _LL1280;} _LL1280: goto _LL1281;
_LL1279: return _temp1282; _LL1281:( void) _throw(( void*)& Cyc_yyfail_AbstractDeclarator_tok);
_LL1277:;} static char _temp1287[ 9u]="Bool_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_Bool_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1287,
_temp1287, _temp1287 + 9u}}; int Cyc_yyget_Bool_tok( void* yy1){ void* _temp1288=
yy1; int _temp1294; _LL1290: if(*(( void**) _temp1288) == Cyc_Bool_tok){ _LL1295:
_temp1294=( int)(( struct Cyc_Bool_tok_struct*) _temp1288)->f1; goto _LL1291;}
else{ goto _LL1292;} _LL1292: goto _LL1293; _LL1291: return _temp1294; _LL1293:(
void) _throw(( void*)& Cyc_yyfail_Bool_tok); _LL1289:;} static char _temp1299[
16u]="TunionField_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_TunionField_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1299, _temp1299, _temp1299 + 16u}};
struct Cyc_Absyn_Tunionfield* Cyc_yyget_TunionField_tok( void* yy1){ void*
_temp1300= yy1; struct Cyc_Absyn_Tunionfield* _temp1306; _LL1302: if(*(( void**)
_temp1300) == Cyc_TunionField_tok){ _LL1307: _temp1306=( struct Cyc_Absyn_Tunionfield*)((
struct Cyc_TunionField_tok_struct*) _temp1300)->f1; goto _LL1303;} else{ goto
_LL1304;} _LL1304: goto _LL1305; _LL1303: return _temp1306; _LL1305:( void)
_throw(( void*)& Cyc_yyfail_TunionField_tok); _LL1301:;} static char _temp1311[
20u]="TunionFieldList_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_TunionFieldList_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1311, _temp1311, _temp1311 + 20u}};
struct Cyc_List_List* Cyc_yyget_TunionFieldList_tok( void* yy1){ void* _temp1312=
yy1; struct Cyc_List_List* _temp1318; _LL1314: if(*(( void**) _temp1312) == Cyc_TunionFieldList_tok){
_LL1319: _temp1318=( struct Cyc_List_List*)(( struct Cyc_TunionFieldList_tok_struct*)
_temp1312)->f1; goto _LL1315;} else{ goto _LL1316;} _LL1316: goto _LL1317;
_LL1315: return _temp1318; _LL1317:( void) _throw(( void*)& Cyc_yyfail_TunionFieldList_tok);
_LL1313:;} static char _temp1323[ 17u]="QualSpecList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_QualSpecList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1323, _temp1323, _temp1323 + 17u}}; struct _tuple14* Cyc_yyget_QualSpecList_tok(
void* yy1){ void* _temp1324= yy1; struct _tuple14* _temp1330; _LL1326: if(*((
void**) _temp1324) == Cyc_QualSpecList_tok){ _LL1331: _temp1330=( struct
_tuple14*)(( struct Cyc_QualSpecList_tok_struct*) _temp1324)->f1; goto _LL1327;}
else{ goto _LL1328;} _LL1328: goto _LL1329; _LL1327: return _temp1330; _LL1329:(
void) _throw(( void*)& Cyc_yyfail_QualSpecList_tok); _LL1325:;} static char
_temp1335[ 11u]="IdList_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_IdList_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1335, _temp1335, _temp1335 + 11u}};
struct Cyc_List_List* Cyc_yyget_IdList_tok( void* yy1){ void* _temp1336= yy1;
struct Cyc_List_List* _temp1342; _LL1338: if(*(( void**) _temp1336) == Cyc_IdList_tok){
_LL1343: _temp1342=( struct Cyc_List_List*)(( struct Cyc_IdList_tok_struct*)
_temp1336)->f1; goto _LL1339;} else{ goto _LL1340;} _LL1340: goto _LL1341;
_LL1339: return _temp1342; _LL1341:( void) _throw(( void*)& Cyc_yyfail_IdList_tok);
_LL1337:;} static char _temp1347[ 14u]="ParamDecl_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_ParamDecl_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1347,
_temp1347, _temp1347 + 14u}}; struct _tuple2* Cyc_yyget_ParamDecl_tok( void* yy1){
void* _temp1348= yy1; struct _tuple2* _temp1354; _LL1350: if(*(( void**)
_temp1348) == Cyc_ParamDecl_tok){ _LL1355: _temp1354=( struct _tuple2*)(( struct
Cyc_ParamDecl_tok_struct*) _temp1348)->f1; goto _LL1351;} else{ goto _LL1352;}
_LL1352: goto _LL1353; _LL1351: return _temp1354; _LL1353:( void) _throw(( void*)&
Cyc_yyfail_ParamDecl_tok); _LL1349:;} static char _temp1359[ 18u]="ParamDeclList_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_ParamDeclList_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1359, _temp1359, _temp1359 + 18u}}; struct Cyc_List_List*
Cyc_yyget_ParamDeclList_tok( void* yy1){ void* _temp1360= yy1; struct Cyc_List_List*
_temp1366; _LL1362: if(*(( void**) _temp1360) == Cyc_ParamDeclList_tok){ _LL1367:
_temp1366=( struct Cyc_List_List*)(( struct Cyc_ParamDeclList_tok_struct*)
_temp1360)->f1; goto _LL1363;} else{ goto _LL1364;} _LL1364: goto _LL1365;
_LL1363: return _temp1366; _LL1365:( void) _throw(( void*)& Cyc_yyfail_ParamDeclList_tok);
_LL1361:;} static char _temp1371[ 22u]="ParamDeclListBool_tok"; static struct
Cyc_Core_Failure_struct Cyc_yyfail_ParamDeclListBool_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1371, _temp1371, _temp1371 + 22u}}; struct _tuple16*
Cyc_yyget_ParamDeclListBool_tok( void* yy1){ void* _temp1372= yy1; struct
_tuple16* _temp1378; _LL1374: if(*(( void**) _temp1372) == Cyc_ParamDeclListBool_tok){
_LL1379: _temp1378=( struct _tuple16*)(( struct Cyc_ParamDeclListBool_tok_struct*)
_temp1372)->f1; goto _LL1375;} else{ goto _LL1376;} _LL1376: goto _LL1377;
_LL1375: return _temp1378; _LL1377:( void) _throw(( void*)& Cyc_yyfail_ParamDeclListBool_tok);
_LL1373:;} static char _temp1383[ 13u]="TypeList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_TypeList_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1383,
_temp1383, _temp1383 + 13u}}; struct Cyc_List_List* Cyc_yyget_TypeList_tok( void*
yy1){ void* _temp1384= yy1; struct Cyc_List_List* _temp1390; _LL1386: if(*((
void**) _temp1384) == Cyc_TypeList_tok){ _LL1391: _temp1390=( struct Cyc_List_List*)((
struct Cyc_TypeList_tok_struct*) _temp1384)->f1; goto _LL1387;} else{ goto
_LL1388;} _LL1388: goto _LL1389; _LL1387: return _temp1390; _LL1389:( void)
_throw(( void*)& Cyc_yyfail_TypeList_tok); _LL1385:;} static char _temp1395[ 19u]="DesignatorList_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_DesignatorList_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1395, _temp1395, _temp1395 + 19u}}; struct Cyc_List_List*
Cyc_yyget_DesignatorList_tok( void* yy1){ void* _temp1396= yy1; struct Cyc_List_List*
_temp1402; _LL1398: if(*(( void**) _temp1396) == Cyc_DesignatorList_tok){
_LL1403: _temp1402=( struct Cyc_List_List*)(( struct Cyc_DesignatorList_tok_struct*)
_temp1396)->f1; goto _LL1399;} else{ goto _LL1400;} _LL1400: goto _LL1401;
_LL1399: return _temp1402; _LL1401:( void) _throw(( void*)& Cyc_yyfail_DesignatorList_tok);
_LL1397:;} static char _temp1407[ 15u]="Designator_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_Designator_tok={ Cyc_Core_Failure,( struct _tagged_string){ _temp1407,
_temp1407, _temp1407 + 15u}}; void* Cyc_yyget_Designator_tok( void* yy1){ void*
_temp1408= yy1; void* _temp1414; _LL1410: if(*(( void**) _temp1408) == Cyc_Designator_tok){
_LL1415: _temp1414=( void*)(( struct Cyc_Designator_tok_struct*) _temp1408)->f1;
goto _LL1411;} else{ goto _LL1412;} _LL1412: goto _LL1413; _LL1411: return
_temp1414; _LL1413:( void) _throw(( void*)& Cyc_yyfail_Designator_tok); _LL1409:;}
static char _temp1419[ 9u]="Kind_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_Kind_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1419, _temp1419, _temp1419 + 9u}};
void* Cyc_yyget_Kind_tok( void* yy1){ void* _temp1420= yy1; void* _temp1426;
_LL1422: if(*(( void**) _temp1420) == Cyc_Kind_tok){ _LL1427: _temp1426=( void*)((
struct Cyc_Kind_tok_struct*) _temp1420)->f1; goto _LL1423;} else{ goto _LL1424;}
_LL1424: goto _LL1425; _LL1423: return _temp1426; _LL1425:( void) _throw(( void*)&
Cyc_yyfail_Kind_tok); _LL1421:;} static char _temp1431[ 9u]="Type_tok"; static
struct Cyc_Core_Failure_struct Cyc_yyfail_Type_tok={ Cyc_Core_Failure,( struct
_tagged_string){ _temp1431, _temp1431, _temp1431 + 9u}}; void* Cyc_yyget_Type_tok(
void* yy1){ void* _temp1432= yy1; void* _temp1438; _LL1434: if(*(( void**)
_temp1432) == Cyc_Type_tok){ _LL1439: _temp1438=( void*)(( struct Cyc_Type_tok_struct*)
_temp1432)->f1; goto _LL1435;} else{ goto _LL1436;} _LL1436: goto _LL1437;
_LL1435: return _temp1438; _LL1437:( void) _throw(( void*)& Cyc_yyfail_Type_tok);
_LL1433:;} static char _temp1443[ 18u]="AttributeList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_AttributeList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1443, _temp1443, _temp1443 + 18u}}; struct Cyc_List_List* Cyc_yyget_AttributeList_tok(
void* yy1){ void* _temp1444= yy1; struct Cyc_List_List* _temp1450; _LL1446: if(*((
void**) _temp1444) == Cyc_AttributeList_tok){ _LL1451: _temp1450=( struct Cyc_List_List*)((
struct Cyc_AttributeList_tok_struct*) _temp1444)->f1; goto _LL1447;} else{ goto
_LL1448;} _LL1448: goto _LL1449; _LL1447: return _temp1450; _LL1449:( void)
_throw(( void*)& Cyc_yyfail_AttributeList_tok); _LL1445:;} static char _temp1455[
14u]="Attribute_tok"; static struct Cyc_Core_Failure_struct Cyc_yyfail_Attribute_tok={
Cyc_Core_Failure,( struct _tagged_string){ _temp1455, _temp1455, _temp1455 + 14u}};
void* Cyc_yyget_Attribute_tok( void* yy1){ void* _temp1456= yy1; void* _temp1462;
_LL1458: if(*(( void**) _temp1456) == Cyc_Attribute_tok){ _LL1463: _temp1462=(
void*)(( struct Cyc_Attribute_tok_struct*) _temp1456)->f1; goto _LL1459;} else{
goto _LL1460;} _LL1460: goto _LL1461; _LL1459: return _temp1462; _LL1461:( void)
_throw(( void*)& Cyc_yyfail_Attribute_tok); _LL1457:;} static char _temp1467[ 14u]="Enumfield_tok";
static struct Cyc_Core_Failure_struct Cyc_yyfail_Enumfield_tok={ Cyc_Core_Failure,(
struct _tagged_string){ _temp1467, _temp1467, _temp1467 + 14u}}; struct Cyc_Absyn_Enumfield*
Cyc_yyget_Enumfield_tok( void* yy1){ void* _temp1468= yy1; struct Cyc_Absyn_Enumfield*
_temp1474; _LL1470: if(*(( void**) _temp1468) == Cyc_Enumfield_tok){ _LL1475:
_temp1474=( struct Cyc_Absyn_Enumfield*)(( struct Cyc_Enumfield_tok_struct*)
_temp1468)->f1; goto _LL1471;} else{ goto _LL1472;} _LL1472: goto _LL1473;
_LL1471: return _temp1474; _LL1473:( void) _throw(( void*)& Cyc_yyfail_Enumfield_tok);
_LL1469:;} static char _temp1479[ 18u]="EnumfieldList_tok"; static struct Cyc_Core_Failure_struct
Cyc_yyfail_EnumfieldList_tok={ Cyc_Core_Failure,( struct _tagged_string){
_temp1479, _temp1479, _temp1479 + 18u}}; struct Cyc_List_List* Cyc_yyget_EnumfieldList_tok(
void* yy1){ void* _temp1480= yy1; struct Cyc_List_List* _temp1486; _LL1482: if(*((
void**) _temp1480) == Cyc_EnumfieldList_tok){ _LL1487: _temp1486=( struct Cyc_List_List*)((
struct Cyc_EnumfieldList_tok_struct*) _temp1480)->f1; goto _LL1483;} else{ goto
_LL1484;} _LL1484: goto _LL1485; _LL1483: return _temp1486; _LL1485:( void)
_throw(( void*)& Cyc_yyfail_EnumfieldList_tok); _LL1481:;} struct Cyc_Yyltype{
int timestamp; int first_line; int first_column; int last_line; int last_column;
struct _tagged_string text; } ; typedef struct Cyc_Yyltype Cyc_yyltype; struct
Cyc_Yyltype Cyc_yynewloc(){ return({ struct Cyc_Yyltype _temp1488; _temp1488.timestamp=
0; _temp1488.first_line= 0; _temp1488.first_column= 0; _temp1488.last_line= 0;
_temp1488.last_column= 0; _temp1488.text=( struct _tagged_string)({ char*
_temp1489=( char*)""; struct _tagged_string _temp1490; _temp1490.curr= _temp1489;
_temp1490.base= _temp1489; _temp1490.last_plus_one= _temp1489 + 1; _temp1490;});
_temp1488;});} static char _temp1493[ 1u]=""; struct Cyc_Yyltype Cyc_yylloc=(
struct Cyc_Yyltype){.timestamp= 0,.first_line= 0,.first_column= 0,.last_line= 0,.last_column=
0,.text=( struct _tagged_string){ _temp1493, _temp1493, _temp1493 + 1u}}; static
short Cyc_yytranslate[ 352u]={ (short)0, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)123, (short)2, (short)2, (short)105,
(short)121, (short)117, (short)2, (short)101, (short)102, (short)112, (short)115,
(short)103, (short)116, (short)109, (short)120, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)108,
(short)97, (short)106, (short)100, (short)107, (short)114, (short)113, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)110, (short)2, (short)111, (short)119, (short)104, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)98, (short)118, (short)99, (short)122, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2, (short)2,
(short)1, (short)2, (short)3, (short)4, (short)5, (short)6, (short)7, (short)8,
(short)9, (short)10, (short)11, (short)12, (short)13, (short)14, (short)15,
(short)16, (short)17, (short)18, (short)19, (short)20, (short)21, (short)22,
(short)23, (short)24, (short)25, (short)26, (short)27, (short)28, (short)29,
(short)30, (short)31, (short)32, (short)33, (short)34, (short)35, (short)36,
(short)37, (short)38, (short)39, (short)40, (short)41, (short)42, (short)43,
(short)44, (short)45, (short)46, (short)47, (short)48, (short)49, (short)50,
(short)51, (short)52, (short)53, (short)54, (short)55, (short)56, (short)57,
(short)58, (short)59, (short)60, (short)61, (short)62, (short)63, (short)64,
(short)65, (short)66, (short)67, (short)68, (short)69, (short)70, (short)71,
(short)72, (short)73, (short)74, (short)75, (short)76, (short)77, (short)78,
(short)79, (short)80, (short)81, (short)82, (short)83, (short)84, (short)85,
(short)86, (short)87, (short)88, (short)89, (short)90, (short)91, (short)92,
(short)93, (short)94, (short)95, (short)96}; static char _temp1496[ 2u]="$";
static char _temp1499[ 6u]="error"; static char _temp1502[ 12u]="$undefined.";
static char _temp1505[ 5u]="AUTO"; static char _temp1508[ 9u]="REGISTER"; static
char _temp1511[ 7u]="STATIC"; static char _temp1514[ 7u]="EXTERN"; static char
_temp1517[ 8u]="TYPEDEF"; static char _temp1520[ 5u]="VOID"; static char
_temp1523[ 5u]="CHAR"; static char _temp1526[ 6u]="SHORT"; static char _temp1529[
4u]="INT"; static char _temp1532[ 5u]="LONG"; static char _temp1535[ 6u]="FLOAT";
static char _temp1538[ 7u]="DOUBLE"; static char _temp1541[ 7u]="SIGNED"; static
char _temp1544[ 9u]="UNSIGNED"; static char _temp1547[ 6u]="CONST"; static char
_temp1550[ 9u]="VOLATILE"; static char _temp1553[ 9u]="RESTRICT"; static char
_temp1556[ 7u]="STRUCT"; static char _temp1559[ 6u]="UNION"; static char
_temp1562[ 5u]="CASE"; static char _temp1565[ 8u]="DEFAULT"; static char
_temp1568[ 7u]="INLINE"; static char _temp1571[ 3u]="IF"; static char _temp1574[
5u]="ELSE"; static char _temp1577[ 7u]="SWITCH"; static char _temp1580[ 6u]="WHILE";
static char _temp1583[ 3u]="DO"; static char _temp1586[ 4u]="FOR"; static char
_temp1589[ 5u]="GOTO"; static char _temp1592[ 9u]="CONTINUE"; static char
_temp1595[ 6u]="BREAK"; static char _temp1598[ 7u]="RETURN"; static char
_temp1601[ 7u]="SIZEOF"; static char _temp1604[ 5u]="ENUM"; static char
_temp1607[ 8u]="NULL_kw"; static char _temp1610[ 4u]="LET"; static char
_temp1613[ 6u]="THROW"; static char _temp1616[ 4u]="TRY"; static char _temp1619[
6u]="CATCH"; static char _temp1622[ 4u]="NEW"; static char _temp1625[ 9u]="ABSTRACT";
static char _temp1628[ 9u]="FALLTHRU"; static char _temp1631[ 6u]="USING";
static char _temp1634[ 10u]="NAMESPACE"; static char _temp1637[ 7u]="TUNION";
static char _temp1640[ 8u]="XTUNION"; static char _temp1643[ 5u]="FILL"; static
char _temp1646[ 8u]="CODEGEN"; static char _temp1649[ 4u]="CUT"; static char
_temp1652[ 7u]="SPLICE"; static char _temp1655[ 7u]="PRINTF"; static char
_temp1658[ 8u]="FPRINTF"; static char _temp1661[ 8u]="XPRINTF"; static char
_temp1664[ 6u]="SCANF"; static char _temp1667[ 7u]="FSCANF"; static char
_temp1670[ 7u]="SSCANF"; static char _temp1673[ 7u]="MALLOC"; static char
_temp1676[ 9u]="REGION_T"; static char _temp1679[ 7u]="REGION"; static char
_temp1682[ 5u]="RNEW"; static char _temp1685[ 8u]="RMALLOC"; static char
_temp1688[ 7u]="PTR_OP"; static char _temp1691[ 7u]="INC_OP"; static char
_temp1694[ 7u]="DEC_OP"; static char _temp1697[ 8u]="LEFT_OP"; static char
_temp1700[ 9u]="RIGHT_OP"; static char _temp1703[ 6u]="LE_OP"; static char
_temp1706[ 6u]="GE_OP"; static char _temp1709[ 6u]="EQ_OP"; static char
_temp1712[ 6u]="NE_OP"; static char _temp1715[ 7u]="AND_OP"; static char
_temp1718[ 6u]="OR_OP"; static char _temp1721[ 11u]="MUL_ASSIGN"; static char
_temp1724[ 11u]="DIV_ASSIGN"; static char _temp1727[ 11u]="MOD_ASSIGN"; static
char _temp1730[ 11u]="ADD_ASSIGN"; static char _temp1733[ 11u]="SUB_ASSIGN";
static char _temp1736[ 12u]="LEFT_ASSIGN"; static char _temp1739[ 13u]="RIGHT_ASSIGN";
static char _temp1742[ 11u]="AND_ASSIGN"; static char _temp1745[ 11u]="XOR_ASSIGN";
static char _temp1748[ 10u]="OR_ASSIGN"; static char _temp1751[ 9u]="ELLIPSIS";
static char _temp1754[ 11u]="LEFT_RIGHT"; static char _temp1757[ 12u]="COLON_COLON";
static char _temp1760[ 11u]="IDENTIFIER"; static char _temp1763[ 17u]="INTEGER_CONSTANT";
static char _temp1766[ 7u]="STRING"; static char _temp1769[ 19u]="CHARACTER_CONSTANT";
static char _temp1772[ 18u]="FLOATING_CONSTANT"; static char _temp1775[ 9u]="TYPE_VAR";
static char _temp1778[ 16u]="QUAL_IDENTIFIER"; static char _temp1781[ 18u]="QUAL_TYPEDEF_NAME";
static char _temp1784[ 10u]="ATTRIBUTE"; static char _temp1787[ 4u]="';'";
static char _temp1790[ 4u]="'{'"; static char _temp1793[ 4u]="'}'"; static char
_temp1796[ 4u]="'='"; static char _temp1799[ 4u]="'('"; static char _temp1802[ 4u]="')'";
static char _temp1805[ 4u]="','"; static char _temp1808[ 4u]="'_'"; static char
_temp1811[ 4u]="'$'"; static char _temp1814[ 4u]="'<'"; static char _temp1817[ 4u]="'>'";
static char _temp1820[ 4u]="':'"; static char _temp1823[ 4u]="'.'"; static char
_temp1826[ 4u]="'['"; static char _temp1829[ 4u]="']'"; static char _temp1832[ 4u]="'*'";
static char _temp1835[ 4u]="'@'"; static char _temp1838[ 4u]="'?'"; static char
_temp1841[ 4u]="'+'"; static char _temp1844[ 4u]="'-'"; static char _temp1847[ 4u]="'&'";
static char _temp1850[ 4u]="'|'"; static char _temp1853[ 4u]="'^'"; static char
_temp1856[ 4u]="'/'"; static char _temp1859[ 4u]="'%'"; static char _temp1862[ 4u]="'~'";
static char _temp1865[ 4u]="'!'"; static char _temp1868[ 5u]="prog"; static char
_temp1871[ 17u]="translation_unit"; static char _temp1874[ 21u]="external_declaration";
static char _temp1877[ 20u]="function_definition"; static char _temp1880[ 21u]="function_definition2";
static char _temp1883[ 13u]="using_action"; static char _temp1886[ 15u]="unusing_action";
static char _temp1889[ 17u]="namespace_action"; static char _temp1892[ 19u]="unnamespace_action";
static char _temp1895[ 12u]="declaration"; static char _temp1898[ 17u]="declaration_list";
static char _temp1901[ 23u]="declaration_specifiers"; static char _temp1904[ 24u]="storage_class_specifier";
static char _temp1907[ 15u]="attributes_opt"; static char _temp1910[ 11u]="attributes";
static char _temp1913[ 15u]="attribute_list"; static char _temp1916[ 10u]="attribute";
static char _temp1919[ 15u]="type_specifier"; static char _temp1922[ 5u]="kind";
static char _temp1925[ 15u]="type_qualifier"; static char _temp1928[ 15u]="enum_specifier";
static char _temp1931[ 11u]="enum_field"; static char _temp1934[ 22u]="enum_declaration_list";
static char _temp1937[ 26u]="struct_or_union_specifier"; static char _temp1940[
16u]="type_params_opt"; static char _temp1943[ 16u]="struct_or_union"; static
char _temp1946[ 24u]="struct_declaration_list"; static char _temp1949[ 25u]="struct_declaration_list0";
static char _temp1952[ 21u]="init_declarator_list"; static char _temp1955[ 22u]="init_declarator_list0";
static char _temp1958[ 16u]="init_declarator"; static char _temp1961[ 19u]="struct_declaration";
static char _temp1964[ 25u]="specifier_qualifier_list"; static char _temp1967[
23u]="struct_declarator_list"; static char _temp1970[ 24u]="struct_declarator_list0";
static char _temp1973[ 18u]="struct_declarator"; static char _temp1976[ 17u]="tunion_specifier";
static char _temp1979[ 18u]="tunion_or_xtunion"; static char _temp1982[ 17u]="tunionfield_list";
static char _temp1985[ 12u]="tunionfield"; static char _temp1988[ 11u]="declarator";
static char _temp1991[ 18u]="direct_declarator"; static char _temp1994[ 8u]="pointer";
static char _temp1997[ 13u]="pointer_char"; static char _temp2000[ 8u]="rgn_opt";
static char _temp2003[ 4u]="rgn"; static char _temp2006[ 20u]="type_qualifier_list";
static char _temp2009[ 20u]="parameter_type_list"; static char _temp2012[ 11u]="effect_set";
static char _temp2015[ 14u]="atomic_effect"; static char _temp2018[ 11u]="region_set";
static char _temp2021[ 15u]="parameter_list"; static char _temp2024[ 22u]="parameter_declaration";
static char _temp2027[ 16u]="identifier_list"; static char _temp2030[ 17u]="identifier_list0";
static char _temp2033[ 12u]="initializer"; static char _temp2036[ 18u]="array_initializer";
static char _temp2039[ 17u]="initializer_list"; static char _temp2042[ 12u]="designation";
static char _temp2045[ 16u]="designator_list"; static char _temp2048[ 11u]="designator";
static char _temp2051[ 10u]="type_name"; static char _temp2054[ 14u]="any_type_name";
static char _temp2057[ 15u]="type_name_list"; static char _temp2060[ 20u]="abstract_declarator";
static char _temp2063[ 27u]="direct_abstract_declarator"; static char _temp2066[
10u]="statement"; static char _temp2069[ 18u]="labeled_statement"; static char
_temp2072[ 21u]="expression_statement"; static char _temp2075[ 19u]="compound_statement";
static char _temp2078[ 16u]="block_item_list"; static char _temp2081[ 11u]="block_item";
static char _temp2084[ 20u]="selection_statement"; static char _temp2087[ 15u]="switch_clauses";
static char _temp2090[ 20u]="iteration_statement"; static char _temp2093[ 15u]="jump_statement";
static char _temp2096[ 8u]="pattern"; static char _temp2099[ 19u]="tuple_pattern_list";
static char _temp2102[ 20u]="tuple_pattern_list0"; static char _temp2105[ 14u]="field_pattern";
static char _temp2108[ 19u]="field_pattern_list"; static char _temp2111[ 20u]="field_pattern_list0";
static char _temp2114[ 11u]="expression"; static char _temp2117[ 22u]="assignment_expression";
static char _temp2120[ 20u]="assignment_operator"; static char _temp2123[ 23u]="conditional_expression";
static char _temp2126[ 20u]="constant_expression"; static char _temp2129[ 22u]="logical_or_expression";
static char _temp2132[ 23u]="logical_and_expression"; static char _temp2135[ 24u]="inclusive_or_expression";
static char _temp2138[ 24u]="exclusive_or_expression"; static char _temp2141[ 15u]="and_expression";
static char _temp2144[ 20u]="equality_expression"; static char _temp2147[ 22u]="relational_expression";
static char _temp2150[ 17u]="shift_expression"; static char _temp2153[ 20u]="additive_expression";
static char _temp2156[ 26u]="multiplicative_expression"; static char _temp2159[
16u]="cast_expression"; static char _temp2162[ 17u]="unary_expression"; static
char _temp2165[ 14u]="format_primop"; static char _temp2168[ 15u]="unary_operator";
static char _temp2171[ 19u]="postfix_expression"; static char _temp2174[ 19u]="primary_expression";
static char _temp2177[ 25u]="argument_expression_list"; static char _temp2180[
26u]="argument_expression_list0"; static char _temp2183[ 9u]="constant"; static
char _temp2186[ 20u]="qual_opt_identifier"; static struct _tagged_string Cyc_yytname[
231u]={( struct _tagged_string){ _temp1496, _temp1496, _temp1496 + 2u},( struct
_tagged_string){ _temp1499, _temp1499, _temp1499 + 6u},( struct _tagged_string){
_temp1502, _temp1502, _temp1502 + 12u},( struct _tagged_string){ _temp1505,
_temp1505, _temp1505 + 5u},( struct _tagged_string){ _temp1508, _temp1508,
_temp1508 + 9u},( struct _tagged_string){ _temp1511, _temp1511, _temp1511 + 7u},(
struct _tagged_string){ _temp1514, _temp1514, _temp1514 + 7u},( struct
_tagged_string){ _temp1517, _temp1517, _temp1517 + 8u},( struct _tagged_string){
_temp1520, _temp1520, _temp1520 + 5u},( struct _tagged_string){ _temp1523,
_temp1523, _temp1523 + 5u},( struct _tagged_string){ _temp1526, _temp1526,
_temp1526 + 6u},( struct _tagged_string){ _temp1529, _temp1529, _temp1529 + 4u},(
struct _tagged_string){ _temp1532, _temp1532, _temp1532 + 5u},( struct
_tagged_string){ _temp1535, _temp1535, _temp1535 + 6u},( struct _tagged_string){
_temp1538, _temp1538, _temp1538 + 7u},( struct _tagged_string){ _temp1541,
_temp1541, _temp1541 + 7u},( struct _tagged_string){ _temp1544, _temp1544,
_temp1544 + 9u},( struct _tagged_string){ _temp1547, _temp1547, _temp1547 + 6u},(
struct _tagged_string){ _temp1550, _temp1550, _temp1550 + 9u},( struct
_tagged_string){ _temp1553, _temp1553, _temp1553 + 9u},( struct _tagged_string){
_temp1556, _temp1556, _temp1556 + 7u},( struct _tagged_string){ _temp1559,
_temp1559, _temp1559 + 6u},( struct _tagged_string){ _temp1562, _temp1562,
_temp1562 + 5u},( struct _tagged_string){ _temp1565, _temp1565, _temp1565 + 8u},(
struct _tagged_string){ _temp1568, _temp1568, _temp1568 + 7u},( struct
_tagged_string){ _temp1571, _temp1571, _temp1571 + 3u},( struct _tagged_string){
_temp1574, _temp1574, _temp1574 + 5u},( struct _tagged_string){ _temp1577,
_temp1577, _temp1577 + 7u},( struct _tagged_string){ _temp1580, _temp1580,
_temp1580 + 6u},( struct _tagged_string){ _temp1583, _temp1583, _temp1583 + 3u},(
struct _tagged_string){ _temp1586, _temp1586, _temp1586 + 4u},( struct
_tagged_string){ _temp1589, _temp1589, _temp1589 + 5u},( struct _tagged_string){
_temp1592, _temp1592, _temp1592 + 9u},( struct _tagged_string){ _temp1595,
_temp1595, _temp1595 + 6u},( struct _tagged_string){ _temp1598, _temp1598,
_temp1598 + 7u},( struct _tagged_string){ _temp1601, _temp1601, _temp1601 + 7u},(
struct _tagged_string){ _temp1604, _temp1604, _temp1604 + 5u},( struct
_tagged_string){ _temp1607, _temp1607, _temp1607 + 8u},( struct _tagged_string){
_temp1610, _temp1610, _temp1610 + 4u},( struct _tagged_string){ _temp1613,
_temp1613, _temp1613 + 6u},( struct _tagged_string){ _temp1616, _temp1616,
_temp1616 + 4u},( struct _tagged_string){ _temp1619, _temp1619, _temp1619 + 6u},(
struct _tagged_string){ _temp1622, _temp1622, _temp1622 + 4u},( struct
_tagged_string){ _temp1625, _temp1625, _temp1625 + 9u},( struct _tagged_string){
_temp1628, _temp1628, _temp1628 + 9u},( struct _tagged_string){ _temp1631,
_temp1631, _temp1631 + 6u},( struct _tagged_string){ _temp1634, _temp1634,
_temp1634 + 10u},( struct _tagged_string){ _temp1637, _temp1637, _temp1637 + 7u},(
struct _tagged_string){ _temp1640, _temp1640, _temp1640 + 8u},( struct
_tagged_string){ _temp1643, _temp1643, _temp1643 + 5u},( struct _tagged_string){
_temp1646, _temp1646, _temp1646 + 8u},( struct _tagged_string){ _temp1649,
_temp1649, _temp1649 + 4u},( struct _tagged_string){ _temp1652, _temp1652,
_temp1652 + 7u},( struct _tagged_string){ _temp1655, _temp1655, _temp1655 + 7u},(
struct _tagged_string){ _temp1658, _temp1658, _temp1658 + 8u},( struct
_tagged_string){ _temp1661, _temp1661, _temp1661 + 8u},( struct _tagged_string){
_temp1664, _temp1664, _temp1664 + 6u},( struct _tagged_string){ _temp1667,
_temp1667, _temp1667 + 7u},( struct _tagged_string){ _temp1670, _temp1670,
_temp1670 + 7u},( struct _tagged_string){ _temp1673, _temp1673, _temp1673 + 7u},(
struct _tagged_string){ _temp1676, _temp1676, _temp1676 + 9u},( struct
_tagged_string){ _temp1679, _temp1679, _temp1679 + 7u},( struct _tagged_string){
_temp1682, _temp1682, _temp1682 + 5u},( struct _tagged_string){ _temp1685,
_temp1685, _temp1685 + 8u},( struct _tagged_string){ _temp1688, _temp1688,
_temp1688 + 7u},( struct _tagged_string){ _temp1691, _temp1691, _temp1691 + 7u},(
struct _tagged_string){ _temp1694, _temp1694, _temp1694 + 7u},( struct
_tagged_string){ _temp1697, _temp1697, _temp1697 + 8u},( struct _tagged_string){
_temp1700, _temp1700, _temp1700 + 9u},( struct _tagged_string){ _temp1703,
_temp1703, _temp1703 + 6u},( struct _tagged_string){ _temp1706, _temp1706,
_temp1706 + 6u},( struct _tagged_string){ _temp1709, _temp1709, _temp1709 + 6u},(
struct _tagged_string){ _temp1712, _temp1712, _temp1712 + 6u},( struct
_tagged_string){ _temp1715, _temp1715, _temp1715 + 7u},( struct _tagged_string){
_temp1718, _temp1718, _temp1718 + 6u},( struct _tagged_string){ _temp1721,
_temp1721, _temp1721 + 11u},( struct _tagged_string){ _temp1724, _temp1724,
_temp1724 + 11u},( struct _tagged_string){ _temp1727, _temp1727, _temp1727 + 11u},(
struct _tagged_string){ _temp1730, _temp1730, _temp1730 + 11u},( struct
_tagged_string){ _temp1733, _temp1733, _temp1733 + 11u},( struct _tagged_string){
_temp1736, _temp1736, _temp1736 + 12u},( struct _tagged_string){ _temp1739,
_temp1739, _temp1739 + 13u},( struct _tagged_string){ _temp1742, _temp1742,
_temp1742 + 11u},( struct _tagged_string){ _temp1745, _temp1745, _temp1745 + 11u},(
struct _tagged_string){ _temp1748, _temp1748, _temp1748 + 10u},( struct
_tagged_string){ _temp1751, _temp1751, _temp1751 + 9u},( struct _tagged_string){
_temp1754, _temp1754, _temp1754 + 11u},( struct _tagged_string){ _temp1757,
_temp1757, _temp1757 + 12u},( struct _tagged_string){ _temp1760, _temp1760,
_temp1760 + 11u},( struct _tagged_string){ _temp1763, _temp1763, _temp1763 + 17u},(
struct _tagged_string){ _temp1766, _temp1766, _temp1766 + 7u},( struct
_tagged_string){ _temp1769, _temp1769, _temp1769 + 19u},( struct _tagged_string){
_temp1772, _temp1772, _temp1772 + 18u},( struct _tagged_string){ _temp1775,
_temp1775, _temp1775 + 9u},( struct _tagged_string){ _temp1778, _temp1778,
_temp1778 + 16u},( struct _tagged_string){ _temp1781, _temp1781, _temp1781 + 18u},(
struct _tagged_string){ _temp1784, _temp1784, _temp1784 + 10u},( struct
_tagged_string){ _temp1787, _temp1787, _temp1787 + 4u},( struct _tagged_string){
_temp1790, _temp1790, _temp1790 + 4u},( struct _tagged_string){ _temp1793,
_temp1793, _temp1793 + 4u},( struct _tagged_string){ _temp1796, _temp1796,
_temp1796 + 4u},( struct _tagged_string){ _temp1799, _temp1799, _temp1799 + 4u},(
struct _tagged_string){ _temp1802, _temp1802, _temp1802 + 4u},( struct
_tagged_string){ _temp1805, _temp1805, _temp1805 + 4u},( struct _tagged_string){
_temp1808, _temp1808, _temp1808 + 4u},( struct _tagged_string){ _temp1811,
_temp1811, _temp1811 + 4u},( struct _tagged_string){ _temp1814, _temp1814,
_temp1814 + 4u},( struct _tagged_string){ _temp1817, _temp1817, _temp1817 + 4u},(
struct _tagged_string){ _temp1820, _temp1820, _temp1820 + 4u},( struct
_tagged_string){ _temp1823, _temp1823, _temp1823 + 4u},( struct _tagged_string){
_temp1826, _temp1826, _temp1826 + 4u},( struct _tagged_string){ _temp1829,
_temp1829, _temp1829 + 4u},( struct _tagged_string){ _temp1832, _temp1832,
_temp1832 + 4u},( struct _tagged_string){ _temp1835, _temp1835, _temp1835 + 4u},(
struct _tagged_string){ _temp1838, _temp1838, _temp1838 + 4u},( struct
_tagged_string){ _temp1841, _temp1841, _temp1841 + 4u},( struct _tagged_string){
_temp1844, _temp1844, _temp1844 + 4u},( struct _tagged_string){ _temp1847,
_temp1847, _temp1847 + 4u},( struct _tagged_string){ _temp1850, _temp1850,
_temp1850 + 4u},( struct _tagged_string){ _temp1853, _temp1853, _temp1853 + 4u},(
struct _tagged_string){ _temp1856, _temp1856, _temp1856 + 4u},( struct
_tagged_string){ _temp1859, _temp1859, _temp1859 + 4u},( struct _tagged_string){
_temp1862, _temp1862, _temp1862 + 4u},( struct _tagged_string){ _temp1865,
_temp1865, _temp1865 + 4u},( struct _tagged_string){ _temp1868, _temp1868,
_temp1868 + 5u},( struct _tagged_string){ _temp1871, _temp1871, _temp1871 + 17u},(
struct _tagged_string){ _temp1874, _temp1874, _temp1874 + 21u},( struct
_tagged_string){ _temp1877, _temp1877, _temp1877 + 20u},( struct _tagged_string){
_temp1880, _temp1880, _temp1880 + 21u},( struct _tagged_string){ _temp1883,
_temp1883, _temp1883 + 13u},( struct _tagged_string){ _temp1886, _temp1886,
_temp1886 + 15u},( struct _tagged_string){ _temp1889, _temp1889, _temp1889 + 17u},(
struct _tagged_string){ _temp1892, _temp1892, _temp1892 + 19u},( struct
_tagged_string){ _temp1895, _temp1895, _temp1895 + 12u},( struct _tagged_string){
_temp1898, _temp1898, _temp1898 + 17u},( struct _tagged_string){ _temp1901,
_temp1901, _temp1901 + 23u},( struct _tagged_string){ _temp1904, _temp1904,
_temp1904 + 24u},( struct _tagged_string){ _temp1907, _temp1907, _temp1907 + 15u},(
struct _tagged_string){ _temp1910, _temp1910, _temp1910 + 11u},( struct
_tagged_string){ _temp1913, _temp1913, _temp1913 + 15u},( struct _tagged_string){
_temp1916, _temp1916, _temp1916 + 10u},( struct _tagged_string){ _temp1919,
_temp1919, _temp1919 + 15u},( struct _tagged_string){ _temp1922, _temp1922,
_temp1922 + 5u},( struct _tagged_string){ _temp1925, _temp1925, _temp1925 + 15u},(
struct _tagged_string){ _temp1928, _temp1928, _temp1928 + 15u},( struct
_tagged_string){ _temp1931, _temp1931, _temp1931 + 11u},( struct _tagged_string){
_temp1934, _temp1934, _temp1934 + 22u},( struct _tagged_string){ _temp1937,
_temp1937, _temp1937 + 26u},( struct _tagged_string){ _temp1940, _temp1940,
_temp1940 + 16u},( struct _tagged_string){ _temp1943, _temp1943, _temp1943 + 16u},(
struct _tagged_string){ _temp1946, _temp1946, _temp1946 + 24u},( struct
_tagged_string){ _temp1949, _temp1949, _temp1949 + 25u},( struct _tagged_string){
_temp1952, _temp1952, _temp1952 + 21u},( struct _tagged_string){ _temp1955,
_temp1955, _temp1955 + 22u},( struct _tagged_string){ _temp1958, _temp1958,
_temp1958 + 16u},( struct _tagged_string){ _temp1961, _temp1961, _temp1961 + 19u},(
struct _tagged_string){ _temp1964, _temp1964, _temp1964 + 25u},( struct
_tagged_string){ _temp1967, _temp1967, _temp1967 + 23u},( struct _tagged_string){
_temp1970, _temp1970, _temp1970 + 24u},( struct _tagged_string){ _temp1973,
_temp1973, _temp1973 + 18u},( struct _tagged_string){ _temp1976, _temp1976,
_temp1976 + 17u},( struct _tagged_string){ _temp1979, _temp1979, _temp1979 + 18u},(
struct _tagged_string){ _temp1982, _temp1982, _temp1982 + 17u},( struct
_tagged_string){ _temp1985, _temp1985, _temp1985 + 12u},( struct _tagged_string){
_temp1988, _temp1988, _temp1988 + 11u},( struct _tagged_string){ _temp1991,
_temp1991, _temp1991 + 18u},( struct _tagged_string){ _temp1994, _temp1994,
_temp1994 + 8u},( struct _tagged_string){ _temp1997, _temp1997, _temp1997 + 13u},(
struct _tagged_string){ _temp2000, _temp2000, _temp2000 + 8u},( struct
_tagged_string){ _temp2003, _temp2003, _temp2003 + 4u},( struct _tagged_string){
_temp2006, _temp2006, _temp2006 + 20u},( struct _tagged_string){ _temp2009,
_temp2009, _temp2009 + 20u},( struct _tagged_string){ _temp2012, _temp2012,
_temp2012 + 11u},( struct _tagged_string){ _temp2015, _temp2015, _temp2015 + 14u},(
struct _tagged_string){ _temp2018, _temp2018, _temp2018 + 11u},( struct
_tagged_string){ _temp2021, _temp2021, _temp2021 + 15u},( struct _tagged_string){
_temp2024, _temp2024, _temp2024 + 22u},( struct _tagged_string){ _temp2027,
_temp2027, _temp2027 + 16u},( struct _tagged_string){ _temp2030, _temp2030,
_temp2030 + 17u},( struct _tagged_string){ _temp2033, _temp2033, _temp2033 + 12u},(
struct _tagged_string){ _temp2036, _temp2036, _temp2036 + 18u},( struct
_tagged_string){ _temp2039, _temp2039, _temp2039 + 17u},( struct _tagged_string){
_temp2042, _temp2042, _temp2042 + 12u},( struct _tagged_string){ _temp2045,
_temp2045, _temp2045 + 16u},( struct _tagged_string){ _temp2048, _temp2048,
_temp2048 + 11u},( struct _tagged_string){ _temp2051, _temp2051, _temp2051 + 10u},(
struct _tagged_string){ _temp2054, _temp2054, _temp2054 + 14u},( struct
_tagged_string){ _temp2057, _temp2057, _temp2057 + 15u},( struct _tagged_string){
_temp2060, _temp2060, _temp2060 + 20u},( struct _tagged_string){ _temp2063,
_temp2063, _temp2063 + 27u},( struct _tagged_string){ _temp2066, _temp2066,
_temp2066 + 10u},( struct _tagged_string){ _temp2069, _temp2069, _temp2069 + 18u},(
struct _tagged_string){ _temp2072, _temp2072, _temp2072 + 21u},( struct
_tagged_string){ _temp2075, _temp2075, _temp2075 + 19u},( struct _tagged_string){
_temp2078, _temp2078, _temp2078 + 16u},( struct _tagged_string){ _temp2081,
_temp2081, _temp2081 + 11u},( struct _tagged_string){ _temp2084, _temp2084,
_temp2084 + 20u},( struct _tagged_string){ _temp2087, _temp2087, _temp2087 + 15u},(
struct _tagged_string){ _temp2090, _temp2090, _temp2090 + 20u},( struct
_tagged_string){ _temp2093, _temp2093, _temp2093 + 15u},( struct _tagged_string){
_temp2096, _temp2096, _temp2096 + 8u},( struct _tagged_string){ _temp2099,
_temp2099, _temp2099 + 19u},( struct _tagged_string){ _temp2102, _temp2102,
_temp2102 + 20u},( struct _tagged_string){ _temp2105, _temp2105, _temp2105 + 14u},(
struct _tagged_string){ _temp2108, _temp2108, _temp2108 + 19u},( struct
_tagged_string){ _temp2111, _temp2111, _temp2111 + 20u},( struct _tagged_string){
_temp2114, _temp2114, _temp2114 + 11u},( struct _tagged_string){ _temp2117,
_temp2117, _temp2117 + 22u},( struct _tagged_string){ _temp2120, _temp2120,
_temp2120 + 20u},( struct _tagged_string){ _temp2123, _temp2123, _temp2123 + 23u},(
struct _tagged_string){ _temp2126, _temp2126, _temp2126 + 20u},( struct
_tagged_string){ _temp2129, _temp2129, _temp2129 + 22u},( struct _tagged_string){
_temp2132, _temp2132, _temp2132 + 23u},( struct _tagged_string){ _temp2135,
_temp2135, _temp2135 + 24u},( struct _tagged_string){ _temp2138, _temp2138,
_temp2138 + 24u},( struct _tagged_string){ _temp2141, _temp2141, _temp2141 + 15u},(
struct _tagged_string){ _temp2144, _temp2144, _temp2144 + 20u},( struct
_tagged_string){ _temp2147, _temp2147, _temp2147 + 22u},( struct _tagged_string){
_temp2150, _temp2150, _temp2150 + 17u},( struct _tagged_string){ _temp2153,
_temp2153, _temp2153 + 20u},( struct _tagged_string){ _temp2156, _temp2156,
_temp2156 + 26u},( struct _tagged_string){ _temp2159, _temp2159, _temp2159 + 16u},(
struct _tagged_string){ _temp2162, _temp2162, _temp2162 + 17u},( struct
_tagged_string){ _temp2165, _temp2165, _temp2165 + 14u},( struct _tagged_string){
_temp2168, _temp2168, _temp2168 + 15u},( struct _tagged_string){ _temp2171,
_temp2171, _temp2171 + 19u},( struct _tagged_string){ _temp2174, _temp2174,
_temp2174 + 19u},( struct _tagged_string){ _temp2177, _temp2177, _temp2177 + 25u},(
struct _tagged_string){ _temp2180, _temp2180, _temp2180 + 26u},( struct
_tagged_string){ _temp2183, _temp2183, _temp2183 + 9u},( struct _tagged_string){
_temp2186, _temp2186, _temp2186 + 20u}}; static short Cyc_yyr1[ 391u]={ (short)0,
(short)124, (short)125, (short)125, (short)125, (short)125, (short)125, (short)125,
(short)125, (short)126, (short)126, (short)127, (short)127, (short)127, (short)127,
(short)128, (short)128, (short)129, (short)130, (short)131, (short)132, (short)133,
(short)133, (short)133, (short)134, (short)134, (short)135, (short)135, (short)135,
(short)135, (short)135, (short)135, (short)135, (short)135, (short)136, (short)136,
(short)136, (short)136, (short)136, (short)136, (short)136, (short)137, (short)137,
(short)138, (short)139, (short)139, (short)140, (short)140, (short)140, (short)140,
(short)141, (short)141, (short)141, (short)141, (short)141, (short)141, (short)141,
(short)141, (short)141, (short)141, (short)141, (short)141, (short)141, (short)141,
(short)141, (short)141, (short)141, (short)141, (short)142, (short)142, (short)143,
(short)143, (short)143, (short)144, (short)144, (short)145, (short)145, (short)146,
(short)146, (short)147, (short)147, (short)147, (short)147, (short)147, (short)148,
(short)148, (short)148, (short)149, (short)149, (short)150, (short)151, (short)151,
(short)152, (short)153, (short)153, (short)154, (short)154, (short)155, (short)156,
(short)156, (short)156, (short)156, (short)157, (short)158, (short)158, (short)159,
(short)159, (short)159, (short)160, (short)160, (short)160, (short)160, (short)161,
(short)161, (short)162, (short)162, (short)162, (short)162, (short)163, (short)163,
(short)164, (short)164, (short)165, (short)165, (short)165, (short)165, (short)165,
(short)165, (short)165, (short)165, (short)165, (short)165, (short)165, (short)166,
(short)166, (short)166, (short)166, (short)167, (short)167, (short)167, (short)167,
(short)167, (short)168, (short)168, (short)169, (short)169, (short)169, (short)170,
(short)170, (short)171, (short)171, (short)171, (short)172, (short)172, (short)173,
(short)173, (short)173, (short)173, (short)174, (short)174, (short)174, (short)174,
(short)175, (short)175, (short)176, (short)176, (short)176, (short)177, (short)178,
(short)178, (short)179, (short)179, (short)180, (short)180, (short)180, (short)180,
(short)181, (short)181, (short)181, (short)181, (short)182, (short)183, (short)183,
(short)184, (short)184, (short)185, (short)185, (short)186, (short)186, (short)186,
(short)186, (short)187, (short)187, (short)188, (short)188, (short)188, (short)189,
(short)189, (short)189, (short)189, (short)189, (short)189, (short)189, (short)189,
(short)189, (short)189, (short)189, (short)189, (short)189, (short)189, (short)190,
(short)190, (short)190, (short)190, (short)190, (short)190, (short)190, (short)190,
(short)190, (short)190, (short)191, (short)192, (short)192, (short)193, (short)193,
(short)194, (short)194, (short)195, (short)195, (short)195, (short)196, (short)196,
(short)196, (short)196, (short)197, (short)197, (short)197, (short)197, (short)197,
(short)197, (short)198, (short)198, (short)198, (short)198, (short)198, (short)198,
(short)198, (short)198, (short)198, (short)198, (short)198, (short)198, (short)198,
(short)198, (short)199, (short)199, (short)199, (short)199, (short)199, (short)199,
(short)199, (short)199, (short)200, (short)200, (short)200, (short)200, (short)200,
(short)200, (short)200, (short)200, (short)200, (short)200, (short)200, (short)200,
(short)200, (short)200, (short)201, (short)201, (short)202, (short)202, (short)203,
(short)203, (short)204, (short)205, (short)205, (short)206, (short)206, (short)207,
(short)207, (short)208, (short)208, (short)208, (short)208, (short)208, (short)208,
(short)208, (short)208, (short)208, (short)208, (short)208, (short)209, (short)209,
(short)209, (short)209, (short)209, (short)209, (short)209, (short)210, (short)211,
(short)211, (short)212, (short)212, (short)213, (short)213, (short)214, (short)214,
(short)215, (short)215, (short)216, (short)216, (short)216, (short)217, (short)217,
(short)217, (short)217, (short)217, (short)218, (short)218, (short)218, (short)219,
(short)219, (short)219, (short)220, (short)220, (short)220, (short)220, (short)221,
(short)221, (short)222, (short)222, (short)222, (short)222, (short)222, (short)222,
(short)222, (short)222, (short)222, (short)222, (short)222, (short)222, (short)223,
(short)223, (short)223, (short)223, (short)223, (short)223, (short)224, (short)224,
(short)224, (short)225, (short)225, (short)225, (short)225, (short)225, (short)225,
(short)225, (short)225, (short)225, (short)225, (short)225, (short)225, (short)225,
(short)225, (short)226, (short)226, (short)226, (short)226, (short)226, (short)226,
(short)226, (short)226, (short)226, (short)227, (short)228, (short)228, (short)229,
(short)229, (short)229, (short)229, (short)230, (short)230}; static short Cyc_yyr2[
391u]={ (short)0, (short)1, (short)2, (short)3, (short)5, (short)3, (short)5,
(short)6, (short)0, (short)1, (short)1, (short)2, (short)3, (short)3, (short)4,
(short)3, (short)4, (short)2, (short)1, (short)2, (short)1, (short)2, (short)3,
(short)5, (short)1, (short)2, (short)2, (short)3, (short)2, (short)3, (short)2,
(short)3, (short)2, (short)3, (short)1, (short)1, (short)1, (short)1, (short)2,
(short)1, (short)1, (short)0, (short)1, (short)6, (short)1, (short)3, (short)1,
(short)1, (short)4, (short)4, (short)1, (short)1, (short)1, (short)1, (short)1,
(short)1, (short)1, (short)1, (short)1, (short)1, (short)1, (short)1, (short)1,
(short)1, (short)3, (short)2, (short)4, (short)4, (short)1, (short)1, (short)1,
(short)1, (short)1, (short)5, (short)2, (short)1, (short)3, (short)1, (short)3,
(short)4, (short)6, (short)6, (short)3, (short)3, (short)0, (short)3, (short)3,
(short)1, (short)1, (short)1, (short)1, (short)2, (short)1, (short)1, (short)3,
(short)1, (short)3, (short)3, (short)2, (short)3, (short)2, (short)3, (short)1,
(short)1, (short)3, (short)1, (short)2, (short)3, (short)6, (short)3, (short)4,
(short)5, (short)1, (short)1, (short)1, (short)2, (short)3, (short)3, (short)1,
(short)5, (short)1, (short)2, (short)1, (short)3, (short)3, (short)4, (short)4,
(short)3, (short)5, (short)4, (short)4, (short)4, (short)2, (short)3, (short)4,
(short)4, (short)5, (short)1, (short)1, (short)4, (short)4, (short)1, (short)0,
(short)1, (short)1, (short)3, (short)1, (short)1, (short)2, (short)1, (short)3,
(short)3, (short)1, (short)3, (short)2, (short)3, (short)1, (short)3, (short)1,
(short)3, (short)3, (short)5, (short)1, (short)3, (short)2, (short)1, (short)2,
(short)1, (short)1, (short)3, (short)1, (short)1, (short)2, (short)3, (short)4,
(short)8, (short)1, (short)2, (short)3, (short)4, (short)2, (short)1, (short)2,
(short)3, (short)2, (short)1, (short)2, (short)1, (short)2, (short)3, (short)3,
(short)1, (short)3, (short)1, (short)1, (short)2, (short)3, (short)2, (short)3,
(short)3, (short)4, (short)2, (short)4, (short)3, (short)3, (short)5, (short)4,
(short)4, (short)4, (short)2, (short)1, (short)1, (short)1, (short)1, (short)1,
(short)1, (short)6, (short)3, (short)2, (short)2, (short)3, (short)1, (short)2,
(short)2, (short)3, (short)1, (short)2, (short)1, (short)1, (short)1, (short)5,
(short)7, (short)7, (short)6, (short)0, (short)3, (short)4, (short)5, (short)6,
(short)7, (short)5, (short)7, (short)6, (short)7, (short)7, (short)8, (short)7,
(short)8, (short)8, (short)9, (short)6, (short)7, (short)7, (short)8, (short)3,
(short)2, (short)2, (short)2, (short)3, (short)2, (short)4, (short)5, (short)1,
(short)3, (short)1, (short)2, (short)1, (short)1, (short)1, (short)1, (short)5,
(short)4, (short)4, (short)5, (short)2, (short)2, (short)0, (short)1, (short)1,
(short)3, (short)1, (short)2, (short)1, (short)1, (short)3, (short)1, (short)3,
(short)1, (short)3, (short)1, (short)1, (short)1, (short)1, (short)1, (short)1,
(short)1, (short)1, (short)1, (short)1, (short)1, (short)1, (short)5, (short)2,
(short)2, (short)2, (short)5, (short)5, (short)1, (short)1, (short)3, (short)1,
(short)3, (short)1, (short)3, (short)1, (short)3, (short)1, (short)3, (short)1,
(short)3, (short)3, (short)1, (short)3, (short)3, (short)3, (short)3, (short)1,
(short)3, (short)3, (short)1, (short)3, (short)3, (short)1, (short)3, (short)3,
(short)3, (short)1, (short)4, (short)1, (short)2, (short)2, (short)2, (short)2,
(short)2, (short)2, (short)4, (short)2, (short)4, (short)7, (short)9, (short)1,
(short)1, (short)1, (short)1, (short)1, (short)1, (short)1, (short)1, (short)1,
(short)1, (short)4, (short)3, (short)4, (short)3, (short)3, (short)3, (short)3,
(short)2, (short)2, (short)6, (short)7, (short)4, (short)4, (short)1, (short)1,
(short)1, (short)3, (short)2, (short)5, (short)4, (short)4, (short)5, (short)1,
(short)1, (short)3, (short)1, (short)1, (short)1, (short)1, (short)1, (short)1};
static short Cyc_yydefact[ 748u]={ (short)8, (short)34, (short)35, (short)36,
(short)37, (short)39, (short)50, (short)52, (short)53, (short)54, (short)55,
(short)56, (short)57, (short)58, (short)59, (short)70, (short)71, (short)72,
(short)87, (short)88, (short)41, (short)0, (short)0, (short)40, (short)0,
(short)0, (short)112, (short)113, (short)0, (short)389, (short)63, (short)390,
(short)84, (short)0, (short)51, (short)0, (short)137, (short)138, (short)141,
(short)1, (short)8, (short)9, (short)0, (short)0, (short)10, (short)0, (short)41,
(short)41, (short)41, (short)60, (short)61, (short)0, (short)62, (short)0,
(short)0, (short)120, (short)0, (short)142, (short)122, (short)38, (short)0,
(short)32, (short)42, (short)74, (short)268, (short)264, (short)267, (short)266,
(short)0, (short)262, (short)0, (short)0, (short)0, (short)0, (short)0, (short)269,
(short)17, (short)19, (short)0, (short)0, (short)0, (short)65, (short)0, (short)0,
(short)0, (short)0, (short)2, (short)8, (short)8, (short)8, (short)8, (short)21,
(short)0, (short)92, (short)93, (short)95, (short)26, (short)28, (short)30,
(short)84, (short)0, (short)84, (short)144, (short)146, (short)0, (short)84,
(short)37, (short)0, (short)24, (short)0, (short)0, (short)11, (short)0, (short)0,
(short)0, (short)132, (short)121, (short)41, (short)143, (short)8, (short)0,
(short)33, (short)0, (short)0, (short)276, (short)275, (short)265, (short)274,
(short)0, (short)0, (short)0, (short)41, (short)41, (short)185, (short)187,
(short)0, (short)68, (short)69, (short)64, (short)191, (short)0, (short)123,
(short)165, (short)0, (short)162, (short)0, (short)388, (short)0, (short)0,
(short)0, (short)0, (short)350, (short)351, (short)352, (short)353, (short)354,
(short)355, (short)0, (short)0, (short)0, (short)0, (short)0, (short)385,
(short)375, (short)386, (short)387, (short)0, (short)0, (short)0, (short)0,
(short)358, (short)0, (short)356, (short)357, (short)0, (short)287, (short)300,
(short)308, (short)310, (short)312, (short)314, (short)316, (short)318, (short)321,
(short)326, (short)329, (short)332, (short)336, (short)0, (short)0, (short)338,
(short)359, (short)374, (short)373, (short)0, (short)3, (short)0, (short)5,
(short)0, (short)22, (short)0, (short)0, (short)0, (short)12, (short)27, (short)29,
(short)31, (short)83, (short)0, (short)89, (short)90, (short)0, (short)82,
(short)0, (short)84, (short)0, (short)109, (short)38, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)389, (short)221, (short)223,
(short)0, (short)229, (short)227, (short)0, (short)228, (short)210, (short)211,
(short)212, (short)0, (short)225, (short)213, (short)214, (short)215, (short)0,
(short)285, (short)25, (short)13, (short)95, (short)168, (short)0, (short)127,
(short)0, (short)149, (short)0, (short)167, (short)0, (short)124, (short)0,
(short)133, (short)0, (short)0, (short)77, (short)0, (short)75, (short)263,
(short)278, (short)0, (short)277, (short)0, (short)0, (short)276, (short)158,
(short)188, (short)0, (short)98, (short)100, (short)0, (short)0, (short)193,
(short)186, (short)194, (short)67, (short)0, (short)86, (short)0, (short)85,
(short)0, (short)164, (short)193, (short)166, (short)66, (short)0, (short)0,
(short)346, (short)302, (short)336, (short)0, (short)303, (short)304, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)339, (short)340,
(short)0, (short)0, (short)0, (short)0, (short)342, (short)343, (short)341,
(short)139, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)290, (short)291, (short)292,
(short)293, (short)294, (short)295, (short)296, (short)297, (short)298, (short)299,
(short)289, (short)0, (short)0, (short)344, (short)0, (short)367, (short)368,
(short)0, (short)0, (short)0, (short)377, (short)0, (short)0, (short)140,
(short)18, (short)8, (short)20, (short)8, (short)94, (short)96, (short)171,
(short)170, (short)14, (short)0, (short)79, (short)91, (short)0, (short)0,
(short)102, (short)103, (short)105, (short)0, (short)145, (short)110, (short)84,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)255,
(short)256, (short)257, (short)0, (short)0, (short)259, (short)0, (short)218,
(short)219, (short)0, (short)0, (short)0, (short)0, (short)95, (short)224,
(short)226, (short)222, (short)0, (short)156, (short)0, (short)0, (short)152,
(short)126, (short)0, (short)0, (short)129, (short)0, (short)131, (short)130,
(short)125, (short)147, (short)135, (short)134, (short)8, (short)47, (short)46,
(short)0, (short)44, (short)0, (short)73, (short)0, (short)271, (short)0,
(short)23, (short)272, (short)0, (short)0, (short)0, (short)0, (short)181,
(short)280, (short)283, (short)0, (short)282, (short)0, (short)0, (short)0,
(short)189, (short)99, (short)101, (short)0, (short)201, (short)0, (short)0,
(short)197, (short)0, (short)195, (short)0, (short)0, (short)0, (short)209,
(short)190, (short)192, (short)163, (short)0, (short)0, (short)172, (short)176,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)376, (short)383, (short)0, (short)382,
(short)309, (short)0, (short)311, (short)313, (short)315, (short)317, (short)319,
(short)320, (short)324, (short)325, (short)322, (short)323, (short)327, (short)328,
(short)330, (short)331, (short)333, (short)334, (short)335, (short)288, (short)0,
(short)365, (short)366, (short)361, (short)0, (short)363, (short)364, (short)0,
(short)0, (short)0, (short)4, (short)6, (short)0, (short)307, (short)106,
(short)97, (short)0, (short)0, (short)0, (short)111, (short)0, (short)114,
(short)118, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)254, (short)258, (short)0, (short)0, (short)0, (short)217, (short)0,
(short)220, (short)0, (short)15, (short)286, (short)0, (short)154, (short)0,
(short)128, (short)0, (short)151, (short)150, (short)169, (short)148, (short)136,
(short)7, (short)0, (short)0, (short)0, (short)78, (short)76, (short)279,
(short)184, (short)0, (short)281, (short)180, (short)182, (short)273, (short)0,
(short)270, (short)160, (short)159, (short)0, (short)203, (short)196, (short)199,
(short)0, (short)204, (short)0, (short)0, (short)198, (short)0, (short)345,
(short)0, (short)173, (short)0, (short)177, (short)371, (short)372, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)337, (short)379,
(short)0, (short)0, (short)347, (short)362, (short)360, (short)380, (short)0,
(short)0, (short)81, (short)104, (short)107, (short)80, (short)108, (short)115,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)234, (short)260, (short)0, (short)0,
(short)16, (short)157, (short)155, (short)153, (short)0, (short)0, (short)43,
(short)45, (short)183, (short)284, (short)0, (short)202, (short)0, (short)206,
(short)208, (short)207, (short)200, (short)0, (short)174, (short)178, (short)0,
(short)0, (short)305, (short)306, (short)0, (short)381, (short)0, (short)384,
(short)301, (short)378, (short)117, (short)116, (short)0, (short)230, (short)234,
(short)240, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)261, (short)0, (short)48,
(short)49, (short)161, (short)205, (short)0, (short)179, (short)0, (short)0,
(short)369, (short)0, (short)0, (short)0, (short)0, (short)0, (short)242,
(short)0, (short)0, (short)0, (short)250, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)233, (short)216, (short)0,
(short)348, (short)0, (short)370, (short)119, (short)231, (short)232, (short)241,
(short)243, (short)244, (short)0, (short)252, (short)251, (short)0, (short)246,
(short)0, (short)0, (short)0, (short)0, (short)234, (short)235, (short)0,
(short)0, (short)245, (short)253, (short)247, (short)248, (short)0, (short)0,
(short)234, (short)236, (short)175, (short)349, (short)249, (short)234, (short)237,
(short)234, (short)238, (short)239, (short)0, (short)0, (short)0}; static short
Cyc_yydefgoto[ 107u]={ (short)745, (short)39, (short)40, (short)41, (short)236,
(short)42, (short)364, (short)43, (short)366, (short)44, (short)202, (short)45,
(short)46, (short)61, (short)62, (short)427, (short)428, (short)47, (short)138,
(short)48, (short)49, (short)266, (short)267, (short)50, (short)81, (short)51,
(short)208, (short)209, (short)92, (short)93, (short)94, (short)210, (short)133,
(short)376, (short)377, (short)378, (short)52, (short)53, (short)524, (short)525,
(short)54, (short)55, (short)56, (short)57, (short)117, (short)104, (short)423,
(short)453, (short)411, (short)412, (short)278, (short)257, (short)144, (short)258,
(short)259, (short)468, (short)369, (short)469, (short)470, (short)439, (short)440,
(short)134, (short)139, (short)140, (short)454, (short)285, (short)239, (short)240,
(short)241, (short)242, (short)243, (short)244, (short)245, (short)674, (short)246,
(short)247, (short)270, (short)271, (short)272, (short)442, (short)443, (short)444,
(short)248, (short)249, (short)350, (short)175, (short)518, (short)176, (short)177,
(short)178, (short)179, (short)180, (short)181, (short)182, (short)183, (short)184,
(short)185, (short)186, (short)187, (short)188, (short)189, (short)190, (short)191,
(short)482, (short)483, (short)192, (short)193}; static short Cyc_yypact[ 748u]={
(short)1764, - (short)-32768, - (short)-32768, - (short)-32768, - (short)69, -
(short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)28, (short)185, (short)529, - (short)-32768, (short)185, (short)2, -
(short)-32768, - (short)-32768, (short)22, - (short)-32768, (short)52, - (short)-32768,
(short)36, (short)314, - (short)-32768, (short)64, (short)101, (short)124, -
(short)-32768, - (short)-32768, (short)1764, - (short)-32768, (short)137,
(short)205, - (short)-32768, (short)310, - (short)28, - (short)28, - (short)28,
- (short)-32768, - (short)-32768, (short)180, - (short)-32768, (short)104,
(short)2062, (short)111, (short)156, - (short)5, - (short)-32768, (short)158,
(short)182, (short)2122, - (short)-32768, (short)194, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, (short)529, - (short)-32768, (short)199,
(short)229, (short)269, (short)529, (short)219, (short)166, - (short)-32768, -
(short)-32768, (short)2262, (short)145, (short)2262, - (short)-32768, (short)225,
(short)2329, (short)3840, (short)3840, - (short)-32768, (short)1764, (short)1764,
(short)1764, (short)1764, - (short)-32768, (short)282, (short)267, - (short)-32768,
(short)1999, (short)2122, (short)2122, (short)2122, (short)36, (short)2329,
(short)36, (short)303, - (short)-32768, (short)185, (short)140, (short)306,
(short)1169, - (short)-32768, (short)2062, (short)310, - (short)-32768, (short)577,
(short)2262, (short)2704, - (short)-32768, (short)111, - (short)28, - (short)-32768,
(short)1764, (short)292, - (short)-32768, (short)185, (short)299, (short)529, -
(short)-32768, - (short)-32768, - (short)-32768, (short)3840, - (short)47,
(short)187, - (short)28, - (short)28, (short)408, - (short)-32768, (short)94, -
(short)-32768, - (short)-32768, - (short)-32768, (short)291, - (short)22, -
(short)-32768, (short)224, (short)243, - (short)-32768, (short)4053, - (short)-32768,
(short)3840, (short)3911, (short)312, (short)318, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)320,
(short)324, (short)332, (short)4124, (short)4124, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, (short)1527, (short)336, (short)4195, (short)4195,
- (short)-32768, (short)4195, - (short)-32768, - (short)-32768, (short)317, -
(short)-32768, - (short)35, (short)374, (short)334, (short)331, (short)351,
(short)261, (short)97, (short)342, (short)315, (short)65, - (short)-32768,
(short)627, (short)379, (short)4195, (short)105, - (short)-32768, - (short)-32768,
- (short)11, (short)383, - (short)-32768, (short)391, - (short)-32768, (short)397,
- (short)-32768, (short)314, (short)2775, (short)2062, - (short)-32768, -
(short)-32768, - (short)-32768, - (short)-32768, (short)406, (short)420, (short)2329,
- (short)-32768, (short)393, (short)435, (short)145, (short)36, (short)185,
(short)450, - (short)-32768, (short)437, (short)452, (short)455, (short)2146,
(short)457, (short)473, (short)472, (short)476, (short)2846, (short)2146,
(short)99, (short)2146, (short)2146, (short)44, (short)466, - (short)-32768, -
(short)-32768, (short)474, - (short)-32768, - (short)-32768, (short)310, -
(short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)477,
(short)1290, - (short)-32768, - (short)-32768, - (short)-32768, (short)184, -
(short)-32768, - (short)-32768, - (short)-32768, (short)479, - (short)-32768,
(short)89, - (short)-32768, (short)475, (short)191, (short)478, (short)480,
(short)46, - (short)-32768, (short)470, (short)10, (short)483, (short)6, (short)496,
(short)501, (short)502, - (short)-32768, - (short)-32768, (short)499, (short)500,
(short)202, (short)701, (short)529, - (short)55, - (short)-32768, (short)505,
(short)2329, (short)2329, (short)1939, (short)2917, - (short)27, - (short)-32768,
(short)122, - (short)-32768, (short)89, - (short)-32768, (short)2262, - (short)-32768,
(short)1879, - (short)-32768, (short)33, - (short)-32768, - (short)-32768,
(short)2329, (short)1527, - (short)-32768, - (short)-32768, - (short)-32768,
(short)2348, - (short)-32768, (short)531, (short)3840, (short)1824, (short)571,
(short)3840, (short)3840, (short)1527, - (short)-32768, - (short)-32768, (short)1290,
(short)506, (short)333, (short)3840, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)-32768, (short)4195, (short)3840, (short)4195, (short)4195, (short)4195,
(short)4195, (short)4195, (short)4195, (short)4195, (short)4195, (short)4195,
(short)4195, (short)4195, (short)4195, (short)4195, (short)4195, (short)4195,
(short)4195, (short)4195, - (short)-32768, - (short)-32768, - (short)-32768, -
(short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, (short)3840, (short)3840, -
(short)-32768, (short)150, - (short)-32768, - (short)-32768, (short)2988,
(short)160, (short)3840, - (short)-32768, (short)2615, (short)503, - (short)-32768,
- (short)-32768, (short)1764, - (short)-32768, (short)1764, - (short)-32768, -
(short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)2329, -
(short)-32768, - (short)-32768, (short)3840, (short)513, (short)508, - (short)-32768,
(short)507, (short)2329, - (short)-32768, - (short)-32768, (short)36, (short)185,
(short)3840, (short)3840, (short)3840, (short)586, (short)1411, (short)519, -
(short)-32768, - (short)-32768, - (short)-32768, (short)207, (short)578, -
(short)-32768, (short)3059, - (short)-32768, - (short)-32768, (short)2146,
(short)533, (short)2146, (short)1643, (short)1999, - (short)-32768, - (short)-32768,
- (short)-32768, (short)3840, (short)542, (short)230, (short)530, (short)516, -
(short)-32768, (short)89, (short)2276, - (short)-32768, (short)547, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)10,
(short)1764, - (short)-32768, (short)535, (short)536, (short)537, (short)185, -
(short)-32768, (short)3840, - (short)-32768, (short)529, - (short)-32768, -
(short)-32768, (short)554, (short)3840, (short)529, (short)9, - (short)-32768, -
(short)-32768, - (short)-32768, (short)544, (short)541, (short)545, (short)145,
(short)555, - (short)-32768, - (short)-32768, - (short)-32768, (short)89, -
(short)-32768, (short)548, (short)550, - (short)-32768, (short)543, (short)122,
(short)903, (short)2262, (short)3130, - (short)-32768, - (short)-32768, (short)291,
- (short)-32768, (short)553, (short)568, - (short)-32768, - (short)-32768,
(short)8, (short)2775, (short)356, (short)556, (short)314, (short)558, (short)363,
(short)557, (short)559, (short)563, (short)3982, - (short)-32768, - (short)-32768,
(short)561, (short)564, (short)374, (short)162, (short)334, (short)331, (short)351,
(short)261, (short)97, (short)97, (short)342, (short)342, (short)342, (short)342,
(short)315, (short)315, (short)65, (short)65, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, (short)566, - (short)-32768, - (short)-32768,
- (short)-32768, (short)567, - (short)-32768, - (short)-32768, (short)102,
(short)121, (short)2262, - (short)-32768, - (short)-32768, (short)574, - (short)-32768,
- (short)-32768, - (short)-32768, (short)393, (short)3840, (short)579, - (short)-32768,
(short)581, (short)227, (short)214, (short)368, (short)375, (short)382, (short)576,
(short)3201, (short)3272, (short)246, - (short)-32768, - (short)-32768, (short)585,
(short)560, (short)582, - (short)-32768, (short)580, - (short)-32768, (short)2062,
- (short)-32768, - (short)-32768, (short)145, - (short)-32768, (short)590, -
(short)-32768, (short)89, - (short)-32768, - (short)-32768, - (short)-32768, -
(short)-32768, - (short)-32768, - (short)-32768, (short)409, (short)583, (short)6,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)584,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)844,
- (short)-32768, (short)588, - (short)-32768, (short)591, - (short)-32768, -
(short)-32768, - (short)-32768, (short)89, - (short)-32768, (short)592, (short)57,
- (short)-32768, (short)587, (short)594, (short)593, - (short)-32768, (short)2437,
- (short)-32768, - (short)-32768, - (short)-32768, (short)2062, (short)2329,
(short)3911, (short)665, (short)594, (short)610, (short)2615, - (short)-32768, -
(short)-32768, (short)3840, (short)3840, - (short)-32768, - (short)-32768, -
(short)-32768, - (short)-32768, (short)2615, (short)241, - (short)-32768, -
(short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)185,
(short)185, (short)612, (short)2146, (short)616, (short)2146, (short)3840,
(short)3343, (short)268, (short)3414, (short)271, (short)3485, (short)491, -
(short)-32768, (short)618, (short)628, - (short)-32768, - (short)-32768, -
(short)-32768, - (short)-32768, (short)619, (short)620, - (short)-32768, -
(short)-32768, - (short)-32768, - (short)-32768, (short)555, - (short)-32768,
(short)621, - (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768,
(short)3840, - (short)-32768, - (short)-32768, (short)2775, (short)622, -
(short)-32768, (short)531, (short)617, - (short)-32768, (short)274, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)2329,
(short)699, (short)491, - (short)-32768, (short)414, (short)2146, (short)422,
(short)3556, (short)2146, (short)424, (short)3627, (short)3698, (short)272,
(short)529, (short)623, (short)629, - (short)-32768, (short)2146, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, (short)258, - (short)-32768,
(short)624, (short)2329, - (short)-32768, (short)2526, (short)426, (short)2146,
(short)630, (short)633, - (short)-32768, (short)2146, (short)2146, (short)429, -
(short)-32768, (short)2146, (short)2146, (short)438, (short)2146, (short)440,
(short)3769, - (short)42, (short)1290, - (short)-32768, - (short)-32768, (short)3840,
- (short)-32768, (short)632, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, (short)2146,
- (short)-32768, - (short)-32768, (short)2146, - (short)-32768, (short)2146,
(short)2146, (short)443, (short)3840, (short)1010, - (short)-32768, (short)289,
(short)634, - (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768,
(short)2146, (short)273, (short)491, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)-32768, (short)1010, - (short)-32768, (short)491, - (short)-32768, -
(short)-32768, (short)739, (short)742, - (short)-32768}; static short Cyc_yypgoto[
107u]={ - (short)-32768, (short)91, - (short)-32768, (short)439, - (short)-32768,
- (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768, - (short)50,
- (short)41, - (short)54, - (short)-32768, (short)30, - (short)43, (short)188, -
(short)-32768, (short)17, - (short)183, - (short)20, - (short)-32768, - (short)-32768,
(short)316, - (short)-32768, (short)11, - (short)-32768, - (short)161, - (short)-32768,
- (short)-32768, - (short)-32768, (short)549, (short)539, (short)76, - (short)-32768,
- (short)-32768, (short)231, - (short)-32768, - (short)-32768, - (short)49, -
(short)-32768, - (short)9, - (short)46, - (short)107, - (short)-32768, - (short)-32768,
(short)695, - (short)-32768, - (short)94, - (short)381, (short)467, - (short)385,
- (short)81, - (short)274, - (short)-32768, - (short)-32768, - (short)186, -
(short)145, - (short)354, - (short)257, - (short)-32768, (short)319, - (short)146,
- (short)59, - (short)108, (short)3, - (short)139, (short)157, - (short)-32768,
- (short)-32768, - (short)45, - (short)230, - (short)-32768, - (short)-32768, -
(short)627, - (short)-32768, - (short)-32768, - (short)21, (short)482, - (short)-32768,
(short)195, - (short)-32768, - (short)-32768, (short)165, (short)152, - (short)-32768,
- (short)136, - (short)366, - (short)140, (short)433, (short)442, (short)432,
(short)441, (short)434, (short)238, (short)113, (short)235, (short)237, (short)4,
(short)572, - (short)-32768, - (short)-32768, - (short)-32768, - (short)-32768,
- (short)260, - (short)-32768, - (short)-32768, (short)16}; static short Cyc_yytable[
4319u]={ (short)110, (short)74, (short)143, (short)302, (short)108, (short)260,
(short)512, (short)121, (short)303, (short)111, (short)116, (short)299, (short)115,
(short)109, (short)406, (short)368, (short)58, (short)438, (short)256, (short)135,
(short)313, (short)59, (short)464, (short)425, (short)82, (short)547, (short)283,
(short)15, (short)16, (short)17, (short)381, (short)724, (short)446, (short)550,
(short)689, (short)293, (short)95, (short)63, (short)75, (short)320, (short)76,
(short)110, (short)204, (short)205, (short)206, (short)108, (short)288, (short)123,
(short)447, (short)58, (short)203, (short)274, (short)127, (short)238, (short)275,
(short)110, (short)58, (short)237, (short)132, (short)250, (short)132, (short)58,
(short)571, (short)132, (short)251, (short)560, (short)725, (short)101, (short)60,
(short)105, (short)572, (short)563, (short)58, (short)115, (short)281, (short)359,
(short)96, (short)97, (short)98, (short)321, (short)132, (short)289, (short)478,
(short)282, (short)75, (short)290, (short)129, (short)360, (short)102, (short)75,
(short)77, (short)504, (short)132, (short)132, (short)426, (short)131, (short)508,
(short)131, (short)736, (short)103, (short)131, (short)252, (short)361, (short)58,
(short)58, (short)58, (short)58, (short)584, (short)741, (short)565, (short)207,
(short)585, (short)212, (short)743, (short)418, (short)744, (short)216, (short)131,
(short)436, (short)437, (short)214, (short)29, (short)36, (short)37, (short)38,
(short)641, (short)58, (short)31, (short)78, (short)131, (short)131, (short)86,
(short)400, (short)292, (short)291, (short)58, (short)284, (short)538, (short)268,
(short)79, (short)75, (short)464, (short)80, (short)282, (short)457, (short)294,
(short)132, (short)263, (short)110, (short)289, (short)401, (short)465, (short)250,
(short)419, (short)457, (short)608, (short)422, (short)371, (short)58, (short)142,
(short)289, (short)279, (short)280, (short)477, (short)642, (short)83, (short)328,
(short)329, (short)630, (short)353, (short)354, (short)355, (short)316, (short)317,
(short)283, (short)318, (short)211, (short)336, (short)195, (short)196, (short)197,
(short)198, (short)409, (short)131, (short)293, (short)337, (short)338, (short)410,
(short)142, (short)132, (short)238, (short)252, (short)29, (short)352, (short)237,
(short)639, (short)396, (short)102, (short)31, (short)84, (short)397, (short)286,
(short)379, (short)330, (short)331, (short)408, (short)356, (short)60, (short)103,
(short)287, (short)264, (short)516, (short)112, (short)602, (short)357, (short)358,
(short)58, (short)113, (short)60, (short)522, (short)603, (short)114, (short)85,
(short)458, (short)604, (short)382, (short)131, (short)58, (short)459, (short)404,
(short)463, (short)383, (short)460, (short)136, (short)87, (short)88, (short)174,
(short)194, (short)505, (short)517, (short)137, (short)653, (short)461, (short)421,
(short)29, (short)506, (short)80, (short)116, (short)509, (short)215, (short)31,
(short)473, (short)679, (short)441, (short)58, (short)510, (short)119, (short)33,
(short)238, (short)132, (short)132, (short)132, (short)237, (short)570, -
(short)84, (short)408, (short)262, - (short)84, (short)29, (short)132, (short)599,
(short)132, (short)80, (short)29, (short)31, (short)99, (short)132, (short)132,
(short)100, (short)31, (short)276, (short)407, (short)82, (short)120, (short)586,
(short)211, (short)277, (short)408, (short)414, (short)132, (short)75, (short)75,
(short)122, (short)273, (short)415, (short)517, (short)131, (short)131, (short)131,
(short)434, (short)124, (short)517, (short)89, (short)90, (short)535, (short)408,
(short)131, (short)58, (short)131, (short)58, (short)408, (short)438, (short)29,
(short)131, (short)131, - (short)84, (short)554, (short)125, (short)31, (short)128,
(short)80, (short)58, (short)143, (short)276, (short)611, (short)291, (short)131,
(short)141, (short)647, (short)546, (short)612, (short)314, (short)326, (short)327,
(short)282, (short)110, (short)36, (short)37, (short)38, (short)532, (short)500,
(short)501, (short)502, (short)622, (short)289, (short)295, (short)296, (short)647,
(short)656, (short)408, (short)110, (short)579, (short)132, (short)370, (short)108,
(short)449, (short)450, (short)142, (short)126, (short)543, (short)132, (short)408,
(short)628, (short)542, (short)578, (short)666, (short)706, (short)142, (short)669,
(short)701, (short)200, (short)408, (short)142, (short)685, (short)408, (short)408,
(short)408, (short)686, (short)388, (short)199, (short)58, (short)740, (short)58,
(short)132, (short)395, (short)517, (short)398, (short)399, (short)737, (short)131,
(short)213, (short)394, (short)408, (short)265, (short)523, (short)132, (short)217,
(short)131, (short)29, (short)646, (short)526, (short)269, (short)29, (short)553,
(short)31, (short)605, (short)287, (short)91, (short)31, (short)332, (short)333,
(short)33, (short)561, (short)304, (short)461, (short)33, (short)319, (short)564,
(short)646, (short)305, (short)131, (short)306, (short)36, (short)37, (short)38,
(short)307, (short)36, (short)37, (short)38, (short)647, (short)334, (short)335,
(short)131, (short)308, (short)456, (short)480, (short)408, (short)315, (short)132,
(short)132, (short)58, (short)492, (short)493, (short)494, (short)495, (short)268,
(short)649, (short)322, (short)211, (short)75, (short)324, (short)650, (short)323,
(short)370, (short)75, (short)514, (short)211, (short)515, (short)587, (short)408,
(short)476, (short)682, (short)314, (short)655, (short)589, (short)591, (short)408,
(short)481, (short)325, (short)471, (short)614, (short)408, (short)475, (short)726,
(short)314, (short)131, (short)131, (short)615, (short)408, (short)142, (short)351,
(short)29, (short)362, (short)596, (short)616, (short)408, (short)485, (short)31,
(short)110, (short)58, (short)363, (short)142, (short)250, (short)132, (short)33,
(short)735, (short)365, (short)627, (short)631, (short)632, (short)646, (short)375,
(short)503, (short)481, (short)372, (short)36, (short)37, (short)38, (short)481,
(short)281, (short)742, (short)379, (short)370, (short)672, (short)673, (short)555,
(short)690, (short)408, (short)282, (short)373, (short)36, (short)37, (short)38,
(short)511, (short)692, (short)408, (short)696, (short)408, (short)710, (short)296,
(short)131, (short)716, (short)408, (short)380, (short)142, (short)110, (short)58,
(short)613, (short)385, (short)108, (short)719, (short)408, (short)721, (short)408,
(short)203, (short)733, (short)408, (short)441, (short)384, (short)481, (short)527,
(short)528, (short)529, (short)386, (short)533, (short)481, (short)387, (short)539,
(short)389, (short)541, (short)544, (short)390, (short)657, (short)658, (short)490,
(short)491, (short)64, (short)496, (short)497, (short)391, (short)132, (short)498,
(short)499, (short)392, (short)402, (short)403, (short)405, (short)413, (short)687,
(short)201, (short)416, (short)420, (short)424, (short)417, (short)75, (short)6,
(short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)429,
(short)430, (short)432, (short)431, (short)433, (short)448, (short)320, (short)474,
(short)131, (short)479, (short)513, (short)519, (short)520, (short)581, (short)21,
(short)530, (short)521, (short)534, (short)29, (short)65, (short)536, (short)66,
(short)67, (short)370, (short)31, (short)26, (short)27, (short)540, (short)526,
(short)526, (short)545, (short)68, (short)549, (short)548, (short)69, (short)70,
(short)552, (short)556, (short)28, (short)557, (short)132, (short)558, (short)71,
(short)562, (short)567, (short)568, (short)72, (short)73, (short)569, (short)276,
(short)238, (short)573, (short)702, (short)574, (short)237, (short)575, (short)582,
(short)583, (short)624, (short)588, (short)590, (short)592, (short)593, (short)594,
(short)597, (short)132, (short)253, (short)648, (short)598, (short)600, (short)601,
(short)30, (short)238, (short)32, (short)606, (short)254, (short)237, (short)131,
(short)617, (short)609, (short)255, (short)610, (short)34, (short)35, (short)623,
(short)625, (short)633, (short)238, (short)626, (short)75, (short)629, (short)237,
(short)637, (short)595, (short)638, (short)640, (short)635, (short)619, (short)621,
(short)643, (short)644, (short)651, (short)131, (short)339, (short)340, (short)341,
(short)342, (short)343, (short)344, (short)345, (short)346, (short)347, (short)348,
(short)652, (short)659, (short)661, (short)675, (short)676, (short)298, (short)684,
(short)300, (short)300, (short)677, (short)678, (short)680, (short)683, (short)688,
(short)707, (short)349, (short)704, (short)712, (short)713, (short)703, (short)310,
(short)311, (short)728, (short)142, (short)738, (short)370, (short)64, (short)746,
(short)300, (short)300, (short)747, (short)300, (short)472, (short)559, (short)634,
(short)370, (short)374, (short)367, (short)654, (short)607, (short)118, (short)484,
(short)462, (short)487, (short)370, (short)445, (short)566, (short)489, (short)708,
(short)300, (short)0, (short)636, (short)486, (short)488, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)660, (short)0, (short)662, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)663,
(short)665, (short)0, (short)668, (short)0, (short)671, (short)0, (short)29,
(short)65, (short)0, (short)66, (short)67, (short)0, (short)31, (short)0,
(short)0, (short)0, (short)370, (short)435, (short)0, (short)68, (short)0,
(short)0, (short)69, (short)70, (short)0, (short)0, (short)681, (short)436,
(short)437, (short)0, (short)71, (short)0, (short)0, (short)0, (short)72,
(short)73, (short)0, (short)0, (short)691, (short)0, (short)0, (short)695,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)694, (short)0,
(short)705, (short)698, (short)700, (short)0, (short)0, (short)370, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)711, (short)0, (short)0,
(short)0, (short)714, (short)715, (short)0, (short)0, (short)717, (short)718,
(short)0, (short)720, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)723, (short)0, (short)0, (short)0, (short)0,
(short)727, (short)0, (short)729, (short)0, (short)0, (short)730, (short)0,
(short)731, (short)732, (short)0, (short)64, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)734, (short)739, (short)0,
(short)300, (short)0, (short)300, (short)300, (short)300, (short)300, (short)300,
(short)300, (short)300, (short)300, (short)300, (short)300, (short)300, (short)300,
(short)300, (short)300, (short)300, (short)300, (short)300, (short)6, (short)7,
(short)8, (short)9, (short)10, (short)11, (short)12, (short)13, (short)14,
(short)15, (short)16, (short)17, (short)18, (short)19, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)65, (short)0,
(short)66, (short)67, (short)0, (short)31, (short)21, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)68, (short)0, (short)300, (short)69,
(short)70, (short)26, (short)27, (short)0, (short)436, (short)437, (short)0,
(short)71, (short)0, (short)0, (short)0, (short)72, (short)73, (short)0, (short)28,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)30, (short)0, (short)32, (short)0, (short)576, (short)0, (short)0,
(short)300, (short)0, (short)577, (short)0, (short)34, (short)35, (short)300,
(short)0, (short)0, (short)0, (short)1, (short)2, (short)3, (short)106, (short)5,
(short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)672,
(short)673, (short)20, (short)218, (short)0, (short)219, (short)220, (short)221,
(short)222, (short)223, (short)224, (short)225, (short)226, (short)145, (short)21,
(short)146, (short)22, (short)147, (short)227, (short)300, (short)148, (short)23,
(short)228, (short)0, (short)0, (short)26, (short)27, (short)149, (short)150,
(short)229, (short)230, (short)151, (short)152, (short)153, (short)154, (short)155,
(short)156, (short)157, (short)28, (short)231, (short)158, (short)159, (short)0,
(short)160, (short)161, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)300, (short)0, (short)0, (short)0, (short)0,
(short)232, (short)162, (short)163, (short)164, (short)165, (short)30, (short)31,
(short)32, (short)0, (short)233, (short)107, (short)0, (short)0, (short)166,
(short)0, (short)0, (short)34, (short)235, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)168, (short)0, (short)0, (short)169, (short)170,
(short)171, (short)0, (short)0, (short)0, (short)0, (short)172, (short)173,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)300, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)300, (short)1, (short)2,
(short)3, (short)106, (short)5, (short)6, (short)7, (short)8, (short)9, (short)10,
(short)11, (short)12, (short)13, (short)14, (short)15, (short)16, (short)17,
(short)18, (short)19, (short)0, (short)0, (short)20, (short)218, (short)0,
(short)219, (short)220, (short)221, (short)222, (short)223, (short)224, (short)225,
(short)226, (short)145, (short)21, (short)146, (short)22, (short)147, (short)227,
(short)0, (short)148, (short)23, (short)228, (short)0, (short)0, (short)26,
(short)27, (short)149, (short)150, (short)229, (short)230, (short)151, (short)152,
(short)153, (short)154, (short)155, (short)156, (short)157, (short)28, (short)231,
(short)158, (short)159, (short)0, (short)160, (short)161, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)232, (short)162, (short)163, (short)164,
(short)165, (short)30, (short)31, (short)32, (short)0, (short)233, (short)107,
(short)234, (short)0, (short)166, (short)0, (short)0, (short)34, (short)235,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)168, (short)0,
(short)0, (short)169, (short)170, (short)171, (short)0, (short)0, (short)0,
(short)0, (short)172, (short)173, (short)1, (short)2, (short)3, (short)106,
(short)5, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12,
(short)13, (short)14, (short)15, (short)16, (short)17, (short)18, (short)19,
(short)0, (short)0, (short)20, (short)218, (short)0, (short)219, (short)220,
(short)221, (short)222, (short)223, (short)224, (short)225, (short)226, (short)145,
(short)21, (short)146, (short)22, (short)147, (short)227, (short)0, (short)148,
(short)23, (short)228, (short)0, (short)0, (short)26, (short)27, (short)149,
(short)150, (short)229, (short)230, (short)151, (short)152, (short)153, (short)154,
(short)155, (short)156, (short)157, (short)28, (short)231, (short)158, (short)159,
(short)0, (short)160, (short)161, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)232, (short)162, (short)163, (short)164, (short)165, (short)30,
(short)31, (short)32, (short)0, (short)233, (short)107, (short)0, (short)0,
(short)166, (short)0, (short)0, (short)34, (short)235, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)168, (short)0, (short)0, (short)169,
(short)170, (short)171, (short)0, (short)0, (short)0, (short)0, (short)172,
(short)173, (short)1, (short)2, (short)3, (short)106, (short)5, (short)6,
(short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)0,
(short)0, (short)20, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)145, (short)21, (short)146,
(short)22, (short)147, (short)0, (short)0, (short)148, (short)23, (short)0,
(short)0, (short)0, (short)26, (short)27, (short)149, (short)150, (short)0,
(short)0, (short)151, (short)152, (short)153, (short)154, (short)155, (short)156,
(short)157, (short)28, (short)0, (short)158, (short)159, (short)0, (short)160,
(short)161, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162,
(short)163, (short)164, (short)165, (short)30, (short)31, (short)32, (short)0,
(short)531, (short)0, (short)0, (short)0, (short)166, (short)0, (short)0,
(short)34, (short)235, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)168, (short)0, (short)0, (short)169, (short)170, (short)171, (short)0,
(short)0, (short)0, (short)0, (short)172, (short)173, (short)6, (short)7,
(short)8, (short)9, (short)10, (short)11, (short)12, (short)13, (short)14,
(short)15, (short)16, (short)17, (short)18, (short)19, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)145, (short)21, (short)146, (short)0,
(short)147, (short)0, (short)0, (short)148, (short)0, (short)0, (short)0,
(short)0, (short)26, (short)27, (short)149, (short)150, (short)0, (short)0,
(short)151, (short)152, (short)153, (short)154, (short)155, (short)156, (short)157,
(short)28, (short)0, (short)158, (short)159, (short)0, (short)160, (short)161,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162, (short)163,
(short)164, (short)165, (short)30, (short)31, (short)32, (short)0, (short)0,
(short)312, (short)0, (short)0, (short)166, (short)0, (short)0, (short)34,
(short)235, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)168,
(short)0, (short)0, (short)169, (short)170, (short)171, (short)0, (short)0,
(short)0, (short)0, (short)172, (short)173, (short)6, (short)7, (short)8,
(short)9, (short)10, (short)11, (short)12, (short)13, (short)14, (short)15,
(short)16, (short)17, (short)18, (short)19, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)145, (short)21, (short)146, (short)0, (short)147,
(short)0, (short)0, (short)148, (short)0, (short)0, (short)0, (short)0, (short)26,
(short)27, (short)149, (short)150, (short)0, (short)0, (short)151, (short)152,
(short)153, (short)154, (short)155, (short)156, (short)157, (short)28, (short)0,
(short)158, (short)159, (short)0, (short)160, (short)161, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)29, (short)162, (short)163, (short)164,
(short)165, (short)30, (short)31, (short)32, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)166, (short)0, (short)0, (short)34, (short)235,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)168, (short)0,
(short)0, (short)169, (short)170, (short)171, (short)0, (short)0, (short)0,
(short)0, (short)172, (short)173, (short)1, (short)2, (short)3, (short)4,
(short)5, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12,
(short)13, (short)14, (short)15, (short)16, (short)17, (short)18, (short)19,
(short)0, (short)0, (short)20, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)21, (short)0,
(short)22, (short)0, (short)0, (short)0, (short)0, (short)23, (short)0, (short)24,
(short)25, (short)26, (short)27, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)28, (short)0,
(short)0, (short)1, (short)2, (short)3, (short)106, (short)5, (short)6, (short)7,
(short)8, (short)9, (short)10, (short)11, (short)12, (short)13, (short)14,
(short)15, (short)16, (short)17, (short)18, (short)19, (short)0, (short)0,
(short)20, (short)0, (short)0, (short)0, (short)29, (short)0, (short)0, (short)0,
(short)0, (short)30, (short)31, (short)32, (short)21, (short)0, (short)0,
(short)0, (short)0, (short)33, (short)0, (short)23, (short)34, (short)35,
(short)0, (short)26, (short)27, (short)0, (short)0, (short)0, (short)36, (short)37,
(short)38, (short)0, (short)0, (short)0, (short)0, (short)0, (short)28, (short)0,
(short)0, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12,
(short)13, (short)14, (short)15, (short)16, (short)17, (short)18, (short)19,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)29, (short)0, (short)0, (short)21, (short)0,
(short)30, (short)31, (short)32, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)33, (short)26, (short)27, (short)34, (short)35, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)36, (short)37, (short)38, (short)28,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)6,
(short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)0, (short)0,
(short)0, (short)0, (short)30, (short)31, (short)32, (short)21, (short)451,
(short)0, (short)0, (short)0, (short)291, (short)452, (short)0, (short)34,
(short)35, (short)0, (short)26, (short)27, (short)0, (short)282, (short)0,
(short)36, (short)37, (short)38, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)28, (short)0, (short)0, (short)1, (short)2, (short)3, (short)106, (short)5,
(short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)0,
(short)0, (short)20, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)30, (short)0, (short)32, (short)21, (short)451,
(short)22, (short)0, (short)0, (short)281, (short)452, (short)23, (short)34,
(short)35, (short)0, (short)26, (short)27, (short)0, (short)282, (short)0,
(short)36, (short)37, (short)38, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)28, (short)0, (short)0, (short)0, (short)0, (short)0, (short)1, (short)2,
(short)3, (short)106, (short)5, (short)6, (short)7, (short)8, (short)9, (short)10,
(short)11, (short)12, (short)13, (short)14, (short)15, (short)16, (short)17,
(short)18, (short)19, (short)0, (short)0, (short)20, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)30, (short)0, (short)32, (short)0, (short)0, (short)107,
(short)21, (short)201, (short)22, (short)0, (short)0, (short)34, (short)35,
(short)23, (short)0, (short)0, (short)0, (short)26, (short)27, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)28, (short)0, (short)0, (short)1, (short)2, (short)3, (short)106,
(short)5, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12,
(short)13, (short)14, (short)15, (short)16, (short)17, (short)18, (short)19,
(short)0, (short)0, (short)20, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)30, (short)0, (short)32, (short)21, (short)0,
(short)107, (short)0, (short)0, (short)0, (short)0, (short)23, (short)34,
(short)35, (short)0, (short)26, (short)27, (short)218, (short)0, (short)219,
(short)220, (short)221, (short)222, (short)223, (short)224, (short)225, (short)226,
(short)145, (short)28, (short)146, (short)0, (short)147, (short)227, (short)0,
(short)148, (short)0, (short)228, (short)0, (short)0, (short)0, (short)0,
(short)149, (short)150, (short)229, (short)230, (short)151, (short)152, (short)153,
(short)154, (short)155, (short)156, (short)157, (short)0, (short)231, (short)158,
(short)159, (short)0, (short)160, (short)161, (short)0, (short)0, (short)30,
(short)0, (short)32, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)34, (short)35, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)232, (short)162, (short)163, (short)164, (short)165,
(short)0, (short)31, (short)0, (short)0, (short)233, (short)107, (short)0,
(short)0, (short)166, (short)0, (short)0, (short)0, (short)167, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)168, (short)0, (short)0,
(short)169, (short)170, (short)171, (short)0, (short)0, (short)0, (short)0,
(short)172, (short)173, (short)6, (short)7, (short)8, (short)9, (short)10,
(short)11, (short)12, (short)13, (short)14, (short)15, (short)16, (short)17,
(short)18, (short)19, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11,
(short)12, (short)13, (short)14, (short)15, (short)16, (short)17, (short)18,
(short)19, (short)21, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)26, (short)27, (short)0, (short)21,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)28, (short)26, (short)27, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)28,
(short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)0,
(short)0, (short)0, (short)0, (short)30, (short)0, (short)32, (short)0, (short)0,
(short)130, (short)551, (short)0, (short)0, (short)0, (short)21, (short)34,
(short)35, (short)0, (short)30, (short)0, (short)32, (short)0, (short)0, (short)0,
(short)0, (short)26, (short)27, (short)466, (short)0, (short)34, (short)35,
(short)0, (short)145, (short)0, (short)146, (short)0, (short)147, (short)0,
(short)28, (short)148, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)149, (short)150, (short)0, (short)0, (short)151, (short)152, (short)153,
(short)154, (short)155, (short)156, (short)157, (short)0, (short)0, (short)158,
(short)159, (short)0, (short)160, (short)161, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)30, (short)0, (short)32, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)34,
(short)35, (short)0, (short)29, (short)162, (short)163, (short)164, (short)165,
(short)0, (short)31, (short)0, (short)0, (short)0, (short)301, (short)467,
(short)0, (short)166, (short)0, (short)0, (short)0, (short)167, (short)0,
(short)0, (short)0, (short)436, (short)437, (short)0, (short)168, (short)0,
(short)0, (short)169, (short)170, (short)171, (short)0, (short)0, (short)0,
(short)0, (short)172, (short)173, (short)145, (short)0, (short)146, (short)0,
(short)147, (short)0, (short)0, (short)148, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)149, (short)150, (short)0, (short)0,
(short)151, (short)152, (short)153, (short)154, (short)155, (short)156, (short)157,
(short)0, (short)0, (short)158, (short)159, (short)0, (short)160, (short)161,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162, (short)163,
(short)164, (short)165, (short)0, (short)31, (short)0, (short)0, (short)0,
(short)301, (short)645, (short)0, (short)166, (short)0, (short)0, (short)0,
(short)167, (short)0, (short)0, (short)0, (short)436, (short)437, (short)0,
(short)168, (short)0, (short)0, (short)169, (short)170, (short)171, (short)0,
(short)0, (short)0, (short)0, (short)172, (short)173, (short)145, (short)0,
(short)146, (short)0, (short)147, (short)0, (short)0, (short)148, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)149, (short)150,
(short)0, (short)0, (short)151, (short)152, (short)153, (short)154, (short)155,
(short)156, (short)157, (short)0, (short)0, (short)158, (short)159, (short)0,
(short)160, (short)161, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)29, (short)162, (short)163, (short)164, (short)165, (short)0, (short)31,
(short)0, (short)0, (short)0, (short)301, (short)709, (short)0, (short)166,
(short)0, (short)0, (short)0, (short)167, (short)0, (short)0, (short)0, (short)436,
(short)437, (short)0, (short)168, (short)0, (short)0, (short)169, (short)170,
(short)171, (short)0, (short)0, (short)0, (short)0, (short)172, (short)173,
(short)145, (short)0, (short)146, (short)0, (short)147, (short)0, (short)0,
(short)148, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)149,
(short)150, (short)0, (short)0, (short)151, (short)152, (short)153, (short)154,
(short)155, (short)156, (short)157, (short)0, (short)0, (short)158, (short)159,
(short)0, (short)160, (short)161, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)29, (short)162, (short)163, (short)164, (short)165, (short)0,
(short)31, (short)0, (short)0, (short)0, (short)301, (short)0, (short)0, (short)166,
(short)0, (short)0, (short)0, (short)167, (short)0, (short)0, (short)0, (short)436,
(short)437, (short)0, (short)168, (short)0, (short)0, (short)169, (short)170,
(short)171, (short)0, (short)0, (short)0, (short)0, (short)172, (short)173,
(short)145, (short)0, (short)146, (short)0, (short)147, (short)0, (short)0,
(short)148, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)149,
(short)150, (short)0, (short)0, (short)151, (short)152, (short)153, (short)154,
(short)155, (short)156, (short)157, (short)0, (short)0, (short)158, (short)159,
(short)0, (short)160, (short)161, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)29, (short)162, (short)163, (short)164, (short)165, (short)0,
(short)31, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)166,
(short)0, (short)0, (short)0, (short)167, (short)145, (short)0, (short)146,
(short)0, (short)147, (short)261, (short)168, (short)148, (short)0, (short)169,
(short)170, (short)171, (short)0, (short)0, (short)149, (short)150, (short)172,
(short)173, (short)151, (short)152, (short)153, (short)154, (short)155, (short)156,
(short)157, (short)0, (short)0, (short)158, (short)159, (short)0, (short)160,
(short)161, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162,
(short)163, (short)164, (short)165, (short)0, (short)31, (short)0, (short)0,
(short)0, (short)301, (short)0, (short)0, (short)166, (short)0, (short)0,
(short)0, (short)167, (short)145, (short)0, (short)146, (short)0, (short)147,
(short)0, (short)168, (short)148, (short)0, (short)169, (short)170, (short)171,
(short)0, (short)0, (short)149, (short)150, (short)172, (short)173, (short)151,
(short)152, (short)153, (short)154, (short)155, (short)156, (short)157, (short)0,
(short)0, (short)158, (short)159, (short)0, (short)160, (short)161, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)29, (short)162, (short)163,
(short)164, (short)165, (short)0, (short)31, (short)0, (short)0, (short)393,
(short)0, (short)0, (short)0, (short)166, (short)0, (short)0, (short)0, (short)167,
(short)145, (short)0, (short)146, (short)0, (short)147, (short)0, (short)168,
(short)148, (short)0, (short)169, (short)170, (short)171, (short)0, (short)0,
(short)149, (short)150, (short)172, (short)173, (short)151, (short)152, (short)153,
(short)154, (short)155, (short)156, (short)157, (short)0, (short)0, (short)158,
(short)159, (short)0, (short)160, (short)161, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)29, (short)162, (short)163, (short)164, (short)165,
(short)0, (short)31, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)166, (short)0, (short)0, (short)0, (short)167, (short)145, (short)0,
(short)146, (short)0, (short)147, (short)455, (short)168, (short)148, (short)0,
(short)169, (short)170, (short)171, (short)0, (short)0, (short)149, (short)150,
(short)172, (short)173, (short)151, (short)152, (short)153, (short)154, (short)155,
(short)156, (short)157, (short)0, (short)0, (short)158, (short)159, (short)0,
(short)160, (short)161, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)29, (short)162, (short)163, (short)164, (short)165, (short)0, (short)31,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)166, (short)507,
(short)0, (short)0, (short)167, (short)145, (short)0, (short)146, (short)0,
(short)147, (short)0, (short)168, (short)148, (short)0, (short)169, (short)170,
(short)171, (short)0, (short)0, (short)149, (short)150, (short)172, (short)173,
(short)151, (short)152, (short)153, (short)154, (short)155, (short)156, (short)157,
(short)0, (short)0, (short)158, (short)159, (short)0, (short)160, (short)161,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162, (short)163,
(short)164, (short)165, (short)0, (short)31, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)166, (short)537, (short)0, (short)0,
(short)167, (short)145, (short)0, (short)146, (short)0, (short)147, (short)0,
(short)168, (short)148, (short)0, (short)169, (short)170, (short)171, (short)0,
(short)0, (short)149, (short)150, (short)172, (short)173, (short)151, (short)152,
(short)153, (short)154, (short)155, (short)156, (short)157, (short)0, (short)0,
(short)158, (short)159, (short)0, (short)160, (short)161, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)29, (short)162, (short)163, (short)164,
(short)165, (short)0, (short)31, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)166, (short)0, (short)0, (short)0, (short)167, (short)145,
(short)0, (short)146, (short)0, (short)147, (short)580, (short)168, (short)148,
(short)0, (short)169, (short)170, (short)171, (short)0, (short)0, (short)149,
(short)150, (short)172, (short)173, (short)151, (short)152, (short)153, (short)154,
(short)155, (short)156, (short)157, (short)0, (short)0, (short)158, (short)159,
(short)0, (short)160, (short)161, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)29, (short)162, (short)163, (short)164, (short)165, (short)0,
(short)31, (short)0, (short)0, (short)618, (short)0, (short)0, (short)0, (short)166,
(short)0, (short)0, (short)0, (short)167, (short)145, (short)0, (short)146,
(short)0, (short)147, (short)0, (short)168, (short)148, (short)0, (short)169,
(short)170, (short)171, (short)0, (short)0, (short)149, (short)150, (short)172,
(short)173, (short)151, (short)152, (short)153, (short)154, (short)155, (short)156,
(short)157, (short)0, (short)0, (short)158, (short)159, (short)0, (short)160,
(short)161, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162,
(short)163, (short)164, (short)165, (short)0, (short)31, (short)0, (short)0,
(short)620, (short)0, (short)0, (short)0, (short)166, (short)0, (short)0,
(short)0, (short)167, (short)145, (short)0, (short)146, (short)0, (short)147,
(short)0, (short)168, (short)148, (short)0, (short)169, (short)170, (short)171,
(short)0, (short)0, (short)149, (short)150, (short)172, (short)173, (short)151,
(short)152, (short)153, (short)154, (short)155, (short)156, (short)157, (short)0,
(short)0, (short)158, (short)159, (short)0, (short)160, (short)161, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)29, (short)162, (short)163,
(short)164, (short)165, (short)0, (short)31, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)166, (short)664, (short)0, (short)0,
(short)167, (short)145, (short)0, (short)146, (short)0, (short)147, (short)0,
(short)168, (short)148, (short)0, (short)169, (short)170, (short)171, (short)0,
(short)0, (short)149, (short)150, (short)172, (short)173, (short)151, (short)152,
(short)153, (short)154, (short)155, (short)156, (short)157, (short)0, (short)0,
(short)158, (short)159, (short)0, (short)160, (short)161, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)29, (short)162, (short)163, (short)164,
(short)165, (short)0, (short)31, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)166, (short)667, (short)0, (short)0, (short)167, (short)145,
(short)0, (short)146, (short)0, (short)147, (short)0, (short)168, (short)148,
(short)0, (short)169, (short)170, (short)171, (short)0, (short)0, (short)149,
(short)150, (short)172, (short)173, (short)151, (short)152, (short)153, (short)154,
(short)155, (short)156, (short)157, (short)0, (short)0, (short)158, (short)159,
(short)0, (short)160, (short)161, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)29, (short)162, (short)163, (short)164, (short)165, (short)0,
(short)31, (short)0, (short)0, (short)670, (short)0, (short)0, (short)0, (short)166,
(short)0, (short)0, (short)0, (short)167, (short)145, (short)0, (short)146,
(short)0, (short)147, (short)0, (short)168, (short)148, (short)0, (short)169,
(short)170, (short)171, (short)0, (short)0, (short)149, (short)150, (short)172,
(short)173, (short)151, (short)152, (short)153, (short)154, (short)155, (short)156,
(short)157, (short)0, (short)0, (short)158, (short)159, (short)0, (short)160,
(short)161, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162,
(short)163, (short)164, (short)165, (short)0, (short)31, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)166, (short)693, (short)0,
(short)0, (short)167, (short)145, (short)0, (short)146, (short)0, (short)147,
(short)0, (short)168, (short)148, (short)0, (short)169, (short)170, (short)171,
(short)0, (short)0, (short)149, (short)150, (short)172, (short)173, (short)151,
(short)152, (short)153, (short)154, (short)155, (short)156, (short)157, (short)0,
(short)0, (short)158, (short)159, (short)0, (short)160, (short)161, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)29, (short)162, (short)163,
(short)164, (short)165, (short)0, (short)31, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)166, (short)697, (short)0, (short)0,
(short)167, (short)145, (short)0, (short)146, (short)0, (short)147, (short)0,
(short)168, (short)148, (short)0, (short)169, (short)170, (short)171, (short)0,
(short)0, (short)149, (short)150, (short)172, (short)173, (short)151, (short)152,
(short)153, (short)154, (short)155, (short)156, (short)157, (short)0, (short)0,
(short)158, (short)159, (short)0, (short)160, (short)161, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)29, (short)162, (short)163, (short)164,
(short)165, (short)0, (short)31, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)166, (short)699, (short)0, (short)0, (short)167, (short)145,
(short)0, (short)146, (short)0, (short)147, (short)0, (short)168, (short)148,
(short)0, (short)169, (short)170, (short)171, (short)0, (short)0, (short)149,
(short)150, (short)172, (short)173, (short)151, (short)152, (short)153, (short)154,
(short)155, (short)156, (short)157, (short)0, (short)0, (short)158, (short)159,
(short)0, (short)160, (short)161, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)29, (short)162, (short)163, (short)164, (short)165, (short)0,
(short)31, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)166,
(short)722, (short)0, (short)0, (short)167, (short)145, (short)0, (short)146,
(short)0, (short)147, (short)0, (short)168, (short)148, (short)0, (short)169,
(short)170, (short)171, (short)0, (short)0, (short)149, (short)150, (short)172,
(short)173, (short)151, (short)152, (short)153, (short)154, (short)155, (short)156,
(short)157, (short)0, (short)0, (short)158, (short)159, (short)0, (short)160,
(short)161, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162,
(short)163, (short)164, (short)165, (short)0, (short)31, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)166, (short)0, (short)0, (short)0,
(short)167, (short)145, (short)0, (short)146, (short)0, (short)0, (short)0,
(short)168, (short)0, (short)0, (short)169, (short)170, (short)171, (short)0,
(short)0, (short)149, (short)150, (short)172, (short)173, (short)151, (short)152,
(short)153, (short)154, (short)155, (short)156, (short)157, (short)0, (short)0,
(short)0, (short)159, (short)0, (short)160, (short)161, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)29, (short)162, (short)163, (short)164,
(short)165, (short)0, (short)31, (short)0, (short)0, (short)0, (short)301,
(short)0, (short)0, (short)166, (short)0, (short)0, (short)0, (short)167,
(short)145, (short)0, (short)146, (short)0, (short)0, (short)0, (short)168,
(short)0, (short)0, (short)169, (short)170, (short)171, (short)0, (short)0,
(short)149, (short)150, (short)172, (short)173, (short)151, (short)152, (short)153,
(short)154, (short)155, (short)156, (short)157, (short)0, (short)0, (short)0,
(short)159, (short)0, (short)160, (short)161, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)29, (short)162, (short)163, (short)164, (short)165,
(short)0, (short)31, (short)0, (short)0, (short)0, (short)595, (short)0, (short)0,
(short)166, (short)0, (short)0, (short)0, (short)167, (short)145, (short)0,
(short)146, (short)0, (short)0, (short)0, (short)168, (short)0, (short)0,
(short)169, (short)170, (short)171, (short)0, (short)0, (short)149, (short)150,
(short)172, (short)173, (short)151, (short)152, (short)153, (short)154, (short)155,
(short)156, (short)157, (short)0, (short)0, (short)0, (short)159, (short)0,
(short)160, (short)161, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)29, (short)162, (short)163, (short)164, (short)165, (short)0, (short)31,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)297, (short)0,
(short)0, (short)0, (short)167, (short)145, (short)0, (short)146, (short)0,
(short)0, (short)0, (short)168, (short)0, (short)0, (short)169, (short)170,
(short)171, (short)0, (short)0, (short)149, (short)150, (short)172, (short)173,
(short)151, (short)152, (short)153, (short)154, (short)155, (short)156, (short)157,
(short)0, (short)0, (short)0, (short)159, (short)0, (short)160, (short)161,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)29, (short)162, (short)163,
(short)164, (short)165, (short)0, (short)31, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)309, (short)0, (short)0, (short)0, (short)167,
(short)145, (short)0, (short)146, (short)0, (short)0, (short)0, (short)168,
(short)0, (short)0, (short)169, (short)170, (short)171, (short)0, (short)0,
(short)149, (short)150, (short)172, (short)173, (short)151, (short)152, (short)153,
(short)154, (short)155, (short)156, (short)157, (short)0, (short)0, (short)0,
(short)159, (short)0, (short)160, (short)161, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)0, (short)0, (short)29, (short)162, (short)163, (short)164, (short)165,
(short)0, (short)31, (short)0, (short)0, (short)0, (short)0, (short)0, (short)0,
(short)166, (short)0, (short)0, (short)0, (short)167, (short)0, (short)0,
(short)0, (short)0, (short)0, (short)0, (short)168, (short)0, (short)0, (short)169,
(short)170, (short)171, (short)0, (short)0, (short)0, (short)0, (short)172,
(short)173}; static short Cyc_yycheck[ 4319u]={ (short)54, (short)22, (short)83,
(short)148, (short)54, (short)113, (short)360, (short)61, (short)148, (short)54,
(short)56, (short)147, (short)55, (short)54, (short)244, (short)201, (short)0,
(short)274, (short)112, (short)78, (short)166, (short)90, (short)296, (short)17,
(short)33, (short)410, (short)133, (short)17, (short)18, (short)19, (short)213,
(short)73, (short)87, (short)414, (short)661, (short)142, (short)45, (short)21,
(short)22, (short)74, (short)24, (short)95, (short)96, (short)97, (short)98,
(short)95, (short)68, (short)68, (short)103, (short)33, (short)95, (short)98,
(short)73, (short)107, (short)101, (short)109, (short)40, (short)107, (short)78,
(short)109, (short)80, (short)45, (short)447, (short)83, (short)109, (short)431,
(short)108, (short)51, (short)96, (short)53, (short)451, (short)437, (short)56,
(short)116, (short)101, (short)86, (short)46, (short)47, (short)48, (short)114,
(short)100, (short)103, (short)312, (short)110, (short)68, (short)107, (short)75,
(short)98, (short)93, (short)73, (short)88, (short)351, (short)112, (short)113,
(short)88, (short)78, (short)356, (short)80, (short)725, (short)104, (short)83,
(short)110, (short)113, (short)87, (short)88, (short)89, (short)90, (short)99,
(short)735, (short)100, (short)99, (short)103, (short)101, (short)740, (short)68,
(short)742, (short)105, (short)100, (short)109, (short)110, (short)104, (short)88,
(short)112, (short)113, (short)114, (short)68, (short)110, (short)94, (short)106,
(short)112, (short)113, (short)40, (short)88, (short)142, (short)101, (short)119,
(short)133, (short)397, (short)122, (short)87, (short)124, (short)415, (short)106,
(short)110, (short)283, (short)142, (short)166, (short)117, (short)202, (short)103,
(short)106, (short)297, (short)202, (short)107, (short)293, (short)521, (short)263,
(short)202, (short)142, (short)83, (short)103, (short)131, (short)132, (short)309,
(short)107, (short)101, (short)69, (short)70, (short)549, (short)64, (short)65,
(short)66, (short)168, (short)169, (short)281, (short)171, (short)100, (short)112,
(short)87, (short)88, (short)89, (short)90, (short)93, (short)166, (short)291,
(short)120, (short)121, (short)98, (short)112, (short)209, (short)244, (short)200,
(short)88, (short)189, (short)244, (short)576, (short)97, (short)93, (short)94,
(short)98, (short)101, (short)107, (short)211, (short)106, (short)107, (short)103,
(short)101, (short)96, (short)104, (short)115, (short)119, (short)372, (short)101,
(short)111, (short)109, (short)110, (short)200, (short)106, (short)96, (short)380,
(short)99, (short)110, (short)98, (short)101, (short)103, (short)214, (short)209,
(short)211, (short)106, (short)238, (short)289, (short)215, (short)110, (short)88,
(short)97, (short)98, (short)84, (short)85, (short)88, (short)375, (short)95,
(short)595, (short)285, (short)263, (short)88, (short)95, (short)106, (short)293,
(short)88, (short)109, (short)94, (short)305, (short)637, (short)274, (short)238,
(short)95, (short)98, (short)101, (short)312, (short)279, (short)280, (short)281,
(short)312, (short)446, (short)98, (short)103, (short)114, (short)101, (short)88,
(short)289, (short)108, (short)291, (short)106, (short)88, (short)94, (short)95,
(short)296, (short)297, (short)98, (short)94, (short)93, (short)97, (short)291,
(short)101, (short)470, (short)209, (short)99, (short)103, (short)97, (short)309,
(short)274, (short)275, (short)98, (short)128, (short)103, (short)431, (short)279,
(short)280, (short)281, (short)97, (short)101, (short)437, (short)97, (short)98,
(short)97, (short)103, (short)289, (short)291, (short)291, (short)293, (short)103,
(short)568, (short)88, (short)296, (short)297, (short)101, (short)423, (short)88,
(short)94, (short)100, (short)106, (short)305, (short)403, (short)93, (short)97,
(short)101, (short)309, (short)102, (short)585, (short)99, (short)103, (short)166,
(short)71, (short)72, (short)110, (short)389, (short)112, (short)113, (short)114,
(short)389, (short)336, (short)337, (short)338, (short)97, (short)103, (short)102,
(short)103, (short)604, (short)107, (short)103, (short)404, (short)459, (short)372,
(short)201, (short)404, (short)279, (short)280, (short)281, (short)89, (short)404,
(short)380, (short)103, (short)545, (short)404, (short)458, (short)97, (short)108,
(short)291, (short)97, (short)97, (short)103, (short)103, (short)296, (short)99,
(short)103, (short)103, (short)103, (short)103, (short)221, (short)97, (short)364,
(short)108, (short)366, (short)403, (short)227, (short)521, (short)229, (short)230,
(short)99, (short)372, (short)87, (short)226, (short)103, (short)101, (short)383,
(short)415, (short)90, (short)380, (short)88, (short)585, (short)384, (short)102,
(short)88, (short)423, (short)94, (short)513, (short)115, (short)97, (short)94,
(short)67, (short)68, (short)101, (short)433, (short)101, (short)457, (short)101,
(short)99, (short)438, (short)604, (short)101, (short)403, (short)101, (short)112,
(short)113, (short)114, (short)101, (short)112, (short)113, (short)114, (short)686,
(short)115, (short)116, (short)415, (short)101, (short)282, (short)102, (short)103,
(short)101, (short)458, (short)459, (short)424, (short)328, (short)329, (short)330,
(short)331, (short)429, (short)591, (short)73, (short)372, (short)433, (short)119,
(short)591, (short)118, (short)301, (short)438, (short)364, (short)380, (short)366,
(short)102, (short)103, (short)308, (short)647, (short)297, (short)599, (short)473,
(short)102, (short)103, (short)315, (short)117, (short)304, (short)102, (short)103,
(short)307, (short)703, (short)309, (short)458, (short)459, (short)102, (short)103,
(short)403, (short)101, (short)88, (short)99, (short)479, (short)102, (short)103,
(short)321, (short)94, (short)542, (short)473, (short)99, (short)415, (short)542,
(short)513, (short)101, (short)725, (short)99, (short)542, (short)89, (short)90,
(short)686, (short)108, (short)350, (short)351, (short)98, (short)112, (short)113,
(short)114, (short)356, (short)101, (short)740, (short)520, (short)360, (short)22,
(short)23, (short)424, (short)102, (short)103, (short)110, (short)99, (short)112,
(short)113, (short)114, (short)358, (short)102, (short)103, (short)102, (short)103,
(short)102, (short)103, (short)513, (short)102, (short)103, (short)98, (short)458,
(short)589, (short)520, (short)526, (short)101, (short)589, (short)102, (short)103,
(short)102, (short)103, (short)589, (short)102, (short)103, (short)568, (short)98,
(short)397, (short)385, (short)386, (short)387, (short)101, (short)389, (short)403,
(short)101, (short)400, (short)101, (short)402, (short)408, (short)88, (short)611,
(short)612, (short)326, (short)327, (short)37, (short)332, (short)333, (short)97,
(short)590, (short)334, (short)335, (short)97, (short)108, (short)101, (short)99,
(short)102, (short)659, (short)100, (short)102, (short)111, (short)99, (short)103,
(short)568, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)20,
(short)21, (short)103, (short)99, (short)102, (short)100, (short)103, (short)99,
(short)74, (short)35, (short)590, (short)102, (short)106, (short)97, (short)103,
(short)460, (short)36, (short)28, (short)108, (short)97, (short)88, (short)89,
(short)41, (short)91, (short)92, (short)470, (short)94, (short)47, (short)48,
(short)93, (short)611, (short)612, (short)87, (short)101, (short)115, (short)102,
(short)104, (short)105, (short)88, (short)101, (short)60, (short)102, (short)659,
(short)103, (short)112, (short)88, (short)99, (short)103, (short)116, (short)117,
(short)102, (short)93, (short)703, (short)102, (short)672, (short)102, (short)703,
(short)111, (short)102, (short)88, (short)97, (short)102, (short)101, (short)103,
(short)102, (short)99, (short)102, (short)684, (short)88, (short)590, (short)103,
(short)102, (short)102, (short)93, (short)725, (short)95, (short)99, (short)97,
(short)725, (short)659, (short)101, (short)99, (short)102, (short)99, (short)104,
(short)105, (short)98, (short)102, (short)102, (short)740, (short)107, (short)672,
(short)99, (short)740, (short)103, (short)98, (short)102, (short)102, (short)111,
(short)531, (short)532, (short)111, (short)106, (short)35, (short)684, (short)75,
(short)76, (short)77, (short)78, (short)79, (short)80, (short)81, (short)82,
(short)83, (short)84, (short)102, (short)101, (short)98, (short)97, (short)88,
(short)145, (short)101, (short)147, (short)148, (short)102, (short)102, (short)102,
(short)102, (short)26, (short)102, (short)100, (short)99, (short)99, (short)97,
(short)108, (short)160, (short)161, (short)102, (short)659, (short)102, (short)585,
(short)37, (short)0, (short)168, (short)169, (short)0, (short)171, (short)305,
(short)429, (short)558, (short)595, (short)209, (short)200, (short)598, (short)520,
(short)57, (short)320, (short)287, (short)323, (short)604, (short)275, (short)439,
(short)325, (short)684, (short)189, - (short)1, (short)568, (short)322, (short)324,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)614, -
(short)1, (short)616, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)617, (short)618, - (short)1, (short)620,
- (short)1, (short)622, - (short)1, (short)88, (short)89, - (short)1, (short)91,
(short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1, (short)647,
(short)99, - (short)1, (short)101, - (short)1, - (short)1, (short)104, (short)105,
- (short)1, - (short)1, (short)644, (short)109, (short)110, - (short)1, (short)112,
- (short)1, - (short)1, - (short)1, (short)116, (short)117, - (short)1, -
(short)1, (short)664, - (short)1, - (short)1, (short)667, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)666, - (short)1, (short)676,
(short)669, (short)670, - (short)1, - (short)1, (short)686, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)688, - (short)1,
- (short)1, - (short)1, (short)692, (short)693, - (short)1, - (short)1, (short)696,
(short)697, - (short)1, (short)699, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)701,
- (short)1, - (short)1, - (short)1, - (short)1, (short)706, - (short)1, (short)716,
- (short)1, - (short)1, (short)719, - (short)1, (short)721, (short)722, -
(short)1, (short)37, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)724, (short)733, - (short)1, (short)320, -
(short)1, (short)322, (short)323, (short)324, (short)325, (short)326, (short)327,
(short)328, (short)329, (short)330, (short)331, (short)332, (short)333, (short)334,
(short)335, (short)336, (short)337, (short)338, (short)8, (short)9, (short)10,
(short)11, (short)12, (short)13, (short)14, (short)15, (short)16, (short)17,
(short)18, (short)19, (short)20, (short)21, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, - (short)1,
(short)91, (short)92, - (short)1, (short)94, (short)36, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, - (short)1, (short)375, (short)104,
(short)105, (short)47, (short)48, - (short)1, (short)109, (short)110, - (short)1,
(short)112, - (short)1, - (short)1, - (short)1, (short)116, (short)117, -
(short)1, (short)60, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, (short)93, - (short)1, (short)95, - (short)1, (short)97, - (short)1,
- (short)1, (short)431, - (short)1, (short)102, - (short)1, (short)104, (short)105,
(short)437, - (short)1, - (short)1, - (short)1, (short)3, (short)4, (short)5,
(short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)20,
(short)21, (short)22, (short)23, (short)24, (short)25, - (short)1, (short)27,
(short)28, (short)29, (short)30, (short)31, (short)32, (short)33, (short)34,
(short)35, (short)36, (short)37, (short)38, (short)39, (short)40, (short)479,
(short)42, (short)43, (short)44, - (short)1, - (short)1, (short)47, (short)48,
(short)49, (short)50, (short)51, (short)52, (short)53, (short)54, (short)55,
(short)56, (short)57, (short)58, (short)59, (short)60, (short)61, (short)62,
(short)63, - (short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)521, - (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89,
(short)90, (short)91, (short)92, (short)93, (short)94, (short)95, - (short)1,
(short)97, (short)98, - (short)1, - (short)1, (short)101, - (short)1, - (short)1,
(short)104, (short)105, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116,
(short)117, - (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)591, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)599, (short)3,
(short)4, (short)5, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11,
(short)12, (short)13, (short)14, (short)15, (short)16, (short)17, (short)18,
(short)19, (short)20, (short)21, - (short)1, - (short)1, (short)24, (short)25, -
(short)1, (short)27, (short)28, (short)29, (short)30, (short)31, (short)32,
(short)33, (short)34, (short)35, (short)36, (short)37, (short)38, (short)39,
(short)40, - (short)1, (short)42, (short)43, (short)44, - (short)1, - (short)1,
(short)47, (short)48, (short)49, (short)50, (short)51, (short)52, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, (short)60,
(short)61, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, (short)93, (short)94,
(short)95, - (short)1, (short)97, (short)98, (short)99, - (short)1, (short)101,
- (short)1, - (short)1, (short)104, (short)105, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, (short)112, - (short)1, - (short)1,
(short)115, (short)116, (short)117, - (short)1, - (short)1, - (short)1, -
(short)1, (short)122, (short)123, (short)3, (short)4, (short)5, (short)6,
(short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)20,
(short)21, - (short)1, - (short)1, (short)24, (short)25, - (short)1, (short)27,
(short)28, (short)29, (short)30, (short)31, (short)32, (short)33, (short)34,
(short)35, (short)36, (short)37, (short)38, (short)39, (short)40, - (short)1,
(short)42, (short)43, (short)44, - (short)1, - (short)1, (short)47, (short)48,
(short)49, (short)50, (short)51, (short)52, (short)53, (short)54, (short)55,
(short)56, (short)57, (short)58, (short)59, (short)60, (short)61, (short)62,
(short)63, - (short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89,
(short)90, (short)91, (short)92, (short)93, (short)94, (short)95, - (short)1,
(short)97, (short)98, - (short)1, - (short)1, (short)101, - (short)1, - (short)1,
(short)104, (short)105, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116,
(short)117, - (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123,
(short)3, (short)4, (short)5, (short)6, (short)7, (short)8, (short)9, (short)10,
(short)11, (short)12, (short)13, (short)14, (short)15, (short)16, (short)17,
(short)18, (short)19, (short)20, (short)21, - (short)1, - (short)1, (short)24, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)35, (short)36, (short)37, (short)38,
(short)39, - (short)1, - (short)1, (short)42, (short)43, - (short)1, - (short)1,
- (short)1, (short)47, (short)48, (short)49, (short)50, - (short)1, - (short)1,
(short)53, (short)54, (short)55, (short)56, (short)57, (short)58, (short)59,
(short)60, - (short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, (short)93,
(short)94, (short)95, - (short)1, (short)97, - (short)1, - (short)1, - (short)1,
(short)101, - (short)1, - (short)1, (short)104, (short)105, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)112, - (short)1,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, -
(short)1, - (short)1, (short)122, (short)123, (short)8, (short)9, (short)10,
(short)11, (short)12, (short)13, (short)14, (short)15, (short)16, (short)17,
(short)18, (short)19, (short)20, (short)21, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, (short)35, (short)36, (short)37, -
(short)1, (short)39, - (short)1, - (short)1, (short)42, - (short)1, - (short)1,
- (short)1, - (short)1, (short)47, (short)48, (short)49, (short)50, - (short)1,
- (short)1, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, (short)60, - (short)1, (short)62, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92,
(short)93, (short)94, (short)95, - (short)1, - (short)1, (short)98, - (short)1,
- (short)1, (short)101, - (short)1, - (short)1, (short)104, (short)105, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)112,
- (short)1, - (short)1, (short)115, (short)116, (short)117, - (short)1, -
(short)1, - (short)1, - (short)1, (short)122, (short)123, (short)8, (short)9,
(short)10, (short)11, (short)12, (short)13, (short)14, (short)15, (short)16,
(short)17, (short)18, (short)19, (short)20, (short)21, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)35, (short)36, (short)37,
- (short)1, (short)39, - (short)1, - (short)1, (short)42, - (short)1, - (short)1,
- (short)1, - (short)1, (short)47, (short)48, (short)49, (short)50, - (short)1,
- (short)1, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, (short)60, - (short)1, (short)62, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92,
(short)93, (short)94, (short)95, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, (short)101, - (short)1, - (short)1, (short)104, (short)105, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)112,
- (short)1, - (short)1, (short)115, (short)116, (short)117, - (short)1, -
(short)1, - (short)1, - (short)1, (short)122, (short)123, (short)3, (short)4,
(short)5, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12,
(short)13, (short)14, (short)15, (short)16, (short)17, (short)18, (short)19,
(short)20, (short)21, - (short)1, - (short)1, (short)24, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, (short)36, - (short)1, (short)38, - (short)1,
- (short)1, - (short)1, - (short)1, (short)43, - (short)1, (short)45, (short)46,
(short)47, (short)48, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)60,
- (short)1, - (short)1, (short)3, (short)4, (short)5, (short)6, (short)7,
(short)8, (short)9, (short)10, (short)11, (short)12, (short)13, (short)14,
(short)15, (short)16, (short)17, (short)18, (short)19, (short)20, (short)21, -
(short)1, - (short)1, (short)24, - (short)1, - (short)1, - (short)1, (short)88,
- (short)1, - (short)1, - (short)1, - (short)1, (short)93, (short)94, (short)95,
(short)36, - (short)1, - (short)1, - (short)1, - (short)1, (short)101, - (short)1,
(short)43, (short)104, (short)105, - (short)1, (short)47, (short)48, - (short)1,
- (short)1, - (short)1, (short)112, (short)113, (short)114, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, (short)60, - (short)1, - (short)1,
(short)8, (short)9, (short)10, (short)11, (short)12, (short)13, (short)14,
(short)15, (short)16, (short)17, (short)18, (short)19, (short)20, (short)21, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, - (short)1, - (short)1,
(short)36, - (short)1, (short)93, (short)94, (short)95, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, (short)47, (short)48, (short)104,
(short)105, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, (short)112, (short)113, (short)114, (short)60, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)8, (short)9,
(short)10, (short)11, (short)12, (short)13, (short)14, (short)15, (short)16,
(short)17, (short)18, (short)19, (short)20, (short)21, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, (short)88, - (short)1, - (short)1,
- (short)1, - (short)1, (short)93, (short)94, (short)95, (short)36, (short)97, -
(short)1, - (short)1, - (short)1, (short)101, (short)102, - (short)1, (short)104,
(short)105, - (short)1, (short)47, (short)48, - (short)1, (short)110, - (short)1,
(short)112, (short)113, (short)114, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, (short)60, - (short)1, - (short)1, (short)3, (short)4,
(short)5, (short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12,
(short)13, (short)14, (short)15, (short)16, (short)17, (short)18, (short)19,
(short)20, (short)21, - (short)1, - (short)1, (short)24, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)93,
- (short)1, (short)95, (short)36, (short)97, (short)38, - (short)1, - (short)1,
(short)101, (short)102, (short)43, (short)104, (short)105, - (short)1, (short)47,
(short)48, - (short)1, (short)110, - (short)1, (short)112, (short)113, (short)114,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)60, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)3, (short)4, (short)5,
(short)6, (short)7, (short)8, (short)9, (short)10, (short)11, (short)12, (short)13,
(short)14, (short)15, (short)16, (short)17, (short)18, (short)19, (short)20,
(short)21, - (short)1, - (short)1, (short)24, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)93, - (short)1, (short)95, - (short)1, - (short)1,
(short)98, (short)36, (short)100, (short)38, - (short)1, - (short)1, (short)104,
(short)105, (short)43, - (short)1, - (short)1, - (short)1, (short)47, (short)48,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)60, - (short)1,
- (short)1, (short)3, (short)4, (short)5, (short)6, (short)7, (short)8, (short)9,
(short)10, (short)11, (short)12, (short)13, (short)14, (short)15, (short)16,
(short)17, (short)18, (short)19, (short)20, (short)21, - (short)1, - (short)1,
(short)24, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)93, - (short)1, (short)95, (short)36, - (short)1,
(short)98, - (short)1, - (short)1, - (short)1, - (short)1, (short)43, (short)104,
(short)105, - (short)1, (short)47, (short)48, (short)25, - (short)1, (short)27,
(short)28, (short)29, (short)30, (short)31, (short)32, (short)33, (short)34,
(short)35, (short)60, (short)37, - (short)1, (short)39, (short)40, - (short)1,
(short)42, - (short)1, (short)44, - (short)1, - (short)1, - (short)1, - (short)1,
(short)49, (short)50, (short)51, (short)52, (short)53, (short)54, (short)55,
(short)56, (short)57, (short)58, (short)59, - (short)1, (short)61, (short)62,
(short)63, - (short)1, (short)65, (short)66, - (short)1, - (short)1, (short)93,
- (short)1, (short)95, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)104, (short)105, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89,
(short)90, (short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1,
(short)97, (short)98, - (short)1, - (short)1, (short)101, - (short)1, - (short)1,
- (short)1, (short)105, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116,
(short)117, - (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123,
(short)8, (short)9, (short)10, (short)11, (short)12, (short)13, (short)14,
(short)15, (short)16, (short)17, (short)18, (short)19, (short)20, (short)21,
(short)8, (short)9, (short)10, (short)11, (short)12, (short)13, (short)14,
(short)15, (short)16, (short)17, (short)18, (short)19, (short)20, (short)21,
(short)36, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)47, (short)48, - (short)1,
(short)36, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)60, (short)47, (short)48, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, (short)60, (short)8, (short)9,
(short)10, (short)11, (short)12, (short)13, (short)14, (short)15, (short)16,
(short)17, (short)18, (short)19, (short)20, (short)21, - (short)1, - (short)1, -
(short)1, - (short)1, (short)93, - (short)1, (short)95, - (short)1, - (short)1,
(short)98, (short)85, - (short)1, - (short)1, - (short)1, (short)36, (short)104,
(short)105, - (short)1, (short)93, - (short)1, (short)95, - (short)1, - (short)1,
- (short)1, - (short)1, (short)47, (short)48, (short)30, - (short)1, (short)104,
(short)105, - (short)1, (short)35, - (short)1, (short)37, - (short)1, (short)39,
- (short)1, (short)60, (short)42, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)49, (short)50, - (short)1, - (short)1, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)93,
- (short)1, (short)95, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)104, (short)105, - (short)1, (short)88,
(short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, - (short)1, -
(short)1, - (short)1, (short)98, (short)99, - (short)1, (short)101, - (short)1,
- (short)1, - (short)1, (short)105, - (short)1, - (short)1, - (short)1, (short)109,
(short)110, - (short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116,
(short)117, - (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123,
(short)35, - (short)1, (short)37, - (short)1, (short)39, - (short)1, - (short)1,
(short)42, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)49, (short)50, - (short)1, - (short)1, (short)53, (short)54, (short)55,
(short)56, (short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62,
(short)63, - (short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89,
(short)90, (short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1,
- (short)1, (short)98, (short)99, - (short)1, (short)101, - (short)1, - (short)1,
- (short)1, (short)105, - (short)1, - (short)1, - (short)1, (short)109, (short)110,
- (short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, - (short)1, (short)42,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)49,
(short)50, - (short)1, - (short)1, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
(short)98, (short)99, - (short)1, (short)101, - (short)1, - (short)1, - (short)1,
(short)105, - (short)1, - (short)1, - (short)1, (short)109, (short)110, -
(short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, - (short)1, (short)42,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)49,
(short)50, - (short)1, - (short)1, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
(short)98, - (short)1, - (short)1, (short)101, - (short)1, - (short)1, - (short)1,
(short)105, - (short)1, - (short)1, - (short)1, (short)109, (short)110, -
(short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, - (short)1, (short)42,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)49,
(short)50, - (short)1, - (short)1, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, - (short)1, - (short)1, -
(short)1, (short)105, (short)35, - (short)1, (short)37, - (short)1, (short)39,
(short)111, (short)112, (short)42, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, (short)49, (short)50, (short)122, (short)123, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, -
(short)1, - (short)1, - (short)1, (short)98, - (short)1, - (short)1, (short)101,
- (short)1, - (short)1, - (short)1, (short)105, (short)35, - (short)1, (short)37,
- (short)1, (short)39, - (short)1, (short)112, (short)42, - (short)1, (short)115,
(short)116, (short)117, - (short)1, - (short)1, (short)49, (short)50, (short)122,
(short)123, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, - (short)1, - (short)1, (short)62, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, -
(short)1, (short)94, - (short)1, - (short)1, (short)97, - (short)1, - (short)1,
- (short)1, (short)101, - (short)1, - (short)1, - (short)1, (short)105, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, (short)112, (short)42,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, (short)49,
(short)50, (short)122, (short)123, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, - (short)1, - (short)1, -
(short)1, (short)105, (short)35, - (short)1, (short)37, - (short)1, (short)39,
(short)111, (short)112, (short)42, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, (short)49, (short)50, (short)122, (short)123, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)101,
(short)102, - (short)1, - (short)1, (short)105, (short)35, - (short)1, (short)37,
- (short)1, (short)39, - (short)1, (short)112, (short)42, - (short)1, (short)115,
(short)116, (short)117, - (short)1, - (short)1, (short)49, (short)50, (short)122,
(short)123, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, - (short)1, - (short)1, (short)62, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, -
(short)1, (short)94, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, (short)101, (short)102, - (short)1, - (short)1, (short)105, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, (short)112, (short)42,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, (short)49,
(short)50, (short)122, (short)123, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, - (short)1, - (short)1, -
(short)1, (short)105, (short)35, - (short)1, (short)37, - (short)1, (short)39,
(short)111, (short)112, (short)42, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, (short)49, (short)50, (short)122, (short)123, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, -
(short)1, - (short)1, (short)97, - (short)1, - (short)1, - (short)1, (short)101,
- (short)1, - (short)1, - (short)1, (short)105, (short)35, - (short)1, (short)37,
- (short)1, (short)39, - (short)1, (short)112, (short)42, - (short)1, (short)115,
(short)116, (short)117, - (short)1, - (short)1, (short)49, (short)50, (short)122,
(short)123, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, - (short)1, - (short)1, (short)62, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, -
(short)1, (short)94, - (short)1, - (short)1, (short)97, - (short)1, - (short)1,
- (short)1, (short)101, - (short)1, - (short)1, - (short)1, (short)105, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, (short)112, (short)42,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, (short)49,
(short)50, (short)122, (short)123, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, (short)102, - (short)1, -
(short)1, (short)105, (short)35, - (short)1, (short)37, - (short)1, (short)39, -
(short)1, (short)112, (short)42, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, (short)49, (short)50, (short)122, (short)123, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)101,
(short)102, - (short)1, - (short)1, (short)105, (short)35, - (short)1, (short)37,
- (short)1, (short)39, - (short)1, (short)112, (short)42, - (short)1, (short)115,
(short)116, (short)117, - (short)1, - (short)1, (short)49, (short)50, (short)122,
(short)123, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, - (short)1, - (short)1, (short)62, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, -
(short)1, (short)94, - (short)1, - (short)1, (short)97, - (short)1, - (short)1,
- (short)1, (short)101, - (short)1, - (short)1, - (short)1, (short)105, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, (short)112, (short)42,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, (short)49,
(short)50, (short)122, (short)123, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, (short)102, - (short)1, -
(short)1, (short)105, (short)35, - (short)1, (short)37, - (short)1, (short)39, -
(short)1, (short)112, (short)42, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, (short)49, (short)50, (short)122, (short)123, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)101,
(short)102, - (short)1, - (short)1, (short)105, (short)35, - (short)1, (short)37,
- (short)1, (short)39, - (short)1, (short)112, (short)42, - (short)1, (short)115,
(short)116, (short)117, - (short)1, - (short)1, (short)49, (short)50, (short)122,
(short)123, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, - (short)1, - (short)1, (short)62, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, -
(short)1, (short)94, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, (short)101, (short)102, - (short)1, - (short)1, (short)105, (short)35,
- (short)1, (short)37, - (short)1, (short)39, - (short)1, (short)112, (short)42,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, (short)49,
(short)50, (short)122, (short)123, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, (short)62, (short)63, -
(short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, (short)102, - (short)1, -
(short)1, (short)105, (short)35, - (short)1, (short)37, - (short)1, (short)39, -
(short)1, (short)112, (short)42, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, (short)49, (short)50, (short)122, (short)123, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, (short)62, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)101,
- (short)1, - (short)1, - (short)1, (short)105, (short)35, - (short)1, (short)37,
- (short)1, - (short)1, - (short)1, (short)112, - (short)1, - (short)1, (short)115,
(short)116, (short)117, - (short)1, - (short)1, (short)49, (short)50, (short)122,
(short)123, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, - (short)1, - (short)1, - (short)1, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, -
(short)1, (short)94, - (short)1, - (short)1, - (short)1, (short)98, - (short)1,
- (short)1, (short)101, - (short)1, - (short)1, - (short)1, (short)105, (short)35,
- (short)1, (short)37, - (short)1, - (short)1, - (short)1, (short)112, - (short)1,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, (short)49,
(short)50, (short)122, (short)123, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, - (short)1, (short)63,
- (short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
(short)98, - (short)1, - (short)1, (short)101, - (short)1, - (short)1, - (short)1,
(short)105, (short)35, - (short)1, (short)37, - (short)1, - (short)1, - (short)1,
(short)112, - (short)1, - (short)1, (short)115, (short)116, (short)117, -
(short)1, - (short)1, (short)49, (short)50, (short)122, (short)123, (short)53,
(short)54, (short)55, (short)56, (short)57, (short)58, (short)59, - (short)1, -
(short)1, - (short)1, (short)63, - (short)1, (short)65, (short)66, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
(short)88, (short)89, (short)90, (short)91, (short)92, - (short)1, (short)94, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, (short)101,
- (short)1, - (short)1, - (short)1, (short)105, (short)35, - (short)1, (short)37,
- (short)1, - (short)1, - (short)1, (short)112, - (short)1, - (short)1, (short)115,
(short)116, (short)117, - (short)1, - (short)1, (short)49, (short)50, (short)122,
(short)123, (short)53, (short)54, (short)55, (short)56, (short)57, (short)58,
(short)59, - (short)1, - (short)1, - (short)1, (short)63, - (short)1, (short)65,
(short)66, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, (short)88, (short)89, (short)90, (short)91, (short)92, -
(short)1, (short)94, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, (short)101, - (short)1, - (short)1, - (short)1, (short)105, (short)35,
- (short)1, (short)37, - (short)1, - (short)1, - (short)1, (short)112, - (short)1,
- (short)1, (short)115, (short)116, (short)117, - (short)1, - (short)1, (short)49,
(short)50, (short)122, (short)123, (short)53, (short)54, (short)55, (short)56,
(short)57, (short)58, (short)59, - (short)1, - (short)1, - (short)1, (short)63,
- (short)1, (short)65, (short)66, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, -
(short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, - (short)1, (short)88, (short)89, (short)90,
(short)91, (short)92, - (short)1, (short)94, - (short)1, - (short)1, - (short)1,
- (short)1, - (short)1, - (short)1, (short)101, - (short)1, - (short)1, -
(short)1, (short)105, - (short)1, - (short)1, - (short)1, - (short)1, - (short)1,
- (short)1, (short)112, - (short)1, - (short)1, (short)115, (short)116, (short)117,
- (short)1, - (short)1, - (short)1, - (short)1, (short)122, (short)123}; char
Cyc_Yyimpossible[ 17u]="\000\000\000\000Yyimpossible"; char Cyc_Yystack_overflow[
21u]="\000\000\000\000Yystack_overflow"; extern void Cyc_yyerror( struct
_tagged_string); extern int Cyc_yylex(); char Cyc_YYINITIALSVAL[ 18u]="\000\000\000\000YYINITIALSVAL";
static int Cyc_yychar=( int)'\000'; void* Cyc_yylval=( void*) Cyc_YYINITIALSVAL;
static int Cyc_yynerrs= 0; struct _tagged_ptr1{ short* curr; short* base; short*
last_plus_one; } ; struct _tagged_ptr2{ void** curr; void** base; void**
last_plus_one; } ; struct _tagged_ptr3{ struct Cyc_Yyltype* curr; struct Cyc_Yyltype*
base; struct Cyc_Yyltype* last_plus_one; } ; struct _tuple18{ struct Cyc_List_List*
f1; struct Cyc_Absyn_Exp* f2; } ; int Cyc_yyparse(){ int yystate; int yyn= 0;
int yyerrstatus; int yychar1= 0; int yyssp_offset; struct _tagged_ptr1 yyss=(
struct _tagged_ptr1)({ short* _temp7457=( short*)({ unsigned int _temp7453= 200u;
short* _temp7454=( short*) GC_malloc_atomic( sizeof( short) * _temp7453);{
unsigned int _temp7455= _temp7453; unsigned int i; for( i= 0; i < _temp7455; i
++){ _temp7454[ i]= (short)0;}}; _temp7454;}); struct _tagged_ptr1 _temp7458;
_temp7458.curr= _temp7457; _temp7458.base= _temp7457; _temp7458.last_plus_one=
_temp7457 + 200; _temp7458;}); int yyvsp_offset; struct _tagged_ptr2 yyvs=(
struct _tagged_ptr2)({ void** _temp7451=( void**)({ unsigned int _temp7447= 200u;
void** _temp7448=( void**) GC_malloc( sizeof( void*) * _temp7447);{ unsigned int
_temp7449= _temp7447; unsigned int i; for( i= 0; i < _temp7449; i ++){ _temp7448[
i]= Cyc_yylval;}}; _temp7448;}); struct _tagged_ptr2 _temp7452; _temp7452.curr=
_temp7451; _temp7452.base= _temp7451; _temp7452.last_plus_one= _temp7451 + 200;
_temp7452;}); int yylsp_offset; struct _tagged_ptr3 yyls=( struct _tagged_ptr3)({
struct Cyc_Yyltype* _temp7445=( struct Cyc_Yyltype*)({ unsigned int _temp7441=
200u; struct Cyc_Yyltype* _temp7442=( struct Cyc_Yyltype*) GC_malloc( sizeof(
struct Cyc_Yyltype) * _temp7441);{ unsigned int _temp7443= _temp7441;
unsigned int i; for( i= 0; i < _temp7443; i ++){ _temp7442[ i]= Cyc_yynewloc();}};
_temp7442;}); struct _tagged_ptr3 _temp7446; _temp7446.curr= _temp7445;
_temp7446.base= _temp7445; _temp7446.last_plus_one= _temp7445 + 200; _temp7446;});
int yystacksize= 200; void* yyval= Cyc_yylval; int yylen; yystate= 0;
yyerrstatus= 0; Cyc_yynerrs= 0; Cyc_yychar= - 2; yyssp_offset= - 1; yyvsp_offset=
0; yylsp_offset= 0; yynewstate:({ struct _tagged_ptr1 _temp2187= yyss; short*
_temp2189= _temp2187.curr +( ++ yyssp_offset); if( _temp2187.base == 0? 1:(
_temp2189 < _temp2187.base? 1: _temp2189 >= _temp2187.last_plus_one)){ _throw(
Null_Exception);}* _temp2189=( short) yystate;}); if( yyssp_offset >=
yystacksize - 1){ if( yystacksize >= 10000){ Cyc_yyerror(( struct _tagged_string)({
char* _temp2190=( char*)"parser stack overflow"; struct _tagged_string _temp2191;
_temp2191.curr= _temp2190; _temp2191.base= _temp2190; _temp2191.last_plus_one=
_temp2190 + 22; _temp2191;}));( void) _throw(( void*) Cyc_Yystack_overflow);}
yystacksize *= 2; if( yystacksize > 10000){ yystacksize= 10000;}{ struct
_tagged_ptr1 yyss1=({ unsigned int _temp2220=( unsigned int) yystacksize; short*
_temp2221=( short*) GC_malloc_atomic( sizeof( short) * _temp2220); struct
_tagged_ptr1 _temp2224={ _temp2221, _temp2221, _temp2221 + _temp2220};{
unsigned int _temp2222= _temp2220; unsigned int i; for( i= 0; i < _temp2222; i
++){ _temp2221[ i]= (short)0;}}; _temp2224;}); struct _tagged_ptr2 yyvs1=({
unsigned int _temp2215=( unsigned int) yystacksize; void** _temp2216=( void**)
GC_malloc( sizeof( void*) * _temp2215); struct _tagged_ptr2 _temp2219={
_temp2216, _temp2216, _temp2216 + _temp2215};{ unsigned int _temp2217= _temp2215;
unsigned int i; for( i= 0; i < _temp2217; i ++){ _temp2216[ i]= Cyc_yylval;}};
_temp2219;}); struct _tagged_ptr3 yyls1=({ unsigned int _temp2210=( unsigned int)
yystacksize; struct Cyc_Yyltype* _temp2211=( struct Cyc_Yyltype*) GC_malloc(
sizeof( struct Cyc_Yyltype) * _temp2210); struct _tagged_ptr3 _temp2214={
_temp2211, _temp2211, _temp2211 + _temp2210};{ unsigned int _temp2212= _temp2210;
unsigned int i; for( i= 0; i < _temp2212; i ++){ _temp2211[ i]= Cyc_yynewloc();}};
_temp2214;});{ int i= 0; for( 0; i <= yyssp_offset; i ++){({ struct _tagged_ptr1
_temp2192= yyss1; short* _temp2194= _temp2192.curr + i; if( _temp2192.base == 0?
1:( _temp2194 < _temp2192.base? 1: _temp2194 >= _temp2192.last_plus_one)){
_throw( Null_Exception);}* _temp2194=({ struct _tagged_ptr1 _temp2195= yyss;
short* _temp2197= _temp2195.curr + i; if( _temp2195.base == 0? 1:( _temp2197 <
_temp2195.base? 1: _temp2197 >= _temp2195.last_plus_one)){ _throw(
Null_Exception);}* _temp2197;});});({ struct _tagged_ptr2 _temp2198= yyvs1; void**
_temp2200= _temp2198.curr + i; if( _temp2198.base == 0? 1:( _temp2200 <
_temp2198.base? 1: _temp2200 >= _temp2198.last_plus_one)){ _throw(
Null_Exception);}* _temp2200=({ struct _tagged_ptr2 _temp2201= yyvs; void**
_temp2203= _temp2201.curr + i; if( _temp2201.base == 0? 1:( _temp2203 <
_temp2201.base? 1: _temp2203 >= _temp2201.last_plus_one)){ _throw(
Null_Exception);}* _temp2203;});});({ struct _tagged_ptr3 _temp2204= yyls1;
struct Cyc_Yyltype* _temp2206= _temp2204.curr + i; if( _temp2204.base == 0? 1:(
_temp2206 < _temp2204.base? 1: _temp2206 >= _temp2204.last_plus_one)){ _throw(
Null_Exception);}* _temp2206=({ struct _tagged_ptr3 _temp2207= yyls; struct Cyc_Yyltype*
_temp2209= _temp2207.curr + i; if( _temp2207.base == 0? 1:( _temp2209 <
_temp2207.base? 1: _temp2209 >= _temp2207.last_plus_one)){ _throw(
Null_Exception);}* _temp2209;});});}} yyss= yyss1; yyvs= yyvs1; yyls= yyls1;}}
goto yybackup; yybackup: yyn=( int)({ short* _temp2225=( short*) Cyc_yypact;
unsigned int _temp2226= yystate; if( _temp2226 >= 748u){ _throw( Null_Exception);}
_temp2225[ _temp2226];}); if( yyn == - 32768){ goto yydefault;} if( Cyc_yychar
== - 2){ Cyc_yychar= Cyc_yylex();} if( Cyc_yychar <= 0){ yychar1= 0; Cyc_yychar=
0;} else{ yychar1=( Cyc_yychar > 0? Cyc_yychar <= 351: 0)?( int)({ short*
_temp2227=( short*) Cyc_yytranslate; unsigned int _temp2228= Cyc_yychar; if(
_temp2228 >= 352u){ _throw( Null_Exception);} _temp2227[ _temp2228];}): 231;}
yyn += yychar1; if(( yyn < 0? 1: yyn > 4318)? 1:({ short* _temp2229=( short*)
Cyc_yycheck; unsigned int _temp2230= yyn; if( _temp2230 >= 4319u){ _throw(
Null_Exception);} _temp2229[ _temp2230];}) != yychar1){ goto yydefault;} yyn=(
int)({ short* _temp2231=( short*) Cyc_yytable; unsigned int _temp2232= yyn; if(
_temp2232 >= 4319u){ _throw( Null_Exception);} _temp2231[ _temp2232];}); if( yyn
< 0){ if( yyn == - 32768){ goto yyerrlab;} yyn= - yyn; goto yyreduce;} else{ if(
yyn == 0){ goto yyerrlab;}} if( yyn == 747){ return 0;} if( Cyc_yychar != 0){
Cyc_yychar= - 2;}({ struct _tagged_ptr2 _temp2233= yyvs; void** _temp2235=
_temp2233.curr +( ++ yyvsp_offset); if( _temp2233.base == 0? 1:( _temp2235 <
_temp2233.base? 1: _temp2235 >= _temp2233.last_plus_one)){ _throw(
Null_Exception);}* _temp2235= Cyc_yylval;});({ struct _tagged_ptr3 _temp2236=
yyls; struct Cyc_Yyltype* _temp2238= _temp2236.curr +( ++ yylsp_offset); if(
_temp2236.base == 0? 1:( _temp2238 < _temp2236.base? 1: _temp2238 >= _temp2236.last_plus_one)){
_throw( Null_Exception);}* _temp2238= Cyc_yylloc;}); if( yyerrstatus != 0){
yyerrstatus --;} yystate= yyn; goto yynewstate; yydefault: yyn=( int)({ short*
_temp2239=( short*) Cyc_yydefact; unsigned int _temp2240= yystate; if( _temp2240
>= 748u){ _throw( Null_Exception);} _temp2239[ _temp2240];}); if( yyn == 0){
goto yyerrlab;} yyreduce: yylen=( int)({ short* _temp2241=( short*) Cyc_yyr2;
unsigned int _temp2242= yyn; if( _temp2242 >= 391u){ _throw( Null_Exception);}
_temp2241[ _temp2242];}); if( yylen > 0){ yyval=({ struct _tagged_ptr2 _temp2243=
yyvs; void** _temp2245= _temp2243.curr +(( yyvsp_offset + 1) - yylen); if(
_temp2243.base == 0? 1:( _temp2245 < _temp2243.base? 1: _temp2245 >= _temp2243.last_plus_one)){
_throw( Null_Exception);}* _temp2245;});} switch( yyn){ case 1: _LL2246: yyval=({
struct _tagged_ptr2 _temp2248= yyvs; void** _temp2250= _temp2248.curr +
yyvsp_offset; if( _temp2248.base == 0? 1:( _temp2250 < _temp2248.base? 1:
_temp2250 >= _temp2248.last_plus_one)){ _throw( Null_Exception);}* _temp2250;});
Cyc_Parse_parse_result= Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp2251=
yyvs; void** _temp2253= _temp2251.curr + yyvsp_offset; if( _temp2251.base == 0?
1:( _temp2253 < _temp2251.base? 1: _temp2253 >= _temp2251.last_plus_one)){
_throw( Null_Exception);}* _temp2253;})); break; case 2: _LL2247: yyval=( void*)({
struct Cyc_DeclList_tok_struct* _temp2255=( struct Cyc_DeclList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclList_tok_struct)); _temp2255[ 0]=({ struct Cyc_DeclList_tok_struct
_temp2256; _temp2256.tag= Cyc_DeclList_tok; _temp2256.f1=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_imp_append)( Cyc_yyget_DeclList_tok(({
struct _tagged_ptr2 _temp2257= yyvs; void** _temp2259= _temp2257.curr +(
yyvsp_offset - 1); if( _temp2257.base == 0? 1:( _temp2259 < _temp2257.base? 1:
_temp2259 >= _temp2257.last_plus_one)){ _throw( Null_Exception);}* _temp2259;})),
Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp2260= yyvs; void** _temp2262=
_temp2260.curr + yyvsp_offset; if( _temp2260.base == 0? 1:( _temp2262 <
_temp2260.base? 1: _temp2262 >= _temp2260.last_plus_one)){ _throw(
Null_Exception);}* _temp2262;}))); _temp2256;}); _temp2255;}); break; case 3:
_LL2254: yyval=( void*)({ struct Cyc_DeclList_tok_struct* _temp2264=( struct Cyc_DeclList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclList_tok_struct)); _temp2264[ 0]=({ struct Cyc_DeclList_tok_struct
_temp2265; _temp2265.tag= Cyc_DeclList_tok; _temp2265.f1=({ struct Cyc_List_List*
_temp2266=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp2266->hd=( void*)({ struct Cyc_Absyn_Decl* _temp2267=( struct Cyc_Absyn_Decl*)
GC_malloc( sizeof( struct Cyc_Absyn_Decl)); _temp2267->r=( void*)(( void*)({
struct Cyc_Absyn_Using_d_struct* _temp2274=( struct Cyc_Absyn_Using_d_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Using_d_struct)); _temp2274[ 0]=({ struct
Cyc_Absyn_Using_d_struct _temp2275; _temp2275.tag= Cyc_Absyn_Using_d; _temp2275.f1=
Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp2276= yyvs; void** _temp2278=
_temp2276.curr +( yyvsp_offset - 2); if( _temp2276.base == 0? 1:( _temp2278 <
_temp2276.base? 1: _temp2278 >= _temp2276.last_plus_one)){ _throw(
Null_Exception);}* _temp2278;})); _temp2275.f2= Cyc_yyget_DeclList_tok(({ struct
_tagged_ptr2 _temp2279= yyvs; void** _temp2281= _temp2279.curr + yyvsp_offset;
if( _temp2279.base == 0? 1:( _temp2281 < _temp2279.base? 1: _temp2281 >=
_temp2279.last_plus_one)){ _throw( Null_Exception);}* _temp2281;})); _temp2275;});
_temp2274;})); _temp2267->loc= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2268= yyls; struct Cyc_Yyltype* _temp2270= _temp2268.curr +(
yylsp_offset - 2); if( _temp2268.base == 0? 1:( _temp2270 < _temp2268.base? 1:
_temp2270 >= _temp2268.last_plus_one)){ _throw( Null_Exception);}* _temp2270;}).first_line,({
struct _tagged_ptr3 _temp2271= yyls; struct Cyc_Yyltype* _temp2273= _temp2271.curr
+ yylsp_offset; if( _temp2271.base == 0? 1:( _temp2273 < _temp2271.base? 1:
_temp2273 >= _temp2271.last_plus_one)){ _throw( Null_Exception);}* _temp2273;}).last_line);
_temp2267;}); _temp2266->tl= 0; _temp2266;}); _temp2265;}); _temp2264;}); Cyc_Lex_leave_using();
break; case 4: _LL2263: yyval=( void*)({ struct Cyc_DeclList_tok_struct*
_temp2283=( struct Cyc_DeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclList_tok_struct));
_temp2283[ 0]=({ struct Cyc_DeclList_tok_struct _temp2284; _temp2284.tag= Cyc_DeclList_tok;
_temp2284.f1=({ struct Cyc_List_List* _temp2285=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp2285->hd=( void*)({ struct Cyc_Absyn_Decl*
_temp2289=( struct Cyc_Absyn_Decl*) GC_malloc( sizeof( struct Cyc_Absyn_Decl));
_temp2289->r=( void*)(( void*)({ struct Cyc_Absyn_Using_d_struct* _temp2296=(
struct Cyc_Absyn_Using_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Using_d_struct));
_temp2296[ 0]=({ struct Cyc_Absyn_Using_d_struct _temp2297; _temp2297.tag= Cyc_Absyn_Using_d;
_temp2297.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp2298= yyvs; void**
_temp2300= _temp2298.curr +( yyvsp_offset - 4); if( _temp2298.base == 0? 1:(
_temp2300 < _temp2298.base? 1: _temp2300 >= _temp2298.last_plus_one)){ _throw(
Null_Exception);}* _temp2300;})); _temp2297.f2= Cyc_yyget_DeclList_tok(({ struct
_tagged_ptr2 _temp2301= yyvs; void** _temp2303= _temp2301.curr +( yyvsp_offset -
2); if( _temp2301.base == 0? 1:( _temp2303 < _temp2301.base? 1: _temp2303 >=
_temp2301.last_plus_one)){ _throw( Null_Exception);}* _temp2303;})); _temp2297;});
_temp2296;})); _temp2289->loc= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2290= yyls; struct Cyc_Yyltype* _temp2292= _temp2290.curr +(
yylsp_offset - 4); if( _temp2290.base == 0? 1:( _temp2292 < _temp2290.base? 1:
_temp2292 >= _temp2290.last_plus_one)){ _throw( Null_Exception);}* _temp2292;}).first_line,({
struct _tagged_ptr3 _temp2293= yyls; struct Cyc_Yyltype* _temp2295= _temp2293.curr
+( yylsp_offset - 1); if( _temp2293.base == 0? 1:( _temp2295 < _temp2293.base? 1:
_temp2295 >= _temp2293.last_plus_one)){ _throw( Null_Exception);}* _temp2295;}).last_line);
_temp2289;}); _temp2285->tl= Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2
_temp2286= yyvs; void** _temp2288= _temp2286.curr + yyvsp_offset; if( _temp2286.base
== 0? 1:( _temp2288 < _temp2286.base? 1: _temp2288 >= _temp2286.last_plus_one)){
_throw( Null_Exception);}* _temp2288;})); _temp2285;}); _temp2284;}); _temp2283;});
break; case 5: _LL2282: yyval=( void*)({ struct Cyc_DeclList_tok_struct*
_temp2305=( struct Cyc_DeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclList_tok_struct));
_temp2305[ 0]=({ struct Cyc_DeclList_tok_struct _temp2306; _temp2306.tag= Cyc_DeclList_tok;
_temp2306.f1=({ struct Cyc_List_List* _temp2307=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp2307->hd=( void*)({ struct Cyc_Absyn_Decl*
_temp2308=( struct Cyc_Absyn_Decl*) GC_malloc( sizeof( struct Cyc_Absyn_Decl));
_temp2308->r=( void*)(( void*)({ struct Cyc_Absyn_Namespace_d_struct* _temp2315=(
struct Cyc_Absyn_Namespace_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Namespace_d_struct));
_temp2315[ 0]=({ struct Cyc_Absyn_Namespace_d_struct _temp2316; _temp2316.tag=
Cyc_Absyn_Namespace_d; _temp2316.f1=({ struct _tagged_string* _temp2317=( struct
_tagged_string*) GC_malloc( sizeof( struct _tagged_string) * 1); _temp2317[ 0]=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp2318= yyvs; void** _temp2320=
_temp2318.curr +( yyvsp_offset - 2); if( _temp2318.base == 0? 1:( _temp2320 <
_temp2318.base? 1: _temp2320 >= _temp2318.last_plus_one)){ _throw(
Null_Exception);}* _temp2320;})); _temp2317;}); _temp2316.f2= Cyc_yyget_DeclList_tok(({
struct _tagged_ptr2 _temp2321= yyvs; void** _temp2323= _temp2321.curr +
yyvsp_offset; if( _temp2321.base == 0? 1:( _temp2323 < _temp2321.base? 1:
_temp2323 >= _temp2321.last_plus_one)){ _throw( Null_Exception);}* _temp2323;}));
_temp2316;}); _temp2315;})); _temp2308->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2309= yyls; struct Cyc_Yyltype* _temp2311= _temp2309.curr
+( yylsp_offset - 2); if( _temp2309.base == 0? 1:( _temp2311 < _temp2309.base? 1:
_temp2311 >= _temp2309.last_plus_one)){ _throw( Null_Exception);}* _temp2311;}).first_line,({
struct _tagged_ptr3 _temp2312= yyls; struct Cyc_Yyltype* _temp2314= _temp2312.curr
+ yylsp_offset; if( _temp2312.base == 0? 1:( _temp2314 < _temp2312.base? 1:
_temp2314 >= _temp2312.last_plus_one)){ _throw( Null_Exception);}* _temp2314;}).last_line);
_temp2308;}); _temp2307->tl= 0; _temp2307;}); _temp2306;}); _temp2305;}); Cyc_Lex_leave_namespace();
break; case 6: _LL2304: yyval=( void*)({ struct Cyc_DeclList_tok_struct*
_temp2325=( struct Cyc_DeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclList_tok_struct));
_temp2325[ 0]=({ struct Cyc_DeclList_tok_struct _temp2326; _temp2326.tag= Cyc_DeclList_tok;
_temp2326.f1=({ struct Cyc_List_List* _temp2327=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp2327->hd=( void*)({ struct Cyc_Absyn_Decl*
_temp2331=( struct Cyc_Absyn_Decl*) GC_malloc( sizeof( struct Cyc_Absyn_Decl));
_temp2331->r=( void*)(( void*)({ struct Cyc_Absyn_Namespace_d_struct* _temp2338=(
struct Cyc_Absyn_Namespace_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Namespace_d_struct));
_temp2338[ 0]=({ struct Cyc_Absyn_Namespace_d_struct _temp2339; _temp2339.tag=
Cyc_Absyn_Namespace_d; _temp2339.f1=({ struct _tagged_string* _temp2340=( struct
_tagged_string*) GC_malloc( sizeof( struct _tagged_string) * 1); _temp2340[ 0]=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp2341= yyvs; void** _temp2343=
_temp2341.curr +( yyvsp_offset - 4); if( _temp2341.base == 0? 1:( _temp2343 <
_temp2341.base? 1: _temp2343 >= _temp2341.last_plus_one)){ _throw(
Null_Exception);}* _temp2343;})); _temp2340;}); _temp2339.f2= Cyc_yyget_DeclList_tok(({
struct _tagged_ptr2 _temp2344= yyvs; void** _temp2346= _temp2344.curr +(
yyvsp_offset - 2); if( _temp2344.base == 0? 1:( _temp2346 < _temp2344.base? 1:
_temp2346 >= _temp2344.last_plus_one)){ _throw( Null_Exception);}* _temp2346;}));
_temp2339;}); _temp2338;})); _temp2331->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2332= yyls; struct Cyc_Yyltype* _temp2334= _temp2332.curr
+( yylsp_offset - 4); if( _temp2332.base == 0? 1:( _temp2334 < _temp2332.base? 1:
_temp2334 >= _temp2332.last_plus_one)){ _throw( Null_Exception);}* _temp2334;}).first_line,({
struct _tagged_ptr3 _temp2335= yyls; struct Cyc_Yyltype* _temp2337= _temp2335.curr
+( yylsp_offset - 1); if( _temp2335.base == 0? 1:( _temp2337 < _temp2335.base? 1:
_temp2337 >= _temp2335.last_plus_one)){ _throw( Null_Exception);}* _temp2337;}).last_line);
_temp2331;}); _temp2327->tl= Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2
_temp2328= yyvs; void** _temp2330= _temp2328.curr + yyvsp_offset; if( _temp2328.base
== 0? 1:( _temp2330 < _temp2328.base? 1: _temp2330 >= _temp2328.last_plus_one)){
_throw( Null_Exception);}* _temp2330;})); _temp2327;}); _temp2326;}); _temp2325;});
break; case 7: _LL2324: if( Cyc_String_strcmp( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp2348= yyvs; void** _temp2350= _temp2348.curr +( yyvsp_offset -
4); if( _temp2348.base == 0? 1:( _temp2350 < _temp2348.base? 1: _temp2350 >=
_temp2348.last_plus_one)){ _throw( Null_Exception);}* _temp2350;})),( struct
_tagged_string)({ char* _temp2351=( char*)"C"; struct _tagged_string _temp2352;
_temp2352.curr= _temp2351; _temp2352.base= _temp2351; _temp2352.last_plus_one=
_temp2351 + 2; _temp2352;})) != 0){ Cyc_Parse_err(( struct _tagged_string)({
char* _temp2353=( char*)"only extern \"C\" { ... } is allowed"; struct
_tagged_string _temp2354; _temp2354.curr= _temp2353; _temp2354.base= _temp2353;
_temp2354.last_plus_one= _temp2353 + 35; _temp2354;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2355= yyls; struct Cyc_Yyltype* _temp2357= _temp2355.curr
+( yylsp_offset - 5); if( _temp2355.base == 0? 1:( _temp2357 < _temp2355.base? 1:
_temp2357 >= _temp2355.last_plus_one)){ _throw( Null_Exception);}* _temp2357;}).first_line,({
struct _tagged_ptr3 _temp2358= yyls; struct Cyc_Yyltype* _temp2360= _temp2358.curr
+( yylsp_offset - 4); if( _temp2358.base == 0? 1:( _temp2360 < _temp2358.base? 1:
_temp2360 >= _temp2358.last_plus_one)){ _throw( Null_Exception);}* _temp2360;}).last_line));}
yyval=( void*)({ struct Cyc_DeclList_tok_struct* _temp2361=( struct Cyc_DeclList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclList_tok_struct)); _temp2361[ 0]=({ struct Cyc_DeclList_tok_struct
_temp2362; _temp2362.tag= Cyc_DeclList_tok; _temp2362.f1=({ struct Cyc_List_List*
_temp2363=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp2363->hd=( void*)({ struct Cyc_Absyn_Decl* _temp2367=( struct Cyc_Absyn_Decl*)
GC_malloc( sizeof( struct Cyc_Absyn_Decl)); _temp2367->r=( void*)(( void*)({
struct Cyc_Absyn_ExternC_d_struct* _temp2374=( struct Cyc_Absyn_ExternC_d_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_ExternC_d_struct)); _temp2374[ 0]=({ struct
Cyc_Absyn_ExternC_d_struct _temp2375; _temp2375.tag= Cyc_Absyn_ExternC_d;
_temp2375.f1= Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp2376= yyvs;
void** _temp2378= _temp2376.curr +( yyvsp_offset - 2); if( _temp2376.base == 0?
1:( _temp2378 < _temp2376.base? 1: _temp2378 >= _temp2376.last_plus_one)){
_throw( Null_Exception);}* _temp2378;})); _temp2375;}); _temp2374;})); _temp2367->loc=
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp2368= yyls; struct Cyc_Yyltype*
_temp2370= _temp2368.curr +( yylsp_offset - 5); if( _temp2368.base == 0? 1:(
_temp2370 < _temp2368.base? 1: _temp2370 >= _temp2368.last_plus_one)){ _throw(
Null_Exception);}* _temp2370;}).first_line,({ struct _tagged_ptr3 _temp2371=
yyls; struct Cyc_Yyltype* _temp2373= _temp2371.curr +( yylsp_offset - 1); if(
_temp2371.base == 0? 1:( _temp2373 < _temp2371.base? 1: _temp2373 >= _temp2371.last_plus_one)){
_throw( Null_Exception);}* _temp2373;}).last_line); _temp2367;}); _temp2363->tl=
Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp2364= yyvs; void** _temp2366=
_temp2364.curr + yyvsp_offset; if( _temp2364.base == 0? 1:( _temp2366 <
_temp2364.base? 1: _temp2366 >= _temp2364.last_plus_one)){ _throw(
Null_Exception);}* _temp2366;})); _temp2363;}); _temp2362;}); _temp2361;});
break; case 8: _LL2347: yyval=( void*)({ struct Cyc_DeclList_tok_struct*
_temp2380=( struct Cyc_DeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclList_tok_struct));
_temp2380[ 0]=({ struct Cyc_DeclList_tok_struct _temp2381; _temp2381.tag= Cyc_DeclList_tok;
_temp2381.f1= 0; _temp2381;}); _temp2380;}); break; case 9: _LL2379: yyval=(
void*)({ struct Cyc_DeclList_tok_struct* _temp2383=( struct Cyc_DeclList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclList_tok_struct)); _temp2383[ 0]=({ struct Cyc_DeclList_tok_struct
_temp2384; _temp2384.tag= Cyc_DeclList_tok; _temp2384.f1=({ struct Cyc_List_List*
_temp2385=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp2385->hd=( void*) Cyc_Absyn_new_decl(( void*)({ struct Cyc_Absyn_Fn_d_struct*
_temp2386=( struct Cyc_Absyn_Fn_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Fn_d_struct));
_temp2386[ 0]=({ struct Cyc_Absyn_Fn_d_struct _temp2387; _temp2387.tag= Cyc_Absyn_Fn_d;
_temp2387.f1= Cyc_yyget_FnDecl_tok(({ struct _tagged_ptr2 _temp2388= yyvs; void**
_temp2390= _temp2388.curr + yyvsp_offset; if( _temp2388.base == 0? 1:( _temp2390
< _temp2388.base? 1: _temp2390 >= _temp2388.last_plus_one)){ _throw(
Null_Exception);}* _temp2390;})); _temp2387;}); _temp2386;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2391= yyls; struct Cyc_Yyltype* _temp2393= _temp2391.curr
+ yylsp_offset; if( _temp2391.base == 0? 1:( _temp2393 < _temp2391.base? 1:
_temp2393 >= _temp2391.last_plus_one)){ _throw( Null_Exception);}* _temp2393;}).first_line,({
struct _tagged_ptr3 _temp2394= yyls; struct Cyc_Yyltype* _temp2396= _temp2394.curr
+ yylsp_offset; if( _temp2394.base == 0? 1:( _temp2396 < _temp2394.base? 1:
_temp2396 >= _temp2394.last_plus_one)){ _throw( Null_Exception);}* _temp2396;}).last_line));
_temp2385->tl= 0; _temp2385;}); _temp2384;}); _temp2383;}); break; case 10:
_LL2382: yyval=({ struct _tagged_ptr2 _temp2398= yyvs; void** _temp2400=
_temp2398.curr + yyvsp_offset; if( _temp2398.base == 0? 1:( _temp2400 <
_temp2398.base? 1: _temp2400 >= _temp2398.last_plus_one)){ _throw(
Null_Exception);}* _temp2400;}); break; case 11: _LL2397: yyval=( void*)({
struct Cyc_FnDecl_tok_struct* _temp2402=( struct Cyc_FnDecl_tok_struct*)
GC_malloc( sizeof( struct Cyc_FnDecl_tok_struct)); _temp2402[ 0]=({ struct Cyc_FnDecl_tok_struct
_temp2403; _temp2403.tag= Cyc_FnDecl_tok; _temp2403.f1= Cyc_Parse_make_function(
0, Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2 _temp2404= yyvs; void**
_temp2406= _temp2404.curr +( yyvsp_offset - 1); if( _temp2404.base == 0? 1:(
_temp2406 < _temp2404.base? 1: _temp2406 >= _temp2404.last_plus_one)){ _throw(
Null_Exception);}* _temp2406;})), 0, Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2
_temp2407= yyvs; void** _temp2409= _temp2407.curr + yyvsp_offset; if( _temp2407.base
== 0? 1:( _temp2409 < _temp2407.base? 1: _temp2409 >= _temp2407.last_plus_one)){
_throw( Null_Exception);}* _temp2409;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2410= yyls; struct Cyc_Yyltype* _temp2412= _temp2410.curr +(
yylsp_offset - 1); if( _temp2410.base == 0? 1:( _temp2412 < _temp2410.base? 1:
_temp2412 >= _temp2410.last_plus_one)){ _throw( Null_Exception);}* _temp2412;}).first_line,({
struct _tagged_ptr3 _temp2413= yyls; struct Cyc_Yyltype* _temp2415= _temp2413.curr
+ yylsp_offset; if( _temp2413.base == 0? 1:( _temp2415 < _temp2413.base? 1:
_temp2415 >= _temp2413.last_plus_one)){ _throw( Null_Exception);}* _temp2415;}).last_line));
_temp2403;}); _temp2402;}); break; case 12: _LL2401: yyval=( void*)({ struct Cyc_FnDecl_tok_struct*
_temp2417=( struct Cyc_FnDecl_tok_struct*) GC_malloc( sizeof( struct Cyc_FnDecl_tok_struct));
_temp2417[ 0]=({ struct Cyc_FnDecl_tok_struct _temp2418; _temp2418.tag= Cyc_FnDecl_tok;
_temp2418.f1= Cyc_Parse_make_function(({ struct Cyc_Core_Opt* _temp2419=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp2419->v=( void*)
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2420= yyvs; void** _temp2422=
_temp2420.curr +( yyvsp_offset - 2); if( _temp2420.base == 0? 1:( _temp2422 <
_temp2420.base? 1: _temp2422 >= _temp2420.last_plus_one)){ _throw(
Null_Exception);}* _temp2422;})); _temp2419;}), Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp2423= yyvs; void** _temp2425= _temp2423.curr +(
yyvsp_offset - 1); if( _temp2423.base == 0? 1:( _temp2425 < _temp2423.base? 1:
_temp2425 >= _temp2423.last_plus_one)){ _throw( Null_Exception);}* _temp2425;})),
0, Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp2426= yyvs; void** _temp2428=
_temp2426.curr + yyvsp_offset; if( _temp2426.base == 0? 1:( _temp2428 <
_temp2426.base? 1: _temp2428 >= _temp2426.last_plus_one)){ _throw(
Null_Exception);}* _temp2428;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2429= yyls; struct Cyc_Yyltype* _temp2431= _temp2429.curr +(
yylsp_offset - 2); if( _temp2429.base == 0? 1:( _temp2431 < _temp2429.base? 1:
_temp2431 >= _temp2429.last_plus_one)){ _throw( Null_Exception);}* _temp2431;}).first_line,({
struct _tagged_ptr3 _temp2432= yyls; struct Cyc_Yyltype* _temp2434= _temp2432.curr
+ yylsp_offset; if( _temp2432.base == 0? 1:( _temp2434 < _temp2432.base? 1:
_temp2434 >= _temp2432.last_plus_one)){ _throw( Null_Exception);}* _temp2434;}).last_line));
_temp2418;}); _temp2417;}); break; case 13: _LL2416: yyval=( void*)({ struct Cyc_FnDecl_tok_struct*
_temp2436=( struct Cyc_FnDecl_tok_struct*) GC_malloc( sizeof( struct Cyc_FnDecl_tok_struct));
_temp2436[ 0]=({ struct Cyc_FnDecl_tok_struct _temp2437; _temp2437.tag= Cyc_FnDecl_tok;
_temp2437.f1= Cyc_Parse_make_function( 0, Cyc_yyget_Declarator_tok(({ struct
_tagged_ptr2 _temp2438= yyvs; void** _temp2440= _temp2438.curr +( yyvsp_offset -
2); if( _temp2438.base == 0? 1:( _temp2440 < _temp2438.base? 1: _temp2440 >=
_temp2438.last_plus_one)){ _throw( Null_Exception);}* _temp2440;})), Cyc_yyget_DeclList_tok(({
struct _tagged_ptr2 _temp2441= yyvs; void** _temp2443= _temp2441.curr +(
yyvsp_offset - 1); if( _temp2441.base == 0? 1:( _temp2443 < _temp2441.base? 1:
_temp2443 >= _temp2441.last_plus_one)){ _throw( Null_Exception);}* _temp2443;})),
Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp2444= yyvs; void** _temp2446=
_temp2444.curr + yyvsp_offset; if( _temp2444.base == 0? 1:( _temp2446 <
_temp2444.base? 1: _temp2446 >= _temp2444.last_plus_one)){ _throw(
Null_Exception);}* _temp2446;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2447= yyls; struct Cyc_Yyltype* _temp2449= _temp2447.curr +(
yylsp_offset - 2); if( _temp2447.base == 0? 1:( _temp2449 < _temp2447.base? 1:
_temp2449 >= _temp2447.last_plus_one)){ _throw( Null_Exception);}* _temp2449;}).first_line,({
struct _tagged_ptr3 _temp2450= yyls; struct Cyc_Yyltype* _temp2452= _temp2450.curr
+ yylsp_offset; if( _temp2450.base == 0? 1:( _temp2452 < _temp2450.base? 1:
_temp2452 >= _temp2450.last_plus_one)){ _throw( Null_Exception);}* _temp2452;}).last_line));
_temp2437;}); _temp2436;}); break; case 14: _LL2435: yyval=( void*)({ struct Cyc_FnDecl_tok_struct*
_temp2454=( struct Cyc_FnDecl_tok_struct*) GC_malloc( sizeof( struct Cyc_FnDecl_tok_struct));
_temp2454[ 0]=({ struct Cyc_FnDecl_tok_struct _temp2455; _temp2455.tag= Cyc_FnDecl_tok;
_temp2455.f1= Cyc_Parse_make_function(({ struct Cyc_Core_Opt* _temp2456=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp2456->v=( void*)
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2457= yyvs; void** _temp2459=
_temp2457.curr +( yyvsp_offset - 3); if( _temp2457.base == 0? 1:( _temp2459 <
_temp2457.base? 1: _temp2459 >= _temp2457.last_plus_one)){ _throw(
Null_Exception);}* _temp2459;})); _temp2456;}), Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp2460= yyvs; void** _temp2462= _temp2460.curr +(
yyvsp_offset - 2); if( _temp2460.base == 0? 1:( _temp2462 < _temp2460.base? 1:
_temp2462 >= _temp2460.last_plus_one)){ _throw( Null_Exception);}* _temp2462;})),
Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp2463= yyvs; void** _temp2465=
_temp2463.curr +( yyvsp_offset - 1); if( _temp2463.base == 0? 1:( _temp2465 <
_temp2463.base? 1: _temp2465 >= _temp2463.last_plus_one)){ _throw(
Null_Exception);}* _temp2465;})), Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2
_temp2466= yyvs; void** _temp2468= _temp2466.curr + yyvsp_offset; if( _temp2466.base
== 0? 1:( _temp2468 < _temp2466.base? 1: _temp2468 >= _temp2466.last_plus_one)){
_throw( Null_Exception);}* _temp2468;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2469= yyls; struct Cyc_Yyltype* _temp2471= _temp2469.curr +(
yylsp_offset - 3); if( _temp2469.base == 0? 1:( _temp2471 < _temp2469.base? 1:
_temp2471 >= _temp2469.last_plus_one)){ _throw( Null_Exception);}* _temp2471;}).first_line,({
struct _tagged_ptr3 _temp2472= yyls; struct Cyc_Yyltype* _temp2474= _temp2472.curr
+ yylsp_offset; if( _temp2472.base == 0? 1:( _temp2474 < _temp2472.base? 1:
_temp2474 >= _temp2472.last_plus_one)){ _throw( Null_Exception);}* _temp2474;}).last_line));
_temp2455;}); _temp2454;}); break; case 15: _LL2453: yyval=( void*)({ struct Cyc_FnDecl_tok_struct*
_temp2476=( struct Cyc_FnDecl_tok_struct*) GC_malloc( sizeof( struct Cyc_FnDecl_tok_struct));
_temp2476[ 0]=({ struct Cyc_FnDecl_tok_struct _temp2477; _temp2477.tag= Cyc_FnDecl_tok;
_temp2477.f1= Cyc_Parse_make_function(({ struct Cyc_Core_Opt* _temp2478=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp2478->v=( void*)
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2479= yyvs; void** _temp2481=
_temp2479.curr +( yyvsp_offset - 2); if( _temp2479.base == 0? 1:( _temp2481 <
_temp2479.base? 1: _temp2481 >= _temp2479.last_plus_one)){ _throw(
Null_Exception);}* _temp2481;})); _temp2478;}), Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp2482= yyvs; void** _temp2484= _temp2482.curr +(
yyvsp_offset - 1); if( _temp2482.base == 0? 1:( _temp2484 < _temp2482.base? 1:
_temp2484 >= _temp2482.last_plus_one)){ _throw( Null_Exception);}* _temp2484;})),
0, Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp2485= yyvs; void** _temp2487=
_temp2485.curr + yyvsp_offset; if( _temp2485.base == 0? 1:( _temp2487 <
_temp2485.base? 1: _temp2487 >= _temp2485.last_plus_one)){ _throw(
Null_Exception);}* _temp2487;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2488= yyls; struct Cyc_Yyltype* _temp2490= _temp2488.curr +(
yylsp_offset - 2); if( _temp2488.base == 0? 1:( _temp2490 < _temp2488.base? 1:
_temp2490 >= _temp2488.last_plus_one)){ _throw( Null_Exception);}* _temp2490;}).first_line,({
struct _tagged_ptr3 _temp2491= yyls; struct Cyc_Yyltype* _temp2493= _temp2491.curr
+ yylsp_offset; if( _temp2491.base == 0? 1:( _temp2493 < _temp2491.base? 1:
_temp2493 >= _temp2491.last_plus_one)){ _throw( Null_Exception);}* _temp2493;}).last_line));
_temp2477;}); _temp2476;}); break; case 16: _LL2475: yyval=( void*)({ struct Cyc_FnDecl_tok_struct*
_temp2495=( struct Cyc_FnDecl_tok_struct*) GC_malloc( sizeof( struct Cyc_FnDecl_tok_struct));
_temp2495[ 0]=({ struct Cyc_FnDecl_tok_struct _temp2496; _temp2496.tag= Cyc_FnDecl_tok;
_temp2496.f1= Cyc_Parse_make_function(({ struct Cyc_Core_Opt* _temp2497=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp2497->v=( void*)
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2498= yyvs; void** _temp2500=
_temp2498.curr +( yyvsp_offset - 3); if( _temp2498.base == 0? 1:( _temp2500 <
_temp2498.base? 1: _temp2500 >= _temp2498.last_plus_one)){ _throw(
Null_Exception);}* _temp2500;})); _temp2497;}), Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp2501= yyvs; void** _temp2503= _temp2501.curr +(
yyvsp_offset - 2); if( _temp2501.base == 0? 1:( _temp2503 < _temp2501.base? 1:
_temp2503 >= _temp2501.last_plus_one)){ _throw( Null_Exception);}* _temp2503;})),
Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp2504= yyvs; void** _temp2506=
_temp2504.curr +( yyvsp_offset - 1); if( _temp2504.base == 0? 1:( _temp2506 <
_temp2504.base? 1: _temp2506 >= _temp2504.last_plus_one)){ _throw(
Null_Exception);}* _temp2506;})), Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2
_temp2507= yyvs; void** _temp2509= _temp2507.curr + yyvsp_offset; if( _temp2507.base
== 0? 1:( _temp2509 < _temp2507.base? 1: _temp2509 >= _temp2507.last_plus_one)){
_throw( Null_Exception);}* _temp2509;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2510= yyls; struct Cyc_Yyltype* _temp2512= _temp2510.curr +(
yylsp_offset - 3); if( _temp2510.base == 0? 1:( _temp2512 < _temp2510.base? 1:
_temp2512 >= _temp2510.last_plus_one)){ _throw( Null_Exception);}* _temp2512;}).first_line,({
struct _tagged_ptr3 _temp2513= yyls; struct Cyc_Yyltype* _temp2515= _temp2513.curr
+ yylsp_offset; if( _temp2513.base == 0? 1:( _temp2515 < _temp2513.base? 1:
_temp2515 >= _temp2513.last_plus_one)){ _throw( Null_Exception);}* _temp2515;}).last_line));
_temp2496;}); _temp2495;}); break; case 17: _LL2494: Cyc_Lex_enter_using( Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp2517= yyvs; void** _temp2519= _temp2517.curr +
yyvsp_offset; if( _temp2517.base == 0? 1:( _temp2519 < _temp2517.base? 1:
_temp2519 >= _temp2517.last_plus_one)){ _throw( Null_Exception);}* _temp2519;})));
yyval=({ struct _tagged_ptr2 _temp2520= yyvs; void** _temp2522= _temp2520.curr +
yyvsp_offset; if( _temp2520.base == 0? 1:( _temp2522 < _temp2520.base? 1:
_temp2522 >= _temp2520.last_plus_one)){ _throw( Null_Exception);}* _temp2522;});
break; case 18: _LL2516: Cyc_Lex_leave_using(); break; case 19: _LL2523: Cyc_Lex_enter_namespace(({
struct _tagged_string* _temp2525=( struct _tagged_string*) GC_malloc( sizeof(
struct _tagged_string) * 1); _temp2525[ 0]= Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp2526= yyvs; void** _temp2528= _temp2526.curr + yyvsp_offset;
if( _temp2526.base == 0? 1:( _temp2528 < _temp2526.base? 1: _temp2528 >=
_temp2526.last_plus_one)){ _throw( Null_Exception);}* _temp2528;})); _temp2525;}));
yyval=({ struct _tagged_ptr2 _temp2529= yyvs; void** _temp2531= _temp2529.curr +
yyvsp_offset; if( _temp2529.base == 0? 1:( _temp2531 < _temp2529.base? 1:
_temp2531 >= _temp2529.last_plus_one)){ _throw( Null_Exception);}* _temp2531;});
break; case 20: _LL2524: Cyc_Lex_leave_namespace(); break; case 21: _LL2532:
yyval=( void*)({ struct Cyc_DeclList_tok_struct* _temp2534=( struct Cyc_DeclList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclList_tok_struct)); _temp2534[ 0]=({ struct Cyc_DeclList_tok_struct
_temp2535; _temp2535.tag= Cyc_DeclList_tok; _temp2535.f1= Cyc_Parse_make_declarations(
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2536= yyvs; void** _temp2538=
_temp2536.curr +( yyvsp_offset - 1); if( _temp2536.base == 0? 1:( _temp2538 <
_temp2536.base? 1: _temp2538 >= _temp2536.last_plus_one)){ _throw(
Null_Exception);}* _temp2538;})), 0, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2539= yyls; struct Cyc_Yyltype* _temp2541= _temp2539.curr +(
yylsp_offset - 1); if( _temp2539.base == 0? 1:( _temp2541 < _temp2539.base? 1:
_temp2541 >= _temp2539.last_plus_one)){ _throw( Null_Exception);}* _temp2541;}).first_line,({
struct _tagged_ptr3 _temp2542= yyls; struct Cyc_Yyltype* _temp2544= _temp2542.curr
+( yylsp_offset - 1); if( _temp2542.base == 0? 1:( _temp2544 < _temp2542.base? 1:
_temp2544 >= _temp2542.last_plus_one)){ _throw( Null_Exception);}* _temp2544;}).last_line));
_temp2535;}); _temp2534;}); break; case 22: _LL2533: yyval=( void*)({ struct Cyc_DeclList_tok_struct*
_temp2546=( struct Cyc_DeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclList_tok_struct));
_temp2546[ 0]=({ struct Cyc_DeclList_tok_struct _temp2547; _temp2547.tag= Cyc_DeclList_tok;
_temp2547.f1= Cyc_Parse_make_declarations( Cyc_yyget_DeclSpec_tok(({ struct
_tagged_ptr2 _temp2548= yyvs; void** _temp2550= _temp2548.curr +( yyvsp_offset -
2); if( _temp2548.base == 0? 1:( _temp2550 < _temp2548.base? 1: _temp2550 >=
_temp2548.last_plus_one)){ _throw( Null_Exception);}* _temp2550;})), Cyc_yyget_InitDeclList_tok(({
struct _tagged_ptr2 _temp2551= yyvs; void** _temp2553= _temp2551.curr +(
yyvsp_offset - 1); if( _temp2551.base == 0? 1:( _temp2553 < _temp2551.base? 1:
_temp2553 >= _temp2551.last_plus_one)){ _throw( Null_Exception);}* _temp2553;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp2554= yyls; struct Cyc_Yyltype*
_temp2556= _temp2554.curr +( yylsp_offset - 2); if( _temp2554.base == 0? 1:(
_temp2556 < _temp2554.base? 1: _temp2556 >= _temp2554.last_plus_one)){ _throw(
Null_Exception);}* _temp2556;}).first_line,({ struct _tagged_ptr3 _temp2557=
yyls; struct Cyc_Yyltype* _temp2559= _temp2557.curr + yylsp_offset; if(
_temp2557.base == 0? 1:( _temp2559 < _temp2557.base? 1: _temp2559 >= _temp2557.last_plus_one)){
_throw( Null_Exception);}* _temp2559;}).last_line)); _temp2547;}); _temp2546;});
break; case 23: _LL2545: yyval=( void*)({ struct Cyc_DeclList_tok_struct*
_temp2561=( struct Cyc_DeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclList_tok_struct));
_temp2561[ 0]=({ struct Cyc_DeclList_tok_struct _temp2562; _temp2562.tag= Cyc_DeclList_tok;
_temp2562.f1=({ struct Cyc_List_List* _temp2563=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp2563->hd=( void*) Cyc_Absyn_let_decl(
Cyc_yyget_Pattern_tok(({ struct _tagged_ptr2 _temp2564= yyvs; void** _temp2566=
_temp2564.curr +( yyvsp_offset - 3); if( _temp2564.base == 0? 1:( _temp2566 <
_temp2564.base? 1: _temp2566 >= _temp2564.last_plus_one)){ _throw(
Null_Exception);}* _temp2566;})), 0, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp2567= yyvs; void** _temp2569= _temp2567.curr +( yyvsp_offset - 1); if(
_temp2567.base == 0? 1:( _temp2569 < _temp2567.base? 1: _temp2569 >= _temp2567.last_plus_one)){
_throw( Null_Exception);}* _temp2569;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2570= yyls; struct Cyc_Yyltype* _temp2572= _temp2570.curr +(
yylsp_offset - 4); if( _temp2570.base == 0? 1:( _temp2572 < _temp2570.base? 1:
_temp2572 >= _temp2570.last_plus_one)){ _throw( Null_Exception);}* _temp2572;}).first_line,({
struct _tagged_ptr3 _temp2573= yyls; struct Cyc_Yyltype* _temp2575= _temp2573.curr
+ yylsp_offset; if( _temp2573.base == 0? 1:( _temp2575 < _temp2573.base? 1:
_temp2575 >= _temp2573.last_plus_one)){ _throw( Null_Exception);}* _temp2575;}).last_line));
_temp2563->tl= 0; _temp2563;}); _temp2562;}); _temp2561;}); break; case 24:
_LL2560: yyval=({ struct _tagged_ptr2 _temp2577= yyvs; void** _temp2579=
_temp2577.curr + yyvsp_offset; if( _temp2577.base == 0? 1:( _temp2579 <
_temp2577.base? 1: _temp2579 >= _temp2577.last_plus_one)){ _throw(
Null_Exception);}* _temp2579;}); break; case 25: _LL2576: yyval=( void*)({
struct Cyc_DeclList_tok_struct* _temp2581=( struct Cyc_DeclList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclList_tok_struct)); _temp2581[ 0]=({ struct Cyc_DeclList_tok_struct
_temp2582; _temp2582.tag= Cyc_DeclList_tok; _temp2582.f1=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_imp_append)( Cyc_yyget_DeclList_tok(({
struct _tagged_ptr2 _temp2583= yyvs; void** _temp2585= _temp2583.curr +(
yyvsp_offset - 1); if( _temp2583.base == 0? 1:( _temp2585 < _temp2583.base? 1:
_temp2585 >= _temp2583.last_plus_one)){ _throw( Null_Exception);}* _temp2585;})),
Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp2586= yyvs; void** _temp2588=
_temp2586.curr + yyvsp_offset; if( _temp2586.base == 0? 1:( _temp2588 <
_temp2586.base? 1: _temp2588 >= _temp2586.last_plus_one)){ _throw(
Null_Exception);}* _temp2588;}))); _temp2582;}); _temp2581;}); break; case 26:
_LL2580: yyval=( void*)({ struct Cyc_DeclSpec_tok_struct* _temp2590=( struct Cyc_DeclSpec_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct)); _temp2590[ 0]=({ struct Cyc_DeclSpec_tok_struct
_temp2591; _temp2591.tag= Cyc_DeclSpec_tok; _temp2591.f1=({ struct Cyc_Parse_Declaration_spec*
_temp2592=( struct Cyc_Parse_Declaration_spec*) GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec));
_temp2592->sc=({ struct Cyc_Core_Opt* _temp2596=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp2596->v=( void*) Cyc_yyget_StorageClass_tok(({
struct _tagged_ptr2 _temp2597= yyvs; void** _temp2599= _temp2597.curr +(
yyvsp_offset - 1); if( _temp2597.base == 0? 1:( _temp2599 < _temp2597.base? 1:
_temp2599 >= _temp2597.last_plus_one)){ _throw( Null_Exception);}* _temp2599;}));
_temp2596;}); _temp2592->tq= Cyc_Absyn_empty_tqual(); _temp2592->type_specs= 0;
_temp2592->is_inline= 0; _temp2592->attributes= Cyc_yyget_AttributeList_tok(({
struct _tagged_ptr2 _temp2593= yyvs; void** _temp2595= _temp2593.curr +
yyvsp_offset; if( _temp2593.base == 0? 1:( _temp2595 < _temp2593.base? 1:
_temp2595 >= _temp2593.last_plus_one)){ _throw( Null_Exception);}* _temp2595;}));
_temp2592;}); _temp2591;}); _temp2590;}); break; case 27: _LL2589: if(( Cyc_yyget_DeclSpec_tok(({
struct _tagged_ptr2 _temp2601= yyvs; void** _temp2603= _temp2601.curr +
yyvsp_offset; if( _temp2601.base == 0? 1:( _temp2603 < _temp2601.base? 1:
_temp2603 >= _temp2601.last_plus_one)){ _throw( Null_Exception);}* _temp2603;})))->sc
!= 0){ Cyc_Parse_warn(( struct _tagged_string)({ char* _temp2604=( char*)"Only one storage class is allowed in a declaration";
struct _tagged_string _temp2605; _temp2605.curr= _temp2604; _temp2605.base=
_temp2604; _temp2605.last_plus_one= _temp2604 + 51; _temp2605;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2606= yyls; struct Cyc_Yyltype* _temp2608= _temp2606.curr
+( yylsp_offset - 2); if( _temp2606.base == 0? 1:( _temp2608 < _temp2606.base? 1:
_temp2608 >= _temp2606.last_plus_one)){ _throw( Null_Exception);}* _temp2608;}).first_line,({
struct _tagged_ptr3 _temp2609= yyls; struct Cyc_Yyltype* _temp2611= _temp2609.curr
+( yylsp_offset - 1); if( _temp2609.base == 0? 1:( _temp2611 < _temp2609.base? 1:
_temp2611 >= _temp2609.last_plus_one)){ _throw( Null_Exception);}* _temp2611;}).last_line));}
yyval=( void*)({ struct Cyc_DeclSpec_tok_struct* _temp2612=( struct Cyc_DeclSpec_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct)); _temp2612[ 0]=({ struct Cyc_DeclSpec_tok_struct
_temp2613; _temp2613.tag= Cyc_DeclSpec_tok; _temp2613.f1=({ struct Cyc_Parse_Declaration_spec*
_temp2614=( struct Cyc_Parse_Declaration_spec*) GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec));
_temp2614->sc=({ struct Cyc_Core_Opt* _temp2630=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp2630->v=( void*) Cyc_yyget_StorageClass_tok(({
struct _tagged_ptr2 _temp2631= yyvs; void** _temp2633= _temp2631.curr +(
yyvsp_offset - 2); if( _temp2631.base == 0? 1:( _temp2633 < _temp2631.base? 1:
_temp2633 >= _temp2631.last_plus_one)){ _throw( Null_Exception);}* _temp2633;}));
_temp2630;}); _temp2614->tq=( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2
_temp2627= yyvs; void** _temp2629= _temp2627.curr + yyvsp_offset; if( _temp2627.base
== 0? 1:( _temp2629 < _temp2627.base? 1: _temp2629 >= _temp2627.last_plus_one)){
_throw( Null_Exception);}* _temp2629;})))->tq; _temp2614->type_specs=( Cyc_yyget_DeclSpec_tok(({
struct _tagged_ptr2 _temp2624= yyvs; void** _temp2626= _temp2624.curr +
yyvsp_offset; if( _temp2624.base == 0? 1:( _temp2626 < _temp2624.base? 1:
_temp2626 >= _temp2624.last_plus_one)){ _throw( Null_Exception);}* _temp2626;})))->type_specs;
_temp2614->is_inline=( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2621=
yyvs; void** _temp2623= _temp2621.curr + yyvsp_offset; if( _temp2621.base == 0?
1:( _temp2623 < _temp2621.base? 1: _temp2623 >= _temp2621.last_plus_one)){
_throw( Null_Exception);}* _temp2623;})))->is_inline; _temp2614->attributes=((
struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_imp_append)(
Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp2615= yyvs; void**
_temp2617= _temp2615.curr +( yyvsp_offset - 1); if( _temp2615.base == 0? 1:(
_temp2617 < _temp2615.base? 1: _temp2617 >= _temp2615.last_plus_one)){ _throw(
Null_Exception);}* _temp2617;})),( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2
_temp2618= yyvs; void** _temp2620= _temp2618.curr + yyvsp_offset; if( _temp2618.base
== 0? 1:( _temp2620 < _temp2618.base? 1: _temp2620 >= _temp2618.last_plus_one)){
_throw( Null_Exception);}* _temp2620;})))->attributes); _temp2614;}); _temp2613;});
_temp2612;}); break; case 28: _LL2600: yyval=( void*)({ struct Cyc_DeclSpec_tok_struct*
_temp2635=( struct Cyc_DeclSpec_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct));
_temp2635[ 0]=({ struct Cyc_DeclSpec_tok_struct _temp2636; _temp2636.tag= Cyc_DeclSpec_tok;
_temp2636.f1=({ struct Cyc_Parse_Declaration_spec* _temp2637=( struct Cyc_Parse_Declaration_spec*)
GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec)); _temp2637->sc= 0;
_temp2637->tq= Cyc_Absyn_empty_tqual(); _temp2637->type_specs=({ struct Cyc_List_List*
_temp2641=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp2641->hd=( void*) Cyc_yyget_TypeSpecifier_tok(({ struct _tagged_ptr2
_temp2642= yyvs; void** _temp2644= _temp2642.curr +( yyvsp_offset - 1); if(
_temp2642.base == 0? 1:( _temp2644 < _temp2642.base? 1: _temp2644 >= _temp2642.last_plus_one)){
_throw( Null_Exception);}* _temp2644;})); _temp2641->tl= 0; _temp2641;});
_temp2637->is_inline= 0; _temp2637->attributes= Cyc_yyget_AttributeList_tok(({
struct _tagged_ptr2 _temp2638= yyvs; void** _temp2640= _temp2638.curr +
yyvsp_offset; if( _temp2638.base == 0? 1:( _temp2640 < _temp2638.base? 1:
_temp2640 >= _temp2638.last_plus_one)){ _throw( Null_Exception);}* _temp2640;}));
_temp2637;}); _temp2636;}); _temp2635;}); break; case 29: _LL2634: yyval=( void*)({
struct Cyc_DeclSpec_tok_struct* _temp2646=( struct Cyc_DeclSpec_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct)); _temp2646[ 0]=({ struct Cyc_DeclSpec_tok_struct
_temp2647; _temp2647.tag= Cyc_DeclSpec_tok; _temp2647.f1=({ struct Cyc_Parse_Declaration_spec*
_temp2648=( struct Cyc_Parse_Declaration_spec*) GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec));
_temp2648->sc=( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2668= yyvs;
void** _temp2670= _temp2668.curr + yyvsp_offset; if( _temp2668.base == 0? 1:(
_temp2670 < _temp2668.base? 1: _temp2670 >= _temp2668.last_plus_one)){ _throw(
Null_Exception);}* _temp2670;})))->sc; _temp2648->tq=( Cyc_yyget_DeclSpec_tok(({
struct _tagged_ptr2 _temp2665= yyvs; void** _temp2667= _temp2665.curr +
yyvsp_offset; if( _temp2665.base == 0? 1:( _temp2667 < _temp2665.base? 1:
_temp2667 >= _temp2665.last_plus_one)){ _throw( Null_Exception);}* _temp2667;})))->tq;
_temp2648->type_specs=({ struct Cyc_List_List* _temp2658=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp2658->hd=( void*) Cyc_yyget_TypeSpecifier_tok(({
struct _tagged_ptr2 _temp2662= yyvs; void** _temp2664= _temp2662.curr +(
yyvsp_offset - 2); if( _temp2662.base == 0? 1:( _temp2664 < _temp2662.base? 1:
_temp2664 >= _temp2662.last_plus_one)){ _throw( Null_Exception);}* _temp2664;}));
_temp2658->tl=( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2659= yyvs;
void** _temp2661= _temp2659.curr + yyvsp_offset; if( _temp2659.base == 0? 1:(
_temp2661 < _temp2659.base? 1: _temp2661 >= _temp2659.last_plus_one)){ _throw(
Null_Exception);}* _temp2661;})))->type_specs; _temp2658;}); _temp2648->is_inline=(
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2655= yyvs; void** _temp2657=
_temp2655.curr + yyvsp_offset; if( _temp2655.base == 0? 1:( _temp2657 <
_temp2655.base? 1: _temp2657 >= _temp2655.last_plus_one)){ _throw(
Null_Exception);}* _temp2657;})))->is_inline; _temp2648->attributes=(( struct
Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_imp_append)(
Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp2649= yyvs; void**
_temp2651= _temp2649.curr +( yyvsp_offset - 1); if( _temp2649.base == 0? 1:(
_temp2651 < _temp2649.base? 1: _temp2651 >= _temp2649.last_plus_one)){ _throw(
Null_Exception);}* _temp2651;})),( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2
_temp2652= yyvs; void** _temp2654= _temp2652.curr + yyvsp_offset; if( _temp2652.base
== 0? 1:( _temp2654 < _temp2652.base? 1: _temp2654 >= _temp2652.last_plus_one)){
_throw( Null_Exception);}* _temp2654;})))->attributes); _temp2648;}); _temp2647;});
_temp2646;}); break; case 30: _LL2645: yyval=( void*)({ struct Cyc_DeclSpec_tok_struct*
_temp2672=( struct Cyc_DeclSpec_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct));
_temp2672[ 0]=({ struct Cyc_DeclSpec_tok_struct _temp2673; _temp2673.tag= Cyc_DeclSpec_tok;
_temp2673.f1=({ struct Cyc_Parse_Declaration_spec* _temp2674=( struct Cyc_Parse_Declaration_spec*)
GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec)); _temp2674->sc= 0;
_temp2674->tq= Cyc_yyget_TypeQual_tok(({ struct _tagged_ptr2 _temp2678= yyvs;
void** _temp2680= _temp2678.curr +( yyvsp_offset - 1); if( _temp2678.base == 0?
1:( _temp2680 < _temp2678.base? 1: _temp2680 >= _temp2678.last_plus_one)){
_throw( Null_Exception);}* _temp2680;})); _temp2674->type_specs= 0; _temp2674->is_inline=
0; _temp2674->attributes= Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2
_temp2675= yyvs; void** _temp2677= _temp2675.curr + yyvsp_offset; if( _temp2675.base
== 0? 1:( _temp2677 < _temp2675.base? 1: _temp2677 >= _temp2675.last_plus_one)){
_throw( Null_Exception);}* _temp2677;})); _temp2674;}); _temp2673;}); _temp2672;});
break; case 31: _LL2671: yyval=( void*)({ struct Cyc_DeclSpec_tok_struct*
_temp2682=( struct Cyc_DeclSpec_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct));
_temp2682[ 0]=({ struct Cyc_DeclSpec_tok_struct _temp2683; _temp2683.tag= Cyc_DeclSpec_tok;
_temp2683.f1=({ struct Cyc_Parse_Declaration_spec* _temp2684=( struct Cyc_Parse_Declaration_spec*)
GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec)); _temp2684->sc=( Cyc_yyget_DeclSpec_tok(({
struct _tagged_ptr2 _temp2703= yyvs; void** _temp2705= _temp2703.curr +
yyvsp_offset; if( _temp2703.base == 0? 1:( _temp2705 < _temp2703.base? 1:
_temp2705 >= _temp2703.last_plus_one)){ _throw( Null_Exception);}* _temp2705;})))->sc;
_temp2684->tq= Cyc_Absyn_combine_tqual( Cyc_yyget_TypeQual_tok(({ struct
_tagged_ptr2 _temp2697= yyvs; void** _temp2699= _temp2697.curr +( yyvsp_offset -
2); if( _temp2697.base == 0? 1:( _temp2699 < _temp2697.base? 1: _temp2699 >=
_temp2697.last_plus_one)){ _throw( Null_Exception);}* _temp2699;})),( Cyc_yyget_DeclSpec_tok(({
struct _tagged_ptr2 _temp2700= yyvs; void** _temp2702= _temp2700.curr +
yyvsp_offset; if( _temp2700.base == 0? 1:( _temp2702 < _temp2700.base? 1:
_temp2702 >= _temp2700.last_plus_one)){ _throw( Null_Exception);}* _temp2702;})))->tq);
_temp2684->type_specs=( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2694=
yyvs; void** _temp2696= _temp2694.curr + yyvsp_offset; if( _temp2694.base == 0?
1:( _temp2696 < _temp2694.base? 1: _temp2696 >= _temp2694.last_plus_one)){
_throw( Null_Exception);}* _temp2696;})))->type_specs; _temp2684->is_inline=(
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2691= yyvs; void** _temp2693=
_temp2691.curr + yyvsp_offset; if( _temp2691.base == 0? 1:( _temp2693 <
_temp2691.base? 1: _temp2693 >= _temp2691.last_plus_one)){ _throw(
Null_Exception);}* _temp2693;})))->is_inline; _temp2684->attributes=(( struct
Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_imp_append)(
Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp2685= yyvs; void**
_temp2687= _temp2685.curr +( yyvsp_offset - 1); if( _temp2685.base == 0? 1:(
_temp2687 < _temp2685.base? 1: _temp2687 >= _temp2685.last_plus_one)){ _throw(
Null_Exception);}* _temp2687;})),( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2
_temp2688= yyvs; void** _temp2690= _temp2688.curr + yyvsp_offset; if( _temp2688.base
== 0? 1:( _temp2690 < _temp2688.base? 1: _temp2690 >= _temp2688.last_plus_one)){
_throw( Null_Exception);}* _temp2690;})))->attributes); _temp2684;}); _temp2683;});
_temp2682;}); break; case 32: _LL2681: yyval=( void*)({ struct Cyc_DeclSpec_tok_struct*
_temp2707=( struct Cyc_DeclSpec_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct));
_temp2707[ 0]=({ struct Cyc_DeclSpec_tok_struct _temp2708; _temp2708.tag= Cyc_DeclSpec_tok;
_temp2708.f1=({ struct Cyc_Parse_Declaration_spec* _temp2709=( struct Cyc_Parse_Declaration_spec*)
GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec)); _temp2709->sc= 0;
_temp2709->tq= Cyc_Absyn_empty_tqual(); _temp2709->type_specs= 0; _temp2709->is_inline=
1; _temp2709->attributes= Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2
_temp2710= yyvs; void** _temp2712= _temp2710.curr + yyvsp_offset; if( _temp2710.base
== 0? 1:( _temp2712 < _temp2710.base? 1: _temp2712 >= _temp2710.last_plus_one)){
_throw( Null_Exception);}* _temp2712;})); _temp2709;}); _temp2708;}); _temp2707;});
break; case 33: _LL2706: yyval=( void*)({ struct Cyc_DeclSpec_tok_struct*
_temp2714=( struct Cyc_DeclSpec_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclSpec_tok_struct));
_temp2714[ 0]=({ struct Cyc_DeclSpec_tok_struct _temp2715; _temp2715.tag= Cyc_DeclSpec_tok;
_temp2715.f1=({ struct Cyc_Parse_Declaration_spec* _temp2716=( struct Cyc_Parse_Declaration_spec*)
GC_malloc( sizeof( struct Cyc_Parse_Declaration_spec)); _temp2716->sc=( Cyc_yyget_DeclSpec_tok(({
struct _tagged_ptr2 _temp2729= yyvs; void** _temp2731= _temp2729.curr +
yyvsp_offset; if( _temp2729.base == 0? 1:( _temp2731 < _temp2729.base? 1:
_temp2731 >= _temp2729.last_plus_one)){ _throw( Null_Exception);}* _temp2731;})))->sc;
_temp2716->tq=( Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2726= yyvs;
void** _temp2728= _temp2726.curr + yyvsp_offset; if( _temp2726.base == 0? 1:(
_temp2728 < _temp2726.base? 1: _temp2728 >= _temp2726.last_plus_one)){ _throw(
Null_Exception);}* _temp2728;})))->tq; _temp2716->type_specs=( Cyc_yyget_DeclSpec_tok(({
struct _tagged_ptr2 _temp2723= yyvs; void** _temp2725= _temp2723.curr +
yyvsp_offset; if( _temp2723.base == 0? 1:( _temp2725 < _temp2723.base? 1:
_temp2725 >= _temp2723.last_plus_one)){ _throw( Null_Exception);}* _temp2725;})))->type_specs;
_temp2716->is_inline= 1; _temp2716->attributes=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_imp_append)( Cyc_yyget_AttributeList_tok(({
struct _tagged_ptr2 _temp2717= yyvs; void** _temp2719= _temp2717.curr +(
yyvsp_offset - 1); if( _temp2717.base == 0? 1:( _temp2719 < _temp2717.base? 1:
_temp2719 >= _temp2717.last_plus_one)){ _throw( Null_Exception);}* _temp2719;})),(
Cyc_yyget_DeclSpec_tok(({ struct _tagged_ptr2 _temp2720= yyvs; void** _temp2722=
_temp2720.curr + yyvsp_offset; if( _temp2720.base == 0? 1:( _temp2722 <
_temp2720.base? 1: _temp2722 >= _temp2720.last_plus_one)){ _throw(
Null_Exception);}* _temp2722;})))->attributes); _temp2716;}); _temp2715;});
_temp2714;}); break; case 34: _LL2713: yyval=( void*)({ struct Cyc_StorageClass_tok_struct*
_temp2733=( struct Cyc_StorageClass_tok_struct*) GC_malloc( sizeof( struct Cyc_StorageClass_tok_struct));
_temp2733[ 0]=({ struct Cyc_StorageClass_tok_struct _temp2734; _temp2734.tag=
Cyc_StorageClass_tok; _temp2734.f1=( void*)(( void*) Cyc_Parse_Auto_sc);
_temp2734;}); _temp2733;}); break; case 35: _LL2732: yyval=( void*)({ struct Cyc_StorageClass_tok_struct*
_temp2736=( struct Cyc_StorageClass_tok_struct*) GC_malloc( sizeof( struct Cyc_StorageClass_tok_struct));
_temp2736[ 0]=({ struct Cyc_StorageClass_tok_struct _temp2737; _temp2737.tag=
Cyc_StorageClass_tok; _temp2737.f1=( void*)(( void*) Cyc_Parse_Register_sc);
_temp2737;}); _temp2736;}); break; case 36: _LL2735: yyval=( void*)({ struct Cyc_StorageClass_tok_struct*
_temp2739=( struct Cyc_StorageClass_tok_struct*) GC_malloc( sizeof( struct Cyc_StorageClass_tok_struct));
_temp2739[ 0]=({ struct Cyc_StorageClass_tok_struct _temp2740; _temp2740.tag=
Cyc_StorageClass_tok; _temp2740.f1=( void*)(( void*) Cyc_Parse_Static_sc);
_temp2740;}); _temp2739;}); break; case 37: _LL2738: yyval=( void*)({ struct Cyc_StorageClass_tok_struct*
_temp2742=( struct Cyc_StorageClass_tok_struct*) GC_malloc( sizeof( struct Cyc_StorageClass_tok_struct));
_temp2742[ 0]=({ struct Cyc_StorageClass_tok_struct _temp2743; _temp2743.tag=
Cyc_StorageClass_tok; _temp2743.f1=( void*)(( void*) Cyc_Parse_Extern_sc);
_temp2743;}); _temp2742;}); break; case 38: _LL2741: if( Cyc_String_strcmp( Cyc_yyget_String_tok(({
struct _tagged_ptr2 _temp2745= yyvs; void** _temp2747= _temp2745.curr +
yyvsp_offset; if( _temp2745.base == 0? 1:( _temp2747 < _temp2745.base? 1:
_temp2747 >= _temp2745.last_plus_one)){ _throw( Null_Exception);}* _temp2747;})),(
struct _tagged_string)({ char* _temp2748=( char*)"C"; struct _tagged_string
_temp2749; _temp2749.curr= _temp2748; _temp2749.base= _temp2748; _temp2749.last_plus_one=
_temp2748 + 2; _temp2749;})) != 0){ Cyc_Parse_err(( struct _tagged_string)({
char* _temp2750=( char*)"only extern or extern \"C\" is allowed"; struct
_tagged_string _temp2751; _temp2751.curr= _temp2750; _temp2751.base= _temp2750;
_temp2751.last_plus_one= _temp2750 + 37; _temp2751;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2752= yyls; struct Cyc_Yyltype* _temp2754= _temp2752.curr
+( yylsp_offset - 1); if( _temp2752.base == 0? 1:( _temp2754 < _temp2752.base? 1:
_temp2754 >= _temp2752.last_plus_one)){ _throw( Null_Exception);}* _temp2754;}).first_line,({
struct _tagged_ptr3 _temp2755= yyls; struct Cyc_Yyltype* _temp2757= _temp2755.curr
+ yylsp_offset; if( _temp2755.base == 0? 1:( _temp2757 < _temp2755.base? 1:
_temp2757 >= _temp2755.last_plus_one)){ _throw( Null_Exception);}* _temp2757;}).last_line));}
yyval=( void*)({ struct Cyc_StorageClass_tok_struct* _temp2758=( struct Cyc_StorageClass_tok_struct*)
GC_malloc( sizeof( struct Cyc_StorageClass_tok_struct)); _temp2758[ 0]=({ struct
Cyc_StorageClass_tok_struct _temp2759; _temp2759.tag= Cyc_StorageClass_tok;
_temp2759.f1=( void*)(( void*) Cyc_Parse_ExternC_sc); _temp2759;}); _temp2758;});
break; case 39: _LL2744: yyval=( void*)({ struct Cyc_StorageClass_tok_struct*
_temp2761=( struct Cyc_StorageClass_tok_struct*) GC_malloc( sizeof( struct Cyc_StorageClass_tok_struct));
_temp2761[ 0]=({ struct Cyc_StorageClass_tok_struct _temp2762; _temp2762.tag=
Cyc_StorageClass_tok; _temp2762.f1=( void*)(( void*) Cyc_Parse_Typedef_sc);
_temp2762;}); _temp2761;}); break; case 40: _LL2760: yyval=( void*)({ struct Cyc_StorageClass_tok_struct*
_temp2764=( struct Cyc_StorageClass_tok_struct*) GC_malloc( sizeof( struct Cyc_StorageClass_tok_struct));
_temp2764[ 0]=({ struct Cyc_StorageClass_tok_struct _temp2765; _temp2765.tag=
Cyc_StorageClass_tok; _temp2765.f1=( void*)(( void*) Cyc_Parse_Abstract_sc);
_temp2765;}); _temp2764;}); break; case 41: _LL2763: yyval=( void*)({ struct Cyc_AttributeList_tok_struct*
_temp2767=( struct Cyc_AttributeList_tok_struct*) GC_malloc( sizeof( struct Cyc_AttributeList_tok_struct));
_temp2767[ 0]=({ struct Cyc_AttributeList_tok_struct _temp2768; _temp2768.tag=
Cyc_AttributeList_tok; _temp2768.f1= 0; _temp2768;}); _temp2767;}); break; case
42: _LL2766: yyval=({ struct _tagged_ptr2 _temp2770= yyvs; void** _temp2772=
_temp2770.curr + yyvsp_offset; if( _temp2770.base == 0? 1:( _temp2772 <
_temp2770.base? 1: _temp2772 >= _temp2770.last_plus_one)){ _throw(
Null_Exception);}* _temp2772;}); break; case 43: _LL2769: yyval=( void*)({
struct Cyc_AttributeList_tok_struct* _temp2774=( struct Cyc_AttributeList_tok_struct*)
GC_malloc( sizeof( struct Cyc_AttributeList_tok_struct)); _temp2774[ 0]=({
struct Cyc_AttributeList_tok_struct _temp2775; _temp2775.tag= Cyc_AttributeList_tok;
_temp2775.f1= Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp2776= yyvs;
void** _temp2778= _temp2776.curr +( yyvsp_offset - 2); if( _temp2776.base == 0?
1:( _temp2778 < _temp2776.base? 1: _temp2778 >= _temp2776.last_plus_one)){
_throw( Null_Exception);}* _temp2778;})); _temp2775;}); _temp2774;}); break;
case 44: _LL2773: yyval=( void*)({ struct Cyc_AttributeList_tok_struct*
_temp2780=( struct Cyc_AttributeList_tok_struct*) GC_malloc( sizeof( struct Cyc_AttributeList_tok_struct));
_temp2780[ 0]=({ struct Cyc_AttributeList_tok_struct _temp2781; _temp2781.tag=
Cyc_AttributeList_tok; _temp2781.f1=({ struct Cyc_List_List* _temp2782=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp2782->hd=( void*)
Cyc_yyget_Attribute_tok(({ struct _tagged_ptr2 _temp2783= yyvs; void** _temp2785=
_temp2783.curr + yyvsp_offset; if( _temp2783.base == 0? 1:( _temp2785 <
_temp2783.base? 1: _temp2785 >= _temp2783.last_plus_one)){ _throw(
Null_Exception);}* _temp2785;})); _temp2782->tl= 0; _temp2782;}); _temp2781;});
_temp2780;}); break; case 45: _LL2779: yyval=( void*)({ struct Cyc_AttributeList_tok_struct*
_temp2787=( struct Cyc_AttributeList_tok_struct*) GC_malloc( sizeof( struct Cyc_AttributeList_tok_struct));
_temp2787[ 0]=({ struct Cyc_AttributeList_tok_struct _temp2788; _temp2788.tag=
Cyc_AttributeList_tok; _temp2788.f1=({ struct Cyc_List_List* _temp2789=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp2789->hd=( void*)
Cyc_yyget_Attribute_tok(({ struct _tagged_ptr2 _temp2793= yyvs; void** _temp2795=
_temp2793.curr +( yyvsp_offset - 2); if( _temp2793.base == 0? 1:( _temp2795 <
_temp2793.base? 1: _temp2795 >= _temp2793.last_plus_one)){ _throw(
Null_Exception);}* _temp2795;})); _temp2789->tl= Cyc_yyget_AttributeList_tok(({
struct _tagged_ptr2 _temp2790= yyvs; void** _temp2792= _temp2790.curr +
yyvsp_offset; if( _temp2790.base == 0? 1:( _temp2792 < _temp2790.base? 1:
_temp2792 >= _temp2790.last_plus_one)){ _throw( Null_Exception);}* _temp2792;}));
_temp2789;}); _temp2788;}); _temp2787;}); break; case 46: _LL2786: { struct
_tagged_string s= Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp2871= yyvs;
void** _temp2873= _temp2871.curr + yyvsp_offset; if( _temp2871.base == 0? 1:(
_temp2873 < _temp2871.base? 1: _temp2873 >= _temp2871.last_plus_one)){ _throw(
Null_Exception);}* _temp2873;})); void* a; if( Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2797=( char*)"stdcall"; struct _tagged_string
_temp2798; _temp2798.curr= _temp2797; _temp2798.base= _temp2797; _temp2798.last_plus_one=
_temp2797 + 8; _temp2798;})) == 0? 1: Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2799=( char*)"__stdcall__"; struct _tagged_string
_temp2800; _temp2800.curr= _temp2799; _temp2800.base= _temp2799; _temp2800.last_plus_one=
_temp2799 + 12; _temp2800;})) == 0){ a=( void*) Cyc_Absyn_Stdcall_att;} else{
if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2801=( char*)"cdecl";
struct _tagged_string _temp2802; _temp2802.curr= _temp2801; _temp2802.base=
_temp2801; _temp2802.last_plus_one= _temp2801 + 6; _temp2802;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2803=( char*)"__cdecl__"; struct
_tagged_string _temp2804; _temp2804.curr= _temp2803; _temp2804.base= _temp2803;
_temp2804.last_plus_one= _temp2803 + 10; _temp2804;})) == 0){ a=( void*) Cyc_Absyn_Cdecl_att;}
else{ if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2805=(
char*)"noreturn"; struct _tagged_string _temp2806; _temp2806.curr= _temp2805;
_temp2806.base= _temp2805; _temp2806.last_plus_one= _temp2805 + 9; _temp2806;}))
== 0? 1: Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2807=( char*)"__noreturn__";
struct _tagged_string _temp2808; _temp2808.curr= _temp2807; _temp2808.base=
_temp2807; _temp2808.last_plus_one= _temp2807 + 13; _temp2808;})) == 0){ a=(
void*) Cyc_Absyn_Noreturn_att;} else{ if( Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2809=( char*)"noreturn"; struct _tagged_string
_temp2810; _temp2810.curr= _temp2809; _temp2810.base= _temp2809; _temp2810.last_plus_one=
_temp2809 + 9; _temp2810;})) == 0? 1: Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2811=( char*)"__noreturn__"; struct _tagged_string
_temp2812; _temp2812.curr= _temp2811; _temp2812.base= _temp2811; _temp2812.last_plus_one=
_temp2811 + 13; _temp2812;})) == 0){ a=( void*) Cyc_Absyn_Noreturn_att;} else{
if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2813=( char*)"__const__";
struct _tagged_string _temp2814; _temp2814.curr= _temp2813; _temp2814.base=
_temp2813; _temp2814.last_plus_one= _temp2813 + 10; _temp2814;})) == 0){ a=(
void*) Cyc_Absyn_Const_att;} else{ if( Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2815=( char*)"aligned"; struct _tagged_string
_temp2816; _temp2816.curr= _temp2815; _temp2816.base= _temp2815; _temp2816.last_plus_one=
_temp2815 + 8; _temp2816;})) == 0? 1: Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2817=( char*)"__aligned__"; struct _tagged_string
_temp2818; _temp2818.curr= _temp2817; _temp2818.base= _temp2817; _temp2818.last_plus_one=
_temp2817 + 12; _temp2818;})) == 0){ a=( void*)({ struct Cyc_Absyn_Aligned_att_struct*
_temp2819=( struct Cyc_Absyn_Aligned_att_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Aligned_att_struct));
_temp2819[ 0]=({ struct Cyc_Absyn_Aligned_att_struct _temp2820; _temp2820.tag=
Cyc_Absyn_Aligned_att; _temp2820.f1= - 1; _temp2820;}); _temp2819;});} else{ if(
Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2821=( char*)"packed";
struct _tagged_string _temp2822; _temp2822.curr= _temp2821; _temp2822.base=
_temp2821; _temp2822.last_plus_one= _temp2821 + 7; _temp2822;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2823=( char*)"__packed__"; struct
_tagged_string _temp2824; _temp2824.curr= _temp2823; _temp2824.base= _temp2823;
_temp2824.last_plus_one= _temp2823 + 11; _temp2824;})) == 0){ a=( void*) Cyc_Absyn_Packed_att;}
else{ if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2825=(
char*)"shared"; struct _tagged_string _temp2826; _temp2826.curr= _temp2825;
_temp2826.base= _temp2825; _temp2826.last_plus_one= _temp2825 + 7; _temp2826;}))
== 0? 1: Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2827=( char*)"__shared__";
struct _tagged_string _temp2828; _temp2828.curr= _temp2827; _temp2828.base=
_temp2827; _temp2828.last_plus_one= _temp2827 + 11; _temp2828;})) == 0){ a=(
void*) Cyc_Absyn_Shared_att;} else{ if( Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2829=( char*)"unused"; struct _tagged_string
_temp2830; _temp2830.curr= _temp2829; _temp2830.base= _temp2829; _temp2830.last_plus_one=
_temp2829 + 7; _temp2830;})) == 0? 1: Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2831=( char*)"__unused__"; struct _tagged_string
_temp2832; _temp2832.curr= _temp2831; _temp2832.base= _temp2831; _temp2832.last_plus_one=
_temp2831 + 11; _temp2832;})) == 0){ a=( void*) Cyc_Absyn_Unused_att;} else{ if(
Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2833=( char*)"weak";
struct _tagged_string _temp2834; _temp2834.curr= _temp2833; _temp2834.base=
_temp2833; _temp2834.last_plus_one= _temp2833 + 5; _temp2834;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2835=( char*)"__weak__"; struct
_tagged_string _temp2836; _temp2836.curr= _temp2835; _temp2836.base= _temp2835;
_temp2836.last_plus_one= _temp2835 + 9; _temp2836;})) == 0){ a=( void*) Cyc_Absyn_Weak_att;}
else{ if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2837=(
char*)"dllimport"; struct _tagged_string _temp2838; _temp2838.curr= _temp2837;
_temp2838.base= _temp2837; _temp2838.last_plus_one= _temp2837 + 10; _temp2838;}))
== 0? 1: Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2839=( char*)"__dllimport__";
struct _tagged_string _temp2840; _temp2840.curr= _temp2839; _temp2840.base=
_temp2839; _temp2840.last_plus_one= _temp2839 + 14; _temp2840;})) == 0){ a=(
void*) Cyc_Absyn_Dllimport_att;} else{ if( Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2841=( char*)"dllexport"; struct _tagged_string
_temp2842; _temp2842.curr= _temp2841; _temp2842.base= _temp2841; _temp2842.last_plus_one=
_temp2841 + 10; _temp2842;})) == 0? 1: Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2843=( char*)"__dllexport__"; struct _tagged_string
_temp2844; _temp2844.curr= _temp2843; _temp2844.base= _temp2843; _temp2844.last_plus_one=
_temp2843 + 14; _temp2844;})) == 0){ a=( void*) Cyc_Absyn_Dllexport_att;} else{
if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2845=( char*)"no_instrument_function";
struct _tagged_string _temp2846; _temp2846.curr= _temp2845; _temp2846.base=
_temp2845; _temp2846.last_plus_one= _temp2845 + 23; _temp2846;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2847=( char*)"__no_instrument_function__";
struct _tagged_string _temp2848; _temp2848.curr= _temp2847; _temp2848.base=
_temp2847; _temp2848.last_plus_one= _temp2847 + 27; _temp2848;})) == 0){ a=(
void*) Cyc_Absyn_No_instrument_function_att;} else{ if( Cyc_String_zstrcmp( s,(
struct _tagged_string)({ char* _temp2849=( char*)"constructor"; struct
_tagged_string _temp2850; _temp2850.curr= _temp2849; _temp2850.base= _temp2849;
_temp2850.last_plus_one= _temp2849 + 12; _temp2850;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2851=( char*)"__constructor__"; struct
_tagged_string _temp2852; _temp2852.curr= _temp2851; _temp2852.base= _temp2851;
_temp2852.last_plus_one= _temp2851 + 16; _temp2852;})) == 0){ a=( void*) Cyc_Absyn_Constructor_att;}
else{ if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2853=(
char*)"destructor"; struct _tagged_string _temp2854; _temp2854.curr= _temp2853;
_temp2854.base= _temp2853; _temp2854.last_plus_one= _temp2853 + 11; _temp2854;}))
== 0? 1: Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2855=( char*)"__destructor__";
struct _tagged_string _temp2856; _temp2856.curr= _temp2855; _temp2856.base=
_temp2855; _temp2856.last_plus_one= _temp2855 + 15; _temp2856;})) == 0){ a=(
void*) Cyc_Absyn_Destructor_att;} else{ if( Cyc_String_zstrcmp( s,( struct
_tagged_string)({ char* _temp2857=( char*)"no_check_memory_usage"; struct
_tagged_string _temp2858; _temp2858.curr= _temp2857; _temp2858.base= _temp2857;
_temp2858.last_plus_one= _temp2857 + 22; _temp2858;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2859=( char*)"__no_check_memory_usage__";
struct _tagged_string _temp2860; _temp2860.curr= _temp2859; _temp2860.base=
_temp2859; _temp2860.last_plus_one= _temp2859 + 26; _temp2860;})) == 0){ a=(
void*) Cyc_Absyn_No_check_memory_usage_att;} else{ Cyc_Parse_err(( struct
_tagged_string)({ char* _temp2861=( char*)"unrecognized attribute"; struct
_tagged_string _temp2862; _temp2862.curr= _temp2861; _temp2862.base= _temp2861;
_temp2862.last_plus_one= _temp2861 + 23; _temp2862;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2863= yyls; struct Cyc_Yyltype* _temp2865= _temp2863.curr
+ yylsp_offset; if( _temp2863.base == 0? 1:( _temp2865 < _temp2863.base? 1:
_temp2865 >= _temp2863.last_plus_one)){ _throw( Null_Exception);}* _temp2865;}).first_line,({
struct _tagged_ptr3 _temp2866= yyls; struct Cyc_Yyltype* _temp2868= _temp2866.curr
+ yylsp_offset; if( _temp2866.base == 0? 1:( _temp2868 < _temp2866.base? 1:
_temp2868 >= _temp2866.last_plus_one)){ _throw( Null_Exception);}* _temp2868;}).last_line));
a=( void*) Cyc_Absyn_Cdecl_att;}}}}}}}}}}}}}}}} yyval=( void*)({ struct Cyc_Attribute_tok_struct*
_temp2869=( struct Cyc_Attribute_tok_struct*) GC_malloc( sizeof( struct Cyc_Attribute_tok_struct));
_temp2869[ 0]=({ struct Cyc_Attribute_tok_struct _temp2870; _temp2870.tag= Cyc_Attribute_tok;
_temp2870.f1=( void*) a; _temp2870;}); _temp2869;}); break;} case 47: _LL2796:
yyval=( void*)({ struct Cyc_Attribute_tok_struct* _temp2875=( struct Cyc_Attribute_tok_struct*)
GC_malloc( sizeof( struct Cyc_Attribute_tok_struct)); _temp2875[ 0]=({ struct
Cyc_Attribute_tok_struct _temp2876; _temp2876.tag= Cyc_Attribute_tok; _temp2876.f1=(
void*)(( void*) Cyc_Absyn_Const_att); _temp2876;}); _temp2875;}); break; case 48:
_LL2874: { struct _tagged_string s= Cyc_yyget_String_tok(({ struct _tagged_ptr2
_temp2934= yyvs; void** _temp2936= _temp2934.curr +( yyvsp_offset - 3); if(
_temp2934.base == 0? 1:( _temp2936 < _temp2934.base? 1: _temp2936 >= _temp2934.last_plus_one)){
_throw( Null_Exception);}* _temp2936;})); struct _tuple12 _temp2883; int
_temp2884; void* _temp2886; struct _tuple12* _temp2881= Cyc_yyget_Int_tok(({
struct _tagged_ptr2 _temp2878= yyvs; void** _temp2880= _temp2878.curr +(
yyvsp_offset - 1); if( _temp2878.base == 0? 1:( _temp2880 < _temp2878.base? 1:
_temp2880 >= _temp2878.last_plus_one)){ _throw( Null_Exception);}* _temp2880;}));
_temp2883=* _temp2881; _LL2887: _temp2886= _temp2883.f1; goto _LL2885; _LL2885:
_temp2884= _temp2883.f2; goto _LL2882; _LL2882: { void* a; if( Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2888=( char*)"regparm"; struct
_tagged_string _temp2889; _temp2889.curr= _temp2888; _temp2889.base= _temp2888;
_temp2889.last_plus_one= _temp2888 + 8; _temp2889;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2890=( char*)"__regparm__"; struct
_tagged_string _temp2891; _temp2891.curr= _temp2890; _temp2891.base= _temp2890;
_temp2891.last_plus_one= _temp2890 + 12; _temp2891;})) == 0){ if( _temp2884 <= 0?
1: _temp2884 > 3){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp2892=(
char*)"regparm requires value between 1 and 3"; struct _tagged_string _temp2893;
_temp2893.curr= _temp2892; _temp2893.base= _temp2892; _temp2893.last_plus_one=
_temp2892 + 39; _temp2893;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp2894= yyls; struct Cyc_Yyltype* _temp2896= _temp2894.curr +( yylsp_offset -
1); if( _temp2894.base == 0? 1:( _temp2896 < _temp2894.base? 1: _temp2896 >=
_temp2894.last_plus_one)){ _throw( Null_Exception);}* _temp2896;}).first_line,({
struct _tagged_ptr3 _temp2897= yyls; struct Cyc_Yyltype* _temp2899= _temp2897.curr
+( yylsp_offset - 1); if( _temp2897.base == 0? 1:( _temp2899 < _temp2897.base? 1:
_temp2899 >= _temp2897.last_plus_one)){ _throw( Null_Exception);}* _temp2899;}).last_line));}
a=( void*)({ struct Cyc_Absyn_Regparm_att_struct* _temp2900=( struct Cyc_Absyn_Regparm_att_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Regparm_att_struct)); _temp2900[ 0]=({
struct Cyc_Absyn_Regparm_att_struct _temp2901; _temp2901.tag= Cyc_Absyn_Regparm_att;
_temp2901.f1= _temp2884; _temp2901;}); _temp2900;});} else{ if( Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2902=( char*)"aligned"; struct
_tagged_string _temp2903; _temp2903.curr= _temp2902; _temp2903.base= _temp2902;
_temp2903.last_plus_one= _temp2902 + 8; _temp2903;})) == 0? 1: Cyc_String_zstrcmp(
s,( struct _tagged_string)({ char* _temp2904=( char*)"__aligned__"; struct
_tagged_string _temp2905; _temp2905.curr= _temp2904; _temp2905.base= _temp2904;
_temp2905.last_plus_one= _temp2904 + 12; _temp2905;})) == 0){ if( _temp2884 < 0){
Cyc_Parse_err(( struct _tagged_string)({ char* _temp2906=( char*)"aligned requires positive power of two";
struct _tagged_string _temp2907; _temp2907.curr= _temp2906; _temp2907.base=
_temp2906; _temp2907.last_plus_one= _temp2906 + 39; _temp2907;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2908= yyls; struct Cyc_Yyltype* _temp2910= _temp2908.curr
+( yylsp_offset - 1); if( _temp2908.base == 0? 1:( _temp2910 < _temp2908.base? 1:
_temp2910 >= _temp2908.last_plus_one)){ _throw( Null_Exception);}* _temp2910;}).first_line,({
struct _tagged_ptr3 _temp2911= yyls; struct Cyc_Yyltype* _temp2913= _temp2911.curr
+( yylsp_offset - 1); if( _temp2911.base == 0? 1:( _temp2913 < _temp2911.base? 1:
_temp2913 >= _temp2911.last_plus_one)){ _throw( Null_Exception);}* _temp2913;}).last_line));}{
unsigned int j=( unsigned int) _temp2884; for( 0;( j & 1) == 0; j= j >> 1){;} j=
j >> 1; if( j != 0){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp2914=(
char*)"aligned requires positive power of two"; struct _tagged_string _temp2915;
_temp2915.curr= _temp2914; _temp2915.base= _temp2914; _temp2915.last_plus_one=
_temp2914 + 39; _temp2915;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp2916= yyls; struct Cyc_Yyltype* _temp2918= _temp2916.curr +( yylsp_offset -
1); if( _temp2916.base == 0? 1:( _temp2918 < _temp2916.base? 1: _temp2918 >=
_temp2916.last_plus_one)){ _throw( Null_Exception);}* _temp2918;}).first_line,({
struct _tagged_ptr3 _temp2919= yyls; struct Cyc_Yyltype* _temp2921= _temp2919.curr
+( yylsp_offset - 1); if( _temp2919.base == 0? 1:( _temp2921 < _temp2919.base? 1:
_temp2921 >= _temp2919.last_plus_one)){ _throw( Null_Exception);}* _temp2921;}).last_line));}
a=( void*)({ struct Cyc_Absyn_Aligned_att_struct* _temp2922=( struct Cyc_Absyn_Aligned_att_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Aligned_att_struct)); _temp2922[ 0]=({
struct Cyc_Absyn_Aligned_att_struct _temp2923; _temp2923.tag= Cyc_Absyn_Aligned_att;
_temp2923.f1= _temp2884; _temp2923;}); _temp2922;});}} else{ Cyc_Parse_err((
struct _tagged_string)({ char* _temp2924=( char*)"unrecognized attribute";
struct _tagged_string _temp2925; _temp2925.curr= _temp2924; _temp2925.base=
_temp2924; _temp2925.last_plus_one= _temp2924 + 23; _temp2925;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2926= yyls; struct Cyc_Yyltype* _temp2928= _temp2926.curr
+( yylsp_offset - 3); if( _temp2926.base == 0? 1:( _temp2928 < _temp2926.base? 1:
_temp2928 >= _temp2926.last_plus_one)){ _throw( Null_Exception);}* _temp2928;}).first_line,({
struct _tagged_ptr3 _temp2929= yyls; struct Cyc_Yyltype* _temp2931= _temp2929.curr
+( yylsp_offset - 3); if( _temp2929.base == 0? 1:( _temp2931 < _temp2929.base? 1:
_temp2931 >= _temp2929.last_plus_one)){ _throw( Null_Exception);}* _temp2931;}).last_line));
a=( void*) Cyc_Absyn_Cdecl_att;}} yyval=( void*)({ struct Cyc_Attribute_tok_struct*
_temp2932=( struct Cyc_Attribute_tok_struct*) GC_malloc( sizeof( struct Cyc_Attribute_tok_struct));
_temp2932[ 0]=({ struct Cyc_Attribute_tok_struct _temp2933; _temp2933.tag= Cyc_Attribute_tok;
_temp2933.f1=( void*) a; _temp2933;}); _temp2932;}); break;}} case 49: _LL2877: {
struct _tagged_string s= Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp2957=
yyvs; void** _temp2959= _temp2957.curr +( yyvsp_offset - 3); if( _temp2957.base
== 0? 1:( _temp2959 < _temp2957.base? 1: _temp2959 >= _temp2957.last_plus_one)){
_throw( Null_Exception);}* _temp2959;})); struct _tagged_string str= Cyc_yyget_String_tok(({
struct _tagged_ptr2 _temp2954= yyvs; void** _temp2956= _temp2954.curr +(
yyvsp_offset - 1); if( _temp2954.base == 0? 1:( _temp2956 < _temp2954.base? 1:
_temp2956 >= _temp2954.last_plus_one)){ _throw( Null_Exception);}* _temp2956;}));
void* a; if( Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2938=(
char*)"section"; struct _tagged_string _temp2939; _temp2939.curr= _temp2938;
_temp2939.base= _temp2938; _temp2939.last_plus_one= _temp2938 + 8; _temp2939;}))
== 0? 1: Cyc_String_zstrcmp( s,( struct _tagged_string)({ char* _temp2940=( char*)"__section__";
struct _tagged_string _temp2941; _temp2941.curr= _temp2940; _temp2941.base=
_temp2940; _temp2941.last_plus_one= _temp2940 + 12; _temp2941;}))){ a=( void*)({
struct Cyc_Absyn_Section_att_struct* _temp2942=( struct Cyc_Absyn_Section_att_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Section_att_struct)); _temp2942[ 0]=({
struct Cyc_Absyn_Section_att_struct _temp2943; _temp2943.tag= Cyc_Absyn_Section_att;
_temp2943.f1= str; _temp2943;}); _temp2942;});} else{ Cyc_Parse_err(( struct
_tagged_string)({ char* _temp2944=( char*)"unrecognized attribute"; struct
_tagged_string _temp2945; _temp2945.curr= _temp2944; _temp2945.base= _temp2944;
_temp2945.last_plus_one= _temp2944 + 23; _temp2945;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2946= yyls; struct Cyc_Yyltype* _temp2948= _temp2946.curr
+( yylsp_offset - 3); if( _temp2946.base == 0? 1:( _temp2948 < _temp2946.base? 1:
_temp2948 >= _temp2946.last_plus_one)){ _throw( Null_Exception);}* _temp2948;}).first_line,({
struct _tagged_ptr3 _temp2949= yyls; struct Cyc_Yyltype* _temp2951= _temp2949.curr
+( yylsp_offset - 3); if( _temp2949.base == 0? 1:( _temp2951 < _temp2949.base? 1:
_temp2951 >= _temp2949.last_plus_one)){ _throw( Null_Exception);}* _temp2951;}).last_line));
a=( void*) Cyc_Absyn_Cdecl_att;} yyval=( void*)({ struct Cyc_Attribute_tok_struct*
_temp2952=( struct Cyc_Attribute_tok_struct*) GC_malloc( sizeof( struct Cyc_Attribute_tok_struct));
_temp2952[ 0]=({ struct Cyc_Attribute_tok_struct _temp2953; _temp2953.tag= Cyc_Attribute_tok;
_temp2953.f1=( void*) a; _temp2953;}); _temp2952;}); break;} case 50: _LL2937:
yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct* _temp2961=( struct Cyc_TypeSpecifier_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct)); _temp2961[ 0]=({
struct Cyc_TypeSpecifier_tok_struct _temp2962; _temp2962.tag= Cyc_TypeSpecifier_tok;
_temp2962.f1=( void*) Cyc_Parse_type_spec(( void*) Cyc_Absyn_VoidType, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp2963= yyls; struct Cyc_Yyltype* _temp2965= _temp2963.curr
+ yylsp_offset; if( _temp2963.base == 0? 1:( _temp2965 < _temp2963.base? 1:
_temp2965 >= _temp2963.last_plus_one)){ _throw( Null_Exception);}* _temp2965;}).first_line,({
struct _tagged_ptr3 _temp2966= yyls; struct Cyc_Yyltype* _temp2968= _temp2966.curr
+ yylsp_offset; if( _temp2966.base == 0? 1:( _temp2968 < _temp2966.base? 1:
_temp2968 >= _temp2966.last_plus_one)){ _throw( Null_Exception);}* _temp2968;}).last_line));
_temp2962;}); _temp2961;}); break; case 51: _LL2960: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp2970=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp2970[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp2971; _temp2971.tag=
Cyc_TypeSpecifier_tok; _temp2971.f1=( void*) Cyc_Parse_type_spec( Cyc_Absyn_new_evar((
void*) Cyc_Absyn_MemKind), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp2972= yyls; struct Cyc_Yyltype* _temp2974= _temp2972.curr + yylsp_offset;
if( _temp2972.base == 0? 1:( _temp2974 < _temp2972.base? 1: _temp2974 >=
_temp2972.last_plus_one)){ _throw( Null_Exception);}* _temp2974;}).first_line,({
struct _tagged_ptr3 _temp2975= yyls; struct Cyc_Yyltype* _temp2977= _temp2975.curr
+ yylsp_offset; if( _temp2975.base == 0? 1:( _temp2977 < _temp2975.base? 1:
_temp2977 >= _temp2975.last_plus_one)){ _throw( Null_Exception);}* _temp2977;}).last_line));
_temp2971;}); _temp2970;}); break; case 52: _LL2969: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp2979=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp2979[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp2980; _temp2980.tag=
Cyc_TypeSpecifier_tok; _temp2980.f1=( void*) Cyc_Parse_type_spec( Cyc_Absyn_uchar_t,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp2981= yyls; struct Cyc_Yyltype*
_temp2983= _temp2981.curr + yylsp_offset; if( _temp2981.base == 0? 1:( _temp2983
< _temp2981.base? 1: _temp2983 >= _temp2981.last_plus_one)){ _throw(
Null_Exception);}* _temp2983;}).first_line,({ struct _tagged_ptr3 _temp2984=
yyls; struct Cyc_Yyltype* _temp2986= _temp2984.curr + yylsp_offset; if(
_temp2984.base == 0? 1:( _temp2986 < _temp2984.base? 1: _temp2986 >= _temp2984.last_plus_one)){
_throw( Null_Exception);}* _temp2986;}).last_line)); _temp2980;}); _temp2979;});
break; case 53: _LL2978: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp2988=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp2988[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp2989; _temp2989.tag=
Cyc_TypeSpecifier_tok; _temp2989.f1=( void*)(( void*)({ struct Cyc_Parse_Short_spec_struct*
_temp2990=( struct Cyc_Parse_Short_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Short_spec_struct));
_temp2990[ 0]=({ struct Cyc_Parse_Short_spec_struct _temp2991; _temp2991.tag=
Cyc_Parse_Short_spec; _temp2991.f1= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp2992= yyls; struct Cyc_Yyltype* _temp2994= _temp2992.curr +
yylsp_offset; if( _temp2992.base == 0? 1:( _temp2994 < _temp2992.base? 1:
_temp2994 >= _temp2992.last_plus_one)){ _throw( Null_Exception);}* _temp2994;}).first_line,({
struct _tagged_ptr3 _temp2995= yyls; struct Cyc_Yyltype* _temp2997= _temp2995.curr
+ yylsp_offset; if( _temp2995.base == 0? 1:( _temp2997 < _temp2995.base? 1:
_temp2997 >= _temp2995.last_plus_one)){ _throw( Null_Exception);}* _temp2997;}).last_line);
_temp2991;}); _temp2990;})); _temp2989;}); _temp2988;}); break; case 54: _LL2987:
yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct* _temp2999=( struct Cyc_TypeSpecifier_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct)); _temp2999[ 0]=({
struct Cyc_TypeSpecifier_tok_struct _temp3000; _temp3000.tag= Cyc_TypeSpecifier_tok;
_temp3000.f1=( void*) Cyc_Parse_type_spec( Cyc_Absyn_sint_t, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3001= yyls; struct Cyc_Yyltype* _temp3003= _temp3001.curr
+ yylsp_offset; if( _temp3001.base == 0? 1:( _temp3003 < _temp3001.base? 1:
_temp3003 >= _temp3001.last_plus_one)){ _throw( Null_Exception);}* _temp3003;}).first_line,({
struct _tagged_ptr3 _temp3004= yyls; struct Cyc_Yyltype* _temp3006= _temp3004.curr
+ yylsp_offset; if( _temp3004.base == 0? 1:( _temp3006 < _temp3004.base? 1:
_temp3006 >= _temp3004.last_plus_one)){ _throw( Null_Exception);}* _temp3006;}).last_line));
_temp3000;}); _temp2999;}); break; case 55: _LL2998: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3008=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3008[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3009; _temp3009.tag=
Cyc_TypeSpecifier_tok; _temp3009.f1=( void*)(( void*)({ struct Cyc_Parse_Long_spec_struct*
_temp3010=( struct Cyc_Parse_Long_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Long_spec_struct));
_temp3010[ 0]=({ struct Cyc_Parse_Long_spec_struct _temp3011; _temp3011.tag= Cyc_Parse_Long_spec;
_temp3011.f1= Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3012= yyls;
struct Cyc_Yyltype* _temp3014= _temp3012.curr + yylsp_offset; if( _temp3012.base
== 0? 1:( _temp3014 < _temp3012.base? 1: _temp3014 >= _temp3012.last_plus_one)){
_throw( Null_Exception);}* _temp3014;}).first_line,({ struct _tagged_ptr3
_temp3015= yyls; struct Cyc_Yyltype* _temp3017= _temp3015.curr + yylsp_offset;
if( _temp3015.base == 0? 1:( _temp3017 < _temp3015.base? 1: _temp3017 >=
_temp3015.last_plus_one)){ _throw( Null_Exception);}* _temp3017;}).last_line);
_temp3011;}); _temp3010;})); _temp3009;}); _temp3008;}); break; case 56: _LL3007:
yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct* _temp3019=( struct Cyc_TypeSpecifier_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct)); _temp3019[ 0]=({
struct Cyc_TypeSpecifier_tok_struct _temp3020; _temp3020.tag= Cyc_TypeSpecifier_tok;
_temp3020.f1=( void*) Cyc_Parse_type_spec( Cyc_Absyn_float_t, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3021= yyls; struct Cyc_Yyltype* _temp3023= _temp3021.curr
+ yylsp_offset; if( _temp3021.base == 0? 1:( _temp3023 < _temp3021.base? 1:
_temp3023 >= _temp3021.last_plus_one)){ _throw( Null_Exception);}* _temp3023;}).first_line,({
struct _tagged_ptr3 _temp3024= yyls; struct Cyc_Yyltype* _temp3026= _temp3024.curr
+ yylsp_offset; if( _temp3024.base == 0? 1:( _temp3026 < _temp3024.base? 1:
_temp3026 >= _temp3024.last_plus_one)){ _throw( Null_Exception);}* _temp3026;}).last_line));
_temp3020;}); _temp3019;}); break; case 57: _LL3018: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3028=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3028[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3029; _temp3029.tag=
Cyc_TypeSpecifier_tok; _temp3029.f1=( void*) Cyc_Parse_type_spec( Cyc_Absyn_double_t,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3030= yyls; struct Cyc_Yyltype*
_temp3032= _temp3030.curr + yylsp_offset; if( _temp3030.base == 0? 1:( _temp3032
< _temp3030.base? 1: _temp3032 >= _temp3030.last_plus_one)){ _throw(
Null_Exception);}* _temp3032;}).first_line,({ struct _tagged_ptr3 _temp3033=
yyls; struct Cyc_Yyltype* _temp3035= _temp3033.curr + yylsp_offset; if(
_temp3033.base == 0? 1:( _temp3035 < _temp3033.base? 1: _temp3035 >= _temp3033.last_plus_one)){
_throw( Null_Exception);}* _temp3035;}).last_line)); _temp3029;}); _temp3028;});
break; case 58: _LL3027: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3037=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3037[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3038; _temp3038.tag=
Cyc_TypeSpecifier_tok; _temp3038.f1=( void*)(( void*)({ struct Cyc_Parse_Signed_spec_struct*
_temp3039=( struct Cyc_Parse_Signed_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Signed_spec_struct));
_temp3039[ 0]=({ struct Cyc_Parse_Signed_spec_struct _temp3040; _temp3040.tag=
Cyc_Parse_Signed_spec; _temp3040.f1= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3041= yyls; struct Cyc_Yyltype* _temp3043= _temp3041.curr +
yylsp_offset; if( _temp3041.base == 0? 1:( _temp3043 < _temp3041.base? 1:
_temp3043 >= _temp3041.last_plus_one)){ _throw( Null_Exception);}* _temp3043;}).first_line,({
struct _tagged_ptr3 _temp3044= yyls; struct Cyc_Yyltype* _temp3046= _temp3044.curr
+ yylsp_offset; if( _temp3044.base == 0? 1:( _temp3046 < _temp3044.base? 1:
_temp3046 >= _temp3044.last_plus_one)){ _throw( Null_Exception);}* _temp3046;}).last_line);
_temp3040;}); _temp3039;})); _temp3038;}); _temp3037;}); break; case 59: _LL3036:
yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct* _temp3048=( struct Cyc_TypeSpecifier_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct)); _temp3048[ 0]=({
struct Cyc_TypeSpecifier_tok_struct _temp3049; _temp3049.tag= Cyc_TypeSpecifier_tok;
_temp3049.f1=( void*)(( void*)({ struct Cyc_Parse_Unsigned_spec_struct*
_temp3050=( struct Cyc_Parse_Unsigned_spec_struct*) GC_malloc( sizeof( struct
Cyc_Parse_Unsigned_spec_struct)); _temp3050[ 0]=({ struct Cyc_Parse_Unsigned_spec_struct
_temp3051; _temp3051.tag= Cyc_Parse_Unsigned_spec; _temp3051.f1= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3052= yyls; struct Cyc_Yyltype* _temp3054= _temp3052.curr
+ yylsp_offset; if( _temp3052.base == 0? 1:( _temp3054 < _temp3052.base? 1:
_temp3054 >= _temp3052.last_plus_one)){ _throw( Null_Exception);}* _temp3054;}).first_line,({
struct _tagged_ptr3 _temp3055= yyls; struct Cyc_Yyltype* _temp3057= _temp3055.curr
+ yylsp_offset; if( _temp3055.base == 0? 1:( _temp3057 < _temp3055.base? 1:
_temp3057 >= _temp3055.last_plus_one)){ _throw( Null_Exception);}* _temp3057;}).last_line);
_temp3051;}); _temp3050;})); _temp3049;}); _temp3048;}); break; case 60: _LL3047:
yyval=({ struct _tagged_ptr2 _temp3059= yyvs; void** _temp3061= _temp3059.curr +
yyvsp_offset; if( _temp3059.base == 0? 1:( _temp3061 < _temp3059.base? 1:
_temp3061 >= _temp3059.last_plus_one)){ _throw( Null_Exception);}* _temp3061;});
break; case 61: _LL3058: yyval=({ struct _tagged_ptr2 _temp3063= yyvs; void**
_temp3065= _temp3063.curr + yyvsp_offset; if( _temp3063.base == 0? 1:( _temp3065
< _temp3063.base? 1: _temp3065 >= _temp3063.last_plus_one)){ _throw(
Null_Exception);}* _temp3065;}); break; case 62: _LL3062: yyval=({ struct
_tagged_ptr2 _temp3067= yyvs; void** _temp3069= _temp3067.curr + yyvsp_offset;
if( _temp3067.base == 0? 1:( _temp3069 < _temp3067.base? 1: _temp3069 >=
_temp3067.last_plus_one)){ _throw( Null_Exception);}* _temp3069;}); break; case
63: _LL3066: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct* _temp3071=(
struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3071[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3072; _temp3072.tag=
Cyc_TypeSpecifier_tok; _temp3072.f1=( void*) Cyc_Parse_type_spec( Cyc_Parse_id2type(
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp3073= yyvs; void** _temp3075=
_temp3073.curr + yyvsp_offset; if( _temp3073.base == 0? 1:( _temp3075 <
_temp3073.base? 1: _temp3075 >= _temp3073.last_plus_one)){ _throw(
Null_Exception);}* _temp3075;})),(( struct Cyc_Absyn_Conref*(*)()) Cyc_Absyn_empty_conref)()),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3076= yyls; struct Cyc_Yyltype*
_temp3078= _temp3076.curr + yylsp_offset; if( _temp3076.base == 0? 1:( _temp3078
< _temp3076.base? 1: _temp3078 >= _temp3076.last_plus_one)){ _throw(
Null_Exception);}* _temp3078;}).first_line,({ struct _tagged_ptr3 _temp3079=
yyls; struct Cyc_Yyltype* _temp3081= _temp3079.curr + yylsp_offset; if(
_temp3079.base == 0? 1:( _temp3081 < _temp3079.base? 1: _temp3081 >= _temp3079.last_plus_one)){
_throw( Null_Exception);}* _temp3081;}).last_line)); _temp3072;}); _temp3071;});
break; case 64: _LL3070: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3083=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3083[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3084; _temp3084.tag=
Cyc_TypeSpecifier_tok; _temp3084.f1=( void*) Cyc_Parse_type_spec( Cyc_Parse_id2type(
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp3085= yyvs; void** _temp3087=
_temp3085.curr +( yyvsp_offset - 2); if( _temp3085.base == 0? 1:( _temp3087 <
_temp3085.base? 1: _temp3087 >= _temp3085.last_plus_one)){ _throw(
Null_Exception);}* _temp3087;})),(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(
Cyc_yyget_Kind_tok(({ struct _tagged_ptr2 _temp3088= yyvs; void** _temp3090=
_temp3088.curr + yyvsp_offset; if( _temp3088.base == 0? 1:( _temp3090 <
_temp3088.base? 1: _temp3090 >= _temp3088.last_plus_one)){ _throw(
Null_Exception);}* _temp3090;})))), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3091= yyls; struct Cyc_Yyltype* _temp3093= _temp3091.curr +(
yylsp_offset - 2); if( _temp3091.base == 0? 1:( _temp3093 < _temp3091.base? 1:
_temp3093 >= _temp3091.last_plus_one)){ _throw( Null_Exception);}* _temp3093;}).first_line,({
struct _tagged_ptr3 _temp3094= yyls; struct Cyc_Yyltype* _temp3096= _temp3094.curr
+ yylsp_offset; if( _temp3094.base == 0? 1:( _temp3096 < _temp3094.base? 1:
_temp3096 >= _temp3094.last_plus_one)){ _throw( Null_Exception);}* _temp3096;}).last_line));
_temp3084;}); _temp3083;}); break; case 65: _LL3082: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3098=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3098[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3099; _temp3099.tag=
Cyc_TypeSpecifier_tok; _temp3099.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_TypedefType_struct* _temp3100=( struct Cyc_Absyn_TypedefType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TypedefType_struct)); _temp3100[ 0]=({
struct Cyc_Absyn_TypedefType_struct _temp3101; _temp3101.tag= Cyc_Absyn_TypedefType;
_temp3101.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp3102= yyvs; void**
_temp3104= _temp3102.curr +( yyvsp_offset - 1); if( _temp3102.base == 0? 1:(
_temp3104 < _temp3102.base? 1: _temp3104 >= _temp3102.last_plus_one)){ _throw(
Null_Exception);}* _temp3104;})); _temp3101.f2= Cyc_yyget_TypeList_tok(({ struct
_tagged_ptr2 _temp3105= yyvs; void** _temp3107= _temp3105.curr + yyvsp_offset;
if( _temp3105.base == 0? 1:( _temp3107 < _temp3105.base? 1: _temp3107 >=
_temp3105.last_plus_one)){ _throw( Null_Exception);}* _temp3107;})); _temp3101.f3=
0; _temp3101;}); _temp3100;}), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3108= yyls; struct Cyc_Yyltype* _temp3110= _temp3108.curr +(
yylsp_offset - 1); if( _temp3108.base == 0? 1:( _temp3110 < _temp3108.base? 1:
_temp3110 >= _temp3108.last_plus_one)){ _throw( Null_Exception);}* _temp3110;}).first_line,({
struct _tagged_ptr3 _temp3111= yyls; struct Cyc_Yyltype* _temp3113= _temp3111.curr
+ yylsp_offset; if( _temp3111.base == 0? 1:( _temp3113 < _temp3111.base? 1:
_temp3113 >= _temp3111.last_plus_one)){ _throw( Null_Exception);}* _temp3113;}).last_line));
_temp3099;}); _temp3098;}); break; case 66: _LL3097: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3115=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3115[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3116; _temp3116.tag=
Cyc_TypeSpecifier_tok; _temp3116.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_TupleType_struct* _temp3117=( struct Cyc_Absyn_TupleType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TupleType_struct)); _temp3117[ 0]=({ struct
Cyc_Absyn_TupleType_struct _temp3118; _temp3118.tag= Cyc_Absyn_TupleType;
_temp3118.f1=(( struct Cyc_List_List*(*)( struct _tuple10*(* f)( struct Cyc_Position_Segment*,
struct _tuple2*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x))
Cyc_List_map_c)( Cyc_Parse_get_tqual_typ, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3119= yyls; struct Cyc_Yyltype* _temp3121= _temp3119.curr +(
yylsp_offset - 1); if( _temp3119.base == 0? 1:( _temp3121 < _temp3119.base? 1:
_temp3121 >= _temp3119.last_plus_one)){ _throw( Null_Exception);}* _temp3121;}).first_line,({
struct _tagged_ptr3 _temp3122= yyls; struct Cyc_Yyltype* _temp3124= _temp3122.curr
+( yylsp_offset - 1); if( _temp3122.base == 0? 1:( _temp3124 < _temp3122.base? 1:
_temp3124 >= _temp3122.last_plus_one)){ _throw( Null_Exception);}* _temp3124;}).last_line),((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_ParamDeclList_tok(({
struct _tagged_ptr2 _temp3125= yyvs; void** _temp3127= _temp3125.curr +(
yyvsp_offset - 1); if( _temp3125.base == 0? 1:( _temp3127 < _temp3125.base? 1:
_temp3127 >= _temp3125.last_plus_one)){ _throw( Null_Exception);}* _temp3127;}))));
_temp3118;}); _temp3117;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp3128= yyls; struct Cyc_Yyltype* _temp3130= _temp3128.curr +( yylsp_offset -
3); if( _temp3128.base == 0? 1:( _temp3130 < _temp3128.base? 1: _temp3130 >=
_temp3128.last_plus_one)){ _throw( Null_Exception);}* _temp3130;}).first_line,({
struct _tagged_ptr3 _temp3131= yyls; struct Cyc_Yyltype* _temp3133= _temp3131.curr
+ yylsp_offset; if( _temp3131.base == 0? 1:( _temp3133 < _temp3131.base? 1:
_temp3133 >= _temp3131.last_plus_one)){ _throw( Null_Exception);}* _temp3133;}).last_line));
_temp3116;}); _temp3115;}); break; case 67: _LL3114: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3135=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3135[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3136; _temp3136.tag=
Cyc_TypeSpecifier_tok; _temp3136.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_RgnHandleType_struct* _temp3137=( struct Cyc_Absyn_RgnHandleType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_RgnHandleType_struct)); _temp3137[ 0]=({
struct Cyc_Absyn_RgnHandleType_struct _temp3138; _temp3138.tag= Cyc_Absyn_RgnHandleType;
_temp3138.f1=( void*) Cyc_yyget_Type_tok(({ struct _tagged_ptr2 _temp3139= yyvs;
void** _temp3141= _temp3139.curr +( yyvsp_offset - 1); if( _temp3139.base == 0?
1:( _temp3141 < _temp3139.base? 1: _temp3141 >= _temp3139.last_plus_one)){
_throw( Null_Exception);}* _temp3141;})); _temp3138;}); _temp3137;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3142= yyls; struct Cyc_Yyltype* _temp3144= _temp3142.curr
+( yylsp_offset - 3); if( _temp3142.base == 0? 1:( _temp3144 < _temp3142.base? 1:
_temp3144 >= _temp3142.last_plus_one)){ _throw( Null_Exception);}* _temp3144;}).first_line,({
struct _tagged_ptr3 _temp3145= yyls; struct Cyc_Yyltype* _temp3147= _temp3145.curr
+ yylsp_offset; if( _temp3145.base == 0? 1:( _temp3147 < _temp3145.base? 1:
_temp3147 >= _temp3145.last_plus_one)){ _throw( Null_Exception);}* _temp3147;}).last_line));
_temp3136;}); _temp3135;}); break; case 68: _LL3134: yyval=( void*)({ struct Cyc_Kind_tok_struct*
_temp3149=( struct Cyc_Kind_tok_struct*) GC_malloc( sizeof( struct Cyc_Kind_tok_struct));
_temp3149[ 0]=({ struct Cyc_Kind_tok_struct _temp3150; _temp3150.tag= Cyc_Kind_tok;
_temp3150.f1=( void*) Cyc_Parse_id_to_kind( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp3151= yyvs; void** _temp3153= _temp3151.curr + yyvsp_offset;
if( _temp3151.base == 0? 1:( _temp3153 < _temp3151.base? 1: _temp3153 >=
_temp3151.last_plus_one)){ _throw( Null_Exception);}* _temp3153;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3154= yyls; struct Cyc_Yyltype* _temp3156= _temp3154.curr
+ yylsp_offset; if( _temp3154.base == 0? 1:( _temp3156 < _temp3154.base? 1:
_temp3156 >= _temp3154.last_plus_one)){ _throw( Null_Exception);}* _temp3156;}).first_line,({
struct _tagged_ptr3 _temp3157= yyls; struct Cyc_Yyltype* _temp3159= _temp3157.curr
+ yylsp_offset; if( _temp3157.base == 0? 1:( _temp3159 < _temp3157.base? 1:
_temp3159 >= _temp3157.last_plus_one)){ _throw( Null_Exception);}* _temp3159;}).last_line));
_temp3150;}); _temp3149;}); break; case 69: _LL3148: { struct _tagged_string*
_temp3166; void* _temp3168; struct _tuple1 _temp3164=* Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3161= yyvs; void** _temp3163= _temp3161.curr +
yyvsp_offset; if( _temp3161.base == 0? 1:( _temp3163 < _temp3161.base? 1:
_temp3163 >= _temp3161.last_plus_one)){ _throw( Null_Exception);}* _temp3163;}));
_LL3169: _temp3168= _temp3164.f1; goto _LL3167; _LL3167: _temp3166= _temp3164.f2;
goto _LL3165; _LL3165: if( _temp3168 !=( void*) Cyc_Absyn_Loc_n){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp3170=( char*)"bad kind in type specifier";
struct _tagged_string _temp3171; _temp3171.curr= _temp3170; _temp3171.base=
_temp3170; _temp3171.last_plus_one= _temp3170 + 27; _temp3171;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3172= yyls; struct Cyc_Yyltype* _temp3174= _temp3172.curr
+ yylsp_offset; if( _temp3172.base == 0? 1:( _temp3174 < _temp3172.base? 1:
_temp3174 >= _temp3172.last_plus_one)){ _throw( Null_Exception);}* _temp3174;}).first_line,({
struct _tagged_ptr3 _temp3175= yyls; struct Cyc_Yyltype* _temp3177= _temp3175.curr
+ yylsp_offset; if( _temp3175.base == 0? 1:( _temp3177 < _temp3175.base? 1:
_temp3177 >= _temp3175.last_plus_one)){ _throw( Null_Exception);}* _temp3177;}).last_line));}
yyval=( void*)({ struct Cyc_Kind_tok_struct* _temp3178=( struct Cyc_Kind_tok_struct*)
GC_malloc( sizeof( struct Cyc_Kind_tok_struct)); _temp3178[ 0]=({ struct Cyc_Kind_tok_struct
_temp3179; _temp3179.tag= Cyc_Kind_tok; _temp3179.f1=( void*) Cyc_Parse_id_to_kind(*
_temp3166, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3180= yyls;
struct Cyc_Yyltype* _temp3182= _temp3180.curr + yylsp_offset; if( _temp3180.base
== 0? 1:( _temp3182 < _temp3180.base? 1: _temp3182 >= _temp3180.last_plus_one)){
_throw( Null_Exception);}* _temp3182;}).first_line,({ struct _tagged_ptr3
_temp3183= yyls; struct Cyc_Yyltype* _temp3185= _temp3183.curr + yylsp_offset;
if( _temp3183.base == 0? 1:( _temp3185 < _temp3183.base? 1: _temp3185 >=
_temp3183.last_plus_one)){ _throw( Null_Exception);}* _temp3185;}).last_line));
_temp3179;}); _temp3178;}); break;} case 70: _LL3160: yyval=( void*)({ struct
Cyc_TypeQual_tok_struct* _temp3187=( struct Cyc_TypeQual_tok_struct*) GC_malloc(
sizeof( struct Cyc_TypeQual_tok_struct)); _temp3187[ 0]=({ struct Cyc_TypeQual_tok_struct
_temp3188; _temp3188.tag= Cyc_TypeQual_tok; _temp3188.f1=({ struct Cyc_Absyn_Tqual
_temp3189; _temp3189.q_const= 1; _temp3189.q_volatile= 0; _temp3189.q_restrict=
0; _temp3189;}); _temp3188;}); _temp3187;}); break; case 71: _LL3186: yyval=(
void*)({ struct Cyc_TypeQual_tok_struct* _temp3191=( struct Cyc_TypeQual_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeQual_tok_struct)); _temp3191[ 0]=({ struct Cyc_TypeQual_tok_struct
_temp3192; _temp3192.tag= Cyc_TypeQual_tok; _temp3192.f1=({ struct Cyc_Absyn_Tqual
_temp3193; _temp3193.q_const= 0; _temp3193.q_volatile= 1; _temp3193.q_restrict=
0; _temp3193;}); _temp3192;}); _temp3191;}); break; case 72: _LL3190: yyval=(
void*)({ struct Cyc_TypeQual_tok_struct* _temp3195=( struct Cyc_TypeQual_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeQual_tok_struct)); _temp3195[ 0]=({ struct Cyc_TypeQual_tok_struct
_temp3196; _temp3196.tag= Cyc_TypeQual_tok; _temp3196.f1=({ struct Cyc_Absyn_Tqual
_temp3197; _temp3197.q_const= 0; _temp3197.q_volatile= 0; _temp3197.q_restrict=
1; _temp3197;}); _temp3196;}); _temp3195;}); break; case 73: _LL3194: yyval=(
void*)({ struct Cyc_TypeSpecifier_tok_struct* _temp3199=( struct Cyc_TypeSpecifier_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct)); _temp3199[ 0]=({
struct Cyc_TypeSpecifier_tok_struct _temp3200; _temp3200.tag= Cyc_TypeSpecifier_tok;
_temp3200.f1=( void*)(( void*)({ struct Cyc_Parse_Decl_spec_struct* _temp3201=(
struct Cyc_Parse_Decl_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Decl_spec_struct));
_temp3201[ 0]=({ struct Cyc_Parse_Decl_spec_struct _temp3202; _temp3202.tag= Cyc_Parse_Decl_spec;
_temp3202.f1=({ struct Cyc_Absyn_Decl* _temp3203=( struct Cyc_Absyn_Decl*)
GC_malloc( sizeof( struct Cyc_Absyn_Decl)); _temp3203->r=( void*)(( void*)({
struct Cyc_Absyn_Enum_d_struct* _temp3210=( struct Cyc_Absyn_Enum_d_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Enum_d_struct)); _temp3210[ 0]=({ struct Cyc_Absyn_Enum_d_struct
_temp3211; _temp3211.tag= Cyc_Absyn_Enum_d; _temp3211.f1=({ struct Cyc_Absyn_Enumdecl*
_temp3212=( struct Cyc_Absyn_Enumdecl*) GC_malloc( sizeof( struct Cyc_Absyn_Enumdecl));
_temp3212->sc=( void*)(( void*) Cyc_Absyn_Public); _temp3212->name= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3216= yyvs; void** _temp3218= _temp3216.curr +(
yyvsp_offset - 3); if( _temp3216.base == 0? 1:( _temp3218 < _temp3216.base? 1:
_temp3218 >= _temp3216.last_plus_one)){ _throw( Null_Exception);}* _temp3218;}));
_temp3212->fields= Cyc_yyget_EnumfieldList_tok(({ struct _tagged_ptr2 _temp3213=
yyvs; void** _temp3215= _temp3213.curr +( yyvsp_offset - 1); if( _temp3213.base
== 0? 1:( _temp3215 < _temp3213.base? 1: _temp3215 >= _temp3213.last_plus_one)){
_throw( Null_Exception);}* _temp3215;})); _temp3212;}); _temp3211;}); _temp3210;}));
_temp3203->loc= Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3204=
yyls; struct Cyc_Yyltype* _temp3206= _temp3204.curr +( yylsp_offset - 4); if(
_temp3204.base == 0? 1:( _temp3206 < _temp3204.base? 1: _temp3206 >= _temp3204.last_plus_one)){
_throw( Null_Exception);}* _temp3206;}).first_line,({ struct _tagged_ptr3
_temp3207= yyls; struct Cyc_Yyltype* _temp3209= _temp3207.curr + yylsp_offset;
if( _temp3207.base == 0? 1:( _temp3209 < _temp3207.base? 1: _temp3209 >=
_temp3207.last_plus_one)){ _throw( Null_Exception);}* _temp3209;}).last_line);
_temp3203;}); _temp3202;}); _temp3201;})); _temp3200;}); _temp3199;}); break;
case 74: _LL3198: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3220=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3220[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3221; _temp3221.tag=
Cyc_TypeSpecifier_tok; _temp3221.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_EnumType_struct* _temp3222=( struct Cyc_Absyn_EnumType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_EnumType_struct)); _temp3222[ 0]=({ struct
Cyc_Absyn_EnumType_struct _temp3223; _temp3223.tag= Cyc_Absyn_EnumType;
_temp3223.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp3224= yyvs; void**
_temp3226= _temp3224.curr + yyvsp_offset; if( _temp3224.base == 0? 1:( _temp3226
< _temp3224.base? 1: _temp3226 >= _temp3224.last_plus_one)){ _throw(
Null_Exception);}* _temp3226;})); _temp3223.f2= 0; _temp3223;}); _temp3222;}),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3227= yyls; struct Cyc_Yyltype*
_temp3229= _temp3227.curr +( yylsp_offset - 1); if( _temp3227.base == 0? 1:(
_temp3229 < _temp3227.base? 1: _temp3229 >= _temp3227.last_plus_one)){ _throw(
Null_Exception);}* _temp3229;}).first_line,({ struct _tagged_ptr3 _temp3230=
yyls; struct Cyc_Yyltype* _temp3232= _temp3230.curr + yylsp_offset; if(
_temp3230.base == 0? 1:( _temp3232 < _temp3230.base? 1: _temp3232 >= _temp3230.last_plus_one)){
_throw( Null_Exception);}* _temp3232;}).last_line)); _temp3221;}); _temp3220;});
break; case 75: _LL3219: yyval=( void*)({ struct Cyc_Enumfield_tok_struct*
_temp3234=( struct Cyc_Enumfield_tok_struct*) GC_malloc( sizeof( struct Cyc_Enumfield_tok_struct));
_temp3234[ 0]=({ struct Cyc_Enumfield_tok_struct _temp3235; _temp3235.tag= Cyc_Enumfield_tok;
_temp3235.f1=({ struct Cyc_Absyn_Enumfield* _temp3236=( struct Cyc_Absyn_Enumfield*)
GC_malloc( sizeof( struct Cyc_Absyn_Enumfield)); _temp3236->name= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3243= yyvs; void** _temp3245= _temp3243.curr +
yyvsp_offset; if( _temp3243.base == 0? 1:( _temp3245 < _temp3243.base? 1:
_temp3245 >= _temp3243.last_plus_one)){ _throw( Null_Exception);}* _temp3245;}));
_temp3236->tag= 0; _temp3236->loc= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3237= yyls; struct Cyc_Yyltype* _temp3239= _temp3237.curr +
yylsp_offset; if( _temp3237.base == 0? 1:( _temp3239 < _temp3237.base? 1:
_temp3239 >= _temp3237.last_plus_one)){ _throw( Null_Exception);}* _temp3239;}).first_line,({
struct _tagged_ptr3 _temp3240= yyls; struct Cyc_Yyltype* _temp3242= _temp3240.curr
+ yylsp_offset; if( _temp3240.base == 0? 1:( _temp3242 < _temp3240.base? 1:
_temp3242 >= _temp3240.last_plus_one)){ _throw( Null_Exception);}* _temp3242;}).last_line);
_temp3236;}); _temp3235;}); _temp3234;}); break; case 76: _LL3233: yyval=( void*)({
struct Cyc_Enumfield_tok_struct* _temp3247=( struct Cyc_Enumfield_tok_struct*)
GC_malloc( sizeof( struct Cyc_Enumfield_tok_struct)); _temp3247[ 0]=({ struct
Cyc_Enumfield_tok_struct _temp3248; _temp3248.tag= Cyc_Enumfield_tok; _temp3248.f1=({
struct Cyc_Absyn_Enumfield* _temp3249=( struct Cyc_Absyn_Enumfield*) GC_malloc(
sizeof( struct Cyc_Absyn_Enumfield)); _temp3249->name= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3259= yyvs; void** _temp3261= _temp3259.curr +(
yyvsp_offset - 2); if( _temp3259.base == 0? 1:( _temp3261 < _temp3259.base? 1:
_temp3261 >= _temp3259.last_plus_one)){ _throw( Null_Exception);}* _temp3261;}));
_temp3249->tag=( struct Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp3256= yyvs; void** _temp3258= _temp3256.curr + yyvsp_offset; if( _temp3256.base
== 0? 1:( _temp3258 < _temp3256.base? 1: _temp3258 >= _temp3256.last_plus_one)){
_throw( Null_Exception);}* _temp3258;})); _temp3249->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3250= yyls; struct Cyc_Yyltype* _temp3252= _temp3250.curr
+( yylsp_offset - 2); if( _temp3250.base == 0? 1:( _temp3252 < _temp3250.base? 1:
_temp3252 >= _temp3250.last_plus_one)){ _throw( Null_Exception);}* _temp3252;}).first_line,({
struct _tagged_ptr3 _temp3253= yyls; struct Cyc_Yyltype* _temp3255= _temp3253.curr
+ yylsp_offset; if( _temp3253.base == 0? 1:( _temp3255 < _temp3253.base? 1:
_temp3255 >= _temp3253.last_plus_one)){ _throw( Null_Exception);}* _temp3255;}).last_line);
_temp3249;}); _temp3248;}); _temp3247;}); break; case 77: _LL3246: yyval=( void*)({
struct Cyc_EnumfieldList_tok_struct* _temp3263=( struct Cyc_EnumfieldList_tok_struct*)
GC_malloc( sizeof( struct Cyc_EnumfieldList_tok_struct)); _temp3263[ 0]=({
struct Cyc_EnumfieldList_tok_struct _temp3264; _temp3264.tag= Cyc_EnumfieldList_tok;
_temp3264.f1=({ struct Cyc_List_List* _temp3265=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp3265->hd=( void*) Cyc_yyget_Enumfield_tok(({
struct _tagged_ptr2 _temp3266= yyvs; void** _temp3268= _temp3266.curr +
yyvsp_offset; if( _temp3266.base == 0? 1:( _temp3268 < _temp3266.base? 1:
_temp3268 >= _temp3266.last_plus_one)){ _throw( Null_Exception);}* _temp3268;}));
_temp3265->tl= 0; _temp3265;}); _temp3264;}); _temp3263;}); break; case 78:
_LL3262: yyval=( void*)({ struct Cyc_EnumfieldList_tok_struct* _temp3270=(
struct Cyc_EnumfieldList_tok_struct*) GC_malloc( sizeof( struct Cyc_EnumfieldList_tok_struct));
_temp3270[ 0]=({ struct Cyc_EnumfieldList_tok_struct _temp3271; _temp3271.tag=
Cyc_EnumfieldList_tok; _temp3271.f1=({ struct Cyc_List_List* _temp3272=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp3272->hd=( void*)
Cyc_yyget_Enumfield_tok(({ struct _tagged_ptr2 _temp3276= yyvs; void** _temp3278=
_temp3276.curr +( yyvsp_offset - 2); if( _temp3276.base == 0? 1:( _temp3278 <
_temp3276.base? 1: _temp3278 >= _temp3276.last_plus_one)){ _throw(
Null_Exception);}* _temp3278;})); _temp3272->tl= Cyc_yyget_EnumfieldList_tok(({
struct _tagged_ptr2 _temp3273= yyvs; void** _temp3275= _temp3273.curr +
yyvsp_offset; if( _temp3273.base == 0? 1:( _temp3275 < _temp3273.base? 1:
_temp3275 >= _temp3273.last_plus_one)){ _throw( Null_Exception);}* _temp3275;}));
_temp3272;}); _temp3271;}); _temp3270;}); break; case 79: _LL3269: { void* t;{
void* _temp3283= Cyc_yyget_StructOrUnion_tok(({ struct _tagged_ptr2 _temp3280=
yyvs; void** _temp3282= _temp3280.curr +( yyvsp_offset - 3); if( _temp3280.base
== 0? 1:( _temp3282 < _temp3280.base? 1: _temp3282 >= _temp3280.last_plus_one)){
_throw( Null_Exception);}* _temp3282;})); _LL3285: if( _temp3283 ==( void*) Cyc_Parse_Struct_su){
goto _LL3286;} else{ goto _LL3287;} _LL3287: if( _temp3283 ==( void*) Cyc_Parse_Union_su){
goto _LL3288;} else{ goto _LL3284;} _LL3286: t=( void*)({ struct Cyc_Absyn_AnonStructType_struct*
_temp3289=( struct Cyc_Absyn_AnonStructType_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_AnonStructType_struct)); _temp3289[ 0]=({ struct Cyc_Absyn_AnonStructType_struct
_temp3290; _temp3290.tag= Cyc_Absyn_AnonStructType; _temp3290.f1= Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3291= yyvs; void** _temp3293= _temp3291.curr +(
yyvsp_offset - 1); if( _temp3291.base == 0? 1:( _temp3293 < _temp3291.base? 1:
_temp3293 >= _temp3291.last_plus_one)){ _throw( Null_Exception);}* _temp3293;}));
_temp3290;}); _temp3289;}); goto _LL3284; _LL3288: t=( void*)({ struct Cyc_Absyn_AnonUnionType_struct*
_temp3294=( struct Cyc_Absyn_AnonUnionType_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_AnonUnionType_struct)); _temp3294[ 0]=({ struct Cyc_Absyn_AnonUnionType_struct
_temp3295; _temp3295.tag= Cyc_Absyn_AnonUnionType; _temp3295.f1= Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3296= yyvs; void** _temp3298= _temp3296.curr +(
yyvsp_offset - 1); if( _temp3296.base == 0? 1:( _temp3298 < _temp3296.base? 1:
_temp3298 >= _temp3296.last_plus_one)){ _throw( Null_Exception);}* _temp3298;}));
_temp3295;}); _temp3294;}); goto _LL3284; _LL3284:;} yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3299=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3299[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3300; _temp3300.tag=
Cyc_TypeSpecifier_tok; _temp3300.f1=( void*)(( void*)({ struct Cyc_Parse_Type_spec_struct*
_temp3301=( struct Cyc_Parse_Type_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Type_spec_struct));
_temp3301[ 0]=({ struct Cyc_Parse_Type_spec_struct _temp3302; _temp3302.tag= Cyc_Parse_Type_spec;
_temp3302.f1=( void*) t; _temp3302.f2= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3303= yyls; struct Cyc_Yyltype* _temp3305= _temp3303.curr +(
yylsp_offset - 3); if( _temp3303.base == 0? 1:( _temp3305 < _temp3303.base? 1:
_temp3305 >= _temp3303.last_plus_one)){ _throw( Null_Exception);}* _temp3305;}).first_line,({
struct _tagged_ptr3 _temp3306= yyls; struct Cyc_Yyltype* _temp3308= _temp3306.curr
+ yylsp_offset; if( _temp3306.base == 0? 1:( _temp3308 < _temp3306.base? 1:
_temp3308 >= _temp3306.last_plus_one)){ _throw( Null_Exception);}* _temp3308;}).last_line);
_temp3302;}); _temp3301;})); _temp3300;}); _temp3299;}); break;} case 80:
_LL3279: { struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(*
f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment* env,
struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3351= yyls; struct Cyc_Yyltype* _temp3353= _temp3351.curr
+( yylsp_offset - 3); if( _temp3351.base == 0? 1:( _temp3353 < _temp3351.base? 1:
_temp3353 >= _temp3351.last_plus_one)){ _throw( Null_Exception);}* _temp3353;}).first_line,({
struct _tagged_ptr3 _temp3354= yyls; struct Cyc_Yyltype* _temp3356= _temp3354.curr
+( yylsp_offset - 3); if( _temp3354.base == 0? 1:( _temp3356 < _temp3354.base? 1:
_temp3356 >= _temp3354.last_plus_one)){ _throw( Null_Exception);}* _temp3356;}).last_line),
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp3357= yyvs; void** _temp3359=
_temp3357.curr +( yyvsp_offset - 3); if( _temp3357.base == 0? 1:( _temp3359 <
_temp3357.base? 1: _temp3359 >= _temp3357.last_plus_one)){ _throw(
Null_Exception);}* _temp3359;}))); struct Cyc_Absyn_Decl* d;{ void* _temp3313=
Cyc_yyget_StructOrUnion_tok(({ struct _tagged_ptr2 _temp3310= yyvs; void**
_temp3312= _temp3310.curr +( yyvsp_offset - 5); if( _temp3310.base == 0? 1:(
_temp3312 < _temp3310.base? 1: _temp3312 >= _temp3310.last_plus_one)){ _throw(
Null_Exception);}* _temp3312;})); _LL3315: if( _temp3313 ==( void*) Cyc_Parse_Struct_su){
goto _LL3316;} else{ goto _LL3317;} _LL3317: if( _temp3313 ==( void*) Cyc_Parse_Union_su){
goto _LL3318;} else{ goto _LL3314;} _LL3316: d= Cyc_Absyn_struct_decl(( void*)
Cyc_Absyn_Public,({ struct Cyc_Core_Opt* _temp3319=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp3319->v=( void*) Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3320= yyvs; void** _temp3322= _temp3320.curr +(
yyvsp_offset - 4); if( _temp3320.base == 0? 1:( _temp3322 < _temp3320.base? 1:
_temp3322 >= _temp3320.last_plus_one)){ _throw( Null_Exception);}* _temp3322;}));
_temp3319;}), ts,({ struct Cyc_Core_Opt* _temp3323=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp3323->v=( void*) Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3324= yyvs; void** _temp3326= _temp3324.curr +(
yyvsp_offset - 1); if( _temp3324.base == 0? 1:( _temp3326 < _temp3324.base? 1:
_temp3326 >= _temp3324.last_plus_one)){ _throw( Null_Exception);}* _temp3326;}));
_temp3323;}), 0, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3327=
yyls; struct Cyc_Yyltype* _temp3329= _temp3327.curr +( yylsp_offset - 5); if(
_temp3327.base == 0? 1:( _temp3329 < _temp3327.base? 1: _temp3329 >= _temp3327.last_plus_one)){
_throw( Null_Exception);}* _temp3329;}).first_line,({ struct _tagged_ptr3
_temp3330= yyls; struct Cyc_Yyltype* _temp3332= _temp3330.curr + yylsp_offset;
if( _temp3330.base == 0? 1:( _temp3332 < _temp3330.base? 1: _temp3332 >=
_temp3330.last_plus_one)){ _throw( Null_Exception);}* _temp3332;}).last_line));
goto _LL3314; _LL3318: d= Cyc_Absyn_union_decl(( void*) Cyc_Absyn_Public,({
struct Cyc_Core_Opt* _temp3333=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp3333->v=( void*) Cyc_yyget_QualId_tok(({ struct
_tagged_ptr2 _temp3334= yyvs; void** _temp3336= _temp3334.curr +( yyvsp_offset -
4); if( _temp3334.base == 0? 1:( _temp3336 < _temp3334.base? 1: _temp3336 >=
_temp3334.last_plus_one)){ _throw( Null_Exception);}* _temp3336;})); _temp3333;}),
ts,({ struct Cyc_Core_Opt* _temp3337=( struct Cyc_Core_Opt*) GC_malloc( sizeof(
struct Cyc_Core_Opt)); _temp3337->v=( void*) Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3338= yyvs; void** _temp3340= _temp3338.curr +(
yyvsp_offset - 1); if( _temp3338.base == 0? 1:( _temp3340 < _temp3338.base? 1:
_temp3340 >= _temp3338.last_plus_one)){ _throw( Null_Exception);}* _temp3340;}));
_temp3337;}), 0, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3341=
yyls; struct Cyc_Yyltype* _temp3343= _temp3341.curr +( yylsp_offset - 5); if(
_temp3341.base == 0? 1:( _temp3343 < _temp3341.base? 1: _temp3343 >= _temp3341.last_plus_one)){
_throw( Null_Exception);}* _temp3343;}).first_line,({ struct _tagged_ptr3
_temp3344= yyls; struct Cyc_Yyltype* _temp3346= _temp3344.curr + yylsp_offset;
if( _temp3344.base == 0? 1:( _temp3346 < _temp3344.base? 1: _temp3346 >=
_temp3344.last_plus_one)){ _throw( Null_Exception);}* _temp3346;}).last_line));
goto _LL3314; _LL3314:;} yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3347=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3347[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3348; _temp3348.tag=
Cyc_TypeSpecifier_tok; _temp3348.f1=( void*)(( void*)({ struct Cyc_Parse_Decl_spec_struct*
_temp3349=( struct Cyc_Parse_Decl_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Decl_spec_struct));
_temp3349[ 0]=({ struct Cyc_Parse_Decl_spec_struct _temp3350; _temp3350.tag= Cyc_Parse_Decl_spec;
_temp3350.f1= d; _temp3350;}); _temp3349;})); _temp3348;}); _temp3347;}); break;}
case 81: _LL3309: { struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)( struct
Cyc_Absyn_Tvar*(* f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment*
env, struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3402= yyls; struct Cyc_Yyltype* _temp3404= _temp3402.curr
+( yylsp_offset - 3); if( _temp3402.base == 0? 1:( _temp3404 < _temp3402.base? 1:
_temp3404 >= _temp3402.last_plus_one)){ _throw( Null_Exception);}* _temp3404;}).first_line,({
struct _tagged_ptr3 _temp3405= yyls; struct Cyc_Yyltype* _temp3407= _temp3405.curr
+( yylsp_offset - 3); if( _temp3405.base == 0? 1:( _temp3407 < _temp3405.base? 1:
_temp3407 >= _temp3405.last_plus_one)){ _throw( Null_Exception);}* _temp3407;}).last_line),
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp3408= yyvs; void** _temp3410=
_temp3408.curr +( yyvsp_offset - 3); if( _temp3408.base == 0? 1:( _temp3410 <
_temp3408.base? 1: _temp3410 >= _temp3408.last_plus_one)){ _throw(
Null_Exception);}* _temp3410;}))); struct Cyc_Absyn_Decl* d;{ void* _temp3364=
Cyc_yyget_StructOrUnion_tok(({ struct _tagged_ptr2 _temp3361= yyvs; void**
_temp3363= _temp3361.curr +( yyvsp_offset - 5); if( _temp3361.base == 0? 1:(
_temp3363 < _temp3361.base? 1: _temp3363 >= _temp3361.last_plus_one)){ _throw(
Null_Exception);}* _temp3363;})); _LL3366: if( _temp3364 ==( void*) Cyc_Parse_Struct_su){
goto _LL3367;} else{ goto _LL3368;} _LL3368: if( _temp3364 ==( void*) Cyc_Parse_Union_su){
goto _LL3369;} else{ goto _LL3365;} _LL3367: d= Cyc_Absyn_struct_decl(( void*)
Cyc_Absyn_Public,({ struct Cyc_Core_Opt* _temp3370=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp3370->v=( void*) Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3371= yyvs; void** _temp3373= _temp3371.curr +(
yyvsp_offset - 4); if( _temp3371.base == 0? 1:( _temp3373 < _temp3371.base? 1:
_temp3373 >= _temp3371.last_plus_one)){ _throw( Null_Exception);}* _temp3373;}));
_temp3370;}), ts,({ struct Cyc_Core_Opt* _temp3374=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp3374->v=( void*) Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3375= yyvs; void** _temp3377= _temp3375.curr +(
yyvsp_offset - 1); if( _temp3375.base == 0? 1:( _temp3377 < _temp3375.base? 1:
_temp3377 >= _temp3375.last_plus_one)){ _throw( Null_Exception);}* _temp3377;}));
_temp3374;}), 0, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3378=
yyls; struct Cyc_Yyltype* _temp3380= _temp3378.curr +( yylsp_offset - 5); if(
_temp3378.base == 0? 1:( _temp3380 < _temp3378.base? 1: _temp3380 >= _temp3378.last_plus_one)){
_throw( Null_Exception);}* _temp3380;}).first_line,({ struct _tagged_ptr3
_temp3381= yyls; struct Cyc_Yyltype* _temp3383= _temp3381.curr + yylsp_offset;
if( _temp3381.base == 0? 1:( _temp3383 < _temp3381.base? 1: _temp3383 >=
_temp3381.last_plus_one)){ _throw( Null_Exception);}* _temp3383;}).last_line));
goto _LL3365; _LL3369: d= Cyc_Absyn_union_decl(( void*) Cyc_Absyn_Public,({
struct Cyc_Core_Opt* _temp3384=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp3384->v=( void*) Cyc_yyget_QualId_tok(({ struct
_tagged_ptr2 _temp3385= yyvs; void** _temp3387= _temp3385.curr +( yyvsp_offset -
4); if( _temp3385.base == 0? 1:( _temp3387 < _temp3385.base? 1: _temp3387 >=
_temp3385.last_plus_one)){ _throw( Null_Exception);}* _temp3387;})); _temp3384;}),
ts,({ struct Cyc_Core_Opt* _temp3388=( struct Cyc_Core_Opt*) GC_malloc( sizeof(
struct Cyc_Core_Opt)); _temp3388->v=( void*) Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3389= yyvs; void** _temp3391= _temp3389.curr +(
yyvsp_offset - 1); if( _temp3389.base == 0? 1:( _temp3391 < _temp3389.base? 1:
_temp3391 >= _temp3389.last_plus_one)){ _throw( Null_Exception);}* _temp3391;}));
_temp3388;}), 0, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3392=
yyls; struct Cyc_Yyltype* _temp3394= _temp3392.curr +( yylsp_offset - 5); if(
_temp3392.base == 0? 1:( _temp3394 < _temp3392.base? 1: _temp3394 >= _temp3392.last_plus_one)){
_throw( Null_Exception);}* _temp3394;}).first_line,({ struct _tagged_ptr3
_temp3395= yyls; struct Cyc_Yyltype* _temp3397= _temp3395.curr + yylsp_offset;
if( _temp3395.base == 0? 1:( _temp3397 < _temp3395.base? 1: _temp3397 >=
_temp3395.last_plus_one)){ _throw( Null_Exception);}* _temp3397;}).last_line));
goto _LL3365; _LL3365:;} yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3398=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3398[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3399; _temp3399.tag=
Cyc_TypeSpecifier_tok; _temp3399.f1=( void*)(( void*)({ struct Cyc_Parse_Decl_spec_struct*
_temp3400=( struct Cyc_Parse_Decl_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Decl_spec_struct));
_temp3400[ 0]=({ struct Cyc_Parse_Decl_spec_struct _temp3401; _temp3401.tag= Cyc_Parse_Decl_spec;
_temp3401.f1= d; _temp3401;}); _temp3400;})); _temp3399;}); _temp3398;}); break;}
case 82: _LL3360:{ void* _temp3415= Cyc_yyget_StructOrUnion_tok(({ struct
_tagged_ptr2 _temp3412= yyvs; void** _temp3414= _temp3412.curr +( yyvsp_offset -
2); if( _temp3412.base == 0? 1:( _temp3414 < _temp3412.base? 1: _temp3414 >=
_temp3412.last_plus_one)){ _throw( Null_Exception);}* _temp3414;})); _LL3417:
if( _temp3415 ==( void*) Cyc_Parse_Struct_su){ goto _LL3418;} else{ goto _LL3419;}
_LL3419: if( _temp3415 ==( void*) Cyc_Parse_Union_su){ goto _LL3420;} else{ goto
_LL3416;} _LL3418: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3421=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3421[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3422; _temp3422.tag=
Cyc_TypeSpecifier_tok; _temp3422.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_StructType_struct* _temp3423=( struct Cyc_Absyn_StructType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_StructType_struct)); _temp3423[ 0]=({ struct
Cyc_Absyn_StructType_struct _temp3424; _temp3424.tag= Cyc_Absyn_StructType;
_temp3424.f1=( struct _tuple1*) Cyc_yyget_QualId_tok(({ struct _tagged_ptr2
_temp3425= yyvs; void** _temp3427= _temp3425.curr +( yyvsp_offset - 1); if(
_temp3425.base == 0? 1:( _temp3427 < _temp3425.base? 1: _temp3427 >= _temp3425.last_plus_one)){
_throw( Null_Exception);}* _temp3427;})); _temp3424.f2= Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp3428= yyvs; void** _temp3430= _temp3428.curr +
yyvsp_offset; if( _temp3428.base == 0? 1:( _temp3430 < _temp3428.base? 1:
_temp3430 >= _temp3428.last_plus_one)){ _throw( Null_Exception);}* _temp3430;}));
_temp3424.f3= 0; _temp3424;}); _temp3423;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3431= yyls; struct Cyc_Yyltype* _temp3433= _temp3431.curr
+( yylsp_offset - 2); if( _temp3431.base == 0? 1:( _temp3433 < _temp3431.base? 1:
_temp3433 >= _temp3431.last_plus_one)){ _throw( Null_Exception);}* _temp3433;}).first_line,({
struct _tagged_ptr3 _temp3434= yyls; struct Cyc_Yyltype* _temp3436= _temp3434.curr
+ yylsp_offset; if( _temp3434.base == 0? 1:( _temp3436 < _temp3434.base? 1:
_temp3436 >= _temp3434.last_plus_one)){ _throw( Null_Exception);}* _temp3436;}).last_line));
_temp3422;}); _temp3421;}); goto _LL3416; _LL3420: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3437=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3437[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3438; _temp3438.tag=
Cyc_TypeSpecifier_tok; _temp3438.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_UnionType_struct* _temp3439=( struct Cyc_Absyn_UnionType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnionType_struct)); _temp3439[ 0]=({ struct
Cyc_Absyn_UnionType_struct _temp3440; _temp3440.tag= Cyc_Absyn_UnionType;
_temp3440.f1=( struct _tuple1*) Cyc_yyget_QualId_tok(({ struct _tagged_ptr2
_temp3441= yyvs; void** _temp3443= _temp3441.curr +( yyvsp_offset - 1); if(
_temp3441.base == 0? 1:( _temp3443 < _temp3441.base? 1: _temp3443 >= _temp3441.last_plus_one)){
_throw( Null_Exception);}* _temp3443;})); _temp3440.f2= Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp3444= yyvs; void** _temp3446= _temp3444.curr +
yyvsp_offset; if( _temp3444.base == 0? 1:( _temp3446 < _temp3444.base? 1:
_temp3446 >= _temp3444.last_plus_one)){ _throw( Null_Exception);}* _temp3446;}));
_temp3440.f3= 0; _temp3440;}); _temp3439;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3447= yyls; struct Cyc_Yyltype* _temp3449= _temp3447.curr
+( yylsp_offset - 2); if( _temp3447.base == 0? 1:( _temp3449 < _temp3447.base? 1:
_temp3449 >= _temp3447.last_plus_one)){ _throw( Null_Exception);}* _temp3449;}).first_line,({
struct _tagged_ptr3 _temp3450= yyls; struct Cyc_Yyltype* _temp3452= _temp3450.curr
+ yylsp_offset; if( _temp3450.base == 0? 1:( _temp3452 < _temp3450.base? 1:
_temp3452 >= _temp3450.last_plus_one)){ _throw( Null_Exception);}* _temp3452;}).last_line));
_temp3438;}); _temp3437;}); goto _LL3416; _LL3416:;} break; case 83: _LL3411:{
void* _temp3457= Cyc_yyget_StructOrUnion_tok(({ struct _tagged_ptr2 _temp3454=
yyvs; void** _temp3456= _temp3454.curr +( yyvsp_offset - 2); if( _temp3454.base
== 0? 1:( _temp3456 < _temp3454.base? 1: _temp3456 >= _temp3454.last_plus_one)){
_throw( Null_Exception);}* _temp3456;})); _LL3459: if( _temp3457 ==( void*) Cyc_Parse_Struct_su){
goto _LL3460;} else{ goto _LL3461;} _LL3461: if( _temp3457 ==( void*) Cyc_Parse_Union_su){
goto _LL3462;} else{ goto _LL3458;} _LL3460: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3463=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3463[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3464; _temp3464.tag=
Cyc_TypeSpecifier_tok; _temp3464.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_StructType_struct* _temp3465=( struct Cyc_Absyn_StructType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_StructType_struct)); _temp3465[ 0]=({ struct
Cyc_Absyn_StructType_struct _temp3466; _temp3466.tag= Cyc_Absyn_StructType;
_temp3466.f1=( struct _tuple1*) Cyc_yyget_QualId_tok(({ struct _tagged_ptr2
_temp3467= yyvs; void** _temp3469= _temp3467.curr +( yyvsp_offset - 1); if(
_temp3467.base == 0? 1:( _temp3469 < _temp3467.base? 1: _temp3469 >= _temp3467.last_plus_one)){
_throw( Null_Exception);}* _temp3469;})); _temp3466.f2= Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp3470= yyvs; void** _temp3472= _temp3470.curr +
yyvsp_offset; if( _temp3470.base == 0? 1:( _temp3472 < _temp3470.base? 1:
_temp3472 >= _temp3470.last_plus_one)){ _throw( Null_Exception);}* _temp3472;}));
_temp3466.f3= 0; _temp3466;}); _temp3465;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3473= yyls; struct Cyc_Yyltype* _temp3475= _temp3473.curr
+( yylsp_offset - 2); if( _temp3473.base == 0? 1:( _temp3475 < _temp3473.base? 1:
_temp3475 >= _temp3473.last_plus_one)){ _throw( Null_Exception);}* _temp3475;}).first_line,({
struct _tagged_ptr3 _temp3476= yyls; struct Cyc_Yyltype* _temp3478= _temp3476.curr
+ yylsp_offset; if( _temp3476.base == 0? 1:( _temp3478 < _temp3476.base? 1:
_temp3478 >= _temp3476.last_plus_one)){ _throw( Null_Exception);}* _temp3478;}).last_line));
_temp3464;}); _temp3463;}); goto _LL3458; _LL3462: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3479=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3479[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3480; _temp3480.tag=
Cyc_TypeSpecifier_tok; _temp3480.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_UnionType_struct* _temp3481=( struct Cyc_Absyn_UnionType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnionType_struct)); _temp3481[ 0]=({ struct
Cyc_Absyn_UnionType_struct _temp3482; _temp3482.tag= Cyc_Absyn_UnionType;
_temp3482.f1=( struct _tuple1*) Cyc_yyget_QualId_tok(({ struct _tagged_ptr2
_temp3483= yyvs; void** _temp3485= _temp3483.curr +( yyvsp_offset - 1); if(
_temp3483.base == 0? 1:( _temp3485 < _temp3483.base? 1: _temp3485 >= _temp3483.last_plus_one)){
_throw( Null_Exception);}* _temp3485;})); _temp3482.f2= Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp3486= yyvs; void** _temp3488= _temp3486.curr +
yyvsp_offset; if( _temp3486.base == 0? 1:( _temp3488 < _temp3486.base? 1:
_temp3488 >= _temp3486.last_plus_one)){ _throw( Null_Exception);}* _temp3488;}));
_temp3482.f3= 0; _temp3482;}); _temp3481;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3489= yyls; struct Cyc_Yyltype* _temp3491= _temp3489.curr
+( yylsp_offset - 2); if( _temp3489.base == 0? 1:( _temp3491 < _temp3489.base? 1:
_temp3491 >= _temp3489.last_plus_one)){ _throw( Null_Exception);}* _temp3491;}).first_line,({
struct _tagged_ptr3 _temp3492= yyls; struct Cyc_Yyltype* _temp3494= _temp3492.curr
+ yylsp_offset; if( _temp3492.base == 0? 1:( _temp3494 < _temp3492.base? 1:
_temp3494 >= _temp3492.last_plus_one)){ _throw( Null_Exception);}* _temp3494;}).last_line));
_temp3480;}); _temp3479;}); goto _LL3458; _LL3458:;} break; case 84: _LL3453:
yyval=( void*)({ struct Cyc_TypeList_tok_struct* _temp3496=( struct Cyc_TypeList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeList_tok_struct)); _temp3496[ 0]=({ struct Cyc_TypeList_tok_struct
_temp3497; _temp3497.tag= Cyc_TypeList_tok; _temp3497.f1= 0; _temp3497;});
_temp3496;}); break; case 85: _LL3495: yyval=( void*)({ struct Cyc_TypeList_tok_struct*
_temp3499=( struct Cyc_TypeList_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeList_tok_struct));
_temp3499[ 0]=({ struct Cyc_TypeList_tok_struct _temp3500; _temp3500.tag= Cyc_TypeList_tok;
_temp3500.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp3501= yyvs; void** _temp3503=
_temp3501.curr +( yyvsp_offset - 1); if( _temp3501.base == 0? 1:( _temp3503 <
_temp3501.base? 1: _temp3503 >= _temp3501.last_plus_one)){ _throw(
Null_Exception);}* _temp3503;}))); _temp3500;}); _temp3499;}); break; case 86:
_LL3498:(( struct Cyc_Lexing_lexbuf*)({ struct Cyc_Core_Opt* _temp3505= Cyc_Parse_lbuf;
if( _temp3505 == 0){ _throw( Null_Exception);} _temp3505->v;}))->lex_curr_pos -=
1; yyval=( void*)({ struct Cyc_TypeList_tok_struct* _temp3506=( struct Cyc_TypeList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeList_tok_struct)); _temp3506[ 0]=({ struct Cyc_TypeList_tok_struct
_temp3507; _temp3507.tag= Cyc_TypeList_tok; _temp3507.f1=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_TypeList_tok(({ struct
_tagged_ptr2 _temp3508= yyvs; void** _temp3510= _temp3508.curr +( yyvsp_offset -
1); if( _temp3508.base == 0? 1:( _temp3510 < _temp3508.base? 1: _temp3510 >=
_temp3508.last_plus_one)){ _throw( Null_Exception);}* _temp3510;}))); _temp3507;});
_temp3506;}); break; case 87: _LL3504: yyval=( void*)({ struct Cyc_StructOrUnion_tok_struct*
_temp3512=( struct Cyc_StructOrUnion_tok_struct*) GC_malloc( sizeof( struct Cyc_StructOrUnion_tok_struct));
_temp3512[ 0]=({ struct Cyc_StructOrUnion_tok_struct _temp3513; _temp3513.tag=
Cyc_StructOrUnion_tok; _temp3513.f1=( void*)(( void*) Cyc_Parse_Struct_su);
_temp3513;}); _temp3512;}); break; case 88: _LL3511: yyval=( void*)({ struct Cyc_StructOrUnion_tok_struct*
_temp3515=( struct Cyc_StructOrUnion_tok_struct*) GC_malloc( sizeof( struct Cyc_StructOrUnion_tok_struct));
_temp3515[ 0]=({ struct Cyc_StructOrUnion_tok_struct _temp3516; _temp3516.tag=
Cyc_StructOrUnion_tok; _temp3516.f1=( void*)(( void*) Cyc_Parse_Union_su);
_temp3516;}); _temp3515;}); break; case 89: _LL3514: yyval=( void*)({ struct Cyc_StructFieldDeclList_tok_struct*
_temp3518=( struct Cyc_StructFieldDeclList_tok_struct*) GC_malloc( sizeof(
struct Cyc_StructFieldDeclList_tok_struct)); _temp3518[ 0]=({ struct Cyc_StructFieldDeclList_tok_struct
_temp3519; _temp3519.tag= Cyc_StructFieldDeclList_tok; _temp3519.f1=(( struct
Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_flatten)((( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_StructFieldDeclListList_tok(({
struct _tagged_ptr2 _temp3520= yyvs; void** _temp3522= _temp3520.curr +
yyvsp_offset; if( _temp3520.base == 0? 1:( _temp3522 < _temp3520.base? 1:
_temp3522 >= _temp3520.last_plus_one)){ _throw( Null_Exception);}* _temp3522;}))));
_temp3519;}); _temp3518;}); break; case 90: _LL3517: yyval=( void*)({ struct Cyc_StructFieldDeclListList_tok_struct*
_temp3524=( struct Cyc_StructFieldDeclListList_tok_struct*) GC_malloc( sizeof(
struct Cyc_StructFieldDeclListList_tok_struct)); _temp3524[ 0]=({ struct Cyc_StructFieldDeclListList_tok_struct
_temp3525; _temp3525.tag= Cyc_StructFieldDeclListList_tok; _temp3525.f1=({
struct Cyc_List_List* _temp3526=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp3526->hd=( void*) Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3527= yyvs; void** _temp3529= _temp3527.curr +
yyvsp_offset; if( _temp3527.base == 0? 1:( _temp3529 < _temp3527.base? 1:
_temp3529 >= _temp3527.last_plus_one)){ _throw( Null_Exception);}* _temp3529;}));
_temp3526->tl= 0; _temp3526;}); _temp3525;}); _temp3524;}); break; case 91:
_LL3523: yyval=( void*)({ struct Cyc_StructFieldDeclListList_tok_struct*
_temp3531=( struct Cyc_StructFieldDeclListList_tok_struct*) GC_malloc( sizeof(
struct Cyc_StructFieldDeclListList_tok_struct)); _temp3531[ 0]=({ struct Cyc_StructFieldDeclListList_tok_struct
_temp3532; _temp3532.tag= Cyc_StructFieldDeclListList_tok; _temp3532.f1=({
struct Cyc_List_List* _temp3533=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp3533->hd=( void*) Cyc_yyget_StructFieldDeclList_tok(({
struct _tagged_ptr2 _temp3537= yyvs; void** _temp3539= _temp3537.curr +
yyvsp_offset; if( _temp3537.base == 0? 1:( _temp3539 < _temp3537.base? 1:
_temp3539 >= _temp3537.last_plus_one)){ _throw( Null_Exception);}* _temp3539;}));
_temp3533->tl= Cyc_yyget_StructFieldDeclListList_tok(({ struct _tagged_ptr2
_temp3534= yyvs; void** _temp3536= _temp3534.curr +( yyvsp_offset - 1); if(
_temp3534.base == 0? 1:( _temp3536 < _temp3534.base? 1: _temp3536 >= _temp3534.last_plus_one)){
_throw( Null_Exception);}* _temp3536;})); _temp3533;}); _temp3532;}); _temp3531;});
break; case 92: _LL3530: yyval=( void*)({ struct Cyc_InitDeclList_tok_struct*
_temp3541=( struct Cyc_InitDeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_InitDeclList_tok_struct));
_temp3541[ 0]=({ struct Cyc_InitDeclList_tok_struct _temp3542; _temp3542.tag=
Cyc_InitDeclList_tok; _temp3542.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x)) Cyc_List_imp_rev)( Cyc_yyget_InitDeclList_tok(({ struct _tagged_ptr2
_temp3543= yyvs; void** _temp3545= _temp3543.curr + yyvsp_offset; if( _temp3543.base
== 0? 1:( _temp3545 < _temp3543.base? 1: _temp3545 >= _temp3543.last_plus_one)){
_throw( Null_Exception);}* _temp3545;}))); _temp3542;}); _temp3541;}); break;
case 93: _LL3540: yyval=( void*)({ struct Cyc_InitDeclList_tok_struct* _temp3547=(
struct Cyc_InitDeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_InitDeclList_tok_struct));
_temp3547[ 0]=({ struct Cyc_InitDeclList_tok_struct _temp3548; _temp3548.tag=
Cyc_InitDeclList_tok; _temp3548.f1=({ struct Cyc_List_List* _temp3549=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp3549->hd=( void*)
Cyc_yyget_InitDecl_tok(({ struct _tagged_ptr2 _temp3550= yyvs; void** _temp3552=
_temp3550.curr + yyvsp_offset; if( _temp3550.base == 0? 1:( _temp3552 <
_temp3550.base? 1: _temp3552 >= _temp3550.last_plus_one)){ _throw(
Null_Exception);}* _temp3552;})); _temp3549->tl= 0; _temp3549;}); _temp3548;});
_temp3547;}); break; case 94: _LL3546: yyval=( void*)({ struct Cyc_InitDeclList_tok_struct*
_temp3554=( struct Cyc_InitDeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_InitDeclList_tok_struct));
_temp3554[ 0]=({ struct Cyc_InitDeclList_tok_struct _temp3555; _temp3555.tag=
Cyc_InitDeclList_tok; _temp3555.f1=({ struct Cyc_List_List* _temp3556=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp3556->hd=( void*)
Cyc_yyget_InitDecl_tok(({ struct _tagged_ptr2 _temp3560= yyvs; void** _temp3562=
_temp3560.curr + yyvsp_offset; if( _temp3560.base == 0? 1:( _temp3562 <
_temp3560.base? 1: _temp3562 >= _temp3560.last_plus_one)){ _throw(
Null_Exception);}* _temp3562;})); _temp3556->tl= Cyc_yyget_InitDeclList_tok(({
struct _tagged_ptr2 _temp3557= yyvs; void** _temp3559= _temp3557.curr +(
yyvsp_offset - 2); if( _temp3557.base == 0? 1:( _temp3559 < _temp3557.base? 1:
_temp3559 >= _temp3557.last_plus_one)){ _throw( Null_Exception);}* _temp3559;}));
_temp3556;}); _temp3555;}); _temp3554;}); break; case 95: _LL3553: yyval=( void*)({
struct Cyc_InitDecl_tok_struct* _temp3564=( struct Cyc_InitDecl_tok_struct*)
GC_malloc( sizeof( struct Cyc_InitDecl_tok_struct)); _temp3564[ 0]=({ struct Cyc_InitDecl_tok_struct
_temp3565; _temp3565.tag= Cyc_InitDecl_tok; _temp3565.f1=({ struct _tuple13*
_temp3566=( struct _tuple13*) GC_malloc( sizeof( struct _tuple13)); _temp3566->f1=
Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2 _temp3567= yyvs; void**
_temp3569= _temp3567.curr + yyvsp_offset; if( _temp3567.base == 0? 1:( _temp3569
< _temp3567.base? 1: _temp3569 >= _temp3567.last_plus_one)){ _throw(
Null_Exception);}* _temp3569;})); _temp3566->f2= 0; _temp3566;}); _temp3565;});
_temp3564;}); break; case 96: _LL3563: yyval=( void*)({ struct Cyc_InitDecl_tok_struct*
_temp3571=( struct Cyc_InitDecl_tok_struct*) GC_malloc( sizeof( struct Cyc_InitDecl_tok_struct));
_temp3571[ 0]=({ struct Cyc_InitDecl_tok_struct _temp3572; _temp3572.tag= Cyc_InitDecl_tok;
_temp3572.f1=({ struct _tuple13* _temp3573=( struct _tuple13*) GC_malloc(
sizeof( struct _tuple13)); _temp3573->f1= Cyc_yyget_Declarator_tok(({ struct
_tagged_ptr2 _temp3577= yyvs; void** _temp3579= _temp3577.curr +( yyvsp_offset -
2); if( _temp3577.base == 0? 1:( _temp3579 < _temp3577.base? 1: _temp3579 >=
_temp3577.last_plus_one)){ _throw( Null_Exception);}* _temp3579;})); _temp3573->f2=(
struct Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp3574= yyvs;
void** _temp3576= _temp3574.curr + yyvsp_offset; if( _temp3574.base == 0? 1:(
_temp3576 < _temp3574.base? 1: _temp3576 >= _temp3574.last_plus_one)){ _throw(
Null_Exception);}* _temp3576;})); _temp3573;}); _temp3572;}); _temp3571;});
break; case 97: _LL3570: { struct Cyc_Absyn_Tqual tq=(* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp3610= yyvs; void** _temp3612= _temp3610.curr +(
yyvsp_offset - 2); if( _temp3610.base == 0? 1:( _temp3612 < _temp3610.base? 1:
_temp3612 >= _temp3610.last_plus_one)){ _throw( Null_Exception);}* _temp3612;}))).f1;
struct Cyc_List_List* atts=(* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp3607= yyvs; void** _temp3609= _temp3607.curr +( yyvsp_offset - 2); if(
_temp3607.base == 0? 1:( _temp3609 < _temp3607.base? 1: _temp3609 >= _temp3607.last_plus_one)){
_throw( Null_Exception);}* _temp3609;}))).f3; void* t= Cyc_Parse_speclist2typ((*
Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2 _temp3598= yyvs; void**
_temp3600= _temp3598.curr +( yyvsp_offset - 2); if( _temp3598.base == 0? 1:(
_temp3600 < _temp3598.base? 1: _temp3600 >= _temp3598.last_plus_one)){ _throw(
Null_Exception);}* _temp3600;}))).f2, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3601= yyls; struct Cyc_Yyltype* _temp3603= _temp3601.curr +(
yylsp_offset - 2); if( _temp3601.base == 0? 1:( _temp3603 < _temp3601.base? 1:
_temp3603 >= _temp3601.last_plus_one)){ _throw( Null_Exception);}* _temp3603;}).first_line,({
struct _tagged_ptr3 _temp3604= yyls; struct Cyc_Yyltype* _temp3606= _temp3604.curr
+( yylsp_offset - 2); if( _temp3604.base == 0? 1:( _temp3606 < _temp3604.base? 1:
_temp3606 >= _temp3604.last_plus_one)){ _throw( Null_Exception);}* _temp3606;}).last_line));
struct Cyc_List_List* _temp3586; struct Cyc_List_List* _temp3588; struct _tuple0
_temp3584=(( struct _tuple0(*)( struct Cyc_List_List* x)) Cyc_List_split)( Cyc_yyget_DeclaratorExpoptList_tok(({
struct _tagged_ptr2 _temp3581= yyvs; void** _temp3583= _temp3581.curr +(
yyvsp_offset - 1); if( _temp3581.base == 0? 1:( _temp3583 < _temp3581.base? 1:
_temp3583 >= _temp3581.last_plus_one)){ _throw( Null_Exception);}* _temp3583;})));
_LL3589: _temp3588= _temp3584.f1; goto _LL3587; _LL3587: _temp3586= _temp3584.f2;
goto _LL3585; _LL3585: { struct Cyc_List_List* info=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_zip)( Cyc_Parse_apply_tmss(
tq, t, _temp3588, atts), _temp3586); yyval=( void*)({ struct Cyc_StructFieldDeclList_tok_struct*
_temp3590=( struct Cyc_StructFieldDeclList_tok_struct*) GC_malloc( sizeof(
struct Cyc_StructFieldDeclList_tok_struct)); _temp3590[ 0]=({ struct Cyc_StructFieldDeclList_tok_struct
_temp3591; _temp3591.tag= Cyc_StructFieldDeclList_tok; _temp3591.f1=(( struct
Cyc_List_List*(*)( struct Cyc_Absyn_Structfield*(* f)( struct Cyc_Position_Segment*,
struct _tuple8*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x))
Cyc_List_map_c)( Cyc_Parse_make_struct_field, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3592= yyls; struct Cyc_Yyltype* _temp3594= _temp3592.curr
+( yylsp_offset - 2); if( _temp3592.base == 0? 1:( _temp3594 < _temp3592.base? 1:
_temp3594 >= _temp3592.last_plus_one)){ _throw( Null_Exception);}* _temp3594;}).first_line,({
struct _tagged_ptr3 _temp3595= yyls; struct Cyc_Yyltype* _temp3597= _temp3595.curr
+( yylsp_offset - 1); if( _temp3595.base == 0? 1:( _temp3597 < _temp3595.base? 1:
_temp3597 >= _temp3595.last_plus_one)){ _throw( Null_Exception);}* _temp3597;}).last_line),
info); _temp3591;}); _temp3590;}); break;}} case 98: _LL3580: yyval=( void*)({
struct Cyc_QualSpecList_tok_struct* _temp3614=( struct Cyc_QualSpecList_tok_struct*)
GC_malloc( sizeof( struct Cyc_QualSpecList_tok_struct)); _temp3614[ 0]=({ struct
Cyc_QualSpecList_tok_struct _temp3615; _temp3615.tag= Cyc_QualSpecList_tok;
_temp3615.f1=({ struct _tuple14* _temp3616=( struct _tuple14*) GC_malloc(
sizeof( struct _tuple14)); _temp3616->f1= Cyc_Absyn_empty_tqual(); _temp3616->f2=(
struct Cyc_List_List*)({ struct Cyc_List_List* _temp3620=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp3620->hd=( void*) Cyc_yyget_TypeSpecifier_tok(({
struct _tagged_ptr2 _temp3621= yyvs; void** _temp3623= _temp3621.curr +(
yyvsp_offset - 1); if( _temp3621.base == 0? 1:( _temp3623 < _temp3621.base? 1:
_temp3623 >= _temp3621.last_plus_one)){ _throw( Null_Exception);}* _temp3623;}));
_temp3620->tl= 0; _temp3620;}); _temp3616->f3= Cyc_yyget_AttributeList_tok(({
struct _tagged_ptr2 _temp3617= yyvs; void** _temp3619= _temp3617.curr +
yyvsp_offset; if( _temp3617.base == 0? 1:( _temp3619 < _temp3617.base? 1:
_temp3619 >= _temp3617.last_plus_one)){ _throw( Null_Exception);}* _temp3619;}));
_temp3616;}); _temp3615;}); _temp3614;}); break; case 99: _LL3613: yyval=( void*)({
struct Cyc_QualSpecList_tok_struct* _temp3625=( struct Cyc_QualSpecList_tok_struct*)
GC_malloc( sizeof( struct Cyc_QualSpecList_tok_struct)); _temp3625[ 0]=({ struct
Cyc_QualSpecList_tok_struct _temp3626; _temp3626.tag= Cyc_QualSpecList_tok;
_temp3626.f1=({ struct _tuple14* _temp3627=( struct _tuple14*) GC_malloc(
sizeof( struct _tuple14)); _temp3627->f1=(* Cyc_yyget_QualSpecList_tok(({ struct
_tagged_ptr2 _temp3641= yyvs; void** _temp3643= _temp3641.curr + yyvsp_offset;
if( _temp3641.base == 0? 1:( _temp3643 < _temp3641.base? 1: _temp3643 >=
_temp3641.last_plus_one)){ _throw( Null_Exception);}* _temp3643;}))).f1;
_temp3627->f2=( struct Cyc_List_List*)({ struct Cyc_List_List* _temp3634=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp3634->hd=(
void*) Cyc_yyget_TypeSpecifier_tok(({ struct _tagged_ptr2 _temp3638= yyvs; void**
_temp3640= _temp3638.curr +( yyvsp_offset - 2); if( _temp3638.base == 0? 1:(
_temp3640 < _temp3638.base? 1: _temp3640 >= _temp3638.last_plus_one)){ _throw(
Null_Exception);}* _temp3640;})); _temp3634->tl=(* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp3635= yyvs; void** _temp3637= _temp3635.curr +
yyvsp_offset; if( _temp3635.base == 0? 1:( _temp3637 < _temp3635.base? 1:
_temp3637 >= _temp3635.last_plus_one)){ _throw( Null_Exception);}* _temp3637;}))).f2;
_temp3634;}); _temp3627->f3=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x,
struct Cyc_List_List* y)) Cyc_List_append)( Cyc_yyget_AttributeList_tok(({
struct _tagged_ptr2 _temp3628= yyvs; void** _temp3630= _temp3628.curr +(
yyvsp_offset - 1); if( _temp3628.base == 0? 1:( _temp3630 < _temp3628.base? 1:
_temp3630 >= _temp3628.last_plus_one)){ _throw( Null_Exception);}* _temp3630;})),(*
Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2 _temp3631= yyvs; void**
_temp3633= _temp3631.curr + yyvsp_offset; if( _temp3631.base == 0? 1:( _temp3633
< _temp3631.base? 1: _temp3633 >= _temp3631.last_plus_one)){ _throw(
Null_Exception);}* _temp3633;}))).f3); _temp3627;}); _temp3626;}); _temp3625;});
break; case 100: _LL3624: yyval=( void*)({ struct Cyc_QualSpecList_tok_struct*
_temp3645=( struct Cyc_QualSpecList_tok_struct*) GC_malloc( sizeof( struct Cyc_QualSpecList_tok_struct));
_temp3645[ 0]=({ struct Cyc_QualSpecList_tok_struct _temp3646; _temp3646.tag=
Cyc_QualSpecList_tok; _temp3646.f1=({ struct _tuple14* _temp3647=( struct
_tuple14*) GC_malloc( sizeof( struct _tuple14)); _temp3647->f1= Cyc_yyget_TypeQual_tok(({
struct _tagged_ptr2 _temp3651= yyvs; void** _temp3653= _temp3651.curr +(
yyvsp_offset - 1); if( _temp3651.base == 0? 1:( _temp3653 < _temp3651.base? 1:
_temp3653 >= _temp3651.last_plus_one)){ _throw( Null_Exception);}* _temp3653;}));
_temp3647->f2= 0; _temp3647->f3= Cyc_yyget_AttributeList_tok(({ struct
_tagged_ptr2 _temp3648= yyvs; void** _temp3650= _temp3648.curr + yyvsp_offset;
if( _temp3648.base == 0? 1:( _temp3650 < _temp3648.base? 1: _temp3650 >=
_temp3648.last_plus_one)){ _throw( Null_Exception);}* _temp3650;})); _temp3647;});
_temp3646;}); _temp3645;}); break; case 101: _LL3644: yyval=( void*)({ struct
Cyc_QualSpecList_tok_struct* _temp3655=( struct Cyc_QualSpecList_tok_struct*)
GC_malloc( sizeof( struct Cyc_QualSpecList_tok_struct)); _temp3655[ 0]=({ struct
Cyc_QualSpecList_tok_struct _temp3656; _temp3656.tag= Cyc_QualSpecList_tok;
_temp3656.f1=({ struct _tuple14* _temp3657=( struct _tuple14*) GC_malloc(
sizeof( struct _tuple14)); _temp3657->f1= Cyc_Absyn_combine_tqual( Cyc_yyget_TypeQual_tok(({
struct _tagged_ptr2 _temp3667= yyvs; void** _temp3669= _temp3667.curr +(
yyvsp_offset - 2); if( _temp3667.base == 0? 1:( _temp3669 < _temp3667.base? 1:
_temp3669 >= _temp3667.last_plus_one)){ _throw( Null_Exception);}* _temp3669;})),(*
Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2 _temp3670= yyvs; void**
_temp3672= _temp3670.curr + yyvsp_offset; if( _temp3670.base == 0? 1:( _temp3672
< _temp3670.base? 1: _temp3672 >= _temp3670.last_plus_one)){ _throw(
Null_Exception);}* _temp3672;}))).f1); _temp3657->f2=(* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp3664= yyvs; void** _temp3666= _temp3664.curr +
yyvsp_offset; if( _temp3664.base == 0? 1:( _temp3666 < _temp3664.base? 1:
_temp3666 >= _temp3664.last_plus_one)){ _throw( Null_Exception);}* _temp3666;}))).f2;
_temp3657->f3=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List*
y)) Cyc_List_append)( Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2
_temp3658= yyvs; void** _temp3660= _temp3658.curr +( yyvsp_offset - 1); if(
_temp3658.base == 0? 1:( _temp3660 < _temp3658.base? 1: _temp3660 >= _temp3658.last_plus_one)){
_throw( Null_Exception);}* _temp3660;})),(* Cyc_yyget_QualSpecList_tok(({ struct
_tagged_ptr2 _temp3661= yyvs; void** _temp3663= _temp3661.curr + yyvsp_offset;
if( _temp3661.base == 0? 1:( _temp3663 < _temp3661.base? 1: _temp3663 >=
_temp3661.last_plus_one)){ _throw( Null_Exception);}* _temp3663;}))).f3);
_temp3657;}); _temp3656;}); _temp3655;}); break; case 102: _LL3654: yyval=( void*)({
struct Cyc_DeclaratorExpoptList_tok_struct* _temp3674=( struct Cyc_DeclaratorExpoptList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclaratorExpoptList_tok_struct)); _temp3674[ 0]=({
struct Cyc_DeclaratorExpoptList_tok_struct _temp3675; _temp3675.tag= Cyc_DeclaratorExpoptList_tok;
_temp3675.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
Cyc_yyget_DeclaratorExpoptList_tok(({ struct _tagged_ptr2 _temp3676= yyvs; void**
_temp3678= _temp3676.curr + yyvsp_offset; if( _temp3676.base == 0? 1:( _temp3678
< _temp3676.base? 1: _temp3678 >= _temp3676.last_plus_one)){ _throw(
Null_Exception);}* _temp3678;}))); _temp3675;}); _temp3674;}); break; case 103:
_LL3673: yyval=( void*)({ struct Cyc_DeclaratorExpoptList_tok_struct* _temp3680=(
struct Cyc_DeclaratorExpoptList_tok_struct*) GC_malloc( sizeof( struct Cyc_DeclaratorExpoptList_tok_struct));
_temp3680[ 0]=({ struct Cyc_DeclaratorExpoptList_tok_struct _temp3681; _temp3681.tag=
Cyc_DeclaratorExpoptList_tok; _temp3681.f1=({ struct Cyc_List_List* _temp3682=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp3682->hd=(
void*) Cyc_yyget_DeclaratorExpopt_tok(({ struct _tagged_ptr2 _temp3683= yyvs;
void** _temp3685= _temp3683.curr + yyvsp_offset; if( _temp3683.base == 0? 1:(
_temp3685 < _temp3683.base? 1: _temp3685 >= _temp3683.last_plus_one)){ _throw(
Null_Exception);}* _temp3685;})); _temp3682->tl= 0; _temp3682;}); _temp3681;});
_temp3680;}); break; case 104: _LL3679: yyval=( void*)({ struct Cyc_DeclaratorExpoptList_tok_struct*
_temp3687=( struct Cyc_DeclaratorExpoptList_tok_struct*) GC_malloc( sizeof(
struct Cyc_DeclaratorExpoptList_tok_struct)); _temp3687[ 0]=({ struct Cyc_DeclaratorExpoptList_tok_struct
_temp3688; _temp3688.tag= Cyc_DeclaratorExpoptList_tok; _temp3688.f1=({ struct
Cyc_List_List* _temp3689=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp3689->hd=( void*) Cyc_yyget_DeclaratorExpopt_tok(({ struct _tagged_ptr2
_temp3693= yyvs; void** _temp3695= _temp3693.curr + yyvsp_offset; if( _temp3693.base
== 0? 1:( _temp3695 < _temp3693.base? 1: _temp3695 >= _temp3693.last_plus_one)){
_throw( Null_Exception);}* _temp3695;})); _temp3689->tl= Cyc_yyget_DeclaratorExpoptList_tok(({
struct _tagged_ptr2 _temp3690= yyvs; void** _temp3692= _temp3690.curr +(
yyvsp_offset - 2); if( _temp3690.base == 0? 1:( _temp3692 < _temp3690.base? 1:
_temp3692 >= _temp3690.last_plus_one)){ _throw( Null_Exception);}* _temp3692;}));
_temp3689;}); _temp3688;}); _temp3687;}); break; case 105: _LL3686: yyval=( void*)({
struct Cyc_DeclaratorExpopt_tok_struct* _temp3697=( struct Cyc_DeclaratorExpopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclaratorExpopt_tok_struct)); _temp3697[ 0]=({
struct Cyc_DeclaratorExpopt_tok_struct _temp3698; _temp3698.tag= Cyc_DeclaratorExpopt_tok;
_temp3698.f1=({ struct _tuple15* _temp3699=( struct _tuple15*) GC_malloc(
sizeof( struct _tuple15)); _temp3699->f1= Cyc_yyget_Declarator_tok(({ struct
_tagged_ptr2 _temp3700= yyvs; void** _temp3702= _temp3700.curr + yyvsp_offset;
if( _temp3700.base == 0? 1:( _temp3702 < _temp3700.base? 1: _temp3702 >=
_temp3700.last_plus_one)){ _throw( Null_Exception);}* _temp3702;})); _temp3699->f2=
0; _temp3699;}); _temp3698;}); _temp3697;}); break; case 106: _LL3696: yyval=(
void*)({ struct Cyc_DeclaratorExpopt_tok_struct* _temp3704=( struct Cyc_DeclaratorExpopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_DeclaratorExpopt_tok_struct)); _temp3704[ 0]=({
struct Cyc_DeclaratorExpopt_tok_struct _temp3705; _temp3705.tag= Cyc_DeclaratorExpopt_tok;
_temp3705.f1=({ struct _tuple15* _temp3706=( struct _tuple15*) GC_malloc(
sizeof( struct _tuple15)); _temp3706->f1=({ struct Cyc_Parse_Declarator*
_temp3711=( struct Cyc_Parse_Declarator*) GC_malloc( sizeof( struct Cyc_Parse_Declarator));
_temp3711->id=({ struct _tuple1* _temp3712=( struct _tuple1*) GC_malloc( sizeof(
struct _tuple1)); _temp3712->f1=( void*)({ struct Cyc_Absyn_Rel_n_struct*
_temp3716=( struct Cyc_Absyn_Rel_n_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Rel_n_struct));
_temp3716[ 0]=({ struct Cyc_Absyn_Rel_n_struct _temp3717; _temp3717.tag= Cyc_Absyn_Rel_n;
_temp3717.f1= 0; _temp3717;}); _temp3716;}); _temp3712->f2=({ struct
_tagged_string* _temp3713=( struct _tagged_string*) GC_malloc( sizeof( struct
_tagged_string)); _temp3713[ 0]=( struct _tagged_string)({ char* _temp3714=(
char*)""; struct _tagged_string _temp3715; _temp3715.curr= _temp3714; _temp3715.base=
_temp3714; _temp3715.last_plus_one= _temp3714 + 1; _temp3715;}); _temp3713;});
_temp3712;}); _temp3711->tms= 0; _temp3711;}); _temp3706->f2=({ struct Cyc_Core_Opt*
_temp3707=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp3707->v=( void*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp3708= yyvs;
void** _temp3710= _temp3708.curr + yyvsp_offset; if( _temp3708.base == 0? 1:(
_temp3710 < _temp3708.base? 1: _temp3710 >= _temp3708.last_plus_one)){ _throw(
Null_Exception);}* _temp3710;})); _temp3707;}); _temp3706;}); _temp3705;});
_temp3704;}); break; case 107: _LL3703: yyval=( void*)({ struct Cyc_DeclaratorExpopt_tok_struct*
_temp3719=( struct Cyc_DeclaratorExpopt_tok_struct*) GC_malloc( sizeof( struct
Cyc_DeclaratorExpopt_tok_struct)); _temp3719[ 0]=({ struct Cyc_DeclaratorExpopt_tok_struct
_temp3720; _temp3720.tag= Cyc_DeclaratorExpopt_tok; _temp3720.f1=({ struct
_tuple15* _temp3721=( struct _tuple15*) GC_malloc( sizeof( struct _tuple15));
_temp3721->f1= Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2 _temp3726= yyvs;
void** _temp3728= _temp3726.curr +( yyvsp_offset - 2); if( _temp3726.base == 0?
1:( _temp3728 < _temp3726.base? 1: _temp3728 >= _temp3726.last_plus_one)){
_throw( Null_Exception);}* _temp3728;})); _temp3721->f2=({ struct Cyc_Core_Opt*
_temp3722=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp3722->v=( void*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp3723= yyvs;
void** _temp3725= _temp3723.curr + yyvsp_offset; if( _temp3723.base == 0? 1:(
_temp3725 < _temp3723.base? 1: _temp3725 >= _temp3723.last_plus_one)){ _throw(
Null_Exception);}* _temp3725;})); _temp3722;}); _temp3721;}); _temp3720;});
_temp3719;}); break; case 108: _LL3718: { struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)(
struct Cyc_Absyn_Tvar*(* f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment*
env, struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3750= yyls; struct Cyc_Yyltype* _temp3752= _temp3750.curr
+( yylsp_offset - 3); if( _temp3750.base == 0? 1:( _temp3752 < _temp3750.base? 1:
_temp3752 >= _temp3750.last_plus_one)){ _throw( Null_Exception);}* _temp3752;}).first_line,({
struct _tagged_ptr3 _temp3753= yyls; struct Cyc_Yyltype* _temp3755= _temp3753.curr
+( yylsp_offset - 3); if( _temp3753.base == 0? 1:( _temp3755 < _temp3753.base? 1:
_temp3755 >= _temp3753.last_plus_one)){ _throw( Null_Exception);}* _temp3755;}).last_line),
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp3756= yyvs; void** _temp3758=
_temp3756.curr +( yyvsp_offset - 3); if( _temp3756.base == 0? 1:( _temp3758 <
_temp3756.base? 1: _temp3758 >= _temp3756.last_plus_one)){ _throw(
Null_Exception);}* _temp3758;}))); yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3730=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3730[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3731; _temp3731.tag=
Cyc_TypeSpecifier_tok; _temp3731.f1=( void*)(( void*)({ struct Cyc_Parse_Decl_spec_struct*
_temp3732=( struct Cyc_Parse_Decl_spec_struct*) GC_malloc( sizeof( struct Cyc_Parse_Decl_spec_struct));
_temp3732[ 0]=({ struct Cyc_Parse_Decl_spec_struct _temp3733; _temp3733.tag= Cyc_Parse_Decl_spec;
_temp3733.f1= Cyc_Absyn_tunion_decl(( void*) Cyc_Absyn_Public, Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3734= yyvs; void** _temp3736= _temp3734.curr +(
yyvsp_offset - 4); if( _temp3734.base == 0? 1:( _temp3736 < _temp3734.base? 1:
_temp3736 >= _temp3734.last_plus_one)){ _throw( Null_Exception);}* _temp3736;})),
ts,({ struct Cyc_Core_Opt* _temp3737=( struct Cyc_Core_Opt*) GC_malloc( sizeof(
struct Cyc_Core_Opt)); _temp3737->v=( void*) Cyc_yyget_TunionFieldList_tok(({
struct _tagged_ptr2 _temp3738= yyvs; void** _temp3740= _temp3738.curr +(
yyvsp_offset - 1); if( _temp3738.base == 0? 1:( _temp3740 < _temp3738.base? 1:
_temp3740 >= _temp3738.last_plus_one)){ _throw( Null_Exception);}* _temp3740;}));
_temp3737;}), Cyc_yyget_Bool_tok(({ struct _tagged_ptr2 _temp3741= yyvs; void**
_temp3743= _temp3741.curr +( yyvsp_offset - 5); if( _temp3741.base == 0? 1:(
_temp3743 < _temp3741.base? 1: _temp3743 >= _temp3741.last_plus_one)){ _throw(
Null_Exception);}* _temp3743;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3744= yyls; struct Cyc_Yyltype* _temp3746= _temp3744.curr +(
yylsp_offset - 5); if( _temp3744.base == 0? 1:( _temp3746 < _temp3744.base? 1:
_temp3746 >= _temp3744.last_plus_one)){ _throw( Null_Exception);}* _temp3746;}).first_line,({
struct _tagged_ptr3 _temp3747= yyls; struct Cyc_Yyltype* _temp3749= _temp3747.curr
+ yylsp_offset; if( _temp3747.base == 0? 1:( _temp3749 < _temp3747.base? 1:
_temp3749 >= _temp3747.last_plus_one)){ _throw( Null_Exception);}* _temp3749;}).last_line));
_temp3733;}); _temp3732;})); _temp3731;}); _temp3730;}); break;} case 109:
_LL3729: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct* _temp3760=(
struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3760[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3761; _temp3761.tag=
Cyc_TypeSpecifier_tok; _temp3761.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_TunionType_struct* _temp3762=( struct Cyc_Absyn_TunionType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TunionType_struct)); _temp3762[ 0]=({ struct
Cyc_Absyn_TunionType_struct _temp3763; _temp3763.tag= Cyc_Absyn_TunionType;
_temp3763.f1=({ struct Cyc_Absyn_TunionInfo _temp3764; _temp3764.tunion_info=(
void*)(( void*)({ struct Cyc_Absyn_UnknownTunion_struct* _temp3768=( struct Cyc_Absyn_UnknownTunion_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnknownTunion_struct)); _temp3768[ 0]=({
struct Cyc_Absyn_UnknownTunion_struct _temp3769; _temp3769.tag= Cyc_Absyn_UnknownTunion;
_temp3769.f1=({ struct Cyc_Absyn_UnknownTunionInfo _temp3770; _temp3770.name=
Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp3774= yyvs; void** _temp3776=
_temp3774.curr +( yyvsp_offset - 1); if( _temp3774.base == 0? 1:( _temp3776 <
_temp3774.base? 1: _temp3776 >= _temp3774.last_plus_one)){ _throw(
Null_Exception);}* _temp3776;})); _temp3770.is_xtunion= Cyc_yyget_Bool_tok(({
struct _tagged_ptr2 _temp3771= yyvs; void** _temp3773= _temp3771.curr +(
yyvsp_offset - 2); if( _temp3771.base == 0? 1:( _temp3773 < _temp3771.base? 1:
_temp3773 >= _temp3771.last_plus_one)){ _throw( Null_Exception);}* _temp3773;}));
_temp3770;}); _temp3769;}); _temp3768;})); _temp3764.targs= Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp3765= yyvs; void** _temp3767= _temp3765.curr +
yyvsp_offset; if( _temp3765.base == 0? 1:( _temp3767 < _temp3765.base? 1:
_temp3767 >= _temp3765.last_plus_one)){ _throw( Null_Exception);}* _temp3767;}));
_temp3764.rgn=( void*)(( void*) Cyc_Absyn_HeapRgn); _temp3764;}); _temp3763;});
_temp3762;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3777= yyls;
struct Cyc_Yyltype* _temp3779= _temp3777.curr +( yylsp_offset - 2); if(
_temp3777.base == 0? 1:( _temp3779 < _temp3777.base? 1: _temp3779 >= _temp3777.last_plus_one)){
_throw( Null_Exception);}* _temp3779;}).first_line,({ struct _tagged_ptr3
_temp3780= yyls; struct Cyc_Yyltype* _temp3782= _temp3780.curr + yylsp_offset;
if( _temp3780.base == 0? 1:( _temp3782 < _temp3780.base? 1: _temp3782 >=
_temp3780.last_plus_one)){ _throw( Null_Exception);}* _temp3782;}).last_line));
_temp3761;}); _temp3760;}); break; case 110: _LL3759: yyval=( void*)({ struct
Cyc_TypeSpecifier_tok_struct* _temp3784=( struct Cyc_TypeSpecifier_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct)); _temp3784[ 0]=({
struct Cyc_TypeSpecifier_tok_struct _temp3785; _temp3785.tag= Cyc_TypeSpecifier_tok;
_temp3785.f1=( void*) Cyc_Parse_type_spec(( void*)({ struct Cyc_Absyn_TunionType_struct*
_temp3786=( struct Cyc_Absyn_TunionType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_TunionType_struct));
_temp3786[ 0]=({ struct Cyc_Absyn_TunionType_struct _temp3787; _temp3787.tag=
Cyc_Absyn_TunionType; _temp3787.f1=({ struct Cyc_Absyn_TunionInfo _temp3788;
_temp3788.tunion_info=( void*)(( void*)({ struct Cyc_Absyn_UnknownTunion_struct*
_temp3795=( struct Cyc_Absyn_UnknownTunion_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_UnknownTunion_struct)); _temp3795[ 0]=({ struct Cyc_Absyn_UnknownTunion_struct
_temp3796; _temp3796.tag= Cyc_Absyn_UnknownTunion; _temp3796.f1=({ struct Cyc_Absyn_UnknownTunionInfo
_temp3797; _temp3797.name= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp3801=
yyvs; void** _temp3803= _temp3801.curr +( yyvsp_offset - 1); if( _temp3801.base
== 0? 1:( _temp3803 < _temp3801.base? 1: _temp3803 >= _temp3801.last_plus_one)){
_throw( Null_Exception);}* _temp3803;})); _temp3797.is_xtunion= Cyc_yyget_Bool_tok(({
struct _tagged_ptr2 _temp3798= yyvs; void** _temp3800= _temp3798.curr +(
yyvsp_offset - 3); if( _temp3798.base == 0? 1:( _temp3800 < _temp3798.base? 1:
_temp3800 >= _temp3798.last_plus_one)){ _throw( Null_Exception);}* _temp3800;}));
_temp3797;}); _temp3796;}); _temp3795;})); _temp3788.targs= Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp3792= yyvs; void** _temp3794= _temp3792.curr +
yyvsp_offset; if( _temp3792.base == 0? 1:( _temp3794 < _temp3792.base? 1:
_temp3794 >= _temp3792.last_plus_one)){ _throw( Null_Exception);}* _temp3794;}));
_temp3788.rgn=( void*) Cyc_yyget_Rgn_tok(({ struct _tagged_ptr2 _temp3789= yyvs;
void** _temp3791= _temp3789.curr +( yyvsp_offset - 2); if( _temp3789.base == 0?
1:( _temp3791 < _temp3789.base? 1: _temp3791 >= _temp3789.last_plus_one)){
_throw( Null_Exception);}* _temp3791;})); _temp3788;}); _temp3787;}); _temp3786;}),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp3804= yyls; struct Cyc_Yyltype*
_temp3806= _temp3804.curr +( yylsp_offset - 3); if( _temp3804.base == 0? 1:(
_temp3806 < _temp3804.base? 1: _temp3806 >= _temp3804.last_plus_one)){ _throw(
Null_Exception);}* _temp3806;}).first_line,({ struct _tagged_ptr3 _temp3807=
yyls; struct Cyc_Yyltype* _temp3809= _temp3807.curr + yylsp_offset; if(
_temp3807.base == 0? 1:( _temp3809 < _temp3807.base? 1: _temp3809 >= _temp3807.last_plus_one)){
_throw( Null_Exception);}* _temp3809;}).last_line)); _temp3785;}); _temp3784;});
break; case 111: _LL3783: yyval=( void*)({ struct Cyc_TypeSpecifier_tok_struct*
_temp3811=( struct Cyc_TypeSpecifier_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeSpecifier_tok_struct));
_temp3811[ 0]=({ struct Cyc_TypeSpecifier_tok_struct _temp3812; _temp3812.tag=
Cyc_TypeSpecifier_tok; _temp3812.f1=( void*) Cyc_Parse_type_spec(( void*)({
struct Cyc_Absyn_TunionFieldType_struct* _temp3813=( struct Cyc_Absyn_TunionFieldType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TunionFieldType_struct)); _temp3813[ 0]=({
struct Cyc_Absyn_TunionFieldType_struct _temp3814; _temp3814.tag= Cyc_Absyn_TunionFieldType;
_temp3814.f1=({ struct Cyc_Absyn_TunionFieldInfo _temp3815; _temp3815.field_info=(
void*)(( void*)({ struct Cyc_Absyn_UnknownTunionfield_struct* _temp3819=( struct
Cyc_Absyn_UnknownTunionfield_struct*) GC_malloc( sizeof( struct Cyc_Absyn_UnknownTunionfield_struct));
_temp3819[ 0]=({ struct Cyc_Absyn_UnknownTunionfield_struct _temp3820; _temp3820.tag=
Cyc_Absyn_UnknownTunionfield; _temp3820.f1=({ struct Cyc_Absyn_UnknownTunionFieldInfo
_temp3821; _temp3821.tunion_name= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2
_temp3828= yyvs; void** _temp3830= _temp3828.curr +( yyvsp_offset - 3); if(
_temp3828.base == 0? 1:( _temp3830 < _temp3828.base? 1: _temp3830 >= _temp3828.last_plus_one)){
_throw( Null_Exception);}* _temp3830;})); _temp3821.field_name= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3825= yyvs; void** _temp3827= _temp3825.curr +(
yyvsp_offset - 1); if( _temp3825.base == 0? 1:( _temp3827 < _temp3825.base? 1:
_temp3827 >= _temp3825.last_plus_one)){ _throw( Null_Exception);}* _temp3827;}));
_temp3821.is_xtunion= Cyc_yyget_Bool_tok(({ struct _tagged_ptr2 _temp3822= yyvs;
void** _temp3824= _temp3822.curr +( yyvsp_offset - 4); if( _temp3822.base == 0?
1:( _temp3824 < _temp3822.base? 1: _temp3824 >= _temp3822.last_plus_one)){
_throw( Null_Exception);}* _temp3824;})); _temp3821;}); _temp3820;}); _temp3819;}));
_temp3815.targs= Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp3816= yyvs;
void** _temp3818= _temp3816.curr + yyvsp_offset; if( _temp3816.base == 0? 1:(
_temp3818 < _temp3816.base? 1: _temp3818 >= _temp3816.last_plus_one)){ _throw(
Null_Exception);}* _temp3818;})); _temp3815;}); _temp3814;}); _temp3813;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3831= yyls; struct Cyc_Yyltype* _temp3833= _temp3831.curr
+( yylsp_offset - 4); if( _temp3831.base == 0? 1:( _temp3833 < _temp3831.base? 1:
_temp3833 >= _temp3831.last_plus_one)){ _throw( Null_Exception);}* _temp3833;}).first_line,({
struct _tagged_ptr3 _temp3834= yyls; struct Cyc_Yyltype* _temp3836= _temp3834.curr
+ yylsp_offset; if( _temp3834.base == 0? 1:( _temp3836 < _temp3834.base? 1:
_temp3836 >= _temp3834.last_plus_one)){ _throw( Null_Exception);}* _temp3836;}).last_line));
_temp3812;}); _temp3811;}); break; case 112: _LL3810: yyval=( void*)({ struct
Cyc_Bool_tok_struct* _temp3838=( struct Cyc_Bool_tok_struct*) GC_malloc( sizeof(
struct Cyc_Bool_tok_struct)); _temp3838[ 0]=({ struct Cyc_Bool_tok_struct
_temp3839; _temp3839.tag= Cyc_Bool_tok; _temp3839.f1= 0; _temp3839;}); _temp3838;});
break; case 113: _LL3837: yyval=( void*)({ struct Cyc_Bool_tok_struct* _temp3841=(
struct Cyc_Bool_tok_struct*) GC_malloc( sizeof( struct Cyc_Bool_tok_struct));
_temp3841[ 0]=({ struct Cyc_Bool_tok_struct _temp3842; _temp3842.tag= Cyc_Bool_tok;
_temp3842.f1= 1; _temp3842;}); _temp3841;}); break; case 114: _LL3840: yyval=(
void*)({ struct Cyc_TunionFieldList_tok_struct* _temp3844=( struct Cyc_TunionFieldList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TunionFieldList_tok_struct)); _temp3844[ 0]=({
struct Cyc_TunionFieldList_tok_struct _temp3845; _temp3845.tag= Cyc_TunionFieldList_tok;
_temp3845.f1=({ struct Cyc_List_List* _temp3846=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp3846->hd=( void*) Cyc_yyget_TunionField_tok(({
struct _tagged_ptr2 _temp3847= yyvs; void** _temp3849= _temp3847.curr +
yyvsp_offset; if( _temp3847.base == 0? 1:( _temp3849 < _temp3847.base? 1:
_temp3849 >= _temp3847.last_plus_one)){ _throw( Null_Exception);}* _temp3849;}));
_temp3846->tl= 0; _temp3846;}); _temp3845;}); _temp3844;}); break; case 115:
_LL3843: yyval=( void*)({ struct Cyc_TunionFieldList_tok_struct* _temp3851=(
struct Cyc_TunionFieldList_tok_struct*) GC_malloc( sizeof( struct Cyc_TunionFieldList_tok_struct));
_temp3851[ 0]=({ struct Cyc_TunionFieldList_tok_struct _temp3852; _temp3852.tag=
Cyc_TunionFieldList_tok; _temp3852.f1=({ struct Cyc_List_List* _temp3853=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp3853->hd=(
void*) Cyc_yyget_TunionField_tok(({ struct _tagged_ptr2 _temp3854= yyvs; void**
_temp3856= _temp3854.curr +( yyvsp_offset - 1); if( _temp3854.base == 0? 1:(
_temp3856 < _temp3854.base? 1: _temp3856 >= _temp3854.last_plus_one)){ _throw(
Null_Exception);}* _temp3856;})); _temp3853->tl= 0; _temp3853;}); _temp3852;});
_temp3851;}); break; case 116: _LL3850: yyval=( void*)({ struct Cyc_TunionFieldList_tok_struct*
_temp3858=( struct Cyc_TunionFieldList_tok_struct*) GC_malloc( sizeof( struct
Cyc_TunionFieldList_tok_struct)); _temp3858[ 0]=({ struct Cyc_TunionFieldList_tok_struct
_temp3859; _temp3859.tag= Cyc_TunionFieldList_tok; _temp3859.f1=({ struct Cyc_List_List*
_temp3860=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp3860->hd=( void*) Cyc_yyget_TunionField_tok(({ struct _tagged_ptr2
_temp3864= yyvs; void** _temp3866= _temp3864.curr +( yyvsp_offset - 2); if(
_temp3864.base == 0? 1:( _temp3866 < _temp3864.base? 1: _temp3866 >= _temp3864.last_plus_one)){
_throw( Null_Exception);}* _temp3866;})); _temp3860->tl= Cyc_yyget_TunionFieldList_tok(({
struct _tagged_ptr2 _temp3861= yyvs; void** _temp3863= _temp3861.curr +
yyvsp_offset; if( _temp3861.base == 0? 1:( _temp3863 < _temp3861.base? 1:
_temp3863 >= _temp3861.last_plus_one)){ _throw( Null_Exception);}* _temp3863;}));
_temp3860;}); _temp3859;}); _temp3858;}); break; case 117: _LL3857: yyval=( void*)({
struct Cyc_TunionFieldList_tok_struct* _temp3868=( struct Cyc_TunionFieldList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TunionFieldList_tok_struct)); _temp3868[ 0]=({
struct Cyc_TunionFieldList_tok_struct _temp3869; _temp3869.tag= Cyc_TunionFieldList_tok;
_temp3869.f1=({ struct Cyc_List_List* _temp3870=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp3870->hd=( void*) Cyc_yyget_TunionField_tok(({
struct _tagged_ptr2 _temp3874= yyvs; void** _temp3876= _temp3874.curr +(
yyvsp_offset - 2); if( _temp3874.base == 0? 1:( _temp3876 < _temp3874.base? 1:
_temp3876 >= _temp3874.last_plus_one)){ _throw( Null_Exception);}* _temp3876;}));
_temp3870->tl= Cyc_yyget_TunionFieldList_tok(({ struct _tagged_ptr2 _temp3871=
yyvs; void** _temp3873= _temp3871.curr + yyvsp_offset; if( _temp3871.base == 0?
1:( _temp3873 < _temp3871.base? 1: _temp3873 >= _temp3871.last_plus_one)){
_throw( Null_Exception);}* _temp3873;})); _temp3870;}); _temp3869;}); _temp3868;});
break; case 118: _LL3867: yyval=( void*)({ struct Cyc_TunionField_tok_struct*
_temp3878=( struct Cyc_TunionField_tok_struct*) GC_malloc( sizeof( struct Cyc_TunionField_tok_struct));
_temp3878[ 0]=({ struct Cyc_TunionField_tok_struct _temp3879; _temp3879.tag= Cyc_TunionField_tok;
_temp3879.f1=({ struct Cyc_Absyn_Tunionfield* _temp3880=( struct Cyc_Absyn_Tunionfield*)
GC_malloc( sizeof( struct Cyc_Absyn_Tunionfield)); _temp3880->name= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3887= yyvs; void** _temp3889= _temp3887.curr +
yyvsp_offset; if( _temp3887.base == 0? 1:( _temp3889 < _temp3887.base? 1:
_temp3889 >= _temp3887.last_plus_one)){ _throw( Null_Exception);}* _temp3889;}));
_temp3880->tvs= 0; _temp3880->typs= 0; _temp3880->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3881= yyls; struct Cyc_Yyltype* _temp3883= _temp3881.curr
+ yylsp_offset; if( _temp3881.base == 0? 1:( _temp3883 < _temp3881.base? 1:
_temp3883 >= _temp3881.last_plus_one)){ _throw( Null_Exception);}* _temp3883;}).first_line,({
struct _tagged_ptr3 _temp3884= yyls; struct Cyc_Yyltype* _temp3886= _temp3884.curr
+ yylsp_offset; if( _temp3884.base == 0? 1:( _temp3886 < _temp3884.base? 1:
_temp3886 >= _temp3884.last_plus_one)){ _throw( Null_Exception);}* _temp3886;}).last_line);
_temp3880;}); _temp3879;}); _temp3878;}); break; case 119: _LL3877: { struct Cyc_List_List*
typs=(( struct Cyc_List_List*(*)( struct _tuple10*(* f)( struct Cyc_Position_Segment*,
struct _tuple2*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x))
Cyc_List_map_c)( Cyc_Parse_get_tqual_typ, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp3912= yyls; struct Cyc_Yyltype* _temp3914= _temp3912.curr +(
yylsp_offset - 1); if( _temp3912.base == 0? 1:( _temp3914 < _temp3912.base? 1:
_temp3914 >= _temp3912.last_plus_one)){ _throw( Null_Exception);}* _temp3914;}).first_line,({
struct _tagged_ptr3 _temp3915= yyls; struct Cyc_Yyltype* _temp3917= _temp3915.curr
+( yylsp_offset - 1); if( _temp3915.base == 0? 1:( _temp3917 < _temp3915.base? 1:
_temp3917 >= _temp3915.last_plus_one)){ _throw( Null_Exception);}* _temp3917;}).last_line),((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_ParamDeclList_tok(({
struct _tagged_ptr2 _temp3918= yyvs; void** _temp3920= _temp3918.curr +(
yyvsp_offset - 1); if( _temp3918.base == 0? 1:( _temp3920 < _temp3918.base? 1:
_temp3920 >= _temp3918.last_plus_one)){ _throw( Null_Exception);}* _temp3920;}))));
struct Cyc_List_List* tvs=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(*
f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment* env,
struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3903= yyls; struct Cyc_Yyltype* _temp3905= _temp3903.curr
+( yylsp_offset - 3); if( _temp3903.base == 0? 1:( _temp3905 < _temp3903.base? 1:
_temp3905 >= _temp3903.last_plus_one)){ _throw( Null_Exception);}* _temp3905;}).first_line,({
struct _tagged_ptr3 _temp3906= yyls; struct Cyc_Yyltype* _temp3908= _temp3906.curr
+( yylsp_offset - 3); if( _temp3906.base == 0? 1:( _temp3908 < _temp3906.base? 1:
_temp3908 >= _temp3906.last_plus_one)){ _throw( Null_Exception);}* _temp3908;}).last_line),
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp3909= yyvs; void** _temp3911=
_temp3909.curr +( yyvsp_offset - 3); if( _temp3909.base == 0? 1:( _temp3911 <
_temp3909.base? 1: _temp3911 >= _temp3909.last_plus_one)){ _throw(
Null_Exception);}* _temp3911;}))); yyval=( void*)({ struct Cyc_TunionField_tok_struct*
_temp3891=( struct Cyc_TunionField_tok_struct*) GC_malloc( sizeof( struct Cyc_TunionField_tok_struct));
_temp3891[ 0]=({ struct Cyc_TunionField_tok_struct _temp3892; _temp3892.tag= Cyc_TunionField_tok;
_temp3892.f1=({ struct Cyc_Absyn_Tunionfield* _temp3893=( struct Cyc_Absyn_Tunionfield*)
GC_malloc( sizeof( struct Cyc_Absyn_Tunionfield)); _temp3893->name= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3900= yyvs; void** _temp3902= _temp3900.curr +(
yyvsp_offset - 4); if( _temp3900.base == 0? 1:( _temp3902 < _temp3900.base? 1:
_temp3902 >= _temp3900.last_plus_one)){ _throw( Null_Exception);}* _temp3902;}));
_temp3893->tvs= tvs; _temp3893->typs= typs; _temp3893->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp3894= yyls; struct Cyc_Yyltype* _temp3896= _temp3894.curr
+( yylsp_offset - 4); if( _temp3894.base == 0? 1:( _temp3896 < _temp3894.base? 1:
_temp3896 >= _temp3894.last_plus_one)){ _throw( Null_Exception);}* _temp3896;}).first_line,({
struct _tagged_ptr3 _temp3897= yyls; struct Cyc_Yyltype* _temp3899= _temp3897.curr
+ yylsp_offset; if( _temp3897.base == 0? 1:( _temp3899 < _temp3897.base? 1:
_temp3899 >= _temp3897.last_plus_one)){ _throw( Null_Exception);}* _temp3899;}).last_line);
_temp3893;}); _temp3892;}); _temp3891;}); break;} case 120: _LL3890: yyval=({
struct _tagged_ptr2 _temp3922= yyvs; void** _temp3924= _temp3922.curr +
yyvsp_offset; if( _temp3922.base == 0? 1:( _temp3924 < _temp3922.base? 1:
_temp3924 >= _temp3922.last_plus_one)){ _throw( Null_Exception);}* _temp3924;});
break; case 121: _LL3921: yyval=( void*)({ struct Cyc_Declarator_tok_struct*
_temp3926=( struct Cyc_Declarator_tok_struct*) GC_malloc( sizeof( struct Cyc_Declarator_tok_struct));
_temp3926[ 0]=({ struct Cyc_Declarator_tok_struct _temp3927; _temp3927.tag= Cyc_Declarator_tok;
_temp3927.f1=({ struct Cyc_Parse_Declarator* _temp3928=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp3928->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp3935= yyvs; void** _temp3937= _temp3935.curr +
yyvsp_offset; if( _temp3935.base == 0? 1:( _temp3937 < _temp3935.base? 1:
_temp3937 >= _temp3935.last_plus_one)){ _throw( Null_Exception);}* _temp3937;})))->id;
_temp3928->tms=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List*
y)) Cyc_List_imp_append)( Cyc_yyget_TypeModifierList_tok(({ struct _tagged_ptr2
_temp3929= yyvs; void** _temp3931= _temp3929.curr +( yyvsp_offset - 1); if(
_temp3929.base == 0? 1:( _temp3931 < _temp3929.base? 1: _temp3931 >= _temp3929.last_plus_one)){
_throw( Null_Exception);}* _temp3931;})),( Cyc_yyget_Declarator_tok(({ struct
_tagged_ptr2 _temp3932= yyvs; void** _temp3934= _temp3932.curr + yyvsp_offset;
if( _temp3932.base == 0? 1:( _temp3934 < _temp3932.base? 1: _temp3934 >=
_temp3932.last_plus_one)){ _throw( Null_Exception);}* _temp3934;})))->tms);
_temp3928;}); _temp3927;}); _temp3926;}); break; case 122: _LL3925: yyval=( void*)({
struct Cyc_Declarator_tok_struct* _temp3939=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp3939[ 0]=({ struct
Cyc_Declarator_tok_struct _temp3940; _temp3940.tag= Cyc_Declarator_tok;
_temp3940.f1=({ struct Cyc_Parse_Declarator* _temp3941=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp3941->id= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp3942= yyvs; void** _temp3944= _temp3942.curr +
yyvsp_offset; if( _temp3942.base == 0? 1:( _temp3944 < _temp3942.base? 1:
_temp3944 >= _temp3942.last_plus_one)){ _throw( Null_Exception);}* _temp3944;}));
_temp3941->tms= 0; _temp3941;}); _temp3940;}); _temp3939;}); break; case 123:
_LL3938: yyval=({ struct _tagged_ptr2 _temp3946= yyvs; void** _temp3948=
_temp3946.curr +( yyvsp_offset - 1); if( _temp3946.base == 0? 1:( _temp3948 <
_temp3946.base? 1: _temp3948 >= _temp3946.last_plus_one)){ _throw(
Null_Exception);}* _temp3948;}); break; case 124: _LL3945: yyval=( void*)({
struct Cyc_Declarator_tok_struct* _temp3950=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp3950[ 0]=({ struct
Cyc_Declarator_tok_struct _temp3951; _temp3951.tag= Cyc_Declarator_tok;
_temp3951.f1=({ struct Cyc_Parse_Declarator* _temp3952=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp3952->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp3957= yyvs; void** _temp3959= _temp3957.curr +(
yyvsp_offset - 2); if( _temp3957.base == 0? 1:( _temp3959 < _temp3957.base? 1:
_temp3959 >= _temp3957.last_plus_one)){ _throw( Null_Exception);}* _temp3959;})))->id;
_temp3952->tms=({ struct Cyc_List_List* _temp3953=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp3953->hd=( void*)(( void*) Cyc_Absyn_Carray_mod);
_temp3953->tl=( Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2 _temp3954= yyvs;
void** _temp3956= _temp3954.curr +( yyvsp_offset - 2); if( _temp3954.base == 0?
1:( _temp3956 < _temp3954.base? 1: _temp3956 >= _temp3954.last_plus_one)){
_throw( Null_Exception);}* _temp3956;})))->tms; _temp3953;}); _temp3952;});
_temp3951;}); _temp3950;}); break; case 125: _LL3949: yyval=( void*)({ struct
Cyc_Declarator_tok_struct* _temp3961=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp3961[ 0]=({ struct
Cyc_Declarator_tok_struct _temp3962; _temp3962.tag= Cyc_Declarator_tok;
_temp3962.f1=({ struct Cyc_Parse_Declarator* _temp3963=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp3963->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp3973= yyvs; void** _temp3975= _temp3973.curr +(
yyvsp_offset - 3); if( _temp3973.base == 0? 1:( _temp3975 < _temp3973.base? 1:
_temp3975 >= _temp3973.last_plus_one)){ _throw( Null_Exception);}* _temp3975;})))->id;
_temp3963->tms=({ struct Cyc_List_List* _temp3964=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp3964->hd=( void*)(( void*)({
struct Cyc_Absyn_ConstArray_mod_struct* _temp3968=( struct Cyc_Absyn_ConstArray_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_ConstArray_mod_struct)); _temp3968[ 0]=({
struct Cyc_Absyn_ConstArray_mod_struct _temp3969; _temp3969.tag= Cyc_Absyn_ConstArray_mod;
_temp3969.f1= Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp3970= yyvs; void**
_temp3972= _temp3970.curr +( yyvsp_offset - 1); if( _temp3970.base == 0? 1:(
_temp3972 < _temp3970.base? 1: _temp3972 >= _temp3970.last_plus_one)){ _throw(
Null_Exception);}* _temp3972;})); _temp3969;}); _temp3968;})); _temp3964->tl=(
Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2 _temp3965= yyvs; void**
_temp3967= _temp3965.curr +( yyvsp_offset - 3); if( _temp3965.base == 0? 1:(
_temp3967 < _temp3965.base? 1: _temp3967 >= _temp3965.last_plus_one)){ _throw(
Null_Exception);}* _temp3967;})))->tms; _temp3964;}); _temp3963;}); _temp3962;});
_temp3961;}); break; case 126: _LL3960: { struct _tuple16 _temp3982; struct Cyc_Core_Opt*
_temp3983; int _temp3985; struct Cyc_List_List* _temp3987; struct _tuple16*
_temp3980= Cyc_yyget_ParamDeclListBool_tok(({ struct _tagged_ptr2 _temp3977=
yyvs; void** _temp3979= _temp3977.curr +( yyvsp_offset - 1); if( _temp3977.base
== 0? 1:( _temp3979 < _temp3977.base? 1: _temp3979 >= _temp3977.last_plus_one)){
_throw( Null_Exception);}* _temp3979;})); _temp3982=* _temp3980; _LL3988:
_temp3987= _temp3982.f1; goto _LL3986; _LL3986: _temp3985= _temp3982.f2; goto
_LL3984; _LL3984: _temp3983= _temp3982.f3; goto _LL3981; _LL3981: yyval=( void*)({
struct Cyc_Declarator_tok_struct* _temp3989=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp3989[ 0]=({ struct
Cyc_Declarator_tok_struct _temp3990; _temp3990.tag= Cyc_Declarator_tok;
_temp3990.f1=({ struct Cyc_Parse_Declarator* _temp3991=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp3991->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4000= yyvs; void** _temp4002= _temp4000.curr +(
yyvsp_offset - 3); if( _temp4000.base == 0? 1:( _temp4002 < _temp4000.base? 1:
_temp4002 >= _temp4000.last_plus_one)){ _throw( Null_Exception);}* _temp4002;})))->id;
_temp3991->tms=({ struct Cyc_List_List* _temp3992=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp3992->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp3996=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp3996[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp3997; _temp3997.tag= Cyc_Absyn_Function_mod;
_temp3997.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp3998=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp3998[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp3999; _temp3999.tag= Cyc_Absyn_WithTypes;
_temp3999.f1= _temp3987; _temp3999.f2= _temp3985; _temp3999.f3= _temp3983;
_temp3999;}); _temp3998;})); _temp3997;}); _temp3996;})); _temp3992->tl=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp3993= yyvs; void** _temp3995= _temp3993.curr +(
yyvsp_offset - 3); if( _temp3993.base == 0? 1:( _temp3995 < _temp3993.base? 1:
_temp3995 >= _temp3993.last_plus_one)){ _throw( Null_Exception);}* _temp3995;})))->tms;
_temp3992;}); _temp3991;}); _temp3990;}); _temp3989;}); break;} case 127:
_LL3976: yyval=( void*)({ struct Cyc_Declarator_tok_struct* _temp4004=( struct
Cyc_Declarator_tok_struct*) GC_malloc( sizeof( struct Cyc_Declarator_tok_struct));
_temp4004[ 0]=({ struct Cyc_Declarator_tok_struct _temp4005; _temp4005.tag= Cyc_Declarator_tok;
_temp4005.f1=({ struct Cyc_Parse_Declarator* _temp4006=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp4006->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4015= yyvs; void** _temp4017= _temp4015.curr +(
yyvsp_offset - 2); if( _temp4015.base == 0? 1:( _temp4017 < _temp4015.base? 1:
_temp4017 >= _temp4015.last_plus_one)){ _throw( Null_Exception);}* _temp4017;})))->id;
_temp4006->tms=({ struct Cyc_List_List* _temp4007=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4007->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp4011=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp4011[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp4012; _temp4012.tag= Cyc_Absyn_Function_mod;
_temp4012.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp4013=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp4013[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp4014; _temp4014.tag= Cyc_Absyn_WithTypes;
_temp4014.f1= 0; _temp4014.f2= 0; _temp4014.f3= 0; _temp4014;}); _temp4013;}));
_temp4012;}); _temp4011;})); _temp4007->tl=( Cyc_yyget_Declarator_tok(({ struct
_tagged_ptr2 _temp4008= yyvs; void** _temp4010= _temp4008.curr +( yyvsp_offset -
2); if( _temp4008.base == 0? 1:( _temp4010 < _temp4008.base? 1: _temp4010 >=
_temp4008.last_plus_one)){ _throw( Null_Exception);}* _temp4010;})))->tms;
_temp4007;}); _temp4006;}); _temp4005;}); _temp4004;}); break; case 128: _LL4003:
yyval=( void*)({ struct Cyc_Declarator_tok_struct* _temp4019=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp4019[ 0]=({ struct
Cyc_Declarator_tok_struct _temp4020; _temp4020.tag= Cyc_Declarator_tok;
_temp4020.f1=({ struct Cyc_Parse_Declarator* _temp4021=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp4021->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4036= yyvs; void** _temp4038= _temp4036.curr +(
yyvsp_offset - 4); if( _temp4036.base == 0? 1:( _temp4038 < _temp4036.base? 1:
_temp4038 >= _temp4036.last_plus_one)){ _throw( Null_Exception);}* _temp4038;})))->id;
_temp4021->tms=({ struct Cyc_List_List* _temp4022=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4022->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp4026=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp4026[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp4027; _temp4027.tag= Cyc_Absyn_Function_mod;
_temp4027.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp4028=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp4028[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp4029; _temp4029.tag= Cyc_Absyn_WithTypes;
_temp4029.f1= 0; _temp4029.f2= 0; _temp4029.f3=({ struct Cyc_Core_Opt* _temp4030=(
struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp4030->v=(
void*)(( void*)({ struct Cyc_Absyn_JoinEff_struct* _temp4031=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp4031[ 0]=({ struct
Cyc_Absyn_JoinEff_struct _temp4032; _temp4032.tag= Cyc_Absyn_JoinEff; _temp4032.f1=
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp4033= yyvs; void** _temp4035=
_temp4033.curr +( yyvsp_offset - 1); if( _temp4033.base == 0? 1:( _temp4035 <
_temp4033.base? 1: _temp4035 >= _temp4033.last_plus_one)){ _throw(
Null_Exception);}* _temp4035;})); _temp4032;}); _temp4031;})); _temp4030;});
_temp4029;}); _temp4028;})); _temp4027;}); _temp4026;})); _temp4022->tl=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4023= yyvs; void** _temp4025= _temp4023.curr +(
yyvsp_offset - 4); if( _temp4023.base == 0? 1:( _temp4025 < _temp4023.base? 1:
_temp4025 >= _temp4023.last_plus_one)){ _throw( Null_Exception);}* _temp4025;})))->tms;
_temp4022;}); _temp4021;}); _temp4020;}); _temp4019;}); break; case 129: _LL4018:
yyval=( void*)({ struct Cyc_Declarator_tok_struct* _temp4040=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp4040[ 0]=({ struct
Cyc_Declarator_tok_struct _temp4041; _temp4041.tag= Cyc_Declarator_tok;
_temp4041.f1=({ struct Cyc_Parse_Declarator* _temp4042=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp4042->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4060= yyvs; void** _temp4062= _temp4060.curr +(
yyvsp_offset - 3); if( _temp4060.base == 0? 1:( _temp4062 < _temp4060.base? 1:
_temp4062 >= _temp4060.last_plus_one)){ _throw( Null_Exception);}* _temp4062;})))->id;
_temp4042->tms=({ struct Cyc_List_List* _temp4043=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4043->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp4047=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp4047[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp4048; _temp4048.tag= Cyc_Absyn_Function_mod;
_temp4048.f1=( void*)(( void*)({ struct Cyc_Absyn_NoTypes_struct* _temp4049=(
struct Cyc_Absyn_NoTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_NoTypes_struct));
_temp4049[ 0]=({ struct Cyc_Absyn_NoTypes_struct _temp4050; _temp4050.tag= Cyc_Absyn_NoTypes;
_temp4050.f1= Cyc_yyget_IdList_tok(({ struct _tagged_ptr2 _temp4051= yyvs; void**
_temp4053= _temp4051.curr +( yyvsp_offset - 1); if( _temp4051.base == 0? 1:(
_temp4053 < _temp4051.base? 1: _temp4053 >= _temp4051.last_plus_one)){ _throw(
Null_Exception);}* _temp4053;})); _temp4050.f2= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4054= yyls; struct Cyc_Yyltype* _temp4056= _temp4054.curr
+( yylsp_offset - 3); if( _temp4054.base == 0? 1:( _temp4056 < _temp4054.base? 1:
_temp4056 >= _temp4054.last_plus_one)){ _throw( Null_Exception);}* _temp4056;}).first_line,({
struct _tagged_ptr3 _temp4057= yyls; struct Cyc_Yyltype* _temp4059= _temp4057.curr
+ yylsp_offset; if( _temp4057.base == 0? 1:( _temp4059 < _temp4057.base? 1:
_temp4059 >= _temp4057.last_plus_one)){ _throw( Null_Exception);}* _temp4059;}).last_line);
_temp4050;}); _temp4049;})); _temp4048;}); _temp4047;})); _temp4043->tl=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4044= yyvs; void** _temp4046= _temp4044.curr +(
yyvsp_offset - 3); if( _temp4044.base == 0? 1:( _temp4046 < _temp4044.base? 1:
_temp4046 >= _temp4044.last_plus_one)){ _throw( Null_Exception);}* _temp4046;})))->tms;
_temp4043;}); _temp4042;}); _temp4041;}); _temp4040;}); break; case 130: _LL4039: {
struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(* f)(
struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment* env, struct
Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4082= yyls; struct Cyc_Yyltype* _temp4084= _temp4082.curr
+( yylsp_offset - 2); if( _temp4082.base == 0? 1:( _temp4084 < _temp4082.base? 1:
_temp4084 >= _temp4082.last_plus_one)){ _throw( Null_Exception);}* _temp4084;}).first_line,({
struct _tagged_ptr3 _temp4085= yyls; struct Cyc_Yyltype* _temp4087= _temp4085.curr
+ yylsp_offset; if( _temp4085.base == 0? 1:( _temp4087 < _temp4085.base? 1:
_temp4087 >= _temp4085.last_plus_one)){ _throw( Null_Exception);}* _temp4087;}).last_line),((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp4088= yyvs; void** _temp4090= _temp4088.curr +(
yyvsp_offset - 1); if( _temp4088.base == 0? 1:( _temp4090 < _temp4088.base? 1:
_temp4090 >= _temp4088.last_plus_one)){ _throw( Null_Exception);}* _temp4090;}))));
yyval=( void*)({ struct Cyc_Declarator_tok_struct* _temp4064=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp4064[ 0]=({ struct
Cyc_Declarator_tok_struct _temp4065; _temp4065.tag= Cyc_Declarator_tok;
_temp4065.f1=({ struct Cyc_Parse_Declarator* _temp4066=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp4066->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4079= yyvs; void** _temp4081= _temp4079.curr +(
yyvsp_offset - 3); if( _temp4079.base == 0? 1:( _temp4081 < _temp4079.base? 1:
_temp4081 >= _temp4079.last_plus_one)){ _throw( Null_Exception);}* _temp4081;})))->id;
_temp4066->tms=({ struct Cyc_List_List* _temp4067=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4067->hd=( void*)(( void*)({
struct Cyc_Absyn_TypeParams_mod_struct* _temp4071=( struct Cyc_Absyn_TypeParams_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TypeParams_mod_struct)); _temp4071[ 0]=({
struct Cyc_Absyn_TypeParams_mod_struct _temp4072; _temp4072.tag= Cyc_Absyn_TypeParams_mod;
_temp4072.f1= ts; _temp4072.f2= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp4073= yyls; struct Cyc_Yyltype* _temp4075= _temp4073.curr +(
yylsp_offset - 3); if( _temp4073.base == 0? 1:( _temp4075 < _temp4073.base? 1:
_temp4075 >= _temp4073.last_plus_one)){ _throw( Null_Exception);}* _temp4075;}).first_line,({
struct _tagged_ptr3 _temp4076= yyls; struct Cyc_Yyltype* _temp4078= _temp4076.curr
+ yylsp_offset; if( _temp4076.base == 0? 1:( _temp4078 < _temp4076.base? 1:
_temp4078 >= _temp4076.last_plus_one)){ _throw( Null_Exception);}* _temp4078;}).last_line);
_temp4072.f3= 0; _temp4072;}); _temp4071;})); _temp4067->tl=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4068= yyvs; void** _temp4070= _temp4068.curr +(
yyvsp_offset - 3); if( _temp4068.base == 0? 1:( _temp4070 < _temp4068.base? 1:
_temp4070 >= _temp4068.last_plus_one)){ _throw( Null_Exception);}* _temp4070;})))->tms;
_temp4067;}); _temp4066;}); _temp4065;}); _temp4064;}); break;} case 131:
_LL4063:(( struct Cyc_Lexing_lexbuf*)({ struct Cyc_Core_Opt* _temp4092= Cyc_Parse_lbuf;
if( _temp4092 == 0){ _throw( Null_Exception);} _temp4092->v;}))->lex_curr_pos -=
1;{ struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(*
f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment* env,
struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4111= yyls; struct Cyc_Yyltype* _temp4113= _temp4111.curr
+( yylsp_offset - 2); if( _temp4111.base == 0? 1:( _temp4113 < _temp4111.base? 1:
_temp4113 >= _temp4111.last_plus_one)){ _throw( Null_Exception);}* _temp4113;}).first_line,({
struct _tagged_ptr3 _temp4114= yyls; struct Cyc_Yyltype* _temp4116= _temp4114.curr
+ yylsp_offset; if( _temp4114.base == 0? 1:( _temp4116 < _temp4114.base? 1:
_temp4116 >= _temp4114.last_plus_one)){ _throw( Null_Exception);}* _temp4116;}).last_line),((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp4117= yyvs; void** _temp4119= _temp4117.curr +(
yyvsp_offset - 1); if( _temp4117.base == 0? 1:( _temp4119 < _temp4117.base? 1:
_temp4119 >= _temp4117.last_plus_one)){ _throw( Null_Exception);}* _temp4119;}))));
yyval=( void*)({ struct Cyc_Declarator_tok_struct* _temp4093=( struct Cyc_Declarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Declarator_tok_struct)); _temp4093[ 0]=({ struct
Cyc_Declarator_tok_struct _temp4094; _temp4094.tag= Cyc_Declarator_tok;
_temp4094.f1=({ struct Cyc_Parse_Declarator* _temp4095=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp4095->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4108= yyvs; void** _temp4110= _temp4108.curr +(
yyvsp_offset - 3); if( _temp4108.base == 0? 1:( _temp4110 < _temp4108.base? 1:
_temp4110 >= _temp4108.last_plus_one)){ _throw( Null_Exception);}* _temp4110;})))->id;
_temp4095->tms=({ struct Cyc_List_List* _temp4096=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4096->hd=( void*)(( void*)({
struct Cyc_Absyn_TypeParams_mod_struct* _temp4100=( struct Cyc_Absyn_TypeParams_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TypeParams_mod_struct)); _temp4100[ 0]=({
struct Cyc_Absyn_TypeParams_mod_struct _temp4101; _temp4101.tag= Cyc_Absyn_TypeParams_mod;
_temp4101.f1= ts; _temp4101.f2= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp4102= yyls; struct Cyc_Yyltype* _temp4104= _temp4102.curr +(
yylsp_offset - 3); if( _temp4102.base == 0? 1:( _temp4104 < _temp4102.base? 1:
_temp4104 >= _temp4102.last_plus_one)){ _throw( Null_Exception);}* _temp4104;}).first_line,({
struct _tagged_ptr3 _temp4105= yyls; struct Cyc_Yyltype* _temp4107= _temp4105.curr
+ yylsp_offset; if( _temp4105.base == 0? 1:( _temp4107 < _temp4105.base? 1:
_temp4107 >= _temp4105.last_plus_one)){ _throw( Null_Exception);}* _temp4107;}).last_line);
_temp4101.f3= 0; _temp4101;}); _temp4100;})); _temp4096->tl=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4097= yyvs; void** _temp4099= _temp4097.curr +(
yyvsp_offset - 3); if( _temp4097.base == 0? 1:( _temp4099 < _temp4097.base? 1:
_temp4099 >= _temp4097.last_plus_one)){ _throw( Null_Exception);}* _temp4099;})))->tms;
_temp4096;}); _temp4095;}); _temp4094;}); _temp4093;}); break;} case 132:
_LL4091: yyval=( void*)({ struct Cyc_Declarator_tok_struct* _temp4121=( struct
Cyc_Declarator_tok_struct*) GC_malloc( sizeof( struct Cyc_Declarator_tok_struct));
_temp4121[ 0]=({ struct Cyc_Declarator_tok_struct _temp4122; _temp4122.tag= Cyc_Declarator_tok;
_temp4122.f1=({ struct Cyc_Parse_Declarator* _temp4123=( struct Cyc_Parse_Declarator*)
GC_malloc( sizeof( struct Cyc_Parse_Declarator)); _temp4123->id=( Cyc_yyget_Declarator_tok(({
struct _tagged_ptr2 _temp4139= yyvs; void** _temp4141= _temp4139.curr +(
yyvsp_offset - 1); if( _temp4139.base == 0? 1:( _temp4141 < _temp4139.base? 1:
_temp4141 >= _temp4139.last_plus_one)){ _throw( Null_Exception);}* _temp4141;})))->id;
_temp4123->tms=({ struct Cyc_List_List* _temp4124=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4124->hd=( void*)(( void*)({
struct Cyc_Absyn_Attributes_mod_struct* _temp4128=( struct Cyc_Absyn_Attributes_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Attributes_mod_struct)); _temp4128[ 0]=({
struct Cyc_Absyn_Attributes_mod_struct _temp4129; _temp4129.tag= Cyc_Absyn_Attributes_mod;
_temp4129.f1= Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4130= yyls;
struct Cyc_Yyltype* _temp4132= _temp4130.curr + yylsp_offset; if( _temp4130.base
== 0? 1:( _temp4132 < _temp4130.base? 1: _temp4132 >= _temp4130.last_plus_one)){
_throw( Null_Exception);}* _temp4132;}).first_line,({ struct _tagged_ptr3
_temp4133= yyls; struct Cyc_Yyltype* _temp4135= _temp4133.curr + yylsp_offset;
if( _temp4133.base == 0? 1:( _temp4135 < _temp4133.base? 1: _temp4135 >=
_temp4133.last_plus_one)){ _throw( Null_Exception);}* _temp4135;}).last_line);
_temp4129.f2= Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp4136= yyvs;
void** _temp4138= _temp4136.curr + yyvsp_offset; if( _temp4136.base == 0? 1:(
_temp4138 < _temp4136.base? 1: _temp4138 >= _temp4136.last_plus_one)){ _throw(
Null_Exception);}* _temp4138;})); _temp4129;}); _temp4128;})); _temp4124->tl=(
Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2 _temp4125= yyvs; void**
_temp4127= _temp4125.curr +( yyvsp_offset - 1); if( _temp4125.base == 0? 1:(
_temp4127 < _temp4125.base? 1: _temp4127 >= _temp4125.last_plus_one)){ _throw(
Null_Exception);}* _temp4127;})))->tms; _temp4124;}); _temp4123;}); _temp4122;});
_temp4121;}); break; case 133: _LL4120: yyval=( void*)({ struct Cyc_TypeModifierList_tok_struct*
_temp4143=( struct Cyc_TypeModifierList_tok_struct*) GC_malloc( sizeof( struct
Cyc_TypeModifierList_tok_struct)); _temp4143[ 0]=({ struct Cyc_TypeModifierList_tok_struct
_temp4144; _temp4144.tag= Cyc_TypeModifierList_tok; _temp4144.f1=({ struct Cyc_List_List*
_temp4145=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4145->hd=( void*)(( void*)({ struct Cyc_Absyn_Pointer_mod_struct* _temp4155=(
struct Cyc_Absyn_Pointer_mod_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Pointer_mod_struct));
_temp4155[ 0]=({ struct Cyc_Absyn_Pointer_mod_struct _temp4156; _temp4156.tag=
Cyc_Absyn_Pointer_mod; _temp4156.f1=( void*) Cyc_yyget_Pointer_Sort_tok(({
struct _tagged_ptr2 _temp4157= yyvs; void** _temp4159= _temp4157.curr +(
yyvsp_offset - 2); if( _temp4157.base == 0? 1:( _temp4159 < _temp4157.base? 1:
_temp4159 >= _temp4157.last_plus_one)){ _throw( Null_Exception);}* _temp4159;}));
_temp4156.f2=( void*) Cyc_yyget_Rgn_tok(({ struct _tagged_ptr2 _temp4160= yyvs;
void** _temp4162= _temp4160.curr +( yyvsp_offset - 1); if( _temp4160.base == 0?
1:( _temp4162 < _temp4160.base? 1: _temp4162 >= _temp4160.last_plus_one)){
_throw( Null_Exception);}* _temp4162;})); _temp4156.f3= Cyc_Absyn_empty_tqual();
_temp4156;}); _temp4155;})); _temp4145->tl= Cyc_Parse_attopt_to_tms( Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4146= yyls; struct Cyc_Yyltype* _temp4148= _temp4146.curr
+ yylsp_offset; if( _temp4146.base == 0? 1:( _temp4148 < _temp4146.base? 1:
_temp4148 >= _temp4146.last_plus_one)){ _throw( Null_Exception);}* _temp4148;}).first_line,({
struct _tagged_ptr3 _temp4149= yyls; struct Cyc_Yyltype* _temp4151= _temp4149.curr
+ yylsp_offset; if( _temp4149.base == 0? 1:( _temp4151 < _temp4149.base? 1:
_temp4151 >= _temp4149.last_plus_one)){ _throw( Null_Exception);}* _temp4151;}).last_line),
Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp4152= yyvs; void**
_temp4154= _temp4152.curr + yyvsp_offset; if( _temp4152.base == 0? 1:( _temp4154
< _temp4152.base? 1: _temp4154 >= _temp4152.last_plus_one)){ _throw(
Null_Exception);}* _temp4154;})), 0); _temp4145;}); _temp4144;}); _temp4143;});
break; case 134: _LL4142: yyval=( void*)({ struct Cyc_TypeModifierList_tok_struct*
_temp4164=( struct Cyc_TypeModifierList_tok_struct*) GC_malloc( sizeof( struct
Cyc_TypeModifierList_tok_struct)); _temp4164[ 0]=({ struct Cyc_TypeModifierList_tok_struct
_temp4165; _temp4165.tag= Cyc_TypeModifierList_tok; _temp4165.f1=({ struct Cyc_List_List*
_temp4166=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4166->hd=( void*)(( void*)({ struct Cyc_Absyn_Pointer_mod_struct* _temp4176=(
struct Cyc_Absyn_Pointer_mod_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Pointer_mod_struct));
_temp4176[ 0]=({ struct Cyc_Absyn_Pointer_mod_struct _temp4177; _temp4177.tag=
Cyc_Absyn_Pointer_mod; _temp4177.f1=( void*) Cyc_yyget_Pointer_Sort_tok(({
struct _tagged_ptr2 _temp4178= yyvs; void** _temp4180= _temp4178.curr +(
yyvsp_offset - 3); if( _temp4178.base == 0? 1:( _temp4180 < _temp4178.base? 1:
_temp4180 >= _temp4178.last_plus_one)){ _throw( Null_Exception);}* _temp4180;}));
_temp4177.f2=( void*) Cyc_yyget_Rgn_tok(({ struct _tagged_ptr2 _temp4181= yyvs;
void** _temp4183= _temp4181.curr +( yyvsp_offset - 2); if( _temp4181.base == 0?
1:( _temp4183 < _temp4181.base? 1: _temp4183 >= _temp4181.last_plus_one)){
_throw( Null_Exception);}* _temp4183;})); _temp4177.f3= Cyc_yyget_TypeQual_tok(({
struct _tagged_ptr2 _temp4184= yyvs; void** _temp4186= _temp4184.curr +
yyvsp_offset; if( _temp4184.base == 0? 1:( _temp4186 < _temp4184.base? 1:
_temp4186 >= _temp4184.last_plus_one)){ _throw( Null_Exception);}* _temp4186;}));
_temp4177;}); _temp4176;})); _temp4166->tl= Cyc_Parse_attopt_to_tms( Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4167= yyls; struct Cyc_Yyltype* _temp4169= _temp4167.curr
+( yylsp_offset - 1); if( _temp4167.base == 0? 1:( _temp4169 < _temp4167.base? 1:
_temp4169 >= _temp4167.last_plus_one)){ _throw( Null_Exception);}* _temp4169;}).first_line,({
struct _tagged_ptr3 _temp4170= yyls; struct Cyc_Yyltype* _temp4172= _temp4170.curr
+( yylsp_offset - 1); if( _temp4170.base == 0? 1:( _temp4172 < _temp4170.base? 1:
_temp4172 >= _temp4170.last_plus_one)){ _throw( Null_Exception);}* _temp4172;}).last_line),
Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp4173= yyvs; void**
_temp4175= _temp4173.curr +( yyvsp_offset - 1); if( _temp4173.base == 0? 1:(
_temp4175 < _temp4173.base? 1: _temp4175 >= _temp4173.last_plus_one)){ _throw(
Null_Exception);}* _temp4175;})), 0); _temp4166;}); _temp4165;}); _temp4164;});
break; case 135: _LL4163: yyval=( void*)({ struct Cyc_TypeModifierList_tok_struct*
_temp4188=( struct Cyc_TypeModifierList_tok_struct*) GC_malloc( sizeof( struct
Cyc_TypeModifierList_tok_struct)); _temp4188[ 0]=({ struct Cyc_TypeModifierList_tok_struct
_temp4189; _temp4189.tag= Cyc_TypeModifierList_tok; _temp4189.f1=({ struct Cyc_List_List*
_temp4190=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4190->hd=( void*)(( void*)({ struct Cyc_Absyn_Pointer_mod_struct* _temp4203=(
struct Cyc_Absyn_Pointer_mod_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Pointer_mod_struct));
_temp4203[ 0]=({ struct Cyc_Absyn_Pointer_mod_struct _temp4204; _temp4204.tag=
Cyc_Absyn_Pointer_mod; _temp4204.f1=( void*) Cyc_yyget_Pointer_Sort_tok(({
struct _tagged_ptr2 _temp4205= yyvs; void** _temp4207= _temp4205.curr +(
yyvsp_offset - 3); if( _temp4205.base == 0? 1:( _temp4207 < _temp4205.base? 1:
_temp4207 >= _temp4205.last_plus_one)){ _throw( Null_Exception);}* _temp4207;}));
_temp4204.f2=( void*) Cyc_yyget_Rgn_tok(({ struct _tagged_ptr2 _temp4208= yyvs;
void** _temp4210= _temp4208.curr +( yyvsp_offset - 2); if( _temp4208.base == 0?
1:( _temp4210 < _temp4208.base? 1: _temp4210 >= _temp4208.last_plus_one)){
_throw( Null_Exception);}* _temp4210;})); _temp4204.f3= Cyc_Absyn_empty_tqual();
_temp4204;}); _temp4203;})); _temp4190->tl= Cyc_Parse_attopt_to_tms( Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4191= yyls; struct Cyc_Yyltype* _temp4193= _temp4191.curr
+( yylsp_offset - 1); if( _temp4191.base == 0? 1:( _temp4193 < _temp4191.base? 1:
_temp4193 >= _temp4191.last_plus_one)){ _throw( Null_Exception);}* _temp4193;}).first_line,({
struct _tagged_ptr3 _temp4194= yyls; struct Cyc_Yyltype* _temp4196= _temp4194.curr
+( yylsp_offset - 1); if( _temp4194.base == 0? 1:( _temp4196 < _temp4194.base? 1:
_temp4196 >= _temp4194.last_plus_one)){ _throw( Null_Exception);}* _temp4196;}).last_line),
Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp4197= yyvs; void**
_temp4199= _temp4197.curr +( yyvsp_offset - 1); if( _temp4197.base == 0? 1:(
_temp4199 < _temp4197.base? 1: _temp4199 >= _temp4197.last_plus_one)){ _throw(
Null_Exception);}* _temp4199;})), Cyc_yyget_TypeModifierList_tok(({ struct
_tagged_ptr2 _temp4200= yyvs; void** _temp4202= _temp4200.curr + yyvsp_offset;
if( _temp4200.base == 0? 1:( _temp4202 < _temp4200.base? 1: _temp4202 >=
_temp4200.last_plus_one)){ _throw( Null_Exception);}* _temp4202;}))); _temp4190;});
_temp4189;}); _temp4188;}); break; case 136: _LL4187: yyval=( void*)({ struct
Cyc_TypeModifierList_tok_struct* _temp4212=( struct Cyc_TypeModifierList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeModifierList_tok_struct)); _temp4212[ 0]=({
struct Cyc_TypeModifierList_tok_struct _temp4213; _temp4213.tag= Cyc_TypeModifierList_tok;
_temp4213.f1=({ struct Cyc_List_List* _temp4214=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4214->hd=( void*)(( void*)({
struct Cyc_Absyn_Pointer_mod_struct* _temp4227=( struct Cyc_Absyn_Pointer_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Pointer_mod_struct)); _temp4227[ 0]=({
struct Cyc_Absyn_Pointer_mod_struct _temp4228; _temp4228.tag= Cyc_Absyn_Pointer_mod;
_temp4228.f1=( void*) Cyc_yyget_Pointer_Sort_tok(({ struct _tagged_ptr2
_temp4229= yyvs; void** _temp4231= _temp4229.curr +( yyvsp_offset - 4); if(
_temp4229.base == 0? 1:( _temp4231 < _temp4229.base? 1: _temp4231 >= _temp4229.last_plus_one)){
_throw( Null_Exception);}* _temp4231;})); _temp4228.f2=( void*) Cyc_yyget_Rgn_tok(({
struct _tagged_ptr2 _temp4232= yyvs; void** _temp4234= _temp4232.curr +(
yyvsp_offset - 3); if( _temp4232.base == 0? 1:( _temp4234 < _temp4232.base? 1:
_temp4234 >= _temp4232.last_plus_one)){ _throw( Null_Exception);}* _temp4234;}));
_temp4228.f3= Cyc_yyget_TypeQual_tok(({ struct _tagged_ptr2 _temp4235= yyvs;
void** _temp4237= _temp4235.curr +( yyvsp_offset - 1); if( _temp4235.base == 0?
1:( _temp4237 < _temp4235.base? 1: _temp4237 >= _temp4235.last_plus_one)){
_throw( Null_Exception);}* _temp4237;})); _temp4228;}); _temp4227;})); _temp4214->tl=
Cyc_Parse_attopt_to_tms( Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp4215= yyls; struct Cyc_Yyltype* _temp4217= _temp4215.curr +( yylsp_offset -
2); if( _temp4215.base == 0? 1:( _temp4217 < _temp4215.base? 1: _temp4217 >=
_temp4215.last_plus_one)){ _throw( Null_Exception);}* _temp4217;}).first_line,({
struct _tagged_ptr3 _temp4218= yyls; struct Cyc_Yyltype* _temp4220= _temp4218.curr
+( yylsp_offset - 2); if( _temp4218.base == 0? 1:( _temp4220 < _temp4218.base? 1:
_temp4220 >= _temp4218.last_plus_one)){ _throw( Null_Exception);}* _temp4220;}).last_line),
Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp4221= yyvs; void**
_temp4223= _temp4221.curr +( yyvsp_offset - 2); if( _temp4221.base == 0? 1:(
_temp4223 < _temp4221.base? 1: _temp4223 >= _temp4221.last_plus_one)){ _throw(
Null_Exception);}* _temp4223;})), Cyc_yyget_TypeModifierList_tok(({ struct
_tagged_ptr2 _temp4224= yyvs; void** _temp4226= _temp4224.curr + yyvsp_offset;
if( _temp4224.base == 0? 1:( _temp4226 < _temp4224.base? 1: _temp4226 >=
_temp4224.last_plus_one)){ _throw( Null_Exception);}* _temp4226;}))); _temp4214;});
_temp4213;}); _temp4212;}); break; case 137: _LL4211: yyval=( void*)({ struct
Cyc_Pointer_Sort_tok_struct* _temp4239=( struct Cyc_Pointer_Sort_tok_struct*)
GC_malloc( sizeof( struct Cyc_Pointer_Sort_tok_struct)); _temp4239[ 0]=({ struct
Cyc_Pointer_Sort_tok_struct _temp4240; _temp4240.tag= Cyc_Pointer_Sort_tok;
_temp4240.f1=( void*)(( void*)({ struct Cyc_Absyn_Nullable_ps_struct* _temp4241=(
struct Cyc_Absyn_Nullable_ps_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Nullable_ps_struct));
_temp4241[ 0]=({ struct Cyc_Absyn_Nullable_ps_struct _temp4242; _temp4242.tag=
Cyc_Absyn_Nullable_ps; _temp4242.f1= Cyc_Absyn_signed_int_exp( 1, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4243= yyls; struct Cyc_Yyltype* _temp4245= _temp4243.curr
+ yylsp_offset; if( _temp4243.base == 0? 1:( _temp4245 < _temp4243.base? 1:
_temp4245 >= _temp4243.last_plus_one)){ _throw( Null_Exception);}* _temp4245;}).first_line,({
struct _tagged_ptr3 _temp4246= yyls; struct Cyc_Yyltype* _temp4248= _temp4246.curr
+ yylsp_offset; if( _temp4246.base == 0? 1:( _temp4248 < _temp4246.base? 1:
_temp4248 >= _temp4246.last_plus_one)){ _throw( Null_Exception);}* _temp4248;}).last_line));
_temp4242;}); _temp4241;})); _temp4240;}); _temp4239;}); break; case 138:
_LL4238: yyval=( void*)({ struct Cyc_Pointer_Sort_tok_struct* _temp4250=( struct
Cyc_Pointer_Sort_tok_struct*) GC_malloc( sizeof( struct Cyc_Pointer_Sort_tok_struct));
_temp4250[ 0]=({ struct Cyc_Pointer_Sort_tok_struct _temp4251; _temp4251.tag=
Cyc_Pointer_Sort_tok; _temp4251.f1=( void*)(( void*)({ struct Cyc_Absyn_NonNullable_ps_struct*
_temp4252=( struct Cyc_Absyn_NonNullable_ps_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_NonNullable_ps_struct)); _temp4252[ 0]=({ struct Cyc_Absyn_NonNullable_ps_struct
_temp4253; _temp4253.tag= Cyc_Absyn_NonNullable_ps; _temp4253.f1= Cyc_Absyn_signed_int_exp(
1, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4254= yyls; struct
Cyc_Yyltype* _temp4256= _temp4254.curr + yylsp_offset; if( _temp4254.base == 0?
1:( _temp4256 < _temp4254.base? 1: _temp4256 >= _temp4254.last_plus_one)){
_throw( Null_Exception);}* _temp4256;}).first_line,({ struct _tagged_ptr3
_temp4257= yyls; struct Cyc_Yyltype* _temp4259= _temp4257.curr + yylsp_offset;
if( _temp4257.base == 0? 1:( _temp4259 < _temp4257.base? 1: _temp4259 >=
_temp4257.last_plus_one)){ _throw( Null_Exception);}* _temp4259;}).last_line));
_temp4253;}); _temp4252;})); _temp4251;}); _temp4250;}); break; case 139:
_LL4249: yyval=( void*)({ struct Cyc_Pointer_Sort_tok_struct* _temp4261=( struct
Cyc_Pointer_Sort_tok_struct*) GC_malloc( sizeof( struct Cyc_Pointer_Sort_tok_struct));
_temp4261[ 0]=({ struct Cyc_Pointer_Sort_tok_struct _temp4262; _temp4262.tag=
Cyc_Pointer_Sort_tok; _temp4262.f1=( void*)(( void*)({ struct Cyc_Absyn_Nullable_ps_struct*
_temp4263=( struct Cyc_Absyn_Nullable_ps_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Nullable_ps_struct));
_temp4263[ 0]=({ struct Cyc_Absyn_Nullable_ps_struct _temp4264; _temp4264.tag=
Cyc_Absyn_Nullable_ps; _temp4264.f1= Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp4265= yyvs; void** _temp4267= _temp4265.curr +( yyvsp_offset - 1); if(
_temp4265.base == 0? 1:( _temp4267 < _temp4265.base? 1: _temp4267 >= _temp4265.last_plus_one)){
_throw( Null_Exception);}* _temp4267;})); _temp4264;}); _temp4263;})); _temp4262;});
_temp4261;}); break; case 140: _LL4260: yyval=( void*)({ struct Cyc_Pointer_Sort_tok_struct*
_temp4269=( struct Cyc_Pointer_Sort_tok_struct*) GC_malloc( sizeof( struct Cyc_Pointer_Sort_tok_struct));
_temp4269[ 0]=({ struct Cyc_Pointer_Sort_tok_struct _temp4270; _temp4270.tag=
Cyc_Pointer_Sort_tok; _temp4270.f1=( void*)(( void*)({ struct Cyc_Absyn_NonNullable_ps_struct*
_temp4271=( struct Cyc_Absyn_NonNullable_ps_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_NonNullable_ps_struct)); _temp4271[ 0]=({ struct Cyc_Absyn_NonNullable_ps_struct
_temp4272; _temp4272.tag= Cyc_Absyn_NonNullable_ps; _temp4272.f1= Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp4273= yyvs; void** _temp4275= _temp4273.curr +(
yyvsp_offset - 1); if( _temp4273.base == 0? 1:( _temp4275 < _temp4273.base? 1:
_temp4275 >= _temp4273.last_plus_one)){ _throw( Null_Exception);}* _temp4275;}));
_temp4272;}); _temp4271;})); _temp4270;}); _temp4269;}); break; case 141:
_LL4268: yyval=( void*)({ struct Cyc_Pointer_Sort_tok_struct* _temp4277=( struct
Cyc_Pointer_Sort_tok_struct*) GC_malloc( sizeof( struct Cyc_Pointer_Sort_tok_struct));
_temp4277[ 0]=({ struct Cyc_Pointer_Sort_tok_struct _temp4278; _temp4278.tag=
Cyc_Pointer_Sort_tok; _temp4278.f1=( void*)(( void*) Cyc_Absyn_TaggedArray_ps);
_temp4278;}); _temp4277;}); break; case 142: _LL4276: yyval=( void*)({ struct
Cyc_Rgn_tok_struct* _temp4280=( struct Cyc_Rgn_tok_struct*) GC_malloc( sizeof(
struct Cyc_Rgn_tok_struct)); _temp4280[ 0]=({ struct Cyc_Rgn_tok_struct
_temp4281; _temp4281.tag= Cyc_Rgn_tok; _temp4281.f1=( void*)(( void*) Cyc_Absyn_HeapRgn);
_temp4281;}); _temp4280;}); break; case 143: _LL4279: yyval=({ struct
_tagged_ptr2 _temp4283= yyvs; void** _temp4285= _temp4283.curr + yyvsp_offset;
if( _temp4283.base == 0? 1:( _temp4285 < _temp4283.base? 1: _temp4285 >=
_temp4283.last_plus_one)){ _throw( Null_Exception);}* _temp4285;}); break; case
144: _LL4282: yyval=( void*)({ struct Cyc_Rgn_tok_struct* _temp4287=( struct Cyc_Rgn_tok_struct*)
GC_malloc( sizeof( struct Cyc_Rgn_tok_struct)); _temp4287[ 0]=({ struct Cyc_Rgn_tok_struct
_temp4288; _temp4288.tag= Cyc_Rgn_tok; _temp4288.f1=( void*) Cyc_Parse_id2type(
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp4289= yyvs; void** _temp4291=
_temp4289.curr + yyvsp_offset; if( _temp4289.base == 0? 1:( _temp4291 <
_temp4289.base? 1: _temp4291 >= _temp4289.last_plus_one)){ _throw(
Null_Exception);}* _temp4291;})),(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)((
void*) Cyc_Absyn_RgnKind)); _temp4288;}); _temp4287;}); break; case 145: _LL4286:
if( Cyc_yyget_Kind_tok(({ struct _tagged_ptr2 _temp4293= yyvs; void** _temp4295=
_temp4293.curr + yyvsp_offset; if( _temp4293.base == 0? 1:( _temp4295 <
_temp4293.base? 1: _temp4295 >= _temp4293.last_plus_one)){ _throw(
Null_Exception);}* _temp4295;})) !=( void*) Cyc_Absyn_RgnKind){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp4296=( char*)"expecting region kind\n";
struct _tagged_string _temp4297; _temp4297.curr= _temp4296; _temp4297.base=
_temp4296; _temp4297.last_plus_one= _temp4296 + 23; _temp4297;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4298= yyls; struct Cyc_Yyltype* _temp4300= _temp4298.curr
+ yylsp_offset; if( _temp4298.base == 0? 1:( _temp4300 < _temp4298.base? 1:
_temp4300 >= _temp4298.last_plus_one)){ _throw( Null_Exception);}* _temp4300;}).first_line,({
struct _tagged_ptr3 _temp4301= yyls; struct Cyc_Yyltype* _temp4303= _temp4301.curr
+ yylsp_offset; if( _temp4301.base == 0? 1:( _temp4303 < _temp4301.base? 1:
_temp4303 >= _temp4301.last_plus_one)){ _throw( Null_Exception);}* _temp4303;}).last_line));}
yyval=( void*)({ struct Cyc_Rgn_tok_struct* _temp4304=( struct Cyc_Rgn_tok_struct*)
GC_malloc( sizeof( struct Cyc_Rgn_tok_struct)); _temp4304[ 0]=({ struct Cyc_Rgn_tok_struct
_temp4305; _temp4305.tag= Cyc_Rgn_tok; _temp4305.f1=( void*) Cyc_Parse_id2type(
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp4306= yyvs; void** _temp4308=
_temp4306.curr +( yyvsp_offset - 2); if( _temp4306.base == 0? 1:( _temp4308 <
_temp4306.base? 1: _temp4308 >= _temp4306.last_plus_one)){ _throw(
Null_Exception);}* _temp4308;})),(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)((
void*) Cyc_Absyn_RgnKind)); _temp4305;}); _temp4304;}); break; case 146: _LL4292:
yyval=( void*)({ struct Cyc_Rgn_tok_struct* _temp4310=( struct Cyc_Rgn_tok_struct*)
GC_malloc( sizeof( struct Cyc_Rgn_tok_struct)); _temp4310[ 0]=({ struct Cyc_Rgn_tok_struct
_temp4311; _temp4311.tag= Cyc_Rgn_tok; _temp4311.f1=( void*) Cyc_Absyn_new_evar((
void*) Cyc_Absyn_RgnKind); _temp4311;}); _temp4310;}); break; case 147: _LL4309:
yyval=({ struct _tagged_ptr2 _temp4313= yyvs; void** _temp4315= _temp4313.curr +
yyvsp_offset; if( _temp4313.base == 0? 1:( _temp4315 < _temp4313.base? 1:
_temp4315 >= _temp4313.last_plus_one)){ _throw( Null_Exception);}* _temp4315;});
break; case 148: _LL4312: yyval=( void*)({ struct Cyc_TypeQual_tok_struct*
_temp4317=( struct Cyc_TypeQual_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeQual_tok_struct));
_temp4317[ 0]=({ struct Cyc_TypeQual_tok_struct _temp4318; _temp4318.tag= Cyc_TypeQual_tok;
_temp4318.f1= Cyc_Absyn_combine_tqual( Cyc_yyget_TypeQual_tok(({ struct
_tagged_ptr2 _temp4319= yyvs; void** _temp4321= _temp4319.curr +( yyvsp_offset -
1); if( _temp4319.base == 0? 1:( _temp4321 < _temp4319.base? 1: _temp4321 >=
_temp4319.last_plus_one)){ _throw( Null_Exception);}* _temp4321;})), Cyc_yyget_TypeQual_tok(({
struct _tagged_ptr2 _temp4322= yyvs; void** _temp4324= _temp4322.curr +
yyvsp_offset; if( _temp4322.base == 0? 1:( _temp4324 < _temp4322.base? 1:
_temp4324 >= _temp4322.last_plus_one)){ _throw( Null_Exception);}* _temp4324;})));
_temp4318;}); _temp4317;}); break; case 149: _LL4316: yyval=( void*)({ struct
Cyc_ParamDeclListBool_tok_struct* _temp4326=( struct Cyc_ParamDeclListBool_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDeclListBool_tok_struct)); _temp4326[ 0]=({
struct Cyc_ParamDeclListBool_tok_struct _temp4327; _temp4327.tag= Cyc_ParamDeclListBool_tok;
_temp4327.f1=({ struct _tuple16* _temp4328=( struct _tuple16*) GC_malloc(
sizeof( struct _tuple16)); _temp4328->f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x)) Cyc_List_imp_rev)( Cyc_yyget_ParamDeclList_tok(({ struct _tagged_ptr2
_temp4329= yyvs; void** _temp4331= _temp4329.curr + yyvsp_offset; if( _temp4329.base
== 0? 1:( _temp4331 < _temp4329.base? 1: _temp4331 >= _temp4329.last_plus_one)){
_throw( Null_Exception);}* _temp4331;}))); _temp4328->f2= 0; _temp4328->f3= 0;
_temp4328;}); _temp4327;}); _temp4326;}); break; case 150: _LL4325: yyval=( void*)({
struct Cyc_ParamDeclListBool_tok_struct* _temp4333=( struct Cyc_ParamDeclListBool_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDeclListBool_tok_struct)); _temp4333[ 0]=({
struct Cyc_ParamDeclListBool_tok_struct _temp4334; _temp4334.tag= Cyc_ParamDeclListBool_tok;
_temp4334.f1=({ struct _tuple16* _temp4335=( struct _tuple16*) GC_malloc(
sizeof( struct _tuple16)); _temp4335->f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x)) Cyc_List_imp_rev)( Cyc_yyget_ParamDeclList_tok(({ struct _tagged_ptr2
_temp4336= yyvs; void** _temp4338= _temp4336.curr +( yyvsp_offset - 2); if(
_temp4336.base == 0? 1:( _temp4338 < _temp4336.base? 1: _temp4338 >= _temp4336.last_plus_one)){
_throw( Null_Exception);}* _temp4338;}))); _temp4335->f2= 1; _temp4335->f3= 0;
_temp4335;}); _temp4334;}); _temp4333;}); break; case 151: _LL4332: yyval=( void*)({
struct Cyc_ParamDeclListBool_tok_struct* _temp4340=( struct Cyc_ParamDeclListBool_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDeclListBool_tok_struct)); _temp4340[ 0]=({
struct Cyc_ParamDeclListBool_tok_struct _temp4341; _temp4341.tag= Cyc_ParamDeclListBool_tok;
_temp4341.f1=({ struct _tuple16* _temp4342=( struct _tuple16*) GC_malloc(
sizeof( struct _tuple16)); _temp4342->f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x)) Cyc_List_imp_rev)( Cyc_yyget_ParamDeclList_tok(({ struct _tagged_ptr2
_temp4349= yyvs; void** _temp4351= _temp4349.curr +( yyvsp_offset - 2); if(
_temp4349.base == 0? 1:( _temp4351 < _temp4349.base? 1: _temp4351 >= _temp4349.last_plus_one)){
_throw( Null_Exception);}* _temp4351;}))); _temp4342->f2= 0; _temp4342->f3=(
struct Cyc_Core_Opt*)({ struct Cyc_Core_Opt* _temp4343=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp4343->v=( void*)(( void*)({
struct Cyc_Absyn_JoinEff_struct* _temp4344=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp4344[ 0]=({ struct
Cyc_Absyn_JoinEff_struct _temp4345; _temp4345.tag= Cyc_Absyn_JoinEff; _temp4345.f1=
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp4346= yyvs; void** _temp4348=
_temp4346.curr + yyvsp_offset; if( _temp4346.base == 0? 1:( _temp4348 <
_temp4346.base? 1: _temp4348 >= _temp4346.last_plus_one)){ _throw(
Null_Exception);}* _temp4348;})); _temp4345;}); _temp4344;})); _temp4343;});
_temp4342;}); _temp4341;}); _temp4340;}); break; case 152: _LL4339: yyval=({
struct _tagged_ptr2 _temp4353= yyvs; void** _temp4355= _temp4353.curr +
yyvsp_offset; if( _temp4353.base == 0? 1:( _temp4355 < _temp4353.base? 1:
_temp4355 >= _temp4353.last_plus_one)){ _throw( Null_Exception);}* _temp4355;});
break; case 153: _LL4352: yyval=( void*)({ struct Cyc_TypeList_tok_struct*
_temp4357=( struct Cyc_TypeList_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeList_tok_struct));
_temp4357[ 0]=({ struct Cyc_TypeList_tok_struct _temp4358; _temp4358.tag= Cyc_TypeList_tok;
_temp4358.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List*
y)) Cyc_List_imp_append)( Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2
_temp4359= yyvs; void** _temp4361= _temp4359.curr +( yyvsp_offset - 2); if(
_temp4359.base == 0? 1:( _temp4361 < _temp4359.base? 1: _temp4361 >= _temp4359.last_plus_one)){
_throw( Null_Exception);}* _temp4361;})), Cyc_yyget_TypeList_tok(({ struct
_tagged_ptr2 _temp4362= yyvs; void** _temp4364= _temp4362.curr + yyvsp_offset;
if( _temp4362.base == 0? 1:( _temp4364 < _temp4362.base? 1: _temp4364 >=
_temp4362.last_plus_one)){ _throw( Null_Exception);}* _temp4364;}))); _temp4358;});
_temp4357;}); break; case 154: _LL4356: yyval=( void*)({ struct Cyc_TypeList_tok_struct*
_temp4366=( struct Cyc_TypeList_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeList_tok_struct));
_temp4366[ 0]=({ struct Cyc_TypeList_tok_struct _temp4367; _temp4367.tag= Cyc_TypeList_tok;
_temp4367.f1= 0; _temp4367;}); _temp4366;}); break; case 155: _LL4365: yyval=({
struct _tagged_ptr2 _temp4369= yyvs; void** _temp4371= _temp4369.curr +(
yyvsp_offset - 1); if( _temp4369.base == 0? 1:( _temp4371 < _temp4369.base? 1:
_temp4371 >= _temp4369.last_plus_one)){ _throw( Null_Exception);}* _temp4371;});
break; case 156: _LL4368: yyval=( void*)({ struct Cyc_TypeList_tok_struct*
_temp4373=( struct Cyc_TypeList_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeList_tok_struct));
_temp4373[ 0]=({ struct Cyc_TypeList_tok_struct _temp4374; _temp4374.tag= Cyc_TypeList_tok;
_temp4374.f1=({ struct Cyc_List_List* _temp4375=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4375->hd=( void*) Cyc_Parse_id2type(
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp4376= yyvs; void** _temp4378=
_temp4376.curr + yyvsp_offset; if( _temp4376.base == 0? 1:( _temp4378 <
_temp4376.base? 1: _temp4378 >= _temp4376.last_plus_one)){ _throw(
Null_Exception);}* _temp4378;})),(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)((
void*) Cyc_Absyn_EffKind)); _temp4375->tl= 0; _temp4375;}); _temp4374;});
_temp4373;}); break; case 157: _LL4372: if( Cyc_yyget_Kind_tok(({ struct
_tagged_ptr2 _temp4380= yyvs; void** _temp4382= _temp4380.curr + yyvsp_offset;
if( _temp4380.base == 0? 1:( _temp4382 < _temp4380.base? 1: _temp4382 >=
_temp4380.last_plus_one)){ _throw( Null_Exception);}* _temp4382;})) !=( void*)
Cyc_Absyn_EffKind){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp4383=(
char*)"expecing effect kind (E)"; struct _tagged_string _temp4384; _temp4384.curr=
_temp4383; _temp4384.base= _temp4383; _temp4384.last_plus_one= _temp4383 + 25;
_temp4384;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4385= yyls;
struct Cyc_Yyltype* _temp4387= _temp4385.curr + yylsp_offset; if( _temp4385.base
== 0? 1:( _temp4387 < _temp4385.base? 1: _temp4387 >= _temp4385.last_plus_one)){
_throw( Null_Exception);}* _temp4387;}).first_line,({ struct _tagged_ptr3
_temp4388= yyls; struct Cyc_Yyltype* _temp4390= _temp4388.curr + yylsp_offset;
if( _temp4388.base == 0? 1:( _temp4390 < _temp4388.base? 1: _temp4390 >=
_temp4388.last_plus_one)){ _throw( Null_Exception);}* _temp4390;}).last_line));}
yyval=( void*)({ struct Cyc_TypeList_tok_struct* _temp4391=( struct Cyc_TypeList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeList_tok_struct)); _temp4391[ 0]=({ struct Cyc_TypeList_tok_struct
_temp4392; _temp4392.tag= Cyc_TypeList_tok; _temp4392.f1=({ struct Cyc_List_List*
_temp4393=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4393->hd=( void*) Cyc_Parse_id2type( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp4394= yyvs; void** _temp4396= _temp4394.curr +( yyvsp_offset -
2); if( _temp4394.base == 0? 1:( _temp4396 < _temp4394.base? 1: _temp4396 >=
_temp4394.last_plus_one)){ _throw( Null_Exception);}* _temp4396;})),(( struct
Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(( void*) Cyc_Absyn_EffKind));
_temp4393->tl= 0; _temp4393;}); _temp4392;}); _temp4391;}); break; case 158:
_LL4379: yyval=( void*)({ struct Cyc_TypeList_tok_struct* _temp4398=( struct Cyc_TypeList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeList_tok_struct)); _temp4398[ 0]=({ struct Cyc_TypeList_tok_struct
_temp4399; _temp4399.tag= Cyc_TypeList_tok; _temp4399.f1=({ struct Cyc_List_List*
_temp4400=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4400->hd=( void*)(( void*)({ struct Cyc_Absyn_AccessEff_struct* _temp4401=(
struct Cyc_Absyn_AccessEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_AccessEff_struct));
_temp4401[ 0]=({ struct Cyc_Absyn_AccessEff_struct _temp4402; _temp4402.tag= Cyc_Absyn_AccessEff;
_temp4402.f1=( void*) Cyc_Parse_id2type( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp4403= yyvs; void** _temp4405= _temp4403.curr + yyvsp_offset;
if( _temp4403.base == 0? 1:( _temp4405 < _temp4403.base? 1: _temp4405 >=
_temp4403.last_plus_one)){ _throw( Null_Exception);}* _temp4405;})),(( struct
Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(( void*) Cyc_Absyn_RgnKind));
_temp4402;}); _temp4401;})); _temp4400->tl= 0; _temp4400;}); _temp4399;});
_temp4398;}); break; case 159: _LL4397: yyval=( void*)({ struct Cyc_TypeList_tok_struct*
_temp4407=( struct Cyc_TypeList_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeList_tok_struct));
_temp4407[ 0]=({ struct Cyc_TypeList_tok_struct _temp4408; _temp4408.tag= Cyc_TypeList_tok;
_temp4408.f1=({ struct Cyc_List_List* _temp4409=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4409->hd=( void*)(( void*)({
struct Cyc_Absyn_AccessEff_struct* _temp4413=( struct Cyc_Absyn_AccessEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_AccessEff_struct)); _temp4413[ 0]=({ struct
Cyc_Absyn_AccessEff_struct _temp4414; _temp4414.tag= Cyc_Absyn_AccessEff;
_temp4414.f1=( void*) Cyc_Parse_id2type( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp4415= yyvs; void** _temp4417= _temp4415.curr +( yyvsp_offset -
2); if( _temp4415.base == 0? 1:( _temp4417 < _temp4415.base? 1: _temp4417 >=
_temp4415.last_plus_one)){ _throw( Null_Exception);}* _temp4417;})),(( struct
Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(( void*) Cyc_Absyn_RgnKind));
_temp4414;}); _temp4413;})); _temp4409->tl= Cyc_yyget_TypeList_tok(({ struct
_tagged_ptr2 _temp4410= yyvs; void** _temp4412= _temp4410.curr + yyvsp_offset;
if( _temp4410.base == 0? 1:( _temp4412 < _temp4410.base? 1: _temp4412 >=
_temp4410.last_plus_one)){ _throw( Null_Exception);}* _temp4412;})); _temp4409;});
_temp4408;}); _temp4407;}); break; case 160: _LL4406: if( Cyc_yyget_Kind_tok(({
struct _tagged_ptr2 _temp4419= yyvs; void** _temp4421= _temp4419.curr +
yyvsp_offset; if( _temp4419.base == 0? 1:( _temp4421 < _temp4419.base? 1:
_temp4421 >= _temp4419.last_plus_one)){ _throw( Null_Exception);}* _temp4421;}))
!=( void*) Cyc_Absyn_RgnKind){ Cyc_Parse_err(( struct _tagged_string)({ char*
_temp4422=( char*)"expecting region kind (R)"; struct _tagged_string _temp4423;
_temp4423.curr= _temp4422; _temp4423.base= _temp4422; _temp4423.last_plus_one=
_temp4422 + 26; _temp4423;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp4424= yyls; struct Cyc_Yyltype* _temp4426= _temp4424.curr + yylsp_offset;
if( _temp4424.base == 0? 1:( _temp4426 < _temp4424.base? 1: _temp4426 >=
_temp4424.last_plus_one)){ _throw( Null_Exception);}* _temp4426;}).first_line,({
struct _tagged_ptr3 _temp4427= yyls; struct Cyc_Yyltype* _temp4429= _temp4427.curr
+ yylsp_offset; if( _temp4427.base == 0? 1:( _temp4429 < _temp4427.base? 1:
_temp4429 >= _temp4427.last_plus_one)){ _throw( Null_Exception);}* _temp4429;}).last_line));}
yyval=( void*)({ struct Cyc_TypeList_tok_struct* _temp4430=( struct Cyc_TypeList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeList_tok_struct)); _temp4430[ 0]=({ struct Cyc_TypeList_tok_struct
_temp4431; _temp4431.tag= Cyc_TypeList_tok; _temp4431.f1=({ struct Cyc_List_List*
_temp4432=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4432->hd=( void*)(( void*)({ struct Cyc_Absyn_AccessEff_struct* _temp4433=(
struct Cyc_Absyn_AccessEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_AccessEff_struct));
_temp4433[ 0]=({ struct Cyc_Absyn_AccessEff_struct _temp4434; _temp4434.tag= Cyc_Absyn_AccessEff;
_temp4434.f1=( void*) Cyc_Parse_id2type( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp4435= yyvs; void** _temp4437= _temp4435.curr +( yyvsp_offset -
2); if( _temp4435.base == 0? 1:( _temp4437 < _temp4435.base? 1: _temp4437 >=
_temp4435.last_plus_one)){ _throw( Null_Exception);}* _temp4437;})),(( struct
Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(( void*) Cyc_Absyn_RgnKind));
_temp4434;}); _temp4433;})); _temp4432->tl= 0; _temp4432;}); _temp4431;});
_temp4430;}); break; case 161: _LL4418: if( Cyc_yyget_Kind_tok(({ struct
_tagged_ptr2 _temp4439= yyvs; void** _temp4441= _temp4439.curr +( yyvsp_offset -
2); if( _temp4439.base == 0? 1:( _temp4441 < _temp4439.base? 1: _temp4441 >=
_temp4439.last_plus_one)){ _throw( Null_Exception);}* _temp4441;})) !=( void*)
Cyc_Absyn_RgnKind){ Cyc_Parse_err(( struct _tagged_string)({ char* _temp4442=(
char*)"expecting region kind (R)"; struct _tagged_string _temp4443; _temp4443.curr=
_temp4442; _temp4443.base= _temp4442; _temp4443.last_plus_one= _temp4442 + 26;
_temp4443;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4444= yyls;
struct Cyc_Yyltype* _temp4446= _temp4444.curr +( yylsp_offset - 2); if(
_temp4444.base == 0? 1:( _temp4446 < _temp4444.base? 1: _temp4446 >= _temp4444.last_plus_one)){
_throw( Null_Exception);}* _temp4446;}).first_line,({ struct _tagged_ptr3
_temp4447= yyls; struct Cyc_Yyltype* _temp4449= _temp4447.curr +( yylsp_offset -
2); if( _temp4447.base == 0? 1:( _temp4449 < _temp4447.base? 1: _temp4449 >=
_temp4447.last_plus_one)){ _throw( Null_Exception);}* _temp4449;}).last_line));}
yyval=( void*)({ struct Cyc_TypeList_tok_struct* _temp4450=( struct Cyc_TypeList_tok_struct*)
GC_malloc( sizeof( struct Cyc_TypeList_tok_struct)); _temp4450[ 0]=({ struct Cyc_TypeList_tok_struct
_temp4451; _temp4451.tag= Cyc_TypeList_tok; _temp4451.f1=({ struct Cyc_List_List*
_temp4452=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4452->hd=( void*)(( void*)({ struct Cyc_Absyn_AccessEff_struct* _temp4456=(
struct Cyc_Absyn_AccessEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_AccessEff_struct));
_temp4456[ 0]=({ struct Cyc_Absyn_AccessEff_struct _temp4457; _temp4457.tag= Cyc_Absyn_AccessEff;
_temp4457.f1=( void*) Cyc_Parse_id2type( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp4458= yyvs; void** _temp4460= _temp4458.curr +( yyvsp_offset -
4); if( _temp4458.base == 0? 1:( _temp4460 < _temp4458.base? 1: _temp4460 >=
_temp4458.last_plus_one)){ _throw( Null_Exception);}* _temp4460;})),(( struct
Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(( void*) Cyc_Absyn_RgnKind));
_temp4457;}); _temp4456;})); _temp4452->tl= Cyc_yyget_TypeList_tok(({ struct
_tagged_ptr2 _temp4453= yyvs; void** _temp4455= _temp4453.curr + yyvsp_offset;
if( _temp4453.base == 0? 1:( _temp4455 < _temp4453.base? 1: _temp4455 >=
_temp4453.last_plus_one)){ _throw( Null_Exception);}* _temp4455;})); _temp4452;});
_temp4451;}); _temp4450;}); break; case 162: _LL4438: yyval=( void*)({ struct
Cyc_ParamDeclList_tok_struct* _temp4462=( struct Cyc_ParamDeclList_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDeclList_tok_struct)); _temp4462[ 0]=({
struct Cyc_ParamDeclList_tok_struct _temp4463; _temp4463.tag= Cyc_ParamDeclList_tok;
_temp4463.f1=({ struct Cyc_List_List* _temp4464=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4464->hd=( void*) Cyc_yyget_ParamDecl_tok(({
struct _tagged_ptr2 _temp4465= yyvs; void** _temp4467= _temp4465.curr +
yyvsp_offset; if( _temp4465.base == 0? 1:( _temp4467 < _temp4465.base? 1:
_temp4467 >= _temp4465.last_plus_one)){ _throw( Null_Exception);}* _temp4467;}));
_temp4464->tl= 0; _temp4464;}); _temp4463;}); _temp4462;}); break; case 163:
_LL4461: yyval=( void*)({ struct Cyc_ParamDeclList_tok_struct* _temp4469=(
struct Cyc_ParamDeclList_tok_struct*) GC_malloc( sizeof( struct Cyc_ParamDeclList_tok_struct));
_temp4469[ 0]=({ struct Cyc_ParamDeclList_tok_struct _temp4470; _temp4470.tag=
Cyc_ParamDeclList_tok; _temp4470.f1=({ struct Cyc_List_List* _temp4471=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp4471->hd=( void*)
Cyc_yyget_ParamDecl_tok(({ struct _tagged_ptr2 _temp4475= yyvs; void** _temp4477=
_temp4475.curr + yyvsp_offset; if( _temp4475.base == 0? 1:( _temp4477 <
_temp4475.base? 1: _temp4477 >= _temp4475.last_plus_one)){ _throw(
Null_Exception);}* _temp4477;})); _temp4471->tl= Cyc_yyget_ParamDeclList_tok(({
struct _tagged_ptr2 _temp4472= yyvs; void** _temp4474= _temp4472.curr +(
yyvsp_offset - 2); if( _temp4472.base == 0? 1:( _temp4474 < _temp4472.base? 1:
_temp4474 >= _temp4472.last_plus_one)){ _throw( Null_Exception);}* _temp4474;}));
_temp4471;}); _temp4470;}); _temp4469;}); break; case 164: _LL4468: { void* t=
Cyc_Parse_speclist2typ((* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp4541= yyvs; void** _temp4543= _temp4541.curr +( yyvsp_offset - 1); if(
_temp4541.base == 0? 1:( _temp4543 < _temp4541.base? 1: _temp4543 >= _temp4541.last_plus_one)){
_throw( Null_Exception);}* _temp4543;}))).f2, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4544= yyls; struct Cyc_Yyltype* _temp4546= _temp4544.curr
+( yylsp_offset - 1); if( _temp4544.base == 0? 1:( _temp4546 < _temp4544.base? 1:
_temp4546 >= _temp4544.last_plus_one)){ _throw( Null_Exception);}* _temp4546;}).first_line,({
struct _tagged_ptr3 _temp4547= yyls; struct Cyc_Yyltype* _temp4549= _temp4547.curr
+( yylsp_offset - 1); if( _temp4547.base == 0? 1:( _temp4549 < _temp4547.base? 1:
_temp4549 >= _temp4547.last_plus_one)){ _throw( Null_Exception);}* _temp4549;}).last_line));
struct Cyc_List_List* atts=(* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp4538= yyvs; void** _temp4540= _temp4538.curr +( yyvsp_offset - 1); if(
_temp4538.base == 0? 1:( _temp4540 < _temp4538.base? 1: _temp4540 >= _temp4538.last_plus_one)){
_throw( Null_Exception);}* _temp4540;}))).f3; struct Cyc_Absyn_Tqual tq=(* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp4535= yyvs; void** _temp4537= _temp4535.curr +(
yyvsp_offset - 1); if( _temp4535.base == 0? 1:( _temp4537 < _temp4535.base? 1:
_temp4537 >= _temp4535.last_plus_one)){ _throw( Null_Exception);}* _temp4537;}))).f1;
struct Cyc_List_List* tms=( Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2
_temp4532= yyvs; void** _temp4534= _temp4532.curr + yyvsp_offset; if( _temp4532.base
== 0? 1:( _temp4534 < _temp4532.base? 1: _temp4534 >= _temp4532.last_plus_one)){
_throw( Null_Exception);}* _temp4534;})))->tms; struct _tuple6 t_info= Cyc_Parse_apply_tms(
tq, t, atts, tms); if( t_info.f3 != 0){ Cyc_Parse_err(( struct _tagged_string)({
char* _temp4479=( char*)"parameter with bad type params"; struct _tagged_string
_temp4480; _temp4480.curr= _temp4479; _temp4480.base= _temp4479; _temp4480.last_plus_one=
_temp4479 + 31; _temp4480;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp4481= yyls; struct Cyc_Yyltype* _temp4483= _temp4481.curr + yylsp_offset;
if( _temp4481.base == 0? 1:( _temp4483 < _temp4481.base? 1: _temp4483 >=
_temp4481.last_plus_one)){ _throw( Null_Exception);}* _temp4483;}).first_line,({
struct _tagged_ptr3 _temp4484= yyls; struct Cyc_Yyltype* _temp4486= _temp4484.curr
+ yylsp_offset; if( _temp4484.base == 0? 1:( _temp4486 < _temp4484.base? 1:
_temp4486 >= _temp4484.last_plus_one)){ _throw( Null_Exception);}* _temp4486;}).last_line));}{
struct _tuple1* q=( Cyc_yyget_Declarator_tok(({ struct _tagged_ptr2 _temp4529=
yyvs; void** _temp4531= _temp4529.curr + yyvsp_offset; if( _temp4529.base == 0?
1:( _temp4531 < _temp4529.base? 1: _temp4531 >= _temp4529.last_plus_one)){
_throw( Null_Exception);}* _temp4531;})))->id;{ void* _temp4487=(* q).f1; struct
Cyc_List_List* _temp4497; struct Cyc_List_List* _temp4499; _LL4489: if(
_temp4487 ==( void*) Cyc_Absyn_Loc_n){ goto _LL4490;} else{ goto _LL4491;}
_LL4491: if(( unsigned int) _temp4487 > 1u?*(( int*) _temp4487) == Cyc_Absyn_Rel_n:
0){ _LL4498: _temp4497=( struct Cyc_List_List*)(( struct Cyc_Absyn_Rel_n_struct*)
_temp4487)->f1; if( _temp4497 == 0){ goto _LL4492;} else{ goto _LL4493;}} else{
goto _LL4493;} _LL4493: if(( unsigned int) _temp4487 > 1u?*(( int*) _temp4487)
== Cyc_Absyn_Abs_n: 0){ _LL4500: _temp4499=( struct Cyc_List_List*)(( struct Cyc_Absyn_Abs_n_struct*)
_temp4487)->f1; if( _temp4499 == 0){ goto _LL4494;} else{ goto _LL4495;}} else{
goto _LL4495;} _LL4495: goto _LL4496; _LL4490: goto _LL4488; _LL4492: goto
_LL4488; _LL4494: goto _LL4488; _LL4496: Cyc_Parse_err(( struct _tagged_string)({
char* _temp4501=( char*)"parameter cannot be qualified with a module name";
struct _tagged_string _temp4502; _temp4502.curr= _temp4501; _temp4502.base=
_temp4501; _temp4502.last_plus_one= _temp4501 + 49; _temp4502;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4503= yyls; struct Cyc_Yyltype* _temp4505= _temp4503.curr
+( yylsp_offset - 1); if( _temp4503.base == 0? 1:( _temp4505 < _temp4503.base? 1:
_temp4505 >= _temp4503.last_plus_one)){ _throw( Null_Exception);}* _temp4505;}).first_line,({
struct _tagged_ptr3 _temp4506= yyls; struct Cyc_Yyltype* _temp4508= _temp4506.curr
+( yylsp_offset - 1); if( _temp4506.base == 0? 1:( _temp4508 < _temp4506.base? 1:
_temp4508 >= _temp4506.last_plus_one)){ _throw( Null_Exception);}* _temp4508;}).last_line));
goto _LL4488; _LL4488:;}{ struct Cyc_Core_Opt* idopt=( struct Cyc_Core_Opt*)({
struct Cyc_Core_Opt* _temp4528=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp4528->v=( void*)(* q).f2; _temp4528;}); if( t_info.f4 != 0){
Cyc_Parse_warn(( struct _tagged_string)({ char* _temp4509=( char*)"extra attributes on parameter, ignoring";
struct _tagged_string _temp4510; _temp4510.curr= _temp4509; _temp4510.base=
_temp4509; _temp4510.last_plus_one= _temp4509 + 40; _temp4510;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4511= yyls; struct Cyc_Yyltype* _temp4513= _temp4511.curr
+( yylsp_offset - 1); if( _temp4511.base == 0? 1:( _temp4513 < _temp4511.base? 1:
_temp4513 >= _temp4511.last_plus_one)){ _throw( Null_Exception);}* _temp4513;}).first_line,({
struct _tagged_ptr3 _temp4514= yyls; struct Cyc_Yyltype* _temp4516= _temp4514.curr
+ yylsp_offset; if( _temp4514.base == 0? 1:( _temp4516 < _temp4514.base? 1:
_temp4516 >= _temp4514.last_plus_one)){ _throw( Null_Exception);}* _temp4516;}).last_line));}
if( t_info.f3 != 0){ Cyc_Parse_warn(( struct _tagged_string)({ char* _temp4517=(
char*)"extra type variables on parameter, ignoring"; struct _tagged_string
_temp4518; _temp4518.curr= _temp4517; _temp4518.base= _temp4517; _temp4518.last_plus_one=
_temp4517 + 44; _temp4518;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp4519= yyls; struct Cyc_Yyltype* _temp4521= _temp4519.curr +( yylsp_offset -
1); if( _temp4519.base == 0? 1:( _temp4521 < _temp4519.base? 1: _temp4521 >=
_temp4519.last_plus_one)){ _throw( Null_Exception);}* _temp4521;}).first_line,({
struct _tagged_ptr3 _temp4522= yyls; struct Cyc_Yyltype* _temp4524= _temp4522.curr
+ yylsp_offset; if( _temp4522.base == 0? 1:( _temp4524 < _temp4522.base? 1:
_temp4524 >= _temp4522.last_plus_one)){ _throw( Null_Exception);}* _temp4524;}).last_line));}
yyval=( void*)({ struct Cyc_ParamDecl_tok_struct* _temp4525=( struct Cyc_ParamDecl_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDecl_tok_struct)); _temp4525[ 0]=({ struct
Cyc_ParamDecl_tok_struct _temp4526; _temp4526.tag= Cyc_ParamDecl_tok; _temp4526.f1=({
struct _tuple2* _temp4527=( struct _tuple2*) GC_malloc( sizeof( struct _tuple2));
_temp4527->f1= idopt; _temp4527->f2= t_info.f1; _temp4527->f3= t_info.f2;
_temp4527;}); _temp4526;}); _temp4525;}); break;}}} case 165: _LL4478: { void* t=
Cyc_Parse_speclist2typ((* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp4568= yyvs; void** _temp4570= _temp4568.curr + yyvsp_offset; if( _temp4568.base
== 0? 1:( _temp4570 < _temp4568.base? 1: _temp4570 >= _temp4568.last_plus_one)){
_throw( Null_Exception);}* _temp4570;}))).f2, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4571= yyls; struct Cyc_Yyltype* _temp4573= _temp4571.curr
+ yylsp_offset; if( _temp4571.base == 0? 1:( _temp4573 < _temp4571.base? 1:
_temp4573 >= _temp4571.last_plus_one)){ _throw( Null_Exception);}* _temp4573;}).first_line,({
struct _tagged_ptr3 _temp4574= yyls; struct Cyc_Yyltype* _temp4576= _temp4574.curr
+ yylsp_offset; if( _temp4574.base == 0? 1:( _temp4576 < _temp4574.base? 1:
_temp4576 >= _temp4574.last_plus_one)){ _throw( Null_Exception);}* _temp4576;}).last_line));
struct Cyc_List_List* atts=(* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp4565= yyvs; void** _temp4567= _temp4565.curr + yyvsp_offset; if( _temp4565.base
== 0? 1:( _temp4567 < _temp4565.base? 1: _temp4567 >= _temp4565.last_plus_one)){
_throw( Null_Exception);}* _temp4567;}))).f3; struct Cyc_Absyn_Tqual tq=(* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp4562= yyvs; void** _temp4564= _temp4562.curr +
yyvsp_offset; if( _temp4562.base == 0? 1:( _temp4564 < _temp4562.base? 1:
_temp4564 >= _temp4562.last_plus_one)){ _throw( Null_Exception);}* _temp4564;}))).f1;
if( atts != 0){ Cyc_Parse_warn(( struct _tagged_string)({ char* _temp4551=( char*)"bad attributes on parameter, ignoring";
struct _tagged_string _temp4552; _temp4552.curr= _temp4551; _temp4552.base=
_temp4551; _temp4552.last_plus_one= _temp4551 + 38; _temp4552;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4553= yyls; struct Cyc_Yyltype* _temp4555= _temp4553.curr
+ yylsp_offset; if( _temp4553.base == 0? 1:( _temp4555 < _temp4553.base? 1:
_temp4555 >= _temp4553.last_plus_one)){ _throw( Null_Exception);}* _temp4555;}).first_line,({
struct _tagged_ptr3 _temp4556= yyls; struct Cyc_Yyltype* _temp4558= _temp4556.curr
+ yylsp_offset; if( _temp4556.base == 0? 1:( _temp4558 < _temp4556.base? 1:
_temp4558 >= _temp4556.last_plus_one)){ _throw( Null_Exception);}* _temp4558;}).last_line));}
yyval=( void*)({ struct Cyc_ParamDecl_tok_struct* _temp4559=( struct Cyc_ParamDecl_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDecl_tok_struct)); _temp4559[ 0]=({ struct
Cyc_ParamDecl_tok_struct _temp4560; _temp4560.tag= Cyc_ParamDecl_tok; _temp4560.f1=({
struct _tuple2* _temp4561=( struct _tuple2*) GC_malloc( sizeof( struct _tuple2));
_temp4561->f1= 0; _temp4561->f2= tq; _temp4561->f3= t; _temp4561;}); _temp4560;});
_temp4559;}); break;} case 166: _LL4550: { void* t= Cyc_Parse_speclist2typ((*
Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2 _temp4606= yyvs; void**
_temp4608= _temp4606.curr +( yyvsp_offset - 1); if( _temp4606.base == 0? 1:(
_temp4608 < _temp4606.base? 1: _temp4608 >= _temp4606.last_plus_one)){ _throw(
Null_Exception);}* _temp4608;}))).f2, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp4609= yyls; struct Cyc_Yyltype* _temp4611= _temp4609.curr +(
yylsp_offset - 1); if( _temp4609.base == 0? 1:( _temp4611 < _temp4609.base? 1:
_temp4611 >= _temp4609.last_plus_one)){ _throw( Null_Exception);}* _temp4611;}).first_line,({
struct _tagged_ptr3 _temp4612= yyls; struct Cyc_Yyltype* _temp4614= _temp4612.curr
+( yylsp_offset - 1); if( _temp4612.base == 0? 1:( _temp4614 < _temp4612.base? 1:
_temp4614 >= _temp4612.last_plus_one)){ _throw( Null_Exception);}* _temp4614;}).last_line));
struct Cyc_List_List* atts=(* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp4603= yyvs; void** _temp4605= _temp4603.curr +( yyvsp_offset - 1); if(
_temp4603.base == 0? 1:( _temp4605 < _temp4603.base? 1: _temp4605 >= _temp4603.last_plus_one)){
_throw( Null_Exception);}* _temp4605;}))).f3; struct Cyc_Absyn_Tqual tq=(* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp4600= yyvs; void** _temp4602= _temp4600.curr +(
yyvsp_offset - 1); if( _temp4600.base == 0? 1:( _temp4602 < _temp4600.base? 1:
_temp4602 >= _temp4600.last_plus_one)){ _throw( Null_Exception);}* _temp4602;}))).f1;
struct Cyc_List_List* tms=( Cyc_yyget_AbstractDeclarator_tok(({ struct
_tagged_ptr2 _temp4597= yyvs; void** _temp4599= _temp4597.curr + yyvsp_offset;
if( _temp4597.base == 0? 1:( _temp4599 < _temp4597.base? 1: _temp4599 >=
_temp4597.last_plus_one)){ _throw( Null_Exception);}* _temp4599;})))->tms;
struct _tuple6 t_info= Cyc_Parse_apply_tms( tq, t, atts, tms); if( t_info.f3 !=
0){ Cyc_Parse_warn(( struct _tagged_string)({ char* _temp4578=( char*)"bad type parameters on formal argument, ignoring";
struct _tagged_string _temp4579; _temp4579.curr= _temp4578; _temp4579.base=
_temp4578; _temp4579.last_plus_one= _temp4578 + 49; _temp4579;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4580= yyls; struct Cyc_Yyltype* _temp4582= _temp4580.curr
+( yylsp_offset - 1); if( _temp4580.base == 0? 1:( _temp4582 < _temp4580.base? 1:
_temp4582 >= _temp4580.last_plus_one)){ _throw( Null_Exception);}* _temp4582;}).first_line,({
struct _tagged_ptr3 _temp4583= yyls; struct Cyc_Yyltype* _temp4585= _temp4583.curr
+ yylsp_offset; if( _temp4583.base == 0? 1:( _temp4585 < _temp4583.base? 1:
_temp4585 >= _temp4583.last_plus_one)){ _throw( Null_Exception);}* _temp4585;}).last_line));}
if( t_info.f4 != 0){ Cyc_Parse_warn(( struct _tagged_string)({ char* _temp4586=(
char*)"bad attributes on parameter, ignoring"; struct _tagged_string _temp4587;
_temp4587.curr= _temp4586; _temp4587.base= _temp4586; _temp4587.last_plus_one=
_temp4586 + 38; _temp4587;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp4588= yyls; struct Cyc_Yyltype* _temp4590= _temp4588.curr +( yylsp_offset -
1); if( _temp4588.base == 0? 1:( _temp4590 < _temp4588.base? 1: _temp4590 >=
_temp4588.last_plus_one)){ _throw( Null_Exception);}* _temp4590;}).first_line,({
struct _tagged_ptr3 _temp4591= yyls; struct Cyc_Yyltype* _temp4593= _temp4591.curr
+ yylsp_offset; if( _temp4591.base == 0? 1:( _temp4593 < _temp4591.base? 1:
_temp4593 >= _temp4591.last_plus_one)){ _throw( Null_Exception);}* _temp4593;}).last_line));}
yyval=( void*)({ struct Cyc_ParamDecl_tok_struct* _temp4594=( struct Cyc_ParamDecl_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDecl_tok_struct)); _temp4594[ 0]=({ struct
Cyc_ParamDecl_tok_struct _temp4595; _temp4595.tag= Cyc_ParamDecl_tok; _temp4595.f1=({
struct _tuple2* _temp4596=( struct _tuple2*) GC_malloc( sizeof( struct _tuple2));
_temp4596->f1= 0; _temp4596->f2= t_info.f1; _temp4596->f3= t_info.f2; _temp4596;});
_temp4595;}); _temp4594;}); break;} case 167: _LL4577: yyval=( void*)({ struct
Cyc_IdList_tok_struct* _temp4616=( struct Cyc_IdList_tok_struct*) GC_malloc(
sizeof( struct Cyc_IdList_tok_struct)); _temp4616[ 0]=({ struct Cyc_IdList_tok_struct
_temp4617; _temp4617.tag= Cyc_IdList_tok; _temp4617.f1=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_IdList_tok(({ struct
_tagged_ptr2 _temp4618= yyvs; void** _temp4620= _temp4618.curr + yyvsp_offset;
if( _temp4618.base == 0? 1:( _temp4620 < _temp4618.base? 1: _temp4620 >=
_temp4618.last_plus_one)){ _throw( Null_Exception);}* _temp4620;}))); _temp4617;});
_temp4616;}); break; case 168: _LL4615: yyval=( void*)({ struct Cyc_IdList_tok_struct*
_temp4622=( struct Cyc_IdList_tok_struct*) GC_malloc( sizeof( struct Cyc_IdList_tok_struct));
_temp4622[ 0]=({ struct Cyc_IdList_tok_struct _temp4623; _temp4623.tag= Cyc_IdList_tok;
_temp4623.f1=({ struct Cyc_List_List* _temp4624=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4624->hd=( void*)({ struct
_tagged_string* _temp4625=( struct _tagged_string*) GC_malloc( sizeof( struct
_tagged_string) * 1); _temp4625[ 0]= Cyc_yyget_String_tok(({ struct _tagged_ptr2
_temp4626= yyvs; void** _temp4628= _temp4626.curr + yyvsp_offset; if( _temp4626.base
== 0? 1:( _temp4628 < _temp4626.base? 1: _temp4628 >= _temp4626.last_plus_one)){
_throw( Null_Exception);}* _temp4628;})); _temp4625;}); _temp4624->tl= 0;
_temp4624;}); _temp4623;}); _temp4622;}); break; case 169: _LL4621: yyval=( void*)({
struct Cyc_IdList_tok_struct* _temp4630=( struct Cyc_IdList_tok_struct*)
GC_malloc( sizeof( struct Cyc_IdList_tok_struct)); _temp4630[ 0]=({ struct Cyc_IdList_tok_struct
_temp4631; _temp4631.tag= Cyc_IdList_tok; _temp4631.f1=({ struct Cyc_List_List*
_temp4632=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4632->hd=( void*)({ struct _tagged_string* _temp4636=( struct
_tagged_string*) GC_malloc( sizeof( struct _tagged_string) * 1); _temp4636[ 0]=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp4637= yyvs; void** _temp4639=
_temp4637.curr + yyvsp_offset; if( _temp4637.base == 0? 1:( _temp4639 <
_temp4637.base? 1: _temp4639 >= _temp4637.last_plus_one)){ _throw(
Null_Exception);}* _temp4639;})); _temp4636;}); _temp4632->tl= Cyc_yyget_IdList_tok(({
struct _tagged_ptr2 _temp4633= yyvs; void** _temp4635= _temp4633.curr +(
yyvsp_offset - 2); if( _temp4633.base == 0? 1:( _temp4635 < _temp4633.base? 1:
_temp4635 >= _temp4633.last_plus_one)){ _throw( Null_Exception);}* _temp4635;}));
_temp4632;}); _temp4631;}); _temp4630;}); break; case 170: _LL4629: yyval=({
struct _tagged_ptr2 _temp4641= yyvs; void** _temp4643= _temp4641.curr +
yyvsp_offset; if( _temp4641.base == 0? 1:( _temp4643 < _temp4641.base? 1:
_temp4643 >= _temp4641.last_plus_one)){ _throw( Null_Exception);}* _temp4643;});
break; case 171: _LL4640: yyval=({ struct _tagged_ptr2 _temp4645= yyvs; void**
_temp4647= _temp4645.curr + yyvsp_offset; if( _temp4645.base == 0? 1:( _temp4647
< _temp4645.base? 1: _temp4647 >= _temp4645.last_plus_one)){ _throw(
Null_Exception);}* _temp4647;}); break; case 172: _LL4644: yyval=( void*)({
struct Cyc_Exp_tok_struct* _temp4649=( struct Cyc_Exp_tok_struct*) GC_malloc(
sizeof( struct Cyc_Exp_tok_struct)); _temp4649[ 0]=({ struct Cyc_Exp_tok_struct
_temp4650; _temp4650.tag= Cyc_Exp_tok; _temp4650.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_UnresolvedMem_e_struct* _temp4651=( struct Cyc_Absyn_UnresolvedMem_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnresolvedMem_e_struct)); _temp4651[ 0]=({
struct Cyc_Absyn_UnresolvedMem_e_struct _temp4652; _temp4652.tag= Cyc_Absyn_UnresolvedMem_e;
_temp4652.f1= 0; _temp4652.f2= 0; _temp4652;}); _temp4651;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4653= yyls; struct Cyc_Yyltype* _temp4655= _temp4653.curr
+( yylsp_offset - 1); if( _temp4653.base == 0? 1:( _temp4655 < _temp4653.base? 1:
_temp4655 >= _temp4653.last_plus_one)){ _throw( Null_Exception);}* _temp4655;}).first_line,({
struct _tagged_ptr3 _temp4656= yyls; struct Cyc_Yyltype* _temp4658= _temp4656.curr
+ yylsp_offset; if( _temp4656.base == 0? 1:( _temp4658 < _temp4656.base? 1:
_temp4658 >= _temp4656.last_plus_one)){ _throw( Null_Exception);}* _temp4658;}).last_line));
_temp4650;}); _temp4649;}); break; case 173: _LL4648: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp4660=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp4660[ 0]=({ struct Cyc_Exp_tok_struct
_temp4661; _temp4661.tag= Cyc_Exp_tok; _temp4661.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_UnresolvedMem_e_struct* _temp4662=( struct Cyc_Absyn_UnresolvedMem_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnresolvedMem_e_struct)); _temp4662[ 0]=({
struct Cyc_Absyn_UnresolvedMem_e_struct _temp4663; _temp4663.tag= Cyc_Absyn_UnresolvedMem_e;
_temp4663.f1= 0; _temp4663.f2=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x)) Cyc_List_imp_rev)( Cyc_yyget_InitializerList_tok(({ struct _tagged_ptr2
_temp4664= yyvs; void** _temp4666= _temp4664.curr +( yyvsp_offset - 1); if(
_temp4664.base == 0? 1:( _temp4666 < _temp4664.base? 1: _temp4666 >= _temp4664.last_plus_one)){
_throw( Null_Exception);}* _temp4666;}))); _temp4663;}); _temp4662;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4667= yyls; struct Cyc_Yyltype* _temp4669= _temp4667.curr
+( yylsp_offset - 2); if( _temp4667.base == 0? 1:( _temp4669 < _temp4667.base? 1:
_temp4669 >= _temp4667.last_plus_one)){ _throw( Null_Exception);}* _temp4669;}).first_line,({
struct _tagged_ptr3 _temp4670= yyls; struct Cyc_Yyltype* _temp4672= _temp4670.curr
+ yylsp_offset; if( _temp4670.base == 0? 1:( _temp4672 < _temp4670.base? 1:
_temp4672 >= _temp4670.last_plus_one)){ _throw( Null_Exception);}* _temp4672;}).last_line));
_temp4661;}); _temp4660;}); break; case 174: _LL4659: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp4674=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp4674[ 0]=({ struct Cyc_Exp_tok_struct
_temp4675; _temp4675.tag= Cyc_Exp_tok; _temp4675.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_UnresolvedMem_e_struct* _temp4676=( struct Cyc_Absyn_UnresolvedMem_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnresolvedMem_e_struct)); _temp4676[ 0]=({
struct Cyc_Absyn_UnresolvedMem_e_struct _temp4677; _temp4677.tag= Cyc_Absyn_UnresolvedMem_e;
_temp4677.f1= 0; _temp4677.f2=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x)) Cyc_List_imp_rev)( Cyc_yyget_InitializerList_tok(({ struct _tagged_ptr2
_temp4678= yyvs; void** _temp4680= _temp4678.curr +( yyvsp_offset - 2); if(
_temp4678.base == 0? 1:( _temp4680 < _temp4678.base? 1: _temp4680 >= _temp4678.last_plus_one)){
_throw( Null_Exception);}* _temp4680;}))); _temp4677;}); _temp4676;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4681= yyls; struct Cyc_Yyltype* _temp4683= _temp4681.curr
+( yylsp_offset - 3); if( _temp4681.base == 0? 1:( _temp4683 < _temp4681.base? 1:
_temp4683 >= _temp4681.last_plus_one)){ _throw( Null_Exception);}* _temp4683;}).first_line,({
struct _tagged_ptr3 _temp4684= yyls; struct Cyc_Yyltype* _temp4686= _temp4684.curr
+ yylsp_offset; if( _temp4684.base == 0? 1:( _temp4686 < _temp4684.base? 1:
_temp4686 >= _temp4684.last_plus_one)){ _throw( Null_Exception);}* _temp4686;}).last_line));
_temp4675;}); _temp4674;}); break; case 175: _LL4673: { struct Cyc_Absyn_Vardecl*
vd= Cyc_Absyn_new_vardecl(({ struct _tuple1* _temp4705=( struct _tuple1*)
GC_malloc( sizeof( struct _tuple1)); _temp4705->f1=( void*) Cyc_Absyn_Loc_n;
_temp4705->f2=({ struct _tagged_string* _temp4706=( struct _tagged_string*)
GC_malloc( sizeof( struct _tagged_string) * 1); _temp4706[ 0]= Cyc_yyget_String_tok(({
struct _tagged_ptr2 _temp4707= yyvs; void** _temp4709= _temp4707.curr +(
yyvsp_offset - 5); if( _temp4707.base == 0? 1:( _temp4709 < _temp4707.base? 1:
_temp4709 >= _temp4707.last_plus_one)){ _throw( Null_Exception);}* _temp4709;}));
_temp4706;}); _temp4705;}), Cyc_Absyn_uint_t,( struct Cyc_Absyn_Exp*) Cyc_Absyn_uint_exp(
0, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4710= yyls; struct
Cyc_Yyltype* _temp4712= _temp4710.curr +( yylsp_offset - 5); if( _temp4710.base
== 0? 1:( _temp4712 < _temp4710.base? 1: _temp4712 >= _temp4710.last_plus_one)){
_throw( Null_Exception);}* _temp4712;}).first_line,({ struct _tagged_ptr3
_temp4713= yyls; struct Cyc_Yyltype* _temp4715= _temp4713.curr +( yylsp_offset -
5); if( _temp4713.base == 0? 1:( _temp4715 < _temp4713.base? 1: _temp4715 >=
_temp4713.last_plus_one)){ _throw( Null_Exception);}* _temp4715;}).last_line)));
vd->tq=({ struct Cyc_Absyn_Tqual _temp4688; _temp4688.q_const= 1; _temp4688.q_volatile=
0; _temp4688.q_restrict= 1; _temp4688;}); yyval=( void*)({ struct Cyc_Exp_tok_struct*
_temp4689=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp4689[ 0]=({ struct Cyc_Exp_tok_struct _temp4690; _temp4690.tag= Cyc_Exp_tok;
_temp4690.f1= Cyc_Absyn_new_exp(( void*)({ struct Cyc_Absyn_Comprehension_e_struct*
_temp4691=( struct Cyc_Absyn_Comprehension_e_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_Comprehension_e_struct)); _temp4691[ 0]=({ struct Cyc_Absyn_Comprehension_e_struct
_temp4692; _temp4692.tag= Cyc_Absyn_Comprehension_e; _temp4692.f1= vd; _temp4692.f2=
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp4693= yyvs; void** _temp4695=
_temp4693.curr +( yyvsp_offset - 3); if( _temp4693.base == 0? 1:( _temp4695 <
_temp4693.base? 1: _temp4695 >= _temp4693.last_plus_one)){ _throw(
Null_Exception);}* _temp4695;})); _temp4692.f3= Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp4696= yyvs; void** _temp4698= _temp4696.curr +( yyvsp_offset -
1); if( _temp4696.base == 0? 1:( _temp4698 < _temp4696.base? 1: _temp4698 >=
_temp4696.last_plus_one)){ _throw( Null_Exception);}* _temp4698;})); _temp4692;});
_temp4691;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4699= yyls;
struct Cyc_Yyltype* _temp4701= _temp4699.curr +( yylsp_offset - 7); if(
_temp4699.base == 0? 1:( _temp4701 < _temp4699.base? 1: _temp4701 >= _temp4699.last_plus_one)){
_throw( Null_Exception);}* _temp4701;}).first_line,({ struct _tagged_ptr3
_temp4702= yyls; struct Cyc_Yyltype* _temp4704= _temp4702.curr + yylsp_offset;
if( _temp4702.base == 0? 1:( _temp4704 < _temp4702.base? 1: _temp4704 >=
_temp4702.last_plus_one)){ _throw( Null_Exception);}* _temp4704;}).last_line));
_temp4690;}); _temp4689;}); break;} case 176: _LL4687: yyval=( void*)({ struct
Cyc_InitializerList_tok_struct* _temp4717=( struct Cyc_InitializerList_tok_struct*)
GC_malloc( sizeof( struct Cyc_InitializerList_tok_struct)); _temp4717[ 0]=({
struct Cyc_InitializerList_tok_struct _temp4718; _temp4718.tag= Cyc_InitializerList_tok;
_temp4718.f1=({ struct Cyc_List_List* _temp4719=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4719->hd=( void*)({ struct
_tuple18* _temp4720=( struct _tuple18*) GC_malloc( sizeof( struct _tuple18));
_temp4720->f1= 0; _temp4720->f2= Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp4721= yyvs; void** _temp4723= _temp4721.curr + yyvsp_offset; if( _temp4721.base
== 0? 1:( _temp4723 < _temp4721.base? 1: _temp4723 >= _temp4721.last_plus_one)){
_throw( Null_Exception);}* _temp4723;})); _temp4720;}); _temp4719->tl= 0;
_temp4719;}); _temp4718;}); _temp4717;}); break; case 177: _LL4716: yyval=( void*)({
struct Cyc_InitializerList_tok_struct* _temp4725=( struct Cyc_InitializerList_tok_struct*)
GC_malloc( sizeof( struct Cyc_InitializerList_tok_struct)); _temp4725[ 0]=({
struct Cyc_InitializerList_tok_struct _temp4726; _temp4726.tag= Cyc_InitializerList_tok;
_temp4726.f1=({ struct Cyc_List_List* _temp4727=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4727->hd=( void*)({ struct
_tuple18* _temp4728=( struct _tuple18*) GC_malloc( sizeof( struct _tuple18));
_temp4728->f1= Cyc_yyget_DesignatorList_tok(({ struct _tagged_ptr2 _temp4732=
yyvs; void** _temp4734= _temp4732.curr +( yyvsp_offset - 1); if( _temp4732.base
== 0? 1:( _temp4734 < _temp4732.base? 1: _temp4734 >= _temp4732.last_plus_one)){
_throw( Null_Exception);}* _temp4734;})); _temp4728->f2= Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp4729= yyvs; void** _temp4731= _temp4729.curr +
yyvsp_offset; if( _temp4729.base == 0? 1:( _temp4731 < _temp4729.base? 1:
_temp4731 >= _temp4729.last_plus_one)){ _throw( Null_Exception);}* _temp4731;}));
_temp4728;}); _temp4727->tl= 0; _temp4727;}); _temp4726;}); _temp4725;}); break;
case 178: _LL4724: yyval=( void*)({ struct Cyc_InitializerList_tok_struct*
_temp4736=( struct Cyc_InitializerList_tok_struct*) GC_malloc( sizeof( struct
Cyc_InitializerList_tok_struct)); _temp4736[ 0]=({ struct Cyc_InitializerList_tok_struct
_temp4737; _temp4737.tag= Cyc_InitializerList_tok; _temp4737.f1=({ struct Cyc_List_List*
_temp4738=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4738->hd=( void*)({ struct _tuple18* _temp4742=( struct _tuple18*)
GC_malloc( sizeof( struct _tuple18)); _temp4742->f1= 0; _temp4742->f2= Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp4743= yyvs; void** _temp4745= _temp4743.curr +
yyvsp_offset; if( _temp4743.base == 0? 1:( _temp4745 < _temp4743.base? 1:
_temp4745 >= _temp4743.last_plus_one)){ _throw( Null_Exception);}* _temp4745;}));
_temp4742;}); _temp4738->tl= Cyc_yyget_InitializerList_tok(({ struct
_tagged_ptr2 _temp4739= yyvs; void** _temp4741= _temp4739.curr +( yyvsp_offset -
2); if( _temp4739.base == 0? 1:( _temp4741 < _temp4739.base? 1: _temp4741 >=
_temp4739.last_plus_one)){ _throw( Null_Exception);}* _temp4741;})); _temp4738;});
_temp4737;}); _temp4736;}); break; case 179: _LL4735: yyval=( void*)({ struct
Cyc_InitializerList_tok_struct* _temp4747=( struct Cyc_InitializerList_tok_struct*)
GC_malloc( sizeof( struct Cyc_InitializerList_tok_struct)); _temp4747[ 0]=({
struct Cyc_InitializerList_tok_struct _temp4748; _temp4748.tag= Cyc_InitializerList_tok;
_temp4748.f1=({ struct Cyc_List_List* _temp4749=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4749->hd=( void*)({ struct
_tuple18* _temp4753=( struct _tuple18*) GC_malloc( sizeof( struct _tuple18));
_temp4753->f1= Cyc_yyget_DesignatorList_tok(({ struct _tagged_ptr2 _temp4757=
yyvs; void** _temp4759= _temp4757.curr +( yyvsp_offset - 1); if( _temp4757.base
== 0? 1:( _temp4759 < _temp4757.base? 1: _temp4759 >= _temp4757.last_plus_one)){
_throw( Null_Exception);}* _temp4759;})); _temp4753->f2= Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp4754= yyvs; void** _temp4756= _temp4754.curr +
yyvsp_offset; if( _temp4754.base == 0? 1:( _temp4756 < _temp4754.base? 1:
_temp4756 >= _temp4754.last_plus_one)){ _throw( Null_Exception);}* _temp4756;}));
_temp4753;}); _temp4749->tl= Cyc_yyget_InitializerList_tok(({ struct
_tagged_ptr2 _temp4750= yyvs; void** _temp4752= _temp4750.curr +( yyvsp_offset -
3); if( _temp4750.base == 0? 1:( _temp4752 < _temp4750.base? 1: _temp4752 >=
_temp4750.last_plus_one)){ _throw( Null_Exception);}* _temp4752;})); _temp4749;});
_temp4748;}); _temp4747;}); break; case 180: _LL4746: yyval=( void*)({ struct
Cyc_DesignatorList_tok_struct* _temp4761=( struct Cyc_DesignatorList_tok_struct*)
GC_malloc( sizeof( struct Cyc_DesignatorList_tok_struct)); _temp4761[ 0]=({
struct Cyc_DesignatorList_tok_struct _temp4762; _temp4762.tag= Cyc_DesignatorList_tok;
_temp4762.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
Cyc_yyget_DesignatorList_tok(({ struct _tagged_ptr2 _temp4763= yyvs; void**
_temp4765= _temp4763.curr +( yyvsp_offset - 1); if( _temp4763.base == 0? 1:(
_temp4765 < _temp4763.base? 1: _temp4765 >= _temp4763.last_plus_one)){ _throw(
Null_Exception);}* _temp4765;}))); _temp4762;}); _temp4761;}); break; case 181:
_LL4760: yyval=( void*)({ struct Cyc_DesignatorList_tok_struct* _temp4767=(
struct Cyc_DesignatorList_tok_struct*) GC_malloc( sizeof( struct Cyc_DesignatorList_tok_struct));
_temp4767[ 0]=({ struct Cyc_DesignatorList_tok_struct _temp4768; _temp4768.tag=
Cyc_DesignatorList_tok; _temp4768.f1=({ struct Cyc_List_List* _temp4769=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp4769->hd=( void*)
Cyc_yyget_Designator_tok(({ struct _tagged_ptr2 _temp4770= yyvs; void**
_temp4772= _temp4770.curr + yyvsp_offset; if( _temp4770.base == 0? 1:( _temp4772
< _temp4770.base? 1: _temp4772 >= _temp4770.last_plus_one)){ _throw(
Null_Exception);}* _temp4772;})); _temp4769->tl= 0; _temp4769;}); _temp4768;});
_temp4767;}); break; case 182: _LL4766: yyval=( void*)({ struct Cyc_DesignatorList_tok_struct*
_temp4774=( struct Cyc_DesignatorList_tok_struct*) GC_malloc( sizeof( struct Cyc_DesignatorList_tok_struct));
_temp4774[ 0]=({ struct Cyc_DesignatorList_tok_struct _temp4775; _temp4775.tag=
Cyc_DesignatorList_tok; _temp4775.f1=({ struct Cyc_List_List* _temp4776=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp4776->hd=( void*)
Cyc_yyget_Designator_tok(({ struct _tagged_ptr2 _temp4780= yyvs; void**
_temp4782= _temp4780.curr + yyvsp_offset; if( _temp4780.base == 0? 1:( _temp4782
< _temp4780.base? 1: _temp4782 >= _temp4780.last_plus_one)){ _throw(
Null_Exception);}* _temp4782;})); _temp4776->tl= Cyc_yyget_DesignatorList_tok(({
struct _tagged_ptr2 _temp4777= yyvs; void** _temp4779= _temp4777.curr +(
yyvsp_offset - 1); if( _temp4777.base == 0? 1:( _temp4779 < _temp4777.base? 1:
_temp4779 >= _temp4777.last_plus_one)){ _throw( Null_Exception);}* _temp4779;}));
_temp4776;}); _temp4775;}); _temp4774;}); break; case 183: _LL4773: yyval=( void*)({
struct Cyc_Designator_tok_struct* _temp4784=( struct Cyc_Designator_tok_struct*)
GC_malloc( sizeof( struct Cyc_Designator_tok_struct)); _temp4784[ 0]=({ struct
Cyc_Designator_tok_struct _temp4785; _temp4785.tag= Cyc_Designator_tok;
_temp4785.f1=( void*)(( void*)({ struct Cyc_Absyn_ArrayElement_struct* _temp4786=(
struct Cyc_Absyn_ArrayElement_struct*) GC_malloc( sizeof( struct Cyc_Absyn_ArrayElement_struct));
_temp4786[ 0]=({ struct Cyc_Absyn_ArrayElement_struct _temp4787; _temp4787.tag=
Cyc_Absyn_ArrayElement; _temp4787.f1= Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp4788= yyvs; void** _temp4790= _temp4788.curr +( yyvsp_offset - 1); if(
_temp4788.base == 0? 1:( _temp4790 < _temp4788.base? 1: _temp4790 >= _temp4788.last_plus_one)){
_throw( Null_Exception);}* _temp4790;})); _temp4787;}); _temp4786;})); _temp4785;});
_temp4784;}); break; case 184: _LL4783: yyval=( void*)({ struct Cyc_Designator_tok_struct*
_temp4792=( struct Cyc_Designator_tok_struct*) GC_malloc( sizeof( struct Cyc_Designator_tok_struct));
_temp4792[ 0]=({ struct Cyc_Designator_tok_struct _temp4793; _temp4793.tag= Cyc_Designator_tok;
_temp4793.f1=( void*)(( void*)({ struct Cyc_Absyn_FieldName_struct* _temp4794=(
struct Cyc_Absyn_FieldName_struct*) GC_malloc( sizeof( struct Cyc_Absyn_FieldName_struct));
_temp4794[ 0]=({ struct Cyc_Absyn_FieldName_struct _temp4795; _temp4795.tag= Cyc_Absyn_FieldName;
_temp4795.f1=({ struct _tagged_string* _temp4796=( struct _tagged_string*)
GC_malloc( sizeof( struct _tagged_string) * 1); _temp4796[ 0]= Cyc_yyget_String_tok(({
struct _tagged_ptr2 _temp4797= yyvs; void** _temp4799= _temp4797.curr +
yyvsp_offset; if( _temp4797.base == 0? 1:( _temp4799 < _temp4797.base? 1:
_temp4799 >= _temp4797.last_plus_one)){ _throw( Null_Exception);}* _temp4799;}));
_temp4796;}); _temp4795;}); _temp4794;})); _temp4793;}); _temp4792;}); break;
case 185: _LL4791: { void* t= Cyc_Parse_speclist2typ((* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp4819= yyvs; void** _temp4821= _temp4819.curr +
yyvsp_offset; if( _temp4819.base == 0? 1:( _temp4821 < _temp4819.base? 1:
_temp4821 >= _temp4819.last_plus_one)){ _throw( Null_Exception);}* _temp4821;}))).f2,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4822= yyls; struct Cyc_Yyltype*
_temp4824= _temp4822.curr + yylsp_offset; if( _temp4822.base == 0? 1:( _temp4824
< _temp4822.base? 1: _temp4824 >= _temp4822.last_plus_one)){ _throw(
Null_Exception);}* _temp4824;}).first_line,({ struct _tagged_ptr3 _temp4825=
yyls; struct Cyc_Yyltype* _temp4827= _temp4825.curr + yylsp_offset; if(
_temp4825.base == 0? 1:( _temp4827 < _temp4825.base? 1: _temp4827 >= _temp4825.last_plus_one)){
_throw( Null_Exception);}* _temp4827;}).last_line)); struct Cyc_List_List* atts=(*
Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2 _temp4816= yyvs; void**
_temp4818= _temp4816.curr + yyvsp_offset; if( _temp4816.base == 0? 1:( _temp4818
< _temp4816.base? 1: _temp4818 >= _temp4816.last_plus_one)){ _throw(
Null_Exception);}* _temp4818;}))).f3; if( atts != 0){ Cyc_Parse_warn(( struct
_tagged_string)({ char* _temp4801=( char*)"ignoring attributes in type"; struct
_tagged_string _temp4802; _temp4802.curr= _temp4801; _temp4802.base= _temp4801;
_temp4802.last_plus_one= _temp4801 + 28; _temp4802;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4803= yyls; struct Cyc_Yyltype* _temp4805= _temp4803.curr
+ yylsp_offset; if( _temp4803.base == 0? 1:( _temp4805 < _temp4803.base? 1:
_temp4805 >= _temp4803.last_plus_one)){ _throw( Null_Exception);}* _temp4805;}).first_line,({
struct _tagged_ptr3 _temp4806= yyls; struct Cyc_Yyltype* _temp4808= _temp4806.curr
+ yylsp_offset; if( _temp4806.base == 0? 1:( _temp4808 < _temp4806.base? 1:
_temp4808 >= _temp4806.last_plus_one)){ _throw( Null_Exception);}* _temp4808;}).last_line));}{
struct Cyc_Absyn_Tqual tq=(* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp4813= yyvs; void** _temp4815= _temp4813.curr + yyvsp_offset; if( _temp4813.base
== 0? 1:( _temp4815 < _temp4813.base? 1: _temp4815 >= _temp4813.last_plus_one)){
_throw( Null_Exception);}* _temp4815;}))).f1; yyval=( void*)({ struct Cyc_ParamDecl_tok_struct*
_temp4809=( struct Cyc_ParamDecl_tok_struct*) GC_malloc( sizeof( struct Cyc_ParamDecl_tok_struct));
_temp4809[ 0]=({ struct Cyc_ParamDecl_tok_struct _temp4810; _temp4810.tag= Cyc_ParamDecl_tok;
_temp4810.f1=({ struct _tuple2* _temp4811=( struct _tuple2*) GC_malloc( sizeof(
struct _tuple2) * 1); _temp4811[ 0]=({ struct _tuple2 _temp4812; _temp4812.f1= 0;
_temp4812.f2= tq; _temp4812.f3= t; _temp4812;}); _temp4811;}); _temp4810;});
_temp4809;}); break;}} case 186: _LL4800: { void* t= Cyc_Parse_speclist2typ((*
Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2 _temp4857= yyvs; void**
_temp4859= _temp4857.curr +( yyvsp_offset - 1); if( _temp4857.base == 0? 1:(
_temp4859 < _temp4857.base? 1: _temp4859 >= _temp4857.last_plus_one)){ _throw(
Null_Exception);}* _temp4859;}))).f2, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp4860= yyls; struct Cyc_Yyltype* _temp4862= _temp4860.curr +(
yylsp_offset - 1); if( _temp4860.base == 0? 1:( _temp4862 < _temp4860.base? 1:
_temp4862 >= _temp4860.last_plus_one)){ _throw( Null_Exception);}* _temp4862;}).first_line,({
struct _tagged_ptr3 _temp4863= yyls; struct Cyc_Yyltype* _temp4865= _temp4863.curr
+( yylsp_offset - 1); if( _temp4863.base == 0? 1:( _temp4865 < _temp4863.base? 1:
_temp4865 >= _temp4863.last_plus_one)){ _throw( Null_Exception);}* _temp4865;}).last_line));
struct Cyc_List_List* atts=(* Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2
_temp4854= yyvs; void** _temp4856= _temp4854.curr +( yyvsp_offset - 1); if(
_temp4854.base == 0? 1:( _temp4856 < _temp4854.base? 1: _temp4856 >= _temp4854.last_plus_one)){
_throw( Null_Exception);}* _temp4856;}))).f3; struct Cyc_Absyn_Tqual tq=(* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp4851= yyvs; void** _temp4853= _temp4851.curr +(
yyvsp_offset - 1); if( _temp4851.base == 0? 1:( _temp4853 < _temp4851.base? 1:
_temp4853 >= _temp4851.last_plus_one)){ _throw( Null_Exception);}* _temp4853;}))).f1;
struct Cyc_List_List* tms=( Cyc_yyget_AbstractDeclarator_tok(({ struct
_tagged_ptr2 _temp4848= yyvs; void** _temp4850= _temp4848.curr + yyvsp_offset;
if( _temp4848.base == 0? 1:( _temp4850 < _temp4848.base? 1: _temp4850 >=
_temp4848.last_plus_one)){ _throw( Null_Exception);}* _temp4850;})))->tms;
struct _tuple6 t_info= Cyc_Parse_apply_tms( tq, t, atts, tms); if( t_info.f3 !=
0){ Cyc_Parse_warn(( struct _tagged_string)({ char* _temp4829=( char*)"bad type params, ignoring";
struct _tagged_string _temp4830; _temp4830.curr= _temp4829; _temp4830.base=
_temp4829; _temp4830.last_plus_one= _temp4829 + 26; _temp4830;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp4831= yyls; struct Cyc_Yyltype* _temp4833= _temp4831.curr
+ yylsp_offset; if( _temp4831.base == 0? 1:( _temp4833 < _temp4831.base? 1:
_temp4833 >= _temp4831.last_plus_one)){ _throw( Null_Exception);}* _temp4833;}).first_line,({
struct _tagged_ptr3 _temp4834= yyls; struct Cyc_Yyltype* _temp4836= _temp4834.curr
+ yylsp_offset; if( _temp4834.base == 0? 1:( _temp4836 < _temp4834.base? 1:
_temp4836 >= _temp4834.last_plus_one)){ _throw( Null_Exception);}* _temp4836;}).last_line));}
if( t_info.f4 != 0){ Cyc_Parse_warn(( struct _tagged_string)({ char* _temp4837=(
char*)"bad specifiers, ignoring"; struct _tagged_string _temp4838; _temp4838.curr=
_temp4837; _temp4838.base= _temp4837; _temp4838.last_plus_one= _temp4837 + 25;
_temp4838;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp4839= yyls;
struct Cyc_Yyltype* _temp4841= _temp4839.curr + yylsp_offset; if( _temp4839.base
== 0? 1:( _temp4841 < _temp4839.base? 1: _temp4841 >= _temp4839.last_plus_one)){
_throw( Null_Exception);}* _temp4841;}).first_line,({ struct _tagged_ptr3
_temp4842= yyls; struct Cyc_Yyltype* _temp4844= _temp4842.curr + yylsp_offset;
if( _temp4842.base == 0? 1:( _temp4844 < _temp4842.base? 1: _temp4844 >=
_temp4842.last_plus_one)){ _throw( Null_Exception);}* _temp4844;}).last_line));}
yyval=( void*)({ struct Cyc_ParamDecl_tok_struct* _temp4845=( struct Cyc_ParamDecl_tok_struct*)
GC_malloc( sizeof( struct Cyc_ParamDecl_tok_struct)); _temp4845[ 0]=({ struct
Cyc_ParamDecl_tok_struct _temp4846; _temp4846.tag= Cyc_ParamDecl_tok; _temp4846.f1=({
struct _tuple2* _temp4847=( struct _tuple2*) GC_malloc( sizeof( struct _tuple2));
_temp4847->f1= 0; _temp4847->f2= t_info.f1; _temp4847->f3= t_info.f2; _temp4847;});
_temp4846;}); _temp4845;}); break;} case 187: _LL4828: yyval=( void*)({ struct
Cyc_Type_tok_struct* _temp4867=( struct Cyc_Type_tok_struct*) GC_malloc( sizeof(
struct Cyc_Type_tok_struct)); _temp4867[ 0]=({ struct Cyc_Type_tok_struct
_temp4868; _temp4868.tag= Cyc_Type_tok; _temp4868.f1=( void*)(* Cyc_yyget_ParamDecl_tok(({
struct _tagged_ptr2 _temp4869= yyvs; void** _temp4871= _temp4869.curr +
yyvsp_offset; if( _temp4869.base == 0? 1:( _temp4871 < _temp4869.base? 1:
_temp4871 >= _temp4869.last_plus_one)){ _throw( Null_Exception);}* _temp4871;}))).f3;
_temp4868;}); _temp4867;}); break; case 188: _LL4866: yyval=( void*)({ struct
Cyc_Type_tok_struct* _temp4873=( struct Cyc_Type_tok_struct*) GC_malloc( sizeof(
struct Cyc_Type_tok_struct)); _temp4873[ 0]=({ struct Cyc_Type_tok_struct
_temp4874; _temp4874.tag= Cyc_Type_tok; _temp4874.f1=( void*)(( void*)({ struct
Cyc_Absyn_JoinEff_struct* _temp4875=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp4875[ 0]=({ struct
Cyc_Absyn_JoinEff_struct _temp4876; _temp4876.tag= Cyc_Absyn_JoinEff; _temp4876.f1=
0; _temp4876;}); _temp4875;})); _temp4874;}); _temp4873;}); break; case 189:
_LL4872: yyval=( void*)({ struct Cyc_Type_tok_struct* _temp4878=( struct Cyc_Type_tok_struct*)
GC_malloc( sizeof( struct Cyc_Type_tok_struct)); _temp4878[ 0]=({ struct Cyc_Type_tok_struct
_temp4879; _temp4879.tag= Cyc_Type_tok; _temp4879.f1=( void*)(( void*)({ struct
Cyc_Absyn_JoinEff_struct* _temp4880=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp4880[ 0]=({ struct
Cyc_Absyn_JoinEff_struct _temp4881; _temp4881.tag= Cyc_Absyn_JoinEff; _temp4881.f1=
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp4882= yyvs; void** _temp4884=
_temp4882.curr +( yyvsp_offset - 1); if( _temp4882.base == 0? 1:( _temp4884 <
_temp4882.base? 1: _temp4884 >= _temp4882.last_plus_one)){ _throw(
Null_Exception);}* _temp4884;})); _temp4881;}); _temp4880;})); _temp4879;});
_temp4878;}); break; case 190: _LL4877: yyval=( void*)({ struct Cyc_Type_tok_struct*
_temp4886=( struct Cyc_Type_tok_struct*) GC_malloc( sizeof( struct Cyc_Type_tok_struct));
_temp4886[ 0]=({ struct Cyc_Type_tok_struct _temp4887; _temp4887.tag= Cyc_Type_tok;
_temp4887.f1=( void*)(( void*)({ struct Cyc_Absyn_JoinEff_struct* _temp4888=(
struct Cyc_Absyn_JoinEff_struct*) GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct));
_temp4888[ 0]=({ struct Cyc_Absyn_JoinEff_struct _temp4889; _temp4889.tag= Cyc_Absyn_JoinEff;
_temp4889.f1=({ struct Cyc_List_List* _temp4890=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4890->hd=( void*) Cyc_yyget_Type_tok(({
struct _tagged_ptr2 _temp4894= yyvs; void** _temp4896= _temp4894.curr +(
yyvsp_offset - 2); if( _temp4894.base == 0? 1:( _temp4896 < _temp4894.base? 1:
_temp4896 >= _temp4894.last_plus_one)){ _throw( Null_Exception);}* _temp4896;}));
_temp4890->tl= Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp4891= yyvs;
void** _temp4893= _temp4891.curr + yyvsp_offset; if( _temp4891.base == 0? 1:(
_temp4893 < _temp4891.base? 1: _temp4893 >= _temp4891.last_plus_one)){ _throw(
Null_Exception);}* _temp4893;})); _temp4890;}); _temp4889;}); _temp4888;}));
_temp4887;}); _temp4886;}); break; case 191: _LL4885: yyval=( void*)({ struct
Cyc_TypeList_tok_struct* _temp4898=( struct Cyc_TypeList_tok_struct*) GC_malloc(
sizeof( struct Cyc_TypeList_tok_struct)); _temp4898[ 0]=({ struct Cyc_TypeList_tok_struct
_temp4899; _temp4899.tag= Cyc_TypeList_tok; _temp4899.f1=({ struct Cyc_List_List*
_temp4900=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp4900->hd=( void*) Cyc_yyget_Type_tok(({ struct _tagged_ptr2 _temp4901= yyvs;
void** _temp4903= _temp4901.curr + yyvsp_offset; if( _temp4901.base == 0? 1:(
_temp4903 < _temp4901.base? 1: _temp4903 >= _temp4901.last_plus_one)){ _throw(
Null_Exception);}* _temp4903;})); _temp4900->tl= 0; _temp4900;}); _temp4899;});
_temp4898;}); break; case 192: _LL4897: yyval=( void*)({ struct Cyc_TypeList_tok_struct*
_temp4905=( struct Cyc_TypeList_tok_struct*) GC_malloc( sizeof( struct Cyc_TypeList_tok_struct));
_temp4905[ 0]=({ struct Cyc_TypeList_tok_struct _temp4906; _temp4906.tag= Cyc_TypeList_tok;
_temp4906.f1=({ struct Cyc_List_List* _temp4907=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4907->hd=( void*) Cyc_yyget_Type_tok(({
struct _tagged_ptr2 _temp4911= yyvs; void** _temp4913= _temp4911.curr +
yyvsp_offset; if( _temp4911.base == 0? 1:( _temp4913 < _temp4911.base? 1:
_temp4913 >= _temp4911.last_plus_one)){ _throw( Null_Exception);}* _temp4913;}));
_temp4907->tl= Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp4908= yyvs;
void** _temp4910= _temp4908.curr +( yyvsp_offset - 2); if( _temp4908.base == 0?
1:( _temp4910 < _temp4908.base? 1: _temp4910 >= _temp4908.last_plus_one)){
_throw( Null_Exception);}* _temp4910;})); _temp4907;}); _temp4906;}); _temp4905;});
break; case 193: _LL4904: yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct*
_temp4915=( struct Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct
Cyc_AbstractDeclarator_tok_struct)); _temp4915[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct
_temp4916; _temp4916.tag= Cyc_AbstractDeclarator_tok; _temp4916.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp4917=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp4917->tms= Cyc_yyget_TypeModifierList_tok(({ struct _tagged_ptr2 _temp4918=
yyvs; void** _temp4920= _temp4918.curr + yyvsp_offset; if( _temp4918.base == 0?
1:( _temp4920 < _temp4918.base? 1: _temp4920 >= _temp4918.last_plus_one)){
_throw( Null_Exception);}* _temp4920;})); _temp4917;}); _temp4916;}); _temp4915;});
break; case 194: _LL4914: yyval=({ struct _tagged_ptr2 _temp4922= yyvs; void**
_temp4924= _temp4922.curr + yyvsp_offset; if( _temp4922.base == 0? 1:( _temp4924
< _temp4922.base? 1: _temp4924 >= _temp4922.last_plus_one)){ _throw(
Null_Exception);}* _temp4924;}); break; case 195: _LL4921: yyval=( void*)({
struct Cyc_AbstractDeclarator_tok_struct* _temp4926=( struct Cyc_AbstractDeclarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct)); _temp4926[ 0]=({
struct Cyc_AbstractDeclarator_tok_struct _temp4927; _temp4927.tag= Cyc_AbstractDeclarator_tok;
_temp4927.f1=({ struct Cyc_Parse_Abstractdeclarator* _temp4928=( struct Cyc_Parse_Abstractdeclarator*)
GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator)); _temp4928->tms=((
struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_imp_append)(
Cyc_yyget_TypeModifierList_tok(({ struct _tagged_ptr2 _temp4929= yyvs; void**
_temp4931= _temp4929.curr +( yyvsp_offset - 1); if( _temp4929.base == 0? 1:(
_temp4931 < _temp4929.base? 1: _temp4931 >= _temp4929.last_plus_one)){ _throw(
Null_Exception);}* _temp4931;})),( Cyc_yyget_AbstractDeclarator_tok(({ struct
_tagged_ptr2 _temp4932= yyvs; void** _temp4934= _temp4932.curr + yyvsp_offset;
if( _temp4932.base == 0? 1:( _temp4934 < _temp4932.base? 1: _temp4934 >=
_temp4932.last_plus_one)){ _throw( Null_Exception);}* _temp4934;})))->tms);
_temp4928;}); _temp4927;}); _temp4926;}); break; case 196: _LL4925: yyval=({
struct _tagged_ptr2 _temp4936= yyvs; void** _temp4938= _temp4936.curr +(
yyvsp_offset - 1); if( _temp4936.base == 0? 1:( _temp4938 < _temp4936.base? 1:
_temp4938 >= _temp4936.last_plus_one)){ _throw( Null_Exception);}* _temp4938;});
break; case 197: _LL4935: yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct*
_temp4940=( struct Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct
Cyc_AbstractDeclarator_tok_struct)); _temp4940[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct
_temp4941; _temp4941.tag= Cyc_AbstractDeclarator_tok; _temp4941.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp4942=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp4942->tms=({ struct Cyc_List_List* _temp4943=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4943->hd=( void*)(( void*) Cyc_Absyn_Carray_mod);
_temp4943->tl= 0; _temp4943;}); _temp4942;}); _temp4941;}); _temp4940;}); break;
case 198: _LL4939: yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct*
_temp4945=( struct Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct
Cyc_AbstractDeclarator_tok_struct)); _temp4945[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct
_temp4946; _temp4946.tag= Cyc_AbstractDeclarator_tok; _temp4946.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp4947=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp4947->tms=({ struct Cyc_List_List* _temp4948=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4948->hd=( void*)(( void*) Cyc_Absyn_Carray_mod);
_temp4948->tl=( Cyc_yyget_AbstractDeclarator_tok(({ struct _tagged_ptr2
_temp4949= yyvs; void** _temp4951= _temp4949.curr +( yyvsp_offset - 2); if(
_temp4949.base == 0? 1:( _temp4951 < _temp4949.base? 1: _temp4951 >= _temp4949.last_plus_one)){
_throw( Null_Exception);}* _temp4951;})))->tms; _temp4948;}); _temp4947;});
_temp4946;}); _temp4945;}); break; case 199: _LL4944: yyval=( void*)({ struct
Cyc_AbstractDeclarator_tok_struct* _temp4953=( struct Cyc_AbstractDeclarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct)); _temp4953[ 0]=({
struct Cyc_AbstractDeclarator_tok_struct _temp4954; _temp4954.tag= Cyc_AbstractDeclarator_tok;
_temp4954.f1=({ struct Cyc_Parse_Abstractdeclarator* _temp4955=( struct Cyc_Parse_Abstractdeclarator*)
GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator)); _temp4955->tms=({
struct Cyc_List_List* _temp4956=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp4956->hd=( void*)(( void*)({ struct Cyc_Absyn_ConstArray_mod_struct*
_temp4957=( struct Cyc_Absyn_ConstArray_mod_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_ConstArray_mod_struct)); _temp4957[ 0]=({ struct Cyc_Absyn_ConstArray_mod_struct
_temp4958; _temp4958.tag= Cyc_Absyn_ConstArray_mod; _temp4958.f1= Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp4959= yyvs; void** _temp4961= _temp4959.curr +(
yyvsp_offset - 1); if( _temp4959.base == 0? 1:( _temp4961 < _temp4959.base? 1:
_temp4961 >= _temp4959.last_plus_one)){ _throw( Null_Exception);}* _temp4961;}));
_temp4958;}); _temp4957;})); _temp4956->tl= 0; _temp4956;}); _temp4955;});
_temp4954;}); _temp4953;}); break; case 200: _LL4952: yyval=( void*)({ struct
Cyc_AbstractDeclarator_tok_struct* _temp4963=( struct Cyc_AbstractDeclarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct)); _temp4963[ 0]=({
struct Cyc_AbstractDeclarator_tok_struct _temp4964; _temp4964.tag= Cyc_AbstractDeclarator_tok;
_temp4964.f1=({ struct Cyc_Parse_Abstractdeclarator* _temp4965=( struct Cyc_Parse_Abstractdeclarator*)
GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator)); _temp4965->tms=({
struct Cyc_List_List* _temp4966=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp4966->hd=( void*)(( void*)({ struct Cyc_Absyn_ConstArray_mod_struct*
_temp4970=( struct Cyc_Absyn_ConstArray_mod_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_ConstArray_mod_struct)); _temp4970[ 0]=({ struct Cyc_Absyn_ConstArray_mod_struct
_temp4971; _temp4971.tag= Cyc_Absyn_ConstArray_mod; _temp4971.f1= Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp4972= yyvs; void** _temp4974= _temp4972.curr +(
yyvsp_offset - 1); if( _temp4972.base == 0? 1:( _temp4974 < _temp4972.base? 1:
_temp4974 >= _temp4972.last_plus_one)){ _throw( Null_Exception);}* _temp4974;}));
_temp4971;}); _temp4970;})); _temp4966->tl=( Cyc_yyget_AbstractDeclarator_tok(({
struct _tagged_ptr2 _temp4967= yyvs; void** _temp4969= _temp4967.curr +(
yyvsp_offset - 3); if( _temp4967.base == 0? 1:( _temp4969 < _temp4967.base? 1:
_temp4969 >= _temp4967.last_plus_one)){ _throw( Null_Exception);}* _temp4969;})))->tms;
_temp4966;}); _temp4965;}); _temp4964;}); _temp4963;}); break; case 201: _LL4962:
yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct* _temp4976=( struct
Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct));
_temp4976[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct _temp4977; _temp4977.tag=
Cyc_AbstractDeclarator_tok; _temp4977.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp4978=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp4978->tms=({ struct Cyc_List_List* _temp4979=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp4979->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp4980=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp4980[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp4981; _temp4981.tag= Cyc_Absyn_Function_mod;
_temp4981.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp4982=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp4982[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp4983; _temp4983.tag= Cyc_Absyn_WithTypes;
_temp4983.f1= 0; _temp4983.f2= 0; _temp4983.f3= 0; _temp4983;}); _temp4982;}));
_temp4981;}); _temp4980;})); _temp4979->tl= 0; _temp4979;}); _temp4978;});
_temp4977;}); _temp4976;}); break; case 202: _LL4975: yyval=( void*)({ struct
Cyc_AbstractDeclarator_tok_struct* _temp4985=( struct Cyc_AbstractDeclarator_tok_struct*)
GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct)); _temp4985[ 0]=({
struct Cyc_AbstractDeclarator_tok_struct _temp4986; _temp4986.tag= Cyc_AbstractDeclarator_tok;
_temp4986.f1=({ struct Cyc_Parse_Abstractdeclarator* _temp4987=( struct Cyc_Parse_Abstractdeclarator*)
GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator)); _temp4987->tms=({
struct Cyc_List_List* _temp4988=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp4988->hd=( void*)(( void*)({ struct Cyc_Absyn_Function_mod_struct*
_temp4989=( struct Cyc_Absyn_Function_mod_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct));
_temp4989[ 0]=({ struct Cyc_Absyn_Function_mod_struct _temp4990; _temp4990.tag=
Cyc_Absyn_Function_mod; _temp4990.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct*
_temp4991=( struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp4991[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp4992; _temp4992.tag= Cyc_Absyn_WithTypes;
_temp4992.f1= 0; _temp4992.f2= 0; _temp4992.f3=({ struct Cyc_Core_Opt* _temp4993=(
struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp4993->v=(
void*)(( void*)({ struct Cyc_Absyn_JoinEff_struct* _temp4994=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp4994[ 0]=({ struct
Cyc_Absyn_JoinEff_struct _temp4995; _temp4995.tag= Cyc_Absyn_JoinEff; _temp4995.f1=
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp4996= yyvs; void** _temp4998=
_temp4996.curr +( yyvsp_offset - 1); if( _temp4996.base == 0? 1:( _temp4998 <
_temp4996.base? 1: _temp4998 >= _temp4996.last_plus_one)){ _throw(
Null_Exception);}* _temp4998;})); _temp4995;}); _temp4994;})); _temp4993;});
_temp4992;}); _temp4991;})); _temp4990;}); _temp4989;})); _temp4988->tl= 0;
_temp4988;}); _temp4987;}); _temp4986;}); _temp4985;}); break; case 203: _LL4984: {
struct _tuple16 _temp5005; struct Cyc_Core_Opt* _temp5006; int _temp5008; struct
Cyc_List_List* _temp5010; struct _tuple16* _temp5003= Cyc_yyget_ParamDeclListBool_tok(({
struct _tagged_ptr2 _temp5000= yyvs; void** _temp5002= _temp5000.curr +(
yyvsp_offset - 1); if( _temp5000.base == 0? 1:( _temp5002 < _temp5000.base? 1:
_temp5002 >= _temp5000.last_plus_one)){ _throw( Null_Exception);}* _temp5002;}));
_temp5005=* _temp5003; _LL5011: _temp5010= _temp5005.f1; goto _LL5009; _LL5009:
_temp5008= _temp5005.f2; goto _LL5007; _LL5007: _temp5006= _temp5005.f3; goto
_LL5004; _LL5004: yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct*
_temp5012=( struct Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct
Cyc_AbstractDeclarator_tok_struct)); _temp5012[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct
_temp5013; _temp5013.tag= Cyc_AbstractDeclarator_tok; _temp5013.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp5014=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp5014->tms=({ struct Cyc_List_List* _temp5015=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5015->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp5016=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp5016[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp5017; _temp5017.tag= Cyc_Absyn_Function_mod;
_temp5017.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp5018=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp5018[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp5019; _temp5019.tag= Cyc_Absyn_WithTypes;
_temp5019.f1= _temp5010; _temp5019.f2= _temp5008; _temp5019.f3= _temp5006;
_temp5019;}); _temp5018;})); _temp5017;}); _temp5016;})); _temp5015->tl= 0;
_temp5015;}); _temp5014;}); _temp5013;}); _temp5012;}); break;} case 204:
_LL4999: yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct* _temp5021=(
struct Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct));
_temp5021[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct _temp5022; _temp5022.tag=
Cyc_AbstractDeclarator_tok; _temp5022.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp5023=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp5023->tms=({ struct Cyc_List_List* _temp5024=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5024->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp5028=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp5028[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp5029; _temp5029.tag= Cyc_Absyn_Function_mod;
_temp5029.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp5030=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp5030[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp5031; _temp5031.tag= Cyc_Absyn_WithTypes;
_temp5031.f1= 0; _temp5031.f2= 0; _temp5031.f3= 0; _temp5031;}); _temp5030;}));
_temp5029;}); _temp5028;})); _temp5024->tl=( Cyc_yyget_AbstractDeclarator_tok(({
struct _tagged_ptr2 _temp5025= yyvs; void** _temp5027= _temp5025.curr +(
yyvsp_offset - 2); if( _temp5025.base == 0? 1:( _temp5027 < _temp5025.base? 1:
_temp5027 >= _temp5025.last_plus_one)){ _throw( Null_Exception);}* _temp5027;})))->tms;
_temp5024;}); _temp5023;}); _temp5022;}); _temp5021;}); break; case 205: _LL5020: {
struct Cyc_Core_Opt* eff=({ struct Cyc_Core_Opt* _temp5044=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp5044->v=( void*)(( void*)({
struct Cyc_Absyn_JoinEff_struct* _temp5045=( struct Cyc_Absyn_JoinEff_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_JoinEff_struct)); _temp5045[ 0]=({ struct
Cyc_Absyn_JoinEff_struct _temp5046; _temp5046.tag= Cyc_Absyn_JoinEff; _temp5046.f1=
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp5047= yyvs; void** _temp5049=
_temp5047.curr +( yyvsp_offset - 1); if( _temp5047.base == 0? 1:( _temp5049 <
_temp5047.base? 1: _temp5049 >= _temp5047.last_plus_one)){ _throw(
Null_Exception);}* _temp5049;})); _temp5046;}); _temp5045;})); _temp5044;});
yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct* _temp5033=( struct
Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct));
_temp5033[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct _temp5034; _temp5034.tag=
Cyc_AbstractDeclarator_tok; _temp5034.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp5035=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp5035->tms=({ struct Cyc_List_List* _temp5036=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5036->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp5040=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp5040[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp5041; _temp5041.tag= Cyc_Absyn_Function_mod;
_temp5041.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp5042=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp5042[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp5043; _temp5043.tag= Cyc_Absyn_WithTypes;
_temp5043.f1= 0; _temp5043.f2= 0; _temp5043.f3= eff; _temp5043;}); _temp5042;}));
_temp5041;}); _temp5040;})); _temp5036->tl=( Cyc_yyget_AbstractDeclarator_tok(({
struct _tagged_ptr2 _temp5037= yyvs; void** _temp5039= _temp5037.curr +(
yyvsp_offset - 4); if( _temp5037.base == 0? 1:( _temp5039 < _temp5037.base? 1:
_temp5039 >= _temp5037.last_plus_one)){ _throw( Null_Exception);}* _temp5039;})))->tms;
_temp5036;}); _temp5035;}); _temp5034;}); _temp5033;}); break;} case 206:
_LL5032: { struct _tuple16 _temp5056; struct Cyc_Core_Opt* _temp5057; int
_temp5059; struct Cyc_List_List* _temp5061; struct _tuple16* _temp5054= Cyc_yyget_ParamDeclListBool_tok(({
struct _tagged_ptr2 _temp5051= yyvs; void** _temp5053= _temp5051.curr +(
yyvsp_offset - 1); if( _temp5051.base == 0? 1:( _temp5053 < _temp5051.base? 1:
_temp5053 >= _temp5051.last_plus_one)){ _throw( Null_Exception);}* _temp5053;}));
_temp5056=* _temp5054; _LL5062: _temp5061= _temp5056.f1; goto _LL5060; _LL5060:
_temp5059= _temp5056.f2; goto _LL5058; _LL5058: _temp5057= _temp5056.f3; goto
_LL5055; _LL5055: yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct*
_temp5063=( struct Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct
Cyc_AbstractDeclarator_tok_struct)); _temp5063[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct
_temp5064; _temp5064.tag= Cyc_AbstractDeclarator_tok; _temp5064.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp5065=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp5065->tms=({ struct Cyc_List_List* _temp5066=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5066->hd=( void*)(( void*)({
struct Cyc_Absyn_Function_mod_struct* _temp5070=( struct Cyc_Absyn_Function_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Function_mod_struct)); _temp5070[ 0]=({
struct Cyc_Absyn_Function_mod_struct _temp5071; _temp5071.tag= Cyc_Absyn_Function_mod;
_temp5071.f1=( void*)(( void*)({ struct Cyc_Absyn_WithTypes_struct* _temp5072=(
struct Cyc_Absyn_WithTypes_struct*) GC_malloc( sizeof( struct Cyc_Absyn_WithTypes_struct));
_temp5072[ 0]=({ struct Cyc_Absyn_WithTypes_struct _temp5073; _temp5073.tag= Cyc_Absyn_WithTypes;
_temp5073.f1= _temp5061; _temp5073.f2= _temp5059; _temp5073.f3= _temp5057;
_temp5073;}); _temp5072;})); _temp5071;}); _temp5070;})); _temp5066->tl=( Cyc_yyget_AbstractDeclarator_tok(({
struct _tagged_ptr2 _temp5067= yyvs; void** _temp5069= _temp5067.curr +(
yyvsp_offset - 3); if( _temp5067.base == 0? 1:( _temp5069 < _temp5067.base? 1:
_temp5069 >= _temp5067.last_plus_one)){ _throw( Null_Exception);}* _temp5069;})))->tms;
_temp5066;}); _temp5065;}); _temp5064;}); _temp5063;}); break;} case 207:
_LL5050: { struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(*
f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment* env,
struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5090= yyls; struct Cyc_Yyltype* _temp5092= _temp5090.curr
+( yylsp_offset - 2); if( _temp5090.base == 0? 1:( _temp5092 < _temp5090.base? 1:
_temp5092 >= _temp5090.last_plus_one)){ _throw( Null_Exception);}* _temp5092;}).first_line,({
struct _tagged_ptr3 _temp5093= yyls; struct Cyc_Yyltype* _temp5095= _temp5093.curr
+ yylsp_offset; if( _temp5093.base == 0? 1:( _temp5095 < _temp5093.base? 1:
_temp5095 >= _temp5093.last_plus_one)){ _throw( Null_Exception);}* _temp5095;}).last_line),((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp5096= yyvs; void** _temp5098= _temp5096.curr +(
yyvsp_offset - 1); if( _temp5096.base == 0? 1:( _temp5098 < _temp5096.base? 1:
_temp5098 >= _temp5096.last_plus_one)){ _throw( Null_Exception);}* _temp5098;}))));
yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct* _temp5075=( struct
Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct));
_temp5075[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct _temp5076; _temp5076.tag=
Cyc_AbstractDeclarator_tok; _temp5076.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp5077=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp5077->tms=({ struct Cyc_List_List* _temp5078=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5078->hd=( void*)(( void*)({
struct Cyc_Absyn_TypeParams_mod_struct* _temp5082=( struct Cyc_Absyn_TypeParams_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TypeParams_mod_struct)); _temp5082[ 0]=({
struct Cyc_Absyn_TypeParams_mod_struct _temp5083; _temp5083.tag= Cyc_Absyn_TypeParams_mod;
_temp5083.f1= ts; _temp5083.f2= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5084= yyls; struct Cyc_Yyltype* _temp5086= _temp5084.curr +(
yylsp_offset - 2); if( _temp5084.base == 0? 1:( _temp5086 < _temp5084.base? 1:
_temp5086 >= _temp5084.last_plus_one)){ _throw( Null_Exception);}* _temp5086;}).first_line,({
struct _tagged_ptr3 _temp5087= yyls; struct Cyc_Yyltype* _temp5089= _temp5087.curr
+ yylsp_offset; if( _temp5087.base == 0? 1:( _temp5089 < _temp5087.base? 1:
_temp5089 >= _temp5087.last_plus_one)){ _throw( Null_Exception);}* _temp5089;}).last_line);
_temp5083.f3= 0; _temp5083;}); _temp5082;})); _temp5078->tl=( Cyc_yyget_AbstractDeclarator_tok(({
struct _tagged_ptr2 _temp5079= yyvs; void** _temp5081= _temp5079.curr +(
yyvsp_offset - 3); if( _temp5079.base == 0? 1:( _temp5081 < _temp5079.base? 1:
_temp5081 >= _temp5079.last_plus_one)){ _throw( Null_Exception);}* _temp5081;})))->tms;
_temp5078;}); _temp5077;}); _temp5076;}); _temp5075;}); break;} case 208:
_LL5074:(( struct Cyc_Lexing_lexbuf*)({ struct Cyc_Core_Opt* _temp5100= Cyc_Parse_lbuf;
if( _temp5100 == 0){ _throw( Null_Exception);} _temp5100->v;}))->lex_curr_pos -=
1;{ struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(*
f)( struct Cyc_Position_Segment*, void*), struct Cyc_Position_Segment* env,
struct Cyc_List_List* x)) Cyc_List_map_c)( Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5116= yyls; struct Cyc_Yyltype* _temp5118= _temp5116.curr
+( yylsp_offset - 2); if( _temp5116.base == 0? 1:( _temp5118 < _temp5116.base? 1:
_temp5118 >= _temp5116.last_plus_one)){ _throw( Null_Exception);}* _temp5118;}).first_line,({
struct _tagged_ptr3 _temp5119= yyls; struct Cyc_Yyltype* _temp5121= _temp5119.curr
+ yylsp_offset; if( _temp5119.base == 0? 1:( _temp5121 < _temp5119.base? 1:
_temp5121 >= _temp5119.last_plus_one)){ _throw( Null_Exception);}* _temp5121;}).last_line),((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp5122= yyvs; void** _temp5124= _temp5122.curr +(
yyvsp_offset - 1); if( _temp5122.base == 0? 1:( _temp5124 < _temp5122.base? 1:
_temp5124 >= _temp5122.last_plus_one)){ _throw( Null_Exception);}* _temp5124;}))));
yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct* _temp5101=( struct
Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct));
_temp5101[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct _temp5102; _temp5102.tag=
Cyc_AbstractDeclarator_tok; _temp5102.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp5103=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp5103->tms=({ struct Cyc_List_List* _temp5104=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5104->hd=( void*)(( void*)({
struct Cyc_Absyn_TypeParams_mod_struct* _temp5108=( struct Cyc_Absyn_TypeParams_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TypeParams_mod_struct)); _temp5108[ 0]=({
struct Cyc_Absyn_TypeParams_mod_struct _temp5109; _temp5109.tag= Cyc_Absyn_TypeParams_mod;
_temp5109.f1= ts; _temp5109.f2= Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5110= yyls; struct Cyc_Yyltype* _temp5112= _temp5110.curr +(
yylsp_offset - 2); if( _temp5110.base == 0? 1:( _temp5112 < _temp5110.base? 1:
_temp5112 >= _temp5110.last_plus_one)){ _throw( Null_Exception);}* _temp5112;}).first_line,({
struct _tagged_ptr3 _temp5113= yyls; struct Cyc_Yyltype* _temp5115= _temp5113.curr
+ yylsp_offset; if( _temp5113.base == 0? 1:( _temp5115 < _temp5113.base? 1:
_temp5115 >= _temp5113.last_plus_one)){ _throw( Null_Exception);}* _temp5115;}).last_line);
_temp5109.f3= 0; _temp5109;}); _temp5108;})); _temp5104->tl=( Cyc_yyget_AbstractDeclarator_tok(({
struct _tagged_ptr2 _temp5105= yyvs; void** _temp5107= _temp5105.curr +(
yyvsp_offset - 3); if( _temp5105.base == 0? 1:( _temp5107 < _temp5105.base? 1:
_temp5107 >= _temp5105.last_plus_one)){ _throw( Null_Exception);}* _temp5107;})))->tms;
_temp5104;}); _temp5103;}); _temp5102;}); _temp5101;}); break;} case 209:
_LL5099: yyval=( void*)({ struct Cyc_AbstractDeclarator_tok_struct* _temp5126=(
struct Cyc_AbstractDeclarator_tok_struct*) GC_malloc( sizeof( struct Cyc_AbstractDeclarator_tok_struct));
_temp5126[ 0]=({ struct Cyc_AbstractDeclarator_tok_struct _temp5127; _temp5127.tag=
Cyc_AbstractDeclarator_tok; _temp5127.f1=({ struct Cyc_Parse_Abstractdeclarator*
_temp5128=( struct Cyc_Parse_Abstractdeclarator*) GC_malloc( sizeof( struct Cyc_Parse_Abstractdeclarator));
_temp5128->tms=({ struct Cyc_List_List* _temp5129=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5129->hd=( void*)(( void*)({
struct Cyc_Absyn_Attributes_mod_struct* _temp5133=( struct Cyc_Absyn_Attributes_mod_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Attributes_mod_struct)); _temp5133[ 0]=({
struct Cyc_Absyn_Attributes_mod_struct _temp5134; _temp5134.tag= Cyc_Absyn_Attributes_mod;
_temp5134.f1= Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5135= yyls;
struct Cyc_Yyltype* _temp5137= _temp5135.curr + yylsp_offset; if( _temp5135.base
== 0? 1:( _temp5137 < _temp5135.base? 1: _temp5137 >= _temp5135.last_plus_one)){
_throw( Null_Exception);}* _temp5137;}).first_line,({ struct _tagged_ptr3
_temp5138= yyls; struct Cyc_Yyltype* _temp5140= _temp5138.curr + yylsp_offset;
if( _temp5138.base == 0? 1:( _temp5140 < _temp5138.base? 1: _temp5140 >=
_temp5138.last_plus_one)){ _throw( Null_Exception);}* _temp5140;}).last_line);
_temp5134.f2= Cyc_yyget_AttributeList_tok(({ struct _tagged_ptr2 _temp5141= yyvs;
void** _temp5143= _temp5141.curr + yyvsp_offset; if( _temp5141.base == 0? 1:(
_temp5143 < _temp5141.base? 1: _temp5143 >= _temp5141.last_plus_one)){ _throw(
Null_Exception);}* _temp5143;})); _temp5134;}); _temp5133;})); _temp5129->tl=(
Cyc_yyget_AbstractDeclarator_tok(({ struct _tagged_ptr2 _temp5130= yyvs; void**
_temp5132= _temp5130.curr +( yyvsp_offset - 1); if( _temp5130.base == 0? 1:(
_temp5132 < _temp5130.base? 1: _temp5132 >= _temp5130.last_plus_one)){ _throw(
Null_Exception);}* _temp5132;})))->tms; _temp5129;}); _temp5128;}); _temp5127;});
_temp5126;}); break; case 210: _LL5125: yyval=({ struct _tagged_ptr2 _temp5145=
yyvs; void** _temp5147= _temp5145.curr + yyvsp_offset; if( _temp5145.base == 0?
1:( _temp5147 < _temp5145.base? 1: _temp5147 >= _temp5145.last_plus_one)){
_throw( Null_Exception);}* _temp5147;}); break; case 211: _LL5144: yyval=({
struct _tagged_ptr2 _temp5149= yyvs; void** _temp5151= _temp5149.curr +
yyvsp_offset; if( _temp5149.base == 0? 1:( _temp5151 < _temp5149.base? 1:
_temp5151 >= _temp5149.last_plus_one)){ _throw( Null_Exception);}* _temp5151;});
break; case 212: _LL5148: yyval=({ struct _tagged_ptr2 _temp5153= yyvs; void**
_temp5155= _temp5153.curr + yyvsp_offset; if( _temp5153.base == 0? 1:( _temp5155
< _temp5153.base? 1: _temp5155 >= _temp5153.last_plus_one)){ _throw(
Null_Exception);}* _temp5155;}); break; case 213: _LL5152: yyval=({ struct
_tagged_ptr2 _temp5157= yyvs; void** _temp5159= _temp5157.curr + yyvsp_offset;
if( _temp5157.base == 0? 1:( _temp5159 < _temp5157.base? 1: _temp5159 >=
_temp5157.last_plus_one)){ _throw( Null_Exception);}* _temp5159;}); break; case
214: _LL5156: yyval=({ struct _tagged_ptr2 _temp5161= yyvs; void** _temp5163=
_temp5161.curr + yyvsp_offset; if( _temp5161.base == 0? 1:( _temp5163 <
_temp5161.base? 1: _temp5163 >= _temp5161.last_plus_one)){ _throw(
Null_Exception);}* _temp5163;}); break; case 215: _LL5160: yyval=({ struct
_tagged_ptr2 _temp5165= yyvs; void** _temp5167= _temp5165.curr + yyvsp_offset;
if( _temp5165.base == 0? 1:( _temp5167 < _temp5165.base? 1: _temp5167 >=
_temp5165.last_plus_one)){ _throw( Null_Exception);}* _temp5167;}); break; case
216: _LL5164: if( Cyc_String_zstrcmp( Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp5169= yyvs; void** _temp5171= _temp5169.curr +( yyvsp_offset -
3); if( _temp5169.base == 0? 1:( _temp5171 < _temp5169.base? 1: _temp5171 >=
_temp5169.last_plus_one)){ _throw( Null_Exception);}* _temp5171;})),( struct
_tagged_string)({ char* _temp5172=( char*)"`H"; struct _tagged_string _temp5173;
_temp5173.curr= _temp5172; _temp5173.base= _temp5172; _temp5173.last_plus_one=
_temp5172 + 3; _temp5173;})) == 0){ Cyc_Parse_err(( struct _tagged_string)({
char* _temp5174=( char*)"bad occurrence of heap region `H"; struct
_tagged_string _temp5175; _temp5175.curr= _temp5174; _temp5175.base= _temp5174;
_temp5175.last_plus_one= _temp5174 + 33; _temp5175;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5176= yyls; struct Cyc_Yyltype* _temp5178= _temp5176.curr
+( yylsp_offset - 3); if( _temp5176.base == 0? 1:( _temp5178 < _temp5176.base? 1:
_temp5178 >= _temp5176.last_plus_one)){ _throw( Null_Exception);}* _temp5178;}).first_line,({
struct _tagged_ptr3 _temp5179= yyls; struct Cyc_Yyltype* _temp5181= _temp5179.curr
+( yylsp_offset - 3); if( _temp5179.base == 0? 1:( _temp5181 < _temp5179.base? 1:
_temp5181 >= _temp5179.last_plus_one)){ _throw( Null_Exception);}* _temp5181;}).last_line));}{
struct Cyc_Absyn_Tvar* tv=({ struct Cyc_Absyn_Tvar* _temp5204=( struct Cyc_Absyn_Tvar*)
GC_malloc( sizeof( struct Cyc_Absyn_Tvar)); _temp5204->name=({ struct
_tagged_string* _temp5205=( struct _tagged_string*) GC_malloc( sizeof( struct
_tagged_string)); _temp5205[ 0]= Cyc_yyget_String_tok(({ struct _tagged_ptr2
_temp5206= yyvs; void** _temp5208= _temp5206.curr +( yyvsp_offset - 3); if(
_temp5206.base == 0? 1:( _temp5208 < _temp5206.base? 1: _temp5208 >= _temp5206.last_plus_one)){
_throw( Null_Exception);}* _temp5208;})); _temp5205;}); _temp5204->kind=((
struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(( void*) Cyc_Absyn_RgnKind);
_temp5204;}); void* t=( void*)({ struct Cyc_Absyn_VarType_struct* _temp5202=(
struct Cyc_Absyn_VarType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct));
_temp5202[ 0]=({ struct Cyc_Absyn_VarType_struct _temp5203; _temp5203.tag= Cyc_Absyn_VarType;
_temp5203.f1= tv; _temp5203;}); _temp5202;}); yyval=( void*)({ struct Cyc_Stmt_tok_struct*
_temp5182=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5182[ 0]=({ struct Cyc_Stmt_tok_struct _temp5183; _temp5183.tag= Cyc_Stmt_tok;
_temp5183.f1= Cyc_Absyn_new_stmt(( void*)({ struct Cyc_Absyn_Region_s_struct*
_temp5184=( struct Cyc_Absyn_Region_s_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Region_s_struct));
_temp5184[ 0]=({ struct Cyc_Absyn_Region_s_struct _temp5185; _temp5185.tag= Cyc_Absyn_Region_s;
_temp5185.f1= tv; _temp5185.f2= Cyc_Absyn_new_vardecl(({ struct _tuple1*
_temp5186=( struct _tuple1*) GC_malloc( sizeof( struct _tuple1)); _temp5186->f1=(
void*) Cyc_Absyn_Loc_n; _temp5186->f2=({ struct _tagged_string* _temp5187=(
struct _tagged_string*) GC_malloc( sizeof( struct _tagged_string)); _temp5187[ 0]=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp5188= yyvs; void** _temp5190=
_temp5188.curr +( yyvsp_offset - 1); if( _temp5188.base == 0? 1:( _temp5190 <
_temp5188.base? 1: _temp5190 >= _temp5188.last_plus_one)){ _throw(
Null_Exception);}* _temp5190;})); _temp5187;}); _temp5186;}),( void*)({ struct
Cyc_Absyn_RgnHandleType_struct* _temp5191=( struct Cyc_Absyn_RgnHandleType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_RgnHandleType_struct)); _temp5191[ 0]=({
struct Cyc_Absyn_RgnHandleType_struct _temp5192; _temp5192.tag= Cyc_Absyn_RgnHandleType;
_temp5192.f1=( void*) t; _temp5192;}); _temp5191;}), 0); _temp5185.f3= Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5193= yyvs; void** _temp5195= _temp5193.curr +
yyvsp_offset; if( _temp5193.base == 0? 1:( _temp5195 < _temp5193.base? 1:
_temp5195 >= _temp5193.last_plus_one)){ _throw( Null_Exception);}* _temp5195;}));
_temp5185;}); _temp5184;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp5196= yyls; struct Cyc_Yyltype* _temp5198= _temp5196.curr +( yylsp_offset -
5); if( _temp5196.base == 0? 1:( _temp5198 < _temp5196.base? 1: _temp5198 >=
_temp5196.last_plus_one)){ _throw( Null_Exception);}* _temp5198;}).first_line,({
struct _tagged_ptr3 _temp5199= yyls; struct Cyc_Yyltype* _temp5201= _temp5199.curr
+ yylsp_offset; if( _temp5199.base == 0? 1:( _temp5201 < _temp5199.base? 1:
_temp5201 >= _temp5199.last_plus_one)){ _throw( Null_Exception);}* _temp5201;}).last_line));
_temp5183;}); _temp5182;}); break;} case 217: _LL5168: if( Cyc_String_zstrcmp(
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp5210= yyvs; void** _temp5212=
_temp5210.curr +( yyvsp_offset - 1); if( _temp5210.base == 0? 1:( _temp5212 <
_temp5210.base? 1: _temp5212 >= _temp5210.last_plus_one)){ _throw(
Null_Exception);}* _temp5212;})),( struct _tagged_string)({ char* _temp5213=(
char*)"H"; struct _tagged_string _temp5214; _temp5214.curr= _temp5213; _temp5214.base=
_temp5213; _temp5214.last_plus_one= _temp5213 + 2; _temp5214;})) == 0){ Cyc_Parse_err((
struct _tagged_string)({ char* _temp5215=( char*)"bad occurrence of heap region `H";
struct _tagged_string _temp5216; _temp5216.curr= _temp5215; _temp5216.base=
_temp5215; _temp5216.last_plus_one= _temp5215 + 33; _temp5216;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5217= yyls; struct Cyc_Yyltype* _temp5219= _temp5217.curr
+ yylsp_offset; if( _temp5217.base == 0? 1:( _temp5219 < _temp5217.base? 1:
_temp5219 >= _temp5217.last_plus_one)){ _throw( Null_Exception);}* _temp5219;}).first_line,({
struct _tagged_ptr3 _temp5220= yyls; struct Cyc_Yyltype* _temp5222= _temp5220.curr
+ yylsp_offset; if( _temp5220.base == 0? 1:( _temp5222 < _temp5220.base? 1:
_temp5222 >= _temp5220.last_plus_one)){ _throw( Null_Exception);}* _temp5222;}).last_line));}{
struct Cyc_Absyn_Tvar* tv=({ struct Cyc_Absyn_Tvar* _temp5245=( struct Cyc_Absyn_Tvar*)
GC_malloc( sizeof( struct Cyc_Absyn_Tvar)); _temp5245->name=({ struct
_tagged_string* _temp5246=( struct _tagged_string*) GC_malloc( sizeof( struct
_tagged_string)); _temp5246[ 0]=({ struct _tagged_string _temp5250= Cyc_yyget_String_tok(({
struct _tagged_ptr2 _temp5247= yyvs; void** _temp5249= _temp5247.curr +(
yyvsp_offset - 1); if( _temp5247.base == 0? 1:( _temp5249 < _temp5247.base? 1:
_temp5249 >= _temp5247.last_plus_one)){ _throw( Null_Exception);}* _temp5249;}));
xprintf("`%.*s", _temp5250.last_plus_one - _temp5250.curr, _temp5250.curr);});
_temp5246;}); _temp5245->kind=(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)((
void*) Cyc_Absyn_RgnKind); _temp5245;}); void* t=( void*)({ struct Cyc_Absyn_VarType_struct*
_temp5243=( struct Cyc_Absyn_VarType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_VarType_struct));
_temp5243[ 0]=({ struct Cyc_Absyn_VarType_struct _temp5244; _temp5244.tag= Cyc_Absyn_VarType;
_temp5244.f1= tv; _temp5244;}); _temp5243;}); yyval=( void*)({ struct Cyc_Stmt_tok_struct*
_temp5223=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5223[ 0]=({ struct Cyc_Stmt_tok_struct _temp5224; _temp5224.tag= Cyc_Stmt_tok;
_temp5224.f1= Cyc_Absyn_new_stmt(( void*)({ struct Cyc_Absyn_Region_s_struct*
_temp5225=( struct Cyc_Absyn_Region_s_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Region_s_struct));
_temp5225[ 0]=({ struct Cyc_Absyn_Region_s_struct _temp5226; _temp5226.tag= Cyc_Absyn_Region_s;
_temp5226.f1= tv; _temp5226.f2= Cyc_Absyn_new_vardecl(({ struct _tuple1*
_temp5227=( struct _tuple1*) GC_malloc( sizeof( struct _tuple1)); _temp5227->f1=(
void*) Cyc_Absyn_Loc_n; _temp5227->f2=({ struct _tagged_string* _temp5228=(
struct _tagged_string*) GC_malloc( sizeof( struct _tagged_string)); _temp5228[ 0]=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp5229= yyvs; void** _temp5231=
_temp5229.curr +( yyvsp_offset - 1); if( _temp5229.base == 0? 1:( _temp5231 <
_temp5229.base? 1: _temp5231 >= _temp5229.last_plus_one)){ _throw(
Null_Exception);}* _temp5231;})); _temp5228;}); _temp5227;}),( void*)({ struct
Cyc_Absyn_RgnHandleType_struct* _temp5232=( struct Cyc_Absyn_RgnHandleType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_RgnHandleType_struct)); _temp5232[ 0]=({
struct Cyc_Absyn_RgnHandleType_struct _temp5233; _temp5233.tag= Cyc_Absyn_RgnHandleType;
_temp5233.f1=( void*) t; _temp5233;}); _temp5232;}), 0); _temp5226.f3= Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5234= yyvs; void** _temp5236= _temp5234.curr +
yyvsp_offset; if( _temp5234.base == 0? 1:( _temp5236 < _temp5234.base? 1:
_temp5236 >= _temp5234.last_plus_one)){ _throw( Null_Exception);}* _temp5236;}));
_temp5226;}); _temp5225;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp5237= yyls; struct Cyc_Yyltype* _temp5239= _temp5237.curr +( yylsp_offset -
2); if( _temp5237.base == 0? 1:( _temp5239 < _temp5237.base? 1: _temp5239 >=
_temp5237.last_plus_one)){ _throw( Null_Exception);}* _temp5239;}).first_line,({
struct _tagged_ptr3 _temp5240= yyls; struct Cyc_Yyltype* _temp5242= _temp5240.curr
+ yylsp_offset; if( _temp5240.base == 0? 1:( _temp5242 < _temp5240.base? 1:
_temp5242 >= _temp5240.last_plus_one)){ _throw( Null_Exception);}* _temp5242;}).last_line));
_temp5224;}); _temp5223;}); break;} case 218: _LL5209: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5252=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5252[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5253; _temp5253.tag= Cyc_Stmt_tok; _temp5253.f1= Cyc_Absyn_new_stmt(( void*)({
struct Cyc_Absyn_Cut_s_struct* _temp5254=( struct Cyc_Absyn_Cut_s_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Cut_s_struct)); _temp5254[ 0]=({ struct Cyc_Absyn_Cut_s_struct
_temp5255; _temp5255.tag= Cyc_Absyn_Cut_s; _temp5255.f1= Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5256= yyvs; void** _temp5258= _temp5256.curr +
yyvsp_offset; if( _temp5256.base == 0? 1:( _temp5258 < _temp5256.base? 1:
_temp5258 >= _temp5256.last_plus_one)){ _throw( Null_Exception);}* _temp5258;}));
_temp5255;}); _temp5254;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp5259= yyls; struct Cyc_Yyltype* _temp5261= _temp5259.curr +( yylsp_offset -
1); if( _temp5259.base == 0? 1:( _temp5261 < _temp5259.base? 1: _temp5261 >=
_temp5259.last_plus_one)){ _throw( Null_Exception);}* _temp5261;}).first_line,({
struct _tagged_ptr3 _temp5262= yyls; struct Cyc_Yyltype* _temp5264= _temp5262.curr
+ yylsp_offset; if( _temp5262.base == 0? 1:( _temp5264 < _temp5262.base? 1:
_temp5264 >= _temp5262.last_plus_one)){ _throw( Null_Exception);}* _temp5264;}).last_line));
_temp5253;}); _temp5252;}); break; case 219: _LL5251: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5266=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5266[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5267; _temp5267.tag= Cyc_Stmt_tok; _temp5267.f1= Cyc_Absyn_new_stmt(( void*)({
struct Cyc_Absyn_Splice_s_struct* _temp5268=( struct Cyc_Absyn_Splice_s_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Splice_s_struct)); _temp5268[ 0]=({ struct
Cyc_Absyn_Splice_s_struct _temp5269; _temp5269.tag= Cyc_Absyn_Splice_s;
_temp5269.f1= Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5270= yyvs; void**
_temp5272= _temp5270.curr + yyvsp_offset; if( _temp5270.base == 0? 1:( _temp5272
< _temp5270.base? 1: _temp5272 >= _temp5270.last_plus_one)){ _throw(
Null_Exception);}* _temp5272;})); _temp5269;}); _temp5268;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5273= yyls; struct Cyc_Yyltype* _temp5275= _temp5273.curr
+( yylsp_offset - 1); if( _temp5273.base == 0? 1:( _temp5275 < _temp5273.base? 1:
_temp5275 >= _temp5273.last_plus_one)){ _throw( Null_Exception);}* _temp5275;}).first_line,({
struct _tagged_ptr3 _temp5276= yyls; struct Cyc_Yyltype* _temp5278= _temp5276.curr
+ yylsp_offset; if( _temp5276.base == 0? 1:( _temp5278 < _temp5276.base? 1:
_temp5278 >= _temp5276.last_plus_one)){ _throw( Null_Exception);}* _temp5278;}).last_line));
_temp5267;}); _temp5266;}); break; case 220: _LL5265: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5280=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5280[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5281; _temp5281.tag= Cyc_Stmt_tok; _temp5281.f1= Cyc_Absyn_new_stmt(( void*)({
struct Cyc_Absyn_Label_s_struct* _temp5282=( struct Cyc_Absyn_Label_s_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Label_s_struct)); _temp5282[ 0]=({ struct
Cyc_Absyn_Label_s_struct _temp5283; _temp5283.tag= Cyc_Absyn_Label_s; _temp5283.f1=({
struct _tagged_string* _temp5284=( struct _tagged_string*) GC_malloc( sizeof(
struct _tagged_string) * 1); _temp5284[ 0]= Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp5285= yyvs; void** _temp5287= _temp5285.curr +( yyvsp_offset -
2); if( _temp5285.base == 0? 1:( _temp5287 < _temp5285.base? 1: _temp5287 >=
_temp5285.last_plus_one)){ _throw( Null_Exception);}* _temp5287;})); _temp5284;});
_temp5283.f2= Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5288= yyvs; void**
_temp5290= _temp5288.curr + yyvsp_offset; if( _temp5288.base == 0? 1:( _temp5290
< _temp5288.base? 1: _temp5290 >= _temp5288.last_plus_one)){ _throw(
Null_Exception);}* _temp5290;})); _temp5283;}); _temp5282;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5291= yyls; struct Cyc_Yyltype* _temp5293= _temp5291.curr
+( yylsp_offset - 2); if( _temp5291.base == 0? 1:( _temp5293 < _temp5291.base? 1:
_temp5293 >= _temp5291.last_plus_one)){ _throw( Null_Exception);}* _temp5293;}).first_line,({
struct _tagged_ptr3 _temp5294= yyls; struct Cyc_Yyltype* _temp5296= _temp5294.curr
+ yylsp_offset; if( _temp5294.base == 0? 1:( _temp5296 < _temp5294.base? 1:
_temp5296 >= _temp5294.last_plus_one)){ _throw( Null_Exception);}* _temp5296;}).last_line));
_temp5281;}); _temp5280;}); break; case 221: _LL5279: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5298=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5298[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5299; _temp5299.tag= Cyc_Stmt_tok; _temp5299.f1= Cyc_Absyn_skip_stmt( Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5300= yyls; struct Cyc_Yyltype* _temp5302= _temp5300.curr
+ yylsp_offset; if( _temp5300.base == 0? 1:( _temp5302 < _temp5300.base? 1:
_temp5302 >= _temp5300.last_plus_one)){ _throw( Null_Exception);}* _temp5302;}).first_line,({
struct _tagged_ptr3 _temp5303= yyls; struct Cyc_Yyltype* _temp5305= _temp5303.curr
+ yylsp_offset; if( _temp5303.base == 0? 1:( _temp5305 < _temp5303.base? 1:
_temp5305 >= _temp5303.last_plus_one)){ _throw( Null_Exception);}* _temp5305;}).last_line));
_temp5299;}); _temp5298;}); break; case 222: _LL5297: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5307=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5307[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5308; _temp5308.tag= Cyc_Stmt_tok; _temp5308.f1= Cyc_Absyn_exp_stmt( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5309= yyvs; void** _temp5311= _temp5309.curr +(
yyvsp_offset - 1); if( _temp5309.base == 0? 1:( _temp5311 < _temp5309.base? 1:
_temp5311 >= _temp5309.last_plus_one)){ _throw( Null_Exception);}* _temp5311;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5312= yyls; struct Cyc_Yyltype*
_temp5314= _temp5312.curr +( yylsp_offset - 1); if( _temp5312.base == 0? 1:(
_temp5314 < _temp5312.base? 1: _temp5314 >= _temp5312.last_plus_one)){ _throw(
Null_Exception);}* _temp5314;}).first_line,({ struct _tagged_ptr3 _temp5315=
yyls; struct Cyc_Yyltype* _temp5317= _temp5315.curr + yylsp_offset; if(
_temp5315.base == 0? 1:( _temp5317 < _temp5315.base? 1: _temp5317 >= _temp5315.last_plus_one)){
_throw( Null_Exception);}* _temp5317;}).last_line)); _temp5308;}); _temp5307;});
break; case 223: _LL5306: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5319=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5319[ 0]=({ struct Cyc_Stmt_tok_struct _temp5320; _temp5320.tag= Cyc_Stmt_tok;
_temp5320.f1= Cyc_Absyn_skip_stmt( Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5321= yyls; struct Cyc_Yyltype* _temp5323= _temp5321.curr +(
yylsp_offset - 1); if( _temp5321.base == 0? 1:( _temp5323 < _temp5321.base? 1:
_temp5323 >= _temp5321.last_plus_one)){ _throw( Null_Exception);}* _temp5323;}).first_line,({
struct _tagged_ptr3 _temp5324= yyls; struct Cyc_Yyltype* _temp5326= _temp5324.curr
+ yylsp_offset; if( _temp5324.base == 0? 1:( _temp5326 < _temp5324.base? 1:
_temp5326 >= _temp5324.last_plus_one)){ _throw( Null_Exception);}* _temp5326;}).last_line));
_temp5320;}); _temp5319;}); break; case 224: _LL5318: yyval=({ struct
_tagged_ptr2 _temp5328= yyvs; void** _temp5330= _temp5328.curr +( yyvsp_offset -
1); if( _temp5328.base == 0? 1:( _temp5330 < _temp5328.base? 1: _temp5330 >=
_temp5328.last_plus_one)){ _throw( Null_Exception);}* _temp5330;}); break; case
225: _LL5327:{ void* _temp5335= Cyc_yyget_BlockItem_tok(({ struct _tagged_ptr2
_temp5332= yyvs; void** _temp5334= _temp5332.curr + yyvsp_offset; if( _temp5332.base
== 0? 1:( _temp5334 < _temp5332.base? 1: _temp5334 >= _temp5332.last_plus_one)){
_throw( Null_Exception);}* _temp5334;})); struct Cyc_List_List* _temp5343;
struct Cyc_Absyn_Fndecl* _temp5345; struct Cyc_Absyn_Stmt* _temp5347; _LL5337:
if(*(( int*) _temp5335) == Cyc_Parse_TopDecls_bl){ _LL5344: _temp5343=( struct
Cyc_List_List*)(( struct Cyc_Parse_TopDecls_bl_struct*) _temp5335)->f1; goto
_LL5338;} else{ goto _LL5339;} _LL5339: if(*(( int*) _temp5335) == Cyc_Parse_FnDecl_bl){
_LL5346: _temp5345=( struct Cyc_Absyn_Fndecl*)(( struct Cyc_Parse_FnDecl_bl_struct*)
_temp5335)->f1; goto _LL5340;} else{ goto _LL5341;} _LL5341: if(*(( int*)
_temp5335) == Cyc_Parse_Stmt_bl){ _LL5348: _temp5347=( struct Cyc_Absyn_Stmt*)((
struct Cyc_Parse_Stmt_bl_struct*) _temp5335)->f1; goto _LL5342;} else{ goto
_LL5336;} _LL5338: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5349=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5349[ 0]=({ struct Cyc_Stmt_tok_struct _temp5350; _temp5350.tag= Cyc_Stmt_tok;
_temp5350.f1= Cyc_Parse_flatten_declarations( _temp5343, Cyc_Absyn_skip_stmt(
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5351= yyls; struct Cyc_Yyltype*
_temp5353= _temp5351.curr + yylsp_offset; if( _temp5351.base == 0? 1:( _temp5353
< _temp5351.base? 1: _temp5353 >= _temp5351.last_plus_one)){ _throw(
Null_Exception);}* _temp5353;}).first_line,({ struct _tagged_ptr3 _temp5354=
yyls; struct Cyc_Yyltype* _temp5356= _temp5354.curr + yylsp_offset; if(
_temp5354.base == 0? 1:( _temp5356 < _temp5354.base? 1: _temp5356 >= _temp5354.last_plus_one)){
_throw( Null_Exception);}* _temp5356;}).last_line))); _temp5350;}); _temp5349;});
goto _LL5336; _LL5340: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5357=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5357[ 0]=({ struct Cyc_Stmt_tok_struct _temp5358; _temp5358.tag= Cyc_Stmt_tok;
_temp5358.f1= Cyc_Parse_flatten_decl( Cyc_Absyn_new_decl(( void*)({ struct Cyc_Absyn_Fn_d_struct*
_temp5359=( struct Cyc_Absyn_Fn_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Fn_d_struct));
_temp5359[ 0]=({ struct Cyc_Absyn_Fn_d_struct _temp5360; _temp5360.tag= Cyc_Absyn_Fn_d;
_temp5360.f1= _temp5345; _temp5360;}); _temp5359;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5361= yyls; struct Cyc_Yyltype* _temp5363= _temp5361.curr
+ yylsp_offset; if( _temp5361.base == 0? 1:( _temp5363 < _temp5361.base? 1:
_temp5363 >= _temp5361.last_plus_one)){ _throw( Null_Exception);}* _temp5363;}).first_line,({
struct _tagged_ptr3 _temp5364= yyls; struct Cyc_Yyltype* _temp5366= _temp5364.curr
+ yylsp_offset; if( _temp5364.base == 0? 1:( _temp5366 < _temp5364.base? 1:
_temp5366 >= _temp5364.last_plus_one)){ _throw( Null_Exception);}* _temp5366;}).last_line)),
Cyc_Absyn_skip_stmt( Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp5367= yyls; struct Cyc_Yyltype* _temp5369= _temp5367.curr + yylsp_offset;
if( _temp5367.base == 0? 1:( _temp5369 < _temp5367.base? 1: _temp5369 >=
_temp5367.last_plus_one)){ _throw( Null_Exception);}* _temp5369;}).first_line,({
struct _tagged_ptr3 _temp5370= yyls; struct Cyc_Yyltype* _temp5372= _temp5370.curr
+ yylsp_offset; if( _temp5370.base == 0? 1:( _temp5372 < _temp5370.base? 1:
_temp5372 >= _temp5370.last_plus_one)){ _throw( Null_Exception);}* _temp5372;}).last_line)));
_temp5358;}); _temp5357;}); goto _LL5336; _LL5342: yyval=( void*)({ struct Cyc_Stmt_tok_struct*
_temp5373=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5373[ 0]=({ struct Cyc_Stmt_tok_struct _temp5374; _temp5374.tag= Cyc_Stmt_tok;
_temp5374.f1= _temp5347; _temp5374;}); _temp5373;}); goto _LL5336; _LL5336:;}
break; case 226: _LL5331:{ void* _temp5379= Cyc_yyget_BlockItem_tok(({ struct
_tagged_ptr2 _temp5376= yyvs; void** _temp5378= _temp5376.curr +( yyvsp_offset -
1); if( _temp5376.base == 0? 1:( _temp5378 < _temp5376.base? 1: _temp5378 >=
_temp5376.last_plus_one)){ _throw( Null_Exception);}* _temp5378;})); struct Cyc_List_List*
_temp5387; struct Cyc_Absyn_Fndecl* _temp5389; struct Cyc_Absyn_Stmt* _temp5391;
_LL5381: if(*(( int*) _temp5379) == Cyc_Parse_TopDecls_bl){ _LL5388: _temp5387=(
struct Cyc_List_List*)(( struct Cyc_Parse_TopDecls_bl_struct*) _temp5379)->f1;
goto _LL5382;} else{ goto _LL5383;} _LL5383: if(*(( int*) _temp5379) == Cyc_Parse_FnDecl_bl){
_LL5390: _temp5389=( struct Cyc_Absyn_Fndecl*)(( struct Cyc_Parse_FnDecl_bl_struct*)
_temp5379)->f1; goto _LL5384;} else{ goto _LL5385;} _LL5385: if(*(( int*)
_temp5379) == Cyc_Parse_Stmt_bl){ _LL5392: _temp5391=( struct Cyc_Absyn_Stmt*)((
struct Cyc_Parse_Stmt_bl_struct*) _temp5379)->f1; goto _LL5386;} else{ goto
_LL5380;} _LL5382: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5393=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5393[ 0]=({ struct Cyc_Stmt_tok_struct _temp5394; _temp5394.tag= Cyc_Stmt_tok;
_temp5394.f1= Cyc_Parse_flatten_declarations( _temp5387, Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5395= yyvs; void** _temp5397= _temp5395.curr +
yyvsp_offset; if( _temp5395.base == 0? 1:( _temp5397 < _temp5395.base? 1:
_temp5397 >= _temp5395.last_plus_one)){ _throw( Null_Exception);}* _temp5397;})));
_temp5394;}); _temp5393;}); goto _LL5380; _LL5384: yyval=( void*)({ struct Cyc_Stmt_tok_struct*
_temp5398=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5398[ 0]=({ struct Cyc_Stmt_tok_struct _temp5399; _temp5399.tag= Cyc_Stmt_tok;
_temp5399.f1= Cyc_Parse_flatten_decl( Cyc_Absyn_new_decl(( void*)({ struct Cyc_Absyn_Fn_d_struct*
_temp5400=( struct Cyc_Absyn_Fn_d_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Fn_d_struct));
_temp5400[ 0]=({ struct Cyc_Absyn_Fn_d_struct _temp5401; _temp5401.tag= Cyc_Absyn_Fn_d;
_temp5401.f1= _temp5389; _temp5401;}); _temp5400;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5402= yyls; struct Cyc_Yyltype* _temp5404= _temp5402.curr
+( yylsp_offset - 1); if( _temp5402.base == 0? 1:( _temp5404 < _temp5402.base? 1:
_temp5404 >= _temp5402.last_plus_one)){ _throw( Null_Exception);}* _temp5404;}).first_line,({
struct _tagged_ptr3 _temp5405= yyls; struct Cyc_Yyltype* _temp5407= _temp5405.curr
+( yylsp_offset - 1); if( _temp5405.base == 0? 1:( _temp5407 < _temp5405.base? 1:
_temp5407 >= _temp5405.last_plus_one)){ _throw( Null_Exception);}* _temp5407;}).last_line)),
Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5408= yyvs; void** _temp5410=
_temp5408.curr + yyvsp_offset; if( _temp5408.base == 0? 1:( _temp5410 <
_temp5408.base? 1: _temp5410 >= _temp5408.last_plus_one)){ _throw(
Null_Exception);}* _temp5410;}))); _temp5399;}); _temp5398;}); goto _LL5380;
_LL5386: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5411=( struct Cyc_Stmt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Stmt_tok_struct)); _temp5411[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5412; _temp5412.tag= Cyc_Stmt_tok; _temp5412.f1= Cyc_Absyn_seq_stmt(
_temp5391, Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5413= yyvs; void**
_temp5415= _temp5413.curr + yyvsp_offset; if( _temp5413.base == 0? 1:( _temp5415
< _temp5413.base? 1: _temp5415 >= _temp5413.last_plus_one)){ _throw(
Null_Exception);}* _temp5415;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5416= yyls; struct Cyc_Yyltype* _temp5418= _temp5416.curr +(
yylsp_offset - 1); if( _temp5416.base == 0? 1:( _temp5418 < _temp5416.base? 1:
_temp5418 >= _temp5416.last_plus_one)){ _throw( Null_Exception);}* _temp5418;}).first_line,({
struct _tagged_ptr3 _temp5419= yyls; struct Cyc_Yyltype* _temp5421= _temp5419.curr
+ yylsp_offset; if( _temp5419.base == 0? 1:( _temp5421 < _temp5419.base? 1:
_temp5421 >= _temp5419.last_plus_one)){ _throw( Null_Exception);}* _temp5421;}).last_line));
_temp5412;}); _temp5411;}); goto _LL5380; _LL5380:;} break; case 227: _LL5375:
yyval=( void*)({ struct Cyc_BlockItem_tok_struct* _temp5423=( struct Cyc_BlockItem_tok_struct*)
GC_malloc( sizeof( struct Cyc_BlockItem_tok_struct)); _temp5423[ 0]=({ struct
Cyc_BlockItem_tok_struct _temp5424; _temp5424.tag= Cyc_BlockItem_tok; _temp5424.f1=(
void*)(( void*)({ struct Cyc_Parse_TopDecls_bl_struct* _temp5425=( struct Cyc_Parse_TopDecls_bl_struct*)
GC_malloc( sizeof( struct Cyc_Parse_TopDecls_bl_struct)); _temp5425[ 0]=({
struct Cyc_Parse_TopDecls_bl_struct _temp5426; _temp5426.tag= Cyc_Parse_TopDecls_bl;
_temp5426.f1= Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp5427= yyvs;
void** _temp5429= _temp5427.curr + yyvsp_offset; if( _temp5427.base == 0? 1:(
_temp5429 < _temp5427.base? 1: _temp5429 >= _temp5427.last_plus_one)){ _throw(
Null_Exception);}* _temp5429;})); _temp5426;}); _temp5425;})); _temp5424;});
_temp5423;}); break; case 228: _LL5422: yyval=( void*)({ struct Cyc_BlockItem_tok_struct*
_temp5431=( struct Cyc_BlockItem_tok_struct*) GC_malloc( sizeof( struct Cyc_BlockItem_tok_struct));
_temp5431[ 0]=({ struct Cyc_BlockItem_tok_struct _temp5432; _temp5432.tag= Cyc_BlockItem_tok;
_temp5432.f1=( void*)(( void*)({ struct Cyc_Parse_Stmt_bl_struct* _temp5433=(
struct Cyc_Parse_Stmt_bl_struct*) GC_malloc( sizeof( struct Cyc_Parse_Stmt_bl_struct));
_temp5433[ 0]=({ struct Cyc_Parse_Stmt_bl_struct _temp5434; _temp5434.tag= Cyc_Parse_Stmt_bl;
_temp5434.f1= Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5435= yyvs; void**
_temp5437= _temp5435.curr + yyvsp_offset; if( _temp5435.base == 0? 1:( _temp5437
< _temp5435.base? 1: _temp5437 >= _temp5435.last_plus_one)){ _throw(
Null_Exception);}* _temp5437;})); _temp5434;}); _temp5433;})); _temp5432;});
_temp5431;}); break; case 229: _LL5430: yyval=( void*)({ struct Cyc_BlockItem_tok_struct*
_temp5439=( struct Cyc_BlockItem_tok_struct*) GC_malloc( sizeof( struct Cyc_BlockItem_tok_struct));
_temp5439[ 0]=({ struct Cyc_BlockItem_tok_struct _temp5440; _temp5440.tag= Cyc_BlockItem_tok;
_temp5440.f1=( void*)(( void*)({ struct Cyc_Parse_FnDecl_bl_struct* _temp5441=(
struct Cyc_Parse_FnDecl_bl_struct*) GC_malloc( sizeof( struct Cyc_Parse_FnDecl_bl_struct));
_temp5441[ 0]=({ struct Cyc_Parse_FnDecl_bl_struct _temp5442; _temp5442.tag= Cyc_Parse_FnDecl_bl;
_temp5442.f1= Cyc_yyget_FnDecl_tok(({ struct _tagged_ptr2 _temp5443= yyvs; void**
_temp5445= _temp5443.curr + yyvsp_offset; if( _temp5443.base == 0? 1:( _temp5445
< _temp5443.base? 1: _temp5445 >= _temp5443.last_plus_one)){ _throw(
Null_Exception);}* _temp5445;})); _temp5442;}); _temp5441;})); _temp5440;});
_temp5439;}); break; case 230: _LL5438: yyval=( void*)({ struct Cyc_Stmt_tok_struct*
_temp5447=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5447[ 0]=({ struct Cyc_Stmt_tok_struct _temp5448; _temp5448.tag= Cyc_Stmt_tok;
_temp5448.f1= Cyc_Absyn_ifthenelse_stmt( Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp5449= yyvs; void** _temp5451= _temp5449.curr +( yyvsp_offset -
2); if( _temp5449.base == 0? 1:( _temp5451 < _temp5449.base? 1: _temp5451 >=
_temp5449.last_plus_one)){ _throw( Null_Exception);}* _temp5451;})), Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5452= yyvs; void** _temp5454= _temp5452.curr +
yyvsp_offset; if( _temp5452.base == 0? 1:( _temp5454 < _temp5452.base? 1:
_temp5454 >= _temp5452.last_plus_one)){ _throw( Null_Exception);}* _temp5454;})),
Cyc_Absyn_skip_stmt( 0), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp5455= yyls; struct Cyc_Yyltype* _temp5457= _temp5455.curr +( yylsp_offset -
4); if( _temp5455.base == 0? 1:( _temp5457 < _temp5455.base? 1: _temp5457 >=
_temp5455.last_plus_one)){ _throw( Null_Exception);}* _temp5457;}).first_line,({
struct _tagged_ptr3 _temp5458= yyls; struct Cyc_Yyltype* _temp5460= _temp5458.curr
+ yylsp_offset; if( _temp5458.base == 0? 1:( _temp5460 < _temp5458.base? 1:
_temp5460 >= _temp5458.last_plus_one)){ _throw( Null_Exception);}* _temp5460;}).last_line));
_temp5448;}); _temp5447;}); break; case 231: _LL5446: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5462=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5462[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5463; _temp5463.tag= Cyc_Stmt_tok; _temp5463.f1= Cyc_Absyn_ifthenelse_stmt(
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5464= yyvs; void** _temp5466=
_temp5464.curr +( yyvsp_offset - 4); if( _temp5464.base == 0? 1:( _temp5466 <
_temp5464.base? 1: _temp5466 >= _temp5464.last_plus_one)){ _throw(
Null_Exception);}* _temp5466;})), Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2
_temp5467= yyvs; void** _temp5469= _temp5467.curr +( yyvsp_offset - 2); if(
_temp5467.base == 0? 1:( _temp5469 < _temp5467.base? 1: _temp5469 >= _temp5467.last_plus_one)){
_throw( Null_Exception);}* _temp5469;})), Cyc_yyget_Stmt_tok(({ struct
_tagged_ptr2 _temp5470= yyvs; void** _temp5472= _temp5470.curr + yyvsp_offset;
if( _temp5470.base == 0? 1:( _temp5472 < _temp5470.base? 1: _temp5472 >=
_temp5470.last_plus_one)){ _throw( Null_Exception);}* _temp5472;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5473= yyls; struct Cyc_Yyltype* _temp5475= _temp5473.curr
+( yylsp_offset - 6); if( _temp5473.base == 0? 1:( _temp5475 < _temp5473.base? 1:
_temp5475 >= _temp5473.last_plus_one)){ _throw( Null_Exception);}* _temp5475;}).first_line,({
struct _tagged_ptr3 _temp5476= yyls; struct Cyc_Yyltype* _temp5478= _temp5476.curr
+ yylsp_offset; if( _temp5476.base == 0? 1:( _temp5478 < _temp5476.base? 1:
_temp5478 >= _temp5476.last_plus_one)){ _throw( Null_Exception);}* _temp5478;}).last_line));
_temp5463;}); _temp5462;}); break; case 232: _LL5461: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5480=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5480[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5481; _temp5481.tag= Cyc_Stmt_tok; _temp5481.f1= Cyc_Absyn_switch_stmt( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5482= yyvs; void** _temp5484= _temp5482.curr +(
yyvsp_offset - 4); if( _temp5482.base == 0? 1:( _temp5484 < _temp5482.base? 1:
_temp5484 >= _temp5482.last_plus_one)){ _throw( Null_Exception);}* _temp5484;})),
Cyc_yyget_SwitchClauseList_tok(({ struct _tagged_ptr2 _temp5485= yyvs; void**
_temp5487= _temp5485.curr +( yyvsp_offset - 1); if( _temp5485.base == 0? 1:(
_temp5487 < _temp5485.base? 1: _temp5487 >= _temp5485.last_plus_one)){ _throw(
Null_Exception);}* _temp5487;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5488= yyls; struct Cyc_Yyltype* _temp5490= _temp5488.curr +(
yylsp_offset - 6); if( _temp5488.base == 0? 1:( _temp5490 < _temp5488.base? 1:
_temp5490 >= _temp5488.last_plus_one)){ _throw( Null_Exception);}* _temp5490;}).first_line,({
struct _tagged_ptr3 _temp5491= yyls; struct Cyc_Yyltype* _temp5493= _temp5491.curr
+ yylsp_offset; if( _temp5491.base == 0? 1:( _temp5493 < _temp5491.base? 1:
_temp5493 >= _temp5491.last_plus_one)){ _throw( Null_Exception);}* _temp5493;}).last_line));
_temp5481;}); _temp5480;}); break; case 233: _LL5479: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5495=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5495[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5496; _temp5496.tag= Cyc_Stmt_tok; _temp5496.f1= Cyc_Absyn_trycatch_stmt(
Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5497= yyvs; void** _temp5499=
_temp5497.curr +( yyvsp_offset - 4); if( _temp5497.base == 0? 1:( _temp5499 <
_temp5497.base? 1: _temp5499 >= _temp5497.last_plus_one)){ _throw(
Null_Exception);}* _temp5499;})), Cyc_yyget_SwitchClauseList_tok(({ struct
_tagged_ptr2 _temp5500= yyvs; void** _temp5502= _temp5500.curr +( yyvsp_offset -
1); if( _temp5500.base == 0? 1:( _temp5502 < _temp5500.base? 1: _temp5502 >=
_temp5500.last_plus_one)){ _throw( Null_Exception);}* _temp5502;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5503= yyls; struct Cyc_Yyltype* _temp5505= _temp5503.curr
+( yylsp_offset - 5); if( _temp5503.base == 0? 1:( _temp5505 < _temp5503.base? 1:
_temp5505 >= _temp5503.last_plus_one)){ _throw( Null_Exception);}* _temp5505;}).first_line,({
struct _tagged_ptr3 _temp5506= yyls; struct Cyc_Yyltype* _temp5508= _temp5506.curr
+ yylsp_offset; if( _temp5506.base == 0? 1:( _temp5508 < _temp5506.base? 1:
_temp5508 >= _temp5506.last_plus_one)){ _throw( Null_Exception);}* _temp5508;}).last_line));
_temp5496;}); _temp5495;}); break; case 234: _LL5494: yyval=( void*)({ struct
Cyc_SwitchClauseList_tok_struct* _temp5510=( struct Cyc_SwitchClauseList_tok_struct*)
GC_malloc( sizeof( struct Cyc_SwitchClauseList_tok_struct)); _temp5510[ 0]=({
struct Cyc_SwitchClauseList_tok_struct _temp5511; _temp5511.tag= Cyc_SwitchClauseList_tok;
_temp5511.f1= 0; _temp5511;}); _temp5510;}); break; case 235: _LL5509: yyval=(
void*)({ struct Cyc_SwitchClauseList_tok_struct* _temp5513=( struct Cyc_SwitchClauseList_tok_struct*)
GC_malloc( sizeof( struct Cyc_SwitchClauseList_tok_struct)); _temp5513[ 0]=({
struct Cyc_SwitchClauseList_tok_struct _temp5514; _temp5514.tag= Cyc_SwitchClauseList_tok;
_temp5514.f1=({ struct Cyc_List_List* _temp5515=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5515->hd=( void*)({ struct Cyc_Absyn_Switch_clause*
_temp5516=( struct Cyc_Absyn_Switch_clause*) GC_malloc( sizeof( struct Cyc_Absyn_Switch_clause));
_temp5516->pattern= Cyc_Absyn_new_pat(( void*) Cyc_Absyn_Wild_p, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5526= yyls; struct Cyc_Yyltype* _temp5528= _temp5526.curr
+( yylsp_offset - 2); if( _temp5526.base == 0? 1:( _temp5528 < _temp5526.base? 1:
_temp5528 >= _temp5526.last_plus_one)){ _throw( Null_Exception);}* _temp5528;}).first_line,({
struct _tagged_ptr3 _temp5529= yyls; struct Cyc_Yyltype* _temp5531= _temp5529.curr
+( yylsp_offset - 2); if( _temp5529.base == 0? 1:( _temp5531 < _temp5529.base? 1:
_temp5531 >= _temp5529.last_plus_one)){ _throw( Null_Exception);}* _temp5531;}).last_line));
_temp5516->pat_vars= 0; _temp5516->where_clause= 0; _temp5516->body= Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5523= yyvs; void** _temp5525= _temp5523.curr +
yyvsp_offset; if( _temp5523.base == 0? 1:( _temp5525 < _temp5523.base? 1:
_temp5525 >= _temp5523.last_plus_one)){ _throw( Null_Exception);}* _temp5525;}));
_temp5516->loc= Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5517=
yyls; struct Cyc_Yyltype* _temp5519= _temp5517.curr +( yylsp_offset - 2); if(
_temp5517.base == 0? 1:( _temp5519 < _temp5517.base? 1: _temp5519 >= _temp5517.last_plus_one)){
_throw( Null_Exception);}* _temp5519;}).first_line,({ struct _tagged_ptr3
_temp5520= yyls; struct Cyc_Yyltype* _temp5522= _temp5520.curr + yylsp_offset;
if( _temp5520.base == 0? 1:( _temp5522 < _temp5520.base? 1: _temp5522 >=
_temp5520.last_plus_one)){ _throw( Null_Exception);}* _temp5522;}).last_line);
_temp5516;}); _temp5515->tl= 0; _temp5515;}); _temp5514;}); _temp5513;}); break;
case 236: _LL5512: yyval=( void*)({ struct Cyc_SwitchClauseList_tok_struct*
_temp5533=( struct Cyc_SwitchClauseList_tok_struct*) GC_malloc( sizeof( struct
Cyc_SwitchClauseList_tok_struct)); _temp5533[ 0]=({ struct Cyc_SwitchClauseList_tok_struct
_temp5534; _temp5534.tag= Cyc_SwitchClauseList_tok; _temp5534.f1=({ struct Cyc_List_List*
_temp5535=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp5535->hd=( void*)({ struct Cyc_Absyn_Switch_clause* _temp5539=( struct Cyc_Absyn_Switch_clause*)
GC_malloc( sizeof( struct Cyc_Absyn_Switch_clause)); _temp5539->pattern= Cyc_yyget_Pattern_tok(({
struct _tagged_ptr2 _temp5552= yyvs; void** _temp5554= _temp5552.curr +(
yyvsp_offset - 2); if( _temp5552.base == 0? 1:( _temp5554 < _temp5552.base? 1:
_temp5554 >= _temp5552.last_plus_one)){ _throw( Null_Exception);}* _temp5554;}));
_temp5539->pat_vars= 0; _temp5539->where_clause= 0; _temp5539->body= Cyc_Absyn_skip_stmt(
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5546= yyls; struct Cyc_Yyltype*
_temp5548= _temp5546.curr +( yylsp_offset - 1); if( _temp5546.base == 0? 1:(
_temp5548 < _temp5546.base? 1: _temp5548 >= _temp5546.last_plus_one)){ _throw(
Null_Exception);}* _temp5548;}).first_line,({ struct _tagged_ptr3 _temp5549=
yyls; struct Cyc_Yyltype* _temp5551= _temp5549.curr +( yylsp_offset - 1); if(
_temp5549.base == 0? 1:( _temp5551 < _temp5549.base? 1: _temp5551 >= _temp5549.last_plus_one)){
_throw( Null_Exception);}* _temp5551;}).last_line)); _temp5539->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5540= yyls; struct Cyc_Yyltype* _temp5542= _temp5540.curr
+( yylsp_offset - 3); if( _temp5540.base == 0? 1:( _temp5542 < _temp5540.base? 1:
_temp5542 >= _temp5540.last_plus_one)){ _throw( Null_Exception);}* _temp5542;}).first_line,({
struct _tagged_ptr3 _temp5543= yyls; struct Cyc_Yyltype* _temp5545= _temp5543.curr
+ yylsp_offset; if( _temp5543.base == 0? 1:( _temp5545 < _temp5543.base? 1:
_temp5545 >= _temp5543.last_plus_one)){ _throw( Null_Exception);}* _temp5545;}).last_line);
_temp5539;}); _temp5535->tl= Cyc_yyget_SwitchClauseList_tok(({ struct
_tagged_ptr2 _temp5536= yyvs; void** _temp5538= _temp5536.curr + yyvsp_offset;
if( _temp5536.base == 0? 1:( _temp5538 < _temp5536.base? 1: _temp5538 >=
_temp5536.last_plus_one)){ _throw( Null_Exception);}* _temp5538;})); _temp5535;});
_temp5534;}); _temp5533;}); break; case 237: _LL5532: yyval=( void*)({ struct
Cyc_SwitchClauseList_tok_struct* _temp5556=( struct Cyc_SwitchClauseList_tok_struct*)
GC_malloc( sizeof( struct Cyc_SwitchClauseList_tok_struct)); _temp5556[ 0]=({
struct Cyc_SwitchClauseList_tok_struct _temp5557; _temp5557.tag= Cyc_SwitchClauseList_tok;
_temp5557.f1=({ struct Cyc_List_List* _temp5558=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5558->hd=( void*)({ struct Cyc_Absyn_Switch_clause*
_temp5562=( struct Cyc_Absyn_Switch_clause*) GC_malloc( sizeof( struct Cyc_Absyn_Switch_clause));
_temp5562->pattern= Cyc_yyget_Pattern_tok(({ struct _tagged_ptr2 _temp5572= yyvs;
void** _temp5574= _temp5572.curr +( yyvsp_offset - 3); if( _temp5572.base == 0?
1:( _temp5574 < _temp5572.base? 1: _temp5574 >= _temp5572.last_plus_one)){
_throw( Null_Exception);}* _temp5574;})); _temp5562->pat_vars= 0; _temp5562->where_clause=
0; _temp5562->body= Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5569= yyvs;
void** _temp5571= _temp5569.curr +( yyvsp_offset - 1); if( _temp5569.base == 0?
1:( _temp5571 < _temp5569.base? 1: _temp5571 >= _temp5569.last_plus_one)){
_throw( Null_Exception);}* _temp5571;})); _temp5562->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5563= yyls; struct Cyc_Yyltype* _temp5565= _temp5563.curr
+( yylsp_offset - 4); if( _temp5563.base == 0? 1:( _temp5565 < _temp5563.base? 1:
_temp5565 >= _temp5563.last_plus_one)){ _throw( Null_Exception);}* _temp5565;}).first_line,({
struct _tagged_ptr3 _temp5566= yyls; struct Cyc_Yyltype* _temp5568= _temp5566.curr
+( yylsp_offset - 1); if( _temp5566.base == 0? 1:( _temp5568 < _temp5566.base? 1:
_temp5568 >= _temp5566.last_plus_one)){ _throw( Null_Exception);}* _temp5568;}).last_line);
_temp5562;}); _temp5558->tl= Cyc_yyget_SwitchClauseList_tok(({ struct
_tagged_ptr2 _temp5559= yyvs; void** _temp5561= _temp5559.curr + yyvsp_offset;
if( _temp5559.base == 0? 1:( _temp5561 < _temp5559.base? 1: _temp5561 >=
_temp5559.last_plus_one)){ _throw( Null_Exception);}* _temp5561;})); _temp5558;});
_temp5557;}); _temp5556;}); break; case 238: _LL5555: yyval=( void*)({ struct
Cyc_SwitchClauseList_tok_struct* _temp5576=( struct Cyc_SwitchClauseList_tok_struct*)
GC_malloc( sizeof( struct Cyc_SwitchClauseList_tok_struct)); _temp5576[ 0]=({
struct Cyc_SwitchClauseList_tok_struct _temp5577; _temp5577.tag= Cyc_SwitchClauseList_tok;
_temp5577.f1=({ struct Cyc_List_List* _temp5578=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5578->hd=( void*)({ struct Cyc_Absyn_Switch_clause*
_temp5582=( struct Cyc_Absyn_Switch_clause*) GC_malloc( sizeof( struct Cyc_Absyn_Switch_clause));
_temp5582->pattern= Cyc_yyget_Pattern_tok(({ struct _tagged_ptr2 _temp5598= yyvs;
void** _temp5600= _temp5598.curr +( yyvsp_offset - 4); if( _temp5598.base == 0?
1:( _temp5600 < _temp5598.base? 1: _temp5600 >= _temp5598.last_plus_one)){
_throw( Null_Exception);}* _temp5600;})); _temp5582->pat_vars= 0; _temp5582->where_clause=(
struct Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5595= yyvs;
void** _temp5597= _temp5595.curr +( yyvsp_offset - 2); if( _temp5595.base == 0?
1:( _temp5597 < _temp5595.base? 1: _temp5597 >= _temp5595.last_plus_one)){
_throw( Null_Exception);}* _temp5597;})); _temp5582->body= Cyc_Absyn_skip_stmt(
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5589= yyls; struct Cyc_Yyltype*
_temp5591= _temp5589.curr +( yylsp_offset - 1); if( _temp5589.base == 0? 1:(
_temp5591 < _temp5589.base? 1: _temp5591 >= _temp5589.last_plus_one)){ _throw(
Null_Exception);}* _temp5591;}).first_line,({ struct _tagged_ptr3 _temp5592=
yyls; struct Cyc_Yyltype* _temp5594= _temp5592.curr +( yylsp_offset - 1); if(
_temp5592.base == 0? 1:( _temp5594 < _temp5592.base? 1: _temp5594 >= _temp5592.last_plus_one)){
_throw( Null_Exception);}* _temp5594;}).last_line)); _temp5582->loc= Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5583= yyls; struct Cyc_Yyltype* _temp5585= _temp5583.curr
+( yylsp_offset - 5); if( _temp5583.base == 0? 1:( _temp5585 < _temp5583.base? 1:
_temp5585 >= _temp5583.last_plus_one)){ _throw( Null_Exception);}* _temp5585;}).first_line,({
struct _tagged_ptr3 _temp5586= yyls; struct Cyc_Yyltype* _temp5588= _temp5586.curr
+ yylsp_offset; if( _temp5586.base == 0? 1:( _temp5588 < _temp5586.base? 1:
_temp5588 >= _temp5586.last_plus_one)){ _throw( Null_Exception);}* _temp5588;}).last_line);
_temp5582;}); _temp5578->tl= Cyc_yyget_SwitchClauseList_tok(({ struct
_tagged_ptr2 _temp5579= yyvs; void** _temp5581= _temp5579.curr + yyvsp_offset;
if( _temp5579.base == 0? 1:( _temp5581 < _temp5579.base? 1: _temp5581 >=
_temp5579.last_plus_one)){ _throw( Null_Exception);}* _temp5581;})); _temp5578;});
_temp5577;}); _temp5576;}); break; case 239: _LL5575: yyval=( void*)({ struct
Cyc_SwitchClauseList_tok_struct* _temp5602=( struct Cyc_SwitchClauseList_tok_struct*)
GC_malloc( sizeof( struct Cyc_SwitchClauseList_tok_struct)); _temp5602[ 0]=({
struct Cyc_SwitchClauseList_tok_struct _temp5603; _temp5603.tag= Cyc_SwitchClauseList_tok;
_temp5603.f1=({ struct Cyc_List_List* _temp5604=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp5604->hd=( void*)({ struct Cyc_Absyn_Switch_clause*
_temp5608=( struct Cyc_Absyn_Switch_clause*) GC_malloc( sizeof( struct Cyc_Absyn_Switch_clause));
_temp5608->pattern= Cyc_yyget_Pattern_tok(({ struct _tagged_ptr2 _temp5621= yyvs;
void** _temp5623= _temp5621.curr +( yyvsp_offset - 5); if( _temp5621.base == 0?
1:( _temp5623 < _temp5621.base? 1: _temp5623 >= _temp5621.last_plus_one)){
_throw( Null_Exception);}* _temp5623;})); _temp5608->pat_vars= 0; _temp5608->where_clause=(
struct Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5618= yyvs;
void** _temp5620= _temp5618.curr +( yyvsp_offset - 3); if( _temp5618.base == 0?
1:( _temp5620 < _temp5618.base? 1: _temp5620 >= _temp5618.last_plus_one)){
_throw( Null_Exception);}* _temp5620;})); _temp5608->body= Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5615= yyvs; void** _temp5617= _temp5615.curr +(
yyvsp_offset - 1); if( _temp5615.base == 0? 1:( _temp5617 < _temp5615.base? 1:
_temp5617 >= _temp5615.last_plus_one)){ _throw( Null_Exception);}* _temp5617;}));
_temp5608->loc= Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5609=
yyls; struct Cyc_Yyltype* _temp5611= _temp5609.curr +( yylsp_offset - 6); if(
_temp5609.base == 0? 1:( _temp5611 < _temp5609.base? 1: _temp5611 >= _temp5609.last_plus_one)){
_throw( Null_Exception);}* _temp5611;}).first_line,({ struct _tagged_ptr3
_temp5612= yyls; struct Cyc_Yyltype* _temp5614= _temp5612.curr + yylsp_offset;
if( _temp5612.base == 0? 1:( _temp5614 < _temp5612.base? 1: _temp5614 >=
_temp5612.last_plus_one)){ _throw( Null_Exception);}* _temp5614;}).last_line);
_temp5608;}); _temp5604->tl= Cyc_yyget_SwitchClauseList_tok(({ struct
_tagged_ptr2 _temp5605= yyvs; void** _temp5607= _temp5605.curr + yyvsp_offset;
if( _temp5605.base == 0? 1:( _temp5607 < _temp5605.base? 1: _temp5607 >=
_temp5605.last_plus_one)){ _throw( Null_Exception);}* _temp5607;})); _temp5604;});
_temp5603;}); _temp5602;}); break; case 240: _LL5601: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5625=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5625[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5626; _temp5626.tag= Cyc_Stmt_tok; _temp5626.f1= Cyc_Absyn_while_stmt( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5627= yyvs; void** _temp5629= _temp5627.curr +(
yyvsp_offset - 2); if( _temp5627.base == 0? 1:( _temp5629 < _temp5627.base? 1:
_temp5629 >= _temp5627.last_plus_one)){ _throw( Null_Exception);}* _temp5629;})),
Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5630= yyvs; void** _temp5632=
_temp5630.curr + yyvsp_offset; if( _temp5630.base == 0? 1:( _temp5632 <
_temp5630.base? 1: _temp5632 >= _temp5630.last_plus_one)){ _throw(
Null_Exception);}* _temp5632;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5633= yyls; struct Cyc_Yyltype* _temp5635= _temp5633.curr +(
yylsp_offset - 4); if( _temp5633.base == 0? 1:( _temp5635 < _temp5633.base? 1:
_temp5635 >= _temp5633.last_plus_one)){ _throw( Null_Exception);}* _temp5635;}).first_line,({
struct _tagged_ptr3 _temp5636= yyls; struct Cyc_Yyltype* _temp5638= _temp5636.curr
+ yylsp_offset; if( _temp5636.base == 0? 1:( _temp5638 < _temp5636.base? 1:
_temp5638 >= _temp5636.last_plus_one)){ _throw( Null_Exception);}* _temp5638;}).last_line));
_temp5626;}); _temp5625;}); break; case 241: _LL5624: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5640=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5640[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5641; _temp5641.tag= Cyc_Stmt_tok; _temp5641.f1= Cyc_Absyn_do_stmt( Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5642= yyvs; void** _temp5644= _temp5642.curr +(
yyvsp_offset - 5); if( _temp5642.base == 0? 1:( _temp5644 < _temp5642.base? 1:
_temp5644 >= _temp5642.last_plus_one)){ _throw( Null_Exception);}* _temp5644;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5645= yyvs; void** _temp5647=
_temp5645.curr +( yyvsp_offset - 2); if( _temp5645.base == 0? 1:( _temp5647 <
_temp5645.base? 1: _temp5647 >= _temp5645.last_plus_one)){ _throw(
Null_Exception);}* _temp5647;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5648= yyls; struct Cyc_Yyltype* _temp5650= _temp5648.curr +(
yylsp_offset - 6); if( _temp5648.base == 0? 1:( _temp5650 < _temp5648.base? 1:
_temp5650 >= _temp5648.last_plus_one)){ _throw( Null_Exception);}* _temp5650;}).first_line,({
struct _tagged_ptr3 _temp5651= yyls; struct Cyc_Yyltype* _temp5653= _temp5651.curr
+ yylsp_offset; if( _temp5651.base == 0? 1:( _temp5653 < _temp5651.base? 1:
_temp5653 >= _temp5651.last_plus_one)){ _throw( Null_Exception);}* _temp5653;}).last_line));
_temp5641;}); _temp5640;}); break; case 242: _LL5639: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5655=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5655[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5656; _temp5656.tag= Cyc_Stmt_tok; _temp5656.f1= Cyc_Absyn_for_stmt( Cyc_Absyn_false_exp(
0), Cyc_Absyn_true_exp( 0), Cyc_Absyn_false_exp( 0), Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5657= yyvs; void** _temp5659= _temp5657.curr +
yyvsp_offset; if( _temp5657.base == 0? 1:( _temp5659 < _temp5657.base? 1:
_temp5659 >= _temp5657.last_plus_one)){ _throw( Null_Exception);}* _temp5659;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5660= yyls; struct Cyc_Yyltype*
_temp5662= _temp5660.curr +( yylsp_offset - 5); if( _temp5660.base == 0? 1:(
_temp5662 < _temp5660.base? 1: _temp5662 >= _temp5660.last_plus_one)){ _throw(
Null_Exception);}* _temp5662;}).first_line,({ struct _tagged_ptr3 _temp5663=
yyls; struct Cyc_Yyltype* _temp5665= _temp5663.curr + yylsp_offset; if(
_temp5663.base == 0? 1:( _temp5665 < _temp5663.base? 1: _temp5665 >= _temp5663.last_plus_one)){
_throw( Null_Exception);}* _temp5665;}).last_line)); _temp5656;}); _temp5655;});
break; case 243: _LL5654: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5667=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5667[ 0]=({ struct Cyc_Stmt_tok_struct _temp5668; _temp5668.tag= Cyc_Stmt_tok;
_temp5668.f1= Cyc_Absyn_for_stmt( Cyc_Absyn_false_exp( 0), Cyc_Absyn_true_exp( 0),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5669= yyvs; void** _temp5671=
_temp5669.curr +( yyvsp_offset - 2); if( _temp5669.base == 0? 1:( _temp5671 <
_temp5669.base? 1: _temp5671 >= _temp5669.last_plus_one)){ _throw(
Null_Exception);}* _temp5671;})), Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2
_temp5672= yyvs; void** _temp5674= _temp5672.curr + yyvsp_offset; if( _temp5672.base
== 0? 1:( _temp5674 < _temp5672.base? 1: _temp5674 >= _temp5672.last_plus_one)){
_throw( Null_Exception);}* _temp5674;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5675= yyls; struct Cyc_Yyltype* _temp5677= _temp5675.curr +(
yylsp_offset - 6); if( _temp5675.base == 0? 1:( _temp5677 < _temp5675.base? 1:
_temp5677 >= _temp5675.last_plus_one)){ _throw( Null_Exception);}* _temp5677;}).first_line,({
struct _tagged_ptr3 _temp5678= yyls; struct Cyc_Yyltype* _temp5680= _temp5678.curr
+ yylsp_offset; if( _temp5678.base == 0? 1:( _temp5680 < _temp5678.base? 1:
_temp5680 >= _temp5678.last_plus_one)){ _throw( Null_Exception);}* _temp5680;}).last_line));
_temp5668;}); _temp5667;}); break; case 244: _LL5666: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5682=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5682[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5683; _temp5683.tag= Cyc_Stmt_tok; _temp5683.f1= Cyc_Absyn_for_stmt( Cyc_Absyn_false_exp(
0), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5684= yyvs; void** _temp5686=
_temp5684.curr +( yyvsp_offset - 3); if( _temp5684.base == 0? 1:( _temp5686 <
_temp5684.base? 1: _temp5686 >= _temp5684.last_plus_one)){ _throw(
Null_Exception);}* _temp5686;})), Cyc_Absyn_false_exp( 0), Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5687= yyvs; void** _temp5689= _temp5687.curr +
yyvsp_offset; if( _temp5687.base == 0? 1:( _temp5689 < _temp5687.base? 1:
_temp5689 >= _temp5687.last_plus_one)){ _throw( Null_Exception);}* _temp5689;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5690= yyls; struct Cyc_Yyltype*
_temp5692= _temp5690.curr +( yylsp_offset - 6); if( _temp5690.base == 0? 1:(
_temp5692 < _temp5690.base? 1: _temp5692 >= _temp5690.last_plus_one)){ _throw(
Null_Exception);}* _temp5692;}).first_line,({ struct _tagged_ptr3 _temp5693=
yyls; struct Cyc_Yyltype* _temp5695= _temp5693.curr + yylsp_offset; if(
_temp5693.base == 0? 1:( _temp5695 < _temp5693.base? 1: _temp5695 >= _temp5693.last_plus_one)){
_throw( Null_Exception);}* _temp5695;}).last_line)); _temp5683;}); _temp5682;});
break; case 245: _LL5681: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5697=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5697[ 0]=({ struct Cyc_Stmt_tok_struct _temp5698; _temp5698.tag= Cyc_Stmt_tok;
_temp5698.f1= Cyc_Absyn_for_stmt( Cyc_Absyn_false_exp( 0), Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5699= yyvs; void** _temp5701= _temp5699.curr +(
yyvsp_offset - 4); if( _temp5699.base == 0? 1:( _temp5701 < _temp5699.base? 1:
_temp5701 >= _temp5699.last_plus_one)){ _throw( Null_Exception);}* _temp5701;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5702= yyvs; void** _temp5704=
_temp5702.curr +( yyvsp_offset - 2); if( _temp5702.base == 0? 1:( _temp5704 <
_temp5702.base? 1: _temp5704 >= _temp5702.last_plus_one)){ _throw(
Null_Exception);}* _temp5704;})), Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2
_temp5705= yyvs; void** _temp5707= _temp5705.curr + yyvsp_offset; if( _temp5705.base
== 0? 1:( _temp5707 < _temp5705.base? 1: _temp5707 >= _temp5705.last_plus_one)){
_throw( Null_Exception);}* _temp5707;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5708= yyls; struct Cyc_Yyltype* _temp5710= _temp5708.curr +(
yylsp_offset - 7); if( _temp5708.base == 0? 1:( _temp5710 < _temp5708.base? 1:
_temp5710 >= _temp5708.last_plus_one)){ _throw( Null_Exception);}* _temp5710;}).first_line,({
struct _tagged_ptr3 _temp5711= yyls; struct Cyc_Yyltype* _temp5713= _temp5711.curr
+( yylsp_offset - 1); if( _temp5711.base == 0? 1:( _temp5713 < _temp5711.base? 1:
_temp5713 >= _temp5711.last_plus_one)){ _throw( Null_Exception);}* _temp5713;}).last_line));
_temp5698;}); _temp5697;}); break; case 246: _LL5696: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5715=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5715[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5716; _temp5716.tag= Cyc_Stmt_tok; _temp5716.f1= Cyc_Absyn_for_stmt( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5717= yyvs; void** _temp5719= _temp5717.curr +(
yyvsp_offset - 4); if( _temp5717.base == 0? 1:( _temp5719 < _temp5717.base? 1:
_temp5719 >= _temp5717.last_plus_one)){ _throw( Null_Exception);}* _temp5719;})),
Cyc_Absyn_true_exp( 0), Cyc_Absyn_false_exp( 0), Cyc_yyget_Stmt_tok(({ struct
_tagged_ptr2 _temp5720= yyvs; void** _temp5722= _temp5720.curr + yyvsp_offset;
if( _temp5720.base == 0? 1:( _temp5722 < _temp5720.base? 1: _temp5722 >=
_temp5720.last_plus_one)){ _throw( Null_Exception);}* _temp5722;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5723= yyls; struct Cyc_Yyltype* _temp5725= _temp5723.curr
+( yylsp_offset - 6); if( _temp5723.base == 0? 1:( _temp5725 < _temp5723.base? 1:
_temp5725 >= _temp5723.last_plus_one)){ _throw( Null_Exception);}* _temp5725;}).first_line,({
struct _tagged_ptr3 _temp5726= yyls; struct Cyc_Yyltype* _temp5728= _temp5726.curr
+ yylsp_offset; if( _temp5726.base == 0? 1:( _temp5728 < _temp5726.base? 1:
_temp5728 >= _temp5726.last_plus_one)){ _throw( Null_Exception);}* _temp5728;}).last_line));
_temp5716;}); _temp5715;}); break; case 247: _LL5714: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5730=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5730[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5731; _temp5731.tag= Cyc_Stmt_tok; _temp5731.f1= Cyc_Absyn_for_stmt( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5732= yyvs; void** _temp5734= _temp5732.curr +(
yyvsp_offset - 5); if( _temp5732.base == 0? 1:( _temp5734 < _temp5732.base? 1:
_temp5734 >= _temp5732.last_plus_one)){ _throw( Null_Exception);}* _temp5734;})),
Cyc_Absyn_true_exp( 0), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5735= yyvs;
void** _temp5737= _temp5735.curr +( yyvsp_offset - 2); if( _temp5735.base == 0?
1:( _temp5737 < _temp5735.base? 1: _temp5737 >= _temp5735.last_plus_one)){
_throw( Null_Exception);}* _temp5737;})), Cyc_yyget_Stmt_tok(({ struct
_tagged_ptr2 _temp5738= yyvs; void** _temp5740= _temp5738.curr + yyvsp_offset;
if( _temp5738.base == 0? 1:( _temp5740 < _temp5738.base? 1: _temp5740 >=
_temp5738.last_plus_one)){ _throw( Null_Exception);}* _temp5740;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5741= yyls; struct Cyc_Yyltype* _temp5743= _temp5741.curr
+( yylsp_offset - 7); if( _temp5741.base == 0? 1:( _temp5743 < _temp5741.base? 1:
_temp5743 >= _temp5741.last_plus_one)){ _throw( Null_Exception);}* _temp5743;}).first_line,({
struct _tagged_ptr3 _temp5744= yyls; struct Cyc_Yyltype* _temp5746= _temp5744.curr
+ yylsp_offset; if( _temp5744.base == 0? 1:( _temp5746 < _temp5744.base? 1:
_temp5746 >= _temp5744.last_plus_one)){ _throw( Null_Exception);}* _temp5746;}).last_line));
_temp5731;}); _temp5730;}); break; case 248: _LL5729: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5748=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5748[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5749; _temp5749.tag= Cyc_Stmt_tok; _temp5749.f1= Cyc_Absyn_for_stmt( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5750= yyvs; void** _temp5752= _temp5750.curr +(
yyvsp_offset - 5); if( _temp5750.base == 0? 1:( _temp5752 < _temp5750.base? 1:
_temp5752 >= _temp5750.last_plus_one)){ _throw( Null_Exception);}* _temp5752;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5753= yyvs; void** _temp5755=
_temp5753.curr +( yyvsp_offset - 3); if( _temp5753.base == 0? 1:( _temp5755 <
_temp5753.base? 1: _temp5755 >= _temp5753.last_plus_one)){ _throw(
Null_Exception);}* _temp5755;})), Cyc_Absyn_false_exp( 0), Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5756= yyvs; void** _temp5758= _temp5756.curr +
yyvsp_offset; if( _temp5756.base == 0? 1:( _temp5758 < _temp5756.base? 1:
_temp5758 >= _temp5756.last_plus_one)){ _throw( Null_Exception);}* _temp5758;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5759= yyls; struct Cyc_Yyltype*
_temp5761= _temp5759.curr +( yylsp_offset - 7); if( _temp5759.base == 0? 1:(
_temp5761 < _temp5759.base? 1: _temp5761 >= _temp5759.last_plus_one)){ _throw(
Null_Exception);}* _temp5761;}).first_line,({ struct _tagged_ptr3 _temp5762=
yyls; struct Cyc_Yyltype* _temp5764= _temp5762.curr + yylsp_offset; if(
_temp5762.base == 0? 1:( _temp5764 < _temp5762.base? 1: _temp5764 >= _temp5762.last_plus_one)){
_throw( Null_Exception);}* _temp5764;}).last_line)); _temp5749;}); _temp5748;});
break; case 249: _LL5747: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5766=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5766[ 0]=({ struct Cyc_Stmt_tok_struct _temp5767; _temp5767.tag= Cyc_Stmt_tok;
_temp5767.f1= Cyc_Absyn_for_stmt( Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp5768= yyvs; void** _temp5770= _temp5768.curr +( yyvsp_offset - 6); if(
_temp5768.base == 0? 1:( _temp5770 < _temp5768.base? 1: _temp5770 >= _temp5768.last_plus_one)){
_throw( Null_Exception);}* _temp5770;})), Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp5771= yyvs; void** _temp5773= _temp5771.curr +( yyvsp_offset -
4); if( _temp5771.base == 0? 1:( _temp5773 < _temp5771.base? 1: _temp5773 >=
_temp5771.last_plus_one)){ _throw( Null_Exception);}* _temp5773;})), Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5774= yyvs; void** _temp5776= _temp5774.curr +(
yyvsp_offset - 2); if( _temp5774.base == 0? 1:( _temp5776 < _temp5774.base? 1:
_temp5776 >= _temp5774.last_plus_one)){ _throw( Null_Exception);}* _temp5776;})),
Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5777= yyvs; void** _temp5779=
_temp5777.curr + yyvsp_offset; if( _temp5777.base == 0? 1:( _temp5779 <
_temp5777.base? 1: _temp5779 >= _temp5777.last_plus_one)){ _throw(
Null_Exception);}* _temp5779;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5780= yyls; struct Cyc_Yyltype* _temp5782= _temp5780.curr +(
yylsp_offset - 8); if( _temp5780.base == 0? 1:( _temp5782 < _temp5780.base? 1:
_temp5782 >= _temp5780.last_plus_one)){ _throw( Null_Exception);}* _temp5782;}).first_line,({
struct _tagged_ptr3 _temp5783= yyls; struct Cyc_Yyltype* _temp5785= _temp5783.curr
+ yylsp_offset; if( _temp5783.base == 0? 1:( _temp5785 < _temp5783.base? 1:
_temp5785 >= _temp5783.last_plus_one)){ _throw( Null_Exception);}* _temp5785;}).last_line));
_temp5767;}); _temp5766;}); break; case 250: _LL5765: { struct Cyc_List_List*
decls= Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp5798= yyvs; void**
_temp5800= _temp5798.curr +( yyvsp_offset - 3); if( _temp5798.base == 0? 1:(
_temp5800 < _temp5798.base? 1: _temp5800 >= _temp5798.last_plus_one)){ _throw(
Null_Exception);}* _temp5800;})); struct Cyc_Absyn_Stmt* s= Cyc_Absyn_for_stmt(
Cyc_Absyn_false_exp( 0), Cyc_Absyn_true_exp( 0), Cyc_Absyn_false_exp( 0), Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5789= yyvs; void** _temp5791= _temp5789.curr +
yyvsp_offset; if( _temp5789.base == 0? 1:( _temp5791 < _temp5789.base? 1:
_temp5791 >= _temp5789.last_plus_one)){ _throw( Null_Exception);}* _temp5791;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5792= yyls; struct Cyc_Yyltype*
_temp5794= _temp5792.curr +( yylsp_offset - 5); if( _temp5792.base == 0? 1:(
_temp5794 < _temp5792.base? 1: _temp5794 >= _temp5792.last_plus_one)){ _throw(
Null_Exception);}* _temp5794;}).first_line,({ struct _tagged_ptr3 _temp5795=
yyls; struct Cyc_Yyltype* _temp5797= _temp5795.curr + yylsp_offset; if(
_temp5795.base == 0? 1:( _temp5797 < _temp5795.base? 1: _temp5797 >= _temp5795.last_plus_one)){
_throw( Null_Exception);}* _temp5797;}).last_line)); yyval=( void*)({ struct Cyc_Stmt_tok_struct*
_temp5787=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5787[ 0]=({ struct Cyc_Stmt_tok_struct _temp5788; _temp5788.tag= Cyc_Stmt_tok;
_temp5788.f1= Cyc_Parse_flatten_declarations( decls, s); _temp5788;}); _temp5787;});
break;} case 251: _LL5786: { struct Cyc_List_List* decls= Cyc_yyget_DeclList_tok(({
struct _tagged_ptr2 _temp5816= yyvs; void** _temp5818= _temp5816.curr +(
yyvsp_offset - 4); if( _temp5816.base == 0? 1:( _temp5818 < _temp5816.base? 1:
_temp5818 >= _temp5816.last_plus_one)){ _throw( Null_Exception);}* _temp5818;}));
struct Cyc_Absyn_Stmt* s= Cyc_Absyn_for_stmt( Cyc_Absyn_false_exp( 0), Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5804= yyvs; void** _temp5806= _temp5804.curr +(
yyvsp_offset - 3); if( _temp5804.base == 0? 1:( _temp5806 < _temp5804.base? 1:
_temp5806 >= _temp5804.last_plus_one)){ _throw( Null_Exception);}* _temp5806;})),
Cyc_Absyn_false_exp( 0), Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2 _temp5807=
yyvs; void** _temp5809= _temp5807.curr + yyvsp_offset; if( _temp5807.base == 0?
1:( _temp5809 < _temp5807.base? 1: _temp5809 >= _temp5807.last_plus_one)){
_throw( Null_Exception);}* _temp5809;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5810= yyls; struct Cyc_Yyltype* _temp5812= _temp5810.curr +(
yylsp_offset - 6); if( _temp5810.base == 0? 1:( _temp5812 < _temp5810.base? 1:
_temp5812 >= _temp5810.last_plus_one)){ _throw( Null_Exception);}* _temp5812;}).first_line,({
struct _tagged_ptr3 _temp5813= yyls; struct Cyc_Yyltype* _temp5815= _temp5813.curr
+ yylsp_offset; if( _temp5813.base == 0? 1:( _temp5815 < _temp5813.base? 1:
_temp5815 >= _temp5813.last_plus_one)){ _throw( Null_Exception);}* _temp5815;}).last_line));
yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5802=( struct Cyc_Stmt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Stmt_tok_struct)); _temp5802[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5803; _temp5803.tag= Cyc_Stmt_tok; _temp5803.f1= Cyc_Parse_flatten_declarations(
decls, s); _temp5803;}); _temp5802;}); break;} case 252: _LL5801: { struct Cyc_List_List*
decls= Cyc_yyget_DeclList_tok(({ struct _tagged_ptr2 _temp5834= yyvs; void**
_temp5836= _temp5834.curr +( yyvsp_offset - 4); if( _temp5834.base == 0? 1:(
_temp5836 < _temp5834.base? 1: _temp5836 >= _temp5834.last_plus_one)){ _throw(
Null_Exception);}* _temp5836;})); struct Cyc_Absyn_Stmt* s= Cyc_Absyn_for_stmt(
Cyc_Absyn_false_exp( 0), Cyc_Absyn_true_exp( 0), Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp5822= yyvs; void** _temp5824= _temp5822.curr +( yyvsp_offset -
2); if( _temp5822.base == 0? 1:( _temp5824 < _temp5822.base? 1: _temp5824 >=
_temp5822.last_plus_one)){ _throw( Null_Exception);}* _temp5824;})), Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp5825= yyvs; void** _temp5827= _temp5825.curr +
yyvsp_offset; if( _temp5825.base == 0? 1:( _temp5827 < _temp5825.base? 1:
_temp5827 >= _temp5825.last_plus_one)){ _throw( Null_Exception);}* _temp5827;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5828= yyls; struct Cyc_Yyltype*
_temp5830= _temp5828.curr +( yylsp_offset - 6); if( _temp5828.base == 0? 1:(
_temp5830 < _temp5828.base? 1: _temp5830 >= _temp5828.last_plus_one)){ _throw(
Null_Exception);}* _temp5830;}).first_line,({ struct _tagged_ptr3 _temp5831=
yyls; struct Cyc_Yyltype* _temp5833= _temp5831.curr + yylsp_offset; if(
_temp5831.base == 0? 1:( _temp5833 < _temp5831.base? 1: _temp5833 >= _temp5831.last_plus_one)){
_throw( Null_Exception);}* _temp5833;}).last_line)); yyval=( void*)({ struct Cyc_Stmt_tok_struct*
_temp5820=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5820[ 0]=({ struct Cyc_Stmt_tok_struct _temp5821; _temp5821.tag= Cyc_Stmt_tok;
_temp5821.f1= Cyc_Parse_flatten_declarations( decls, s); _temp5821;}); _temp5820;});
break;} case 253: _LL5819: { struct Cyc_List_List* decls= Cyc_yyget_DeclList_tok(({
struct _tagged_ptr2 _temp5855= yyvs; void** _temp5857= _temp5855.curr +(
yyvsp_offset - 5); if( _temp5855.base == 0? 1:( _temp5857 < _temp5855.base? 1:
_temp5857 >= _temp5855.last_plus_one)){ _throw( Null_Exception);}* _temp5857;}));
struct Cyc_Absyn_Stmt* s= Cyc_Absyn_for_stmt( Cyc_Absyn_false_exp( 0), Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5840= yyvs; void** _temp5842= _temp5840.curr +(
yyvsp_offset - 4); if( _temp5840.base == 0? 1:( _temp5842 < _temp5840.base? 1:
_temp5842 >= _temp5840.last_plus_one)){ _throw( Null_Exception);}* _temp5842;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp5843= yyvs; void** _temp5845=
_temp5843.curr +( yyvsp_offset - 2); if( _temp5843.base == 0? 1:( _temp5845 <
_temp5843.base? 1: _temp5845 >= _temp5843.last_plus_one)){ _throw(
Null_Exception);}* _temp5845;})), Cyc_yyget_Stmt_tok(({ struct _tagged_ptr2
_temp5846= yyvs; void** _temp5848= _temp5846.curr + yyvsp_offset; if( _temp5846.base
== 0? 1:( _temp5848 < _temp5846.base? 1: _temp5848 >= _temp5846.last_plus_one)){
_throw( Null_Exception);}* _temp5848;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5849= yyls; struct Cyc_Yyltype* _temp5851= _temp5849.curr +(
yylsp_offset - 7); if( _temp5849.base == 0? 1:( _temp5851 < _temp5849.base? 1:
_temp5851 >= _temp5849.last_plus_one)){ _throw( Null_Exception);}* _temp5851;}).first_line,({
struct _tagged_ptr3 _temp5852= yyls; struct Cyc_Yyltype* _temp5854= _temp5852.curr
+ yylsp_offset; if( _temp5852.base == 0? 1:( _temp5854 < _temp5852.base? 1:
_temp5854 >= _temp5852.last_plus_one)){ _throw( Null_Exception);}* _temp5854;}).last_line));
yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5838=( struct Cyc_Stmt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Stmt_tok_struct)); _temp5838[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5839; _temp5839.tag= Cyc_Stmt_tok; _temp5839.f1= Cyc_Parse_flatten_declarations(
decls, s); _temp5839;}); _temp5838;}); break;} case 254: _LL5837: yyval=( void*)({
struct Cyc_Stmt_tok_struct* _temp5859=( struct Cyc_Stmt_tok_struct*) GC_malloc(
sizeof( struct Cyc_Stmt_tok_struct)); _temp5859[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5860; _temp5860.tag= Cyc_Stmt_tok; _temp5860.f1= Cyc_Absyn_goto_stmt(({
struct _tagged_string* _temp5861=( struct _tagged_string*) GC_malloc( sizeof(
struct _tagged_string) * 1); _temp5861[ 0]= Cyc_yyget_String_tok(({ struct
_tagged_ptr2 _temp5862= yyvs; void** _temp5864= _temp5862.curr +( yyvsp_offset -
1); if( _temp5862.base == 0? 1:( _temp5864 < _temp5862.base? 1: _temp5864 >=
_temp5862.last_plus_one)){ _throw( Null_Exception);}* _temp5864;})); _temp5861;}),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5865= yyls; struct Cyc_Yyltype*
_temp5867= _temp5865.curr +( yylsp_offset - 2); if( _temp5865.base == 0? 1:(
_temp5867 < _temp5865.base? 1: _temp5867 >= _temp5865.last_plus_one)){ _throw(
Null_Exception);}* _temp5867;}).first_line,({ struct _tagged_ptr3 _temp5868=
yyls; struct Cyc_Yyltype* _temp5870= _temp5868.curr +( yylsp_offset - 1); if(
_temp5868.base == 0? 1:( _temp5870 < _temp5868.base? 1: _temp5870 >= _temp5868.last_plus_one)){
_throw( Null_Exception);}* _temp5870;}).last_line)); _temp5860;}); _temp5859;});
break; case 255: _LL5858: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5872=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5872[ 0]=({ struct Cyc_Stmt_tok_struct _temp5873; _temp5873.tag= Cyc_Stmt_tok;
_temp5873.f1= Cyc_Absyn_continue_stmt( Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5874= yyls; struct Cyc_Yyltype* _temp5876= _temp5874.curr +(
yylsp_offset - 1); if( _temp5874.base == 0? 1:( _temp5876 < _temp5874.base? 1:
_temp5876 >= _temp5874.last_plus_one)){ _throw( Null_Exception);}* _temp5876;}).first_line,({
struct _tagged_ptr3 _temp5877= yyls; struct Cyc_Yyltype* _temp5879= _temp5877.curr
+( yylsp_offset - 1); if( _temp5877.base == 0? 1:( _temp5879 < _temp5877.base? 1:
_temp5879 >= _temp5877.last_plus_one)){ _throw( Null_Exception);}* _temp5879;}).last_line));
_temp5873;}); _temp5872;}); break; case 256: _LL5871: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5881=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5881[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5882; _temp5882.tag= Cyc_Stmt_tok; _temp5882.f1= Cyc_Absyn_break_stmt( Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5883= yyls; struct Cyc_Yyltype* _temp5885= _temp5883.curr
+( yylsp_offset - 1); if( _temp5883.base == 0? 1:( _temp5885 < _temp5883.base? 1:
_temp5885 >= _temp5883.last_plus_one)){ _throw( Null_Exception);}* _temp5885;}).first_line,({
struct _tagged_ptr3 _temp5886= yyls; struct Cyc_Yyltype* _temp5888= _temp5886.curr
+( yylsp_offset - 1); if( _temp5886.base == 0? 1:( _temp5888 < _temp5886.base? 1:
_temp5888 >= _temp5886.last_plus_one)){ _throw( Null_Exception);}* _temp5888;}).last_line));
_temp5882;}); _temp5881;}); break; case 257: _LL5880: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5890=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5890[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5891; _temp5891.tag= Cyc_Stmt_tok; _temp5891.f1= Cyc_Absyn_return_stmt( 0,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5892= yyls; struct Cyc_Yyltype*
_temp5894= _temp5892.curr +( yylsp_offset - 1); if( _temp5892.base == 0? 1:(
_temp5894 < _temp5892.base? 1: _temp5894 >= _temp5892.last_plus_one)){ _throw(
Null_Exception);}* _temp5894;}).first_line,({ struct _tagged_ptr3 _temp5895=
yyls; struct Cyc_Yyltype* _temp5897= _temp5895.curr +( yylsp_offset - 1); if(
_temp5895.base == 0? 1:( _temp5897 < _temp5895.base? 1: _temp5897 >= _temp5895.last_plus_one)){
_throw( Null_Exception);}* _temp5897;}).last_line)); _temp5891;}); _temp5890;});
break; case 258: _LL5889: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5899=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5899[ 0]=({ struct Cyc_Stmt_tok_struct _temp5900; _temp5900.tag= Cyc_Stmt_tok;
_temp5900.f1= Cyc_Absyn_return_stmt(( struct Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp5901= yyvs; void** _temp5903= _temp5901.curr +(
yyvsp_offset - 1); if( _temp5901.base == 0? 1:( _temp5903 < _temp5901.base? 1:
_temp5903 >= _temp5901.last_plus_one)){ _throw( Null_Exception);}* _temp5903;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5904= yyls; struct Cyc_Yyltype*
_temp5906= _temp5904.curr +( yylsp_offset - 2); if( _temp5904.base == 0? 1:(
_temp5906 < _temp5904.base? 1: _temp5906 >= _temp5904.last_plus_one)){ _throw(
Null_Exception);}* _temp5906;}).first_line,({ struct _tagged_ptr3 _temp5907=
yyls; struct Cyc_Yyltype* _temp5909= _temp5907.curr +( yylsp_offset - 1); if(
_temp5907.base == 0? 1:( _temp5909 < _temp5907.base? 1: _temp5909 >= _temp5907.last_plus_one)){
_throw( Null_Exception);}* _temp5909;}).last_line)); _temp5900;}); _temp5899;});
break; case 259: _LL5898: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5911=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5911[ 0]=({ struct Cyc_Stmt_tok_struct _temp5912; _temp5912.tag= Cyc_Stmt_tok;
_temp5912.f1= Cyc_Absyn_fallthru_stmt( 0, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp5913= yyls; struct Cyc_Yyltype* _temp5915= _temp5913.curr +(
yylsp_offset - 1); if( _temp5913.base == 0? 1:( _temp5915 < _temp5913.base? 1:
_temp5915 >= _temp5913.last_plus_one)){ _throw( Null_Exception);}* _temp5915;}).first_line,({
struct _tagged_ptr3 _temp5916= yyls; struct Cyc_Yyltype* _temp5918= _temp5916.curr
+( yylsp_offset - 1); if( _temp5916.base == 0? 1:( _temp5918 < _temp5916.base? 1:
_temp5918 >= _temp5916.last_plus_one)){ _throw( Null_Exception);}* _temp5918;}).last_line));
_temp5912;}); _temp5911;}); break; case 260: _LL5910: yyval=( void*)({ struct
Cyc_Stmt_tok_struct* _temp5920=( struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof(
struct Cyc_Stmt_tok_struct)); _temp5920[ 0]=({ struct Cyc_Stmt_tok_struct
_temp5921; _temp5921.tag= Cyc_Stmt_tok; _temp5921.f1= Cyc_Absyn_fallthru_stmt( 0,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp5922= yyls; struct Cyc_Yyltype*
_temp5924= _temp5922.curr +( yylsp_offset - 3); if( _temp5922.base == 0? 1:(
_temp5924 < _temp5922.base? 1: _temp5924 >= _temp5922.last_plus_one)){ _throw(
Null_Exception);}* _temp5924;}).first_line,({ struct _tagged_ptr3 _temp5925=
yyls; struct Cyc_Yyltype* _temp5927= _temp5925.curr +( yylsp_offset - 3); if(
_temp5925.base == 0? 1:( _temp5927 < _temp5925.base? 1: _temp5927 >= _temp5925.last_plus_one)){
_throw( Null_Exception);}* _temp5927;}).last_line)); _temp5921;}); _temp5920;});
break; case 261: _LL5919: yyval=( void*)({ struct Cyc_Stmt_tok_struct* _temp5929=(
struct Cyc_Stmt_tok_struct*) GC_malloc( sizeof( struct Cyc_Stmt_tok_struct));
_temp5929[ 0]=({ struct Cyc_Stmt_tok_struct _temp5930; _temp5930.tag= Cyc_Stmt_tok;
_temp5930.f1= Cyc_Absyn_fallthru_stmt( Cyc_yyget_ExpList_tok(({ struct
_tagged_ptr2 _temp5931= yyvs; void** _temp5933= _temp5931.curr +( yyvsp_offset -
2); if( _temp5931.base == 0? 1:( _temp5933 < _temp5931.base? 1: _temp5933 >=
_temp5931.last_plus_one)){ _throw( Null_Exception);}* _temp5933;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5934= yyls; struct Cyc_Yyltype* _temp5936= _temp5934.curr
+( yylsp_offset - 4); if( _temp5934.base == 0? 1:( _temp5936 < _temp5934.base? 1:
_temp5936 >= _temp5934.last_plus_one)){ _throw( Null_Exception);}* _temp5936;}).first_line,({
struct _tagged_ptr3 _temp5937= yyls; struct Cyc_Yyltype* _temp5939= _temp5937.curr
+( yylsp_offset - 4); if( _temp5937.base == 0? 1:( _temp5939 < _temp5937.base? 1:
_temp5939 >= _temp5937.last_plus_one)){ _throw( Null_Exception);}* _temp5939;}).last_line));
_temp5930;}); _temp5929;}); break; case 262: _LL5928: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp5941=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp5941[ 0]=({ struct Cyc_Pattern_tok_struct
_temp5942; _temp5942.tag= Cyc_Pattern_tok; _temp5942.f1= Cyc_Absyn_new_pat((
void*) Cyc_Absyn_Wild_p, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp5943= yyls; struct Cyc_Yyltype* _temp5945= _temp5943.curr + yylsp_offset;
if( _temp5943.base == 0? 1:( _temp5945 < _temp5943.base? 1: _temp5945 >=
_temp5943.last_plus_one)){ _throw( Null_Exception);}* _temp5945;}).first_line,({
struct _tagged_ptr3 _temp5946= yyls; struct Cyc_Yyltype* _temp5948= _temp5946.curr
+ yylsp_offset; if( _temp5946.base == 0? 1:( _temp5948 < _temp5946.base? 1:
_temp5948 >= _temp5946.last_plus_one)){ _throw( Null_Exception);}* _temp5948;}).last_line));
_temp5942;}); _temp5941;}); break; case 263: _LL5940: yyval=({ struct
_tagged_ptr2 _temp5950= yyvs; void** _temp5952= _temp5950.curr +( yyvsp_offset -
1); if( _temp5950.base == 0? 1:( _temp5952 < _temp5950.base? 1: _temp5952 >=
_temp5950.last_plus_one)){ _throw( Null_Exception);}* _temp5952;}); break; case
264: _LL5949: yyval=( void*)({ struct Cyc_Pattern_tok_struct* _temp5954=( struct
Cyc_Pattern_tok_struct*) GC_malloc( sizeof( struct Cyc_Pattern_tok_struct));
_temp5954[ 0]=({ struct Cyc_Pattern_tok_struct _temp5955; _temp5955.tag= Cyc_Pattern_tok;
_temp5955.f1= Cyc_Absyn_new_pat(( void*)({ struct Cyc_Absyn_Int_p_struct*
_temp5956=( struct Cyc_Absyn_Int_p_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Int_p_struct));
_temp5956[ 0]=({ struct Cyc_Absyn_Int_p_struct _temp5957; _temp5957.tag= Cyc_Absyn_Int_p;
_temp5957.f1=( void*)(* Cyc_yyget_Int_tok(({ struct _tagged_ptr2 _temp5958= yyvs;
void** _temp5960= _temp5958.curr + yyvsp_offset; if( _temp5958.base == 0? 1:(
_temp5960 < _temp5958.base? 1: _temp5960 >= _temp5958.last_plus_one)){ _throw(
Null_Exception);}* _temp5960;}))).f1; _temp5957.f2=(* Cyc_yyget_Int_tok(({
struct _tagged_ptr2 _temp5961= yyvs; void** _temp5963= _temp5961.curr +
yyvsp_offset; if( _temp5961.base == 0? 1:( _temp5963 < _temp5961.base? 1:
_temp5963 >= _temp5961.last_plus_one)){ _throw( Null_Exception);}* _temp5963;}))).f2;
_temp5957;}); _temp5956;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp5964= yyls; struct Cyc_Yyltype* _temp5966= _temp5964.curr + yylsp_offset;
if( _temp5964.base == 0? 1:( _temp5966 < _temp5964.base? 1: _temp5966 >=
_temp5964.last_plus_one)){ _throw( Null_Exception);}* _temp5966;}).first_line,({
struct _tagged_ptr3 _temp5967= yyls; struct Cyc_Yyltype* _temp5969= _temp5967.curr
+ yylsp_offset; if( _temp5967.base == 0? 1:( _temp5969 < _temp5967.base? 1:
_temp5969 >= _temp5967.last_plus_one)){ _throw( Null_Exception);}* _temp5969;}).last_line));
_temp5955;}); _temp5954;}); break; case 265: _LL5953: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp5971=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp5971[ 0]=({ struct Cyc_Pattern_tok_struct
_temp5972; _temp5972.tag= Cyc_Pattern_tok; _temp5972.f1= Cyc_Absyn_new_pat((
void*)({ struct Cyc_Absyn_Int_p_struct* _temp5973=( struct Cyc_Absyn_Int_p_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Int_p_struct)); _temp5973[ 0]=({ struct Cyc_Absyn_Int_p_struct
_temp5974; _temp5974.tag= Cyc_Absyn_Int_p; _temp5974.f1=( void*)(( void*) Cyc_Absyn_Signed);
_temp5974.f2= -(* Cyc_yyget_Int_tok(({ struct _tagged_ptr2 _temp5975= yyvs; void**
_temp5977= _temp5975.curr + yyvsp_offset; if( _temp5975.base == 0? 1:( _temp5977
< _temp5975.base? 1: _temp5977 >= _temp5975.last_plus_one)){ _throw(
Null_Exception);}* _temp5977;}))).f2; _temp5974;}); _temp5973;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5978= yyls; struct Cyc_Yyltype* _temp5980= _temp5978.curr
+( yylsp_offset - 1); if( _temp5978.base == 0? 1:( _temp5980 < _temp5978.base? 1:
_temp5980 >= _temp5978.last_plus_one)){ _throw( Null_Exception);}* _temp5980;}).first_line,({
struct _tagged_ptr3 _temp5981= yyls; struct Cyc_Yyltype* _temp5983= _temp5981.curr
+ yylsp_offset; if( _temp5981.base == 0? 1:( _temp5983 < _temp5981.base? 1:
_temp5983 >= _temp5981.last_plus_one)){ _throw( Null_Exception);}* _temp5983;}).last_line));
_temp5972;}); _temp5971;}); break; case 266: _LL5970: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp5985=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp5985[ 0]=({ struct Cyc_Pattern_tok_struct
_temp5986; _temp5986.tag= Cyc_Pattern_tok; _temp5986.f1= Cyc_Absyn_new_pat((
void*)({ struct Cyc_Absyn_Float_p_struct* _temp5987=( struct Cyc_Absyn_Float_p_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Float_p_struct)); _temp5987[ 0]=({ struct
Cyc_Absyn_Float_p_struct _temp5988; _temp5988.tag= Cyc_Absyn_Float_p; _temp5988.f1=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp5989= yyvs; void** _temp5991=
_temp5989.curr + yyvsp_offset; if( _temp5989.base == 0? 1:( _temp5991 <
_temp5989.base? 1: _temp5991 >= _temp5989.last_plus_one)){ _throw(
Null_Exception);}* _temp5991;})); _temp5988;}); _temp5987;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp5992= yyls; struct Cyc_Yyltype* _temp5994= _temp5992.curr
+ yylsp_offset; if( _temp5992.base == 0? 1:( _temp5994 < _temp5992.base? 1:
_temp5994 >= _temp5992.last_plus_one)){ _throw( Null_Exception);}* _temp5994;}).first_line,({
struct _tagged_ptr3 _temp5995= yyls; struct Cyc_Yyltype* _temp5997= _temp5995.curr
+ yylsp_offset; if( _temp5995.base == 0? 1:( _temp5997 < _temp5995.base? 1:
_temp5997 >= _temp5995.last_plus_one)){ _throw( Null_Exception);}* _temp5997;}).last_line));
_temp5986;}); _temp5985;}); break; case 267: _LL5984: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp5999=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp5999[ 0]=({ struct Cyc_Pattern_tok_struct
_temp6000; _temp6000.tag= Cyc_Pattern_tok; _temp6000.f1= Cyc_Absyn_new_pat((
void*)({ struct Cyc_Absyn_Char_p_struct* _temp6001=( struct Cyc_Absyn_Char_p_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Char_p_struct)); _temp6001[ 0]=({ struct Cyc_Absyn_Char_p_struct
_temp6002; _temp6002.tag= Cyc_Absyn_Char_p; _temp6002.f1= Cyc_yyget_Char_tok(({
struct _tagged_ptr2 _temp6003= yyvs; void** _temp6005= _temp6003.curr +
yyvsp_offset; if( _temp6003.base == 0? 1:( _temp6005 < _temp6003.base? 1:
_temp6005 >= _temp6003.last_plus_one)){ _throw( Null_Exception);}* _temp6005;}));
_temp6002;}); _temp6001;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp6006= yyls; struct Cyc_Yyltype* _temp6008= _temp6006.curr + yylsp_offset;
if( _temp6006.base == 0? 1:( _temp6008 < _temp6006.base? 1: _temp6008 >=
_temp6006.last_plus_one)){ _throw( Null_Exception);}* _temp6008;}).first_line,({
struct _tagged_ptr3 _temp6009= yyls; struct Cyc_Yyltype* _temp6011= _temp6009.curr
+ yylsp_offset; if( _temp6009.base == 0? 1:( _temp6011 < _temp6009.base? 1:
_temp6011 >= _temp6009.last_plus_one)){ _throw( Null_Exception);}* _temp6011;}).last_line));
_temp6000;}); _temp5999;}); break; case 268: _LL5998: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp6013=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp6013[ 0]=({ struct Cyc_Pattern_tok_struct
_temp6014; _temp6014.tag= Cyc_Pattern_tok; _temp6014.f1= Cyc_Absyn_new_pat((
void*) Cyc_Absyn_Null_p, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp6015= yyls; struct Cyc_Yyltype* _temp6017= _temp6015.curr + yylsp_offset;
if( _temp6015.base == 0? 1:( _temp6017 < _temp6015.base? 1: _temp6017 >=
_temp6015.last_plus_one)){ _throw( Null_Exception);}* _temp6017;}).first_line,({
struct _tagged_ptr3 _temp6018= yyls; struct Cyc_Yyltype* _temp6020= _temp6018.curr
+ yylsp_offset; if( _temp6018.base == 0? 1:( _temp6020 < _temp6018.base? 1:
_temp6020 >= _temp6018.last_plus_one)){ _throw( Null_Exception);}* _temp6020;}).last_line));
_temp6014;}); _temp6013;}); break; case 269: _LL6012: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp6022=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp6022[ 0]=({ struct Cyc_Pattern_tok_struct
_temp6023; _temp6023.tag= Cyc_Pattern_tok; _temp6023.f1= Cyc_Absyn_new_pat((
void*)({ struct Cyc_Absyn_UnknownId_p_struct* _temp6024=( struct Cyc_Absyn_UnknownId_p_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnknownId_p_struct)); _temp6024[ 0]=({
struct Cyc_Absyn_UnknownId_p_struct _temp6025; _temp6025.tag= Cyc_Absyn_UnknownId_p;
_temp6025.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp6026= yyvs; void**
_temp6028= _temp6026.curr + yyvsp_offset; if( _temp6026.base == 0? 1:( _temp6028
< _temp6026.base? 1: _temp6028 >= _temp6026.last_plus_one)){ _throw(
Null_Exception);}* _temp6028;})); _temp6025;}); _temp6024;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6029= yyls; struct Cyc_Yyltype* _temp6031= _temp6029.curr
+ yylsp_offset; if( _temp6029.base == 0? 1:( _temp6031 < _temp6029.base? 1:
_temp6031 >= _temp6029.last_plus_one)){ _throw( Null_Exception);}* _temp6031;}).first_line,({
struct _tagged_ptr3 _temp6032= yyls; struct Cyc_Yyltype* _temp6034= _temp6032.curr
+ yylsp_offset; if( _temp6032.base == 0? 1:( _temp6034 < _temp6032.base? 1:
_temp6034 >= _temp6032.last_plus_one)){ _throw( Null_Exception);}* _temp6034;}).last_line));
_temp6023;}); _temp6022;}); break; case 270: _LL6021: { struct Cyc_List_List*
tvs=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(* f)( struct Cyc_Position_Segment*,
void*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x)) Cyc_List_map_c)(
Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6052=
yyls; struct Cyc_Yyltype* _temp6054= _temp6052.curr +( yylsp_offset - 3); if(
_temp6052.base == 0? 1:( _temp6054 < _temp6052.base? 1: _temp6054 >= _temp6052.last_plus_one)){
_throw( Null_Exception);}* _temp6054;}).first_line,({ struct _tagged_ptr3
_temp6055= yyls; struct Cyc_Yyltype* _temp6057= _temp6055.curr +( yylsp_offset -
3); if( _temp6055.base == 0? 1:( _temp6057 < _temp6055.base? 1: _temp6057 >=
_temp6055.last_plus_one)){ _throw( Null_Exception);}* _temp6057;}).last_line),
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp6058= yyvs; void** _temp6060=
_temp6058.curr +( yyvsp_offset - 3); if( _temp6058.base == 0? 1:( _temp6060 <
_temp6058.base? 1: _temp6060 >= _temp6058.last_plus_one)){ _throw(
Null_Exception);}* _temp6060;}))); yyval=( void*)({ struct Cyc_Pattern_tok_struct*
_temp6036=( struct Cyc_Pattern_tok_struct*) GC_malloc( sizeof( struct Cyc_Pattern_tok_struct));
_temp6036[ 0]=({ struct Cyc_Pattern_tok_struct _temp6037; _temp6037.tag= Cyc_Pattern_tok;
_temp6037.f1= Cyc_Absyn_new_pat(( void*)({ struct Cyc_Absyn_UnknownCall_p_struct*
_temp6038=( struct Cyc_Absyn_UnknownCall_p_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_UnknownCall_p_struct)); _temp6038[ 0]=({ struct Cyc_Absyn_UnknownCall_p_struct
_temp6039; _temp6039.tag= Cyc_Absyn_UnknownCall_p; _temp6039.f1= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp6040= yyvs; void** _temp6042= _temp6040.curr +(
yyvsp_offset - 4); if( _temp6040.base == 0? 1:( _temp6042 < _temp6040.base? 1:
_temp6042 >= _temp6040.last_plus_one)){ _throw( Null_Exception);}* _temp6042;}));
_temp6039.f2= tvs; _temp6039.f3= Cyc_yyget_PatternList_tok(({ struct
_tagged_ptr2 _temp6043= yyvs; void** _temp6045= _temp6043.curr +( yyvsp_offset -
1); if( _temp6043.base == 0? 1:( _temp6045 < _temp6043.base? 1: _temp6045 >=
_temp6043.last_plus_one)){ _throw( Null_Exception);}* _temp6045;})); _temp6039;});
_temp6038;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6046= yyls;
struct Cyc_Yyltype* _temp6048= _temp6046.curr +( yylsp_offset - 4); if(
_temp6046.base == 0? 1:( _temp6048 < _temp6046.base? 1: _temp6048 >= _temp6046.last_plus_one)){
_throw( Null_Exception);}* _temp6048;}).first_line,({ struct _tagged_ptr3
_temp6049= yyls; struct Cyc_Yyltype* _temp6051= _temp6049.curr + yylsp_offset;
if( _temp6049.base == 0? 1:( _temp6051 < _temp6049.base? 1: _temp6051 >=
_temp6049.last_plus_one)){ _throw( Null_Exception);}* _temp6051;}).last_line));
_temp6037;}); _temp6036;}); break;} case 271: _LL6035: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp6062=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp6062[ 0]=({ struct Cyc_Pattern_tok_struct
_temp6063; _temp6063.tag= Cyc_Pattern_tok; _temp6063.f1= Cyc_Absyn_new_pat((
void*)({ struct Cyc_Absyn_Tuple_p_struct* _temp6064=( struct Cyc_Absyn_Tuple_p_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Tuple_p_struct)); _temp6064[ 0]=({ struct
Cyc_Absyn_Tuple_p_struct _temp6065; _temp6065.tag= Cyc_Absyn_Tuple_p; _temp6065.f1=
Cyc_yyget_PatternList_tok(({ struct _tagged_ptr2 _temp6066= yyvs; void**
_temp6068= _temp6066.curr +( yyvsp_offset - 1); if( _temp6066.base == 0? 1:(
_temp6068 < _temp6066.base? 1: _temp6068 >= _temp6066.last_plus_one)){ _throw(
Null_Exception);}* _temp6068;})); _temp6065;}); _temp6064;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6069= yyls; struct Cyc_Yyltype* _temp6071= _temp6069.curr
+( yylsp_offset - 3); if( _temp6069.base == 0? 1:( _temp6071 < _temp6069.base? 1:
_temp6071 >= _temp6069.last_plus_one)){ _throw( Null_Exception);}* _temp6071;}).first_line,({
struct _tagged_ptr3 _temp6072= yyls; struct Cyc_Yyltype* _temp6074= _temp6072.curr
+ yylsp_offset; if( _temp6072.base == 0? 1:( _temp6074 < _temp6072.base? 1:
_temp6074 >= _temp6072.last_plus_one)){ _throw( Null_Exception);}* _temp6074;}).last_line));
_temp6063;}); _temp6062;}); break; case 272: _LL6061: { struct Cyc_List_List*
tvs=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(* f)( struct Cyc_Position_Segment*,
void*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x)) Cyc_List_map_c)(
Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6089=
yyls; struct Cyc_Yyltype* _temp6091= _temp6089.curr +( yylsp_offset - 2); if(
_temp6089.base == 0? 1:( _temp6091 < _temp6089.base? 1: _temp6091 >= _temp6089.last_plus_one)){
_throw( Null_Exception);}* _temp6091;}).first_line,({ struct _tagged_ptr3
_temp6092= yyls; struct Cyc_Yyltype* _temp6094= _temp6092.curr +( yylsp_offset -
2); if( _temp6092.base == 0? 1:( _temp6094 < _temp6092.base? 1: _temp6094 >=
_temp6092.last_plus_one)){ _throw( Null_Exception);}* _temp6094;}).last_line),
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp6095= yyvs; void** _temp6097=
_temp6095.curr +( yyvsp_offset - 2); if( _temp6095.base == 0? 1:( _temp6097 <
_temp6095.base? 1: _temp6097 >= _temp6095.last_plus_one)){ _throw(
Null_Exception);}* _temp6097;}))); yyval=( void*)({ struct Cyc_Pattern_tok_struct*
_temp6076=( struct Cyc_Pattern_tok_struct*) GC_malloc( sizeof( struct Cyc_Pattern_tok_struct));
_temp6076[ 0]=({ struct Cyc_Pattern_tok_struct _temp6077; _temp6077.tag= Cyc_Pattern_tok;
_temp6077.f1= Cyc_Absyn_new_pat(( void*)({ struct Cyc_Absyn_UnknownFields_p_struct*
_temp6078=( struct Cyc_Absyn_UnknownFields_p_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_UnknownFields_p_struct)); _temp6078[ 0]=({ struct Cyc_Absyn_UnknownFields_p_struct
_temp6079; _temp6079.tag= Cyc_Absyn_UnknownFields_p; _temp6079.f1= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp6080= yyvs; void** _temp6082= _temp6080.curr +(
yyvsp_offset - 3); if( _temp6080.base == 0? 1:( _temp6082 < _temp6080.base? 1:
_temp6082 >= _temp6080.last_plus_one)){ _throw( Null_Exception);}* _temp6082;}));
_temp6079.f2= tvs; _temp6079.f3= 0; _temp6079;}); _temp6078;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6083= yyls; struct Cyc_Yyltype* _temp6085= _temp6083.curr
+( yylsp_offset - 3); if( _temp6083.base == 0? 1:( _temp6085 < _temp6083.base? 1:
_temp6085 >= _temp6083.last_plus_one)){ _throw( Null_Exception);}* _temp6085;}).first_line,({
struct _tagged_ptr3 _temp6086= yyls; struct Cyc_Yyltype* _temp6088= _temp6086.curr
+ yylsp_offset; if( _temp6086.base == 0? 1:( _temp6088 < _temp6086.base? 1:
_temp6088 >= _temp6086.last_plus_one)){ _throw( Null_Exception);}* _temp6088;}).last_line));
_temp6077;}); _temp6076;}); break;} case 273: _LL6075: { struct Cyc_List_List*
tvs=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Tvar*(* f)( struct Cyc_Position_Segment*,
void*), struct Cyc_Position_Segment* env, struct Cyc_List_List* x)) Cyc_List_map_c)(
Cyc_Parse_typ2tvar, Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6115=
yyls; struct Cyc_Yyltype* _temp6117= _temp6115.curr +( yylsp_offset - 3); if(
_temp6115.base == 0? 1:( _temp6117 < _temp6115.base? 1: _temp6117 >= _temp6115.last_plus_one)){
_throw( Null_Exception);}* _temp6117;}).first_line,({ struct _tagged_ptr3
_temp6118= yyls; struct Cyc_Yyltype* _temp6120= _temp6118.curr +( yylsp_offset -
3); if( _temp6118.base == 0? 1:( _temp6120 < _temp6118.base? 1: _temp6120 >=
_temp6118.last_plus_one)){ _throw( Null_Exception);}* _temp6120;}).last_line),
Cyc_yyget_TypeList_tok(({ struct _tagged_ptr2 _temp6121= yyvs; void** _temp6123=
_temp6121.curr +( yyvsp_offset - 3); if( _temp6121.base == 0? 1:( _temp6123 <
_temp6121.base? 1: _temp6123 >= _temp6121.last_plus_one)){ _throw(
Null_Exception);}* _temp6123;}))); yyval=( void*)({ struct Cyc_Pattern_tok_struct*
_temp6099=( struct Cyc_Pattern_tok_struct*) GC_malloc( sizeof( struct Cyc_Pattern_tok_struct));
_temp6099[ 0]=({ struct Cyc_Pattern_tok_struct _temp6100; _temp6100.tag= Cyc_Pattern_tok;
_temp6100.f1= Cyc_Absyn_new_pat(( void*)({ struct Cyc_Absyn_UnknownFields_p_struct*
_temp6101=( struct Cyc_Absyn_UnknownFields_p_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_UnknownFields_p_struct)); _temp6101[ 0]=({ struct Cyc_Absyn_UnknownFields_p_struct
_temp6102; _temp6102.tag= Cyc_Absyn_UnknownFields_p; _temp6102.f1= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp6103= yyvs; void** _temp6105= _temp6103.curr +(
yyvsp_offset - 4); if( _temp6103.base == 0? 1:( _temp6105 < _temp6103.base? 1:
_temp6105 >= _temp6103.last_plus_one)){ _throw( Null_Exception);}* _temp6105;}));
_temp6102.f2= tvs; _temp6102.f3= Cyc_yyget_FieldPatternList_tok(({ struct
_tagged_ptr2 _temp6106= yyvs; void** _temp6108= _temp6106.curr +( yyvsp_offset -
1); if( _temp6106.base == 0? 1:( _temp6108 < _temp6106.base? 1: _temp6108 >=
_temp6106.last_plus_one)){ _throw( Null_Exception);}* _temp6108;})); _temp6102;});
_temp6101;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6109= yyls;
struct Cyc_Yyltype* _temp6111= _temp6109.curr +( yylsp_offset - 4); if(
_temp6109.base == 0? 1:( _temp6111 < _temp6109.base? 1: _temp6111 >= _temp6109.last_plus_one)){
_throw( Null_Exception);}* _temp6111;}).first_line,({ struct _tagged_ptr3
_temp6112= yyls; struct Cyc_Yyltype* _temp6114= _temp6112.curr + yylsp_offset;
if( _temp6112.base == 0? 1:( _temp6114 < _temp6112.base? 1: _temp6114 >=
_temp6112.last_plus_one)){ _throw( Null_Exception);}* _temp6114;}).last_line));
_temp6100;}); _temp6099;}); break;} case 274: _LL6098: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp6125=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp6125[ 0]=({ struct Cyc_Pattern_tok_struct
_temp6126; _temp6126.tag= Cyc_Pattern_tok; _temp6126.f1= Cyc_Absyn_new_pat((
void*)({ struct Cyc_Absyn_Pointer_p_struct* _temp6127=( struct Cyc_Absyn_Pointer_p_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Pointer_p_struct)); _temp6127[ 0]=({ struct
Cyc_Absyn_Pointer_p_struct _temp6128; _temp6128.tag= Cyc_Absyn_Pointer_p;
_temp6128.f1= Cyc_yyget_Pattern_tok(({ struct _tagged_ptr2 _temp6129= yyvs; void**
_temp6131= _temp6129.curr + yyvsp_offset; if( _temp6129.base == 0? 1:( _temp6131
< _temp6129.base? 1: _temp6131 >= _temp6129.last_plus_one)){ _throw(
Null_Exception);}* _temp6131;})); _temp6128;}); _temp6127;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6132= yyls; struct Cyc_Yyltype* _temp6134= _temp6132.curr
+( yylsp_offset - 1); if( _temp6132.base == 0? 1:( _temp6134 < _temp6132.base? 1:
_temp6134 >= _temp6132.last_plus_one)){ _throw( Null_Exception);}* _temp6134;}).first_line,({
struct _tagged_ptr3 _temp6135= yyls; struct Cyc_Yyltype* _temp6137= _temp6135.curr
+ yylsp_offset; if( _temp6135.base == 0? 1:( _temp6137 < _temp6135.base? 1:
_temp6137 >= _temp6135.last_plus_one)){ _throw( Null_Exception);}* _temp6137;}).last_line));
_temp6126;}); _temp6125;}); break; case 275: _LL6124: yyval=( void*)({ struct
Cyc_Pattern_tok_struct* _temp6139=( struct Cyc_Pattern_tok_struct*) GC_malloc(
sizeof( struct Cyc_Pattern_tok_struct)); _temp6139[ 0]=({ struct Cyc_Pattern_tok_struct
_temp6140; _temp6140.tag= Cyc_Pattern_tok; _temp6140.f1= Cyc_Absyn_new_pat((
void*)({ struct Cyc_Absyn_Reference_p_struct* _temp6141=( struct Cyc_Absyn_Reference_p_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Reference_p_struct)); _temp6141[ 0]=({
struct Cyc_Absyn_Reference_p_struct _temp6142; _temp6142.tag= Cyc_Absyn_Reference_p;
_temp6142.f1= Cyc_Absyn_new_vardecl(({ struct _tuple1* _temp6143=( struct
_tuple1*) GC_malloc( sizeof( struct _tuple1)); _temp6143->f1=( void*) Cyc_Absyn_Loc_n;
_temp6143->f2=({ struct _tagged_string* _temp6144=( struct _tagged_string*)
GC_malloc( sizeof( struct _tagged_string) * 1); _temp6144[ 0]= Cyc_yyget_String_tok(({
struct _tagged_ptr2 _temp6145= yyvs; void** _temp6147= _temp6145.curr +
yyvsp_offset; if( _temp6145.base == 0? 1:( _temp6147 < _temp6145.base? 1:
_temp6147 >= _temp6145.last_plus_one)){ _throw( Null_Exception);}* _temp6147;}));
_temp6144;}); _temp6143;}),( void*) Cyc_Absyn_VoidType, 0); _temp6142;});
_temp6141;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6148= yyls;
struct Cyc_Yyltype* _temp6150= _temp6148.curr +( yylsp_offset - 1); if(
_temp6148.base == 0? 1:( _temp6150 < _temp6148.base? 1: _temp6150 >= _temp6148.last_plus_one)){
_throw( Null_Exception);}* _temp6150;}).first_line,({ struct _tagged_ptr3
_temp6151= yyls; struct Cyc_Yyltype* _temp6153= _temp6151.curr + yylsp_offset;
if( _temp6151.base == 0? 1:( _temp6153 < _temp6151.base? 1: _temp6153 >=
_temp6151.last_plus_one)){ _throw( Null_Exception);}* _temp6153;}).last_line));
_temp6140;}); _temp6139;}); break; case 276: _LL6138: yyval=( void*)({ struct
Cyc_PatternList_tok_struct* _temp6155=( struct Cyc_PatternList_tok_struct*)
GC_malloc( sizeof( struct Cyc_PatternList_tok_struct)); _temp6155[ 0]=({ struct
Cyc_PatternList_tok_struct _temp6156; _temp6156.tag= Cyc_PatternList_tok;
_temp6156.f1= 0; _temp6156;}); _temp6155;}); break; case 277: _LL6154: yyval=(
void*)({ struct Cyc_PatternList_tok_struct* _temp6158=( struct Cyc_PatternList_tok_struct*)
GC_malloc( sizeof( struct Cyc_PatternList_tok_struct)); _temp6158[ 0]=({ struct
Cyc_PatternList_tok_struct _temp6159; _temp6159.tag= Cyc_PatternList_tok;
_temp6159.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
Cyc_yyget_PatternList_tok(({ struct _tagged_ptr2 _temp6160= yyvs; void**
_temp6162= _temp6160.curr + yyvsp_offset; if( _temp6160.base == 0? 1:( _temp6162
< _temp6160.base? 1: _temp6162 >= _temp6160.last_plus_one)){ _throw(
Null_Exception);}* _temp6162;}))); _temp6159;}); _temp6158;}); break; case 278:
_LL6157: yyval=( void*)({ struct Cyc_PatternList_tok_struct* _temp6164=( struct
Cyc_PatternList_tok_struct*) GC_malloc( sizeof( struct Cyc_PatternList_tok_struct));
_temp6164[ 0]=({ struct Cyc_PatternList_tok_struct _temp6165; _temp6165.tag= Cyc_PatternList_tok;
_temp6165.f1=({ struct Cyc_List_List* _temp6166=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp6166->hd=( void*) Cyc_yyget_Pattern_tok(({
struct _tagged_ptr2 _temp6167= yyvs; void** _temp6169= _temp6167.curr +
yyvsp_offset; if( _temp6167.base == 0? 1:( _temp6169 < _temp6167.base? 1:
_temp6169 >= _temp6167.last_plus_one)){ _throw( Null_Exception);}* _temp6169;}));
_temp6166->tl= 0; _temp6166;}); _temp6165;}); _temp6164;}); break; case 279:
_LL6163: yyval=( void*)({ struct Cyc_PatternList_tok_struct* _temp6171=( struct
Cyc_PatternList_tok_struct*) GC_malloc( sizeof( struct Cyc_PatternList_tok_struct));
_temp6171[ 0]=({ struct Cyc_PatternList_tok_struct _temp6172; _temp6172.tag= Cyc_PatternList_tok;
_temp6172.f1=({ struct Cyc_List_List* _temp6173=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp6173->hd=( void*) Cyc_yyget_Pattern_tok(({
struct _tagged_ptr2 _temp6177= yyvs; void** _temp6179= _temp6177.curr +
yyvsp_offset; if( _temp6177.base == 0? 1:( _temp6179 < _temp6177.base? 1:
_temp6179 >= _temp6177.last_plus_one)){ _throw( Null_Exception);}* _temp6179;}));
_temp6173->tl= Cyc_yyget_PatternList_tok(({ struct _tagged_ptr2 _temp6174= yyvs;
void** _temp6176= _temp6174.curr +( yyvsp_offset - 2); if( _temp6174.base == 0?
1:( _temp6176 < _temp6174.base? 1: _temp6176 >= _temp6174.last_plus_one)){
_throw( Null_Exception);}* _temp6176;})); _temp6173;}); _temp6172;}); _temp6171;});
break; case 280: _LL6170: yyval=( void*)({ struct Cyc_FieldPattern_tok_struct*
_temp6181=( struct Cyc_FieldPattern_tok_struct*) GC_malloc( sizeof( struct Cyc_FieldPattern_tok_struct));
_temp6181[ 0]=({ struct Cyc_FieldPattern_tok_struct _temp6182; _temp6182.tag=
Cyc_FieldPattern_tok; _temp6182.f1=({ struct _tuple17* _temp6183=( struct
_tuple17*) GC_malloc( sizeof( struct _tuple17)); _temp6183->f1= 0; _temp6183->f2=
Cyc_yyget_Pattern_tok(({ struct _tagged_ptr2 _temp6184= yyvs; void** _temp6186=
_temp6184.curr + yyvsp_offset; if( _temp6184.base == 0? 1:( _temp6186 <
_temp6184.base? 1: _temp6186 >= _temp6184.last_plus_one)){ _throw(
Null_Exception);}* _temp6186;})); _temp6183;}); _temp6182;}); _temp6181;});
break; case 281: _LL6180: yyval=( void*)({ struct Cyc_FieldPattern_tok_struct*
_temp6188=( struct Cyc_FieldPattern_tok_struct*) GC_malloc( sizeof( struct Cyc_FieldPattern_tok_struct));
_temp6188[ 0]=({ struct Cyc_FieldPattern_tok_struct _temp6189; _temp6189.tag=
Cyc_FieldPattern_tok; _temp6189.f1=({ struct _tuple17* _temp6190=( struct
_tuple17*) GC_malloc( sizeof( struct _tuple17)); _temp6190->f1= Cyc_yyget_DesignatorList_tok(({
struct _tagged_ptr2 _temp6194= yyvs; void** _temp6196= _temp6194.curr +(
yyvsp_offset - 1); if( _temp6194.base == 0? 1:( _temp6196 < _temp6194.base? 1:
_temp6196 >= _temp6194.last_plus_one)){ _throw( Null_Exception);}* _temp6196;}));
_temp6190->f2= Cyc_yyget_Pattern_tok(({ struct _tagged_ptr2 _temp6191= yyvs;
void** _temp6193= _temp6191.curr + yyvsp_offset; if( _temp6191.base == 0? 1:(
_temp6193 < _temp6191.base? 1: _temp6193 >= _temp6191.last_plus_one)){ _throw(
Null_Exception);}* _temp6193;})); _temp6190;}); _temp6189;}); _temp6188;});
break; case 282: _LL6187: yyval=( void*)({ struct Cyc_FieldPatternList_tok_struct*
_temp6198=( struct Cyc_FieldPatternList_tok_struct*) GC_malloc( sizeof( struct
Cyc_FieldPatternList_tok_struct)); _temp6198[ 0]=({ struct Cyc_FieldPatternList_tok_struct
_temp6199; _temp6199.tag= Cyc_FieldPatternList_tok; _temp6199.f1=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_FieldPatternList_tok(({
struct _tagged_ptr2 _temp6200= yyvs; void** _temp6202= _temp6200.curr +
yyvsp_offset; if( _temp6200.base == 0? 1:( _temp6202 < _temp6200.base? 1:
_temp6202 >= _temp6200.last_plus_one)){ _throw( Null_Exception);}* _temp6202;})));
_temp6199;}); _temp6198;}); break; case 283: _LL6197: yyval=( void*)({ struct
Cyc_FieldPatternList_tok_struct* _temp6204=( struct Cyc_FieldPatternList_tok_struct*)
GC_malloc( sizeof( struct Cyc_FieldPatternList_tok_struct)); _temp6204[ 0]=({
struct Cyc_FieldPatternList_tok_struct _temp6205; _temp6205.tag= Cyc_FieldPatternList_tok;
_temp6205.f1=({ struct Cyc_List_List* _temp6206=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp6206->hd=( void*) Cyc_yyget_FieldPattern_tok(({
struct _tagged_ptr2 _temp6207= yyvs; void** _temp6209= _temp6207.curr +
yyvsp_offset; if( _temp6207.base == 0? 1:( _temp6209 < _temp6207.base? 1:
_temp6209 >= _temp6207.last_plus_one)){ _throw( Null_Exception);}* _temp6209;}));
_temp6206->tl= 0; _temp6206;}); _temp6205;}); _temp6204;}); break; case 284:
_LL6203: yyval=( void*)({ struct Cyc_FieldPatternList_tok_struct* _temp6211=(
struct Cyc_FieldPatternList_tok_struct*) GC_malloc( sizeof( struct Cyc_FieldPatternList_tok_struct));
_temp6211[ 0]=({ struct Cyc_FieldPatternList_tok_struct _temp6212; _temp6212.tag=
Cyc_FieldPatternList_tok; _temp6212.f1=({ struct Cyc_List_List* _temp6213=(
struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp6213->hd=(
void*) Cyc_yyget_FieldPattern_tok(({ struct _tagged_ptr2 _temp6217= yyvs; void**
_temp6219= _temp6217.curr + yyvsp_offset; if( _temp6217.base == 0? 1:( _temp6219
< _temp6217.base? 1: _temp6219 >= _temp6217.last_plus_one)){ _throw(
Null_Exception);}* _temp6219;})); _temp6213->tl= Cyc_yyget_FieldPatternList_tok(({
struct _tagged_ptr2 _temp6214= yyvs; void** _temp6216= _temp6214.curr +(
yyvsp_offset - 2); if( _temp6214.base == 0? 1:( _temp6216 < _temp6214.base? 1:
_temp6216 >= _temp6214.last_plus_one)){ _throw( Null_Exception);}* _temp6216;}));
_temp6213;}); _temp6212;}); _temp6211;}); break; case 285: _LL6210: yyval=({
struct _tagged_ptr2 _temp6221= yyvs; void** _temp6223= _temp6221.curr +
yyvsp_offset; if( _temp6221.base == 0? 1:( _temp6223 < _temp6221.base? 1:
_temp6223 >= _temp6221.last_plus_one)){ _throw( Null_Exception);}* _temp6223;});
break; case 286: _LL6220: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6225=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp6225[ 0]=({ struct Cyc_Exp_tok_struct _temp6226; _temp6226.tag= Cyc_Exp_tok;
_temp6226.f1= Cyc_Absyn_seq_exp( Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6227= yyvs; void** _temp6229= _temp6227.curr +( yyvsp_offset - 2); if(
_temp6227.base == 0? 1:( _temp6229 < _temp6227.base? 1: _temp6229 >= _temp6227.last_plus_one)){
_throw( Null_Exception);}* _temp6229;})), Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp6230= yyvs; void** _temp6232= _temp6230.curr + yyvsp_offset;
if( _temp6230.base == 0? 1:( _temp6232 < _temp6230.base? 1: _temp6232 >=
_temp6230.last_plus_one)){ _throw( Null_Exception);}* _temp6232;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6233= yyls; struct Cyc_Yyltype* _temp6235= _temp6233.curr
+( yylsp_offset - 2); if( _temp6233.base == 0? 1:( _temp6235 < _temp6233.base? 1:
_temp6235 >= _temp6233.last_plus_one)){ _throw( Null_Exception);}* _temp6235;}).first_line,({
struct _tagged_ptr3 _temp6236= yyls; struct Cyc_Yyltype* _temp6238= _temp6236.curr
+ yylsp_offset; if( _temp6236.base == 0? 1:( _temp6238 < _temp6236.base? 1:
_temp6238 >= _temp6236.last_plus_one)){ _throw( Null_Exception);}* _temp6238;}).last_line));
_temp6226;}); _temp6225;}); break; case 287: _LL6224: yyval=({ struct
_tagged_ptr2 _temp6240= yyvs; void** _temp6242= _temp6240.curr + yyvsp_offset;
if( _temp6240.base == 0? 1:( _temp6242 < _temp6240.base? 1: _temp6242 >=
_temp6240.last_plus_one)){ _throw( Null_Exception);}* _temp6242;}); break; case
288: _LL6239: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6244=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6244[ 0]=({ struct Cyc_Exp_tok_struct
_temp6245; _temp6245.tag= Cyc_Exp_tok; _temp6245.f1= Cyc_Absyn_assignop_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6246= yyvs; void** _temp6248= _temp6246.curr +(
yyvsp_offset - 2); if( _temp6246.base == 0? 1:( _temp6248 < _temp6246.base? 1:
_temp6248 >= _temp6246.last_plus_one)){ _throw( Null_Exception);}* _temp6248;})),
Cyc_yyget_Primopopt_tok(({ struct _tagged_ptr2 _temp6249= yyvs; void** _temp6251=
_temp6249.curr +( yyvsp_offset - 1); if( _temp6249.base == 0? 1:( _temp6251 <
_temp6249.base? 1: _temp6251 >= _temp6249.last_plus_one)){ _throw(
Null_Exception);}* _temp6251;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6252= yyvs; void** _temp6254= _temp6252.curr + yyvsp_offset; if( _temp6252.base
== 0? 1:( _temp6254 < _temp6252.base? 1: _temp6254 >= _temp6252.last_plus_one)){
_throw( Null_Exception);}* _temp6254;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6255= yyls; struct Cyc_Yyltype* _temp6257= _temp6255.curr +(
yylsp_offset - 2); if( _temp6255.base == 0? 1:( _temp6257 < _temp6255.base? 1:
_temp6257 >= _temp6255.last_plus_one)){ _throw( Null_Exception);}* _temp6257;}).first_line,({
struct _tagged_ptr3 _temp6258= yyls; struct Cyc_Yyltype* _temp6260= _temp6258.curr
+ yylsp_offset; if( _temp6258.base == 0? 1:( _temp6260 < _temp6258.base? 1:
_temp6260 >= _temp6258.last_plus_one)){ _throw( Null_Exception);}* _temp6260;}).last_line));
_temp6245;}); _temp6244;}); break; case 289: _LL6243: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6262=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6262[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6263; _temp6263.tag= Cyc_Primopopt_tok; _temp6263.f1=
0; _temp6263;}); _temp6262;}); break; case 290: _LL6261: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6265=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6265[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6266; _temp6266.tag= Cyc_Primopopt_tok; _temp6266.f1=({
struct Cyc_Core_Opt* _temp6267=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6267->v=( void*)(( void*) Cyc_Absyn_Times); _temp6267;});
_temp6266;}); _temp6265;}); break; case 291: _LL6264: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6269=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6269[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6270; _temp6270.tag= Cyc_Primopopt_tok; _temp6270.f1=({
struct Cyc_Core_Opt* _temp6271=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6271->v=( void*)(( void*) Cyc_Absyn_Div); _temp6271;});
_temp6270;}); _temp6269;}); break; case 292: _LL6268: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6273=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6273[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6274; _temp6274.tag= Cyc_Primopopt_tok; _temp6274.f1=({
struct Cyc_Core_Opt* _temp6275=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6275->v=( void*)(( void*) Cyc_Absyn_Mod); _temp6275;});
_temp6274;}); _temp6273;}); break; case 293: _LL6272: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6277=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6277[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6278; _temp6278.tag= Cyc_Primopopt_tok; _temp6278.f1=({
struct Cyc_Core_Opt* _temp6279=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6279->v=( void*)(( void*) Cyc_Absyn_Plus); _temp6279;});
_temp6278;}); _temp6277;}); break; case 294: _LL6276: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6281=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6281[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6282; _temp6282.tag= Cyc_Primopopt_tok; _temp6282.f1=({
struct Cyc_Core_Opt* _temp6283=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6283->v=( void*)(( void*) Cyc_Absyn_Minus); _temp6283;});
_temp6282;}); _temp6281;}); break; case 295: _LL6280: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6285=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6285[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6286; _temp6286.tag= Cyc_Primopopt_tok; _temp6286.f1=({
struct Cyc_Core_Opt* _temp6287=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6287->v=( void*)(( void*) Cyc_Absyn_Bitlshift); _temp6287;});
_temp6286;}); _temp6285;}); break; case 296: _LL6284: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6289=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6289[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6290; _temp6290.tag= Cyc_Primopopt_tok; _temp6290.f1=({
struct Cyc_Core_Opt* _temp6291=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6291->v=( void*)(( void*) Cyc_Absyn_Bitlrshift); _temp6291;});
_temp6290;}); _temp6289;}); break; case 297: _LL6288: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6293=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6293[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6294; _temp6294.tag= Cyc_Primopopt_tok; _temp6294.f1=({
struct Cyc_Core_Opt* _temp6295=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6295->v=( void*)(( void*) Cyc_Absyn_Bitand); _temp6295;});
_temp6294;}); _temp6293;}); break; case 298: _LL6292: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6297=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6297[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6298; _temp6298.tag= Cyc_Primopopt_tok; _temp6298.f1=({
struct Cyc_Core_Opt* _temp6299=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6299->v=( void*)(( void*) Cyc_Absyn_Bitxor); _temp6299;});
_temp6298;}); _temp6297;}); break; case 299: _LL6296: yyval=( void*)({ struct
Cyc_Primopopt_tok_struct* _temp6301=( struct Cyc_Primopopt_tok_struct*)
GC_malloc( sizeof( struct Cyc_Primopopt_tok_struct)); _temp6301[ 0]=({ struct
Cyc_Primopopt_tok_struct _temp6302; _temp6302.tag= Cyc_Primopopt_tok; _temp6302.f1=({
struct Cyc_Core_Opt* _temp6303=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp6303->v=( void*)(( void*) Cyc_Absyn_Bitor); _temp6303;});
_temp6302;}); _temp6301;}); break; case 300: _LL6300: yyval=({ struct
_tagged_ptr2 _temp6305= yyvs; void** _temp6307= _temp6305.curr + yyvsp_offset;
if( _temp6305.base == 0? 1:( _temp6307 < _temp6305.base? 1: _temp6307 >=
_temp6305.last_plus_one)){ _throw( Null_Exception);}* _temp6307;}); break; case
301: _LL6304: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6309=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6309[ 0]=({ struct Cyc_Exp_tok_struct
_temp6310; _temp6310.tag= Cyc_Exp_tok; _temp6310.f1= Cyc_Absyn_conditional_exp(
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6311= yyvs; void** _temp6313=
_temp6311.curr +( yyvsp_offset - 4); if( _temp6311.base == 0? 1:( _temp6313 <
_temp6311.base? 1: _temp6313 >= _temp6311.last_plus_one)){ _throw(
Null_Exception);}* _temp6313;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6314= yyvs; void** _temp6316= _temp6314.curr +( yyvsp_offset - 2); if(
_temp6314.base == 0? 1:( _temp6316 < _temp6314.base? 1: _temp6316 >= _temp6314.last_plus_one)){
_throw( Null_Exception);}* _temp6316;})), Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp6317= yyvs; void** _temp6319= _temp6317.curr + yyvsp_offset;
if( _temp6317.base == 0? 1:( _temp6319 < _temp6317.base? 1: _temp6319 >=
_temp6317.last_plus_one)){ _throw( Null_Exception);}* _temp6319;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6320= yyls; struct Cyc_Yyltype* _temp6322= _temp6320.curr
+( yylsp_offset - 4); if( _temp6320.base == 0? 1:( _temp6322 < _temp6320.base? 1:
_temp6322 >= _temp6320.last_plus_one)){ _throw( Null_Exception);}* _temp6322;}).first_line,({
struct _tagged_ptr3 _temp6323= yyls; struct Cyc_Yyltype* _temp6325= _temp6323.curr
+ yylsp_offset; if( _temp6323.base == 0? 1:( _temp6325 < _temp6323.base? 1:
_temp6325 >= _temp6323.last_plus_one)){ _throw( Null_Exception);}* _temp6325;}).last_line));
_temp6310;}); _temp6309;}); break; case 302: _LL6308: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6327=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6327[ 0]=({ struct Cyc_Exp_tok_struct
_temp6328; _temp6328.tag= Cyc_Exp_tok; _temp6328.f1= Cyc_Absyn_throw_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6329= yyvs; void** _temp6331= _temp6329.curr +
yyvsp_offset; if( _temp6329.base == 0? 1:( _temp6331 < _temp6329.base? 1:
_temp6331 >= _temp6329.last_plus_one)){ _throw( Null_Exception);}* _temp6331;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6332= yyls; struct Cyc_Yyltype*
_temp6334= _temp6332.curr +( yylsp_offset - 1); if( _temp6332.base == 0? 1:(
_temp6334 < _temp6332.base? 1: _temp6334 >= _temp6332.last_plus_one)){ _throw(
Null_Exception);}* _temp6334;}).first_line,({ struct _tagged_ptr3 _temp6335=
yyls; struct Cyc_Yyltype* _temp6337= _temp6335.curr + yylsp_offset; if(
_temp6335.base == 0? 1:( _temp6337 < _temp6335.base? 1: _temp6337 >= _temp6335.last_plus_one)){
_throw( Null_Exception);}* _temp6337;}).last_line)); _temp6328;}); _temp6327;});
break; case 303: _LL6326: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6339=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp6339[ 0]=({ struct Cyc_Exp_tok_struct _temp6340; _temp6340.tag= Cyc_Exp_tok;
_temp6340.f1= Cyc_Absyn_New_exp( 0, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6341= yyvs; void** _temp6343= _temp6341.curr + yyvsp_offset; if( _temp6341.base
== 0? 1:( _temp6343 < _temp6341.base? 1: _temp6343 >= _temp6341.last_plus_one)){
_throw( Null_Exception);}* _temp6343;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6344= yyls; struct Cyc_Yyltype* _temp6346= _temp6344.curr +(
yylsp_offset - 1); if( _temp6344.base == 0? 1:( _temp6346 < _temp6344.base? 1:
_temp6346 >= _temp6344.last_plus_one)){ _throw( Null_Exception);}* _temp6346;}).first_line,({
struct _tagged_ptr3 _temp6347= yyls; struct Cyc_Yyltype* _temp6349= _temp6347.curr
+( yylsp_offset + 1); if( _temp6347.base == 0? 1:( _temp6349 < _temp6347.base? 1:
_temp6349 >= _temp6347.last_plus_one)){ _throw( Null_Exception);}* _temp6349;}).last_line));
_temp6340;}); _temp6339;}); break; case 304: _LL6338: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6351=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6351[ 0]=({ struct Cyc_Exp_tok_struct
_temp6352; _temp6352.tag= Cyc_Exp_tok; _temp6352.f1= Cyc_Absyn_New_exp( 0, Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6353= yyvs; void** _temp6355= _temp6353.curr +
yyvsp_offset; if( _temp6353.base == 0? 1:( _temp6355 < _temp6353.base? 1:
_temp6355 >= _temp6353.last_plus_one)){ _throw( Null_Exception);}* _temp6355;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6356= yyls; struct Cyc_Yyltype*
_temp6358= _temp6356.curr +( yylsp_offset - 1); if( _temp6356.base == 0? 1:(
_temp6358 < _temp6356.base? 1: _temp6358 >= _temp6356.last_plus_one)){ _throw(
Null_Exception);}* _temp6358;}).first_line,({ struct _tagged_ptr3 _temp6359=
yyls; struct Cyc_Yyltype* _temp6361= _temp6359.curr +( yylsp_offset + 1); if(
_temp6359.base == 0? 1:( _temp6361 < _temp6359.base? 1: _temp6361 >= _temp6359.last_plus_one)){
_throw( Null_Exception);}* _temp6361;}).last_line)); _temp6352;}); _temp6351;});
break; case 305: _LL6350: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6363=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp6363[ 0]=({ struct Cyc_Exp_tok_struct _temp6364; _temp6364.tag= Cyc_Exp_tok;
_temp6364.f1= Cyc_Absyn_New_exp(( struct Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6365= yyvs; void** _temp6367= _temp6365.curr +(
yyvsp_offset - 2); if( _temp6365.base == 0? 1:( _temp6367 < _temp6365.base? 1:
_temp6367 >= _temp6365.last_plus_one)){ _throw( Null_Exception);}* _temp6367;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6368= yyvs; void** _temp6370=
_temp6368.curr + yyvsp_offset; if( _temp6368.base == 0? 1:( _temp6370 <
_temp6368.base? 1: _temp6370 >= _temp6368.last_plus_one)){ _throw(
Null_Exception);}* _temp6370;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6371= yyls; struct Cyc_Yyltype* _temp6373= _temp6371.curr +(
yylsp_offset - 4); if( _temp6371.base == 0? 1:( _temp6373 < _temp6371.base? 1:
_temp6373 >= _temp6371.last_plus_one)){ _throw( Null_Exception);}* _temp6373;}).first_line,({
struct _tagged_ptr3 _temp6374= yyls; struct Cyc_Yyltype* _temp6376= _temp6374.curr
+ yylsp_offset; if( _temp6374.base == 0? 1:( _temp6376 < _temp6374.base? 1:
_temp6376 >= _temp6374.last_plus_one)){ _throw( Null_Exception);}* _temp6376;}).last_line));
_temp6364;}); _temp6363;}); break; case 306: _LL6362: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6378=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6378[ 0]=({ struct Cyc_Exp_tok_struct
_temp6379; _temp6379.tag= Cyc_Exp_tok; _temp6379.f1= Cyc_Absyn_New_exp(( struct
Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6380= yyvs; void**
_temp6382= _temp6380.curr +( yyvsp_offset - 2); if( _temp6380.base == 0? 1:(
_temp6382 < _temp6380.base? 1: _temp6382 >= _temp6380.last_plus_one)){ _throw(
Null_Exception);}* _temp6382;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6383= yyvs; void** _temp6385= _temp6383.curr + yyvsp_offset; if( _temp6383.base
== 0? 1:( _temp6385 < _temp6383.base? 1: _temp6385 >= _temp6383.last_plus_one)){
_throw( Null_Exception);}* _temp6385;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6386= yyls; struct Cyc_Yyltype* _temp6388= _temp6386.curr +(
yylsp_offset - 4); if( _temp6386.base == 0? 1:( _temp6388 < _temp6386.base? 1:
_temp6388 >= _temp6386.last_plus_one)){ _throw( Null_Exception);}* _temp6388;}).first_line,({
struct _tagged_ptr3 _temp6389= yyls; struct Cyc_Yyltype* _temp6391= _temp6389.curr
+ yylsp_offset; if( _temp6389.base == 0? 1:( _temp6391 < _temp6389.base? 1:
_temp6391 >= _temp6389.last_plus_one)){ _throw( Null_Exception);}* _temp6391;}).last_line));
_temp6379;}); _temp6378;}); break; case 307: _LL6377: yyval=({ struct
_tagged_ptr2 _temp6393= yyvs; void** _temp6395= _temp6393.curr + yyvsp_offset;
if( _temp6393.base == 0? 1:( _temp6395 < _temp6393.base? 1: _temp6395 >=
_temp6393.last_plus_one)){ _throw( Null_Exception);}* _temp6395;}); break; case
308: _LL6392: yyval=({ struct _tagged_ptr2 _temp6397= yyvs; void** _temp6399=
_temp6397.curr + yyvsp_offset; if( _temp6397.base == 0? 1:( _temp6399 <
_temp6397.base? 1: _temp6399 >= _temp6397.last_plus_one)){ _throw(
Null_Exception);}* _temp6399;}); break; case 309: _LL6396: yyval=( void*)({
struct Cyc_Exp_tok_struct* _temp6401=( struct Cyc_Exp_tok_struct*) GC_malloc(
sizeof( struct Cyc_Exp_tok_struct)); _temp6401[ 0]=({ struct Cyc_Exp_tok_struct
_temp6402; _temp6402.tag= Cyc_Exp_tok; _temp6402.f1= Cyc_Absyn_or_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6403= yyvs; void** _temp6405= _temp6403.curr +(
yyvsp_offset - 2); if( _temp6403.base == 0? 1:( _temp6405 < _temp6403.base? 1:
_temp6405 >= _temp6403.last_plus_one)){ _throw( Null_Exception);}* _temp6405;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6406= yyvs; void** _temp6408=
_temp6406.curr + yyvsp_offset; if( _temp6406.base == 0? 1:( _temp6408 <
_temp6406.base? 1: _temp6408 >= _temp6406.last_plus_one)){ _throw(
Null_Exception);}* _temp6408;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6409= yyls; struct Cyc_Yyltype* _temp6411= _temp6409.curr +(
yylsp_offset - 2); if( _temp6409.base == 0? 1:( _temp6411 < _temp6409.base? 1:
_temp6411 >= _temp6409.last_plus_one)){ _throw( Null_Exception);}* _temp6411;}).first_line,({
struct _tagged_ptr3 _temp6412= yyls; struct Cyc_Yyltype* _temp6414= _temp6412.curr
+ yylsp_offset; if( _temp6412.base == 0? 1:( _temp6414 < _temp6412.base? 1:
_temp6414 >= _temp6412.last_plus_one)){ _throw( Null_Exception);}* _temp6414;}).last_line));
_temp6402;}); _temp6401;}); break; case 310: _LL6400: yyval=({ struct
_tagged_ptr2 _temp6416= yyvs; void** _temp6418= _temp6416.curr + yyvsp_offset;
if( _temp6416.base == 0? 1:( _temp6418 < _temp6416.base? 1: _temp6418 >=
_temp6416.last_plus_one)){ _throw( Null_Exception);}* _temp6418;}); break; case
311: _LL6415: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6420=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6420[ 0]=({ struct Cyc_Exp_tok_struct
_temp6421; _temp6421.tag= Cyc_Exp_tok; _temp6421.f1= Cyc_Absyn_and_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6422= yyvs; void** _temp6424= _temp6422.curr +(
yyvsp_offset - 2); if( _temp6422.base == 0? 1:( _temp6424 < _temp6422.base? 1:
_temp6424 >= _temp6422.last_plus_one)){ _throw( Null_Exception);}* _temp6424;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6425= yyvs; void** _temp6427=
_temp6425.curr + yyvsp_offset; if( _temp6425.base == 0? 1:( _temp6427 <
_temp6425.base? 1: _temp6427 >= _temp6425.last_plus_one)){ _throw(
Null_Exception);}* _temp6427;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6428= yyls; struct Cyc_Yyltype* _temp6430= _temp6428.curr +(
yylsp_offset - 2); if( _temp6428.base == 0? 1:( _temp6430 < _temp6428.base? 1:
_temp6430 >= _temp6428.last_plus_one)){ _throw( Null_Exception);}* _temp6430;}).first_line,({
struct _tagged_ptr3 _temp6431= yyls; struct Cyc_Yyltype* _temp6433= _temp6431.curr
+ yylsp_offset; if( _temp6431.base == 0? 1:( _temp6433 < _temp6431.base? 1:
_temp6433 >= _temp6431.last_plus_one)){ _throw( Null_Exception);}* _temp6433;}).last_line));
_temp6421;}); _temp6420;}); break; case 312: _LL6419: yyval=({ struct
_tagged_ptr2 _temp6435= yyvs; void** _temp6437= _temp6435.curr + yyvsp_offset;
if( _temp6435.base == 0? 1:( _temp6437 < _temp6435.base? 1: _temp6437 >=
_temp6435.last_plus_one)){ _throw( Null_Exception);}* _temp6437;}); break; case
313: _LL6434: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6439=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6439[ 0]=({ struct Cyc_Exp_tok_struct
_temp6440; _temp6440.tag= Cyc_Exp_tok; _temp6440.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Bitor, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6441= yyvs; void**
_temp6443= _temp6441.curr +( yyvsp_offset - 2); if( _temp6441.base == 0? 1:(
_temp6443 < _temp6441.base? 1: _temp6443 >= _temp6441.last_plus_one)){ _throw(
Null_Exception);}* _temp6443;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6444= yyvs; void** _temp6446= _temp6444.curr + yyvsp_offset; if( _temp6444.base
== 0? 1:( _temp6446 < _temp6444.base? 1: _temp6446 >= _temp6444.last_plus_one)){
_throw( Null_Exception);}* _temp6446;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6447= yyls; struct Cyc_Yyltype* _temp6449= _temp6447.curr +(
yylsp_offset - 2); if( _temp6447.base == 0? 1:( _temp6449 < _temp6447.base? 1:
_temp6449 >= _temp6447.last_plus_one)){ _throw( Null_Exception);}* _temp6449;}).first_line,({
struct _tagged_ptr3 _temp6450= yyls; struct Cyc_Yyltype* _temp6452= _temp6450.curr
+ yylsp_offset; if( _temp6450.base == 0? 1:( _temp6452 < _temp6450.base? 1:
_temp6452 >= _temp6450.last_plus_one)){ _throw( Null_Exception);}* _temp6452;}).last_line));
_temp6440;}); _temp6439;}); break; case 314: _LL6438: yyval=({ struct
_tagged_ptr2 _temp6454= yyvs; void** _temp6456= _temp6454.curr + yyvsp_offset;
if( _temp6454.base == 0? 1:( _temp6456 < _temp6454.base? 1: _temp6456 >=
_temp6454.last_plus_one)){ _throw( Null_Exception);}* _temp6456;}); break; case
315: _LL6453: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6458=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6458[ 0]=({ struct Cyc_Exp_tok_struct
_temp6459; _temp6459.tag= Cyc_Exp_tok; _temp6459.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Bitxor, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6460= yyvs; void**
_temp6462= _temp6460.curr +( yyvsp_offset - 2); if( _temp6460.base == 0? 1:(
_temp6462 < _temp6460.base? 1: _temp6462 >= _temp6460.last_plus_one)){ _throw(
Null_Exception);}* _temp6462;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6463= yyvs; void** _temp6465= _temp6463.curr + yyvsp_offset; if( _temp6463.base
== 0? 1:( _temp6465 < _temp6463.base? 1: _temp6465 >= _temp6463.last_plus_one)){
_throw( Null_Exception);}* _temp6465;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6466= yyls; struct Cyc_Yyltype* _temp6468= _temp6466.curr +(
yylsp_offset - 2); if( _temp6466.base == 0? 1:( _temp6468 < _temp6466.base? 1:
_temp6468 >= _temp6466.last_plus_one)){ _throw( Null_Exception);}* _temp6468;}).first_line,({
struct _tagged_ptr3 _temp6469= yyls; struct Cyc_Yyltype* _temp6471= _temp6469.curr
+ yylsp_offset; if( _temp6469.base == 0? 1:( _temp6471 < _temp6469.base? 1:
_temp6471 >= _temp6469.last_plus_one)){ _throw( Null_Exception);}* _temp6471;}).last_line));
_temp6459;}); _temp6458;}); break; case 316: _LL6457: yyval=({ struct
_tagged_ptr2 _temp6473= yyvs; void** _temp6475= _temp6473.curr + yyvsp_offset;
if( _temp6473.base == 0? 1:( _temp6475 < _temp6473.base? 1: _temp6475 >=
_temp6473.last_plus_one)){ _throw( Null_Exception);}* _temp6475;}); break; case
317: _LL6472: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6477=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6477[ 0]=({ struct Cyc_Exp_tok_struct
_temp6478; _temp6478.tag= Cyc_Exp_tok; _temp6478.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Bitand, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6479= yyvs; void**
_temp6481= _temp6479.curr +( yyvsp_offset - 2); if( _temp6479.base == 0? 1:(
_temp6481 < _temp6479.base? 1: _temp6481 >= _temp6479.last_plus_one)){ _throw(
Null_Exception);}* _temp6481;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6482= yyvs; void** _temp6484= _temp6482.curr + yyvsp_offset; if( _temp6482.base
== 0? 1:( _temp6484 < _temp6482.base? 1: _temp6484 >= _temp6482.last_plus_one)){
_throw( Null_Exception);}* _temp6484;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6485= yyls; struct Cyc_Yyltype* _temp6487= _temp6485.curr +(
yylsp_offset - 2); if( _temp6485.base == 0? 1:( _temp6487 < _temp6485.base? 1:
_temp6487 >= _temp6485.last_plus_one)){ _throw( Null_Exception);}* _temp6487;}).first_line,({
struct _tagged_ptr3 _temp6488= yyls; struct Cyc_Yyltype* _temp6490= _temp6488.curr
+ yylsp_offset; if( _temp6488.base == 0? 1:( _temp6490 < _temp6488.base? 1:
_temp6490 >= _temp6488.last_plus_one)){ _throw( Null_Exception);}* _temp6490;}).last_line));
_temp6478;}); _temp6477;}); break; case 318: _LL6476: yyval=({ struct
_tagged_ptr2 _temp6492= yyvs; void** _temp6494= _temp6492.curr + yyvsp_offset;
if( _temp6492.base == 0? 1:( _temp6494 < _temp6492.base? 1: _temp6494 >=
_temp6492.last_plus_one)){ _throw( Null_Exception);}* _temp6494;}); break; case
319: _LL6491: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6496=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6496[ 0]=({ struct Cyc_Exp_tok_struct
_temp6497; _temp6497.tag= Cyc_Exp_tok; _temp6497.f1= Cyc_Absyn_eq_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6498= yyvs; void** _temp6500= _temp6498.curr +(
yyvsp_offset - 2); if( _temp6498.base == 0? 1:( _temp6500 < _temp6498.base? 1:
_temp6500 >= _temp6498.last_plus_one)){ _throw( Null_Exception);}* _temp6500;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6501= yyvs; void** _temp6503=
_temp6501.curr + yyvsp_offset; if( _temp6501.base == 0? 1:( _temp6503 <
_temp6501.base? 1: _temp6503 >= _temp6501.last_plus_one)){ _throw(
Null_Exception);}* _temp6503;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6504= yyls; struct Cyc_Yyltype* _temp6506= _temp6504.curr +(
yylsp_offset - 2); if( _temp6504.base == 0? 1:( _temp6506 < _temp6504.base? 1:
_temp6506 >= _temp6504.last_plus_one)){ _throw( Null_Exception);}* _temp6506;}).first_line,({
struct _tagged_ptr3 _temp6507= yyls; struct Cyc_Yyltype* _temp6509= _temp6507.curr
+ yylsp_offset; if( _temp6507.base == 0? 1:( _temp6509 < _temp6507.base? 1:
_temp6509 >= _temp6507.last_plus_one)){ _throw( Null_Exception);}* _temp6509;}).last_line));
_temp6497;}); _temp6496;}); break; case 320: _LL6495: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6511=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6511[ 0]=({ struct Cyc_Exp_tok_struct
_temp6512; _temp6512.tag= Cyc_Exp_tok; _temp6512.f1= Cyc_Absyn_neq_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6513= yyvs; void** _temp6515= _temp6513.curr +(
yyvsp_offset - 2); if( _temp6513.base == 0? 1:( _temp6515 < _temp6513.base? 1:
_temp6515 >= _temp6513.last_plus_one)){ _throw( Null_Exception);}* _temp6515;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6516= yyvs; void** _temp6518=
_temp6516.curr + yyvsp_offset; if( _temp6516.base == 0? 1:( _temp6518 <
_temp6516.base? 1: _temp6518 >= _temp6516.last_plus_one)){ _throw(
Null_Exception);}* _temp6518;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6519= yyls; struct Cyc_Yyltype* _temp6521= _temp6519.curr +(
yylsp_offset - 2); if( _temp6519.base == 0? 1:( _temp6521 < _temp6519.base? 1:
_temp6521 >= _temp6519.last_plus_one)){ _throw( Null_Exception);}* _temp6521;}).first_line,({
struct _tagged_ptr3 _temp6522= yyls; struct Cyc_Yyltype* _temp6524= _temp6522.curr
+ yylsp_offset; if( _temp6522.base == 0? 1:( _temp6524 < _temp6522.base? 1:
_temp6524 >= _temp6522.last_plus_one)){ _throw( Null_Exception);}* _temp6524;}).last_line));
_temp6512;}); _temp6511;}); break; case 321: _LL6510: yyval=({ struct
_tagged_ptr2 _temp6526= yyvs; void** _temp6528= _temp6526.curr + yyvsp_offset;
if( _temp6526.base == 0? 1:( _temp6528 < _temp6526.base? 1: _temp6528 >=
_temp6526.last_plus_one)){ _throw( Null_Exception);}* _temp6528;}); break; case
322: _LL6525: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6530=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6530[ 0]=({ struct Cyc_Exp_tok_struct
_temp6531; _temp6531.tag= Cyc_Exp_tok; _temp6531.f1= Cyc_Absyn_lt_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6532= yyvs; void** _temp6534= _temp6532.curr +(
yyvsp_offset - 2); if( _temp6532.base == 0? 1:( _temp6534 < _temp6532.base? 1:
_temp6534 >= _temp6532.last_plus_one)){ _throw( Null_Exception);}* _temp6534;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6535= yyvs; void** _temp6537=
_temp6535.curr + yyvsp_offset; if( _temp6535.base == 0? 1:( _temp6537 <
_temp6535.base? 1: _temp6537 >= _temp6535.last_plus_one)){ _throw(
Null_Exception);}* _temp6537;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6538= yyls; struct Cyc_Yyltype* _temp6540= _temp6538.curr +(
yylsp_offset - 2); if( _temp6538.base == 0? 1:( _temp6540 < _temp6538.base? 1:
_temp6540 >= _temp6538.last_plus_one)){ _throw( Null_Exception);}* _temp6540;}).first_line,({
struct _tagged_ptr3 _temp6541= yyls; struct Cyc_Yyltype* _temp6543= _temp6541.curr
+ yylsp_offset; if( _temp6541.base == 0? 1:( _temp6543 < _temp6541.base? 1:
_temp6543 >= _temp6541.last_plus_one)){ _throw( Null_Exception);}* _temp6543;}).last_line));
_temp6531;}); _temp6530;}); break; case 323: _LL6529: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6545=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6545[ 0]=({ struct Cyc_Exp_tok_struct
_temp6546; _temp6546.tag= Cyc_Exp_tok; _temp6546.f1= Cyc_Absyn_gt_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6547= yyvs; void** _temp6549= _temp6547.curr +(
yyvsp_offset - 2); if( _temp6547.base == 0? 1:( _temp6549 < _temp6547.base? 1:
_temp6549 >= _temp6547.last_plus_one)){ _throw( Null_Exception);}* _temp6549;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6550= yyvs; void** _temp6552=
_temp6550.curr + yyvsp_offset; if( _temp6550.base == 0? 1:( _temp6552 <
_temp6550.base? 1: _temp6552 >= _temp6550.last_plus_one)){ _throw(
Null_Exception);}* _temp6552;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6553= yyls; struct Cyc_Yyltype* _temp6555= _temp6553.curr +(
yylsp_offset - 2); if( _temp6553.base == 0? 1:( _temp6555 < _temp6553.base? 1:
_temp6555 >= _temp6553.last_plus_one)){ _throw( Null_Exception);}* _temp6555;}).first_line,({
struct _tagged_ptr3 _temp6556= yyls; struct Cyc_Yyltype* _temp6558= _temp6556.curr
+ yylsp_offset; if( _temp6556.base == 0? 1:( _temp6558 < _temp6556.base? 1:
_temp6558 >= _temp6556.last_plus_one)){ _throw( Null_Exception);}* _temp6558;}).last_line));
_temp6546;}); _temp6545;}); break; case 324: _LL6544: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6560=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6560[ 0]=({ struct Cyc_Exp_tok_struct
_temp6561; _temp6561.tag= Cyc_Exp_tok; _temp6561.f1= Cyc_Absyn_lte_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6562= yyvs; void** _temp6564= _temp6562.curr +(
yyvsp_offset - 2); if( _temp6562.base == 0? 1:( _temp6564 < _temp6562.base? 1:
_temp6564 >= _temp6562.last_plus_one)){ _throw( Null_Exception);}* _temp6564;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6565= yyvs; void** _temp6567=
_temp6565.curr + yyvsp_offset; if( _temp6565.base == 0? 1:( _temp6567 <
_temp6565.base? 1: _temp6567 >= _temp6565.last_plus_one)){ _throw(
Null_Exception);}* _temp6567;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6568= yyls; struct Cyc_Yyltype* _temp6570= _temp6568.curr +(
yylsp_offset - 2); if( _temp6568.base == 0? 1:( _temp6570 < _temp6568.base? 1:
_temp6570 >= _temp6568.last_plus_one)){ _throw( Null_Exception);}* _temp6570;}).first_line,({
struct _tagged_ptr3 _temp6571= yyls; struct Cyc_Yyltype* _temp6573= _temp6571.curr
+ yylsp_offset; if( _temp6571.base == 0? 1:( _temp6573 < _temp6571.base? 1:
_temp6573 >= _temp6571.last_plus_one)){ _throw( Null_Exception);}* _temp6573;}).last_line));
_temp6561;}); _temp6560;}); break; case 325: _LL6559: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6575=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6575[ 0]=({ struct Cyc_Exp_tok_struct
_temp6576; _temp6576.tag= Cyc_Exp_tok; _temp6576.f1= Cyc_Absyn_gte_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6577= yyvs; void** _temp6579= _temp6577.curr +(
yyvsp_offset - 2); if( _temp6577.base == 0? 1:( _temp6579 < _temp6577.base? 1:
_temp6579 >= _temp6577.last_plus_one)){ _throw( Null_Exception);}* _temp6579;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6580= yyvs; void** _temp6582=
_temp6580.curr + yyvsp_offset; if( _temp6580.base == 0? 1:( _temp6582 <
_temp6580.base? 1: _temp6582 >= _temp6580.last_plus_one)){ _throw(
Null_Exception);}* _temp6582;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6583= yyls; struct Cyc_Yyltype* _temp6585= _temp6583.curr +(
yylsp_offset - 2); if( _temp6583.base == 0? 1:( _temp6585 < _temp6583.base? 1:
_temp6585 >= _temp6583.last_plus_one)){ _throw( Null_Exception);}* _temp6585;}).first_line,({
struct _tagged_ptr3 _temp6586= yyls; struct Cyc_Yyltype* _temp6588= _temp6586.curr
+ yylsp_offset; if( _temp6586.base == 0? 1:( _temp6588 < _temp6586.base? 1:
_temp6588 >= _temp6586.last_plus_one)){ _throw( Null_Exception);}* _temp6588;}).last_line));
_temp6576;}); _temp6575;}); break; case 326: _LL6574: yyval=({ struct
_tagged_ptr2 _temp6590= yyvs; void** _temp6592= _temp6590.curr + yyvsp_offset;
if( _temp6590.base == 0? 1:( _temp6592 < _temp6590.base? 1: _temp6592 >=
_temp6590.last_plus_one)){ _throw( Null_Exception);}* _temp6592;}); break; case
327: _LL6589: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6594=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6594[ 0]=({ struct Cyc_Exp_tok_struct
_temp6595; _temp6595.tag= Cyc_Exp_tok; _temp6595.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Bitlshift, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6596= yyvs;
void** _temp6598= _temp6596.curr +( yyvsp_offset - 2); if( _temp6596.base == 0?
1:( _temp6598 < _temp6596.base? 1: _temp6598 >= _temp6596.last_plus_one)){
_throw( Null_Exception);}* _temp6598;})), Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp6599= yyvs; void** _temp6601= _temp6599.curr + yyvsp_offset;
if( _temp6599.base == 0? 1:( _temp6601 < _temp6599.base? 1: _temp6601 >=
_temp6599.last_plus_one)){ _throw( Null_Exception);}* _temp6601;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6602= yyls; struct Cyc_Yyltype* _temp6604= _temp6602.curr
+( yylsp_offset - 2); if( _temp6602.base == 0? 1:( _temp6604 < _temp6602.base? 1:
_temp6604 >= _temp6602.last_plus_one)){ _throw( Null_Exception);}* _temp6604;}).first_line,({
struct _tagged_ptr3 _temp6605= yyls; struct Cyc_Yyltype* _temp6607= _temp6605.curr
+ yylsp_offset; if( _temp6605.base == 0? 1:( _temp6607 < _temp6605.base? 1:
_temp6607 >= _temp6605.last_plus_one)){ _throw( Null_Exception);}* _temp6607;}).last_line));
_temp6595;}); _temp6594;}); break; case 328: _LL6593: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6609=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6609[ 0]=({ struct Cyc_Exp_tok_struct
_temp6610; _temp6610.tag= Cyc_Exp_tok; _temp6610.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Bitlrshift, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6611= yyvs;
void** _temp6613= _temp6611.curr +( yyvsp_offset - 2); if( _temp6611.base == 0?
1:( _temp6613 < _temp6611.base? 1: _temp6613 >= _temp6611.last_plus_one)){
_throw( Null_Exception);}* _temp6613;})), Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp6614= yyvs; void** _temp6616= _temp6614.curr + yyvsp_offset;
if( _temp6614.base == 0? 1:( _temp6616 < _temp6614.base? 1: _temp6616 >=
_temp6614.last_plus_one)){ _throw( Null_Exception);}* _temp6616;})), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6617= yyls; struct Cyc_Yyltype* _temp6619= _temp6617.curr
+( yylsp_offset - 2); if( _temp6617.base == 0? 1:( _temp6619 < _temp6617.base? 1:
_temp6619 >= _temp6617.last_plus_one)){ _throw( Null_Exception);}* _temp6619;}).first_line,({
struct _tagged_ptr3 _temp6620= yyls; struct Cyc_Yyltype* _temp6622= _temp6620.curr
+ yylsp_offset; if( _temp6620.base == 0? 1:( _temp6622 < _temp6620.base? 1:
_temp6622 >= _temp6620.last_plus_one)){ _throw( Null_Exception);}* _temp6622;}).last_line));
_temp6610;}); _temp6609;}); break; case 329: _LL6608: yyval=({ struct
_tagged_ptr2 _temp6624= yyvs; void** _temp6626= _temp6624.curr + yyvsp_offset;
if( _temp6624.base == 0? 1:( _temp6626 < _temp6624.base? 1: _temp6626 >=
_temp6624.last_plus_one)){ _throw( Null_Exception);}* _temp6626;}); break; case
330: _LL6623: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6628=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6628[ 0]=({ struct Cyc_Exp_tok_struct
_temp6629; _temp6629.tag= Cyc_Exp_tok; _temp6629.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Plus, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6630= yyvs; void**
_temp6632= _temp6630.curr +( yyvsp_offset - 2); if( _temp6630.base == 0? 1:(
_temp6632 < _temp6630.base? 1: _temp6632 >= _temp6630.last_plus_one)){ _throw(
Null_Exception);}* _temp6632;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6633= yyvs; void** _temp6635= _temp6633.curr + yyvsp_offset; if( _temp6633.base
== 0? 1:( _temp6635 < _temp6633.base? 1: _temp6635 >= _temp6633.last_plus_one)){
_throw( Null_Exception);}* _temp6635;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6636= yyls; struct Cyc_Yyltype* _temp6638= _temp6636.curr +(
yylsp_offset - 2); if( _temp6636.base == 0? 1:( _temp6638 < _temp6636.base? 1:
_temp6638 >= _temp6636.last_plus_one)){ _throw( Null_Exception);}* _temp6638;}).first_line,({
struct _tagged_ptr3 _temp6639= yyls; struct Cyc_Yyltype* _temp6641= _temp6639.curr
+ yylsp_offset; if( _temp6639.base == 0? 1:( _temp6641 < _temp6639.base? 1:
_temp6641 >= _temp6639.last_plus_one)){ _throw( Null_Exception);}* _temp6641;}).last_line));
_temp6629;}); _temp6628;}); break; case 331: _LL6627: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6643=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6643[ 0]=({ struct Cyc_Exp_tok_struct
_temp6644; _temp6644.tag= Cyc_Exp_tok; _temp6644.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Minus, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6645= yyvs; void**
_temp6647= _temp6645.curr +( yyvsp_offset - 2); if( _temp6645.base == 0? 1:(
_temp6647 < _temp6645.base? 1: _temp6647 >= _temp6645.last_plus_one)){ _throw(
Null_Exception);}* _temp6647;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6648= yyvs; void** _temp6650= _temp6648.curr + yyvsp_offset; if( _temp6648.base
== 0? 1:( _temp6650 < _temp6648.base? 1: _temp6650 >= _temp6648.last_plus_one)){
_throw( Null_Exception);}* _temp6650;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6651= yyls; struct Cyc_Yyltype* _temp6653= _temp6651.curr +(
yylsp_offset - 2); if( _temp6651.base == 0? 1:( _temp6653 < _temp6651.base? 1:
_temp6653 >= _temp6651.last_plus_one)){ _throw( Null_Exception);}* _temp6653;}).first_line,({
struct _tagged_ptr3 _temp6654= yyls; struct Cyc_Yyltype* _temp6656= _temp6654.curr
+ yylsp_offset; if( _temp6654.base == 0? 1:( _temp6656 < _temp6654.base? 1:
_temp6656 >= _temp6654.last_plus_one)){ _throw( Null_Exception);}* _temp6656;}).last_line));
_temp6644;}); _temp6643;}); break; case 332: _LL6642: yyval=({ struct
_tagged_ptr2 _temp6658= yyvs; void** _temp6660= _temp6658.curr + yyvsp_offset;
if( _temp6658.base == 0? 1:( _temp6660 < _temp6658.base? 1: _temp6660 >=
_temp6658.last_plus_one)){ _throw( Null_Exception);}* _temp6660;}); break; case
333: _LL6657: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6662=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6662[ 0]=({ struct Cyc_Exp_tok_struct
_temp6663; _temp6663.tag= Cyc_Exp_tok; _temp6663.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Times, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6664= yyvs; void**
_temp6666= _temp6664.curr +( yyvsp_offset - 2); if( _temp6664.base == 0? 1:(
_temp6666 < _temp6664.base? 1: _temp6666 >= _temp6664.last_plus_one)){ _throw(
Null_Exception);}* _temp6666;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6667= yyvs; void** _temp6669= _temp6667.curr + yyvsp_offset; if( _temp6667.base
== 0? 1:( _temp6669 < _temp6667.base? 1: _temp6669 >= _temp6667.last_plus_one)){
_throw( Null_Exception);}* _temp6669;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6670= yyls; struct Cyc_Yyltype* _temp6672= _temp6670.curr +(
yylsp_offset - 2); if( _temp6670.base == 0? 1:( _temp6672 < _temp6670.base? 1:
_temp6672 >= _temp6670.last_plus_one)){ _throw( Null_Exception);}* _temp6672;}).first_line,({
struct _tagged_ptr3 _temp6673= yyls; struct Cyc_Yyltype* _temp6675= _temp6673.curr
+ yylsp_offset; if( _temp6673.base == 0? 1:( _temp6675 < _temp6673.base? 1:
_temp6675 >= _temp6673.last_plus_one)){ _throw( Null_Exception);}* _temp6675;}).last_line));
_temp6663;}); _temp6662;}); break; case 334: _LL6661: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6677=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6677[ 0]=({ struct Cyc_Exp_tok_struct
_temp6678; _temp6678.tag= Cyc_Exp_tok; _temp6678.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Div, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6679= yyvs; void**
_temp6681= _temp6679.curr +( yyvsp_offset - 2); if( _temp6679.base == 0? 1:(
_temp6681 < _temp6679.base? 1: _temp6681 >= _temp6679.last_plus_one)){ _throw(
Null_Exception);}* _temp6681;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6682= yyvs; void** _temp6684= _temp6682.curr + yyvsp_offset; if( _temp6682.base
== 0? 1:( _temp6684 < _temp6682.base? 1: _temp6684 >= _temp6682.last_plus_one)){
_throw( Null_Exception);}* _temp6684;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6685= yyls; struct Cyc_Yyltype* _temp6687= _temp6685.curr +(
yylsp_offset - 2); if( _temp6685.base == 0? 1:( _temp6687 < _temp6685.base? 1:
_temp6687 >= _temp6685.last_plus_one)){ _throw( Null_Exception);}* _temp6687;}).first_line,({
struct _tagged_ptr3 _temp6688= yyls; struct Cyc_Yyltype* _temp6690= _temp6688.curr
+ yylsp_offset; if( _temp6688.base == 0? 1:( _temp6690 < _temp6688.base? 1:
_temp6690 >= _temp6688.last_plus_one)){ _throw( Null_Exception);}* _temp6690;}).last_line));
_temp6678;}); _temp6677;}); break; case 335: _LL6676: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6692=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6692[ 0]=({ struct Cyc_Exp_tok_struct
_temp6693; _temp6693.tag= Cyc_Exp_tok; _temp6693.f1= Cyc_Absyn_prim2_exp(( void*)
Cyc_Absyn_Mod, Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6694= yyvs; void**
_temp6696= _temp6694.curr +( yyvsp_offset - 2); if( _temp6694.base == 0? 1:(
_temp6696 < _temp6694.base? 1: _temp6696 >= _temp6694.last_plus_one)){ _throw(
Null_Exception);}* _temp6696;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6697= yyvs; void** _temp6699= _temp6697.curr + yyvsp_offset; if( _temp6697.base
== 0? 1:( _temp6699 < _temp6697.base? 1: _temp6699 >= _temp6697.last_plus_one)){
_throw( Null_Exception);}* _temp6699;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6700= yyls; struct Cyc_Yyltype* _temp6702= _temp6700.curr +(
yylsp_offset - 2); if( _temp6700.base == 0? 1:( _temp6702 < _temp6700.base? 1:
_temp6702 >= _temp6700.last_plus_one)){ _throw( Null_Exception);}* _temp6702;}).first_line,({
struct _tagged_ptr3 _temp6703= yyls; struct Cyc_Yyltype* _temp6705= _temp6703.curr
+ yylsp_offset; if( _temp6703.base == 0? 1:( _temp6705 < _temp6703.base? 1:
_temp6705 >= _temp6703.last_plus_one)){ _throw( Null_Exception);}* _temp6705;}).last_line));
_temp6693;}); _temp6692;}); break; case 336: _LL6691: yyval=({ struct
_tagged_ptr2 _temp6707= yyvs; void** _temp6709= _temp6707.curr + yyvsp_offset;
if( _temp6707.base == 0? 1:( _temp6709 < _temp6707.base? 1: _temp6709 >=
_temp6707.last_plus_one)){ _throw( Null_Exception);}* _temp6709;}); break; case
337: _LL6706: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6711=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6711[ 0]=({ struct Cyc_Exp_tok_struct
_temp6712; _temp6712.tag= Cyc_Exp_tok; _temp6712.f1= Cyc_Absyn_cast_exp((* Cyc_yyget_ParamDecl_tok(({
struct _tagged_ptr2 _temp6713= yyvs; void** _temp6715= _temp6713.curr +(
yyvsp_offset - 2); if( _temp6713.base == 0? 1:( _temp6715 < _temp6713.base? 1:
_temp6715 >= _temp6713.last_plus_one)){ _throw( Null_Exception);}* _temp6715;}))).f3,
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6716= yyvs; void** _temp6718=
_temp6716.curr + yyvsp_offset; if( _temp6716.base == 0? 1:( _temp6718 <
_temp6716.base? 1: _temp6718 >= _temp6716.last_plus_one)){ _throw(
Null_Exception);}* _temp6718;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6719= yyls; struct Cyc_Yyltype* _temp6721= _temp6719.curr +(
yylsp_offset - 3); if( _temp6719.base == 0? 1:( _temp6721 < _temp6719.base? 1:
_temp6721 >= _temp6719.last_plus_one)){ _throw( Null_Exception);}* _temp6721;}).first_line,({
struct _tagged_ptr3 _temp6722= yyls; struct Cyc_Yyltype* _temp6724= _temp6722.curr
+ yylsp_offset; if( _temp6722.base == 0? 1:( _temp6724 < _temp6722.base? 1:
_temp6724 >= _temp6722.last_plus_one)){ _throw( Null_Exception);}* _temp6724;}).last_line));
_temp6712;}); _temp6711;}); break; case 338: _LL6710: yyval=({ struct
_tagged_ptr2 _temp6726= yyvs; void** _temp6728= _temp6726.curr + yyvsp_offset;
if( _temp6726.base == 0? 1:( _temp6728 < _temp6726.base? 1: _temp6728 >=
_temp6726.last_plus_one)){ _throw( Null_Exception);}* _temp6728;}); break; case
339: _LL6725: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6730=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6730[ 0]=({ struct Cyc_Exp_tok_struct
_temp6731; _temp6731.tag= Cyc_Exp_tok; _temp6731.f1= Cyc_Absyn_pre_inc_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6732= yyvs; void** _temp6734= _temp6732.curr +
yyvsp_offset; if( _temp6732.base == 0? 1:( _temp6734 < _temp6732.base? 1:
_temp6734 >= _temp6732.last_plus_one)){ _throw( Null_Exception);}* _temp6734;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6735= yyls; struct Cyc_Yyltype*
_temp6737= _temp6735.curr +( yylsp_offset - 1); if( _temp6735.base == 0? 1:(
_temp6737 < _temp6735.base? 1: _temp6737 >= _temp6735.last_plus_one)){ _throw(
Null_Exception);}* _temp6737;}).first_line,({ struct _tagged_ptr3 _temp6738=
yyls; struct Cyc_Yyltype* _temp6740= _temp6738.curr + yylsp_offset; if(
_temp6738.base == 0? 1:( _temp6740 < _temp6738.base? 1: _temp6740 >= _temp6738.last_plus_one)){
_throw( Null_Exception);}* _temp6740;}).last_line)); _temp6731;}); _temp6730;});
break; case 340: _LL6729: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6742=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp6742[ 0]=({ struct Cyc_Exp_tok_struct _temp6743; _temp6743.tag= Cyc_Exp_tok;
_temp6743.f1= Cyc_Absyn_pre_dec_exp( Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6744= yyvs; void** _temp6746= _temp6744.curr + yyvsp_offset; if( _temp6744.base
== 0? 1:( _temp6746 < _temp6744.base? 1: _temp6746 >= _temp6744.last_plus_one)){
_throw( Null_Exception);}* _temp6746;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6747= yyls; struct Cyc_Yyltype* _temp6749= _temp6747.curr +(
yylsp_offset - 1); if( _temp6747.base == 0? 1:( _temp6749 < _temp6747.base? 1:
_temp6749 >= _temp6747.last_plus_one)){ _throw( Null_Exception);}* _temp6749;}).first_line,({
struct _tagged_ptr3 _temp6750= yyls; struct Cyc_Yyltype* _temp6752= _temp6750.curr
+ yylsp_offset; if( _temp6750.base == 0? 1:( _temp6752 < _temp6750.base? 1:
_temp6752 >= _temp6750.last_plus_one)){ _throw( Null_Exception);}* _temp6752;}).last_line));
_temp6743;}); _temp6742;}); break; case 341: _LL6741: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6754=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6754[ 0]=({ struct Cyc_Exp_tok_struct
_temp6755; _temp6755.tag= Cyc_Exp_tok; _temp6755.f1= Cyc_Absyn_address_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp6756= yyvs; void** _temp6758= _temp6756.curr +
yyvsp_offset; if( _temp6756.base == 0? 1:( _temp6758 < _temp6756.base? 1:
_temp6758 >= _temp6756.last_plus_one)){ _throw( Null_Exception);}* _temp6758;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6759= yyls; struct Cyc_Yyltype*
_temp6761= _temp6759.curr +( yylsp_offset - 1); if( _temp6759.base == 0? 1:(
_temp6761 < _temp6759.base? 1: _temp6761 >= _temp6759.last_plus_one)){ _throw(
Null_Exception);}* _temp6761;}).first_line,({ struct _tagged_ptr3 _temp6762=
yyls; struct Cyc_Yyltype* _temp6764= _temp6762.curr + yylsp_offset; if(
_temp6762.base == 0? 1:( _temp6764 < _temp6762.base? 1: _temp6764 >= _temp6762.last_plus_one)){
_throw( Null_Exception);}* _temp6764;}).last_line)); _temp6755;}); _temp6754;});
break; case 342: _LL6753: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6766=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp6766[ 0]=({ struct Cyc_Exp_tok_struct _temp6767; _temp6767.tag= Cyc_Exp_tok;
_temp6767.f1= Cyc_Absyn_deref_exp( Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6768= yyvs; void** _temp6770= _temp6768.curr + yyvsp_offset; if( _temp6768.base
== 0? 1:( _temp6770 < _temp6768.base? 1: _temp6770 >= _temp6768.last_plus_one)){
_throw( Null_Exception);}* _temp6770;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6771= yyls; struct Cyc_Yyltype* _temp6773= _temp6771.curr +(
yylsp_offset - 1); if( _temp6771.base == 0? 1:( _temp6773 < _temp6771.base? 1:
_temp6773 >= _temp6771.last_plus_one)){ _throw( Null_Exception);}* _temp6773;}).first_line,({
struct _tagged_ptr3 _temp6774= yyls; struct Cyc_Yyltype* _temp6776= _temp6774.curr
+ yylsp_offset; if( _temp6774.base == 0? 1:( _temp6776 < _temp6774.base? 1:
_temp6776 >= _temp6774.last_plus_one)){ _throw( Null_Exception);}* _temp6776;}).last_line));
_temp6767;}); _temp6766;}); break; case 343: _LL6765: yyval=({ struct
_tagged_ptr2 _temp6778= yyvs; void** _temp6780= _temp6778.curr + yyvsp_offset;
if( _temp6778.base == 0? 1:( _temp6780 < _temp6778.base? 1: _temp6780 >=
_temp6778.last_plus_one)){ _throw( Null_Exception);}* _temp6780;}); break; case
344: _LL6777: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6782=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6782[ 0]=({ struct Cyc_Exp_tok_struct
_temp6783; _temp6783.tag= Cyc_Exp_tok; _temp6783.f1= Cyc_Absyn_prim1_exp( Cyc_yyget_Primop_tok(({
struct _tagged_ptr2 _temp6784= yyvs; void** _temp6786= _temp6784.curr +(
yyvsp_offset - 1); if( _temp6784.base == 0? 1:( _temp6786 < _temp6784.base? 1:
_temp6786 >= _temp6784.last_plus_one)){ _throw( Null_Exception);}* _temp6786;})),
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6787= yyvs; void** _temp6789=
_temp6787.curr + yyvsp_offset; if( _temp6787.base == 0? 1:( _temp6789 <
_temp6787.base? 1: _temp6789 >= _temp6787.last_plus_one)){ _throw(
Null_Exception);}* _temp6789;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6790= yyls; struct Cyc_Yyltype* _temp6792= _temp6790.curr +(
yylsp_offset - 1); if( _temp6790.base == 0? 1:( _temp6792 < _temp6790.base? 1:
_temp6792 >= _temp6790.last_plus_one)){ _throw( Null_Exception);}* _temp6792;}).first_line,({
struct _tagged_ptr3 _temp6793= yyls; struct Cyc_Yyltype* _temp6795= _temp6793.curr
+ yylsp_offset; if( _temp6793.base == 0? 1:( _temp6795 < _temp6793.base? 1:
_temp6795 >= _temp6793.last_plus_one)){ _throw( Null_Exception);}* _temp6795;}).last_line));
_temp6783;}); _temp6782;}); break; case 345: _LL6781: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6797=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6797[ 0]=({ struct Cyc_Exp_tok_struct
_temp6798; _temp6798.tag= Cyc_Exp_tok; _temp6798.f1= Cyc_Absyn_sizeoftyp_exp((*
Cyc_yyget_ParamDecl_tok(({ struct _tagged_ptr2 _temp6799= yyvs; void** _temp6801=
_temp6799.curr +( yyvsp_offset - 1); if( _temp6799.base == 0? 1:( _temp6801 <
_temp6799.base? 1: _temp6801 >= _temp6799.last_plus_one)){ _throw(
Null_Exception);}* _temp6801;}))).f3, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6802= yyls; struct Cyc_Yyltype* _temp6804= _temp6802.curr +(
yylsp_offset - 3); if( _temp6802.base == 0? 1:( _temp6804 < _temp6802.base? 1:
_temp6804 >= _temp6802.last_plus_one)){ _throw( Null_Exception);}* _temp6804;}).first_line,({
struct _tagged_ptr3 _temp6805= yyls; struct Cyc_Yyltype* _temp6807= _temp6805.curr
+ yylsp_offset; if( _temp6805.base == 0? 1:( _temp6807 < _temp6805.base? 1:
_temp6807 >= _temp6805.last_plus_one)){ _throw( Null_Exception);}* _temp6807;}).last_line));
_temp6798;}); _temp6797;}); break; case 346: _LL6796: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6809=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6809[ 0]=({ struct Cyc_Exp_tok_struct
_temp6810; _temp6810.tag= Cyc_Exp_tok; _temp6810.f1= Cyc_Absyn_sizeofexp_exp(
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6811= yyvs; void** _temp6813=
_temp6811.curr + yyvsp_offset; if( _temp6811.base == 0? 1:( _temp6813 <
_temp6811.base? 1: _temp6813 >= _temp6811.last_plus_one)){ _throw(
Null_Exception);}* _temp6813;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6814= yyls; struct Cyc_Yyltype* _temp6816= _temp6814.curr +(
yylsp_offset - 1); if( _temp6814.base == 0? 1:( _temp6816 < _temp6814.base? 1:
_temp6816 >= _temp6814.last_plus_one)){ _throw( Null_Exception);}* _temp6816;}).first_line,({
struct _tagged_ptr3 _temp6817= yyls; struct Cyc_Yyltype* _temp6819= _temp6817.curr
+ yylsp_offset; if( _temp6817.base == 0? 1:( _temp6819 < _temp6817.base? 1:
_temp6819 >= _temp6817.last_plus_one)){ _throw( Null_Exception);}* _temp6819;}).last_line));
_temp6810;}); _temp6809;}); break; case 347: _LL6808: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6821=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6821[ 0]=({ struct Cyc_Exp_tok_struct
_temp6822; _temp6822.tag= Cyc_Exp_tok; _temp6822.f1= Cyc_Absyn_primop_exp( Cyc_yyget_Primop_tok(({
struct _tagged_ptr2 _temp6823= yyvs; void** _temp6825= _temp6823.curr +(
yyvsp_offset - 3); if( _temp6823.base == 0? 1:( _temp6825 < _temp6823.base? 1:
_temp6825 >= _temp6823.last_plus_one)){ _throw( Null_Exception);}* _temp6825;})),
Cyc_yyget_ExpList_tok(({ struct _tagged_ptr2 _temp6826= yyvs; void** _temp6828=
_temp6826.curr +( yyvsp_offset - 1); if( _temp6826.base == 0? 1:( _temp6828 <
_temp6826.base? 1: _temp6828 >= _temp6826.last_plus_one)){ _throw(
Null_Exception);}* _temp6828;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6829= yyls; struct Cyc_Yyltype* _temp6831= _temp6829.curr +(
yylsp_offset - 3); if( _temp6829.base == 0? 1:( _temp6831 < _temp6829.base? 1:
_temp6831 >= _temp6829.last_plus_one)){ _throw( Null_Exception);}* _temp6831;}).first_line,({
struct _tagged_ptr3 _temp6832= yyls; struct Cyc_Yyltype* _temp6834= _temp6832.curr
+ yylsp_offset; if( _temp6832.base == 0? 1:( _temp6834 < _temp6832.base? 1:
_temp6834 >= _temp6832.last_plus_one)){ _throw( Null_Exception);}* _temp6834;}).last_line));
_temp6822;}); _temp6821;}); break; case 348: _LL6820: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6836=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6836[ 0]=({ struct Cyc_Exp_tok_struct
_temp6837; _temp6837.tag= Cyc_Exp_tok; _temp6837.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_Malloc_e_struct* _temp6838=( struct Cyc_Absyn_Malloc_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Malloc_e_struct)); _temp6838[ 0]=({ struct
Cyc_Absyn_Malloc_e_struct _temp6839; _temp6839.tag= Cyc_Absyn_Malloc_e;
_temp6839.f1= 0; _temp6839.f2=( void*) Cyc_Parse_speclist2typ((* Cyc_yyget_QualSpecList_tok(({
struct _tagged_ptr2 _temp6840= yyvs; void** _temp6842= _temp6840.curr +(
yyvsp_offset - 2); if( _temp6840.base == 0? 1:( _temp6842 < _temp6840.base? 1:
_temp6842 >= _temp6840.last_plus_one)){ _throw( Null_Exception);}* _temp6842;}))).f2,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6843= yyls; struct Cyc_Yyltype*
_temp6845= _temp6843.curr +( yylsp_offset - 2); if( _temp6843.base == 0? 1:(
_temp6845 < _temp6843.base? 1: _temp6845 >= _temp6843.last_plus_one)){ _throw(
Null_Exception);}* _temp6845;}).first_line,({ struct _tagged_ptr3 _temp6846=
yyls; struct Cyc_Yyltype* _temp6848= _temp6846.curr +( yylsp_offset - 2); if(
_temp6846.base == 0? 1:( _temp6848 < _temp6846.base? 1: _temp6848 >= _temp6846.last_plus_one)){
_throw( Null_Exception);}* _temp6848;}).last_line)); _temp6839;}); _temp6838;}),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6849= yyls; struct Cyc_Yyltype*
_temp6851= _temp6849.curr +( yylsp_offset - 6); if( _temp6849.base == 0? 1:(
_temp6851 < _temp6849.base? 1: _temp6851 >= _temp6849.last_plus_one)){ _throw(
Null_Exception);}* _temp6851;}).first_line,({ struct _tagged_ptr3 _temp6852=
yyls; struct Cyc_Yyltype* _temp6854= _temp6852.curr + yylsp_offset; if(
_temp6852.base == 0? 1:( _temp6854 < _temp6852.base? 1: _temp6854 >= _temp6852.last_plus_one)){
_throw( Null_Exception);}* _temp6854;}).last_line)); _temp6837;}); _temp6836;});
break; case 349: _LL6835: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6856=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp6856[ 0]=({ struct Cyc_Exp_tok_struct _temp6857; _temp6857.tag= Cyc_Exp_tok;
_temp6857.f1= Cyc_Absyn_new_exp(( void*)({ struct Cyc_Absyn_Malloc_e_struct*
_temp6858=( struct Cyc_Absyn_Malloc_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Malloc_e_struct));
_temp6858[ 0]=({ struct Cyc_Absyn_Malloc_e_struct _temp6859; _temp6859.tag= Cyc_Absyn_Malloc_e;
_temp6859.f1=( struct Cyc_Absyn_Exp*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6860= yyvs; void** _temp6862= _temp6860.curr +( yyvsp_offset - 6); if(
_temp6860.base == 0? 1:( _temp6862 < _temp6860.base? 1: _temp6862 >= _temp6860.last_plus_one)){
_throw( Null_Exception);}* _temp6862;})); _temp6859.f2=( void*) Cyc_Parse_speclist2typ((*
Cyc_yyget_QualSpecList_tok(({ struct _tagged_ptr2 _temp6863= yyvs; void**
_temp6865= _temp6863.curr +( yyvsp_offset - 2); if( _temp6863.base == 0? 1:(
_temp6865 < _temp6863.base? 1: _temp6865 >= _temp6863.last_plus_one)){ _throw(
Null_Exception);}* _temp6865;}))).f2, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6866= yyls; struct Cyc_Yyltype* _temp6868= _temp6866.curr +(
yylsp_offset - 2); if( _temp6866.base == 0? 1:( _temp6868 < _temp6866.base? 1:
_temp6868 >= _temp6866.last_plus_one)){ _throw( Null_Exception);}* _temp6868;}).first_line,({
struct _tagged_ptr3 _temp6869= yyls; struct Cyc_Yyltype* _temp6871= _temp6869.curr
+( yylsp_offset - 2); if( _temp6869.base == 0? 1:( _temp6871 < _temp6869.base? 1:
_temp6871 >= _temp6869.last_plus_one)){ _throw( Null_Exception);}* _temp6871;}).last_line));
_temp6859;}); _temp6858;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp6872= yyls; struct Cyc_Yyltype* _temp6874= _temp6872.curr +( yylsp_offset -
8); if( _temp6872.base == 0? 1:( _temp6874 < _temp6872.base? 1: _temp6874 >=
_temp6872.last_plus_one)){ _throw( Null_Exception);}* _temp6874;}).first_line,({
struct _tagged_ptr3 _temp6875= yyls; struct Cyc_Yyltype* _temp6877= _temp6875.curr
+ yylsp_offset; if( _temp6875.base == 0? 1:( _temp6877 < _temp6875.base? 1:
_temp6877 >= _temp6875.last_plus_one)){ _throw( Null_Exception);}* _temp6877;}).last_line));
_temp6857;}); _temp6856;}); break; case 350: _LL6855: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6879=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6879[ 0]=({ struct Cyc_Primop_tok_struct
_temp6880; _temp6880.tag= Cyc_Primop_tok; _temp6880.f1=( void*)(( void*) Cyc_Absyn_Printf);
_temp6880;}); _temp6879;}); break; case 351: _LL6878: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6882=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6882[ 0]=({ struct Cyc_Primop_tok_struct
_temp6883; _temp6883.tag= Cyc_Primop_tok; _temp6883.f1=( void*)(( void*) Cyc_Absyn_Fprintf);
_temp6883;}); _temp6882;}); break; case 352: _LL6881: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6885=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6885[ 0]=({ struct Cyc_Primop_tok_struct
_temp6886; _temp6886.tag= Cyc_Primop_tok; _temp6886.f1=( void*)(( void*) Cyc_Absyn_Xprintf);
_temp6886;}); _temp6885;}); break; case 353: _LL6884: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6888=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6888[ 0]=({ struct Cyc_Primop_tok_struct
_temp6889; _temp6889.tag= Cyc_Primop_tok; _temp6889.f1=( void*)(( void*) Cyc_Absyn_Scanf);
_temp6889;}); _temp6888;}); break; case 354: _LL6887: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6891=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6891[ 0]=({ struct Cyc_Primop_tok_struct
_temp6892; _temp6892.tag= Cyc_Primop_tok; _temp6892.f1=( void*)(( void*) Cyc_Absyn_Fscanf);
_temp6892;}); _temp6891;}); break; case 355: _LL6890: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6894=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6894[ 0]=({ struct Cyc_Primop_tok_struct
_temp6895; _temp6895.tag= Cyc_Primop_tok; _temp6895.f1=( void*)(( void*) Cyc_Absyn_Sscanf);
_temp6895;}); _temp6894;}); break; case 356: _LL6893: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6897=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6897[ 0]=({ struct Cyc_Primop_tok_struct
_temp6898; _temp6898.tag= Cyc_Primop_tok; _temp6898.f1=( void*)(( void*) Cyc_Absyn_Bitnot);
_temp6898;}); _temp6897;}); break; case 357: _LL6896: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6900=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6900[ 0]=({ struct Cyc_Primop_tok_struct
_temp6901; _temp6901.tag= Cyc_Primop_tok; _temp6901.f1=( void*)(( void*) Cyc_Absyn_Not);
_temp6901;}); _temp6900;}); break; case 358: _LL6899: yyval=( void*)({ struct
Cyc_Primop_tok_struct* _temp6903=( struct Cyc_Primop_tok_struct*) GC_malloc(
sizeof( struct Cyc_Primop_tok_struct)); _temp6903[ 0]=({ struct Cyc_Primop_tok_struct
_temp6904; _temp6904.tag= Cyc_Primop_tok; _temp6904.f1=( void*)(( void*) Cyc_Absyn_Minus);
_temp6904;}); _temp6903;}); break; case 359: _LL6902: yyval=({ struct
_tagged_ptr2 _temp6906= yyvs; void** _temp6908= _temp6906.curr + yyvsp_offset;
if( _temp6906.base == 0? 1:( _temp6908 < _temp6906.base? 1: _temp6908 >=
_temp6906.last_plus_one)){ _throw( Null_Exception);}* _temp6908;}); break; case
360: _LL6905: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6910=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp6910[ 0]=({ struct Cyc_Exp_tok_struct
_temp6911; _temp6911.tag= Cyc_Exp_tok; _temp6911.f1= Cyc_Absyn_subscript_exp(
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6912= yyvs; void** _temp6914=
_temp6912.curr +( yyvsp_offset - 3); if( _temp6912.base == 0? 1:( _temp6914 <
_temp6912.base? 1: _temp6914 >= _temp6912.last_plus_one)){ _throw(
Null_Exception);}* _temp6914;})), Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp6915= yyvs; void** _temp6917= _temp6915.curr +( yyvsp_offset - 1); if(
_temp6915.base == 0? 1:( _temp6917 < _temp6915.base? 1: _temp6917 >= _temp6915.last_plus_one)){
_throw( Null_Exception);}* _temp6917;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6918= yyls; struct Cyc_Yyltype* _temp6920= _temp6918.curr +(
yylsp_offset - 3); if( _temp6918.base == 0? 1:( _temp6920 < _temp6918.base? 1:
_temp6920 >= _temp6918.last_plus_one)){ _throw( Null_Exception);}* _temp6920;}).first_line,({
struct _tagged_ptr3 _temp6921= yyls; struct Cyc_Yyltype* _temp6923= _temp6921.curr
+ yylsp_offset; if( _temp6921.base == 0? 1:( _temp6923 < _temp6921.base? 1:
_temp6923 >= _temp6921.last_plus_one)){ _throw( Null_Exception);}* _temp6923;}).last_line));
_temp6911;}); _temp6910;}); break; case 361: _LL6909: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6925=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6925[ 0]=({ struct Cyc_Exp_tok_struct
_temp6926; _temp6926.tag= Cyc_Exp_tok; _temp6926.f1= Cyc_Absyn_unknowncall_exp(
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6927= yyvs; void** _temp6929=
_temp6927.curr +( yyvsp_offset - 2); if( _temp6927.base == 0? 1:( _temp6929 <
_temp6927.base? 1: _temp6929 >= _temp6927.last_plus_one)){ _throw(
Null_Exception);}* _temp6929;})), 0, Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6930= yyls; struct Cyc_Yyltype* _temp6932= _temp6930.curr +(
yylsp_offset - 2); if( _temp6930.base == 0? 1:( _temp6932 < _temp6930.base? 1:
_temp6932 >= _temp6930.last_plus_one)){ _throw( Null_Exception);}* _temp6932;}).first_line,({
struct _tagged_ptr3 _temp6933= yyls; struct Cyc_Yyltype* _temp6935= _temp6933.curr
+ yylsp_offset; if( _temp6933.base == 0? 1:( _temp6935 < _temp6933.base? 1:
_temp6935 >= _temp6933.last_plus_one)){ _throw( Null_Exception);}* _temp6935;}).last_line));
_temp6926;}); _temp6925;}); break; case 362: _LL6924: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6937=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6937[ 0]=({ struct Cyc_Exp_tok_struct
_temp6938; _temp6938.tag= Cyc_Exp_tok; _temp6938.f1= Cyc_Absyn_unknowncall_exp(
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6939= yyvs; void** _temp6941=
_temp6939.curr +( yyvsp_offset - 3); if( _temp6939.base == 0? 1:( _temp6941 <
_temp6939.base? 1: _temp6941 >= _temp6939.last_plus_one)){ _throw(
Null_Exception);}* _temp6941;})), Cyc_yyget_ExpList_tok(({ struct _tagged_ptr2
_temp6942= yyvs; void** _temp6944= _temp6942.curr +( yyvsp_offset - 1); if(
_temp6942.base == 0? 1:( _temp6944 < _temp6942.base? 1: _temp6944 >= _temp6942.last_plus_one)){
_throw( Null_Exception);}* _temp6944;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp6945= yyls; struct Cyc_Yyltype* _temp6947= _temp6945.curr +(
yylsp_offset - 3); if( _temp6945.base == 0? 1:( _temp6947 < _temp6945.base? 1:
_temp6947 >= _temp6945.last_plus_one)){ _throw( Null_Exception);}* _temp6947;}).first_line,({
struct _tagged_ptr3 _temp6948= yyls; struct Cyc_Yyltype* _temp6950= _temp6948.curr
+ yylsp_offset; if( _temp6948.base == 0? 1:( _temp6950 < _temp6948.base? 1:
_temp6950 >= _temp6948.last_plus_one)){ _throw( Null_Exception);}* _temp6950;}).last_line));
_temp6938;}); _temp6937;}); break; case 363: _LL6936: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp6952=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp6952[ 0]=({ struct Cyc_Exp_tok_struct
_temp6953; _temp6953.tag= Cyc_Exp_tok; _temp6953.f1= Cyc_Absyn_structmember_exp(
Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp6954= yyvs; void** _temp6956=
_temp6954.curr +( yyvsp_offset - 2); if( _temp6954.base == 0? 1:( _temp6956 <
_temp6954.base? 1: _temp6956 >= _temp6954.last_plus_one)){ _throw(
Null_Exception);}* _temp6956;})),({ struct _tagged_string* _temp6957=( struct
_tagged_string*) GC_malloc( sizeof( struct _tagged_string) * 1); _temp6957[ 0]=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp6958= yyvs; void** _temp6960=
_temp6958.curr + yyvsp_offset; if( _temp6958.base == 0? 1:( _temp6960 <
_temp6958.base? 1: _temp6960 >= _temp6958.last_plus_one)){ _throw(
Null_Exception);}* _temp6960;})); _temp6957;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp6961= yyls; struct Cyc_Yyltype* _temp6963= _temp6961.curr
+( yylsp_offset - 2); if( _temp6961.base == 0? 1:( _temp6963 < _temp6961.base? 1:
_temp6963 >= _temp6961.last_plus_one)){ _throw( Null_Exception);}* _temp6963;}).first_line,({
struct _tagged_ptr3 _temp6964= yyls; struct Cyc_Yyltype* _temp6966= _temp6964.curr
+ yylsp_offset; if( _temp6964.base == 0? 1:( _temp6966 < _temp6964.base? 1:
_temp6966 >= _temp6964.last_plus_one)){ _throw( Null_Exception);}* _temp6966;}).last_line));
_temp6953;}); _temp6952;}); break; case 364: _LL6951: { struct _tuple1* q= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp7001= yyvs; void** _temp7003= _temp7001.curr +
yyvsp_offset; if( _temp7001.base == 0? 1:( _temp7003 < _temp7001.base? 1:
_temp7003 >= _temp7001.last_plus_one)){ _throw( Null_Exception);}* _temp7003;}));{
void* _temp6968=(* q).f1; struct Cyc_List_List* _temp6978; struct Cyc_List_List*
_temp6980; _LL6970: if( _temp6968 ==( void*) Cyc_Absyn_Loc_n){ goto _LL6971;}
else{ goto _LL6972;} _LL6972: if(( unsigned int) _temp6968 > 1u?*(( int*)
_temp6968) == Cyc_Absyn_Rel_n: 0){ _LL6979: _temp6978=( struct Cyc_List_List*)((
struct Cyc_Absyn_Rel_n_struct*) _temp6968)->f1; if( _temp6978 == 0){ goto
_LL6973;} else{ goto _LL6974;}} else{ goto _LL6974;} _LL6974: if(( unsigned int)
_temp6968 > 1u?*(( int*) _temp6968) == Cyc_Absyn_Abs_n: 0){ _LL6981: _temp6980=(
struct Cyc_List_List*)(( struct Cyc_Absyn_Abs_n_struct*) _temp6968)->f1; if(
_temp6980 == 0){ goto _LL6975;} else{ goto _LL6976;}} else{ goto _LL6976;}
_LL6976: goto _LL6977; _LL6971: goto _LL6969; _LL6973: goto _LL6969; _LL6975:
goto _LL6969; _LL6977: Cyc_Parse_err(( struct _tagged_string)({ char* _temp6982=(
char*)"struct field name is qualified"; struct _tagged_string _temp6983;
_temp6983.curr= _temp6982; _temp6983.base= _temp6982; _temp6983.last_plus_one=
_temp6982 + 31; _temp6983;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp6984= yyls; struct Cyc_Yyltype* _temp6986= _temp6984.curr + yylsp_offset;
if( _temp6984.base == 0? 1:( _temp6986 < _temp6984.base? 1: _temp6986 >=
_temp6984.last_plus_one)){ _throw( Null_Exception);}* _temp6986;}).first_line,({
struct _tagged_ptr3 _temp6987= yyls; struct Cyc_Yyltype* _temp6989= _temp6987.curr
+ yylsp_offset; if( _temp6987.base == 0? 1:( _temp6989 < _temp6987.base? 1:
_temp6989 >= _temp6987.last_plus_one)){ _throw( Null_Exception);}* _temp6989;}).last_line));
goto _LL6969; _LL6969:;} yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp6990=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp6990[ 0]=({ struct Cyc_Exp_tok_struct _temp6991; _temp6991.tag= Cyc_Exp_tok;
_temp6991.f1= Cyc_Absyn_structmember_exp( Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp6992= yyvs; void** _temp6994= _temp6992.curr +( yyvsp_offset -
2); if( _temp6992.base == 0? 1:( _temp6994 < _temp6992.base? 1: _temp6994 >=
_temp6992.last_plus_one)){ _throw( Null_Exception);}* _temp6994;})),(* q).f2,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp6995= yyls; struct Cyc_Yyltype*
_temp6997= _temp6995.curr +( yylsp_offset - 2); if( _temp6995.base == 0? 1:(
_temp6997 < _temp6995.base? 1: _temp6997 >= _temp6995.last_plus_one)){ _throw(
Null_Exception);}* _temp6997;}).first_line,({ struct _tagged_ptr3 _temp6998=
yyls; struct Cyc_Yyltype* _temp7000= _temp6998.curr + yylsp_offset; if(
_temp6998.base == 0? 1:( _temp7000 < _temp6998.base? 1: _temp7000 >= _temp6998.last_plus_one)){
_throw( Null_Exception);}* _temp7000;}).last_line)); _temp6991;}); _temp6990;});
break;} case 365: _LL6967: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7005=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7005[ 0]=({ struct Cyc_Exp_tok_struct _temp7006; _temp7006.tag= Cyc_Exp_tok;
_temp7006.f1= Cyc_Absyn_structarrow_exp( Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp7007= yyvs; void** _temp7009= _temp7007.curr +( yyvsp_offset -
2); if( _temp7007.base == 0? 1:( _temp7009 < _temp7007.base? 1: _temp7009 >=
_temp7007.last_plus_one)){ _throw( Null_Exception);}* _temp7009;})),({ struct
_tagged_string* _temp7010=( struct _tagged_string*) GC_malloc( sizeof( struct
_tagged_string) * 1); _temp7010[ 0]= Cyc_yyget_String_tok(({ struct _tagged_ptr2
_temp7011= yyvs; void** _temp7013= _temp7011.curr + yyvsp_offset; if( _temp7011.base
== 0? 1:( _temp7013 < _temp7011.base? 1: _temp7013 >= _temp7011.last_plus_one)){
_throw( Null_Exception);}* _temp7013;})); _temp7010;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7014= yyls; struct Cyc_Yyltype* _temp7016= _temp7014.curr
+( yylsp_offset - 2); if( _temp7014.base == 0? 1:( _temp7016 < _temp7014.base? 1:
_temp7016 >= _temp7014.last_plus_one)){ _throw( Null_Exception);}* _temp7016;}).first_line,({
struct _tagged_ptr3 _temp7017= yyls; struct Cyc_Yyltype* _temp7019= _temp7017.curr
+ yylsp_offset; if( _temp7017.base == 0? 1:( _temp7019 < _temp7017.base? 1:
_temp7019 >= _temp7017.last_plus_one)){ _throw( Null_Exception);}* _temp7019;}).last_line));
_temp7006;}); _temp7005;}); break; case 366: _LL7004: { struct _tuple1* q= Cyc_yyget_QualId_tok(({
struct _tagged_ptr2 _temp7054= yyvs; void** _temp7056= _temp7054.curr +
yyvsp_offset; if( _temp7054.base == 0? 1:( _temp7056 < _temp7054.base? 1:
_temp7056 >= _temp7054.last_plus_one)){ _throw( Null_Exception);}* _temp7056;}));{
void* _temp7021=(* q).f1; struct Cyc_List_List* _temp7031; struct Cyc_List_List*
_temp7033; _LL7023: if( _temp7021 ==( void*) Cyc_Absyn_Loc_n){ goto _LL7024;}
else{ goto _LL7025;} _LL7025: if(( unsigned int) _temp7021 > 1u?*(( int*)
_temp7021) == Cyc_Absyn_Rel_n: 0){ _LL7032: _temp7031=( struct Cyc_List_List*)((
struct Cyc_Absyn_Rel_n_struct*) _temp7021)->f1; if( _temp7031 == 0){ goto
_LL7026;} else{ goto _LL7027;}} else{ goto _LL7027;} _LL7027: if(( unsigned int)
_temp7021 > 1u?*(( int*) _temp7021) == Cyc_Absyn_Abs_n: 0){ _LL7034: _temp7033=(
struct Cyc_List_List*)(( struct Cyc_Absyn_Abs_n_struct*) _temp7021)->f1; if(
_temp7033 == 0){ goto _LL7028;} else{ goto _LL7029;}} else{ goto _LL7029;}
_LL7029: goto _LL7030; _LL7024: goto _LL7022; _LL7026: goto _LL7022; _LL7028:
goto _LL7022; _LL7030: Cyc_Parse_err(( struct _tagged_string)({ char* _temp7035=(
char*)"struct field is qualified with module name"; struct _tagged_string
_temp7036; _temp7036.curr= _temp7035; _temp7036.base= _temp7035; _temp7036.last_plus_one=
_temp7035 + 43; _temp7036;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp7037= yyls; struct Cyc_Yyltype* _temp7039= _temp7037.curr + yylsp_offset;
if( _temp7037.base == 0? 1:( _temp7039 < _temp7037.base? 1: _temp7039 >=
_temp7037.last_plus_one)){ _throw( Null_Exception);}* _temp7039;}).first_line,({
struct _tagged_ptr3 _temp7040= yyls; struct Cyc_Yyltype* _temp7042= _temp7040.curr
+ yylsp_offset; if( _temp7040.base == 0? 1:( _temp7042 < _temp7040.base? 1:
_temp7042 >= _temp7040.last_plus_one)){ _throw( Null_Exception);}* _temp7042;}).last_line));
goto _LL7022; _LL7022:;} yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7043=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7043[ 0]=({ struct Cyc_Exp_tok_struct _temp7044; _temp7044.tag= Cyc_Exp_tok;
_temp7044.f1= Cyc_Absyn_structarrow_exp( Cyc_yyget_Exp_tok(({ struct
_tagged_ptr2 _temp7045= yyvs; void** _temp7047= _temp7045.curr +( yyvsp_offset -
2); if( _temp7045.base == 0? 1:( _temp7047 < _temp7045.base? 1: _temp7047 >=
_temp7045.last_plus_one)){ _throw( Null_Exception);}* _temp7047;})),(* q).f2,
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp7048= yyls; struct Cyc_Yyltype*
_temp7050= _temp7048.curr +( yylsp_offset - 2); if( _temp7048.base == 0? 1:(
_temp7050 < _temp7048.base? 1: _temp7050 >= _temp7048.last_plus_one)){ _throw(
Null_Exception);}* _temp7050;}).first_line,({ struct _tagged_ptr3 _temp7051=
yyls; struct Cyc_Yyltype* _temp7053= _temp7051.curr + yylsp_offset; if(
_temp7051.base == 0? 1:( _temp7053 < _temp7051.base? 1: _temp7053 >= _temp7051.last_plus_one)){
_throw( Null_Exception);}* _temp7053;}).last_line)); _temp7044;}); _temp7043;});
break;} case 367: _LL7020: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7058=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7058[ 0]=({ struct Cyc_Exp_tok_struct _temp7059; _temp7059.tag= Cyc_Exp_tok;
_temp7059.f1= Cyc_Absyn_post_inc_exp( Cyc_yyget_Exp_tok(({ struct _tagged_ptr2
_temp7060= yyvs; void** _temp7062= _temp7060.curr +( yyvsp_offset - 1); if(
_temp7060.base == 0? 1:( _temp7062 < _temp7060.base? 1: _temp7062 >= _temp7060.last_plus_one)){
_throw( Null_Exception);}* _temp7062;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp7063= yyls; struct Cyc_Yyltype* _temp7065= _temp7063.curr +(
yylsp_offset - 1); if( _temp7063.base == 0? 1:( _temp7065 < _temp7063.base? 1:
_temp7065 >= _temp7063.last_plus_one)){ _throw( Null_Exception);}* _temp7065;}).first_line,({
struct _tagged_ptr3 _temp7066= yyls; struct Cyc_Yyltype* _temp7068= _temp7066.curr
+ yylsp_offset; if( _temp7066.base == 0? 1:( _temp7068 < _temp7066.base? 1:
_temp7068 >= _temp7066.last_plus_one)){ _throw( Null_Exception);}* _temp7068;}).last_line));
_temp7059;}); _temp7058;}); break; case 368: _LL7057: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7070=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7070[ 0]=({ struct Cyc_Exp_tok_struct
_temp7071; _temp7071.tag= Cyc_Exp_tok; _temp7071.f1= Cyc_Absyn_post_dec_exp( Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp7072= yyvs; void** _temp7074= _temp7072.curr +(
yyvsp_offset - 1); if( _temp7072.base == 0? 1:( _temp7074 < _temp7072.base? 1:
_temp7074 >= _temp7072.last_plus_one)){ _throw( Null_Exception);}* _temp7074;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp7075= yyls; struct Cyc_Yyltype*
_temp7077= _temp7075.curr +( yylsp_offset - 1); if( _temp7075.base == 0? 1:(
_temp7077 < _temp7075.base? 1: _temp7077 >= _temp7075.last_plus_one)){ _throw(
Null_Exception);}* _temp7077;}).first_line,({ struct _tagged_ptr3 _temp7078=
yyls; struct Cyc_Yyltype* _temp7080= _temp7078.curr + yylsp_offset; if(
_temp7078.base == 0? 1:( _temp7080 < _temp7078.base? 1: _temp7080 >= _temp7078.last_plus_one)){
_throw( Null_Exception);}* _temp7080;}).last_line)); _temp7071;}); _temp7070;});
break; case 369: _LL7069: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7082=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7082[ 0]=({ struct Cyc_Exp_tok_struct _temp7083; _temp7083.tag= Cyc_Exp_tok;
_temp7083.f1= Cyc_Absyn_new_exp(( void*)({ struct Cyc_Absyn_CompoundLit_e_struct*
_temp7084=( struct Cyc_Absyn_CompoundLit_e_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_CompoundLit_e_struct)); _temp7084[ 0]=({ struct Cyc_Absyn_CompoundLit_e_struct
_temp7085; _temp7085.tag= Cyc_Absyn_CompoundLit_e; _temp7085.f1= Cyc_yyget_ParamDecl_tok(({
struct _tagged_ptr2 _temp7086= yyvs; void** _temp7088= _temp7086.curr +(
yyvsp_offset - 4); if( _temp7086.base == 0? 1:( _temp7088 < _temp7086.base? 1:
_temp7088 >= _temp7086.last_plus_one)){ _throw( Null_Exception);}* _temp7088;}));
_temp7085.f2=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
Cyc_yyget_InitializerList_tok(({ struct _tagged_ptr2 _temp7089= yyvs; void**
_temp7091= _temp7089.curr +( yyvsp_offset - 1); if( _temp7089.base == 0? 1:(
_temp7091 < _temp7089.base? 1: _temp7091 >= _temp7089.last_plus_one)){ _throw(
Null_Exception);}* _temp7091;}))); _temp7085;}); _temp7084;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7092= yyls; struct Cyc_Yyltype* _temp7094= _temp7092.curr
+( yylsp_offset - 5); if( _temp7092.base == 0? 1:( _temp7094 < _temp7092.base? 1:
_temp7094 >= _temp7092.last_plus_one)){ _throw( Null_Exception);}* _temp7094;}).first_line,({
struct _tagged_ptr3 _temp7095= yyls; struct Cyc_Yyltype* _temp7097= _temp7095.curr
+ yylsp_offset; if( _temp7095.base == 0? 1:( _temp7097 < _temp7095.base? 1:
_temp7097 >= _temp7095.last_plus_one)){ _throw( Null_Exception);}* _temp7097;}).last_line));
_temp7083;}); _temp7082;}); break; case 370: _LL7081: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7099=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7099[ 0]=({ struct Cyc_Exp_tok_struct
_temp7100; _temp7100.tag= Cyc_Exp_tok; _temp7100.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_CompoundLit_e_struct* _temp7101=( struct Cyc_Absyn_CompoundLit_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_CompoundLit_e_struct)); _temp7101[ 0]=({
struct Cyc_Absyn_CompoundLit_e_struct _temp7102; _temp7102.tag= Cyc_Absyn_CompoundLit_e;
_temp7102.f1= Cyc_yyget_ParamDecl_tok(({ struct _tagged_ptr2 _temp7103= yyvs;
void** _temp7105= _temp7103.curr +( yyvsp_offset - 5); if( _temp7103.base == 0?
1:( _temp7105 < _temp7103.base? 1: _temp7105 >= _temp7103.last_plus_one)){
_throw( Null_Exception);}* _temp7105;})); _temp7102.f2=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_InitializerList_tok(({
struct _tagged_ptr2 _temp7106= yyvs; void** _temp7108= _temp7106.curr +(
yyvsp_offset - 2); if( _temp7106.base == 0? 1:( _temp7108 < _temp7106.base? 1:
_temp7108 >= _temp7106.last_plus_one)){ _throw( Null_Exception);}* _temp7108;})));
_temp7102;}); _temp7101;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp7109= yyls; struct Cyc_Yyltype* _temp7111= _temp7109.curr +( yylsp_offset -
6); if( _temp7109.base == 0? 1:( _temp7111 < _temp7109.base? 1: _temp7111 >=
_temp7109.last_plus_one)){ _throw( Null_Exception);}* _temp7111;}).first_line,({
struct _tagged_ptr3 _temp7112= yyls; struct Cyc_Yyltype* _temp7114= _temp7112.curr
+ yylsp_offset; if( _temp7112.base == 0? 1:( _temp7114 < _temp7112.base? 1:
_temp7114 >= _temp7112.last_plus_one)){ _throw( Null_Exception);}* _temp7114;}).last_line));
_temp7100;}); _temp7099;}); break; case 371: _LL7098: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7116=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7116[ 0]=({ struct Cyc_Exp_tok_struct
_temp7117; _temp7117.tag= Cyc_Exp_tok; _temp7117.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_Fill_e_struct* _temp7118=( struct Cyc_Absyn_Fill_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Fill_e_struct)); _temp7118[ 0]=({ struct Cyc_Absyn_Fill_e_struct
_temp7119; _temp7119.tag= Cyc_Absyn_Fill_e; _temp7119.f1= Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp7120= yyvs; void** _temp7122= _temp7120.curr +(
yyvsp_offset - 1); if( _temp7120.base == 0? 1:( _temp7122 < _temp7120.base? 1:
_temp7122 >= _temp7120.last_plus_one)){ _throw( Null_Exception);}* _temp7122;}));
_temp7119;}); _temp7118;}), Cyc_Position_segment_of_abs(({ struct _tagged_ptr3
_temp7123= yyls; struct Cyc_Yyltype* _temp7125= _temp7123.curr +( yylsp_offset -
3); if( _temp7123.base == 0? 1:( _temp7125 < _temp7123.base? 1: _temp7125 >=
_temp7123.last_plus_one)){ _throw( Null_Exception);}* _temp7125;}).first_line,({
struct _tagged_ptr3 _temp7126= yyls; struct Cyc_Yyltype* _temp7128= _temp7126.curr
+ yylsp_offset; if( _temp7126.base == 0? 1:( _temp7128 < _temp7126.base? 1:
_temp7128 >= _temp7126.last_plus_one)){ _throw( Null_Exception);}* _temp7128;}).last_line));
_temp7117;}); _temp7116;}); break; case 372: _LL7115: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7130=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7130[ 0]=({ struct Cyc_Exp_tok_struct
_temp7131; _temp7131.tag= Cyc_Exp_tok; _temp7131.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_Codegen_e_struct* _temp7132=( struct Cyc_Absyn_Codegen_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Codegen_e_struct)); _temp7132[ 0]=({ struct
Cyc_Absyn_Codegen_e_struct _temp7133; _temp7133.tag= Cyc_Absyn_Codegen_e;
_temp7133.f1= Cyc_yyget_FnDecl_tok(({ struct _tagged_ptr2 _temp7134= yyvs; void**
_temp7136= _temp7134.curr +( yyvsp_offset - 1); if( _temp7134.base == 0? 1:(
_temp7136 < _temp7134.base? 1: _temp7136 >= _temp7134.last_plus_one)){ _throw(
Null_Exception);}* _temp7136;})); _temp7133;}); _temp7132;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7137= yyls; struct Cyc_Yyltype* _temp7139= _temp7137.curr
+( yylsp_offset - 3); if( _temp7137.base == 0? 1:( _temp7139 < _temp7137.base? 1:
_temp7139 >= _temp7137.last_plus_one)){ _throw( Null_Exception);}* _temp7139;}).first_line,({
struct _tagged_ptr3 _temp7140= yyls; struct Cyc_Yyltype* _temp7142= _temp7140.curr
+ yylsp_offset; if( _temp7140.base == 0? 1:( _temp7142 < _temp7140.base? 1:
_temp7142 >= _temp7140.last_plus_one)){ _throw( Null_Exception);}* _temp7142;}).last_line));
_temp7131;}); _temp7130;}); break; case 373: _LL7129: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7144=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7144[ 0]=({ struct Cyc_Exp_tok_struct
_temp7145; _temp7145.tag= Cyc_Exp_tok; _temp7145.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_UnknownId_e_struct* _temp7146=( struct Cyc_Absyn_UnknownId_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_UnknownId_e_struct)); _temp7146[ 0]=({
struct Cyc_Absyn_UnknownId_e_struct _temp7147; _temp7147.tag= Cyc_Absyn_UnknownId_e;
_temp7147.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp7148= yyvs; void**
_temp7150= _temp7148.curr + yyvsp_offset; if( _temp7148.base == 0? 1:( _temp7150
< _temp7148.base? 1: _temp7150 >= _temp7148.last_plus_one)){ _throw(
Null_Exception);}* _temp7150;})); _temp7147;}); _temp7146;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7151= yyls; struct Cyc_Yyltype* _temp7153= _temp7151.curr
+ yylsp_offset; if( _temp7151.base == 0? 1:( _temp7153 < _temp7151.base? 1:
_temp7153 >= _temp7151.last_plus_one)){ _throw( Null_Exception);}* _temp7153;}).first_line,({
struct _tagged_ptr3 _temp7154= yyls; struct Cyc_Yyltype* _temp7156= _temp7154.curr
+ yylsp_offset; if( _temp7154.base == 0? 1:( _temp7156 < _temp7154.base? 1:
_temp7156 >= _temp7154.last_plus_one)){ _throw( Null_Exception);}* _temp7156;}).last_line));
_temp7145;}); _temp7144;}); break; case 374: _LL7143: yyval=({ struct
_tagged_ptr2 _temp7158= yyvs; void** _temp7160= _temp7158.curr + yyvsp_offset;
if( _temp7158.base == 0? 1:( _temp7160 < _temp7158.base? 1: _temp7160 >=
_temp7158.last_plus_one)){ _throw( Null_Exception);}* _temp7160;}); break; case
375: _LL7157: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7162=( struct Cyc_Exp_tok_struct*)
GC_malloc( sizeof( struct Cyc_Exp_tok_struct)); _temp7162[ 0]=({ struct Cyc_Exp_tok_struct
_temp7163; _temp7163.tag= Cyc_Exp_tok; _temp7163.f1= Cyc_Absyn_string_exp( Cyc_yyget_String_tok(({
struct _tagged_ptr2 _temp7164= yyvs; void** _temp7166= _temp7164.curr +
yyvsp_offset; if( _temp7164.base == 0? 1:( _temp7166 < _temp7164.base? 1:
_temp7166 >= _temp7164.last_plus_one)){ _throw( Null_Exception);}* _temp7166;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp7167= yyls; struct Cyc_Yyltype*
_temp7169= _temp7167.curr + yylsp_offset; if( _temp7167.base == 0? 1:( _temp7169
< _temp7167.base? 1: _temp7169 >= _temp7167.last_plus_one)){ _throw(
Null_Exception);}* _temp7169;}).first_line,({ struct _tagged_ptr3 _temp7170=
yyls; struct Cyc_Yyltype* _temp7172= _temp7170.curr + yylsp_offset; if(
_temp7170.base == 0? 1:( _temp7172 < _temp7170.base? 1: _temp7172 >= _temp7170.last_plus_one)){
_throw( Null_Exception);}* _temp7172;}).last_line)); _temp7163;}); _temp7162;});
break; case 376: _LL7161: yyval=({ struct _tagged_ptr2 _temp7174= yyvs; void**
_temp7176= _temp7174.curr +( yyvsp_offset - 1); if( _temp7174.base == 0? 1:(
_temp7176 < _temp7174.base? 1: _temp7176 >= _temp7174.last_plus_one)){ _throw(
Null_Exception);}* _temp7176;}); break; case 377: _LL7173: yyval=( void*)({
struct Cyc_Exp_tok_struct* _temp7178=( struct Cyc_Exp_tok_struct*) GC_malloc(
sizeof( struct Cyc_Exp_tok_struct)); _temp7178[ 0]=({ struct Cyc_Exp_tok_struct
_temp7179; _temp7179.tag= Cyc_Exp_tok; _temp7179.f1= Cyc_Absyn_noinstantiate_exp(
Cyc_Absyn_new_exp(( void*)({ struct Cyc_Absyn_UnknownId_e_struct* _temp7180=(
struct Cyc_Absyn_UnknownId_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_UnknownId_e_struct));
_temp7180[ 0]=({ struct Cyc_Absyn_UnknownId_e_struct _temp7181; _temp7181.tag=
Cyc_Absyn_UnknownId_e; _temp7181.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2
_temp7182= yyvs; void** _temp7184= _temp7182.curr +( yyvsp_offset - 1); if(
_temp7182.base == 0? 1:( _temp7184 < _temp7182.base? 1: _temp7184 >= _temp7182.last_plus_one)){
_throw( Null_Exception);}* _temp7184;})); _temp7181;}); _temp7180;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7185= yyls; struct Cyc_Yyltype* _temp7187= _temp7185.curr
+( yylsp_offset - 1); if( _temp7185.base == 0? 1:( _temp7187 < _temp7185.base? 1:
_temp7187 >= _temp7185.last_plus_one)){ _throw( Null_Exception);}* _temp7187;}).first_line,({
struct _tagged_ptr3 _temp7188= yyls; struct Cyc_Yyltype* _temp7190= _temp7188.curr
+( yylsp_offset - 1); if( _temp7188.base == 0? 1:( _temp7190 < _temp7188.base? 1:
_temp7190 >= _temp7188.last_plus_one)){ _throw( Null_Exception);}* _temp7190;}).last_line)),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp7191= yyls; struct Cyc_Yyltype*
_temp7193= _temp7191.curr +( yylsp_offset - 1); if( _temp7191.base == 0? 1:(
_temp7193 < _temp7191.base? 1: _temp7193 >= _temp7191.last_plus_one)){ _throw(
Null_Exception);}* _temp7193;}).first_line,({ struct _tagged_ptr3 _temp7194=
yyls; struct Cyc_Yyltype* _temp7196= _temp7194.curr + yylsp_offset; if(
_temp7194.base == 0? 1:( _temp7196 < _temp7194.base? 1: _temp7196 >= _temp7194.last_plus_one)){
_throw( Null_Exception);}* _temp7196;}).last_line)); _temp7179;}); _temp7178;});
break; case 378: _LL7177: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7198=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7198[ 0]=({ struct Cyc_Exp_tok_struct _temp7199; _temp7199.tag= Cyc_Exp_tok;
_temp7199.f1= Cyc_Absyn_instantiate_exp( Cyc_Absyn_new_exp(( void*)({ struct Cyc_Absyn_UnknownId_e_struct*
_temp7200=( struct Cyc_Absyn_UnknownId_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_UnknownId_e_struct));
_temp7200[ 0]=({ struct Cyc_Absyn_UnknownId_e_struct _temp7201; _temp7201.tag=
Cyc_Absyn_UnknownId_e; _temp7201.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2
_temp7202= yyvs; void** _temp7204= _temp7202.curr +( yyvsp_offset - 4); if(
_temp7202.base == 0? 1:( _temp7204 < _temp7202.base? 1: _temp7204 >= _temp7202.last_plus_one)){
_throw( Null_Exception);}* _temp7204;})); _temp7201;}); _temp7200;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7205= yyls; struct Cyc_Yyltype* _temp7207= _temp7205.curr
+( yylsp_offset - 4); if( _temp7205.base == 0? 1:( _temp7207 < _temp7205.base? 1:
_temp7207 >= _temp7205.last_plus_one)){ _throw( Null_Exception);}* _temp7207;}).first_line,({
struct _tagged_ptr3 _temp7208= yyls; struct Cyc_Yyltype* _temp7210= _temp7208.curr
+( yylsp_offset - 4); if( _temp7208.base == 0? 1:( _temp7210 < _temp7208.base? 1:
_temp7210 >= _temp7208.last_plus_one)){ _throw( Null_Exception);}* _temp7210;}).last_line)),((
struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_TypeList_tok(({
struct _tagged_ptr2 _temp7211= yyvs; void** _temp7213= _temp7211.curr +(
yyvsp_offset - 1); if( _temp7211.base == 0? 1:( _temp7213 < _temp7211.base? 1:
_temp7213 >= _temp7211.last_plus_one)){ _throw( Null_Exception);}* _temp7213;}))),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp7214= yyls; struct Cyc_Yyltype*
_temp7216= _temp7214.curr +( yylsp_offset - 4); if( _temp7214.base == 0? 1:(
_temp7216 < _temp7214.base? 1: _temp7216 >= _temp7214.last_plus_one)){ _throw(
Null_Exception);}* _temp7216;}).first_line,({ struct _tagged_ptr3 _temp7217=
yyls; struct Cyc_Yyltype* _temp7219= _temp7217.curr + yylsp_offset; if(
_temp7217.base == 0? 1:( _temp7219 < _temp7217.base? 1: _temp7219 >= _temp7217.last_plus_one)){
_throw( Null_Exception);}* _temp7219;}).last_line)); _temp7199;}); _temp7198;});
break; case 379: _LL7197: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7221=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7221[ 0]=({ struct Cyc_Exp_tok_struct _temp7222; _temp7222.tag= Cyc_Exp_tok;
_temp7222.f1= Cyc_Absyn_tuple_exp( Cyc_yyget_ExpList_tok(({ struct _tagged_ptr2
_temp7223= yyvs; void** _temp7225= _temp7223.curr +( yyvsp_offset - 1); if(
_temp7223.base == 0? 1:( _temp7225 < _temp7223.base? 1: _temp7225 >= _temp7223.last_plus_one)){
_throw( Null_Exception);}* _temp7225;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp7226= yyls; struct Cyc_Yyltype* _temp7228= _temp7226.curr +(
yylsp_offset - 3); if( _temp7226.base == 0? 1:( _temp7228 < _temp7226.base? 1:
_temp7228 >= _temp7226.last_plus_one)){ _throw( Null_Exception);}* _temp7228;}).first_line,({
struct _tagged_ptr3 _temp7229= yyls; struct Cyc_Yyltype* _temp7231= _temp7229.curr
+ yylsp_offset; if( _temp7229.base == 0? 1:( _temp7231 < _temp7229.base? 1:
_temp7231 >= _temp7229.last_plus_one)){ _throw( Null_Exception);}* _temp7231;}).last_line));
_temp7222;}); _temp7221;}); break; case 380: _LL7220: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7233=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7233[ 0]=({ struct Cyc_Exp_tok_struct
_temp7234; _temp7234.tag= Cyc_Exp_tok; _temp7234.f1= Cyc_Absyn_new_exp(( void*)({
struct Cyc_Absyn_Struct_e_struct* _temp7235=( struct Cyc_Absyn_Struct_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Struct_e_struct)); _temp7235[ 0]=({ struct
Cyc_Absyn_Struct_e_struct _temp7236; _temp7236.tag= Cyc_Absyn_Struct_e;
_temp7236.f1= Cyc_yyget_QualId_tok(({ struct _tagged_ptr2 _temp7237= yyvs; void**
_temp7239= _temp7237.curr +( yyvsp_offset - 3); if( _temp7237.base == 0? 1:(
_temp7239 < _temp7237.base? 1: _temp7239 >= _temp7237.last_plus_one)){ _throw(
Null_Exception);}* _temp7239;})); _temp7236.f2= 0; _temp7236.f3=(( struct Cyc_List_List*(*)(
struct Cyc_List_List* x)) Cyc_List_imp_rev)( Cyc_yyget_InitializerList_tok(({
struct _tagged_ptr2 _temp7240= yyvs; void** _temp7242= _temp7240.curr +(
yyvsp_offset - 1); if( _temp7240.base == 0? 1:( _temp7242 < _temp7240.base? 1:
_temp7242 >= _temp7240.last_plus_one)){ _throw( Null_Exception);}* _temp7242;})));
_temp7236.f4= 0; _temp7236;}); _temp7235;}), Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7243= yyls; struct Cyc_Yyltype* _temp7245= _temp7243.curr
+( yylsp_offset - 3); if( _temp7243.base == 0? 1:( _temp7245 < _temp7243.base? 1:
_temp7245 >= _temp7243.last_plus_one)){ _throw( Null_Exception);}* _temp7245;}).first_line,({
struct _tagged_ptr3 _temp7246= yyls; struct Cyc_Yyltype* _temp7248= _temp7246.curr
+ yylsp_offset; if( _temp7246.base == 0? 1:( _temp7248 < _temp7246.base? 1:
_temp7248 >= _temp7246.last_plus_one)){ _throw( Null_Exception);}* _temp7248;}).last_line));
_temp7234;}); _temp7233;}); break; case 381: _LL7232: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7250=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7250[ 0]=({ struct Cyc_Exp_tok_struct
_temp7251; _temp7251.tag= Cyc_Exp_tok; _temp7251.f1= Cyc_Absyn_stmt_exp( Cyc_yyget_Stmt_tok(({
struct _tagged_ptr2 _temp7252= yyvs; void** _temp7254= _temp7252.curr +(
yyvsp_offset - 2); if( _temp7252.base == 0? 1:( _temp7254 < _temp7252.base? 1:
_temp7254 >= _temp7252.last_plus_one)){ _throw( Null_Exception);}* _temp7254;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp7255= yyls; struct Cyc_Yyltype*
_temp7257= _temp7255.curr +( yylsp_offset - 4); if( _temp7255.base == 0? 1:(
_temp7257 < _temp7255.base? 1: _temp7257 >= _temp7255.last_plus_one)){ _throw(
Null_Exception);}* _temp7257;}).first_line,({ struct _tagged_ptr3 _temp7258=
yyls; struct Cyc_Yyltype* _temp7260= _temp7258.curr + yylsp_offset; if(
_temp7258.base == 0? 1:( _temp7260 < _temp7258.base? 1: _temp7260 >= _temp7258.last_plus_one)){
_throw( Null_Exception);}* _temp7260;}).last_line)); _temp7251;}); _temp7250;});
break; case 382: _LL7249: yyval=( void*)({ struct Cyc_ExpList_tok_struct*
_temp7262=( struct Cyc_ExpList_tok_struct*) GC_malloc( sizeof( struct Cyc_ExpList_tok_struct));
_temp7262[ 0]=({ struct Cyc_ExpList_tok_struct _temp7263; _temp7263.tag= Cyc_ExpList_tok;
_temp7263.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
Cyc_yyget_ExpList_tok(({ struct _tagged_ptr2 _temp7264= yyvs; void** _temp7266=
_temp7264.curr + yyvsp_offset; if( _temp7264.base == 0? 1:( _temp7266 <
_temp7264.base? 1: _temp7266 >= _temp7264.last_plus_one)){ _throw(
Null_Exception);}* _temp7266;}))); _temp7263;}); _temp7262;}); break; case 383:
_LL7261: yyval=( void*)({ struct Cyc_ExpList_tok_struct* _temp7268=( struct Cyc_ExpList_tok_struct*)
GC_malloc( sizeof( struct Cyc_ExpList_tok_struct)); _temp7268[ 0]=({ struct Cyc_ExpList_tok_struct
_temp7269; _temp7269.tag= Cyc_ExpList_tok; _temp7269.f1=({ struct Cyc_List_List*
_temp7270=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp7270->hd=( void*) Cyc_yyget_Exp_tok(({ struct _tagged_ptr2 _temp7271= yyvs;
void** _temp7273= _temp7271.curr + yyvsp_offset; if( _temp7271.base == 0? 1:(
_temp7273 < _temp7271.base? 1: _temp7273 >= _temp7271.last_plus_one)){ _throw(
Null_Exception);}* _temp7273;})); _temp7270->tl= 0; _temp7270;}); _temp7269;});
_temp7268;}); break; case 384: _LL7267: yyval=( void*)({ struct Cyc_ExpList_tok_struct*
_temp7275=( struct Cyc_ExpList_tok_struct*) GC_malloc( sizeof( struct Cyc_ExpList_tok_struct));
_temp7275[ 0]=({ struct Cyc_ExpList_tok_struct _temp7276; _temp7276.tag= Cyc_ExpList_tok;
_temp7276.f1=({ struct Cyc_List_List* _temp7277=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp7277->hd=( void*) Cyc_yyget_Exp_tok(({
struct _tagged_ptr2 _temp7281= yyvs; void** _temp7283= _temp7281.curr +
yyvsp_offset; if( _temp7281.base == 0? 1:( _temp7283 < _temp7281.base? 1:
_temp7283 >= _temp7281.last_plus_one)){ _throw( Null_Exception);}* _temp7283;}));
_temp7277->tl= Cyc_yyget_ExpList_tok(({ struct _tagged_ptr2 _temp7278= yyvs;
void** _temp7280= _temp7278.curr +( yyvsp_offset - 2); if( _temp7278.base == 0?
1:( _temp7280 < _temp7278.base? 1: _temp7280 >= _temp7278.last_plus_one)){
_throw( Null_Exception);}* _temp7280;})); _temp7277;}); _temp7276;}); _temp7275;});
break; case 385: _LL7274: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7285=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7285[ 0]=({ struct Cyc_Exp_tok_struct _temp7286; _temp7286.tag= Cyc_Exp_tok;
_temp7286.f1= Cyc_Absyn_int_exp((* Cyc_yyget_Int_tok(({ struct _tagged_ptr2
_temp7287= yyvs; void** _temp7289= _temp7287.curr + yyvsp_offset; if( _temp7287.base
== 0? 1:( _temp7289 < _temp7287.base? 1: _temp7289 >= _temp7287.last_plus_one)){
_throw( Null_Exception);}* _temp7289;}))).f1,(* Cyc_yyget_Int_tok(({ struct
_tagged_ptr2 _temp7290= yyvs; void** _temp7292= _temp7290.curr + yyvsp_offset;
if( _temp7290.base == 0? 1:( _temp7292 < _temp7290.base? 1: _temp7292 >=
_temp7290.last_plus_one)){ _throw( Null_Exception);}* _temp7292;}))).f2, Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7293= yyls; struct Cyc_Yyltype* _temp7295= _temp7293.curr
+ yylsp_offset; if( _temp7293.base == 0? 1:( _temp7295 < _temp7293.base? 1:
_temp7295 >= _temp7293.last_plus_one)){ _throw( Null_Exception);}* _temp7295;}).first_line,({
struct _tagged_ptr3 _temp7296= yyls; struct Cyc_Yyltype* _temp7298= _temp7296.curr
+ yylsp_offset; if( _temp7296.base == 0? 1:( _temp7298 < _temp7296.base? 1:
_temp7298 >= _temp7296.last_plus_one)){ _throw( Null_Exception);}* _temp7298;}).last_line));
_temp7286;}); _temp7285;}); break; case 386: _LL7284: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7300=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7300[ 0]=({ struct Cyc_Exp_tok_struct
_temp7301; _temp7301.tag= Cyc_Exp_tok; _temp7301.f1= Cyc_Absyn_char_exp( Cyc_yyget_Char_tok(({
struct _tagged_ptr2 _temp7302= yyvs; void** _temp7304= _temp7302.curr +
yyvsp_offset; if( _temp7302.base == 0? 1:( _temp7304 < _temp7302.base? 1:
_temp7304 >= _temp7302.last_plus_one)){ _throw( Null_Exception);}* _temp7304;})),
Cyc_Position_segment_of_abs(({ struct _tagged_ptr3 _temp7305= yyls; struct Cyc_Yyltype*
_temp7307= _temp7305.curr + yylsp_offset; if( _temp7305.base == 0? 1:( _temp7307
< _temp7305.base? 1: _temp7307 >= _temp7305.last_plus_one)){ _throw(
Null_Exception);}* _temp7307;}).first_line,({ struct _tagged_ptr3 _temp7308=
yyls; struct Cyc_Yyltype* _temp7310= _temp7308.curr + yylsp_offset; if(
_temp7308.base == 0? 1:( _temp7310 < _temp7308.base? 1: _temp7310 >= _temp7308.last_plus_one)){
_throw( Null_Exception);}* _temp7310;}).last_line)); _temp7301;}); _temp7300;});
break; case 387: _LL7299: yyval=( void*)({ struct Cyc_Exp_tok_struct* _temp7312=(
struct Cyc_Exp_tok_struct*) GC_malloc( sizeof( struct Cyc_Exp_tok_struct));
_temp7312[ 0]=({ struct Cyc_Exp_tok_struct _temp7313; _temp7313.tag= Cyc_Exp_tok;
_temp7313.f1= Cyc_Absyn_float_exp( Cyc_yyget_String_tok(({ struct _tagged_ptr2
_temp7314= yyvs; void** _temp7316= _temp7314.curr + yyvsp_offset; if( _temp7314.base
== 0? 1:( _temp7316 < _temp7314.base? 1: _temp7316 >= _temp7314.last_plus_one)){
_throw( Null_Exception);}* _temp7316;})), Cyc_Position_segment_of_abs(({ struct
_tagged_ptr3 _temp7317= yyls; struct Cyc_Yyltype* _temp7319= _temp7317.curr +
yylsp_offset; if( _temp7317.base == 0? 1:( _temp7319 < _temp7317.base? 1:
_temp7319 >= _temp7317.last_plus_one)){ _throw( Null_Exception);}* _temp7319;}).first_line,({
struct _tagged_ptr3 _temp7320= yyls; struct Cyc_Yyltype* _temp7322= _temp7320.curr
+ yylsp_offset; if( _temp7320.base == 0? 1:( _temp7322 < _temp7320.base? 1:
_temp7322 >= _temp7320.last_plus_one)){ _throw( Null_Exception);}* _temp7322;}).last_line));
_temp7313;}); _temp7312;}); break; case 388: _LL7311: yyval=( void*)({ struct
Cyc_Exp_tok_struct* _temp7324=( struct Cyc_Exp_tok_struct*) GC_malloc( sizeof(
struct Cyc_Exp_tok_struct)); _temp7324[ 0]=({ struct Cyc_Exp_tok_struct
_temp7325; _temp7325.tag= Cyc_Exp_tok; _temp7325.f1= Cyc_Absyn_null_exp( Cyc_Position_segment_of_abs(({
struct _tagged_ptr3 _temp7326= yyls; struct Cyc_Yyltype* _temp7328= _temp7326.curr
+ yylsp_offset; if( _temp7326.base == 0? 1:( _temp7328 < _temp7326.base? 1:
_temp7328 >= _temp7326.last_plus_one)){ _throw( Null_Exception);}* _temp7328;}).first_line,({
struct _tagged_ptr3 _temp7329= yyls; struct Cyc_Yyltype* _temp7331= _temp7329.curr
+ yylsp_offset; if( _temp7329.base == 0? 1:( _temp7331 < _temp7329.base? 1:
_temp7331 >= _temp7329.last_plus_one)){ _throw( Null_Exception);}* _temp7331;}).last_line));
_temp7325;}); _temp7324;}); break; case 389: _LL7323: yyval=( void*)({ struct
Cyc_QualId_tok_struct* _temp7333=( struct Cyc_QualId_tok_struct*) GC_malloc(
sizeof( struct Cyc_QualId_tok_struct)); _temp7333[ 0]=({ struct Cyc_QualId_tok_struct
_temp7334; _temp7334.tag= Cyc_QualId_tok; _temp7334.f1=({ struct _tuple1*
_temp7335=( struct _tuple1*) GC_malloc( sizeof( struct _tuple1)); _temp7335->f1=(
void*)({ struct Cyc_Absyn_Rel_n_struct* _temp7340=( struct Cyc_Absyn_Rel_n_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Rel_n_struct)); _temp7340[ 0]=({ struct Cyc_Absyn_Rel_n_struct
_temp7341; _temp7341.tag= Cyc_Absyn_Rel_n; _temp7341.f1= 0; _temp7341;});
_temp7340;}); _temp7335->f2=({ struct _tagged_string* _temp7336=( struct
_tagged_string*) GC_malloc( sizeof( struct _tagged_string) * 1); _temp7336[ 0]=
Cyc_yyget_String_tok(({ struct _tagged_ptr2 _temp7337= yyvs; void** _temp7339=
_temp7337.curr + yyvsp_offset; if( _temp7337.base == 0? 1:( _temp7339 <
_temp7337.base? 1: _temp7339 >= _temp7337.last_plus_one)){ _throw(
Null_Exception);}* _temp7339;})); _temp7336;}); _temp7335;}); _temp7334;});
_temp7333;}); break; case 390: _LL7332: yyval=({ struct _tagged_ptr2 _temp7343=
yyvs; void** _temp7345= _temp7343.curr + yyvsp_offset; if( _temp7343.base == 0?
1:( _temp7345 < _temp7343.base? 1: _temp7345 >= _temp7343.last_plus_one)){
_throw( Null_Exception);}* _temp7345;}); break; default: _LL7342:( void) _throw((
void*) Cyc_Yyimpossible);} yyvsp_offset -= yylen; yyssp_offset -= yylen;
yylsp_offset -= yylen;({ struct _tagged_ptr2 _temp7347= yyvs; void** _temp7349=
_temp7347.curr +( ++ yyvsp_offset); if( _temp7347.base == 0? 1:( _temp7349 <
_temp7347.base? 1: _temp7349 >= _temp7347.last_plus_one)){ _throw(
Null_Exception);}* _temp7349= yyval;}); yylsp_offset ++; if( yylen == 0){({
struct _tagged_ptr3 _temp7350= yyls; struct Cyc_Yyltype* _temp7352= _temp7350.curr
+ yylsp_offset; if( _temp7350.base == 0? 1:( _temp7352 < _temp7350.base? 1:
_temp7352 >= _temp7350.last_plus_one)){ _throw( Null_Exception);}(* _temp7352).first_line=
Cyc_yylloc.first_line;});({ struct _tagged_ptr3 _temp7353= yyls; struct Cyc_Yyltype*
_temp7355= _temp7353.curr + yylsp_offset; if( _temp7353.base == 0? 1:( _temp7355
< _temp7353.base? 1: _temp7355 >= _temp7353.last_plus_one)){ _throw(
Null_Exception);}(* _temp7355).first_column= Cyc_yylloc.first_column;});({
struct _tagged_ptr3 _temp7356= yyls; struct Cyc_Yyltype* _temp7358= _temp7356.curr
+ yylsp_offset; if( _temp7356.base == 0? 1:( _temp7358 < _temp7356.base? 1:
_temp7358 >= _temp7356.last_plus_one)){ _throw( Null_Exception);}(* _temp7358).last_line=({
struct _tagged_ptr3 _temp7359= yyls; struct Cyc_Yyltype* _temp7361= _temp7359.curr
+( yylsp_offset - 1); if( _temp7359.base == 0? 1:( _temp7361 < _temp7359.base? 1:
_temp7361 >= _temp7359.last_plus_one)){ _throw( Null_Exception);}* _temp7361;}).last_line;});({
struct _tagged_ptr3 _temp7362= yyls; struct Cyc_Yyltype* _temp7364= _temp7362.curr
+ yylsp_offset; if( _temp7362.base == 0? 1:( _temp7364 < _temp7362.base? 1:
_temp7364 >= _temp7362.last_plus_one)){ _throw( Null_Exception);}(* _temp7364).last_column=({
struct _tagged_ptr3 _temp7365= yyls; struct Cyc_Yyltype* _temp7367= _temp7365.curr
+( yylsp_offset - 1); if( _temp7365.base == 0? 1:( _temp7367 < _temp7365.base? 1:
_temp7367 >= _temp7365.last_plus_one)){ _throw( Null_Exception);}* _temp7367;}).last_column;});({
struct _tagged_ptr3 _temp7368= yyls; struct Cyc_Yyltype* _temp7370= _temp7368.curr
+ yylsp_offset; if( _temp7368.base == 0? 1:( _temp7370 < _temp7368.base? 1:
_temp7370 >= _temp7368.last_plus_one)){ _throw( Null_Exception);}(* _temp7370).text=(
struct _tagged_string)({ char* _temp7371=( char*)""; struct _tagged_string
_temp7372; _temp7372.curr= _temp7371; _temp7372.base= _temp7371; _temp7372.last_plus_one=
_temp7371 + 1; _temp7372;});});} else{({ struct _tagged_ptr3 _temp7373= yyls;
struct Cyc_Yyltype* _temp7375= _temp7373.curr + yylsp_offset; if( _temp7373.base
== 0? 1:( _temp7375 < _temp7373.base? 1: _temp7375 >= _temp7373.last_plus_one)){
_throw( Null_Exception);}(* _temp7375).last_line=({ struct _tagged_ptr3
_temp7376= yyls; struct Cyc_Yyltype* _temp7378= _temp7376.curr +(( yylsp_offset
+ yylen) - 1); if( _temp7376.base == 0? 1:( _temp7378 < _temp7376.base? 1:
_temp7378 >= _temp7376.last_plus_one)){ _throw( Null_Exception);}* _temp7378;}).last_line;});({
struct _tagged_ptr3 _temp7379= yyls; struct Cyc_Yyltype* _temp7381= _temp7379.curr
+ yylsp_offset; if( _temp7379.base == 0? 1:( _temp7381 < _temp7379.base? 1:
_temp7381 >= _temp7379.last_plus_one)){ _throw( Null_Exception);}(* _temp7381).last_column=({
struct _tagged_ptr3 _temp7382= yyls; struct Cyc_Yyltype* _temp7384= _temp7382.curr
+(( yylsp_offset + yylen) - 1); if( _temp7382.base == 0? 1:( _temp7384 <
_temp7382.base? 1: _temp7384 >= _temp7382.last_plus_one)){ _throw(
Null_Exception);}* _temp7384;}).last_column;});} yyn=( int)({ short* _temp7385=(
short*) Cyc_yyr1; unsigned int _temp7386= yyn; if( _temp7386 >= 391u){ _throw(
Null_Exception);} _temp7385[ _temp7386];}); yystate=({ short* _temp7387=( short*)
Cyc_yypgoto; unsigned int _temp7388= yyn - 124; if( _temp7388 >= 107u){ _throw(
Null_Exception);} _temp7387[ _temp7388];}) +({ struct _tagged_ptr1 _temp7389=
yyss; short* _temp7391= _temp7389.curr + yyssp_offset; if( _temp7389.base == 0?
1:( _temp7391 < _temp7389.base? 1: _temp7391 >= _temp7389.last_plus_one)){
_throw( Null_Exception);}* _temp7391;}); if(( yystate >= 0? yystate <= 4318: 0)?({
short* _temp7392=( short*) Cyc_yycheck; unsigned int _temp7393= yystate; if(
_temp7393 >= 4319u){ _throw( Null_Exception);} _temp7392[ _temp7393];}) ==({
struct _tagged_ptr1 _temp7394= yyss; short* _temp7396= _temp7394.curr +
yyssp_offset; if( _temp7394.base == 0? 1:( _temp7396 < _temp7394.base? 1:
_temp7396 >= _temp7394.last_plus_one)){ _throw( Null_Exception);}* _temp7396;}):
0){ yystate=( int)({ short* _temp7397=( short*) Cyc_yytable; unsigned int
_temp7398= yystate; if( _temp7398 >= 4319u){ _throw( Null_Exception);} _temp7397[
_temp7398];});} else{ yystate=( int)({ short* _temp7399=( short*) Cyc_yydefgoto;
unsigned int _temp7400= yyn - 124; if( _temp7400 >= 107u){ _throw(
Null_Exception);} _temp7399[ _temp7400];});} goto yynewstate; yyerrlab: if(
yyerrstatus == 0){ ++ Cyc_yynerrs; yyn=( int)({ short* _temp7401=( short*) Cyc_yypact;
unsigned int _temp7402= yystate; if( _temp7402 >= 748u){ _throw( Null_Exception);}
_temp7401[ _temp7402];}); if( yyn > - 32768? yyn < 4318: 0){ int sze= 0; struct
_tagged_string msg; int x; int count; count= 0; for( x= yyn < 0? - yyn: 0; x <
231u / sizeof( char*); x ++){ if(({ short* _temp7403=( short*) Cyc_yycheck;
unsigned int _temp7404= x + yyn; if( _temp7404 >= 4319u){ _throw( Null_Exception);}
_temp7403[ _temp7404];}) == x){ sze += Cyc_String_strlen(({ struct
_tagged_string* _temp7405=( struct _tagged_string*) Cyc_yytname; unsigned int
_temp7406= x; if( _temp7406 >= 231u){ _throw( Null_Exception);} _temp7405[
_temp7406];})) + 15, count ++;}} msg=({ unsigned int _temp7407=( unsigned int)(
sze + 15); char* _temp7408=( char*) GC_malloc_atomic( sizeof( char) * _temp7407);
struct _tagged_string _temp7411={ _temp7408, _temp7408, _temp7408 + _temp7407};{
unsigned int _temp7409= _temp7407; unsigned int i; for( i= 0; i < _temp7409; i
++){ _temp7408[ i]='\000';}}; _temp7411;}); Cyc_String_strcpy( msg,( struct
_tagged_string)({ char* _temp7412=( char*)"parse error"; struct _tagged_string
_temp7413; _temp7413.curr= _temp7412; _temp7413.base= _temp7412; _temp7413.last_plus_one=
_temp7412 + 12; _temp7413;})); if( count < 5){ count= 0; for( x= yyn < 0? - yyn:
0; x < 231u / sizeof( char*); x ++){ if(({ short* _temp7414=( short*) Cyc_yycheck;
unsigned int _temp7415= x + yyn; if( _temp7415 >= 4319u){ _throw( Null_Exception);}
_temp7414[ _temp7415];}) == x){ Cyc_String_strcat( msg, count == 0?( struct
_tagged_string)({ char* _temp7416=( char*)", expecting `"; struct _tagged_string
_temp7417; _temp7417.curr= _temp7416; _temp7417.base= _temp7416; _temp7417.last_plus_one=
_temp7416 + 14; _temp7417;}):( struct _tagged_string)({ char* _temp7418=( char*)" or `";
struct _tagged_string _temp7419; _temp7419.curr= _temp7418; _temp7419.base=
_temp7418; _temp7419.last_plus_one= _temp7418 + 6; _temp7419;})); Cyc_String_strcat(
msg,({ struct _tagged_string* _temp7420=( struct _tagged_string*) Cyc_yytname;
unsigned int _temp7421= x; if( _temp7421 >= 231u){ _throw( Null_Exception);}
_temp7420[ _temp7421];})); Cyc_String_strcat( msg,( struct _tagged_string)({
char* _temp7422=( char*)"'"; struct _tagged_string _temp7423; _temp7423.curr=
_temp7422; _temp7423.base= _temp7422; _temp7423.last_plus_one= _temp7422 + 2;
_temp7423;})); count ++;}}} Cyc_yyerror( msg);} else{ Cyc_yyerror(( struct
_tagged_string)({ char* _temp7424=( char*)"parse error"; struct _tagged_string
_temp7425; _temp7425.curr= _temp7424; _temp7425.base= _temp7424; _temp7425.last_plus_one=
_temp7424 + 12; _temp7425;}));}} goto yyerrlab1; yyerrlab1: if( yyerrstatus == 3){
if( Cyc_yychar == 0){ return 1;} Cyc_yychar= - 2;} yyerrstatus= 3; goto
yyerrhandle; yyerrdefault: yyerrpop: if( yyssp_offset == 0){ return 1;}
yyvsp_offset --; yystate=( int)({ struct _tagged_ptr1 _temp7426= yyss; short*
_temp7428= _temp7426.curr +( -- yyssp_offset); if( _temp7426.base == 0? 1:(
_temp7428 < _temp7426.base? 1: _temp7428 >= _temp7426.last_plus_one)){ _throw(
Null_Exception);}* _temp7428;}); yylsp_offset --; yyerrhandle: yyn=( int)({
short* _temp7429=( short*) Cyc_yypact; unsigned int _temp7430= yystate; if(
_temp7430 >= 748u){ _throw( Null_Exception);} _temp7429[ _temp7430];}); if( yyn
== - 32768){ goto yyerrdefault;} yyn += 1; if(( yyn < 0? 1: yyn > 4318)? 1:({
short* _temp7431=( short*) Cyc_yycheck; unsigned int _temp7432= yyn; if(
_temp7432 >= 4319u){ _throw( Null_Exception);} _temp7431[ _temp7432];}) != 1){
goto yyerrdefault;} yyn=( int)({ short* _temp7433=( short*) Cyc_yytable;
unsigned int _temp7434= yyn; if( _temp7434 >= 4319u){ _throw( Null_Exception);}
_temp7433[ _temp7434];}); if( yyn < 0){ if( yyn == - 32768){ goto yyerrpop;} yyn=
- yyn; goto yyreduce;} else{ if( yyn == 0){ goto yyerrpop;}} if( yyn == 747){
return 0;}({ struct _tagged_ptr2 _temp7435= yyvs; void** _temp7437= _temp7435.curr
+( ++ yyvsp_offset); if( _temp7435.base == 0? 1:( _temp7437 < _temp7435.base? 1:
_temp7437 >= _temp7435.last_plus_one)){ _throw( Null_Exception);}* _temp7437=
Cyc_yylval;});({ struct _tagged_ptr3 _temp7438= yyls; struct Cyc_Yyltype*
_temp7440= _temp7438.curr +( ++ yylsp_offset); if( _temp7438.base == 0? 1:(
_temp7440 < _temp7438.base? 1: _temp7440 >= _temp7438.last_plus_one)){ _throw(
Null_Exception);}* _temp7440= Cyc_yylloc;}); goto yynewstate;} void Cyc_yyprint(
int i, void* v){ void* _temp7459= v; struct _tuple12* _temp7479; struct _tuple12
_temp7481; int _temp7482; void* _temp7484; char _temp7486; short _temp7488;
struct _tagged_string _temp7490; struct Cyc_Core_Opt* _temp7492; struct Cyc_Core_Opt*
_temp7494; struct Cyc_Core_Opt _temp7496; struct _tagged_string* _temp7497;
struct _tuple1* _temp7499; struct _tuple1 _temp7501; struct _tagged_string*
_temp7502; void* _temp7504; _LL7461: if( _temp7459 == Cyc_Okay_tok){ goto
_LL7462;} else{ goto _LL7463;} _LL7463: if(*(( void**) _temp7459) == Cyc_Int_tok){
_LL7480: _temp7479=( struct _tuple12*)(( struct Cyc_Int_tok_struct*) _temp7459)->f1;
_temp7481=* _temp7479; _LL7485: _temp7484= _temp7481.f1; goto _LL7483; _LL7483:
_temp7482= _temp7481.f2; goto _LL7464;} else{ goto _LL7465;} _LL7465: if(*((
void**) _temp7459) == Cyc_Char_tok){ _LL7487: _temp7486=( char)(( struct Cyc_Char_tok_struct*)
_temp7459)->f1; goto _LL7466;} else{ goto _LL7467;} _LL7467: if(*(( void**)
_temp7459) == Cyc_Short_tok){ _LL7489: _temp7488=( short)(( struct Cyc_Short_tok_struct*)
_temp7459)->f1; goto _LL7468;} else{ goto _LL7469;} _LL7469: if(*(( void**)
_temp7459) == Cyc_String_tok){ _LL7491: _temp7490=( struct _tagged_string)((
struct Cyc_String_tok_struct*) _temp7459)->f1; goto _LL7470;} else{ goto _LL7471;}
_LL7471: if(*(( void**) _temp7459) == Cyc_Stringopt_tok){ _LL7493: _temp7492=(
struct Cyc_Core_Opt*)(( struct Cyc_Stringopt_tok_struct*) _temp7459)->f1; if(
_temp7492 == 0){ goto _LL7472;} else{ goto _LL7473;}} else{ goto _LL7473;}
_LL7473: if(*(( void**) _temp7459) == Cyc_Stringopt_tok){ _LL7495: _temp7494=(
struct Cyc_Core_Opt*)(( struct Cyc_Stringopt_tok_struct*) _temp7459)->f1; if(
_temp7494 == 0){ goto _LL7475;} else{ _temp7496=* _temp7494; _LL7498: _temp7497=(
struct _tagged_string*) _temp7496.v; goto _LL7474;}} else{ goto _LL7475;}
_LL7475: if(*(( void**) _temp7459) == Cyc_QualId_tok){ _LL7500: _temp7499=(
struct _tuple1*)(( struct Cyc_QualId_tok_struct*) _temp7459)->f1; _temp7501=*
_temp7499; _LL7505: _temp7504= _temp7501.f1; goto _LL7503; _LL7503: _temp7502=
_temp7501.f2; goto _LL7476;} else{ goto _LL7477;} _LL7477: goto _LL7478; _LL7462:
fprintf( Cyc_Stdio_stderr,"ok"); goto _LL7460; _LL7464: fprintf( Cyc_Stdio_stderr,"%d",
_temp7482); goto _LL7460; _LL7466: fprintf( Cyc_Stdio_stderr,"%c",( int)
_temp7486); goto _LL7460; _LL7468: fprintf( Cyc_Stdio_stderr,"%ds",( int)
_temp7488); goto _LL7460; _LL7470:({ struct _tagged_string _temp7506= _temp7490;
fprintf( Cyc_Stdio_stderr,"\"%.*s\"", _temp7506.last_plus_one - _temp7506.curr,
_temp7506.curr);}); goto _LL7460; _LL7472: fprintf( Cyc_Stdio_stderr,"null");
goto _LL7460; _LL7474:({ struct _tagged_string _temp7507=* _temp7497; fprintf(
Cyc_Stdio_stderr,"\"%.*s\"", _temp7507.last_plus_one - _temp7507.curr, _temp7507.curr);});
goto _LL7460; _LL7476: { struct Cyc_List_List* prefix= 0;{ void* _temp7508=
_temp7504; struct Cyc_List_List* _temp7516; struct Cyc_List_List* _temp7518;
_LL7510: if(( unsigned int) _temp7508 > 1u?*(( int*) _temp7508) == Cyc_Absyn_Rel_n:
0){ _LL7517: _temp7516=( struct Cyc_List_List*)(( struct Cyc_Absyn_Rel_n_struct*)
_temp7508)->f1; goto _LL7511;} else{ goto _LL7512;} _LL7512: if(( unsigned int)
_temp7508 > 1u?*(( int*) _temp7508) == Cyc_Absyn_Abs_n: 0){ _LL7519: _temp7518=(
struct Cyc_List_List*)(( struct Cyc_Absyn_Abs_n_struct*) _temp7508)->f1; goto
_LL7513;} else{ goto _LL7514;} _LL7514: if( _temp7508 ==( void*) Cyc_Absyn_Loc_n){
goto _LL7515;} else{ goto _LL7509;} _LL7511: prefix= _temp7516; goto _LL7509;
_LL7513: prefix= _temp7518; goto _LL7509; _LL7515: goto _LL7509; _LL7509:;} for(
0; prefix != 0; prefix=({ struct Cyc_List_List* _temp7520= prefix; if( _temp7520
== 0){ _throw( Null_Exception);} _temp7520->tl;})){({ struct _tagged_string
_temp7522=*(( struct _tagged_string*)({ struct Cyc_List_List* _temp7521= prefix;
if( _temp7521 == 0){ _throw( Null_Exception);} _temp7521->hd;})); fprintf( Cyc_Stdio_stderr,"%.*s::",
_temp7522.last_plus_one - _temp7522.curr, _temp7522.curr);});}({ struct
_tagged_string _temp7523=* _temp7502; fprintf( Cyc_Stdio_stderr,"%.*s::",
_temp7523.last_plus_one - _temp7523.curr, _temp7523.curr);}); goto _LL7460;}
_LL7478: fprintf( Cyc_Stdio_stderr,"?"); goto _LL7460; _LL7460:;} struct Cyc_List_List*
Cyc_Parse_parse_file( struct Cyc_Stdio___sFILE* f){ Cyc_Parse_parse_result= 0;
Cyc_Parse_lbuf=({ struct Cyc_Core_Opt* _temp7524=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp7524->v=( void*) Cyc_Lexing_from_file(
f); _temp7524;}); Cyc_yyparse(); return Cyc_Parse_parse_result;}