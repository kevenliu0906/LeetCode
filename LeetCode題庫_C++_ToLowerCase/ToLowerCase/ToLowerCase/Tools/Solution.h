#pragma once
#include <string>
using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		for (size_t i_i = 0; i_i<str.size(); i_i++)
		{
			str[i_i] = tolower(str[i_i]);
		}
		return (str);
	}
};
