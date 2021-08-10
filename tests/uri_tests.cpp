#include <gtest/gtest.h>
#include <URI/Parser.h>

TEST(URI_test, Extract_component_valid){
    URI::Parser parser;
    std::string test_string = "https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_component(test_string,"^([a-z][a-z0-9+.-]*):");
    ASSERT_EQ("https", result);
};
TEST(URI_test, Extract_component_valid2_1){
    URI::Parser parser;
    std::string test_string = "//www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_component(test_string,"^(\\/\\/[a-z][a-z0-9+.-]*)");
   // ASSERT_EQ("//www.google.com",result); 
    ASSERT_TRUE("/jfejs/cdscs/cdcs/?csdsdc#cdsmc"==test_string);
};
TEST(URI_test, Extract_component_valid2_2){
    URI::Parser parser;
    std::string test_string = "//www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_component(test_string,"^(\\/\\/[a-z][a-z0-9+.-]*)");
    ASSERT_EQ("//www.google.com",result); 
};

//"^(\\/[a-z][a-z0-9+.-/]*)(/?)"
TEST(URI_test, Extract_component_valid3_1){
    URI::Parser parser;
    std::string test_string = "/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string result = parser.extract_component(test_string,"^(\\/[a-z][a-z0-9+.-/]*)(/?)");
    ASSERT_EQ("/jfejs/cdscs/cdcs/",result); 
};



TEST(URI_test, parse_valid){
    URI::Parser parser;
    std::string test_protocol("http");

    bool result = parser.parse("http://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_protocol);
    ASSERT_TRUE(result);
};
TEST(URI_test, parse_invalid1){
    URI::Parser parser;
    std::string test_protocol("http");

    bool result = parser.parse("http:///www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_protocol);
    ASSERT_FALSE(result);
};
TEST(URI_test, parse_invalid2){
    URI::Parser parser;
    std::string test_protocol("https");

    bool result = parser.parse("http://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_protocol);
    ASSERT_FALSE(result);
};


TEST(URI_test, isAbsoluteURI_valid){
    URI::Parser parser;
    std::string test_uri = "http://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string test_protocol = "HTTp";

    URI::Scheme sc = parser.protocolNormalization(test_protocol);
    parser.define_regex_maping(sc); 
    bool result = parser.is_Absolute_URI(test_uri);
    
    ASSERT_TRUE(result);
};
 TEST(URI_test, isAbsoluteURI_invalid){
    URI::Parser parser;
    std::string test_uri = "https:/www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string test_protocol = "https";

    URI::Scheme sc = parser.protocolNormalization(test_protocol);
    parser.define_regex_maping(sc); 
    bool result = parser.is_Absolute_URI(test_uri);
    
    ASSERT_FALSE(result);
};
 TEST(URI_test, isAbsoluteURI_invalid2){
    URI::Parser parser;
    std::string test_uri = "https:///www.google.com/jfejs/cdscs/cdcs?csdsdc#cdsmc";
    std::string test_protocol = "https";

    URI::Scheme sc = parser.protocolNormalization(test_protocol);
    parser.define_regex_maping(sc); 
    bool result = parser.is_Absolute_URI(test_uri);
    
    ASSERT_FALSE(result);
};
 TEST(URI_test, isAbsoluteURI_invalid3){
    URI::Parser parser;
    std::string test_uri = "htt:///www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc";
    std::string test_protocol = "https";

    URI::Scheme sc = parser.protocolNormalization(test_protocol);
    parser.define_regex_maping(sc); 
    bool result = parser.is_Absolute_URI(test_uri);
    
    ASSERT_FALSE(result);
};
