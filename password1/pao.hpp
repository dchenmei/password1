#include "password.hpp"

class PAO: public Password
{
  public:
	PAO();

  private:
	string get_word();
};
