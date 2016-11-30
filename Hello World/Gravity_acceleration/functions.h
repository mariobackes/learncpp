#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int getTowerHeight();
int getGravity();
int getIntervall();
void printHeightOfBall(double height, double secondsPassed);
double calculateHeightOfBall(double towerHeight, int planetID, double secondsPassed);
int forLoop(int intervallID, int planetID, double towerHeight);

#endif // !FUNCTIONS_H