#include "tinyxml.h"

class DataManager
{
public:
	DataManager();
	~DataManager();
	void LoadXML();
	static DataManager* GetInstance();
	/* data */
protected:
	static DataManager* m_DataManager;
	TiXmlDocument* m_xmlData;
};