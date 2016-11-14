// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    
// ===============================================================================
// Filename Name       :    JsonBaseData.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 13:00:45
// Update Time         :    
// ===============================================================================

#ifndef JSONBASEDATA_H__
#define JSONBASEDATA_H__

#include <string>
#include <map>
#include <assert.h>
#include <vector>
#include <algorithm>
#include "utils.h"

using std::map;
using std::string;
using std::vector;

namespace json {
	// class JsonDataBase
	class JsonBaseData
	{
	public:
		virtual string toString() {
			return "JsonDataBase";
		}

		virtual ~JsonBaseData() { }
	};

	typedef JsonBaseData* JsonDataPtr;
}

#endif  //JSONBASEDATA_H__


