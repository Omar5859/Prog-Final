#ifndef save_h
#define save_h

#include "Actions/Action.h"
#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

#include "Statements/Statement.h"

class Save : public Action
{
private:
	Point Position;	//position where the user clicks to add the stat.
public:
	Save(ApplicationManager* Pointappmanager);

	//read assignemt statements position
	void ReadActionParameters();

	//delete an assignemnt statement from the list of statements
	void Execute();

};

#endif