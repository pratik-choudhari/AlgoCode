#include <iostream>
#include <regex>

class CreditCardValidator {
    private:
        static const size_t LENGTH = 16;
        static const size_t LENGTH_W_SEPERATOR = LENGTH + 3;
        std::string creditCardString;
        size_t index;

        bool isSeperator() {
            const bool isSep = creditCardString.at(index) == '-';
            index += 1;
            return isSep;
        }

        bool startsWithCorrectDigit() {
            char &firstChar = creditCardString.at(0);
            return ((firstChar == '4') || firstChar == '5' || firstChar == '6');
        }

        std::string_view getNextChunck() {
            const std::string_view chunck(creditCardString.data() + index, 4);
            index += 4;
            return chunck;
        }

        bool isNonDuplicatingInt(const std::string_view s)
        {
            return !s.empty() && std::find_if(s.begin(), 
                s.end(), [&s](unsigned char c) { return !std::isdigit(c) && c != s[0]; }) == s.end();
        }

    public:
        CreditCardValidator(std::string creditCardString): creditCardString(creditCardString), index(0) {
        }

        bool validate() {
            const bool shouldHaveSeperators = creditCardString.length() == LENGTH_W_SEPERATOR;

            return (shouldHaveSeperators || creditCardString.length() == LENGTH)
                    && startsWithCorrectDigit()
                    && isNonDuplicatingInt(getNextChunck())
                    && (!shouldHaveSeperators || isSeperator())
                    && isNonDuplicatingInt(getNextChunck())
                    && (!shouldHaveSeperators || isSeperator())
                    && isNonDuplicatingInt(getNextChunck())
                    && (!shouldHaveSeperators || isSeperator())
                    && isNonDuplicatingInt(getNextChunck());
        }


};

int main() {
    std::string creditCardInput;
    std::cout << "enter credit card number: ";
    std::getline(std::cin, creditCardInput);
    auto validator = new CreditCardValidator(creditCardInput);
    std::string output = validator->validate() ? "valid": "invalid";
    std::cout << output << std::endl;
    return 0;
}