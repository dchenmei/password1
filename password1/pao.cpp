/***********************************************
 * Implements PAO password
 *
 * Author: swolewizard
 ***********************************************/

#include "pao.hpp"

PAO::PAO()
{
    /* Mnemonic Sentence:
     * [Adjective] [celebrity] [verb] a [adjective] [brand] [object] at [adjective] [famous place] on [month or holiday] 
     */

	/* Because the instructions are the same ("Enter ..."), it is a pefect opportunity to use a loop! */
	vector<string> words = { "adjective", "celebrity", "verb", "adjective", "brand", "object", "adjective", "famous place", "month or holiday" };
	string temp = "";
	string w;

	int i = 0;
	for (string word : words)
	{
		if (i == 3)
			temp += "a ";
		else if (i == 6)
			temp += "at ";
		else if (i == 8)
			temp += "on ";

		cout << "Enter " << word << ": ";
		if (cin >> w)
			temp += (w + " ");

		++i;
	}

	set_password(temp);
}
