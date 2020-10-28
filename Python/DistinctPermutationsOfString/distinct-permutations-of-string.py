class DistinctPermutations:
    def __init__(self,str):
        self.str = list(str) #convert to list for efficient swapping
        self.distinctPermutations(self.str,0,len(self.str))

    # check whether swap is required or not
    def swapRequired(self,str, startIndex, currentIndex):
        for i in range(startIndex, currentIndex):
            if str[i] == str[currentIndex]:
                return False
        return True

    #find all unique permutations of string
    def distinctPermutations(self,str,index,strLength):
        #base case
        if index >= strLength:
            print(''.join(str)) #convert list back to string before displaying
            return

        for x in range(index, strLength):
            #only swap if current char dont match char after the current char
            swap = self.swapRequired(str, index, x)
            if swap:
                #swap
                str[x], str[index], = str[index], str[x]
                #call function recurisvely
                self.distinctPermutations(str, index + 1, strLength)
                #swap
                str[x], str[index], = str[index], str[x]


# test case
test = DistinctPermutations('ABCA')
# output
'''
ABCA
ABAC
ACBA
ACAB
AACB
AABC
BACA
BAAC
BCAA
CBAA
CABA
CAAB
'''
