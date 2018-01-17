/********************************************
 *
 * Implementation of Password class
 *
 * Author: swolewizard
 *******************************************/

#include "password.hpp"

Password::Password() 
{
}

Password::Password(string s): password(s), length(s.size())
{
}

void Password::set_password(string s)
{
	password = s;
}

string Password::get_password()
{
	return password;
}

