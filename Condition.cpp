#include "Condition.h"
#include <sstream>
#include <fstream>

using namespace std;

Condition::Condition(Point Center, string OP, string LeftHS, double RightHS, ApplicationManager* app):Statement(Center)
{
	LHS = LeftHS;
	Operation = OP;
	RHS = RightHS;

	UpdateStatementText();

	CenterPoint = Center;

	pConn = NULL;   //will be changed after connectors are done
	pApp = app;

	widthS = UI.Statement_Width;
	heightS = UI.Statement_HI;

	vStatX.first = CenterPoint.x - widthS / 2;
	vStatX.second = CenterPoint.x + widthS / 2;

	vStatY.first = CenterPoint.y - heightS / 2;
	vStatY.second = CenterPoint.y + heightS / 2;

	Inlet.x = CenterPoint.x;
	Inlet.y = CenterPoint.y - UI.Statement_HI / 2;
	Outlet.x = CenterPoint.x + UI.Statement_Width / 2;  //Yes will point to the right
	Outlet.y = CenterPoint.y;
	Outlet2.x = CenterPoint.x - UI.Statement_Width / 2;  //No will point to the left
	Outlet2.y = CenterPoint.y;
}

void Condition::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void Condition::setOperation(string& OP)
{
	Operation = OP;
	UpdateStatementText();
}

void Condition::setRHS(double R)
{
	RHS = R;
	UpdateStatementText();
}

void Condition::Draw(Output *pOut) const
{
	pOut->DrawConditionalStat(CenterPoint, UI.Statement_Width, UI.Statement_HI, Text, Selected);
}

void Condition::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = "if ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << "if " << LHS << " " << Operation << " " << RHS;
		Text = T.str();
	}
}

Point Condition::getInlet() const
{
	return Inlet;
}

Point Condition::getOutlet() const
{
	return Outlet;
}

void Condition::Save(ofstream& myfile)
{

	myfile << "COND" << "  " << ID << "  " << CenterPoint.x << "  " << CenterPoint.y << "  " << LHS << "  " << Operation << "  " << RHS;

	myfile << endl;
}
void Condition::Edit() {}

/*
void Condition::Load(ifstream& takefile)
{
	myfile >> "COND" >> "  " >> ID >> "  " >> CenterPoint.x >> "  " >>  CenterPoint.y >> "  " >> LHS >> "  " >> Operation >> "  " >> RHS;

}*/