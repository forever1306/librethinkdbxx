// auto-generated by yaml_to_cxx.py from test/upstream/times/constructors.yaml
#include "testlib.h"
void test_upstream_times_constructors() {
    enter_section("test_upstream_times_constructors: Test basic time arithmetic");
    TEST_EQ(maybe_run(R::expr(R::epoch_time(896571240)), *conn), (R::Time(896571240, R::Time::parse_utc_offset("00:00"))));
    TEST_EQ(maybe_run(R::expr(R::object("stuff", R::epoch_time(896571240), "more", R::array(R::epoch_time(996571240)))), *conn), (R::Object{{"stuff", R::Time(896571240, R::Time::parse_utc_offset("00:00"))}, {"more", R::Array{R::Time(996571240, R::Time::parse_utc_offset("00:00"))}}}));
    TEST_EQ(maybe_run(R::expr(R::array(R::epoch_time(796571240), R::epoch_time(896571240), R::object("stuff", R::epoch_time(996571240)))), *conn), (R::Array{R::Time(796571240, R::Time::parse_utc_offset("00:00")), R::Time(896571240, R::Time::parse_utc_offset("00:00")), R::Object{{"stuff", R::Time(996571240, R::Time::parse_utc_offset("00:00"))}}}));
    TEST_EQ(maybe_run(R::expr(R::object("nested", R::object("time", R::epoch_time(896571240)))), *conn), (R::Object{{"nested", R::Object{{"time", R::Time(896571240, R::Time::parse_utc_offset("00:00"))}}}}));
    TEST_EQ(maybe_run(R::expr(R::array(1, "two", R::array("a", R::epoch_time(896571240), 3))), *conn), (R::Array{1, "two", R::Array{"a", R::Time(896571240, R::Time::parse_utc_offset("00:00")), 3}}));
    TEST_EQ(maybe_run(R::epoch_time(1).to_epoch_time(), *conn), (1));
    TEST_EQ(maybe_run(R::epoch_time(-1).to_epoch_time(), *conn), (-1));
    TEST_EQ(maybe_run(R::epoch_time(1.4444445).to_epoch_time(), *conn), (1.444));
    TEST_EQ(maybe_run(R::epoch_time(1.4444445).to_iso8601(), *conn), ("1970-01-01T00:00:01.444+00:00"));
    TEST_EQ(maybe_run(R::epoch_time(1.4444445).seconds(), *conn), (1.444));
    TEST_EQ(maybe_run(R::epoch_time(253430000000).year(), *conn), (10000));
    TEST_EQ(maybe_run(R::epoch_time(253430000000).to_iso8601(), *conn), (err("ReqlQueryLogicError", "Year `10000` out of valid ISO 8601 range [0, 9999].", R::Array{})));
    TEST_EQ(maybe_run(R::epoch_time(253440000000).year(), *conn), (err("ReqlQueryLogicError", "Error in time logic: Year is out of valid range: 1400..10000.", R::Array{})));
    TEST_EQ(maybe_run(R::epoch_time(253440000000).to_epoch_time(), *conn), (253440000000));
    TEST_EQ(maybe_run(R::epoch_time(-17980000000).year(), *conn), (1400));
    TEST_EQ(maybe_run(R::epoch_time(-17990000000).year(), *conn), (err("ReqlQueryLogicError", "Error in time logic: Year is out of valid range: 1400..10000.", R::Array{})));
    TEST_EQ(maybe_run(R::epoch_time(-17990000000).to_epoch_time(), *conn), (-17990000000));
    TEST_DO(auto cdate = (std::string("2013-01-01", 10)));
    TEST_DO(auto dates = (R::Array{std::string("2013", 4), std::string("2013-01", 7), std::string("2013-01-01", 10), std::string("20130101", 8), std::string("2013-001", 8), std::string("2013001", 7)}));
    TEST_DO(auto ctime = (std::string("13:00:00", 8)));
    TEST_DO(auto times = (R::Array{std::string("13", 2), std::string("13:00", 5), std::string("1300", 4), std::string("13:00:00", 8), std::string("13:00:00.000000", 15), std::string("130000.000000", 13)}));
    TEST_DO(auto ctz = (std::string("+00:00", 6)));
    TEST_DO(auto tzs = (R::Array{std::string("Z", 1), std::string("+00", 3), std::string("+0000", 5), std::string("+00:00", 6)}));
    TEST_DO(auto cdt = (R::Array{((cdate + std::string("T", 1)) + ctime) + ctz}));
    TEST_DO(auto bad_dates = (R::Array{std::string("201301", 6), std::string("2013-0101", 9), std::string("2a13", 4), std::string("2013+01", 7), std::string("2013-01-01.1", 12)}));
    TEST_DO(auto bad_times = (R::Array{std::string("a3", 2), std::string("13:0000", 7), std::string("13:000", 6), std::string("13:00.00", 8), std::string("130000.00000000a", 16)}));
    TEST_DO(auto bad_tzs = (R::Array{std::string("X", 1), std::string("-7", 2), std::string("-07:-1", 6), std::string("+07+01", 6), std::string("PST", 3), std::string("UTC", 3), std::string("Z+00", 4)}));
    exit_section();
}
