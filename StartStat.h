#ifndef START_STAT_H
#define START_STAT_H

#include "Statements/Statement.h"
#include "ApplicationManager.h"

class StartStat : public Statement
{
private:
	Connector* pConn;	//start Stat has one Connector to next statement
	ApplicationManager* pApp;

	Point Inlet;
	Point Outlet;

	virtual void UpdateStatementText();

public:
	StartStat(Point Center);

	virtual Point getInlet() const;
	virtual Point getOutlet() const;

	virtual void Draw(Output* pOut) const;

	void Save(ofstream& myfile);
	void Edit(); 

	/*void Load(ifstream& takefile);*/
};

#endif