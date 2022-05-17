#include "ApplicationManager.h"

#include "Actions\AddSmplAssign.h"
#include "AddCondition.h"
#include "AddStartStat.h"
#include "AddEndStat.h"
#include "Actions/AddVarAssign.h"
#include "Actions/AddSnglOpAssign.h"
#include "AddConnector.h"
#include "AddInputStat.h"
#include "Actions/AddOutputStat.h"
#include "Save.h"

#include "GUI/Input.h"
#include "GUI\Output.h"

#include <vector>
#include <string>

Point pt;
int ApplicationManager::selectionCount = 0;
pair<int, int> NewCoord;
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();

	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pSelectedConn = NULL;   

	ArrX = new pair<int,int>[200];      //Array of pairs where each pair contains the most right x coordinate and the most left x coordinate of any shape
	ArrY = new pair<int,int>[200];      //Array of pairs where each pair contains the most top y coordinate and the most bottom y coordinate of any shape

	UI.AppMode = DESIGN;

	//Create an array of Statement & Connector pointers and set them to NULL		
	for (int i = 0; i < MaxCount; i++)
	{
		StatList[i] = NULL;
		ConnList[i] = NULL;
	}
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;

	//According to ActionType, create the corresponding action object
	switch (ActType)
	{
	case ADD_START_STAT:
		pAct = new AddStartStat(this);
		break;

	case ADD_INPUT:
		pAct = new AddInputStat(this);
		break;

	case ADD_SMPL_ASSIGN:
		pAct = new AddSmplAssign(this);
		break;

	case ADD_VAR_ASSIGN:
		pAct = new AddVarAssign(this);
		break;

	case ADD_SO_ASSIGN:
		pAct = new AddSnglOpAssign(this);
		break;

	case ADD_CONDITION:
		///create AddCondition Action here
		pAct = new AddCondition(this);
		break;

	case ADD_CONNECTOR:
		pAct = new AddConnector(this);
		break;
		
	case ADD_OUTPUT:
		pAct = new AddOutputStat(this);
		break;

	case SELECT:
		///create Select Action here
		pOut->PrintMessage("Select");
		pIn->GetPointClicked(pt);
		SetSelectedStatement(pSelectedStat, pt);
		if (pSelectedStat != NULL) {
			if (pSelectedStat->IsSelected()) 
			{
				pSelectedStat->SetSelected(false);
				selectionCount -= 1;
				MultiSelections[selectionCount] = -1; //emptying array
			}
			else 
			{
				pSelectedStat->SetSelected(true);
				MultiSelections[selectionCount] = pSelectedStat->GetID();
				selectionCount += 1;
			}
			UpdateInterface();
		}
		pOut->ClearStatusBar();
		break;

	case MOVE:
		pOut->PrintMessage("Choose the new position or positions");

		//for (int i = 0; i < selectionCount; i++) {
		NewCoord = pSelectedStat->SetCenterPoint(pIn);
		pSelectedStat->setvStatX(NewCoord.first);
		pSelectedStat->setvStatY(NewCoord.second);
		UpdateStat(pSelectedStat->GetID());
		pOut->ClearDrawArea();
		UpdateInterface();
		pOut->ClearStatusBar();
		//}
		break;

	case SAVE:
		pAct = new Save(this);
		break;

	case EXIT:
		///create Exit Action here

		break;

	case ADD_END_STAT:
		pAct = new AddEndStat(this);
		break;

	case SIM_MODE:
		pOut->PrintMessage("Switching to Simulation Mode");
		pOut->CreateSimulationToolBar();
		pOut->ClearDrawArea();
		break;

	case DSN_MODE:
		pOut->PrintMessage("Switching to Design Mode");
		pOut->CreateDesignToolBar();
		pOut->ClearDrawArea();
		break;
		
	case STATUS:
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}


//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//
//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement* pStat)
{
	for (int i = 0; i < StatCount; i++)  //To avoid overlapping of shapes
	{
		if ((pStat->getvStatX().first < ArrX[i].second && pStat->getvStatX().first > ArrX[i].first) || (pStat->getvStatX().second < ArrX[i].second&& pStat->getvStatX().second > ArrX[i].first))   //Checking if the left x coordinate of the pair is inside the shape range and same for y coordinate 
		{
			if ((pStat->getvStatY().first < ArrY[i].second && pStat->getvStatY().first > ArrY[i].first) || (pStat->getvStatY().second < ArrY[i].second && pStat->getvStatY().second > ArrY[i].first))
			{
				pOut->PrintMessage("Error! Overlapping statements");
				return;  //Return so that the statement is not added due to the overlapping
			}
		}
	}
	if (StatCount < MaxCount)
	{
		ArrX[StatCount] = (pStat->getvStatX());   //Add statement shape coordinates to the array of pairs
		ArrY[StatCount] = (pStat->getvStatY());
		StatList[StatCount++] = pStat;            //Add statement to the array of statements and increasing stat count by 1
	}
	else
		pOut->PrintMessage("Error! Max number of statements is reached");
}

