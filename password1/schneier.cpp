/***********************************************
 *
 * Schneier password implementation
 *
 * Author: swolewizard
 *
 ***********************************************/

#include "schneier.hpp"

Schneier::Schneier()
{
	/* I/O: No need to read line, simply read by cin which gives each word */
	vector<string> pieces;

	cout << "Please enter a sentence, press ENTER then CTRL + D when done." << endl;
	string w;
	while (cin >> w)
	{
		pieces.push_back(w);
	}
    
	/* For each word, there is a 1/3 the full word might be used */
    srand(time(NULL));
	
	string temp = "";
    for (int i = 0; i < pieces.size(); ++i)
    {   
        if ((rand() % 3) == 0)
            temp += pieces[i];
        else
            temp += pieces[i][0];
    }   

	set_password(temp);
}
