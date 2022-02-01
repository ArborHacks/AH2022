#include <iostream>
#include <list>
#include <fstream>
#include "contest_19.h"
#include <sstream>

using namespace std;

/* Example function prototypes */
  //change names to new question type
static pair<uint32_t, uint32_t> testHangman();
static pair<uint32_t, uint32_t> testVigenere();

//Example of how to set up test:
//1. set up points pair (what gets returned)
//2. set up the vectors for input (test) and expected output (keys)
//3. try statement that iterates over the vectors and gives 1 point for every passed test case
//4. return pair of points (points earned, points available)
static pair<uint32_t, uint32_t> testVectors() {
  pair<uint32_t, uint32_t> points;

  vector<string> tests = { "","CCCCCCC", "TATCCC", "AAACCC", "TAACCC", "AAATGGG", "TAATGGG", "CAATGGG", "GAATGGG", "GAGACCC", "GACACCC", "CCCTATATATTANAATTTGAGACCC"};
  vector<string> keys = {"GACTAC", "GACTACCCCCCCC", "TATGACTACCCC", "AAAGACTACCCC", "TAAGACTACCCC", "AAATGACTACGGG", "TAATGACTACGGG", "CAATGACTACGGG", "GAATGACTACGGG", "GAGAGACTACCCC", "GACAGACTACCCC", "GACTACCCCTATATATTANAATTTGAGACCC"};
  
  try {
    for (int i = 0; i < 12; i++){
      if (vectors(tests[i]) == keys[i]){
        points.first++;
      }
    }
  } catch(...) {
    points.first = 0;
  }

  points.second = 12;
  cout << "Testing Vectors: " << points.first << "/" << points.second << endl;
}