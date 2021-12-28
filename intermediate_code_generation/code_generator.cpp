#include "code_generator.h"

#include <tuple>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

void debug(std::vector<std::string>::iterator it1,std::vector<std::string>::iterator it2)
{
    for(;it1 != it2; ++it1)
        std::cout << *it1 << "\n";
}

bool generator::is_type(const std::string & str)
{
    bool fundomental_type = [&]()->bool{ 
        return  (str == "int" || str == "floath" || str == "char" || str == "double"  || str == "string") ? true : false ;
    }() ;
    auto my_type = std::find_if(vec_c_class.begin(),vec_c_class.end(),[&](c_class & ob){
        if(ob.class_name == str) return true ;
        return false ;
    }) ;
    return fundomental_type || (my_type != vec_c_class.end()) ? true : false ;
}

void generator::generate_user_ctor(std::vector<std::string>::iterator first,std::vector<std::string>::iterator last,std::vector<std::string> & vec)
{
    std::string str_tmp{","} ;
    std::for_each(first + 3,last + 1,[&](std::string&str) {
        str_tmp += str ;
    }) ;
    auto pos = vec.erase(first + 2,last) ;
    vec.insert(pos + 1,"_" + *first + "(&" + *(first + 1) + str_tmp) ;
}

void generator::generate_user_coll(std::vector<std::string> & vec,const std::vector<std::pair<std::string,std::string>> & class_obj_names)
{
    for(int i = 0 ; i < vec.size() ; ++i)
    {
        auto pos = std::find_if(class_obj_names.cbegin(),class_obj_names.cend(),[&](const std::pair<std::string,std::string> & str) {
            if(str.second == vec[i] && vec[i + 1] == ".") 
            {
                return true ;
            }
            return false ;
        }) ;

        if(pos != class_obj_names.end())
        {
            std::for_each(vec_c_class.begin(),vec_c_class.end(),[&](c_class & obj) {
                std::find_if(obj.members.begin(),obj.members.end(),[&](std::tuple<char,std::string,std::string,std::string> & member) {
                    if(std::get<2>(member) == vec[i + 2]) {
                    if(std::get<0>(member) == 'e') { std::cout << "hangstaci hly es JS chi" << std::endl ; throw ; }
                        if(obj.class_name != pos->first) {
                            std::string mName = "subObj." + vec[i + 2] ;
                            auto mpos = vec.erase(vec.begin() + i + 2) ;
                            vec.insert(mpos,mName) ;
                        }
                        return true ;
                    }
                    return false ;
                }) ;
                std::for_each(obj.function.begin() , obj.function.end() ,[&] (std::pair<char,std::vector<std::string>>& f) {
                    if(vec[i + 2] == f.second[1]) 
                    {
                        if(f.first == 'e') { std::cout << "hangstaci hly es JS chi" << std::endl ; throw ; } 
                        std::string obname = vec[i] ;
                        if(obj.class_name != pos->first) {
                            obname += ".subObj"  ;
                        }
                        std::string fooname = vec[i + 2] ;
                        auto line_pos = std::find(vec.begin() + i,vec.end(),";") ;
                        std::string str_tmp{","};
                        std::for_each(vec.begin() + i + 4,line_pos ,[&](std::string&str) {
                            str_tmp += str ;
                        }) ;
                        auto pos = vec.erase(vec.begin() + i ,line_pos ) ;
                        vec.insert(pos , fooname + "(&" + obname + str_tmp) ;
                    }
                }) ;
            }) ;
        }
    }
}

void generator::generate_c_base_pointer(std::vector<std::string> & vec,const std::vector<std::pair<std::string,std::string>>& class_obj_names,
const std::vector<std::pair<std::string,std::string>>& pointers) 
{
        auto obj_or_pointer = [&](const std::string& str)->bool {
        for(const auto & it: class_obj_names) 
        {
            if(it.second == str) return true ;
        }
        for(const auto & it: pointers) 
        {
            if(it.second == str) return true ;
        }
        return false ;
    } ;
    auto return_type_name = [&](const std::string& str)->std::string {
        for(const auto & it: class_obj_names) 
        {
            if(it.second == str) return it.first ;
        }
        for(const auto & it: pointers) 
        {
            if(it.second == str) return it.first ;
        }
        return "" ;
    } ;
    for(int i = 0 ; i < vec.size() ; ++i)
    {
        auto pointer_position = std::find_if(pointers.begin(),pointers.end(),[&](const std::pair<std::string,std::string> & p) {
            return p.second == vec[i] ;
        }) ;
        if(pointer_position != pointers.end())
        {
            auto line_pos = std::find(vec.begin() + i , vec.end(), ";") ;
            std::string vptr_type_name ;
            std::string tmp_type_name ;
            std::for_each(vec.begin() + i , line_pos,[&](std::string& str) {
                if(obj_or_pointer(str)) {
                    vptr_type_name = return_type_name(str) ;
                    tmp_type_name = return_type_name(str) ;
                }
                if(is_type(str)) {
                    vptr_type_name = str ;
                    str = pointer_position->first ;
                    tmp_type_name = str ;
                }
            }) ;
            
            vec.insert(line_pos + 1,vec[i] + "->v_ptr = (" + pointer_position->first + "_vtable*)" + "&" + vptr_type_name +"table ;") ;
            if(pointer_position->first !=  tmp_type_name) {
                vec.erase(vec.begin() + i , line_pos + 1) ;
            }
        }
    }
}

