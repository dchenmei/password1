/********************************************
 *
 * Defines a password
 *
 * Author: swolewizard
 *******************************************/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Password
{
  public:
	Password(int l, int a);

  private:
    
	/* Random password algorithm */
	void random(int l); // 0
	void schneier(int l); // 1
	void electrum(int l); // 2 
	void pao(int l); // 3

	/* member variables */
    string password;
	int length;
};
