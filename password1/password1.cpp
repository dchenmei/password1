/**********************************
 *
 * Password1 
 *
 * Author: swolewizard
 *
 ***********************************/

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

/************************************
 *
 * Flags and Options 
 *
 * ./password1 l o
 *
 * l: length of password 1 (8), 2 (16), 3 (32)
 * o: algorithm to choose from
 *
 ************************************/
	
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		cout << "Insufficient number of arguments:" << endl;
		cout << "./password l o where l is length and o algorithm" << endl;
		return -1;
	}

	int length = atoi(argv[1]);
	int algorithm = atoi(argv[2]);

	cout << length << endl << algorithm << endl;

	/* cout << generate_password(length, algorithm); */
	

	return 0;
}
