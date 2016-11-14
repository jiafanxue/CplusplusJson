// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    Json Parser to Bool 
// ===============================================================================
// Filename Name       :    JsonBool.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 12:47:53
// Update Time         :    
// ===============================================================================

#ifndef JSONBOOL_H__
#define JSONBOOL_H__

#include "JsonBaseData.h"

namespace json {
	// class JsonBool
	class JsonBool : public JsonBaseData {
	public:
		JsonBool() : m_bData(false) { }
		JsonBool(bool data) : m_bData(data) { }

		virtual ~JsonBool() { }

		virtual string toString() {
			if (m_bData) {
				return "true";
			}
			else {
				return "false";
			}
		}

	private:
		bool m_bData;
	};
}



#endif  //JSONBOOL_H__


