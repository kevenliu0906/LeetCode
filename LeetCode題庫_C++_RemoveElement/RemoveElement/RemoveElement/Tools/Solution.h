#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int    Count_i = 0;
		bool   Erase_fg = false;
		
		do
		{
			Erase_fg = false;
			for (size_t i_i = 0; i_i < nums.size(); i_i++)
			{
				if (nums[i_i] == val)
				{
					nums.erase(nums.begin() + i_i);
					Erase_fg = true;
					break;
				}
			}
		} while (Erase_fg);

		for (size_t i_i = 0; i_i < nums.size(); i_i++)
		{
			if (nums[i_i] != val)
				Count_i++;
		}

		return (Count_i);
	}
};
