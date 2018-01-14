/**************************************
 *
 *
 *************************************/

#ifndef SCHNEIER_HPP
#define SCHNEIER_HPP
#include "password.hpp"

class Schneier: public Password
{
  public:
	Schneier();

  private:

	/* Helper functions */
	string get_sentence();
	vector<string> process_sentence(string s);
};

#endif
