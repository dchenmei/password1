/************************************
 *
 * Describes a random password
 *
 ***********************************/
#ifndef RANDOM_HPP
#define RANDOM_HPP
#include "password.hpp"

class Random: public Password
{
  public:
	Random(int l);

  private:
	char rand_char();
};

#endif
