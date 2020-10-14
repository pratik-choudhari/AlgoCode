# All morse alphabets are being hardcoded
morse_alphabets ={
        "A" : ".-",
        "B" : "-...",
        "C" : "-.-.",
        "D" : "-..",
        "E" : ".",
        "F" : "..-.",
        "G" : "--.",
        "H" : "....",
        "I" : "..",
        "J" : ".---",
        "K" : "-.-",
        "L" : ".-..",
        "M" : "--",
        "N" : "-.",
        "O" : "---",
        "P" : ".--.",
        "Q" : "--.-",
        "R" : ".-.",
        "S" : "...",
        "T" : "-",
        "U" : "..-",
        "V" : "...-",
        "W" : ".--",
        "X" : "-..-",
        "Y" : "-.--",
        "Z" : "--..",
        " " : "/",
        "1" : ".----",
        "2" : "..---",
        "3" : "...--",
        "4" : "....-",
        "5" : ".....",
        "6" : "-....",
        "7" : "--...",
        "8" : "---..",
        "9" : "----.",
        "0" : "-----",
        "." : ".-.-.-",
        "," : "--..--",
        ":" : "---...",
        "?" : "..--..",
        "'" : ".----.",
        "-" : "-....-",
        "@" : ".--.-.",
        "=" : "-...-"
        }



inverse_morse_alphabets = dict((v,k) for (k,v) in morse_alphabets.items())

class MorseEncodeDecode:
    
    #this takes the input and translates to english using an inverse dictionary and key positioning 
    def decodeFromMorse(self, code, position_in_string = 0):
        
        if position_in_string < len(code):
            morse_letter = ""
            for key,char in enumerate(code[position_in_string:]):
                if char == " ":
                    position_in_string = key + position_in_string + 1
                    letter = inverse_morse_alphabets[morse_letter]
                    return letter + decodeFromMorse(code, position_in_string)
                
                else:
                    morse_letter += char
        else:
            return ""
    
    # this just takes the input and translates them using the above dictionary
    def encodeToMorse(self, message):
        
        encoded_message = ""
        for char in message[:]:
            encoded_message += morse_alphabets[char.upper()] + " "
                
        return encoded_message