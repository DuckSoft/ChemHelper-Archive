// ===================================
// ChemHelper Project
// ===================================
//   化学式抽象 头文件
//

#ifndef _F8BB7BD7A790F6A2F2417AB1947420C2
#define _F8BB7BD7A790F6A2F2417AB1947420C2
#include "misc.h"
#include "advnum.h"
#include "rmm.h"

using namespace std;

typedef pair<string, unsigned int> str_uint_pair;
typedef map<string, unsigned int> AtomListMap;

class Formula {

	public:
		string strRaw;
		map<string, unsigned int> atoms;
		Formula(string inFormula);
		
		void showAtomList();
		AdvNum getMolarMass(RMDatabase* databaseFrom);
	private:
		void parseSubstring(string& strTodo, AtomListMap& parentList, unsigned int numMultiplier);
		void insertList(AtomListMap& listToInsert, str_uint_pair pairToInsert);
		void combineList(AtomListMap& listParent, AtomListMap& listChild);

};
#endif
