#include "VarAssign.h"
#include <sstream>
#include <fstream>

using namespace std;

VarAssign::VarAssign(Point Center, string LeftHS, string RightHS):Statement(Center)
{
	LHS = LeftHS;
	RHS = RightHS;

	UpdateStatementText();

	CenterPoint = Center;

	pConn = NULL;	//No connectors yet
	pApp = NULL;

	widthS = UI.ASSGN_WDTH;
	heightS = UI.ASSGN_HI;

	vStatX.first = CenterPoint.x - widthS / 2;
	vStatX.second = CenterPoint.x + widthS / 2;

	vStatY.first = CenterPoint.y - heightS / 2;
	vStatY.second = CenterPoint.y + heightS / 2;

	Inlet.x = CenterPoint.x;                        
	Inlet.y = CenterPoint.y - UI.ASSGN_HI / 2;

	Outlet.x = Inlet.x;
	Outlet.y = CenterPoint.y + UI.ASSGN_HI / 2;
}

void VarAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}
 
void VarAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}


void VarAssign::Draw(Output* pOut) const
{
	//Call Output::DrawAssign function to draw assignment statement 	
	pOut->DrawAssign(CenterPoint, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);

}


//This function should be called when LHS or RHS changes
void VarAssign::UpdateStatementText()
{
	if (LHS == "" || RHS== "")  //No left handside ==>statement have no valid text yet
		Text = "    =    ";

	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << LHS << " = " << RHS;
		Text = T.str();
	}
}

Point VarAssign::getInlet()
{
	return Inlet;
}

Point VarAssign::getOutlet()
{
	return Outlet;
}

void VarAssign::Save(ofstream& myfile)
{

	myfile << "VARASSIGN" << "  " << ID << "  " << CenterPoint.x << "  " << CenterPoint.y << "  " << LHS << "  " << " = " << "  " << RHS;

	myfile << endl;
}