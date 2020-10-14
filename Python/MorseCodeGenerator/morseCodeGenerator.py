
#Python morse code generator, Works for  alphanumeric characters and permitted special symbols

def init(a,b):
    global data
    data=a
    global type
    type=b

    global encode_dict

    #Morse code lookup table, alphabet to morse code


    encode_dict= {"a":'.-' , 'b': '-...','c':'-.-.','d':'-..','e':'.','f':'..-.','g':'--.','h':'....','i':'..','j':'.---',
            
            'k':'-.-','l':'.-..','m':'--','n':'-.','o':'---','p':'.--.','q':'--.-','r':'.-.','s':'...','t':'-',
            
            'u':'..-','v':'...-','w':'.--','x':'-..-','y':'-.--','z':'--..',' ': '/',
            
            '1':'.----', '2':'..---','3':'...--','4':'....-','5':'....','6':'-...',
            
            '7':'--..', '8':'---..','9':'----.','0':'-----',
            
            ',':'--..--','?':'..--..',':':'---...','-':'-....-' ,'"' : '.-..-.', '(': '-.--.' , ')': '-.--.-', 
            
            '+':'.-.-.', '/': '-..-.' , ';' : '-.-.-.', '.': '.-.-.-', '-':'-....-'}

    global decode_dict 
    
    #Morse code lookup table, morse code to alphabet
    
    decode_dict= {v: k for k,v in encode_dict.items()}

def decodeEncode():
    global data,type

    if(type==1):
        print("The Encoded String is : \n")
        temp=""
        for char in data:
            temp+=encode_dict[char] +" "

        print(temp+" ")
    else:
        data+=" "
        temp=""
        decoded=""

        for char in data:

            if(char==" "):

                if temp not in decode_dict.keys():
                    print("Please enter a vaild Morse Code \n")
                    return
                
                decoded+=decode_dict[temp]
                temp=""
            else:
                temp+=char
        print(decoded,'\n')



init(input("Enter the String to Encode or Decode \n").lower().strip(),
            int(input("Enter '1' to ENCODE STRING, \nENTER '2' TO DECODE STRING\n").strip()))
decodeEncode() #decode and encoding fucntion



