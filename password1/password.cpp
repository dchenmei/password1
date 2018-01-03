/********************************************
 *
 * Implementation of password class
 *
 * Author: swolewizard
 *******************************************/

#include "password.hpp"

Password::Password(int l, int a): length(l)
{
	switch(a)
	{
		case 0:
			random(l);
			break;
		case 1:
			schneier(l);
			break;
		case 2:
			electrum(l);
			break;
		case 3:
			pao(l);
			break;
		default:
			cout << "Invalid algorithm." << endl;
			cout << "0: random" << endl;
			cout << "1: schneier" << endl;
			cout << "2: electrum" << endl;
			cout << "3: pao" << endl;
	}
}

void Password::random(int l)
{
}

void Password::schneier(int l)
{
}

void Password::electrum(int l)
{
}

void Password::pao(int l)
{
}

int main()
{
	return 0;
}
