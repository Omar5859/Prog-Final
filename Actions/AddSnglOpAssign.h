#ifndef ADD_SNGL_OP_ASSIGN_H
#define ADD_SNGL_OP_ASSIGN_H

#include "Action.h"
#include "..\Statements\SnglOpAssign.h"
#include "..\ApplicationManager.h"

//Add Single operand Assignment Statement Action
//This class is responsible for 
// 1 - Getting Assignment stat. coordinates from the user
// 2 - Creating an object of Assignment class and fill it parameters
// 3 - Adding the created object to the list of statements
class AddSnglOpAssign : public Action
{
private:
	Point Position;	//Position where the user clicks to add the stat.
	string LeftText; //LHS text
	double RightValue; //RHS value
	string RightString; //RHS string 
	string operand; //operand 
public:
	AddSnglOpAssign(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();

};

#endif
#pragma once
