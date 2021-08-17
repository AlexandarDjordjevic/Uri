#include <URI/Parser.h>

namespace URI{

    Parser::Parser(){   // za autor "^(\\/\\/[a-z][a-z0-9+.-]*)/"
                        // za semu  ^([a-z][a-z0-9+.-]*):"
                        // 
        
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
       
        if(std::regex_search(uri.begin(),uri.end(), match, scheme_rgx)){
            return match[1];
        }
        else{
            return "";
        }
       
    }

    std::string Parser::extract_scheme(const std::string& uri){
        const std::regex scheme_rgx("^([a-zA-Z][a-z0-9+.-]*):");
        
        std::smatch match;
       
        if(std::regex_search(uri.begin(),uri.end(), match, scheme_rgx)){
            return match[1];
        }
        else{
            return "";
        }
       
    }
    std::string Parser::extract_authority(const std::string& uri){
        const std::regex scheme_rgx("^([a-zA-Z][a-z0-9+.-]*):");
        
        std::smatch match;
       
        if(std::regex_search(uri.begin(),uri.end(), match, scheme_rgx)){
            return match[1];
        }
        else{
            return "";
        }
       
    }
    
    void Parser::parse(const std::string& uri, std::string& protocol_name){  // ako je URI absolute authority mora da ima host 
        std::string wcopy_uri = uri; //working copy uri
        Scheme protocol_scheme =  protocolNormalization(protocol_name);
        define_regex_maping(protocol_scheme);

        auto map_result = regex_patterns_table.find(URI::scheme_regex_expresions::scheme_reg);
        const std::string scheme_rgx(map_result->second);

      //  m_scheme = extract_component( wcopy_uri, scheme_rgx);

        
        if(wcopy_uri.length()<= 0)
        {
            return ; 
        }

        map_result = regex_patterns_table.find(URI::scheme_regex_expresions::autority);
        const std::string authority_rgx(map_result->second);

        m_authority = extract_component(wcopy_uri, authority_rgx );
        if(wcopy_uri.length() <= 0)
        {
            return ;
        }
        map_result = regex_patterns_table.find(URI::scheme_regex_expresions::path);
        const std::string path_rgx(map_result->second);
        m_path = extract_component(wcopy_uri,path_rgx);
        if(m_path.length()>0){

            
            absolute_path = true;
        }
        if(wcopy_uri.length() <= 0)
        {
            return;
        }

        map_result = regex_patterns_table.find(URI::scheme_regex_expresions::query);
        const std::string query_rgx(map_result->second);
        m_query = extract_component(wcopy_uri, query_rgx);

        if(wcopy_uri.length() <= 0)
        {
            return;
        }

        map_result = regex_patterns_table.find(URI::scheme_regex_expresions::fragments);
        const std::string fragment_rgx(map_result->second);
        m_fragment = extract_component(wcopy_uri, fragment_rgx);

        if(wcopy_uri.length() <= 0)
        {
            return;
        }
        

    }
    bool Parser::is_Relative_URI(std::string&relative_uri){
        

        auto map_result = regex_patterns_table.find(URI::scheme_regex_expresions::autority);
        const std::string authority_rgx(map_result->second);
        m_authority = extract_component( relative_uri, authority_rgx );

        

         map_result = regex_patterns_table.find(URI::scheme_regex_expresions::path);
        const std::string path_rgx(map_result->second);
        m_path = extract_component(relative_uri,path_rgx);
       

         map_result = regex_patterns_table.find(URI::scheme_regex_expresions::query);
        const std::string query_rgx(map_result->second);
        m_query = extract_component(relative_uri,query_rgx );

         map_result = regex_patterns_table.find(URI::scheme_regex_expresions::fragments);
        const std::string fragment_rgx(map_result->second);
        m_fragment = extract_component(relative_uri,fragment_rgx );

        if(m_authority.length()<= 0 && m_path.length() <= 0 ) 
        {
            return false;
        }  
        return true;
    }
    Scheme Parser::protocolNormalization(std::string &protocol_name)
    {
        
        
        std::for_each(protocol_name.begin(), protocol_name.end(), [](char &c)
        { 
            c = ::tolower(c); 
        });
        Scheme protocol_scheme;
        
        auto map_result = table.find(protocol_name);
        if (map_result != table.end())
        {
            protocol_scheme = map_result->second; 
        }
        return protocol_scheme;
    }
    void Parser::define_regex_maping(Scheme&protocol)
    {
        switch (protocol)
        {
        case (Scheme::http): 
                regex_patterns_table = { 
                {URI::scheme_regex_expresions::scheme_reg,"^(http:)"},
                {URI::scheme_regex_expresions::autority,"^\\/\\/([a-z0-9+.-]*)"},
                {URI::scheme_regex_expresions::path,"^(\\/[a-z0-9+.-\\/]*)"},
                {URI::scheme_regex_expresions::query,"(^\\?[(a-z0-9+)=(a-z0-9+&)]*)"},
                {URI::scheme_regex_expresions::fragments,"(^\\#[(a-z0-9+)=(a-z0-9+&)]*)"}
                };
    

            // code block
            break;
        case (Scheme::https):regex_patterns_table = {
                {URI::scheme_regex_expresions::scheme_reg,"^(https:)"},
                {URI::scheme_regex_expresions::autority,"^\\/\\/([a-z0-9+.-]*)"},
                {URI::scheme_regex_expresions::path,"^(\\/[a-z0-9+.-\\/]*)(\\#|\\?)"},
                {URI::scheme_regex_expresions::query,"(^\\?[(a-z0-9+)=(a-z0-9+&)]*)"},
                {URI::scheme_regex_expresions::fragments,"(^\\#[(a-z0-9+)=(a-z0-9+&)]*)"}
                };
            // code block
            break;
        default:
        regex_patterns_table = {
                {URI::scheme_regex_expresions::scheme_reg,"^([a-z][a-z0-9+.-]*):"},
                {URI::scheme_regex_expresions::autority,"^\\/\\/([a-z0-9+.-]*)"},
                {URI::scheme_regex_expresions::path,"^(\\/[a-z0-9+.-\\/]*)(\\#|\\?)|:\\/[a-z0-9+.-\\/]*)(:)"},
                {URI::scheme_regex_expresions::query,"(^\\?[(a-z0-9+)=(a-z0-9+&)]*)"},
                {URI::scheme_regex_expresions::fragments,"(^\\#[(a-z0-9+)=(a-z0-9+&)]*)"}
                };
            // code block
        }
    }

}//namespace Namespace