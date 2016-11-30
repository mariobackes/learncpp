// Quiz_4_7_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


void printMoneyMadeToday(Advertising ads)
{
    using namespace std;
    cout << "Today " << ads.adsShown <<             " ads were shown to users." << endl;
    cout << "Today " << ads.percentageClickedAds << " percent of ads were clicked." << endl;
    cout << "Today " << ads.moneyPerAdClick <<      " money was earned for every ad that was clicked." << endl << endl;
    double moneyEarnedToday;
    moneyEarnedToday = ads.adsShown * ads.moneyPerAdClick * (ads.percentageClickedAds / 100);
    std::cout << "Today you earned this amount of money: " << moneyEarnedToday << std::endl;
}

int main()
{
    using namespace std;
    cout << "Enter the amount of ads shown to users, today: " << endl;
    Advertising ads;
    cin >> ads.adsShown;
    cout << "Enter the percentage of users that clicked on an ad, today: " << endl;
    cin >> ads.percentageClickedAds;
    if (ads.percentageClickedAds > 100 || ads.percentageClickedAds < 0)
    {
        std::cout << "ERROR: You entered a value that is not between 0 and 100. Exiting now." << std::endl;
        return 1;
    }
    cout << "Enter the amount of money that you received for every clicked ad, today: " << endl;
    cin >> ads.moneyPerAdClick;
    printMoneyMadeToday(ads);

    return 0;
}

