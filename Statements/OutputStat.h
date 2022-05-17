#include "Statement.h"
#include "../ApplicationManager.h"
#include <vector>

#ifndef OUTPUT_STAT_H
#define OUTPUT_STAT_H
//OutputStat statement class
//OutputStat  statement 
class OutputStat : public Statement
{
private:
	string OutT; //text or value written 
	//if value will be converted to string.

	vector<string> v1;

	Connector* pConn;	//Input Stat. has one Connector to next statement
	ApplicationManager* pApp;

	Point Inlet;
	Point Outlet;

	virtual void UpdateStatementText();

public:
	OutputStat(Point Center, string text);

	OutputStat(ApplicationManager*Pointer);
	//needed for the load pointer

	void setOutT(const string& L);

	//void setOutV(double R);

	virtual void Draw(Output* pOut) const;

	Point getInlet();
	Point getOutlet();

	void Save(ofstream& myfile);

	//void Load(ifstream& takefile);
};

#endif