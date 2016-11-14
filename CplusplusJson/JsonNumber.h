// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    Json Parser to Number
// ===============================================================================
// Filename Name       :    JsonNumber.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 12:48:20
// Update Time         :    
// ===============================================================================

#ifndef JSONNUMBER_H__
#define JSONNUMBER_H__

#include "JsonBaseData.h"

namespace json {
	// class JsonNumber
	class JsonNumber : public JsonBaseData {
	public:
		JsonNumber() : m_iData(0) { }
		JsonNumber(int data) : m_iData(data) { }

		virtual ~JsonNumber() { }

		virtual string toString() {
			return intToString(m_iData);
		}

	private:
		int m_iData;
	};
}

#endif  //JSONNUMBER_H__


