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
#include </home/syrmia/htppparser/include/HTTP/Request.h>

namespace URI
{

    std::vector<std::string> splitString(const std::string& s, std::string rgx_str );
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
        bool validate_scheme(const std::string& uri);
        bool parse(const std::string& uri);
        std::vector<std::string>  extract_component(const std::string& uri,std::string rgx_str);

    private:
        std::string m_scheme;
        std::string m_authority;
        std::string m_path;
        std::string m_query;
        std::string m_fragment;
    };

} // namespace URI
