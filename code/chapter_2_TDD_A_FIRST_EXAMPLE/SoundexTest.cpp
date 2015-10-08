#include <string>

class Soundex {
    public:
        std::string encode(const std::string& word) const {
            return zeroPad(word);
        }
    private:
        std::string zeroPad(const std::string& word) const {
            return word + "000";
        }
};


#include "gmock/gmock.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    Soundex soundex;

    auto encoded = soundex.encode("A");

    ASSERT_THAT(encoded, testing::Eq("A000"));
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    Soundex soundex;

    auto encoded = soundex.encode("I");

    ASSERT_THAT(encoded, testing::Eq("I000"));
}
