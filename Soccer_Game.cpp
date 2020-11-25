/*
Kayla Chenier
SYDE 121

PURPOSE: write a program that will generate a random soccer game that meets all the criteria
in the assignment.
*/

#include <iostream>
#include <ctime>
using namespace std;

//functions- execute_soccer_game, output_scoreboard, and execute_half
void execute_soccer_game();
//PURPOSE: calls the other functions and executes the different steps of the program
//INPUT: none
//OUTPUTS: none
void output_scoreboard(int Ascore, int Bscore, int Ashots_on_goal, int Bshots_on_goal,  int Ashots_off_goal, int Bshots_off_goal,int Ashots_blocked, int Bshots_blocked,
	int Afouls, int Bfouls, int Ayellow_cards, int Byellow_cards, int Ared_cards, int Bred_cards);
//PURPOSE: outputs the scoreboard in propper format
//INPUTS: all the variables, like litterally all of them except the number of events in the half
//OUTPUTS: none
void execute_half(int& Ascore, int& Bscore, int& Ashots_on_goal, int& Bshots_on_goal, int& Ashots_off_goal, int& Bshots_off_goal, int& Ashots_blocked, int& Bshots_blocked,
	int& Afouls, int& Bfouls, int& Ayellow_cards, int& Byellow_cards, int& Ared_cards, int& Bred_cards, int events_left);
//PURPOSE: execute the events in the half
//INPUTS: all the variables- an they are pointers
//OUTPUTS: none

//PURPOSE: calls the other functions and executes the different steps of the program
//INPUT: none
//OUTPUTS: none
void execute_soccer_game() {
	//initialize variables for current score, shots on goal, shots off goal, blocked shots, fouls, yellow cards, and red cards
	int Ascore=0, Bscore=0, Ashots_on_goal=0, Bshots_on_goal = 0, Ashots_off_goal = 0, Bshots_off_goal = 0, Ashots_blocked = 0, Bshots_blocked = 0, Afouls = 0, Bfouls = 0,
		Ayellow_cards = 0, Byellow_cards = 0, Ared_cards = 0, Bred_cards = 0, num_events = 0, events_half1= 0, events_half2 = 0;
	srand(time(0));

	//Generate number 1-20 to determine the number of events that will take place
	num_events = rand() % 20;
	//Divide the number by 2 and assign that number of events to each half(if it is odd, add one to the first half)
	events_half1 = events_half2 = num_events / 2;
	if (num_events % 2 == 1) {
		events_half2 ++;
	}
	
	//Execute First Half
	execute_half(Ascore, Bscore, Ashots_on_goal, Bshots_on_goal, Ashots_off_goal, Bshots_off_goal, Ashots_blocked, Bshots_blocked,
		Afouls, Bfouls, Ayellow_cards, Byellow_cards, Ared_cards, Bred_cards, events_half1);

	//Output Scoreboard
	output_scoreboard(Ascore, Bscore, Ashots_on_goal, Bshots_on_goal, Ashots_off_goal, Bshots_off_goal, Ashots_blocked, Bshots_blocked, Afouls, Bfouls, Ayellow_cards,
		Byellow_cards, Ared_cards, Bred_cards);

	//Execute Second Half
	execute_half(Ascore, Bscore, Ashots_on_goal, Bshots_on_goal, Ashots_off_goal, Bshots_off_goal, Ashots_blocked, Bshots_blocked,
		Afouls, Bfouls, Ayellow_cards, Byellow_cards, Ared_cards, Bred_cards, events_half2);

	//Output Scoreboard
	output_scoreboard(Ascore, Bscore, Ashots_on_goal, Bshots_on_goal, Ashots_off_goal, Bshots_off_goal, Ashots_blocked, Bshots_blocked, Afouls, Bfouls, Ayellow_cards,
		Byellow_cards, Ared_cards, Bred_cards);

	//Determine who wins at the end
	if (Ascore > Bscore) {
		cout << "TEAM A WINS!!!" << endl;
	}
	else if (Bscore > Ascore) {
		cout << "TEAM B WINS!!!" << endl;
	}
	else {
		cout << "IT'S A TIE" << endl;
	}
}

