/**
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-08-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <iostream>
#include <vector>
#include <regex>

namespace URI
{
    enum class Scheme{
        http,
        https
    };
    enum class scheme_regex_expresions {
        scheme_reg,
        autority,
        path,
        query,
        fragments
        
    };
    static std::map<std::string, Scheme> const table = { 
        {"http",Scheme::http},
        {"https",Scheme::https}
    };

    
    
    class Parser{
    public:
        /**
         * @brief Default constructor
         * 
         */
        Parser();

        /**
         * @brief Default destructor
         * 
         */
        ~Parser();
        
        Parser(const Parser&) = delete;
        Parser& operator=(const Parser&) = delete;
        Parser(Parser&&) = delete;
        Parser& operator=(Parser &&) = delete;
        
        bool psrse_uri(const std::string& uri);
        bool parse(const std::string& uri,std::string& protocol_name);

        bool is_Absolute_URI(std::string& uri);
        bool is_Relative_URI(std::string& relative_uri);
        Scheme protocolNormalization(std::string& protocol_name);
        void define_regex_maping(Scheme&protocol);

        std::string athstr(){
            return regex_patterns_table.find(scheme_regex_expresions::autority)->second;
        }
       
        std::string extract_component(std::string& uri,std::string rgx_str);

    private:
        std::string m_scheme;
        std::string m_authority;
        std::string m_path;
        std::string m_query;
        std::string m_fragment;
        std::map< scheme_regex_expresions,const std::string> regex_patterns_table;
        bool isabsolute_URI = false; // this is one of four types of HTTP-Request URI
        bool has_net_path = false;   // authority + abs_path 
        bool has_absolute_path=false; // this is one of four types of HTTP-Request URI
        bool has_relative_path = false;
        bool has_empty_path = false;
    };
    

} // namespace URI
