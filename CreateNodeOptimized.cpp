//THE RIGHT MOVES
#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>

using namespace std;
using namespace cv;

Scalar Black = Scalar(0, 0, 0);
Scalar White = Scalar(255, 255, 255);
Scalar SkyBlue = Scalar(252, 214, 94);
Scalar Red = Scalar(10, 10, 210);
Scalar Blue = Scalar(240, 55, 14);
Point Center = Point(400, 350);
Mat Window(700, 800, CV_8UC3, SkyBlue);
int ArrayX = 0;
int ArrayY = 0;
int LocX[59];
int LocY[59];
int Radious = 16;

struct Circle {
	int Data;
	int Id;
	int CoordX;
	int CoordY;
	Circle* Next;
	Circle* Down;
	Circle* Prev;
	Circle* Up;
};

class RightM {
private:
	Circle * InitialP;
	Circle* InitialRowA;
	Circle* InitialRowB;
	Circle* InitialRowC;
	Circle* InitialRowD;
	Circle* InitialRowE;
	Circle* InitialRowF;
public:
	RightM();
	void CreateCircleList();
	void CreateNode(int, int, int, int, Circle*&);
	void ConnectCircleList();
	void ConnectNode();
	void DrawRing(int, int);
	void ConnectionBoard();
	void CenterCircle();
	void RecieveXY(int, int);
	void FindNode(int, int, Circle*);
	void ShowList();
};

RightM::RightM() {
	InitialP = NULL;
	InitialRowA = NULL;
	InitialRowB = NULL;
	InitialRowC = NULL;
	InitialRowD = NULL;
	InitialRowE = NULL;
	InitialRowF = NULL;
}

void RightM::CreateCircleList() {
	ArrayX = 0;
	ArrayY = 0;
	for (int I = 1; I <= 16; I++) {		
		if (I == 2 || I == 3 || I == 4 || I == 10 || I == 11 || I == 12) {
			CreateNode(2, ArrayX, ArrayY, I, InitialRowA);
		}
		else if (I == 6 || I == 7 || I == 8 || I == 14 || I == 15 || I == 16) {
			CreateNode(1, ArrayX, ArrayY, I, InitialRowA);
		}
		else {
			CreateNode(0, ArrayX, ArrayY, I, InitialRowA);
		}		
		ArrayX++;
		ArrayY++;
	}

	for (int J = 1; J <= 16; J++) {
		if (J == 2 || J == 3 || J == 4 || J == 10 || J == 11 || J == 12) {
			CreateNode(2, ArrayX, ArrayY, J, InitialRowB);
		}
		else if (J == 6 || J == 7 || J == 8 || J == 10 || J == 11 || J == 12) {
			CreateNode(1, ArrayX, ArrayY, J, InitialRowB);
		}
		else {
			CreateNode(0, ArrayX, ArrayY, J, InitialRowB);
		}
		ArrayX++;
		ArrayY++;
	}

	for (int K = 1; K <= 16; K++) {
		if (K == 2 || K == 3 || K == 4 || K == 10 || K == 11 || K == 12) {
			CreateNode(2, ArrayX, ArrayY, K, InitialRowC);
		}
		else if (K == 6 || K == 7 || K == 8 || K == 10 || K == 11 || K == 12) {
			CreateNode(1, ArrayX, ArrayY, K, InitialRowC);
		}
		else {
			CreateNode(0, ArrayX, ArrayY, K, InitialRowC);
		}
		ArrayX++;
		ArrayY++;
	}

	for (int L = 1; L <= 8; L++) {
		CreateNode(0, ArrayX, ArrayY, L, InitialRowD);
		ArrayX++;
		ArrayY++;
	}

	for (int M = 1; M <= 2; M++) {
		CreateNode(0, ArrayX, ArrayY, M, InitialRowE);
		ArrayX++;
		ArrayY++;
	}

	for (int N = 1; N <= 2; N++) {
		CreateNode(0, ArrayX, ArrayY, N, InitialRowF);
		ArrayX++;
		ArrayY++;
	}
}
void RightM::CreateNode(int Data, int X, int Y, int Id, Circle *&Initial) {
	Circle* NewNode = new Circle;
	NewNode->Data = Data;
	NewNode->CoordX = LocX[X];
	NewNode->CoordY = LocY[Y];
	NewNode->Id = Id;

	if (!Initial) {
		Initial = NewNode;
		NewNode->Next = Initial;
		NewNode->Up = NULL;
		NewNode->Prev = Initial;
		NewNode->Down = NULL;
	}
	else {
		Circle* Jump = Initial;
		while (Jump->Next != Initial) {
			Jump = Jump->Next;
		}
		NewNode->Next = Initial;
		Initial->Prev = NewNode;
		NewNode->Prev = Jump;
		Initial = NewNode;
		Jump->Next = Initial;
	}
}

