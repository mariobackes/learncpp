#include "Playfield.h"
#include <iostream>


Playfield::Playfield()
{
	for (int i = 0; i < 9; ++i)
	{
		m_field[i] = Tile::null;
	}
}


Playfield::~Playfield()
{
}

void Playfield::PrintField() const
{
	auto functor = [&](int index)->char
	{
		return (m_field[index - 1] == Tile::null ? static_cast<char>(index) : TileToString(m_field[index-1]));
	};
	std::cout << " " << functor(1) << " | " << functor(2) << " | " << functor(3) << "\n";
	std::cout << "---+---+---\n";
	std::cout << " " << functor(4) << " | " << functor(5) << " | " << functor(6) << "\n";
	std::cout << "---+---+---\n";
	std::cout << " " << functor(7) << " | " << functor(8) << " | " << functor(9) << "\n";
}

char Playfield::TileToString(Tile tile) const
{
	switch (tile)
	{
	case Tile::X:
	return 'X';
	case Tile::O:
	return 'O';
	default:
	return ' ';
	}
}


void Playfield::NextMove()
{
	bool userInputSuccess = false;
	while (!userInputSuccess)
	{

		int input;
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
			std::cout << "You entered invalid input." << std::endl;
			continue;
		}
		if (input <= 0 || input >= 10)
		{
			std::cout << "The index you entered is out of range." << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		input -= 1; // Index of m_field starts at 0 but the tile enumeration starts at 1 for the user
		if (m_field[input] == Tile::X || m_field[input] == Tile::O)
		{
			std::cout << "The tile you entered is already taken." << std::endl;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		m_field[input] = Tile::X;
		userInputSuccess = true;
	}
}

uint8_t Playfield::CheckWin() const
{
	Tile winner;
	if (m_field[0] == m_field[1] && m_field[1] == m_field[2])
	{
		winner = m_field[1];
	}
	else if(m_field[3] == m_field[4] && m_field[4] == m_field[5])
	{
		winner = m_field[4];
	}
	else if(m_field[6] == m_field[7] && m_field[7] == m_field[8])
	{
		winner = m_field[7];
	}
	else if(m_field[0] == m_field[3] && m_field[3] == m_field[6])
	{
		winner = m_field[3];
	}
	else if (m_field[1] == m_field[4] && m_field[4] == m_field[7])
	{
		winner = m_field[4];
	}

	else if (m_field[2] == m_field[5] && m_field[5] == m_field[8])
	{
		winner = m_field[5];
	}
	else if (m_field[0] == m_field[5] && m_field[5] == m_field[8])
	{
		winner = m_field[5];
	}

	else if (m_field[2] == m_field[5] && m_field[5] == m_field[6])
	{
		winner = m_field[5];
	}
	else // no winner found
	{
		bool gameUnfinished = false;
		for (int i = 0; i < 9; ++i)
		{
			if (m_field[i] == Tile::null)
			{
				return 4; // Still empty tiles and no winner was found >>> Game is not over yet
			}
		}
		return 3; // No empty tiles and no winner was found >>> game is a draw
	}

	switch (winner) // winner will either be set here or the function will have returned if there is no winner
	{
	case Tile::X:
	return 1; // Player won
	case Tile::O:
	return 2; // AI won
	}
}

void Playfield::AIsMove()
{

}
