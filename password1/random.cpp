/*****************************************
 *
 * Implementation for random password
 *
 *****************************************/
#include "random.hpp"

/* A random seed will draw a number from [0, 74], then an algorithm figures out which char to get */
/* random helper function */
char Random::rand_char()
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
Random::Random(int l)
{
	/* Char set used (ASCII):
 *      * 0 - 9 (48 - 57) 10      0 - 9
 *           * a - z (97 - 122) 26     10 - 35
 *                * A - Z (65 - 90) 26      36 - 61
 *                     * Assorted symbols (in an array)
 *                          * 33 (!), 35 (#), 36 ($), 37 (%), 38 (&), 63(?), 64(@) 7 62 - 68
 *                               */

    string p;
    while (l--)
    {
        sleep(1);
        p.push_back(rand_char());
    }

	/* why super class constructor no work? */
	set_password(p);
}
