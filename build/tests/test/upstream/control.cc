// auto-generated by yaml_to_cxx.py from test/upstream/control.yaml
#include "testlib.h"
void test_upstream_control() {
    enter_section("test_upstream_control: Tests RQL control flow structures");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    temp_table tbl2_table;
    R::Query tbl2 = tbl2_table.table();
    TEST_EQ(maybe_run(R::expr(1).do_([=](R::Var v){ return *v * 2; }), *conn), (2));
    TEST_EQ(maybe_run(R::expr(R::array(0, 1, 2)).do_([=](R::Var v){ return (*v).append(3); }), *conn), (R::Array{0, 1, 2, 3}));
    TEST_EQ(maybe_run(R::do_(1, 2, [=](R::Var x, R::Var y){ return *x + *y; }), *conn), (3));
    TEST_EQ(maybe_run(R::do_([=](){ return R::expr(1); }), *conn), (1));
    TEST_EQ(maybe_run(R::do_(1), *conn), (1));
    TEST_EQ(maybe_run(R::expr("abc").do_([=](R::Var v){ return (*v).append(3); }), *conn), (err("ReqlQueryLogicError", "Expected type ARRAY but found STRING.", R::Array{1, 0})));
    TEST_EQ(maybe_run(R::expr("abc").do_([=](R::Var v){ return *v + 3; }), *conn), (err("ReqlQueryLogicError", "Expected type STRING but found NUMBER.", R::Array{1, 1})));
    TEST_EQ(maybe_run((R::expr("abc").do_([=](R::Var v){ return *v + "def"; }) + 3), *conn), (err("ReqlQueryLogicError", "Expected type STRING but found NUMBER.", R::Array{1})));
    TEST_EQ(maybe_run(R::expr(5).do_(R::row), *conn), (5));
    TEST_EQ(maybe_run(R::branch(true, 1, 2), *conn), (1));
    TEST_EQ(maybe_run(R::branch(false, 1, 2), *conn), (2));
    TEST_EQ(maybe_run(R::branch(1, "c", false), *conn), ("c"));
    TEST_EQ(maybe_run(R::branch(R::Nil(), R::object(), R::array()), *conn), (R::Array{}));
    TEST_EQ(maybe_run(R::branch(R::db("test"), 1, 2), *conn), (err("ReqlQueryLogicError", "Expected type DATUM but found DATABASE:", R::Array{})));
    TEST_EQ(maybe_run(R::branch(tbl, 1, 2), *conn), (err("ReqlQueryLogicError", "Expected type DATUM but found TABLE:", R::Array{})));
    TEST_EQ(maybe_run(R::branch(R::error("a"), 1, 2), *conn), (err("ReqlUserError", "a", R::Array{})));
    TEST_EQ(maybe_run(R::branch(R::array(), 1, 2), *conn), (1));
    TEST_EQ(maybe_run(R::branch(R::object(), 1, 2), *conn), (1));
    TEST_EQ(maybe_run(R::branch("a", 1, 2), *conn), (1));
    TEST_EQ(maybe_run(R::branch(1.2, 1, 2), *conn), (1));
    TEST_EQ(maybe_run(R::branch(true, 1, true, 2, 3), *conn), (1));
    TEST_EQ(maybe_run(R::branch(true, 1, false, 2, 3), *conn), (1));
    TEST_EQ(maybe_run(R::branch(false, 1, true, 2, 3), *conn), (2));
    TEST_EQ(maybe_run(R::branch(false, 1, false, 2, 3), *conn), (3));
    TEST_EQ(maybe_run(R::branch(true, 1, true, 2), *conn), (err("ReqlQueryLogicError", "Cannot call `branch` term with an even number of arguments.")));
    TEST_EQ(maybe_run(R::error("Hello World"), *conn), (err("ReqlUserError", "Hello World", R::Array{0})));
    TEST_EQ(maybe_run(R::error(5), *conn), (err("ReqlQueryLogicError", "Expected type STRING but found NUMBER.", R::Array{0})));
    TEST_EQ(maybe_run(R::js("1 + 1"), *conn), (2));
    TEST_EQ(maybe_run(R::js("1 + 1; 2 + 2"), *conn), (4));
    TEST_EQ(maybe_run(R::do_(1, 2, R::js("(function(a, b) { return a + b; })")), *conn), (3));
    TEST_EQ(maybe_run(R::expr(1).do_(R::js("(function(x) { return x + 1; })")), *conn), (2));
    TEST_EQ(maybe_run(R::expr("foo").do_(R::js("(function(x) { return x + \"bar\"; })")), *conn), ("foobar"));
    TEST_EQ(maybe_run(R::js("1 + 2", R::OptArgs{{"timeout", R::expr(1.2)}}), *conn), (3));
    TEST_EQ(maybe_run(R::js("(function() { return 1; })"), *conn), (err("ReqlQueryLogicError", "Query result must be of type DATUM, GROUPED_DATA, or STREAM (got FUNCTION).", R::Array{0})));
    TEST_EQ(maybe_run(R::js("function() { return 1; }"), *conn), (err("ReqlQueryLogicError", "SyntaxError: Unexpected token (", R::Array{0})));
    TEST_EQ(maybe_run(R::do_(1, 2, R::js("(function(a) { return a; })")), *conn), (1));
    TEST_EQ(maybe_run(R::do_(1, 2, R::js("(function(a, b, c) { return a; })")), *conn), (1));
    TEST_EQ(maybe_run(R::do_(1, 2, R::js("(function(a, b, c) { return c; })")), *conn), (err("ReqlQueryLogicError", "Cannot convert javascript `undefined` to ql::datum_t.", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).filter(R::js("(function(a) { return a >= 2; })")), *conn), (R::Array{2, 3}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).map(R::js("(function(a) { return a + 1; })")), *conn), (R::Array{2, 3, 4}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).map(R::js("1")), *conn), (err("ReqlQueryLogicError", "Expected type FUNCTION but found DATUM:", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).filter(R::js("(function(a) {})")), *conn), (err("ReqlQueryLogicError", "Cannot convert javascript `undefined` to ql::datum_t.", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).map(1), *conn), (err("ReqlQueryLogicError", "Expected type FUNCTION but found DATUM:", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).filter("foo"), *conn), (R::Array{1, 2, 3}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 4)).filter(R::array()), *conn), (R::Array{1, 2, 4}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).filter(R::Nil()), *conn), (R::Array{}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 4)).filter(false), *conn), (R::Array{}));
    TEST_EQ(maybe_run(tbl.count(), *conn), (0));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each([=](R::Var row){ return tbl.insert(R::object("id", *row)); }), *conn), (R::Object{{"deleted", 0.0}, {"replaced", 0.0}, {"unchanged", 0.0}, {"errors", 0.0}, {"skipped", 0.0}, {"inserted", 3}}));
    TEST_EQ(maybe_run(tbl.count(), *conn), (3));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each([=](R::Var row){ return tbl.update(R::object("foo", *row)); }), *conn), (R::Object{{"deleted", 0.0}, {"replaced", 9}, {"unchanged", 0.0}, {"errors", 0.0}, {"skipped", 0.0}, {"inserted", 0.0}}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each([=](R::Var row){ return R::array(tbl.insert(R::object("id", *row)), tbl.insert(R::object("id", *row * 10))); }), *conn), (R::Object{{"first_error", "Duplicate primary key `id`:\x0a{\x0a\x09\"foo\":\x09\x33,\x0a\x09\"id\":\x09\x31\x0a}\x0a{\x0a\x09\"id\":\x09\x31\x0a}"}, {"deleted", 0.0}, {"replaced", 0.0}, {"unchanged", 0.0}, {"errors", 3}, {"skipped", 0.0}, {"inserted", 3}}));
    TEST_EQ(maybe_run(tbl.count(), *conn), (6));
    TEST_DO(auto tableCount = (tbl2.count().run(*conn)));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each(tbl2.insert(R::object())), *conn), (R::Object{{"deleted", 0.0}, {"replaced", 0.0}, {"generated_keys", arrlen(3, uuid())}, {"unchanged", 0.0}, {"errors", 0.0}, {"skipped", 0.0}, {"inserted", 3}}));
    TEST_EQ(maybe_run(tbl2.count(), *conn), (tableCount + 1));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each([=](R::Var row){ return R::array(tbl.update(R::object("foo", *row)), tbl.update(R::object("bar", *row))); }), *conn), (R::Object{{"deleted", 0.0}, {"replaced", 36}, {"unchanged", 0.0}, {"errors", 0.0}, {"skipped", 0.0}, {"inserted", 0.0}}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each(tbl2.insert(R::object("id", R::row))), *conn), (R::Object{{"deleted", 0.0}, {"replaced", 0.0}, {"unchanged", 0.0}, {"errors", 0.0}, {"skipped", 0.0}, {"inserted", 3}}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each(1), *conn), (err("ReqlQueryLogicError", "FOR_EACH expects one or more basic write queries.  Expected type ARRAY but found NUMBER.", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each([=](R::Var x){ return *x; }), *conn), (err("ReqlQueryLogicError", "FOR_EACH expects one or more basic write queries.  Expected type ARRAY but found NUMBER.", R::Array{1, 1})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each(R::row), *conn), (err("ReqlQueryLogicError", "FOR_EACH expects one or more basic write queries.  Expected type ARRAY but found NUMBER.", R::Array{1, 1})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2, 3)).for_each([=](R::Var row){ return tbl; }), *conn), (err("ReqlQueryLogicError", "FOR_EACH expects one or more basic write queries.", R::Array{1, 1})));
    TEST_EQ(maybe_run(R::expr(1).do_(tbl.insert(R::object("foo", R::row))), *conn), (R::Object{{"deleted", 0.0}, {"replaced", 0.0}, {"generated_keys", arrlen(1, uuid())}, {"unchanged", 0.0}, {"errors", 0.0}, {"skipped", 0.0}, {"inserted", 1}}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2))[0].do_(tbl.insert(R::object("foo", R::row))), *conn), (R::Object{{"deleted", 0.0}, {"replaced", 0.0}, {"generated_keys", arrlen(1, uuid())}, {"unchanged", 0.0}, {"errors", 0.0}, {"skipped", 0.0}, {"inserted", 1}}));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2)).map(tbl.insert(R::object("foo", R::row))), *conn), (err("ReqlCompileError", "Cannot nest writes or meta ops in stream operations.  Use FOR_EACH instead.", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2)).map(R::db("test").table_create("table_create_failure")), *conn), (err("ReqlCompileError", "Cannot nest writes or meta ops in stream operations.  Use FOR_EACH instead.", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2)).map(tbl.insert(R::object("foo", R::row)).get_field("inserted")), *conn), (err("ReqlCompileError", "Cannot nest writes or meta ops in stream operations.  Use FOR_EACH instead.", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(R::array(1, 2)).map(tbl.insert(R::object("foo", R::row)).get_field("inserted").add(5)), *conn), (err("ReqlCompileError", "Cannot nest writes or meta ops in stream operations.  Use FOR_EACH instead.", R::Array{0})));
    TEST_EQ(maybe_run(R::expr(1).do_(R::db("test").table_create("table_create_success")), *conn), (partial(R::Object{{"tables_created", 1}})));
    exit_section();
}
