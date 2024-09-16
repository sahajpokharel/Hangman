#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <windows.h>

using namespace std;

class words{
	string word;
	public:
		words()
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
		    int current_line = 0;
		    while (getline(wordfile, word)) 
			{
		    	current_line++;
		        if (current_line == word_position)
		        break;
		    }
		    wordfile.close();
		}
		void play_game()
		{
			char letter, letters_and_blanks[word.length()], wrong_guesses[8];
			int wrong_attempts=0,blanks=word.length(),i;
			bool complete=false,wrong_letter=false;
			for(i=0; i<word.length(); i++)
			letters_and_blanks[i]='_';
//			cout<<word;
//			Sleep(2000);
			while(1)
			{
				display_hangman(wrong_attempts,letters_and_blanks,wrong_guesses);
				cout<<endl<<endl<<"Enter letter: ";
				cin>>letter;
				int new_blanks=blanks;
				for(i=0; i<word.length(); i++)
				{
					if(word[i]==toupper(letter))
					{
						letters_and_blanks[i]=toupper(letter);
						blanks--;
					}
				}
				if(new_blanks==blanks)
				{
					for(i=0; wrong_guesses[i]!='\0'; i++)
					if(wrong_guesses[i]==letter)
					goto blanks_continue_label;
					wrong_guesses[wrong_attempts]=letter;
					wrong_attempts++;
					blanks_continue_label:
					continue;
				}
				for(i=0; i<word.length(); i++)
				{
					if(letters_and_blanks[i]=='_')
					{
						complete=false;
						break;
					}
					else
					{
						complete=true;
					}
				}
				if(complete)
				break;
			}
			if(complete)
			{
				display_hangman(wrong_attempts,letters_and_blanks,wrong_guesses);
				cout<<endl<<endl<<"CORRECT!\n\nYou Win";
			}
		}
		void display_hangman(int w_a, string combo, char w_g[])
		{
			if (w_a==0)
			{
				system("cls");
				cout<<"\n\n\n\n\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: ";
			}
			else if (w_a==1)
			{
				system("cls");
				cout<<"=========="<<endl;
		    	cout<<"\n\n\n\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0];
			}
			else if (w_a==2)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
		    	cout<<"\n\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0]<<" "<<w_g[1];
			}
			else if (w_a==3)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
		    	cout<<"\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0]<<" "<<w_g[1]<<" "<<w_g[2];
			}
		    else if (w_a==4)
		    {
		    	system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"    |"<<endl;
				cout<<"    |";
		    	cout<<"\n\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0]<<" "<<w_g[1]<<" "<<w_g[2]<<" "<<w_g[3];
			}
			else if (w_a==5)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|"<<endl;
				cout<<"    |";
		    	cout<<"\n\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0]<<" "<<w_g[1]<<" "<<w_g[2]<<" "<<w_g[3]<<" "<<w_g[4];
			}
			else if (w_a==6)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|\\"<<endl;
				cout<<"    |";
		    	cout<<"\n\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0]<<" "<<w_g[1]<<" "<<w_g[2]<<" "<<w_g[3]<<" "<<w_g[4]<<" "<<w_g[5];
			}
			else if (w_a==7)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|\\"<<endl;
				cout<<"    |"<<endl;
				cout<<"   /"<<endl;
		    	cout<<"\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0]<<" "<<w_g[1]<<" "<<w_g[2]<<" "<<w_g[3]<<" "<<w_g[4]<<" "<<w_g[5]<<" "<<w_g[6];
			}
			else if (w_a==8)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|\\"<<endl;
				cout<<"    |"<<endl;
				cout<<"   / \\"<<endl;
		    	cout<<"\n\n\n";
				cout<<combo;
				cout<<endl<<endl<<"Invalid letters: "<<w_g[0]<<" "<<w_g[1]<<" "<<w_g[2]<<" "<<w_g[3]<<" "<<w_g[4]<<" "<<w_g[5]<<" "<<w_g[6]<<" "<<w_g[7];
				cout<<endl<<endl<<"The word was: "<<word<<"!\n\nYou Lose";
				exit(1);
			}
		}
};
int main()
{
	words w;
	w.play_game();
	return 0;
}
