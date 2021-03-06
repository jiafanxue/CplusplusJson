// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    
// ===============================================================================
// Filename Name       :    Json.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 11:51:34
// Update Time         :    
// ===============================================================================

#ifndef JSON_H__
#define JSON_H__

#include <vector>
#include <string>
#include "JsonValue.h"

using std::vector;
using std::string;

namespace json {
	// class Json
	class Json {
	public:
		Json();
		Json(JsonDataPtr data);
		~Json();

		void parse(const string& jsonStr);
		string toString();
		Value root();
		void setRoot(const Value& root);

	private:
		JsonDataPtr m_pRoot;
	};
}


#endif  //JSON_H__


