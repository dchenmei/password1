#ifndef ELECTRUM_HPP
#define ELECTRUM_HPP
#include "password.hpp"

class Electrum: public Password
{
  public:
	Electrum();

  private:
	vector<string> read_seeds();
};

#endif
