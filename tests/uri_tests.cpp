#include <gtest/gtest.h>
#include <URI/Uri.h>

TEST(URI_test, parse_scheme_https){
    URI::Uri uri;
    const std::string test_uri = "https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    uri.from_string(test_uri);
    ASSERT_EQ("https", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_Https){
    URI::Uri uri;
    const std::string test_uri = "Https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    uri.from_string(test_uri);
    ASSERT_EQ("Https", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_ftp){
    URI::Uri uri;
    const std::string test_uri = "ftp://ftp.is.co.za/rfc/rfc1808.txt";
    uri.from_string(test_uri);
    ASSERT_EQ("ftp", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_ldap){
    URI::Uri uri;
    const std::string test_uri = "ldap://[2001:db8::7]/c=GB?objectClass?one";
    uri.from_string(test_uri);
    ASSERT_EQ("ldap", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_mailto){
    URI::Uri uri;
    const std::string test_uri = "mailto:John.Doe@example.com";
    uri.from_string(test_uri);
    ASSERT_EQ("mailto", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_news){
    URI::Uri uri;
    const std::string test_uri = "news:comp.infosystems.www.servers.unix";
    uri.from_string(test_uri);
    ASSERT_EQ("news", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_tel){
    URI::Uri uri;
    const std::string test_uri = "tel:+1-816-555-1212";
    uri.from_string(test_uri);
    ASSERT_EQ("tel", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_telnet){
    URI::Uri uri;
    const std::string test_uri = "telnet://192.0.2.16:80/";
    uri.from_string(test_uri);
    ASSERT_EQ("telnet", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_urn){
    URI::Uri uri;
    const std::string test_uri = "urn:oasis:names:specification:docbook:dtd:xml:4.1.2";
    uri.from_string(test_uri);
    ASSERT_EQ("urn", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_git){
    URI::Uri uri;
    const std::string test_uri = "git://github.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("git", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_http){
    URI::Uri uri;
    const std::string test_uri = "http://wwww.google.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("http", uri.get_scheme()); 
};

TEST(URI_test, parse_authority_google){
    URI::Uri uri;
    const std::string test_uri = "http://wwww.google.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("wwww.google.com", uri.get_authority()); 
};

TEST(URI_test, parse_authority_git){
    URI::Uri uri;
    const std::string test_uri = "git://github.com/user/project-name.git";
    uri.from_string(test_uri);
    ASSERT_EQ("github.com", uri.get_authority()); 
};

TEST(URI_test, parse_authority_ipv6_with_path){
    URI::Uri uri;
    const std::string test_uri = "ldap://[2001:db8::7]/c=GB?objectClass?one";
    uri.from_string(test_uri);
    ASSERT_EQ("[2001:db8::7]", uri.get_authority());  
};

TEST(URI_test, parse_authority_ipv6_without_path){
    URI::Uri uri;
    const std::string test_uri = "ldap://[2001:db8::7]";
    uri.from_string(test_uri);
    ASSERT_EQ("[2001:db8::7]", uri.get_authority());  
};

TEST(URI_test, parse_host){
    URI::Uri uri;
    const std::string test_authority = "[5655:43:4343:76dd:::]:8080";
    uri.parse_host(test_authority);
    ASSERT_EQ("[5655:43:4343:76dd:::]", uri.get_host());  
};

TEST(URI_test, parse_host1){
    URI::Uri uri;
    const std::string test_authority = "127.0.0.1:8080";
    uri.parse_host(test_authority);
    ASSERT_EQ("127.0.0.1", uri.get_host());  
};


TEST(URI_test, parse_host2){
    URI::Uri uri;
    const std::string test_authority = "google.csds.com:8080";
    uri.parse_host(test_authority);
    ASSERT_EQ("google.csds.com", uri.get_host());  
};