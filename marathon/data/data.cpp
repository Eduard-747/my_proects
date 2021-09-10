#include <iostream>
#include <fstream>
#include <map>
#include<vector>
std::ofstream ofile;

class mclass {
public:
    std::vector<std::string> arr;
    mclass() {
       
    }
    void creat(std::string txt) {
        this->txt = txt;
        ofile.open(txt,std::ofstream::app);
    }
    void enterMap(std::string strkey,std::string str = "") {
        arr.push_back(strkey);
        mMap.emplace(strkey,str);
        x++;
    }

    void changemap(std::string strkey,std::string str) {
        mMap[strkey] = str;
    }
    bool ka(std::string str) {
        if(str == txt) {
            return 1;
        }
        return 0;
    }
    int getX() const { return x; }
    void fillfile(std::string strkey,std::string str) {
        ofile << strkey;
        ofile << " = ";
        ofile << str << std::endl;
    }
        
private:

    static int x;
    std::string txt;
    std::map <std::string,std::string> mMap;
};
int mclass::x = 0;

int main()
{
    mclass mc;
    
ex:
    std::string str;
    std::cout<<"what do you want to do: ";
    
    std::cin >> str;
    
    if(str == "creat" ) {
    
    std::cout<<"Enter name file: ";
    std::string txt;
    std::cin >> txt;
    mc.creat(txt);
    std::string element;
ag:
    std::cout << "Enter elemtnt: ";
    std::cin >> element;
    mc.enterMap(element);
        
    std::cout << "Enter again? y/n: ";
    char y;
    std::cin >> y;
    if(y == 'y') {
        goto ag;
    }

    std::cout<<"Exit? y/n: ";
    char n;
    std::cin >> n;
    if(n == 'n') {
        goto ex;
    }

    }
    if(str == "insert") {
        std::string txt;
        std::cout<<"Enter name file: ";
        std::cin >> txt;
        if(mc.ka(txt)) {
            std::string str;
            std::cout << "equate element: ";
            int x;
            x = mc.getX();
            std::vector <std::string> tmpstr;
            for(int i = 0;i < x;i++) {
            std::string str;
            std::cout << mc.arr[i]<<" = ";
            std::cin >> str;
            tmpstr.push_back(str);
            mc.changemap(mc.arr[i],str);
            }
            std::cout << "do you want to change something? enter update: ";
            std::string update;
            std::cin >> update;
            // std::vector <std::string> tmpstr;
            if(update == "update") {
                tmpstr.clear();
                for(int i = 0;i < x;i++) {
                    std::string str;
                    std::cout << mc.arr[i]<<" = ";
                    std::cin >> str;
                    tmpstr.push_back(str);
                    mc.changemap(mc.arr[i],str);
                }
            }
            std::cout << "do you want save? y/n: ";
            char y;
            std::cin >> y;
            if(y == 'y') {
                for(int i = 0;i < x ;i++) {                    
                    // std::cout << mc.arr[i]<<" ";
                    // ofile << mc.arr[i] << " = " << tmpstr.at(i) << std::endl;
                    mc.fillfile(mc.arr[i],tmpstr.at(i));
                }
                ofile << std::endl << "= = = = = = = = = = = = = = = = ="; 
                ofile.close();
            }

        }
    }
    if(str == "select") {
        std::string txt;
        std::cout<<"Enter name file: ";
        std::cin >> txt;
        std::ifstream ifile;
        ifile.open(txt);
        if(ifile.is_open()) {

        std::cout << "Enter what you want to know: ";
        std::string str1;
        std::cin >> str1;
        std::string strr;
        std::cout << "whose data are you looking for? ";
        std::string who;
        std::cin >> who;

        while (!ifile.eof())
        {
            ifile >> strr;
            if(strr == "name") {
                ifile >> strr;
                ifile >> strr;
                if(strr == who) {
                    ifile >> strr;
                    if(strr == str1) {
                        ifile >> strr;
                        ifile >> strr;
                        std::cout << strr;
                    }
                }
            }
        }
        

        } else {

        std::cout << "there is no such file!!\n";
        
        }
    

    }
    

    std::cout << std::endl;
    return 0;
}