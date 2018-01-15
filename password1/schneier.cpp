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
    
	/* TODO: simplify this? */
    /* one or two words where the full word is used */
    srand(time(NULL));
    int full_words = (rand() % 2) + 1;
    srand(time(NULL) * 10);
    int index_1, index_2;
    index_1 = rand() % pieces.size();
    srand(time(NULL));

    index_2 = full_words == 2 ? rand() % pieces.size() : -1; 

	string temp = "";
    for (int i = 0; i < pieces.size(); ++i)
    {   
        if (i == index_1 || i == index_2)
            temp += pieces[i];
        else
            temp += pieces[i][0];
    }   

	set_password(temp);
}
