#ifndef SNGL_OP_ASSIGN_H
#define SNGL_OP_ASSIGN_H

#include "Statement.h"
#include "..\ApplicationManager.h"

//Simple Assignment statement class
//The simple assignment statement assigns a variable to a value
class SnglOpAssign : public Statement
{
private:
	string LHS;	//Left Handside of the assignment (name of a variable)
	double RHSd;	//Right Handside (Value)
	string RHSs;    //Right Handside (name of variabe) 
	string op;         //operator 

	Connector* pConn;	//Simple Assignment Stat. has one Connector to next statement
	ApplicationManager* pApp;

	Point Inlet;
	Point Outlet;

	virtual void UpdateStatementText();

public:
	SnglOpAssign(Point Center, string LeftHS = "", double RightHSd = 0,string RightHSs="",string op=0, ApplicationManager* app = NULL);

	void setLHS(const string& L);
	string& getLHS();
	void setRHSd(double R);
	double getRHSd();
	void setRHSs(const string& R);
	string& getRHSs();
	void setOp(string& oper);
	string& getOp();

	void Save(ofstream& myfile);

	Point getInlet();
	Point getOutlet();

	virtual void Draw(Output* pOut) const;

};

#endif