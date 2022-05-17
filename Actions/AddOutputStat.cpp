#include "AddOutputStat.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

#include <sstream>

#include "../Statements/OutputStat.h"

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddOutputStat::AddOutputStat(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddOutputStat::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Output Statement: Click to add Output statement");

	pIn->GetPointClicked(Position);

	pOut->ClearStatusBar();

	pOut->PrintMessage("Output Statement: Write the variable you want to be displayed");

	Variable = pIn->GetString(pOut);

	pOut->ClearStatusBar();

}

void AddOutputStat::Execute()
{
	ReadActionParameters();

	OutputStat* pOutput = new OutputStat(Position, Variable);

	pManager->AddStatement(pOutput);
}

