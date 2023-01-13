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

	void setSrc(Statement* S1);
	void setDst(Statement* S2);

	virtual void ReadActionParameters();

	virtual void Execute();
};