// Quiz 8-x-4 Card Game oop.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const int g_deckSize{ 52 };


class Card
{
public:
    
enum CardSuit
{
    SUIT_CLUB,
    SUIT_DIAMOND,
    SUIT_HEART,
    SUIT_SPADE,
    MAX_SUITS
};

enum CardRank
{
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    RANK_JACK,
    RANK_QUEEN,
    RANK_KING,
    RANK_ACE,
    MAX_RANKS
};



Card(CardRank rank = CardRank::RANK_2, Card::CardSuit suit = Card::CardSuit::SUIT_HEART)
    : m_rank{ rank }, m_suit{ suit }
{

}
~Card()
{

}


void printCard() const
{
    switch (m_rank)
    {
    case RANK_2:		std::cout << '2'; break;
    case RANK_3:		std::cout << '3'; break;
    case RANK_4:		std::cout << '4'; break;
    case RANK_5:		std::cout << '5'; break;
    case RANK_6:		std::cout << '6'; break;
    case RANK_7:		std::cout << '7'; break;
    case RANK_8:		std::cout << '8'; break;
    case RANK_9:		std::cout << '9'; break;
    case RANK_10:		std::cout << 'T'; break;
    case RANK_JACK:		std::cout << 'J'; break;
    case RANK_QUEEN:	std::cout << 'Q'; break;
    case RANK_KING:		std::cout << 'K'; break;
    case RANK_ACE:		std::cout << 'A'; break;
    }

    switch (m_suit)
    {
    case SUIT_CLUB:		std::cout << 'C'; break;
    case SUIT_DIAMOND:	std::cout << 'D'; break;
    case SUIT_HEART:	std::cout << 'H'; break;
    case SUIT_SPADE:	std::cout << 'S'; break;
    }
}

int getCardValue() const
{
    switch (m_rank)
    {
    case RANK_2:		return 2;
    case RANK_3:		return 3;
    case RANK_4:		return 4;
    case RANK_5:		return 5;
    case RANK_6:		return 6;
    case RANK_7:		return 7;
    case RANK_8:		return 8;
    case RANK_9:		return 9;
    case RANK_10:		return 10;
    case RANK_JACK:		return 10;
    case RANK_QUEEN:	return 10;
    case RANK_KING:		return 10;
    case RANK_ACE:		return 11;
    }

    return 0;
}

friend class Deck;

private:
    CardRank m_rank;
    CardSuit m_suit;
};


class Deck
{
private:
    std::array<Card, g_deckSize> m_deck;
    int m_cardIndex = 0;
    static int getRandomNumber(int min, int max)
    {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
                                                                                     // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }

    static void swapCard(Card &a, Card &b)
    {
        Card temp = a;
        a = b;
        b = temp;
    }
public:

    Deck()
    {
        int card = 0;
        for (int suit = 0; suit < Card::CardSuit::MAX_SUITS; ++suit)
        {
            for (int rank = 0; rank < Card::CardRank::MAX_RANKS; ++rank)
            {
                m_deck[card].m_rank = static_cast<Card::CardRank>(rank);
                m_deck[card].m_suit = static_cast<Card::CardSuit>(suit);
                ++card;
            }
        }
    }

    void printDeck() const
    {
        for (const Card card : m_deck)
        {
            card.printCard();
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    void shuffleDeck()
    {
        // Step through each card in the deck
        for (int index = 0; index < 52; ++index)
        {
            // Pick a random card, any card
            int swapIndex = getRandomNumber(0, 51);
            // Swap it with the current card
            swapCard(m_deck[index], m_deck[swapIndex]);
        }
        m_cardIndex = 0;
    }

    const Card& dealCard()
    {
        return m_deck[m_cardIndex++];
    }
};

char getPlayerChoice()
{
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice;
    do
    {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}


bool playBlackjack()
{
    Deck deck;
    int playerTotal = 0;
    int dealerTotal = 0;

    deck.shuffleDeck();

    // Deal the player one card
    dealerTotal += deck.dealCard().getCardValue();
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    // Deal the player two cards
    playerTotal += deck.dealCard().getCardValue();
    playerTotal += deck.dealCard().getCardValue();

    // Player goes first
    while (1)
    {
        std::cout << "You have: " << playerTotal << '\n';
        char choice = getPlayerChoice();
        if (choice == 's')
            break;

        playerTotal += deck.dealCard().getCardValue();

        // See if the player busted
        if (playerTotal > 21)
            return false;
    }

    // If player hasn't busted, dealer goes until he has at least 17 points
    while (dealerTotal < 17)
    {
        dealerTotal += deck.dealCard().getCardValue();
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // If dealer busted, player wins
    if (dealerTotal > 21)
        return true;

    return (playerTotal > dealerTotal);
}


int main()
{
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
    rand(); // If using Visual Studio, discard first random value

    Deck deck;
    if (playBlackjack())
        std::cout << "You win!\n";
    else
        std::cout << "You lose!\n";


    return 0;
}