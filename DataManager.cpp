#include "DataManager.h"
#include <iostream>


using namespace std;

DataManager* DataManager::m_DataManager = NULL;

DataManager::DataManager()
{
	cout<<"DataManager()"<<endl;
}

DataManager::~DataManager()
{
	cout<<"~DataManager()"<<endl;
}

DataManager* DataManager::GetInstance()
{
	if(m_DataManager == NULL)
	{
		m_DataManager = new DataManager();
	}
	return m_DataManager;
}

void DataManager::LoadXML()
{

}