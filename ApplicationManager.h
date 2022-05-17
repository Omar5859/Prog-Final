#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Statements/Statement.h"
#include "Statements/Connector.h"
#include "GUI/Input.h"
#include "GUI/Output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxCount = 200 };	//Max no of statements/connectors in a single flowchart

private:
	int StatCount;		//Actual number of statements
	int ConnCount;		//Actual number of connectors
	Statement* StatList[MaxCount];	//List of all statements (Array of pointers)
	Connector* ConnList[MaxCount];	//List of all connectors (Array of pointers)

	Statement* pSelectedStat; //a pointer to the last selected statement
	Connector* pSelectedConn;

	pair<int, int>* ArrX;
	pair<int, int>* ArrY;

	int MultiSelections[200]; //an array of selected statements with their IDs
	static int selectionCount;

	void UpdateStat(int id);  //Updates the Arrays

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Actions Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Statements/Connector Management Functions
	void AddStatement(Statement* pStat); //Adds a new Statement to the Flowchart
	Statement* GetStatement(Point P) const;	//search for a statement where point P belongs

	Statement* & GetSelectedStatement();	//Returns the selected Statement
	void SetSelectedStatement(Statement* pStat, Point P); //Set the Statement selected by the user

	void AddConnectorList(Connector* pConn); //Adds a new Connector to the flowchart
	Connector* GetConnector(Point P) const; //Search for a statement where point p belongs

	void SetSelectedConnector(Connector* pConn); //Set the Connector Statement by the user
	Connector* & GetSelectedConnector(); //Returns the selected Connector

	int GetStatCount();
	int GetConnCount();
	Statement** GetStatList();    //Returns each statement (Pointer-Pointer-Object)
	Connector** GetConnList();

	void SaveChart(ofstream& myfile);
	/*
	void LoadChart(ifstream& takefile);
	*/

	bool Validation();

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window

};

#endif