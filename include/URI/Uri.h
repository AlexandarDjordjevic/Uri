/**
 * @author your name (you@domain.com)
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
        std::string get_path();
        std::string get_query();
        std::string get_fragments();

        void set_scheme(const std::string &scheme);
        void set_authority(const std::string &authority);
        void set_path(const std::string &path);
        void set_query(const std::string &query);
        void set_fragments(const std::string &fragments);

        /**
         * @brief Extracting the scheme from the uri 
         * 
         * @param uri 
         * @return std::string 
         */
        std::string extract_scheme(const std::string& uri);

        /**
         * @brief Extracting the authority from the uri 
         * 
         * @param uri 
         * @return std::string 
         */
        std::string extract_authority(const std::string& uri);
        
        /**
         * @brief Extracting the host from authority
         * 
         * @param authority 
         * @return std::string 
         */
        std::string extract_host();

        /**
         * @brief Extracting the port from the authority 
         * 
         * @param authority 
         * @return std::string 
         */
        std::string extract_port();
        
        /**
         * @brief Extracting the user info from the authority
         * 
         * @param authority 
         * @return std::string 
         */
        std::string extract_userinfo();
        
        /**
         * @brief Extracting all components from uri
         * 
         * @param uri 
         */

        std::string extract_path(const std::string& path);

        void from_string(const std::string& uri);

        //std::string serialize(const std::string& scheme, const std::string& autority, const std::string& path, const std::string& query, const std::string& fragment);



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

} // namespace Namespace
