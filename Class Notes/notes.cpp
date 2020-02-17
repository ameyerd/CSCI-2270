#include <iostream>
using namespace std;

int main() {
  char A[4] = {'H','i','!', NULL};

  cout << A << endl;
  cout << A[0] << endl;
  cout << *A << endl;
}

// cu-tcom-3-10:class ameyerdenebileg$ ./test
// Hi!
// H
// H
