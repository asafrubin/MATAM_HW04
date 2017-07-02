#include "ScaryRoom.h"
#include "Exceptions.h"

using namespace mtm::escaperoom;

ScaryRoom::ScaryRoom(char *name, const int &escapeTime, const int &level, const int &maxParticipants,
                             const int &ageLimit, const int &numOfScaryEnigmas)
                : EscapeRoomWrapper(name, escapeTime, level, maxParticipants)
{

            if(ageLimit < 0){
                throw ScaryRoomIllegalAgeLimit();
            }

            this->age_limit = ageLimit;
            this->num_of_scary_enigmas = numOfScaryEnigmas;
}

void ScaryRoom::setNewAgeLimit(const int &limit)
{
            if(limit < 0){
                throw ScaryRoomIllegalAgeLimit();
            }
            age_limit = limit;
        }

void ScaryRoom::incNumberOfScaryEnigmas()
{
            num_of_scary_enigmas++;
}

int ScaryRoom::getAgeLimit() const
{
            return age_limit;
}

ScaryRoom* ScaryRoom::clone() const
{
    return new ScaryRoom(*this);
}

std::ostream& operator<<(std::ostream& output, const ScaryRoom& scaryRoom)
{
    output << "ScaryRoom: " << scaryRoom.getName() << " (" << scaryRoom.getMaxTime() << "/" << scaryRoom.level()
           << "/" << scaryRoom.getMaxParticipants() << "/" << scaryRoom.getAgeLimit() << ")";

    return output;
}