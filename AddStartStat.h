#ifndef ADD_START_STAT_H
#define ADD_START_STAT_H 

#include "Actions/Action.h"
#include "StartStat.h"
#include "ApplicationManager.h"

#include <sstream>

class AddStartStat : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.

public:
	AddStartStat(ApplicationManager* pAppManager);

	//Read End statements position

	virtual void ReadActionParameters();

	//Create and add an Start statement to the list of statements

	virtual void Execute();
};

#endif