#pragma once

int selectedindexboomX = 1;
int selectedindexboomY = 1;
int emptyX = 10;
int emptyY = 5;
int fullX = 3;
int fullY = 3;
int Points;
int Truemines;
int minesX;
int minesY;
int MinesCount;
const int areaY = 20;
const int areaX = 60;
char areaUnvisible[areaY][areaX]{};
char areaVisible[areaY][areaX]{};
Players BOOM;
void Login() {
	system("cls");
	cout << "Name(less than 20 letters) : ", cin >> BOOM.Firstname;
}


void PrintBoom() {
	system("cls");

	for (int j = 0; j < areaY; j++)
	{


		for (int i = 0; i < areaX; i++)
		{
			if (i == selectedindexboomX && j == selectedindexboomY) {
				SetConsoleTextAttribute(console, 0x70);
				cout << areaVisible[j][i];
				SetConsoleTextAttribute(console, 0x07);
			}
			else {
				cout << areaVisible[j][i];
			}

		}
		cout << endl;
	}
}

void AreaElement(char area[][60], int X, int Y, char symbol = ' ') {
	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			if (j == 0 || j == X - 1 || i == 0 || i == Y - 1)
				area[i][j] = char(219);
			else
				area[i][j] = symbol;

		}
	}
}

void Randommines(char area[][60], int X, int Y, int mines) {
	srand(time(0));
	for (int i = 0; i < mines; i++)
	{
		minesX = rand() % (X - 2) + 1;
		minesY = rand() % (Y - 2) + 1;
		area[minesY][minesX] = 'X';
	}
}

void Printareaboom() {
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 60; i++)
			cout << areaUnvisible[j][i];
		cout << endl;
	}
}


void MineFinder(char area[][60], int X, int Y) {

	for (int j = 1; j < 19; j++)
	{
		for (int i = 1; i < 59; i++)
		{
			if (area[j][i] == ' ')
			{
				int counter = 48;

				if (area[j][i + 1] == 'X')
					counter += 1;

				if (area[j + 1][i + 1] == 'X')
					counter += 1;

				if (area[j + 1][i] == 'X')
					counter += 1;

				if (area[j + 1][i - 1] == 'X')
					counter += 1;

				if (area[j][i - 1] == 'X')
					counter += 1;

				if (area[j - 1][i - 1] == 'X')
					counter += 1;

				if (area[j - 1][i] == 'X')
					counter += 1;

				if (area[j - 1][i + 1] == 'X')
					counter += 1;


				if (counter != 48)
					area[j][i] = char(counter);
			}
		}

	}
}

void AreaOpen(int X, int Y) {

	for (int j = 0; j < Y; j++)
	{
		for (int i = 0; i < X; i++)
		{
			if (areaUnvisible[selectedindexboomY + j][selectedindexboomX + i] != 'X')
			{
				areaVisible[selectedindexboomY + j][selectedindexboomX + i] = areaUnvisible[selectedindexboomY + j][selectedindexboomX + i];
			}
		}
	}
}



bool LogicBoom(int key) {

	switch (key)
	{
	case KEYBOARD_KEYS::w:
	case KEYBOARD_KEYS::up:

		if (selectedindexboomY > 1)
			selectedindexboomY--;
		else if (selectedindexboomY == 1)
			selectedindexboomY = areaY - 2;
		break;


	case KEYBOARD_KEYS::s:
	case KEYBOARD_KEYS::down:
		if (selectedindexboomY < areaY - 2)
			selectedindexboomY++;
		else if (selectedindexboomY == areaY - 2)
			selectedindexboomY = 1;
		break;



	case KEYBOARD_KEYS::a:
	case KEYBOARD_KEYS::left:
		if (selectedindexboomX > 1)
			selectedindexboomX--;
		else if (selectedindexboomX == 1)
			selectedindexboomX = areaX - 2;
		break;

	case KEYBOARD_KEYS::d:
	case KEYBOARD_KEYS::right:
		if (selectedindexboomX < areaX - 2)
			selectedindexboomX++;
		else if (selectedindexboomX == areaX - 2)
			selectedindexboomX = 1;
		break;

	case enter:
		system("cls");
		if (areaUnvisible[selectedindexboomY][selectedindexboomX] == ' ' && areaVisible[selectedindexboomY][selectedindexboomX] == '*')
			AreaOpen(emptyX, emptyY);
		else if (areaUnvisible[selectedindexboomY][selectedindexboomX] == 'X') {
			cout << "You lose game..." << endl;
			cout << "True mines count: " << MinesCount << endl;
			cout << "Your finds: " << Truemines << endl;
			cout << "Your score: " << Points << endl;
			Printareaboom();
			ofstream fout("Records.txt", ofstream::app);
			fout << "\n" << BOOM.Firstname << ':' << Points;
			fout.close();

			_getch();

			return true;
		}
		else
			AreaOpen(1, 1);

	case KEYBOARD_KEYS::space:
		if (areaUnvisible[selectedindexboomY][selectedindexboomX] == 'X' && areaVisible[selectedindexboomY][selectedindexboomX] == '*')
		{
			areaVisible[selectedindexboomY][selectedindexboomX] = char(254);
			Points += 100;
			Truemines += 1;
			if (Truemines == MinesCount)
			{
				system("cls");
				cout << "You win the game,god job my friend!!!!" << endl;
				cout << "True mines count: " << MinesCount << endl;
				cout << "Your finds: " << Truemines << endl;
				cout << "Your score: " << Points << endl;
				Printareaboom();
				ofstream fout("Records.txt", ofstream::app);
				fout << "\n" << BOOM.Firstname << ':' << Points;
				fout.close();
				_getch();
				return true;
			}
		}
		else if (areaUnvisible[selectedindexboomY][selectedindexboomX] == 'X' && areaVisible[selectedindexboomY][selectedindexboomX] == char(254))
		{
			areaVisible[selectedindexboomY][selectedindexboomX] = '*';
			Points -= 100;
			Truemines -= 1;
		}
		else if (areaVisible[selectedindexboomY][selectedindexboomX] == char(254))
			areaVisible[selectedindexboomY][selectedindexboomX] = '*';

		else if (areaVisible[selectedindexboomY][selectedindexboomX] == '*')
			areaVisible[selectedindexboomY][selectedindexboomX] = char(254);



		/*case esc:
			system("cls");
			return true;*/
	}
	return false;

}