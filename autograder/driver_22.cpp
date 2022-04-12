#include <iostream>
#include <list>
#include <fstream>
#include "contest_22.h"
#include <sstream>
#include <string.h>

using namespace std;

// How to set up test:
// 1. set up points pair (what gets returned)
// 2. set up the vectors for input (test) and expected output (keys)
// 3. try statement that iterates over the vectors and gives 1 point for every passed test case
// 4. return pair of points (points earned, points available)

static pair<uint32_t, uint32_t> testIsBezos();
static pair<uint32_t, uint32_t> testRocketPrices();
static pair<uint32_t, uint32_t> testOutputCities();
static pair<uint32_t, uint32_t> testIsAlien();
static pair<uint32_t, uint32_t> testWorstStocks();
static pair<uint32_t, uint32_t> testSortPackages();
// static pair<uint32_t, uint32_t> QUESTION 7
static pair<uint32_t, uint32_t> testMaxJeffCoin();

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
  vector<bool> keys = {false,
  false,
  false,
  true,
  true,
  true};
  
  try {
    for (int i = 0; i < 6; i++){
      if (isBezos(tests[i]) == keys[i]){ 
        points.first++;
      }
    }
  } catch(...) {
    points.first = 0;
  }

  points.second = 6;
  cout << "Testing isBezos: " << points.first << "/" << points.second << endl;
  return points;
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
  return points;

}

// QUESTION 3
// TODO: buffers & how to check with cout -- Scotty
static pair<uint32_t, uint32_t> testOutputCities(){
  pair<uint32_t, uint32_t> points;
  points.first = 0;
  points.second = 4;

  std::ifstream inStream("in.txt");
  std::streambuf *cinbuf = std::cin.rdbuf(inStream.rdbuf()); //save old buf + redirect


  std::stringstream redirectStream;
  std::streambuf *coutbuf = std::cout.rdbuf( redirectStream.rdbuf() ); //save old buf + redirect

  // normal ag stuff
  vector<string> test_filenames = {
  "in1.txt",
  "in2.txt",
  "in3.txt",
  "in4.txt"
  };
  vector<string> key_filenames = {
  "out1.txt",
  "out2.txt",
  "out3.txt",
  "out4.txt"
  };

  try{
    for(int i = 0; i < 4; ++i){
      std::ifstream inStream(test_filenames[i]);
      std::cin.rdbuf(inStream.rdbuf());
      outputCities();

      string output_line;
      string key_line;
      bool studentCorrect = true;
      std::ifstream key_file(key_filenames[i]);

      for(int j = 0; redirectStream >> output_line; ++j){
        if(key_file >> key_line){
          if(output_line.compare(key_line) != 0){
            studentCorrect = false;
            break;
          }
        }
      }
      if(studentCorrect) points.first++;

    }
  } catch(...) {
    points.first = 0;
  }

  
  std::cin.rdbuf(cinbuf);   //reset to standard input again
  std::cout.rdbuf(coutbuf); //reset to standard output again

  cout << "Testing outputCities: " << points.first << "/" << points.second << endl;
  return points;
}

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
  points.second = 4;
  cout << "Testing isAlien: " << points.first << "/" << points.second << endl;
  return points;
}

// QUESTION 5 
static pair<uint32_t, uint32_t> testWorstStocks() {
  pair<uint32_t, uint32_t> points;
  points.first = 0;

  vector<vector<int>> tests = {
    {18, 14, 12, 12, 11, 10, 0},
    {1, 3, 2, 0, 18, 13, 4, 1, 10, 9, 8},
    {1, 0, 2, 3, 4, 5, 2, 5, 2, 1},
    {1, 0, 2, 3, 4, 5, 2, 5, 2},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 0}
  };

  vector<int> keys = {
    4, 4, 3, 2, 1, 2
  };

  try {
    for (int i = 0; i < 6; i++){
      if (worstStocks(tests[i]) == keys[i]){
        points.first++;
      }
    }
  } catch(...) {
    points.first = 0;
  }

    points.second = 6;

   cout << "Testing worstStocks: " << points.first << "/" << points.second << endl;
  return points;
  
}

// QUESTION 6
// struct Package {
//     int length;
//     int width;
//     int height;
// };

