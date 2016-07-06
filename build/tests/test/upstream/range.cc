// auto-generated by yaml_to_cxx.py from test/upstream/range.yaml
#include "testlib.h"
void test_upstream_range() {
    enter_section("test_upstream_range: Tests RQL range generation");
    TEST_EQ(maybe_run(R::range().type_of(), *conn), ("STREAM"));
    TEST_EQ(maybe_run(R::range().limit(4), *conn), (R::Array{0, 1, 2, 3}));
    TEST_EQ(maybe_run(R::range(4), *conn), (R::Array{0, 1, 2, 3}));
    TEST_EQ(maybe_run(R::range(2, 5), *conn), (R::Array{2, 3, 4}));
    TEST_EQ(maybe_run(R::range(0), *conn), (R::Array{}));
    TEST_EQ(maybe_run(R::range(5, 2), *conn), (R::Array{}));
    TEST_EQ(maybe_run(R::range(-5, -2), *conn), (R::Array{-5, -4, -3}));
    TEST_EQ(maybe_run(R::range(-5, 2), *conn), (R::Array{-5, -4, -3, -2, -1, 0, 1}));
    TEST_EQ(maybe_run(R::range("foo"), *conn), (err("ReqlQueryLogicError", "Expected type NUMBER but found STRING.", R::Array{})));
    TEST_EQ(maybe_run(R::range(9007199254740994.0), *conn), (err_regex("ReqlQueryLogicError", "Number not an integer \\(>2\\^53\\). 9007199254740994", R::Array{})));
    TEST_EQ(maybe_run(R::range(-9007199254740994.0), *conn), (err_regex("ReqlQueryLogicError", "Number not an integer \\(<-2\\^53\\). -9007199254740994", R::Array{})));
    TEST_EQ(maybe_run(R::range(0.5), *conn), (err_regex("ReqlQueryLogicError", "Number not an integer. 0\\.5", R::Array{})));
    TEST_EQ(maybe_run(R::range().count(), *conn), (err("ReqlQueryLogicError", "Cannot use an infinite stream with an aggregation function (`reduce`, `count`, etc.) or coerce it to an array.", R::Array{})));
    TEST_EQ(maybe_run(R::range().coerce_to("ARRAY"), *conn), (err("ReqlQueryLogicError", "Cannot use an infinite stream with an aggregation function (`reduce`, `count`, etc.) or coerce it to an array.", R::Array{})));
    TEST_EQ(maybe_run(R::range().coerce_to("OBJECT"), *conn), (err("ReqlQueryLogicError", "Cannot use an infinite stream with an aggregation function (`reduce`, `count`, etc.) or coerce it to an array.", R::Array{})));
    TEST_EQ(maybe_run(R::range(4).count(), *conn), (4));
    exit_section();
}