//PURPOSE: execute the events in the half
//INPUTS: all the variables- an they are pointers
//OUTPUTS: none
void execute_half(int& Ascore, int& Bscore, int& Ashots_on_goal, int& Bshots_on_goal, int& Ashots_off_goal, int& Bshots_off_goal, int& Ashots_blocked, int& Bshots_blocked,
	int& Afouls, int& Bfouls, int& Ayellow_cards, int& Byellow_cards, int& Ared_cards, int& Bred_cards, int events_left){

	int event = 0;
	//go though the logic of the events
	while (events_left > 0) {
		event = (rand() % 6) + 1;
		cout << endl;
		if (event == 1) {
			// Team A shoots target
			cout << "Team A shoots"<< endl;
			int outcome = rand() % 4;
			if (outcome == 0) {
				//team scores a goal
				cout << "Team A scores!" << endl;
				Ashots_on_goal++;
				Ascore++;
			}
			else if (outcome == 1) {
				//shot was saved by goalkeeper or last defender
				cout << "Shot was saved by goalkeep or last defender" << endl;
				Ashots_on_goal++;
				Ashots_blocked++;
			}
			else if (outcome == 2) {
				//shot made off goal
				cout << "Shot was made off goal" << endl;
				Ashots_off_goal++;
			}
			else if (outcome == 3) {
				//shot was blocked by player
				cout << "Shot was blocked by player" << endl;
				Ashots_on_goal++;
				Ashots_blocked++;
			}
		}
		else if (event == 2) {
			// Team B shoots target
			cout << "Team B shoots" << endl;
			int outcome = rand() % 4;
			if (outcome == 0) {
				//team scores a goal
				cout << "Team B scores!" << endl;
				Bshots_on_goal++;
				Bscore++;
			}
			else if (outcome == 1) {
				//shot was saved by goalkeeper or last defender
				cout << "Shot was saved by goalkeeper or last defender" << endl;
				Bshots_on_goal++;
				Bshots_blocked++;
			}
			else if (outcome == 2) {
				//shot made off goal
				cout << "Shot was made off goal" << endl;
				Bshots_off_goal++;
			}
			else if (outcome == 3) {
				//shot was blocked by player
				cout << "Shot was blocked by player" << endl;
				Bshots_on_goal++;
				Bshots_blocked++;
			}
		}
		else if (event == 3) {
			// Team B fouls, team A gets a free kick
			cout << "Team B fouls, team A gets a free kick" << endl;
			Bfouls++;
			int outcome = rand() % 4;
			if (outcome == 0) {
				//team scores a goal
				cout << "Team A scores!" << endl;
				Ashots_on_goal++;
				Ascore++;
			}
			else if (outcome == 1) {
				//shot was saved by goalkeeper or last defender
				cout << "Shot was saved by goalkeeper or last defender" << endl;
				Ashots_on_goal++;
				Ashots_blocked++;
			}
			else if (outcome == 2) {
				//shot made off goal
				cout << "Shot was made off goal" << endl;
				Ashots_off_goal++;
			}
			else if (outcome == 3) {
				//shot was blocked by player
				cout << "Shot was blocked by player" << endl;
				Ashots_on_goal++;
				Ashots_blocked++;
			}
			outcome = rand() % 3;
			if (outcome == 0) {
				//no card given
				cout << "No card given" << endl;
			}
			else if (outcome == 1) {
				//yellow card
				cout << "yellow card given to team B" << endl;
				Byellow_cards++;
			}
			else if (outcome == 2) {
				//red card
				cout << "red card given to team B" << endl;
				Bred_cards++;
			}
		}
		else if (event == 4) {
			// Team A fouls, team B gets a free kick
			cout << "Team A fouls, team B gets a free kick" << endl;
			Afouls++;
			int outcome = rand() % 4;
			if (outcome == 0) {
				//team scores a goal
				cout << "Team B scores!" << endl;
				Bshots_on_goal++;
				Bscore++;
			}
			else if (outcome == 1) {
				//shot was saved by goalkeeper or last defender
				cout << "Shot was saved by goalkeeper or last defender" << endl;
				Bshots_on_goal++;
				Bshots_blocked++;
			}
			else if (outcome == 2) {
				//shot made off goal
				cout << "Shot was made off goal" << endl;
				Bshots_off_goal++;
			}
			else if (outcome == 3) {
				//shot was blocked by player
				cout << "Shot was blocked by player" << endl;
				Bshots_on_goal++;
				Bshots_blocked++;
			}
			outcome = rand() % 3;
			if (outcome == 0) {
				//no card given
				cout << "No card given" << endl;
			}
			else if (outcome == 1) {
				//yellow card
				cout << "yellow card given to team A" << endl;
				Ayellow_cards++;
			}
			else if (outcome == 2) {
				//red card
				cout << "red card given to team A" << endl;
				Ared_cards++;
			}
		}
		else if (event == 5) {
			// Team B fouls near goal, team A gets a penalty kick
			cout << "Team B fouls near goal, team A gets a penalty kick" << endl;
			Bfouls++;
			int outcome = rand() % 3;
			if (outcome == 0) {
				//team scores a goal
				cout << "Team A scores!" << endl;
				Ashots_on_goal++;
				Ascore++;
			}
			else if (outcome == 1) {
				//shot was saved by goalkeeper or last defender
				cout << "Shot was saved by goalkeeper or last defender" << endl;
				Ashots_on_goal++;
				Ashots_blocked++;
			}
			else if (outcome == 2) {
				//shot made off goal
				cout << "Shot was made off goal" << endl;
				Ashots_off_goal++;
			}
			outcome = rand() % 3;
			if (outcome == 0) {
				//no card given
				cout << "No card given" << endl;
			}
			else if (outcome == 1) {
				//yellow card
				cout << "yellow card given to team B" << endl;
				Byellow_cards++;
			}
			else if (outcome == 2) {
				//red card
				cout << "red card given to team B" << endl;
				Bred_cards++;
			}
		}
		else if (event == 6) {
			// Team A fouls near goal, team B gets a penalty kick
			cout << "Team A fouls near goal, team B gets a penalty kick" << endl;
			Afouls++;
			int outcome = rand() % 3;
			if (outcome == 0) {
				//team scores a goal
				cout << "Team B scores!" << endl;
				Bshots_on_goal++;
				Bscore++;
			}
			else if (outcome == 1) {
				//shot was saved by goalkeeper or last defender
				cout << "Shot was saved by goalkeeper or last defender" << endl;
				Bshots_on_goal++;
				Bshots_blocked++;
			}
			else if (outcome == 2) {
				//shot made off goal
				cout << "Shot was made off goal" << endl;
				Bshots_off_goal++;
			}
			outcome = rand() % 3;
			if (outcome == 0) {
				//no card given
				cout << "No card given" << endl;
			}
			else if (outcome == 1) {
				//yellow card
				cout << "yellow card given to team A" << endl;
				Ayellow_cards++;
			}
			else if (outcome == 2) {
				//red card
				cout << "red card given to team A" << endl;
				Ared_cards++;
			}
		}
		events_left--;
	}

}

