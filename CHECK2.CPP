// checkers.cpp
// 
// Created: 13 Mar 2019
// Updated: 15 Mar 2019
//
// class Checkers

#include <conio.h> // console input output header file
#include <graphics.h>
#include <iostream.h>
#include <stdio.h> // for gets()

#include <stdlib.h> // for randomize()
#include <dos.h> // for delay()

class Checker
{
public:

	Checker(){
		_color = 'x';
		_x = -1;
		_y = -1;
		_isKing = 0;
		_radius = 0;
	}
	Checker(char color,int  x,int  y, int radius){
		_color = color;
		_x = x;
		_y = y;
		_isKing = 0;
		_radius = radius;
	}

	Checker(const Checker &other){
		_color = other.getColor();
		_x = other.getX();
		_y = other.getY();
		_radius = other.getRadius();
		_isKing = other.getIsKing();
	}

	int getRadius() const{
		return _radius;
	}

	int getIsKing() const{
		return _isKing;
	}

    char getColor() const{
	return _color;
    }

    void setColor(char color){
     _color = color;
    }
	int getX() const {
		return _x;
	}

	int getY() const {
		return _y;
	}

	void setX(int x) {
		_x = x;

	}

	void setY(int y) {
		_y = y;
	}

	void crownKing() {
		_isKing = 1;
	}

	void setRadius(int radius){
		_radius = radius;
	}

    //draws red and black checkers but not x checkers
	void draw(){
		if (_color == 'r'){
			setfillstyle(SOLID_FILL, RED);
			setcolor(RED);
			circle(_x, _y, _radius);
			floodfill(_x, _y, RED); //////////////////////////////////////turned off for debugging
			setcolor(WHITE); //////////////// probably don't need
		}
		else if (_color == 'b'){
			setcolor(WHITE);
			circle(_x, _y, _radius);
		}
		else if (_color == 'x'){
			setcolor(WHITE);
		}
	}

private:

	char _color;
	int _isKing;
	int _x;
	int _y;
	int _radius;

};



void swapCheckers(Checker &checker1, Checker &checker2){
	//Checker temp = checker1;
	//checker1 = checker2;
//	checker2 = temp;
    //int x = checker1.getX();
    //int y = checker1.getY();
   // checker1.setX(checker2.getX());
    //checker1.setY(checker2.getY());
   // checker2.setX(x);
   // checker2.setY(y);
   char color = checker1.getColor();
   checker1.setColor(checker2.getColor());
   checker2.setColor(color);
}

