// auto-generated by yaml_to_cxx.py from test/upstream/regression/1132.yaml
#include "testlib.h"
void test_upstream_regression_1132() {
    enter_section("test_upstream_regression_1132: 1132 JSON duplicate key");
    TEST_EQ(maybe_run(R::json("{\"a\":1,\"a\":2}"), *conn), (err("ReqlQueryLogicError", "Duplicate key \"a\" in JSON.", R::Array{})));
    exit_section();
}
