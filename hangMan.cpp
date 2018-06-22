#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

class hangMan{
private:
    string word;
    string update_word;
    int chances_left;
    bool game_over;

public:
    hangMan(string word = "anonymous", int chances_left = 5, bool game_over = false):
    	word(word), chances_left(chances_left), game_over(game_over){

        select_word() ;

    }

    string select_word(){

    	ifstream inputFile;
    	vector<string> temp;
    	string temp_string;
    	string randomWord;
        string temp_word;

        unsigned int MIN = 0;
    	unsigned int randomNumber;
    	unsigned int i = 0;

    	inputFile.open("inputFile.dat");

    	while(inputFile >> temp_string){
    		temp.push_back(temp_string);
    		i++;
    	}
    	inputFile.close();
    	srand(static_cast<unsigned int>(time(0)));
    	random_shuffle(temp.begin(), temp.end());
    	randomWord = temp[0];

    	string::iterator iterator1;

        for (iterator1 = randomWord.begin(); iterator1 != randomWord.end(); ++iterator1) {
            temp_word += "#";
        }

    	word = randomWord;
        update_word = temp_word;

        return word;
    }

    void update_game_status(char user_input){
        string answer;
        answer = word;

        string::iterator it;

        int i;
        char temp_char;

        for (it = answer.begin(), i = 0; it != answer.end(); ++it, ++i) {
            if(user_input == *it){
                update_word[i] = answer[i];
                temp_char = *it;
            }
        }

        if(temp_char != user_input){
            chances_left = this->chances_left - 1 ;
        }

        cout << "update game status word: "<< update_word << endl;
    }

    void printF(){
        cout << "Word is: " << word << endl;
    	cout << "Chances left: " << chances_left << endl;
        cout << "updated word: "<< update_word << endl;
    }

    void play(){

        char user_input;

        while(chances_left > 0){
            cout << "Please enter the character: " << endl;
            cin >> user_input;
            update_game_status(user_input);
            printF();

            if (update_word == word){
                cout << "Congratulations! you've won the game!" << endl;
                exit(1);
            }

        }
    }
};

int main() {
    cout << "game starts now: ";

    vector<string> word;
    hangMan hangman("anonymous", 5, false);
    hangman.printF();
    hangman.play();
    return 0;
}