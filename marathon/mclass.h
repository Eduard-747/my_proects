#include<iostream>
class contact{
public:
    
    void changeName(std::string name){
        this->name = name;
    }
    
    void changeFamelName(std::string famelname){
        this->famelname = famelname;
    }

    void changePhoneNumber(int phoneNumber){
        this->phoneNumber = phoneNumber;
    }

    void changeAddres(std::string addres){
        this->addres = addres;
    }

    std::string getName() const {
        return name;
    }
    std::string getFamelName() const {
        return famelname;
    }
    int getPhoneNumber() const {
        return phoneNumber;
    }
    std::string getAddres() const {
        return addres;
    }

private:

    std::string name;
    std::string famelname;
    int phoneNumber;
    std::string addres;

};
