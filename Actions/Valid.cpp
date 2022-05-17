#include "Valid.h"


Valid::Valid(ApplicationManager* pAppManager) :Action(pAppManager)
{
	//empty constructor
}


void Valid::ReadActionParameters()
{

	/*if (st->GetStatCount() == 0)
	{
		pOut->ClearStatusBar();

		pOut->PrintMessage("The design has no statements");
	}*/
	//better do it in the function validation to make each part make its own task.
}

void Valid::Execute() {


	pManager->Validation();

	//To call the function validation
}