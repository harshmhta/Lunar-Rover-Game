#pragma once
//#include "conio.h"			// This probably won't work in Cloud9, you'll have to clear screen another way
#include "LunarSurface.h"	// LunarSurface specification file

class LunarRover
{
public:
	LunarRover(LunarSurface *inBoard);			// Constructor - need a valid LunarSurface pointer
	~LunarRover();								// Destructor - might not need to do anything here

public:
	void drawGrid();							// Draw the board
	bool land(int row, int col);				// Initial landing of the rover
	int	 move(char direction);			// Move the rover and return outcome
	
	void n();									//temp
	
	int getPositionX();
	int getPositionY();							// Get current position of the rover on the board X=Rows Y=COL
	void setPosition(int newrow, int newcol);	// Update the rover position without outcome
	
	char getTempSurface(int row, int col);
	void setTempSurface(int row, int col);
	
	int	 getDamage();							// Get the rover's damage status
	void setDamage(int newdmg);					// Set the rover's damage status
	
	bool play();
	
	int	 getFuel();								// Get the rover's fuel status
	void setFuel(int newfuel);					// Set the rover's fuel status

private:
	LunarSurface *gameBoard;					// A pointer to a valid game board (LunarSurface class)
	int rowPOS, colPOS;							// The rover's position on the game board
	int fuel;									// Rover's fuel level (start at 100)
	int damage;									// Rover's damage level (start at 0)
	char surface;
};