//PURPOSE: outputs the scoreboard in propper format
//INPUTS: all the variables, like litterally all of them except the number of events in the half
//OUTPUTS: none
void output_scoreboard(int Ascore, int Bscore, int Ashots_on_goal, int Bshots_on_goal, int Ashots_off_goal, int Bshots_off_goal, int Ashots_blocked, int Bshots_blocked,
	int Afouls, int Bfouls, int Ayellow_cards, int Byellow_cards, int Ared_cards, int Bred_cards) {
	cout << "\nSCOREBOARD" << "\tTeam A \tTeam B" << endl;
	cout << "Score: \t\t" << Ascore << "\t" << Bscore << endl;
	cout << "Shots on goal:\t" << Ashots_on_goal << "\t" << Bshots_on_goal << endl;
	cout << "Shots off goal:\t" << Ashots_off_goal << "\t" << Bshots_off_goal << endl;
	cout << "Shots blocked:\t" << Ashots_blocked << "\t" << Bshots_blocked << endl;
	cout << "Fouls:\t\t" << Afouls << "\t" << Bfouls << endl;
	cout << "Yellow Cards:\t" << Ayellow_cards << "\t" << Byellow_cards << endl;
	cout << "Red Cards:\t" << Ared_cards << "\t" << Bred_cards << endl;
	cout << endl;
}

int main() {
	execute_soccer_game();
}