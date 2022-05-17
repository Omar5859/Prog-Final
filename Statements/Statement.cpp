#include "Statement.h"

int Statement::ID_counter = 0;

Statement::Statement(Point P)
{
	ID = ID_counter++;
	Text = "";
	Selected = false;
	CenterPoint = P;
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

int Statement::GetID()
{
	return ID;
}

pair<int, int> Statement::SetCenterPoint(Input* In)
{
	In->GetPointClicked(CenterPoint);
	return pair<int, int>(CenterPoint.x, CenterPoint.y); //first will be X and Second wil be y
}

void Statement::setvStatX(int X)
{
	int XLeft = X - widthS / 2;
	int XRight = X + widthS / 2;
	vStatX.first = XLeft;
	vStatX.second = XRight;
}

void Statement::setvStatY(int Y)
{
	int YUp = Y - heightS / 2;
	int Ydown = Y + heightS / 2;
	vStatY.first = YUp;
	vStatY.second = Ydown;
}

pair<int, int> Statement::getvStatX()
{
	return vStatX;
}

pair<int, int> Statement::getvStatY()
{
	return vStatY;
}
