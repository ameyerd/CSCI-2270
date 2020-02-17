#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Park {
  string parkname;
  string state;
  int area;
};


// length: number of item currently stored in the array
void addPark (Park parks[], string parkname, string state, int area, int length){
  Park park;

  park.parkname = parkname;
  park.state = state;
  park.area = area;

  parks[length] = park;

}


// length: number of items in the array
void printList(const Park parks[], int length){

  for(int i = 0; i < length; i++) {

    cout << parks[i].parkname << " [" << parks[i].state << "] area: " << parks[i].area << endl;
  }

}

int main(int argc, char* const argv[]) {
  Park parks[100];
  int counter = 0;

  //open the File
  ifstream fp(argv[1]);

  if(fp.is_open()) {
    //cout << "File is open." << endl;
  }
  else {
    cout << "Failed to open the file." << endl;
  }

  //read the File
  string line;
  while(getline(fp,line)) {
    //parkname -> string
    // state -> string
    // area -> int
    string parkname;
    string state;
    string area1;

    stringstream ss(line);

    getline(ss, parkname, ',');
    getline(ss, state, ',');
    getline(ss, area1);

    addPark(parks, parkname, state, stoi(area1), counter);

    counter++;

  }

  printList(parks, counter);

  ofstream oFile(argv[2]);

  for(int i =0; i < counter; i++) {
    if(parks[i].area >= stoi(argv[3])) {
      oFile << parks[i].parkname << "," << parks[i].state << "," << parks[i].area << endl;
    }
  }


  oFile.close();


  fp.close();
  return 0;

}
