// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    Json Parser to Object
// ===============================================================================
// Filename Name       :    JsonObject.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 12:48:36
// Update Time         :    
// ===============================================================================

#ifndef JSONOBJECT_H__
#define JSONOBJECT_H__

#include <utility>	// for pair;   template <class T1, class T2> struct pair;
#include "JsonBaseData.h"

namespace json {
	// class JsonDeleteObject
	class JsonDeleteObject {
	public:
		void operator()(const std::pair<string, JsonDataPtr>& p) {
			if (p.second) {
				delete p.second;
			}
		}
	};

	// class JsonObject
	class JsonObject : public JsonBaseData {
	public:
		typedef map<string, JsonDataPtr>::iterator MapIteraotr;
			
		JsonObject() : m_mapDatas() { }
		
		virtual ~JsonObject() {
			std::for_each(m_mapDatas.begin(), m_mapDatas.end(), JsonDeleteObject());
		}

		virtual string toString() {
			string ret = "{";
			for (MapIteraotr iter = m_mapDatas.begin(); iter != m_mapDatas.end(); iter++) {
				ret = ret + "\"" + iter->first + "\" : " + iter->second->toString() + ", ";
			}
			ret.erase(ret.size() - 2, 2);	// 为了清除最后一个“， ”
			ret = ret + "}";
			return ret;
		}

		JsonBaseData* get(const string& key) {
			return m_mapDatas[key];
		}

		void addItem(string key, JsonDataPtr value) {
			m_mapDatas.insert(std::make_pair(key, value));
		}

	private:
		map<string, JsonDataPtr> m_mapDatas;
	};
}

#endif  //JSONOBJECT_H__


