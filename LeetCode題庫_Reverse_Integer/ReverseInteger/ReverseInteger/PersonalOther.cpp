#include "stdafx.h"
#include "PersonalOther.h"

int reverse(int x)
{
	long long int TempX_i = 0;
	long long int TargetNum_i = 0;
	bool Negative_fg = false;
	bool ExceptionCase_fg = false;

	TempX_i = x;
	if (x < 0)
	{
		Negative_fg = true;
		TempX_i = 0 - TempX_i;
	}
	while (TempX_i)
	{
		if (!Negative_fg)   // positive integer
		{
			TargetNum_i = TargetNum_i * 10 + TempX_i % 10;
			if (TargetNum_i > pow(2, 31) - 1)
			{
				ExceptionCase_fg = true;
				break;
			}
		}
		else                // negative integer
		{
			TargetNum_i = TargetNum_i * 10 - TempX_i % 10;
			if (TargetNum_i < pow(-2, 31))
			{
				ExceptionCase_fg = true;
				break;
			}
		}

		TempX_i = TempX_i / 10;
	}

	if (ExceptionCase_fg)
		return 0;

	return (TargetNum_i);
}