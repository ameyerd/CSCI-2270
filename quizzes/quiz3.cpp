#include <iostream>
using namespace std;

// class Test {
//   int x;
// };
// int main()
// {
//   Test t;
//   cout << t.x;
//   return 0;
// }

// struct Distance
// {
//   int feet;
//   int inch;
// };
//
// int main()
// {
//   Distance d;
//   d.feet = 10;
//   d.inch = 5;
//
//   int* ptr1;
//   Distance* ptr2;
//
//   // ptr1 = &d;
//   ptr2 = &d;
//
//   cout << "Distance = " << (*ptr2).feet << " ft" << endl;
// }
//
// void swap0(int* ptr1, int* ptr2)
//  {
//    int *temp;
//    temp = ptr1;
//    ptr1 = ptr2;
//    ptr2 = temp;
//  }
//
//  void swap1(int ptr1, int ptr2)
//   {
//     int temp;
//     temp = ptr1;
//     ptr1 = ptr2;
//     ptr2 = temp;
//   }
//
//   void swap2(int *&ptr1, int *&ptr2)
//    {
//      int* temp;
//      temp = ptr1;
//      ptr1 = ptr2;
//      ptr2 = temp;
//    }
//
//    void swap3(int &ptr1, int &ptr2)
//     {
//       int temp;
//       temp = ptr1;
//       ptr1 = ptr2;
//       ptr2 = temp;
//     }
//
//     void swap4(int** ptr1, int** ptr2)
//      {
//        int *temp;
//        temp = *ptr1;
//        *ptr1 = *ptr2;
//        *ptr2 = temp;
//      }
//
// int main()
// {
//   int *ptr1 = new int[5];
//   int *ptr2 = new int[5];
//
//   for(int i = 0; i < 5; i++) {
//     ptr1[i] = i;
//   }
//
//   for(int i = 0; i < 5; i++) {
//     ptr2[i] = 4 - i;
//   }
//
//   for(int i = 0; i <5; i++)
//   {
//     cout << ptr1[i] << " ";
//
//   }
//   cout << endl;
//
//    //swap0(ptr1, ptr2);
//    //swap1(*ptr1, *ptr2);
//    //swap2(ptr1, ptr2);
//   // swap3(*ptr1, *ptr2);
//     swap4(&ptr1, &ptr2);
//
//   for(int i = 0; i < 5; i++)
//   {
//     cout << ptr1[i] << " ";
//   }
//
//   return 0;
//
//
// }



int* foo(int x)
{
  int *y = new int[x*x];
  return y;
}

int main()
{
  int *z = foo(10);

  

  delete [] z;
  cout << *z << endl;

  return 0;
}



// int main() {
//   int x = 5;
//   int &y = x;
//   int *z = &y;
//
//   x = 20;
//   y = 15;
//   *z = 10;
//
//   cout << x << ", " << y << endl;
// }




// int** foo(int row, int col){
//     int** arr = new int*[row]; //Foo funtion is to create a 2-dimension array;
//     for(int i = 0; i < row; i++)
//         arr[i] = new int[col];
//     return arr;}
//
//
// int main(){
//     const int row = 10 ;
//     const int col = 12 ;
// 	int ** arr = foo(row,col);
// 	// use the array
//
//     //deallocate the array
//     for(int i = 0; i < row; i++)
//         delete arr[i];
//
//     delete arr;
// }



// int main() {
//   int a[] = {1,2,3,4,5};
//
//   int* ptr = (int*)(&a[0]+5);
//
//   cout << *(a+1) << ", " << *(ptr-1) << endl;
//
//   return 0;
// }
