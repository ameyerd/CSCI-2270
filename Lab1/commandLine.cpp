#include <iostream>

int main (int argc, char const *argv[])
{
  std :: cout << "Number of arguments: " ;
  std :: cout << argc << std :: endl;
  std :: cout << "Program arguments: " << std :: endl;
  for (int i =0; i < argc; i++)
  {
    std :: cout << "Argument #: " << i << ": " ;
    std :: cout << argv[i] << std :: endl;
  }
}


// ./commandLine
// Output:
// Number of arguments: 1
// Program arguments:
// Argument #: 0: ./commandLine

// ./commandLine arg1 arg2 arg3
// Output:
// Number of arguments: 4
// Program arguments:
// Argument #: 0: ./commandLine
// Argument #: 1: arg1
// Argument #: 2: arg2
// Argument #: 3: arg3
