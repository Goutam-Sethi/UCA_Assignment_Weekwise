// Problem Statement

// Given a string expression, write a program to determine whether the pairs of parentheses (), square brackets [], and curly brackets {} are correctly balanced.

// A string is balanced if:

// * Every opening bracket has a corresponding closing bracket.
// * Brackets are closed in the correct order.

// The solution should run in O(N) time.

// Constraints:
// 0 < Length(expression) <= 30

// Input 1:
// [()]{}{()()}

// Output 1:
// true

// Input 2:
// [()

// Output 2:
// false


import java.util.Stack;

public class balancedParenthesis {

  public static boolean isBalanced(String str) {
    Stack<Character> stack = new Stack<>();

    for (char ch : str.toCharArray()) {
      if (ch == '(' || ch == '[' || ch == '{') {
        stack.push(ch);
      } else if (ch == ')' || ch == ']' || ch == '}') {
        if (stack.isEmpty()) {
          return false;
        }

        char top = stack.pop();

        if ((ch == ')' && top != '(') ||
            (ch == ']' && top != '[') ||
            (ch == '}' && top != '{')) {
          return false;
        }
      }
    }

    return stack.isEmpty();
  }

  public static void main(String[] args) {
    String str1 = "[()]{}{()()}";
    System.out.println(isBalanced(str1));

    String str2 = "[()";
    System.out.println(isBalanced(str2));
  }
}