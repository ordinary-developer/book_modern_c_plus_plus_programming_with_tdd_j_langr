#include "gmock/gmock.h"

#include "Soundex.hpp"


class SoundexEncoding : public testing::Test {
    public:
        Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    ASSERT_THAT(soundex.encode("A"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    ASSERT_THAT(soundex.encode("I"), testing::Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    ASSERT_THAT(soundex.encode("Ax"), testing::Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlpabetics) {
    ASSERT_THAT(soundex.encode("A#"), testing::Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
    ASSERT_THAT(soundex.encode("Acdl"), testing::Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
    ASSERT_THAT(soundex.encode("Dcdlb").length(), testing::Eq(4u));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
    ASSERT_THAT(soundex.encode("Baeiouhycdl"), testing::Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
    ASSERT_THAT(soundex.encodedDigit('b'), testing::Eq(soundex.encodedDigit('f')));
    ASSERT_THAT(soundex.encodedDigit('c'), testing::Eq(soundex.encodedDigit('g')));
    ASSERT_THAT(soundex.encodedDigit('d'), testing::Eq(soundex.encodedDigit('t')));

    ASSERT_THAT(soundex.encode("Abfcgdt"), testing::Eq("A123"));
}
