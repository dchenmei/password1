#ifndef PAO_HPP
#define PAO_HPP
#include "password.hpp"

class PAO: public Password
{
  public:
	PAO();

  private:
	string get_word();
};

#endif
