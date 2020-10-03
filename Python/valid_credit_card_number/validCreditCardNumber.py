import re

def main():

    cardNumber = input()

    print(validateCreditCard(cardNumber))

    return

def validateCreditCard(cardNumber):

    # Validatyin the credit card number
    if bool(re.match('^([4-6]{1})([0-9]{15})*$', cardNumber)) == False and \
       bool(re.match('^([4-6]{1})([0-9]{3}-)([0-9]{4}-)([0-9]{4}-)([0-9]{4})*$', cardNumber)) == False:
        return 'No'

    cardNumber = cardNumber.replace('-', '')
    count = 0

    # Checking the repetitions
    for i in range(1, len(cardNumber)):
        if cardNumber[i] == cardNumber[i-1]:
            count += 1
            if count >= 4:
                return 'No'
        else:
            count = 0
       
    return 'Yes'

main()