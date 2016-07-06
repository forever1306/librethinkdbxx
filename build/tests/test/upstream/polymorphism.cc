// auto-generated by yaml_to_cxx.py from test/upstream/polymorphism.yaml
#include "testlib.h"
void test_upstream_polymorphism() {
    enter_section("test_upstream_polymorphism: Tests that manipulation data in tables");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    TEST_DO(auto obj = (R::expr(R::object("id", 0, "a", 0))));
    TEST_EQ(maybe_run(tbl.insert(R::range(3).map([=](R::Var i){ return R::object("id", *i, "a", *i); })), *conn), (R::Object{{"deleted", 0}, {"replaced", 0}, {"unchanged", 0}, {"errors", 0}, {"skipped", 0}, {"inserted", 3}}));
    TEST_EQ(maybe_run(tbl.merge(R::object("c", 1)).nth(0), *conn), (R::Object{{"id", 0}, {"c", 1}, {"a", 0}}));
    TEST_EQ(maybe_run(obj.merge(R::object("c", 1)), *conn), (R::Object{{"id", 0}, {"c", 1}, {"a", 0}}));
    TEST_EQ(maybe_run(tbl.without("a").nth(0), *conn), (R::Object{{"id", 0}}));
    TEST_EQ(maybe_run(obj.without("a"), *conn), (R::Object{{"id", 0}}));
    TEST_EQ(maybe_run(tbl.pluck("a").nth(0), *conn), (R::Object{{"a", 0}}));
    TEST_EQ(maybe_run(obj.pluck("a"), *conn), (R::Object{{"a", 0}}));
    exit_section();
}
