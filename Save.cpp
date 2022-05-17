#include "Save.h"

#include <fstream> //it can create files, write information to files, and read information from files.

#include <iostream>

using namespace std;


Save::Save(ApplicationManager* PointAppManager) :Action(PointAppManager)
{
}

void Save::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	cout << pManager->GetStatCount() << endl;
	cout << pManager->GetConnCount() << endl;

	if (pManager->GetStatCount() == 0 && pManager->GetConnCount() == 0)
	{
		pOut->ClearStatusBar();
		pOut->PrintMessage("Nothing to save");
	}
	//If no charts to be saved
}


void Save::Execute()
{
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	ofstream myfile("SavedFile.txt", ios::out);

	myfile << pManager->GetStatCount();

	myfile << endl;

	pManager->SaveChart(myfile);


	myfile.close();

	//to close file (must be closed)

	pOut->ClearStatusBar();

	pOut->PrintMessage("Saved");
}