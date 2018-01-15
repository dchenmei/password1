/***********************************************
 *
 * Implementation for Random password class
 *
 * Author: swolewizard
 *
 ***********************************************/
#include "random.hpp"

Random::Random(int l)
{
    string p;
    while (l--)
    {
        sleep(1);
        p.push_back(rand_char());
    }

	/* why super class constructor no work? */
	set_password(p);
}

/* A random seed will draw a number from [0, 74], then an algorithm figures out which char to get */
/* random helper function */
char Random::rand_char()
{
	/* Algorithm breakdown: 
     *   Limitation: 69 possible characters, non-sequential in ASCII
     *	 
     *	 To achieve an equal probability for each character, algorithm randomly draw
     *   from 0 - 68. Then the result is pseudo-mapped (math) to corresponding char. 
     *
     * 	 Mapping (char, ascii -> 0 - 68):
     *   0 - 9 (48 - 75) -> 0 - 9
     *   a - z (97 - 122) -> 10 - 35
     *   A - Z (65 - 90) -> 36 - 61
     *   !, #, $, %, &, ?, @ -> 62 62 - 68
     *
     */

	/* Using sys time as seed, to pick a number from 0 to 68 */
	srand(time(NULL));
    int place = rand() % (NUM_CHARS + 1);

    char c; 
	/* Assorted symmbols: !, #, $ ... */
    if (place < (NUM_CHARS + 1) && place >= DELIM_ASSORT_SYMBOL)
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
	/* A - Z */
    else if (place >= DELIM_A_Z)
    {   
        c = (char) place - DELIM_A_Z + 'A';
    }
	/* a - z */
    else if (place >= DELIM_a_z)
    {   
        c = (char) place - DELIM_a_z + 'a';
    }
	/* 0 - 9 */
    else if (place < DELIM_a_z)
    {   
        c = (char) place + '0';
    }

    return c;
}

