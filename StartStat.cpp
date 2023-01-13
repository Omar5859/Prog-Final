#include "StartStat.h"
#include <fstream>

StartStat::StartStat(Point Center):Statement(Center)
{
	CenterPoint = Center;

	pConn = NULL;	//No connectors yet
	pApp = NULL;

	widthS = UI.Start_Radius;
	heightS = UI.Start_Radius;

	vStatX.first = CenterPoint.x - widthS;
	vStatX.second = CenterPoint.x + widthS;

	vStatY.first = CenterPoint.y - heightS;
	vStatY.second = CenterPoint.y + heightS;

	Outlet.x = CenterPoint.x;
	Outlet.y = CenterPoint.y + heightS;
}

void StartStat::Draw(Output* pOut) const
{
	//Call Output::DrawStartEnd function to draw StartStat statement 	
	pOut->DrawStartEnd(CenterPoint, UI.Start_Radius, "Start");
}

void StartStat::UpdateStatementText()
{}

Point StartStat::getInlet() const
{
	return Inlet;
}

Point StartStat::getOutlet() const
{
	return Outlet;
}

void StartStat::Save(ofstream& myfile)
{

	myfile << "STRT" << "  " << ID << "  " << CenterPoint.x << "  " << CenterPoint.y << "  ";

	myfile << endl;
}
void StartStat::Edit() {}

/*
 void StartStat::Load(ifstream& takefile)
{

	takefile >>"  " >> ID >> "  " >> CenterPoint.x >> "  " >> CenterPoint.y >> "  ";

	UpdateStatementText();
}*/


//Commented due to error