#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
	int singleNumber(vector<int>& nums) {
		int Count_i = 0;
		int SingleNum_i = 0;
		for (size_t i_i = 0; i_i < nums.size(); i_i++)
		{
			Count_i = 0;
			for (size_t j_i = 0; j_i < nums.size(); j_i++)
			{
				if (nums[i_i] == nums[j_i])
					Count_i++;
				if (Count_i>1)    //因為題目只要求出現一次的元素，所以當出現2次以上的元素就直接離開，不需要繼續往下計數
					break;
			}
			if (Count_i == 1)
				return (nums[i_i]);
		}
		return (-1);
	}
};
