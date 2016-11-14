// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    Json Parser to String
// ===============================================================================
// Filename Name       :    JsonString.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 12:48:53
// Update Time         :    
// ===============================================================================

#ifndef JSONSTRING_H__
#define JSONSTRING_H__

#include "JsonBaseData.h"

namespace json {
	// class JsonString
	class JsonString : public JsonBaseData {
	public:	
		JsonString() : m_sData() { }
		JsonString(const string& data) : m_sData(data) { }

		virtual ~JsonString() { }

		virtual string toString() {
			return "\"" + m_sData + "\"";
		}

	private:
		string m_sData;

	};
}


#endif  //JSONSTRING_H__


