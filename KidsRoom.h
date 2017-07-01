#ifndef HW04_KIDSROOM_H
#define HW04_KIDSROOM_H

#include "EscapeRoomWrapper.h"

namespace mtm {
    namespace escaperoom {

        class KidsRoom : public EscapeRoomWrapper{

            int age_limit;
        public:
            //constructor
            KidsRoom(char* name, const int& escapeTime, const int& level, const int& maxParticipants,
                     const int& ageLimit);

            void setNewAgeLimit(const int& limit);

            int getAgeLimit() const;

            friend std::ostream& operator<<(std::ostream& output, const KidsRoom& kidsRoom);

        };
        //Kids Room: <name> (<maxTime>/<level>/<maxParticipants>/<ageLimit>)
        std::ostream& operator<<(std::ostream& output, const KidsRoom& kidsRoom);


    }
}




#endif //HW04_KIDSROOM_H