void generator::generate_user(std::vector<std::string> & vec)
{
    std::vector<std::pair<std::string,std::string>> class_obj_names ;
    std::vector<std::pair<std::string,std::string>> pointers ;
    
    for(int i = 0; i < vec.size() ; ++i) 
    {
        auto pos = std::find_if(vec_c_class.begin(),vec_c_class.end(),[&](c_class & obj) {
            if(obj.class_name == vec[i] && parser::word(vec[i + 1])) 
            {
                class_obj_names.push_back(std::make_pair(vec[i],vec[i + 1])) ;
                return true ;
            } else if(obj.class_name == vec[i] && vec[i + 1] == "*")
            {
                pointers.push_back(std::make_pair(vec[i],vec[i + 2])) ;
                return true ;
            }
            return false ;
        }) ;
        if(pos != vec_c_class.end() ) 
        {
            std::vector<std::string>::iterator line_pos = std::find(vec.begin() + i, vec.end(), ";") ;
            if(line_pos - (vec.begin() + i) > 2 && (*(vec.begin() + i + 1) != "*")) 
            {
                auto it = vec.begin() + i ;
                generate_user_ctor(it, line_pos,vec) ;
            }
        }
    }
    generate_c_base_pointer(vec,class_obj_names,pointers) ;

    generate_user_coll(vec,class_obj_names) ;
}

void generator::generate_c_functions(std::ofstream & ofile,c_class obj)
{
    for(int i = 0 ; i < obj.function.size() ; ++i)
    {
        if(obj.function[i].second[0] == "static") 
        {
            obj.function[i].second[0] = "" ;
            break ;
        }
        auto pos = std::find(obj.function[i].second.begin(),obj.function[i].second.end(),"(") ;
        int dis = std::distance(obj.function[i].second.begin(),pos) ;
        obj.function[i].second.insert(obj.function[i].second.begin() + dis + 1,obj.class_name) ;
        obj.function[i].second.insert(obj.function[i].second.begin() + dis + 2,"*") ;
        obj.function[i].second.insert(obj.function[i].second.begin() + dis + 3,"that") ;
        if(*(obj.function[i].second.begin() + dis + 4) != ")")
            obj.function[i].second.insert(obj.function[i].second.begin() + dis + 4,",") ;
        auto pos2 = std::find(obj.function[i].second.begin(),obj.function[i].second.end(),")") ;
        int dis2 = std::distance(obj.function[i].second.begin(),pos2) ;
        for(int j = dis2 ; j < obj.function[i].second.size() ; ++j)
        {
            auto pos = std::find_if(obj.members.begin(),obj.members.end(),[&](std::tuple<char,std::string,std::string,std::string> t){
                return obj.function[i].second[j] == std::get<2>(t) ;
            }) ;
            if(pos != obj.members.end() && obj.function[i].second[j - 1] != "->" && (obj.function[i].second[j - 2] != obj.function[i].second[j]))
            {
                obj.function[i].second[j] = "that->" + obj.function[i].second[j] ;
            } else if(pos != obj.members.end() && obj.function[i].second[j - 1] == "->" )
            {
                obj.function[i].second[j - 2]  = "that" ;
            }
        }
    }
    for(const auto & it: obj.function)
    {
        for(const auto & j: it.second) {
            c_funtions.push_back(j) ;
        }
        c_funtions.push_back("\n") ;
    }
}

void generator::generate_virtual_funtions(std::ofstream & ofile,const c_class & obj) const
{
    std::vector<std::vector<std::string>> functions = obj.v_table.get_virtual_funtions() ;
    std::for_each(functions.begin(),functions.end(),[&](std::vector<std::string> & function){
        std::copy(function.begin(),function.end(),std::ostream_iterator<std::string>(ofile)) ;
        ofile << ";\n" ;
    });
}

void generator::generate_c(std::ofstream &ofile ,c_class & obj)
{   
    if(obj.v_table.have_virtual_function)
    {
        ofile << "struct " << obj.class_name << ";" << std::endl ;
        ofile << "struct " << obj.class_name + "_vtable " << "\n{" << std::endl ;
        generate_virtual_funtions(ofile,obj) ;
        ofile << "}" + obj.class_name + "table;" << std::endl ;
        obj.members.push_back(std::make_tuple('c', obj.class_name + "_vtable*", "v_ptr", ";")) ;
    }
    ofile << "struct " << obj.class_name << "\n{" << std::endl ;
    if(!obj.inheritance.second.empty()) {
        ofile << '\t' << obj.inheritance.second << " subObj ;" << std::endl ;
    }
    std::for_each(obj.members.begin(),obj.members.end(),[&](std::tuple<char,std::string,std::string,std::string> it) {
        ofile << '\t' <<  std::get<1>(it) << " " << std::get<2>(it)  << " " << std::get<3>(it) << std::endl ;
    });
    static int nested_count {} ;
    static std::string name ;
    if(!obj.nested_class.empty()) {
        for(auto & it: obj.nested_class)
        {
            name = obj.class_name ;
            nested_count++ ;
            generate_c(ofile,it) ;
        }
    }
    ofile << "};" << std::endl ;
    if(nested_count == 0) {
        generate_c_functions(ofile,obj) ;
    } else {
        std::string name1 = obj.class_name ;
        obj.class_name = name + "::" + obj.class_name ;
        nested_count = 0;
        generate_c_functions(ofile,obj) ;
        obj.class_name = name1 ;
    }
}

void generator::creat_member(std::vector<std::string> vec,c_class & obj,const char & modifier)
{
    std::vector<std::vector<std::string>> mat_members ;
    std::vector<std::string> tmp ;
    for(int i = 0 ; i < vec.size(); ++i)
    {
        if(vec[i] != ";") {
            tmp.push_back(vec[i]) ;
        } else {
            tmp.push_back(";") ;
            mat_members.push_back(tmp) ;
            tmp.clear() ;
        }
    }
    for(int i = 0 ; i < mat_members.size(); ++i)
    {
        std::string tmpstr ;
        std::for_each(mat_members[i].begin() + 2,mat_members[i].end(),[&](const std::string& s){
            tmpstr += s;
            tmpstr.push_back(' ') ;
        }) ;
        if(mat_members[i][0] != "static") {
            obj.members.push_back(std::make_tuple(modifier,mat_members[i][0],mat_members[i][1] ,tmpstr )) ;
        } else {
            obj.static_members.push_back(std::make_tuple(modifier,mat_members[i][1],mat_members[i][2] ,tmpstr )) ;
        }
        tmpstr.clear() ;
    }
}

std::vector<std::string> put_void(std::vector<std::string>::iterator first,std::vector<std::string>::iterator last)
{
    std::vector<std::string> vec(first,last) ;
    vec.insert(vec.begin() , "void") ;
    return vec ;
}

void generator::creat_function(std::vector<std::string> vec,c_class & obj,const char & modifier)
{
    int count_parenthes1 {} ;
    int count_parenthes2 {} ;
    for(int i = 0; i < vec.size(); ++i) 
    {
        if(vec[i] == "(") {
            std::vector<std::string>::iterator pos = vec.end() ;
            for(int j = i; ; ++j) 
            {
                if(vec[j] == "{") ++count_parenthes1 ;
                if(vec[j] == "}") {
                    ++count_parenthes2 ;
                    if(count_parenthes1 == count_parenthes2) {
                        pos = vec.begin() + j ;
                        count_parenthes1 = 0 ;
                        count_parenthes2 = 0 ;
                        break ;
                    }
                }
            }
            if(*(vec.begin()) == "virtual" && pos != vec.end()) {    // virtual funtions
                obj.v_table.have_virtual_function = true ;
                auto pos_parenthes = std::find(vec.begin() + i - 3, pos, ")") ;
                obj.v_table.set_fuction(std::vector<std::string>(vec.begin() + i - 2,pos_parenthes + 1),obj.class_name) ;
                obj.function.push_back(std::make_pair(modifier,std::vector<std::string>(vec.begin() + i - 2 ,pos + 1))) ;
                vec.erase(vec.begin() + i - 3,pos + 1) ;
                i = 0;
            } else if (*(vec.begin() + i - 3) == "static" && pos != vec.end()) {  // static funtions
                obj.function.push_back(std::make_pair(modifier,std::vector<std::string>(vec.begin() + i - 3 ,pos + 1))) ;
                vec.erase(vec.begin() + i - 3,pos + 1) ;
                i = 0 ;
            } else if(pos != vec.end()) {
                if(*(vec.begin() + i - 1) == obj.class_name) {              // ctrors
                    *(vec.begin() + i - 1) = "_" + *(vec.begin() + i - 1) ;
                    obj.function.push_back(std::make_pair(modifier,std::vector<std::string>(put_void(vec.begin() + i - 1,pos + 1)))) ;
                    vec.erase(vec.begin() + i - 1 ,pos + 1 ) ;
                    i = 0;
                } else {                // methods
                    obj.function.push_back(std::make_pair(modifier,std::vector<std::string>(vec.begin() + i - 2,pos + 1))) ;
                    vec.erase(vec.begin() + i - 2,pos + 1) ;
                    i = 0;
                }
            }       
        }
    }
    creat_member(vec,obj,modifier) ;
}

