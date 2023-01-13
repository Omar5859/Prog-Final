#include "AddConnector.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddConnector::AddConnector(ApplicationManager* pAppManager):Action(pAppManager)
{
	pApp = pAppManager;
	pSrc = NULL;
	pDst = NULL;
}

void AddConnector::setSrc(Statement* S1)
{
	pSrc = S1;
}

void AddConnector::setDst(Statement* S2)
{
	pDst = S2;
}

void AddConnector::ReadActionParameters()
{
	Input* pIn = pApp->GetInput();
	Output* pOut = pApp->GetOutput();


	do
	{
		pOut->PrintMessage("Connector: Click to set the starting point of the connector");

		pIn->GetPointClicked(From);
		pOut->ClearStatusBar();

	} while (pSrc = NULL);

	setSrc(pApp->GetStatement(From));

	do
	{
		pOut->PrintMessage("Connector: Click to set the ending point of the connector");

		pIn->GetPointClicked(To);
		pOut->ClearStatusBar();

	} while (pDst = NULL);

	setDst(pApp->GetStatement(To));

}

void AddConnector::Execute()
{
	ReadActionParameters();
	
	Connector* pConn = new Connector(pSrc, pDst);

	pApp->AddConnectorList(pConn);
}