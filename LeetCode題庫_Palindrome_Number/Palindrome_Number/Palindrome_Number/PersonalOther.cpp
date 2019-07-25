#include "stdafx.h"
#include "PersonalOther.h"

bool isPalindrome(int x) {

	int TempX_i = 0;
	int TotalDigitalNum_i = 0;
	long long int Rev_Num_i = 0;

	if (x<0)
		return false;

	TempX_i = x;
	while (TempX_i>0)
	{
		TotalDigitalNum_i++;
		TempX_i = TempX_i / 10;
	}

	int *A_Num_i_ay_pr = (int *)malloc(sizeof(int)*TotalDigitalNum_i);//new int[TotalDigitalNum_i]
	long long int *Rev_Num_i_ay_pr = (long long int *)malloc(sizeof(long long int)*TotalDigitalNum_i);

	TempX_i = x;
	TotalDigitalNum_i = 0;
	//--> record Num into A_Num_i_ay
	while (TempX_i>0)
	{
		A_Num_i_ay_pr[TotalDigitalNum_i] = TempX_i % 10;
		TotalDigitalNum_i++;
		TempX_i = TempX_i / 10;
	}

	//--> record Reverse Num into Rev_Num_i_ay
	int Rev_Index_i = 0;
	for (int i_i = TotalDigitalNum_i - 1; i_i >= 0; i_i--)
	{
		Rev_Num_i_ay_pr[Rev_Index_i] = A_Num_i_ay_pr[i_i];
		Rev_Index_i++;
	}

	//--> compare Original num & Reverse num
	int MultFactor_i = 1;
	int MultCount_i = 1;
	long long int NewRev_i = 0;
	for (int i_i = 1; i_i <= TotalDigitalNum_i; i_i++)
	{
		MultFactor_i = 1;
		MultCount_i = i_i;
		while (MultCount_i>1)
		{
			MultFactor_i = MultFactor_i * 10;
			MultCount_i--;
		}
		NewRev_i = Rev_Num_i_ay_pr[i_i - 1] * MultFactor_i;
		Rev_Num_i = Rev_Num_i + NewRev_i;
	}
	bool  Match_fg = true;

	if (Rev_Num_i != x)
		Match_fg = false;

	free(A_Num_i_ay_pr);
	free(Rev_Num_i_ay_pr);

	return (Match_fg);
}