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
				if (Count_i>1)    //�]���D�إu�n�D�X�{�@���������A�ҥH��X�{2���H�W�������N�������}�A���ݭn�~�򩹤U�p��
					break;
			}
			if (Count_i == 1)
				return (nums[i_i]);
		}
		return (-1);
	}
};
