/* Copyright (C) 2005 Greg Morrisett, AT&T.
   This file is part of the Cyclone project.

   Cyclone is free software; you can redistribute it
   and/or modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   Cyclone is distributed in the hope that it will be
   useful, but WITHOUT ANY WARRANTY; without even the implied warranty
   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Cyclone; see the file COPYING. If not,
   write to the Free Software Foundation, Inc., 59 Temple Place -
   Suite 330, Boston, MA 02111-1307, USA. */

#ifndef BNF_H
#define BNF_H
#include <core.h>
#include <hashtable.h>
#include <graph.h>
#include "util.h"
#include "cs.h"

datatype Repeat {
  Num(unsigned int);
  Infinity;
};
typedef datatype Repeat @repeat_t;
typedef struct arule @rule_t;
typedef struct arule *Rule_t;
datatype Rule {
  Symb(const char ?,const char ?); // grammar symbol, params
  Lit(const char ?);
  CharRange(unsigned int,unsigned int); // closed interval [l,u]
  Prose(const char ?);
  Opt(rule_t);
  Seq(rule_t,rule_t);
  Alt(rule_t,rule_t);
  Rcount(const char ?,rule_t);
  Star(unsigned int,repeat_t,rule_t);
  Hash(unsigned int,repeat_t,rule_t);
  Minus(rule_t,rule_t);
};

extern cs_opt_t @not_cs; // a pointer to NULL

struct arule {
  const char ?a;    // action, possibly NULL
  const char ?p;    // predicate, possibly NULL
  const char ?v;    // value id, possibly NULL
  cs_opt_t *css;    // NULL if cs_status hasn't been determined
  datatype Rule @r; // rule
};
/* construct an arule with all properties set to NULL. */
rule_t arule_inj(datatype Rule @`H);

/* Constructors with NULL properties */
rule_t SYMB(const char ?`H);
rule_t LIT(const char ?`H);
rule_t CHARRANGE(unsigned int,unsigned int); // closed interval
rule_t PROSE(const char ?`H);
rule_t OPT(rule_t);
rule_t SEQ(... rule_t);
rule_t ALT(... rule_t);
rule_t RCOUNT(const char ?`H,rule_t);
rule_t STAR(unsigned int,repeat_t,rule_t);
rule_t HASH(unsigned int,repeat_t,rule_t);
rule_t MINUS(rule_t,rule_t);
/* Constructors that copy all of the properties of the first argument */
rule_t SYMB_r(rule_t,const char ?`H,const char ?`H);
rule_t LIT_r(rule_t,const char ?`H);
rule_t CHARRANGE_r(rule_t,unsigned int,unsigned int); // closed interval
rule_t PROSE_r(rule_t,const char ?`H);
rule_t OPT_r(rule_t,rule_t);
rule_t SEQ_r(rule_t,rule_t,rule_t);
rule_t ALT_r(rule_t,rule_t,rule_t);
rule_t RCOUNT_r(rule_t,const char ?`H,rule_t);
rule_t STAR_r(rule_t,unsigned int,repeat_t,rule_t);
rule_t HASH_r(rule_t,unsigned int,repeat_t,rule_t);
rule_t MINUS_r(rule_t,rule_t,rule_t);

extern int lower_prec(rule_t r1, rule_t r2);
struct Attr { int ws; int re; const char ?paramtype; const char ?rettype; };
typedef struct Attr attr_t;
typedef $(const char ?,rule_t,attr_t) @definition_t;
typedef List::list_t<definition_t,`r> grammar_t<`r>;
extern int do_ws(definition_t d);
extern int do_re(definition_t d);
extern strset_t freevars_rule(rule_t r);
extern strset_t freevars(grammar_t ds);
extern void report_undefined(grammar_t ds);
extern void report_multiple(grammar_t ds);
extern strgraph_t dependency_graph(grammar_t ds);
extern grammar_t sort_definitions(grammar_t ds);
extern grammar_t sort_definitions_by_name(grammar_t ds);
extern grammar_t isort_definitions_by_name(grammar_t ds); // case insensitive
extern int rule_cmp(rule_t r1, rule_t r2);
extern int eq_definitions(grammar_t ds1,grammar_t ds2);
extern grammar_t remove_duplicates(grammar_t ds);
extern repeat_t minus_one(repeat_t);
extern int repeat_zero(repeat_t);
extern grammar_t get_reachable(grammar_t<`H> ds, List::list_t<const char ?@> roots);
extern grammar_t close_definitions(grammar_t<`H> ds, List::list_t<grammar_t<`H>> e);
extern Rule_t lookup_symbol(grammar_t grm, string_t sym);
/** returns NULL if symbol cannot be found. */
extern attr_t *lookup_symbol_attr(grammar_t grm, string_t sym);
/** returns NULL if symbol cannot be found. */

extern bool is_symb(rule_t r);
/**
   Indicate whether [r] is a symbol.
 */

extern List::list_t<rule_t> alt2rules(rule_t r);

extern List::List_t<rule_t> seq2rules(rule_t r);
/** Turn a rule into a list of the rule sequence. 
   If [r] is not a sequence, will return a singleton list of [r].
   Guaranteed to contain at least one element.

   N.B. Will strip any attributes off of nested sequences.
 */

extern rule_t rules2seq(List::List_t<rule_t> rules);
/** Turn a list of rules into a sequence.*/

extern List::List_t<rule_t> depseq2rules(rule_t r);
/** Turn a rule into a list of the rule sequence. 
   If [r] is not a sequence, will return a singleton list of [r].
   Guaranteed to contain at least one element.

   *Treats nested sequences with v attributes differently.*
 */
extern rule_t commas();
// encode a hash rule as a star.
extern rule_t hash2star(unsigned int,repeat_t,rule_t);

typedef struct Hashtable::Table<const char ?@,cs_t,`H> @cs_table_t;
typedef struct Hashtable::Table<const char ?@,cs_t,`H> *cs_table_opt_t;
typedef struct Hashtable::Table<const char ?@,strset_t,`H> @strset_table_t;
typedef struct Hashtable::Table<const char ?@,unsigned int,`H> @uint_table_t;
typedef struct Hashtable::Table<const char ?@,unsigned int,`H> *uint_table_opt_t;

struct grammar {
  List::list_t<definition_t> rules;
  strset_opt_t   maybe_empty;     // Set of symbols that may derive the empty string
  cs_table_opt_t firstt;          // Map symbols to the first characters they may derive
  cs_table_opt_t lastt;           // Map symbols to the last characters they may derive
  cs_table_opt_t followt;         // Map symbols to the first characters that may follow them in a derivation
  cs_table_opt_t mayt;            // Map symbols to characters they may derive
  cs_table_opt_t mustt;           // Map symbols to characters they must derive
  strset_opt_t   rec_symbols;     // Recursively defined nodes
  strset_opt_t   rec_dep_symbols; // Nonrecursive nodes depending on recursive nodes
  strset_opt_t   white_edge_symbols; // Symbols with white edges
  uint_table_opt_t arityt;        // Arity of symbols for printing
};

extern int is_cs(rule_t r);
extern cs_t rule2cs(rule_t r);
// convert all rules marked as css into actual css.
extern void cs_optimize(grammar_t ds);
extern void minus_elim(grammar_t ds);
extern rule_t cs2rule(cs_t rng);


#endif
