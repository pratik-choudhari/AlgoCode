import morse_encode_decode

En_Dn = morse_encode_decode.MorseEncodeDecode()

def encode_decode(argument):
    
    if argument == "1":
        argument = input("Enter text to encode:\n")
        return En_Dn.encodeToMorse(argument) 
    # passses args to encodeToMorse fn in MorseEncodeDecode class in morse_encode_decode file
    
    elif argument == "2":
        argument = input("Enter Morse text:\n")
        return En_Dn.decodeFromMorse(argument)
    # passses args to decodeFromMorse fn in MorseEncodeDecode class in morse_encode_decode file
    else:
        print("Invalid option")
        exit
    
if __name__ == "__main__": 
    argument = input("Enter an option \n1.Encode to MorseCode \n2.Decode from MorseCode\n")
    print(encode_decode(argument))