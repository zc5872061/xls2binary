//
//  DataManager.h
//  HelloCpp
//
//  Created by Chukie on 14-10-22.
//
//

#ifndef __HelloCpp__DataManager__
#define __HelloCpp__DataManager__

#include "tinyxml.h"
#include <string>
#include <vector>

using namespace std;

class DataManager
{
public:
    DataManager();
    ~DataManager();
    bool LoadXML(string file);
    void ReadData();
    int getColumnSize();
    int getRowsSize();
    string getData(int column,int row);
    vector<string> getColumns();
    static DataManager* GetInstance();
    /* data */
protected:
    static DataManager* m_DataManager;
    TiXmlDocument* m_xmlData;
    vector<string> columns;
    vector<vector<string>*> rows;
};

#endif /* defined(__HelloCpp__DataManager__) */
