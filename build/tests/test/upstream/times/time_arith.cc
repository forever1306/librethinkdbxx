// auto-generated by yaml_to_cxx.py from test/upstream/times/time_arith.yaml
#include "testlib.h"
void test_upstream_times_time_arith() {
    enter_section("test_upstream_times_time_arith: Test basic time arithmetic");
    TEST_DO(auto rt1 = (1375147296.681));
    TEST_DO(auto rt2 = (1375147296.682));
    TEST_DO(auto rt3 = (1375147297.681));
    TEST_DO(auto rt4 = (2375147296.681));
    TEST_DO(auto rts = (R::Array{rt1, rt2, rt3, rt4}));
    TEST_DO(auto t1 = (R::epoch_time(rt1)));
    TEST_DO(auto t2 = (R::epoch_time(rt2)));
    TEST_DO(auto t3 = (R::epoch_time(rt3)));
    TEST_DO(auto t4 = (R::epoch_time(rt4)));
    TEST_DO(auto ts = (R::expr(R::array(t1, t2, t3, t4))));
    TEST_EQ(maybe_run(((t2 - t1) * 1000).do_([=](R::Var x){ return *x>0.99 && *x<1.01; }), *conn), (true));
    TEST_EQ(maybe_run((t3 - t1), *conn), (1));
    TEST_EQ(maybe_run((t4 - t1), *conn), (1000000000));
    TEST_EQ(maybe_run(((t1 - t2) * 1000).do_([=](R::Var x){ return *x<-0.99 && *x>-1.01; }), *conn), (true));
    TEST_EQ(maybe_run((t1 - t3), *conn), (-1));
    TEST_EQ(maybe_run((t1 - t4), *conn), (-1000000000));
    TEST_EQ(maybe_run(ts.map([=](R::Var x){ return t1 + (*x - t1); }).map([=](R::Var x){ return (*x).to_epoch_time(); }), *conn), (R::Array{rt1, rt2, rt3, rt4}));
    TEST_EQ(maybe_run(ts.map([=](R::Var x){ return (t1 + *x) - t1; }).map([=](R::Var x){ return (*x).to_epoch_time(); }), *conn), (err("ReqlQueryLogicError", "Expected type NUMBER but found PTYPE<TIME>.", R::Array{})));
    TEST_EQ(maybe_run(ts.map([=](R::Var x){ return t1 - (t1 - *x); }).map([=](R::Var x){ return (*x).to_epoch_time(); }), *conn), (R::Array{rt1, rt2, rt3, rt4}));
    TEST_EQ(maybe_run(ts.map([=](R::Var x){ return ts.map([=](R::Var y){ return R::array(*x<*y, *x<=*y, *x==*y, *x!=*y, *x>=*y, *x>*y); }); }), *conn), (R::Array{R::Array{R::Array{false, true, true, false, true, false}, R::Array{true, true, false, true, false, false}, R::Array{true, true, false, true, false, false}, R::Array{true, true, false, true, false, false}}, R::Array{R::Array{false, false, false, true, true, true}, R::Array{false, true, true, false, true, false}, R::Array{true, true, false, true, false, false}, R::Array{true, true, false, true, false, false}}, R::Array{R::Array{false, false, false, true, true, true}, R::Array{false, false, false, true, true, true}, R::Array{false, true, true, false, true, false}, R::Array{true, true, false, true, false, false}}, R::Array{R::Array{false, false, false, true, true, true}, R::Array{false, false, false, true, true, true}, R::Array{false, false, false, true, true, true}, R::Array{false, true, true, false, true, false}}}));
    TEST_DO(auto datum_types = (R::expr(R::array(R::Nil(), true, false, 1, "1", R::array(1), R::object("1", 1), R::binary("")))));
    TEST_EQ(maybe_run(datum_types.map([=](R::Var x){ return R::expr(R::array(R::array(*x, t1), R::array(t1, *x))).map([=](R::Var xy){ return (*xy)[0].do_([=](R::Var x2){ return (*xy)[1].do_([=](R::Var y){ return R::array(*x2<*y, *x2<=*y, *x2==*y, *x2!=*y, *x2>=*y, *x2>*y); }); }); }); }), *conn), (R::Array{R::Array{R::Array{true, true, false, true, false, false}, R::Array{false, false, false, true, true, true}}, R::Array{R::Array{true, true, false, true, false, false}, R::Array{false, false, false, true, true, true}}, R::Array{R::Array{true, true, false, true, false, false}, R::Array{false, false, false, true, true, true}}, R::Array{R::Array{true, true, false, true, false, false}, R::Array{false, false, false, true, true, true}}, R::Array{R::Array{false, false, false, true, true, true}, R::Array{true, true, false, true, false, false}}, R::Array{R::Array{true, true, false, true, false, false}, R::Array{false, false, false, true, true, true}}, R::Array{R::Array{true, true, false, true, false, false}, R::Array{false, false, false, true, true, true}}, R::Array{R::Array{true, true, false, true, false, false}, R::Array{false, false, false, true, true, true}}}));
    TEST_EQ(maybe_run(ts.map([=](R::Var a){ return ts.map([=](R::Var b){ return ts.map([=](R::Var c){ return (*b).during(*a, *c); }); }); }), *conn), (R::Array{R::Array{R::Array{false, true, true, true}, R::Array{false, false, true, true}, R::Array{false, false, false, true}, R::Array{false, false, false, false}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, true, true}, R::Array{false, false, false, true}, R::Array{false, false, false, false}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, true}, R::Array{false, false, false, false}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}}}));
    TEST_EQ(maybe_run(ts.map([=](R::Var a){ return ts.map([=](R::Var b){ return ts.map([=](R::Var c){ return (*b).during(*a, *c, R::OptArgs{{"left_bound", R::expr("open")}}); }); }); }), *conn), (R::Array{R::Array{R::Array{false, false, false, false}, R::Array{false, false, true, true}, R::Array{false, false, false, true}, R::Array{false, false, false, false}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, true}, R::Array{false, false, false, false}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}}}));
    TEST_EQ(maybe_run(ts.map([=](R::Var a){ return ts.map([=](R::Var b){ return ts.map([=](R::Var c){ return (*b).during(*a, *c, R::OptArgs{{"right_bound", R::expr("closed")}}); }); }); }), *conn), (R::Array{R::Array{R::Array{true, true, true, true}, R::Array{false, true, true, true}, R::Array{false, false, true, true}, R::Array{false, false, false, true}}, R::Array{R::Array{false, false, false, false}, R::Array{false, true, true, true}, R::Array{false, false, true, true}, R::Array{false, false, false, true}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, true, true}, R::Array{false, false, false, true}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, true}}}));
    TEST_EQ(maybe_run(ts.map([=](R::Var a){ return ts.map([=](R::Var b){ return ts.map([=](R::Var c){ return (*b).during(*a, *c, R::OptArgs{{"left_bound", R::expr("open")}, {"right_bound", R::expr("closed")}}); }); }); }), *conn), (R::Array{R::Array{R::Array{false, false, false, false}, R::Array{false, true, true, true}, R::Array{false, false, true, true}, R::Array{false, false, false, true}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, true, true}, R::Array{false, false, false, true}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, true}}, R::Array{R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}, R::Array{false, false, false, false}}}));
    TEST_EQ(maybe_run(ts.map([=](R::Var x){ return (*x).date() + (*x).time_of_day(); }).map([=](R::Var x){ return (*x).to_epoch_time(); }), *conn), (rts));
    TEST_EQ(maybe_run(R::epoch_time(rt1).do_(R::js("(function(data){return data})")).to_epoch_time(), *conn), (rt1));
    TEST_EQ(maybe_run(R::do_(R::js("new Date('2012-08-01')")).to_iso8601(), *conn), ("2012-08-01T00:00:00+00:00"));
    TEST_EQ(maybe_run(R::do_(R::js("(function(x){doc = new Object(); doc.date = new Date('2012-08-01'); return doc;})"))["date"].to_iso8601(), *conn), ("2012-08-01T00:00:00+00:00"));
    exit_section();
}
