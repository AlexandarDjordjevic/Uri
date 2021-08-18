#include <URI/Parser.h>

namespace URI{

    Parser::Parser(){ 

    }
    Parser::~Parser(){

    }
    std::string Parser::extract_component( std::string& uri, std::string rgx_str){
        const std::regex scheme_rgx(rgx_str);
        const std::string uri_cw = uri;
        std::smatch match;
        if (std::regex_search(uri_cw.begin(),uri_cw.end(), match, scheme_rgx))
        {
            uri = std::regex_replace(uri_cw,scheme_rgx,""); 
        }
        return match[1];
    }

    std::string Parser::extract_scheme(const std::string& uri){
        const std::regex scheme_rgx("^([a-zA-Z][a-z0-9+.-]*):");
        
        std::smatch match;
       
        if(std::regex_search(uri.begin(),uri.end(), match, scheme_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
       
    }
    std::string Parser::extract_authority(const std::string& uri){
        const std::regex authority_rgx("//([\\[A-Za-z0-9@.:\\]]*)"); 
        
        std::smatch match;
       
        if(std::regex_search(uri.begin(),uri.end(), match, authority_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
       
    }
    bool Parser::parse_authority(const std::string& authority){
        m_userinfo = extract_userinfo(authority);
        m_host = extract_host(authority);
        m_port = extract_port(authority);
        if(m_host!="")
        {
            return true;
        }
        else
        {
            return false;
        }
           
    }
    std::string Parser::extract_port(const std::string& authority){ 
        const std::regex port_rgx("[A-Za-z0-9+.:]@[A-Za-z0-9+-.]*:([0-9+]*)"); 
        
        std::smatch match;
       
        if(std::regex_search(authority.begin(),authority.end(), match, port_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
       
    }
    std::string Parser::extract_userinfo(const std::string& authority){ 
        const std::regex port_rgx("([A-Za-z0-9+-.\\]]*)@"); 
        
        std::smatch match;
       
        if(std::regex_search(authority.begin(),authority.end(), match, port_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
       
    }
    std::string Parser::extract_host(const std::string& authority){ 
        std::regex port_rgx("([\\[A-Za-z0-9+-.\\]]*)"); 
        std::size_t found = authority.find("@");
        if (found != std::string::npos)
        {   
            port_rgx = std::regex("[A-Za-z0-9+.:]@([\\[A-Za-z0-9+-.\\]]*)"); 
        }
        
        std::smatch match;
       
        if(std::regex_search(authority.begin(),authority.end(), match, port_rgx))
        {
            return match[1];
        }
        else
        {
            return "";
        }
       
    }
   

}//namespace Namespace