#include "EndStat.h"
#include <fstream>

EndStat::EndStat(Point Center):Statement(Center)
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

	Inlet.x = CenterPoint.x;
	Inlet.y = CenterPoint.y - heightS;
}

void EndStat::Draw(Output* pOut) const
{
	//Call Output::DrawStartEnd function to draw EndStat statement 	
	pOut->DrawStartEnd(CenterPoint, UI.Start_Radius, "End");
}

void EndStat::UpdateStatementText()
{}

Point EndStat::getInlet() const
{
	return Inlet;
}

Point EndStat::getOutlet() const
{
	return Outlet;
}

void EndStat::Save(ofstream& myfile)
{
	myfile << "END" << "  " << ID << "  " << CenterPoint.x << "  " << CenterPoint.y << "  ";

	myfile << endl;
}
void EndStat::Edit() {}

/*
void EndStat::Load(ifstream& takefile)
{
	takefile >> "  " >> ID >> "  " >> CenterPoint.x >> "  " >> CenterPoint.y >> "  ";


	UpdateStatementText();

}*/