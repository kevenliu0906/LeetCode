#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums) {

		for (size_t i_i = 0; i_i < nums.size(); i_i++)
		{
			if (i_i + 1 < nums.size())
			{
				if (nums[i_i] != nums[i_i + 1])
					continue;
			}
			for (size_t j_i = i_i + 1; j_i < nums.size(); j_i++)
			{
				if (nums[i_i] == nums[j_i])
				{
					nums.erase(begin(nums) + j_i);
					j_i--;
					continue;
				}
				else  //因為輸入vector是有sort過，所以只要資料沒有相同就可以不用比對這輪，直接跳下一輪比對
					break;
			}
		}

		return (nums.size());
	}
};