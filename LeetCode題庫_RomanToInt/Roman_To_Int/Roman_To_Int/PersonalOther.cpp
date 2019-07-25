#include "stdafx.h"
#include "PersonalOther.h"

int romanToInt(char * s) {
	char *s_pr = s;
	int CurrentSum_i = 0;
	int StringLength_i = strlen(s);
	int Index_i = 0;
	char CurrentChar_c = '0';
	bool ExceptionCase_fg = false;

	while (Index_i<StringLength_i)
	{
		ExceptionCase_fg = false;
		CurrentChar_c = *(s_pr + Index_i);
		if (CurrentChar_c == 'I')
		{
			if (*(s_pr + Index_i + 1) == 'V')
			{
				ExceptionCase_fg = true;
				CurrentSum_i = CurrentSum_i + 4;
			}
			else if (*(s_pr + Index_i + 1) == 'X')
			{
				ExceptionCase_fg = true;
				CurrentSum_i = CurrentSum_i + 9;
			}
		}
		else if (CurrentChar_c == 'X')
		{
			if (*(s_pr + Index_i + 1) == 'L')
			{
				ExceptionCase_fg = true;
				CurrentSum_i = CurrentSum_i + 40;
			}
			else if (*(s_pr + Index_i + 1) == 'C')
			{
				ExceptionCase_fg = true;
				CurrentSum_i = CurrentSum_i + 90;
			}
		}
		else if (CurrentChar_c == 'C')
		{
			if (*(s_pr + Index_i + 1) == 'D')
			{
				ExceptionCase_fg = true;
				CurrentSum_i = CurrentSum_i + 400;
			}
			else if (*(s_pr + Index_i + 1) == 'M')
			{
				ExceptionCase_fg = true;
				CurrentSum_i = CurrentSum_i + 900;
			}
		}

		if (!ExceptionCase_fg)
		{
			if (CurrentChar_c == 'I')
				CurrentSum_i = CurrentSum_i + 1;
			if (CurrentChar_c == 'V')
				CurrentSum_i = CurrentSum_i + 5;
			if (CurrentChar_c == 'X')
				CurrentSum_i = CurrentSum_i + 10;
			if (CurrentChar_c == 'L')
				CurrentSum_i = CurrentSum_i + 50;
			if (CurrentChar_c == 'C')
				CurrentSum_i = CurrentSum_i + 100;
			if (CurrentChar_c == 'D')
				CurrentSum_i = CurrentSum_i + 500;
			if (CurrentChar_c == 'M')
				CurrentSum_i = CurrentSum_i + 1000;
		}


		if (ExceptionCase_fg)
			Index_i = Index_i + 2;
		else
			Index_i++;
	}

	return (CurrentSum_i);

}