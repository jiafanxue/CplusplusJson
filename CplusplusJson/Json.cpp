// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    
// ===============================================================================
// Filename Name       :    Json.cpp
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 15:29:48
// Update Time         :    
// ===============================================================================

#include <stack>
#include <typeinfo>
#include <iostream>
#include "Json.h"
#include "utils.h"

using std::stack;

namespace json {
	Json::Json() : m_pRoot(NULL) { }

	Json::Json(JsonDataPtr data = NULL) : m_pRoot(data) { }

	Json::~Json() {
		delete m_pRoot;
	}

	Value Json::root() {
		Value value(m_pRoot);
		return value; 
	}

	void Json::setRoot(const Value& root) {
		if (m_pRoot) {
			delete m_pRoot;
		}

		m_pRoot = root.m_pData;
	}

	void addData(JsonDataPtr parent, JsonDataPtr data, string key) {
		if (typeid(*(parent)) == typeid(JsonObject)) {
			JsonObject* oData = dynamic_cast<JsonObject*>(parent);
			oData->addItem(key, data);
		}
		else if(typeid(*(parent)) == typeid(JsonArray)) {
			JsonArray* aData = dynamic_cast<JsonArray*>(parent);
			aData->addItem(data);
		}
	}

	bool inArrayLoop(JsonDataPtr parent) {
		if (typeid(*(parent)) == typeid(JsonArray)) {
			return true;
		}
		else {
			return false;
		}
	}

	const int EXCEPT_KEY = 0;
	const int EXCEPT_VALUE = 1;

	void Json::parse(const string& jsonStr) {
		stack<JsonDataPtr> dataStack;

		string key = "first";

		size_t len = jsonStr.length();
		size_t pos = 0;
		JsonDataPtr data = NULL;
		int exceptValue = EXCEPT_VALUE;

		while (len > pos) {
			if (jsonStr[pos] == ' ' || jsonStr[pos] == '\n' || jsonStr[pos] == '\t') {
				pos++;
				continue;
			}
			if (!dataStack.empty() && inArrayLoop(dataStack.top())) {
				exceptValue = EXCEPT_VALUE;
			}

			switch (jsonStr[pos])
			{
			default:
				if (isDigitChar(jsonStr[pos])) {
					assert(exceptValue == EXCEPT_VALUE);
					int start = pos;
					int end = start;
					while (isDigitChar(jsonStr[end])) {
						end++;
					}
					string val = jsonStr.substr(start, end - start);
					data = new JsonNumber(stringToInt(val));
					addData(dataStack.top(), data, key);
					exceptValue = EXCEPT_KEY;
					pos = end - 1;
				}
				break;
			case 't':
				assert(!dataStack.empty());
				assert(jsonStr.substr(pos, 4) == "true");
				assert(exceptValue == EXCEPT_VALUE);
				data = new JsonBool(true);
				addData(dataStack.top(), data, key);
				exceptValue = EXCEPT_VALUE;
				pos = pos + 3;
				break;
			case '[':
			case '{':
			{
				if (jsonStr[pos] == '[') {
					data = new JsonArray();
				}
				else {
					data = new JsonObject();
					exceptValue = EXCEPT_KEY;
				}

				if (!m_pRoot) {
					dataStack.push(data);
					m_pRoot = data;
				}
				else {
					addData(dataStack.top(), data, key);
					dataStack.push(data);
				}
				break; 
			}
			case '}':
				assert(!dataStack.empty());
				assert(typeid(*(dataStack.top())) == typeid(JsonObject));
				dataStack.top();
				break;
			case ']':
				assert(!dataStack.empty());
				assert(typeid(*(dataStack.top())) == typeid(JsonArray));
				dataStack.pop();
				break;
			case '\"':
				size_t pos2 = jsonStr.find('\"', pos + 1);
				assert(pos2 != std::string::npos);
				if (exceptValue == EXCEPT_VALUE) {
					key = jsonStr.substr(pos + 1, pos2 - (pos + 1));
					pos2 = jsonStr.find(':', pos2 - 1);
					assert(pos2 != std::string::npos);
					exceptValue = EXCEPT_VALUE;
				}
				else if(exceptValue == EXCEPT_VALUE) {
					assert(!dataStack.empty());
					string value = jsonStr.substr(pos + 1, pos2 - (pos + 1));
					data = new JsonString(value);
					addData(dataStack.top(), data, key);
					exceptValue = EXCEPT_KEY;
				}
				pos = pos2;
				break; 
			}
		}
	}

	string Json::toString() {
		return m_pRoot->toString();
	}

}



