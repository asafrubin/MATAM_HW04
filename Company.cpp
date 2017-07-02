#include "EscapeRoomWrapper.h"
#include "Company.h"
#include "ScaryRoom.h"
#include "KidsRoom.h"
#include "Exceptions.h"

using std::string;
using std::set;
using namespace mtm::escaperoom;

Company::Company(string name, string phoneNumber) : name(name), phoneNumber(phoneNumber) {}

Company::Company(const Company &company) : name(company.name), phoneNumber(company.phoneNumber), rooms(company.rooms){}

Company& Company::operator=(const Company &company)
{
    if(this == &company){
        return *this;
    }

    delete this;

    this->phoneNumber = company.phoneNumber;
    this->name = company.name;
    this->rooms = company.rooms;

    return *this;
}

void Company::createRoom(char *name, const int &escapeTime, const int &level, const int &maxParticipants)
{
    try {
        auto newRoom = new EscapeRoomWrapper(name, escapeTime, level, maxParticipants);
        rooms.insert(newRoom);
    }catch (EscapeRoomMemoryProblemException& e){
        throw CompanyMemoryProblemException();
    }
}

void Company::createScaryRoom(char *name, const int &escapeTime, const int &level, const int &maxParticipants,
                              const int &ageLimit, const int &numOfScaryEnigmas)
{
    try{
        EscapeRoomWrapper *newScaryRoom;
        newScaryRoom = new ScaryRoom(name, escapeTime, level, maxParticipants, ageLimit, numOfScaryEnigmas);

        rooms.insert(newScaryRoom);
    }catch (EscapeRoomMemoryProblemException e) {
        throw CompanyMemoryProblemException();
    }
}

void Company::createKidsRoom(char *name, const int &escapeTime, const int &level, const int &maxParticipants,
                             const int &ageLimit)
{
    try{
        EscapeRoomWrapper *newKidsRoom;
        newKidsRoom = new KidsRoom(name, escapeTime, level, maxParticipants, ageLimit);

        rooms.insert(newKidsRoom);
    }catch (EscapeRoomMemoryProblemException e) {
        throw CompanyMemoryProblemException();
    }
}

set<EscapeRoomWrapper*> Company::getAllRooms() const
{
    return rooms;
}

void Company::removeRoom(const EscapeRoomWrapper &room)
{
    for(auto it : rooms){
        if(*it == room){
            delete it;
            rooms.erase(it);
            return;
        }
    }

    throw CompanyRoomNotFoundException();
}

void Company::addEnigma(const EscapeRoomWrapper &room, const Enigma &enigma)
{
    for(auto it = rooms.begin(); it != rooms.end(); it++){
        if(**it == room){
            (*it)->addEnigma(enigma);
            return;
        }
    }

    throw CompanyRoomNotFoundException();
}

void Company::removeEnigma(const EscapeRoomWrapper &room, const Enigma &enigma)
{
    for(auto it = rooms.begin() ; it != rooms.end() ; it++){
        if(**it == room){
            try {
                (*it)->removeEnigma(enigma);
            }catch(CompanyRoomHasNoEnigmasException& e){
                throw CompanyRoomHasNoEnigmasException();
            }catch(CompanyRoomNotFoundException& e){
                throw CompanyRoomNotFoundException();
            }catch(...){
                throw;
            }
        }
    }

    throw CompanyRoomNotFoundException();
}

void Company::addItem(const EscapeRoomWrapper &room, const Enigma &enigma, const string &element)
{
    for(auto it = rooms.begin(); it != rooms.end() ; it++){
        if(**it==room){
            for(auto it2 = it.operator*()->getAllEnigmas().begin(); it2 != it.operator*()->getAllEnigmas().end(); it2++)
            {
                if(*it2 == enigma){
                        it2->addElement(element);
                }
            }
            throw CompanyRoomEnigmaNotFoundException();
        }
    }
    throw CompanyRoomNotFoundException();
}

void Company::removeItem(const EscapeRoomWrapper &room, const Enigma &enigma, const string &element)
{
    for(auto it = rooms.begin(); it != rooms.end() ; it++){
        if(**it==room){
            for(auto it2 = it.operator*()->getAllEnigmas().begin(); it2 != it.operator*()->getAllEnigmas().end(); it2++)
            {
                if(*it2 == enigma){
                    try {
                        it2->removeElement(element);
                    }catch(EnigmaNoElementsException& e){
                        throw EnigmaNoElementsException();
                    }
                }
            }
            throw CompanyRoomEnigmaNotFoundException();
        }
    }
    throw CompanyRoomNotFoundException();
}

set<EscapeRoomWrapper*> Company::getAllRoomsByType(RoomType type) const
{
    std::set<EscapeRoomWrapper*> newSet;

    for(auto &it : rooms) {
        switch (type) {
            case (BASE_ROOM):
                if( !dynamic_cast<ScaryRoom*>(it) && !dynamic_cast<KidsRoom*>(it)){
                    newSet.insert(it);
                }
                break;
            case (SCARY_ROOM):
                if(dynamic_cast<ScaryRoom*>(it)){
                    newSet.insert(it);
                }
                break;
            case (KIDS_ROOM):
                if(dynamic_cast<KidsRoom*>(it)){
                    newSet.insert(it);
                }
                break;
        }
    }
    return newSet;
}

EscapeRoomWrapper* Company::getRoomByName(const string &name) const
{
    for(auto &it : rooms){
        if(it->getName() == name){
            return it;
        }
    }
    throw CompanyRoomNotFoundException();
}

std::ostream& mtm::escaperoom::operator<<(std::ostream &output, const Company &company)
{
    output << company.name << " : " << company.phoneNumber << std::endl;
    for(auto it : company.rooms){
        output << *it << std::endl;
    }
    output << std::endl;

    return output;
}