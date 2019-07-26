#include "stdafx.h"
#include "PersonalOther.h"

int myAtoi(char * str) {
	char *tempstr = NULL;
	int  CurrentIndex_i = 0;
	int  ValuePositive_i = 1;
	long long int  CurrentNumValue_i = 0;
	bool LegalCase_fg = false;
	int  SingleDigValue_i = 0;
	int  StringLength_i = strlen(str);
	int  RangeMax_i = 0;
	long long int  TempValue_i = 0;
	int  MeetSignCount_i = 0;
	int  MeetNumCount_i = 0;

	tempstr = str;

	while (tempstr != '\0')
	{
		LegalCase_fg = false;
		// point next char when get space char
		if (*tempstr == ' ')
		{
			if (MeetNumCount_i)
				break;
			if (MeetSignCount_i)
				break;
			LegalCase_fg = true;
		}
		// get positive sign or negative sign
		else if (*tempstr == '+' || *tempstr == '-')
		{
			MeetSignCount_i++;
			if (MeetSignCount_i>1)
				break;
			if (MeetNumCount_i>0)
				break;
			if (*tempstr == '+')
				ValuePositive_i = 1;  // positive sign
			else
				ValuePositive_i = -1; // negative sign
			LegalCase_fg = true;
		}
		// get 0~9 number
		else if (*tempstr >= 48 && *tempstr <= 57)
		{
			MeetNumCount_i++;
			SingleDigValue_i = *tempstr - 48;
			RangeMax_i = pow(2, 31) - 1;
			TempValue_i = CurrentNumValue_i * 10 + SingleDigValue_i;
			if (ValuePositive_i == 1)
			{
				if (TempValue_i > (pow(2, 31) - 1))
					break;
			}
			else if (ValuePositive_i == -1)
			{
				if (TempValue_i > pow(2, 31))
					break;
			}

			CurrentNumValue_i = CurrentNumValue_i * 10 + SingleDigValue_i;
			LegalCase_fg = true;
		}

		if (LegalCase_fg)
		{
			CurrentIndex_i++;
			tempstr = str;
			tempstr = tempstr + CurrentIndex_i;
			if (CurrentIndex_i >= StringLength_i)
				break;
			continue;
		}
		else
			break;
	}

	if (ValuePositive_i == -1)
	{
		TempValue_i = 0 - TempValue_i;
		CurrentNumValue_i = TempValue_i;
		if (TempValue_i < pow(-2, 31))
			CurrentNumValue_i = pow(-2, 31);
	}
	else
	{
		CurrentNumValue_i = TempValue_i;
		if (TempValue_i >(pow(2, 31) - 1))
			CurrentNumValue_i = pow(2, 31) - 1;
	}


	return (CurrentNumValue_i);
}