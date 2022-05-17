#include "AddEndStat.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddEndStat::AddEndStat(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddEndStat::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("End Statement: Click to add the end statement");

	pIn->GetPointClicked(Position);

	pOut->ClearStatusBar();

}

void AddEndStat::Execute()
{
	ReadActionParameters();

	EndStat* pEndStat = new EndStat(Position);

	pManager->AddStatement(pEndStat);
}