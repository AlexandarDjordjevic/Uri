/**
 * @author Andejla14 & krrle
 * @brief 
 * @version 0.1
 * @date 2021-08-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once
#include <string>

namespace URI
{
    class Uri{
    public:

        /**
         * @brief Default constructor
         * 
         */
        Uri();

        /**
         * @brief Default destructor
         * 
         */
        ~Uri();

        Uri(const Uri&) = delete;
        Uri& operator=(const Uri&) = delete;
        Uri(Uri&&) = delete;
        Uri& operator=(Uri &&) = delete;

        std::string get_scheme();
        std::string get_authority();
        std::string get_port();
        std::string get_host();
        std::string get_userinfo();
        std::string get_path();
        std::string get_query();
        std::string get_fragments();

        void set_scheme(const std::string &scheme);
        void set_authority(const std::string &authority);
        void set_path(const std::string &path);
        void set_query(const std::string &query);
        void set_fragments(const std::string &fragments);

        /**
         * @brief Extracting components from the uri
         */
        void from_string(const std::string& uri);
        /**
         * @brief Extracting user's info from the authority
         * 
         * @param authority
         */
        void parse_userinfo(const std::string &authority);
        
        /**
         * @brief Extracting host from the authority
         * 
         * @param authority
         */
        void parse_host(const std::string &authority);

    private:
    
        /**
         * @brief Extracting the scheme from the uri 
         * 
         * @param uri
         */
        void parse_scheme(const std::string& uri);

        /**
         * @brief Extracting the authority from the uri 
         * 
         * @param uri 
         */
        void parse_authority(const std::string& uri);
        
        

        /**
         * @brief Extracting port from the authority 
         * 
         * @param authority
         */
        void parse_port(const std::string &authority);
        

    private:
        std::string m_scheme;
        std::string m_authority;
        std::string m_port;
        std::string m_host;
        std::string m_userinfo;
        std::string m_path;
        std::string m_query;
        std::string m_fragments;
    };

} // namespace URI
