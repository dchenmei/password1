/***********************************************
 *
 * Implements Electrum password
 *
 * Author: swolewizard
 *
 ***********************************************/

#include "electrum.hpp"

Electrum::Electrum()
{
    vector<string> seeds = read_seeds();
    
    /* Randomize and mix up the words */
    srand(time(NULL));
    random_shuffle(seeds.begin(), seeds.end());
    
	/* Create a new sequence of words */
	string temp = "";
    for (string seed : seeds)
    {   
        temp += (seed + " ");
    }   

	set_password(temp);
}

vector<string> Electrum::read_seeds() 
{
    cout << "Please enter twelve words (3 char min)." << endl;
    
    vector<string> words;
    string s;
    for (int i = 0; i < NUM_SEEDS; ++i)
    {   
        cin >> s;
        if (s.size() < 3)
        {
            cout << "Words of at least three characters please." << endl;
            return {};
        }
        
        words.push_back(s);
    }
    
    return words;
}