void RightM::ConnectCircleList() {
	Circle* JumpA = InitialRowA;
	Circle* JumpB = InitialRowB;
	Circle* JumpC = InitialRowC;
	Circle* JumpD = InitialRowD;
	Circle* JumpE = InitialRowE;
	Circle* JumpF = InitialRowF;

	for (int I = 1; I <= 16; I++) {
		if (JumpA->Id == 1 && JumpB->Id == 1 && JumpC->Id == 1) {
			for (int J = 0; J < 2; J++) {
				JumpD = JumpD->Next;
			}
			JumpA->Down = JumpB;
			JumpB->Up = JumpA;
			JumpB->Down = JumpC;
			JumpC->Up = JumpB;
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}
		else if (JumpA->Id == 5 && JumpB->Id == 5 && JumpC->Id == 5) {
			for (int J = 0; J < 2; J++) {
				JumpD = JumpD->Next;
			}
			JumpA->Down = JumpB;
			JumpB->Up = JumpA;
			JumpB->Down = JumpC;
			JumpC->Up = JumpB;
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}

		else if (JumpA->Id == 9 && JumpB->Id == 9 && JumpC->Id == 9) {
			for (int J = 0; J < 2; J++) {
				JumpD = JumpD->Next;
			}
			JumpA->Down = JumpB;
			JumpB->Up = JumpA;
			JumpB->Down = JumpC;
			JumpC->Up = JumpB;
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}
		else if (JumpA->Id == 13 && JumpB->Id == 13 && JumpC->Id == 13) {
			JumpD = JumpD->Next;
			JumpA->Down = JumpB;
			JumpB->Up = JumpA;
			JumpB->Down = JumpC;
			JumpC->Up = JumpB;
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}
		else
		{
			JumpA->Down = NULL;
			JumpB->Down = NULL;
			JumpB->Up = NULL;
			JumpC->Down = NULL;
			JumpC->Up = NULL;
			JumpD->Up = NULL;
			JumpD->Down = NULL;
		}
		JumpA = JumpA->Next;
		JumpB = JumpB->Next;
		JumpC = JumpC->Next;
	}

	for (int J = 1; J <= 16; J++) {
		if (!JumpB->Down) {
			JumpB->Down = JumpC;
			JumpC->Up = JumpB;
		}
		JumpB = JumpB->Next;
		JumpC = JumpC->Next;
	}

	for (int K = 1; K <= 16; K++) {
		if (JumpC->Id == 15) {
			while (JumpD->Id != 8) {
				JumpD = JumpD->Next;
			}
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}
		else if (JumpC->Id == 11) {
			while (JumpD->Id != 6) {
				JumpD = JumpD->Next;
			}
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}
		else if (JumpC->Id == 7) {
			while (JumpD->Id != 4) {
				JumpD = JumpD->Next;
			}
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}
		else if (JumpC->Id == 3) {
			while (JumpD->Id != 2) {
				JumpD = JumpD->Next;
			}
			JumpC->Down = JumpD;
			JumpD->Up = JumpC;
		}
		JumpC = JumpC->Next;
	}

	JumpD = InitialRowD;
	for (int M = 1; M <= 8; M++) {
		if (JumpD->Id == 5) {
			JumpD->Down = JumpE;
			JumpE->Up = JumpD;
		}
		else if (JumpD->Id == 1) {
			JumpE = JumpE->Next;
			JumpD->Down = JumpE;
			JumpE->Up = JumpD;
		}
		else
		{
			JumpD->Down = NULL;
			JumpD->Up = NULL;
			JumpE->Down = NULL;
		}
		JumpD = JumpD->Next;
	}

	JumpD = InitialRowD;
	for (int N = 1; N <= 8; N++) {
		if (JumpD->Id == 7) {
			JumpD->Down = JumpF;
			JumpF->Up = JumpD;
		}
		else if (JumpD->Id == 3) {
			JumpF = JumpF->Next;
			JumpD->Down = JumpF;
			JumpF->Up = JumpD;
		}
		else
		{
			JumpD->Down = NULL;
			JumpD->Up = NULL;
			JumpF->Down = NULL;
		}
		JumpD = JumpD->Next;
	}
}


