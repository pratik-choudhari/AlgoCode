from gtts import gTTS
import os
import playsound
import json

with open('./config.json') as f:
    config = json.load(f)

mytext = config['text']
if not mytext == "Lets take a walk":
    language = 'en'

    myobj = gTTS(text=mytext, lang=language, slow=False) 

    n=len(os.listdir("./Audio Files/")) 
    myobj.save(f"./Audio Files/Audio{n+1}.mp3") 

    # Playing the converted file 
    playsound.playsound(f"./Audio Files/Audio{n+1}.mp3",True)