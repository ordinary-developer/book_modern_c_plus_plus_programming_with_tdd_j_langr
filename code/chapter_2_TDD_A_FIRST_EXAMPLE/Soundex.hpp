#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

class Soundex {
    public:
        static const size_t MaxCodeLength {4};

        std::string encode(const std::string& word) const {
            return zeroPad(head(word) + encodedDigits(word));
        }
    private:
        std::string head(const std::string& word) const {
            return word.substr(0, 1);
        }

        std::string encodedDigits(const std::string& word) const {
            if (word.length() > 1) {
                return encodeDigit();
            }
            else {
                return "";
            }
        }

        std::string encodeDigit() const {
            return "1";
        }

        std::string zeroPad(const std::string& word) const {
            auto zerosNeeded = MaxCodeLength - word.length();
            return word + std::string(zerosNeeded, '0');
        }
};
#endif
