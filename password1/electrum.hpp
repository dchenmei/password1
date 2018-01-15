/***********************************************
 *
 * Defines Electrum password, generated using 
 * 12 words as seeds. Similar method also used
 * in bitcoin wallet passwords.
 *
 * Author: swolewizard
 *
 ***********************************************/
#ifndef ELECTRUM_HPP
#define ELECTRUM_HPP
#include "password.hpp"
#define NUM_SEEDS 12

class Electrum: public Password
{
  public:
	/* With twelve seeds (words) from users, create a new sequence of words*/
	Electrum();

  private:
	/* Read 12 words from user as seeds */
	vector<string> read_seeds();
};

#endif
