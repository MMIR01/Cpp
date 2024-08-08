/***********************************
 * MMIR01. Example with shared pointers.
 * I want to check that if we update
 * a shared pointer, the new values
 * can be seen from the lvalue
 * reference
************************************/

#include <iostream>
#include <memory>

class House {
    public:
        House(std::string address, std::string postcode);
        ~House();

        std::string getAddress() const;
        std::string getPostCode() const;

    private:
        std::string m_address;
        std::string m_postCode;
};

std::shared_ptr<House> createNewHouse(std::string address, std::string postCode) {
    return std::make_shared<House>(address, postCode);
}

int main (){

    std::shared_ptr<House> myHouse_p = std::make_shared<House>("Flower", "110");
    std::shared_ptr<House>& myHouseRef{myHouse_p};

    std::cout << "My address: " << myHouse_p->getAddress() << ", " << myHouse_p->getPostCode() << "\n";
    //They should see the same address
    std::cout << "My copied address: " << myHouseRef->getAddress() << ", " << myHouseRef->getPostCode() << "\n";
    
    std::cout << "Total pointers: " << myHouse_p.use_count() << "\n";
    
    //Create a new house and give the ownership to the first pointer
    myHouse_p = std::move(createNewHouse("Cars", "222"));
    
    std::cout << "My address: " << myHouse_p->getAddress() << ", " << myHouse_p->getPostCode() << "\n";
    //They see different address
    std::cout << "My copied address: " << myHouseRef->getAddress() << ", " << myHouseRef->getPostCode() << "\n";
    
    std::cout << "Total pointers: " << myHouse_p.use_count() << "\n";

    
    return 0;

};


House::House(std::string address, std::string postCode)
 : m_address{address}, m_postCode{postCode} {
}

House::~House() {
}

std::string House::getAddress() const {
    return m_address;
}

std::string House::getPostCode() const {
    return m_postCode;
}