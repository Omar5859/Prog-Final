#pragma once
#ifndef ADD_VAR_ASSIGN_H
#define ADD_VAR_ASSIGN_H

#include "..\Statements\VarAssign.h"
#include "Action.h"
#include "..\ApplicationManager.h"

//Add Variable Assignment Statement Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements
class AddVarAssign : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
	string LeftText; //LHS text
	string RightText; //RHS value
public:
	AddVarAssign(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};



#endif
