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

    std::string Uri::extract_scheme(const std::string &uri)
    {
        const std::regex scheme_rgx("^([a-zA-Z][a-z0-9+.-]*):");
        std::smatch match;
        if (std::regex_search(uri.begin(), uri.end(), match, scheme_rgx))
        {
            m_scheme = match[1];  
        }
        return m_scheme;
    }

    std::string Uri::extract_authority(const std::string &uri)
    {
        const std::regex authority_rgx("//([\\[A-Za-z0-9@.:\\]]*)");
        std::smatch match;
        if (std::regex_search(uri.begin(), uri.end(), match, authority_rgx))
        {

           m_autority=match[1];
        
        }
        return m_authority;
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
            //match[0] is meched chars from first to last in regex 
            //other indexes are wholes separated in parentheses 
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

        extract_scheme(uri);

    }
    // std::string Uri::extract_path(const std::string& path){
    //      std::smatch match;
    //      std::regex path_rgx("^(\\/|:)[a-zA-Z][a-z0-9+.-](#|\\?|)*");

    //      if(m_autority == ""){
            
    //         if (std::regex_search(path.begin(), path.end(), match, path_rgx))
    //         {
    //             m_path=match[1];
    //         }
    //         else
    //         {
    //             m_path="";
    //         }

    //     }
    //     else{
    //         if (std::regex_search(path.begin(), path.end(), match, path_rgx))
    //         {
    //             m_path=match[1];
    //         }
            
    //     }
       
    // }
    

}//namespace Namespace
