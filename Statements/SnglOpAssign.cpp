#include "SnglOpAssign.h"
#include <sstream>
#include <fstream>

using namespace std;

SnglOpAssign::SnglOpAssign(Point Center, string LeftHS, double RightHSd,string RightHSs, string operand, ApplicationManager* app) :Statement(Center)
{
	LHS = LeftHS;
	RHSd = RightHSd;
	RHSs = RightHSs; 
	op = operand; 

	UpdateStatementText();

	CenterPoint = Center;

	pConn = NULL;	//No connectors yet
	pApp = app;

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

void SnglOpAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

string& SnglOpAssign::getLHS() {
	return LHS;
}


void SnglOpAssign::setRHSs(const string& R) {
	RHSs = R; 
	UpdateStatementText();
}

string& SnglOpAssign::getRHSs() {
	return RHSs;
}

void  SnglOpAssign::setOp(string& oper) {
	op = oper; 
	UpdateStatementText();
}

string& SnglOpAssign::getOp() {
	return op;
}

void SnglOpAssign::setRHSd(double R)
{
	RHSd = R;
	UpdateStatementText();
}

double SnglOpAssign::getRHSd() {
	return RHSd;
}

void SnglOpAssign::Draw(Output* pOut) const
{
	pOut->DrawAssign(CenterPoint, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}


//This function should be called when LHS or RHS changes
void SnglOpAssign::UpdateStatementText()
{
	if (LHS == "")	//No left handside ==>statement have no valid text yet
		Text = "    = ";
	else
	{
		//Build the statement text: Left handside then equals then right handside
		ostringstream T;
		T << LHS << " = " << RHSs<<" "<<op<<" " << RHSd;
		Text = T.str();
	}
}

Point SnglOpAssign::getInlet()
{
	return Inlet;
}

Point SnglOpAssign::getOutlet()
{
	return Outlet;
}

void SnglOpAssign::Save(ofstream& myfile)
{

	myfile << "SNGLOP" << "  " << ID << "  " << CenterPoint.x << "  " << CenterPoint.y << "  " << LHS << "  " << " = " << "  " << RHSs << " " << op << " " << RHSd;

	myfile << endl;
}