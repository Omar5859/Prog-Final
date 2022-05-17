#include "AddVarAssign.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

#include <sstream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddVarAssign::AddVarAssign(ApplicationManager* pAppManager):Action(pAppManager)
{}

void AddVarAssign::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Simple Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Simple Value Assignment Statement: Click to add Variable");

	LeftText = pIn->GetString(pOut);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Simple Value Assignment Statement: Click to add assigned variable");

	RightText = pIn->GetString(pOut);
	pOut->ClearStatusBar();
}

void AddVarAssign::Execute()
{
	ReadActionParameters();

	VarAssign* pVarAssign = new VarAssign(Position, LeftText, RightText);

	pManager->AddStatement(pVarAssign);
}