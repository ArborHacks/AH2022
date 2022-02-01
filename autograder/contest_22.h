#include <vector>
#include <string>
#include <list>

//Example RME:

// REQUIRES: startDate is between "01/01/2000" and "12/31/9999"
// EFFECTS:  Returns the next palindromic date given the starting date.
//           If the date given is a palindrome, it returns that date.
//           See instruction document for more information on palindromes.
std::string palindrome(std::string startDate);