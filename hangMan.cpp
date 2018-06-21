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
    	word = randomWord;

        return word;
    }

    void update_game_status(char user_input){
        string answer;
        answer = this->word;
        string temp;
        string::iterator it;
        for (it = answer.begin(); it != answer.end(); ++it) {
            temp += "#";
        }

        int i;
        for (it = answer.begin(), i = 0; it != answer.end(); ++it, ++i) {
            if(user_input == *it){
                temp[i] = user_input;
            }
        }

        cout << "update game status word: "<< temp << endl;
    }

    void printF(){

    	cout << "Selected word is: " << word << endl;
    }
};
/*
class player{
private:
	hangMan hangman;
public:

};
*/
int main() {
    cout << "game starts now: ";

    vector<string> word;
    hangMan hangman("anonymous", 5, false);
    hangman.printF();
    hangman.update_game_status('e');
    return 0;
}