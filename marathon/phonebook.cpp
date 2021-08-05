
// #include<iostream>
#include"mclass.h"
#include<fstream>
#include<cstring>

int main()
{
    std::ofstream ofile;
    contact human ;
    std::string Name;
    std::string FamelName;
    int PhoneNumber;
    std::string Addres;
    std::cout<<"New contact? y/n: ";
    char y;
    std::cin >> y;
    
    if(y == 'y'){
        

        std::cout << "Enter contact name: ";
        std::cin >> Name;
        std::cout << "Enter contact famel name: ";
        std::cin >> FamelName;
        std::cout << "Enter contact phone number: ";
        std::cin >> PhoneNumber;
        std::cout << "Enter contact addres: ";
        std::cin >> Addres;
        std::string ID = Name + Addres;
        ofile.open(ID);
        human.changeName(Name);
        human.changeFamelName(FamelName);
        human.changePhoneNumber(PhoneNumber);
        human.changeAddres(Addres);
        ofile << "\nyour contact name: ";
        ofile << human.getName()<<std::endl;
        ofile << "your contact famelname: ";
        ofile << human.getFamelName()<<std::endl;
        ofile << "your contact phone number: ";
        ofile << human.getPhoneNumber()<<std::endl;
        ofile << "your contact addres: ";
        ofile << human.getAddres()<<std::endl;


    }else{
        std::ifstream ifile;
        std::cout<<"Are you want change contact information? y/n: ";
        char y1;
        std::cin >> y1;
        if(y1 == 'y'){
        
        std::string contname;
        std::cout<<" Enter contact name and addres: ";
        std::cin >> contname;
        ifile.open(contname);
        if(!ifile.is_open()){
            std::cout<<"You dont such a contact!! \n";
            
            goto E;
        }
        ofile.open(contname);
        std::cout << "Enter changed contact name: ";
        std::cin >> Name;
        std::cout << "Enter changed contact famel name: ";
        std::cin >> FamelName;
        std::cout << "Enter changed contact phone number: ";
        std::cin >> PhoneNumber;
        std::cout << "Enter changed contact addres: ";
        std::cin >> Addres;
        std::string ID = Name + Addres;
        
        human.changeName(Name);
        human.changeFamelName(FamelName);
        human.changePhoneNumber(PhoneNumber);
        human.changeAddres(Addres);
        ofile << "\nyour contact name: ";
        ofile << human.getName()<<std::endl;
        ofile << "your contact famelname: ";
        ofile << human.getFamelName()<<std::endl;
        ofile << "your contact phone number: ";
        ofile << human.getPhoneNumber()<<std::endl;
        ofile << "your contact addres: ";
        ofile << human.getAddres()<<std::endl;

        char id[16];
        char cn[16];
        strcpy(cn, contname.c_str());
        strcpy(id, ID.c_str());
        std::rename(cn,id);


        ofile.close();
        }
        }
    

E:

ofile.close();
return 0;

}
 