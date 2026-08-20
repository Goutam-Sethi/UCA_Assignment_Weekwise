// Problem Statement

// Given a postfix expression, evaluate and return its result.

// In postfix notation, operators are placed after their operands, so parentheses are not required to determine the order of evaluation.

// For example:

// 2 3 1 * + 9 -

// The evaluation order is:

// 3 * 1 = 3
// 2 + 3 = 5
// 5 - 9 = -4

// Therefore, the output is:

// -4

// Constraints:

// 0 < Length of expression < 50

// Operands are numeric.

// Operators are:

// for addition
// for subtraction
// for multiplication
// / for division

// Every token in the expression is separated by a space.

// Sample Input:

// 2 3 1 * + 9 -

// Sample Output:

// -4

import java.util.Stack;

class PostfixExpressionEval {
  private static int operation(int a, int b, char operator) {
  switch (operator) {
    case '+':
      return a + b;

    case '-':
      return a - b;

    case '*':
      return a * b;

    case '/':
      return a / b;

    default:
      return 0;
  }
}

  public static int evaluatePostfix(String expression) {
    Stack<Integer> operands = new Stack<>();
    int length = expression.length();

    for (int i=0; i<length; i++) {
      StringBuilder sb = new StringBuilder();

      while (i < length && expression.charAt(i) != ' ') {
        sb.append(expression.charAt(i));
        i++;
      }

      if (Character.isDigit(sb.charAt(0))) {
        operands.add(Integer.parseInt(sb.toString()));
      } 
      else {
        int val2 = operands.pop();
        int val1 = operands.pop();
        char operator = sb.charAt(0);

        operands.add(operation(val1, val2, operator));
      }
    }

    return operands.peek();
  }

  public static void main(String[] argc) {
    String expression = "2 3 1 * + 9 -";
    System.out.println(evaluatePostfix(expression));
  }
}