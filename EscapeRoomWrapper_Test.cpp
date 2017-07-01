#include "Enigma.h"
#include "mtmtest.h"
#include <assert.h>
#include "Exceptions.h"
#include "EscapeRoomWrapper.h"
#include <cstdio>
#include <cstring>

using namespace mtm::escaperoom;


void WrapperConstructor() {
    char* name =  "name1";
    const int max_participents(20), level(15), max_time(50);
    EscapeRoomWrapper escapeRoom(name, max_time, level, max_participents);
    EscapeRoomWrapper escapeRoom2(name, level);
    ASSERT_TRUE(escapeRoom.getName() == name);
    ASSERT_TRUE(escapeRoom.getMaxParticipants() == max_participents);
    ASSERT_TRUE(escapeRoom.level() == level);

    ASSERT_TRUE(escapeRoom2.getMaxParticipants() == 6);
    ASSERT_TRUE(escapeRoom2.getMaxTime() == 60);
}
void WrapperCopyConstructor(){
    std::string name("name1"), name2("name2");
    const int max_participents(20), level(15), max_time(50);
    EscapeRoomWrapper escape1(name2, level);
    EscapeRoomWrapper escape2(name, max_time, level, max_participents);

    escape1 = escape2;
    ASSERT_TRUE(escape1.getMaxTime() == max_time);
    ASSERT_TRUE(escape1.getMaxParticipants() == max_participents);
    ASSERT_TRUE(escape1.getName() == name);
}
void Wrapper


int main() {
    RUN_TEST(WrapperConstructor);
    RUN_TEST(WrapperCopyConstructor);
}