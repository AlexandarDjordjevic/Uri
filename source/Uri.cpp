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
        return m_autority;
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

    std::string Uri::extract_scheme(const std::string &uri)
    {
        const std::regex scheme_rgx("^([a-zA-Z][a-z0-9+.-]*):");

        std::smatch match;

        if (std::regex_search(uri.begin(), uri.end(), match, scheme_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
    }

    std::string Uri::extract_authority(const std::string &uri)
    {
        const std::regex authority_rgx("//([\\[A-Za-z0-9@.:\\]]*)");

        std::smatch match;

        if (std::regex_search(uri.begin(), uri.end(), match, authority_rgx))
        {
           m_autority=match[1];
        }
        else
        {
            return "";
        }
    }

    std::string Uri::extract_port(const std::string &authority)
    {
        const std::regex port_rgx("[A-Za-z0-9+.:]@[A-Za-z0-9+-.]*:([0-9+]*)");

        std::smatch match;

        if (std::regex_search(authority.begin(), authority.end(), match, port_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
    }

    std::string Uri::extract_userinfo(const std::string &authority)
    {
        const std::regex port_rgx("([A-Za-z0-9+-.\\]]*)@");

        std::smatch match;

        if (std::regex_search(authority.begin(), authority.end(), match, port_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
    }

    std::string Uri::extract_host(const std::string &authority)
    {
        std::regex port_rgx("([\\[A-Za-z0-9+-.\\]]*)");
        std::size_t found = authority.find("@");
        if (found != std::string::npos)
        {
            port_rgx = std::regex("[A-Za-z0-9+.:]@([\\[A-Za-z0-9+-.\\]]*)");
        }

        std::smatch match;

        if (std::regex_search(authority.begin(), authority.end(), match, port_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
    }
    void Uri::from_string(const std::string& uri){
        
        
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
