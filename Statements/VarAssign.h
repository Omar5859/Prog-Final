#ifndef VAR_ASSIGN_H
#define VAR_ASSIGN_H

#include "Statement.h"
#include "..\ApplicationManager.h"

//Variable Assignment statement class
//The simple assignment statement assigns a variable to another variable
class VarAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	string RHS;	//Right Handside (name of the other value)

	Connector* pConn;	//Variable Assignment Stat. has one Connector to next statement
	ApplicationManager* pApp;

	Point Inlet;
	Point Outlet;

	virtual void UpdateStatementText();

public:
	VarAssign(Point Center, string LeftHS = "", string RightHS = "");

	void setLHS(const string& L);
	void setRHS(const string& R);

	void Save(ofstream& myfile);

	Point getInlet();
	Point getOutlet();

	virtual void Draw(Output* pOut) const;
};

#endif 