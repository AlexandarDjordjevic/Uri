#include <gtest/gtest.h>
#include <URI/Uri.h>

TEST(URI_test, extract_scheme_1){
    URI::Uri uri;
    const std::string test_string = "https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    uri.from_string(test_string);
    ASSERT_EQ("https",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_2){
    URI::Uri uri;
    const std::string test_string = "Https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    uri.from_string(test_string);
    ASSERT_EQ("Https",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_3){
    URI::Uri uri;
    const std::string test_string = "ftp://ftp.is.co.za/rfc/rfc1808.txt";
    uri.from_string(test_string);
    ASSERT_EQ("ftp",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_4){
    URI::Uri uri;
    const std::string test_string = "ldap://[2001:db8::7]/c=GB?objectClass?one";
    uri.from_string(test_string);
    ASSERT_EQ("ldap",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_5){
    URI::Uri uri;
    const std::string test_string = "mailto:John.Doe@example.com";
    uri.from_string(test_string);
    ASSERT_EQ("mailto",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_6){
    URI::Uri uri;
    const std::string test_string = "news:comp.infosystems.www.servers.unix";
    uri.from_string(test_string);
    ASSERT_EQ("news",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_7){
    URI::Uri uri;
    const std::string test_string = "tel:+1-816-555-1212";
    uri.from_string(test_string);
    ASSERT_EQ("tel",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_8){
    URI::Uri uri;
    const std::string test_string = "telnet://192.0.2.16:80/";
    uri.from_string(test_string);
    ASSERT_EQ("telnet",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_9){
    URI::Uri uri;
    const std::string test_string = "urn:oasis:names:specification:docbook:dtd:xml:4.1.2";
    uri.from_string(test_string);
    ASSERT_EQ("urn",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_10){
    URI::Uri uri;
    const std::string test_string = "git://github.com/user/project-name.git";
    uri.from_string(test_string);
    ASSERT_EQ("git",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_11){
    URI::Uri uri;
    const std::string test_string = "http://wwww.google.com/user/project-name.git";
    uri.from_string(test_string);
    ASSERT_EQ("http",uri.get_scheme()); 
};

