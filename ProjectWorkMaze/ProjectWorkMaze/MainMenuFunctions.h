#pragma once

#include "SecondMenuFucntions.h"
#include "Files.h"

PagesSettings MainPage;
int lengthMain = 4;
char** MainMenu = new char* [4] {
	    new char[30] {"Games"},
		new char[30] {"Records in Boom"},
		new char[30] {"About how i make this project"},
		new char[30] {"Exit"}
};



void PrintMain() {
	system("cls");
	Pages(MainMenu, lengthMain, MainPage.selectedIndex);
	
}



bool LogicMain(int key) {
	switch (key)
	{
	case KEYBOARD_KEYS::w:
	case up:
		if (MainPage.selectedIndex > 0)
			MainPage.selectedIndex--;
		else if (MainPage.selectedIndex == 0)
			MainPage.selectedIndex = 4 - 1;
		break;
	case KEYBOARD_KEYS::s:
	case down:
		if (MainPage.selectedIndex < 4 - 1)
			MainPage.selectedIndex++;
		else if (MainPage.selectedIndex == 4 - 1)
			MainPage.selectedIndex = 0;
		break;

	case enter:
		system("cls");
		if (MainPage.selectedIndex == 0) {
			AllLogic(PrintGameMenu, LogicGame);
		}
		else if (MainPage.selectedIndex == 1) {
			AllLogic(PrintRecordsMenu, LogicRecords);
		}
		else if (MainPage.selectedIndex == 2) {
			cout << "To see all of text open conosle full" << endl;
			cout << "If u open full or console was open click any button" << endl;
			_getch();
			system("cls");
			FILE* file1 = fopen("AboutUs.txt", "r");
			ReadAllText(file1);
			cout << "To close this menu click any button" << endl;
			_getch();
			return false;

		}
		else if (MainPage.selectedIndex == 3) {
			return true;

		}






	case esc:
		system("cls");
		return false;
	}

	return false;
}

//from internet
void HeartMaker() {
	int n, row, col;
	n = 6;
	for (row = 0; row < n; row++)
	{
		for (col = 0; col < n + 1; col++)
			if ((row == 0 && col % 3 != 0) || (row == 1 && col % 3 == 0) || (row - col == 2) || (row + col == 8))
				cout << ("*");
			else
				cout << (" ");

		cout << ("\n");
	}

}