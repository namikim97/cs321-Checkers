// checkers.cpp
// 
// Created: 13 Mar 2019
// Updated: 15 Mar 2019
//
// class Checkers

#include <conio.h> // console input output header file

#include <iostream.h>
#include <stdio.h> // for gets()

#include <stdlib.h> // for randomize()
#include <dos.h> // for delay()

void boardDisplay(char [8][8]);

void boardDisplay(char Board[8][8])
{
	clrscr(); //used to clear the console screen

	for(int i = 0; i < 8; i++)
	{
		cout << "  +---+---+---+---+---+---+---+---+" << endl;
		cout << i+1 << " | " << Board[i][0]
					<< " | " << Board[i][1]
					<< " | " << Board[i][2]
					<< " | " << Board[i][3]
					<< " | " << Board[i][4]
					<< " | " << Board[i][5]
					<< " | " << Board[i][6]
					<< " | " << Board[i][7] << endl;
	}
	cout << "  +---+---+---+---+---+---+---+---+" << endl;
	cout << "    A   B   C   D   E   F   G   H  " << endl;
}

void main()
{
Intro:
	randomize();
	clrscr();
	int X, Y, dir, Plr, Opp;
	int yolo = 0;
	int limit = 0;
	char Board[8][8];
	char PlrToken = '@';
	char OppToken = '!';
	char pos[2];
	int i, j;

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			Board[i][j] = ' ';
		}
	}

	cout << "Welcome to Checkers Game" << endl;

	cout << "The Player's token is " << PlrToken << endl;
	cout << "The Opponent's token is " << OppToken << endl;

	char *String[4] = { "THE", "GAME", "STARTS", "NOW!!!!" };
	for(i = 0; i < 4; i++)
	{
		cout << "\n\n" << "\t\t\t" << String[i] << " ";
		delay(500);
	}
	delay(1000);

	Board[0][0] = OppToken; Board[0][2] = OppToken;
	Board[0][4] = OppToken; Board[0][6] = OppToken;
	Board[1][1] = OppToken; Board[1][3] = OppToken;
	Board[1][5] = OppToken; Board[1][7] = OppToken;
	Board[2][0] = OppToken; Board[2][2] = OppToken;
	Board[2][4] = OppToken; Board[2][6] = OppToken;

	Board[5][1] = PlrToken; Board[5][3] = PlrToken;
	Board[5][5] = PlrToken; Board[5][7] = PlrToken;
	Board[6][0] = PlrToken; Board[6][2] = PlrToken;
	Board[6][4] = PlrToken; Board[6][6] = PlrToken;
	Board[7][1] = PlrToken; Board[7][3] = PlrToken;
	Board[7][5] = PlrToken; Board[7][7] = PlrToken;


	// Your Turn
start:
	boardDisplay(Board);
	cout << "Your (" << PlrToken << ") Turn .....";
	delay(1000);
	cout << endl << "Enter the Position of the token you want to move: ( Like A1, A6, C1 etc. ) ";
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

	if(Board[Y][X] != PlrToken)
	{
		cout << "Um... Enter Again.......";
		delay(500);
		goto start;
	}

	cout << "Which Direction do you want to move?" << endl;
	cout << " 1 (North-West Diagonal), 2 (North-East Diagonal) " << endl;
	cout << " 3 (South-West Diagonal), 4 (South-East Diagonal) " ;
	cin >> dir;

	PlrToken = '@';
	OppToken = '!';

	// North-West Diagonal
	if(dir == 1)
	{
		if(X == 0 || Y == 0)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y-1][X-1] == PlrToken)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y-1][X-1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[--Y][--X] = PlrToken;
			goto done1;
		}
		if(Board[Y-1][X-1] == OppToken)
		{
			if(X <= 1)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y-2][X-2] != ' ')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y-1][X-1] = ' ';
				Y -= 2;
				X -= 2;
				Board[Y][X] = PlrToken;
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
		if(Board[Y-1][X+1] == PlrToken)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y-1][X+1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[--Y][++X] = PlrToken;
			goto done1;
		}
		if(Board[Y-1][X+1] == OppToken)
		{
			if(X >= 6)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y-2][X+2] != ' ')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y-1][X+1] = ' ';
				Y -= 2;
				X += 2;
				Board[Y][X] = PlrToken;
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
		if(Board[Y+1][X-1] == PlrToken)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y+1][X-1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[++Y][--X] = PlrToken;
			goto done1;
		}
		if(Board[Y+1][X-1] == OppToken)
		{
			if(X <= 1)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y+2][X-2] != ' ')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y+1][X-1] = ' ';
				Y += 2;
				X -= 2;
				Board[Y][X] = PlrToken;
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
		if(Board[Y+1][X+1] == PlrToken)
		{
			cout << "Token can't be moved....";
			delay(500);
			goto start;
		}
		if(Board[Y+1][X+1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[++Y][++X] = PlrToken;
			goto done1;
		}
		if(Board[Y+1][X+1] == OppToken)
		{
			if(X >= 6)
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			if(Board[Y+2][X+2] != ' ')
			{
				cout << "Token can't be moved....";
				delay(500);
				goto start;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y+1][X+1] = ' ';
				Y += 2;
				X += 2;
				Board[Y][X] = PlrToken;
				goto done1;
			}
		}
	}