void RightM::DrawRing(int radio, int casillas) {

	int lol = 0;

	circle(Window, Center, radio, White, 2);
	float angulo = 2 * 3.14159 / casillas;

	for (float i = 0; i < 2 * 3.14159; i += angulo) {
		Point casilla = Point(Center.x + radio * cos(i), Center.y + radio * sin(i));
		cout << "Center del circulo " << "#" << lol++ << ": " << casilla << endl;
		LocX[ArrayX] = casilla.x;
		LocY[ArrayY] = casilla.y;
		circle(Window, casilla, 20, White, CV_FILLED);

		if (casillas > 15) {
			if (lol == 2 || lol == 3 || lol == 4 || lol == 10 || lol == 11 || lol == 12) {
				circle(Window, casilla, 16, Blue, CV_FILLED);
			}
			if (lol == 6 || lol == 7 || lol == 8 || lol == 14 || lol == 15 || lol == 16) {
				circle(Window, casilla, 16, Red, CV_FILLED);
			}
		}
		ArrayX++;
		ArrayY++;
	}
}

void RightM::ConnectionBoard() {

	//Coordenadas Linea Horizontal
	Point x1(400, 85);
	Point x2(400, 615);

	//Coordenadas Linea Vertical
	Point y1(135, 350);
	Point y2(665, 350);

	//Cruz
	line(Window, x1, x2, White, 2);
	line(Window, y1, y2, White, 2);

	//Conexiones del tablero cuadrante 1
	line(Window, Point(457, 212), Point(476, 167), White, 2);
	line(Window, Point(471, 280), Point(542, 208), White, 2);
	line(Window, Point(539, 293), Point(585, 274), White, 2);

	//Conexiones del tablero cuadrante 2
	line(Window, Point(324, 165), Point(342, 212), White, 2);
	line(Window, Point(257, 208), Point(329, 280), White, 2);
	line(Window, Point(215, 273), Point(261, 293), White, 2);

	//Conexiones del tablero cuadrante 3
	line(Window, Point(215, 426), Point(262, 407), White, 2);
	line(Window, Point(259, 491), Point(330, 420), White, 2);
	line(Window, Point(323, 535), Point(342, 488), White, 2);

	//Conexiones del trablero cuadrante 4
	line(Window, Point(458, 489), Point(476, 535), White, 2);
	line(Window, Point(471, 421), Point(542, 492), White, 2);
	line(Window, Point(584, 427), Point(539, 408), White, 2);

}

void RightM::CenterCircle()
{
	//Coordenadas para 4 circulos del Center
	Point cVertical1(400, 310);
	Point cVertical2(400, 390);
	Point cHorizontal1(360, 350);
	Point cHorizontal2(440, 350);
	LocX[56] = 400;
	LocY[56] = 310;
	LocX[57] = 400;
	LocY[57] = 390;
	LocX[58] = 360;
	LocY[58] = 350;
	LocX[59] = 440;
	LocY[59] = 350;


	//4 circulos del Center
	circle(Window, cVertical1, 20, White, CV_FILLED);
	circle(Window, cVertical2, 20, White, CV_FILLED);
	circle(Window, cHorizontal1, 20, White, CV_FILLED);
	circle(Window, cHorizontal2, 20, White, CV_FILLED);

};

void RightM::RecieveXY(int x, int y) {
	FindNode(x, y, InitialRowA);
}

