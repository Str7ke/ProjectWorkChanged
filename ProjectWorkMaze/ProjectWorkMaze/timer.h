#pragma once

char loadingMenu[3][17]{ {219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219},
						{219,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',219},
						{219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219}
};
void Printarealoading() {
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 17; i++)
			cout << loadingMenu[j][i];
		cout << endl;
	}
}


int timer() {
	int hours = 0;
	int min = 0;
	int sec1 = 15;
	int sec2 = 1;
	while (true)
	{
		system("cls");

		if (sec2 != 16) {
			cout << "Loading..." << endl;
			loadingMenu[1][sec2] = char(254);
		}
		else if (sec2 == 16)
			cout << "Loading Finished" << endl;
		cout << 0 << " : " << min << " : " << sec1 << endl;
		Printarealoading();


		Sleep(970);
		if (sec1 > 0, sec2 < 16) {
			sec1--;
			sec2++;

		}

		else if (sec1 == 0 && min == 0) {
			cout << "You can Find .txt file in source of this code" << endl;
			cout << "Click any button to close" << endl;
			_getch();
			return false;
		}
	}





}