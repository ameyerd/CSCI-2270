#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct wordItem {
  string word;
  int count;
};

void getStopWords (const char *ignoreWordFileName, string ignoreWords[])
{
  //open the file
  ifstream fp(ignoreWordFileName);

  if(fp.is_open()) {
    //cout << "File is open." << endl;
    //read the File
    string line;
    int i = 0;
    while(getline(fp,line))
    {
        ignoreWords[i] = line;

        i++;
    }

  }
  else {
    cout << "Failed to open " << ignoreWordFileName << endl;
  }

  // for(int j = 0; j < 50; j++) {
  //   cout << ignoreWords[j] << endl;
}

bool isStopWord(string word, string ignoreWords[]) {

  for (int i = 0; i < 50; i++) {

    if(word == ignoreWords[i]) {
      return true;
    }

  }

  return false;

}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {

  int sum = 0;
  for(int i = 0; i < length; i++) {
    sum += uniqueWords[i].count;

  }
  return sum;
}

void arraySort(wordItem uniqueWords[], int length) {

  //sort uniqueWords ARRAY by word counter
  // the most frequent words are sorted to the beginning
  string tempWord;
  int tempCount;

  for(int i = 0; i < length; i++) {
    for(int j = 0; j < length - 1; j++) {

      if(uniqueWords[j+1].count > uniqueWords[j].count) {

        tempWord = uniqueWords[j+1].word;
        uniqueWords[j+1].word = uniqueWords[j].word;
        uniqueWords[j].word = tempWord;

        tempCount = uniqueWords[j+1].count;
        uniqueWords[j+1].count = uniqueWords[j].count;
        uniqueWords[j].count = tempCount;

      }
    }
  }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords) {

  // probability-of-occurrence = ​(float) uniqueWords[ind].count / totalNumWords

  for(int i = N; i < 10; i++) {

    float probability_of_occurence = (float)uniqueWords[i].count / totalNumWords;

    cout << fixed << setprecision(4) << probability_of_occurence << " - " << uniqueWords[i].word << endl;

  }

}


int main(int argc, char const *argv[]) {

  //check if correct # of command line arguments is passed
  if (argc > 3) {
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    // exit program?
  }

  // call getStopWords function store them into an array
  string ignoreArr[50];
  getStopWords(argv[3],ignoreArr);

  //read word from tomsawyer.txt file
  // store all unique words that are NOT ignore words in an array of structs

  //create dynamic word item array of size 100
  wordItem word[100];

  // open the file
  ifstream fp(argv[2]);

  //counters
  int doubleCounter = 0;
  int uniqueWordCounter = 0;
  int totalWordCounter = 0;

  //check if open
  if(fp.is_open()) {

    //read file
    string line;
    int double_count = 0;
    while(getline(fp,line)) {

      // check if non-ignore
      if(isStopWord(line,ignoreArr) == false) {

        //search the array for the word
        for(int a = 0; a < word.length(); a++) {
          if(line == word[a].word) {
            //adjust word.count
            word[a].count++;

            totalWordCounter++;
          }
          else {
            // check whether array has enough space to make a new entry
            if(word[a].word == NULL) {
              //insert word into array
              word[a].word = line;

              word[a].count++;

              uniqueWordCounter++;
              totalWordCounter++;
            }
            else {
              // double the array
              int newCapacity = 2 * word.length();

              int *newArray = new int[newCapacity];

              for(int m = 0; m < word.length(); m++) {
                newArray[m] = word[m].word;
              }

              delete [] newArray;

              doubleCounter++;

              // then insert the word
              word.word = newArray;
              word.length() = newCapacity;

              if(word[a].word != NULL){
                word[a].word = line;

                uniqueWordCounter++;
                totalWordCounter++;
              }
            }
          }
        }

    }

  }

  cout << "Array doubled: " << doubleCounter << endl;
  cout << "#" << endl;
  cout << "Unique non-common words: " << uniqueWordCounter << endl;
  cout << "#" << endl;
  cout << "Total non-common words: " << totalWordCounter << endl;
  cout << "#" << endl;
  cout << "Probability of next 10 words from rank" << argv[1] << endl;
  cout << "---------------------------------------" << endl;

  arraySort(word, totalWordCounter);

  printNext10(word, argv[1], totalWordCounter);

  fp.close();

}
  else {
    cout << "File is not open.";
  }


  return 0;
}
