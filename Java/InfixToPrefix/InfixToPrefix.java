import java.util.Scanner;
import java.util.Stack;
public class InfixToPrefix {
static boolean isOperator(char c)  // function to check if the character is an operator
{ 
    return (!(c >= 'a' && c <= 'z') &&  
            !(c >= '0' && c <= '9') &&  
            !(c >= 'A' && c <= 'Z')); 
}

static int getPriority(char C)  // sets priority of the operators according to BEODMAS rule
{ 
    if (C == '-' || C == '+') 
        return 1; 
    else if (C == '*' || C == '/') 
        return 2; 
    else if (C == '^') 
        return 3; 
    return 0; 
}

static String infixToPrefix(String infix)  // converts infix to prefix
{ 

    Stack<Character> operators = new Stack<Character>(); 

    Stack<String> operands = new Stack<String>(); 
  
    for (int i = 0; i < infix.length(); i++)  
    { 

        if (infix.charAt(i) == '(')  
        { 
            operators.push(infix.charAt(i)); 
        } 

        else if (infix.charAt(i) == ')')  
        { 
            while (!operators.empty() &&  
                operators.peek() != '(')  
                { 
  
                // operand 1 
                String op1 = operands.peek(); 
                operands.pop(); 
  
                // operand 2 
                String op2 = operands.peek(); 
                operands.pop(); 
  
                // operator 
                char op = operators.peek(); 
                operators.pop(); 

                String tmp = op + op2 + op1; 
                operands.push(tmp); 
            } 
  
   
            operators.pop(); 
        } 

        else if (!isOperator(infix.charAt(i)))   // checks for operands and handles them
        { 
            operands.push(infix.charAt(i) + ""); 
        } 

        else  // checks for operators and handles them
        { 
            while (!operators.empty() &&  
                getPriority(infix.charAt(i)) <=  
                    getPriority(operators.peek()))  
                { 
  
                String op1 = operands.peek(); 
                operands.pop(); 
  
                String op2 = operands.peek(); 
                operands.pop(); 
  
                char op = operators.peek(); 
                operators.pop(); 
  
                String tmp = op + op2 + op1; 
                operands.push(tmp); 
            } 
  
            operators.push(infix.charAt(i)); 
        } 
    } 
  

    while (!operators.empty())  // pop stack to produce final expression
    { 
        String op1 = operands.peek(); 
        operands.pop(); 
  
        String op2 = operands.peek(); 
        operands.pop(); 
  
        char op = operators.peek(); 
        operators.pop(); 
  
        String tmp = op + op2 + op1; 
        operands.push(tmp); 
    } 

    return operands.peek(); 
} 
  

    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String infix=sc.next();
        System.out.println( infixToPrefix(infix));
    }
}
