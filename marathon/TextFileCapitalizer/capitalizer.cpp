#include<iostream>
#include<fstream>
#include<vector>
class capitalizer {
public:
    capitalizer(std::string fileName)
    {
        ifin.open(fileName);
        this->fileName = fileName;
        checkFile();
    }
    void change()
    {
        std::string str;
        ofin.open("ModifiedFile.txt");
        while(!ifin.eof())
        {
            std::getline(ifin, str);
            str = changeLine(str);
            ofin << str ;
        } 
        ifin.close();
    }

private:
    void checkFile() 
    {
        if(!ifin.is_open()) {
            std::cerr << "There is no such file !!!" << std::endl;
            exit(1) ;
        }
    }
    std::string changeLine(const std::string &str)
    {
        std::string strTmp;
        std::string strLine;

        for(int i = 0;i < str.size() + 1;i++) {
            if(str[i] >= 'A' && str[i] <= 'z' ) {
                strTmp += str[i];
            } else {
                changeWord(strTmp);
                strLine += strTmp;
                strLine += " ";
                strTmp = "";

            }

        }
        strLine.push_back('\n') ;
        return strLine;
    }
    void changeWord(std::string &str)
    {
        if(str[0] >= 'a' && str[0] <= 'z') {
            str[0] -= 32;
        }
        if(str[str.size() - 1] >= 'a' && str[str.size() - 1] <= 'z') {
            str[str.size() - 1] -= 32;
        }
    }

private:
    std::ifstream ifin;
    std::ofstream ofin;
    std::string fileName;
    std::vector<std::string> vec;

};

int main()
{
    capitalizer obj("file.txt");
    obj.change();
}
