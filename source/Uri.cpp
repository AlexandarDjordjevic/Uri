#include <URI/Uri.h>
#include <regex>
#include <iostream>

namespace URI{

    Uri::Uri()
    {

    }

    Uri::~Uri()
    {

    }

    std::string Uri::get_scheme(){
        return m_scheme;
    }

    std::string Uri::get_authority(){
        return m_authority;
    }
    
    std::string Uri::get_port(){
        return m_port;
    }

    std::string Uri::get_host(){
        return m_host;
    }

    std::string Uri::get_userinfo(){
        return m_userinfo;
    }

    std::string Uri::get_path(){
        return m_path;
    }
    
    std::string Uri::get_query(){
        return m_query;
    }
    
    std::string Uri::get_fragments(){
        return m_fragments;
    }
    
    iterator_pairs Uri::parse_scheme(const std::string &uri)
    {
        std::smatch match;

        if (std::regex_search(uri.begin(), uri.end(), match, std::regex(R"(^[a-zA-Z]*[^:])")))
        {
            m_scheme = *match.begin();
        }
        return {(uri.begin() + m_scheme.length()), uri.end()};
    }

    iterator_pairs Uri::parse_authority(iterator_pairs& uri_iterators)
    {
        std::smatch match;
        const std::string authority_start{"//"};

        if (std::regex_search(uri_iterators.first, uri_iterators.second, match, std::regex(R"(\/\/(\[?[a-zA-Z0-9:\_\.@]*\]?)[^\/\?#])")))
        {
            std::string result{*match.begin()};
            m_authority = result.substr(authority_start.length(), result.length());
            return {uri_iterators.first + authority_start.length() + m_authority.length(),uri_iterators.second};
        }
<<<<<<< HEAD
        return {uri_iterators.first,uri_iterators.second};

=======
        return { begin , end };
>>>>>>> 6a46e4973b22d9f85e4970282e6102dfce2ef056
    }

    iterator_pairs Uri::parse_userinfo()
    {
        std::smatch match;
        std::string::const_iterator auth_begin {m_authority.begin()};
        std::string::const_iterator auth_end{ m_authority.begin() + m_authority.length()};
        std::string user_info_ending{"@"};

        if (std::regex_search(auth_begin, auth_end, match, std::regex(R"(([A-Za-z0-9+\-\.\_:]*)@)")))
        {
            std::string result{*match.begin()};
            result.resize(result.length()-user_info_ending.length());
            m_userinfo = result;
            return { auth_begin + m_userinfo.length() + user_info_ending.length() , auth_end };
        }
        return { auth_begin, auth_end };
    }

    iterator_pairs Uri::parse_host(iterator_pairs& auth_iterators)
    {
        std::smatch match;
        if (std::regex_search( auth_iterators.first, auth_iterators.second, match,
                std::regex(
                    R"((^[a-zA-Z][a-zA-Z+\_\.]*)|(\[([([0-9a-fA-F]{0,4}:){0,7}[0-9a-fA-F]{0,4}\])|(([0-9]{0,3}.){3}([0-9]{0,3}){1}))")))
        {
            m_host = *match.begin();
            return {auth_iterators.first + m_host.length(), auth_iterators.second};
        }
        return {auth_iterators.first, auth_iterators.second};
    }

    void Uri::parse_port(iterator_pairs& auth_iterators)
    {
        std::smatch match;
        const std::string port_start{":"};
        if (std::regex_search( auth_iterators.first, auth_iterators.second, match, std::regex(R"(\:([0-9]{0,4}))")))
        {
            std::string result{*match.begin()};
            m_port = result.substr(port_start.length(), result.length()- port_start.length());
        }
    }

    iterator_pairs Uri::parse_path(iterator_pairs& uri_iterators) 
    {
        std::regex regex_path_start_backslash{R"(\/[a-zA-Z0-9+=\_\-@]*[a-zA-Z0-9+.\/\_\-]*)"};
        std::regex regex_path_start_colon{R"(\:([a-zA-Z0-9+\+\-=\.@]*[a-zA-Z0-9+.:]*))"};

        const auto path_start_delimeter_length = 1;

        auto search_path( []
        (
            std::string::const_iterator& begini, std::string::const_iterator& endi,
                std::regex&regex_path, const u_short&start_delimeter_length) -> std::pair<bool, std::string> 
        {
            std::smatch match;
            if (std::regex_search(begini, endi, match, regex_path))
            {
                std::string result{*match.begin()};
                result = result.substr(start_delimeter_length, result.length());
                begini = begini + start_delimeter_length + result.length();

                return { true, result };
            }

            return { false, { } };  
            
        });
            
        std::pair<bool, std::string> match;
        match = search_path(uri_iterators.first, uri_iterators.second, regex_path_start_backslash,path_start_delimeter_length);
        
        if(match.first == false)
        {
            match = search_path(uri_iterators.first, uri_iterators.second, regex_path_start_colon, path_start_delimeter_length);
        }

        m_path = match.second;
        
<<<<<<< HEAD
        return {uri_iterators.first,uri_iterators.second};
    
=======
        return { begin , end };    
>>>>>>> 6a46e4973b22d9f85e4970282e6102dfce2ef056
    }

    iterator_pairs Uri::parse_query(iterator_pairs& uri_iterators){

        std::smatch match;
        const std::string query_start{"?"};

        if (std::regex_search(uri_iterators.first, uri_iterators.second, match, std::regex(R"(\?([a-zA-Z0-9+=&%\+\/\.~\-\_\?]*))")))
        {
            std::string result{*match.begin()};
            m_query = result.substr(query_start.length(), result.length()-query_start.length());
            return {uri_iterators.first+ query_start.length() + m_query.length() ,uri_iterators.second};;
        }
        return {uri_iterators.first,uri_iterators.second};
    }

    iterator_pairs Uri::parse_fragment(iterator_pairs& uri_iterators){
        std::smatch match;
        const std::string fragment_start{"#"};

        if (std::regex_search(uri_iterators.first, uri_iterators.second, match, std::regex(R"(\#([\?a-zA-Z0-9+=&\+\-,\!\[\]\:\-\(\))]*)$)")))
        {
            std::string result{*match.begin()};
            m_fragments = result.substr(fragment_start.length(), result.length()-fragment_start.length());
            
            return {uri_iterators.first+ fragment_start.length() + m_fragments.length(),uri_iterators.second};;
        }
        return {uri_iterators.first,uri_iterators.second};
    }
    
    void Uri::from_string(const std::string& uri){
        iterator_pairs uri_iterators;
        uri_iterators = parse_scheme(uri);
        uri_iterators = parse_authority(uri_iterators);
       
        iterator_pairs auth_iterators;
        auth_iterators = parse_userinfo();
        auth_iterators = parse_host(auth_iterators);
        parse_port(auth_iterators);
        
        uri_iterators = parse_path(uri_iterators);
        uri_iterators = parse_query(uri_iterators);
        uri_iterators = parse_fragment(uri_iterators);
    }  
    
}//namespace URI
