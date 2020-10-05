#!/usr/bin/python3
import sys

"""
    The python function written compresses the string taken as input
    the compressed string is represented as character followed by its
    consecutive repetition count
"""

def main(argv):
    s = str(input('Input String : '))
    
    # corner case when user enters nothing
    if(len(s) == 0):
        print('You entered empty string !')
        return None
   

    count = 0
    # tracks the previous characters
    prev_char = s[0]

    # list contains the tuples having character and consecutive count
    compress_string_list = []

    # for each character compare it with previous character encountered
    for char in s:
        # different characters encountered then append to the list
        if prev_char != char:
            compress_string_list.append((prev_char, count))
            count = 1
            prev_char = char
        # same characters encountered then increment its count
        else:
            count = count + 1

    # last character frequency to be appended
    compress_string_list.append((prev_char, count))
    
    # format the output as required in the question
    output = " ".join('(' + str(s[0]) + ',' + str(s[1]) + ')' for s in compress_string_list)
    
    # print the compressed string
    print('Ouput String : ' + output)


if __name__ == '__main__':
    main(sys.argv)

