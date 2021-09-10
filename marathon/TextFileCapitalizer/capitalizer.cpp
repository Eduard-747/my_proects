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
        std::string text;
        std::string str;
        ofin.open("llll.txt");
        while(!ifin.eof())
        {
            str = "";
            std::getline(ifin,str);
            
            // text += changeLine(str);
            changeLine(str);
            ofin << str ;
            // ofin << std::endl;
            std::cout << str;
            std::cout << std::endl;
            // text += "\n";
        } 
        ifin.close();
        // std::cout << text;
        
        // ofin << text;
    }

private:

    void checkFile() 
    {
        if(!ifin.is_open()) {
            std::cout << "Aydpisi fayl goyutyun chuni!!!" << std::endl;
        }
    }

    std::string changeLine(std::string &str)
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
                // strLine += str[i];
                strTmp = "";

            }

        }
        str = strLine;
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