done1:
	boardDisplay(Board);
	delay(500);
	Plr = 0;
	Opp = 0;
	PlrToken = '@';
	OppToken = '!';

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j] == PlrToken)
			{
				Plr++;
			}
		}
	}
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j] == OppToken)
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
				if(Board[i][j] == OppToken)
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

	if(Board[Y][X] != OppToken)
	{
		goto Again;
	}
	dir = random(4) + 1;
	if(Board[Y-1][X-1] == PlrToken && X > 1 && Y > 1)
	{
		dir = 1;
	}
	if(Board[Y-1][X+1] == PlrToken && X < 6 && Y > 1)
	{
		dir = 2;
	}
	if(Board[Y+1][X-1] == PlrToken && X > 1 && Y < 6)
	{
		dir = 3;
	}
	if(Board[Y+1][X+1] == PlrToken && X < 6 && Y < 6)
	{
		dir = 4;
	}

	PlrToken = '@';
	OppToken = '!';

	//North-West Diagonal
	if(dir == 1)
	{
		if(X == 0 || Y == 0)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y-1][X-1] == OppToken)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y-1][X-1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[--Y][--X] = OppToken;
			goto done2;
		}
		if(Board[Y-1][X-1] == PlrToken)
		{
			if(X >= 1)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y-2][X-2] != ' ')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y-1][X-1] = ' ';
				Y -= 2;
				X -= 2;
				Board[Y][X] = OppToken;
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
		if(Board[Y-1][X+1] == OppToken)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y-1][X+1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[--Y][++X] = OppToken;
			goto done2;
		}
		if(Board[Y-1][X+1] == PlrToken)
		{
			if(X >= 6)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y-2][X+2] != ' ')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y-1][X+1] = ' ';
				Y -= 2;
				X += 2;
				Board[Y][X] = OppToken;
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
		if(Board[Y+1][X-1] == OppToken)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y+1][X-1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[++Y][--X] = OppToken;
			goto done2;
		}
		if(Board[Y+1][X-1] == PlrToken)
		{
			if(X >= 1)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y+2][X-2] != ' ')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y+1][X-1] = ' ';
				Y += 2;
				X -= 2;
				Board[Y][X] = OppToken;
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
		if(Board[Y+1][X+1] == OppToken)
		{
			yolo++;
			goto Again;
		}
		if(Board[Y+1][X+1] == ' ')
		{
			Board[Y][X] = ' ';
			Board[++Y][++X] = OppToken;
			goto done2;
		}
		if(Board[Y+1][X+1] == PlrToken)
		{
			if(X >= 6)
			{
				yolo++;
				goto Again;
			}
			if(Board[Y+2][X+2] != ' ')
			{
				yolo++;
				goto Again;
			}
			else
			{
				Board[Y][X] = ' ';
				Board[Y+1][X+1] = ' ';
				Y += 2;
				X += 2;
				Board[Y][X] = OppToken;
				goto done2;
			}
		}
	}

done2:
	boardDisplay(Board);
	delay(1000);
	Plr = 0;
	Opp = 0;
	PlrToken = '@';
	OppToken = '!';

	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j] == PlrToken)
			{
				Plr++;
			}
		}
	}
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 8; j++)
		{
			if(Board[i][j] == OppToken)
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
