#define _WIN32_WINNT 0x0500
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include"myconsole.h"
#include"mygraphics.h"
#include<ctime>
#include<cstdlib>

using namespace std;


const int pathRow[52] = { 6, 6, 6, 6, 6,   5, 4, 3, 2, 1, 0,   0,   0, 1, 2, 3, 4, 5,
6, 6, 6, 6, 6, 6,   7,   8, 8, 8, 8, 8, 8,   9, 10, 11, 12, 13, 14,
14,   14, 13, 12, 11, 10, 9,   8, 8, 8, 8, 8, 8,   7,   6 };

const int pathCol[52] = { 1, 2, 3, 4, 5,   6, 6, 6, 6, 6, 6,   7,   8, 8, 8, 8, 8, 8,
9, 10, 11, 12, 13, 14,   14,   14, 13, 12, 11, 10, 9,   8, 8, 8, 8, 8, 8,
7,   6, 6, 6, 6, 6, 6,   5, 4, 3, 2, 1, 0,   0,   0 };

// players : 0 = red, 1 = green, 2 = yellow, 3 = blue  (clockwise)
const int startIndex[4] = { 0, 13, 26, 39 };	// where each colour enters the path array

const int yardRow[4][4] = { { 1, 1, 4, 4 },{ 1, 1, 4, 4 },{ 10, 10, 13, 13 },{ 10, 10, 13, 13 } };
const int yardCol[4][4] = { { 1, 4, 1, 4 },{ 10, 13, 10, 13 },{ 10, 13, 10, 13 },{ 1, 4, 1, 4 } };

// position of every token:  -1 = in yard, 0 to 50 = on the path,
// 51 to 55 = inside own home lane, 56 = reached the centre (home)
int pos[4][4];

int yellow()
{
	return RGB(255, 215, 0);

}
int red()
{
	return RGB(220, 40, 40);
}
int green()
{
	return RGB(40, 170, 70);
}
int blue()
{
	return RGB(40, 90, 210);
}
int black()
{
	return RGB(0, 0, 0);
}
int white()
{
	return RGB(255, 255, 255);
}
int cyan()
{
	return RGB(0, 255, 255);
}
int purple()
{
	return RGB(128, 0, 128);
}
int grey()
{
	return RGB(60, 60, 60);
}

int playerColour(int p)
{
	if (p == 0)
		return red();
	else if (p == 1)
		return green();
	else if (p == 2)
		return yellow();
	else
		return blue();
}


void dice_1()//dice  for 1
{

	myRect(1020, 480, 1150, 610, black(), white());
	myEllipse(1060, 520, 1110, 570, black(), red());
}
void dice_5() // dice  for 5 also use  for base
{
	myRect(1020, 480, 1150, 610, black(), white());
	myEllipse(1070, 530, 1100, 560, black(), red());//CENTER



	myEllipse(1110, 560, 1140, 590, black(), red());//right DOWN  
	myEllipse(1110, 490, 1140, 520, black(), red());//right UP


	myEllipse(1030, 490, 1060, 520, black(), red());//left up
	myEllipse(1030, 560, 1060, 590, black(), red());// left  down
}
void dice_6()// dice  for 6 also use  for base
{
	myRect(1020, 480, 1150, 610, black(), white());
	myEllipse(1110, 530, 1140, 560, black(), red());//CENTER right
	myEllipse(1030, 530, 1060, 560, black(), red());//CENTER left



	myEllipse(1110, 570, 1140, 600, black(), red());//right DOWN  
	myEllipse(1110, 485, 1140, 515, black(), red());//right UP


	myEllipse(1030, 485, 1060, 515, black(), red());//left up
	myEllipse(1030, 570, 1060, 600, black(), red());// left  down
}
void dice_3()//dice  for 3
{
	myRect(1020, 480, 1150, 610, black(), white()); //base rectangle



	myEllipse(1110, 490, 1140, 520, black(), red());//right UP
	myEllipse(1070, 530, 1100, 560, black(), red());//CENTER
	myEllipse(1030, 560, 1060, 590, black(), red());// left  down
}
void dice_4()//FOR 4
{
	myRect(1020, 480, 1150, 610, black(), white());//BASE  RECTANGLE

	myEllipse(1110, 560, 1140, 590, black(), red());//right DOWN  
	myEllipse(1110, 490, 1140, 520, black(), red());//right UP

	myEllipse(1030, 490, 1060, 520, black(), red());//left up
	myEllipse(1030, 560, 1060, 590, black(), red());// left  down
}
void dice_2()//FOR  2
{
	myRect(1020, 480, 1150, 610, black(), white());//BASE  RECTANGLE
	myEllipse(1030, 490, 1060, 520, black(), red());//left up
	myEllipse(1110, 560, 1140, 590, black(), red());//right DOWN

}

