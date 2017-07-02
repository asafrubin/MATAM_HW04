#include "EscapeRoomWrapper.h"
#include "Exceptions.h"
#include "Enigma.h"

using namespace mtm::escaperoom;

const int default_max_time = 60;
const int default_max_visitors = 6;

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& escapeTime, const int& level, const int& maxParticipants)
{
    room = escapeRoomCreate(name, escapeTime, maxParticipants, level);
    if(room == nullptr){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& level)
{
     room = escapeRoomCreate(name, default_max_time, default_max_visitors, level);
     if(room == nullptr){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper& room)
{
    if(this->room) {
        escapeRoomDestroy(this->room);
    }
    this->room = escapeRoomCopy(room.room);
    if(this->room == nullptr){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper& EscapeRoomWrapper::operator=(const EscapeRoomWrapper& room)
{
    if(this == &room){
        return *this;
    }

    escapeRoomDestroy(this->room);
    this->room = escapeRoomCopy(room.room);
    this->enigmaVector = room.enigmaVector;

    return *this;
}
EscapeRoomWrapper* EscapeRoomWrapper::clone() const
{
    return new EscapeRoomWrapper(*this);
}
bool EscapeRoomWrapper::operator==(const EscapeRoomWrapper& room) const
{
    return areEqualRooms(this->room, room.room);
}

bool EscapeRoomWrapper::operator!=(const EscapeRoomWrapper& room) const
{
    return !(*this == room);
}

bool EscapeRoomWrapper::operator<(const EscapeRoomWrapper& room) const
{
    return isBiggerRoom(room.room, this->room);
}

bool EscapeRoomWrapper::operator>(const EscapeRoomWrapper& room) const
{
    return isBiggerRoom(this->room, room.room);
}

void EscapeRoomWrapper::addEnigma(const Enigma& enigma)
{
    enigmaVector.push_back(enigma);
}

void EscapeRoomWrapper::removeEnigma(const Enigma& enigma)
{
    if(enigmaVector.size() == 0){
        throw EscapeRoomNoEnigmasException();
    }
    for(auto it = enigmaVector.begin(); it < enigmaVector.end(); it++){
        if(*it == enigma){
            enigmaVector.erase(it);
            return;
        }
    }
    throw EscapeRoomEnigmaNotFoundException();
}

Enigma EscapeRoomWrapper::getHardestEnigma()
{
    for(auto it = enigmaVector.begin(); it < enigmaVector.end(); it++){
        if(it.operator*().getDifficulty() == HARD_ENIGMA){
            return *it;
        }
    }

    throw EscapeRoomNoEnigmasException();
}

std::vector<Enigma>& EscapeRoomWrapper::getAllEnigmas()
{
    return enigmaVector;
}

int EscapeRoomWrapper::level() const
{
    return getLevel(this->room);
}

void EscapeRoomWrapper::rate(const int& newRate) const
{
    updateRate(this->room, newRate);
}

EscapeRoomWrapper::~EscapeRoomWrapper()
{
    escapeRoomDestroy(this->room);
}

std::ostream& mtm::escaperoom::operator<<(std::ostream& output, const EscapeRoomWrapper& room)
{
    output << room.getName() << " ("  << room.getMaxTime() << "/" << room.level() << "/"
           << room.getMaxParticipants() << ")";
    return output;
}

std::string EscapeRoomWrapper::getName() const
{
    return roomGetName(this->room);
}

double EscapeRoomWrapper::getRate() const
{
    return roomGetRate(this->room);
}

int EscapeRoomWrapper::getMaxTime() const
{
    return roomGetMaxTime(this->room);
}

int EscapeRoomWrapper::getMaxParticipants() const
{
    return roomGetMaxParticipants(this->room);
}