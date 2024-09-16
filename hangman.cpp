#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

void display_hangman();

class words{
	int i;
	public:
		void set_i(int value){i=value;}
		string generate_random_word()
		{
			srand(time(0));
			int word_position = 1 + (rand() % 100);
			ifstream wordfile;
			wordfile.open("words.txt");
			if(!wordfile.is_open())
			{
				cout<<"Sorry, unable to generate a word."<<endl;
				exit(1);
			}
			string word;
		    int current_line = 0;
		    while (getline(wordfile, word)) 
			{
		    	current_line++;
		        if (current_line == word_position)
		        break;
		    }
		    wordfile.close();
		    return word;
		}
};

int main()
{
	words w;
	string word;
	word=w.generate_random_word();
	return 0;
}

void display_hangman()
{
	cout<<"=========="<<endl;
	cout<<"    |"<<endl;
	cout<<"    |"<<endl;
	cout<<"    O"<<endl;
	cout<<"   /";
	cout<<"|";
	cout<<"\\"<<endl;
	cout<<"   /";
	cout<<" \\";
}
