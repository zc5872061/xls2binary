#include "msg.pb.h"  
#include "tinyxml.h"
#include "tconf.pb.h"
#include "DataManager.h"
#include <fstream>  
#include <iostream>  

using namespace std;  
  
int main(void)   
{   
  
  	TiXmlDocument* myDocument = new TiXmlDocument("res/Sheet1.xml");
    myDocument->LoadFile();
    myDocument->Print();

    DataManager* dataManager = DataManager::GetInstance();

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
    TconfColDef tconfColDef;  
    msg1.set_id(101);   
    msg1.set_str("hello");   
    fstream output("./log", ios::out | ios::trunc | ios::binary);   
  
    if (!msg1.SerializeToOstream(&output)) {   
        cerr << "Failed to write msg." << endl;   
        return -1;   
    }          
    return 0;   
}  
