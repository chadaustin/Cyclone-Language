#include "cyc_include.h"

 struct _tuple0{ int f1; struct Cyc_Lineno_Pos* f2; } ; struct _tuple1{ struct
_tagged_string f1; int f2; int f3; } ; typedef int Cyc_ptrdiff_t; typedef
unsigned int Cyc_size_t; typedef unsigned short Cyc_wchar_t; typedef
unsigned int Cyc_wint_t; typedef char Cyc_u_char; typedef unsigned short Cyc_u_short;
typedef unsigned int Cyc_u_int; typedef unsigned int Cyc_u_long; typedef
unsigned short Cyc_ushort; typedef unsigned int Cyc_uint; typedef unsigned int
Cyc_clock_t; typedef int Cyc_time_t; struct Cyc_timespec{ int tv_sec; int
tv_nsec; } ; struct Cyc_itimerspec{ struct Cyc_timespec it_interval; struct Cyc_timespec
it_value; } ; typedef int Cyc_daddr_t; typedef char* Cyc_caddr_t; typedef
unsigned int Cyc_ino_t; typedef unsigned int Cyc_vm_offset_t; typedef
unsigned int Cyc_vm_size_t; typedef char Cyc_int8_t; typedef char Cyc_u_int8_t;
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
struct Cyc_Core_Opt* Cyc_Core_opt_t; extern struct _tagged_string Cyc_Core_new_string(
int); extern char Cyc_Core_InvalidArg_tag[ 11u]; struct Cyc_Core_InvalidArg_struct{
char* tag; struct _tagged_string f1; } ; extern char Cyc_Core_Failure_tag[ 8u];
struct Cyc_Core_Failure_struct{ char* tag; struct _tagged_string f1; } ; extern
char Cyc_Core_Impossible_tag[ 11u]; struct Cyc_Core_Impossible_struct{ char* tag;
struct _tagged_string f1; } ; extern char Cyc_Core_Not_found_tag[ 10u]; struct
Cyc_Core_Not_found_struct{ char* tag; } ; extern char Cyc_Core_Unreachable_tag[
12u]; struct Cyc_Core_Unreachable_struct{ char* tag; struct _tagged_string f1; }
; extern char* string_to_Cstring( struct _tagged_string); extern char*
underlying_Cstring( struct _tagged_string); extern struct _tagged_string
Cstring_to_string( char*); extern int system( char*); struct Cyc_List_List{ void*
hd; struct Cyc_List_List* tl; } ; typedef struct Cyc_List_List* Cyc_List_glist_t;
typedef struct Cyc_List_List* Cyc_List_list_t; typedef struct Cyc_List_List* Cyc_List_List_t;
extern char Cyc_List_List_empty_tag[ 11u]; struct Cyc_List_List_empty_struct{
char* tag; } ; extern char Cyc_List_List_mismatch_tag[ 14u]; struct Cyc_List_List_mismatch_struct{
char* tag; } ; extern struct Cyc_List_List* Cyc_List_imp_rev( struct Cyc_List_List*
x); extern char Cyc_List_Nth_tag[ 4u]; struct Cyc_List_Nth_struct{ char* tag; }
; struct Cyc_Stdio___sFILE; typedef struct Cyc_Stdio___sFILE Cyc_Stdio_FILE;
extern struct Cyc_Stdio___sFILE* Cyc_Stdio_stdout; extern struct Cyc_Stdio___sFILE*
Cyc_Stdio_stderr; typedef int Cyc_Stdio_fpos_t; extern int Cyc_Stdio_fflush(
struct Cyc_Stdio___sFILE*); extern char Cyc_Stdio_FileOpenError_tag[ 14u];
struct Cyc_Stdio_FileOpenError_struct{ char* tag; struct _tagged_string f1; } ;
extern char Cyc_Stdio_FileCloseError_tag[ 15u]; struct Cyc_Stdio_FileCloseError_struct{
char* tag; } ; struct Cyc_Lineno_Pos{ struct _tagged_string logical_file; struct
_tagged_string line; int line_no; int col; } ; typedef struct Cyc_Lineno_Pos*
Cyc_Lineno_pos_t; extern struct Cyc_Lineno_Pos* Cyc_Lineno_pos_of_abs( struct
_tagged_string, int); extern void Cyc_Lineno_poss_of_abss( struct _tagged_string
filename, struct Cyc_List_List* places); extern char Cyc_Position_Exit_tag[ 5u];
struct Cyc_Position_Exit_struct{ char* tag; } ; extern void Cyc_Position_reset_position(
struct _tagged_string); extern void Cyc_Position_set_position_file( struct
_tagged_string); extern struct _tagged_string Cyc_Position_get_position_file();
struct Cyc_Position_Segment; typedef struct Cyc_Position_Segment* Cyc_Position_seg_t;
extern struct Cyc_Position_Segment* Cyc_Position_segment_of_abs( int, int);
extern struct Cyc_Position_Segment* Cyc_Position_segment_join( struct Cyc_Position_Segment*,
struct Cyc_Position_Segment*); extern struct _tagged_string Cyc_Position_string_of_loc(
int); extern struct _tagged_string Cyc_Position_string_of_segment( struct Cyc_Position_Segment*);
extern struct Cyc_List_List* Cyc_Position_strings_of_segments( struct Cyc_List_List*);
typedef void* Cyc_Position_Error_kind; static const unsigned int Cyc_Position_Lex=
0; static const unsigned int Cyc_Position_Parse= 1; static const unsigned int
Cyc_Position_Elab= 2; typedef void* Cyc_Position_error_kind_t; struct Cyc_Position_Error{
struct _tagged_string source; struct Cyc_Position_Segment* seg; void* kind;
struct _tagged_string desc; } ; typedef struct Cyc_Position_Error* Cyc_Position_error_t;
extern struct Cyc_Position_Error* Cyc_Position_mk_err_lex( struct Cyc_Position_Segment*,
struct _tagged_string); extern struct Cyc_Position_Error* Cyc_Position_mk_err_parse(
struct Cyc_Position_Segment*, struct _tagged_string); extern struct Cyc_Position_Error*
Cyc_Position_mk_err_elab( struct Cyc_Position_Segment*, struct _tagged_string);
extern char Cyc_Position_Nocontext_tag[ 10u]; struct Cyc_Position_Nocontext_struct{
char* tag; } ; extern int Cyc_Position_print_context; extern void Cyc_Position_post_error(
struct Cyc_Position_Error*); extern int Cyc_Position_error_p(); extern
unsigned int Cyc_String_strlen( struct _tagged_string s); extern int Cyc_String_strcmp(
struct _tagged_string s1, struct _tagged_string s2); extern struct
_tagged_string Cyc_String_strncpy( struct _tagged_string, int, struct
_tagged_string, int, unsigned int); extern struct _tagged_string Cyc_String_substring(
struct _tagged_string, int ofs, unsigned int n); char Cyc_Position_Exit_tag[ 5u]="Exit";
static char _temp2[ 1u]=""; static struct _tagged_string Cyc_Position_source=(
struct _tagged_string){ _temp2, _temp2, _temp2 + 1u}; struct Cyc_Position_Segment{
int start; int end; } ; struct Cyc_Position_Segment* Cyc_Position_segment_of_abs(
int start, int end){ return({ struct Cyc_Position_Segment* _temp3=( struct Cyc_Position_Segment*)
GC_malloc( sizeof( struct Cyc_Position_Segment) * 1); _temp3[ 0]=({ struct Cyc_Position_Segment
_temp4; _temp4.start= start; _temp4.end= end; _temp4;}); _temp3;});} struct Cyc_Position_Segment*
Cyc_Position_segment_join( struct Cyc_Position_Segment* s1, struct Cyc_Position_Segment*
s2){ if( s1 == 0){ return s2;} if( s2 == 0){ return s1;} return({ struct Cyc_Position_Segment*
_temp5=( struct Cyc_Position_Segment*) GC_malloc( sizeof( struct Cyc_Position_Segment)
* 1); _temp5[ 0]=({ struct Cyc_Position_Segment _temp6; _temp6.start= s1->start;
_temp6.end= s2->end; _temp6;}); _temp5;});} struct _tagged_string Cyc_Position_string_of_loc(
int loc){ struct Cyc_Lineno_Pos* pos= Cyc_Lineno_pos_of_abs( Cyc_Position_source,
loc); return({ struct _tagged_string _temp7= pos->logical_file; int _temp8= pos->line_no;
int _temp9= pos->col; xprintf("%.*s (%d:%d)", _temp7.last_plus_one - _temp7.curr,
_temp7.curr, _temp8, _temp9);});} static struct _tagged_string Cyc_Position_string_of_pos_pr(
struct Cyc_Lineno_Pos* pos_s, struct Cyc_Lineno_Pos* pos_e){ if( Cyc_String_strcmp(
pos_s->logical_file, pos_e->logical_file) == 0){ return({ struct _tagged_string
_temp10= pos_s->logical_file; int _temp11= pos_s->line_no; int _temp12= pos_s->col;
int _temp13= pos_e->line_no; int _temp14= pos_e->col; xprintf("%.*s(%d:%d-%d:%d)",
_temp10.last_plus_one - _temp10.curr, _temp10.curr, _temp11, _temp12, _temp13,
_temp14);});} else{ return({ struct _tagged_string _temp15= pos_s->logical_file;
int _temp16= pos_s->line_no; int _temp17= pos_s->col; struct _tagged_string
_temp18= pos_e->logical_file; int _temp19= pos_e->line_no; int _temp20= pos_e->col;
xprintf("%.*s(%d:%d)-%.*s(%d:%d)", _temp15.last_plus_one - _temp15.curr, _temp15.curr,
_temp16, _temp17, _temp18.last_plus_one - _temp18.curr, _temp18.curr, _temp19,
_temp20);});}} struct _tagged_string Cyc_Position_string_of_segment( struct Cyc_Position_Segment*
s){ if( s == 0){ return({ struct _tagged_string _temp21= Cyc_Position_source;
xprintf("%.*s(unknown)", _temp21.last_plus_one - _temp21.curr, _temp21.curr);});}{
struct Cyc_Lineno_Pos* pos_s= Cyc_Lineno_pos_of_abs( Cyc_Position_source, s->start);
struct Cyc_Lineno_Pos* pos_e= Cyc_Lineno_pos_of_abs( Cyc_Position_source, s->end);
return Cyc_Position_string_of_pos_pr( pos_s, pos_e);}} static struct Cyc_Lineno_Pos*
Cyc_Position_new_pos(){ return({ struct Cyc_Lineno_Pos* _temp22=( struct Cyc_Lineno_Pos*)
GC_malloc( sizeof( struct Cyc_Lineno_Pos) * 1); _temp22[ 0]=({ struct Cyc_Lineno_Pos
_temp23; _temp23.logical_file=( struct _tagged_string)({ char* _temp26=( char*)"";
struct _tagged_string _temp27; _temp27.curr= _temp26; _temp27.base= _temp26;
_temp27.last_plus_one= _temp26 + 1; _temp27;}); _temp23.line=( struct
_tagged_string)({ char* _temp24=( char*)""; struct _tagged_string _temp25;
_temp25.curr= _temp24; _temp25.base= _temp24; _temp25.last_plus_one= _temp24 + 1;
_temp25;}); _temp23.line_no= 0; _temp23.col= 0; _temp23;}); _temp22;});} struct
Cyc_List_List* Cyc_Position_strings_of_segments( struct Cyc_List_List* segs){
struct Cyc_List_List* places= 0;{ struct Cyc_List_List* segs2= segs; for( 0;
segs2 != 0; segs2= segs2->tl){ if(( struct Cyc_Position_Segment*) segs2->hd == 0){
continue;} places=({ struct Cyc_List_List* _temp28=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp28->hd=( void*)({ struct _tuple0*
_temp31=( struct _tuple0*) GC_malloc( sizeof( struct _tuple0)); _temp31->f1=((
struct Cyc_Position_Segment*) segs2->hd)->end; _temp31->f2= Cyc_Position_new_pos();
_temp31;}); _temp28->tl=({ struct Cyc_List_List* _temp29=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp29->hd=( void*)({ struct _tuple0*
_temp30=( struct _tuple0*) GC_malloc( sizeof( struct _tuple0)); _temp30->f1=((
struct Cyc_Position_Segment*) segs2->hd)->start; _temp30->f2= Cyc_Position_new_pos();
_temp30;}); _temp29->tl= places; _temp29;}); _temp28;});}} Cyc_Lineno_poss_of_abss(
Cyc_Position_source, places);{ struct Cyc_List_List* ans= 0; places=(( struct
Cyc_List_List*(*)( struct Cyc_List_List* x)) Cyc_List_imp_rev)( places); for( 0;
segs != 0; segs= segs->tl){ if(( struct Cyc_Position_Segment*) segs->hd == 0){
ans=({ struct Cyc_List_List* _temp32=( struct Cyc_List_List*) GC_malloc( sizeof(
struct Cyc_List_List)); _temp32->hd=( void*)({ struct _tagged_string* _temp33=(
struct _tagged_string*) GC_malloc( sizeof( struct _tagged_string) * 1); _temp33[
0]=({ struct _tagged_string _temp34= Cyc_Position_source; xprintf("%.*s(unknown)",
_temp34.last_plus_one - _temp34.curr, _temp34.curr);}); _temp33;}); _temp32->tl=
ans; _temp32;});} else{ ans=({ struct Cyc_List_List* _temp35=( struct Cyc_List_List*)
GC_malloc( sizeof( struct Cyc_List_List)); _temp35->hd=( void*)({ struct
_tagged_string* _temp36=( struct _tagged_string*) GC_malloc( sizeof( struct
_tagged_string) * 1); _temp36[ 0]= Cyc_Position_string_of_pos_pr((*(( struct
_tuple0*) places->hd)).f2,(*(( struct _tuple0*)( places->tl)->hd)).f2); _temp36;});
_temp35->tl= ans; _temp35;}); places=( places->tl)->tl;}} return ans;}} struct
Cyc_Position_Error; struct Cyc_Position_Error* Cyc_Position_mk_err_lex( struct
Cyc_Position_Segment* l, struct _tagged_string desc){ return({ struct Cyc_Position_Error*
_temp37=( struct Cyc_Position_Error*) GC_malloc( sizeof( struct Cyc_Position_Error));
_temp37->source= Cyc_Position_source; _temp37->seg= l; _temp37->kind=( void*)((
void*) Cyc_Position_Lex); _temp37->desc= desc; _temp37;});} struct Cyc_Position_Error*
Cyc_Position_mk_err_parse( struct Cyc_Position_Segment* l, struct _tagged_string
desc){ return({ struct Cyc_Position_Error* _temp38=( struct Cyc_Position_Error*)
GC_malloc( sizeof( struct Cyc_Position_Error)); _temp38->source= Cyc_Position_source;
_temp38->seg= l; _temp38->kind=( void*)(( void*) Cyc_Position_Parse); _temp38->desc=
desc; _temp38;});} struct Cyc_Position_Error* Cyc_Position_mk_err_elab( struct
Cyc_Position_Segment* l, struct _tagged_string desc){ return({ struct Cyc_Position_Error*
_temp39=( struct Cyc_Position_Error*) GC_malloc( sizeof( struct Cyc_Position_Error));
_temp39->source= Cyc_Position_source; _temp39->seg= l; _temp39->kind=( void*)((
void*) Cyc_Position_Elab); _temp39->desc= desc; _temp39;});} char Cyc_Position_Nocontext_tag[
10u]="Nocontext"; static struct _tagged_string Cyc_Position_trunc( int n, struct
_tagged_string s){ int len=( int) Cyc_String_strlen( s); if( len < n){ return s;}{
int len_one=( n - 3) / 2; int len_two=( n - 3) - len_one; struct _tagged_string
ans= Cyc_Core_new_string( n + 1); Cyc_String_strncpy( ans, 0, s, 0,(
unsigned int) len_one); Cyc_String_strncpy( ans, len_one,( struct _tagged_string)({
char* _temp40=( char*)"..."; struct _tagged_string _temp41; _temp41.curr=
_temp40; _temp41.base= _temp40; _temp41.last_plus_one= _temp40 + 4; _temp41;}),
0,( unsigned int) 3); Cyc_String_strncpy( ans, len_one + 3, s, len - len_two,(
unsigned int) len_two); return ans;}} static int Cyc_Position_line_length= 76;
static struct _tuple1* Cyc_Position_get_context( struct Cyc_Position_Segment*
seg){ if( seg == 0){( void) _throw(( struct _xtunion_struct*)({ struct Cyc_Position_Nocontext_struct*
_temp42=( struct Cyc_Position_Nocontext_struct*) GC_malloc( sizeof( struct Cyc_Position_Nocontext_struct));
_temp42[ 0]=({ struct Cyc_Position_Nocontext_struct _temp43; _temp43.tag= Cyc_Position_Nocontext_tag;
_temp43;}); _temp42;}));}{ struct Cyc_Lineno_Pos* pos_s; struct Cyc_Lineno_Pos*
pos_e;{ struct _handler_cons _temp44; _push_handler(& _temp44);{ struct
_xtunion_struct* _temp45=( struct _xtunion_struct*) setjmp( _temp44.handler);
if( ! _temp45){ pos_s= Cyc_Lineno_pos_of_abs( Cyc_Position_source, seg->start);
pos_e= Cyc_Lineno_pos_of_abs( Cyc_Position_source, seg->end);; _pop_handler();}
else{ struct _xtunion_struct* _temp47= _temp45; _LL49: goto _LL50; _LL51: goto
_LL52; _LL50:( void) _throw(( struct _xtunion_struct*)({ struct Cyc_Position_Nocontext_struct*
_temp53=( struct Cyc_Position_Nocontext_struct*) GC_malloc( sizeof( struct Cyc_Position_Nocontext_struct));
_temp53[ 0]=({ struct Cyc_Position_Nocontext_struct _temp54; _temp54.tag= Cyc_Position_Nocontext_tag;
_temp54;}); _temp53;})); _LL52:( void) _throw( _temp47); _LL48:;}}}{ struct Cyc_Lineno_Pos
_temp57; int _temp58; int _temp60; struct _tagged_string _temp62; struct
_tagged_string _temp64; struct Cyc_Lineno_Pos* _temp55= pos_s; _temp57=* _temp55;
_LL65: _temp64=( struct _tagged_string) _temp57.logical_file; goto _LL63; _LL63:
_temp62=( struct _tagged_string) _temp57.line; goto _LL61; _LL61: _temp60=( int)
_temp57.line_no; goto _LL59; _LL59: _temp58=( int) _temp57.col; goto _LL56;
_LL56: { struct Cyc_Lineno_Pos _temp68; int _temp69; int _temp71; struct
_tagged_string _temp73; struct _tagged_string _temp75; struct Cyc_Lineno_Pos*
_temp66= pos_e; _temp68=* _temp66; _LL76: _temp75=( struct _tagged_string)
_temp68.logical_file; goto _LL74; _LL74: _temp73=( struct _tagged_string)
_temp68.line; goto _LL72; _LL72: _temp71=( int) _temp68.line_no; goto _LL70;
_LL70: _temp69=( int) _temp68.col; goto _LL67; _LL67: if( _temp60 == _temp71){
int n= Cyc_Position_line_length / 3; struct _tagged_string sec_one= Cyc_Position_trunc(
n, Cyc_String_substring( _temp62, 0,( unsigned int) _temp58)); struct
_tagged_string sec_two= Cyc_Position_trunc( n, Cyc_String_substring( _temp62,
_temp58,( unsigned int)( _temp69 - _temp58))); struct _tagged_string sec_three=
Cyc_Position_trunc( n, Cyc_String_substring( _temp62, _temp58, Cyc_String_strlen(
_temp62) -( unsigned int) _temp69)); return({ struct _tuple1* _temp77=( struct
_tuple1*) GC_malloc( sizeof( struct _tuple1)); _temp77->f1=({ struct
_tagged_string _temp78= sec_one; struct _tagged_string _temp79= sec_two; struct
_tagged_string _temp80= sec_three; xprintf("%.*s%.*s%.*s", _temp78.last_plus_one
- _temp78.curr, _temp78.curr, _temp79.last_plus_one - _temp79.curr, _temp79.curr,
_temp80.last_plus_one - _temp80.curr, _temp80.curr);}); _temp77->f2=( int) Cyc_String_strlen(
sec_one); _temp77->f3=( int)( Cyc_String_strlen( sec_one) + Cyc_String_strlen(
sec_two)); _temp77;});} else{ int n=( Cyc_Position_line_length - 3) / 4; struct
_tagged_string sec_one= Cyc_Position_trunc( n, Cyc_String_substring( _temp62, 0,(
unsigned int) _temp58)); struct _tagged_string sec_two= Cyc_Position_trunc( n,
Cyc_String_substring( _temp62, _temp58, Cyc_String_strlen( _temp62) -(
unsigned int) _temp58)); struct _tagged_string sec_three= Cyc_Position_trunc( n,
Cyc_String_substring( _temp73, 0,( unsigned int) _temp69)); struct
_tagged_string sec_four= Cyc_Position_trunc( n, Cyc_String_substring( _temp73,
_temp69, Cyc_String_strlen( _temp73) -( unsigned int) _temp69)); return({ struct
_tuple1* _temp81=( struct _tuple1*) GC_malloc( sizeof( struct _tuple1)); _temp81->f1=({
struct _tagged_string _temp82= sec_one; struct _tagged_string _temp83= sec_two;
struct _tagged_string _temp84= sec_three; struct _tagged_string _temp85=
sec_four; xprintf("%.*s%.*s.\\.%.*s%.*s", _temp82.last_plus_one - _temp82.curr,
_temp82.curr, _temp83.last_plus_one - _temp83.curr, _temp83.curr, _temp84.last_plus_one
- _temp84.curr, _temp84.curr, _temp85.last_plus_one - _temp85.curr, _temp85.curr);});
_temp81->f2=( int) Cyc_String_strlen( sec_one); _temp81->f3=( int)((( Cyc_String_strlen(
sec_one) + Cyc_String_strlen( sec_two)) +( unsigned int) 3) + Cyc_String_strlen(
sec_three)); _temp81;});}}}}} static int Cyc_Position_error_b= 0; int Cyc_Position_error_p(){
return Cyc_Position_error_b;} char Cyc_Position_Error_tag[ 6u]="Error"; struct
Cyc_Position_Error_struct{ char* tag; struct Cyc_Position_Error* f1; } ; int Cyc_Position_print_context=
0; int Cyc_Position_first_error= 1; void Cyc_Position_post_error( struct Cyc_Position_Error*
e){ Cyc_Position_error_b= 1; Cyc_Stdio_fflush(( struct Cyc_Stdio___sFILE*) Cyc_Stdio_stdout);
if( Cyc_Position_first_error){ fprintf( Cyc_Stdio_stderr,"\n"); Cyc_Position_first_error=
0;}({ struct _tagged_string _temp86= Cyc_Position_string_of_segment( e->seg);
struct _tagged_string _temp87= e->desc; fprintf( Cyc_Stdio_stderr,"%.*s: %.*s\n",
_temp86.last_plus_one - _temp86.curr, _temp86.curr, _temp87.last_plus_one -
_temp87.curr, _temp87.curr);}); if( Cyc_Position_print_context){ struct
_handler_cons _temp88; _push_handler(& _temp88);{ struct _xtunion_struct*
_temp89=( struct _xtunion_struct*) setjmp( _temp88.handler); if( ! _temp89){{
struct _tuple1* x= Cyc_Position_get_context( e->seg); struct _tagged_string
marker_str=({ unsigned int _temp90=( unsigned int)((* x).f3 + 1); char* _temp91=(
char*) GC_malloc_atomic( sizeof( char) * _temp90); unsigned int i; struct
_tagged_string _temp92={ _temp91, _temp91, _temp91 + _temp90}; for( i= 0; i <
_temp90; i ++){ _temp91[ i]='\000';} _temp92;}); int i= - 1; while(( ++ i) <(* x).f2) {({
struct _tagged_string _temp93= marker_str; char* _temp95= _temp93.curr + i; if(
_temp95 < _temp93.base? 1: _temp95 >= _temp93.last_plus_one){ _throw(
Null_Exception);}* _temp95=' ';});} while(( ++ i) <(* x).f3) {({ struct
_tagged_string _temp96= marker_str; char* _temp98= _temp96.curr + i; if( _temp98
< _temp96.base? 1: _temp98 >= _temp96.last_plus_one){ _throw( Null_Exception);}*
_temp98='^';});}({ struct _tagged_string _temp99=(* x).f1; struct _tagged_string
_temp100= marker_str; fprintf( Cyc_Stdio_stderr,"  %.*s\n  %.*s\n", _temp99.last_plus_one
- _temp99.curr, _temp99.curr, _temp100.last_plus_one - _temp100.curr, _temp100.curr);});};
_pop_handler();} else{ struct _xtunion_struct* _temp102= _temp89; _LL104: if(
_temp102->tag == Cyc_Position_Nocontext_tag){ goto _LL105;} else{ goto _LL106;}
_LL106: goto _LL107; _LL105: goto _LL103; _LL107:( void) _throw( _temp102);
_LL103:;}}} Cyc_Stdio_fflush(( struct Cyc_Stdio___sFILE*) Cyc_Stdio_stderr);}
void Cyc_Position_reset_position( struct _tagged_string s){ Cyc_Position_source=
s; Cyc_Position_error_b= 0;} void Cyc_Position_set_position_file( struct
_tagged_string s){ Cyc_Position_source= s; Cyc_Position_error_b= 0;} struct
_tagged_string Cyc_Position_get_position_file(){ return Cyc_Position_source;}