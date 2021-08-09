#include <gtest/gtest.h>
#include <URI/Parser.h>

TEST(URI_test, Extract_component_valid){
    URI::Parser parser;
    std::vector<std::string> test_vector = parser.extract_component("https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc","^([a-z][a-z0-9+.-]*):");
    ASSERT_EQ("https",test_vector[2]);
};
TEST(URI_test, Extract_component_valid1){
    URI::Parser parser;
    std::vector<std::string> test_vector = parser.extract_component("https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc","^([a-z][a-z0-9+.-]*):");
    ASSERT_EQ("//www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_vector[1]);
};
TEST(URI_test, Extract_component_valid2_1){
    URI::Parser parser;
    std::vector<std::string> test_vector = parser.extract_component("//www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc","^(\\/\\/[a-z][a-z0-9+.-]*)");
    ASSERT_EQ("/jfejs/cdscs/cdcs/?csdsdc#cdsmc",test_vector[1]); 
};
TEST(URI_test, Extract_component_valid2_2){
    URI::Parser parser;
    std::vector<std::string> test_vector = parser.extract_component("//www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc","^(\\/\\/[a-z][a-z0-9+.-]*)");
    ASSERT_EQ("//www.google.com",test_vector[2]); 
};

//"^(\\/[a-z][a-z0-9+.-/]*)(/?)"
TEST(URI_test, Extract_component_valid3_1){
    URI::Parser parser;
    std::vector<std::string> test_vector = parser.extract_component("/jfejs/cdscs/cdcs/?csdsdc#cdsmc","^(\\/[a-z][a-z0-9+.-/]*)(/?)");
    ASSERT_EQ("/jfejs/cdscs/cdcs/",test_vector[2]); 
};

TEST(URI_test, Extract_component_valid3_2){
    URI::Parser parser;
    std::vector<std::string> test_vector = parser.extract_component("/jfejs/cdscs/cdcs/?csdsdc#cdsmc","^(\\/[a-z][a-z0-9+.-/]*)(/?)");
    ASSERT_EQ("?csdsdc#cdsmc",test_vector[1]); 
};

TEST(URI_test, parse_valid){
    URI::Parser parser;
    bool result = parser.parse("https://www.google.com/jfejs/cdscs/cdcs/?csdsdc#cdsmc");
    ASSERT_TRUE(result);
};