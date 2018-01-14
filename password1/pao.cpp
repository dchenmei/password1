#include "pao.hpp"

PAO::PAO()
{
 vector<string> words;

    /* Adjective celebrity verb 'a' adjective brand object 'at' adjective famous place 'on' month or holiday */
    
    cout << "Enter an adjective:" << endl;
    words.push_back(get_word());

    cout << "Enter a celebrity:" << endl;
    words.push_back(get_word());

    cout << "Enter a verb:" << endl;
    words.push_back(get_word());

    words.push_back("a");
    
    cout << "Enter an adjective:" << endl;
    words.push_back(get_word());

    cout << "Enter a brand:" << endl;
    words.push_back(get_word());

    cout << "Enter an object:" << endl;
    words.push_back(get_word());

    words.push_back("at");

    cout << "Enter an adjective:" << endl;
    words.push_back(get_word());

    cout << "Enter a famous place:" << endl;
    words.push_back(get_word());

    words.push_back("on");

    cout << "Enter a month (in word)  or holiday:" << endl;
    words.push_back(get_word());

	string temp = "";
    for (string word : words)
        temp += (word + " ");

	set_password(temp);
}

string PAO::get_word()
{
	string s;
    getline(cin, s);
    return s;
}
