#pragma once

#include "Actions/Action.h"
#include "Statements/Connector.h"
#include "Statements/Statement.h"
#include "ApplicationManager.h"

class AddConnector : public Action
{
	Point From;
	Point To;
	ApplicationManager* pApp;
	Statement* pSrc;
	Statement* pDst;

public:
	AddConnector(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};