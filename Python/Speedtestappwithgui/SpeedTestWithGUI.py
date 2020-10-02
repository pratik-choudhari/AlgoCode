#Important Libraries imported
from tkinter import Tk,Button,Label,CENTER,Place,PhotoImage,IntVar,Radiobutton,Canvas
import urllib
from PIL import Image,ImageTk
from speedtest import Speedtest
#buttonidentify function to identify which button was pressed
def button_identify(id):
    if(id == 1):
        speed_kbps()
        downlabel.place(x = 40, y = 120) 
        uplabel.place(x = 40,y =150) 
    if(id==2):
        speed_mbps()
        downlabel.place(x = 40, y = 120) 
        uplabel.place(x = 40,y = 150) 
#speed_mbps to get internet speed in Mbps
def speed_mbps():
    speedinst = Speedtest()
    down,up = speedinst.download(),speedinst.upload()
    download_speed = round(down/(10**6),2)
    upload_speed = round(up/(10**6),2)
    downlabel.config(text="Download Speed: " + str(download_speed) + " Mbps")
    uplabel.config(text="Upload Speed: " + str(upload_speed) + " Mbps")
#speed_kbps to get internet speed in Kbps
def speed_kbps():
    speedinst = Speedtest()
    down,up = speedinst.download(),speedinst.upload()
    download_speed = round(down/(10**3),2)
    upload_speed = round(up/(10**3),2)
    downlabel.config(text="Download Speed: " + str(download_speed) + " Kbps")
    uplabel.config(text="Upload Speed: " + str(upload_speed) + " Kbps")
#radiobutton identifier to know which button was selected
def selector():
    select = v.get()
    print(select)
    if(select == 1):
        but = Button(tk,text="Get Internet Speed",width=30,command=lambda: button_identify(1),bg="cyan")
        print(select)
        but.place(x = 40,y = 180)
    if(select==2):
        but = Button(tk,text="Get Internet Speed",width=30,command=lambda: button_identify(2),bg="cyan")
        but.place(x = 40,y = 180) 
         

tk = Tk()
tk.title("Internet Speed Test")
tk.geometry("300x300")
downlabel = Label(tk,text="",font=50,bg="lightblue")
uplabel = Label(tk,text="",font=50,bg="lightblue")
#label asking in which format you want speed test
Label(tk,text="Choose format to get internet speed : ",bg="lightblue",font=10).place(x=30,y=220)
v = IntVar() 
Radiobutton(tk, text='Kbps', variable=v, value=1,command=selector,bg="lightblue",font=5).place(x=35,y=250)
Radiobutton(tk, text='Mbps', variable=v, value=2,command=selector,bg="lightblue",font=5).place(x=100,y=250)
#favicon for application
urllib.request.urlretrieve("https://icons.iconarchive.com/icons/chrisbanks2/cold-fusion-hd/128/speed-test-icon.png", "favicon.png")
img = Image.open("favicon.png")
p = PhotoImage(file="favicon.png")
tk.iconphoto(False,p)
tk.config(background="lightblue")
#image added to get gui a better look
urllib.request.urlretrieve("https://inteng-storage.s3.amazonaws.com/img/iea/zBwgmajpGK/sizes/speed-test-tools_resize_md.jpg", "head.jpg")
img = Image.open("head.jpg")     
img = img.resize((150,80),Image.ANTIALIAS)
img = ImageTk.PhotoImage(img)      
ilabel = Label(tk,image= img)
ilabel.place(x=80,y=10)
tk.mainloop()