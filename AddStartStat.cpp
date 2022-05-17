#include "AddStartStat.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddStartStat::AddStartStat(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddStartStat::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Start Statement: Click to add the start statement");

	pIn->GetPointClicked(Position);

	pOut->ClearStatusBar();
}

void AddStartStat::Execute()
{
	ReadActionParameters();

	StartStat* pStartStat = new StartStat(Position);

	pManager->AddStatement(pStartStat);
}