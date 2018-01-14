#include "electrum.hpp"

Electrum::Electrum()
{
/* with spaces because that take longer to crack, length is king sometimes */
    vector<string> seeds = read_seeds();
    
    /* Randomize and mix up the words */
    srand(time(NULL));
    random_shuffle(seeds.begin(), seeds.end());
    
	string temp = "";
    for (string seed : seeds)
    {   
        temp += (seed + " ");
    }   

	set_password(temp);
}

vector<string> Electrum::read_seeds() 
{
	/* No repeats allowed & no words less than three characters */
    /* TODO: NO MAGIC NUMBERS */
    
    cout << "Please enter twelve words (3 char min)." << endl;
    
    vector<string> words;
    string s;
    for (int i = 0; i < 12; ++i)
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


int main()
{
	return 0;
}
