#include "AddConnector.h"

#include "GUI/Input.h"
#include "GUI/Output.h"

AddConnector::AddConnector(ApplicationManager* pAppManager):Action(pAppManager)
{
	pApp = pAppManager;
	pSrc = NULL;
	pDst = NULL;
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
		pSrc = pApp->GetStatement(From);

	} while (pSrc = NULL);

	do
	{
		pOut->PrintMessage("Connector: Click to set the ending point of the connector");

		pIn->GetPointClicked(To);
		pOut->ClearStatusBar();

		pDst = pApp->GetStatement(To);

	} while (pDst = NULL);
}

void AddConnector::Execute()
{
	ReadActionParameters();
	
	Connector* pConn = new Connector(pSrc, pDst);

	pConn->setStartPoint(pSrc->getvStatY().second);
	pConn->setEndPoint(pDst->getvStatY().first);

	pApp->AddConnectorList(pConn);
}