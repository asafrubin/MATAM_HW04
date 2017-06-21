#include "Enigma.h"
#include "mtmtest.h"
#include <assert.h>
#include "Exceptions.h"

using namespace mtm::escaperoom;


void test1() {
    Enigma enigma1("test1", EASY_ENIGMA, 5);
    Enigma enigma2("test2", MEDIUM_ENIGMA, 7);

    ASSERT_NO_THROW(enigma1.getDifficulty() == EASY_ENIGMA);
    ASSERT_NO_THROW(enigma1.getName() == "test1");
    ASSERT_NO_THROW(enigma1.getNumOfElements() == 5);

    ASSERT_NO_THROW(enigma2.getDifficulty() == MEDIUM_ENIGMA);
    ASSERT_NO_THROW(enigma2.getName() == "test2");
    ASSERT_NO_THROW(enigma2.getNumOfElements() == 7);

    enigma2 = enigma1;
    ASSERT_NO_THROW(enigma2.getDifficulty() == EASY_ENIGMA);
    ASSERT_NO_THROW(enigma2.getName() == "test1");
    ASSERT_NO_THROW(enigma2.getNumOfElements() == 5);

}


int main() {
    RUN_TEST(test1);
}