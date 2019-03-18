#include <graphics.h>


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
	int getX() {
		return _x;
	}

	int getY() {
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

	void draw(){
		if (_color == 'r'){
			setfillstyle(SOLID_FILL, RED);
			circle(_x, _y, _radius);
			floodfill(_x, _y, WHITE);
		}
		else if (_color == 'b'){
			circle(_x, _y, _radius);
		}
	}

private:

	char _color;
	int _isKing;
	int _x;
	int _y;
	int _radius;

};



void main()
{
	int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "c:\\TURBOC3\\BGI");
	int w = getmaxx() - 1;
	int h = getmaxy();
	int squareLen = w / 16;
	int boardSideLen = w / 2;
	int borderLen = (h - boardSideLen) / 2;
	circle(50, 50, 50);

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

	//int *whiteSquares[32];
	drawpoly(5, boardEdge);

	//Column A White Squares
	int tempP2 = p2;
	int tempP3 = p3;
	for (int i = 0; i < 4; i++) {
		int whiteSq[] = { p1, tempP2, p1, tempP3, p4, tempP3, p4, tempP2, p1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column B white squares
	int tempP1 = p1 + squareLen;
	int tempP4 = p4 + squareLen;
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int b = 0; b < 4; b++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}


	//Column C White Squares
	tempP1 = p1 + (2 * squareLen);
	tempP4 = p4 + (2 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int ii = 0; ii < 4; ii++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column D white squares
	tempP1 = p1 + (3 * squareLen);
	tempP4 = p4 + (3 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int bbb = 0; bbb < 4; bbb++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column E White Squares
	tempP1 = p1 + (4 * squareLen);
	tempP4 = p4 + (4 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int iii = 0; iii < 4; iii++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column F white squares
	tempP1 = p1 + (5 * squareLen);
	tempP4 = p4 + (5 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int xx = 0; xx < 4; xx++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column G White Squares
	tempP1 = p1 + (6 * squareLen);
	tempP4 = p4 + (6 * squareLen);
	tempP2 = p2;
	tempP3 = p3;
	for (int x = 0; x < 4; x++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}

	//Column H white squares
	tempP1 = p1 + (7 * squareLen);
	tempP4 = p4 + (7 * squareLen);
	tempP2 = p2 + squareLen;
	tempP3 = p3 + squareLen;
	for (int bb = 0; bb < 4; bb++) {
		int whiteSq[] = { tempP1, tempP2, tempP1, tempP3, tempP4, tempP3, tempP4, tempP2, tempP1, tempP2 };
		fillpoly(5, whiteSq);
		tempP2 = tempP2 + (2 * squareLen);
		tempP3 = tempP3 + (2 * squareLen);
	}
	//setcolor(3);

	Checker checkers[24];
	int x1 = w - boardSideLen + (squareLen/2);
	int y1 = h - borderLen - (squareLen/2) - 8;
	//setfillstyle(SOLID_FILL, RED);
	//circle(x1, y1, squareLen * 0.45);
	//floodfill(x1, y1, WHITE);

	for (int xxx = 0; xxx < 4; xxx++){
		Checker chec0 = Checker('r', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[xxx] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + squareLen + (squareLen/2);
	y1 = h - borderLen - squareLen - (squareLen/2) - 8;
	for (int t = 0; t < 4; t++){
		Checker chec0 = Checker('r', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[t+4] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + (squareLen/2);
	y1 = h - borderLen - (2*squareLen) - (squareLen/2) - 8;
	for (int tt = 0; tt < 4; tt++){
		Checker chec0 = Checker('r', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[tt+8] = chec0;
		//chec0.draw();
	}

	x1 = w - boardSideLen + squareLen + (squareLen/2);
	y1 = h - borderLen - (5*squareLen) - (squareLen/2) - 8;
	for (int s = 0; s < 4; s++){
		Checker chec0 = Checker('b', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[s+12] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + (squareLen/2);
	y1 = h - borderLen - (6*squareLen) - (squareLen/2) - 8;
	for (int ss = 0; ss < 4; ss++){
		Checker chec0 = Checker('b', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[ss+16] = chec0;
		//chec0.draw();
	}
	x1 = w - boardSideLen + squareLen + (squareLen/2);
	y1 = h - borderLen - (7*squareLen) - (squareLen/2) - 8;
	for (int sss = 0; sss < 4; sss++){
		Checker chec0 = Checker('b', x1, y1, squareLen * 0.45);
		x1 = x1 + (2*squareLen);
		checkers[sss+20] = chec0;
		//chec0.draw();
	}




    for (int q = 0; q < 24; q++) {
    	checkers[q].draw();
    }


	//for (int a = 0; a < 2; a++){
	//fillpoly(5, whiteSquares[a]);
	//}



}