void RightM::ShowList() {
	Circle* JumpA = InitialRowA;
	Circle* JumpB = InitialRowB;
	Circle* JumpC = InitialRowC;
	Circle* JumpD = InitialRowD;
	Circle* JumpE = InitialRowE;
	Circle* JumpF = InitialRowF;

	cout << "*****NODE A*****" << endl;
	do {
		cout << "ID: " << JumpA->Id << endl;
		cout << "Data: " << JumpA->Data << endl;
		cout << "Next: " << JumpA->Next->Id << endl;
		cout << "Previous: " << JumpA->Prev->Id << endl;
		cout << "Coordenada X: " << JumpA->CoordX << endl;
		cout << "Coordenada Y: " << JumpA->CoordY << endl;
		if (JumpA->Down) {
			cout << "Down: " << JumpA->Down->Id << endl;
		}
		JumpA = JumpA->Next;
	} while (JumpA != InitialRowA);

	cout << "*****NODE B*****" << endl;
	do {
		cout << "ID: " << JumpB->Id << endl;
		cout << "Data: " << JumpB->Data << endl;
		cout << "Next: " << JumpB->Next->Id << endl;
		cout << "Previous: " << JumpB->Prev->Id << endl;
		cout << "Coordenada X: " << JumpB->CoordX << endl;
		cout << "Coordenada Y: " << JumpB->CoordY << endl;
		if (JumpB->Down) {
			cout << "Down: " << JumpB->Down->Id << endl;
		}
		if (JumpB->Up) {
			cout << "Up: " << JumpB->Up->Id << endl;
		}
		JumpB = JumpB->Next;
	} while (JumpB != InitialRowB);

	cout << "*****NODE C*****" << endl;
	do {
		cout << "ID: " << JumpC->Id << endl;
		cout << "Data: " << JumpC->Data << endl;
		cout << "Next: " << JumpC->Next->Id << endl;
		cout << "Previous: " << JumpC->Prev->Id << endl;
		cout << "Coordenada X: " << JumpC->CoordX << endl;
		cout << "Coordenada Y: " << JumpC->CoordY << endl;
		if (JumpC->Down) {
			cout << "Down: " << JumpC->Down->Id << endl;
		}
		if (JumpC->Up) {
			cout << "Up: " << JumpC->Up->Id << endl;
		}
		JumpC = JumpC->Next;
	} while (JumpC != InitialRowC);

	cout << "*****NODE D*****" << endl;
	do {
		cout << "ID: " << JumpD->Id << endl;
		cout << "Data: " << JumpD->Data << endl;
		cout << "Next: " << JumpD->Next->Id << endl;
		cout << "Previous: " << JumpD->Prev->Id << endl;
		cout << "Coordenada X: " << JumpD->CoordX << endl;
		cout << "Coordenada Y: " << JumpD->CoordY << endl;
		if (JumpD->Up) {
			cout << "Up: " << JumpD->Up->Id << endl;
		}
		if (JumpD->Down) {
			cout << "Down: " << JumpD->Down->Id << endl;
		}
		JumpD = JumpD->Next;
	} while (JumpD != InitialRowD);

	cout << "*****NODE E*****" << endl;
	do {
		cout << "ID: " << JumpE->Id << endl;
		cout << "Data: " << JumpE->Data << endl;
		cout << "Coordenada X: " << JumpE->CoordX << endl;
		cout << "Coordenada Y: " << JumpE->CoordY << endl;
		if (JumpE->Next) {
			cout << "Next: " << JumpE->Next->Id << endl;
		}
		if (JumpE->Prev) {
			cout << "Previous: " << JumpE->Prev->Id << endl;
		}
		if (JumpE->Up) {
			cout << "Up: " << JumpE->Up->Id << endl;
		}
		if (JumpE->Down) {
			cout << "Down: " << JumpE->Down->Id << endl;
		}
		JumpE = JumpE->Next;
	} while (JumpE != InitialRowE);

	cout << "*****NODE F*****" << endl;
	do {
		cout << "ID: " << JumpF->Id << endl;
		cout << "Data: " << JumpF->Data << endl;
		cout << "Coordenada X: " << JumpF->CoordX << endl;
		cout << "Coordenada Y: " << JumpF->CoordY << endl;
		if (JumpF->Next) {
			cout << "Next: " << JumpF->Next->Id << endl;
		}
		if (JumpF->Prev) {
			cout << "Previous: " << JumpF->Prev->Id << endl;
		}
		if (JumpF->Up) {
			cout << "Up: " << JumpF->Up->Id << endl;
		}
		if (JumpF->Down) {
			cout << "Down: " << JumpE->Down->Id << endl;
		}
		JumpF = JumpF->Next;
	} while (JumpF != InitialRowF);

}

