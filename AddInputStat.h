#ifndef ADD_INPUT_H
#define ADD_INPUT_H

#include "Actions/Action.h"
#include "InputStat.h"
#include "ApplicationManager.h"

class AddInputStat : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
	double value; // value
public:
	AddInputStat(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif