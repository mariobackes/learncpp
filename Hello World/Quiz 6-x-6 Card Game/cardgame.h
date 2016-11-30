
// I assume this is not the right way to structorize a header file...
// I'd appreciate feedback here or maybe an example of a well structorized header file.

// Includes 
#include <array>

// Header guard
#pragma once
#ifndef CARD_GAME_H
#define CARD_GAME_H

// global variables

const int g_deckSize = 52;

// enumerations

// I had these enums as enum classes, but the solution for this task was without the class keyword and my intention was to stick with the tutorial.
// Probably because there will be regular arrays later and these arrays synergise well with regular enums.

// Yes, needed the MAX_RANKS/MAX_SUITS to initialize the deck.

enum CardRank
{
    RANK_TWO,
    RANK_THREE,
    RANK_FOUR,
    RANK_FIVE,
    RANK_SIX,
    RANK_SEVEN,
    RANK_EIGHT,
    RANK_NINE,
    RANK_TEN,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};

enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};

enum class Result
{
    WIN,
    LOSE,
    TIE
};

// Structs

struct Card
{
    CardSuit suit;
    CardRank rank;
};

// Forward function decalarations

void printCard(const Card& card);

void printDeck(const std::array<Card, g_deckSize>& deck);

void swapCard(Card& x, Card& y);

void shuffleDeck(std::array<Card, g_deckSize>& deck);

int getCardValue(Card card);

Result playBlackjack(std::array<Card, g_deckSize>& deck);

bool hitOrStand();

#endif // !CARD_GAME_H