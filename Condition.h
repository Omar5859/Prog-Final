#pragma once

#include "Statements/Statement.h"
#include "ApplicationManager.h"

class Condition : public Statement
{
	string LHS;
	string Operation;
	double RHS;

	Connector* pConn;
	ApplicationManager* pApp;

	Point Inlet;
	Point Outlet;
	Point Outlet2;

	virtual void UpdateStatementText();

public:
	Condition(Point Center, string OP, string LeftHS="", double RightHS = 0, ApplicationManager* app = NULL);

	void setLHS(const string& L);
	void setOperation(string& O);
	void setRHS(double R);

	void Save(ofstream& myfile);

	Point getInlet();
	Point getOutlet();
	Point getOutlet2();

	virtual void Draw(Output* pOut) const;
};