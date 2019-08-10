//A program to convert an infix expression to a postfix expression
# include <iostream>
# include <stack>
# include <string>

using namespace std;

//Function which checks and returns if the passed character is an operand.
bool isOperand(char c)
{
    if(c >= '0' && c <= '9')
      return true;
    else if(c >= 'a' && c <='z')
      return true;
    else if(c >= 'A' && c <= 'Z')
      return true;
    return false;
}

//Function which checks and returns if the passed character is an operator.
bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c =='/')
      return true;
    return false;
}

//Function to calculate weightage of an operator so that we can decide how much precedence is to be given to each operator.
int getOperatorWeight(char Op)
{
    int Weight = -1;

    switch(Op)
    {
        case '+' :
        case '-' : Weight = 1;
                    break;

        case '*' :
        case '/' : Weight = 2;
                    break;

        case '^' : Weight = 3;
                    break;

    }
    return Weight;
}

//Function which returns which operator has higher precedence using the getOperatorWeight(char) function
bool hasHigherPrecedence(char op1, char op2)
{
    int op1Weight = getOperatorWeight(op1);
    int op2Weight = getOperatorWeight(op2);
    return op1Weight >= op2Weight ? true : false;
}

string infixToPostfix(string Exp)
{
    stack <char> S; //Stack to keep track of the operators and operands.
    string Postfix = ""; //The postfix expression is initially an empty string.
    for(int i = 0 ; i < Exp.length() ; i++) //Traverse every character of the input expression.
    {
        if(Exp[i] == ' ' && Exp[i] == ',') //If the character is a deleimiter, ignore it and continue to parse the expression.
        {
            continue;
        }

        else if(Exp[i] == '(') //If the scanned character is an open parantheses, blindly push it into the stack because it has highest precedence.
                              //A left parenthesis on the stack will not be removed unless an incoming right parenthesis is found.
        {
            S.push(Exp[i]);
        }

        else if(isOperand(Exp[i])) //If the scanned character is an operand, append it to the postfix expression because a postfix postfix expression
                                   //usually consist of operands followed by the operators.
        {
            Postfix += Exp[i];
        }

        else if(isOperator(Exp[i])) //If the scanned character is an operator
        {
            //If the scanned character has lower precedence than top of stack and the top of stack is not an opening parantheses, procced to the while loop.
            //Continue popping until the stack is not empty, the top element is not ( and S.top() has higher precedence than the scanned operator
            while(!S.empty() && S.top() != '(' && hasHigherPrecedence(S.top(), Exp[i]))
            {
                Postfix += S.top(); //Append the topmost element to the resulting postfix expression
                S.pop(); //Pop the topmost element
            }
            S.push(Exp[i]); //Push the scanned operator into the stack.
        }

        else if(Exp[i] == ')') //If the scanned character is an incoming closed parantheses, pop till the next left parantheses.
        {
            while(!S.empty() && S.top() != '(')
            {
                Postfix += S.top(); //Keep appending to the postfix expression
                S.pop(); //Pop from the stack
            }
            S.pop(); //Atlast pop the opening parantheses, but do not append it to the postfix expression.
        }
    }
    while(!S.empty()) //After the complete expression has benn scanned, append the remaining stack to the postfix expression.
    {
        Postfix += S.top();
        S.pop();
    }
    return Postfix; //Return the resulting postfix expression to main()
}

//Driver function
int main(void)
{
    string infixExpression;
    cout << "\nEnter an infix expression : ";
    cin >> infixExpression;
    string postfixExpression = infixToPostfix(infixExpression);
    cout << "The equivalent postfix expression is : " << postfixExpression;
    return 0;
}
