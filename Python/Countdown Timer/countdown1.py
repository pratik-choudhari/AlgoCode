# import the time module 
import time 
import pygame

# define the countdown func. 
def countdown(t): 
    
    while t:
        
        #divmod functions return quotient and remainder
        mins, secs = divmod(t, 60) 
        
        #:02d repesents that minutes and seconds will be 		represented in 2 digits
        timer = '{:02d}:{:02d}'.format(mins, secs) 
        pygame.mixer.init()
        pygame.mixer.music.load('clock.ogg')#any mp3/ogg file
        pygame.mixer.music.play()
       #while pygame.mixer.music.get_busy():
        pygame.time.Clock().tick()
        print(timer, end="\r") 
        time.sleep(1) 
        t -= 1
    print('Time\'s up!!!') 


# input time in seconds 
t = input("For how many seconds do you want to set the timer? ") 

# function call 
countdown(int(t)) 


