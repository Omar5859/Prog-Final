#include "AddSnglOpAssign.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddSnglOpAssign::AddSnglOpAssign(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddSnglOpAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Single Operator Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Single Operator Assignment Statement: Click to add variable");

	LeftText = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Single Operator Assignment Statement: Click to add Varaibe");

	RightString = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Single Operator Assignment Statement: Click to add Operand");

	operand = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Single Operator Assignment Statement: Click to add Value");

	RightValue = pIn->GetValue(pOut);
	pOut->ClearStatusBar();
}

void AddSnglOpAssign::Execute()
{
	ReadActionParameters();

	SnglOpAssign* pAssign = new SnglOpAssign(Position, LeftText, RightValue,RightString,operand, this->pManager);

	pManager->AddStatement(pAssign);
}