void main()
{
Intro:
	randomize();
	clrscr();
/////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "c:\\TURBOC3\\BGI");
	int w = getmaxx() - 1;
	int h = getmaxy();
	int squareLen = w / 16;
	int boardSideLen = w / 2;
	int borderLen = (h - boardSideLen) / 2;

	

	Checker checkers[32];
	int x1 = w - boardSideLen + (squareLen/2);
	int y1 = h - borderLen - (squareLen/2) - 8;

	x1 = w - boardSideLen + squareLen + (squareLen/2);
	for (int xxx = 0; xxx < 4; xxx++){
		Checker chec0 = Checker('r', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[xxx] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + (squareLen/2);
	y1 = h - borderLen - (squareLen) - (squareLen/2) - 8;
	for (int t = 0; t < 4; t++){
		Checker chec0 = Checker('r', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[t+4] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + squareLen + (squareLen/2);
	y1 = h - borderLen - (2*squareLen) - (squareLen/2) - 8;
	for (int tt = 0; tt < 4; tt++){
		Checker chec0 = Checker('r', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[tt+8] = chec0;
		//chec0.draw();
	}

	x1 = w - boardSideLen + (squareLen/2);
	y1 = h - borderLen - (3*squareLen) - (squareLen/2) - 8;
	for (int as = 0; as < 4; as++){
		Checker chec0 = Checker('x', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[as+12] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + squareLen + (squareLen/2);
	y1 = h - borderLen - (4*squareLen) - (squareLen/2) - 8;
	for (int sas = 0; sas < 4; sas++){
		Checker chec0 = Checker('x', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[sas+16] = chec0;
		//chec0.draw();
	}



	x1 = w - boardSideLen + (squareLen/2);
	y1 = h - borderLen - (5*squareLen) - (squareLen/2) - 8;
	for (int s = 0; s < 4; s++){
		Checker chec0 = Checker('b', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[s+20] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + squareLen + (squareLen/2);
	y1 = h - borderLen - (6*squareLen) - (squareLen/2) - 8;
	for (int ss = 0; ss < 4; ss++){
		Checker chec0 = Checker('b', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[ss+24] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + (squareLen/2);
	y1 = h - borderLen - (7*squareLen) - (squareLen/2) - 8;
	for (int sss = 0; sss < 4; sss++){
		Checker chec0 = Checker('b', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[sss+28] = chec0;
		//chec0.draw();
	}







///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////

	int X, Y, dir, Plr, Opp;
	int yolo = 0;
	int limit = 0;
	Checker Board[8][8];
	char PlrToken = '@';
	char OppToken = '!';
	char pos[2];
	int i, j;
    for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
            Checker ch = Checker();
			Board[i][j] = ch;
		}
	}
	

	cout << "Welcome to Checkers Game" << endl;

	cout << "The Player's token is " << PlrToken << endl;
	cout << "The Opponent's token is " << OppToken << endl;

	char *String[4] = { "THE", "GAME", "STARTS", "NOW!!!!" };
	for(i = 0; i < 4; i++)
	{
		cout << "\n\n" << "\t\t\t" << String[i] << " \n";
		delay(500);
	}
	delay(1000);

	Board[0][0] = checkers[28]; Board[0][2] = checkers[29];
	Board[0][4] = checkers[30]; Board[0][6] = checkers[31];
	Board[1][1] = checkers[24]; Board[1][3] = checkers[25];
	Board[1][5] = checkers[26]; Board[1][7] = checkers[27];
	Board[2][0] = checkers[20]; Board[2][2] = checkers[21];
	Board[2][4] = checkers[22]; Board[2][6] = checkers[23];

	Board[3][1] = checkers[16]; Board[3][3] = checkers[17];
	Board[3][5] = checkers[18]; Board[3][7] = checkers[19];
	Board[4][0] = checkers[12]; Board[4][2] = checkers[13];
	Board[4][4] = checkers[14]; Board[4][6] = checkers[15];

	Board[5][1] = checkers[8]; Board[5][3] = checkers[9];
	Board[5][5] = checkers[10]; Board[5][7] = checkers[11];
	Board[6][0] = checkers[4]; Board[6][2] = checkers[5];
	Board[6][4] = checkers[6]; Board[6][6] = checkers[7];
	Board[7][1] = checkers[0]; Board[7][3] = checkers[1];
	Board[7][5] = checkers[2]; Board[7][7] = checkers[3];


	// Your Turn
start:
	clrscr();
    //The edges of the board
	int boardEdge[] = { w - 7, borderLen,
		w - 7, borderLen + (8 * squareLen),
		w - (8 * squareLen) - 8, borderLen + (8 * squareLen),
		w - (8 * squareLen) - 8, borderLen,
		w - 7, borderLen };

	int p1 = w - boardSideLen;
	int p2 = borderLen;
	int p3 = borderLen + squareLen;
	int p4 = w - boardSideLen + squareLen;

	setfillstyle(SOLID_FILL, BLACK);
	fillpoly(5, boardEdge);
	setfillstyle(SOLID_FILL, WHITE);

	//Column A White Squares
	int tempP2 = p2 + squareLen;
	int tempP3 = p3 + squareLen;
	for (int iiii = 0; iiii < 4; iiii++) {
		int whiteSq[] = { p1, tempP2, p1, tempP3, p4, tempP3, p4, tempP2, p1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column B white squares
	int tempP1 = p1 + squareLen;
	int tempP4 = p4 + squareLen;
	tempP2 = p2;
	tempP3 = p3;
	for (int b = 0; b < 4; b++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}


	//Column C White Squares
	tempP1 = p1 + (2 * squareLen);
	tempP4 = p4 + (2 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int ii = 0; ii < 4; ii++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column D white squares
	tempP1 = p1 + (3 * squareLen);
	tempP4 = p4 + (3 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int bbb = 0; bbb < 4; bbb++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column E White Squares
	tempP1 = p1 + (4 * squareLen);
	tempP4 = p4 + (4 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int iii = 0; iii < 4; iii++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column F white squares
	tempP1 = p1 + (5 * squareLen);
	tempP4 = p4 + (5 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int xx = 0; xx < 4; xx++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column G White Squares
	tempP1 = p1 + (6 * squareLen);
	tempP4 = p4 + (6 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int x = 0; x < 4; x++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column H white squares
	tempP1 = p1 + (7 * squareLen);
	tempP4 = p4 + (7 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int bb = 0; bb < 4; bb++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}


    for (int q = 0; q < 8; q++) {
    	for (int er = 0; er < 8; er++){
			Board[q][er].draw();
		}
    }
////////////////////////////////////////////////////////////////////////////

	cout << "\nYour Turn Red.....";
	delay(1000);
	cout << endl << "Enter the Position of the token\n you want to move (A1, C1 etc.):";
	gets(pos);
	cout << endl;

	if(pos[0] == 'A')
	{
		X = 0;
	}
	else if(pos[0] == 'B')
	{
		X = 1;
	}
	else if(pos[0] == 'C')
	{
		X = 2;
	}
	else if(pos[0] == 'D')
	{
		X = 3;
	}
	else if(pos[0] == 'E')
	{
		X = 4;
	}
	else if(pos[0] == 'F')
	{
		X = 5;
	}
	else if(pos[0] == 'G')
	{
		X = 6;
	}
	else if(pos[0] == 'H')
	{
		X = 7;
	}
	else
	{
		cout << "Um... Enter Again ........";
		delay(500);
		goto start;
	}

	if(pos[1] == '1')
	{
		Y = 0;
	}
	else if(pos[1] == '2')
	{
		Y = 1;
	}
	else if(pos[1] == '3')
	{
		Y = 2;
	}
	else if(pos[1] == '4')
	{
		Y = 3;
	}
	else if(pos[1] == '5')
	{
		Y = 4;
	}
	else if(pos[1] == '6')
	{
		Y = 5;
	}
	else if(pos[1] == '7')
	{
		Y = 6;
	}
	else if(pos[1] == '8')
	{
		Y = 7;
	}
	else
	{
		cout << "Um... Enter Again.......";
		delay(500);
		goto start;
	}

	if(Board[Y][X].getColor() == 'x' || Board[Y][X].getColor() == 'b')
	{
		cout << "Um... Enter Again.......";
		delay(500);
		goto start;
	}

	cout << "Which Direction do you want to move?" << endl;
	cout << " 1 (North-West Diagonal),\n 2 (North-East Diagonal), " << endl;
	cout << " 3 (South-West Diagonal),\n 4 (South-East Diagonal), " << endl;
	cin >> dir;

	// North-West Diagonal
	if(dir == 1)
	{
		if(X == 0 || Y == 0)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y-1][X-1].getColor() == 'r')
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y-1][X-1].getColor() == 'x')
		{  
			Board[Y-1][X-1].setColor('r');
			Board[Y][X].setColor('x');
			goto done1;
		}
		if(Board[Y-1][X-1].getColor() == 'b')
		{
			if(X <= 1)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y-2][X-2].getColor() != 'x')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{	
				Board[Y][X].setColor('x'); 
				Board[Y-1][X-1].setColor('x');
				Y -= 2;
				X -= 2;
				Board[Y][X].setColor('r');
				goto done1;
			}
		}
	}

	// North-East Diagonal
	if(dir == 2)
	{
		if(X == 7 || Y == 0)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y-1][X+1].getColor() == 'r')
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y-1][X+1].getColor() == 'x')
		{
            Board[Y][X].setColor('x');
			Board[--Y][++X].setColor('r');
			goto done1;
		}
		if(Board[Y-1][X+1].getColor() == 'b')
		{
			if(X >= 6)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y-2][X+2].getColor() != 'x')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{
				Board[Y][X].setColor('x');
				Board[Y-1][X+1].setColor('x');
				Y -= 2;
				X += 2;
				Board[Y][X].setColor('r');
				goto done1;
			}
		}
	}

	// South-West Diagonal
	if(dir == 3)
	{
		if(X == 0 || Y == 7)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y+1][X-1].getColor() == 'r')
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y+1][X-1].getColor() == 'x')
		{
            Board[Y][X].setColor('x');
			Board[++Y][--X].setColor('b');
			goto done1;
		}
		if(Board[Y+1][X-1].getColor() == 'b')
		{
			if(X <= 1)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y+2][X-2].getColor() != 'x')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{
				Board[Y][X].setColor('x');
				Board[Y+1][X-1].setColor('x');
				Y += 2;
				X -= 2;
				Board[Y][X].setColor('r');
				goto done1;
			}
		}
	}

	// South-East Diagonal
	if(dir == 4)
	{
		if(X == 7 || Y == 7)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y+1][X+1].getColor() == 'r')
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y+1][X+1].getColor() == 'x')
		{
	    Board[Y][X].setColor('x');
		Board[++Y][++X].setColor('b');
			goto done1;
		}
		if(Board[Y+1][X+1].getColor() == 'b')
		{
			if(X >= 6)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y+2][X+2].getColor() != 'x')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{
				Board[Y][X].setColor('x');
				Board[Y+1][X+1].setColor('x');
				Y += 2;
				X += 2;
				Board[Y][X].setColor('r');
				goto done1;
			}
		}
	}

