#include <gtest/gtest.h>
#include <URI/Parser.h>

TEST(URI_test, extract_scheme_1){
    URI::Parser parser;
    std::string test_string = "https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("https",result); 
};
TEST(URI_test, extract_scheme_2){
    URI::Parser parser;
    std::string test_string = "Https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("Https",result); 
};
TEST(URI_test, extract_scheme_3){
    URI::Parser parser;
    std::string test_string = "ftp://ftp.is.co.za/rfc/rfc1808.txt";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("ftp",result); 
};
TEST(URI_test, extract_scheme_4){
    URI::Parser parser;
    std::string test_string = "ldap://[2001:db8::7]/c=GB?objectClass?one";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("ldap",result); 
};
TEST(URI_test, extract_scheme_5){
    URI::Parser parser;
    std::string test_string = "mailto:John.Doe@example.com";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("mailto",result); 
};
TEST(URI_test, extract_scheme_6){
    URI::Parser parser;
    std::string test_string = "news:comp.infosystems.www.servers.unix";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("news",result); 
};
TEST(URI_test, extract_scheme_7){
    URI::Parser parser;
    std::string test_string = "tel:+1-816-555-1212";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("tel",result); 
};
TEST(URI_test, extract_scheme_8){
    URI::Parser parser;
    std::string test_string = "telnet://192.0.2.16:80/";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("telnet",result); 
};
TEST(URI_test, extract_scheme_9){
    URI::Parser parser;
    std::string test_string = "urn:oasis:names:specification:docbook:dtd:xml:4.1.2";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("urn",result); 
};
TEST(URI_test, extract_scheme_10){
    URI::Parser parser;
    std::string test_string = "git://github.com/user/project-name.git";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("git",result); 
};
TEST(URI_test, extract_scheme_11){
    URI::Parser parser;
    std::string test_string = "http://wwww.google.com/user/project-name.git";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("http",result); 
};

TEST(URI_test, extract_auth_1){
    URI::Parser parser;
    std::string test_string = "git://github.com/user/project-name.git";
    std::string result = parser.extract_authority(test_string);
    ASSERT_EQ("github.com",result); 
};
TEST(URI_test, extract_auth_2){
    URI::Parser parser;
    std::string test_string = "https://127.0.0.1:8080/user/project-name.git";
    std::string result = parser.extract_authority(test_string);
    ASSERT_EQ("127.0.0.1:8080", result); 
};
TEST(URI_test, extract_auth_3){
    URI::Parser parser;
    std::string test_string = "ftp://ftp.is.co.za/rfc/rfc1808.txt";
    std::string result = parser.extract_authority(test_string);
    ASSERT_EQ("ftp.is.co.za",result); 
};
TEST(URI_test, extract_auth_4){
    URI::Parser parser;
    std::string test_string = "ldap://[2001:db8::7]/c=GB?objectClass?one";
    std::string result = parser.extract_authority(test_string);
    ASSERT_EQ("[2001:db8::7]",result); 
};
TEST(URI_test, extract_auth_5){
    URI::Parser parser;
    std::string test_string = "telnet://192.0.2.16:80/";
    std::string result = parser.extract_authority(test_string);
    ASSERT_EQ("192.0.2.16:80",result); 
};
TEST(URI_test, extract_auth_6){
    URI::Parser parser;
    std::string test_string = "http://wwww.google.com/user/project-name.git";
    std::string result = parser.extract_authority(test_string);
    ASSERT_EQ("wwww.google.com",result); 
};
TEST(URI_test, extract_userinfo_1){
    URI::Parser parser;
    std::string test_string = "ncsdksd54.csdd545@wwww.google.com";
    std::string result = parser.extract_userinfo(test_string);
    ASSERT_EQ("ncsdksd54.csdd545",result); 
};
TEST(URI_test, extract_userinfo_2){
    URI::Parser parser;
    std::string test_string = "www.geeksforgeeks.org:80";
    std::string result = parser.extract_userinfo(test_string);
    ASSERT_EQ("",result); 
};
TEST(URI_test, extract_host_1){
    URI::Parser parser;
    std::string test_string = "www.geeksforgeeks.org:80";
    std::string result = parser.extract_host(test_string);
    ASSERT_EQ("www.geeksforgeeks.org",result); 
};
TEST(URI_test, extract_host_2){
    URI::Parser parser;
    std::string test_string = "www.geeksforgeeks.org";
    std::string result = parser.extract_host(test_string);
    ASSERT_EQ("www.geeksforgeeks.org",result); 
};
TEST(URI_test, extract_host_3){
    URI::Parser parser;
    std::string test_string = "gogo.kole@gmail.com";
    std::string result = parser.extract_host(test_string);
    ASSERT_EQ("gmail.com",result); 
};
TEST(URI_test, extract_host_4){
    URI::Parser parser;
    std::string test_string = "127.0.0.1:8080";
    std::string result = parser.extract_host(test_string);
    ASSERT_EQ("127.0.0.1",result); 
};
TEST(URI_test, extract_host_5){
    URI::Parser parser;
    std::string test_string = "[2001:db8::7]:8080";
    std::string result = parser.extract_host(test_string);
    ASSERT_EQ("[2001:db8::7]",result); 
};

TEST(URI_test, extract_port_1){
    URI::Parser parser;
    std::string test_string = "www.geeksforgeeks.org:80";
    std::string result = parser.extract_port(test_string);
    ASSERT_EQ("80",result); 
};
TEST(URI_test, extract_port_2){
    URI::Parser parser;
    std::string test_string = "127.0.0.1:8080";
    std::string result = parser.extract_port(test_string);
    ASSERT_EQ("8080",result); 
};