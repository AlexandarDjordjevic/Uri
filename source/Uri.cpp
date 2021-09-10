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

    remining_uri Uri::parse_scheme(const std::string &uri)
    {
        std::smatch match;

        if (std::regex_search(uri.begin(), uri.end(), match, std::regex(R"(^[a-zA-Z]*[^:])")))
        {
            m_scheme = *match.begin();
        }
        return {(uri.begin() + m_scheme.length()), uri.end()};
    }

    remining_uri Uri::parse_authority(const remining_uri& uri_positions)
    {
        std::smatch match;
        const std::string authority_start{"//"};

        if (std::regex_search(uri_positions.first, uri_positions.second, match, std::regex(R"(\/\/(\[?[a-zA-Z0-9:\_\.@]*\]?)[^\/\?#])")))
        {
            std::string result{*match.begin()};
            m_authority = result.substr(authority_start.length(), result.length());
            return {uri_positions.first + authority_start.length() + m_authority.length(),uri_positions.second};
        }
        return { uri_positions};

    }

    remining_uri Uri::parse_userinfo()
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

    remining_uri Uri::parse_host(const remining_uri& auth_positions)
    {
        std::smatch match;
        if (std::regex_search( auth_positions.first, auth_positions.second, match,
                std::regex(
                    R"((^[a-zA-Z][a-zA-Z+\_\.]*)|(\[([([0-9a-fA-F]{0,4}:){0,7}[0-9a-fA-F]{0,4}\])|(([0-9]{0,3}.){3}([0-9]{0,3}){1}))")))
        {
            m_host = *match.begin();
            return {auth_positions.first + m_host.length(), auth_positions.second};
        }
        return {auth_positions};
    }

    void Uri::parse_port(const remining_uri& auth_positions)
    {
        std::smatch match;
        const std::string port_start{":"};
        if (std::regex_search( auth_positions.first, auth_positions.second, match, std::regex(R"(\:([0-9]{0,4}))")))
        {
            std::string result{*match.begin()};
            m_port = result.substr(port_start.length(), result.length()- port_start.length());
        }
    }

    remining_uri Uri::parse_path(const remining_uri& uri_positions) 
    {
        std::regex regex_path_start_backslash{R"(\/[a-zA-Z0-9+=\_\-@]*[a-zA-Z0-9+.\/\_\-]*)"};
        std::regex regex_path_start_colon{R"(\:([a-zA-Z0-9+\+\-=\.@]*[a-zA-Z0-9+.:]*))"};

        const auto path_start_delimeter_length = 1;
        remining_uri uri_path_part{uri_positions};

        const auto search_path( []
        (remining_uri& uri_path_part, std::regex&regex_path, const u_short&start_delimeter_length) -> std::pair<bool, std::string> 
        {
            std::smatch match;
            if (std::regex_search(uri_path_part.first, uri_path_part.second, match, regex_path))
            {
                std::string result{*match.begin()};
                result = result.substr(start_delimeter_length, result.length());
                uri_path_part.first = uri_path_part.first + start_delimeter_length + result.length();

                return { true, result };
            }

            return { false, { } };  
            
        });
            
        std::pair<bool, std::string> match;
        match = search_path(uri_path_part, regex_path_start_backslash, path_start_delimeter_length);
        
        if(match.first == false)
        {
            match = search_path(uri_path_part, regex_path_start_colon, path_start_delimeter_length);
        }

        m_path = match.second;
        
        return {uri_path_part};
    
    }

    remining_uri Uri::parse_query(const remining_uri& uri_positions){

        std::smatch match;
        const std::string query_start{"?"};

        if (std::regex_search(uri_positions.first, uri_positions.second, match, std::regex(R"(\?([a-zA-Z0-9+=&%\+\/\.~\-\_\?]*))")))
        {
            std::string result{*match.begin()};
            m_query = result.substr(query_start.length(), result.length()-query_start.length());
            return {uri_positions.first+ query_start.length() + m_query.length() ,uri_positions.second};;
        }
        return {uri_positions};
    }

    remining_uri Uri::parse_fragment(const remining_uri& uri_positions){
        std::smatch match;
        const std::string fragment_start{"#"};

        if (std::regex_search(uri_positions.first, uri_positions.second, match, std::regex(R"(\#([\?a-zA-Z0-9+=&\+\-,\!\[\]\:\-\(\))]*)$)")))
        {
            std::string result{*match.begin()};
            m_fragments = result.substr(fragment_start.length(), result.length()-fragment_start.length());
            
            return {uri_positions.first+ fragment_start.length() + m_fragments.length(),uri_positions.second};;
        }
        return {uri_positions};
    }
    
    void Uri::from_string(const std::string& uri){
        remining_uri uri_positions;
        uri_positions = parse_scheme(uri);
        uri_positions = parse_authority(uri_positions);
       
        remining_uri auth_positions;
        auth_positions = parse_userinfo();
        auth_positions = parse_host(auth_positions);
        parse_port(auth_positions);
        
        uri_positions = parse_path(uri_positions);
        uri_positions = parse_query(uri_positions);
        uri_positions = parse_fragment(uri_positions);
    }  
    
}//namespace URI
