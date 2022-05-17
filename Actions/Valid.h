#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class Valid : public Action
{
public:
	Valid(ApplicationManager* pAppManager);

	void ReadActionParameters();

	void Execute();
};
