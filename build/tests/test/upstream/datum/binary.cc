// auto-generated by yaml_to_cxx.py from test/upstream/datum/binary.yaml
#include "testlib.h"
void test_upstream_datum_binary() {
    enter_section("test_upstream_datum_binary: Tests of converstion to and from the RQL binary type");
    TEST_DO(auto s = (std::string("", 0)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (0));
    TEST_DO(s = (std::string("\x00", 1)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (1));
    TEST_DO(s = (std::string("\x00\x42", 2)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (2));
    TEST_DO(s = (std::string("\x00\xfez", 3)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (3));
    TEST_DO(s = (std::string("\xed\xfe\x00\xba", 4)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (4));
    TEST_DO(s = (std::string("P\xf9\x00w\xf9", 5)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (5));
    TEST_DO(s = (std::string("/\xe3\xb5W\x00\x92", 6)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (6));
    TEST_DO(s = (std::string("\xa9\x43T\xe9\x00\xf8\xfb", 7)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (7));
    TEST_DO(s = (std::string("W\xbb\xe5\x82\x8b\xd3\x00\xf9", 8)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (8));
    TEST_DO(s = (std::string("D\x1b>\x00\x13\x19)*\xbf", 9)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (9));
    TEST_DO(s = (std::string("\x8a\x1d\x09\x00]`k.p\xd9", 10)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (10));
    TEST_DO(s = (std::string("\x00\xafGK8\x99\x14\x8d\x8f\x10Q", 11)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (11));
    TEST_DO(s = (std::string("E9\x00\xf7\xc2\x37\xfd\xe0\x38\x82@\xa9", 12)));
    TEST_EQ(maybe_run(R::binary(s), *conn), (s));
    TEST_EQ(maybe_run(R::binary(s).count(), *conn), (12));
    TEST_DO(auto a = (std::string("\x00", 1)));
    TEST_DO(auto b = (std::string("\x00\x01", 2)));
    TEST_DO(auto c = (std::string("\x01", 1)));
    TEST_DO(auto d = (std::string("p\"", 2)));
    TEST_DO(auto e = (std::string("\x80", 1)));
    TEST_DO(auto f = (std::string("\xfe", 1)));
    TEST_EQ(maybe_run(R::binary(a).eq(R::binary(a)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(a).le(R::binary(a)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(a).ge(R::binary(a)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(a).ne(R::binary(a)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(a).lt(R::binary(a)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(a).gt(R::binary(a)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(a).ne(R::binary(b)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(a).lt(R::binary(b)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(a).le(R::binary(b)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(a).ge(R::binary(b)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(a).gt(R::binary(b)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(a).eq(R::binary(b)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(b).ne(R::binary(c)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(b).lt(R::binary(c)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(b).le(R::binary(c)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(b).ge(R::binary(c)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(b).gt(R::binary(c)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(b).eq(R::binary(c)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(c).ne(R::binary(d)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(c).lt(R::binary(d)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(c).le(R::binary(d)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(c).ge(R::binary(d)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(c).gt(R::binary(d)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(c).eq(R::binary(d)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(d).ne(R::binary(e)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(d).lt(R::binary(e)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(d).le(R::binary(e)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(d).ge(R::binary(e)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(d).gt(R::binary(e)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(d).eq(R::binary(e)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(e).ne(R::binary(f)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(e).lt(R::binary(f)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(e).le(R::binary(f)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(e).ge(R::binary(f)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(e).gt(R::binary(f)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(e).eq(R::binary(f)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(f).eq(R::binary(f)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(f).le(R::binary(f)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(f).ge(R::binary(f)), *conn), (true));
    TEST_EQ(maybe_run(R::binary(f).ne(R::binary(f)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(f).lt(R::binary(f)), *conn), (false));
    TEST_EQ(maybe_run(R::binary(f).gt(R::binary(f)), *conn), (false));
    TEST_EQ(maybe_run(R::binary("foo").coerce_to("string"), *conn), ("foo"));
    TEST_EQ(maybe_run(R::expr("foo").coerce_to("binary"), *conn), ("foo"));
    TEST_EQ(maybe_run(R::binary(a).coerce_to("bool"), *conn), (true));
    TEST_EQ(maybe_run(R::binary("foo").coerce_to("binary"), *conn), ("foo"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(-3, -1), *conn), ("ef"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(0, 2), *conn), ("ab"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(3, -1), *conn), ("def"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(-5, 5), *conn), ("cde"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(-8, 2), *conn), ("ab"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(5, 7), *conn), ("fg"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(-9, 2), *conn), ("ab"));
    TEST_EQ(maybe_run(R::binary("abcdefg").slice(5, 9), *conn), ("fg"));
    TEST_EQ(maybe_run(R::binary(b), *conn, R::optargs("binary_format", "native")), (b));
    TEST_EQ(maybe_run(R::binary(b), *conn, R::optargs("binary_format", "raw")), (R::Object{{"$reql_type$", "BINARY"}, {"data", "AAE="}}));
    TEST_EQ(maybe_run(R::binary(R::expr("data")), *conn), ("data"));
    TEST_EQ(maybe_run(R::binary(R::expr(R::object())), *conn), (err("ReqlQueryLogicError", "Expected type STRING but found OBJECT.", R::Array{})));
    TEST_EQ(maybe_run(R::binary(R::expr(R::array())), *conn), (err("ReqlQueryLogicError", "Expected type STRING but found ARRAY.", R::Array{})));
    TEST_EQ(maybe_run(R::expr(R::object("$reql_type$", "BINARY")), *conn), (err("ReqlQueryLogicError", "Invalid binary pseudotype: lacking `data` key.", R::Array{})));
    TEST_EQ(maybe_run(R::expr(R::object("$reql_type$", "BINARY", "data", "ABCDEFGH==AA")), *conn), (err("ReqlQueryLogicError", "Invalid base64 format, data found after padding character '='.", R::Array{})));
    TEST_EQ(maybe_run(R::expr(R::object("$reql_type$", "BINARY", "data", "ABCDEF==$")), *conn), (err("ReqlQueryLogicError", "Invalid base64 format, data found after padding character '='.", R::Array{})));
    TEST_EQ(maybe_run(R::expr(R::object("$reql_type$", "BINARY", "data", "A^CDEFGH")), *conn), (err("ReqlQueryLogicError", "Invalid base64 character found: '^'.", R::Array{})));
    TEST_EQ(maybe_run(R::expr(R::object("$reql_type$", "BINARY", "data", "ABCDE")), *conn), (err("ReqlQueryLogicError", "Invalid base64 length: 1 character remaining, cannot decode a full byte.", R::Array{})));
    TEST_EQ(maybe_run(R::binary(a).coerce_to("array"), *conn), (err("ReqlQueryLogicError", "Cannot coerce BINARY to ARRAY.", R::Array{})));
    TEST_EQ(maybe_run(R::binary(a).coerce_to("object"), *conn), (err("ReqlQueryLogicError", "Cannot coerce BINARY to OBJECT.", R::Array{})));
    TEST_EQ(maybe_run(R::binary(a).coerce_to("number"), *conn), (err("ReqlQueryLogicError", "Cannot coerce BINARY to NUMBER.", R::Array{})));
    TEST_EQ(maybe_run(R::binary(a).coerce_to(R::expr("nu") + "ll"), *conn), (err("ReqlQueryLogicError", "Cannot coerce BINARY to NULL.", R::Array{})));
    exit_section();
}
