#include <gtest/gtest.h>
#include <URI/Parser.h>

TEST(URI_test, Extract_scheme_1){
    URI::Parser parser;
    std::string test_string = "https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("https",result); 
};
TEST(URI_test, Extract_scheme_2){
    URI::Parser parser;
    std::string test_string = "Https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("Https",result); 
};
TEST(URI_test, Extract_scheme_3){
    URI::Parser parser;
    std::string test_string = "ftp://ftp.is.co.za/rfc/rfc1808.txt";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("ftp",result); 
};
TEST(URI_test, Extract_scheme_4){
    URI::Parser parser;
    std::string test_string = "ldap://[2001:db8::7]/c=GB?objectClass?one";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("ldap",result); 
};
TEST(URI_test, Extract_scheme_5){
    URI::Parser parser;
    std::string test_string = "mailto:John.Doe@example.com";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("mailto",result); 
};
TEST(URI_test, Extract_scheme_6){
    URI::Parser parser;
    std::string test_string = "news:comp.infosystems.www.servers.unix";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("news",result); 
};
TEST(URI_test, Extract_scheme_7){
    URI::Parser parser;
    std::string test_string = "tel:+1-816-555-1212";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("tel",result); 
};
TEST(URI_test, Extract_scheme_8){
    URI::Parser parser;
    std::string test_string = "telnet://192.0.2.16:80/";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("telnet",result); 
};
TEST(URI_test, Extract_scheme_9){
    URI::Parser parser;
    std::string test_string = "urn:oasis:names:specification:docbook:dtd:xml:4.1.2";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("urn",result); 
};
TEST(URI_test, Extract_scheme_9){
    URI::Parser parser;
    std::string test_string = "git://github.com/user/project-name.git";
    std::string result = parser.extract_scheme(test_string);
    ASSERT_EQ("git",result); 
};


// TEST(URI_test, Extract_component_valid){
//     URI::Parser parser;
//     std::string test_string = "https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
//     std::string result = parser.extract_component(test_string,"^([a-z][a-z0-9+.-]*):");
//     ASSERT_EQ("https", result);
// };
// TEST(URI_test, Extract_component_valid2_1){
//     URI::Parser parser;
//     std::string test_string = "//www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
//     std::string result = parser.extract_component(test_string,"^(\\/\\/[a-z][a-z0-9+.-]*)");
//    // ASSERT_EQ("//www.google.com",result); 
//     ASSERT_TRUE("/jfejs/cdscs/cdcs/?csdsdc#cdsmc"==test_string);
// };
// TEST(URI_test, Extract_component_valid2_2){
//     URI::Parser parser;
//     std::string test_string = "//www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
//     std::string result = parser.extract_component(test_string,"^(\\/\\/[a-z][a-z0-9+.-]*)");
//     ASSERT_EQ("//www.google.com",result); 
// };

// //"^(\\/[a-z][a-z0-9+.-/]*)(/?)"
// TEST(URI_test, Extract_component_valid3_1){
//     URI::Parser parser;
//     std::string test_string = "/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
//     std::string result = parser.extract_component(test_string,"^(\\/[a-z][a-z0-9+.-/]*)(/?)");
//     ASSERT_EQ("/jfejs/cdscs/cdcs/",result); 
// };



// TEST(URI_test, parse_valid){
//     URI::Parser parser;
//     std::string test_protocol("http");

//     bool result = parser.parse("http://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_protocol);
//     ASSERT_TRUE(result);
// };
// TEST(URI_test, parse_invalid1){
//     URI::Parser parser;
//     std::string test_protocol("http");

//     bool result = parser.parse("http:///www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_protocol);
//     ASSERT_FALSE(result);
// };
// TEST(URI_test, parse_invalid2){
//     URI::Parser parser;
//     std::string test_protocol("https");

//     bool result = parser.parse("http://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_protocol);
//     ASSERT_FALSE(result);
// };


// TEST(URI_test, isAbsoluteURI_valid){
//     URI::Parser parser;
//     std::string test_uri = "http://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
//     std::string test_protocol = "HTTp";

//     URI::Scheme sc = parser.protocolNormalization(test_protocol);
//     parser.define_regex_maping(sc); 
//     bool result = parser.is_Absolute_URI(test_uri);
    
//     ASSERT_TRUE(result);
// };
//  TEST(URI_test, isAbsoluteURI_invalid){
//     URI::Parser parser;
//     std::string test_uri = "https:/www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
//     std::string test_protocol = "https";

//     URI::Scheme sc = parser.protocolNormalization(test_protocol);
//     parser.define_regex_maping(sc); 
//     bool result = parser.is_Absolute_URI(test_uri);
    
//     ASSERT_FALSE(result);
// };
//  TEST(URI_test, isAbsoluteURI_invalid2){
//     URI::Parser parser;
//     std::string test_uri = "https:///www.google.com/jfejs/cdscs/cdcs?csdsdc#cdsmc";
//     std::string test_protocol = "https";

//     URI::Scheme sc = parser.protocolNormalization(test_protocol);
//     parser.define_regex_maping(sc); 
//     bool result = parser.is_Absolute_URI(test_uri);
    
//     ASSERT_FALSE(result);
// };
//  TEST(URI_test, isAbsoluteURI_invalid3){
//     URI::Parser parser;
//     std::string test_uri = "htt:///www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
//     std::string test_protocol = "https";

//     URI::Scheme sc = parser.protocolNormalization(test_protocol);
//     parser.define_regex_maping(sc); 
//     bool result = parser.is_Absolute_URI(test_uri);
    
//     ASSERT_FALSE(result);
// };
