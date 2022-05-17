#include "OutputStat.h"

#include <sstream>
#include <fstream>

using namespace std;

OutputStat::OutputStat(Point Center, string Variable):Statement(Center)
{
	OutT = Variable;


	UpdateStatementText();

	CenterPoint = Center;

	pConn = NULL;	//No connectors yet
	pApp = NULL;

	widthS = UI.Parallelogram_Width;
	heightS = UI.Parallelogram_HI;

	vStatX.first = CenterPoint.x - widthS * 3 / 4;
	vStatX.second = CenterPoint.x + widthS * 3 / 4;

	vStatY.first = CenterPoint.y - heightS / 2;
	vStatY.second = CenterPoint.y + heightS / 2;

	Inlet.x = CenterPoint.x + widthS / 4;
	Inlet.y = CenterPoint.y - heightS / 2;

	Outlet.x = Inlet.x - widthS / 4;
	Outlet.y = CenterPoint.y + UI.ASSGN_HI / 2;
}

OutputStat::OutputStat(ApplicationManager* Pointer):Statement(CenterPoint)
{
}


void OutputStat::setOutT(const string& L)
{
	OutT = L;
	UpdateStatementText();
}

/*void OutputStat::setOutV(double R)
{
	OutV = R;
	UpdateStatementText();
}*/

void OutputStat::Draw(Output* pOut) const
{
	//Call Output::DrawInputOutput function to draw Input statement 	

	pOut->DrawOutput(CenterPoint, UI.Parallelogram_Width, UI.Parallelogram_HI, Text, Selected);
}

void OutputStat::UpdateStatementText()
{

	ostringstream T;

	T << OutT ;

	Text = T.str();
}

Point OutputStat::getInlet()
{
	return Inlet;
}

Point OutputStat::getOutlet()
{
	return Outlet;
}

void OutputStat::Save(ofstream& myfile)
{

	myfile << "WRITE" << "  " << ID << "  " << CenterPoint.x << "  " << CenterPoint.y << "  " << OutT << "  " << "=" << "  " << OutT;

	myfile << endl;
}

/*void OutputStat::Load(ifstream& takefile)
{
	takefile >> "  " >> ID >> "  " >> CenterPoint.x >> "  " >> CenterPoint.y >> "  " >> OutT >> "  " >> "=" >> "  " >> OutT;

	UpdateStatementText();
}*/

