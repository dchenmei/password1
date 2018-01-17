/**********************************
 *
 * Password1 
 *
 * Author: swolewizard
 *
 ***********************************/

#include "random.hpp"
#include "schneier.hpp"
#include "electrum.hpp"
#include "pao.hpp"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/************************************
 *
 * Flags and Options 
 *
 * ./password1 o l
 *
 * o - password method: random(1), schneier(2), electrum(3), pao(4) 
 * l - password length, only required for random method
 ************************************/

void print_usage_insturction()
{
	cout << "Usage:" << endl;
	cout << "./password1 o l" << endl;
	cout << "o - password method: random(1), schneier(2), electrum(3), pao(4)" << endl;
	cout << "l - password length, only required for random method" << endl;
	cout << "Note: Random method takes approx. 1s/char, recommend password length of 8 or 16" << endl;
}
	
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		print_usage_insturction();
		return -1;
	}
	
	int algorithm = atoi(argv[1]);

	/* Random */
	if (algorithm == 1 && argc == 3)
	{
		/* Need to verify that the input is length */
		Random *r = new Random(atoi(argv[2]));
		cout << r->get_password() << endl;
	}
	/* Schneier */
	else if (algorithm == 2)
	{
		Schneier *s = new Schneier();
		cout << s->get_password() << endl;
	}

	/* Electrum */
	else if (algorithm == 3)
	{
		Electrum *e = new Electrum();
		cout << e->get_password() << endl;
	}

	/* PAO */
	else if (algorithm == 4)
	{
		PAO *p = new PAO();
		cout << p->get_password() << endl;
	}

	/* Invalid Input */
	else
	{
		print_usage_insturction();
	}

	return 0;
}
