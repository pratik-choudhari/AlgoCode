#include <string>
#include <iostream>
#include "Include/morse_encoder_decoder.hpp"

int main() {
    MorseEncoderDecoder morse_encoder_decoder = MorseEncoderDecoder();

    std::cout << "enter string to encode into morse: ";
    std::string input;
    std::getline(std::cin, input);
    auto morse = morse_encoder_decoder.encode(input);
    std::cout << "input in morse: " << morse << std::endl;

    std::string toDecode;
    std::cout << "enter morse string to decode: ";
    std::getline(std::cin, toDecode);
    std::cout << "string to decode: " << toDecode << std::endl;
    auto toString = morse_encoder_decoder.decode(toDecode);
    std::cout << "input in ascii: " << toString << std::endl;

    return 0;
}