// draws the face of the dice for the given number (0 = nothing rolled yet)
void drawDice(int number)
{
	if (number == 1)
	{
		dice_1();
	}
	else if (number == 2)
	{
		dice_2();
	}
	else if (number == 3)
	{
		dice_3();
	}
	else if (number == 4)
	{
		dice_4();
	}
	else if (number == 5)
	{
		dice_5();
	}
	else if (number == 6)
	{
		dice_6();
	}
}

void roll_text()
{

	char arr2[] = "press d to  roll";
	myDrawTextWithFont(380, 725, 56, arr2, white(), red());


}

void choose_text()
{

	char arr2[] = "choose token 1-4";
	myDrawTextWithFont(380, 725, 56, arr2, white(), red());


}

void exit_text()
{
	char arr2[] = "press esc to exit";
	myDrawTextWithFont(380, 725, 56, arr2, white(), red());
}

void esc_text()
{
	char arr2[] = "ESC = exit game";
	myDrawText(985, 650, 20, arr2, black(), white());
}

void turn_text(int p)
{
	char r[] = "RED    turn";
	char g[] = "GREEN  turn";
	char y[] = "YELLOW turn";
	char b[] = "BLUE   turn";

	if (p == 0)
		myDrawText(985, 150, 20, r, white(), red());
	else if (p == 1)
		myDrawText(985, 150, 20, g, white(), green());
	else if (p == 2)
		myDrawText(985, 150, 20, y, black(), yellow());
	else
		myDrawText(985, 150, 20, b, white(), blue());
}

void winner_text(int p)
{
	char r[] = "RED    WINS";
	char g[] = "GREEN  WINS";
	char y[] = "YELLOW WINS";
	char b[] = "BLUE   WINS";

	if (p == 0)
		myDrawText(985, 200, 20, r, white(), red());
	else if (p == 1)
		myDrawText(985, 200, 20, g, white(), green());
	else if (p == 2)
		myDrawText(985, 200, 20, y, black(), yellow());
	else
		myDrawText(985, 200, 20, b, white(), blue());
}




const int  N = 15;
const int RED = 1, GREEN = 2, BLUE = 3, YELLOW = 4, CENTER = 6, PATH = 0, YARD = 5;



void grid(int board[][N])
{

	for (int r = 0;r < N;r++)
	{
		for (int c = 0;c < N;c++)
		{
			if (r <= 5 && c <= 5)
			{
				board[r][c] = RED;
			}
			else if (r <= 5 && c >= 9)
			{
				board[r][c] = GREEN;
			}
			else if (r >= 9 && c <= 5)
			{
				board[r][c] = BLUE;
			}
			else if (r >= 9 && c >= 9)
			{
				board[r][c] = YELLOW;
			}
			else if
				(r >= 6 && r <= 8 && c >= 6 && c <= 8)
			{
				board[r][c] = CENTER;
			}
			else
			{

				board[r][c] = PATH;
			}
		}
	}


	for (int r = 1;r <= 4;r++)//smaller white box in  main colour box
	{
		for (int c = 1;c <= 4;c++)
		{
			board[r][c] = YARD;
			board[r][c + 9] = YARD;
			board[r + 9][c] = YARD;
			board[r + 9][c + 9] = YARD;

		}

	}

	for (int i = 1;i <= YARD;i++)
	{
		board[7][i] = RED;
		board[i][7] = GREEN;
		board[7][N - i - 1] = YELLOW;
		board[N - 1 - i][7] = BLUE;

	}

	//exxtra pos points 
	board[6][1] = RED;
	board[1][8] = GREEN;
	board[8][13] = YELLOW;
	board[13][6] = BLUE;

}
const int CELL = 40; // size of one square in pixels
// Chooses the fill colour for each type of square
int colourOf(int type)
{
	switch (type) {
	case RED: return red();
	case GREEN: return green();
	case YELLOW: return yellow();
	case BLUE: return blue();
	case CENTER: return grey();
	default: return white(); // PATH and YARD
	}
}
// Draws ONE square. (left, top) is where the board starts on the screen.
void drawCell(const int board[][N], int r, int c, int left, int top) {
	int x = left + c * CELL; // column -> x (across)
	int y = top + r * CELL; // row -> y (down)
	myRect(x, y, x + CELL, y + CELL, black(), colourOf(board[r][c]));
}
// Draws the whole board: one square at a time
void drawBoard(const int board[][N], int left, int top) {
	for (int r = 0; r < N; r++)
		for (int c = 0; c < N; c++)
			drawCell(board, r, c, left, top);
}

