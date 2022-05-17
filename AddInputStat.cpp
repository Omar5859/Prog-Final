#include "AddInputStat.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

#include <sstream>

using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddInputStat::AddInputStat(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddInputStat::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Input Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

	pOut->PrintMessage("Input Statement: Click to add Value");

	value = pIn->GetValue(pOut);

	/// text = pIn->GetString(pOut);  (Ask)

	pOut->ClearStatusBar();

}

void AddInputStat::Execute()
{
	ReadActionParameters();

	InputStat* pInput = new InputStat(Position, value);

	pManager->AddStatement(pInput);
}