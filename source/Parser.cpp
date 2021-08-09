#include <URI/Parser.h>

namespace URI{

    Parser::Parser(){   // za autor "^(\\/\\/[a-z][a-z0-9+.-]*)/"
                        // za semu  ^([a-z][a-z0-9+.-]*):"
                        // 
        
    }
    Parser::~Parser(){

    }
    //ne znam nacim da ukljucim ovu funkciju iz HTTP biblioteke 
    std::vector<std::string> splitString(const std::string& s, std::string rgx_str ){  
        std::vector<std::string> tokens;
        std::regex pattern (rgx_str);
        std::sregex_token_iterator iter(s.begin(),s.end(), pattern,-1);
        std::sregex_token_iterator end;
        while(iter != end){
            tokens.push_back(*iter);
            ++iter;
        }
        return tokens;
    }
    bool Parser::parse(const std::string& uri){
        
        std::vector<std::string> uri_components = extract_component(uri,"^([a-z][a-z0-9+.-]*):");
        if(uri_components.size()>0){
            std::string scheme = uri_components[2];
            m_scheme = scheme;
        }
        else{
            return false;
        }
        uri_components = extract_component(uri_components[1], "^(\\/\\/[a-z][a-z0-9+.-]*)"); 
        if(uri_components.size()>0){
            if(uri_components[2].length()>0){
                std::string authority = uri_components[2];
                m_authority = authority;
            }
        }
        uri_components = extract_component(uri_components[1], "^(\\/[a-z][a-z0-9+.-/]*)(/?)"); 
        if(uri_components.size()>0){
            if(uri_components[2].length()>0){
                std::string path = uri_components[2];
                m_path = path;
            }
        }
        else{
            return false;
        }
        uri_components = extract_component(uri_components[1], "^(\\/[a-z][a-z0-9+.-/]*)(/?)"); 
        if(uri_components.size()>0){
            if(uri_components[2].length()>0){
                std::string path = uri_components[2];
                m_path = path;
            }
        }
        uri_components = extract_component(uri_components[1], "^(\\?[a-z][a-z0-9+.-=&]*)(#)"); 
        if(uri_components.size()>0){
            if(uri_components[2].length()>0){
                std::string query = uri_components[2];
                m_query = query;
            }
        }
        uri_components = extract_component(uri_components[1], "^(\\?[a-z][a-z0-9+.-=&]*)(#)"); 
        if(uri_components.size()>0){
            if(uri_components[2].length()>0){
                std::string fragments = uri_components[2];
                m_fragment = fragments;
            }
        }

        return true;
    }

    
   
    std::vector<std::string> Parser::extract_component(const std::string& uri, std::string rgx_str){
        std::regex rgx(rgx_str);
        std::smatch match;
        std::vector<std::string> component_uri;

        if (std::regex_search(uri.begin(), uri.end(), match, rgx)){
            std::string k = match[1];

            component_uri = URI::splitString(uri, rgx_str);
            component_uri.push_back(k);
        }
        return component_uri;
    }
    


    
    
    

}//namespace Namespace