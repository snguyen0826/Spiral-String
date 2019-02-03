#include <iostream>
#include <cmath>
#include <string>
#include "ArgumentManager.h"
using namespace std;

int getSquareSide (string &str)
{
    int stringLength = str.size();
    if ( sqrt(stringLength) - (int)sqrt(stringLength) > 0)
        return (int)sqrt(stringLength) + 1;
    return (int)sqrt(stringLength);
}

void printSpiral(string &inputString, int &squareSide)
{
    //Allocate Space for Square
    char** square = new char*[squareSide];
    for (int i = 0; i < squareSide; i++)
        square[i] = new char[squareSide];

    //Store String the Square
    int strIndex = 0;
    for (int x = 0; x < squareSide; x++){
        for (int y = 0; y < squareSide; y++) {
            square[x][y] = inputString[strIndex];
            strIndex++;
        }
    }

    //Print Spiral
    strIndex = 0;
    int c1 = 0, c2 = squareSide - 1, r1 = 0, r2 = squareSide - 1;

    while (strIndex < inputString.size())
    {
        for(int i=c1;i<=c2;i++)
            square[r1][i] = inputString[strIndex++];

        for(int j=r1+1;j<=r2;j++)
            square[j][c2] = inputString[strIndex++];

        for(int i=c2-1;i>=c1;i--)
            square[r2][i] = inputString[strIndex++];

        for(int j=r2-1;j>=r1+1;j--)
            square[j][c1] = inputString[strIndex++];

        c1++, c2--, r1++, r2--;
    }

    for (int x = 0; x < squareSide; x++){
        for (int y = 0; y < squareSide; y++){
            cout << square[x][y] << " ";
        }
        cout << endl;
    }
}

int main() {
    //char** charSquare;
    string inputString = "Testing";
    int squareSide = getSquareSide(inputString);
    int numPeriods = squareSide*squareSide - inputString.size();

    //Add periods if needed to fill up the square
    for (int i = 0; i < numPeriods; i++)
        inputString += '.';

    //Print result
    printSpiral(inputString, squareSide);
    return 0;
}

