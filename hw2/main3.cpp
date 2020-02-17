#include <iostream>
#include <fstream>
#include <string>
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
    sum = sum + uniqueWords[i].count;

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

  for(int i = N; i < N + 10; i++) {

    float probability_of_occurence = (float)uniqueWords[i].count / totalNumWords;

    cout << fixed << setprecision(4) << probability_of_occurence << " - " << uniqueWords[i].word << endl;

  }

}

int main(int argc, char const *argv[]) {

  // check if correct # of command line arguments is passed
  if (argc > 4) {
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;

    return -1;
  }

  int N = stoi(argv[1]);

  string ignoreArr[50];
  getStopWords(argv[3], ignoreArr);

  ifstream fp;
  fp.open(argv[2]);


  //dynamic word item array of size 100
  int capacity = 100;
  wordItem *word;
  word = new wordItem[capacity];

  //counters
  int totalNum = 0;
  int totalDouble = 0;

  if(fp.is_open()) {

    string line;
    while(fp >> line) {

      if(isStopWord(line, ignoreArr) == false) {

        if(totalNum == 0) {
          word[0].word = line;
          word[0].count++;
          totalNum++;
        }
        else{

          for(int i = 0; i < totalNum; i++) {
            if(line == word[i].word) {
              word[i].count++;
              break;
            }
            if(line != word[i].word && i == totalNum -1) {
              if(totalNum == capacity) {
                // double array
                int newCapacity = 2 * capacity;

                //dynamically allocate an array of size newCapacity
                wordItem *newArray = new wordItem[newCapacity];

                //copy all data from oldArray to newArray
                for(int j = 0; j < capacity; j++) {
                  newArray[j] = word[j];
                }

                //free memory
                delete [] word;

                word = newArray;
                capacity = newCapacity;

                // word[totalNum].word = line;
                // word[totalNum].count++;
                // totalNum++;
                 totalDouble++;
              }

                word[totalNum].word = line;
                word[totalNum].count++;
                totalNum++;
                break;

            }

          }

        }

      }

    }


    cout << "Array doubled: " << totalDouble << endl;
    cout << "#" << endl;
    cout << "Unique non-common words: " << totalNum << endl;
    cout << "#" << endl;
    cout << "Total non-common words: " << getTotalNumberNonStopWords(word, totalNum) << endl;
    cout << "#" << endl;
    cout << "Probability of next 10 words from rank " << argv[1] << endl;
    cout << "---------------------------------------" << endl;

    arraySort(word, totalNum);

    printNext10(word, N , getTotalNumberNonStopWords(word, totalNum));

    fp.close();
  }


  return 0;
}
