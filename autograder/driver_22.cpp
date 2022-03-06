#include <iostream>
#include <list>
#include <fstream>
#include "contest_22.h"
#include <sstream>

using namespace std;

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


static pair<uint32_t, uint32_t> testIsBezos();
static pair<uint32_t, uint32_t> testRocketPrices();
static pair<uint32_t, uint32_t> testOutputCities();
static pair<uint32_t, uint32_t> testIsAlien();
static pair<uint32_t, uint32_t> testWorstStocks();
static pair<uint32_t, uint32_t> testSortPackages();
// static pair<uint32_t, uint32_t> QUESTION 7
static pair<uint32_t, uint32_t> testMaxJeffCoin();


//Example of how to set up test:
//1. set up points pair (what gets returned)
//2. set up the vectors for input (test) and expected output (keys)
//3. try statement that iterates over the vectors and gives 1 point for every passed test case
//4. return pair of points (points earned, points available)

// TODO: fix try statement
// QUESTION 1
static pair<uint32_t, uint32_t> testIsBezos() {
  pair<uint32_t, uint32_t> points;
  points.first = 0;

  vector<string> tests = {"Beff Bezos",
"Zuckerberg",
"Jeff Jezos",
"Beff Jezos",
"Bezz Jefos",
"Jeff Bezos"};
  vector<string> keys = {"Not Jeff",
"Not Jeff",
"Not Jeff",
"Beff Jezos",
"Bezz Jefos",
"Found Him!"};
  
  try {
    for (int i = 0; i < 12; i++){
      if (vectors(tests[i]) == keys[i]){ // TODO vectors() calls the contestant function, also we need to check for cout somehow
        points.first++;
      }
    }
  } catch(...) {
    points.first = 0;
  }

  points.second = 6;
  cout << "Testing IsBezos: " << points.first << "/" << points.second << endl;
}

// QUESTION 2 
static pair<uint32_t, uint32_t> testRocketPrices() {
  pair<uint32_t, uint32_t> points;
  points.first = 0;

  vector<vector<int>> tests = {
    {48, 12, 9, 0, 50, 0, 40, 1, 0, 9},
    {0},
    {2, 3, 4, 18, 1, 0},
    {4, 5, 1, 483, 3181, 123, 0, 13, 34},
    {0, 1, 2, 3}
  };

  vector<int> prices = {3, 8, 16, 99, 84};

  vector<vector<int>> keys = {

    {48, 12, 9, 0, 50, 0, 40, 1, 3, 9},
    {8},
    {2, 3, 4, 18, 1, 16},
    {4, 5, 1, 483, 3181, 123, 99, 13, 34},
    {84, 1, 2, 3}

  };

  try {
    for (int i = 0; i < 5; i++){
      if (newRocketPrices(tests[i], prices[i]) == keys[i]){
        points.first++;
      }
    }
  } catch(...) {
    points.first = 0;
  }

    points.second = 5;

   cout << "Testing newRocketPrices: " << points.first << "/" << points.second << endl;
  
}

// QUESTION 3
// TODO: buffers & how to check with cout

// QUESTION 4
static pair<uint32_t, uint32_t> testIsAlien(){
  pair<uint32_t, uint32_t> points;
  points.first = 0;
  points.second = 4;

  vector<vector<vector<int>>> tests = {
    { // Test 1
    {0, 0, 0},
    {0, 95, 0},
    {0, 96, 0},
    {0, 97, 0},
    {0, 0, 0}
    },
    { // Test 2
    {0, 111, 0},
    {120, 120, 120},
    {0, 0, 0},
    {120, 120, 120},
    {0, 89, 0}
    },
    { // Test 3
    {100, 101, 102},
    {100, 101, 102},
    {100, 101, 102},
    {100, 101, 102},
    {100, 101, 102}
    },
    { // Test 4
    {89, 90, 91},
    {92, 93, 94},
    {95, 96, 97},
    {98, 99, 100},
    {101, 102, 103},
    {104, 105, 106},
    {107, 108, 109},
    {110, 111, 112}
    },
  };

  // vector<double> keys = {96, 0, 101, 100};

  vector<bool> feverKeys = {false, false, true, true};
  vector<bool> alienKeys = {false, true, false, false};

  try {
    for (int i = 0; i < 4; i++){
      bool feverFlag = false;
      bool alienFlag = false;
      isAlien(tests[i], feverFlag, alienFlag);
      if(feverFlag == feverKeys[i] && alienFlag == alienKeys[i]){
        points.first+=1;
      }
    }
  } catch(...) {
    points.first = 0;
  }
  points.
  cout << "Testing Temperature Averaging: " << points.first << "/" << points.second << endl;
  return points;
}