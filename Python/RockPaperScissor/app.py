import random

valid_inputs = ["rock", "paper", "scissor"]

def ask_the_user():
    val = input("Choose: rock, paper, scissor \n") 
    if val in valid_inputs:
        return val
    else:
        print("Sorry, I can't understand")
        return ask_the_user()

def ask_the_PC():
    return random.choice(valid_inputs)

def get_the_winner(user_response, pc_response):
    usr = valid_inputs.index(user_response)
    pc = valid_inputs.index(pc_response)
    if usr == pc:
        return "TIE"
    else:
        difference = abs(usr - pc)
        if difference == 1:
            return ("User wins!","PC wins!")[usr < pc]
        else:
            return ("User wins!","PC wins!")[usr > pc]

def main():
    user_response = ask_the_user()
    pc_response = ask_the_PC()
    print(f"The PC choosed  {pc_response}")
    print(get_the_winner(user_response, pc_response))

if __name__ == "__main__":
    main()

