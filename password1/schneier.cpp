#include "schneier.hpp"

Schneier::Schneier()
{
    vector<string> pieces = process_sentence(get_sentence());
    
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

string Schneier::get_sentence()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    
    return s;
}

vector<string> Schneier::process_sentence(string s)
{
	/* Also ignore period if there is any */
    /* to distinguish words, we use whitespaces as delimiter */

    istringstream is(s);
    vector<string> words;
    string word;

    while (is >> word) 
    {   
        words.push_back(word);
    }   

    return words;
}

int main()
{

	return 0;
}
