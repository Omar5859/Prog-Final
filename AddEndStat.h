#ifndef ADD_END_STAT_H
#define ADD_END_STAT_H 

#include "Actions/Action.h"
#include "EndStat.h"
#include "ApplicationManager.h"

#include <sstream>

class AddEndStat : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.

public:
	AddEndStat(ApplicationManager* pAppManager);

	//Read End statements position

	virtual void ReadActionParameters();

	//Create and add an End statement to the list of statements

	virtual void Execute();

};
#endif