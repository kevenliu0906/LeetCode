#pragma once
#include <string>
using namespace std;

class Solution {
public:
	bool isValid(string s) {
		bool Legal_fg = false;
		int  RightIndex_i = 0;
		int  LeftIndex_i = 0;
		bool DeleteElement_fg = false;

		if ((int)s.size() % 2)  // 奇數個字串符號
			return false;

		if (s.size() == 0)       // 輸入為空字串
			return true;

		do {
			DeleteElement_fg = false;
			Legal_fg = false;
			for (size_t i_i = 0; i_i < s.size(); i_i++)
			{
				if (s[i_i] == ')')
				{
					RightIndex_i = i_i;
					if (i_i == 0)
						return false;
					Legal_fg = true;
					for (size_t j_i = i_i - 1; j_i >= 0; j_i--)
					{
						if (s[j_i] == '(')
						{
							Legal_fg = true;
							//s.erase(begin(s) + j_i);
							LeftIndex_i = j_i;
							break;
						}
						if (s[j_i] == '[')
						{
							Legal_fg = false;
							break;
						}
						if (s[j_i] == '{')
						{
							Legal_fg = false;
							break;
						}
					}
					if (!Legal_fg)
						break;
					else
					{
						if (LeftIndex_i < RightIndex_i)
						{
							// 先從最右邊開始刪除
							s.erase(begin(s) + RightIndex_i);
							s.erase(begin(s) + LeftIndex_i);
							DeleteElement_fg = true;
						}
						else
						{
							// 先從最右邊開始刪除
							s.erase(begin(s) + LeftIndex_i);
							s.erase(begin(s) + RightIndex_i);
							DeleteElement_fg = true;
						}
						break;
						//s.erase(begin(s) + i_i);
					}
				}
				else if (s[i_i] == ']')
				{
					RightIndex_i = i_i;
					if (i_i == 0)
						return false;
					Legal_fg = true;
					for (size_t j_i = i_i - 1; j_i >= 0; j_i--)
					{
						if (s[j_i] == '[')
						{
							Legal_fg = true;
							//s.erase(begin(s) + j_i);
							LeftIndex_i = j_i;
							break;
						}
						if (s[j_i] == '(')
						{
							Legal_fg = false;
							break;
						}
						if (s[j_i] == '{')
						{
							Legal_fg = false;
							break;
						}
					}
					if (!Legal_fg)
						break;
					else
					{
						if (LeftIndex_i < RightIndex_i)
						{
							// 先從最右邊開始刪除
							s.erase(begin(s) + RightIndex_i);
							s.erase(begin(s) + LeftIndex_i);
							DeleteElement_fg = true;
						}
						else
						{
							// 先從最右邊開始刪除
							s.erase(begin(s) + LeftIndex_i);
							s.erase(begin(s) + RightIndex_i);
							DeleteElement_fg = true;
						}
						break;
						//s.erase(begin(s) + i_i);
					}
				}
				else if (s[i_i] == '}')
				{
					RightIndex_i = i_i;
					if (i_i == 0)
						return false;
					Legal_fg = true;
					for (size_t j_i = i_i - 1; j_i >= 0; j_i--)
					{
						if (s[j_i] == '{')
						{
							Legal_fg = true;
							//s.erase(begin(s) + j_i);
							LeftIndex_i = j_i;
							break;
						}
						if (s[j_i] == '(')
						{
							Legal_fg = false;
							break;
						}
						if (s[j_i] == '[')
						{
							Legal_fg = false;
							break;
						}
					}
					if (!Legal_fg)
						break;
					else
					{
						if (LeftIndex_i < RightIndex_i)
						{
							// 先從最右邊開始刪除
							s.erase(begin(s) + RightIndex_i);
							s.erase(begin(s) + LeftIndex_i);
							DeleteElement_fg = true;
						}
						else
						{
							// 先從最右邊開始刪除
							s.erase(begin(s) + LeftIndex_i);
							s.erase(begin(s) + RightIndex_i);
							DeleteElement_fg = true;
						}
						break;
						//s.erase(begin(s) + i_i);
					}
				}
			}
		} while (DeleteElement_fg && s.size()>0);

		return (Legal_fg);
	}
};