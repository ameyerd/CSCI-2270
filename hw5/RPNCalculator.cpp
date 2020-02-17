#include <iostream>
#include "RPNCalculator.hpp"
using namespace std;

RPNCalculator::RPNCalculator()
{
  stackHead = NULL;
}

RPNCalculator::~RPNCalculator()
{
  // pop everything off the stack and set stackHead to NULL
  while(!isEmpty())
  {
    pop();
  }

  stackHead = NULL;
}

bool RPNCalculator::isEmpty()
{
  return stackHead == NULL;
}

void RPNCalculator::push(float num)
{
  Operand *nn = new Operand;

  nn->number = num;
  nn->next = NULL;
  nn->next = stackHead;
  stackHead = nn;
}

void RPNCalculator::pop()
{
  if(!isEmpty())
  {
      Operand* temp = stackHead;
      stackHead = stackHead->next;
      delete temp;
  }
  else
  {
      cout<<"Stack empty, cannot pop an item."<<endl;
  }
}

//here
Operand *RPNCalculator::peek()
{
  if(!isEmpty())
      //return a pointer to the top of the stack
      return stackHead;
  else{
      cout<<"Stack empty, cannot peek."<<endl;
      return NULL;
  }
}


// Operand *RPNCalculator::getStackHead()
// {
//   return stackHead;
// }


bool RPNCalculator::compute(string symbol)
{
  //if the stack is empty
  if(isEmpty())
  {
    cout << "err: not enough operands" << endl;
    return false;
  }

  // if invalid operation is inputted
  if(symbol != "+" && symbol != "*")
  {
    cout << "err: invalid operation" << endl;

    return false;
  }

  // if list is empty after popping of first element
  if(stackHead->next == NULL){
    cout << "err: not enough operands" << endl;
    return false;
  }

  // else pop
  if(symbol == "+")
  {
    Operand *first = stackHead;

    Operand *second = stackHead->next;

    float total = first->number + second->number;

    pop();
    pop();

    push(total);

    return true;
  }

  if(symbol == "*")
  {
    Operand *first = stackHead;
    Operand *second = stackHead->next;

    float total = first->number * second->number;

    pop();
    pop();

    push(total);

    return true;
  }

  return false;

}
