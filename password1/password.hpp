/********************************************
 *
 * Defines a password
 *
 * Author: swolewizard
 *******************************************/

#ifndef PASSWORD_HPP
#define PASSWORD_HPP

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
	Password();
    Password(string s);
	void set_password(string s);
	string get_password();

  private:
    string password;
	int length;
};

#endif
