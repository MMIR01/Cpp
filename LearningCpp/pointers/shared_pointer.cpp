/***********************************
 * MMIR01. Example with shared pointers,
 * lvalue references,
 * and lvalue references to shared pointers
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

    std::cout << "Part 1\n";

    std::shared_ptr<House> myHouseOwner1_p = std::make_shared<House>("Flower", "111");
    std::shared_ptr<House> myHouseOwner2_p{myHouseOwner1_p};
    House& refHouse {*myHouseOwner1_p};
    std::shared_ptr<House>& refPtrHouse {myHouseOwner1_p};

    std::cout << "Shared pointer address: " << myHouseOwner1_p->getAddress() << ", " << myHouseOwner1_p->getPostCode() << "\n";
    //They should see the same address
    std::cout << "Second Shared pointer address: " << myHouseOwner2_p->getAddress() << ", " << myHouseOwner2_p->getPostCode() << "\n";
    std::cout << "Reference address: " << refHouse.getAddress() << ", " << refHouse.getPostCode() << "\n";
    std::cout << "Shared pointer reference address: " << refPtrHouse->getAddress() << ", " << refPtrHouse->getPostCode() << "\n";

    //Both should be 2
    std::cout << "Counter from first shared pointer: " << myHouseOwner1_p.use_count() << "\n";
    std::cout << "Counter from second shared pointer: " << myHouseOwner2_p.use_count() << "\n";


    std::cout << "\nPart 2\n";

    //Create a new house and give the ownership to the first pointer
    myHouseOwner1_p = std::move(createNewHouse("Cars", "222"));
    /* What is happening here?
    * 1. A new house is created and the owner is myHouseOwner1_p
    * 2. The only owner of "Flower 110" is now myHouseOwner2_p (so the counter will be 1)
    * 3. refHouse was referencing the content of myHouseOwner1_p, so it is still binding to it
    * 3. refPtrHouse is binded to myHouseOwner1_p so it should see the changes
    */
    std::cout << "Shared pointer address: " << myHouseOwner1_p->getAddress() << ", " << myHouseOwner1_p->getPostCode() << "\n";
    //They see should still see Flower 111
    std::cout << "Second Shared pointer address: " << myHouseOwner2_p->getAddress() << ", " << myHouseOwner2_p->getPostCode() << "\n";
    std::cout << "Reference address: " << refHouse.getAddress() << ", " << refHouse.getPostCode() << "\n";
    std::cout << "Shared pointer reference address: " << refPtrHouse->getAddress() << ", " << refPtrHouse->getPostCode() << "\n";
    
    //Pointer counter should be 1
    std::cout << "Counter from first shared pointer: " << myHouseOwner1_p.use_count() << "\n";
    std::cout << "Counter from second shared pointer: " << myHouseOwner2_p.use_count() << "\n";


    std::cout << "\nPart 3\n";

    /* What happens when we modified the reference?
    * A reference works in this way. For example:
    * int x = 5;
    * int& refx = x;
    * int y = 6;
    * refx = y;
    * refx is not referencing to y, is still referencing x, so refx = y is equivalent to:
    * x = y
    * 
    * In this case, what happens when the following sentence is executed?*/ 
    refHouse = *createNewHouse("Bear", "333");
    //refHouse was binding to Flower 111, so the content of the resource should be updated to Bear 333
    //myHouseOwner2_p was pointing out to the memory where Flower 111 was, but now it contains Bear 333

    //The first shared pointer and the shared pointer reference are still pointing out at the Cars 222
    std::cout << "Shared pointer address: " << myHouseOwner1_p->getAddress() << ", " << myHouseOwner1_p->getPostCode() << "\n";
    //The second share pointer and the refHouse are seeing the new house Bear 333
    std::cout << "Second Shared pointer address: " << myHouseOwner2_p->getAddress() << ", " << myHouseOwner2_p->getPostCode() << "\n";
    std::cout << "Reference address: " << refHouse.getAddress() << ", " << refHouse.getPostCode() << "\n";
    std::cout << "Shared pointer reference address: " << refPtrHouse->getAddress() << ", " << refPtrHouse->getPostCode() << "\n";


    std::cout << "Counter from first shared pointer: " << myHouseOwner1_p.use_count() << "\n";
    std::cout << "Counter from second shared pointer: " << myHouseOwner2_p.use_count() << "\n";


    std::cout << "\nPart 4\n";

    // What happens when we modified the shared pointer reference?
    refPtrHouse = myHouseOwner2_p;
    /* refPtrHouse was binding to myHouseOwner1_p, so this operation is equivalent to:
    * myHouseOwner1_p = myHouseOwner2_p
    * Therefore:
    * 1. refPtrHouse and myHouseOwner1_p will be pointing out at Bear 333
    * 2. The counter will be 2
    */

    std::cout << "Shared pointer address: " << myHouseOwner1_p->getAddress() << ", " << myHouseOwner1_p->getPostCode() << "\n";
    std::cout << "Second Shared pointer address: " << myHouseOwner2_p->getAddress() << ", " << myHouseOwner2_p->getPostCode() << "\n";
    std::cout << "Reference address: " << refHouse.getAddress() << ", " << refHouse.getPostCode() << "\n";
    std::cout << "Shared pointer reference address: " << refPtrHouse->getAddress() << ", " << refPtrHouse->getPostCode() << "\n";


    std::cout << "Counter from first shared pointer: " << myHouseOwner1_p.use_count() << "\n";
    std::cout << "Counter from second shared pointer: " << myHouseOwner2_p.use_count() << "\n";
    
    /*
    * Note: a problem when using a shared pointer reference:
    * It is not a shared owner of the resource because it won't change the reference counter. 
    * So, it is not guaranteed that the shared pointer will stay alive during the execution of the function (if applicable)
    */
    

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