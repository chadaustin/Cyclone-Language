 struct Cyc_timespec{ int tv_sec; int tv_nsec; } ; struct Cyc_itimerspec{ struct
Cyc_timespec it_interval; struct Cyc_timespec it_value; } ; struct Cyc__types_fd_set{
int fds_bits[ 2u]; } ; extern void exit( int); extern void* abort(); struct Cyc_Core_Opt{
void* v; } ; struct _tuple0{ void* f1; void* f2; } ; extern void* Cyc_Core_snd(
struct _tuple0*); extern unsigned char Cyc_Core_InvalidArg[ 15u]; struct Cyc_Core_InvalidArg_struct{
unsigned char* tag; struct _tagged_string f1; } ; extern unsigned char Cyc_Core_Failure[
12u]; struct Cyc_Core_Failure_struct{ unsigned char* tag; struct _tagged_string
f1; } ; extern unsigned char Cyc_Core_Impossible[ 15u]; struct Cyc_Core_Impossible_struct{
unsigned char* tag; struct _tagged_string f1; } ; extern unsigned char Cyc_Core_Not_found[
14u]; extern unsigned char Cyc_Core_Unreachable[ 16u]; struct Cyc_Core_Unreachable_struct{
unsigned char* tag; struct _tagged_string f1; } ; extern unsigned char*
string_to_Cstring( struct _tagged_string); extern unsigned char*
underlying_Cstring( struct _tagged_string); extern struct _tagged_string
Cstring_to_string( unsigned char*); struct _tagged_ptr0{ struct _tagged_string*
curr; struct _tagged_string* base; struct _tagged_string* last_plus_one; } ;
extern struct _tagged_ptr0 ntCsl_to_ntsl( unsigned char**); extern int system(
unsigned char*); extern int* __errno(); struct Cyc_List_List{ void* hd; struct
Cyc_List_List* tl; } ; extern int Cyc_List_length( struct Cyc_List_List* x);
extern unsigned char Cyc_List_List_empty[ 15u]; extern struct Cyc_List_List* Cyc_List_map(
void*(* f)( void*), struct Cyc_List_List* x); extern struct Cyc_List_List* Cyc_List_rmap_c(
struct _RegionHandle*, void*(* f)( void*, void*), void* env, struct Cyc_List_List*
x); extern unsigned char Cyc_List_List_mismatch[ 18u]; extern struct Cyc_List_List*
Cyc_List_imp_rev( struct Cyc_List_List* x); extern struct Cyc_List_List* Cyc_List_append(
struct Cyc_List_List* x, struct Cyc_List_List* y); extern struct Cyc_List_List*
Cyc_List_rappend( struct _RegionHandle*, struct Cyc_List_List* x, struct Cyc_List_List*
y); extern unsigned char Cyc_List_Nth[ 8u]; extern void* Cyc_List_nth( struct
Cyc_List_List* x, int i); extern struct Cyc_List_List* Cyc_List_zip( struct Cyc_List_List*
x, struct Cyc_List_List* y); extern struct Cyc_List_List* Cyc_List_rzip( struct
_RegionHandle* r3, struct _RegionHandle* r4, struct Cyc_List_List* x, struct Cyc_List_List*
y); struct Cyc_Lineno_Pos{ struct _tagged_string logical_file; struct
_tagged_string line; int line_no; int col; } ; extern unsigned char Cyc_Position_Exit[
9u]; struct Cyc_Position_Segment; static const int Cyc_Position_Lex= 0; static
const int Cyc_Position_Parse= 1; static const int Cyc_Position_Elab= 2; struct
Cyc_Position_Error{ struct _tagged_string source; struct Cyc_Position_Segment*
seg; void* kind; struct _tagged_string desc; } ; extern unsigned char Cyc_Position_Nocontext[
14u]; struct _tuple1{ void* f1; struct _tagged_string* f2; } ; struct Cyc_Absyn_Tvar;
struct Cyc_Absyn_Tqual; struct Cyc_Absyn_Conref; struct Cyc_Absyn_PtrInfo;
struct Cyc_Absyn_VarargInfo; struct Cyc_Absyn_FnInfo; struct Cyc_Absyn_TunionInfo;
struct Cyc_Absyn_TunionFieldInfo; struct Cyc_Absyn_VarargCallInfo; struct Cyc_Absyn_Exp;
struct Cyc_Absyn_Stmt; struct Cyc_Absyn_Pat; struct Cyc_Absyn_Switch_clause;
struct Cyc_Absyn_SwitchC_clause; struct Cyc_Absyn_Fndecl; struct Cyc_Absyn_Structdecl;
struct Cyc_Absyn_Uniondecl; struct Cyc_Absyn_Tuniondecl; struct Cyc_Absyn_Tunionfield;
struct Cyc_Absyn_Enumfield; struct Cyc_Absyn_Enumdecl; struct Cyc_Absyn_Typedefdecl;
struct Cyc_Absyn_Vardecl; struct Cyc_Absyn_Decl; struct Cyc_Absyn_Structfield;
static const int Cyc_Absyn_Loc_n= 0; static const int Cyc_Absyn_Rel_n= 0; struct
Cyc_Absyn_Rel_n_struct{ int tag; struct Cyc_List_List* f1; } ; static const int
Cyc_Absyn_Abs_n= 1; struct Cyc_Absyn_Abs_n_struct{ int tag; struct Cyc_List_List*
f1; } ; static const int Cyc_Absyn_Static= 0; static const int Cyc_Absyn_Abstract=
1; static const int Cyc_Absyn_Public= 2; static const int Cyc_Absyn_Extern= 3;
static const int Cyc_Absyn_ExternC= 4; struct Cyc_Absyn_Tqual{ int q_const: 1;
int q_volatile: 1; int q_restrict: 1; } ; static const int Cyc_Absyn_B1= 0;
static const int Cyc_Absyn_B2= 1; static const int Cyc_Absyn_B4= 2; static const
int Cyc_Absyn_B8= 3; static const int Cyc_Absyn_AnyKind= 0; static const int Cyc_Absyn_MemKind=
1; static const int Cyc_Absyn_BoxKind= 2; static const int Cyc_Absyn_RgnKind= 3;
static const int Cyc_Absyn_EffKind= 4; static const int Cyc_Absyn_Signed= 0;
static const int Cyc_Absyn_Unsigned= 1; struct Cyc_Absyn_Conref{ void* v; } ;
static const int Cyc_Absyn_Eq_constr= 0; struct Cyc_Absyn_Eq_constr_struct{ int
tag; void* f1; } ; static const int Cyc_Absyn_Forward_constr= 1; struct Cyc_Absyn_Forward_constr_struct{
int tag; struct Cyc_Absyn_Conref* f1; } ; static const int Cyc_Absyn_No_constr=
0; struct Cyc_Absyn_Tvar{ struct _tagged_string* name; int* identity; struct Cyc_Absyn_Conref*
kind; } ; static const int Cyc_Absyn_Unknown_b= 0; static const int Cyc_Absyn_Upper_b=
0; struct Cyc_Absyn_Upper_b_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
struct Cyc_Absyn_PtrInfo{ void* elt_typ; void* rgn_typ; struct Cyc_Absyn_Conref*
nullable; struct Cyc_Absyn_Tqual tq; struct Cyc_Absyn_Conref* bounds; } ; struct
Cyc_Absyn_VarargInfo{ struct Cyc_Core_Opt* name; struct Cyc_Absyn_Tqual tq; void*
type; void* rgn; int inject; } ; struct Cyc_Absyn_FnInfo{ struct Cyc_List_List*
tvars; struct Cyc_Core_Opt* effect; void* ret_typ; struct Cyc_List_List* args;
int c_varargs; struct Cyc_Absyn_VarargInfo* cyc_varargs; struct Cyc_List_List*
rgn_po; struct Cyc_List_List* attributes; } ; struct Cyc_Absyn_UnknownTunionInfo{
struct _tuple1* name; int is_xtunion; } ; static const int Cyc_Absyn_UnknownTunion=
0; struct Cyc_Absyn_UnknownTunion_struct{ int tag; struct Cyc_Absyn_UnknownTunionInfo
f1; } ; static const int Cyc_Absyn_KnownTunion= 1; struct Cyc_Absyn_KnownTunion_struct{
int tag; struct Cyc_Absyn_Tuniondecl* f1; } ; struct Cyc_Absyn_TunionInfo{ void*
tunion_info; struct Cyc_List_List* targs; void* rgn; } ; struct Cyc_Absyn_UnknownTunionFieldInfo{
struct _tuple1* tunion_name; struct _tuple1* field_name; int is_xtunion; } ;
static const int Cyc_Absyn_UnknownTunionfield= 0; struct Cyc_Absyn_UnknownTunionfield_struct{
int tag; struct Cyc_Absyn_UnknownTunionFieldInfo f1; } ; static const int Cyc_Absyn_KnownTunionfield=
1; struct Cyc_Absyn_KnownTunionfield_struct{ int tag; struct Cyc_Absyn_Tuniondecl*
f1; struct Cyc_Absyn_Tunionfield* f2; } ; struct Cyc_Absyn_TunionFieldInfo{ void*
field_info; struct Cyc_List_List* targs; } ; static const int Cyc_Absyn_VoidType=
0; static const int Cyc_Absyn_Evar= 0; struct Cyc_Absyn_Evar_struct{ int tag;
struct Cyc_Core_Opt* f1; struct Cyc_Core_Opt* f2; int f3; struct Cyc_Core_Opt*
f4; } ; static const int Cyc_Absyn_VarType= 1; struct Cyc_Absyn_VarType_struct{
int tag; struct Cyc_Absyn_Tvar* f1; } ; static const int Cyc_Absyn_TunionType= 2;
struct Cyc_Absyn_TunionType_struct{ int tag; struct Cyc_Absyn_TunionInfo f1; } ;
static const int Cyc_Absyn_TunionFieldType= 3; struct Cyc_Absyn_TunionFieldType_struct{
int tag; struct Cyc_Absyn_TunionFieldInfo f1; } ; static const int Cyc_Absyn_PointerType=
4; struct Cyc_Absyn_PointerType_struct{ int tag; struct Cyc_Absyn_PtrInfo f1; }
; static const int Cyc_Absyn_IntType= 5; struct Cyc_Absyn_IntType_struct{ int
tag; void* f1; void* f2; } ; static const int Cyc_Absyn_FloatType= 1; static
const int Cyc_Absyn_DoubleType= 2; static const int Cyc_Absyn_ArrayType= 6;
struct Cyc_Absyn_ArrayType_struct{ int tag; void* f1; struct Cyc_Absyn_Tqual f2;
struct Cyc_Absyn_Exp* f3; } ; static const int Cyc_Absyn_FnType= 7; struct Cyc_Absyn_FnType_struct{
int tag; struct Cyc_Absyn_FnInfo f1; } ; static const int Cyc_Absyn_TupleType= 8;
struct Cyc_Absyn_TupleType_struct{ int tag; struct Cyc_List_List* f1; } ; static
const int Cyc_Absyn_StructType= 9; struct Cyc_Absyn_StructType_struct{ int tag;
struct _tuple1* f1; struct Cyc_List_List* f2; struct Cyc_Absyn_Structdecl** f3;
} ; static const int Cyc_Absyn_UnionType= 10; struct Cyc_Absyn_UnionType_struct{
int tag; struct _tuple1* f1; struct Cyc_List_List* f2; struct Cyc_Absyn_Uniondecl**
f3; } ; static const int Cyc_Absyn_AnonStructType= 11; struct Cyc_Absyn_AnonStructType_struct{
int tag; struct Cyc_List_List* f1; } ; static const int Cyc_Absyn_AnonUnionType=
12; struct Cyc_Absyn_AnonUnionType_struct{ int tag; struct Cyc_List_List* f1; }
; static const int Cyc_Absyn_EnumType= 13; struct Cyc_Absyn_EnumType_struct{ int
tag; struct _tuple1* f1; struct Cyc_Absyn_Enumdecl* f2; } ; static const int Cyc_Absyn_RgnHandleType=
14; struct Cyc_Absyn_RgnHandleType_struct{ int tag; void* f1; } ; static const
int Cyc_Absyn_TypedefType= 15; struct Cyc_Absyn_TypedefType_struct{ int tag;
struct _tuple1* f1; struct Cyc_List_List* f2; struct Cyc_Core_Opt* f3; } ;
static const int Cyc_Absyn_HeapRgn= 3; static const int Cyc_Absyn_AccessEff= 16;
struct Cyc_Absyn_AccessEff_struct{ int tag; void* f1; } ; static const int Cyc_Absyn_JoinEff=
17; struct Cyc_Absyn_JoinEff_struct{ int tag; struct Cyc_List_List* f1; } ;
static const int Cyc_Absyn_NoTypes= 0; struct Cyc_Absyn_NoTypes_struct{ int tag;
struct Cyc_List_List* f1; struct Cyc_Position_Segment* f2; } ; static const int
Cyc_Absyn_WithTypes= 1; struct Cyc_Absyn_WithTypes_struct{ int tag; struct Cyc_List_List*
f1; int f2; struct Cyc_Absyn_VarargInfo* f3; struct Cyc_Core_Opt* f4; struct Cyc_List_List*
f5; } ; static const int Cyc_Absyn_NonNullable_ps= 0; struct Cyc_Absyn_NonNullable_ps_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_Nullable_ps= 1;
struct Cyc_Absyn_Nullable_ps_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
static const int Cyc_Absyn_TaggedArray_ps= 0; static const int Cyc_Absyn_Regparm_att=
0; struct Cyc_Absyn_Regparm_att_struct{ int tag; int f1; } ; static const int
Cyc_Absyn_Stdcall_att= 0; static const int Cyc_Absyn_Cdecl_att= 1; static const
int Cyc_Absyn_Fastcall_att= 2; static const int Cyc_Absyn_Noreturn_att= 3;
static const int Cyc_Absyn_Const_att= 4; static const int Cyc_Absyn_Aligned_att=
1; struct Cyc_Absyn_Aligned_att_struct{ int tag; int f1; } ; static const int
Cyc_Absyn_Packed_att= 5; static const int Cyc_Absyn_Section_att= 2; struct Cyc_Absyn_Section_att_struct{
int tag; struct _tagged_string f1; } ; static const int Cyc_Absyn_Nocommon_att=
6; static const int Cyc_Absyn_Shared_att= 7; static const int Cyc_Absyn_Unused_att=
8; static const int Cyc_Absyn_Weak_att= 9; static const int Cyc_Absyn_Dllimport_att=
10; static const int Cyc_Absyn_Dllexport_att= 11; static const int Cyc_Absyn_No_instrument_function_att=
12; static const int Cyc_Absyn_Constructor_att= 13; static const int Cyc_Absyn_Destructor_att=
14; static const int Cyc_Absyn_No_check_memory_usage_att= 15; static const int
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
unsigned char f2; } ; static const int Cyc_Absyn_Short_c= 1; struct Cyc_Absyn_Short_c_struct{
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
struct Cyc_Absyn_VarargCallInfo{ int num_varargs; struct Cyc_List_List*
injectors; struct Cyc_Absyn_VarargInfo* vai; } ; static const int Cyc_Absyn_Const_e=
0; struct Cyc_Absyn_Const_e_struct{ int tag; void* f1; } ; static const int Cyc_Absyn_Var_e=
1; struct Cyc_Absyn_Var_e_struct{ int tag; struct _tuple1* f1; void* f2; } ;
static const int Cyc_Absyn_UnknownId_e= 2; struct Cyc_Absyn_UnknownId_e_struct{
int tag; struct _tuple1* f1; } ; static const int Cyc_Absyn_Primop_e= 3; struct
Cyc_Absyn_Primop_e_struct{ int tag; void* f1; struct Cyc_List_List* f2; } ;
static const int Cyc_Absyn_AssignOp_e= 4; struct Cyc_Absyn_AssignOp_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_Core_Opt* f2; struct Cyc_Absyn_Exp*
f3; } ; static const int Cyc_Absyn_Increment_e= 5; struct Cyc_Absyn_Increment_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; void* f2; } ; static const int Cyc_Absyn_Conditional_e=
6; struct Cyc_Absyn_Conditional_e_struct{ int tag; struct Cyc_Absyn_Exp* f1;
struct Cyc_Absyn_Exp* f2; struct Cyc_Absyn_Exp* f3; } ; static const int Cyc_Absyn_SeqExp_e=
7; struct Cyc_Absyn_SeqExp_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; struct
Cyc_Absyn_Exp* f2; } ; static const int Cyc_Absyn_UnknownCall_e= 8; struct Cyc_Absyn_UnknownCall_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_FnCall_e= 9; struct Cyc_Absyn_FnCall_e_struct{ int tag; struct Cyc_Absyn_Exp*
f1; struct Cyc_List_List* f2; struct Cyc_Absyn_VarargCallInfo* f3; } ; static
const int Cyc_Absyn_Throw_e= 10; struct Cyc_Absyn_Throw_e_struct{ int tag;
struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_NoInstantiate_e= 11;
struct Cyc_Absyn_NoInstantiate_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
static const int Cyc_Absyn_Instantiate_e= 12; struct Cyc_Absyn_Instantiate_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_Cast_e= 13; struct Cyc_Absyn_Cast_e_struct{ int tag; void* f1;
struct Cyc_Absyn_Exp* f2; } ; static const int Cyc_Absyn_Address_e= 14; struct
Cyc_Absyn_Address_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ; static const
int Cyc_Absyn_New_e= 15; struct Cyc_Absyn_New_e_struct{ int tag; struct Cyc_Absyn_Exp*
f1; struct Cyc_Absyn_Exp* f2; } ; static const int Cyc_Absyn_Sizeoftyp_e= 16;
struct Cyc_Absyn_Sizeoftyp_e_struct{ int tag; void* f1; } ; static const int Cyc_Absyn_Sizeofexp_e=
17; struct Cyc_Absyn_Sizeofexp_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
static const int Cyc_Absyn_Offsetof_e= 18; struct Cyc_Absyn_Offsetof_e_struct{
int tag; void* f1; struct _tagged_string* f2; } ; static const int Cyc_Absyn_Deref_e=
19; struct Cyc_Absyn_Deref_e_struct{ int tag; struct Cyc_Absyn_Exp* f1; } ;
static const int Cyc_Absyn_StructMember_e= 20; struct Cyc_Absyn_StructMember_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; struct _tagged_string* f2; } ; static const
int Cyc_Absyn_StructArrow_e= 21; struct Cyc_Absyn_StructArrow_e_struct{ int tag;
struct Cyc_Absyn_Exp* f1; struct _tagged_string* f2; } ; static const int Cyc_Absyn_Subscript_e=
22; struct Cyc_Absyn_Subscript_e_struct{ int tag; struct Cyc_Absyn_Exp* f1;
struct Cyc_Absyn_Exp* f2; } ; static const int Cyc_Absyn_Tuple_e= 23; struct Cyc_Absyn_Tuple_e_struct{
int tag; struct Cyc_List_List* f1; } ; static const int Cyc_Absyn_CompoundLit_e=
24; struct _tuple2{ struct Cyc_Core_Opt* f1; struct Cyc_Absyn_Tqual f2; void* f3;
} ; struct Cyc_Absyn_CompoundLit_e_struct{ int tag; struct _tuple2* f1; struct
Cyc_List_List* f2; } ; static const int Cyc_Absyn_Array_e= 25; struct Cyc_Absyn_Array_e_struct{
int tag; struct Cyc_List_List* f1; } ; static const int Cyc_Absyn_Comprehension_e=
26; struct Cyc_Absyn_Comprehension_e_struct{ int tag; struct Cyc_Absyn_Vardecl*
f1; struct Cyc_Absyn_Exp* f2; struct Cyc_Absyn_Exp* f3; } ; static const int Cyc_Absyn_Struct_e=
27; struct Cyc_Absyn_Struct_e_struct{ int tag; struct _tuple1* f1; struct Cyc_Core_Opt*
f2; struct Cyc_List_List* f3; struct Cyc_Absyn_Structdecl* f4; } ; static const
int Cyc_Absyn_AnonStruct_e= 28; struct Cyc_Absyn_AnonStruct_e_struct{ int tag;
void* f1; struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_Tunion_e= 29;
struct Cyc_Absyn_Tunion_e_struct{ int tag; struct Cyc_Core_Opt* f1; struct Cyc_Core_Opt*
f2; struct Cyc_List_List* f3; struct Cyc_Absyn_Tuniondecl* f4; struct Cyc_Absyn_Tunionfield*
f5; } ; static const int Cyc_Absyn_Enum_e= 30; struct Cyc_Absyn_Enum_e_struct{
int tag; struct _tuple1* f1; struct Cyc_Absyn_Enumdecl* f2; struct Cyc_Absyn_Enumfield*
f3; } ; static const int Cyc_Absyn_Malloc_e= 31; struct Cyc_Absyn_Malloc_e_struct{
int tag; struct Cyc_Absyn_Exp* f1; void* f2; } ; static const int Cyc_Absyn_UnresolvedMem_e=
32; struct Cyc_Absyn_UnresolvedMem_e_struct{ int tag; struct Cyc_Core_Opt* f1;
struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_StmtExp_e= 33; struct
Cyc_Absyn_StmtExp_e_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; static const
int Cyc_Absyn_Codegen_e= 34; struct Cyc_Absyn_Codegen_e_struct{ int tag; struct
Cyc_Absyn_Fndecl* f1; } ; static const int Cyc_Absyn_Fill_e= 35; struct Cyc_Absyn_Fill_e_struct{
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
int Cyc_Absyn_SwitchC_s= 10; struct Cyc_Absyn_SwitchC_s_struct{ int tag; struct
Cyc_Absyn_Exp* f1; struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_Fallthru_s=
11; struct Cyc_Absyn_Fallthru_s_struct{ int tag; struct Cyc_List_List* f1;
struct Cyc_Absyn_Switch_clause** f2; } ; static const int Cyc_Absyn_Decl_s= 12;
struct Cyc_Absyn_Decl_s_struct{ int tag; struct Cyc_Absyn_Decl* f1; struct Cyc_Absyn_Stmt*
f2; } ; static const int Cyc_Absyn_Cut_s= 13; struct Cyc_Absyn_Cut_s_struct{ int
tag; struct Cyc_Absyn_Stmt* f1; } ; static const int Cyc_Absyn_Splice_s= 14;
struct Cyc_Absyn_Splice_s_struct{ int tag; struct Cyc_Absyn_Stmt* f1; } ; static
const int Cyc_Absyn_Label_s= 15; struct Cyc_Absyn_Label_s_struct{ int tag;
struct _tagged_string* f1; struct Cyc_Absyn_Stmt* f2; } ; static const int Cyc_Absyn_Do_s=
16; struct Cyc_Absyn_Do_s_struct{ int tag; struct Cyc_Absyn_Stmt* f1; struct
_tuple3 f2; } ; static const int Cyc_Absyn_TryCatch_s= 17; struct Cyc_Absyn_TryCatch_s_struct{
int tag; struct Cyc_Absyn_Stmt* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_Region_s= 18; struct Cyc_Absyn_Region_s_struct{ int tag; struct
Cyc_Absyn_Tvar* f1; struct Cyc_Absyn_Vardecl* f2; struct Cyc_Absyn_Stmt* f3; } ;
struct Cyc_Absyn_Stmt{ void* r; struct Cyc_Position_Segment* loc; struct Cyc_List_List*
non_local_preds; int try_depth; void* annot; } ; static const int Cyc_Absyn_Wild_p=
0; static const int Cyc_Absyn_Var_p= 0; struct Cyc_Absyn_Var_p_struct{ int tag;
struct Cyc_Absyn_Vardecl* f1; } ; static const int Cyc_Absyn_Null_p= 1; static
const int Cyc_Absyn_Int_p= 1; struct Cyc_Absyn_Int_p_struct{ int tag; void* f1;
int f2; } ; static const int Cyc_Absyn_Char_p= 2; struct Cyc_Absyn_Char_p_struct{
int tag; unsigned char f1; } ; static const int Cyc_Absyn_Float_p= 3; struct Cyc_Absyn_Float_p_struct{
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
body; struct Cyc_Position_Segment* loc; } ; struct Cyc_Absyn_SwitchC_clause{
struct Cyc_Absyn_Exp* cnst_exp; struct Cyc_Absyn_Stmt* body; struct Cyc_Position_Segment*
loc; } ; static const int Cyc_Absyn_Unresolved_b= 0; static const int Cyc_Absyn_Global_b=
0; struct Cyc_Absyn_Global_b_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ;
static const int Cyc_Absyn_Funname_b= 1; struct Cyc_Absyn_Funname_b_struct{ int
tag; struct Cyc_Absyn_Fndecl* f1; } ; static const int Cyc_Absyn_Param_b= 2;
struct Cyc_Absyn_Param_b_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ;
static const int Cyc_Absyn_Local_b= 3; struct Cyc_Absyn_Local_b_struct{ int tag;
struct Cyc_Absyn_Vardecl* f1; } ; static const int Cyc_Absyn_Pat_b= 4; struct
Cyc_Absyn_Pat_b_struct{ int tag; struct Cyc_Absyn_Vardecl* f1; } ; struct Cyc_Absyn_Vardecl{
void* sc; struct _tuple1* name; struct Cyc_Absyn_Tqual tq; void* type; struct
Cyc_Absyn_Exp* initializer; struct Cyc_Core_Opt* rgn; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_Fndecl{ void* sc; int is_inline; struct _tuple1*
name; struct Cyc_List_List* tvs; struct Cyc_Core_Opt* effect; void* ret_type;
struct Cyc_List_List* args; int c_varargs; struct Cyc_Absyn_VarargInfo*
cyc_varargs; struct Cyc_List_List* rgn_po; struct Cyc_Absyn_Stmt* body; struct
Cyc_Core_Opt* cached_typ; struct Cyc_Core_Opt* param_vardecls; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_Structfield{ struct _tagged_string* name;
struct Cyc_Absyn_Tqual tq; void* type; struct Cyc_Core_Opt* width; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_Structdecl{ void* sc; struct Cyc_Core_Opt* name;
struct Cyc_List_List* tvs; struct Cyc_Core_Opt* fields; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_Uniondecl{ void* sc; struct Cyc_Core_Opt* name;
struct Cyc_List_List* tvs; struct Cyc_Core_Opt* fields; struct Cyc_List_List*
attributes; } ; struct Cyc_Absyn_Tunionfield{ struct _tuple1* name; struct Cyc_List_List*
tvs; struct Cyc_List_List* typs; struct Cyc_Position_Segment* loc; void* sc; } ;
struct Cyc_Absyn_Tuniondecl{ void* sc; struct _tuple1* name; struct Cyc_List_List*
tvs; struct Cyc_Core_Opt* fields; int is_xtunion; } ; struct Cyc_Absyn_Enumfield{
struct _tuple1* name; struct Cyc_Absyn_Exp* tag; struct Cyc_Position_Segment*
loc; } ; struct Cyc_Absyn_Enumdecl{ void* sc; struct _tuple1* name; struct Cyc_Core_Opt*
fields; } ; struct Cyc_Absyn_Typedefdecl{ struct _tuple1* name; struct Cyc_List_List*
tvs; void* defn; } ; static const int Cyc_Absyn_Var_d= 0; struct Cyc_Absyn_Var_d_struct{
int tag; struct Cyc_Absyn_Vardecl* f1; } ; static const int Cyc_Absyn_Fn_d= 1;
struct Cyc_Absyn_Fn_d_struct{ int tag; struct Cyc_Absyn_Fndecl* f1; } ; static
const int Cyc_Absyn_Let_d= 2; struct Cyc_Absyn_Let_d_struct{ int tag; struct Cyc_Absyn_Pat*
f1; struct Cyc_Core_Opt* f2; struct Cyc_Core_Opt* f3; struct Cyc_Absyn_Exp* f4;
int f5; } ; static const int Cyc_Absyn_Letv_d= 3; struct Cyc_Absyn_Letv_d_struct{
int tag; struct Cyc_List_List* f1; } ; static const int Cyc_Absyn_Struct_d= 4;
struct Cyc_Absyn_Struct_d_struct{ int tag; struct Cyc_Absyn_Structdecl* f1; } ;
static const int Cyc_Absyn_Union_d= 5; struct Cyc_Absyn_Union_d_struct{ int tag;
struct Cyc_Absyn_Uniondecl* f1; } ; static const int Cyc_Absyn_Tunion_d= 6;
struct Cyc_Absyn_Tunion_d_struct{ int tag; struct Cyc_Absyn_Tuniondecl* f1; } ;
static const int Cyc_Absyn_Enum_d= 7; struct Cyc_Absyn_Enum_d_struct{ int tag;
struct Cyc_Absyn_Enumdecl* f1; } ; static const int Cyc_Absyn_Typedef_d= 8;
struct Cyc_Absyn_Typedef_d_struct{ int tag; struct Cyc_Absyn_Typedefdecl* f1; }
; static const int Cyc_Absyn_Namespace_d= 9; struct Cyc_Absyn_Namespace_d_struct{
int tag; struct _tagged_string* f1; struct Cyc_List_List* f2; } ; static const
int Cyc_Absyn_Using_d= 10; struct Cyc_Absyn_Using_d_struct{ int tag; struct
_tuple1* f1; struct Cyc_List_List* f2; } ; static const int Cyc_Absyn_ExternC_d=
11; struct Cyc_Absyn_ExternC_d_struct{ int tag; struct Cyc_List_List* f1; } ;
struct Cyc_Absyn_Decl{ void* r; struct Cyc_Position_Segment* loc; } ; static
const int Cyc_Absyn_ArrayElement= 0; struct Cyc_Absyn_ArrayElement_struct{ int
tag; struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_Absyn_FieldName= 1;
struct Cyc_Absyn_FieldName_struct{ int tag; struct _tagged_string* f1; } ;
extern unsigned char Cyc_Absyn_EmptyAnnot[ 15u]; extern struct Cyc_Absyn_Tqual
Cyc_Absyn_const_tqual(); extern struct Cyc_Absyn_Tqual Cyc_Absyn_empty_tqual();
extern struct Cyc_Absyn_Conref* Cyc_Absyn_new_conref( void* x); extern struct
Cyc_Absyn_Conref* Cyc_Absyn_empty_conref(); extern struct Cyc_Absyn_Conref* Cyc_Absyn_compress_conref(
struct Cyc_Absyn_Conref* x); extern void* Cyc_Absyn_conref_val( struct Cyc_Absyn_Conref*
x); extern void* Cyc_Absyn_new_evar( struct Cyc_Core_Opt* k, struct Cyc_Core_Opt*
tenv); extern void* Cyc_Absyn_wildtyp( struct Cyc_Core_Opt*); extern void* Cyc_Absyn_uchar_t;
extern void* Cyc_Absyn_ushort_t; extern void* Cyc_Absyn_uint_t; extern void* Cyc_Absyn_ulong_t;
extern void* Cyc_Absyn_schar_t; extern void* Cyc_Absyn_sshort_t; extern void*
Cyc_Absyn_sint_t; extern void* Cyc_Absyn_slong_t; extern void* Cyc_Absyn_float_t;
extern void* Cyc_Absyn_exn_typ; extern void* Cyc_Absyn_string_typ( void* rgn);
extern void* Cyc_Absyn_file_typ(); extern void* Cyc_Absyn_atb_typ( void* t, void*
rgn, struct Cyc_Absyn_Tqual tq, void* b); extern void* Cyc_Absyn_star_typ( void*
t, void* rgn, struct Cyc_Absyn_Tqual tq); extern void* Cyc_Absyn_at_typ( void* t,
void* rgn, struct Cyc_Absyn_Tqual tq); extern struct Cyc_Absyn_Exp* Cyc_Absyn_new_exp(
void*, struct Cyc_Position_Segment*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_copy_exp(
struct Cyc_Absyn_Exp*); extern struct Cyc_Absyn_Exp* Cyc_Absyn_uint_exp(
unsigned int, struct Cyc_Position_Segment*); extern void* Cyc_Absyn_pointer_expand(
void*); extern int Cyc_Absyn_is_lvalue( struct Cyc_Absyn_Exp*); extern struct
Cyc_Absyn_Structfield* Cyc_Absyn_lookup_field( struct Cyc_List_List*, struct
_tagged_string*); extern struct Cyc_Absyn_Structfield* Cyc_Absyn_lookup_struct_field(
struct Cyc_Absyn_Structdecl*, struct _tagged_string*); extern struct Cyc_Absyn_Structfield*
Cyc_Absyn_lookup_union_field( struct Cyc_Absyn_Uniondecl*, struct _tagged_string*);
struct Cyc_Stdio___sFILE; extern unsigned char Cyc_Stdio_FileCloseError[ 19u];
extern unsigned char Cyc_Stdio_FileOpenError[ 18u]; struct Cyc_Stdio_FileOpenError_struct{
unsigned char* tag; struct _tagged_string f1; } ; extern int Cyc_String_zstrcmp(
struct _tagged_string, struct _tagged_string); struct Cyc_PP_Ppstate; struct Cyc_PP_Out;
struct Cyc_PP_Doc; struct Cyc_Absynpp_Params{ int expand_typedefs: 1; int
qvar_to_Cids: 1; int add_cyc_prefix: 1; int to_VC: 1; int decls_first: 1; int
rewrite_temp_tvars: 1; int print_all_tvars: 1; int print_all_kinds: 1; int
print_using_stmts: 1; int print_externC_stmts: 1; int print_full_evars: 1; int
use_curr_namespace: 1; struct Cyc_List_List* curr_namespace; } ; extern struct
_tagged_string Cyc_Absynpp_typ2string( void*); extern struct _tagged_string Cyc_Absynpp_qvar2string(
struct _tuple1*); struct Cyc_Set_Set; extern unsigned char Cyc_Set_Absent[ 11u];
struct Cyc_Dict_Dict; extern unsigned char Cyc_Dict_Present[ 12u]; extern
unsigned char Cyc_Dict_Absent[ 11u]; static const int Cyc_Tcenv_VarRes= 0;
struct Cyc_Tcenv_VarRes_struct{ int tag; void* f1; } ; static const int Cyc_Tcenv_StructRes=
1; struct Cyc_Tcenv_StructRes_struct{ int tag; struct Cyc_Absyn_Structdecl* f1;
} ; static const int Cyc_Tcenv_TunionRes= 2; struct Cyc_Tcenv_TunionRes_struct{
int tag; struct Cyc_Absyn_Tuniondecl* f1; struct Cyc_Absyn_Tunionfield* f2; } ;
static const int Cyc_Tcenv_EnumRes= 3; struct Cyc_Tcenv_EnumRes_struct{ int tag;
struct Cyc_Absyn_Enumdecl* f1; struct Cyc_Absyn_Enumfield* f2; } ; struct Cyc_Tcenv_Genv{
struct Cyc_Set_Set* namespaces; struct Cyc_Dict_Dict* structdecls; struct Cyc_Dict_Dict*
uniondecls; struct Cyc_Dict_Dict* tuniondecls; struct Cyc_Dict_Dict* enumdecls;
struct Cyc_Dict_Dict* typedefs; struct Cyc_Dict_Dict* ordinaries; struct Cyc_List_List*
availables; } ; struct Cyc_Tcenv_Fenv; static const int Cyc_Tcenv_NotLoop_j= 0;
static const int Cyc_Tcenv_CaseEnd_j= 1; static const int Cyc_Tcenv_FnEnd_j= 2;
static const int Cyc_Tcenv_Stmt_j= 0; struct Cyc_Tcenv_Stmt_j_struct{ int tag;
struct Cyc_Absyn_Stmt* f1; } ; static const int Cyc_Tcenv_Outermost= 0; struct
Cyc_Tcenv_Outermost_struct{ int tag; void* f1; } ; static const int Cyc_Tcenv_Frame=
1; struct Cyc_Tcenv_Frame_struct{ int tag; void* f1; void* f2; } ; static const
int Cyc_Tcenv_Hidden= 2; struct Cyc_Tcenv_Hidden_struct{ int tag; void* f1; void*
f2; } ; struct Cyc_Tcenv_Tenv{ struct Cyc_List_List* ns; struct Cyc_Dict_Dict*
ae; struct Cyc_Core_Opt* le; } ; extern void* Cyc_Tcenv_lookup_ordinary( struct
Cyc_Tcenv_Tenv*, struct Cyc_Position_Segment*, struct _tuple1*); extern struct
Cyc_Absyn_Structdecl** Cyc_Tcenv_lookup_structdecl( struct Cyc_Tcenv_Tenv*,
struct Cyc_Position_Segment*, struct _tuple1*); extern struct Cyc_Absyn_Tuniondecl**
Cyc_Tcenv_lookup_tuniondecl( struct Cyc_Tcenv_Tenv*, struct Cyc_Position_Segment*,
struct _tuple1*); extern struct Cyc_Tcenv_Tenv* Cyc_Tcenv_add_local_var( struct
Cyc_Position_Segment*, struct Cyc_Tcenv_Tenv*, struct Cyc_Absyn_Vardecl*);
extern struct Cyc_List_List* Cyc_Tcenv_lookup_type_vars( struct Cyc_Tcenv_Tenv*);
extern struct Cyc_Absyn_Stmt* Cyc_Tcenv_get_encloser( struct Cyc_Tcenv_Tenv*);
extern struct Cyc_Tcenv_Tenv* Cyc_Tcenv_set_encloser( struct Cyc_Tcenv_Tenv*,
struct Cyc_Absyn_Stmt*); extern struct Cyc_Tcenv_Tenv* Cyc_Tcenv_new_block(
struct Cyc_Position_Segment*, struct Cyc_Tcenv_Tenv*); extern void* Cyc_Tcenv_curr_rgn(
struct Cyc_Tcenv_Tenv*); extern void Cyc_Tcenv_check_rgn_accessible( struct Cyc_Tcenv_Tenv*,
struct Cyc_Position_Segment*, void* rgn); extern void Cyc_Tcenv_check_effect_accessible(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void* eff); extern
void Cyc_Tcenv_check_rgn_partial_order( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment*
loc, struct Cyc_List_List* po); extern unsigned char Cyc_Tcutil_TypeErr[ 12u];
extern void* Cyc_Tcutil_impos( struct _tagged_string); extern void Cyc_Tcutil_terr(
struct Cyc_Position_Segment*, struct _tagged_string); extern void Cyc_Tcutil_warn(
struct Cyc_Position_Segment*, struct _tagged_string); extern void* Cyc_Tcutil_compress(
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
Cyc_Position_Segment*, void*, void*); extern int Cyc_Tcutil_is_integral( struct
Cyc_Absyn_Exp*); extern int Cyc_Tcutil_is_numeric( struct Cyc_Absyn_Exp*);
extern void* Cyc_Tcutil_max_arithmetic_type( void*, void*); extern int Cyc_Tcutil_unify(
void*, void*); extern void* Cyc_Tcutil_substitute( struct Cyc_List_List*, void*);
extern void* Cyc_Tcutil_rsubstitute( struct _RegionHandle*, struct Cyc_List_List*,
void*); extern void* Cyc_Tcutil_fndecl2typ( struct Cyc_Absyn_Fndecl*); struct
_tuple4{ struct Cyc_List_List* f1; struct _RegionHandle* f2; } ; struct _tuple5{
struct Cyc_Absyn_Tvar* f1; void* f2; } ; extern struct _tuple5* Cyc_Tcutil_r_make_inst_var(
struct _tuple4*, struct Cyc_Absyn_Tvar*); extern void Cyc_Tcutil_check_contains_assign(
struct Cyc_Absyn_Exp*); extern void Cyc_Tcutil_check_type( struct Cyc_Position_Segment*,
struct Cyc_Tcenv_Tenv*, struct Cyc_List_List* bound_tvars, void* k, void*);
extern void Cyc_Tcutil_check_nonzero_bound( struct Cyc_Position_Segment*, struct
Cyc_Absyn_Conref*); extern void Cyc_Tcutil_check_bound( struct Cyc_Position_Segment*,
unsigned int i, struct Cyc_Absyn_Conref*); extern struct Cyc_List_List* Cyc_Tcutil_resolve_struct_designators(
struct _RegionHandle* rgn, struct Cyc_Position_Segment* loc, struct Cyc_List_List*
des, struct Cyc_List_List* fields); extern int Cyc_Tcutil_is_tagged_pointer_typ(
void*); struct _tuple6{ int f1; void* f2; } ; extern struct _tuple6 Cyc_Tcutil_addressof_props(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e); extern int Cyc_Tcutil_is_const_exp(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e); extern unsigned int Cyc_Evexp_eval_const_uint_exp(
struct Cyc_Absyn_Exp* e); extern int Cyc_Evexp_okay_szofarg( void* t); extern
void Cyc_Tcstmt_tcStmt( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Stmt* s, int
new_block); extern struct Cyc_List_List* Cyc_Formatstr_get_format_typs( struct
Cyc_Tcenv_Tenv*, struct _tagged_string, struct Cyc_Position_Segment*); extern
struct Cyc_List_List* Cyc_Formatstr_get_scanf_typs( struct Cyc_Tcenv_Tenv*,
struct _tagged_string, struct Cyc_Position_Segment*); extern void* Cyc_Tcexp_tcExp(
struct Cyc_Tcenv_Tenv*, void**, struct Cyc_Absyn_Exp*); extern void* Cyc_Tcexp_tcExpInitializer(
struct Cyc_Tcenv_Tenv*, void**, struct Cyc_Absyn_Exp*); extern void Cyc_Tcexp_tcTest(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e, struct _tagged_string
msg_part); struct Cyc_CfFlowInfo_Place; static const int Cyc_CfFlowInfo_VarRoot=
0; struct Cyc_CfFlowInfo_VarRoot_struct{ int tag; struct Cyc_Absyn_Vardecl* f1;
} ; static const int Cyc_CfFlowInfo_MallocPt= 1; struct Cyc_CfFlowInfo_MallocPt_struct{
int tag; struct Cyc_Absyn_Exp* f1; } ; static const int Cyc_CfFlowInfo_StructF=
0; struct Cyc_CfFlowInfo_StructF_struct{ int tag; struct _tagged_string* f1; } ;
static const int Cyc_CfFlowInfo_TupleF= 1; struct Cyc_CfFlowInfo_TupleF_struct{
int tag; int f1; } ; struct Cyc_CfFlowInfo_Place{ void* root; struct Cyc_List_List*
fields; } ; static const int Cyc_CfFlowInfo_Esc= 0; static const int Cyc_CfFlowInfo_Unesc=
1; static const int Cyc_CfFlowInfo_NoneIL= 0; static const int Cyc_CfFlowInfo_ThisIL=
1; static const int Cyc_CfFlowInfo_AllIL= 2; static const int Cyc_CfFlowInfo_UnknownIS=
0; struct Cyc_CfFlowInfo_UnknownIS_struct{ int tag; void* f1; void* f2; } ;
static const int Cyc_CfFlowInfo_MustPointTo= 1; struct Cyc_CfFlowInfo_MustPointTo_struct{
int tag; struct Cyc_CfFlowInfo_Place* f1; } ; static const int Cyc_CfFlowInfo_LeafPI=
0; struct Cyc_CfFlowInfo_LeafPI_struct{ int tag; void* f1; } ; static const int
Cyc_CfFlowInfo_TuplePI= 1; struct Cyc_CfFlowInfo_TuplePI_struct{ int tag; struct
Cyc_Dict_Dict* f1; } ; static const int Cyc_CfFlowInfo_StructPI= 2; struct Cyc_CfFlowInfo_StructPI_struct{
int tag; struct Cyc_Dict_Dict* f1; } ; static const int Cyc_CfFlowInfo_BottomFL=
0; static const int Cyc_CfFlowInfo_InitsFL= 0; struct Cyc_CfFlowInfo_InitsFL_struct{
int tag; struct Cyc_Dict_Dict* f1; } ; extern void Cyc_NewControlFlow_set_encloser(
struct Cyc_Absyn_Stmt* enclosee, struct Cyc_Absyn_Stmt* encloser); struct Cyc_NewControlFlow_AnalEnv{
struct Cyc_Dict_Dict* roots; int in_try; void* tryflow; } ; static void* Cyc_Tcexp_expr_err(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, struct
_tagged_string msg){ Cyc_Tcutil_terr( loc, msg); return Cyc_Absyn_wildtyp(({
struct Cyc_Core_Opt* _temp0=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp0->v=( void*) Cyc_Tcenv_lookup_type_vars( te); _temp0;}));}
static struct Cyc_Core_Opt Cyc_Tcexp_rk={( void*)(( void*) 3u)}; static struct
Cyc_Core_Opt Cyc_Tcexp_ak={( void*)(( void*) 0u)}; static struct Cyc_Core_Opt
Cyc_Tcexp_bk={( void*)(( void*) 2u)}; static struct Cyc_Core_Opt Cyc_Tcexp_mk={(
void*)(( void*) 1u)}; static void Cyc_Tcexp_resolve_unknown_id( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Absyn_Exp* e, struct _tuple1* q){ struct _handler_cons _temp1;
_push_handler(& _temp1);{ int _temp3= 0; if( setjmp( _temp1.handler)){ _temp3= 1;}
if( ! _temp3){{ void* _temp4= Cyc_Tcenv_lookup_ordinary( te, e->loc, q); void*
_temp14; struct Cyc_Absyn_Enumfield* _temp16; struct Cyc_Absyn_Enumdecl* _temp18;
struct Cyc_Absyn_Tunionfield* _temp20; struct Cyc_Absyn_Tuniondecl* _temp22;
struct Cyc_Absyn_Structdecl* _temp24; _LL6: if(*(( int*) _temp4) == Cyc_Tcenv_VarRes){
_LL15: _temp14=( void*)(( struct Cyc_Tcenv_VarRes_struct*) _temp4)->f1; goto
_LL7;} else{ goto _LL8;} _LL8: if(*(( int*) _temp4) == Cyc_Tcenv_EnumRes){ _LL19:
_temp18=(( struct Cyc_Tcenv_EnumRes_struct*) _temp4)->f1; goto _LL17; _LL17:
_temp16=(( struct Cyc_Tcenv_EnumRes_struct*) _temp4)->f2; goto _LL9;} else{ goto
_LL10;} _LL10: if(*(( int*) _temp4) == Cyc_Tcenv_TunionRes){ _LL23: _temp22=((
struct Cyc_Tcenv_TunionRes_struct*) _temp4)->f1; goto _LL21; _LL21: _temp20=((
struct Cyc_Tcenv_TunionRes_struct*) _temp4)->f2; goto _LL11;} else{ goto _LL12;}
_LL12: if(*(( int*) _temp4) == Cyc_Tcenv_StructRes){ _LL25: _temp24=(( struct
Cyc_Tcenv_StructRes_struct*) _temp4)->f1; goto _LL13;} else{ goto _LL5;} _LL7:(
void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Var_e_struct* _temp26=( struct
Cyc_Absyn_Var_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Var_e_struct));
_temp26[ 0]=({ struct Cyc_Absyn_Var_e_struct _temp27; _temp27.tag= Cyc_Absyn_Var_e;
_temp27.f1= q; _temp27.f2=( void*) _temp14; _temp27;}); _temp26;}))); goto _LL5;
_LL9:( void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Enum_e_struct* _temp28=(
struct Cyc_Absyn_Enum_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Enum_e_struct));
_temp28[ 0]=({ struct Cyc_Absyn_Enum_e_struct _temp29; _temp29.tag= Cyc_Absyn_Enum_e;
_temp29.f1= q; _temp29.f2=( struct Cyc_Absyn_Enumdecl*) _temp18; _temp29.f3=(
struct Cyc_Absyn_Enumfield*) _temp16; _temp29;}); _temp28;}))); goto _LL5; _LL11:(
void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Tunion_e_struct* _temp30=(
struct Cyc_Absyn_Tunion_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Tunion_e_struct));
_temp30[ 0]=({ struct Cyc_Absyn_Tunion_e_struct _temp31; _temp31.tag= Cyc_Absyn_Tunion_e;
_temp31.f1= 0; _temp31.f2= 0; _temp31.f3= 0; _temp31.f4= _temp22; _temp31.f5=
_temp20; _temp31;}); _temp30;}))); goto _LL5; _LL13: Cyc_Tcutil_terr( e->loc,(
struct _tagged_string)({ struct _tagged_string _temp32= Cyc_Absynpp_qvar2string(
q); xprintf("bad occurrence of struct name %.*s", _temp32.last_plus_one -
_temp32.curr, _temp32.curr);}));( void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Var_e_struct*
_temp33=( struct Cyc_Absyn_Var_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Var_e_struct));
_temp33[ 0]=({ struct Cyc_Absyn_Var_e_struct _temp34; _temp34.tag= Cyc_Absyn_Var_e;
_temp34.f1= q; _temp34.f2=( void*)(( void*) Cyc_Absyn_Unresolved_b); _temp34;});
_temp33;}))); goto _LL5; _LL5:;}; _pop_handler();} else{ void* _temp2=( void*)
_exn_thrown; void* _temp36= _temp2; _LL38: if( _temp36 == Cyc_Dict_Absent){ goto
_LL39;} else{ goto _LL40;} _LL40: goto _LL41; _LL39:( void*)( e->r=( void*)((
void*)({ struct Cyc_Absyn_Var_e_struct* _temp42=( struct Cyc_Absyn_Var_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Var_e_struct)); _temp42[ 0]=({ struct Cyc_Absyn_Var_e_struct
_temp43; _temp43.tag= Cyc_Absyn_Var_e; _temp43.f1= q; _temp43.f2=( void*)(( void*)
Cyc_Absyn_Unresolved_b); _temp43;}); _temp42;}))); goto _LL37; _LL41:( void)
_throw( _temp36); _LL37:;}}} struct _tuple7{ struct Cyc_List_List* f1; struct
Cyc_Absyn_Exp* f2; } ; static struct _tuple7* Cyc_Tcexp_make_struct_arg( struct
Cyc_Absyn_Exp* e){ return({ struct _tuple7* _temp44=( struct _tuple7*) GC_malloc(
sizeof( struct _tuple7)); _temp44->f1= 0; _temp44->f2= e; _temp44;});} static
void Cyc_Tcexp_resolve_unknown_fn( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp*
e, struct Cyc_Absyn_Exp* e1, struct Cyc_List_List* es){ void* _temp45=( void*)
e1->r; struct _tuple1* _temp51; _LL47: if(*(( int*) _temp45) == Cyc_Absyn_UnknownId_e){
_LL52: _temp51=(( struct Cyc_Absyn_UnknownId_e_struct*) _temp45)->f1; goto _LL48;}
else{ goto _LL49;} _LL49: goto _LL50; _LL48: { struct _handler_cons _temp53;
_push_handler(& _temp53);{ int _temp55= 0; if( setjmp( _temp53.handler)){
_temp55= 1;} if( ! _temp55){{ void* _temp56= Cyc_Tcenv_lookup_ordinary( te, e1->loc,
_temp51); void* _temp66; struct Cyc_Absyn_Tunionfield* _temp68; struct Cyc_Absyn_Tuniondecl*
_temp70; struct Cyc_Absyn_Structdecl* _temp72; struct Cyc_Absyn_Enumfield*
_temp74; struct Cyc_Absyn_Enumdecl* _temp76; _LL58: if(*(( int*) _temp56) == Cyc_Tcenv_VarRes){
_LL67: _temp66=( void*)(( struct Cyc_Tcenv_VarRes_struct*) _temp56)->f1; goto
_LL59;} else{ goto _LL60;} _LL60: if(*(( int*) _temp56) == Cyc_Tcenv_TunionRes){
_LL71: _temp70=(( struct Cyc_Tcenv_TunionRes_struct*) _temp56)->f1; goto _LL69;
_LL69: _temp68=(( struct Cyc_Tcenv_TunionRes_struct*) _temp56)->f2; goto _LL61;}
else{ goto _LL62;} _LL62: if(*(( int*) _temp56) == Cyc_Tcenv_StructRes){ _LL73:
_temp72=(( struct Cyc_Tcenv_StructRes_struct*) _temp56)->f1; goto _LL63;} else{
goto _LL64;} _LL64: if(*(( int*) _temp56) == Cyc_Tcenv_EnumRes){ _LL77: _temp76=((
struct Cyc_Tcenv_EnumRes_struct*) _temp56)->f1; goto _LL75; _LL75: _temp74=((
struct Cyc_Tcenv_EnumRes_struct*) _temp56)->f2; goto _LL65;} else{ goto _LL57;}
_LL59:( void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_FnCall_e_struct*
_temp78=( struct Cyc_Absyn_FnCall_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_FnCall_e_struct));
_temp78[ 0]=({ struct Cyc_Absyn_FnCall_e_struct _temp79; _temp79.tag= Cyc_Absyn_FnCall_e;
_temp79.f1= e1; _temp79.f2= es; _temp79.f3= 0; _temp79;}); _temp78;})));
_npop_handler( 0u); return; _LL61: if( _temp68->typs == 0){ Cyc_Tcutil_terr( e->loc,(
struct _tagged_string)({ struct _tagged_string _temp80= Cyc_Absynpp_qvar2string(
_temp68->name); xprintf("%.*s is a constant, not a function", _temp80.last_plus_one
- _temp80.curr, _temp80.curr);}));}( void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Tunion_e_struct*
_temp81=( struct Cyc_Absyn_Tunion_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Tunion_e_struct));
_temp81[ 0]=({ struct Cyc_Absyn_Tunion_e_struct _temp82; _temp82.tag= Cyc_Absyn_Tunion_e;
_temp82.f1= 0; _temp82.f2= 0; _temp82.f3= es; _temp82.f4= _temp70; _temp82.f5=
_temp68; _temp82;}); _temp81;}))); _npop_handler( 0u); return; _npop_handler( 0u);
return; _LL63: { struct Cyc_List_List* _temp83=(( struct Cyc_List_List*(*)(
struct _tuple7*(* f)( struct Cyc_Absyn_Exp*), struct Cyc_List_List* x)) Cyc_List_map)(
Cyc_Tcexp_make_struct_arg, es); goto _LL84; _LL84: if( _temp72->name != 0){(
void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Struct_e_struct* _temp85=(
struct Cyc_Absyn_Struct_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Struct_e_struct));
_temp85[ 0]=({ struct Cyc_Absyn_Struct_e_struct _temp86; _temp86.tag= Cyc_Absyn_Struct_e;
_temp86.f1=( struct _tuple1*)(( struct Cyc_Core_Opt*) _check_null( _temp72->name))->v;
_temp86.f2= 0; _temp86.f3= _temp83; _temp86.f4=( struct Cyc_Absyn_Structdecl*)
_temp72; _temp86;}); _temp85;})));} else{ Cyc_Tcutil_terr( e->loc,({
unsigned char* _temp87=( unsigned char*)"missing struct name"; struct
_tagged_string _temp88; _temp88.curr= _temp87; _temp88.base= _temp87; _temp88.last_plus_one=
_temp87 + 20; _temp88;}));( void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Struct_e_struct*
_temp89=( struct Cyc_Absyn_Struct_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Struct_e_struct));
_temp89[ 0]=({ struct Cyc_Absyn_Struct_e_struct _temp90; _temp90.tag= Cyc_Absyn_Struct_e;
_temp90.f1= _temp51; _temp90.f2= 0; _temp90.f3= _temp83; _temp90.f4=( struct Cyc_Absyn_Structdecl*)
_temp72; _temp90;}); _temp89;})));} _npop_handler( 0u); return;} _LL65: Cyc_Tcutil_terr(
e->loc,( struct _tagged_string)({ struct _tagged_string _temp91= Cyc_Absynpp_qvar2string(
_temp51); xprintf("%.*s is an enum constructor, not a function", _temp91.last_plus_one
- _temp91.curr, _temp91.curr);})); _npop_handler( 0u); return; _LL57:;};
_pop_handler();} else{ void* _temp54=( void*) _exn_thrown; void* _temp93=
_temp54; _LL95: if( _temp93 == Cyc_Dict_Absent){ goto _LL96;} else{ goto _LL97;}
_LL97: goto _LL98; _LL96: Cyc_Tcutil_terr( e1->loc,( struct _tagged_string)({
struct _tagged_string _temp99= Cyc_Absynpp_qvar2string( _temp51); xprintf("unbound identifier %.*s",
_temp99.last_plus_one - _temp99.curr, _temp99.curr);}));( void*)( e->r=( void*)((
void*)({ struct Cyc_Absyn_FnCall_e_struct* _temp100=( struct Cyc_Absyn_FnCall_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_FnCall_e_struct)); _temp100[ 0]=({ struct
Cyc_Absyn_FnCall_e_struct _temp101; _temp101.tag= Cyc_Absyn_FnCall_e; _temp101.f1=
e1; _temp101.f2= es; _temp101.f3= 0; _temp101;}); _temp100;}))); return; _LL98:(
void) _throw( _temp93); _LL94:;}}} _LL50:( void*)( e->r=( void*)(( void*)({
struct Cyc_Absyn_FnCall_e_struct* _temp102=( struct Cyc_Absyn_FnCall_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_FnCall_e_struct)); _temp102[ 0]=({ struct
Cyc_Absyn_FnCall_e_struct _temp103; _temp103.tag= Cyc_Absyn_FnCall_e; _temp103.f1=
e1; _temp103.f2= es; _temp103.f3= 0; _temp103;}); _temp102;}))); return; _LL46:;}
static void Cyc_Tcexp_resolve_unresolved_mem( struct Cyc_Tcenv_Tenv* te, struct
Cyc_Position_Segment* loc, void** topt, struct Cyc_Absyn_Exp* e, struct Cyc_List_List*
des){ if( topt == 0){( void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Array_e_struct*
_temp104=( struct Cyc_Absyn_Array_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Array_e_struct));
_temp104[ 0]=({ struct Cyc_Absyn_Array_e_struct _temp105; _temp105.tag= Cyc_Absyn_Array_e;
_temp105.f1= des; _temp105;}); _temp104;}))); return;}{ void* t=*(( void**)
_check_null( topt)); void* _temp106= Cyc_Tcutil_compress( t); struct Cyc_Absyn_Exp*
_temp116; struct Cyc_Absyn_Tqual _temp118; void* _temp120; struct Cyc_Absyn_Structdecl**
_temp122; struct Cyc_List_List* _temp124; struct _tuple1* _temp126; struct Cyc_List_List*
_temp128; _LL108: if(( unsigned int) _temp106 > 4u?*(( int*) _temp106) == Cyc_Absyn_ArrayType:
0){ _LL121: _temp120=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp106)->f1;
goto _LL119; _LL119: _temp118=(( struct Cyc_Absyn_ArrayType_struct*) _temp106)->f2;
goto _LL117; _LL117: _temp116=(( struct Cyc_Absyn_ArrayType_struct*) _temp106)->f3;
goto _LL109;} else{ goto _LL110;} _LL110: if(( unsigned int) _temp106 > 4u?*((
int*) _temp106) == Cyc_Absyn_StructType: 0){ _LL127: _temp126=(( struct Cyc_Absyn_StructType_struct*)
_temp106)->f1; goto _LL125; _LL125: _temp124=(( struct Cyc_Absyn_StructType_struct*)
_temp106)->f2; goto _LL123; _LL123: _temp122=(( struct Cyc_Absyn_StructType_struct*)
_temp106)->f3; goto _LL111;} else{ goto _LL112;} _LL112: if(( unsigned int)
_temp106 > 4u?*(( int*) _temp106) == Cyc_Absyn_AnonStructType: 0){ _LL129:
_temp128=(( struct Cyc_Absyn_AnonStructType_struct*) _temp106)->f1; goto _LL113;}
else{ goto _LL114;} _LL114: goto _LL115; _LL109:( void*)( e->r=( void*)(( void*)({
struct Cyc_Absyn_Array_e_struct* _temp130=( struct Cyc_Absyn_Array_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Array_e_struct)); _temp130[ 0]=({ struct Cyc_Absyn_Array_e_struct
_temp131; _temp131.tag= Cyc_Absyn_Array_e; _temp131.f1= des; _temp131;});
_temp130;}))); goto _LL107; _LL111: if( _temp122 == 0? 1: _temp126 == 0){ Cyc_Tcutil_terr(
loc,({ unsigned char* _temp132=( unsigned char*)"Compiler bug: struct type not properly set";
struct _tagged_string _temp133; _temp133.curr= _temp132; _temp133.base= _temp132;
_temp133.last_plus_one= _temp132 + 43; _temp133;}));}( void*)( e->r=( void*)((
void*)({ struct Cyc_Absyn_Struct_e_struct* _temp134=( struct Cyc_Absyn_Struct_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Struct_e_struct)); _temp134[ 0]=({ struct
Cyc_Absyn_Struct_e_struct _temp135; _temp135.tag= Cyc_Absyn_Struct_e; _temp135.f1=(
struct _tuple1*) _check_null( _temp126); _temp135.f2= 0; _temp135.f3= des;
_temp135.f4=( struct Cyc_Absyn_Structdecl*)*(( struct Cyc_Absyn_Structdecl**)
_check_null( _temp122)); _temp135;}); _temp134;}))); goto _LL107; _LL113:( void*)(
e->r=( void*)(( void*)({ struct Cyc_Absyn_AnonStruct_e_struct* _temp136=( struct
Cyc_Absyn_AnonStruct_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_AnonStruct_e_struct));
_temp136[ 0]=({ struct Cyc_Absyn_AnonStruct_e_struct _temp137; _temp137.tag= Cyc_Absyn_AnonStruct_e;
_temp137.f1=( void*) t; _temp137.f2= des; _temp137;}); _temp136;}))); goto
_LL107; _LL115:( void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Array_e_struct*
_temp138=( struct Cyc_Absyn_Array_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Array_e_struct));
_temp138[ 0]=({ struct Cyc_Absyn_Array_e_struct _temp139; _temp139.tag= Cyc_Absyn_Array_e;
_temp139.f1= des; _temp139;}); _temp138;}))); goto _LL107; _LL107:;}} static
void Cyc_Tcexp_tcExpNoInst( struct Cyc_Tcenv_Tenv* te, void** topt, struct Cyc_Absyn_Exp*
e); static void* Cyc_Tcexp_tcExpNoPromote( struct Cyc_Tcenv_Tenv* te, void**
topt, struct Cyc_Absyn_Exp* e); static void Cyc_Tcexp_tcExpList( struct Cyc_Tcenv_Tenv*
te, struct Cyc_List_List* es){ for( 0; es != 0; es=(( struct Cyc_List_List*)
_check_null( es))->tl){ Cyc_Tcexp_tcExp( te, 0,( struct Cyc_Absyn_Exp*)(( struct
Cyc_List_List*) _check_null( es))->hd);}} void Cyc_Tcexp_tcTest( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Absyn_Exp* e, struct _tagged_string msg_part){ Cyc_Tcutil_check_contains_assign(
e); Cyc_Tcexp_tcExp( te,( void**)& Cyc_Absyn_sint_t, e); if( ! Cyc_Tcutil_coerce_to_bool(
te, e)){ Cyc_Tcutil_terr( e->loc,( struct _tagged_string)({ struct
_tagged_string _temp140= msg_part; struct _tagged_string _temp141= Cyc_Absynpp_typ2string((
void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v); xprintf("test of %.*s has type %.*s instead of integral or * type",
_temp140.last_plus_one - _temp140.curr, _temp140.curr, _temp141.last_plus_one -
_temp141.curr, _temp141.curr);}));}} static void* Cyc_Tcexp_tcConst( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void** topt, void* c, struct Cyc_Absyn_Exp*
e){ void* t;{ void* _temp142= c; unsigned char _temp158; void* _temp160; short
_temp162; void* _temp164; long long _temp166; void* _temp168; struct
_tagged_string _temp170; int _temp172; void* _temp174; struct _tagged_string
_temp176; _LL144: if(( unsigned int) _temp142 > 1u?*(( int*) _temp142) == Cyc_Absyn_Char_c:
0){ _LL161: _temp160=( void*)(( struct Cyc_Absyn_Char_c_struct*) _temp142)->f1;
goto _LL159; _LL159: _temp158=(( struct Cyc_Absyn_Char_c_struct*) _temp142)->f2;
goto _LL145;} else{ goto _LL146;} _LL146: if(( unsigned int) _temp142 > 1u?*((
int*) _temp142) == Cyc_Absyn_Short_c: 0){ _LL165: _temp164=( void*)(( struct Cyc_Absyn_Short_c_struct*)
_temp142)->f1; goto _LL163; _LL163: _temp162=(( struct Cyc_Absyn_Short_c_struct*)
_temp142)->f2; goto _LL147;} else{ goto _LL148;} _LL148: if(( unsigned int)
_temp142 > 1u?*(( int*) _temp142) == Cyc_Absyn_LongLong_c: 0){ _LL169: _temp168=(
void*)(( struct Cyc_Absyn_LongLong_c_struct*) _temp142)->f1; goto _LL167; _LL167:
_temp166=(( struct Cyc_Absyn_LongLong_c_struct*) _temp142)->f2; goto _LL149;}
else{ goto _LL150;} _LL150: if(( unsigned int) _temp142 > 1u?*(( int*) _temp142)
== Cyc_Absyn_Float_c: 0){ _LL171: _temp170=(( struct Cyc_Absyn_Float_c_struct*)
_temp142)->f1; goto _LL151;} else{ goto _LL152;} _LL152: if(( unsigned int)
_temp142 > 1u?*(( int*) _temp142) == Cyc_Absyn_Int_c: 0){ _LL175: _temp174=(
void*)(( struct Cyc_Absyn_Int_c_struct*) _temp142)->f1; goto _LL173; _LL173:
_temp172=(( struct Cyc_Absyn_Int_c_struct*) _temp142)->f2; goto _LL153;} else{
goto _LL154;} _LL154: if(( unsigned int) _temp142 > 1u?*(( int*) _temp142) ==
Cyc_Absyn_String_c: 0){ _LL177: _temp176=(( struct Cyc_Absyn_String_c_struct*)
_temp142)->f1; goto _LL155;} else{ goto _LL156;} _LL156: if( _temp142 ==( void*)
Cyc_Absyn_Null_c){ goto _LL157;} else{ goto _LL143;} _LL145: t= _temp160 ==(
void*) Cyc_Absyn_Unsigned? Cyc_Absyn_uchar_t: Cyc_Absyn_schar_t; goto _LL143;
_LL147: t= _temp164 ==( void*) Cyc_Absyn_Unsigned? Cyc_Absyn_ushort_t: Cyc_Absyn_sshort_t;
goto _LL143; _LL149: t= _temp168 ==( void*) Cyc_Absyn_Unsigned? Cyc_Absyn_ulong_t:
Cyc_Absyn_slong_t; goto _LL143; _LL151: t= Cyc_Absyn_float_t; goto _LL143;
_LL153: if( topt == 0){ t= _temp174 ==( void*) Cyc_Absyn_Unsigned? Cyc_Absyn_uint_t:
Cyc_Absyn_sint_t;} else{ void* _temp178= Cyc_Tcutil_compress(*(( void**)
_check_null( topt))); void* _temp188; void* _temp190; void* _temp192; void*
_temp194; void* _temp196; void* _temp198; _LL180: if(( unsigned int) _temp178 >
4u?*(( int*) _temp178) == Cyc_Absyn_IntType: 0){ _LL191: _temp190=( void*)((
struct Cyc_Absyn_IntType_struct*) _temp178)->f1; goto _LL189; _LL189: _temp188=(
void*)(( struct Cyc_Absyn_IntType_struct*) _temp178)->f2; if( _temp188 ==( void*)
Cyc_Absyn_B1){ goto _LL181;} else{ goto _LL182;}} else{ goto _LL182;} _LL182:
if(( unsigned int) _temp178 > 4u?*(( int*) _temp178) == Cyc_Absyn_IntType: 0){
_LL195: _temp194=( void*)(( struct Cyc_Absyn_IntType_struct*) _temp178)->f1;
goto _LL193; _LL193: _temp192=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp178)->f2; if( _temp192 ==( void*) Cyc_Absyn_B2){ goto _LL183;} else{ goto
_LL184;}} else{ goto _LL184;} _LL184: if(( unsigned int) _temp178 > 4u?*(( int*)
_temp178) == Cyc_Absyn_IntType: 0){ _LL199: _temp198=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp178)->f1; goto _LL197; _LL197: _temp196=( void*)(( struct Cyc_Absyn_IntType_struct*)
_temp178)->f2; goto _LL185;} else{ goto _LL186;} _LL186: goto _LL187; _LL181: t=
_temp190 ==( void*) Cyc_Absyn_Unsigned? Cyc_Absyn_uchar_t: Cyc_Absyn_schar_t;(
void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Const_e_struct* _temp200=(
struct Cyc_Absyn_Const_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct));
_temp200[ 0]=({ struct Cyc_Absyn_Const_e_struct _temp201; _temp201.tag= Cyc_Absyn_Const_e;
_temp201.f1=( void*)(( void*)({ struct Cyc_Absyn_Char_c_struct* _temp202=(
struct Cyc_Absyn_Char_c_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Char_c_struct));
_temp202[ 0]=({ struct Cyc_Absyn_Char_c_struct _temp203; _temp203.tag= Cyc_Absyn_Char_c;
_temp203.f1=( void*) _temp190; _temp203.f2=( unsigned char) _temp172; _temp203;});
_temp202;})); _temp201;}); _temp200;}))); goto _LL179; _LL183: t= _temp194 ==(
void*) Cyc_Absyn_Unsigned? Cyc_Absyn_ushort_t: Cyc_Absyn_sshort_t;( void*)( e->r=(
void*)(( void*)({ struct Cyc_Absyn_Const_e_struct* _temp204=( struct Cyc_Absyn_Const_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct)); _temp204[ 0]=({ struct Cyc_Absyn_Const_e_struct
_temp205; _temp205.tag= Cyc_Absyn_Const_e; _temp205.f1=( void*)(( void*)({
struct Cyc_Absyn_Short_c_struct* _temp206=( struct Cyc_Absyn_Short_c_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Short_c_struct)); _temp206[ 0]=({ struct Cyc_Absyn_Short_c_struct
_temp207; _temp207.tag= Cyc_Absyn_Short_c; _temp207.f1=( void*) _temp194;
_temp207.f2=( short) _temp172; _temp207;}); _temp206;})); _temp205;}); _temp204;})));
goto _LL179; _LL185: t= _temp198 ==( void*) Cyc_Absyn_Unsigned? Cyc_Absyn_uint_t:
Cyc_Absyn_sint_t; goto _LL179; _LL187: t= _temp174 ==( void*) Cyc_Absyn_Unsigned?
Cyc_Absyn_uint_t: Cyc_Absyn_sint_t; goto _LL179; _LL179:;} goto _LL143; _LL155: {
int len=( int)({ struct _tagged_string _temp250= _temp176;( unsigned int)(
_temp250.last_plus_one - _temp250.curr);}); struct Cyc_Absyn_Const_e_struct*
_temp212=({ struct Cyc_Absyn_Const_e_struct* _temp208=( struct Cyc_Absyn_Const_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct)); _temp208[ 0]=({ struct Cyc_Absyn_Const_e_struct
_temp209; _temp209.tag= Cyc_Absyn_Const_e; _temp209.f1=( void*)(( void*)({
struct Cyc_Absyn_Int_c_struct* _temp210=( struct Cyc_Absyn_Int_c_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Int_c_struct)); _temp210[ 0]=({ struct Cyc_Absyn_Int_c_struct
_temp211; _temp211.tag= Cyc_Absyn_Int_c; _temp211.f1=( void*)(( void*) Cyc_Absyn_Unsigned);
_temp211.f2= len; _temp211;}); _temp210;})); _temp209;}); _temp208;}); goto
_LL213; _LL213: { struct Cyc_Absyn_Exp* elen= Cyc_Absyn_new_exp(( void*)
_temp212, loc); elen->topt=({ struct Cyc_Core_Opt* _temp214=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp214->v=( void*) Cyc_Absyn_uint_t;
_temp214;}); t= Cyc_Absyn_atb_typ( Cyc_Absyn_uchar_t,( void*) Cyc_Absyn_HeapRgn,
Cyc_Absyn_const_tqual(),( void*)({ struct Cyc_Absyn_Upper_b_struct* _temp215=(
struct Cyc_Absyn_Upper_b_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct));
_temp215[ 0]=({ struct Cyc_Absyn_Upper_b_struct _temp216; _temp216.tag= Cyc_Absyn_Upper_b;
_temp216.f1= elen; _temp216;}); _temp215;})); if( topt != 0){ void* _temp217=
Cyc_Tcutil_compress(*(( void**) _check_null( topt))); struct Cyc_Absyn_Exp*
_temp225; struct Cyc_Absyn_Tqual _temp227; void* _temp229; struct Cyc_Absyn_PtrInfo
_temp231; struct Cyc_Absyn_Conref* _temp233; struct Cyc_Absyn_Tqual _temp235;
struct Cyc_Absyn_Conref* _temp237; void* _temp239; void* _temp241; _LL219: if((
unsigned int) _temp217 > 4u?*(( int*) _temp217) == Cyc_Absyn_ArrayType: 0){
_LL230: _temp229=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp217)->f1;
goto _LL228; _LL228: _temp227=(( struct Cyc_Absyn_ArrayType_struct*) _temp217)->f2;
goto _LL226; _LL226: _temp225=(( struct Cyc_Absyn_ArrayType_struct*) _temp217)->f3;
goto _LL220;} else{ goto _LL221;} _LL221: if(( unsigned int) _temp217 > 4u?*((
int*) _temp217) == Cyc_Absyn_PointerType: 0){ _LL232: _temp231=(( struct Cyc_Absyn_PointerType_struct*)
_temp217)->f1; _LL242: _temp241=( void*) _temp231.elt_typ; goto _LL240; _LL240:
_temp239=( void*) _temp231.rgn_typ; goto _LL238; _LL238: _temp237= _temp231.nullable;
goto _LL236; _LL236: _temp235= _temp231.tq; goto _LL234; _LL234: _temp233=
_temp231.bounds; goto _LL222;} else{ goto _LL223;} _LL223: goto _LL224; _LL220:
return( void*)({ struct Cyc_Absyn_ArrayType_struct* _temp243=( struct Cyc_Absyn_ArrayType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_ArrayType_struct)); _temp243[ 0]=({ struct
Cyc_Absyn_ArrayType_struct _temp244; _temp244.tag= Cyc_Absyn_ArrayType; _temp244.f1=(
void*) Cyc_Absyn_uchar_t; _temp244.f2= _temp227; _temp244.f3=( struct Cyc_Absyn_Exp*)
elen; _temp244;}); _temp243;}); _LL222: if( ! Cyc_Tcutil_unify(*(( void**)
_check_null( topt)), t)? Cyc_Tcutil_silent_castable( te, loc, t,*(( void**)
_check_null( topt))): 0){ e->topt=({ struct Cyc_Core_Opt* _temp245=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp245->v=( void*) t; _temp245;});
Cyc_Tcutil_unchecked_cast( te, e,*(( void**) _check_null( topt))); t=*(( void**)
_check_null( topt));} else{ t= Cyc_Absyn_atb_typ( Cyc_Absyn_uchar_t, Cyc_Absyn_new_evar((
struct Cyc_Core_Opt*)& Cyc_Tcexp_rk,({ struct Cyc_Core_Opt* _temp246=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp246->v=( void*)
Cyc_Tcenv_lookup_type_vars( te); _temp246;})), Cyc_Absyn_const_tqual(),( void*)({
struct Cyc_Absyn_Upper_b_struct* _temp247=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp247[ 0]=({ struct Cyc_Absyn_Upper_b_struct
_temp248; _temp248.tag= Cyc_Absyn_Upper_b; _temp248.f1= elen; _temp248;});
_temp247;})); if( ! Cyc_Tcutil_unify(*(( void**) _check_null( topt)), t)? Cyc_Tcutil_silent_castable(
te, loc, t,*(( void**) _check_null( topt))): 0){ e->topt=({ struct Cyc_Core_Opt*
_temp249=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp249->v=( void*) t; _temp249;}); Cyc_Tcutil_unchecked_cast( te, e,*(( void**)
_check_null( topt))); t=*(( void**) _check_null( topt));}} goto _LL218; _LL224:
goto _LL218; _LL218:;} return t;}} _LL157: { struct Cyc_List_List* _temp251= Cyc_Tcenv_lookup_type_vars(
te); goto _LL252; _LL252: t=( void*)({ struct Cyc_Absyn_PointerType_struct*
_temp253=( struct Cyc_Absyn_PointerType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct));
_temp253[ 0]=({ struct Cyc_Absyn_PointerType_struct _temp254; _temp254.tag= Cyc_Absyn_PointerType;
_temp254.f1=({ struct Cyc_Absyn_PtrInfo _temp255; _temp255.elt_typ=( void*) Cyc_Absyn_new_evar((
struct Cyc_Core_Opt*)& Cyc_Tcexp_ak,({ struct Cyc_Core_Opt* _temp257=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp257->v=( void*)
_temp251; _temp257;})); _temp255.rgn_typ=( void*) Cyc_Absyn_new_evar(( struct
Cyc_Core_Opt*)& Cyc_Tcexp_rk,({ struct Cyc_Core_Opt* _temp256=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp256->v=( void*) _temp251;
_temp256;})); _temp255.nullable=(( struct Cyc_Absyn_Conref*(*)( int x)) Cyc_Absyn_new_conref)(
1); _temp255.tq= Cyc_Absyn_empty_tqual(); _temp255.bounds=(( struct Cyc_Absyn_Conref*(*)())
Cyc_Absyn_empty_conref)(); _temp255;}); _temp254;}); _temp253;}); goto _LL143;}
_LL143:;} return t;} static void* Cyc_Tcexp_tcVar( struct Cyc_Tcenv_Tenv* te,
struct Cyc_Position_Segment* loc, struct _tuple1* q, void* b){ void* _temp258= b;
struct Cyc_Absyn_Vardecl* _temp272; struct Cyc_Absyn_Fndecl* _temp274; struct
Cyc_Absyn_Vardecl* _temp276; struct Cyc_Absyn_Vardecl* _temp278; struct Cyc_Absyn_Vardecl*
_temp280; _LL260: if( _temp258 ==( void*) Cyc_Absyn_Unresolved_b){ goto _LL261;}
else{ goto _LL262;} _LL262: if(( unsigned int) _temp258 > 1u?*(( int*) _temp258)
== Cyc_Absyn_Global_b: 0){ _LL273: _temp272=(( struct Cyc_Absyn_Global_b_struct*)
_temp258)->f1; goto _LL263;} else{ goto _LL264;} _LL264: if(( unsigned int)
_temp258 > 1u?*(( int*) _temp258) == Cyc_Absyn_Funname_b: 0){ _LL275: _temp274=((
struct Cyc_Absyn_Funname_b_struct*) _temp258)->f1; goto _LL265;} else{ goto
_LL266;} _LL266: if(( unsigned int) _temp258 > 1u?*(( int*) _temp258) == Cyc_Absyn_Pat_b:
0){ _LL277: _temp276=(( struct Cyc_Absyn_Pat_b_struct*) _temp258)->f1; goto
_LL267;} else{ goto _LL268;} _LL268: if(( unsigned int) _temp258 > 1u?*(( int*)
_temp258) == Cyc_Absyn_Local_b: 0){ _LL279: _temp278=(( struct Cyc_Absyn_Local_b_struct*)
_temp258)->f1; goto _LL269;} else{ goto _LL270;} _LL270: if(( unsigned int)
_temp258 > 1u?*(( int*) _temp258) == Cyc_Absyn_Param_b: 0){ _LL281: _temp280=((
struct Cyc_Absyn_Param_b_struct*) _temp258)->f1; goto _LL271;} else{ goto _LL259;}
_LL261: return Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)({ struct
_tagged_string _temp282= Cyc_Absynpp_qvar2string( q); xprintf("unbound identifier %.*s",
_temp282.last_plus_one - _temp282.curr, _temp282.curr);})); _LL263: q[
_check_known_subscript_notnull( 1u, 0)]=( _temp272->name)[
_check_known_subscript_notnull( 1u, 0)]; return( void*) _temp272->type; _LL265:
q[ _check_known_subscript_notnull( 1u, 0)]=( _temp274->name)[
_check_known_subscript_notnull( 1u, 0)]; return Cyc_Tcutil_fndecl2typ( _temp274);
_LL267: _temp278= _temp276; goto _LL269; _LL269: _temp280= _temp278; goto _LL271;
_LL271:(* q).f1=( void*) Cyc_Absyn_Loc_n; return( void*) _temp280->type; _LL259:;}
static void Cyc_Tcexp_check_format_args( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp*
fmt, struct Cyc_List_List* args, struct Cyc_List_List*(* type_getter)( struct
Cyc_Tcenv_Tenv*, struct _tagged_string, struct Cyc_Position_Segment*)){ struct
Cyc_List_List* desc_types;{ void* _temp283=( void*) fmt->r; void* _temp289;
struct _tagged_string _temp291; _LL285: if(*(( int*) _temp283) == Cyc_Absyn_Const_e){
_LL290: _temp289=( void*)(( struct Cyc_Absyn_Const_e_struct*) _temp283)->f1; if((
unsigned int) _temp289 > 1u?*(( int*) _temp289) == Cyc_Absyn_String_c: 0){
_LL292: _temp291=(( struct Cyc_Absyn_String_c_struct*) _temp289)->f1; goto
_LL286;} else{ goto _LL287;}} else{ goto _LL287;} _LL287: goto _LL288; _LL286:
desc_types= type_getter( te, _temp291, fmt->loc); goto _LL284; _LL288: Cyc_Tcutil_terr(
fmt->loc,({ unsigned char* _temp293=( unsigned char*)"expecting a literal format string";
struct _tagged_string _temp294; _temp294.curr= _temp293; _temp294.base= _temp293;
_temp294.last_plus_one= _temp293 + 34; _temp294;})); return; _LL284:;} for( 0;
desc_types != 0? args != 0: 0;( desc_types=(( struct Cyc_List_List*) _check_null(
desc_types))->tl, args=(( struct Cyc_List_List*) _check_null( args))->tl)){ void*
t=( void*)(( struct Cyc_List_List*) _check_null( desc_types))->hd; struct Cyc_Absyn_Exp*
e=( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( args))->hd; if(
! Cyc_Tcutil_coerce_arg( te, e, t)){ Cyc_Tcutil_terr( e->loc,( struct
_tagged_string)({ struct _tagged_string _temp295= Cyc_Absynpp_typ2string( t);
struct _tagged_string _temp296= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v); xprintf("descriptor has type %.*s but argument has type %.*s",
_temp295.last_plus_one - _temp295.curr, _temp295.curr, _temp296.last_plus_one -
_temp296.curr, _temp296.curr);}));}} if( desc_types != 0){ Cyc_Tcutil_terr( fmt->loc,({
unsigned char* _temp297=( unsigned char*)"too few arguments"; struct
_tagged_string _temp298; _temp298.curr= _temp297; _temp298.base= _temp297;
_temp298.last_plus_one= _temp297 + 18; _temp298;}));} if( args != 0){ Cyc_Tcutil_terr(((
struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( args))->hd)->loc,({
unsigned char* _temp299=( unsigned char*)"too many arguments"; struct
_tagged_string _temp300; _temp300.curr= _temp299; _temp300.base= _temp299;
_temp300.last_plus_one= _temp299 + 19; _temp300;}));}} static void* Cyc_Tcexp_tcUnPrimop(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, void*
p, struct Cyc_Absyn_Exp* e){ void* t= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v); void* _temp301= p; _LL303: if( _temp301 ==( void*)
Cyc_Absyn_Plus){ goto _LL304;} else{ goto _LL305;} _LL305: if( _temp301 ==( void*)
Cyc_Absyn_Minus){ goto _LL306;} else{ goto _LL307;} _LL307: if( _temp301 ==(
void*) Cyc_Absyn_Not){ goto _LL308;} else{ goto _LL309;} _LL309: if( _temp301 ==(
void*) Cyc_Absyn_Bitnot){ goto _LL310;} else{ goto _LL311;} _LL311: if( _temp301
==( void*) Cyc_Absyn_Size){ goto _LL312;} else{ goto _LL313;} _LL313: goto
_LL314; _LL304: goto _LL306; _LL306: if( ! Cyc_Tcutil_is_numeric( e)){ Cyc_Tcutil_terr(
loc,( struct _tagged_string)({ struct _tagged_string _temp315= Cyc_Absynpp_typ2string(
t); xprintf("expecting arithmetic type but found %.*s", _temp315.last_plus_one -
_temp315.curr, _temp315.curr);}));} return( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v; _LL308: Cyc_Tcutil_check_contains_assign( e); if( !
Cyc_Tcutil_coerce_to_bool( te, e)){ Cyc_Tcutil_terr( loc,( struct _tagged_string)({
struct _tagged_string _temp316= Cyc_Absynpp_typ2string( t); xprintf("expecting integral or * type but found %.*s",
_temp316.last_plus_one - _temp316.curr, _temp316.curr);}));} return Cyc_Absyn_sint_t;
_LL310: if( ! Cyc_Tcutil_is_integral( e)){ Cyc_Tcutil_terr( loc,( struct
_tagged_string)({ struct _tagged_string _temp317= Cyc_Absynpp_typ2string( t);
xprintf("expecting integral type but found %.*s", _temp317.last_plus_one -
_temp317.curr, _temp317.curr);}));} return( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v; _LL312:{ void* _temp318= t; struct Cyc_Absyn_Exp*
_temp326; struct Cyc_Absyn_Tqual _temp328; void* _temp330; struct Cyc_Absyn_PtrInfo
_temp332; struct Cyc_Absyn_Conref* _temp334; struct Cyc_Absyn_Tqual _temp336;
struct Cyc_Absyn_Conref* _temp338; void* _temp340; void* _temp342; _LL320: if((
unsigned int) _temp318 > 4u?*(( int*) _temp318) == Cyc_Absyn_ArrayType: 0){
_LL331: _temp330=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp318)->f1;
goto _LL329; _LL329: _temp328=(( struct Cyc_Absyn_ArrayType_struct*) _temp318)->f2;
goto _LL327; _LL327: _temp326=(( struct Cyc_Absyn_ArrayType_struct*) _temp318)->f3;
goto _LL321;} else{ goto _LL322;} _LL322: if(( unsigned int) _temp318 > 4u?*((
int*) _temp318) == Cyc_Absyn_PointerType: 0){ _LL333: _temp332=(( struct Cyc_Absyn_PointerType_struct*)
_temp318)->f1; _LL343: _temp342=( void*) _temp332.elt_typ; goto _LL341; _LL341:
_temp340=( void*) _temp332.rgn_typ; goto _LL339; _LL339: _temp338= _temp332.nullable;
goto _LL337; _LL337: _temp336= _temp332.tq; goto _LL335; _LL335: _temp334=
_temp332.bounds; goto _LL323;} else{ goto _LL324;} _LL324: goto _LL325; _LL321:
goto _LL319; _LL323: goto _LL319; _LL325: Cyc_Tcutil_terr( loc,( struct
_tagged_string)({ struct _tagged_string _temp344= Cyc_Absynpp_typ2string( t);
xprintf("size requires pointer or array type, not %.*s", _temp344.last_plus_one
- _temp344.curr, _temp344.curr);})); goto _LL319; _LL319:;} return Cyc_Absyn_uint_t;
_LL314: return(( void*(*)( struct _tagged_string)) Cyc_Tcutil_impos)(({
unsigned char* _temp345=( unsigned char*)"Non-unary primop"; struct
_tagged_string _temp346; _temp346.curr= _temp345; _temp346.base= _temp345;
_temp346.last_plus_one= _temp345 + 17; _temp346;})); _LL302:;} static void* Cyc_Tcexp_tcArithBinop(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e1, struct Cyc_Absyn_Exp* e2,
int(* checker)( struct Cyc_Absyn_Exp*)){ if( ! checker( e1)){ Cyc_Tcutil_terr(
e1->loc,( struct _tagged_string)({ struct _tagged_string _temp347= Cyc_Absynpp_typ2string((
void*)(( struct Cyc_Core_Opt*) _check_null( e1->topt))->v); xprintf("type %.*s cannot be used here",
_temp347.last_plus_one - _temp347.curr, _temp347.curr);})); return Cyc_Absyn_wildtyp(({
struct Cyc_Core_Opt* _temp348=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp348->v=( void*) Cyc_Tcenv_lookup_type_vars( te); _temp348;}));}
if( ! checker( e2)){ Cyc_Tcutil_terr( e2->loc,( struct _tagged_string)({ struct
_tagged_string _temp349= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*)
_check_null( e2->topt))->v); xprintf("type %.*s cannot be used here", _temp349.last_plus_one
- _temp349.curr, _temp349.curr);})); return Cyc_Absyn_wildtyp(({ struct Cyc_Core_Opt*
_temp350=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp350->v=( void*) Cyc_Tcenv_lookup_type_vars( te); _temp350;}));}{ void* t1=
Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e1->topt))->v);
void* t2= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e2->topt))->v);
return Cyc_Tcutil_max_arithmetic_type( t1, t2);}} static void* Cyc_Tcexp_tcPlus(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e1, struct Cyc_Absyn_Exp* e2){
void* t1= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e1->topt))->v);
void* t2= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e2->topt))->v);
void* _temp351= t1; struct Cyc_Absyn_PtrInfo _temp357; struct Cyc_Absyn_Conref*
_temp359; struct Cyc_Absyn_Tqual _temp361; struct Cyc_Absyn_Conref* _temp363;
void* _temp365; void* _temp367; _LL353: if(( unsigned int) _temp351 > 4u?*(( int*)
_temp351) == Cyc_Absyn_PointerType: 0){ _LL358: _temp357=(( struct Cyc_Absyn_PointerType_struct*)
_temp351)->f1; _LL368: _temp367=( void*) _temp357.elt_typ; goto _LL366; _LL366:
_temp365=( void*) _temp357.rgn_typ; goto _LL364; _LL364: _temp363= _temp357.nullable;
goto _LL362; _LL362: _temp361= _temp357.tq; goto _LL360; _LL360: _temp359=
_temp357.bounds; goto _LL354;} else{ goto _LL355;} _LL355: goto _LL356; _LL354:
if( ! Cyc_Tcutil_coerce_sint_typ( te, e2)){ Cyc_Tcutil_terr( e2->loc,( struct
_tagged_string)({ struct _tagged_string _temp369= Cyc_Absynpp_typ2string( t2);
xprintf("expecting int but found %.*s", _temp369.last_plus_one - _temp369.curr,
_temp369.curr);}));} _temp359=(( struct Cyc_Absyn_Conref*(*)( struct Cyc_Absyn_Conref*
x)) Cyc_Absyn_compress_conref)( _temp359);{ void* _temp370=( void*) _temp359->v;
void* _temp378; void* _temp380; struct Cyc_Absyn_Exp* _temp382; _LL372: if((
unsigned int) _temp370 > 1u?*(( int*) _temp370) == Cyc_Absyn_Eq_constr: 0){
_LL379: _temp378=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp370)->f1;
if( _temp378 ==( void*) Cyc_Absyn_Unknown_b){ goto _LL373;} else{ goto _LL374;}}
else{ goto _LL374;} _LL374: if(( unsigned int) _temp370 > 1u?*(( int*) _temp370)
== Cyc_Absyn_Eq_constr: 0){ _LL381: _temp380=( void*)(( struct Cyc_Absyn_Eq_constr_struct*)
_temp370)->f1; if(( unsigned int) _temp380 > 1u?*(( int*) _temp380) == Cyc_Absyn_Upper_b:
0){ _LL383: _temp382=(( struct Cyc_Absyn_Upper_b_struct*) _temp380)->f1; goto
_LL375;} else{ goto _LL376;}} else{ goto _LL376;} _LL376: goto _LL377; _LL373:
return t1; _LL375: { unsigned int _temp384= Cyc_Evexp_eval_const_uint_exp(
_temp382); goto _LL385; _LL385: _temp363=(( struct Cyc_Absyn_Conref*(*)( struct
Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)( _temp363);{ int is_nullable;{
void* _temp386=( void*) _temp363->v; int _temp392; _LL388: if(( unsigned int)
_temp386 > 1u?*(( int*) _temp386) == Cyc_Absyn_Eq_constr: 0){ _LL393: _temp392=(
int)(( struct Cyc_Absyn_Eq_constr_struct*) _temp386)->f1; goto _LL389;} else{
goto _LL390;} _LL390: goto _LL391; _LL389: if( _temp392){ struct Cyc_Absyn_PointerType_struct*
_temp397=({ struct Cyc_Absyn_PointerType_struct* _temp394=( struct Cyc_Absyn_PointerType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct)); _temp394[ 0]=({ struct
Cyc_Absyn_PointerType_struct _temp395; _temp395.tag= Cyc_Absyn_PointerType;
_temp395.f1=({ struct Cyc_Absyn_PtrInfo _temp396; _temp396.elt_typ=( void*)
_temp367; _temp396.rgn_typ=( void*) _temp365; _temp396.nullable=(( struct Cyc_Absyn_Conref*(*)(
int x)) Cyc_Absyn_new_conref)( 0); _temp396.tq= _temp361; _temp396.bounds=
_temp359; _temp396;}); _temp395;}); _temp394;}); goto _LL398; _LL398: Cyc_Tcutil_warn(
e1->loc,( struct _tagged_string)({ struct _tagged_string _temp399= Cyc_Absynpp_typ2string(
t1); struct _tagged_string _temp400= Cyc_Absynpp_typ2string(( void*) _temp397);
xprintf("coercing from %.*s to %.*s", _temp399.last_plus_one - _temp399.curr,
_temp399.curr, _temp400.last_plus_one - _temp400.curr, _temp400.curr);})); Cyc_Tcutil_unchecked_cast(
te, e1,( void*) _temp397);} goto _LL387; _LL391:( void*)( _temp363->v=( void*)((
void*)({ struct Cyc_Absyn_Eq_constr_struct* _temp401=( struct Cyc_Absyn_Eq_constr_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct)); _temp401[ 0]=({ struct
Cyc_Absyn_Eq_constr_struct _temp402; _temp402.tag= Cyc_Absyn_Eq_constr; _temp402.f1=(
void*) 0; _temp402;}); _temp401;}))); goto _LL387; _LL387:;} if( Cyc_Tcutil_is_const_exp(
te, e2)){ unsigned int _temp403= Cyc_Evexp_eval_const_uint_exp( e2); goto _LL404;
_LL404: if( _temp384 < _temp403){ _temp403= _temp384; Cyc_Tcutil_warn( e1->loc,(
struct _tagged_string) xprintf("pointer arithmetic is out of bounds"));}{ struct
Cyc_Absyn_Exp* _temp405= Cyc_Absyn_uint_exp( _temp384 - _temp403, 0); goto
_LL406; _LL406: _temp405->topt=({ struct Cyc_Core_Opt* _temp407=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp407->v=( void*) Cyc_Absyn_uint_t;
_temp407;}); return( void*)({ struct Cyc_Absyn_PointerType_struct* _temp408=(
struct Cyc_Absyn_PointerType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct));
_temp408[ 0]=({ struct Cyc_Absyn_PointerType_struct _temp409; _temp409.tag= Cyc_Absyn_PointerType;
_temp409.f1=({ struct Cyc_Absyn_PtrInfo _temp410; _temp410.elt_typ=( void*)
_temp367; _temp410.rgn_typ=( void*) _temp365; _temp410.nullable=(( struct Cyc_Absyn_Conref*(*)(
int x)) Cyc_Absyn_new_conref)( 0); _temp410.tq= _temp361; _temp410.bounds=((
struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)(( void*)({ struct
Cyc_Absyn_Upper_b_struct* _temp411=( struct Cyc_Absyn_Upper_b_struct*) GC_malloc(
sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp411[ 0]=({ struct Cyc_Absyn_Upper_b_struct
_temp412; _temp412.tag= Cyc_Absyn_Upper_b; _temp412.f1= _temp405; _temp412;});
_temp411;})); _temp410;}); _temp409;}); _temp408;});}} else{ Cyc_Tcutil_terr( e1->loc,({
unsigned char* _temp413=( unsigned char*)"cannot statically check pointer arithmetic.\n   suggest you cast the first expression to a ? type.";
struct _tagged_string _temp414; _temp414.curr= _temp413; _temp414.base= _temp413;
_temp414.last_plus_one= _temp413 + 98; _temp414;})); return t1;}}} _LL377:( void*)(
_temp359->v=( void*)(( void*)({ struct Cyc_Absyn_Eq_constr_struct* _temp415=(
struct Cyc_Absyn_Eq_constr_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Eq_constr_struct));
_temp415[ 0]=({ struct Cyc_Absyn_Eq_constr_struct _temp416; _temp416.tag= Cyc_Absyn_Eq_constr;
_temp416.f1=( void*)(( void*) Cyc_Absyn_Unknown_b); _temp416;}); _temp415;})));
return t1; _LL371:;} _LL356: return Cyc_Tcexp_tcArithBinop( te, e1, e2, Cyc_Tcutil_is_numeric);
_LL352:;} static void* Cyc_Tcexp_tcMinus( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp*
e1, struct Cyc_Absyn_Exp* e2){ void* t1=( void*)(( struct Cyc_Core_Opt*)
_check_null( e1->topt))->v; void* t2=( void*)(( struct Cyc_Core_Opt*)
_check_null( e2->topt))->v; if( Cyc_Tcutil_is_tagged_pointer_typ( t1)){ if( Cyc_Tcutil_is_tagged_pointer_typ(
t2)){ if( ! Cyc_Tcutil_unify( t1, t2)){ Cyc_Tcutil_terr( e1->loc,( struct
_tagged_string)({ struct _tagged_string _temp417= Cyc_Absynpp_typ2string(( void*)((
struct Cyc_Core_Opt*) _check_null( e1->topt))->v); struct _tagged_string
_temp418= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*) _check_null(
e2->topt))->v); xprintf("pointer arithmetic on values of different types (%.*s != %.*s)",
_temp417.last_plus_one - _temp417.curr, _temp417.curr, _temp418.last_plus_one -
_temp418.curr, _temp418.curr);}));} return Cyc_Absyn_sint_t;} else{ if( ! Cyc_Tcutil_coerce_sint_typ(
te, e2)){ Cyc_Tcutil_terr( e2->loc,( struct _tagged_string)({ struct
_tagged_string _temp419= Cyc_Absynpp_typ2string( t1); struct _tagged_string
_temp420= Cyc_Absynpp_typ2string( t2); xprintf("expecting either %.*s or int but found %.*s",
_temp419.last_plus_one - _temp419.curr, _temp419.curr, _temp420.last_plus_one -
_temp420.curr, _temp420.curr);}));} return t1;}} else{ return Cyc_Tcexp_tcArithBinop(
te, e1, e2, Cyc_Tcutil_is_numeric);}} static void* Cyc_Tcexp_tcAnyBinop( struct
Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, struct Cyc_Absyn_Exp* e1,
struct Cyc_Absyn_Exp* e2){ int e1_is_num= Cyc_Tcutil_is_numeric( e1); int
e2_is_num= Cyc_Tcutil_is_numeric( e2); void* t1= Cyc_Tcutil_compress(( void*)((
struct Cyc_Core_Opt*) _check_null( e1->topt))->v); void* t2= Cyc_Tcutil_compress((
void*)(( struct Cyc_Core_Opt*) _check_null( e2->topt))->v); if( e1_is_num?
e2_is_num: 0){ return Cyc_Absyn_sint_t;} else{ if( Cyc_Tcutil_unify( t1, t2)?
Cyc_Tcutil_unify( t1, Cyc_Absyn_new_evar(( struct Cyc_Core_Opt*)& Cyc_Tcexp_bk,({
struct Cyc_Core_Opt* _temp421=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp421->v=( void*) Cyc_Tcenv_lookup_type_vars( te); _temp421;}))):
0){ return Cyc_Absyn_sint_t;} else{ if( Cyc_Tcutil_silent_castable( te, loc, t2,
t1)){ Cyc_Tcutil_unchecked_cast( te, e2, t1); return Cyc_Absyn_sint_t;} else{
if( Cyc_Tcutil_silent_castable( te, loc, t1, t2)){ Cyc_Tcutil_unchecked_cast( te,
e1, t2); return Cyc_Absyn_sint_t;} else{ void* t1=( void*)(( struct Cyc_Core_Opt*)
_check_null( e1->topt))->v; void* t2=( void*)(( struct Cyc_Core_Opt*)
_check_null( e2->topt))->v;{ struct _tuple0 _temp423=({ struct _tuple0 _temp422;
_temp422.f1= Cyc_Tcutil_compress( t1); _temp422.f2= Cyc_Tcutil_compress( t2);
_temp422;}); void* _temp429; struct Cyc_Absyn_PtrInfo _temp431; struct Cyc_Absyn_Conref*
_temp433; struct Cyc_Absyn_Tqual _temp435; struct Cyc_Absyn_Conref* _temp437;
void* _temp439; void* _temp441; void* _temp443; struct Cyc_Absyn_PtrInfo
_temp445; struct Cyc_Absyn_Conref* _temp447; struct Cyc_Absyn_Tqual _temp449;
struct Cyc_Absyn_Conref* _temp451; void* _temp453; void* _temp455; _LL425:
_LL444: _temp443= _temp423.f1; if(( unsigned int) _temp443 > 4u?*(( int*)
_temp443) == Cyc_Absyn_PointerType: 0){ _LL446: _temp445=(( struct Cyc_Absyn_PointerType_struct*)
_temp443)->f1; _LL456: _temp455=( void*) _temp445.elt_typ; goto _LL454; _LL454:
_temp453=( void*) _temp445.rgn_typ; goto _LL452; _LL452: _temp451= _temp445.nullable;
goto _LL450; _LL450: _temp449= _temp445.tq; goto _LL448; _LL448: _temp447=
_temp445.bounds; goto _LL430;} else{ goto _LL427;} _LL430: _temp429= _temp423.f2;
if(( unsigned int) _temp429 > 4u?*(( int*) _temp429) == Cyc_Absyn_PointerType: 0){
_LL432: _temp431=(( struct Cyc_Absyn_PointerType_struct*) _temp429)->f1; _LL442:
_temp441=( void*) _temp431.elt_typ; goto _LL440; _LL440: _temp439=( void*)
_temp431.rgn_typ; goto _LL438; _LL438: _temp437= _temp431.nullable; goto _LL436;
_LL436: _temp435= _temp431.tq; goto _LL434; _LL434: _temp433= _temp431.bounds;
goto _LL426;} else{ goto _LL427;} _LL427: goto _LL428; _LL426: if( Cyc_Tcutil_unify(
_temp455, _temp441)){ return Cyc_Absyn_sint_t;} goto _LL424; _LL428: goto _LL424;
_LL424:;} Cyc_Tcutil_terr( loc,( struct _tagged_string)({ struct _tagged_string
_temp457= Cyc_Absynpp_typ2string( t1); struct _tagged_string _temp458= Cyc_Absynpp_typ2string(
t2); xprintf("comparison not allowed between %.*s and %.*s", _temp457.last_plus_one
- _temp457.curr, _temp457.curr, _temp458.last_plus_one - _temp458.curr, _temp458.curr);}));
return Cyc_Absyn_wildtyp(({ struct Cyc_Core_Opt* _temp459=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp459->v=( void*) Cyc_Tcenv_lookup_type_vars(
te); _temp459;}));}}}}} static void* Cyc_Tcexp_tcBinPrimop( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void** topt, void* p, struct Cyc_Absyn_Exp*
e1, struct Cyc_Absyn_Exp* e2){ void* _temp460= p; _LL462: if( _temp460 ==( void*)
Cyc_Absyn_Plus){ goto _LL463;} else{ goto _LL464;} _LL464: if( _temp460 ==( void*)
Cyc_Absyn_Minus){ goto _LL465;} else{ goto _LL466;} _LL466: if( _temp460 ==(
void*) Cyc_Absyn_Times){ goto _LL467;} else{ goto _LL468;} _LL468: if( _temp460
==( void*) Cyc_Absyn_Div){ goto _LL469;} else{ goto _LL470;} _LL470: if(
_temp460 ==( void*) Cyc_Absyn_Mod){ goto _LL471;} else{ goto _LL472;} _LL472:
if( _temp460 ==( void*) Cyc_Absyn_Bitand){ goto _LL473;} else{ goto _LL474;}
_LL474: if( _temp460 ==( void*) Cyc_Absyn_Bitor){ goto _LL475;} else{ goto
_LL476;} _LL476: if( _temp460 ==( void*) Cyc_Absyn_Bitxor){ goto _LL477;} else{
goto _LL478;} _LL478: if( _temp460 ==( void*) Cyc_Absyn_Bitlshift){ goto _LL479;}
else{ goto _LL480;} _LL480: if( _temp460 ==( void*) Cyc_Absyn_Bitlrshift){ goto
_LL481;} else{ goto _LL482;} _LL482: if( _temp460 ==( void*) Cyc_Absyn_Bitarshift){
goto _LL483;} else{ goto _LL484;} _LL484: if( _temp460 ==( void*) Cyc_Absyn_Eq){
goto _LL485;} else{ goto _LL486;} _LL486: if( _temp460 ==( void*) Cyc_Absyn_Neq){
goto _LL487;} else{ goto _LL488;} _LL488: if( _temp460 ==( void*) Cyc_Absyn_Gt){
goto _LL489;} else{ goto _LL490;} _LL490: if( _temp460 ==( void*) Cyc_Absyn_Lt){
goto _LL491;} else{ goto _LL492;} _LL492: if( _temp460 ==( void*) Cyc_Absyn_Gte){
goto _LL493;} else{ goto _LL494;} _LL494: if( _temp460 ==( void*) Cyc_Absyn_Lte){
goto _LL495;} else{ goto _LL496;} _LL496: goto _LL497; _LL463: return Cyc_Tcexp_tcPlus(
te, e1, e2); _LL465: return Cyc_Tcexp_tcMinus( te, e1, e2); _LL467: goto _LL469;
_LL469: return Cyc_Tcexp_tcArithBinop( te, e1, e2, Cyc_Tcutil_is_numeric);
_LL471: goto _LL473; _LL473: goto _LL475; _LL475: goto _LL477; _LL477: goto
_LL479; _LL479: goto _LL481; _LL481: goto _LL483; _LL483: return Cyc_Tcexp_tcArithBinop(
te, e1, e2, Cyc_Tcutil_is_integral); _LL485: goto _LL487; _LL487: goto _LL489;
_LL489: goto _LL491; _LL491: goto _LL493; _LL493: goto _LL495; _LL495: return
Cyc_Tcexp_tcAnyBinop( te, loc, e1, e2); _LL497:( void) _throw(( void*)({ struct
Cyc_Core_Failure_struct* _temp498=( struct Cyc_Core_Failure_struct*) GC_malloc(
sizeof( struct Cyc_Core_Failure_struct)); _temp498[ 0]=({ struct Cyc_Core_Failure_struct
_temp499; _temp499.tag= Cyc_Core_Failure; _temp499.f1=({ unsigned char* _temp500=(
unsigned char*)"bad binary primop"; struct _tagged_string _temp501; _temp501.curr=
_temp500; _temp501.base= _temp500; _temp501.last_plus_one= _temp500 + 18;
_temp501;}); _temp499;}); _temp498;})); _LL461:;} static void* Cyc_Tcexp_tcPrimop(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, void*
p, struct Cyc_List_List* es){ if( p ==( void*) Cyc_Absyn_Minus?(( int(*)( struct
Cyc_List_List* x)) Cyc_List_length)( es) == 1: 0){ return Cyc_Tcexp_tcExp( te,
topt,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd);}
Cyc_Tcexp_tcExpList( te, es);{ void* t;{ void* _temp502= p; _LL504: if( _temp502
==( void*) Cyc_Absyn_Printf){ goto _LL505;} else{ goto _LL506;} _LL506: if(
_temp502 ==( void*) Cyc_Absyn_Fprintf){ goto _LL507;} else{ goto _LL508;} _LL508:
if( _temp502 ==( void*) Cyc_Absyn_Xprintf){ goto _LL509;} else{ goto _LL510;}
_LL510: if( _temp502 ==( void*) Cyc_Absyn_Scanf){ goto _LL511;} else{ goto
_LL512;} _LL512: if( _temp502 ==( void*) Cyc_Absyn_Fscanf){ goto _LL513;} else{
goto _LL514;} _LL514: if( _temp502 ==( void*) Cyc_Absyn_Sscanf){ goto _LL515;}
else{ goto _LL516;} _LL516: goto _LL517; _LL505: if( es == 0){ return Cyc_Tcexp_expr_err(
te, loc,({ unsigned char* _temp518=( unsigned char*)"missing format string in printf";
struct _tagged_string _temp519; _temp519.curr= _temp518; _temp519.base= _temp518;
_temp519.last_plus_one= _temp518 + 32; _temp519;}));} Cyc_Tcexp_check_format_args(
te,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd,((
struct Cyc_List_List*) _check_null( es))->tl, Cyc_Formatstr_get_format_typs); t=(
void*) Cyc_Absyn_VoidType; goto _LL503; _LL507: if( es == 0? 1:(( struct Cyc_List_List*)
_check_null( es))->tl == 0){ return Cyc_Tcexp_expr_err( te, loc,({ unsigned char*
_temp520=( unsigned char*)"too few arguments to fprintf"; struct _tagged_string
_temp521; _temp521.curr= _temp520; _temp521.base= _temp520; _temp521.last_plus_one=
_temp520 + 29; _temp521;}));} if( ! Cyc_Tcutil_unify(( void*)(( struct Cyc_Core_Opt*)
_check_null((( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd)->topt))->v,
Cyc_Absyn_file_typ())){ Cyc_Tcutil_terr((( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*)
_check_null( es))->hd)->loc,( struct _tagged_string)({ struct _tagged_string
_temp522= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*) _check_null(((
struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd)->topt))->v);
xprintf("expecting FILE @ but found %.*s", _temp522.last_plus_one - _temp522.curr,
_temp522.curr);}));} Cyc_Tcexp_check_format_args( te,( struct Cyc_Absyn_Exp*)((
struct Cyc_List_List*) _check_null((( struct Cyc_List_List*) _check_null( es))->tl))->hd,((
struct Cyc_List_List*) _check_null((( struct Cyc_List_List*) _check_null( es))->tl))->tl,
Cyc_Formatstr_get_format_typs); t=( void*) Cyc_Absyn_VoidType; goto _LL503;
_LL509: if( es == 0){ return Cyc_Tcexp_expr_err( te, loc,({ unsigned char*
_temp523=( unsigned char*)"missing format string in xprintf"; struct
_tagged_string _temp524; _temp524.curr= _temp523; _temp524.base= _temp523;
_temp524.last_plus_one= _temp523 + 33; _temp524;}));} Cyc_Tcexp_check_format_args(
te,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd,((
struct Cyc_List_List*) _check_null( es))->tl, Cyc_Formatstr_get_format_typs); t=
Cyc_Absyn_string_typ( Cyc_Absyn_new_evar(( struct Cyc_Core_Opt*)& Cyc_Tcexp_rk,({
struct Cyc_Core_Opt* _temp525=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp525->v=( void*) Cyc_Tcenv_lookup_type_vars( te); _temp525;})));
goto _LL503; _LL511: if( es == 0){ return Cyc_Tcexp_expr_err( te, loc,({
unsigned char* _temp526=( unsigned char*)"missing format string in scanf";
struct _tagged_string _temp527; _temp527.curr= _temp526; _temp527.base= _temp526;
_temp527.last_plus_one= _temp526 + 31; _temp527;}));} Cyc_Tcexp_check_format_args(
te,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd,((
struct Cyc_List_List*) _check_null( es))->tl, Cyc_Formatstr_get_scanf_typs); t=
Cyc_Absyn_sint_t; goto _LL503; _LL513: if( es == 0? 1:(( struct Cyc_List_List*)
_check_null( es))->tl == 0){ return Cyc_Tcexp_expr_err( te, loc,({ unsigned char*
_temp528=( unsigned char*)"too few arguments to fscanf"; struct _tagged_string
_temp529; _temp529.curr= _temp528; _temp529.base= _temp528; _temp529.last_plus_one=
_temp528 + 28; _temp529;}));} if( ! Cyc_Tcutil_unify(( void*)(( struct Cyc_Core_Opt*)
_check_null((( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd)->topt))->v,
Cyc_Absyn_file_typ())){ Cyc_Tcutil_terr((( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*)
_check_null( es))->hd)->loc,( struct _tagged_string)({ struct _tagged_string
_temp530= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*) _check_null(((
struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd)->topt))->v);
xprintf("expecting FILE @ but found %.*s", _temp530.last_plus_one - _temp530.curr,
_temp530.curr);}));} Cyc_Tcexp_check_format_args( te,( struct Cyc_Absyn_Exp*)((
struct Cyc_List_List*) _check_null((( struct Cyc_List_List*) _check_null( es))->tl))->hd,((
struct Cyc_List_List*) _check_null((( struct Cyc_List_List*) _check_null( es))->tl))->tl,
Cyc_Formatstr_get_scanf_typs); t= Cyc_Absyn_sint_t; goto _LL503; _LL515: Cyc_Tcutil_terr(
loc,({ unsigned char* _temp531=( unsigned char*)"sscanf is not supported";
struct _tagged_string _temp532; _temp532.curr= _temp531; _temp532.base= _temp531;
_temp532.last_plus_one= _temp531 + 24; _temp532;})); t= Cyc_Absyn_sint_t; goto
_LL503; _LL517: switch((( int(*)( struct Cyc_List_List* x)) Cyc_List_length)( es)){
case 0: _LL533: return Cyc_Tcexp_expr_err( te, loc,({ unsigned char* _temp535=(
unsigned char*)"primitive operator has 0 arguments"; struct _tagged_string
_temp536; _temp536.curr= _temp535; _temp536.base= _temp535; _temp536.last_plus_one=
_temp535 + 35; _temp536;})); case 1: _LL534: t= Cyc_Tcexp_tcUnPrimop( te, loc,
topt, p,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd);
break; case 2: _LL537: t= Cyc_Tcexp_tcBinPrimop( te, loc, topt, p,( struct Cyc_Absyn_Exp*)((
struct Cyc_List_List*) _check_null( es))->hd,( struct Cyc_Absyn_Exp*)(( struct
Cyc_List_List*) _check_null((( struct Cyc_List_List*) _check_null( es))->tl))->hd);
break; default: _LL538: return Cyc_Tcexp_expr_err( te, loc,({ unsigned char*
_temp540=( unsigned char*)"primitive operator has > 2 arguments"; struct
_tagged_string _temp541; _temp541.curr= _temp540; _temp541.base= _temp540;
_temp541.last_plus_one= _temp540 + 37; _temp541;}));} goto _LL503; _LL503:;}
return t;}} struct _tuple8{ struct Cyc_Absyn_Tqual f1; void* f2; } ; static void
Cyc_Tcexp_check_writable( struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e){{
void* _temp542=( void*) e->r; void* _temp566; struct Cyc_Absyn_Vardecl* _temp568;
struct _tuple1* _temp570; void* _temp572; struct Cyc_Absyn_Vardecl* _temp574;
struct _tuple1* _temp576; void* _temp578; struct Cyc_Absyn_Vardecl* _temp580;
struct _tuple1* _temp582; void* _temp584; struct Cyc_Absyn_Vardecl* _temp586;
struct _tuple1* _temp588; struct Cyc_Absyn_Exp* _temp590; struct Cyc_Absyn_Exp*
_temp592; struct _tagged_string* _temp594; struct Cyc_Absyn_Exp* _temp596;
struct _tagged_string* _temp598; struct Cyc_Absyn_Exp* _temp600; struct Cyc_Absyn_Exp*
_temp602; struct Cyc_Absyn_Exp* _temp604; struct Cyc_List_List* _temp606; struct
Cyc_Absyn_Exp* _temp608; _LL544: if(*(( int*) _temp542) == Cyc_Absyn_Var_e){
_LL571: _temp570=(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f1; goto _LL567;
_LL567: _temp566=( void*)(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f2; if((
unsigned int) _temp566 > 1u?*(( int*) _temp566) == Cyc_Absyn_Param_b: 0){ _LL569:
_temp568=(( struct Cyc_Absyn_Param_b_struct*) _temp566)->f1; goto _LL545;} else{
goto _LL546;}} else{ goto _LL546;} _LL546: if(*(( int*) _temp542) == Cyc_Absyn_Var_e){
_LL577: _temp576=(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f1; goto _LL573;
_LL573: _temp572=( void*)(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f2; if((
unsigned int) _temp572 > 1u?*(( int*) _temp572) == Cyc_Absyn_Local_b: 0){ _LL575:
_temp574=(( struct Cyc_Absyn_Local_b_struct*) _temp572)->f1; goto _LL547;} else{
goto _LL548;}} else{ goto _LL548;} _LL548: if(*(( int*) _temp542) == Cyc_Absyn_Var_e){
_LL583: _temp582=(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f1; goto _LL579;
_LL579: _temp578=( void*)(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f2; if((
unsigned int) _temp578 > 1u?*(( int*) _temp578) == Cyc_Absyn_Pat_b: 0){ _LL581:
_temp580=(( struct Cyc_Absyn_Pat_b_struct*) _temp578)->f1; goto _LL549;} else{
goto _LL550;}} else{ goto _LL550;} _LL550: if(*(( int*) _temp542) == Cyc_Absyn_Var_e){
_LL589: _temp588=(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f1; goto _LL585;
_LL585: _temp584=( void*)(( struct Cyc_Absyn_Var_e_struct*) _temp542)->f2; if((
unsigned int) _temp584 > 1u?*(( int*) _temp584) == Cyc_Absyn_Global_b: 0){
_LL587: _temp586=(( struct Cyc_Absyn_Global_b_struct*) _temp584)->f1; goto
_LL551;} else{ goto _LL552;}} else{ goto _LL552;} _LL552: if(*(( int*) _temp542)
== Cyc_Absyn_Subscript_e){ _LL593: _temp592=(( struct Cyc_Absyn_Subscript_e_struct*)
_temp542)->f1; goto _LL591; _LL591: _temp590=(( struct Cyc_Absyn_Subscript_e_struct*)
_temp542)->f2; goto _LL553;} else{ goto _LL554;} _LL554: if(*(( int*) _temp542)
== Cyc_Absyn_StructMember_e){ _LL597: _temp596=(( struct Cyc_Absyn_StructMember_e_struct*)
_temp542)->f1; goto _LL595; _LL595: _temp594=(( struct Cyc_Absyn_StructMember_e_struct*)
_temp542)->f2; goto _LL555;} else{ goto _LL556;} _LL556: if(*(( int*) _temp542)
== Cyc_Absyn_StructArrow_e){ _LL601: _temp600=(( struct Cyc_Absyn_StructArrow_e_struct*)
_temp542)->f1; goto _LL599; _LL599: _temp598=(( struct Cyc_Absyn_StructArrow_e_struct*)
_temp542)->f2; goto _LL557;} else{ goto _LL558;} _LL558: if(*(( int*) _temp542)
== Cyc_Absyn_Deref_e){ _LL603: _temp602=(( struct Cyc_Absyn_Deref_e_struct*)
_temp542)->f1; goto _LL559;} else{ goto _LL560;} _LL560: if(*(( int*) _temp542)
== Cyc_Absyn_NoInstantiate_e){ _LL605: _temp604=(( struct Cyc_Absyn_NoInstantiate_e_struct*)
_temp542)->f1; goto _LL561;} else{ goto _LL562;} _LL562: if(*(( int*) _temp542)
== Cyc_Absyn_Instantiate_e){ _LL609: _temp608=(( struct Cyc_Absyn_Instantiate_e_struct*)
_temp542)->f1; goto _LL607; _LL607: _temp606=(( struct Cyc_Absyn_Instantiate_e_struct*)
_temp542)->f2; goto _LL563;} else{ goto _LL564;} _LL564: goto _LL565; _LL545:
_temp574= _temp568; goto _LL547; _LL547: _temp580= _temp574; goto _LL549; _LL549:
_temp586= _temp580; goto _LL551; _LL551: if( !( _temp586->tq).q_const){ return;}
goto _LL543; _LL553:{ void* _temp610= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*)
_check_null( _temp592->topt))->v); struct Cyc_Absyn_PtrInfo _temp620; struct Cyc_Absyn_Conref*
_temp622; struct Cyc_Absyn_Tqual _temp624; struct Cyc_Absyn_Conref* _temp626;
void* _temp628; void* _temp630; struct Cyc_Absyn_Exp* _temp632; struct Cyc_Absyn_Tqual
_temp634; void* _temp636; struct Cyc_List_List* _temp638; _LL612: if((
unsigned int) _temp610 > 4u?*(( int*) _temp610) == Cyc_Absyn_PointerType: 0){
_LL621: _temp620=(( struct Cyc_Absyn_PointerType_struct*) _temp610)->f1; _LL631:
_temp630=( void*) _temp620.elt_typ; goto _LL629; _LL629: _temp628=( void*)
_temp620.rgn_typ; goto _LL627; _LL627: _temp626= _temp620.nullable; goto _LL625;
_LL625: _temp624= _temp620.tq; goto _LL623; _LL623: _temp622= _temp620.bounds;
goto _LL613;} else{ goto _LL614;} _LL614: if(( unsigned int) _temp610 > 4u?*((
int*) _temp610) == Cyc_Absyn_ArrayType: 0){ _LL637: _temp636=( void*)(( struct
Cyc_Absyn_ArrayType_struct*) _temp610)->f1; goto _LL635; _LL635: _temp634=((
struct Cyc_Absyn_ArrayType_struct*) _temp610)->f2; goto _LL633; _LL633: _temp632=((
struct Cyc_Absyn_ArrayType_struct*) _temp610)->f3; goto _LL615;} else{ goto
_LL616;} _LL616: if(( unsigned int) _temp610 > 4u?*(( int*) _temp610) == Cyc_Absyn_TupleType:
0){ _LL639: _temp638=(( struct Cyc_Absyn_TupleType_struct*) _temp610)->f1; goto
_LL617;} else{ goto _LL618;} _LL618: goto _LL619; _LL613: _temp634= _temp624;
goto _LL615; _LL615: if( ! _temp634.q_const){ return;} goto _LL611; _LL617: {
unsigned int i= Cyc_Evexp_eval_const_uint_exp( _temp590);{ struct _handler_cons
_temp640; _push_handler(& _temp640);{ int _temp642= 0; if( setjmp( _temp640.handler)){
_temp642= 1;} if( ! _temp642){{ struct _tuple8 _temp645; void* _temp646; struct
Cyc_Absyn_Tqual _temp648; struct _tuple8* _temp643=(( struct _tuple8*(*)( struct
Cyc_List_List* x, int i)) Cyc_List_nth)( _temp638,( int) i); _temp645=* _temp643;
_LL649: _temp648= _temp645.f1; goto _LL647; _LL647: _temp646= _temp645.f2; goto
_LL644; _LL644: if( ! _temp648.q_const){ _npop_handler( 0u); return;}};
_pop_handler();} else{ void* _temp641=( void*) _exn_thrown; void* _temp651=
_temp641; _LL653: if( _temp651 == Cyc_List_Nth){ goto _LL654;} else{ goto _LL655;}
_LL655: goto _LL656; _LL654: return; _LL656:( void) _throw( _temp651); _LL652:;}}}
goto _LL611;} _LL619: goto _LL611; _LL611:;} goto _LL543; _LL555:{ void*
_temp657= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null(
_temp596->topt))->v); struct Cyc_Absyn_Structdecl** _temp669; struct Cyc_List_List*
_temp671; struct _tuple1* _temp673; struct Cyc_List_List* _temp675; struct Cyc_List_List*
_temp677; struct Cyc_Absyn_Uniondecl** _temp679; struct Cyc_List_List* _temp681;
struct _tuple1* _temp683; _LL659: if(( unsigned int) _temp657 > 4u?*(( int*)
_temp657) == Cyc_Absyn_StructType: 0){ _LL674: _temp673=(( struct Cyc_Absyn_StructType_struct*)
_temp657)->f1; goto _LL672; _LL672: _temp671=(( struct Cyc_Absyn_StructType_struct*)
_temp657)->f2; goto _LL670; _LL670: _temp669=(( struct Cyc_Absyn_StructType_struct*)
_temp657)->f3; goto _LL660;} else{ goto _LL661;} _LL661: if(( unsigned int)
_temp657 > 4u?*(( int*) _temp657) == Cyc_Absyn_AnonUnionType: 0){ _LL676:
_temp675=(( struct Cyc_Absyn_AnonUnionType_struct*) _temp657)->f1; goto _LL662;}
else{ goto _LL663;} _LL663: if(( unsigned int) _temp657 > 4u?*(( int*) _temp657)
== Cyc_Absyn_AnonStructType: 0){ _LL678: _temp677=(( struct Cyc_Absyn_AnonStructType_struct*)
_temp657)->f1; goto _LL664;} else{ goto _LL665;} _LL665: if(( unsigned int)
_temp657 > 4u?*(( int*) _temp657) == Cyc_Absyn_UnionType: 0){ _LL684: _temp683=((
struct Cyc_Absyn_UnionType_struct*) _temp657)->f1; goto _LL682; _LL682: _temp681=((
struct Cyc_Absyn_UnionType_struct*) _temp657)->f2; goto _LL680; _LL680: _temp679=((
struct Cyc_Absyn_UnionType_struct*) _temp657)->f3; goto _LL666;} else{ goto
_LL667;} _LL667: goto _LL668; _LL660: { struct Cyc_Absyn_Structfield* sf=
_temp669 == 0? 0: Cyc_Absyn_lookup_struct_field(( struct Cyc_Absyn_Structdecl*)*((
struct Cyc_Absyn_Structdecl**) _check_null( _temp669)), _temp594); if( sf == 0?
1: !((( struct Cyc_Absyn_Structfield*) _check_null( sf))->tq).q_const){ return;}
goto _LL658;} _LL662: _temp677= _temp675; goto _LL664; _LL664: { struct Cyc_Absyn_Structfield*
sf= Cyc_Absyn_lookup_field( _temp677, _temp594); if( sf == 0? 1: !((( struct Cyc_Absyn_Structfield*)
_check_null( sf))->tq).q_const){ return;} goto _LL658;} _LL666: { struct Cyc_Absyn_Structfield*
sf= _temp679 == 0? 0: Cyc_Absyn_lookup_union_field(( struct Cyc_Absyn_Uniondecl*)*((
struct Cyc_Absyn_Uniondecl**) _check_null( _temp679)), _temp594); if( sf == 0? 1:
!((( struct Cyc_Absyn_Structfield*) _check_null( sf))->tq).q_const){ return;}
goto _LL658;} _LL668: goto _LL658; _LL658:;} goto _LL543; _LL557:{ void*
_temp685= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null(
_temp600->topt))->v); struct Cyc_Absyn_PtrInfo _temp691; struct Cyc_Absyn_Conref*
_temp693; struct Cyc_Absyn_Tqual _temp695; struct Cyc_Absyn_Conref* _temp697;
void* _temp699; void* _temp701; _LL687: if(( unsigned int) _temp685 > 4u?*(( int*)
_temp685) == Cyc_Absyn_PointerType: 0){ _LL692: _temp691=(( struct Cyc_Absyn_PointerType_struct*)
_temp685)->f1; _LL702: _temp701=( void*) _temp691.elt_typ; goto _LL700; _LL700:
_temp699=( void*) _temp691.rgn_typ; goto _LL698; _LL698: _temp697= _temp691.nullable;
goto _LL696; _LL696: _temp695= _temp691.tq; goto _LL694; _LL694: _temp693=
_temp691.bounds; goto _LL688;} else{ goto _LL689;} _LL689: goto _LL690; _LL688:{
void* _temp703= Cyc_Tcutil_compress( _temp701); struct Cyc_Absyn_Structdecl**
_temp715; struct Cyc_List_List* _temp717; struct _tuple1* _temp719; struct Cyc_Absyn_Uniondecl**
_temp721; struct Cyc_List_List* _temp723; struct _tuple1* _temp725; struct Cyc_List_List*
_temp727; struct Cyc_List_List* _temp729; _LL705: if(( unsigned int) _temp703 >
4u?*(( int*) _temp703) == Cyc_Absyn_StructType: 0){ _LL720: _temp719=(( struct
Cyc_Absyn_StructType_struct*) _temp703)->f1; goto _LL718; _LL718: _temp717=((
struct Cyc_Absyn_StructType_struct*) _temp703)->f2; goto _LL716; _LL716:
_temp715=(( struct Cyc_Absyn_StructType_struct*) _temp703)->f3; goto _LL706;}
else{ goto _LL707;} _LL707: if(( unsigned int) _temp703 > 4u?*(( int*) _temp703)
== Cyc_Absyn_UnionType: 0){ _LL726: _temp725=(( struct Cyc_Absyn_UnionType_struct*)
_temp703)->f1; goto _LL724; _LL724: _temp723=(( struct Cyc_Absyn_UnionType_struct*)
_temp703)->f2; goto _LL722; _LL722: _temp721=(( struct Cyc_Absyn_UnionType_struct*)
_temp703)->f3; goto _LL708;} else{ goto _LL709;} _LL709: if(( unsigned int)
_temp703 > 4u?*(( int*) _temp703) == Cyc_Absyn_AnonStructType: 0){ _LL728:
_temp727=(( struct Cyc_Absyn_AnonStructType_struct*) _temp703)->f1; goto _LL710;}
else{ goto _LL711;} _LL711: if(( unsigned int) _temp703 > 4u?*(( int*) _temp703)
== Cyc_Absyn_AnonUnionType: 0){ _LL730: _temp729=(( struct Cyc_Absyn_AnonUnionType_struct*)
_temp703)->f1; goto _LL712;} else{ goto _LL713;} _LL713: goto _LL714; _LL706: {
struct Cyc_Absyn_Structfield* sf= _temp715 == 0? 0: Cyc_Absyn_lookup_struct_field((
struct Cyc_Absyn_Structdecl*)*(( struct Cyc_Absyn_Structdecl**) _check_null(
_temp715)), _temp598); if( sf == 0? 1: !((( struct Cyc_Absyn_Structfield*)
_check_null( sf))->tq).q_const){ return;} goto _LL704;} _LL708: { struct Cyc_Absyn_Structfield*
sf= _temp721 == 0? 0: Cyc_Absyn_lookup_union_field(( struct Cyc_Absyn_Uniondecl*)*((
struct Cyc_Absyn_Uniondecl**) _check_null( _temp721)), _temp598); if( sf == 0? 1:
!((( struct Cyc_Absyn_Structfield*) _check_null( sf))->tq).q_const){ return;}
goto _LL704;} _LL710: _temp729= _temp727; goto _LL712; _LL712: { struct Cyc_Absyn_Structfield*
sf= Cyc_Absyn_lookup_field( _temp729, _temp598); if( sf == 0? 1: !((( struct Cyc_Absyn_Structfield*)
_check_null( sf))->tq).q_const){ return;} goto _LL704;} _LL714: goto _LL704;
_LL704:;} goto _LL686; _LL690: goto _LL686; _LL686:;} goto _LL543; _LL559:{ void*
_temp731= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null(
_temp602->topt))->v); struct Cyc_Absyn_PtrInfo _temp739; struct Cyc_Absyn_Conref*
_temp741; struct Cyc_Absyn_Tqual _temp743; struct Cyc_Absyn_Conref* _temp745;
void* _temp747; void* _temp749; struct Cyc_Absyn_Exp* _temp751; struct Cyc_Absyn_Tqual
_temp753; void* _temp755; _LL733: if(( unsigned int) _temp731 > 4u?*(( int*)
_temp731) == Cyc_Absyn_PointerType: 0){ _LL740: _temp739=(( struct Cyc_Absyn_PointerType_struct*)
_temp731)->f1; _LL750: _temp749=( void*) _temp739.elt_typ; goto _LL748; _LL748:
_temp747=( void*) _temp739.rgn_typ; goto _LL746; _LL746: _temp745= _temp739.nullable;
goto _LL744; _LL744: _temp743= _temp739.tq; goto _LL742; _LL742: _temp741=
_temp739.bounds; goto _LL734;} else{ goto _LL735;} _LL735: if(( unsigned int)
_temp731 > 4u?*(( int*) _temp731) == Cyc_Absyn_ArrayType: 0){ _LL756: _temp755=(
void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp731)->f1; goto _LL754; _LL754:
_temp753=(( struct Cyc_Absyn_ArrayType_struct*) _temp731)->f2; goto _LL752;
_LL752: _temp751=(( struct Cyc_Absyn_ArrayType_struct*) _temp731)->f3; goto
_LL736;} else{ goto _LL737;} _LL737: goto _LL738; _LL734: _temp753= _temp743;
goto _LL736; _LL736: if( ! _temp753.q_const){ return;} goto _LL732; _LL738: goto
_LL732; _LL732:;} goto _LL543; _LL561: _temp608= _temp604; goto _LL563; _LL563:
Cyc_Tcexp_check_writable( te, _temp608); return; _LL565: goto _LL543; _LL543:;}
Cyc_Tcutil_terr( e->loc,({ unsigned char* _temp757=( unsigned char*)"attempt to write a read-only location";
struct _tagged_string _temp758; _temp758.curr= _temp757; _temp758.base= _temp757;
_temp758.last_plus_one= _temp757 + 38; _temp758;}));} static void* Cyc_Tcexp_tcIncrement(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e, void* i){ Cyc_Tcexp_tcExpNoPromote( te, 0, e); if( ! Cyc_Absyn_is_lvalue(
e)){ return Cyc_Tcexp_expr_err( te, loc,({ unsigned char* _temp759=(
unsigned char*)"increment/decrement of non-lvalue"; struct _tagged_string
_temp760; _temp760.curr= _temp759; _temp760.base= _temp759; _temp760.last_plus_one=
_temp759 + 34; _temp760;}));} Cyc_Tcexp_check_writable( te, e);{ void* t=( void*)((
struct Cyc_Core_Opt*) _check_null( e->topt))->v; if( ! Cyc_Tcutil_is_numeric( e)?
! Cyc_Tcutil_is_tagged_pointer_typ( t): 0){ Cyc_Tcutil_terr( e->loc,( struct
_tagged_string)({ struct _tagged_string _temp761= Cyc_Absynpp_typ2string( t);
xprintf("expecting arithmetic or ? type but found %.*s", _temp761.last_plus_one
- _temp761.curr, _temp761.curr);}));} return t;}} static void* Cyc_Tcexp_tcConditional(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e1, struct Cyc_Absyn_Exp* e2, struct Cyc_Absyn_Exp* e3){ Cyc_Tcexp_tcTest(
te, e1,({ unsigned char* _temp762=( unsigned char*)"conditional expression";
struct _tagged_string _temp763; _temp763.curr= _temp762; _temp763.base= _temp762;
_temp763.last_plus_one= _temp762 + 23; _temp763;})); Cyc_Tcexp_tcExp( te, topt,
e2); Cyc_Tcexp_tcExp( te, topt, e3);{ void* t= Cyc_Absyn_new_evar(( struct Cyc_Core_Opt*)&
Cyc_Tcexp_mk,({ struct Cyc_Core_Opt* _temp772=( struct Cyc_Core_Opt*) GC_malloc(
sizeof( struct Cyc_Core_Opt)); _temp772->v=( void*) Cyc_Tcenv_lookup_type_vars(
te); _temp772;})); struct Cyc_List_List* _temp765=({ struct Cyc_List_List*
_temp764=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp764->hd=( void*) e3; _temp764->tl= 0; _temp764;}); goto _LL766; _LL766: {
struct Cyc_List_List* _temp768=({ struct Cyc_List_List* _temp767=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp767->hd=( void*) e2; _temp767->tl=
_temp765; _temp767;}); goto _LL769; _LL769: if( ! Cyc_Tcutil_coerce_list( te, t,
_temp768)){ Cyc_Tcutil_terr( loc,( struct _tagged_string)({ struct
_tagged_string _temp770= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*)
_check_null( e2->topt))->v); struct _tagged_string _temp771= Cyc_Absynpp_typ2string((
void*)(( struct Cyc_Core_Opt*) _check_null( e3->topt))->v); xprintf("conditional clause types do not match: %.*s != %.*s",
_temp770.last_plus_one - _temp770.curr, _temp770.curr, _temp771.last_plus_one -
_temp771.curr, _temp771.curr);}));} return t;}}} static void* Cyc_Tcexp_tcAssignOp(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e1, struct Cyc_Core_Opt* po, struct Cyc_Absyn_Exp* e2){ Cyc_Tcexp_tcExpNoPromote(
te, 0, e1); Cyc_Tcexp_tcExp( te,( void**)(( void**)(( void*)&(( struct Cyc_Core_Opt*)
_check_null( e1->topt))->v)), e2);{ void* t1=( void*)(( struct Cyc_Core_Opt*)
_check_null( e1->topt))->v; void* t2=( void*)(( struct Cyc_Core_Opt*)
_check_null( e2->topt))->v;{ void* _temp773= Cyc_Tcutil_compress( t1); struct
Cyc_Absyn_Exp* _temp779; struct Cyc_Absyn_Tqual _temp781; void* _temp783; _LL775:
if(( unsigned int) _temp773 > 4u?*(( int*) _temp773) == Cyc_Absyn_ArrayType: 0){
_LL784: _temp783=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp773)->f1;
goto _LL782; _LL782: _temp781=(( struct Cyc_Absyn_ArrayType_struct*) _temp773)->f2;
goto _LL780; _LL780: _temp779=(( struct Cyc_Absyn_ArrayType_struct*) _temp773)->f3;
goto _LL776;} else{ goto _LL777;} _LL777: goto _LL778; _LL776: Cyc_Tcutil_terr(
loc,({ unsigned char* _temp785=( unsigned char*)"cannot assign to an array";
struct _tagged_string _temp786; _temp786.curr= _temp785; _temp786.base= _temp785;
_temp786.last_plus_one= _temp785 + 26; _temp786;})); goto _LL774; _LL778: goto
_LL774; _LL774:;} if( ! Cyc_Absyn_is_lvalue( e1)){ return Cyc_Tcexp_expr_err( te,
loc,({ unsigned char* _temp787=( unsigned char*)"assignment to non-lvalue";
struct _tagged_string _temp788; _temp788.curr= _temp787; _temp788.base= _temp787;
_temp788.last_plus_one= _temp787 + 25; _temp788;}));} Cyc_Tcexp_check_writable(
te, e1); if( po == 0){ if( ! Cyc_Tcutil_coerce_assign( te, e2, t1)){ return Cyc_Tcexp_expr_err(
te, loc,( struct _tagged_string)({ struct _tagged_string _temp789= Cyc_Absynpp_typ2string(
t1); struct _tagged_string _temp790= Cyc_Absynpp_typ2string( t2); xprintf("type mismatch: %.*s != %.*s",
_temp789.last_plus_one - _temp789.curr, _temp789.curr, _temp790.last_plus_one -
_temp790.curr, _temp790.curr);}));}} else{ void* _temp791=( void*)(( struct Cyc_Core_Opt*)
_check_null( po))->v; goto _LL792; _LL792: { void* _temp793= Cyc_Tcexp_tcBinPrimop(
te, loc, 0, _temp791, e1, e2); goto _LL794; _LL794: if( !( Cyc_Tcutil_unify(
_temp793, t1)? 1: Cyc_Tcutil_coerceable( _temp793))){ return Cyc_Tcexp_expr_err(
te, loc,({ unsigned char* _temp795=( unsigned char*)"Cannot use this operator in an assignment";
struct _tagged_string _temp796; _temp796.curr= _temp795; _temp796.base= _temp795;
_temp796.last_plus_one= _temp795 + 42; _temp796;}));}}} return t2;}} static void*
Cyc_Tcexp_tcSeqExp( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc,
void** topt, struct Cyc_Absyn_Exp* e1, struct Cyc_Absyn_Exp* e2){ Cyc_Tcexp_tcExp(
te, 0, e1); Cyc_Tcexp_tcExp( te, topt, e2); return( void*)(( struct Cyc_Core_Opt*)
_check_null( e2->topt))->v;} static struct Cyc_Absyn_Tunionfield* Cyc_Tcexp_tcInjection(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Absyn_Exp* e, void* tu, struct
_RegionHandle* r, struct Cyc_List_List* inst, struct Cyc_List_List* fs){ struct
Cyc_List_List* fields; void* t1=( void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v;
for( fields= fs; fields != 0; fields=(( struct Cyc_List_List*) _check_null(
fields))->tl){ void* _temp799; struct Cyc_Position_Segment* _temp801; struct Cyc_List_List*
_temp803; struct Cyc_List_List* _temp805; struct _tuple1* _temp807; struct Cyc_Absyn_Tunionfield
_temp797=*(( struct Cyc_Absyn_Tunionfield*)(( struct Cyc_List_List*) _check_null(
fields))->hd); _LL808: _temp807= _temp797.name; goto _LL806; _LL806: _temp805=
_temp797.tvs; goto _LL804; _LL804: _temp803= _temp797.typs; goto _LL802; _LL802:
_temp801= _temp797.loc; goto _LL800; _LL800: _temp799=( void*) _temp797.sc; goto
_LL798; _LL798: if(( _temp803 == 0? 1:(( struct Cyc_List_List*) _check_null(
_temp803))->tl != 0)? 1: _temp805 != 0){ continue;}{ void* t2= Cyc_Tcutil_rsubstitute(
r, inst,(*(( struct _tuple8*)(( struct Cyc_List_List*) _check_null( _temp803))->hd)).f2);
if( Cyc_Tcutil_unify( t1, t2)){ return( struct Cyc_Absyn_Tunionfield*)(( struct
Cyc_Absyn_Tunionfield*)(( struct Cyc_List_List*) _check_null( fields))->hd);}}}
for( fields= fs; fields != 0; fields=(( struct Cyc_List_List*) _check_null(
fields))->tl){ void* _temp811; struct Cyc_Position_Segment* _temp813; struct Cyc_List_List*
_temp815; struct Cyc_List_List* _temp817; struct _tuple1* _temp819; struct Cyc_Absyn_Tunionfield
_temp809=*(( struct Cyc_Absyn_Tunionfield*)(( struct Cyc_List_List*) _check_null(
fields))->hd); _LL820: _temp819= _temp809.name; goto _LL818; _LL818: _temp817=
_temp809.tvs; goto _LL816; _LL816: _temp815= _temp809.typs; goto _LL814; _LL814:
_temp813= _temp809.loc; goto _LL812; _LL812: _temp811=( void*) _temp809.sc; goto
_LL810; _LL810: if(( _temp815 == 0? 1:(( struct Cyc_List_List*) _check_null(
_temp815))->tl != 0)? 1: _temp817 != 0){ continue;}{ void* t2= Cyc_Tcutil_rsubstitute(
r, inst,(*(( struct _tuple8*)(( struct Cyc_List_List*) _check_null( _temp815))->hd)).f2);
if( Cyc_Tcutil_silent_castable( te, e->loc, t1, t2)){ Cyc_Tcutil_unchecked_cast(
te, e, t2); return( struct Cyc_Absyn_Tunionfield*)(( struct Cyc_Absyn_Tunionfield*)((
struct Cyc_List_List*) _check_null( fields))->hd);}}} Cyc_Tcutil_terr( e->loc,(
struct _tagged_string)({ struct _tagged_string _temp821= Cyc_Absynpp_typ2string(
tu); struct _tagged_string _temp822= Cyc_Absynpp_typ2string( t1); xprintf("can't find a field in %.*s to inject a value of type %.*s",
_temp821.last_plus_one - _temp821.curr, _temp821.curr, _temp822.last_plus_one -
_temp822.curr, _temp822.curr);})); return 0;} static void* Cyc_Tcexp_tcFnCall(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e, struct Cyc_List_List* es, struct Cyc_Absyn_VarargCallInfo**
vararg_call_info){ te= Cyc_Tcenv_new_block( loc, te); Cyc_Tcexp_tcExp( te, 0, e);{
void* t= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v);
void* _temp823= t; struct Cyc_Absyn_PtrInfo _temp829; struct Cyc_Absyn_Conref*
_temp831; struct Cyc_Absyn_Tqual _temp833; struct Cyc_Absyn_Conref* _temp835;
void* _temp837; void* _temp839; _LL825: if(( unsigned int) _temp823 > 4u?*(( int*)
_temp823) == Cyc_Absyn_PointerType: 0){ _LL830: _temp829=(( struct Cyc_Absyn_PointerType_struct*)
_temp823)->f1; _LL840: _temp839=( void*) _temp829.elt_typ; goto _LL838; _LL838:
_temp837=( void*) _temp829.rgn_typ; goto _LL836; _LL836: _temp835= _temp829.nullable;
goto _LL834; _LL834: _temp833= _temp829.tq; goto _LL832; _LL832: _temp831=
_temp829.bounds; goto _LL826;} else{ goto _LL827;} _LL827: goto _LL828; _LL826:
Cyc_Tcenv_check_rgn_accessible( te, loc, _temp837); Cyc_Tcutil_check_nonzero_bound(
loc, _temp831);{ void* _temp841= Cyc_Tcutil_compress( _temp839); struct Cyc_Absyn_FnInfo
_temp847; struct Cyc_List_List* _temp849; struct Cyc_List_List* _temp851; struct
Cyc_Absyn_VarargInfo* _temp853; int _temp855; struct Cyc_List_List* _temp857;
void* _temp859; struct Cyc_Core_Opt* _temp861; struct Cyc_List_List* _temp863;
_LL843: if(( unsigned int) _temp841 > 4u?*(( int*) _temp841) == Cyc_Absyn_FnType:
0){ _LL848: _temp847=(( struct Cyc_Absyn_FnType_struct*) _temp841)->f1; _LL864:
_temp863= _temp847.tvars; goto _LL862; _LL862: _temp861= _temp847.effect; goto
_LL860; _LL860: _temp859=( void*) _temp847.ret_typ; goto _LL858; _LL858:
_temp857= _temp847.args; goto _LL856; _LL856: _temp855= _temp847.c_varargs; goto
_LL854; _LL854: _temp853= _temp847.cyc_varargs; goto _LL852; _LL852: _temp851=
_temp847.rgn_po; goto _LL850; _LL850: _temp849= _temp847.attributes; goto _LL844;}
else{ goto _LL845;} _LL845: goto _LL846; _LL844: if( topt != 0){ Cyc_Tcutil_unify(
_temp859,*(( void**) _check_null( topt)));} while( es != 0? _temp857 != 0: 0) {
struct Cyc_Absyn_Exp* e1=( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*)
_check_null( es))->hd; void* t2=(*(( struct _tuple2*)(( struct Cyc_List_List*)
_check_null( _temp857))->hd)).f3; Cyc_Tcexp_tcExp( te,( void**)& t2, e1); if( !
Cyc_Tcutil_coerce_arg( te, e1, t2)){ Cyc_Tcutil_terr( loc,( struct
_tagged_string)({ struct _tagged_string _temp865= Cyc_Absynpp_typ2string(( void*)((
struct Cyc_Core_Opt*) _check_null( e1->topt))->v); struct _tagged_string
_temp866= Cyc_Absynpp_typ2string( t2); xprintf("actual argument has type %.*s but formal has type %.*s",
_temp865.last_plus_one - _temp865.curr, _temp865.curr, _temp866.last_plus_one -
_temp866.curr, _temp866.curr);}));} es=(( struct Cyc_List_List*) _check_null( es))->tl;
_temp857=(( struct Cyc_List_List*) _check_null( _temp857))->tl;} if( _temp857 !=
0){ Cyc_Tcutil_terr( loc,({ unsigned char* _temp867=( unsigned char*)"too few arguments for function";
struct _tagged_string _temp868; _temp868.curr= _temp867; _temp868.base= _temp867;
_temp868.last_plus_one= _temp867 + 31; _temp868;}));} else{ if( es != 0){ if(
_temp855){ for( 0; es != 0; es=(( struct Cyc_List_List*) _check_null( es))->tl){
Cyc_Tcexp_tcExp( te, 0,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*)
_check_null( es))->hd);}} else{ if( _temp853 == 0){ Cyc_Tcutil_terr( loc,({
unsigned char* _temp869=( unsigned char*)"too many arguments for function";
struct _tagged_string _temp870; _temp870.curr= _temp869; _temp870.base= _temp869;
_temp870.last_plus_one= _temp869 + 32; _temp870;}));} else{ int _temp873; void*
_temp875; void* _temp877; struct Cyc_Absyn_Tqual _temp879; struct Cyc_Core_Opt*
_temp881; struct Cyc_Absyn_VarargInfo _temp871=*(( struct Cyc_Absyn_VarargInfo*)
_check_null( _temp853)); _LL882: _temp881= _temp871.name; goto _LL880; _LL880:
_temp879= _temp871.tq; goto _LL878; _LL878: _temp877=( void*) _temp871.type;
goto _LL876; _LL876: _temp875=( void*) _temp871.rgn; goto _LL874; _LL874:
_temp873= _temp871.inject; goto _LL872; _LL872: { struct Cyc_Absyn_VarargCallInfo*
_temp884=({ struct Cyc_Absyn_VarargCallInfo* _temp883=( struct Cyc_Absyn_VarargCallInfo*)
GC_malloc( sizeof( struct Cyc_Absyn_VarargCallInfo)); _temp883->num_varargs= 0;
_temp883->injectors= 0; _temp883->vai=( struct Cyc_Absyn_VarargInfo*)
_check_null( _temp853); _temp883;}); goto _LL885; _LL885:* vararg_call_info=
_temp884; if( ! Cyc_Tcutil_unify( Cyc_Tcenv_curr_rgn( te), _temp875)){ Cyc_Tcutil_terr(
loc,( struct _tagged_string)({ struct _tagged_string _temp886= Cyc_Absynpp_typ2string(
_temp875); struct _tagged_string _temp887= Cyc_Absynpp_typ2string( Cyc_Tcenv_curr_rgn(
te)); xprintf("I have no idea how this could fail, but it did because the region for the varargs (%.*s) doesn't unify with the expected new_block region (%.*s).",
_temp886.last_plus_one - _temp886.curr, _temp886.curr, _temp887.last_plus_one -
_temp887.curr, _temp887.curr);}));} if( ! _temp873){ for( 0; es != 0; es=((
struct Cyc_List_List*) _check_null( es))->tl){ struct Cyc_Absyn_Exp* e1=( struct
Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd;(( struct Cyc_Absyn_VarargCallInfo*)
_check_null( _temp884))->num_varargs ++; Cyc_Tcexp_tcExp( te,( void**)& _temp877,
e1); if( ! Cyc_Tcutil_coerce_arg( te, e1, _temp877)){ Cyc_Tcutil_terr( loc,(
struct _tagged_string)({ struct _tagged_string _temp888= Cyc_Absynpp_typ2string(
_temp877); struct _tagged_string _temp889= Cyc_Absynpp_typ2string(( void*)((
struct Cyc_Core_Opt*) _check_null( e1->topt))->v); xprintf("vararg requires type %.*s but argument has type %.*s",
_temp888.last_plus_one - _temp888.curr, _temp888.curr, _temp889.last_plus_one -
_temp889.curr, _temp889.curr);}));}}} else{ void* _temp890= Cyc_Tcutil_compress(
_temp877); struct Cyc_Absyn_TunionInfo _temp896; void* _temp898; struct Cyc_List_List*
_temp900; void* _temp902; struct Cyc_Absyn_Tuniondecl* _temp904; _LL892: if((
unsigned int) _temp890 > 4u?*(( int*) _temp890) == Cyc_Absyn_TunionType: 0){
_LL897: _temp896=(( struct Cyc_Absyn_TunionType_struct*) _temp890)->f1; _LL903:
_temp902=( void*) _temp896.tunion_info; if(*(( int*) _temp902) == Cyc_Absyn_KnownTunion){
_LL905: _temp904=(( struct Cyc_Absyn_KnownTunion_struct*) _temp902)->f1; goto
_LL901;} else{ goto _LL894;} _LL901: _temp900= _temp896.targs; goto _LL899;
_LL899: _temp898=( void*) _temp896.rgn; goto _LL893;} else{ goto _LL894;} _LL894:
goto _LL895; _LL893: { struct Cyc_Absyn_Tuniondecl* _temp906=* Cyc_Tcenv_lookup_tuniondecl(
te, loc, _temp904->name); goto _LL907; _LL907: if( ! Cyc_Tcutil_unify( _temp898,
_temp875)){ Cyc_Tcutil_terr( loc,( struct _tagged_string) xprintf("bad region for injected varargs"));}{
struct Cyc_List_List* fields= 0; if( _temp906->fields == 0){ Cyc_Tcutil_terr(
loc,( struct _tagged_string)({ struct _tagged_string _temp908= Cyc_Absynpp_typ2string(
_temp877); xprintf("can't inject into %.*s", _temp908.last_plus_one - _temp908.curr,
_temp908.curr);}));} else{ fields=( struct Cyc_List_List*)(( struct Cyc_Core_Opt*)
_check_null( _temp906->fields))->v;}{ struct _RegionHandle _temp909= _new_region();
struct _RegionHandle* rgn=& _temp909; _push_region( rgn);{ struct Cyc_List_List*
_temp910=(( struct Cyc_List_List*(*)( struct _RegionHandle* r3, struct
_RegionHandle* r4, struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_rzip)(
rgn, rgn, _temp906->tvs, _temp900); goto _LL911; _LL911: for( 0; es != 0; es=((
struct Cyc_List_List*) _check_null( es))->tl){(( struct Cyc_Absyn_VarargCallInfo*)
_check_null( _temp884))->num_varargs ++;{ struct Cyc_Absyn_Exp* e1=( struct Cyc_Absyn_Exp*)((
struct Cyc_List_List*) _check_null( es))->hd; Cyc_Tcexp_tcExp( te, 0, e1);{
struct Cyc_Absyn_Tunionfield* _temp912= Cyc_Tcexp_tcInjection( te, e1, _temp877,
rgn, _temp910, fields); goto _LL913; _LL913: if( _temp912 != 0){(( struct Cyc_Absyn_VarargCallInfo*)
_check_null( _temp884))->injectors=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x, struct Cyc_List_List* y)) Cyc_List_append)((( struct Cyc_Absyn_VarargCallInfo*)
_check_null( _temp884))->injectors,({ struct Cyc_List_List* _temp914=( struct
Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List)); _temp914->hd=( void*)((
struct Cyc_Absyn_Tunionfield*) _check_null( _temp912)); _temp914->tl= 0;
_temp914;}));}}}}}; _pop_region(& _temp909);} goto _LL891;}} _LL895: Cyc_Tcutil_terr(
loc,({ unsigned char* _temp915=( unsigned char*)"bad inject vararg type"; struct
_tagged_string _temp916; _temp916.curr= _temp915; _temp916.base= _temp915;
_temp916.last_plus_one= _temp915 + 23; _temp916;})); goto _LL891; _LL891:;}}}}}}
Cyc_Tcenv_check_effect_accessible( te, loc,( void*)(( struct Cyc_Core_Opt*)
_check_null( _temp861))->v); Cyc_Tcenv_check_rgn_partial_order( te, loc,
_temp851); return _temp859; _LL846: return Cyc_Tcexp_expr_err( te, loc,({
unsigned char* _temp917=( unsigned char*)"expected pointer to function"; struct
_tagged_string _temp918; _temp918.curr= _temp917; _temp918.base= _temp917;
_temp918.last_plus_one= _temp917 + 29; _temp918;})); _LL842:;} _LL828: return
Cyc_Tcexp_expr_err( te, loc,({ unsigned char* _temp919=( unsigned char*)"expected pointer to function";
struct _tagged_string _temp920; _temp920.curr= _temp919; _temp920.base= _temp919;
_temp920.last_plus_one= _temp919 + 29; _temp920;})); _LL824:;}} static void* Cyc_Tcexp_tcThrow(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e){ Cyc_Tcexp_tcExp( te,( void**)& Cyc_Absyn_exn_typ, e); if( !
Cyc_Tcutil_coerce_use( te, e, Cyc_Absyn_exn_typ)){ Cyc_Tcutil_terr( loc,( struct
_tagged_string)({ struct _tagged_string _temp921= Cyc_Absynpp_typ2string(( void*)((
struct Cyc_Core_Opt*) _check_null( e->topt))->v); xprintf("expected xtunion exn but found %.*s",
_temp921.last_plus_one - _temp921.curr, _temp921.curr);}));} return Cyc_Absyn_wildtyp(({
struct Cyc_Core_Opt* _temp922=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct
Cyc_Core_Opt)); _temp922->v=( void*) Cyc_Tcenv_lookup_type_vars( te); _temp922;}));}
static void* Cyc_Tcexp_tcInstantiate( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment*
loc, void** topt, struct Cyc_Absyn_Exp* e, struct Cyc_List_List* ts){ Cyc_Tcexp_tcExpNoInst(
te, 0, e);( void*)((( struct Cyc_Core_Opt*) _check_null( e->topt))->v=( void*)
Cyc_Absyn_pointer_expand( Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v)));{ void* t1= Cyc_Tcutil_compress(( void*)(( struct
Cyc_Core_Opt*) _check_null( e->topt))->v);{ void* _temp923= t1; struct Cyc_Absyn_PtrInfo
_temp929; struct Cyc_Absyn_Conref* _temp931; struct Cyc_Absyn_Tqual _temp933;
struct Cyc_Absyn_Conref* _temp935; void* _temp937; void* _temp939; _LL925: if((
unsigned int) _temp923 > 4u?*(( int*) _temp923) == Cyc_Absyn_PointerType: 0){
_LL930: _temp929=(( struct Cyc_Absyn_PointerType_struct*) _temp923)->f1; _LL940:
_temp939=( void*) _temp929.elt_typ; goto _LL938; _LL938: _temp937=( void*)
_temp929.rgn_typ; goto _LL936; _LL936: _temp935= _temp929.nullable; goto _LL934;
_LL934: _temp933= _temp929.tq; goto _LL932; _LL932: _temp931= _temp929.bounds;
goto _LL926;} else{ goto _LL927;} _LL927: goto _LL928; _LL926:{ void* _temp941=
Cyc_Tcutil_compress( _temp939); struct Cyc_Absyn_FnInfo _temp947; struct Cyc_List_List*
_temp949; struct Cyc_List_List* _temp951; struct Cyc_Absyn_VarargInfo* _temp953;
int _temp955; struct Cyc_List_List* _temp957; void* _temp959; struct Cyc_Core_Opt*
_temp961; struct Cyc_List_List* _temp963; _LL943: if(( unsigned int) _temp941 >
4u?*(( int*) _temp941) == Cyc_Absyn_FnType: 0){ _LL948: _temp947=(( struct Cyc_Absyn_FnType_struct*)
_temp941)->f1; _LL964: _temp963= _temp947.tvars; goto _LL962; _LL962: _temp961=
_temp947.effect; goto _LL960; _LL960: _temp959=( void*) _temp947.ret_typ; goto
_LL958; _LL958: _temp957= _temp947.args; goto _LL956; _LL956: _temp955= _temp947.c_varargs;
goto _LL954; _LL954: _temp953= _temp947.cyc_varargs; goto _LL952; _LL952:
_temp951= _temp947.rgn_po; goto _LL950; _LL950: _temp949= _temp947.attributes;
goto _LL944;} else{ goto _LL945;} _LL945: goto _LL946; _LL944: { struct Cyc_List_List*
instantiation= 0; if((( int(*)( struct Cyc_List_List* x)) Cyc_List_length)( ts)
!=(( int(*)( struct Cyc_List_List* x)) Cyc_List_length)( _temp963)){ return Cyc_Tcexp_expr_err(
te, loc,({ unsigned char* _temp965=( unsigned char*)"type instantiation mismatch";
struct _tagged_string _temp966; _temp966.curr= _temp965; _temp966.base= _temp965;
_temp966.last_plus_one= _temp965 + 28; _temp966;}));} for( 0; ts != 0;( ts=((
struct Cyc_List_List*) _check_null( ts))->tl, _temp963=(( struct Cyc_List_List*)
_check_null( _temp963))->tl)){ void* k=(( void*(*)( struct Cyc_Absyn_Conref* x))
Cyc_Absyn_conref_val)((( struct Cyc_Absyn_Tvar*)(( struct Cyc_List_List*)
_check_null( _temp963))->hd)->kind); Cyc_Tcutil_check_type( loc, te, Cyc_Tcenv_lookup_type_vars(
te), k,( void*)(( struct Cyc_List_List*) _check_null( ts))->hd); instantiation=({
struct Cyc_List_List* _temp967=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp967->hd=( void*)({ struct _tuple5* _temp968=(
struct _tuple5*) GC_malloc( sizeof( struct _tuple5)); _temp968->f1=( struct Cyc_Absyn_Tvar*)((
struct Cyc_List_List*) _check_null( _temp963))->hd; _temp968->f2=( void*)((
struct Cyc_List_List*) _check_null( ts))->hd; _temp968;}); _temp967->tl=
instantiation; _temp967;});}{ void* new_fn_typ= Cyc_Tcutil_substitute(
instantiation,( void*)({ struct Cyc_Absyn_FnType_struct* _temp972=( struct Cyc_Absyn_FnType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_FnType_struct)); _temp972[ 0]=({ struct Cyc_Absyn_FnType_struct
_temp973; _temp973.tag= Cyc_Absyn_FnType; _temp973.f1=({ struct Cyc_Absyn_FnInfo
_temp974; _temp974.tvars= 0; _temp974.effect= _temp961; _temp974.ret_typ=( void*)
_temp959; _temp974.args= _temp957; _temp974.c_varargs= _temp955; _temp974.cyc_varargs=
_temp953; _temp974.rgn_po= _temp951; _temp974.attributes= _temp949; _temp974;});
_temp973;}); _temp972;})); void* new_typ=( void*)({ struct Cyc_Absyn_PointerType_struct*
_temp969=( struct Cyc_Absyn_PointerType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct));
_temp969[ 0]=({ struct Cyc_Absyn_PointerType_struct _temp970; _temp970.tag= Cyc_Absyn_PointerType;
_temp970.f1=({ struct Cyc_Absyn_PtrInfo _temp971; _temp971.elt_typ=( void*)
new_fn_typ; _temp971.rgn_typ=( void*) _temp937; _temp971.nullable= _temp935;
_temp971.tq= _temp933; _temp971.bounds= _temp931; _temp971;}); _temp970;});
_temp969;}); return new_typ;}} _LL946: goto _LL942; _LL942:;} goto _LL924;
_LL928: goto _LL924; _LL924:;} return Cyc_Tcexp_expr_err( te, loc,( struct
_tagged_string)({ struct _tagged_string _temp975= Cyc_Absynpp_typ2string( t1);
xprintf("expecting polymorphic type but found %.*s", _temp975.last_plus_one -
_temp975.curr, _temp975.curr);}));}} static void* Cyc_Tcexp_tcCast( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void** topt, void* t, struct Cyc_Absyn_Exp*
e){ Cyc_Tcutil_check_type( loc, te, Cyc_Tcenv_lookup_type_vars( te),( void*) Cyc_Absyn_MemKind,
t); Cyc_Tcexp_tcExp( te, 0, e);{ void* t2=( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v; if( ! Cyc_Tcutil_silent_castable( te, loc, t2, t)? !
Cyc_Tcutil_castable( te, loc, t2, t): 0){ return Cyc_Tcexp_expr_err( te, loc,(
struct _tagged_string)({ struct _tagged_string _temp976= Cyc_Absynpp_typ2string(
t2); struct _tagged_string _temp977= Cyc_Absynpp_typ2string( t); xprintf("cannot cast %.*s to %.*s",
_temp976.last_plus_one - _temp976.curr, _temp976.curr, _temp977.last_plus_one -
_temp977.curr, _temp977.curr);}));} return t;}} static void* Cyc_Tcexp_tcAddress(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e){ void** _temp978= 0; goto _LL979; _LL979: { struct Cyc_Absyn_Tqual
_temp980= Cyc_Absyn_empty_tqual(); goto _LL981; _LL981: if( topt != 0){ void*
_temp982= Cyc_Tcutil_compress(*(( void**) _check_null( topt))); struct Cyc_Absyn_PtrInfo
_temp988; struct Cyc_Absyn_Conref* _temp990; struct Cyc_Absyn_Tqual _temp992;
struct Cyc_Absyn_Conref* _temp994; void* _temp996; void* _temp998; _LL984: if((
unsigned int) _temp982 > 4u?*(( int*) _temp982) == Cyc_Absyn_PointerType: 0){
_LL989: _temp988=(( struct Cyc_Absyn_PointerType_struct*) _temp982)->f1; _LL999:
_temp998=( void*) _temp988.elt_typ; goto _LL997; _LL997: _temp996=( void*)
_temp988.rgn_typ; goto _LL995; _LL995: _temp994= _temp988.nullable; goto _LL993;
_LL993: _temp992= _temp988.tq; goto _LL991; _LL991: _temp990= _temp988.bounds;
goto _LL985;} else{ goto _LL986;} _LL986: goto _LL987; _LL985: _temp978=({ void**
_temp1000=( void**) GC_malloc( sizeof( void*)); _temp1000[ 0]= _temp998;
_temp1000;}); _temp980= _temp992; goto _LL983; _LL987: goto _LL983; _LL983:;}
Cyc_Tcexp_tcExpNoInst( te, _temp978, e);{ void* _temp1001=( void*) e->r; struct
Cyc_Absyn_Structdecl* _temp1009; struct Cyc_List_List* _temp1011; struct Cyc_Core_Opt*
_temp1013; struct _tuple1* _temp1015; struct Cyc_List_List* _temp1017; _LL1003:
if(*(( int*) _temp1001) == Cyc_Absyn_Struct_e){ _LL1016: _temp1015=(( struct Cyc_Absyn_Struct_e_struct*)
_temp1001)->f1; goto _LL1014; _LL1014: _temp1013=(( struct Cyc_Absyn_Struct_e_struct*)
_temp1001)->f2; goto _LL1012; _LL1012: _temp1011=(( struct Cyc_Absyn_Struct_e_struct*)
_temp1001)->f3; goto _LL1010; _LL1010: _temp1009=(( struct Cyc_Absyn_Struct_e_struct*)
_temp1001)->f4; goto _LL1004;} else{ goto _LL1005;} _LL1005: if(*(( int*)
_temp1001) == Cyc_Absyn_Tuple_e){ _LL1018: _temp1017=(( struct Cyc_Absyn_Tuple_e_struct*)
_temp1001)->f1; goto _LL1006;} else{ goto _LL1007;} _LL1007: goto _LL1008;
_LL1004: goto _LL1006; _LL1006: Cyc_Tcutil_warn( loc,({ unsigned char* _temp1019=(
unsigned char*)"& used to allocate"; struct _tagged_string _temp1020; _temp1020.curr=
_temp1019; _temp1020.base= _temp1019; _temp1020.last_plus_one= _temp1019 + 19;
_temp1020;}));{ void*(* _temp1021)( void* t, void* rgn, struct Cyc_Absyn_Tqual
tq)= Cyc_Absyn_at_typ; goto _LL1022; _LL1022: if( topt != 0){ void* _temp1023=
Cyc_Tcutil_compress(*(( void**) _check_null( topt))); struct Cyc_Absyn_PtrInfo
_temp1029; struct Cyc_Absyn_Conref* _temp1031; struct Cyc_Absyn_Tqual _temp1033;
struct Cyc_Absyn_Conref* _temp1035; void* _temp1037; void* _temp1039; _LL1025:
if(( unsigned int) _temp1023 > 4u?*(( int*) _temp1023) == Cyc_Absyn_PointerType:
0){ _LL1030: _temp1029=(( struct Cyc_Absyn_PointerType_struct*) _temp1023)->f1;
_LL1040: _temp1039=( void*) _temp1029.elt_typ; goto _LL1038; _LL1038: _temp1037=(
void*) _temp1029.rgn_typ; goto _LL1036; _LL1036: _temp1035= _temp1029.nullable;
goto _LL1034; _LL1034: _temp1033= _temp1029.tq; goto _LL1032; _LL1032: _temp1031=
_temp1029.bounds; goto _LL1026;} else{ goto _LL1027;} _LL1027: goto _LL1028;
_LL1026: if((( int(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(
_temp1035)){ _temp1021= Cyc_Absyn_star_typ;} goto _LL1024; _LL1028: goto _LL1024;
_LL1024:;} return _temp1021(( void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v,(
void*) Cyc_Absyn_HeapRgn, _temp980);} _LL1008: goto _LL1002; _LL1002:;}{ void*
_temp1043; int _temp1045; struct _tuple6 _temp1041= Cyc_Tcutil_addressof_props(
te, e); _LL1046: _temp1045= _temp1041.f1; goto _LL1044; _LL1044: _temp1043=
_temp1041.f2; goto _LL1042; _LL1042: { struct Cyc_Absyn_Tqual tq= Cyc_Absyn_empty_tqual();
if( _temp1045){ tq.q_const= 1;}{ void* t= Cyc_Absyn_at_typ(( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v, _temp1043, tq); return t;}}}}} static void* Cyc_Tcexp_tcSizeof(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, void*
t){ Cyc_Tcutil_check_type( loc, te, Cyc_Tcenv_lookup_type_vars( te),( void*) Cyc_Absyn_MemKind,
t); if( ! Cyc_Evexp_okay_szofarg( t)){ Cyc_Tcutil_terr( loc,( struct
_tagged_string)({ struct _tagged_string _temp1047= Cyc_Absynpp_typ2string( t);
xprintf("sizeof applied to type %.*s, which has unknown size here", _temp1047.last_plus_one
- _temp1047.curr, _temp1047.curr);}));} return Cyc_Absyn_uint_t;} static void*
Cyc_Tcexp_tcOffsetof( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment*
loc, void** topt, void* t, struct _tagged_string* n){ Cyc_Tcutil_check_type( loc,
te, Cyc_Tcenv_lookup_type_vars( te),( void*) Cyc_Absyn_MemKind, t);{ int
bad_type= 1;{ void* _temp1048= Cyc_Tcutil_compress( t); struct Cyc_Absyn_Structdecl**
_temp1056; struct Cyc_List_List* _temp1058; struct _tuple1* _temp1060; struct
Cyc_List_List* _temp1062; _LL1050: if(( unsigned int) _temp1048 > 4u?*(( int*)
_temp1048) == Cyc_Absyn_StructType: 0){ _LL1061: _temp1060=(( struct Cyc_Absyn_StructType_struct*)
_temp1048)->f1; goto _LL1059; _LL1059: _temp1058=(( struct Cyc_Absyn_StructType_struct*)
_temp1048)->f2; goto _LL1057; _LL1057: _temp1056=(( struct Cyc_Absyn_StructType_struct*)
_temp1048)->f3; goto _LL1051;} else{ goto _LL1052;} _LL1052: if(( unsigned int)
_temp1048 > 4u?*(( int*) _temp1048) == Cyc_Absyn_AnonStructType: 0){ _LL1063:
_temp1062=(( struct Cyc_Absyn_AnonStructType_struct*) _temp1048)->f1; goto
_LL1053;} else{ goto _LL1054;} _LL1054: goto _LL1055; _LL1051: if( _temp1056 ==
0){ return(( void*(*)( struct _tagged_string)) Cyc_Tcutil_impos)(({
unsigned char* _temp1064=( unsigned char*)"offsetof on unchecked StructType";
struct _tagged_string _temp1065; _temp1065.curr= _temp1064; _temp1065.base=
_temp1064; _temp1065.last_plus_one= _temp1064 + 33; _temp1065;}));} if((*((
struct Cyc_Absyn_Structdecl**) _check_null( _temp1056)))->fields == 0){ goto
_LL1049;} goto _LL1053; _LL1053: bad_type= 0; goto _LL1049; _LL1055: goto
_LL1049; _LL1049:;} if( bad_type){ Cyc_Tcutil_terr( loc,( struct _tagged_string)({
struct _tagged_string _temp1066= Cyc_Absynpp_typ2string( t); xprintf("%.*s is not a known struct type",
_temp1066.last_plus_one - _temp1066.curr, _temp1066.curr);}));} return Cyc_Absyn_uint_t;}}
static void* Cyc_Tcexp_tcDeref( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment*
loc, void** topt, struct Cyc_Absyn_Exp* e){ Cyc_Tcexp_tcExp( te, 0, e);{ void* t=
Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v);
void* _temp1067= t; struct Cyc_Absyn_PtrInfo _temp1073; struct Cyc_Absyn_Conref*
_temp1075; struct Cyc_Absyn_Tqual _temp1077; struct Cyc_Absyn_Conref* _temp1079;
void* _temp1081; void* _temp1083; _LL1069: if(( unsigned int) _temp1067 > 4u?*((
int*) _temp1067) == Cyc_Absyn_PointerType: 0){ _LL1074: _temp1073=(( struct Cyc_Absyn_PointerType_struct*)
_temp1067)->f1; _LL1084: _temp1083=( void*) _temp1073.elt_typ; goto _LL1082;
_LL1082: _temp1081=( void*) _temp1073.rgn_typ; goto _LL1080; _LL1080: _temp1079=
_temp1073.nullable; goto _LL1078; _LL1078: _temp1077= _temp1073.tq; goto _LL1076;
_LL1076: _temp1075= _temp1073.bounds; goto _LL1070;} else{ goto _LL1071;}
_LL1071: goto _LL1072; _LL1070: Cyc_Tcenv_check_rgn_accessible( te, loc,
_temp1081); Cyc_Tcutil_check_nonzero_bound( loc, _temp1075); return _temp1083;
_LL1072: return Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)({ struct
_tagged_string _temp1085= Cyc_Absynpp_typ2string( t); xprintf("expecting * or @ type but found %.*s",
_temp1085.last_plus_one - _temp1085.curr, _temp1085.curr);})); _LL1068:;}}
static void* Cyc_Tcexp_tcStructMember( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment*
loc, void** topt, struct Cyc_Absyn_Exp* outer_e, struct Cyc_Absyn_Exp* e, struct
_tagged_string* f){ Cyc_Tcexp_tcExpNoPromote( te, 0, e);{ void* t= Cyc_Tcutil_compress((
void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v); void* _temp1086= t;
struct Cyc_Absyn_Structdecl** _temp1102; struct Cyc_Absyn_Structdecl* _temp1104;
struct Cyc_List_List* _temp1105; struct _tuple1* _temp1107; struct Cyc_List_List*
_temp1109; struct Cyc_List_List* _temp1111; struct Cyc_Absyn_Uniondecl**
_temp1113; struct Cyc_Absyn_Uniondecl* _temp1115; struct Cyc_List_List*
_temp1116; struct _tuple1* _temp1118; struct Cyc_Absyn_Exp* _temp1121; struct
Cyc_Absyn_Tqual _temp1123; void* _temp1125; struct Cyc_Absyn_PtrInfo _temp1130;
_LL1088: if(( unsigned int) _temp1086 > 4u?*(( int*) _temp1086) == Cyc_Absyn_StructType:
0){ _LL1108: _temp1107=(( struct Cyc_Absyn_StructType_struct*) _temp1086)->f1;
goto _LL1106; _LL1106: _temp1105=(( struct Cyc_Absyn_StructType_struct*)
_temp1086)->f2; goto _LL1103; _LL1103: _temp1102=(( struct Cyc_Absyn_StructType_struct*)
_temp1086)->f3; if( _temp1102 == 0){ goto _LL1090;} else{ _temp1104=* _temp1102;
goto _LL1089;}} else{ goto _LL1090;} _LL1090: if(( unsigned int) _temp1086 > 4u?*((
int*) _temp1086) == Cyc_Absyn_AnonStructType: 0){ _LL1110: _temp1109=(( struct
Cyc_Absyn_AnonStructType_struct*) _temp1086)->f1; goto _LL1091;} else{ goto
_LL1092;} _LL1092: if(( unsigned int) _temp1086 > 4u?*(( int*) _temp1086) == Cyc_Absyn_AnonUnionType:
0){ _LL1112: _temp1111=(( struct Cyc_Absyn_AnonUnionType_struct*) _temp1086)->f1;
goto _LL1093;} else{ goto _LL1094;} _LL1094: if(( unsigned int) _temp1086 > 4u?*((
int*) _temp1086) == Cyc_Absyn_UnionType: 0){ _LL1119: _temp1118=(( struct Cyc_Absyn_UnionType_struct*)
_temp1086)->f1; goto _LL1117; _LL1117: _temp1116=(( struct Cyc_Absyn_UnionType_struct*)
_temp1086)->f2; goto _LL1114; _LL1114: _temp1113=(( struct Cyc_Absyn_UnionType_struct*)
_temp1086)->f3; if( _temp1113 == 0){ goto _LL1096;} else{ _temp1115=* _temp1113;
goto _LL1095;}} else{ goto _LL1096;} _LL1096: if(( unsigned int) _temp1086 > 4u?*((
int*) _temp1086) == Cyc_Absyn_ArrayType: 0){ _LL1126: _temp1125=( void*)((
struct Cyc_Absyn_ArrayType_struct*) _temp1086)->f1; goto _LL1124; _LL1124:
_temp1123=(( struct Cyc_Absyn_ArrayType_struct*) _temp1086)->f2; goto _LL1122;
_LL1122: _temp1121=(( struct Cyc_Absyn_ArrayType_struct*) _temp1086)->f3; goto
_LL1120;} else{ goto _LL1098;} _LL1120: if( Cyc_String_zstrcmp(* f,({
unsigned char* _temp1127=( unsigned char*)"size"; struct _tagged_string
_temp1128; _temp1128.curr= _temp1127; _temp1128.base= _temp1127; _temp1128.last_plus_one=
_temp1127 + 5; _temp1128;})) == 0){ goto _LL1097;} else{ goto _LL1098;} _LL1098:
if(( unsigned int) _temp1086 > 4u?*(( int*) _temp1086) == Cyc_Absyn_PointerType:
0){ _LL1131: _temp1130=(( struct Cyc_Absyn_PointerType_struct*) _temp1086)->f1;
goto _LL1129;} else{ goto _LL1100;} _LL1129: if( Cyc_String_zstrcmp(* f,({
unsigned char* _temp1132=( unsigned char*)"size"; struct _tagged_string
_temp1133; _temp1133.curr= _temp1132; _temp1133.base= _temp1132; _temp1133.last_plus_one=
_temp1132 + 5; _temp1133;})) == 0){ goto _LL1099;} else{ goto _LL1100;} _LL1100:
goto _LL1101; _LL1089: if( _temp1107 == 0){ return Cyc_Tcexp_expr_err( te, loc,({
unsigned char* _temp1134=( unsigned char*)"unresolved struct type (COMPILER ERROR)";
struct _tagged_string _temp1135; _temp1135.curr= _temp1134; _temp1135.base=
_temp1134; _temp1135.last_plus_one= _temp1134 + 40; _temp1135;}));}{ struct Cyc_Absyn_Structfield*
_temp1136= Cyc_Absyn_lookup_struct_field( _temp1104, f); goto _LL1137; _LL1137:
if( _temp1136 == 0){ return Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)({
struct _tagged_string _temp1138= Cyc_Absynpp_qvar2string(( struct _tuple1*)
_check_null( _temp1107)); struct _tagged_string _temp1139=* f; xprintf("struct %.*s has no %.*s field",
_temp1138.last_plus_one - _temp1138.curr, _temp1138.curr, _temp1139.last_plus_one
- _temp1139.curr, _temp1139.curr);}));}{ void* t2;{ struct _RegionHandle
_temp1140= _new_region(); struct _RegionHandle* rgn=& _temp1140; _push_region(
rgn);{ struct Cyc_List_List* _temp1141=(( struct Cyc_List_List*(*)( struct
_RegionHandle* r3, struct _RegionHandle* r4, struct Cyc_List_List* x, struct Cyc_List_List*
y)) Cyc_List_rzip)( rgn, rgn, _temp1104->tvs, _temp1105); goto _LL1142; _LL1142:
t2= Cyc_Tcutil_rsubstitute( rgn, _temp1141,( void*)(( struct Cyc_Absyn_Structfield*)
_check_null( _temp1136))->type);}; _pop_region(& _temp1140);} return t2;}}
_LL1091: { struct Cyc_Absyn_Structfield* _temp1143= Cyc_Absyn_lookup_field(
_temp1109, f); goto _LL1144; _LL1144: if( _temp1143 == 0){ return Cyc_Tcexp_expr_err(
te, loc,( struct _tagged_string)({ struct _tagged_string _temp1145=* f; xprintf("struct has no %.*s field",
_temp1145.last_plus_one - _temp1145.curr, _temp1145.curr);}));} return( void*)((
struct Cyc_Absyn_Structfield*) _check_null( _temp1143))->type;} _LL1093: {
struct Cyc_Absyn_Structfield* _temp1146= Cyc_Absyn_lookup_field( _temp1111, f);
goto _LL1147; _LL1147: if( _temp1146 == 0){ return Cyc_Tcexp_expr_err( te, loc,(
struct _tagged_string)({ struct _tagged_string _temp1148=* f; xprintf("union has no %.*s field",
_temp1148.last_plus_one - _temp1148.curr, _temp1148.curr);}));} return( void*)((
struct Cyc_Absyn_Structfield*) _check_null( _temp1146))->type;} _LL1095: if(
_temp1118 == 0){ return Cyc_Tcexp_expr_err( te, loc,({ unsigned char* _temp1149=(
unsigned char*)"unresolved union type (COMPILER ERROR)"; struct _tagged_string
_temp1150; _temp1150.curr= _temp1149; _temp1150.base= _temp1149; _temp1150.last_plus_one=
_temp1149 + 39; _temp1150;}));}{ struct Cyc_Absyn_Structfield* _temp1151= Cyc_Absyn_lookup_union_field(
_temp1115, f); goto _LL1152; _LL1152: if( _temp1151 == 0){ return Cyc_Tcexp_expr_err(
te, loc,( struct _tagged_string)({ struct _tagged_string _temp1153= Cyc_Absynpp_qvar2string((
struct _tuple1*) _check_null( _temp1118)); struct _tagged_string _temp1154=* f;
xprintf("union %.*s has no %.*s field", _temp1153.last_plus_one - _temp1153.curr,
_temp1153.curr, _temp1154.last_plus_one - _temp1154.curr, _temp1154.curr);}));}{
struct Cyc_List_List* _temp1155=(( struct Cyc_List_List*(*)( struct Cyc_List_List*
x, struct Cyc_List_List* y)) Cyc_List_zip)( _temp1115->tvs, _temp1116); goto
_LL1156; _LL1156: { void* _temp1157= Cyc_Tcutil_substitute( _temp1155,( void*)((
struct Cyc_Absyn_Structfield*) _check_null( _temp1151))->type); goto _LL1158;
_LL1158: return _temp1157;}}} _LL1097:( void*)( outer_e->r=( void*)(( void*)({
struct Cyc_Absyn_Primop_e_struct* _temp1159=( struct Cyc_Absyn_Primop_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Primop_e_struct)); _temp1159[ 0]=({ struct
Cyc_Absyn_Primop_e_struct _temp1160; _temp1160.tag= Cyc_Absyn_Primop_e;
_temp1160.f1=( void*)(( void*) Cyc_Absyn_Size); _temp1160.f2=({ struct Cyc_List_List*
_temp1161=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1161->hd=( void*) e; _temp1161->tl= 0; _temp1161;}); _temp1160;});
_temp1159;}))); return Cyc_Absyn_uint_t; _LL1099:( void*)( outer_e->r=( void*)((
void*)({ struct Cyc_Absyn_Primop_e_struct* _temp1162=( struct Cyc_Absyn_Primop_e_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Primop_e_struct)); _temp1162[ 0]=({ struct
Cyc_Absyn_Primop_e_struct _temp1163; _temp1163.tag= Cyc_Absyn_Primop_e;
_temp1163.f1=( void*)(( void*) Cyc_Absyn_Size); _temp1163.f2=({ struct Cyc_List_List*
_temp1164=( struct Cyc_List_List*) GC_malloc( sizeof( struct Cyc_List_List));
_temp1164->hd=( void*) e; _temp1164->tl= 0; _temp1164;}); _temp1163;});
_temp1162;}))); return Cyc_Absyn_uint_t; _LL1101: if( Cyc_String_zstrcmp(* f,({
unsigned char* _temp1165=( unsigned char*)"size"; struct _tagged_string
_temp1166; _temp1166.curr= _temp1165; _temp1166.base= _temp1165; _temp1166.last_plus_one=
_temp1165 + 5; _temp1166;})) == 0){ return Cyc_Tcexp_expr_err( te, loc,( struct
_tagged_string)({ struct _tagged_string _temp1167= Cyc_Absynpp_typ2string( t);
xprintf("expecting struct, union or array, found %.*s", _temp1167.last_plus_one
- _temp1167.curr, _temp1167.curr);}));} else{ return Cyc_Tcexp_expr_err( te, loc,(
struct _tagged_string)({ struct _tagged_string _temp1168= Cyc_Absynpp_typ2string(
t); xprintf("expecting struct or union, found %.*s", _temp1168.last_plus_one -
_temp1168.curr, _temp1168.curr);}));} _LL1087:;}} static void* Cyc_Tcexp_tcStructArrow(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e, struct _tagged_string* f){ Cyc_Tcexp_tcExp( te, 0, e);{ void*
t= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v);
void* _temp1169= t; struct Cyc_Absyn_PtrInfo _temp1175; struct Cyc_Absyn_Conref*
_temp1177; struct Cyc_Absyn_Tqual _temp1179; struct Cyc_Absyn_Conref* _temp1181;
void* _temp1183; void* _temp1185; _LL1171: if(( unsigned int) _temp1169 > 4u?*((
int*) _temp1169) == Cyc_Absyn_PointerType: 0){ _LL1176: _temp1175=(( struct Cyc_Absyn_PointerType_struct*)
_temp1169)->f1; _LL1186: _temp1185=( void*) _temp1175.elt_typ; goto _LL1184;
_LL1184: _temp1183=( void*) _temp1175.rgn_typ; goto _LL1182; _LL1182: _temp1181=
_temp1175.nullable; goto _LL1180; _LL1180: _temp1179= _temp1175.tq; goto _LL1178;
_LL1178: _temp1177= _temp1175.bounds; goto _LL1172;} else{ goto _LL1173;}
_LL1173: goto _LL1174; _LL1172: Cyc_Tcutil_check_nonzero_bound( loc, _temp1177);{
void* _temp1187= Cyc_Tcutil_compress( _temp1185); struct Cyc_Absyn_Structdecl**
_temp1199; struct Cyc_Absyn_Structdecl* _temp1201; struct Cyc_List_List*
_temp1202; struct _tuple1* _temp1204; struct Cyc_Absyn_Uniondecl** _temp1206;
struct Cyc_Absyn_Uniondecl* _temp1208; struct Cyc_List_List* _temp1209; struct
_tuple1* _temp1211; struct Cyc_List_List* _temp1213; struct Cyc_List_List*
_temp1215; _LL1189: if(( unsigned int) _temp1187 > 4u?*(( int*) _temp1187) ==
Cyc_Absyn_StructType: 0){ _LL1205: _temp1204=(( struct Cyc_Absyn_StructType_struct*)
_temp1187)->f1; goto _LL1203; _LL1203: _temp1202=(( struct Cyc_Absyn_StructType_struct*)
_temp1187)->f2; goto _LL1200; _LL1200: _temp1199=(( struct Cyc_Absyn_StructType_struct*)
_temp1187)->f3; if( _temp1199 == 0){ goto _LL1191;} else{ _temp1201=* _temp1199;
goto _LL1190;}} else{ goto _LL1191;} _LL1191: if(( unsigned int) _temp1187 > 4u?*((
int*) _temp1187) == Cyc_Absyn_UnionType: 0){ _LL1212: _temp1211=(( struct Cyc_Absyn_UnionType_struct*)
_temp1187)->f1; goto _LL1210; _LL1210: _temp1209=(( struct Cyc_Absyn_UnionType_struct*)
_temp1187)->f2; goto _LL1207; _LL1207: _temp1206=(( struct Cyc_Absyn_UnionType_struct*)
_temp1187)->f3; if( _temp1206 == 0){ goto _LL1193;} else{ _temp1208=* _temp1206;
goto _LL1192;}} else{ goto _LL1193;} _LL1193: if(( unsigned int) _temp1187 > 4u?*((
int*) _temp1187) == Cyc_Absyn_AnonStructType: 0){ _LL1214: _temp1213=(( struct
Cyc_Absyn_AnonStructType_struct*) _temp1187)->f1; goto _LL1194;} else{ goto
_LL1195;} _LL1195: if(( unsigned int) _temp1187 > 4u?*(( int*) _temp1187) == Cyc_Absyn_AnonUnionType:
0){ _LL1216: _temp1215=(( struct Cyc_Absyn_AnonUnionType_struct*) _temp1187)->f1;
goto _LL1196;} else{ goto _LL1197;} _LL1197: goto _LL1198; _LL1190: { struct Cyc_Absyn_Structfield*
_temp1217= Cyc_Absyn_lookup_struct_field( _temp1201, f); goto _LL1218; _LL1218:
if( _temp1217 == 0){ return Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)({
struct _tagged_string _temp1219= Cyc_Absynpp_qvar2string(( struct _tuple1*)
_check_null( _temp1204)); struct _tagged_string _temp1220=* f; xprintf("struct %.*s has no %.*s field",
_temp1219.last_plus_one - _temp1219.curr, _temp1219.curr, _temp1220.last_plus_one
- _temp1220.curr, _temp1220.curr);}));}{ void* t3;{ struct _RegionHandle
_temp1221= _new_region(); struct _RegionHandle* rgn=& _temp1221; _push_region(
rgn);{ struct Cyc_List_List* _temp1222=(( struct Cyc_List_List*(*)( struct
_RegionHandle* r3, struct _RegionHandle* r4, struct Cyc_List_List* x, struct Cyc_List_List*
y)) Cyc_List_rzip)( rgn, rgn, _temp1201->tvs, _temp1202); goto _LL1223; _LL1223:
t3= Cyc_Tcutil_rsubstitute( rgn, _temp1222,( void*)(( struct Cyc_Absyn_Structfield*)
_check_null( _temp1217))->type);}; _pop_region(& _temp1221);} Cyc_Tcenv_check_rgn_accessible(
te, loc, _temp1183); return t3;}} _LL1192: { struct Cyc_Absyn_Structfield*
_temp1224= Cyc_Absyn_lookup_union_field( _temp1208, f); goto _LL1225; _LL1225:
if( _temp1224 == 0){ return Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)({
struct _tagged_string _temp1226= Cyc_Absynpp_qvar2string(( struct _tuple1*)
_check_null( _temp1211)); struct _tagged_string _temp1227=* f; xprintf("union %.*s has no %.*s field",
_temp1226.last_plus_one - _temp1226.curr, _temp1226.curr, _temp1227.last_plus_one
- _temp1227.curr, _temp1227.curr);}));}{ struct Cyc_List_List* _temp1228=((
struct Cyc_List_List*(*)( struct Cyc_List_List* x, struct Cyc_List_List* y)) Cyc_List_zip)(
_temp1208->tvs, _temp1209); goto _LL1229; _LL1229: { void* _temp1230= Cyc_Tcutil_substitute(
_temp1228,( void*)(( struct Cyc_Absyn_Structfield*) _check_null( _temp1224))->type);
goto _LL1231; _LL1231: Cyc_Tcenv_check_rgn_accessible( te, loc, _temp1183);
return _temp1230;}}} _LL1194: { struct Cyc_Absyn_Structfield* _temp1232= Cyc_Absyn_lookup_field(
_temp1213, f); goto _LL1233; _LL1233: if( _temp1232 == 0){ return Cyc_Tcexp_expr_err(
te, loc,( struct _tagged_string)({ struct _tagged_string _temp1234=* f; xprintf("struct has no %.*s field",
_temp1234.last_plus_one - _temp1234.curr, _temp1234.curr);}));} return( void*)((
struct Cyc_Absyn_Structfield*) _check_null( _temp1232))->type;} _LL1196: {
struct Cyc_Absyn_Structfield* _temp1235= Cyc_Absyn_lookup_field( _temp1215, f);
goto _LL1236; _LL1236: if( _temp1235 == 0){ return Cyc_Tcexp_expr_err( te, loc,(
struct _tagged_string)({ struct _tagged_string _temp1237=* f; xprintf("union has no %.*s field",
_temp1237.last_plus_one - _temp1237.curr, _temp1237.curr);}));} return( void*)((
struct Cyc_Absyn_Structfield*) _check_null( _temp1235))->type;} _LL1198: return
Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)({ struct _tagged_string
_temp1238= Cyc_Absynpp_typ2string( t); xprintf("expecting struct pointer, found %.*s",
_temp1238.last_plus_one - _temp1238.curr, _temp1238.curr);})); _LL1188:;}
_LL1174: return Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)({ struct
_tagged_string _temp1239= Cyc_Absynpp_typ2string( t); xprintf("expecting struct pointer, found %.*s",
_temp1239.last_plus_one - _temp1239.curr, _temp1239.curr);})); _LL1170:;}}
static void* Cyc_Tcexp_ithTupleType( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment*
loc, struct Cyc_List_List* ts, struct Cyc_Absyn_Exp* index){ unsigned int i= Cyc_Evexp_eval_const_uint_exp(
index); struct _handler_cons _temp1240; _push_handler(& _temp1240);{ int
_temp1242= 0; if( setjmp( _temp1240.handler)){ _temp1242= 1;} if( ! _temp1242){{
void* _temp1243=(*(( struct _tuple8*(*)( struct Cyc_List_List* x, int i)) Cyc_List_nth)(
ts,( int) i)).f2; _npop_handler( 0u); return _temp1243;}; _pop_handler();} else{
void* _temp1241=( void*) _exn_thrown; void* _temp1245= _temp1241; _LL1247: if(
_temp1245 == Cyc_List_Nth){ goto _LL1248;} else{ goto _LL1249;} _LL1249: goto
_LL1250; _LL1248: return Cyc_Tcexp_expr_err( te, loc,( struct _tagged_string)
xprintf("index is %d but tuple has only %d fields",( int) i,(( int(*)( struct
Cyc_List_List* x)) Cyc_List_length)( ts))); _LL1250:( void) _throw( _temp1245);
_LL1246:;}}} static void* Cyc_Tcexp_tcSubscript( struct Cyc_Tcenv_Tenv* te,
struct Cyc_Position_Segment* loc, void** topt, struct Cyc_Absyn_Exp* e1, struct
Cyc_Absyn_Exp* e2){ Cyc_Tcexp_tcExp( te, 0, e1); Cyc_Tcexp_tcExp( te, 0, e2);{
void* t1= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e1->topt))->v);
void* t2= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e2->topt))->v);
if( ! Cyc_Tcutil_coerce_sint_typ( te, e2)){ return Cyc_Tcexp_expr_err( te, e2->loc,(
struct _tagged_string)({ struct _tagged_string _temp1251= Cyc_Absynpp_typ2string(
t2); xprintf("expecting int subscript, found %.*s", _temp1251.last_plus_one -
_temp1251.curr, _temp1251.curr);}));}{ void* _temp1252= t1; struct Cyc_Absyn_PtrInfo
_temp1260; struct Cyc_Absyn_Conref* _temp1262; struct Cyc_Absyn_Tqual _temp1264;
struct Cyc_Absyn_Conref* _temp1266; void* _temp1268; void* _temp1270; struct Cyc_List_List*
_temp1272; _LL1254: if(( unsigned int) _temp1252 > 4u?*(( int*) _temp1252) ==
Cyc_Absyn_PointerType: 0){ _LL1261: _temp1260=(( struct Cyc_Absyn_PointerType_struct*)
_temp1252)->f1; _LL1271: _temp1270=( void*) _temp1260.elt_typ; goto _LL1269;
_LL1269: _temp1268=( void*) _temp1260.rgn_typ; goto _LL1267; _LL1267: _temp1266=
_temp1260.nullable; goto _LL1265; _LL1265: _temp1264= _temp1260.tq; goto _LL1263;
_LL1263: _temp1262= _temp1260.bounds; goto _LL1255;} else{ goto _LL1256;}
_LL1256: if(( unsigned int) _temp1252 > 4u?*(( int*) _temp1252) == Cyc_Absyn_TupleType:
0){ _LL1273: _temp1272=(( struct Cyc_Absyn_TupleType_struct*) _temp1252)->f1;
goto _LL1257;} else{ goto _LL1258;} _LL1258: goto _LL1259; _LL1255: if( Cyc_Tcutil_is_const_exp(
te, e2)){ Cyc_Tcutil_check_bound( loc, Cyc_Evexp_eval_const_uint_exp( e2),
_temp1262);} else{{ void* _temp1274=( void*)((( struct Cyc_Absyn_Conref*(*)(
struct Cyc_Absyn_Conref* x)) Cyc_Absyn_compress_conref)( _temp1262))->v; void*
_temp1280; struct Cyc_Absyn_Exp* _temp1282; struct Cyc_Absyn_Exp _temp1284;
struct Cyc_Position_Segment* _temp1285; void* _temp1287; void* _temp1289; int
_temp1291; void* _temp1293; struct Cyc_Core_Opt* _temp1295; _LL1276: if((
unsigned int) _temp1274 > 1u?*(( int*) _temp1274) == Cyc_Absyn_Eq_constr: 0){
_LL1281: _temp1280=( void*)(( struct Cyc_Absyn_Eq_constr_struct*) _temp1274)->f1;
if(( unsigned int) _temp1280 > 1u?*(( int*) _temp1280) == Cyc_Absyn_Upper_b: 0){
_LL1283: _temp1282=(( struct Cyc_Absyn_Upper_b_struct*) _temp1280)->f1;
_temp1284=* _temp1282; _LL1296: _temp1295= _temp1284.topt; goto _LL1288; _LL1288:
_temp1287=( void*) _temp1284.r; if(*(( int*) _temp1287) == Cyc_Absyn_Const_e){
_LL1290: _temp1289=( void*)(( struct Cyc_Absyn_Const_e_struct*) _temp1287)->f1;
if(( unsigned int) _temp1289 > 1u?*(( int*) _temp1289) == Cyc_Absyn_Int_c: 0){
_LL1294: _temp1293=( void*)(( struct Cyc_Absyn_Int_c_struct*) _temp1289)->f1;
if( _temp1293 ==( void*) Cyc_Absyn_Unsigned){ goto _LL1292;} else{ goto _LL1278;}
_LL1292: _temp1291=(( struct Cyc_Absyn_Int_c_struct*) _temp1289)->f2; if(
_temp1291 == 1){ goto _LL1286;} else{ goto _LL1278;}} else{ goto _LL1278;}}
else{ goto _LL1278;} _LL1286: _temp1285= _temp1284.loc; goto _LL1277;} else{
goto _LL1278;}} else{ goto _LL1278;} _LL1278: goto _LL1279; _LL1277: Cyc_Tcutil_warn(
e1->loc,({ unsigned char* _temp1297=( unsigned char*)"subscript applied to pointer to one object";
struct _tagged_string _temp1298; _temp1298.curr= _temp1297; _temp1298.base=
_temp1297; _temp1298.last_plus_one= _temp1297 + 43; _temp1298;})); goto _LL1275;
_LL1279: goto _LL1275; _LL1275:;} Cyc_Tcutil_check_nonzero_bound( loc, _temp1262);}
Cyc_Tcenv_check_rgn_accessible( te, loc, _temp1268); return _temp1270; _LL1257:
return Cyc_Tcexp_ithTupleType( te, loc, _temp1272, e2); _LL1259: return Cyc_Tcexp_expr_err(
te, loc,( struct _tagged_string)({ struct _tagged_string _temp1299= Cyc_Absynpp_typ2string(
t1); xprintf("subscript applied to %.*s", _temp1299.last_plus_one - _temp1299.curr,
_temp1299.curr);})); _LL1253:;}}} static void* Cyc_Tcexp_tcTuple( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void** topt, struct Cyc_List_List* es){
int done= 0; struct Cyc_List_List* fields= 0; if( topt != 0){ void* _temp1300=
Cyc_Tcutil_compress(*(( void**) _check_null( topt))); struct Cyc_List_List*
_temp1306; _LL1302: if(( unsigned int) _temp1300 > 4u?*(( int*) _temp1300) ==
Cyc_Absyn_TupleType: 0){ _LL1307: _temp1306=(( struct Cyc_Absyn_TupleType_struct*)
_temp1300)->f1; goto _LL1303;} else{ goto _LL1304;} _LL1304: goto _LL1305;
_LL1303: if((( int(*)( struct Cyc_List_List* x)) Cyc_List_length)( _temp1306) !=((
int(*)( struct Cyc_List_List* x)) Cyc_List_length)( es)){ Cyc_Tcutil_terr( loc,({
unsigned char* _temp1308=( unsigned char*)"tuple expression has the wrong number of fields";
struct _tagged_string _temp1309; _temp1309.curr= _temp1308; _temp1309.base=
_temp1308; _temp1309.last_plus_one= _temp1308 + 48; _temp1309;})); goto _LL1301;}
for( 0; es != 0;( es=(( struct Cyc_List_List*) _check_null( es))->tl, _temp1306=((
struct Cyc_List_List*) _check_null( _temp1306))->tl)){ void* _temp1310=(*((
struct _tuple8*)(( struct Cyc_List_List*) _check_null( _temp1306))->hd)).f2;
goto _LL1311; _LL1311: Cyc_Tcexp_tcExpInitializer( te,( void**)& _temp1310,(
struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd); fields=({
struct Cyc_List_List* _temp1312=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp1312->hd=( void*)({ struct _tuple8* _temp1313=(
struct _tuple8*) GC_malloc( sizeof( struct _tuple8)); _temp1313->f1=(*(( struct
_tuple8*)(( struct Cyc_List_List*) _check_null( _temp1306))->hd)).f1; _temp1313->f2=(
void*)(( struct Cyc_Core_Opt*) _check_null((( struct Cyc_Absyn_Exp*)(( struct
Cyc_List_List*) _check_null( es))->hd)->topt))->v; _temp1313;}); _temp1312->tl=
fields; _temp1312;});} done= 1; goto _LL1301; _LL1305: goto _LL1301; _LL1301:;}
if( ! done){ for( 0; es != 0; es=(( struct Cyc_List_List*) _check_null( es))->tl){
Cyc_Tcexp_tcExpInitializer( te, 0,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*)
_check_null( es))->hd); fields=({ struct Cyc_List_List* _temp1314=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp1314->hd=( void*)({ struct
_tuple8* _temp1315=( struct _tuple8*) GC_malloc( sizeof( struct _tuple8));
_temp1315->f1= Cyc_Absyn_empty_tqual(); _temp1315->f2=( void*)(( struct Cyc_Core_Opt*)
_check_null((( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd)->topt))->v;
_temp1315;}); _temp1314->tl= fields; _temp1314;});}} return( void*)({ struct Cyc_Absyn_TupleType_struct*
_temp1316=( struct Cyc_Absyn_TupleType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_TupleType_struct));
_temp1316[ 0]=({ struct Cyc_Absyn_TupleType_struct _temp1317; _temp1317.tag= Cyc_Absyn_TupleType;
_temp1317.f1=(( struct Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)(
fields); _temp1317;}); _temp1316;});} static void* Cyc_Tcexp_tcCompoundLit(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
_tuple2* t, struct Cyc_List_List* des){ return Cyc_Tcexp_expr_err( te, loc,({
unsigned char* _temp1318=( unsigned char*)"tcCompoundLit"; struct _tagged_string
_temp1319; _temp1319.curr= _temp1318; _temp1319.base= _temp1318; _temp1319.last_plus_one=
_temp1318 + 14; _temp1319;}));} static void* Cyc_Tcexp_tcArray( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void** elt_topt, struct Cyc_List_List* des){
struct Cyc_List_List* es=(( struct Cyc_List_List*(*)( struct Cyc_Absyn_Exp*(* f)(
struct _tuple7*), struct Cyc_List_List* x)) Cyc_List_map)(( struct Cyc_Absyn_Exp*(*)(
struct _tuple7*)) Cyc_Core_snd, des); void* res= Cyc_Absyn_new_evar(( struct Cyc_Core_Opt*)&
Cyc_Tcexp_mk,({ struct Cyc_Core_Opt* _temp1342=( struct Cyc_Core_Opt*) GC_malloc(
sizeof( struct Cyc_Core_Opt)); _temp1342->v=( void*) Cyc_Tcenv_lookup_type_vars(
te); _temp1342;})); struct Cyc_Absyn_Const_e_struct* _temp1324=({ struct Cyc_Absyn_Const_e_struct*
_temp1320=( struct Cyc_Absyn_Const_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Const_e_struct));
_temp1320[ 0]=({ struct Cyc_Absyn_Const_e_struct _temp1321; _temp1321.tag= Cyc_Absyn_Const_e;
_temp1321.f1=( void*)(( void*)({ struct Cyc_Absyn_Int_c_struct* _temp1322=(
struct Cyc_Absyn_Int_c_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Int_c_struct));
_temp1322[ 0]=({ struct Cyc_Absyn_Int_c_struct _temp1323; _temp1323.tag= Cyc_Absyn_Int_c;
_temp1323.f1=( void*)(( void*) Cyc_Absyn_Unsigned); _temp1323.f2=(( int(*)(
struct Cyc_List_List* x)) Cyc_List_length)( es); _temp1323;}); _temp1322;}));
_temp1321;}); _temp1320;}); goto _LL1325; _LL1325: { struct Cyc_Absyn_Exp*
sz_exp= Cyc_Absyn_new_exp(( void*) _temp1324, loc); sz_exp->topt=({ struct Cyc_Core_Opt*
_temp1326=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp1326->v=( void*) Cyc_Absyn_uint_t; _temp1326;});{ void* res_t2=( void*)({
struct Cyc_Absyn_ArrayType_struct* _temp1340=( struct Cyc_Absyn_ArrayType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_ArrayType_struct)); _temp1340[ 0]=({ struct
Cyc_Absyn_ArrayType_struct _temp1341; _temp1341.tag= Cyc_Absyn_ArrayType;
_temp1341.f1=( void*) res; _temp1341.f2= Cyc_Absyn_empty_tqual(); _temp1341.f3=(
struct Cyc_Absyn_Exp*) sz_exp; _temp1341;}); _temp1340;});{ struct Cyc_List_List*
es2= es; for( 0; es2 != 0; es2=(( struct Cyc_List_List*) _check_null( es2))->tl){
Cyc_Tcexp_tcExpInitializer( te, elt_topt,( struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*)
_check_null( es2))->hd);}} if( ! Cyc_Tcutil_coerce_list( te, res, es)){ Cyc_Tcutil_terr(((
struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd)->loc,(
struct _tagged_string)({ struct _tagged_string _temp1327= Cyc_Absynpp_typ2string(
res); xprintf("elements of array do not all have the same type (%.*s)",
_temp1327.last_plus_one - _temp1327.curr, _temp1327.curr);}));}{ int offset= 0;
for( 0; des != 0;( offset ++, des=(( struct Cyc_List_List*) _check_null( des))->tl)){
struct Cyc_List_List* ds=(*(( struct _tuple7*)(( struct Cyc_List_List*)
_check_null( des))->hd)).f1; if( ds != 0){ void* _temp1328=( void*)(( struct Cyc_List_List*)
_check_null( ds))->hd; struct _tagged_string* _temp1334; struct Cyc_Absyn_Exp*
_temp1336; _LL1330: if(*(( int*) _temp1328) == Cyc_Absyn_FieldName){ _LL1335:
_temp1334=(( struct Cyc_Absyn_FieldName_struct*) _temp1328)->f1; goto _LL1331;}
else{ goto _LL1332;} _LL1332: if(*(( int*) _temp1328) == Cyc_Absyn_ArrayElement){
_LL1337: _temp1336=(( struct Cyc_Absyn_ArrayElement_struct*) _temp1328)->f1;
goto _LL1333;} else{ goto _LL1329;} _LL1331: Cyc_Tcutil_terr( loc,({
unsigned char* _temp1338=( unsigned char*)"only array index designators are supported";
struct _tagged_string _temp1339; _temp1339.curr= _temp1338; _temp1339.base=
_temp1338; _temp1339.last_plus_one= _temp1338 + 43; _temp1339;})); goto _LL1329;
_LL1333: Cyc_Tcexp_tcExpInitializer( te, 0, _temp1336);{ unsigned int i= Cyc_Evexp_eval_const_uint_exp(
_temp1336); if( i != offset){ Cyc_Tcutil_terr( _temp1336->loc,( struct
_tagged_string) xprintf("expecting index designator %d but found %d", offset,(
int) i));} goto _LL1329;} _LL1329:;}}} return res_t2;}}} static void* Cyc_Tcexp_tcComprehension(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Vardecl* vd, struct Cyc_Absyn_Exp* bound, struct Cyc_Absyn_Exp* body){
Cyc_Tcexp_tcExp( te, 0, bound); if( ! Cyc_Tcutil_coerce_uint_typ( te, bound)){
Cyc_Tcutil_terr( bound->loc,( struct _tagged_string)({ struct _tagged_string
_temp1343= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*) _check_null(
bound->topt))->v); xprintf("expecting unsigned int, found %.*s", _temp1343.last_plus_one
- _temp1343.curr, _temp1343.curr);}));} if( !( vd->tq).q_const){(( void(*)(
struct _tagged_string)) Cyc_Tcutil_impos)(({ unsigned char* _temp1344=(
unsigned char*)"comprehension index variable is not declared const!"; struct
_tagged_string _temp1345; _temp1345.curr= _temp1344; _temp1345.base= _temp1344;
_temp1345.last_plus_one= _temp1344 + 52; _temp1345;}));} if( te->le != 0){ te=
Cyc_Tcenv_new_block( loc, te); te= Cyc_Tcenv_add_local_var( loc, te, vd);} else{
if( ! Cyc_Tcutil_is_const_exp( te, bound)){ Cyc_Tcutil_terr( bound->loc,({
unsigned char* _temp1346=( unsigned char*)"bound is not constant"; struct
_tagged_string _temp1347; _temp1347.curr= _temp1346; _temp1347.base= _temp1346;
_temp1347.last_plus_one= _temp1346 + 22; _temp1347;}));} if( ! Cyc_Tcutil_is_const_exp(
te, body)){ Cyc_Tcutil_terr( bound->loc,({ unsigned char* _temp1348=(
unsigned char*)"body is not constant"; struct _tagged_string _temp1349;
_temp1349.curr= _temp1348; _temp1349.base= _temp1348; _temp1349.last_plus_one=
_temp1348 + 21; _temp1349;}));}}{ struct Cyc_Absyn_PtrInfo pinfo; void**
_temp1350= 0; goto _LL1351; _LL1351: { struct Cyc_Absyn_Tqual* _temp1352= 0;
goto _LL1353; _LL1353: if( topt != 0){ void* _temp1354= Cyc_Tcutil_compress(*((
void**) _check_null( topt))); struct Cyc_Absyn_PtrInfo _temp1362; struct Cyc_Absyn_Exp*
_temp1364; struct Cyc_Absyn_Tqual _temp1366; struct Cyc_Absyn_Tqual* _temp1368;
void* _temp1369; void** _temp1371; _LL1356: if(( unsigned int) _temp1354 > 4u?*((
int*) _temp1354) == Cyc_Absyn_PointerType: 0){ _LL1363: _temp1362=(( struct Cyc_Absyn_PointerType_struct*)
_temp1354)->f1; goto _LL1357;} else{ goto _LL1358;} _LL1358: if(( unsigned int)
_temp1354 > 4u?*(( int*) _temp1354) == Cyc_Absyn_ArrayType: 0){ _LL1370:
_temp1369=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1354)->f1;
_temp1371=&(( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1354)->f1); goto
_LL1367; _LL1367: _temp1366=(( struct Cyc_Absyn_ArrayType_struct*) _temp1354)->f2;
_temp1368=&(( struct Cyc_Absyn_ArrayType_struct*) _temp1354)->f2; goto _LL1365;
_LL1365: _temp1364=(( struct Cyc_Absyn_ArrayType_struct*) _temp1354)->f3; goto
_LL1359;} else{ goto _LL1360;} _LL1360: goto _LL1361; _LL1357: pinfo= _temp1362;
_temp1350=( void**)(( void**)(( void*)& pinfo.elt_typ)); _temp1352=( struct Cyc_Absyn_Tqual*)&
pinfo.tq; goto _LL1355; _LL1359: _temp1350=( void**) _temp1371; _temp1352=(
struct Cyc_Absyn_Tqual*) _temp1368; goto _LL1355; _LL1361: goto _LL1355; _LL1355:;}{
void* t= Cyc_Tcexp_tcExp( te, _temp1350, body); return( void*)({ struct Cyc_Absyn_ArrayType_struct*
_temp1372=( struct Cyc_Absyn_ArrayType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_ArrayType_struct));
_temp1372[ 0]=({ struct Cyc_Absyn_ArrayType_struct _temp1373; _temp1373.tag= Cyc_Absyn_ArrayType;
_temp1373.f1=( void*) t; _temp1373.f2= _temp1352 == 0? Cyc_Absyn_empty_tqual():*((
struct Cyc_Absyn_Tqual*) _check_null( _temp1352)); _temp1373.f3=( struct Cyc_Absyn_Exp*)
bound; _temp1373;}); _temp1372;});}}}} struct _tuple9{ struct Cyc_Absyn_Structfield*
f1; struct Cyc_Absyn_Exp* f2; } ; static void* Cyc_Tcexp_tcStruct( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void** topt, struct _tuple1** tn, struct
Cyc_Core_Opt** otyps, struct Cyc_List_List* args, struct Cyc_Absyn_Structdecl**
sd_opt){ struct Cyc_Absyn_Structdecl* sd; if(* sd_opt != 0){ sd=( struct Cyc_Absyn_Structdecl*)
_check_null(* sd_opt);} else{{ struct _handler_cons _temp1374; _push_handler(&
_temp1374);{ int _temp1376= 0; if( setjmp( _temp1374.handler)){ _temp1376= 1;}
if( ! _temp1376){ sd=* Cyc_Tcenv_lookup_structdecl( te, loc,* tn);; _pop_handler();}
else{ void* _temp1375=( void*) _exn_thrown; void* _temp1378= _temp1375; _LL1380:
if( _temp1378 == Cyc_Dict_Absent){ goto _LL1381;} else{ goto _LL1382;} _LL1382:
goto _LL1383; _LL1381: Cyc_Tcutil_terr( loc,( struct _tagged_string)({ struct
_tagged_string _temp1384= Cyc_Absynpp_qvar2string(* tn); xprintf("unbound struct name %.*s",
_temp1384.last_plus_one - _temp1384.curr, _temp1384.curr);})); return topt != 0?*((
void**) _check_null( topt)):( void*) Cyc_Absyn_VoidType; _LL1383:( void) _throw(
_temp1378); _LL1379:;}}}* sd_opt=( struct Cyc_Absyn_Structdecl*) sd; if( sd->name
!= 0){* tn=( struct _tuple1*)(( struct Cyc_Core_Opt*) _check_null( sd->name))->v;}}{
struct _RegionHandle _temp1385= _new_region(); struct _RegionHandle* rgn=&
_temp1385; _push_region( rgn);{ struct _tuple4 _temp1387=({ struct _tuple4
_temp1386; _temp1386.f1= Cyc_Tcenv_lookup_type_vars( te); _temp1386.f2= rgn;
_temp1386;}); goto _LL1388; _LL1388: { struct Cyc_List_List* _temp1389=(( struct
Cyc_List_List*(*)( struct _RegionHandle*, struct _tuple5*(* f)( struct _tuple4*,
struct Cyc_Absyn_Tvar*), struct _tuple4* env, struct Cyc_List_List* x)) Cyc_List_rmap_c)(
rgn, Cyc_Tcutil_r_make_inst_var,& _temp1387, sd->tvs); goto _LL1390; _LL1390: {
struct Cyc_List_List* _temp1391=(( struct Cyc_List_List*(*)( void*(* f)( struct
_tuple5*), struct Cyc_List_List* x)) Cyc_List_map)(( void*(*)( struct _tuple5*))
Cyc_Core_snd, _temp1389); goto _LL1392; _LL1392: { struct Cyc_Absyn_StructType_struct*
_temp1396=({ struct Cyc_Absyn_StructType_struct* _temp1393=( struct Cyc_Absyn_StructType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_StructType_struct)); _temp1393[ 0]=({ struct
Cyc_Absyn_StructType_struct _temp1394; _temp1394.tag= Cyc_Absyn_StructType;
_temp1394.f1=( struct _tuple1*)* tn; _temp1394.f2= _temp1391; _temp1394.f3=({
struct Cyc_Absyn_Structdecl** _temp1395=( struct Cyc_Absyn_Structdecl**)
GC_malloc( sizeof( struct Cyc_Absyn_Structdecl*)); _temp1395[ 0]= sd; _temp1395;});
_temp1394;}); _temp1393;}); goto _LL1397; _LL1397: if( topt != 0){ Cyc_Tcutil_unify((
void*) _temp1396,*(( void**) _check_null( topt)));}* otyps=({ struct Cyc_Core_Opt*
_temp1398=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp1398->v=( void*) _temp1391; _temp1398;}); if( sd->fields == 0){ Cyc_Tcutil_terr(
loc,({ unsigned char* _temp1399=( unsigned char*)"can't build abstract struct";
struct _tagged_string _temp1400; _temp1400.curr= _temp1399; _temp1400.base=
_temp1399; _temp1400.last_plus_one= _temp1399 + 28; _temp1400;}));{ void*
_temp1401=( void*) _temp1396; _npop_handler( 0u); return _temp1401;}}{ struct
Cyc_List_List* fields=(( struct Cyc_List_List*(*)( struct _RegionHandle* rgn,
struct Cyc_Position_Segment* loc, struct Cyc_List_List* des, struct Cyc_List_List*
fields)) Cyc_Tcutil_resolve_struct_designators)( rgn, loc, args,( struct Cyc_List_List*)((
struct Cyc_Core_Opt*) _check_null( sd->fields))->v); for( 0; fields != 0; fields=((
struct Cyc_List_List*) _check_null( fields))->tl){ struct _tuple9 _temp1404;
struct Cyc_Absyn_Exp* _temp1405; struct Cyc_Absyn_Structfield* _temp1407; struct
_tuple9* _temp1402=( struct _tuple9*)(( struct Cyc_List_List*) _check_null(
fields))->hd; _temp1404=* _temp1402; _LL1408: _temp1407= _temp1404.f1; goto
_LL1406; _LL1406: _temp1405= _temp1404.f2; goto _LL1403; _LL1403: { void*
_temp1409= Cyc_Tcutil_rsubstitute( rgn, _temp1389,( void*) _temp1407->type);
goto _LL1410; _LL1410: Cyc_Tcexp_tcExpInitializer( te,( void**)& _temp1409,
_temp1405); if( ! Cyc_Tcutil_coerce_arg( te, _temp1405, _temp1409)){ Cyc_Tcutil_terr(
_temp1405->loc,( struct _tagged_string)({ struct _tagged_string _temp1411=*
_temp1407->name; struct _tagged_string _temp1412= Cyc_Absynpp_qvar2string(* tn);
struct _tagged_string _temp1413= Cyc_Absynpp_typ2string( _temp1409); struct
_tagged_string _temp1414= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*)
_check_null( _temp1405->topt))->v); xprintf("field %.*s of struct %.*s expects type %.*s != %.*s",
_temp1411.last_plus_one - _temp1411.curr, _temp1411.curr, _temp1412.last_plus_one
- _temp1412.curr, _temp1412.curr, _temp1413.last_plus_one - _temp1413.curr,
_temp1413.curr, _temp1414.last_plus_one - _temp1414.curr, _temp1414.curr);}));}}}{
void* _temp1415=( void*) _temp1396; _npop_handler( 0u); return _temp1415;}}}}}};
_pop_region(& _temp1385);}} static void* Cyc_Tcexp_tcAnonStruct( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void* ts, struct Cyc_List_List* args){{
struct _RegionHandle _temp1416= _new_region(); struct _RegionHandle* rgn=&
_temp1416; _push_region( rgn);{ void* _temp1417= Cyc_Tcutil_compress( ts);
struct Cyc_List_List* _temp1423; _LL1419: if(( unsigned int) _temp1417 > 4u?*((
int*) _temp1417) == Cyc_Absyn_AnonStructType: 0){ _LL1424: _temp1423=(( struct
Cyc_Absyn_AnonStructType_struct*) _temp1417)->f1; goto _LL1420;} else{ goto
_LL1421;} _LL1421: goto _LL1422; _LL1420: { struct Cyc_List_List* fields=((
struct Cyc_List_List*(*)( struct _RegionHandle* rgn, struct Cyc_Position_Segment*
loc, struct Cyc_List_List* des, struct Cyc_List_List* fields)) Cyc_Tcutil_resolve_struct_designators)(
rgn, loc, args, _temp1423); for( 0; fields != 0; fields=(( struct Cyc_List_List*)
_check_null( fields))->tl){ struct _tuple9 _temp1427; struct Cyc_Absyn_Exp*
_temp1428; struct Cyc_Absyn_Structfield* _temp1430; struct _tuple9* _temp1425=(
struct _tuple9*)(( struct Cyc_List_List*) _check_null( fields))->hd; _temp1427=*
_temp1425; _LL1431: _temp1430= _temp1427.f1; goto _LL1429; _LL1429: _temp1428=
_temp1427.f2; goto _LL1426; _LL1426: Cyc_Tcexp_tcExpInitializer( te,( void**)((
void**)(( void*)& _temp1430->type)), _temp1428); if( ! Cyc_Tcutil_coerce_arg( te,
_temp1428,( void*) _temp1430->type)){ Cyc_Tcutil_terr( _temp1428->loc,( struct
_tagged_string)({ struct _tagged_string _temp1432=* _temp1430->name; struct
_tagged_string _temp1433= Cyc_Absynpp_typ2string(( void*) _temp1430->type);
struct _tagged_string _temp1434= Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*)
_check_null( _temp1428->topt))->v); xprintf("field %.*s of struct expects type %.*s != %.*s",
_temp1432.last_plus_one - _temp1432.curr, _temp1432.curr, _temp1433.last_plus_one
- _temp1433.curr, _temp1433.curr, _temp1434.last_plus_one - _temp1434.curr,
_temp1434.curr);}));}} goto _LL1418;} _LL1422:(( void(*)( struct _tagged_string))
Cyc_Tcutil_impos)(({ unsigned char* _temp1435=( unsigned char*)"tcAnonStruct:  not an AnonStructType";
struct _tagged_string _temp1436; _temp1436.curr= _temp1435; _temp1436.base=
_temp1435; _temp1436.last_plus_one= _temp1435 + 37; _temp1436;})); goto _LL1418;
_LL1418:;}; _pop_region(& _temp1416);} return ts;} static void* Cyc_Tcexp_tcTunion(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e, struct Cyc_Core_Opt** all_ref, struct Cyc_Core_Opt** exist_ref,
struct Cyc_List_List* es, struct Cyc_Absyn_Tuniondecl* tud, struct Cyc_Absyn_Tunionfield*
tuf){ struct _RegionHandle _temp1437= _new_region(); struct _RegionHandle* rgn=&
_temp1437; _push_region( rgn);{ struct _tuple4 _temp1439=({ struct _tuple4
_temp1438; _temp1438.f1= Cyc_Tcenv_lookup_type_vars( te); _temp1438.f2= rgn;
_temp1438;}); goto _LL1440; _LL1440: { struct Cyc_List_List* _temp1441=(( struct
Cyc_List_List*(*)( struct _RegionHandle*, struct _tuple5*(* f)( struct _tuple4*,
struct Cyc_Absyn_Tvar*), struct _tuple4* env, struct Cyc_List_List* x)) Cyc_List_rmap_c)(
rgn, Cyc_Tcutil_r_make_inst_var,& _temp1439, tud->tvs); goto _LL1442; _LL1442: {
struct Cyc_List_List* _temp1443=(( struct Cyc_List_List*(*)( struct
_RegionHandle*, struct _tuple5*(* f)( struct _tuple4*, struct Cyc_Absyn_Tvar*),
struct _tuple4* env, struct Cyc_List_List* x)) Cyc_List_rmap_c)( rgn, Cyc_Tcutil_r_make_inst_var,&
_temp1439, tuf->tvs); goto _LL1444; _LL1444: { struct Cyc_List_List* _temp1445=((
struct Cyc_List_List*(*)( void*(* f)( struct _tuple5*), struct Cyc_List_List* x))
Cyc_List_map)(( void*(*)( struct _tuple5*)) Cyc_Core_snd, _temp1441); goto
_LL1446; _LL1446: { struct Cyc_List_List* _temp1447=(( struct Cyc_List_List*(*)(
void*(* f)( struct _tuple5*), struct Cyc_List_List* x)) Cyc_List_map)(( void*(*)(
struct _tuple5*)) Cyc_Core_snd, _temp1443); goto _LL1448; _LL1448: { struct Cyc_List_List*
_temp1449=(( struct Cyc_List_List*(*)( struct _RegionHandle*, struct Cyc_List_List*
x, struct Cyc_List_List* y)) Cyc_List_rappend)( rgn, _temp1441, _temp1443); goto
_LL1450; _LL1450:* all_ref=({ struct Cyc_Core_Opt* _temp1451=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1451->v=( void*) _temp1445;
_temp1451;});* exist_ref=({ struct Cyc_Core_Opt* _temp1452=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1452->v=( void*) _temp1447;
_temp1452;});{ void* res=( void*)({ struct Cyc_Absyn_TunionFieldType_struct*
_temp1488=( struct Cyc_Absyn_TunionFieldType_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_TunionFieldType_struct)); _temp1488[ 0]=({ struct Cyc_Absyn_TunionFieldType_struct
_temp1489; _temp1489.tag= Cyc_Absyn_TunionFieldType; _temp1489.f1=({ struct Cyc_Absyn_TunionFieldInfo
_temp1490; _temp1490.field_info=( void*)(( void*)({ struct Cyc_Absyn_KnownTunionfield_struct*
_temp1491=( struct Cyc_Absyn_KnownTunionfield_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_KnownTunionfield_struct)); _temp1491[ 0]=({ struct Cyc_Absyn_KnownTunionfield_struct
_temp1492; _temp1492.tag= Cyc_Absyn_KnownTunionfield; _temp1492.f1= tud;
_temp1492.f2= tuf; _temp1492;}); _temp1491;})); _temp1490.targs= _temp1445;
_temp1490;}); _temp1489;}); _temp1488;}); if( topt != 0){ void* _temp1453= Cyc_Tcutil_compress(*((
void**) _check_null( topt))); struct Cyc_Absyn_TunionFieldInfo _temp1461; struct
Cyc_Absyn_TunionInfo _temp1463; void* _temp1465; struct Cyc_List_List* _temp1467;
void* _temp1469; _LL1455: if(( unsigned int) _temp1453 > 4u?*(( int*) _temp1453)
== Cyc_Absyn_TunionFieldType: 0){ _LL1462: _temp1461=(( struct Cyc_Absyn_TunionFieldType_struct*)
_temp1453)->f1; goto _LL1456;} else{ goto _LL1457;} _LL1457: if(( unsigned int)
_temp1453 > 4u?*(( int*) _temp1453) == Cyc_Absyn_TunionType: 0){ _LL1464:
_temp1463=(( struct Cyc_Absyn_TunionType_struct*) _temp1453)->f1; _LL1470:
_temp1469=( void*) _temp1463.tunion_info; goto _LL1468; _LL1468: _temp1467=
_temp1463.targs; goto _LL1466; _LL1466: _temp1465=( void*) _temp1463.rgn; goto
_LL1458;} else{ goto _LL1459;} _LL1459: goto _LL1460; _LL1456: Cyc_Tcutil_unify(*((
void**) _check_null( topt)), res); goto _LL1454; _LL1458:{ struct Cyc_List_List*
a= _temp1445; for( 0; a != 0? _temp1467 != 0: 0;( a=(( struct Cyc_List_List*)
_check_null( a))->tl, _temp1467=(( struct Cyc_List_List*) _check_null( _temp1467))->tl)){
Cyc_Tcutil_unify(( void*)(( struct Cyc_List_List*) _check_null( a))->hd,( void*)((
struct Cyc_List_List*) _check_null( _temp1467))->hd);}} if( tuf->typs == 0? es
== 0: 0){ e->topt=({ struct Cyc_Core_Opt* _temp1471=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1471->v=( void*) res; _temp1471;});
res=( void*)({ struct Cyc_Absyn_TunionType_struct* _temp1472=( struct Cyc_Absyn_TunionType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_TunionType_struct)); _temp1472[ 0]=({ struct
Cyc_Absyn_TunionType_struct _temp1473; _temp1473.tag= Cyc_Absyn_TunionType;
_temp1473.f1=({ struct Cyc_Absyn_TunionInfo _temp1474; _temp1474.tunion_info=(
void*)(( void*)({ struct Cyc_Absyn_KnownTunion_struct* _temp1475=( struct Cyc_Absyn_KnownTunion_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_KnownTunion_struct)); _temp1475[ 0]=({
struct Cyc_Absyn_KnownTunion_struct _temp1476; _temp1476.tag= Cyc_Absyn_KnownTunion;
_temp1476.f1= tud; _temp1476;}); _temp1475;})); _temp1474.targs= _temp1445;
_temp1474.rgn=( void*) _temp1465; _temp1474;}); _temp1473;}); _temp1472;}); Cyc_Tcutil_unchecked_cast(
te, e, res);{ void* _temp1477= res; _npop_handler( 0u); return _temp1477;}} goto
_LL1454; _LL1460: goto _LL1454; _LL1454:;}{ struct Cyc_List_List* ts= tuf->typs;
for( 0; es != 0? ts != 0: 0;( es=(( struct Cyc_List_List*) _check_null( es))->tl,
ts=(( struct Cyc_List_List*) _check_null( ts))->tl)){ struct Cyc_Absyn_Exp* e=(
struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd; void* t=
Cyc_Tcutil_rsubstitute( rgn, _temp1449,(*(( struct _tuple8*)(( struct Cyc_List_List*)
_check_null( ts))->hd)).f2); Cyc_Tcexp_tcExpInitializer( te,( void**)& t, e);
if( ! Cyc_Tcutil_coerce_arg( te, e, t)){ Cyc_Tcutil_terr( e->loc,( struct
_tagged_string)({ struct _tagged_string _temp1480= Cyc_Absynpp_qvar2string( tuf->name);
struct _tagged_string _temp1481= Cyc_Absynpp_typ2string( t); struct
_tagged_string _temp1482= e->topt == 0?({ unsigned char* _temp1478=(
unsigned char*)"?"; struct _tagged_string _temp1479; _temp1479.curr= _temp1478;
_temp1479.base= _temp1478; _temp1479.last_plus_one= _temp1478 + 2; _temp1479;}):
Cyc_Absynpp_typ2string(( void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v);
xprintf("tunion constructor %.*s expects argument of type %.*s but this argument has type %.*s",
_temp1480.last_plus_one - _temp1480.curr, _temp1480.curr, _temp1481.last_plus_one
- _temp1481.curr, _temp1481.curr, _temp1482.last_plus_one - _temp1482.curr,
_temp1482.curr);}));}} if( es != 0){ void* _temp1484= Cyc_Tcexp_expr_err( te,((
struct Cyc_Absyn_Exp*)(( struct Cyc_List_List*) _check_null( es))->hd)->loc,(
struct _tagged_string)({ struct _tagged_string _temp1483= Cyc_Absynpp_qvar2string(
tuf->name); xprintf("too many arguments for tunion constructor %.*s", _temp1483.last_plus_one
- _temp1483.curr, _temp1483.curr);})); _npop_handler( 0u); return _temp1484;}
if( ts != 0){ void* _temp1486= Cyc_Tcexp_expr_err( te, loc,( struct
_tagged_string)({ struct _tagged_string _temp1485= Cyc_Absynpp_qvar2string( tuf->name);
xprintf("too few arguments for tunion constructor %.*s", _temp1485.last_plus_one
- _temp1485.curr, _temp1485.curr);})); _npop_handler( 0u); return _temp1486;}{
void* _temp1487= res; _npop_handler( 0u); return _temp1487;}}}}}}}}};
_pop_region(& _temp1437);} static void* Cyc_Tcexp_tcMalloc( struct Cyc_Tcenv_Tenv*
te, struct Cyc_Position_Segment* loc, void** topt, struct Cyc_Absyn_Exp* ropt,
void* t){ void* rgn=( void*) Cyc_Absyn_HeapRgn; if( ropt != 0){ void*
expected_type=( void*)({ struct Cyc_Absyn_RgnHandleType_struct* _temp1502=(
struct Cyc_Absyn_RgnHandleType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_RgnHandleType_struct));
_temp1502[ 0]=({ struct Cyc_Absyn_RgnHandleType_struct _temp1503; _temp1503.tag=
Cyc_Absyn_RgnHandleType; _temp1503.f1=( void*) Cyc_Absyn_new_evar(( struct Cyc_Core_Opt*)&
Cyc_Tcexp_rk,({ struct Cyc_Core_Opt* _temp1504=( struct Cyc_Core_Opt*) GC_malloc(
sizeof( struct Cyc_Core_Opt)); _temp1504->v=( void*) Cyc_Tcenv_lookup_type_vars(
te); _temp1504;})); _temp1503;}); _temp1502;}); void* handle_type= Cyc_Tcexp_tcExp(
te,( void**)& expected_type,( struct Cyc_Absyn_Exp*) _check_null( ropt)); void*
_temp1493= Cyc_Tcutil_compress( handle_type); void* _temp1499; _LL1495: if((
unsigned int) _temp1493 > 4u?*(( int*) _temp1493) == Cyc_Absyn_RgnHandleType: 0){
_LL1500: _temp1499=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*) _temp1493)->f1;
goto _LL1496;} else{ goto _LL1497;} _LL1497: goto _LL1498; _LL1496: rgn=
_temp1499; Cyc_Tcenv_check_rgn_accessible( te, loc, rgn); goto _LL1494; _LL1498:
Cyc_Tcutil_terr((( struct Cyc_Absyn_Exp*) _check_null( ropt))->loc,( struct
_tagged_string)({ struct _tagged_string _temp1501= Cyc_Absynpp_typ2string(
handle_type); xprintf("expecting region_t type but found %.*s", _temp1501.last_plus_one
- _temp1501.curr, _temp1501.curr);})); goto _LL1494; _LL1494:;} Cyc_Tcutil_check_type(
loc, te, Cyc_Tcenv_lookup_type_vars( te),( void*) Cyc_Absyn_MemKind, t);{ void*
_temp1505= t; struct Cyc_Absyn_TunionFieldInfo _temp1511; struct Cyc_List_List*
_temp1513; void* _temp1515; struct Cyc_Absyn_Tunionfield* _temp1517; struct Cyc_Absyn_Tuniondecl*
_temp1519; _LL1507: if(( unsigned int) _temp1505 > 4u?*(( int*) _temp1505) ==
Cyc_Absyn_TunionFieldType: 0){ _LL1512: _temp1511=(( struct Cyc_Absyn_TunionFieldType_struct*)
_temp1505)->f1; _LL1516: _temp1515=( void*) _temp1511.field_info; if(*(( int*)
_temp1515) == Cyc_Absyn_KnownTunionfield){ _LL1520: _temp1519=(( struct Cyc_Absyn_KnownTunionfield_struct*)
_temp1515)->f1; goto _LL1518; _LL1518: _temp1517=(( struct Cyc_Absyn_KnownTunionfield_struct*)
_temp1515)->f2; goto _LL1514;} else{ goto _LL1509;} _LL1514: _temp1513=
_temp1511.targs; goto _LL1508;} else{ goto _LL1509;} _LL1509: goto _LL1510;
_LL1508: if( _temp1517->tvs != 0){ Cyc_Tcutil_terr( loc,({ unsigned char*
_temp1521=( unsigned char*)"malloc with existential types not yet implemented";
struct _tagged_string _temp1522; _temp1522.curr= _temp1521; _temp1522.base=
_temp1521; _temp1522.last_plus_one= _temp1521 + 50; _temp1522;}));} goto _LL1506;
_LL1510: goto _LL1506; _LL1506:;}{ void*(* _temp1523)( void* t, void* rgn,
struct Cyc_Absyn_Tqual tq)= Cyc_Absyn_at_typ; goto _LL1524; _LL1524: if( topt !=
0){ void* _temp1525= Cyc_Tcutil_compress(*(( void**) _check_null( topt)));
struct Cyc_Absyn_PtrInfo _temp1531; struct Cyc_Absyn_Conref* _temp1533; struct
Cyc_Absyn_Tqual _temp1535; struct Cyc_Absyn_Conref* _temp1537; void* _temp1539;
void* _temp1541; _LL1527: if(( unsigned int) _temp1525 > 4u?*(( int*) _temp1525)
== Cyc_Absyn_PointerType: 0){ _LL1532: _temp1531=(( struct Cyc_Absyn_PointerType_struct*)
_temp1525)->f1; _LL1542: _temp1541=( void*) _temp1531.elt_typ; goto _LL1540;
_LL1540: _temp1539=( void*) _temp1531.rgn_typ; goto _LL1538; _LL1538: _temp1537=
_temp1531.nullable; goto _LL1536; _LL1536: _temp1535= _temp1531.tq; goto _LL1534;
_LL1534: _temp1533= _temp1531.bounds; goto _LL1528;} else{ goto _LL1529;}
_LL1529: goto _LL1530; _LL1528: if((( int(*)( struct Cyc_Absyn_Conref* x)) Cyc_Absyn_conref_val)(
_temp1537)){ _temp1523= Cyc_Absyn_star_typ;} goto _LL1526; _LL1530: goto _LL1526;
_LL1526:;} return _temp1523( t, rgn, Cyc_Absyn_empty_tqual());}} static void*
Cyc_Tcexp_tcStmtExp( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc,
void** topt, struct Cyc_Absyn_Stmt* s){ Cyc_Tcstmt_tcStmt( Cyc_Tcenv_set_encloser(
te, s), s, 1); Cyc_NewControlFlow_set_encloser( s, Cyc_Tcenv_get_encloser( te));
while( 1) { void* _temp1543=( void*) s->r; struct Cyc_Absyn_Exp* _temp1553;
struct Cyc_Absyn_Stmt* _temp1555; struct Cyc_Absyn_Stmt* _temp1557; struct Cyc_Absyn_Stmt*
_temp1559; struct Cyc_Absyn_Decl* _temp1561; _LL1545: if(( unsigned int)
_temp1543 > 1u?*(( int*) _temp1543) == Cyc_Absyn_Exp_s: 0){ _LL1554: _temp1553=((
struct Cyc_Absyn_Exp_s_struct*) _temp1543)->f1; goto _LL1546;} else{ goto
_LL1547;} _LL1547: if(( unsigned int) _temp1543 > 1u?*(( int*) _temp1543) == Cyc_Absyn_Seq_s:
0){ _LL1558: _temp1557=(( struct Cyc_Absyn_Seq_s_struct*) _temp1543)->f1; goto
_LL1556; _LL1556: _temp1555=(( struct Cyc_Absyn_Seq_s_struct*) _temp1543)->f2;
goto _LL1548;} else{ goto _LL1549;} _LL1549: if(( unsigned int) _temp1543 > 1u?*((
int*) _temp1543) == Cyc_Absyn_Decl_s: 0){ _LL1562: _temp1561=(( struct Cyc_Absyn_Decl_s_struct*)
_temp1543)->f1; goto _LL1560; _LL1560: _temp1559=(( struct Cyc_Absyn_Decl_s_struct*)
_temp1543)->f2; goto _LL1550;} else{ goto _LL1551;} _LL1551: goto _LL1552;
_LL1546: return( void*)(( struct Cyc_Core_Opt*) _check_null( _temp1553->topt))->v;
_LL1548: s= _temp1555; continue; _LL1550: s= _temp1559; continue; _LL1552:
return Cyc_Tcexp_expr_err( te, loc,({ unsigned char* _temp1563=( unsigned char*)"statement expression must end with expression";
struct _tagged_string _temp1564; _temp1564.curr= _temp1563; _temp1564.base=
_temp1563; _temp1564.last_plus_one= _temp1563 + 46; _temp1564;})); _LL1544:;}}
static void* Cyc_Tcexp_tcCodegen( struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment*
loc, void** topt, struct Cyc_Absyn_Fndecl* fd){ return Cyc_Tcexp_expr_err( te,
loc,({ unsigned char* _temp1565=( unsigned char*)"tcCodegen"; struct
_tagged_string _temp1566; _temp1566.curr= _temp1565; _temp1566.base= _temp1565;
_temp1566.last_plus_one= _temp1565 + 10; _temp1566;}));} static void* Cyc_Tcexp_tcFill(
struct Cyc_Tcenv_Tenv* te, struct Cyc_Position_Segment* loc, void** topt, struct
Cyc_Absyn_Exp* e){ return Cyc_Tcexp_expr_err( te, loc,({ unsigned char*
_temp1567=( unsigned char*)"tcFill"; struct _tagged_string _temp1568; _temp1568.curr=
_temp1567; _temp1568.base= _temp1567; _temp1568.last_plus_one= _temp1567 + 7;
_temp1568;}));} static void* Cyc_Tcexp_tcNew( struct Cyc_Tcenv_Tenv* te, struct
Cyc_Position_Segment* loc, void** topt, struct Cyc_Absyn_Exp* rgn_handle, struct
Cyc_Absyn_Exp* e, struct Cyc_Absyn_Exp* e1){ void* rgn=( void*) Cyc_Absyn_HeapRgn;
if( rgn_handle != 0){ void* expected_type=( void*)({ struct Cyc_Absyn_RgnHandleType_struct*
_temp1578=( struct Cyc_Absyn_RgnHandleType_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_RgnHandleType_struct)); _temp1578[ 0]=({ struct Cyc_Absyn_RgnHandleType_struct
_temp1579; _temp1579.tag= Cyc_Absyn_RgnHandleType; _temp1579.f1=( void*) Cyc_Absyn_new_evar((
struct Cyc_Core_Opt*)& Cyc_Tcexp_rk,({ struct Cyc_Core_Opt* _temp1580=( struct
Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1580->v=( void*)
Cyc_Tcenv_lookup_type_vars( te); _temp1580;})); _temp1579;}); _temp1578;}); void*
handle_type= Cyc_Tcexp_tcExp( te,( void**)& expected_type,( struct Cyc_Absyn_Exp*)
_check_null( rgn_handle)); void* _temp1569= Cyc_Tcutil_compress( handle_type);
void* _temp1575; _LL1571: if(( unsigned int) _temp1569 > 4u?*(( int*) _temp1569)
== Cyc_Absyn_RgnHandleType: 0){ _LL1576: _temp1575=( void*)(( struct Cyc_Absyn_RgnHandleType_struct*)
_temp1569)->f1; goto _LL1572;} else{ goto _LL1573;} _LL1573: goto _LL1574;
_LL1572: rgn= _temp1575; Cyc_Tcenv_check_rgn_accessible( te, loc, rgn); goto
_LL1570; _LL1574: Cyc_Tcutil_terr((( struct Cyc_Absyn_Exp*) _check_null(
rgn_handle))->loc,( struct _tagged_string)({ struct _tagged_string _temp1577=
Cyc_Absynpp_typ2string( handle_type); xprintf("expecting region_t type but found %.*s",
_temp1577.last_plus_one - _temp1577.curr, _temp1577.curr);})); goto _LL1570;
_LL1570:;}{ void* _temp1581=( void*) e1->r; struct Cyc_Absyn_Exp* _temp1593;
struct Cyc_Absyn_Exp* _temp1595; struct Cyc_Absyn_Vardecl* _temp1597; struct Cyc_List_List*
_temp1599; struct Cyc_Core_Opt* _temp1601; struct Cyc_List_List* _temp1603; void*
_temp1605; struct _tagged_string _temp1607; _LL1583: if(*(( int*) _temp1581) ==
Cyc_Absyn_Comprehension_e){ _LL1598: _temp1597=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1581)->f1; goto _LL1596; _LL1596: _temp1595=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1581)->f2; goto _LL1594; _LL1594: _temp1593=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1581)->f3; goto _LL1584;} else{ goto _LL1585;} _LL1585: if(*(( int*)
_temp1581) == Cyc_Absyn_UnresolvedMem_e){ _LL1602: _temp1601=(( struct Cyc_Absyn_UnresolvedMem_e_struct*)
_temp1581)->f1; goto _LL1600; _LL1600: _temp1599=(( struct Cyc_Absyn_UnresolvedMem_e_struct*)
_temp1581)->f2; goto _LL1586;} else{ goto _LL1587;} _LL1587: if(*(( int*)
_temp1581) == Cyc_Absyn_Array_e){ _LL1604: _temp1603=(( struct Cyc_Absyn_Array_e_struct*)
_temp1581)->f1; goto _LL1588;} else{ goto _LL1589;} _LL1589: if(*(( int*)
_temp1581) == Cyc_Absyn_Const_e){ _LL1606: _temp1605=( void*)(( struct Cyc_Absyn_Const_e_struct*)
_temp1581)->f1; if(( unsigned int) _temp1605 > 1u?*(( int*) _temp1605) == Cyc_Absyn_String_c:
0){ _LL1608: _temp1607=(( struct Cyc_Absyn_String_c_struct*) _temp1605)->f1;
goto _LL1590;} else{ goto _LL1591;}} else{ goto _LL1591;} _LL1591: goto _LL1592;
_LL1584: { void* _temp1609= Cyc_Tcexp_tcExpNoPromote( te, topt, e1); goto
_LL1610; _LL1610: { void* _temp1611= Cyc_Tcutil_compress( _temp1609); struct Cyc_Absyn_Exp*
_temp1617; struct Cyc_Absyn_Tqual _temp1619; void* _temp1621; _LL1613: if((
unsigned int) _temp1611 > 4u?*(( int*) _temp1611) == Cyc_Absyn_ArrayType: 0){
_LL1622: _temp1621=( void*)(( struct Cyc_Absyn_ArrayType_struct*) _temp1611)->f1;
goto _LL1620; _LL1620: _temp1619=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1611)->f2; goto _LL1618; _LL1618: _temp1617=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1611)->f3; goto _LL1614;} else{ goto _LL1615;} _LL1615: goto _LL1616;
_LL1614: { void* b= Cyc_Tcutil_is_const_exp( te, _temp1595)?( void*)({ struct
Cyc_Absyn_Upper_b_struct* _temp1627=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp1627[ 0]=({ struct
Cyc_Absyn_Upper_b_struct _temp1628; _temp1628.tag= Cyc_Absyn_Upper_b; _temp1628.f1=
_temp1595; _temp1628;}); _temp1627;}):( void*) Cyc_Absyn_Unknown_b; void*
res_typ=( void*)({ struct Cyc_Absyn_PointerType_struct* _temp1624=( struct Cyc_Absyn_PointerType_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct)); _temp1624[ 0]=({
struct Cyc_Absyn_PointerType_struct _temp1625; _temp1625.tag= Cyc_Absyn_PointerType;
_temp1625.f1=({ struct Cyc_Absyn_PtrInfo _temp1626; _temp1626.elt_typ=( void*)
_temp1621; _temp1626.rgn_typ=( void*) rgn; _temp1626.nullable=(( struct Cyc_Absyn_Conref*(*)())
Cyc_Absyn_empty_conref)(); _temp1626.tq= _temp1619; _temp1626.bounds=(( struct
Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)( b); _temp1626;});
_temp1625;}); _temp1624;}); if( topt != 0){ if( ! Cyc_Tcutil_unify(*(( void**)
_check_null( topt)), res_typ)? Cyc_Tcutil_silent_castable( te, loc, res_typ,*((
void**) _check_null( topt))): 0){ e->topt=({ struct Cyc_Core_Opt* _temp1623=(
struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1623->v=(
void*) res_typ; _temp1623;}); Cyc_Tcutil_unchecked_cast( te, e,*(( void**)
_check_null( topt))); res_typ=*(( void**) _check_null( topt));}} return res_typ;}
_LL1616: return(( void*(*)( struct _tagged_string)) Cyc_Tcutil_impos)(({
unsigned char* _temp1629=( unsigned char*)"tcNew: comprehension returned non-array type";
struct _tagged_string _temp1630; _temp1630.curr= _temp1629; _temp1630.base=
_temp1629; _temp1630.last_plus_one= _temp1629 + 45; _temp1630;})); _LL1612:;}}
_LL1586:( void*)( e1->r=( void*)(( void*)({ struct Cyc_Absyn_Array_e_struct*
_temp1631=( struct Cyc_Absyn_Array_e_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Array_e_struct));
_temp1631[ 0]=({ struct Cyc_Absyn_Array_e_struct _temp1632; _temp1632.tag= Cyc_Absyn_Array_e;
_temp1632.f1= _temp1599; _temp1632;}); _temp1631;}))); _temp1603= _temp1599;
goto _LL1588; _LL1588: { void** elt_typ_opt= 0; if( topt != 0){ void* _temp1633=
Cyc_Tcutil_compress(*(( void**) _check_null( topt))); struct Cyc_Absyn_PtrInfo
_temp1639; struct Cyc_Absyn_Conref* _temp1641; struct Cyc_Absyn_Tqual _temp1643;
struct Cyc_Absyn_Conref* _temp1645; void* _temp1647; void* _temp1649; void**
_temp1651; _LL1635: if(( unsigned int) _temp1633 > 4u?*(( int*) _temp1633) ==
Cyc_Absyn_PointerType: 0){ _LL1640: _temp1639=(( struct Cyc_Absyn_PointerType_struct*)
_temp1633)->f1; _LL1650: _temp1649=( void*) _temp1639.elt_typ; _temp1651=&(((
struct Cyc_Absyn_PointerType_struct*) _temp1633)->f1).elt_typ; goto _LL1648;
_LL1648: _temp1647=( void*) _temp1639.rgn_typ; goto _LL1646; _LL1646: _temp1645=
_temp1639.nullable; goto _LL1644; _LL1644: _temp1643= _temp1639.tq; goto _LL1642;
_LL1642: _temp1641= _temp1639.bounds; goto _LL1636;} else{ goto _LL1637;}
_LL1637: goto _LL1638; _LL1636: elt_typ_opt=( void**) _temp1651; goto _LL1634;
_LL1638: goto _LL1634; _LL1634:;}{ void* _temp1652= Cyc_Tcexp_tcExpNoPromote( te,
elt_typ_opt, e1); goto _LL1653; _LL1653: { void* res_typ;{ void* _temp1654= Cyc_Tcutil_compress(
_temp1652); struct Cyc_Absyn_Exp* _temp1660; struct Cyc_Absyn_Tqual _temp1662;
void* _temp1664; _LL1656: if(( unsigned int) _temp1654 > 4u?*(( int*) _temp1654)
== Cyc_Absyn_ArrayType: 0){ _LL1665: _temp1664=( void*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1654)->f1; goto _LL1663; _LL1663: _temp1662=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1654)->f2; goto _LL1661; _LL1661: _temp1660=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1654)->f3; goto _LL1657;} else{ goto _LL1658;} _LL1658: goto _LL1659;
_LL1657: res_typ=( void*)({ struct Cyc_Absyn_PointerType_struct* _temp1666=(
struct Cyc_Absyn_PointerType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct));
_temp1666[ 0]=({ struct Cyc_Absyn_PointerType_struct _temp1667; _temp1667.tag=
Cyc_Absyn_PointerType; _temp1667.f1=({ struct Cyc_Absyn_PtrInfo _temp1668;
_temp1668.elt_typ=( void*) _temp1664; _temp1668.rgn_typ=( void*) rgn; _temp1668.nullable=((
struct Cyc_Absyn_Conref*(*)()) Cyc_Absyn_empty_conref)(); _temp1668.tq=
_temp1662; _temp1668.bounds=(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)((
void*)({ struct Cyc_Absyn_Upper_b_struct* _temp1669=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp1669[ 0]=({ struct
Cyc_Absyn_Upper_b_struct _temp1670; _temp1670.tag= Cyc_Absyn_Upper_b; _temp1670.f1=(
struct Cyc_Absyn_Exp*) _check_null( _temp1660); _temp1670;}); _temp1669;}));
_temp1668;}); _temp1667;}); _temp1666;}); if( topt != 0){ if( ! Cyc_Tcutil_unify(*((
void**) _check_null( topt)), res_typ)? Cyc_Tcutil_silent_castable( te, loc,
res_typ,*(( void**) _check_null( topt))): 0){ e->topt=({ struct Cyc_Core_Opt*
_temp1671=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp1671->v=( void*) res_typ; _temp1671;}); Cyc_Tcutil_unchecked_cast( te, e,*((
void**) _check_null( topt))); res_typ=*(( void**) _check_null( topt));}} goto
_LL1655; _LL1659: return(( void*(*)( struct _tagged_string)) Cyc_Tcutil_impos)(({
unsigned char* _temp1672=( unsigned char*)"tcExpNoPromote on Array_e returned non-array type";
struct _tagged_string _temp1673; _temp1673.curr= _temp1672; _temp1673.base=
_temp1672; _temp1673.last_plus_one= _temp1672 + 50; _temp1673;})); _LL1655:;}
return res_typ;}}} _LL1590: { void* _temp1674= Cyc_Absyn_atb_typ( Cyc_Absyn_uchar_t,
rgn, Cyc_Absyn_const_tqual(),( void*) Cyc_Absyn_Unknown_b); goto _LL1675;
_LL1675: { void* _temp1676= Cyc_Tcexp_tcExp( te,( void**)& _temp1674, e1); goto
_LL1677; _LL1677: return Cyc_Absyn_atb_typ( _temp1676, rgn, Cyc_Absyn_empty_tqual(),(
void*)({ struct Cyc_Absyn_Upper_b_struct* _temp1678=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp1678[ 0]=({ struct
Cyc_Absyn_Upper_b_struct _temp1679; _temp1679.tag= Cyc_Absyn_Upper_b; _temp1679.f1=
Cyc_Absyn_uint_exp( 1, 0); _temp1679;}); _temp1678;}));}} _LL1592: { void**
topt2= 0; if( topt != 0){ void* _temp1680= Cyc_Tcutil_compress(*(( void**)
_check_null( topt))); struct Cyc_Absyn_PtrInfo _temp1688; struct Cyc_Absyn_Conref*
_temp1690; struct Cyc_Absyn_Tqual _temp1692; struct Cyc_Absyn_Conref* _temp1694;
void* _temp1696; void* _temp1698; void** _temp1700; struct Cyc_Absyn_TunionInfo
_temp1701; _LL1682: if(( unsigned int) _temp1680 > 4u?*(( int*) _temp1680) ==
Cyc_Absyn_PointerType: 0){ _LL1689: _temp1688=(( struct Cyc_Absyn_PointerType_struct*)
_temp1680)->f1; _LL1699: _temp1698=( void*) _temp1688.elt_typ; _temp1700=&(((
struct Cyc_Absyn_PointerType_struct*) _temp1680)->f1).elt_typ; goto _LL1697;
_LL1697: _temp1696=( void*) _temp1688.rgn_typ; goto _LL1695; _LL1695: _temp1694=
_temp1688.nullable; goto _LL1693; _LL1693: _temp1692= _temp1688.tq; goto _LL1691;
_LL1691: _temp1690= _temp1688.bounds; goto _LL1683;} else{ goto _LL1684;}
_LL1684: if(( unsigned int) _temp1680 > 4u?*(( int*) _temp1680) == Cyc_Absyn_TunionType:
0){ _LL1702: _temp1701=(( struct Cyc_Absyn_TunionType_struct*) _temp1680)->f1;
goto _LL1685;} else{ goto _LL1686;} _LL1686: goto _LL1687; _LL1683: topt2=( void**)
_temp1700; goto _LL1681; _LL1685: topt2=({ void** _temp1703=( void**) GC_malloc(
sizeof( void*)); _temp1703[ 0]=*(( void**) _check_null( topt)); _temp1703;});
goto _LL1681; _LL1687: goto _LL1681; _LL1681:;}{ void* _temp1704= Cyc_Tcexp_tcExp(
te, topt2, e1); goto _LL1705; _LL1705: { void* res_typ=( void*)({ struct Cyc_Absyn_PointerType_struct*
_temp1707=( struct Cyc_Absyn_PointerType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct));
_temp1707[ 0]=({ struct Cyc_Absyn_PointerType_struct _temp1708; _temp1708.tag=
Cyc_Absyn_PointerType; _temp1708.f1=({ struct Cyc_Absyn_PtrInfo _temp1709;
_temp1709.elt_typ=( void*) _temp1704; _temp1709.rgn_typ=( void*) rgn; _temp1709.nullable=((
struct Cyc_Absyn_Conref*(*)()) Cyc_Absyn_empty_conref)(); _temp1709.tq= Cyc_Absyn_empty_tqual();
_temp1709.bounds=(( struct Cyc_Absyn_Conref*(*)( void* x)) Cyc_Absyn_new_conref)((
void*)({ struct Cyc_Absyn_Upper_b_struct* _temp1710=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp1710[ 0]=({ struct
Cyc_Absyn_Upper_b_struct _temp1711; _temp1711.tag= Cyc_Absyn_Upper_b; _temp1711.f1=
Cyc_Absyn_uint_exp( 1, 0); _temp1711;}); _temp1710;})); _temp1709;}); _temp1708;});
_temp1707;}); if( topt != 0){ if( ! Cyc_Tcutil_unify(*(( void**) _check_null(
topt)), res_typ)? Cyc_Tcutil_silent_castable( te, loc, res_typ,*(( void**)
_check_null( topt))): 0){ e->topt=({ struct Cyc_Core_Opt* _temp1706=( struct Cyc_Core_Opt*)
GC_malloc( sizeof( struct Cyc_Core_Opt)); _temp1706->v=( void*) res_typ;
_temp1706;}); Cyc_Tcutil_unchecked_cast( te, e,*(( void**) _check_null( topt)));
res_typ=*(( void**) _check_null( topt));}} return res_typ;}}} _LL1582:;}} void*
Cyc_Tcexp_tcExp( struct Cyc_Tcenv_Tenv* te, void** topt, struct Cyc_Absyn_Exp* e){
void* t= Cyc_Tcexp_tcExpNoPromote( te, topt, e); t= Cyc_Tcutil_compress( t);{
void* _temp1712= t; struct Cyc_Absyn_Exp* _temp1718; struct Cyc_Absyn_Tqual
_temp1720; void* _temp1722; _LL1714: if(( unsigned int) _temp1712 > 4u?*(( int*)
_temp1712) == Cyc_Absyn_ArrayType: 0){ _LL1723: _temp1722=( void*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1712)->f1; goto _LL1721; _LL1721: _temp1720=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1712)->f2; goto _LL1719; _LL1719: _temp1718=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1712)->f3; goto _LL1715;} else{ goto _LL1716;} _LL1716: goto _LL1717;
_LL1715: { void* _temp1726; int _temp1728; struct _tuple6 _temp1724= Cyc_Tcutil_addressof_props(
te, e); _LL1729: _temp1728= _temp1724.f1; goto _LL1727; _LL1727: _temp1726=
_temp1724.f2; goto _LL1725; _LL1725: { void* _temp1732= _temp1718 == 0?( void*)
Cyc_Absyn_Unknown_b:( void*)({ struct Cyc_Absyn_Upper_b_struct* _temp1730=(
struct Cyc_Absyn_Upper_b_struct*) GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct));
_temp1730[ 0]=({ struct Cyc_Absyn_Upper_b_struct _temp1731; _temp1731.tag= Cyc_Absyn_Upper_b;
_temp1731.f1=( struct Cyc_Absyn_Exp*) _check_null( _temp1718); _temp1731;});
_temp1730;}); goto _LL1733; _LL1733: t= Cyc_Absyn_atb_typ( _temp1722, _temp1726,
_temp1720, _temp1732);( void*)((( struct Cyc_Core_Opt*) _check_null( e->topt))->v=(
void*) t); return t;}} _LL1717: return t; _LL1713:;}} void* Cyc_Tcexp_tcExpInitializer(
struct Cyc_Tcenv_Tenv* te, void** topt, struct Cyc_Absyn_Exp* e){ void* t= Cyc_Tcexp_tcExpNoPromote(
te, topt, e); void* _temp1734=( void*) e->r; struct Cyc_List_List* _temp1744;
struct Cyc_Absyn_Exp* _temp1746; struct Cyc_Absyn_Exp* _temp1748; struct Cyc_Absyn_Vardecl*
_temp1750; void* _temp1752; struct _tagged_string _temp1754; _LL1736: if(*(( int*)
_temp1734) == Cyc_Absyn_Array_e){ _LL1745: _temp1744=(( struct Cyc_Absyn_Array_e_struct*)
_temp1734)->f1; goto _LL1737;} else{ goto _LL1738;} _LL1738: if(*(( int*)
_temp1734) == Cyc_Absyn_Comprehension_e){ _LL1751: _temp1750=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1734)->f1; goto _LL1749; _LL1749: _temp1748=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1734)->f2; goto _LL1747; _LL1747: _temp1746=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1734)->f3; goto _LL1739;} else{ goto _LL1740;} _LL1740: if(*(( int*)
_temp1734) == Cyc_Absyn_Const_e){ _LL1753: _temp1752=( void*)(( struct Cyc_Absyn_Const_e_struct*)
_temp1734)->f1; if(( unsigned int) _temp1752 > 1u?*(( int*) _temp1752) == Cyc_Absyn_String_c:
0){ _LL1755: _temp1754=(( struct Cyc_Absyn_String_c_struct*) _temp1752)->f1;
goto _LL1741;} else{ goto _LL1742;}} else{ goto _LL1742;} _LL1742: goto _LL1743;
_LL1737: return t; _LL1739: return t; _LL1741: return t; _LL1743: t= Cyc_Tcutil_compress(
t);{ void* _temp1756= t; struct Cyc_Absyn_Exp* _temp1762; struct Cyc_Absyn_Tqual
_temp1764; void* _temp1766; _LL1758: if(( unsigned int) _temp1756 > 4u?*(( int*)
_temp1756) == Cyc_Absyn_ArrayType: 0){ _LL1767: _temp1766=( void*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp1756)->f1; goto _LL1765; _LL1765: _temp1764=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1756)->f2; goto _LL1763; _LL1763: _temp1762=(( struct Cyc_Absyn_ArrayType_struct*)
_temp1756)->f3; goto _LL1759;} else{ goto _LL1760;} _LL1760: goto _LL1761;
_LL1759: { void* _temp1770; int _temp1772; struct _tuple6 _temp1768= Cyc_Tcutil_addressof_props(
te, e); _LL1773: _temp1772= _temp1768.f1; goto _LL1771; _LL1771: _temp1770=
_temp1768.f2; goto _LL1769; _LL1769: { void* b= _temp1762 == 0?( void*) Cyc_Absyn_Unknown_b:(
void*)({ struct Cyc_Absyn_Upper_b_struct* _temp1774=( struct Cyc_Absyn_Upper_b_struct*)
GC_malloc( sizeof( struct Cyc_Absyn_Upper_b_struct)); _temp1774[ 0]=({ struct
Cyc_Absyn_Upper_b_struct _temp1775; _temp1775.tag= Cyc_Absyn_Upper_b; _temp1775.f1=(
struct Cyc_Absyn_Exp*) _check_null( _temp1762); _temp1775;}); _temp1774;}); t=
Cyc_Absyn_atb_typ( _temp1766, _temp1770, _temp1764, b); Cyc_Tcutil_unchecked_cast(
te, e, t); return t;}} _LL1761: return t; _LL1757:;} _LL1735:;} static void* Cyc_Tcexp_tcExpNoPromote(
struct Cyc_Tcenv_Tenv* te, void** topt, struct Cyc_Absyn_Exp* e){{ void*
_temp1776=( void*) e->r; struct Cyc_Absyn_Exp* _temp1782; _LL1778: if(*(( int*)
_temp1776) == Cyc_Absyn_NoInstantiate_e){ _LL1783: _temp1782=(( struct Cyc_Absyn_NoInstantiate_e_struct*)
_temp1776)->f1; goto _LL1779;} else{ goto _LL1780;} _LL1780: goto _LL1781;
_LL1779: Cyc_Tcexp_tcExpNoInst( te, topt, _temp1782);( void*)((( struct Cyc_Core_Opt*)
_check_null( _temp1782->topt))->v=( void*) Cyc_Absyn_pointer_expand( Cyc_Tcutil_compress((
void*)(( struct Cyc_Core_Opt*) _check_null( _temp1782->topt))->v))); e->topt=
_temp1782->topt; goto _LL1777; _LL1781: Cyc_Tcexp_tcExpNoInst( te, topt, e);(
void*)((( struct Cyc_Core_Opt*) _check_null( e->topt))->v=( void*) Cyc_Absyn_pointer_expand(
Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*) _check_null( e->topt))->v)));{
void* _temp1784= Cyc_Tcutil_compress(( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v); struct Cyc_Absyn_PtrInfo _temp1790; struct Cyc_Absyn_Conref*
_temp1792; struct Cyc_Absyn_Tqual _temp1794; struct Cyc_Absyn_Conref* _temp1796;
void* _temp1798; void* _temp1800; _LL1786: if(( unsigned int) _temp1784 > 4u?*((
int*) _temp1784) == Cyc_Absyn_PointerType: 0){ _LL1791: _temp1790=(( struct Cyc_Absyn_PointerType_struct*)
_temp1784)->f1; _LL1801: _temp1800=( void*) _temp1790.elt_typ; goto _LL1799;
_LL1799: _temp1798=( void*) _temp1790.rgn_typ; goto _LL1797; _LL1797: _temp1796=
_temp1790.nullable; goto _LL1795; _LL1795: _temp1794= _temp1790.tq; goto _LL1793;
_LL1793: _temp1792= _temp1790.bounds; goto _LL1787;} else{ goto _LL1788;}
_LL1788: goto _LL1789; _LL1787:{ void* _temp1802= Cyc_Tcutil_compress( _temp1800);
struct Cyc_Absyn_FnInfo _temp1808; struct Cyc_List_List* _temp1810; struct Cyc_List_List*
_temp1812; struct Cyc_Absyn_VarargInfo* _temp1814; int _temp1816; struct Cyc_List_List*
_temp1818; void* _temp1820; struct Cyc_Core_Opt* _temp1822; struct Cyc_List_List*
_temp1824; _LL1804: if(( unsigned int) _temp1802 > 4u?*(( int*) _temp1802) ==
Cyc_Absyn_FnType: 0){ _LL1809: _temp1808=(( struct Cyc_Absyn_FnType_struct*)
_temp1802)->f1; _LL1825: _temp1824= _temp1808.tvars; goto _LL1823; _LL1823:
_temp1822= _temp1808.effect; goto _LL1821; _LL1821: _temp1820=( void*) _temp1808.ret_typ;
goto _LL1819; _LL1819: _temp1818= _temp1808.args; goto _LL1817; _LL1817:
_temp1816= _temp1808.c_varargs; goto _LL1815; _LL1815: _temp1814= _temp1808.cyc_varargs;
goto _LL1813; _LL1813: _temp1812= _temp1808.rgn_po; goto _LL1811; _LL1811:
_temp1810= _temp1808.attributes; goto _LL1805;} else{ goto _LL1806;} _LL1806:
goto _LL1807; _LL1805: if( _temp1824 != 0){ struct _RegionHandle _temp1826=
_new_region(); struct _RegionHandle* rgn=& _temp1826; _push_region( rgn);{
struct _tuple4 _temp1828=({ struct _tuple4 _temp1827; _temp1827.f1= Cyc_Tcenv_lookup_type_vars(
te); _temp1827.f2= rgn; _temp1827;}); goto _LL1829; _LL1829: { struct Cyc_List_List*
inst=(( struct Cyc_List_List*(*)( struct _RegionHandle*, struct _tuple5*(* f)(
struct _tuple4*, struct Cyc_Absyn_Tvar*), struct _tuple4* env, struct Cyc_List_List*
x)) Cyc_List_rmap_c)( rgn, Cyc_Tcutil_r_make_inst_var,& _temp1828, _temp1824);
struct Cyc_List_List* ts=(( struct Cyc_List_List*(*)( void*(* f)( struct _tuple5*),
struct Cyc_List_List* x)) Cyc_List_map)(( void*(*)( struct _tuple5*)) Cyc_Core_snd,
inst); void* ftyp= Cyc_Tcutil_rsubstitute( rgn, inst,( void*)({ struct Cyc_Absyn_FnType_struct*
_temp1836=( struct Cyc_Absyn_FnType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_FnType_struct));
_temp1836[ 0]=({ struct Cyc_Absyn_FnType_struct _temp1837; _temp1837.tag= Cyc_Absyn_FnType;
_temp1837.f1=({ struct Cyc_Absyn_FnInfo _temp1838; _temp1838.tvars= 0; _temp1838.effect=
_temp1822; _temp1838.ret_typ=( void*) _temp1820; _temp1838.args= _temp1818;
_temp1838.c_varargs= _temp1816; _temp1838.cyc_varargs= _temp1814; _temp1838.rgn_po=
_temp1812; _temp1838.attributes= _temp1810; _temp1838;}); _temp1837;});
_temp1836;})); void* new_typ=( void*)({ struct Cyc_Absyn_PointerType_struct*
_temp1833=( struct Cyc_Absyn_PointerType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_PointerType_struct));
_temp1833[ 0]=({ struct Cyc_Absyn_PointerType_struct _temp1834; _temp1834.tag=
Cyc_Absyn_PointerType; _temp1834.f1=({ struct Cyc_Absyn_PtrInfo _temp1835;
_temp1835.elt_typ=( void*) ftyp; _temp1835.rgn_typ=( void*) _temp1798; _temp1835.nullable=
_temp1796; _temp1835.tq= _temp1794; _temp1835.bounds= _temp1792; _temp1835;});
_temp1834;}); _temp1833;}); struct Cyc_Absyn_Exp* inner= Cyc_Absyn_copy_exp( e);(
void*)( e->r=( void*)(( void*)({ struct Cyc_Absyn_Instantiate_e_struct*
_temp1830=( struct Cyc_Absyn_Instantiate_e_struct*) GC_malloc( sizeof( struct
Cyc_Absyn_Instantiate_e_struct)); _temp1830[ 0]=({ struct Cyc_Absyn_Instantiate_e_struct
_temp1831; _temp1831.tag= Cyc_Absyn_Instantiate_e; _temp1831.f1= inner;
_temp1831.f2= ts; _temp1831;}); _temp1830;}))); e->topt=({ struct Cyc_Core_Opt*
_temp1832=( struct Cyc_Core_Opt*) GC_malloc( sizeof( struct Cyc_Core_Opt));
_temp1832->v=( void*) new_typ; _temp1832;});}}; _pop_region(& _temp1826);} goto
_LL1803; _LL1807: goto _LL1803; _LL1803:;} goto _LL1785; _LL1789: goto _LL1785;
_LL1785:;} goto _LL1777; _LL1777:;} return( void*)(( struct Cyc_Core_Opt*)
_check_null( e->topt))->v;} static void Cyc_Tcexp_tcExpNoInst( struct Cyc_Tcenv_Tenv*
te, void** topt, struct Cyc_Absyn_Exp* e){ struct Cyc_Position_Segment* loc= e->loc;
void* t;{ void* _temp1839=( void*) e->r; struct Cyc_Absyn_Exp* _temp1913; struct
_tuple1* _temp1915; struct Cyc_List_List* _temp1917; struct Cyc_Absyn_Exp*
_temp1919; struct Cyc_List_List* _temp1921; struct Cyc_Core_Opt* _temp1923; void*
_temp1925; void* _temp1927; struct _tuple1* _temp1929; struct Cyc_List_List*
_temp1931; void* _temp1933; void* _temp1935; struct Cyc_Absyn_Exp* _temp1937;
struct Cyc_Absyn_Exp* _temp1939; struct Cyc_Core_Opt* _temp1941; struct Cyc_Absyn_Exp*
_temp1943; struct Cyc_Absyn_Exp* _temp1945; struct Cyc_Absyn_Exp* _temp1947;
struct Cyc_Absyn_Exp* _temp1949; struct Cyc_Absyn_Exp* _temp1951; struct Cyc_Absyn_Exp*
_temp1953; struct Cyc_Absyn_VarargCallInfo* _temp1955; struct Cyc_Absyn_VarargCallInfo**
_temp1957; struct Cyc_List_List* _temp1958; struct Cyc_Absyn_Exp* _temp1960;
struct Cyc_Absyn_Exp* _temp1962; struct Cyc_List_List* _temp1964; struct Cyc_Absyn_Exp*
_temp1966; struct Cyc_Absyn_Exp* _temp1968; void* _temp1970; struct Cyc_Absyn_Exp*
_temp1972; struct Cyc_Absyn_Exp* _temp1974; struct Cyc_Absyn_Exp* _temp1976;
struct Cyc_Absyn_Exp* _temp1978; void* _temp1980; struct _tagged_string*
_temp1982; void* _temp1984; struct Cyc_Absyn_Exp* _temp1986; struct
_tagged_string* _temp1988; struct Cyc_Absyn_Exp* _temp1990; struct
_tagged_string* _temp1992; struct Cyc_Absyn_Exp* _temp1994; struct Cyc_Absyn_Exp*
_temp1996; struct Cyc_Absyn_Exp* _temp1998; struct Cyc_List_List* _temp2000;
struct Cyc_List_List* _temp2002; struct _tuple2* _temp2004; struct Cyc_List_List*
_temp2006; struct Cyc_Absyn_Stmt* _temp2008; struct Cyc_Absyn_Fndecl* _temp2010;
struct Cyc_Absyn_Exp* _temp2012; struct Cyc_Absyn_Exp* _temp2014; struct Cyc_Absyn_Exp*
_temp2016; struct Cyc_Absyn_Vardecl* _temp2018; struct Cyc_Absyn_Structdecl*
_temp2020; struct Cyc_Absyn_Structdecl** _temp2022; struct Cyc_List_List*
_temp2023; struct Cyc_Core_Opt* _temp2025; struct Cyc_Core_Opt** _temp2027;
struct _tuple1* _temp2028; struct _tuple1** _temp2030; struct Cyc_List_List*
_temp2031; void* _temp2033; struct Cyc_Absyn_Tunionfield* _temp2035; struct Cyc_Absyn_Tuniondecl*
_temp2037; struct Cyc_List_List* _temp2039; struct Cyc_Core_Opt* _temp2041;
struct Cyc_Core_Opt** _temp2043; struct Cyc_Core_Opt* _temp2044; struct Cyc_Core_Opt**
_temp2046; struct Cyc_Absyn_Enumfield* _temp2047; struct Cyc_Absyn_Enumdecl*
_temp2049; struct _tuple1* _temp2051; struct _tuple1** _temp2053; void*
_temp2054; struct Cyc_Absyn_Exp* _temp2056; _LL1841: if(*(( int*) _temp1839) ==
Cyc_Absyn_NoInstantiate_e){ _LL1914: _temp1913=(( struct Cyc_Absyn_NoInstantiate_e_struct*)
_temp1839)->f1; goto _LL1842;} else{ goto _LL1843;} _LL1843: if(*(( int*)
_temp1839) == Cyc_Absyn_UnknownId_e){ _LL1916: _temp1915=(( struct Cyc_Absyn_UnknownId_e_struct*)
_temp1839)->f1; goto _LL1844;} else{ goto _LL1845;} _LL1845: if(*(( int*)
_temp1839) == Cyc_Absyn_UnknownCall_e){ _LL1920: _temp1919=(( struct Cyc_Absyn_UnknownCall_e_struct*)
_temp1839)->f1; goto _LL1918; _LL1918: _temp1917=(( struct Cyc_Absyn_UnknownCall_e_struct*)
_temp1839)->f2; goto _LL1846;} else{ goto _LL1847;} _LL1847: if(*(( int*)
_temp1839) == Cyc_Absyn_UnresolvedMem_e){ _LL1924: _temp1923=(( struct Cyc_Absyn_UnresolvedMem_e_struct*)
_temp1839)->f1; goto _LL1922; _LL1922: _temp1921=(( struct Cyc_Absyn_UnresolvedMem_e_struct*)
_temp1839)->f2; goto _LL1848;} else{ goto _LL1849;} _LL1849: if(*(( int*)
_temp1839) == Cyc_Absyn_Const_e){ _LL1926: _temp1925=( void*)(( struct Cyc_Absyn_Const_e_struct*)
_temp1839)->f1; goto _LL1850;} else{ goto _LL1851;} _LL1851: if(*(( int*)
_temp1839) == Cyc_Absyn_Var_e){ _LL1930: _temp1929=(( struct Cyc_Absyn_Var_e_struct*)
_temp1839)->f1; goto _LL1928; _LL1928: _temp1927=( void*)(( struct Cyc_Absyn_Var_e_struct*)
_temp1839)->f2; goto _LL1852;} else{ goto _LL1853;} _LL1853: if(*(( int*)
_temp1839) == Cyc_Absyn_Primop_e){ _LL1934: _temp1933=( void*)(( struct Cyc_Absyn_Primop_e_struct*)
_temp1839)->f1; goto _LL1932; _LL1932: _temp1931=(( struct Cyc_Absyn_Primop_e_struct*)
_temp1839)->f2; goto _LL1854;} else{ goto _LL1855;} _LL1855: if(*(( int*)
_temp1839) == Cyc_Absyn_Increment_e){ _LL1938: _temp1937=(( struct Cyc_Absyn_Increment_e_struct*)
_temp1839)->f1; goto _LL1936; _LL1936: _temp1935=( void*)(( struct Cyc_Absyn_Increment_e_struct*)
_temp1839)->f2; goto _LL1856;} else{ goto _LL1857;} _LL1857: if(*(( int*)
_temp1839) == Cyc_Absyn_AssignOp_e){ _LL1944: _temp1943=(( struct Cyc_Absyn_AssignOp_e_struct*)
_temp1839)->f1; goto _LL1942; _LL1942: _temp1941=(( struct Cyc_Absyn_AssignOp_e_struct*)
_temp1839)->f2; goto _LL1940; _LL1940: _temp1939=(( struct Cyc_Absyn_AssignOp_e_struct*)
_temp1839)->f3; goto _LL1858;} else{ goto _LL1859;} _LL1859: if(*(( int*)
_temp1839) == Cyc_Absyn_Conditional_e){ _LL1950: _temp1949=(( struct Cyc_Absyn_Conditional_e_struct*)
_temp1839)->f1; goto _LL1948; _LL1948: _temp1947=(( struct Cyc_Absyn_Conditional_e_struct*)
_temp1839)->f2; goto _LL1946; _LL1946: _temp1945=(( struct Cyc_Absyn_Conditional_e_struct*)
_temp1839)->f3; goto _LL1860;} else{ goto _LL1861;} _LL1861: if(*(( int*)
_temp1839) == Cyc_Absyn_SeqExp_e){ _LL1954: _temp1953=(( struct Cyc_Absyn_SeqExp_e_struct*)
_temp1839)->f1; goto _LL1952; _LL1952: _temp1951=(( struct Cyc_Absyn_SeqExp_e_struct*)
_temp1839)->f2; goto _LL1862;} else{ goto _LL1863;} _LL1863: if(*(( int*)
_temp1839) == Cyc_Absyn_FnCall_e){ _LL1961: _temp1960=(( struct Cyc_Absyn_FnCall_e_struct*)
_temp1839)->f1; goto _LL1959; _LL1959: _temp1958=(( struct Cyc_Absyn_FnCall_e_struct*)
_temp1839)->f2; goto _LL1956; _LL1956: _temp1955=(( struct Cyc_Absyn_FnCall_e_struct*)
_temp1839)->f3; _temp1957=&(( struct Cyc_Absyn_FnCall_e_struct*) _temp1839)->f3;
goto _LL1864;} else{ goto _LL1865;} _LL1865: if(*(( int*) _temp1839) == Cyc_Absyn_Throw_e){
_LL1963: _temp1962=(( struct Cyc_Absyn_Throw_e_struct*) _temp1839)->f1; goto
_LL1866;} else{ goto _LL1867;} _LL1867: if(*(( int*) _temp1839) == Cyc_Absyn_Instantiate_e){
_LL1967: _temp1966=(( struct Cyc_Absyn_Instantiate_e_struct*) _temp1839)->f1;
goto _LL1965; _LL1965: _temp1964=(( struct Cyc_Absyn_Instantiate_e_struct*)
_temp1839)->f2; goto _LL1868;} else{ goto _LL1869;} _LL1869: if(*(( int*)
_temp1839) == Cyc_Absyn_Cast_e){ _LL1971: _temp1970=( void*)(( struct Cyc_Absyn_Cast_e_struct*)
_temp1839)->f1; goto _LL1969; _LL1969: _temp1968=(( struct Cyc_Absyn_Cast_e_struct*)
_temp1839)->f2; goto _LL1870;} else{ goto _LL1871;} _LL1871: if(*(( int*)
_temp1839) == Cyc_Absyn_Address_e){ _LL1973: _temp1972=(( struct Cyc_Absyn_Address_e_struct*)
_temp1839)->f1; goto _LL1872;} else{ goto _LL1873;} _LL1873: if(*(( int*)
_temp1839) == Cyc_Absyn_New_e){ _LL1977: _temp1976=(( struct Cyc_Absyn_New_e_struct*)
_temp1839)->f1; goto _LL1975; _LL1975: _temp1974=(( struct Cyc_Absyn_New_e_struct*)
_temp1839)->f2; goto _LL1874;} else{ goto _LL1875;} _LL1875: if(*(( int*)
_temp1839) == Cyc_Absyn_Sizeofexp_e){ _LL1979: _temp1978=(( struct Cyc_Absyn_Sizeofexp_e_struct*)
_temp1839)->f1; goto _LL1876;} else{ goto _LL1877;} _LL1877: if(*(( int*)
_temp1839) == Cyc_Absyn_Sizeoftyp_e){ _LL1981: _temp1980=( void*)(( struct Cyc_Absyn_Sizeoftyp_e_struct*)
_temp1839)->f1; goto _LL1878;} else{ goto _LL1879;} _LL1879: if(*(( int*)
_temp1839) == Cyc_Absyn_Offsetof_e){ _LL1985: _temp1984=( void*)(( struct Cyc_Absyn_Offsetof_e_struct*)
_temp1839)->f1; goto _LL1983; _LL1983: _temp1982=(( struct Cyc_Absyn_Offsetof_e_struct*)
_temp1839)->f2; goto _LL1880;} else{ goto _LL1881;} _LL1881: if(*(( int*)
_temp1839) == Cyc_Absyn_Deref_e){ _LL1987: _temp1986=(( struct Cyc_Absyn_Deref_e_struct*)
_temp1839)->f1; goto _LL1882;} else{ goto _LL1883;} _LL1883: if(*(( int*)
_temp1839) == Cyc_Absyn_StructMember_e){ _LL1991: _temp1990=(( struct Cyc_Absyn_StructMember_e_struct*)
_temp1839)->f1; goto _LL1989; _LL1989: _temp1988=(( struct Cyc_Absyn_StructMember_e_struct*)
_temp1839)->f2; goto _LL1884;} else{ goto _LL1885;} _LL1885: if(*(( int*)
_temp1839) == Cyc_Absyn_StructArrow_e){ _LL1995: _temp1994=(( struct Cyc_Absyn_StructArrow_e_struct*)
_temp1839)->f1; goto _LL1993; _LL1993: _temp1992=(( struct Cyc_Absyn_StructArrow_e_struct*)
_temp1839)->f2; goto _LL1886;} else{ goto _LL1887;} _LL1887: if(*(( int*)
_temp1839) == Cyc_Absyn_Subscript_e){ _LL1999: _temp1998=(( struct Cyc_Absyn_Subscript_e_struct*)
_temp1839)->f1; goto _LL1997; _LL1997: _temp1996=(( struct Cyc_Absyn_Subscript_e_struct*)
_temp1839)->f2; goto _LL1888;} else{ goto _LL1889;} _LL1889: if(*(( int*)
_temp1839) == Cyc_Absyn_Tuple_e){ _LL2001: _temp2000=(( struct Cyc_Absyn_Tuple_e_struct*)
_temp1839)->f1; goto _LL1890;} else{ goto _LL1891;} _LL1891: if(*(( int*)
_temp1839) == Cyc_Absyn_CompoundLit_e){ _LL2005: _temp2004=(( struct Cyc_Absyn_CompoundLit_e_struct*)
_temp1839)->f1; goto _LL2003; _LL2003: _temp2002=(( struct Cyc_Absyn_CompoundLit_e_struct*)
_temp1839)->f2; goto _LL1892;} else{ goto _LL1893;} _LL1893: if(*(( int*)
_temp1839) == Cyc_Absyn_Array_e){ _LL2007: _temp2006=(( struct Cyc_Absyn_Array_e_struct*)
_temp1839)->f1; goto _LL1894;} else{ goto _LL1895;} _LL1895: if(*(( int*)
_temp1839) == Cyc_Absyn_StmtExp_e){ _LL2009: _temp2008=(( struct Cyc_Absyn_StmtExp_e_struct*)
_temp1839)->f1; goto _LL1896;} else{ goto _LL1897;} _LL1897: if(*(( int*)
_temp1839) == Cyc_Absyn_Codegen_e){ _LL2011: _temp2010=(( struct Cyc_Absyn_Codegen_e_struct*)
_temp1839)->f1; goto _LL1898;} else{ goto _LL1899;} _LL1899: if(*(( int*)
_temp1839) == Cyc_Absyn_Fill_e){ _LL2013: _temp2012=(( struct Cyc_Absyn_Fill_e_struct*)
_temp1839)->f1; goto _LL1900;} else{ goto _LL1901;} _LL1901: if(*(( int*)
_temp1839) == Cyc_Absyn_Comprehension_e){ _LL2019: _temp2018=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1839)->f1; goto _LL2017; _LL2017: _temp2016=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1839)->f2; goto _LL2015; _LL2015: _temp2014=(( struct Cyc_Absyn_Comprehension_e_struct*)
_temp1839)->f3; goto _LL1902;} else{ goto _LL1903;} _LL1903: if(*(( int*)
_temp1839) == Cyc_Absyn_Struct_e){ _LL2029: _temp2028=(( struct Cyc_Absyn_Struct_e_struct*)
_temp1839)->f1; _temp2030=&(( struct Cyc_Absyn_Struct_e_struct*) _temp1839)->f1;
goto _LL2026; _LL2026: _temp2025=(( struct Cyc_Absyn_Struct_e_struct*) _temp1839)->f2;
_temp2027=&(( struct Cyc_Absyn_Struct_e_struct*) _temp1839)->f2; goto _LL2024;
_LL2024: _temp2023=(( struct Cyc_Absyn_Struct_e_struct*) _temp1839)->f3; goto
_LL2021; _LL2021: _temp2020=(( struct Cyc_Absyn_Struct_e_struct*) _temp1839)->f4;
_temp2022=&(( struct Cyc_Absyn_Struct_e_struct*) _temp1839)->f4; goto _LL1904;}
else{ goto _LL1905;} _LL1905: if(*(( int*) _temp1839) == Cyc_Absyn_AnonStruct_e){
_LL2034: _temp2033=( void*)(( struct Cyc_Absyn_AnonStruct_e_struct*) _temp1839)->f1;
goto _LL2032; _LL2032: _temp2031=(( struct Cyc_Absyn_AnonStruct_e_struct*)
_temp1839)->f2; goto _LL1906;} else{ goto _LL1907;} _LL1907: if(*(( int*)
_temp1839) == Cyc_Absyn_Tunion_e){ _LL2045: _temp2044=(( struct Cyc_Absyn_Tunion_e_struct*)
_temp1839)->f1; _temp2046=&(( struct Cyc_Absyn_Tunion_e_struct*) _temp1839)->f1;
goto _LL2042; _LL2042: _temp2041=(( struct Cyc_Absyn_Tunion_e_struct*) _temp1839)->f2;
_temp2043=&(( struct Cyc_Absyn_Tunion_e_struct*) _temp1839)->f2; goto _LL2040;
_LL2040: _temp2039=(( struct Cyc_Absyn_Tunion_e_struct*) _temp1839)->f3; goto
_LL2038; _LL2038: _temp2037=(( struct Cyc_Absyn_Tunion_e_struct*) _temp1839)->f4;
goto _LL2036; _LL2036: _temp2035=(( struct Cyc_Absyn_Tunion_e_struct*) _temp1839)->f5;
goto _LL1908;} else{ goto _LL1909;} _LL1909: if(*(( int*) _temp1839) == Cyc_Absyn_Enum_e){
_LL2052: _temp2051=(( struct Cyc_Absyn_Enum_e_struct*) _temp1839)->f1; _temp2053=&((
struct Cyc_Absyn_Enum_e_struct*) _temp1839)->f1; goto _LL2050; _LL2050:
_temp2049=(( struct Cyc_Absyn_Enum_e_struct*) _temp1839)->f2; goto _LL2048;
_LL2048: _temp2047=(( struct Cyc_Absyn_Enum_e_struct*) _temp1839)->f3; goto
_LL1910;} else{ goto _LL1911;} _LL1911: if(*(( int*) _temp1839) == Cyc_Absyn_Malloc_e){
_LL2057: _temp2056=(( struct Cyc_Absyn_Malloc_e_struct*) _temp1839)->f1; goto
_LL2055; _LL2055: _temp2054=( void*)(( struct Cyc_Absyn_Malloc_e_struct*)
_temp1839)->f2; goto _LL1912;} else{ goto _LL1840;} _LL1842: Cyc_Tcexp_tcExpNoInst(
te, 0, _temp1913); return; _LL1844: Cyc_Tcexp_resolve_unknown_id( te, e,
_temp1915); Cyc_Tcexp_tcExpNoInst( te, topt, e); return; _LL1846: Cyc_Tcexp_resolve_unknown_fn(
te, e, _temp1919, _temp1917); Cyc_Tcexp_tcExpNoInst( te, topt, e); return;
_LL1848: Cyc_Tcexp_resolve_unresolved_mem( te, loc, topt, e, _temp1921); Cyc_Tcexp_tcExpNoInst(
te, topt, e); return; _LL1850: t= Cyc_Tcexp_tcConst( te, loc, topt, _temp1925, e);
goto _LL1840; _LL1852: t= Cyc_Tcexp_tcVar( te, loc, _temp1929, _temp1927); goto
_LL1840; _LL1854: t= Cyc_Tcexp_tcPrimop( te, loc, topt, _temp1933, _temp1931);
goto _LL1840; _LL1856: t= Cyc_Tcexp_tcIncrement( te, loc, topt, _temp1937,
_temp1935); goto _LL1840; _LL1858: t= Cyc_Tcexp_tcAssignOp( te, loc, topt,
_temp1943, _temp1941, _temp1939); goto _LL1840; _LL1860: t= Cyc_Tcexp_tcConditional(
te, loc, topt, _temp1949, _temp1947, _temp1945); goto _LL1840; _LL1862: t= Cyc_Tcexp_tcSeqExp(
te, loc, topt, _temp1953, _temp1951); goto _LL1840; _LL1864: t= Cyc_Tcexp_tcFnCall(
te, loc, topt, _temp1960, _temp1958, _temp1957); goto _LL1840; _LL1866: t= Cyc_Tcexp_tcThrow(
te, loc, topt, _temp1962); goto _LL1840; _LL1868: t= Cyc_Tcexp_tcInstantiate( te,
loc, topt, _temp1966, _temp1964); goto _LL1840; _LL1870: t= Cyc_Tcexp_tcCast( te,
loc, topt, _temp1970, _temp1968); goto _LL1840; _LL1872: t= Cyc_Tcexp_tcAddress(
te, loc, topt, _temp1972); goto _LL1840; _LL1874: t= Cyc_Tcexp_tcNew( te, loc,
topt, _temp1976, e, _temp1974); goto _LL1840; _LL1876: { void* _temp2058= Cyc_Tcexp_tcExpNoPromote(
te, 0, _temp1978); goto _LL2059; _LL2059: t= Cyc_Tcexp_tcSizeof( te, loc, topt,
_temp2058); goto _LL1840;} _LL1878: t= Cyc_Tcexp_tcSizeof( te, loc, topt,
_temp1980); goto _LL1840; _LL1880: t= Cyc_Tcexp_tcOffsetof( te, loc, topt,
_temp1984, _temp1982); goto _LL1840; _LL1882: t= Cyc_Tcexp_tcDeref( te, loc,
topt, _temp1986); goto _LL1840; _LL1884: t= Cyc_Tcexp_tcStructMember( te, loc,
topt, e, _temp1990, _temp1988); goto _LL1840; _LL1886: t= Cyc_Tcexp_tcStructArrow(
te, loc, topt, _temp1994, _temp1992); goto _LL1840; _LL1888: t= Cyc_Tcexp_tcSubscript(
te, loc, topt, _temp1998, _temp1996); goto _LL1840; _LL1890: t= Cyc_Tcexp_tcTuple(
te, loc, topt, _temp2000); goto _LL1840; _LL1892: t= Cyc_Tcexp_tcCompoundLit( te,
loc, topt, _temp2004, _temp2002); goto _LL1840; _LL1894: { void** elt_topt= 0;
if( topt != 0){ void* _temp2060= Cyc_Tcutil_compress(*(( void**) _check_null(
topt))); struct Cyc_Absyn_Exp* _temp2066; struct Cyc_Absyn_Tqual _temp2068; void*
_temp2070; void** _temp2072; _LL2062: if(( unsigned int) _temp2060 > 4u?*(( int*)
_temp2060) == Cyc_Absyn_ArrayType: 0){ _LL2071: _temp2070=( void*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp2060)->f1; _temp2072=&(( void*)(( struct Cyc_Absyn_ArrayType_struct*)
_temp2060)->f1); goto _LL2069; _LL2069: _temp2068=(( struct Cyc_Absyn_ArrayType_struct*)
_temp2060)->f2; goto _LL2067; _LL2067: _temp2066=(( struct Cyc_Absyn_ArrayType_struct*)
_temp2060)->f3; goto _LL2063;} else{ goto _LL2064;} _LL2064: goto _LL2065;
_LL2063: elt_topt=( void**) _temp2072; goto _LL2061; _LL2065: goto _LL2061;
_LL2061:;} t= Cyc_Tcexp_tcArray( te, loc, elt_topt, _temp2006); goto _LL1840;}
_LL1896: t= Cyc_Tcexp_tcStmtExp( te, loc, topt, _temp2008); goto _LL1840;
_LL1898: t= Cyc_Tcexp_tcCodegen( te, loc, topt, _temp2010); goto _LL1840;
_LL1900: t= Cyc_Tcexp_tcFill( te, loc, topt, _temp2012); goto _LL1840; _LL1902:
t= Cyc_Tcexp_tcComprehension( te, loc, topt, _temp2018, _temp2016, _temp2014);
goto _LL1840; _LL1904: t= Cyc_Tcexp_tcStruct( te, loc, topt, _temp2030,
_temp2027, _temp2023, _temp2022); goto _LL1840; _LL1906: t= Cyc_Tcexp_tcAnonStruct(
te, loc, _temp2033, _temp2031); goto _LL1840; _LL1908: t= Cyc_Tcexp_tcTunion( te,
loc, topt, e, _temp2046, _temp2043, _temp2039, _temp2037, _temp2035); goto
_LL1840; _LL1910:* _temp2053=(( struct Cyc_Absyn_Enumfield*) _check_null(
_temp2047))->name; t=( void*)({ struct Cyc_Absyn_EnumType_struct* _temp2073=(
struct Cyc_Absyn_EnumType_struct*) GC_malloc( sizeof( struct Cyc_Absyn_EnumType_struct));
_temp2073[ 0]=({ struct Cyc_Absyn_EnumType_struct _temp2074; _temp2074.tag= Cyc_Absyn_EnumType;
_temp2074.f1=(( struct Cyc_Absyn_Enumdecl*) _check_null( _temp2049))->name;
_temp2074.f2= _temp2049; _temp2074;}); _temp2073;}); goto _LL1840; _LL1912: t=
Cyc_Tcexp_tcMalloc( te, loc, topt, _temp2056, _temp2054); goto _LL1840; _LL1840:;}
e->topt=({ struct Cyc_Core_Opt* _temp2075=( struct Cyc_Core_Opt*) GC_malloc(
sizeof( struct Cyc_Core_Opt)); _temp2075->v=( void*) t; _temp2075;});}