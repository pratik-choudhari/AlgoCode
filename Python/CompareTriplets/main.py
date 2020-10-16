a=input().split()
b=input().split()

score = [0,0]

for i in range (3):
    if(a[i]!=b[i]):
        if(a[i]>b[i]):
            score[0]=score[0]+1
        else:
            score[1]=score[1]+1
print(score)