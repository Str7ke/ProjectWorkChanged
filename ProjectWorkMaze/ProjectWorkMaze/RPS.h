#pragma once

PagesSettings RPS;
int RPSLength = 3;

char** RPSNames=new char*[RPSLength]{
	new char [16] {"ROCK"},
	new char[16] { "PAPER" },
	new char [16] { "SCISSORS" }
};


//int selectedindexRPS = 0;

void PrintNames() {
	system("cls");
	Pages(RPSNames, RPSLength, RPS.selectedIndex);
}

int compChooise;

// random number
int CompChooise() {
	srand(time(0));



	compChooise = rand() % 3;

	//1 means Rock
	//2 means Paper
	//3 means Scissors
	return compChooise;
}

bool LogicRPS(int key) {
	switch (key)
	{
	case w:
	case up:
		if (RPS.selectedIndex > 0)
			RPS.selectedIndex--;
		else if (RPS.selectedIndex == 0)
			RPS.selectedIndex = 3 - 1;
		break;
	case s:
	case down:
		if (RPS.selectedIndex < 3 - 1)
			RPS.selectedIndex++;
		else if (RPS.selectedIndex == 3 - 1)
			RPS.selectedIndex = 0;
		break;

	case enter:
		system("cls");
		CompChooise();
		cout << "your choice is: " << RPSNames[RPS.selectedIndex] << endl;
		cout << "computer's choice is: " << RPSNames[compChooise] << endl;

		if (RPS.selectedIndex == 0)
		{
			if (compChooise == 1)
				cout << "computer wins! paper wraps rock." << endl;
			else if (compChooise == 2)
				cout << "you win! paper wraps rock." << endl;
			else if (compChooise == 0)
				cout << "tie. play again win the game." << endl;
		}

		else if (RPS.selectedIndex == 1)
		{
			if (compChooise == 0)
				cout << "you win! paper wraps rock." << endl;
			else if (compChooise == 2)
				cout << "computer wins! scissors cut paper." << endl;
			else if (compChooise == 1)
				cout << "tie. play again win the game." << endl;
		}

		else if (RPS.selectedIndex == 2)
		{
			if (compChooise == 0)
				cout << "computer wins! rock smashes scissors." << endl;
			else if (compChooise == 1)
				cout << "you win! scissors cut paper." << endl;
			else if (compChooise == 2)
				cout << "tie. play again win the game." << endl;
		}
		_getch();
	case esc:
		system("cls");
		return true;
	}
	return false;
}
