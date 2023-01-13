#ifndef INPUT_STAT_H
#define INPUT_STAT_H

#include "Statements/Statement.h"
#include "ApplicationManager.h"

//Input statement class
//Input  statement 
class InputStat : public Statement
{
private:

	double InpV; //value written

	Connector* pConn;	//Input Stat. has one Connector to next statement
	ApplicationManager* pApp;

	Point Inlet;
	Point Outlet;

	virtual void UpdateStatementText();

public:
	InputStat(Point Center, double value);

	InputStat(ApplicationManager* Pointer);

	void setInpV(double R);

	virtual Point getInlet() const;
	virtual Point getOutlet() const;

	virtual void Draw(Output* pOut) const;

	void Save(ofstream& myfile);
	void Edit(); 

	/*void Load(ifstream& takefile);*/

};


#endif