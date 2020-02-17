#include<iostream>
#include<string>
using namespace std;

/*
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
	//Implement this function

  // go through the elements of the original array
  for(int i = 0; i < size; i++)
  {
    // check if the element is even
    if(arr[i] % 2 == 0)
    {
      // put into even array

      // check if you need to double size
      if(i == even_size)
      {
        //double the array
        int *b_arr = new int[even_size];
        int b_size = 0;

        b_size = even_size *2;
        // copy the array
        for(int j = 0; j < even_size; j++)
        {
          b_arr[j] = even_arr[j];
        }

        //delete old array
        delete [] b_arr;

        //insert into even array
        even_arr[i] = b_arr[i] ;
        even_size++;

      }
      else
      {
        even_arr[i] = arr[i];
        even_size++;
      }




    }
    else
    {
      //put into odd array
      if(i == odd_size)
      {
        //double the array
        int *b_arr = new int[odd_size];
        int b_size = 0;

        b_size = odd_size *2;
        // copy the array
        for(int j = 0; j < odd_size; j++)
        {
          b_arr[j] = odd_arr[j];
        }

        //delete old array
        delete [] b_arr;

        //insert into even array
        odd_arr[i] = b_arr[i] ;
        odd_size++;

      }
      else
      {
        odd_arr[i] = arr[i];
        odd_size++;
      }


    }
  }
}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;

	// Call your function with new arrays:
  int *even_arr = new int[size];
  int *odd_arr = new int[size];

	split(arr, even_arr, odd_arr, size, size, size);

	// Output
  cout << "even array: ";
  for(int i = 0; i <size; i++)
  {
    cout << even_arr[i];
    if(i < size-1)
      cout << ", ";
  }
  cout << endl;

  cout << "odd array: ";
  for(int i = 0; i <size; i++)
  {
    cout << odd_arr[i];
    if(i < size-1)
      cout << ", ";
  }
  cout << endl;

	// Clean up (delete)

    return 0;
}
