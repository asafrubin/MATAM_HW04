#include "EscapeRoomWrapper.h"
#include "Exceptions.h"

using namespace mtm::escaperoom;

const int default_max_time = 60;
const int default_max_visitors = 6;

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& escapeTime, const int& level, const int& maxParticipants)
{
    room = escapeRoomCreate(name, escapeTime, maxParticipants, level);
    if(room == NULL){
        throw EscapeRoomMemoryProblemException();
    }
}

EscapeRoomWrapper::EscapeRoomWrapper(char* name, const int& level)
{
    room = escapeRoomCreate(name, default_max_time, default_max_visitors, level);
}

EscapeRoomWrapper::EscapeRoomWrapper(const EscapeRoomWrapper& room)
{
    escapeRoomDestroy(this->room);
    this->room = escapeRoomCopy(room.room);
}

EscapeRoomWrapper& EscapeRoomWrapper::operator=(const EscapeRoomWrapper& room)
{
    if(this == &room){
        return *this;
    }

    escapeRoomDestroy(this->room);
    *this = EscapeRoomWrapper(room);

    return *this;
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

std::ostream& operator<<(std::ostream& output, const EscapeRoomWrapper& room)
{
    output << room.getName() << " ("  << room.getMaxTime() << "/" << room.level() << "/" << room.getMaxParticipants() << ")";
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