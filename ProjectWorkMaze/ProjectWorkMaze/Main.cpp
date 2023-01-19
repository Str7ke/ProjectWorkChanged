#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

#include "Structures.h"
#include "timer.h"
#include "Enums.h"
#include "MainMenuFunctions.h"


int main()
{
	AllLogic(PrintMain, LogicMain);
	cout << "Thank you for using my application)))" << endl;
	HeartMaker();
}