////////////////////////////////////////////////////////////////////////////////////
Statement* ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL


	///Add your code here to search for a statement given a point P(x,y)

	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i] == NULL)
			continue;
		if (P.x < ArrX[i].second && P.x > ArrX[i].first)      //Checking if point P is inside the statement
		{
			if (P.y < ArrY[i].second && P.y > ArrY[i].first)
				return StatList[i];
		}
	}
	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement* & ApplicationManager::GetSelectedStatement() 
{
	return pSelectedStat;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement* pStat, Point pt)
{
	pStat = GetStatement(pt);
	pSelectedStat = pStat;
}

void ApplicationManager::AddConnectorList(Connector* pConn)
{
	if (ConnCount < MaxCount)
		ConnList[ConnCount++] = pConn;
	else
		pOut->PrintMessage("Error! Max number of Connectors is reached");
}

Connector* ApplicationManager::GetConnector(Point P) const
{
	//Mehtaga tafkeer hn get el point ezay enaha bt belong ll connector, zy el statement bzabt

	return NULL;
}

void ApplicationManager::SetSelectedConnector(Connector* pConn)
{
	pSelectedConn = pConn;
}

Connector* & ApplicationManager::GetSelectedConnector()
{
	return pSelectedConn;
}

int ApplicationManager::GetStatCount()
{
	return StatCount;
}

int ApplicationManager::GetConnCount()
{
	return ConnCount;
}

Statement** ApplicationManager::GetStatList()
{
	return StatList;
}

Connector** ApplicationManager::GetConnList()
{
	return ConnList;
}

void ApplicationManager::SaveChart(ofstream& myfile)
{
	for (int j = 0; j < StatCount; j++)
	{
		if (StatList[j] != NULL)
		{
			StatList[j]->Save(myfile);
		}
	}

	/*for (int j = 0; j < ConnCount; j++)
	{
		if (ConnList[j] != NULL)
		{
			ConnList[j]->Save(myfile);
		}
	}*/
}

void ApplicationManager::UpdateStat(int id) 
{
	ArrX[id] = pSelectedStat->getvStatX();
	ArrY[id] = pSelectedStat->getvStatY();
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	//Draw all statements
	for (int i = 0; i < StatCount; i++)
		StatList[i]->Draw(pOut);

	//Draw all connections
	for (int i = 0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////

bool ApplicationManager::Validation()
{

	while (StatCount == 0)
	{
		pOut->PrintMessage("The design has no Statements");
		return false;
	}
	int NumberOfStarts = 0;
	int NumberOfEnds = 0;
	bool IsValidChart = true;
	for (int j = 0; j < StatCount; j++)

	{//dynamic Casting to check that I have only one StartStat in the chart by checking the array of statements being applied.
		if (dynamic_cast<StartStat*>(StatList[j]))
			NumberOfStarts++;
		else if (dynamic_cast<EndStat*>(StatList[j]))
			NumberOfEnds++;
	}

	//The following   process to check that only text or string could be written on the left handside.
	//done with asci code check.

	for (int j = 0; j < StatCount; j++)
	{
		if (dynamic_cast<SmplAssign*>(StatList[j]))
		{
			SmplAssign* Inp = (SmplAssign*)StatList[j];

			for (int i = 0; i < Inp->getLHS().length(); i++)
			{
				char x = Inp->getLHS().at(i);
				if (101 <= int(x) <= 132 || 141 <= int(x) <= 172)
				{

					IsValidChart = true;
					break;
				}
				else
				{
					IsValidChart = false;
					break;
				}
			}
		}
		//Still do not have the connector yet (to perform validation on it).
	}

	for (int j = 0; j < StatCount; j++)
	{
		if (dynamic_cast<SnglOpAssign*>(StatList[j]))
		{
			SnglOpAssign* Inp = (SnglOpAssign*)StatList[j];

			for (int i = 0; i < Inp->getOp().length(); i++)
			{
				char x = Inp->getOp().at(i);
				if (int(x) == 74 || int(x) == 75 || int(x) == 76)  //74 (<)    //75(=)    // 76(>)  (Askicode)
				{

					IsValidChart = true;
					break;
				}
				else
				{
					IsValidChart = false;
					break;
				}
			}
		}
		//Still do not have the connector yet (to perform validation on it).
	}

	if (NumberOfStarts > 1 || NumberOfStarts < 1 || NumberOfEnds > 1 || NumberOfEnds < 1)
	{
		IsValidChart = false;
	}

	if (IsValidChart == false)
	{
		pOut->PrintMessage("Chart Invalid!");
	}
	if (IsValidChart)

		pOut->PrintMessage("Valid Chart!");
	return true;
}

//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < StatCount; i++)
		delete StatList[i];
	for (int i = 0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;

}
