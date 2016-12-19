#pragma once
class Player : public Creature
{
protected:
  int m_level;

public:
  Player(std::string name);

  // Increments m_level and m_dpa
  void levelUp();

  // Returns m_level
  int getLevel();

  // Returns true if the player won
  bool hasWon();

};

