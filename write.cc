#include "msg.pb.h"  
#include "tinyxml.h"
#include "tconf.pb.h"
#include "DataManager.h"
#include <fstream>  
#include <iostream>  

using namespace std;  
  
int main(void)   
{   
  
    DataManager* dataManager = DataManager::GetInstance();
    dataManager->LoadXML("res/Sheet1.xml");
    dataManager->ReadData();

    vector<string> tmp = dataManager->getColumns();

    TconfTable table;

    for(int i = 0; i < tmp.size();i ++)
    {
        TconfColDef* tconfColDef = table.add_coldefs(); 
        tconfColDef->set_name(tmp[i].c_str());
        tconfColDef->set_type("string");
    }

    cout<<"size"<<table.coldefs_size()<<endl;

    for(int j = 0;j<table.coldefs_size(); j++)
    {
        cout<<"name"<<table.coldefs(j).name().c_str()<<endl;    
    }
    cout<<"row size"<<dataManager->getRowsSize()<<endl;
    cout<<"column size"<<dataManager->getColumnSize()<<endl;

    for(int i = 0; i < dataManager->getRowsSize();i++)
    {
        TconfRow* tconfRows = table.add_rows();
        cout<<"i :"<<i<<endl;
        for (int j = 0; j < dataManager->getColumnSize();j++)
        {
            /* code */
            cout<<"j :"<<j<<endl;
            cout<<dataManager->getData(j,i).c_str()<<endl;
            tconfRows->add_values(dataManager->getData(j,i));
        }

    }
    
    cout<<"row size"<<table.rows_size()<<endl;

    fstream output("./log", ios::output | ios::trunc |ios::binary);

    // if(myDocument.LoadFile("res/Sheet1.xml"))
    // {
    //     myDocument.Print();
    // }
    // else
    // {
    //     cout<<"error"<<endl;
    // }
    
    //test *t = new test();
    lm::helloworld msg1; 
 
    msg1.set_id(101);   
    msg1.set_str("hello");   
    fstream output("./log", ios::out | ios::trunc | ios::binary);   
  
    if (!msg1.SerializeToOstream(&output)) {   
        cerr << "Failed to write msg." << endl;   
        return -1;   
    }          
    return 0;   
}  
