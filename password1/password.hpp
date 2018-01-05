/********************************************
 *
 * Defines a password
 *
 * Author: swolewizard
 *******************************************/

#include <iostream>
#include <string>
#include <cstdlib> /* srand() */
#include <ctime> /* time() */
#include <unistd.h> /* sleep */
#include <sstream> /* istringstream */
#include <vector> /* vector */
#include <algorithm> /* random_shuffle */

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;
using std::vector;
using std::random_shuffle;

class Password
{
  public:
	Password(int l, int a);

  private:
    
	/* Random password algorithm */
	char rand_char();
	void random(int l); // 0
	void schneier(int l); // 1
	void electrum(int l); // 2 
	void pao(int l); // 3

	string get_sentence();
	vector<string> process_sentence(string s);
	vector<string> read_seeds();

	string get_word();

	/* member variables */
    string password;
	int length;
};
