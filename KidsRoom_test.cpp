#include "KidsRoom.h"
#include "mtmtest.h"
#include <assert.h>
#include <cstring>
#include "Exceptions.h"

using namespace mtm::escaperoom;


void testConstructor() {

    char *name = (char*)malloc(6);
    strcpy(name, "Name1\0");

    KidsRoom room1(name, 5, 10, 5, 9);

    ASSERT_NO_THROW(room1.getAgeLimit() == 9);
    ASSERT_NO_THROW(room1.level() == 10);
    ASSERT_NO_THROW(room1.getName() == "Name1");
    ASSERT_NO_THROW(room1.getMaxParticipants() == 5);

    output << room1;


}


int main() {
    RUN_TEST(testConstructor);
}