//Author: Chase Morgan 8/18/22
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string tricks[9] = { "Ollie", "BS-Shuvit","FS-Shuvit","FS-180", "BS-180", "KickFlip", "HeelFlip", "Varial Flip", "Frontside Kickflip" };
const string stances[4] = { "","Fakie ", "Switch ", "Nollie "};

vector<string> robot_tricks_done = {};
vector<string> user_tricks_done = {};

int user_letters = 0;
int robot_letters = 0;

string user_guess;
string robot_guess;
string user_trick;
string robot_trick;
string yesno;

bool isUsersTurn;
bool didRobotLandTrick;
bool didUserLandTrick;

bool contains(vector<string> haystack, string needle) {
	if (count(haystack.begin(), haystack.end(), needle)) {
		return true;
	}return false;
}
bool isValidTrick(string needsChecked) {
	for (int i = 0; i < size(stances); i++) {
		for (int a = 0; a < size(tricks); a++) {
			if (needsChecked == stances[i] + tricks[a]) {
				return true;
			}
		}

	}
	return false;
}
void drawLetters(int num) {
	string letters[5] = { "S","K","A","T","E"};
	cout << "***************\n";
	if (num == 5) {
		cout << "S.K.A.T.E\n";
	}
	else {
		for (int i = 0; i < num; i++) {
			cout << letters[i] << ".";
		}
		cout << endl;
	}
	cout << "***************\n";
}

string randomRPS() {
	int randNum = (rand() % 3);
	string choices[3] = { "Rock", "Paper", "Scissors" };
	return choices[randNum];
}
string getRandomTrick() {
	return stances[(rand() % 4)] + tricks[(rand() % 9)];
}
int main() {
	srand(time(NULL));
	cout << "Rock, Paper, Or Scissors?\n";
	cin >> user_guess;
	while (user_guess != "Rock" && user_guess != "Paper" && user_guess != "Scissors") {
		cout << "Error. invalid selection\n";
		cout << "Rock, Paper, Or Scissors?\n";
		cin >> user_guess;
	}
	robot_guess = randomRPS();
	cout << "Robot's Guess is " << robot_guess << "!\n";
	while (robot_guess == user_guess) {
		cout << "Try again!\n";
		cout << "Rock, Paper, Or Scissors?\n";
		cin >> user_guess;
		robot_guess = randomRPS();
		cout << "Robot's Guess is " << robot_guess << "!\n";
	}
	//If user wins RPS Match.
	if ((user_guess == "Rock" && robot_guess == "Scissors") || (user_guess == "Paper" && robot_guess == "Rock") || (user_guess == "Scissors" && robot_guess == "Paper")) {
		isUsersTurn = true;
	}//if robot does
	else {
		isUsersTurn = false;
	}
	while (user_letters < 5 && robot_letters < 5) {
		if (isUsersTurn) {
			cout << "Enter your trick. (type Missed if you missed the trick)\n";
			cin >> user_trick;
			if (user_trick == "Missed") {
				isUsersTurn = false;
				continue;
			}
			while (!isValidTrick(user_trick)) {
				cout << "Not a valid trick.\nEnter your trick. (type Missed if you missed the trick)\n";
				cin >> user_trick;
			}
			while (contains(user_tricks_done, user_trick)) {
				cout << "You have already done that trick!\nEnter your trick. (type Missed if you missed the trick)\n";
				cin >> user_trick;
			}
			user_tricks_done.push_back(user_trick);
			didRobotLandTrick = (rand() % 2);
			if (didRobotLandTrick) {
				cout << "Robot defended it!\n";
			}
			else {
				robot_letters++;
				cout << "Robot Missed!\nRobot's letters:\n";
				drawLetters(robot_letters);
			}
		}
		else {
			cout << "Robot enters trick\n";
			didRobotLandTrick = (rand() % 2);
			if (didRobotLandTrick) {
				robot_trick = getRandomTrick();
				while (contains(robot_tricks_done, robot_trick)) {
					robot_trick = getRandomTrick();
				}
				cout << "Robot did a " << robot_trick << endl << "Did you land it? ";
				cin >> yesno;
				if (yesno == "No") {
					user_letters++;
					cout << "Your letters: \n";
					drawLetters(user_letters);

				}
			}
			else {
				cout << "Robot did not land trick.\n";
				isUsersTurn = true;
			}
		}
	}if (user_letters == 5) {
		cout << "You Win! Well Done\n";
	}
	else {
		cout << "Robot Wins. Better Luck Next Time\n";
	}
}
