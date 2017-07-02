#include "Enigma.h"
#include "mtmtest.h"
#include <assert.h>
#include "Exceptions.h"
#include "Company.h"
#include "KidsRoom.h"
#include "ScaryRoom.h"

using namespace mtm::escaperoom;


void companyConstructor() {
    Company newCompany("company1", "0526777");
    Company newCompany2("company2", "0541212");

    Enigma newEnigma("Enigma1", HARD_ENIGMA);
    char *name1 = new char(7);
    char *name2 = new char(7);
    strcpy(name1, "name1");
    strcpy(name2, "name2");
    ASSERT_NO_THROW(newCompany.createRoom(name1, 20, 5, 10));
    ASSERT_NO_THROW(newCompany2.createRoom(name1, 21, 10, 9));
    EscapeRoomWrapper *room = newCompany.getRoomByName(name1);
    ASSERT_NO_THROW( newCompany.addEnigma(*room, newEnigma) );

    ASSERT_THROWS(CompanyRoomNotFoundException, newCompany2.addEnigma(*room, newEnigma));


}

void getAllRoomsByType() {
    char *baseRoom1 = new char(10);
    char *baseRoom2 = new char(10);
    char *kidsRoom1 = new char(10);
    char *kidsRoom2 = new char(10);
    char *scaryRoom1 = new char(11);
    char *scaryRoom2 = new char(11);

    strcpy(baseRoom1, "baseRoom1");
    strcpy(baseRoom2, "baseRoom2");
    strcpy(kidsRoom1, "kidsRoom1");
    strcpy(kidsRoom2, "kidsRoom2");
    strcpy(scaryRoom1, "scaryRoom1");
    strcpy(scaryRoom2, "scaryRoom2");

    Company newCompany("name1", "454545");
    ASSERT_NO_THROW(newCompany.createRoom(baseRoom1, 20, 5, 10));
    ASSERT_NO_THROW(newCompany.createRoom(baseRoom2, 15, 2, 3));
    ASSERT_NO_THROW(newCompany.createKidsRoom(kidsRoom1, 2, 4, 5, 7));
    ASSERT_NO_THROW(newCompany.createKidsRoom(kidsRoom2, 4, 7, 12, 8));
    ASSERT_NO_THROW(newCompany.createScaryRoom(scaryRoom1, 3,5,6,9,1));
    ASSERT_NO_THROW(newCompany.createScaryRoom(scaryRoom2, 10,3,4,11,5));

    auto set2 = newCompany.getAllRoomsByType(KIDS_ROOM);

    ASSERT_TRUE(set2.size() == 2);
    for(auto it : set2 ) {
        ASSERT_TRUE(it->getName().find("kids") != std::string::npos);
    }
    set2 = newCompany.getAllRoomsByType(SCARY_ROOM);
    for(auto it : set2 ) {
        ASSERT_TRUE(it->getName().find("scary") != std::string::npos);
    }
    set2 = newCompany.getAllRoomsByType(BASE_ROOM);
    for(auto it : set2 ) {
        ASSERT_TRUE(it->getName().find("base") != std::string::npos);
    }
}

void getAllRooms(){
    char *baseRoom1 = new char(10);
    char *baseRoom2 = new char(10);
    char *kidsRoom1 = new char(10);
    char *kidsRoom2 = new char(10);
    char *scaryRoom1 = new char(11);
    char *scaryRoom2 = new char(11);

    strcpy(baseRoom1, "baseRoom1");
    strcpy(baseRoom2, "baseRoom2");
    strcpy(kidsRoom1, "kidsRoom1");
    strcpy(kidsRoom2, "kidsRoom2");
    strcpy(scaryRoom1, "scaryRoom1");
    strcpy(scaryRoom2, "scaryRoom2");


}

int main() {
    RUN_TEST(companyConstructor);
    RUN_TEST(getAllRoomsByType);
}