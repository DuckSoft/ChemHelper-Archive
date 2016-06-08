// ===================================
// ChemHelper Project
// ===================================
//   相对分子质量计算 头文件 
//

#ifndef _2713AD21890D9A3CFFBD8E72DDA619CB
#define _2713AD21890D9A3CFFBD8E72DDA619CB
#include "advnum.h"
#include "misc.h"
using namespace std;

class RMDatabase {
	public:
		RMDatabase();
		void loadDataDefault();
		bool addCustomAtom(string strAtom, AdvNum numMassRelative);
		AdvNum queryAtom(string strAtom);
	private:
		map<string, AdvNum> dataRM;
};

#endif 
