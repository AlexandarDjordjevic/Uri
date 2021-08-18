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
        void parse(const std::string& uri,std::string& protocol_name);

        std::string extract_component(std::string& uri,std::string rgx_str);
        /**
         * @brief Extraction string from uri by rgx_str pattern and deletes that string from uri
         */
        std::string extract_scheme(const std::string& uri);
        /**
         * @brief Extracting the scheme from the uri if it exists, otherwise returns an empty string
         */
        std::string extract_authority(const std::string& uri);
        /**
         * @brief Extracting the authority from the uri if it exists, otherwise returns an empty string
         */
        std::string extract_host(const std::string& authority);
        /**
         * @brief Extracting the host from authority 
         */
        std::string extract_port(const std::string& authority);
        /**
         * @brief Extracting the port from the authority if it exists, otherwise returns an empty string
         */
        std::string extract_userinfo(const std::string& authority);
        /**
         * @brief Extracting the user info from the uri if it exists, otherwise returns an empty string
         */
        bool parse_authority(const std::string& authority);
        /**
         * @brief  
         */
    
    private:
        std::string m_scheme;
        std::string m_authority;
        std::string m_userinfo;
        std::string m_host;
        std::string m_port;
    };
    

} // namespace URI