void RightM::FindNode(int x, int y, Circle* Jump) {
	Jump = InitialRowA;
	cout << Jump->Data << endl;
	
	//if (!Jump) {
	//	Jump = InitialRowA;
	//	if (Jump) {
	//		cout << "JumpA:" << Jump->Data << endl;
	//		FindNode(x, y, Jump);
	//	}
	//	else {
	//		cout << "VACIO" << endl;
	//	}
	//}
	//else {
	//	if (Jump == InitialRowA) {
	//		if (x + Radious <= Jump->CoordX  && y + Radious <= Jump->CoordY && x - Radious >= Jump->CoordX && y - Radious >= Jump->CoordY) {
	//			cout << "True" << endl;
	//		} 
	//		else
	//		{
	//			if (Jump->Id == 1 && Jump->Next->Id == 16) {
	//				Jump = InitialRowB;
	//			}
	//			else {
	//				FindNode(x, y, Jump->Next);
	//			}
	//		}
	//	}
	//	else if (Jump == InitialRowB) {
	//		if (x + Radious <= Jump->CoordX  && y + Radious <= Jump->CoordY && x - Radious >= Jump->CoordX && y - Radious >= Jump->CoordY) {
	//			cout << "True" << endl;
	//		}
	//		else
	//		{
	//			if (Jump->Id == 1 && Jump->Next->Id == 16) {
	//				Jump = InitialRowC;
	//			}
	//			else {
	//				FindNode(x, y, Jump->Next);
	//			}
	//		}
	//	}
	//	else if (Jump == InitialRowC) {
	//		if (x + Radious <= Jump->CoordX  && y + Radious <= Jump->CoordY && x - Radious >= Jump->CoordX && y - Radious >= Jump->CoordY) {
	//			cout << "True" << endl;
	//		}
	//		else
	//		{
	//			if (Jump->Id == 1 && Jump->Next->Id == 16) {
	//				Jump = InitialRowD;
	//			}
	//			else {
	//				FindNode(x, y, Jump->Next);
	//			}
	//		}
	//	}
	//	else if (Jump == InitialRowD) {
	//		if (x + Radious <= Jump->CoordX  && y + Radious <= Jump->CoordY && x - Radious >= Jump->CoordX && y - Radious >= Jump->CoordY) {
	//			cout << "True" << endl;
	//		}
	//		else
	//		{
	//			if (Jump->Id == 1 && Jump->Next->Id == 8) {
	//				Jump = InitialRowE;
	//			}
	//			else {
	//				FindNode(x, y, Jump->Next);
	//			}
	//		}
	//	}
	//	else if (Jump == InitialRowE) {
	//		if (x + Radious <= Jump->CoordX  && y + Radious <= Jump->CoordY && x - Radious >= Jump->CoordX && y - Radious >= Jump->CoordY) {
	//			cout << "True" << endl;
	//		}
	//		else
	//		{
	//			if (!Jump->Next) {
	//				Jump = InitialRowF;
	//			}
	//			else {
	//				FindNode(x, y, Jump->Next);
	//			}
	//		}
	//	}
	//	else if (InitialP == InitialRowF) {
	//		if (x + Radious <= Jump->CoordX  && y + Radious <= Jump->CoordY && x - Radious >= Jump->CoordX && y - Radious >= Jump->CoordY) {
	//			cout << "True" << endl;
	//		}
	//		else
	//		{
	//			if (!Jump->Next) {
	//				cout << "Haga click sobre un circulo valido." << endl;
	//				return;
	//			}
	//			else {
	//				FindNode(x, y, Jump->Next);
	//			}
	//		}
	//	}
	//}
}

void posMouse(int event, int x, int y, int, void*)
{
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		cout << "X: " << x << "\tY: " << y << endl;
	}
}

//void NodeLocation(int event, int x, int y, int, void*) {
//	RightM List;
//	if (event == CV_EVENT_LBUTTONDOWN) {
//		List.FindNode(x, y, NULL);
//	}
//}

int main() {
	RightM List;
	//Conexiones tablero
	List.ConnectionBoard();
	//Dibujar Tablero
	circle(Window, Center, 285, White, 2); //Circunferencia externa (sin circulos)
	List.DrawRing(250, 16);
	List.DrawRing(200, 16);
	List.DrawRing(150, 16);
	List.DrawRing(100, 8);
	circle(Window, Center, 68, White, 2); //Circunferencia Interna	(sin circulos)

										  //4 Circulos del Center
	List.CenterCircle();
	List.CreateCircleList();
	List.ConnectCircleList();
	List.ShowList();

	namedWindow("The Right Moves!");
	setMouseCallback("The Right Moves!", posMouse);
	//setMouseCallback("The Right Moves!", NodeLocation);
	imshow("The Right Moves!", Window);
	waitKey(0);

	return 0;
}