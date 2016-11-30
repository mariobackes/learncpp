#include "stdafx.h"
#include <iostream>

int getGravity()
{
    using namespace std;
    cout << "Please choose which Plant/Moon gravity you want to simulate.\n" << endl;
    cout << "e = earth | j = jupiter | m = mars | o = moon | p = pluto\n" << endl;
    char planet;
    cin >> planet;
    int retVal;
    switch (planet)
    {
        case 'e': retVal = planet_id::k_earth_id;
        break;
        case 'j': retVal = planet_id::k_jupiter_id;
        break;
        case 'm': retVal = planet_id::k_mars_id;
        break;
        case 'o': retVal = planet_id::k_moon_id;
        break;
        case 'p': retVal = planet_id::k_pluto_id;
        break;
        default: cout << "An error occured. Did you enter a character that is not listed?\n";
            retVal = error_ids::general_error;
        break;
    }
    return retVal;
}

int getIntervall()
{
    using namespace std;
    cout << "Please select how long the interval between each update of the location of the ball is.\n";
    cout << " 1 = every 1s | 2 = every 2s | 3 = every 5s | 4 = every 0.5s | 5 = every 0.25s \n";
    int id;
    cin >> id;
    switch (id)
    {
    case 1: 
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    default: cout << "An error occured. Reporting error to main. Did you enter a valid input?";
        id = error_ids::general_error;
        break;
    }
    return id;
}

int getTowerHeight()
{
    using namespace std;
    cout << "Please select which height the simulated tower should have (in metres).\n";
    cout << "Do not enter a negative value or a value higher than 60,000\n";
    int height;
    cin >> height;
    // Need to remove magic number here
    if (height > 60000)
    {                                       // here too
        cout << "ERROR: Heights higher than 60000 metres are not supported.\n";
        cout << "Reporting error to main.\n";
        height = error_ids::value_out_of_reach;
    }
    else if (height <= 0)
    {
        cout << "ERROR: Height can not be zero or negative.";
        cout << "Reporting error to main.\n";
        height = error_ids::value_out_of_reach;
    }
    else
    {
        return height;
    }
    return height;
}

double calculateHeightOfBall(double towerHeight, int planetID, double secondsPassed)
{
    double heightOfBall;
    double gravityConstant;

    switch (planetID)
    {
    case planet_id::k_earth_id: gravityConstant = myConstants::k_gravity_earth;
        break;
    case planet_id::k_jupiter_id: gravityConstant = myConstants::k_gravity_jupiter;
        break;
    case planet_id::k_mars_id: gravityConstant = myConstants::k_gravity_mars;
        break;
    case planet_id::k_moon_id: gravityConstant = myConstants::k_gravity_moon;
        break;
    case planet_id::k_pluto_id: gravityConstant = myConstants::k_gravity_pluto;
        break;
    default: std::cout << "Can not identify planetID. Reporting error to main.\n";
        return error_ids::no_identifier;
        break;
    }


    heightOfBall = towerHeight - (gravityConstant * (secondsPassed * secondsPassed) / 2);
    return heightOfBall;
}

void printHeightOfBall(double height, double secondsPassed)
{
    using namespace std;
    if (height <= 0)
    {
        cout << "At " << secondsPassed << " seconds, the ball is on the ground.\n";
    }
    else
    {
        cout << "At " << secondsPassed << " seconds, the ball is at height: " << height << " metres.\n";
    }

}

// This function will call printHeightOfBall() and calculateHeightOfBall.
// That is why it needs all these parameters.
int forLoop(int intervallID, int planetID, double towerHeight)
{
    double heightOfBall = towerHeight;
    switch (intervallID)
    {
    case 1: for (double secondsPassed = 0; heightOfBall > 0; secondsPassed += 1)
    {
        heightOfBall = calculateHeightOfBall(towerHeight, planetID, secondsPassed);
        printHeightOfBall(heightOfBall, secondsPassed);
    }
        break;
    case 2: for (double secondsPassed = 0; heightOfBall > 0; secondsPassed += 2)
    {
        heightOfBall = calculateHeightOfBall(towerHeight, planetID, secondsPassed);
        printHeightOfBall(heightOfBall, secondsPassed);
    }
        break;
    case 3: for (double secondsPassed = 0; heightOfBall > 0; secondsPassed += 5)
    {
        heightOfBall = calculateHeightOfBall(towerHeight, planetID, secondsPassed);
        printHeightOfBall(heightOfBall, secondsPassed);
    }
            break;
    case 4: for (double secondsPassed = 0; heightOfBall > 0; secondsPassed += 0.5)
    {
        heightOfBall = calculateHeightOfBall(towerHeight, planetID, secondsPassed);
        printHeightOfBall(heightOfBall, secondsPassed);
    }
            break;
    case 5: for (double secondsPassed = 0; heightOfBall > 0; secondsPassed += 0.25)
    {
        heightOfBall = calculateHeightOfBall(towerHeight, planetID, secondsPassed);
        printHeightOfBall(heightOfBall, secondsPassed);
    }
            break;
    default: std::cout << "Something went terribly wrong. inervallID seems to be wrong. Reporting to main.\n";
        return error_ids::general_error;
        break;
    }
    return 0;
}