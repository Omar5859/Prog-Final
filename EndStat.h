#ifndef END_STAT_H
#define END_STAT_H

#include "Statements/Statement.h"
#include "ApplicationManager.h"

class EndStat : public Statement
{
private:
	Connector* pConn;	//end Stat has one Connector to next statement
	ApplicationManager* pApp;

	Point Inlet;
	Point Outlet;

	virtual void UpdateStatementText();

public:
	EndStat(Point Center);

	virtual Point getInlet() const;
	virtual Point getOutlet() const;

	virtual void Draw(Output* pOut) const;

	void Save(ofstream& myfile);
	void Edit(); 

	/*void Load(ifstream& takefile);*/
};

#endif