c_class generator::read_class(std::vector<std::string> class_vec) 
{
    c_class obj ;
    int nested_count {} ;
    for(int i = 0 ; i < class_vec.size() ; ++i) 
    {
        if(class_vec[i] == "class") {
            auto pos = std::find(class_vec.begin() + i, class_vec.end(),"{") ;
            int p = std::distance(class_vec.begin() + i, pos ) ;
            if(nested_count == 0) {
                obj.class_name = class_vec[i + 1] ;
                if(p > 2) {
                    obj.inheritance = std::make_pair(*(class_vec[i + 3].end() - 1), class_vec[i + 4]) ;
                }
            } else {
                obj.nested_class.push_back(read_class(std::vector<std::string>(class_vec.begin() + i , ++std::find(class_vec.begin() + i,class_vec.end(),"};")) ) ) ;
                class_vec.erase(class_vec.begin() + i , std::find(class_vec.begin() + i,class_vec.end(),"};") + 1) ;
                i-- ;
            }
            ++nested_count ;
        }
    }
    generate_user(class_vec) ;
    for(int i = 0 ; i < class_vec.size() ; ++i) 
    {
        if((class_vec[i] == "public" || class_vec[i] == "private" || class_vec[i] == "protected" ) && class_vec[i + 1] == ":" && class_vec[i + 2] != "public") 
        {   
            creat_function(std::vector<std::string>(class_vec.begin() + i + 2,std::find_if(class_vec.begin() + i + 2 ,class_vec.end(),[](std::string & str) {
                return (str == "public" || str == "private" || str == "protected" || str == "};")  ;
            })), obj ,*(class_vec[i].end() - 1)) ;
        }
    }
    return obj ;
}

void generator::read() 
{
    tokens = pars.get_tokens() ;

    std::vector<int> positions ;
    int count_class {} ;
    int count {} ;
    for(int i = 0 ; i < tokens.size() ; ++i) 
    {
        if(tokens[i] == ";" && tokens[i - 1] == "}") {
            tokens.erase(tokens.begin() + i) ;
            tokens.erase(tokens.begin() + i - 1) ;
            tokens.insert(tokens.begin() + i - 1, "};" ) ;
        }
    }
    std::vector<std::string>::iterator pos1 = tokens.end() ;
    std::vector<std::string>::iterator pos2 = tokens.end() ;
    for(int i = 0 ; i < tokens.size()  ; ++i) 
    {
        if(tokens[i] == "class") 
        {
            if(count_class == 0)
            pos1 = tokens.begin() + i ;
            ++count_class ; 
        }
        if(tokens[i] == "};") 
        {
            ++count ;
            if(count_class == count) {
                pos2 = tokens.begin() + i + 1;
            }
        }
        if(pos1 != tokens.end() && pos2 != tokens.end()) 
        {
            vec_c_class.push_back( read_class(std::vector<std::string>(pos1,pos2)) );
            positions.push_back(std::distance(tokens.begin(),pos1)) ;
            positions.push_back(std::distance(tokens.begin(),pos2)) ;
            pos1 = tokens.end();
            pos2 = tokens.end() ;
            count_class = 0;
            count = 0;
        }
    }

    for(int i = positions.size() - 1; i >= 0 ; i -= 2) 
    {
        tokens.erase(tokens.begin() + positions[i - 1] ,tokens.begin() + positions[i]) ;
    }

    generate_user(tokens) ;
    std::ofstream ofile("intermediate_code.cpp") ;
    for(auto & it : vec_c_class)
    {
        generate_c(ofile,it) ;
        std::for_each(it.static_members.begin(),it.static_members.end(),[&](std::tuple<char,std::string,std::string,std::string> it) {
            ofile << '\t' <<  std::get<1>(it) << " " << std::get<2>(it) << "; " << std::endl ;
        });
    }
    std::copy(c_funtions.begin() , c_funtions.end() , std::ostream_iterator<std::string>(ofile, " ")) ;
    std::copy(tokens.begin() , tokens.end() , std::ostream_iterator<std::string>(ofile, " ")) ;
}

int main()
{
    generator obj ;
    obj.read() ;
}