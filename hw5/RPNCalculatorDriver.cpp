/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <string>
#include <iomanip>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  // TODO - Declare a stack to hold the operands
  RPNCalculator cal;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  while(true)
  {
    cout << "#> ";
    /* TODO
       1. Read input (operators and operands) until you encounter a "="
       2. Use the isNumber function to check if the input is an operand
       3. push all operands to the stack
       4. If input is not an operand, call the compute function to evaluate
          the partial expression
    */
    string input;
    getline(cin, input);

    if(input == "=")
    {
      break;
    }

    if(isNumber(input))
    {
      float num_input = stof(input);
      cal.push(num_input);
      // cout << "inserted: " << cal.peek() << endl;
    }

    if(input == "+" || input == "*")
    {
      cal.compute(input);
      // cout << "compute!" << endl;
    }


  }

  /* TODO - If the stack is empty then print "No operands: Nothing to evaluate" */
  if(cal.getStackHead() == NULL)
  {
    cout << "No operands: Nothing to evaluate" << endl;
    return 0;
  }


  /* TODO - Validate the expression
      1. If valid then print the result
      2. Else, print "Invalid expression"*/

  Operand *top = cal.getStackHead();
  float top_num = top->number;

  cal.pop();
  if(cal.getStackHead() != NULL)
  {
    cout << "Invalid expression" << endl;
    return 0;
  }
  else
  {
    cal.push(top_num);
    cout << setprecision(4) << top_num << endl;
  }

  return 0;
}
