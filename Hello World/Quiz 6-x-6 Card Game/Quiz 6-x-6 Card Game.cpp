// Quiz 6-x-6 Card Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Prints the value of a card. Format example: Queen of spades would be "QS". No whitespace is provided.
void printCard(const Card& card)
{
    switch (card.rank)
    {
    case RANK_TWO:      std::cout << "2";
        break;                              // Indent the content of a case statement?
    case RANK_THREE:    std::cout << "3";
        break;
    case RANK_FOUR:     std::cout << "4";
        break;
    case RANK_FIVE:     std::cout << "5";
        break;
    case RANK_SIX:      std::cout << "6";
        break;
    case RANK_SEVEN:    std::cout << "7";
        break;
    case RANK_EIGHT:    std::cout << "8";
        break;
    case RANK_NINE:     std::cout << "9";
        break;
    case RANK_TEN:      std::cout << "T";
        break;
    case RANK_JACK:     std::cout << "J";
        break;
    case RANK_QUEEN:    std::cout << "Q";
        break;
    case RANK_KING:     std::cout << "K";
        break;
    case RANK_ACE:      std::cout << "A";
        break;
    default: std::cout << "UNEXPECTED ERROR: card.rank was invalid. Exiting now." << std::endl; // TODO: Add an exit code here and have the caller decide what to do.
        exit(1);                // A better solution might be to return an error code here, that an invalid card rank was passed. 
        break;                  // Then the caller can for example reexecute this function.
    }

    // You can compare case with contents indented vs case with contents not indented here.

    switch (card.suit)
    {
    case SUIT_CLUB:     std::cout << "C";
    break;
    case SUIT_DIAMOND:  std::cout << "D";
    break;
    case SUIT_HEART:    std::cout << "H";
    break;
    case SUIT_SPADE:    std::cout << "S";
    break;
    default: std::cout << "UNEXPECTED ERROR: card.suit was invalid. Exiting now." << std::endl;
    exit(1);
    // TODO: Add an exit code here and have the caller decide what to do.
    // Won't fix, this should be possible to happen in the first place.
    break;
    }
}

// Prints every card in the passed array, seperated by a single space.
void printDeck(const std::array<Card, g_deckSize>& deck)
{
    for ( const Card card : deck)   // Is it good practice to always use auto as type in for-each loops?
    {
        printCard(card);
        std::cout << " ";
    }
}

// Swaps values of two cards.
void swapCard(Card& x, Card& y)
{

    /*
    Card temp;
    temp.rank = x.rank;
    temp.suit = x.suit;
    x.rank = y.rank;
    x.suit = y.suit;
    y.rank = temp.rank;
    y.suit = temp.suit;
    */

    Card temp = x;
    x = y;
    y = temp;
}

// TODO change Visual Studio for each loop snippet - done

// Puts the array that contains the deck of cards in a random order. Expects srand() and rand() to been called before.
void shuffleDeck(std::array<Card, g_deckSize>& deck)
{
	std::cout << "Shuffling deck";
  for (int i = 0; i < 6; ++i)
  {
      Sleep(250);   // 'Animation'
      std::cout << ".";
  }
  std::cout << std::endl;
  unsigned int random;
  for(int i = 0; i < g_deckSize; ++i)
  {
      // Pick a number between 1 and 52.
      random = (rand() % 52);
      swapCard(deck[random], deck[i]);
      i++;
  }
}

// returns the rank of the passed card as an integer. Jack, Queen and King are worth 10, an ace is worth 11.
int getCardValue(Card card)
{
    int retVal;
    switch (card.rank)
    {
    case RANK_TWO:      retVal = 2;
        break;
    case RANK_THREE:    retVal = 3;
        break;
    case RANK_FOUR:     retVal = 4;
        break;
    case RANK_FIVE:     retVal = 5;
        break;
    case RANK_SIX:      retVal = 6;
        break;
    case RANK_SEVEN:    retVal = 7;
        break;
    case RANK_EIGHT:    retVal = 8;
        break;
    case RANK_NINE:     retVal = 9;
        break;
    case RANK_TEN:      // Intended fall-throughs
    case RANK_JACK:
    case RANK_QUEEN:
    case RANK_KING:     retVal = 10;
        break;
    case RANK_ACE:      retVal = 11;
        break;
    default: std::cout << "UNEXPECTED ERROR: Card value could not be found. Exiting now." << std::endl;
        exit(1);
    break;
    }
    return retVal;
}

// Returns true if the player entered hit.
bool hitOrStand()
{
    while (true)
    {
        std::cout << "Do you want to [h]it or [s]tand?" << std::endl;
        char input;
        std::cin >> input;
        if (std::cin.fail())    // In case the user enters invalid input.
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Invalid input, try again. (cin.fail returned true)" << std::endl;
        }
        else if (input == 'h' || input == 'H')
        {
            return true;        // Loopexit
        }
        else if (input == 's' || input == 'S')
        {
            return false;       // Loopexit
        }
        else
        {
            std::cout << "Invalid input, try again." << std::endl;
        }
    }
}

