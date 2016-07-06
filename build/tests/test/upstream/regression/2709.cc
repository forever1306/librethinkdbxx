// auto-generated by yaml_to_cxx.py from test/upstream/regression/2709.yaml
#include "testlib.h"
void test_upstream_regression_2709() {
    enter_section("test_upstream_regression_2709: 2709 -- Guarantee failed with [max_els >= min_els]");
    temp_table tbl_table;
    R::Query tbl = tbl_table.table();
    TEST_EQ(maybe_run(tbl.insert(R::range(1, 1000).map([=](R::Var i){ return R::object("result", *i); })).pluck("first_error", "inserted"), *conn, R::optargs("min_batch_rows", 10, "max_batch_rows", 13)), (R::Object{{"inserted", 999}}));
    TEST_EQ(maybe_run(tbl.map([=](R::Var thing){ return R::expr("key"); }).count(), *conn, R::optargs("min_batch_rows", 10, "max_batch_rows", 13)), (999));
    TEST_EQ(maybe_run(tbl.map([=](R::Var thing){ return R::expr("key"); }).count(), *conn, R::optargs("min_batch_rows", 10, "max_batch_rows", 13)), (999));
    exit_section();
}
