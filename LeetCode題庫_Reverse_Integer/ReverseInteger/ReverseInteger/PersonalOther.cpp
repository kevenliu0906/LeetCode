#include "stdafx.h"
#include "PersonalOther.h"

int reverse(int x) 
{
	bool NegativeNum_fg = false;
	int TotalDigital_i = 0;
	int TempX_i = x;
	int SingleDigital_i = 0;
	long long int ReverseNum_i = 0;
	int MultCount_i = 0;
	long long int MultFactor_i = 0;


	if (x<0)
	{
		NegativeNum_fg = true;
		TempX_i = abs(x);
		x = TempX_i;
	}

	while (TempX_i>0)
	{
		TotalDigital_i++;
		TempX_i = TempX_i / 10;
	}

	int *Num_i_ay = (int *)malloc(sizeof(int)*TotalDigital_i)/*new int[TotalDigital_i]*/;
	TempX_i = x;

	TotalDigital_i = 0;
	while (TempX_i>0)
	{
		Num_i_ay[TotalDigital_i] = TempX_i % 10;
		TotalDigital_i++;
		TempX_i = TempX_i / 10;
	}

	for (int i_i = 1; i_i <= TotalDigital_i; i_i++)
	{
		MultFactor_i = 1;
		MultCount_i = TotalDigital_i;
		while (MultCount_i != i_i)
		{
			MultFactor_i = MultFactor_i * 10;
			MultCount_i--;
		}
		ReverseNum_i = ReverseNum_i + Num_i_ay[i_i - 1] * MultFactor_i;
	}

	if (NegativeNum_fg)
		ReverseNum_i = 0 - ReverseNum_i;

	free(Num_i_ay);

	return (ReverseNum_i);
}
