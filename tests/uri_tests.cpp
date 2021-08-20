#include <gtest/gtest.h>
#include <URI/Uri.h>

TEST(URI_test, extract_scheme_https){
    URI::Uri uri;
    const std::string test_uri = "https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    uri.from_string(test_uri);
    ASSERT_EQ("https",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_Https){
    URI::Uri uri;
    const std::string test_uri = "Https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    uri.from_string(test_uri);
    ASSERT_EQ("Https",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_ftp){
    URI::Uri uri;
    const std::string test_uri = "ftp://ftp.is.co.za/rfc/rfc1808.txt";
    uri.from_string(test_uri);
    ASSERT_EQ("ftp",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_ldap){
    URI::Uri uri;
    const std::string test_uri = "ldap://[2001:db8::7]/c=GB?objectClass?one";
    uri.from_string(test_uri);
    ASSERT_EQ("ldap",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_mailto){
    URI::Uri uri;
    const std::string test_uri = "mailto:John.Doe@example.com";
    uri.from_string(test_uri);
    ASSERT_EQ("mailto",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_news){
    URI::Uri uri;
    const std::string test_uri = "news:comp.infosystems.www.servers.unix";
    uri.from_string(test_uri);
    ASSERT_EQ("news",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_tel){
    URI::Uri uri;
    const std::string test_uri = "tel:+1-816-555-1212";
    uri.from_string(test_uri);
    ASSERT_EQ("tel",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_telnet){
    URI::Uri uri;
    const std::string test_uri = "telnet://192.0.2.16:80/";
    uri.from_string(test_uri);
    ASSERT_EQ("telnet",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_urn){
    URI::Uri uri;
    const std::string test_uri = "urn:oasis:names:specification:docbook:dtd:xml:4.1.2";
    uri.from_string(test_uri);
    ASSERT_EQ("urn",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_git){
    URI::Uri uri;
    const std::string test_uri = "git://github.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("git",uri.get_scheme()); 
};
TEST(URI_test, extract_scheme_http){
    URI::Uri uri;
    const std::string test_uri = "http://wwww.google.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("http",uri.get_scheme()); 
};
TEST(URI_test, extract_authority_google){
    URI::Uri uri;
    const std::string test_uri = "http://wwww.google.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("wwww.google.com",uri.get_authority()); 
};
TEST(URI_test, extract_authority_git){
    URI::Uri uri;
    const std::string test_uri = "git://github.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("github.com",uri.get_authority()); 
};




