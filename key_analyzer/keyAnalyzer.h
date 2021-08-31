#include<iostream>
#include<fstream>
#include<vector>
class KeyAnalyzer {
public:
    KeyAnalyzer(std::string file_name) {
        keyWords = new std::string[20]{"int","char","float","double","delete","new","void","for","while","if",
                                                "else","bool","struct","const","return","true","false","class","sizeof","static"};
        this->file_name = file_name;
        check(file_name);
    }
    void read_file();
    ~KeyAnalyzer() {
        delete [] keyWords;
        keyWords = nullptr;
        ifile.close();
        ofile.close();
    }
private:
    bool check(std::string file_name);
    void check_class(int &count);
    void checkKeys(std::string key,int &count);
    bool checkKeys(std::string key);
    bool checkVar(std::string str1);
    bool check_VAR(std::string str,int & count);
    void checkVariables(int & count);
    void checkArguments(std::string str,int & arguments);
    bool check_FUN(std::string str,std::string &strfoo,int & arguments);
    void checkFunction(int & functions);
    void overload_fun();
private:
    std::string *keyWords;
    std::string file_name;
    std::ifstream ifile;
    std::ofstream ofile;
    std::vector<std::string> fun;
};