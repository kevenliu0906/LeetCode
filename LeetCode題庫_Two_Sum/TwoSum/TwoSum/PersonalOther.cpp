#include "stdafx.h"
#include "PersonalOther.h"

//------------------------------------------------------------------------------
int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
	int SizeLength_i = numsSize;
	bool Find_fg = false;
	int X_i = -1;
	int Y_i = -1;
	int *A_i_ay = (int*)malloc(sizeof(int) * 2);//new int[2];
	memset(A_i_ay, 0, 2);
	for (int i_i = 0; i_i<SizeLength_i; i_i++)
	{
		for (int j_i = i_i + 1; j_i<SizeLength_i; j_i++)
		{
			if (nums[i_i] + nums[j_i] == target)
			{
				Find_fg = true;
				X_i = i_i;
				Y_i = j_i;
				A_i_ay[0] = X_i;
				A_i_ay[1] = Y_i;
				*returnSize = 2;
				break;
			}
		}
		if (Find_fg)
			break;
	}
	if (Find_fg)
		*returnSize = 2;
	else
		*returnSize = 0;
	return A_i_ay;
}
//------------------------------------------------------------------------------