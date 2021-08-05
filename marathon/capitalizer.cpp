
#include<iostream>
#include<fstream>
int main()
{
    std::ifstream file;
    file.open("file.txt");
    std::string str;
    std::string row;
    while (!file.eof())
    {
        str = "";
        file >> str;
        if(str[0]>='a' && str[0] <= 'z'){
            str[0] -= 32;
        }
        if(str[str.size()-1] >= 'a' && str[str.size()-1] <= 'z'){
            str[str.size()-1] -= 32;
        }
        row += str;
        row += " ";
    }
    std::ofstream ofile;
    ofile.open("file.txt");
    ofile << row;

    ofile.close();
}