done1:
////////////////////////////////////////////////////////////////////////////////////////////////////////
clrscr();
    //The edges of the board


	setfillstyle(SOLID_FILL, BLACK);
	fillpoly(5, boardEdge);
	setfillstyle(SOLID_FILL, WHITE);

	//Column A White Squares
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int iiiiw = 0; iiiiw < 4; iiiiw++) {
		int whiteSq[] = { p1, tempP2, p1, tempP3, p4, tempP3, p4, tempP2, p1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column B white squares
	tempP1 = p1 + squareLen;
	tempP4 = p4 + squareLen;
	tempP2 = p2;
	tempP3 = p3;
	for (int bw = 0; bw < 4; bw++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}


	//Column C White Squares
	tempP1 = p1 + (2 * squareLen);
	tempP4 = p4 + (2 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int iiw = 0; iiw < 4; iiw++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column D white squares
	tempP1 = p1 + (3 * squareLen);
	tempP4 = p4 + (3 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int bbbw = 0; bbbw < 4; bbbw++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column E White Squares
	tempP1 = p1 + (4 * squareLen);
	tempP4 = p4 + (4 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int iiiw = 0; iiiw < 4; iiiw++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column F white squares
	tempP1 = p1 + (5 * squareLen);
	tempP4 = p4 + (5 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int xxw = 0; xxw < 4; xxw++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column G White Squares
	tempP1 = p1 + (6 * squareLen);
	tempP4 = p4 + (6 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int xw = 0; xw < 4; xw++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column H white squares
	tempP1 = p1 + (7 * squareLen);
	tempP4 = p4 + (7 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int bbw = 0; bbw < 4; bbw++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}


    for (int qw = 0; qw < 8; qw++) {
    	for (int erw = 0; erw < 8; erw++){
			Board[qw][erw].draw();
		}
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////
	delay(500);
	Plr = 0;
	Opp = 0;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j].getColor() == 'r')
			{
				Plr++;
			}
		}
	}
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j].getColor() == 'b')
			{
				Opp++;
			}
		}
	}

	if(Plr == 0 || Opp == 0)
	{
		goto end;
	}

	// Opponent's Turn
	cout << endl << "Opponent's (" << OppToken << ") Turn ........";
	delay(1000);