void Second_board()//second right side board now used for dice and also used to show menu ranking rules and more
{

	myRect(975, 128, 1200, 720, black(), white()); //  MAINN BOARD FOR SCCORE OF DICE

}
// Draws a round token inside square (r, c)
void drawToken(int r, int c, int left, int top, int colour) {
	int x = left + c * CELL;
	int y = top + r * CELL;
	myEllipse(x + 7, y + 7, x + CELL - 7, y + CELL - 7,
		black(), colour);
}

// row of token t of player p on the board
int tokenRow(int p, int t)
{
	int s = pos[p][t];
	int k = s - 50;		// step inside the home lane

	if (s == -1)
		return yardRow[p][t];
	else if (s <= 50)
		return pathRow[(startIndex[p] + s) % 52];
	else if (p == 0 || p == 2)
		return 7;
	else if (p == 1)
		return k;
	else
		return 14 - k;
}

// column of token t of player p on the board
int tokenCol(int p, int t)
{
	int s = pos[p][t];
	int k = s - 50;

	if (s == -1)
		return yardCol[p][t];
	else if (s <= 50)
		return pathCol[(startIndex[p] + s) % 52];
	else if (p == 0)
		return k;
	else if (p == 2)
		return 14 - k;
	else
		return 7;
}

void InitialiseTokensPositions()
{
	for (int p = 0;p < 4;p++)
	{
		for (int t = 0;t < 4;t++)
		{
			pos[p][t] = -1;
		}
	}
}

// safe squares : the 4 starting squares and the square 8 steps after each of them
bool isSafe(int index)
{
	if (index % 13 == 0 || index % 13 == 8)
		return true;
	return false;
}

// draws all 16 tokens with their number (1-4) written on them
void drawAllTokens(int left, int top)
{
	for (int p = 0;p < 4;p++)
	{
		for (int t = 0;t < 4;t++)
		{
			int r = tokenRow(p, t);
			int c = tokenCol(p, t);
			char num[2];
			num[0] = '1' + t;
			num[1] = '\0';

			drawToken(r, c, left, top, playerColour(p));
			myDrawText(left + c * CELL + 14, top + r * CELL + 11, 14, num, white(), playerColour(p));
		}
	}
}

// repaints the board, the safe squares and every token
void redraw(int board[][N], int left, int top)
{
	drawBoard(board, left, top);

	for (int i = 0;i < 52;i++)
	{
		if (i % 13 == 8)
		{
			int x = left + pathCol[i] * CELL;
			int y = top + pathRow[i] * CELL;
			myEllipse(x + 15, y + 15, x + CELL - 15, y + CELL - 15, black(), black());
		}
	}

	drawAllTokens(left, top);
}

// repaints EVERYTHING on the screen (board, title, side board, turn, dice, messages)
// message : 1 = press d to roll,  2 = choose token,  3 = game over
void drawScreen(int board[][N], int left, int top, int player, int diceNumber, int message)
{
	char title[] = "LUDO";

	redraw(board, left, top);
	myDrawText(left, top - 30, 20, title, white(), black());
	Second_board();
	turn_text(player);
	drawDice(diceNumber);
	esc_text();

	if (message == 1)
		roll_text();
	else if (message == 2)
		choose_text();
	else
	{
		winner_text(player);
		exit_text();
	}
}

// can token t of player p move with this dice number
bool canMove(int p, int t, int diceNumber)
{
	if (pos[p][t] == -1)
		return diceNumber == 6;		// only a 6 brings a token out of the yard
	if (pos[p][t] + diceNumber > 56)
		return false;				// exact number needed to reach home
	return true;
}

