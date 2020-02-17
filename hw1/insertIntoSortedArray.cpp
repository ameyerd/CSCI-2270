#include <iostream>
#include <fstream>
using namespace std;


int insertIntoSortedArray(int myArray[], int numEntries, int newValue){

  int temp;

  // insert into myArray
  myArray[numEntries] = newValue;

  // sort array
  for(int i = 0; i < numEntries; i++) {

    for(int j = 0; j < numEntries - i; j++) {

      if(myArray[j] > myArray[j+1]) {

        temp = myArray[j];
        myArray[j] = myArray[j+1];
        myArray[j+1] = temp;

      }
    }
  }

  numEntries++;

  //cout << "nument:" << numEntries << endl;
  return numEntries;
}



int main(int argc, char const *argv[]) {

  int arr[100];
  int counter = 0;

  //open the file
  // ifstream fp (argv[1]);
  ifstream fp (argv[1]);

  if(fp.is_open()) {
    //cout << "File is open." << endl;
  }
  else {
    cout << "Failed to open the file." << endl;
  }

  //read the file
  string line;
  while(getline(fp,line)) {
    //cout << line << endl;
    int num = stoi(line);

    //cout << num << endl;

    //store integers into sorted array by passing them to the insertIntoSortedArray function
    insertIntoSortedArray(arr, counter, num);


    counter++;
    //cout << "count" << counter << endl;

    for(int i = 0; i < counter; i++){
      // check if its the last element
      // size -1
      if(i == counter -1){
        cout << arr[i];
      }
      else {
        cout << arr[i] << ",";
      }
    }
    cout << endl;
  }


  fp.close();
  return 0;

}
