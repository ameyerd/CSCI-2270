//problem 2
#include <iostream>
using namespace std;

void reset(int *ip)
{
  *ip = 0;
}

int main() {

  int i = 100;
  int *p = &i;
  reset(p);
  cout << *p << endl;
}

// problem 4
// void swap(int &v1, int &v2)
// {
//   int tmp= v2;
//   v2 = v1;
//   v1 = tmp;
// }
//
// int main() {
//   int i = 10;
//   int j = 20;
//   cout << "Before swap() " << i << ":" <<j << endl;
//   swap(i, j);
//   cout << "After swap() " << i << ":" <<j << endl;
//   return 0;
// }

//problem 5 & 6
// void Swap(int& x, int y) ;
//
// int main(void) {
//   int a = 1;
//   int b = 2;
//   Swap(a, b);
//   cout << a << ", " << b << endl;
//   return 0;
// }
//
// void Swap(int& x, int y) {
//   int temp = x;
//   x = y;
//   y = temp;
// }

//problem 7
// int main(void) {
//   int m=1, n=2;
//
//   int *pm=&m, *pn=&n, *r;
//
//   r=pn;
//
//   pn=pm;
//
//   *pm=*pn+2;
//
//   cout <<m <<"," <<n <<"," <<*r <<"," <<*pm << endl;
// }

// // problem 10
// void calculateCost(int count, float& subTotal, float taxCost){
//   if (count < 10) {
//     subTotal = count*0.50;
//   }
//   else {
//     subTotal = count*0.20;
//   }
//   taxCost = 0.1*subTotal;
// }
//
// float tax = 0.0;
//   subtotal = 0.0;
//
// calculateCost(15,subtotal,tax);
// cout << "The cost for 15 items is " << subtotal << ", and the tax for" << subtotal << "is" << tax << endl;
// // end of fragment
