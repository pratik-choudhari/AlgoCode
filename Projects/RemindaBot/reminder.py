import time
import threading
import os
import playsound
import random
import json

ftime=0
ptime=0
start = -1

with open('./config.json') as f:
    config = json.load(f)

TIME = config['time']*60

a_files=os.listdir("./Audio_Files/")


def input_func():
    global ftime,ptime,start
    startevent.set()
    print(f"Welcome to ReminderBot! 0 to Pause and -1 to exit! Ill Remind you every {TIME/60} minutes")
    while(True):
        s = int(input())
        if s == 1:
            if not pauseevent.is_set():
                continue
            print("Reminder Resumed! Select 0 to pause and -1 to exit")
            ftime=ftime+time.time()-ptime
            pauseevent.clear() # Resume Remindabot
        elif s==0:
            if pauseevent.is_set():
                continue
            ptime = time.time()
            print(f"Reminder Paused! {(ptime-start)/60} mins elapsed (Select 1 to Resume and -1 to exit)")
            pauseevent.set()
        elif s==-1:
            killevent.set()
            break
    print("Program Exited")

def rem_func():
    global ftime,start
    while True:

        if killevent.is_set(): # Check if thread should be killed
            break
        if pauseevent.is_set(): # Check for Pause Condition
            continue

        if startevent.is_set(): # Check for initial Start condition of timer.
            start = time.time()
            startevent.clear()

        if not startevent.is_set(): # If startevent is false, Check for time match.
            if start!=-1:
                cur = time.time()
                if cur-start-ftime>=TIME:
                    print(f"{TIME/60} mins has elapsed")
                    playsound.playsound(f"./Audio_Files/{random.choice(a_files)}",True)
                    startevent.set()
                    ftime=0

pauseevent = threading.Event()
killevent = threading.Event()
startevent = threading.Event()


t1 = threading.Thread(target=input_func)
t2 = threading.Thread(target=rem_func)

t1.start()
t2.start()