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

    void Uri::set_scheme(const std::string& scheme){
        m_scheme = scheme;
    }

    void Uri::set_authority(const std::string& authority){
        m_authority = authority;
    }

    void Uri::set_path(const std::string& path){
        m_path = path;
    }

    void Uri::set_query(const std::string& query){
        m_query = query;
    }

    void Uri::set_fragments(const std::string& fragments){
        m_fragments = fragments;
    }

    std::pair<std::string::const_iterator, std::string::const_iterator> Uri::parse_scheme(const std::string &uri)
    {
        std::smatch match;

        if (std::regex_search(uri.begin(), uri.end(), match, std::regex(R"(^[a-zA-Z]*[^:])")))
        {
            m_scheme = *match.begin();
        }
        return {(uri.begin() + m_scheme.length()), uri.end()};
    }

    std::pair<std::string::const_iterator, std::string::const_iterator> Uri::parse_authority(std::string::const_iterator& begin, std::string::const_iterator& end)
    {
        std::smatch match;
        const std::string authority_start{"//"};

        if (std::regex_search(begin, end, match, std::regex(R"(\/\/(\[?[a-zA-Z0-9:\_\.@]*\]?)[^\/\?#])")))
        {
            std::string result{*match.begin()};
            m_authority = result.substr(authority_start.length(), result.length());
            return { begin + authority_start.length() + m_authority.length(), end };
        }
        return { begin , end };

    }

    std::pair<std::string::const_iterator, std::string::const_iterator> Uri::parse_userinfo()
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

    std::pair<std::string::const_iterator, std::string::const_iterator> Uri::parse_host(std::string::const_iterator& begin, std::string::const_iterator& end)
    {
        std::smatch match;
        if (std::regex_search(begin, end, match,
                std::regex(
                    R"((^[a-zA-Z][a-zA-Z+\_\.]*)|(\[([([0-9a-fA-F]{0,4}:){0,7}[0-9a-fA-F]{0,4}\])|(([0-9]{0,3}.){3}([0-9]{0,3}){1}))")))
        {
            m_host = *match.begin();
            return { begin + m_host.length(), end };
        }
        return { begin , end };
    }

    void Uri::parse_port(std::string::const_iterator& begin, std::string::const_iterator& end)
    {
        std::smatch match;
        const std::string port_start{":"};
        if (std::regex_search(begin, end, match, std::regex(R"(\:([0-9]{0,4}))")))
        {
            std::string result{*match.begin()};
            m_port = result.substr(port_start.length(), result.length()- port_start.length());
        }
    }

    std::pair<std::string::const_iterator, std::string::const_iterator> Uri::parse_path(std::string::const_iterator& begin, std::string::const_iterator& end) 
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
        match = search_path(begin, end, regex_path_start_backslash,path_start_delimeter_length);
        
        if(match.first == false)
        {
            match = search_path(begin, end, regex_path_start_colon, path_start_delimeter_length);
        }

        m_path = match.second;
        
        return { begin , end };
    
    }

    std::pair<std::string::const_iterator, std::string::const_iterator> Uri::parse_query(std::string::const_iterator& begin, std::string::const_iterator& end){

        std::smatch match;
        const std::string query_start{"?"};

        if (std::regex_search(begin, end, match, std::regex(R"(\?([a-zA-Z0-9+=&%\+\/\.~\-\_\?]*))")))
        {
            std::string result{*match.begin()};
            m_query = result.substr(query_start.length(), result.length()-query_start.length());
            return { begin + query_start.length() + m_query.length() , end };;
        }
        return { begin , end };
    }

    std::pair<std::string::const_iterator, std::string::const_iterator> Uri::parse_fragment(std::string::const_iterator& begin, std::string::const_iterator& end){
        std::smatch match;
        const std::string fragment_start{"#"};

        if (std::regex_search(begin, end, match, std::regex(R"(\#([\?a-zA-Z0-9+=&\+\-,\!\[\]\:\-\(\))]*)$)")))
        {
            std::string result{*match.begin()};
            m_fragments = result.substr(fragment_start.length(), result.length()-fragment_start.length());
            
            return { begin + fragment_start.length() + m_fragments.length(), end };;
        }
        return { begin , end };
    }
    
    void Uri::from_string(const std::string& uri){
        std::pair<std::string::const_iterator,std::string::const_iterator> uri_iterators;
        uri_iterators = parse_scheme(uri);
        uri_iterators = parse_authority(uri_iterators.first, uri_iterators.second);
       
        std::pair<std::string::const_iterator,std::string::const_iterator> auth_iterators;
        auth_iterators = parse_userinfo();
        auth_iterators = parse_host(auth_iterators.first, auth_iterators.second);
        parse_port(auth_iterators.first, auth_iterators.second);
        
        uri_iterators = parse_path(uri_iterators.first, uri_iterators.second);
        uri_iterators = parse_query(uri_iterators.first, uri_iterators.second);
        uri_iterators = parse_fragment(uri_iterators.first, uri_iterators.second);
    }  
    
}//namespace URI
