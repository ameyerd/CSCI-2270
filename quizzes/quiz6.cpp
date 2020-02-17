#include <iostream>
using namespace std;

// int myFunc(int n)
// {
//   int result = 0;
//   if (n <=0)
//     return 1;
//   result = n * myFunc(n-2);
//   return result;
// }
//
// int main()
// {
//   cout << myFunc(7);
//   return 0;
// }

int f(int x)
{
  return ((x>0)?x*f(x-1):2);
}

int main()
{
  int i = f(f(2));

  cout << i << endl;
}
