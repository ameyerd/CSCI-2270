#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  // File writing
  // creates instance of ofstream and opens the File
  ofstream oFile("filename.txt");
  // outputs the filename.txt through oFile
  oFile<< "Inserted this text into filename.txt" ;
  // close the file stream
  oFile.close();
}
