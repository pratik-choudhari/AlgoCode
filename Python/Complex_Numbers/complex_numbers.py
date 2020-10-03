# Complex Numbers

a,b = input().split()
c,d = input().split()
a = float(a)
b = float(b)
c = float(c)
d = float(d)

moda = (a**2+b**2)
modb = (c**2+d**2)

sign = "+" if b+d >=0 else ""
print(round(a+c,2),sign,round(b+d,2),"i",sep='')
sign = "+" if b-d >=0 else ""
print(round(a-c,2),sign,round(b-d,2),"i",sep='')
sign = "+" if (a*c+b*d) >=0 else ""
print(round(a*c-b*d,2),sign,round(a*d+b*c,2),"i",sep='')
sign = "+" if (-(a*d)+b*c) >=0 else ""
print(round((a*c+b*d)/modb,2),sign,round((-(a*d)+b*c)/modb,2),"i",sep='')
print(round(moda**0.5,2),"+0.00i",sep="")
print(round(modb**0.5,2),"+0.00i",sep="")
