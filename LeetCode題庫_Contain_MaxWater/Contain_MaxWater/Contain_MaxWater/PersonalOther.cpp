#include "stdafx.h"
#include "PersonalOther.h"

int maxArea(int* height, int heightSize) {
	int   MaxAera_i = 0;

	for (int i_i = 0; i_i < heightSize; i_i++)
	{
		for (int j_i = i_i + 1; j_i < heightSize; j_i++)
		{
			MaxAera_i = max(MaxAera_i, (j_i - i_i) * min(height[i_i], height[j_i]));
		}
		
	}
	return (MaxAera_i);
}