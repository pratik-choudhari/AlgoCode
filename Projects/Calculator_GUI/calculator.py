from tkinter import *
import math
import parser
import tkinter.messagebox

root= Tk()
root.title("Scientific Calculator")
root.configure(background='black')
root.resizable(width=False, height=False)
root.geometry("480x550+0+0")

calc=Frame(root)
calc.grid()

class Calc():
    def __init__(self):
        self.total = 0
        self.current = ""
        self.input_value = True
        self.check_sum = False
        self.op = ""
        self.result = False

    def numberEnter(self, num):
        self.result = False
        firstnum= txtDisplay.get()
        secondnum= str(num)
        if self.input_value:
            self.current = secondnum
            self.input_value = False
        else:
            if secondnum == '.':
                if secondnum in firstnum:
                    return
            self.current = firstnum + secondnum
        self.display(self.current)

    def sum_of_total(self):
        self.result = True
        self.current = float(self.current)
        if self.check_sum == True:
            self.valid_function()
        else:
            self.total = float(txtDisplay.get())
            
    def display(self, value):
        txtDisplay.delete(0, END)
        txtDisplay.insert(0, value)

    def valid_function(self):
        if self.op == 'add':
            self.total += self.current
        if self.op == 'sub':
            self.total -= self.current
        if self.op == 'multi':
            self.total *= self.current
        if self.op == 'divide':
            self.total /= self.current
        if self.op == 'mod':
            self.total %= self.current
        self.input_value = True
        self.check_sum = False
        self.display(self.total)
            
    def operation(self, op):
        self.current = float(self.current)
        if self.check_sum:
            self.valid_function()
        elif not self.result:
            self.total = self.current
            self.input_value = True
        self.check_sum = True
        self.op=op
        self.result = False

    def Clear_Entry(self):
        self.display(0)
        self.current = "0"
        self.input_value = True
        self.result = False

    def all_Clear_Entry(self):
        self.Clear_Entry()
        self.total = 0

    def pi(self):
        self.result = False
        self.current = math.pi
        self.display(self.current)

    def tau(self):
        self.result = False
        self.current = math.tau
        self.display(self.current)
        
    def sin(self):
        self.result = False
        self.current = math.sin(math.radians(float(txtDisplay.get())))
        self.display(self.current)
        
    def cos(self):
        self.result = False
        self.current = math.cos(math.radians(float(txtDisplay.get())))
        self.display(self.current)
        
    def tan(self):
        self.result = False
        self.current = math.tan(math.radians(float(txtDisplay.get())))
        self.display(self.current)
        
    def cosec(self):
        self.result = False
        self.current = 1/math.sin(math.radians(float(txtDisplay.get())))
        self.display(self.current)
        
    def sec(self):
        self.result = False
        self.current = 1/math.cos(math.radians(float(txtDisplay.get())))
        self.display(self.current)
        
    def cot(self):
        self.result = False
        self.current = 1/math.tan(math.radians(float(txtDisplay.get())))
        self.display(self.current)
        
    def sqroot(self):
        self.result = False
        self.current = math.sqrt(float(txtDisplay.get()))
        self.display(self.current)
        
    def sq(self):
        self.result = False
        self.current = math.pow(float(txtDisplay.get()),2)
        self.display(self.current)

    def cube(self):
        self.result = False
        self.current = math.pow(float(txtDisplay.get()),3)
        self.display(self.current)

    def fact(self):
        self.result = False
        self.current = math.factorial(float(txtDisplay.get()))
        self.display(self.current)

    def inverse(self):
        self.result = False
        self.current = 1/(float(txtDisplay.get()))
        self.display(self.current)

    def x10(self):
        self.result = False
        self.current = math.pow(10,float(txtDisplay.get()))
        self.display(self.current)

    def mathsPM(self):
        self.result = False
        self.current = -(float(txtDisplay.get()))
        self.display(self.current)
    
    def e(self):
        self.result = False
        self.current = math.e
        self.display(self.current)

    def exp(self):
        self.result = False
        self.current = math.exp(float(txtDisplay.get()))
        self.display(self.current)

    def log(self):
        self.result = False
        self.current = math.log(float(txtDisplay.get()))
        self.display(self.current)

    def log2(self):
        self.result = False
        self.current = math.log2(float(txtDisplay.get()))
        self.display(self.current)
        
    def log10(self):
        self.result = False
        self.current = math.log10(float(txtDisplay.get()))
        self.display(self.current)
        
    def degrees(self):
        self.result = False
        self.current = math.degrees(float(txtDisplay.get()))
        self.display(self.current)

added_value=Calc()

txtDisplay=Entry(calc, font=('Arial',20,'bold'), bg='seashell4', fg='ivory2', bd=22, width=29, justify=RIGHT)
txtDisplay.grid(row=0, column=0, columnspan=4, pady=1)
txtDisplay.insert(0,"0")

#------------------------Adding 9 digits in 3x3 grid------------------------------#
numberpad='789456123'
i=0
btn=[]
for j in range(2,5):
    for k in range(3):
        btn.append(Button(calc, width=6, height=2, font=('Arial',20,'bold'), bg='dim gray', fg='ivory2', bd=4, text=numberpad[i]))
        btn[i].grid(row=j, column=k, pady=1)
        btn[i]["command"] = lambda x = numberpad[i] : added_value.numberEnter(x)
        i+=1

