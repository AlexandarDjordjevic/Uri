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
        extract_userinfo();
        extract_host();
        extract_port();
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

        if (std::regex_search(uri.begin(), uri.end(), match, std::regex(R"(\/\/(\[?[a-zA-Z0-9:.]*\]?)[^\/\?#])")))
        {
            std::string result{*match.begin()};
            m_authority = result.substr(authority_start.length(), result.length());
        }
    }

    std::string Uri::extract_port()
    {
        const std::regex port_rgx("[A-Za-z0-9+.:@\\[\\]]*:([0-9+]*)");
        std::smatch match;
        const std::string auth_wc = m_authority;
        if (std::regex_search(auth_wc.begin(), auth_wc.end(), match, port_rgx))
        {
             m_port = match[1];
        }
        return m_port;
    }

    std::string Uri::extract_userinfo()
    {
        const std::regex port_rgx("([A-Za-z0-9+-.\\]]*)@");
        std::smatch match;
        const std::string auth_wc = m_authority;
        if (std::regex_search(auth_wc.begin(), auth_wc.end(), match, port_rgx))
        {
             m_userinfo = match[1];
        }
        return m_userinfo;
    }

    std::string Uri::extract_host()
    {
        std::regex port_rgx("(\\[([0-9a-fA-F]{0,4}:){7}[0-9a-fA-F]{0,4}\\]|([0-9]{1,3}.){3}[0-9]{1,3}|[A-Za-z0-9+.]*):"); 
        std::size_t found = m_authority.find("@");
        if (found != std::string::npos)
        {       
            port_rgx = std::regex("[A-Za-z0-9+.:]@([\\[A-Za-z0-9+-.\\]]*)"); 
        }
        std::smatch match;
        const std::string auth_wc = m_authority;
        if (std::regex_search(auth_wc.begin(), auth_wc.end(), match, port_rgx))
        {
             m_host = match[1];
        }
        return m_host;
    }
    
    void Uri::from_string(const std::string& uri){
        parse_scheme(uri);
        parse_authority(uri);
        extract_userinfo();
        extract_host();
        extract_port();
    }   

}//namespace URI
