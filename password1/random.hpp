/***********************************************
 *
 * Describes a randomly generated password, also
 * known as the psychopath method
 * 
 * Author: swolewizard
 *
 * ASCII Chars Used:
 * 0 - 9 (48 - 57)
 * a - z (97 - 122)
 * A - Z (65 - 90)
 * ! (33), # (35), $ (36), % (37), 
 * & (38), ? (63), @ (64)
 *
 ***********************************************/
#ifndef RANDOM_HPP
#define RANDOM_HPP
#include "password.hpp" /* parent class */

/* Delimiters and useful numbers */
#define NUM_CHARS 68
#define DELIM_ASSORT_SYMBOL 62
#define DELIM_A_Z 36
#define DELIM_a_z 10

class Random: public Password
{
  public:
	/* Given length l, randomly created a password using
     * char mentioned from above. Recommended lengths: 8, 16, 24 */
	Random(int l);

  private:
    /* Generates a random char from the set mentioned above */
	char rand_char();
};

#endif
