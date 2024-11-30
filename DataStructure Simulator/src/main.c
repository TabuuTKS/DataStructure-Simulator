#include <stdio.h>
#include <conio.h>

#include "Menus\Colors.h"
#include "Menus\MainMenu.h"

int main() {
	printf("Welcome To Our Data Structure Simulator.\n");
	setYellowColor();
	printf("Note:- This Software Only Supports Integer Type to Simulate Data Structures Right Now\n");
	resetToBaseColor();
	MainMenu();
	_getch();
	return 0;
}