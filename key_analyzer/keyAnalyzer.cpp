#include"keyAnalyzer.h"

void KeyAnalyzer::read_file()
{
    std::string str;
    int keysCount = 0;
    int variables = 0;
    int functions = 0;
    int class_count = 0;
    while (!ifile.eof())
    {
        str = "";
        ifile >> str;
        checkKeys(str,keysCount);
    }
    checkVariables(variables);
    checkFunction(functions);
    check_class(class_count);
    ofile.open("reportation");
    ofile << "Keywords: ";
    ofile << keysCount << std::endl;
    ofile << "Variables: ";
    ofile << variables << std::endl;
    ofile << "functions: "<<functions << std::endl;
    ofile << "functions: "<<std::endl;
    ofile << "overload functions: " << std::endl;
    overload_fun();
    ofile << "Class: " << class_count;
}

bool KeyAnalyzer::check(std::string file_name) 
{
    ifile.open(file_name);
    if(!ifile.is_open()) {
        std::cout << "Aydpisi fayl goyuctyun chuni: ";
        return false;
    } else {
        return true;
    }
}

void KeyAnalyzer::check_class(int &count) 
{
    ifile.close();
    ifile.open(file_name);
    std::string str;
    while (!ifile.eof())
    {
        str = "";
        ifile >> str;
        if(str == "class") {
            count++;
        }

    }
}

void KeyAnalyzer::checkKeys(std::string key,int &count) {
    for(int i = 0;i < 20;i++) {
        if(key == keyWords[i]) {
            count++ ;
        }
    }
}
bool KeyAnalyzer::checkKeys(std::string key) {
    std::string keys[5] {"int","double","bool","char","float"} ;
    for(int i = 0;i < 5;i++) {
        if(key == keys[i]) {
            return true;
        }
    }
    return false;
}
bool KeyAnalyzer::checkVar(std::string str1){
    int x = str1.size();
    for(int i = 0 ; i < x ; i++){
        if(str1[i] >= 65 && str1[i] <= 122) {
            return true;
        } 
    }
    return false;
}
bool KeyAnalyzer::check_VAR(std::string str,int & count) {
    int tmp = str.size() - 1;
    if(str[tmp] != ';') {    
        return false;
    } else {
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == ',') {
                ++count;
            }
            
        }
    }
    return true;
}
void KeyAnalyzer::checkVariables(int & count) {
    ifile.close();
    ifile.open(file_name);
    std::string str;
    while (!ifile.eof())
    {
        str = "";
        ifile >> str;
        if(checkKeys(str)) {
            std::getline(ifile,str);
            if(check_VAR(str,count)) {
                ++count;
            }               
        }
    }
}
void KeyAnalyzer::checkArguments(std::string str,int & arguments) {
    std::string strTemp = "";
    for(int i = 1; i < str.size();i++) {
        if(str[i] == '('){
            for(int j = i+1; j < str.size();j++) {
                strTemp.push_back(str[j]);
                if(checkKeys(strTemp)) {
                    strTemp = "";
                    arguments++;
                }
                if(strTemp[strTemp.size() - 1] == ',') {
                    strTemp = "";
                }
                if(str[j] == ')') {
                    break;
                }
            }
        }
    }
}
bool KeyAnalyzer::check_FUN(std::string str,std::string &strfoo,int & arguments) {
    int size = str.size();
    for(int i = size;i > 0;i--) {
        if(str[i] == ')') {
            checkArguments(str,arguments);
            for(int j = 0;j < size;j++) {
                if(str[j] != '(') {
                    strfoo.push_back(str[j]);
                } else {
                    break;
                }
            }
            return true;
        } 
    }
    return false;   
}
void KeyAnalyzer::checkFunction(int & functions) {
    ifile.close();
    ifile.open(file_name);
    std::string str ;
    std::string strfoo ;
    int arguments = 0;
    while(!ifile.eof())
    {
        str = "";
        strfoo = "";
        ifile >> str;
        if(checkKeys(str)) {
            std::getline(ifile,str);
            if(check_FUN(str,strfoo,arguments)) {
        fun.push_back(strfoo);
                functions++;
                arguments = 0;
            }
        }
    }
}
void KeyAnalyzer::overload_fun() { 
    std::vector<std::string> vec;
    for(int i = 0;i < fun.size();++i) {
        for(int j = i + 1; j < fun.size();++j) {
            if(fun[i] == fun[j]) {
                vec.push_back(fun[i]);
            }
        }
    }
    for(int i = 0; i < vec.size();i++) {
        ofile << vec[i] << std::endl;
    }
}

int main()
{
    KeyAnalyzer obj("cpp.cpp");
    obj.read_file();
}