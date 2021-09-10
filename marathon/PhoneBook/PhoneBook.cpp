#include<iostream>
#include<fstream>
#include<vector>
#include<map>

class phonebook {
public:
    void creat()
    {
        readFile();

        char ch;
        std::cout << "creat Contact: a" << std::endl;
        std::cout << "change Contact: b" << std::endl;
        std::cout << "delete Contact: c" << std::endl;
        std::cin >> ch;
        if(ch == 'a') {
            creatNewContact();
        }
        if(ch == 'b') {
            changeContact();
        }
        if(ch == 'c') {
            deleteContact();
        }
    }


private:
    void creatNewContact()
    {
        std::string name;
        std::cout << "Enter contact name: ";
        std::cin >> name;
        std::string FamelName;
        std::cout << "Enter contact famel name: ";
        std::cin >> FamelName;
        std::string PhoneNumber;
        std::cout << "Enter contact phone number: ";
        std::cin >> PhoneNumber;
        std::string Addres;
        std::cout << "Enter contact addres: ";
        std::cin >> Addres;
        creatContact(name,Addres,FamelName,PhoneNumber);
    }
    void creatContact(std::string name,std::string addres,std::string famelName,std::string PhoneNumber) {
        ofin.open("Contacts",std::ofstream::app);
        ofin << "\nyour contact name: " ;
        ofin << name << std::endl;
        ofin << "your contact famelname: ";
        ofin << famelName << std::endl;
        ofin << "your contact phone number: ";
        ofin << PhoneNumber << std::endl;
        ofin << "your contact addres: ";
        ofin << addres << std::endl;
        ofin.close();
    }
    void readFile()
    {
        ifin.open("Contacts");
        std::string str;
        while (!ifin.eof())
        {
            str = "";
            ifin >> str;
            if(str == "name:") {
                ifin >> str;
                vec.push_back(str);
                
            }
            if(str == "famelname:") {
                ifin >> str;
                vec.push_back(str);
            }
            if(str == "number:") {
                ifin >> str;
                vec.push_back(str);
            }
            if(str == "addres:") {
                ifin >> str;
                vec.push_back(str);
                Mmap.emplace(id,vec);
                id++;
                vec.clear();
            }

        }
        ifin.close();
    }

    void changeContact()
    {
        std::cout << "Whose data are you going to change: addres: ";
        std::string changeHuman;
        std::cin >> changeHuman;
        std::cout << "whate are you want change: name/famelname/addres/number: ";
        std::string changes;
        std::cin >> changes;
        std::cout << "What is the new data: ";
        std::string changeData;
        std::cin >> changeData;
        
        for(auto& it: Mmap) {
            if(it.second.at(3) == changeHuman) {
                if(it.second.at(0) == changes) {
                    it.second.at(0) = changeData;
                }
            }
        }
        ofin.open("Contacts");
        ofin.close();
        for(auto it: Mmap) 
        {
            creatContact(it.second.at(0),it.second.at(3),it.second.at(1),it.second.at(2));
        }
    }

    void deleteContact()
    {
        std::cout << "Whose data are you going to delete: addres: ";
        std::string changeHuman;
        std::cin >> changeHuman;
        ofin.open("Contacts");
        ofin.close();
        for(auto it: Mmap) {
            if(it.second.at(3) != changeHuman) {
                creatContact(it.second.at(0),it.second.at(3),it.second.at(1),it.second.at(2));
            }
        }
    }
private:
    std::ifstream ifin;
    std::ofstream ofin;    
    std::map<int,std::vector<std::string>> Mmap;
    std::vector<std::string> vec;
    static int id;
};
int phonebook::id = 0;


int main()
{
    phonebook obj;
    obj.creat();
}