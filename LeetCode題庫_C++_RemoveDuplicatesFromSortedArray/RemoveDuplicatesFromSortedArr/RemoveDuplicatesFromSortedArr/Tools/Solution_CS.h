#pragma once
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(vector<int>& nums) {
		bool   RemoveElement_fg = true;
		do {
			RemoveElement_fg = false;
			for (size_t i_i = 0; i_i < nums.size(); i_i++)
			{
				for (size_t j_i = i_i + 1; j_i < nums.size(); j_i++)
				{
					if (nums[i_i] == nums[j_i])
					{
						RemoveElement_fg = true;
						nums.erase(begin(nums) + j_i);
						break;
					}
					else
						break;
				}
				if (RemoveElement_fg)
					break;
			}
		} while (RemoveElement_fg);

		return (nums.size());
	}
};