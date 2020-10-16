#ifndef MORSE_ENCODER_DECODER
#define MORSE_ENCODER_DECODER

#include <string>
#include <optional>
#include <unordered_map>

class MorseEncoderDecoder {
    private:
        static const std::unordered_map<char, std::string> ASCII_TO_MORSE_LOOKUP;
        static const std::unordered_map<std::string, std::string> MORSE_TO_ASCII_LOOKUP;
    
    public:
        MorseEncoderDecoder();
        ~MorseEncoderDecoder();
        std::string encode(std::string &input);
        std::string decode(std::string &input);
        std::optional<std::string> decodeMorseLetter(std::string &morseLetter);
};

#endif