

# Python program for KMP Algorithm 

def kmp_preprocess(pattern):

    # create lps[] that will hold the longest prefix suffix  
    lps = [0] * len(pattern)

    for i in range(1, len(pattern)):

        j = lps[i - 1]

        while j > 0 and pattern[i] != pattern[j]:

            j = lps[j - 1]

        if pattern[i] == pattern[j]:

            lps[i] = j + 1

    return lps


def kmp(pattern, text):

  lps = kmp_preprocess(pattern)

  results = []
  N=len(text)
  M=len(pattern)
  j = 0 # index for pattern[] 
  i = 0 # index for text[] 

  while i < N: 
    if pat[j] == txt[i]: 
            i += 1
            j += 1
  
    if j == M: 
            results.append(i-j);
            j = lps[j-1] 
  
        # mismatch after j matches 
    elif i < N and pattern[j] != txt[i]: 
            # Do not match lps[0..lps[j-1]] characters 
            # they will match anyway 
        if j != 0: 
                j = lps[j-1] 
        else: 
                i += 1

  return results


  
txt = input("enter the text   ")
pat = input("enter the pattern  ")
matchingIndexes=kmp(pat, txt) 
#print(" The text contains the pattern at indexes ")
print(len(matchingIndexes))
  
