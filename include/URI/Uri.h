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

        /**
         * @brief Get the scheme object
         * 
         * @return std::string 
         */
        std::string get_scheme();

        /**
         * @brief Get the authority object
         * 
         * @return std::string 
         */
        std::string get_authority();

        /**
         * @brief Get the port object
         * 
         * @return std::string 
         */
        std::string get_port();

        /**
         * @brief Get the host object
         * 
         * @return std::string 
         */
        std::string get_host();

        /**
         * @brief Get the userinfo object
         * 
         * @return std::string 
         */
        std::string get_userinfo();
        
        /**
         * @brief Get the path object
         * 
         * @return std::string 
         */
        std::string get_path();

        /**
         * @brief Get the query object
         * 
         * @return std::string 
         */
        std::string get_query();

        /**
         * @brief Get the fragments object
         * 
         * @return std::string 
         */
        std::string get_fragments();

        /**
         * @brief Set the scheme object
         * 
         * @param scheme 
         */
        void set_scheme(const std::string &scheme);

        /**
         * @brief Set the authority object
         * 
         * @param authority 
         */
        void set_authority(const std::string &authority);

        /**
         * @brief Set the path object
         * 
         * @param path 
         */
        void set_path(const std::string &path);
        
        /**
         * @brief Set the query object
         * 
         * @param query 
         */
        void set_query(const std::string &query);

        /**
         * @brief Set the fragments object
         * 
         * @param fragments 
         */
        void set_fragments(const std::string &fragments);

        /**
         * @brief Extracting components from the uri
         */
        void from_string(const std::string& uri);

    private:

        /**
         * @brief Extracting the scheme from the uri 
         * 
         * @param uri 
         * @return std::pair<std::string::const_iterator, std::string::const_iterator> 
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_scheme(const std::string& uri);
    
        /**
         * @brief Extracting the authority from the uri 
         * 
         * @param begin 
         * @param end
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_authority(std::string::const_iterator& begin, std::string::const_iterator& end);

        /**
         * @brief Extracting path from the authority 
         * 
         * @param begin 
         * @param end 
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_path(std::string::const_iterator &begin, std::string::const_iterator &end);

        /**
         * @brief Extracting query from the uri
         * 
         * @param begin 
         * @param end  
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_query(std::string::const_iterator& begin, std::string::const_iterator& end);

        /**
         * @brief Extracting fragment from the uri
         * 
         * @param begin 
         * @param end 
         * @return std::pair<std::string::const_iterator, std::string::const_iterator> 
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_fragment(std::string::const_iterator& begin, std::string::const_iterator& end);

        /**
         * @brief Extracting user's info from the authority
         * 
         * @param begin 
         * @param authority 
         * @return std::pair<std::string::const_iterator, std::string::const_iterator> 
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_userinfo(std::string::const_iterator& begin, const std::string& authority);

        /**
         * @brief Extracting host from the authority
         * 
         * @param begin 
         * @param end 
         * @return std::pair<std::string::const_iterator, std::string::const_iterator> 
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_host(std::string::const_iterator& begin, std::string::const_iterator& end);

        /**
         * @brief Extracting port from the authority 
         * 
         * @param begin 
         * @param end 
         * @return std::pair<std::string::const_iterator, std::string::const_iterator> 
         */
        std::pair<std::string::const_iterator, std::string::const_iterator> parse_port(std::string::const_iterator& begin, std::string::const_iterator& end);

    private:

        /**
         * @brief Value for scheme from uri
         * 
         */
        std::string m_scheme;

        /**
         * @brief Value for authority from uri
         * 
         */
        std::string m_authority;

        /**
         * @brief Value for port from authority
         * 
         */
        std::string m_port;

        /**
         * @brief Value for host from authority
         * 
         */
        std::string m_host;

        /**
         * @brief Value for userinfo from authority
         * 
         */
        std::string m_userinfo;

        /**
         * @brief Value for path from uri
         * 
         */
        std::string m_path;

        /**
         * @brief Value for querry from uri
         * 
         */
        std::string m_query;

        /**
         * @brief Value for fragments from uri
         * 
         */
        std::string m_fragments;
       
    };

}//namespace URI