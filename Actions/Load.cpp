#include "Load.h"
#include <fstream> //it can create files, write information to files, and read information from files.

#include <iostream>

using namespace std;
Load::Load(ApplicationManager* Pointappmanager) :Action(Pointappmanager)
{}

void Load::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	if (pManager->GetStatCount() == 0 && pManager->GetConnCount() == 0)
	{
		pOut->PrintMessage("You have nothing to load");
	}
}
void Load::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	pOut->ClearStatusBar();

	pOut->PrintMessage("LOADING IS BEING APPLIED");

	ifstream takefile("SavedFile.txt", ios::in);
	/*
	pManager->LoadChart(takefile);
	*/

	takefile.close();

	ConnCount = pManager->GetConnCount();

	StatCount = pManager->GetConnCount();
}


