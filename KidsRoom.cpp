#include "KidsRoom.h"
#include "Exceptions.h"

using namespace mtm::escaperoom;

KidsRoom::KidsRoom(char *name, const int &escapeTime, const int &level, const int &maxParticipants,
                   const int &ageLimit) : EscapeRoomWrapper(name, escapeTime, level, maxParticipants)
{
    if(ageLimit < 0){
        throw KidsRoomIllegalAgeLimit();
    }

    this->age_limit = ageLimit;
}

void KidsRoom::setNewAgeLimit(const int &limit)
{
    if(limit < 0){
        throw KidsRoomIllegalAgeLimit();
    }

    age_limit = limit;
}

int KidsRoom::getAgeLimit() const
{
    return age_limit;
}

//Kids Room: <name> (<maxTime>/<level>/<maxParticipants>/<ageLimit>)
std::ostream& operator<<(std::ostream& output, const KidsRoom& kidsRoom)
{
    output << "Kids Room: " << kidsRoom.getName() << " (" << kidsRoom.getMaxTime() << "/" << kidsRoom.level() << "/"
                <<kidsRoom.getMaxParticipants() << "/" << kidsRoom.getAgeLimit() << ")";

    return output;
}