#include<iostream>
#include<fstream>
#include<map>
#include<vector>
class KeyAnalyzer {
public:
    KeyAnalyzer(std::string file_name) {
        keyWords = new std::string[20]{"int","char","float","double","delete","new","void","for","while","if",
                                                "else","bool","struct","const","return","true","false","class","sizeof","static"};
        this->file_name = file_name;
        check(file_name);
    }
    void read_file()
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
        printFunctionsAndArguments();
        ofile << "overload functions: " << std::endl;
        overload_fun();
        ofile << "Class: " << class_count;
    }
    ~KeyAnalyzer() {
        delete [] keyWords;
        keyWords = nullptr;
        ifile.close();
    }
private:
    bool check(std::string file_name) {
        ifile.open(file_name);
        if(!ifile.is_open()) {
            std::cout << "Aydpisi fayl goyuctyun chuni: ";
            return false;
        } else {
            return true;
        }

    }
    void check_class(int &count) {
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
    void checkKeys(std::string key,int &count) {
        for(int i = 0;i < 20;i++) {
            if(key == keyWords[i]) {
                count++ ;
            }
        }
    }
    bool checkKeys(std::string key) {
        std::string keys[5] {"int","double","bool","char","float"} ;
        for(int i = 0;i < 5;i++) {
            if(key == keys[i]) {
                return true;
            }
        }
        return false;
    }
    bool checkVar(std::string str1){
        int x = str1.size();
        for(int i = 0 ; i < x ; i++){
            if(str1[i] >= 65 && str1[i] <= 122) {
                return true;
            } 
        }
        return false;
    }
    bool check_VAR(std::string str,int & count) {
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

    void checkVariables(int & count) {
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
        ++count;
    }
    void checkArguments(std::string str,int & arguments) {
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
    bool check_FUN(std::string str,std::string &strfoo,int & arguments) {
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
    void checkFunction(int & functions) {
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
                    fun.emplace(strfoo,arguments);
                    functions++;
                    arguments = 0;
                }
            }
        }
    }
    void overload_fun() {
        std::vector<std::string> vec;
        bool flag = false;
        for(auto i = fun.begin(),j = ++fun.begin();j != fun.end();) {
            if(i->first == j->first) {
                vec.push_back(i->first);
                flag = true;
            } else if(flag && i->first != j->first) {
                flag = false;
                continue;
            }
		++i;
		++j;
        }
        for(int i = 0; i < vec.size();i++) {
            ofile << vec[i] << std::endl;
        }
    }
    void printFunctionsAndArguments() {
        auto it = fun.begin();
        while (it != fun.end())
        {
            ofile << it->first << " arguments: " << it ->second << std::endl;
            it++;
        }
        
    }
private:
    std::string *keyWords;
    std::string file_name;
    std::ifstream ifile;
    std::ofstream ofile;
    std::multimap<std::string,int> fun;
};
int main()
{
    KeyAnalyzer obj("cpp.cpp");
    obj.read_file();
}