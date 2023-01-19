#pragma once
#include "RPS.h"
#include "TicTac.h"
#include "BOOM.h"
#include "Files.h"
PagesSettings Games;
PagesSettings Records;

int GamesLength = 3;
int RecordLength = 2;
char** menuGame= new char*[GamesLength]{
	new char[30]{"Rock,Paper & Siccors"},
	new char[30]{ "Tic,Tac" },
	new char[30]{ "BOOM" }
};
char** menuRecords= new char*[RecordLength]{
	new char[30]{"Show in console"},
	new char[30]{ "Export to txt" },

};

void PrintGameMenu() {
	system("cls");
	Pages(menuGame, GamesLength, Games.selectedIndex);
}
void PrintRecordsMenu() {
	system("cls");
	Pages(menuRecords, RecordLength, Records.selectedIndex);
}
bool LogicGame(int key) {
	switch (key)
	{
	case w:
	case up:
		if (Games.selectedIndex > 0)
			Games.selectedIndex--;
		else if (Games.selectedIndex == 0)
			Games.selectedIndex = 3 - 1;
		break;
	case s:
	case down:
		if (Games.selectedIndex < 3 - 1)
			Games.selectedIndex++;
		else if (Games.selectedIndex == 3 - 1)
			Games.selectedIndex = 0;
		break;

	case enter:
		system("cls");
		if (Games.selectedIndex == 0) {
			AllLogic(PrintNames, LogicRPS);
		}

		else if (Games.selectedIndex == 1) {
			ClearArea();
			Whosstep = 0;
			cout << "Enter First player name:", cin >> TicTac.Firstname;
			cout << "Enter second player name:", cin >> TicTac.Secondname;
			AllLogic(Printarea, LogicT1);

		}

		else if (Games.selectedIndex == 2) {
			Login();
			cout << "Enter mines count: ", cin >> MinesCount;
			AreaElement(areaUnvisible, areaX, areaY);
			AreaElement(areaVisible, areaX, areaY, '*');
			Randommines(areaUnvisible, areaX, areaY, MinesCount);
			MineFinder(areaUnvisible, areaX, areaY);
			AllLogic(PrintBoom, LogicBoom);
		}


		// Exit


	case esc:
		system("cls");
		return true;
	}

	return false;
}

bool LogicRecords(int key) {
	switch (key)
	{
	case w:
	case up:
		if (Records.selectedIndex > 0)
			Records.selectedIndex--;
		else if (Records.selectedIndex == 0)
			Records.selectedIndex = 2 - 1;
		break;
	case s:
	case down:
		if (Records.selectedIndex < 2 - 1)
			Records.selectedIndex++;
		else if (Records.selectedIndex == 2 - 1)
			Records.selectedIndex = 0;
		break;
	case enter:
		system("cls");
		if (Records.selectedIndex == 0)
		{
			cout << "To close click any button" << endl;
			FILE* file = fopen("Records.txt", "r");
			ReadAllText(file);
			fclose(file);
			_getch();

		}
		else if (Records.selectedIndex == 1)
		{
			timer();
			_getch();

		}


	case esc:
		system("cls");
		return true;
	}

	return false;
}