// waits for ONE key press .
// old key presses are thrown away first, and while waiting the whole screen is
// repainted every half second so it comes back if the window was minimised or covered
int getKey(int board[][N], int left, int top, int player, int diceNumber, int message)
{
	int count = 0;

	while (_kbhit())
		_getch();

	while (true)
	{
		if (_kbhit())
			return _getch();

		Sleep(200);
		count++;

		if (count % 10 == 0)
			drawScreen(board, left, top, player, diceNumber, message);
	}
}

// waits for d, returns the dice number (1 to 6), or 0 if escape was pressed
int rollDice(int board[][N], int left, int top, int player, int diceNumber)
{
	int key = 0;

	while (key != 'd' && key != 'D' && key != 27)
	{
		key = getKey(board, left, top, player, diceNumber, 1);
	}

	if (key == 27)
		return 0;

	return rand() % 6 + 1;
}

// waits for a token key (1-4) that can really move, returns 0 to 3, or -1 if escape was pressed
int chooseToken(int board[][N], int left, int top, int player, int diceNumber)
{
	int key = 0;

	while (true)
	{
		key = getKey(board, left, top, player, diceNumber, 2);

		if (key == 27)
			return -1;

		if (key >= '1' && key <= '4' && canMove(player, key - '1', diceNumber) == true)
			return key - '1';
	}
}

// sends opponent tokens back to their yard if they are on the same square
void capture(int p, int t)
{
	if (pos[p][t] < 0 || pos[p][t] > 50)
		return;

	int index = (startIndex[p] + pos[p][t]) % 52;

	if (isSafe(index) == true)
		return;

	for (int q = 0;q < 4;q++)
	{
		if (q != p)
		{
			for (int k = 0;k < 4;k++)
			{
				if (pos[q][k] >= 0 && pos[q][k] <= 50 && (startIndex[q] + pos[q][k]) % 52 == index)
				{
					pos[q][k] = -1;
				}
			}
		}
	}
}

void moveToken(int p, int t, int diceNumber)
{
	if (pos[p][t] == -1)
		pos[p][t] = 0;
	else
		pos[p][t] += diceNumber;

	capture(p, t);
}

bool hasWon(int p)
{
	for (int t = 0;t < 4;t++)
	{
		if (pos[p][t] != 56)
			return false;
	}
	return true;
}


int main()
{


	// 1. Maximize the console window, then give Windows a moment to finish
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	Sleep(500);
	// 2. Find the drawing area size and centre the board in it
	RECT area;
	GetClientRect(GetConsoleWindow(), &area);
	int left = (area.right - N * CELL) / 2;
	int top = (area.bottom - N * CELL) / 2;
	// 3. Build and draw the board
	int board[N][N];
	int player = 0;
	int diceNumber = 0;		// 0 = nothing rolled yet
	int message = 1;
	bool game = true;
	bool won = false;
	srand(time(0));
	grid(board);
	InitialiseTokensPositions();

	while (game == true)
	{
		message = 1;
		drawScreen(board, left, top, player, diceNumber, message);

		int roll = rollDice(board, left, top, player, diceNumber);

		if (roll == 0)		// escape pressed
		{
			game = false;
			break;
		}

		diceNumber = roll;
		drawScreen(board, left, top, player, diceNumber, message);

		int movable = 0, last = 0;
		for (int t = 0;t < 4;t++)
		{
			if (canMove(player, t, diceNumber) == true)
			{
				movable++;
				last = t;
			}
		}

		if (movable > 0)
		{
			int choice = last;	// only one possible token so no need to ask

			if (movable > 1)
			{
				message = 2;
				drawScreen(board, left, top, player, diceNumber, message);
				choice = chooseToken(board, left, top, player, diceNumber);

				if (choice == -1)		// escape pressed
				{
					game = false;
					break;
				}
			}

			moveToken(player, choice, diceNumber);

			if (hasWon(player) == true)
			{
				won = true;
				game = false;
				message = 3;
			}

			drawScreen(board, left, top, player, diceNumber, message);
		}
		else
		{
			Sleep(800);		// no move possible, let the player see the dice
		}

		if (game == true && diceNumber != 6)	// a 6 gives another turn
		{
			player = (player + 1) % 4;
		}
	}

	if (won == true)		// show the winner until escape is pressed
	{
		int key = 0;
		while (key != 27)
		{
			key = getKey(board, left, top, player, diceNumber, 3);
		}
	}

	return 0;
}

