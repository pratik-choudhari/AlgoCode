package Java.MorseCodeEncoderDecoder;

import java.util.*;

public class MorseCodeEncoderDecoder {
    public Map<Character, String> letters;
    public Map<String, Character> morseCode;

    public MorseCodeEncoderDecoder(){
        this.letters = createLetterMap();
        this.morseCode = createMorseMap();
    }

    public String encodeToMorse(String str){
        if(str.length() == 0){
            return "";
        }

        //Make input all caps to read map
        String input = str.toUpperCase();

        StringBuilder encoded = new StringBuilder();
        char[] words = input.toCharArray();

        //Go through and translate character by character
        for(char c: words){
            String code = letters.get(c);
            if(code != null){
                encoded.append(code).append(" ");
            } else {
                return "Invalid input" + c;
            }
        }

        //Trim additional space on the end of string
        return encoded.toString().trim();
    }

    public String decodeMorse(String morse){
        if(morse.length() == 0){
            return "";
        }

        //Split morse on space to get each code element
        String[] input = morse.split(" ");
        StringBuilder output = new StringBuilder();

        //Go through each encoded letter and find it in the morse map
        for(String curr: input){
            Character letter = morseCode.get(curr);
            if(letter!=null){
                output.append(letter);
            } else {
                return "Invalid input" + curr;
            }
        }

        return output.toString();
    }




    private Map<Character, String> createLetterMap(){
        Map<Character, String> map = new HashMap<>();
        map.put('A', ".-");
        map.put('B', "-...");
        map.put('C', "-.-.");
        map.put('D', "-..");
        map.put('E', ".");
        map.put('F', "..-.");
        map.put('G', "--.");
        map.put('H' , "....");
        map.put('I' , "..");
        map.put('J' , ".---");
        map.put('K' , "-.-");
        map.put('L' , ".-..");
        map.put('M' , "--");
        map.put('N' , "-.");
        map.put('O' , "---");
        map.put('P' , ".--.");
        map.put('Q' , "--.-");
        map.put('R' , ".-.");
        map.put('S' , "...");
        map.put('T' , "-");
        map.put('U' , "..-");
        map.put('V' , "...-");
        map.put('W' , ".--");
        map.put('X' , "-..-");
        map.put('Y' , "-.--");
        map.put('Z' , "--..");
        map.put(' ' , "/");
        map.put('1' , ".----");
        map.put('2' , "..---");
        map.put('3' , "...--");
        map.put('4' , "....-");
        map.put('5' , ".....");
        map.put('6' , "-....");
        map.put('7' , "--...");
        map.put('8' , "---..");
        map.put('9' , "----.");
        map.put('0' , "-----");
        map.put('.' , ".-.-.-");
        map.put(',' , "--..--");
        map.put(',' , "---...");
        map.put('?' , "..--..");
        map.put('\'' , ".----.");
        map.put('-' , "-....-");
        map.put('@' , ".--.-.");
        map.put('=' , "-...-");
        map.put('!', "-.-.--");
        return map;
    }

    private Map<String, Character> createMorseMap(){
        Map<String, Character> map = new HashMap<>();
        map.put(".-", 'A');
        map.put("-...", 'B');
        map.put("-.-.", 'C');
        map.put("-..", 'D');
        map.put(".", 'E');
        map.put("..-.", 'F');
        map.put("--.", 'G');
        map.put("....", 'H');
        map.put("..", 'I');
        map.put(".---", 'J');
        map.put("-.-", 'K');
        map.put(".-..", 'L');
        map.put("--", 'M');
        map.put("-.", 'N');
        map.put("---", 'O');
        map.put(".--.", 'P');
        map.put("--.-", 'Q');
        map.put(".-.", 'R');
        map.put("...", 'S');
        map.put("-", 'T');
        map.put("..-", 'U');
        map.put("...-", 'V');
        map.put(".--", 'W');
        map.put("-..-", 'X');
        map.put("-.--", 'Y');
        map.put("--..", 'Z');
        map.put("/", ' ');
        map.put(".----", '1');
        map.put("..---", '2');
        map.put("...--", '3');
        map.put("....-", '4');
        map.put(".....", '5');
        map.put("-....", '6');
        map.put("--...", '7');
        map.put("---..", '8');
        map.put("----.", '9');
        map.put("-----", '0');
        map.put(".-.-.-", '.');
        map.put("--..--", ',');
        map.put("---...", ',');
        map.put("..--..", '?');
        map.put(".----.", '\'');
        map.put("-....-", '-');
        map.put(".--.-.", '@');
        map.put("-...-", '=');
        map.put("-.-.--", '!');
        return map;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the String to encode: ");
        
        String input = in.nextLine();
        MorseCodeEncoderDecoder m = new MorseCodeEncoderDecoder();

        String encoded = m.encodeToMorse(input);
        System.out.println("The encoded morse is: " + encoded);

        System.out.println("Enter the Morse to decode: ");
        String morse = in.nextLine();

        String decoded = m.decodeMorse(morse);
        System.out.println("The decoded morse is: " + decoded);

        in.close();
    }
}