static pair<uint32_t, uint32_t> testSortPackages(){
  pair<uint32_t, uint32_t> points;
  points.first = 0;

 vector<vector<Package>> tests = {
  {Package{5, 5, 5}, Package{1, 2, 3}, Package{3, 2, 1},     Package{6, 1, 1}, Package{1, 7, 1}},
  
{Package{5, 5, 5}, Package{1, 1, 1}, Package{3, 3, 3},     Package{2, 2, 2}, Package{4, 4, 4}},

{Package{9, 10, 11}, Package{10, 1, 1}, Package{7, 4, 2},     Package{1, 10, 1}, Package{1, 1, 1}}
  };

  
  vector<vector<Package>> keys = {
  {Package{1, 2, 3}, Package{3, 2, 1}, Package{6, 1, 1}, Package{1, 7, 1},Package{5, 5, 5}},
  
  {Package{1, 1, 1}, Package{2, 2, 2}, Package{3, 3, 3},     Package{4, 4, 4}, Package{5, 5, 5}},

  {Package{1, 1, 1}, Package{1, 10, 1}, Package{10, 1, 1},       Package{7, 4, 2}, Package{9, 10, 11}}
  };

  try {
    for (int i = 0; i < 3; i++){
      bool correctTest = true; 
      vector<Package> studentAnswer = tests[i];
      sortPackages(studentAnswer);
      vector<Package> correctAnswer = keys[i];
      for(int j = 0; j < 5; j++){
        Package correctPackage = correctAnswer[j];
        if (studentAnswer[i].length != correctPackage.length ||  
            studentAnswer[i].width != correctPackage.width || 
            studentAnswer[i].height != correctPackage.height)
              correctTest = false;
      }
      if(correctTest) points.first++;
    }
  } catch(...) {
    points.first = 0;
  }

  points.second = 3;

   cout << "Testing sortPackages: " << points.first << "/" << points.second << endl;
  return points;

  
}

// QUESTION 7

// QUESTION 8
static pair<uint32_t, uint32_t> testMaxJeffCoin(){
  pair<uint32_t, uint32_t> points;
  points.first = 0;

  vector<vector<int>> tests = {
    {4, 6, 2, 3, 2, 1},
    {1, 3, 2, 0, 18, 13, 4, 1, 10, 9, 8},
    {1, 0, 2, 3, 4, 5, 2, 5, 2, 1},
    {1, 0, 2, 3, 4, 5, 2, 5, 2},
    {0, 0, 0, 0, 0, 0, 0},
    {1, 0}
  };

  vector<int> keys = {
    10, 4, 3, 2, 1, 2
  };

  try {
    for (int i = 0; i < 6; i++){
      if (maxJeffCoin(tests[i]) == keys[i]){
        points.first++;
      }
    }
  } catch(...) {
    points.first = 0;
  }

    points.second = 6;

   cout << "Testing maxJeffCoin: " << points.first << "/" << points.second << endl;
  return points;
}

int main() {
	cout << "--- Booting up UMich ArborHacks Autograder ---" << endl;

  // Initialize point counters
	uint32_t totalPoints = 0;
  uint32_t totalTests = 0;

   pair<uint32_t, uint32_t> test1 = testIsBezos();
   totalPoints += test1.first;
	 totalTests += test1.second;
   pair<uint32_t, uint32_t> test2 = testRocketPrices();
   totalPoints += test2.first;
	 totalTests += test2.second;
   pair<uint32_t, uint32_t> test3 = testOutputCities();
   totalPoints += test3.first;
	 totalTests += test3.second;
   pair<uint32_t, uint32_t> test4 = testIsAlien();
   totalPoints += test4.first;
	 totalTests += test4.second;
   pair<uint32_t, uint32_t> test5 = testWorstStocks();
   totalPoints += test5.first;
	 totalTests += test5.second;
   pair<uint32_t, uint32_t> test6 = testSortPackages();
   totalPoints += test6.first;
	 totalTests += test6.second;
   pair<uint32_t, uint32_t> test7 = testMaxJeffCoin();
   totalPoints += test7.first;
	 totalTests += test7.second;
	

    // Print final score
	cout << "Final Score: " << totalPoints << "/" << totalTests << endl;
	return 0;
}