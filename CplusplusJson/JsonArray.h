// ===============================================================================
// Project Name        :    CplusplusJson
// Project Description :    Json Parser to Array
// ===============================================================================
// Filename Name       :    JsonArray.h
// Class Version       :    v1.0.0.0
// Class Description   :    
// Author              :    Tutuxs
// Email               :	tutuxsfly@126.com
// Create Time         :    2016/11/12 12:47:31
// Update Time         :    
// ===============================================================================

#ifndef JSONARRAY_H__
#define JSONARRAY_H__

#include "JsonBaseData.h"
#include "utils.h"

namespace json {
	// clas JsonDeleteArray
	class JsonDeleteArray {
	public:
		void operator()(JsonDataPtr ptr) {
			if (ptr) {
				delete ptr;
			}
		}
	};

	// class JsonArray
	class JsonArray : public JsonBaseData {
	public:
		typedef vector<JsonDataPtr>::iterator VecIterator;
		
		virtual ~JsonArray() {
			std::for_each(m_vecDatas.begin(), m_vecDatas.end(), JsonDeleteArray());
		}

		virtual string toString() {
			string ret = "[";
			for (size_t i = 0; i < m_vecDatas.size(); i++) {
				ret = ret + m_vecDatas[i]->toString() + ", ";
			}
			ret.erase(ret.size() - 2, 2);
			ret = ret + "]";
			return ret;
		}

		JsonDataPtr at(size_t n) {
			assert(n < m_vecDatas.size());		// ÓÐµã´Ö±©
			return m_vecDatas[n];
		}

		void addItem(JsonDataPtr data) {
			m_vecDatas.push_back(data);
		}

	private:
		vector<JsonDataPtr> m_vecDatas;
	};
}



#endif  //JSONARRAY_H__