#--------------------------- Adding other buttons ----------------------------#
btnClear= Button(calc, text=chr(67), width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.Clear_Entry).grid(row=1, column=0, pady = 1)
btnAllClear= Button(calc, text=chr(67)+chr(69), width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.all_Clear_Entry).grid(row=1, column=1, pady = 1)

#------------------------ Adding standard buttons ----------------------------#

btnSqrt= Button(calc, text='√', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.sqroot).grid(row=1, column=2, pady = 1)
btnAdd= Button(calc, text='+', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command = lambda: added_value.operation("add")).grid(row=1, column=3, pady = 1)
btnSub= Button(calc, text='-', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command = lambda: added_value.operation("sub")).grid(row=2, column=3, pady = 1)
btnMul= Button(calc, text='*', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command = lambda: added_value.operation("multi")).grid(row=3, column=3, pady = 1)
btnDiv= Button(calc, text=chr(247), width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command = lambda: added_value.operation("divide")).grid(row=4, column=3, pady = 1)

btnZero= Button(calc, text='0', width=6, height=2, font=('Arial',20,'bold'),bg='seashell4', fg='ivory2', bd=4,
                command = lambda: added_value.numberEnter(0)).grid(row=5, column=1, pady = 1)
btnDot= Button(calc, text='.', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command = lambda: added_value.numberEnter('.')).grid(row=5, column=2, pady = 1)
btnPM= Button(calc, text=chr(177), width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.mathsPM).grid(row=5, column=0, pady = 1)
btnEquals= Button(calc, text='=', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.sum_of_total).grid(row=5, column=3, pady = 1)

#--------------------------Adding scientific buttons----------------------------#

lb=Label(calc, text="Scientific Calculator", font=('Arial',30,'bold'), justify=CENTER)
lb.grid(row=0, column=4, columnspan=4)

#row 1
btnPi= Button(calc, text='π', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.pi).grid(row=1, column=4, pady = 1)
btnCos= Button(calc, text='cos', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.cos).grid(row=1, column=5, pady = 1)
btnSin= Button(calc, text='sin', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.sin).grid(row=1, column=6, pady = 1)
btnTan= Button(calc, text='tan', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.tan).grid(row=1, column=7, pady = 1)

#row 2
btn2Pi= Button(calc, text='2π', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.tau).grid(row=2, column=4, pady = 1)
btnCosec= Button(calc, text='cosec', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.cosec).grid(row=2, column=6, pady = 1)
btnSec= Button(calc, text='sec', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.sec).grid(row=2, column=5, pady = 1)
btnCot= Button(calc, text='cot', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.cot).grid(row=2, column=7, pady = 1)

#row 3
btnlog= Button(calc, text='log', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.log).grid(row=3, column=4, pady = 1)
btnSq= Button(calc, text='x^2', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.sq).grid(row=3, column=5, pady = 1)
btnCube= Button(calc, text='x^3', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.cube).grid(row=3, column=6, pady = 1)
btnFact= Button(calc, text='n!', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.fact).grid(row=3, column=7, pady = 1)

#row 4
btnlog2= Button(calc, text='log2', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.log2).grid(row=4, column=4, pady = 1)
btnE= Button(calc, text='e', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.e).grid(row=4, column=5, pady = 1)
btnMod= Button(calc, text='mod', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command = lambda: added_value.operation("mod")).grid(row=4, column=6, pady = 1)
btnExp= Button(calc, text='Exp', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.exp).grid(row=4, column=7, pady = 1)

#row 5
btnlog10= Button(calc, text='log10', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.log10).grid(row=5, column=4, pady = 1)
btnInverse= Button(calc, text='1/n', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command= added_value.inverse).grid(row=5, column=5, pady = 1)
btndeg= Button(calc, text='deg', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command=added_value.degrees).grid(row=5, column=6, pady = 1)
btn10x= Button(calc, text='10^x', width=6, height=2, font=('Arial',20,'bold'),
                 bg='seashell4', fg='ivory2', bd=4, command= added_value.x10).grid(row=5, column=7, pady = 1)


#-----------------------------MENU and its functionality------------------------#

def iExit():
    iExit=tkinter.messagebox.askyesno("Scientific Calculator", "Do you want to Exit?")
    if iExit>0:
        root.destroy()
        return

def Scientific():
    root.resizable(width=False, height=False)
    root.geometry("944x550+0+0")

def Standard():
    root.resizable(width=False, height=False)
    root.geometry("480x550+0+0")
    

menubar=Menu(calc)
filemenu=Menu(menubar, tearoff=0)
menubar.add_cascade(label = 'File', menu=filemenu)
filemenu.add_command(label = 'Standard', command=Standard)
filemenu.add_command(label = 'Scientific', command=Scientific)
filemenu.add_separator()
filemenu.add_command(label = 'Exit', command=iExit)


root.configure(menu=menubar)
root.mainloop()