// Returns true if the player won.
Result playBlackjack(std::array<Card, g_deckSize>& deck)
{
    Card* cardPtr = &deck[0];       // cardPtr points to the first card in the deck.
    
    // Scores:
    int playerScore = 0;            // Win counts
    int dealerScore = 0;

    int playerAceCounter = 0;       // These counters are there to see if an ace should be evaluated as 1 or 11.
    int dealerAceCounter = 0;


    // Dealers turn
    std::cout << "The dealer drew ";    
    if (cardPtr->rank == RANK_ACE)              // Check if the card that the dealer is about to draw is an ace
    {
        ++dealerAceCounter;                     // If yes increment the ace counter.
    }
    printCard(*cardPtr);                        // Tell the user what he drew.
    std::cout << std::endl;                     // Formatting
    dealerScore += getCardValue(*cardPtr++);    // Add the value of the first card in the deck to the account of the dealer and move the pointer to the next card.
    std::cout << "His score is now:" << dealerScore << std::endl << std::endl;      // Tell the user his current score.


    // Users turn
    std::cout << "You draw ";       // User draws a card.
    printCard(*cardPtr);
    std::cout << std::endl;
    if (cardPtr->rank == RANK_ACE)  // Ace check.
    {
        ++playerAceCounter;
    }
    playerScore += getCardValue(*cardPtr++);        // User draws another card.
    std::cout << "You draw ";
    printCard(*cardPtr);
    std::cout << std::endl;
    if (cardPtr->rank == RANK_ACE)                  // Ace check again.
    {
        ++playerAceCounter;                         // TODO: Make the ace check a function.
    }                                               // Having the same code mutiple times is very bad practice.
    playerScore += getCardValue(*cardPtr++);
    std::cout << "Your score is now " << playerScore << std::endl << std::endl;

    while (hitOrStand())                            // If the used hits, he draws another card.
    {
        std::cout << "You draw ";
        printCard(*cardPtr);
        std::cout << std::endl;
        if (cardPtr->rank == RANK_ACE)              // Ace check.
        {
            ++playerAceCounter;
        }
        playerScore += getCardValue(*cardPtr++);    // The player draws an additional card if he hits.
        std::cout << "Your score is now " << playerScore << std::endl << std::endl;
        if (playerScore > 21)
        {                                           
            if (playerAceCounter == 0)
            {   // If the player has more than 21 points, he loses instantly.
                std::cout << "Bust: You have more than 21 points and therefore you lose." << std::endl;
                return Result::LOSE;
            }
            else
            {
                playerScore -= 10;
                --playerAceCounter;
            }
        }
    }

    while (dealerScore < 17)
    {                   // The dealer draws cards until he has 17 points or more.
        std::cout << "The dealer drew ";
        printCard(*cardPtr);
        std::cout << std::endl;
        if (cardPtr->rank == RANK_ACE)
        {
            ++dealerAceCounter;
        }
        dealerScore += getCardValue(*cardPtr++);
        std::cout << "His score is now:" << dealerScore << std::endl << std::endl;
        if (dealerScore > 21)
        {               
            if (dealerAceCounter == 0)
            {   // If the dealer has more than 21 points, he loses instantly.
                std::cout << "Bust: The dealer has more than 21 Points. You win." << std::endl;
                return Result::WIN;
            }
            else
            {
                dealerScore -= 10;
                dealerAceCounter--;
            }
        }
    }

    // This only happends if no player is above 21 points.
    if (playerScore > dealerScore)  
    {
        std::cout << "You have more points than the dealer. You win." << std::endl;
        return Result::WIN;
    }
    else if (playerScore < dealerScore)
    {
        std::cout << "The dealer has more points than you. You lose." << std::endl;
        return Result::LOSE;
    }
    else
    {
        std::cout << "You and the dealer have the same amount of points. It's a tie." << std::endl;
        return Result::TIE;
    }
}

// Returns true if the user wants to play again. Clears screen before returning.
bool playAgain()
{
    std::cout << "Do you want to play again?" << std::endl;
    std::cout << "[Y]es or [N]o?" << std::endl;
    char input;
    std::cin >> input;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Invalid input, try again. (cin.fail)" << std::endl;
    }
    if (input == 'y' || input == 'Y')
    {
        system("cls");      // Clear the screen after every game.
        return true;
    }
    else if (input == 'N' || input == 'n')
    {
        return false;
    }
}

int main()
{
    std::array<Card, g_deckSize> deck;              // Declare an array that represents the deck of cards.
    int count = 0;
    for (int rank = 0; rank < MAX_RANKS; ++rank)    // Initialize the deck of cards with one card each.
    {
        for (int suit = 0; suit < MAX_SUITS; ++suit)
        {
            deck[count].rank = static_cast<CardRank>(rank);
            deck[count].suit = static_cast<CardSuit>(suit);
            ++count;
        }
    }
    srand(static_cast<unsigned int>(time(0)));  // Seed rand() with the current time.
    rand();                                     // Discard rand() once, because of VS.

    // Win counts:
	  int userWinCount	   = 0;
	  int computerWinCount = 0;
    int tieCount         = 0;

    do      // while (playAgain())
    {
        
            shuffleDeck(deck);
			      Result result;
            result = playBlackjack(deck);
            if (result == Result::LOSE)
            {
                ++computerWinCount;
            }
            else if (result == Result::WIN)
            {
                ++userWinCount;
            }
            else if (result == Result::TIE)
            {
                ++tieCount;
            }
            else        // This should never happen.
            {
                std::cout << "ERROR: Could not determine who won. Exiting now." << std::endl;
                exit(1);
            }
            // Print who won how many games.
            std::cout << "Won: " << userWinCount << " Lost: " << computerWinCount << " Tied: " << tieCount << std::endl;
    } while (playAgain());


    // This piece of code was for the previous task.

    //std::cout << "Sorted deck: " << std::endl;
    //printDeck(deck);    // Prints every card with a space between each card.
    //std::cout << std::endl;
    //srand(time(0));     // Set the seed for the RNG to the current time.
    //rand();             // Discard rand() once, because of VS.
    //shuffleDeck(deck);
    //std::cout << "Shuffled deck: " << std::endl;
    //printDeck(deck);
    //std::cout << std::endl;

    return 0;
}

