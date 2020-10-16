# Autor: Daniel Martínez(TrebolDan)

#Reading input lines
a=input().split()
b=input().split()

# score[0] to A & score[1] to B
score = [0,0]

# Comparing triplets 
for i in range (3):
    if(a[i]!=b[i]): # If equals, neither one gets a point
        if(a[i]>b[i]): 
            score[0]=score[0]+1 # A bigger than B
        else:
            score[1]=score[1]+1 # B bigger than A
# Printing out score
print(score)