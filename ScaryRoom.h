#ifndef HW04_SCARYROOM_H
#define HW04_SCARYROOM_H


#include "EscapeRoomWrapper.h"

namespace mtm{
    namespace escaperoom {


        class ScaryRoom : public EscapeRoomWrapper{
            int age_limit;
            int num_of_scary_enigmas;

        public:

            //constructor
            ScaryRoom(char* name, const int& escapeTime, const int& level, const int& maxParticipants,
                      const int& ageLimit, const int& numOfScaryEnigmas);

            void setNewAgeLimit(const int& limit);

            void incNumberOfScaryEnigmas();

            int getAgeLimit() const;

            virtual ScaryRoom* clone() const;

            // print in this format : Scary Room: <name> (<maxTime>/<level>/<maxParticipants>/<ageLimit>)
            friend std::ostream& operator<<(std::ostream& output, const ScaryRoom& scaryRoom);


        };
        std::ostream& operator<<(std::ostream& output, const ScaryRoom& scaryRoom);

    }
}
#endif //HW04_SCARYROOM_H
