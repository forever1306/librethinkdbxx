// auto-generated by yaml_to_cxx.py from test/upstream/mutation/sync.yaml
#include "testlib.h"
void test_upstream_mutation_sync() {
    enter_section("test_upstream_mutation_sync: Tests syncing tables");
    TEST_EQ(maybe_run(R::db("test").table_create("test1"), *conn), (partial(R::Object{{"tables_created", 1}})));
    TEST_EQ(maybe_run(R::db("test").table_create("test1soft"), *conn), (partial(R::Object{{"tables_created", 1}})));
    TEST_EQ(maybe_run(R::db("test").table("test1soft").config().update(R::object("durability", "soft")), *conn), (R::Object{{"skipped", 0}, {"deleted", 0}, {"unchanged", 0}, {"errors", 0}, {"replaced", 1}, {"inserted", 0}}));
    TEST_DO(auto tbl = (R::db("test").table("test1")));
    TEST_DO(auto tbl_soft = (R::db("test").table("test1soft")));
    TEST_EQ(maybe_run(tbl.index_create("x"), *conn), (partial(R::Object{{"created", 1}})));
    TEST_EQ(maybe_run(tbl.index_wait("x").pluck("index", "ready"), *conn), (R::Array{R::Object{{"ready", true}, {"index", "x"}}}));
    TEST_EQ(maybe_run(tbl.sync(), *conn), (R::Object{{"synced", 1}}));
    TEST_EQ(maybe_run(tbl_soft.sync(), *conn), (R::Object{{"synced", 1}}));
    TEST_EQ(maybe_run(tbl.sync(), *conn, R::optargs("durability", "soft")), (R::Object{{"synced", 1}}));
    TEST_EQ(maybe_run(tbl.sync(), *conn, R::optargs("durability", "hard")), (R::Object{{"synced", 1}}));
    TEST_EQ(maybe_run(tbl.between(1, 2).sync(), *conn), (err("AttributeError", "'Between' object has no attribute 'sync'")));
    TEST_EQ(maybe_run(R::expr(1).sync(), *conn), (err("AttributeError", "'Datum' object has no attribute 'sync'")));
    TEST_EQ(maybe_run(R::db("test").table_drop("test1"), *conn), (partial(R::Object{{"tables_dropped", 1}})));
    TEST_EQ(maybe_run(R::db("test").table_drop("test1soft"), *conn), (partial(R::Object{{"tables_dropped", 1}})));
    exit_section();
}
