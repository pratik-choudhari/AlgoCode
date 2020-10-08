s = input("Enter your input:") 

counterZero = 0
counterOne = 0
counterTwo = 0
counterTree = 0
counterFour = 0
counterFive = 0
counterSix = 0
counterSeven = 0
counterEight = 0
counterNine = 0

for i in s:
    if i == "0":
        counterZero+=1
    if i == "1":
        counterOne+=1
    if i == "2":
        counterTwo+=1
    if i == "3":
        counterTree+=1
    if i == "4":
        counterFour+=1
    if i == "5":
        counterFive+=1
    if i == "6":
        counterSix+=1
    if i == "7":
        counterSeven+=1
    if i == "8":
        counterEight+=1
    if i == "9":
        counterNine+=1
        
print(str(counterZero)+" "+str(counterOne)+" "+str(counterTwo)+" "+str(counterTree)+" "+str(counterFour)+" "+str(counterFive)+" "+str(counterSix)+" "+str(counterSeven)+" "+str(counterEight)+" "+str(counterNine))        
    
    
    
        
        
        