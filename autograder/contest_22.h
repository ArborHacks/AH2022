#include <vector>
#include <string>
#include <list>

using namespace std;

//Contestants: replace the "throw 0;" with your code!

// Question 1
// REQUIRES: name is formatted and capitalized correctly if it is Jeff Bezos or one of his aliases given in spec
// EFFECTS: Returns true if name is "Jeff Bezos" or an alias. Outputs "Found Him!" if it is actually "Jeff Bezos". Outputs the name of the alias if it one of the three given. Outputs "Not Jeff" if neither Jeff Bezos nor an alias.
bool isBezos(string name);

// Question 2
// REQUIRES: prices contains a single index that has the value 0
// EFFECTS: returns a new array that replaces the 0 index with newPrice
vector<int> newRocketPrices(std::vector<int> prices, int newPrice);

// Question 3
// REQUIRES: Input is formatted with 16 cities, each with a string of the city followed by a char of its building type (h, w, d, r)
// EFFECTS: Output modeled after spec: <Building Type>: followed by a ranking of the 4 cities that correspond to that building type. The order of building are Headquarters, Warehouse, Data Center, then Research Center
void outputCities(istream& in, ostream& out);

// Question 4
// REQUIRES: temperatures 2D vector is not empty
// MODIFIES: hasFever and isMinion flags
// EFFECTS: temperatures is read with a bandpass of 90-110 degrees, and the hasFever and isMinion flags are set according to the average temperature after the bandpass filter. A fever is an average above 100 degrees, and the lowest human temperature is 96 degrees

void isAlien(vector<vector<int>> temperatures, bool &hasFever, bool &isMinion);


//Question 5
// REQUIRES: stocks vector is at least size 1
// EFFECTS: returns the length of the longest, continuous, and decreasing subsequence of stocks vector
int worstStocks(vector<int> stocks);


//Question 6

// Package ADT interface
struct Package{
  int length;
  int width;
  int height;
}

// REQUIRES: all packages have lenght, width, height > 0
// MODIFIES: vector<Package> packages
// EFFECTS: sorts packages in ascedning order (smallest first)
void sortPackages(std::vector<Package> &packages);



// Question 7 --> TODO


// Question 8
// REQUIRES: coins is not empty
// EFFECTS: any two consecutive coins in the vector cannot both be mined. You must return the maximum value that can be mined under the above constraint.
int maxJeffCoin(vector<int> coins);
