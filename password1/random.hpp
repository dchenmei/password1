/************************************
 *
 * Describes a random password
 *
 ***********************************/
#include "password.hpp"

class Random: public Password
{
  public:
	Random(int l);

  private:
	char rand_char();
};
