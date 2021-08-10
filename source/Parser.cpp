#include <URI/Parser.h>

namespace URI{

    Parser::Parser(){   // za autor "^(\\/\\/[a-z][a-z0-9+.-]*)/"
                        // za semu  ^([a-z][a-z0-9+.-]*):"
                        // 
        
    }
    Parser::~Parser(){

    }
    
    bool Parser::parse(const std::string& uri, std::string& protocol_name){

        std::string wcopy_uri = uri; //working copy uri
        Scheme protocol_scheme =  protocolNormalization(protocol_name);
        define_regex_maping(protocol_scheme);


        if(is_Absolute_URI(wcopy_uri ) == false ){
            return false; 
        }
        // if(is_Relative_URI(wcopy_uri)== false){
        //     return false;
        // }
        return true;
    }

    
   
    std::string Parser::extract_component( std::string& uri_part, std::string rgx_str){
        const std::regex component_rgx(rgx_str);
        const std::string part_copy = uri_part;
        std::smatch match;
       
        
        if (std::regex_search(part_copy.begin(),part_copy.end(), match, component_rgx))
        {

            
            uri_part = std::regex_replace(part_copy,component_rgx,""); 
        }
        return match[1];
    }
    
    bool Parser::is_Absolute_URI(std::string& wcopy_uri){ // ako je URI absolute authority mora da ima host 
       

        auto it = regex_patterns_table.find(URI::scheme_regex_expresions::scheme_reg);
        const std::string scheme_rgx(it->second);

        m_scheme = extract_component( wcopy_uri, scheme_rgx);

        if( m_scheme.length()<=0 )
        {
            return false;
        }
        if(wcopy_uri.length()<= 0)
        {
            return false; 
        }

        auto it2 = regex_patterns_table.find(URI::scheme_regex_expresions::autority);
        const std::string authority_rgx(it2->second);

        m_authority = extract_component(wcopy_uri, authority_rgx );
        if(m_authority.length()<= 0)
        {
            return false;
        }


        auto it3 = regex_patterns_table.find(URI::scheme_regex_expresions::path);
        const std::string path_rgx(it3->second);
        m_path = extract_component(wcopy_uri,path_rgx);
        if(m_path.length()<= 0)
        {
            return false;
        }
        if(wcopy_uri.length() <= 0)
        {
            return false;
        }

            auto it4 = regex_patterns_table.find(URI::scheme_regex_expresions::query);
            const std::string query_rgx(it4->second);
            m_query = extract_component(wcopy_uri,query_rgx );
            
            if(wcopy_uri.length() > 0){

                 auto it5 = regex_patterns_table.find(URI::scheme_regex_expresions::fragments);
                const std::string fragment_rgx(it5->second);
                m_fragment = extract_component(wcopy_uri,fragment_rgx );

                if(wcopy_uri.length() > 0){ 
                    
                    //ne bi trebalo da posle fragmenta ostane nesto 
                    return false; 
                }
            }
            

        
        return true;
        
    }
    bool Parser::is_Relative_URI(std::string&relative_uri){
        

        auto it = regex_patterns_table.find(URI::scheme_regex_expresions::autority);
        const std::string authority_rgx(it->second);
        m_authority = extract_component( relative_uri, authority_rgx );

        

         it = regex_patterns_table.find(URI::scheme_regex_expresions::path);
        const std::string path_rgx(it->second);
        m_path = extract_component(relative_uri,path_rgx);
       

         it = regex_patterns_table.find(URI::scheme_regex_expresions::query);
        const std::string query_rgx(it->second);
        m_query = extract_component(relative_uri,query_rgx );

         it = regex_patterns_table.find(URI::scheme_regex_expresions::fragments);
        const std::string fragment_rgx(it->second);
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
        
        auto it = table.find(protocol_name);
        if (it != table.end())
        {
            protocol_scheme = it->second; 
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