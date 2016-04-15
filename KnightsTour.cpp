//===================================================================================
// Project     : KnightsTourProject.cpp
// Description : Program mimics the movement of the knight on a chessboard
// Company     : Cal Poly Pomona
// Course      : ECE 304
// Name		   : David Moreno and Kim Nibungco
//===================================================================================
#include "stdafx.h"
#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

#define width 8
#define height 8

using namespace std;

//===================================================================================
// Name         : Knights Tour
// Description  : This program will allow a Knight to move to every space on a 
//					chessboard once and only once.
// Parameters   : Chessboard 8X8 Standard Size
// Global Data  : N = 8, height and width of chessboard
// Return Value : <None>
//===================================================================================

//===================================================================================
// FUNCTIONS
//===================================================================================

void KnightsTour()
{
	int cb [width][height];			//matrix for chessboard 8 X 8
	int i, j;						//position of the knight
	
	for (int x = 0; x < width; x++)			//for loop to fill the 8 X 8 with 0's
	{
		for (int y = 0; y < height; y++)
		{
			cb [x] [y] = 0;
		}
	}
	
	int KTMOV1[width] = { -2, -1, 1, 2, -2, -1, 1, 2 };
	int KTMOV2[height] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	
	for (int x = 0; x < width; x++)			//print out the chessboard matrix
	{
		for (int y = 0; y < height; y++)
		{
			cout << cb [x][y] << "\t";
		}
		
		cout << "\n";
	}

}

//===================================================================================
//MAIN
//===================================================================================

int main() {
	
	KnightsTour();		//Call the KnightsTour Function
	cout << endl;
	return 0;
}
