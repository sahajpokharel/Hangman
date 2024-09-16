#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

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
			char letter,game_word[word.length()], wrong[8];
			int i=0;
			for(int i=0; i<word.length(); i++)
			game_word[i]='_';
			while(1)
			{
				display_hangman(i,game_word,wrong);
				cout<<endl<<endl<<"Enter letter: ";
				cin>>letter;
				for(int j=0; word[j]!='\0'; j++)
				{
					if(word[j]==letter)
					game_word[j]=letter;
				}
				for(int j=0; game_word[j]!='\0'; j++)
				{
					if(game_word[j]=='_')
					{
						i++;
						continue;
					}
					else
					{
						cout<<endl<<endl<<"CORRECT!\n\nYou Win";
						break;
					}
				}
			}
		}
		void display_hangman(int n, string combo, char c[])
		{
			if (n==0)
			{
				cout<<"\n\n\n\n\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<"Invalid letters: ";
			}
			else if (n==1)
			{
				system("cls");
				cout<<"=========="<<endl;
		    	cout<<"\n\n\n\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<"Invalid letters: "<<c[0];
			}
			else if (n==2)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
		    	cout<<"\n\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<"Invalid letters: "<<c[0]<<" "<<c[1];
			}
			else if (n==3)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
		    	cout<<"\n\n\n\n\n\n";
				cout<<combo;
				cout<<endl<<"Invalid letters: "<<c[0]<<" "<<c[1]<<" "<<c[2];
			}
		    else if (n==4)
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
				cout<<endl<<"Invalid letters: "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3];
			}
			else if (n==5)
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
				cout<<endl<<"Invalid letters: "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4];
			}
			else if (n==6)
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
				cout<<endl<<"Invalid letters: "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5];
			}
			else if (n==7)
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
				cout<<endl<<"Invalid letters: "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6];
			}
			else if (n==8)
			{
				system("cls");
				cout<<"=========="<<endl;
				cout<<"    |"<<endl;
		    	cout<<"    |"<<endl;
				cout<<"    O"<<endl;
				cout<<"   /|\\"<<endl;
				cout<<"    |"<<endl;
				cout<<"   /\\"<<endl;
		    	cout<<"\n\n\n";
				cout<<combo;
				cout<<endl<<"Invalid letters: "<<c[0]<<" "<<c[1]<<" "<<c[2]<<" "<<c[3]<<" "<<c[4]<<" "<<c[5]<<" "<<c[6]<<" "<<c[7];
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
