#ifndef START_STAT_H
#define START_STAT_H

#include "Statements/Statement.h"
#include "ApplicationManager.h"

class StartStat : public Statement
{
private:
	Connector* pConn;	//start Stat has one Connector to next statement
	ApplicationManager* pApp;

	Point Outlet;

	virtual void UpdateStatementText();

public:
	StartStat(Point Center);

	Point getOutlet();

	virtual void Draw(Output* pOut) const;

	void Save(ofstream& myfile);
};

#endif