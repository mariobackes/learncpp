#pragma once
#ifndef HI_LO_H
#define HI_LO_H

const int g_lo(0);
const int g_hi(100);
const int g_triesPerRun(10);

int getRandomNumber(int min, int max);

void playHiLo();

int getUserInput();

bool playAgain();

#endif // !HI_LO_H