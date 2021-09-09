#include <gtest/gtest.h>
#include <URI/Uri.h>

TEST(URI_test, parse_scheme_https){
    URI::Uri uri;
    const auto test_uri{"https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc"};
    uri.from_string(test_uri);
    ASSERT_EQ("https", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_Https){
    URI::Uri uri;
    const auto test_uri{"Https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc"};
    uri.from_string(test_uri);
    ASSERT_EQ("Https", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_ftp){
    URI::Uri uri;
    const auto test_uri{"ftp://ftp.is.co.za/rfc/rfc1808.txt"};
    uri.from_string(test_uri);
    ASSERT_EQ("ftp", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_ldap){
    URI::Uri uri;
    const auto test_uri{"ldap://[2001:db8::7]/c=GB?objectClass?one"};
    uri.from_string(test_uri);
    ASSERT_EQ("ldap", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_mailto){
    URI::Uri uri;
    const auto test_uri{"mailto:John.Doe@example.com"};
    uri.from_string(test_uri);
    ASSERT_EQ("mailto", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_news){
    URI::Uri uri;
    const auto test_uri{"news:comp.infosystems.www.servers.unix"};
    uri.from_string(test_uri);
    ASSERT_EQ("news", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_tel){
    URI::Uri uri;
    const auto test_uri{"tel:+1-816-555-1212"};
    uri.from_string(test_uri);
    ASSERT_EQ("tel", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_telnet){
    URI::Uri uri;
    const auto test_uri{"telnet://192.0.2.16:80/"};
    uri.from_string(test_uri);
    ASSERT_EQ("telnet", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_urn){
    URI::Uri uri;
    const auto test_uri{"urn:oasis:names:specification:docbook:dtd:xml:4.1.2"};
    uri.from_string(test_uri);
    ASSERT_EQ("urn", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_git){
    URI::Uri uri;
    const auto test_uri{"git://github.com/user/project-name.git"};
    uri.from_string(test_uri);
    ASSERT_EQ("git", uri.get_scheme()); 
};

TEST(URI_test, parse_scheme_http){
    URI::Uri uri;
    const auto test_uri{"http://wwww.google.com/user/project-name.git"};
    uri.from_string(test_uri);
    ASSERT_EQ("http", uri.get_scheme()); 
};

TEST(URI_test, parse_authority_google){
    URI::Uri uri;
    const auto test_uri{"http://wwww.google.com/user/project-name.git"};
    uri.from_string(test_uri);
    ASSERT_EQ("wwww.google.com", uri.get_authority()); 
};

TEST(URI_test, parse_authority_git){
    URI::Uri uri;
    const auto test_uri{"git://github.com/user/project-name.git"};
    uri.from_string(test_uri);
    ASSERT_EQ("github.com", uri.get_authority()); 
};

TEST(URI_test, parse_authority_ipv6_with_path){
    URI::Uri uri;
    const auto test_uri{"ldap://[2001:db8::7]/c=GB?objectClass?one"};
    uri.from_string(test_uri);
    ASSERT_EQ("[2001:db8::7]", uri.get_authority());  
};

TEST(URI_test, parse_authority_ipv6_without_path){
    URI::Uri uri;
    const auto test_uri{"ldap://[2001:db8::7]"};
    uri.from_string(test_uri);
    ASSERT_EQ("[2001:db8::7]", uri.get_authority());  
};

TEST(URI_test, parse_host_ipv6){
    URI::Uri uri;
    const auto test_uri{"http://[5655:43:4343:76dd:::]:8080"};
    uri.from_string(test_uri);
    ASSERT_EQ("[5655:43:4343:76dd:::]", uri.get_host());  
};

TEST(URI_test, parse_host_ipv4){
    URI::Uri uri;
    const auto test_uri{"http://127.0.0.1:8080"};
    uri.from_string(test_uri);
    ASSERT_EQ("127.0.0.1", uri.get_host());  
};

TEST(URI_test, parse_host_when_userinfo_ispresent){
    URI::Uri uri;
    const auto test_uri{"http://csdv@google.csds.com:8080"};
    uri.from_string(test_uri);
    ASSERT_EQ("google.csds.com", uri.get_host());  
};

TEST(URI_test, parse_host_without_userinfo){
    URI::Uri uri;
    const auto test_uri{"http://google.csds.com:8080"};
    uri.from_string(test_uri);
    ASSERT_EQ("google.csds.com", uri.get_host());  
};
TEST(URI_test, parse_port_without_userinfo){
    URI::Uri uri;
    const auto test_uri{"http://google.csds.com:8080"};
    uri.from_string(test_uri);
    ASSERT_EQ("8080", uri.get_port());  
};

TEST(URI_test, parse_host_without_port){
    URI::Uri uri;
    const auto test_uri{"http://csdv@google.csds.com"};
    uri.from_string(test_uri);
    ASSERT_EQ("google.csds.com", uri.get_host());  
};
TEST(URI_test, parse_userinfo_without_port){
    URI::Uri uri;
    const auto test_uri{"http://csdv@google.csds.com"};
    uri.from_string(test_uri);
    ASSERT_EQ("csdv", uri.get_userinfo());  
};
TEST(URI_test, parse_host_without_port_ipv6){
    URI::Uri uri;
    const auto test_uri{"http://[5655:43:4343:76dd:::]"};
    uri.from_string(test_uri);
    ASSERT_EQ("[5655:43:4343:76dd:::]", uri.get_host());  
};

TEST(URI_test, parse_path_with_port){
    URI::Uri uri;
    const auto test_uri{"foo://example.com:8042/over/there?name"};
    uri.from_string(test_uri);
    ASSERT_EQ("over/there", uri.get_path());  
};

TEST(URI_test, parse_path_ipv6){
    URI::Uri uri;
    const auto test_uri{"ldap://[2001:db8::7]/c=GB?objectClass?one"};
    uri.from_string(test_uri);
    ASSERT_EQ("c=GB", uri.get_path());  
};

TEST(URI_test, parse_path_no_authority){
    URI::Uri uri;
    const auto test_uri{"mailto:John.Doe@example.com"};
    uri.from_string(test_uri);
    ASSERT_EQ("John.Doe@example.com", uri.get_path());  
};

TEST(URI_test, parse_path_no_authority_long){
    URI::Uri uri;
    const auto test_uri{"news:comp.infosystems.www.servers.unix"};
    uri.from_string(test_uri);
    ASSERT_EQ("comp.infosystems.www.servers.unix", uri.get_path());  
};

TEST(URI_test, parse_path_tel){
    URI::Uri uri;
    const auto test_uri{"tel:+1-816-555-1212"};
    uri.from_string(test_uri);
    ASSERT_EQ("+1-816-555-1212", uri.get_path());  
};

TEST(URI_test, parse_path_no_path){
    URI::Uri uri;
    const auto test_uri{"telnet://192.0.2.16:80/"};
    uri.from_string(test_uri);
    ASSERT_EQ("", uri.get_path());  
};

TEST(URI_test, parse_path_urn){
    URI::Uri uri;
    const auto test_uri{"urn:oasis:names:specification:docbook:dtd:xml:4.1.2"};
    uri.from_string(test_uri);
    ASSERT_EQ("oasis:names:specification:docbook:dtd:xml:4.1.2", uri.get_path());  
};

TEST(URI_test, parse_path_with_all){
    URI::Uri uri;
    const auto test_uri{"https://john.doe@www.example.com:123/forum/questions/geee.fs?tag=networking&order=newest#top"};
    uri.from_string(test_uri);
    ASSERT_EQ("forum/questions/geee.fs", uri.get_path());  
};

TEST(URI_test, parse_path_git){
 URI::Uri uri;
 const auto test_uri{"git://github.com/user/project-name.git"};
 uri.from_string(test_uri);
 ASSERT_EQ("user/project-name.git", uri.get_path()); 
};
 
TEST(URI_test, parse_directory_path){
 URI::Uri uri;
 const auto test_uri{"./directory_1/directory_2/file.txt"};
 uri.from_string(test_uri);
 ASSERT_EQ("directory_1/directory_2/file.txt", uri.get_path()); 
};

TEST(URI_test, parse_query_ipv6){
    URI::Uri uri;
    const auto test_uri{"ldap://[2001:db8::7]/c=GB?objectClass?one"};
    uri.from_string(test_uri);
    ASSERT_EQ("objectClass?one", uri.get_query());  
};

TEST(URI_test, parse_query_with_all){
    URI::Uri uri;
    const auto test_uri{"https://john.doe@www.example.com:123/forum/questions/geee.fs?tag=networking&order=newest#top"};
    uri.from_string(test_uri);
    ASSERT_EQ("tag=networking&order=newest", uri.get_query());  
};

TEST(URI_test, parse_query_without_frags){
    URI::Uri uri;
    const auto test_uri{"https://example.com/path/to/page?name=ferret&color=purple"};
    uri.from_string(test_uri);
    ASSERT_EQ("name=ferret&color=purple", uri.get_query());  
};

TEST(URI_test, parse_fragment_with_all){
    URI::Uri uri;
    const auto test_uri{"https://john.doe@www.example.com:123/forum/questions/geee.fs?tag=networking&order=newest#top"};
    uri.from_string(test_uri);
    ASSERT_EQ("top", uri.get_fragments());  
};

TEST(URI_test, parse_fragment_with_exclamationmarks){
    URI::Uri uri;
    const auto test_uri{"http://example.com/index.html#!s3!searchterms"};
    uri.from_string(test_uri);
    ASSERT_EQ("!s3!searchterms", uri.get_fragments());  
};

TEST(URI_test, parse_fragment_with_brackets){
    URI::Uri uri;
    const auto test_uri{"http://example.com/document.txt#match=[rR][fF][cC]"};
    uri.from_string(test_uri);
    ASSERT_EQ("match=[rR][fF][cC]", uri.get_fragments());  
};

TEST(URI_test, parse_userinfo_google){
    URI::Uri uri;
    const auto test_uri{"http://wwww.google.com/user/project-name.git"};
    uri.from_string(test_uri);
    ASSERT_EQ("", uri.get_userinfo()); 
};

TEST(URI_test, parse_userinfo_git){
    URI::Uri uri;
    const auto test_uri{"git://github.com/user/project-name.git"};
    uri.from_string(test_uri);
    ASSERT_EQ("", uri.get_userinfo()); 
};

TEST(URI_test, parse_userinfo_ipv6_with_path){
    URI::Uri uri;
    const auto test_uri{"ldap://[2001:db8::7]/c=GB?objectClass?one"};
    uri.from_string(test_uri);
    ASSERT_EQ("", uri.get_userinfo());  
};

TEST(URI_test, parse_userinfo_ipv6_without_path){
    URI::Uri uri;
    const auto test_uri{"https://user:pass@sub.example.com:8080/path?query#fragment"};
    uri.from_string(test_uri);
    ASSERT_EQ("user:pass", uri.get_userinfo());  
};