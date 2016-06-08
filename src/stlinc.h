// ===================================
// ChemHelper Project
// ===================================
//   STL标准模板库公共头文件
//

#ifndef _dbc854e917004234b42cf8f1ab874fac
#define _dbc854e917004234b42cf8f1ab874fac

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <map>
#include <exception>
#include <iomanip>
#include <regex>

class MyException : public std::exception {
	public:
		MyException() {

		}

		MyException(std::string strException) {
			std::cout << strException << std::endl;
		}
};
#endif
