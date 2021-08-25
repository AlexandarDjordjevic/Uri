#include <URI/Uri.h>
#include <regex>

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

    void Uri::parse_scheme(const std::string &uri)
    {
        std::smatch match;

        if (std::regex_search(uri.begin(), uri.end(), match, std::regex("^[a-zA-Z]*[^:]")))
        {
            m_scheme = *match.begin();
        }
    }

    void Uri::parse_authority(const std::string &uri)
    {
        std::smatch match;
        const std::string authority_start{"//"};

        if (std::regex_search(uri.begin(), uri.end(), match, std::regex(R"(\/\/(\[?[a-zA-Z0-9:.@]*\]?)[^\/\?#])")))
        {
            std::string result{*match.begin()};
            m_authority = result.substr(authority_start.length(), result.length());
        }
    }

    void Uri::parse_port(const std::string &authority)
    {
        std::smatch match;
        const std::string port_start{"_:"};

        if (std::regex_search(authority.begin(), authority.end(), match, std::regex(R"(\]:([0-9]{0,4})[^\/?#]|[a-zA-Z]:([0-9]{0,4})[^\/?#])")))
        {
            std::string result{*match.begin()};
            m_port = result.substr(port_start.length(), result.length());
        }
    }

    void Uri::parse_userinfo(const std::string &authority)
    {
        std::smatch match;

        if (std::regex_search(authority.begin(), authority.end(), match, std::regex(R"(([A-Za-z0-9+-.:]*)@)")))
        {
            m_port = *match.begin();
        }
    }

    void Uri::parse_host(const std::string &authority)
    {
        std::smatch match;
        const std::string authority_delimiter{"@"};
        auto position{authority.find(authority_delimiter)};
        std::string authority_part = (position != std::string::npos)
                                         ? authority.substr(position + authority_delimiter.length())
                                         : authority;

        if (
            std::regex_search(
                authority_part.cbegin(), authority_part.cend(), match,
                std::regex(
                    R"((^[a-zA-Z][a-zA-Z+.]*)|(\[([([0-9a-fA-F]{0,4}:){0,7}[0-9a-fA-F]{0,4}\])|(([0-9]{0,3}.){3}([0-9]{0,3}){1}))")))
        {
            m_host = *match.begin();
        }
    }

    void Uri::from_string(const std::string& uri){
        parse_scheme(uri);
        parse_authority(uri);
        parse_userinfo(m_authority);
        parse_host(m_authority);
        parse_port(m_authority);
    }  
    
}//namespace URI
