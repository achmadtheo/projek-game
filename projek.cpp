#include <iostream>
#include <cstdlib>
#include<ctime>
#include <string>
using namespace std;

const int MAX_TRIES=5;

int letterFill (char, string, string&);

int main ()
{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"filipina",
		"malaysia",
		"singapura",
		"kamboja",
		"myanmar",
		"thailand",
		"brunai",
		"vietnam",
		"laos",
		"indonesia"
	};

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];

	// Initialize the secret word with the * character.
	string unknown(word.length(),'*');

	// welcome the user
	cout << "\n\nselamat datang...tebak nama negara di ASEAN";
	cout << "\n\nkamu hanya bisa menampilkan satu huruf di setiap percobaan";
	cout << "\n\nkamu punya " << MAX_TRIES << " kesempatan untuk menebak katanya.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\ntebak satu huruf: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! tidak ada huruf tersebut!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "kamu menemukan huruf itu! " << endl;
		}
		// Tell user how many guesses has left.
		cout << "kamu mempunyai " << MAX_TRIES - num_of_wrong_guesses;
		cout << " kesempatan tersisa." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! kamu menemukannya!";
			break;
		}

	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nmaaf kamu kalah kamu tidak menemukannya" << endl;
		cout << "katanya adalah : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}
