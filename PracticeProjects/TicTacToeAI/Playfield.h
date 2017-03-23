#pragma once
#include <string>

class Playfield
{
public:
	enum class Tile
	{
		X,
		O,
		null
	};


private:
	Tile m_field[9];

public:
	Playfield();
	~Playfield();

	
	void PrintField() const;
	// Tile::X returns 'X'. Tile::O returns 'O'. everything else returns a space (' ')
	char TileToString(Tile tile) const;
	// Asks the player to make his move and then lets the AI make its move
	void NextMove();
	// returns 1 if the player won. 2 if the AI won. 3 if the game is a draw. 4 if the game is not over yet
	uint8_t CheckWin() const;
	void AIsMove();

	int score()
	{
		if (CheckWin() == )
	}
private:

};

