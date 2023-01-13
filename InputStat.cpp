#include "InputStat.h"

#include <sstream>

#include <fstream>

using namespace std;

InputStat::InputStat(Point Center, double value):Statement(Center)
{
	InpV = value;

	UpdateStatementText();

	CenterPoint = Center;

	widthS = UI.Parallelogram_Width;
	heightS = UI.Parallelogram_HI;

	vStatX.first = CenterPoint.x - widthS * 3 / 4;
	vStatX.second = CenterPoint.x + widthS * 3 / 4;

	vStatY.first = CenterPoint.y - heightS / 2;
	vStatY.second = CenterPoint.y + heightS / 2;

	pConn = NULL;	//No connectors yet
	pApp = NULL;

	Inlet.x = CenterPoint.x + widthS / 4;
	Inlet.y = CenterPoint.y - heightS / 2;

	Outlet.x = Inlet.x - widthS / 4;
	Outlet.y = CenterPoint.y + UI.ASSGN_HI / 2;
}

InputStat::InputStat(ApplicationManager* Pointer):Statement(CenterPoint)
{}

void InputStat::setInpV(double R)
{
	InpV = R;
	UpdateStatementText();
}


void InputStat::Draw(Output* pOut) const
{
	//Call Output::DrawInputOutput function to draw Input statement 	

	pOut->DrawOutput(CenterPoint, UI.Parallelogram_Width, UI.Parallelogram_HI, Text, Selected);
}


void InputStat::UpdateStatementText()
{

	ostringstream T;

	T << InpV;

	Text = T.str();
}

Point InputStat::getInlet() const
{
	return Inlet;
}

Point InputStat::getOutlet() const
{
	return Outlet;
}

void InputStat::Save(ofstream& myfile)
{

	myfile << "READ" << "  " << ID << "  " << CenterPoint.x << "  " << CenterPoint.y << "  " << InpV;

	myfile << endl;
}

void InputStat::Edit() {}
/*void InputStat::Load(ifstream& takefile)
{
	takefile >> "  " >> ID >> "  " >> CenterPoint.x >> "  " >> CenterPoint.y >> "  " >> InpV;

	UpdateStatementText();

}*/