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
				else  //�]����Jvector�O��sort�L�A�ҥH�u�n��ƨS���ۦP�N�i�H���Τ��o���A�������U�@�����
					break;
			}
		}

		return (nums.size());
	}
};