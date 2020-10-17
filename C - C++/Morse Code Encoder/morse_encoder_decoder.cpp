#include "Include/morse_encoder_decoder.hpp"

const std::unordered_map<char, std::string> MorseEncoderDecoder::ASCII_TO_MORSE_LOOKUP({
    {'A', ".-"},
    {'B', "-..."},
    {'C', "-.-."},
    {'D', "-.."},
    {'E', "."},
    {'F', "..-."},
    {'G', "--."},
    {'H' , "...."},
    {'I' , ".."},
    {'J' , ".---"},
    {'K' , "-.-"},
    {'L' , ".-.."},
    {'M' , "--"},
    {'N' , "-."},
    {'O' , "---"},
    {'P' , ".--."},
    {'Q' , "--.-"},
    {'R' , ".-."},
    {'S' , "..."},
    {'T' , "-"},
    {'U' , "..-"},
    {'V' , "...-"},
    {'W' , ".--"},
    {'X' , "-..-"},
    {'Y' , "-.--"},
    {'Z' , "--.."},
    {' ' , "/"},
    {'1' , ".----"},
    {'2' , "..---"},
    {'3' , "...--"},
    {'4' , "....-"},
    {'5' , "....."},
    {'6' , "-...."},
    {'7' , "--..."},
    {'8' , "---.."},
    {'9' , "----."},
    {'0' , "-----"},
    {'.' , ".-.-.-"},
    {',' , "--..--"},
    {',' , "---..."},
    {'?' , "..--.."},
    {'\'' , ".----."},
    {'-' , "-....-"},
    {'@' , ".--.-."},
    {'=' , "-...-"}
});

const std::unordered_map<std::string, std::string> MorseEncoderDecoder::MORSE_TO_ASCII_LOOKUP({
    {".-", "A"},
    {"-...", "B"},
    {"-.-.", "C"},
    {"-..", "D"},
    {".", "E"},
    {"..-.", "F"},
    {"--.", "G"},
    {"....", "H"},
    {"..", "I"},
    {".---", "J"},
    {"-.-", "K"},
    {".-..", "L"},
    {"--", "M"},
    {"-.", "N"},
    {"---", "O"},
    {".--.", "P"},
    {"--.-", "Q"},
    {".-.", "R"},
    {"...", "S"},
    {"-", "T"},
    {"..-", "U"},
    {"...-", "V"},
    {".--", "W"},
    {"-..-", "X"},
    {"-.--", "Y"},
    {"--..", "Z"},
    {"/", " "},
    {".----", "1"},
    {"..---", "2"},
    {"...--", "3"},
    {"....-", "4"},
    {".....", "5"},
    {"-....", "6"},
    {"--...", "7"},
    {"---..", "8"},
    {"----.", "9"},
    {"-----", "0"},
    {".-.-.-", "."},
    {"--..--", ","},
    {"---...", ","},
    {"..--..", "?"},
    {".----.", "'"},
    {"-....-", "-"},
    {".--.-.", "@"},
    {"-...-", "="}
});

MorseEncoderDecoder::MorseEncoderDecoder() = default;

MorseEncoderDecoder::~MorseEncoderDecoder() = default;

std::string MorseEncoderDecoder::encode(std::string &input) {
    std::string output;
    bool isFirst = true;
    for(const char &c : input) {
        auto iter = ASCII_TO_MORSE_LOOKUP.find(std::toupper(c));

        if (iter == ASCII_TO_MORSE_LOOKUP.end()) {
            return "Invalid input " + c;
        }
        
        if (!isFirst) {
            output.append(" ");
        }

        output.append(iter->second);
        isFirst = false;
    }

    return output;
}

std::string MorseEncoderDecoder::decode(std::string &input) {
    std::string output;
    std::string morseLetter;
    for(const char &c : input) {
        if (c != ' ') {
            morseLetter.push_back(c);
            continue;
        }

        auto opt = decodeMorseLetter(morseLetter);
        if (!opt) {
            return "Invalid input: " + morseLetter;
        }
        output.append(opt.value());
        morseLetter.clear();
    
    }
    
    if (!morseLetter.empty()) {
        auto opt = decodeMorseLetter(morseLetter);
        if (!opt) {
            return "Invalid input: " + morseLetter;
        }
        output.append(opt.value());
        morseLetter.clear();
    }
    

    return output;
}

std::optional<std::string> MorseEncoderDecoder::decodeMorseLetter(std::string &morseLetter) {
    auto iter = MORSE_TO_ASCII_LOOKUP.find(morseLetter);

    if (iter == MORSE_TO_ASCII_LOOKUP.end()) {
        return std::nullopt;
    }

    return { iter->second };
}