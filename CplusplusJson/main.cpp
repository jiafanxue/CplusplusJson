// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    Main entrance of the method
// ===============================================================================
// Filename Name       :    main.cpp
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 11:44:56
// Update Time         :    
// ===============================================================================

#include <iostream>
#include <fstream>
#include "json.h"

using std::cout;
using std::endl;

using namespace json;

void test_parse();

int main()
{
	// test
	test_parse();

	return 0;
}

void test_parse()
{
	Json json;
	Value arrayValue = makeArrayValue();
	Value stringValue1 = makeStringValue("name1");
	Value stringValue2 = makeStringValue("name2");

	Value objectValue = makeObjectValue();
	Value numValue = makeNumberValue(2345);
	Value boolValue = makeBoolValue(false);
	Value stringValue3 = makeStringValue("value3");
	objectValue.addValue("num", numValue);
	objectValue.addValue("bool", boolValue);
	objectValue.addValue("name3", stringValue3);

	arrayValue.addValue(stringValue1);
	arrayValue.addValue(stringValue2);
	arrayValue.addValue(objectValue);
	json.setRoot(arrayValue);

	cout << json.toString() << endl;


}


