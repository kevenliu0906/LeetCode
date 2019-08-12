#include "stdafx.h"
#include "PersonalOther.h"

int searchInsert(int* nums, int numsSize, int target)
{
	int    MinIndex_i = 0;
	int    MaxIndex_i = 0;
	int    CompareIndex_i = numsSize - 1;

	while (CompareIndex_i >= 0)
	{
		MinIndex_i = CompareIndex_i - 1;
		MaxIndex_i = CompareIndex_i;

		if (MinIndex_i < 0)
		{
			if (target < nums[0])
			{
				CompareIndex_i = 0;
				break;
			}
		}

		if (target == nums[MaxIndex_i])
			break;
		else if (target > nums[MaxIndex_i])
		{
			CompareIndex_i++;
			break;
		}

		CompareIndex_i--;
	}

	return (CompareIndex_i);
}