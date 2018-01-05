/********************************************
 *
 * Implementation of password class
 *
 * Author: swolewizard
 *******************************************/

#include "password.hpp"

Password::Password(int l, int a): length(l)
{
	switch(a)
	{
		case 0:
			random(l);
			break;
		case 1:
			schneier(l);
			break;
		case 2:
			electrum(l);
			break;
		case 3:
			pao(l);
			break;
		default:
			cout << "Invalid algorithm." << endl;
			cout << "0: random" << endl;
			cout << "1: schneier" << endl;
			cout << "2: electrum" << endl;
			cout << "3: pao" << endl;
	}
}

/* A random seed will draw a number from [0, 74], then an algorithm figures out which char to get */
/* random helper function */
char Password::rand_char()
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
void Password::random(int l)
{
	/* Char set used (ASCII):
	 * 0 - 9 (48 - 57) 10      0 - 9
	 * a - z (97 - 122) 26     10 - 35
	 * A - Z (65 - 90) 26      36 - 61
	 * Assorted symbols (in an array)
	 * 33 (!), 35 (#), 36 ($), 37 (%), 38 (&), 63(?), 64(@) 7 62 - 68
	 */

	string p;
	while (l--)
	{
		sleep(1);
		p.push_back(rand_char());
	}
	
	password = p;
}

string Password::get_sentence()
{
	string s;
	getline(cin, s);
	cout << s << endl;
	
	return s;
}

/* Pushes each word and symbol of a setence into a vector */
vector<string> Password::process_sentence(string s)
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

void Password::schneier(int l)
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

	for (int i = 0; i < pieces.size(); ++i)
	{
		if (i == index_1 || i == index_2)
			password += pieces[i];
		else
			password += pieces[i][0];
	}
}

vector<string> Password::read_seeds()
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
void Password::electrum(int l)
{
	/* with spaces because that take longer to crack, length is king sometimes */
	vector<string> seeds = read_seeds();
	
	/* Randomize and mix up the words */
	srand(time(NULL));
	random_shuffle(seeds.begin(), seeds.end());
	
	for (string seed : seeds)
	{
		password += (seed + " ");
	}

	cout << password << endl;
}

string Password::get_word()
{
	string s;
	getline(cin, s);
	return s;
}

void Password::pao(int l)
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

	for (string word : words)
		password += (word + " ");

	cout << password << endl;
}

int main()
{
	Password *p = new Password(8, 3);


	return 0;
}

