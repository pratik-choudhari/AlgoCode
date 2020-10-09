def InfixToPostfix(exp):
    rank = {'^': 3}
    rank.update(dict.fromkeys(['*', '%', '/'], 2))
    rank.update(dict.fromkeys(['+', '-'], 1))

    stack, ans = [], []
    for ele in exp:
        if ele == ' ':
            continue
        if ele.isalpha():
            ans.append(ele)
        elif ele == '(':
            stack.append(ele)
        elif ele == ')':
            while stack and stack[-1] != '(':
                ans.append(stack.pop())
            if stack[-1] == '(':
                stack.pop()
        else:
            while stack and rank.get(ele, 0) <= rank.get(stack[-1], 0):
                ans.append(stack.pop())
            stack.append(ele)
    while stack:
        ans.append(stack.pop())

    return ''.join(ans)


if __name__ == "__main__":
    expression = input("Enter an infix expression: ")
    print(f'The postfix expression: {InfixToPostfix(expression)}')
