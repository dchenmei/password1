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

/* A random seed will draw a number from [0, 74], then an algorithm figures out which char to get */
/* random helper function */
char Password::rand_char()
{
	/* Random number [0, 74] */
	srand(time(NULL));
	int place = rand() % 75;
	char c;

	if (place < 74 && place >= 62)
	{
		switch(place)
		{
			case 62:
				c = '!';
				break;
			case 63:
				c = '#';
				break;
			case 64:
				c = '$';
				break;
			case 65:
				c = '%';
				break;
			case 66:
				c = '&';
				break;
			case 67:
				c = '?';
				break;
			case 68:
				c = '@';
				break;
		}
	}
	else if (place >= 36)
	{
		c = (char) place - 36 + 'A';
	}
	else if (place >= 10)
	{
		c = (char) place - 10 + 'a';
	}
	else if (place < 10)
	{
		c = (char) place + '0';
	}

	return c;
}

/* Also known as psychopath method */
void Password::random(int l)
{
	/* Char set used (ASCII):
	 * 0 - 9 (48 - 57) 10      0 - 9
	 * a - z (97 - 122) 26     10 - 35
	 * A - Z (65 - 90) 26      36 - 61
	 * Assorted symbols (in an array)
	 * 33 (!), 35 (#), 36 ($), 37 (%), 38 (&), 63(?), 64(@) 7 62 - 68
	 */

	string p;
	while (l--)
	{
		sleep(.5);
		p.push_back(rand_char());
	}
	
	cout << p << endl;
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
	Password *p = new Password(8, 0);

	return 0;
}
