//
//  DataManager.cpp
//  HelloCpp
//
//  Created by Chukie on 14-10-22.
//
//

#include "DataManager.h"
#include <iostream>


using namespace std;

DataManager* DataManager::m_DataManager = NULL;

DataManager::DataManager()
{
    m_xmlData = NULL;
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

bool DataManager::LoadXML(string file)
{
    bool ret = false;
    
    do
    {
        m_xmlData = new TiXmlDocument(file.c_str());
        if(m_xmlData->LoadFile())
            ret = true;
    }
    while (0);
    
    return ret;
}

void DataManager::ReadData()
{
    TiXmlElement* pRoot = m_xmlData->RootElement();
    TiXmlElement* itemElement = pRoot->FirstChildElement();
    //cout<<first->FirstAttribute()->Value();
    
    
    //fill data in columns
    if(itemElement == NULL)
        return;
    TiXmlAttribute* tempAttribute = itemElement->FirstAttribute();
    for (; tempAttribute != NULL; tempAttribute = tempAttribute->Next()) {
        columns.push_back(tempAttribute->Name());
    }
    //fill data in rows
    
    for (; itemElement != NULL; itemElement = itemElement->NextSiblingElement()) {
        TiXmlAttribute* itemElementAttri = itemElement->FirstAttribute();
        vector<string>* vecStr = new vector<string>;
        for (; itemElementAttri != NULL; itemElementAttri = itemElementAttri->Next()) {
            vecStr->push_back(itemElementAttri->Value());
        }
        rows.push_back(vecStr);
    }
    
}

int DataManager::getColumnSize()
{
    return columns.size();
}

int DataManager::getRowsSize()
{
    return rows.size();
    
}

string DataManager::getData(int column,int row)
{
    string ret = "";
    if(column < getColumnSize())
    {
        if(row < getRowsSize())
        {
            ret = (*rows[row])[column];
        }
    }
    return ret;
    
}

vector<string> DataManager::getColumns()
{
    return columns;
}
