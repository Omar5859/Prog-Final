#ifndef LOAD_H
#define LOAD_H

#include "Action.h"
#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

#include "..\Statements\Statement.h"
class Load : public Action
{
	int StatCount;
	int ConnCount;
public:

	Load(ApplicationManager* Pointappmanager);

	//read assignemt statements position
	virtual void ReadActionParameters();

	//delete an assignemnt statement from the list of statements
	   virtual void Execute();

};



#endif