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
    using iterator_pairs = std::pair<std::string::const_iterator, std::string::const_iterator>;
    
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
         * @brief Extracting components from the uri
         */
        void from_string(const std::string& uri);

    private:

        /**
         * @brief Extracting the scheme from the uri 
         * 
         * @param uri 
         * @return iterator_pairs 
         */
        iterator_pairs parse_scheme(const std::string& uri);
    
        /**
         * @brief Extracting the authority from the uri 
         * 
         * @param uri_iterators 
         * @return iterator_pairs 
         */
        iterator_pairs parse_authority(iterator_pairs& uri_iterators);

        /**
         * @brief Extracting path from the authority 
         * 
         * @param uri_iterators 
         * @return iterator_pairs 
         */
        iterator_pairs parse_path(iterator_pairs& uri_iterators);

        /**
         * @brief Extracting query from the uri
         * 
         * @param uri_iterators 
         * @return iterator_pairs 
         */
        iterator_pairs parse_query(iterator_pairs& uri_iterators);

        /**
         * @brief Extracting fragment from the uri
         * 
         * @param uri_iterators 
         * @return iterator_pairs 
         */
        iterator_pairs parse_fragment(iterator_pairs& uri_iterators);

        /**
         * @brief Extracting user's info from the authority
         * 
         * @return iterator_pairs 
         */
        iterator_pairs parse_userinfo();

        /**
         * @brief Extracting host from the authority
         * 
         * @param auth_iterators 
         * @return iterator_pairs 
         */
        iterator_pairs parse_host(iterator_pairs& auth_iterators);

        /**
         * @brief Extracting port from the authority 
         * 
         * @param auth_iterators 
         */
        void parse_port(iterator_pairs& auth_iterators);

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