Again:


	if(limit == 15)
	{
		cout << endl << "Oppnent got confused .. ";
		limit = 0;
		delay(1000);
		goto start;
	}

	if(yolo == 15)
	{
		for(i = 0; i < 8; i++)
		{
			for(j = 0; j < 8; j++)
			{
				if(Board[i][j].getColor() == 'b')
				{
					Y = i;
					X = j;
				}
			}
		}
		yolo = 0;
		limit++;
	}
	else
	{
		Y = random(8);
		X = random(8);
	}

	if(Board[Y][X].getColor() != 'b')
	{
		goto Again;
	}
	dir = random(2) + 2;
	if(Board[Y-1][X-1].getColor() == 'r' && X > 1 && Y > 1 && Board[Y-1][X-1].getIsKing())
	{
		dir = 1;
	}
	if(Board[Y-1][X+1].getColor() == 'r' && X < 6 && Y > 1 && Board[Y-1][X-1].getIsKing())
	{
		dir = 2;
	}
	if(Board[Y+1][X-1].getColor() == 'r' && X > 1 && Y < 6)
	{
		dir = 3;
	}
	if(Board[Y+1][X+1].getColor() == 'r' && X < 6 && Y < 6)
	{
		dir = 4;
	}


	//North-West Diagonal
	if(dir == 1)
	{
		if(X == 0 || Y == 0)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y-1][X-1].getColor() == 'b')
		{
			yolo++;
			goto Again;
		}
		if(Board[Y-1][X-1].getColor() == 'x')
		{
			Board[Y][X].setColor('x');
			Board[--Y][--X].setColor('r');
			goto done2;
		}
		if(Board[Y-1][X-1].getColor() == 'r')
		{
			if(X >= 1)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y-2][X-2].getColor() != 'x')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X].setColor('x');
				Board[Y-1][X-1].setColor('x');
				Y -= 2;
				X -= 2;
				Board[Y][X].setColor('b');
				goto done2;
			}
		}
	}

	//North-East Diagonal
	if(dir == 2)
	{
		if(X == 7 || Y == 0)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y-1][X+1].getColor() == 'r')
		{
			yolo++;
			goto Again;
		}
		if(Board[Y-1][X+1].getColor() == 'x')
		{
            Board[Y][X].setColor('x');
			Board[--Y][++X].setColor('r');
			goto done2;
		}
		if(Board[Y-1][X+1].getColor() == 'r')
		{
			if(X >= 6)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y-2][X+2].getColor() != 'x')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X].setColor('x');
				Board[Y-1][X+1].setColor('x');
				Y -= 2;
				X += 2;
				Board[Y][X].setColor('b');
				goto done2;
			}
		}
	}

	//South-West Diagonal
	if(dir == 3)
	{
		if(X == 0 || Y == 7)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y+1][X-1].getColor() == 'b')
		{
			yolo++;
			goto Again;
		}
		if(Board[Y+1][X-1].getColor() == 'x')
		{
            Board[Y][X].setColor('x');
			Board[Y+1][X-1].setColor('b');
			goto done2;
		}
		if(Board[Y+1][X-1].getColor() == 'r')
		{
			if(X >= 1)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y+2][X-2].getColor() != 'x')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X].setColor('x');
				Board[Y+1][X-1].setColor('x');
				Y += 2;
				X -= 2;
				Board[Y][X].setColor('b');
				goto done2;
			}
		}
	}

	//South-West Diagonal
	if(dir == 4)
	{
		if(X == 7 || Y == 7)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y+1][X+1].getColor() == 'b')
		{
			yolo++;
			goto Again;
		}
		if(Board[Y+1][X+1].getColor() == 'x')
		{
            Board[Y][X].setColor('x');
			Board[Y+1][X+1].setColor('b');
			goto done2;
		}
		if(Board[Y+1][X+1].getColor() == 'r')
		{
			if(X >= 6)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y+2][X+2].getColor() != 'x')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X].setColor('x');
				Board[Y+1][X+1].setColor('x');
				Y += 2;
				X += 2;
				Board[Y][X].setColor('b');
				goto done2;
			}
		}
	}

done2:
	//boardDisplay(Board);
	delay(1000);
	Plr = 0;
	Opp = 0;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j].getColor() == 'r')
			{
				Plr++;
			}
		}
	}
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j].getColor() == 'b')
			{
				Opp++;
			}
		}
	}
	if(Plr == 0 || Opp == 0)
	{
		goto end;
	}
	else
	{
		goto start;
	}

end:
	clrscr();
	if(Plr > Opp)
	{
		delay(2000);
		gotoxy(30, 10);
		cout << "YOU WON!!!!" << endl;
	}
	if(Plr < Opp)
	{
		delay(2000);
		gotoxy(30, 10);
		cout << "OPPONENT WON!!!" << endl;
	}
	if(Plr == Opp)
	{
		delay(2000);
		gotoxy(30, 10);
		cout << "IT'S A DRAW!!!!";
	}
	getch();
}
