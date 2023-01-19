#pragma once
struct AllLogic
{

	AllLogic(void printmenu(), bool Logic(int key))
	{
		bool end = false;
		while (end == false) {
			// print
			printmenu();

			// input
			int key = _getch();

			// logic
			if (Logic(key))
				break;
		}
	}

	
};

class Players
{
public:
	string Firstname;
	string Secondname;
};

struct AreaPrintTicTac
{
	AreaPrintTicTac(char** area, int X, int Y, int selectedindexX,int selectedindexY) {
		for (int j = 0; j < Y; j++)
		{


			for (int i = 0; i < X; i++)
			{
				if (i == selectedindexX && j == selectedindexY) {
					SetConsoleTextAttribute(console, 0x70);
					cout << area[j][i] << " | ";
					SetConsoleTextAttribute(console, 0x07);
				}
				else {
					cout << area[j][i] << " | ";
				}

			}
			cout << endl;
			cout << "___________" << endl;
		}

	}

};

struct Pages
{
	Pages(char** menu, int lenght, int selectedindex) {
		for (int i = 0; i < lenght; i++)
		{
			if (i == selectedindex) {
				SetConsoleTextAttribute(console, 0x70);
				cout << "> " << menu[i] << endl;
				SetConsoleTextAttribute(console, 0x07);
			}
			else {
				cout << menu[i] << endl;
			}
		}

	}

	
};


class PagesSettings
{
public:
	int selectedIndex = 0;
	

};

