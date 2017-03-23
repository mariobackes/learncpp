

#include "Playfield.h"
#include <iostream>
#include "Windows.h"

// This was intended to become a project for a tictactoe ai

int main()
{
	Playfield field;
	while (true)
	{

		field.PrintField();
		field.NextMove();
		if(field.CheckWin() == 1)
		{
			std::cout << "You won" << std::endl;
			break;
		}
		if (field.CheckWin() == 3)
		{
			std::cout << "Draw" << std::endl;
			break;
		}
		field.AIsMove();
		if(field.CheckWin() == 2)
		{
			std::cout << "You lose" << std::endl;
			break;
		}
		if (field.CheckWin() == 3)
		{
			std::cout << "Draw" << std::endl;
			break;
		}
		system("cls");
	}
	std::cout << "Play again?" << std::endl;
	std::cin.get();
}
