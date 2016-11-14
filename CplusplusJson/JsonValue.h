// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    
// ===============================================================================
// Filename Name       :    JsonValue.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 11:58:07
// Update Time         :    
// ===============================================================================

#ifndef JSONVALUE_H__
#define JSONVALUE_H__

#include <typeinfo>
#include "JsonComment.h"

namespace json {

	enum JsonDataType {
		TYPE_BOOL,
		TYPE_OBJECT,
		TYPE_STRING,
		TYPE_NUMBER,
		TYPE_ARRAY,
	};

	// class Value
	class Value {
	public:
		friend class Json;

		Value() : m_pData(NULL) { }
		Value(JsonDataPtr data) : m_pData(data) { }

		void addValue(Value value) {
			assert(typeid(*m_pData) == typeid(JsonArray));
			JsonArray* data = dynamic_cast<JsonArray*>(m_pData);
			data->addItem(value.m_pData);
		}

		void addValue(const string& key, Value value) {
			assert(typeid(*m_pData) == typeid(JsonObject));
			JsonObject* data = dynamic_cast<JsonObject*>(m_pData);
			data->addItem(key, value.m_pData);
		}

		Value operator[](size_t n) {
			assert(typeid(*m_pData) == typeid(JsonArray));
			JsonArray* data = dynamic_cast<JsonArray*>(m_pData);
			Value value(data->at(n));
			return value;
		}

		Value operator[](string key) {
			assert(typeid(*m_pData) == typeid(JsonObject));
			JsonObject* data = dynamic_cast<JsonObject*>(m_pData);
			Value value(data->get(key));
			return value;
		}

		string toString() {
			return m_pData->toString();
		}

	private:
		JsonDataPtr m_pData;
	};
	
	static Value makeBoolValue(bool data) {
		Value value(new JsonBool(data));
		return value;
	}

	static Value makeStringValue(string data) {
		Value value(new JsonString(data));
		return value; 
	}

	static Value makeArrayValue() {
		Value value(new JsonArray());
		return value;
	}

	static Value makeObjectValue() {
		Value value(new JsonObject());
		return value;
	}

	static Value makeNumberValue(int data) {
		Value value(new JsonNumber(data));
		return value;
	}
	
}

#endif  //JSONVALUE_H__


