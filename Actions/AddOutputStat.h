#ifndef ADD_OUTPUT_H
#define ADD_OUTPUT_H

#include "Action.h"
#include "..\Statements\OutputStat.h"
#include "..\ApplicationManager.h"

class AddOutputStat : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
	string Variable; // text
public:
	AddOutputStat(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif
