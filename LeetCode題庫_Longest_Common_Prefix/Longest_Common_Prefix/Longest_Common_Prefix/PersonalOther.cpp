#include "stdafx.h"
#include "PersonalOther.h"


char * longestCommonPrefix(char ** strs, int strsSize) {
	int   SubDataLength_i = 0;
	char  TargetLength_i = strlen(strs[0]);
	char  *TempSourceString_c_pr = NULL;
	char  *LastMatchString_c_pr = NULL;
	int   LastMathLength_i = 0;
	bool  MatchCase_fg = true;

	

	while (SubDataLength_i < TargetLength_i)
	{
		MatchCase_fg = true;
		if (TempSourceString_c_pr == NULL)
			TempSourceString_c_pr = (char *)malloc(sizeof(char) * (SubDataLength_i + 2));
		memset(TempSourceString_c_pr, '\0', sizeof(char) * (SubDataLength_i + 2));

		//--> get source sub-string (strs[0])
		for (int j_i = 0; j_i <= SubDataLength_i; j_i++)
		{
			TempSourceString_c_pr[j_i] = strs[0][j_i];
		}


		for (int i_i = 1; i_i < strsSize; i_i++)
		{
			if (strstr(strs[i_i], TempSourceString_c_pr) == NULL)
			{
				MatchCase_fg = false;
				break;
			}
		}

		if (!MatchCase_fg)
			break;
		else    // move the tempsourcestring to lastmatchstring
		{
			if (LastMatchString_c_pr)
			{
				free(LastMatchString_c_pr);
				LastMatchString_c_pr = NULL;
			}
			if (LastMatchString_c_pr == NULL)
				LastMatchString_c_pr = (char *)malloc(sizeof(char) * (SubDataLength_i + 2));
			memset(LastMatchString_c_pr, '\0', sizeof(char) * (SubDataLength_i + 2));

			memcpy(LastMatchString_c_pr, TempSourceString_c_pr, SubDataLength_i + 2);
		}

		if (SubDataLength_i == TargetLength_i)
			break;

		if (TempSourceString_c_pr)
		{
			free(TempSourceString_c_pr);
			TempSourceString_c_pr = NULL;
		}

		SubDataLength_i++;
	}

	if (SubDataLength_i == 0)
	{
		if (TempSourceString_c_pr)
		{
			free(TempSourceString_c_pr);
			TempSourceString_c_pr = NULL;
		}
		if (LastMatchString_c_pr)
		{
			free(LastMatchString_c_pr);
			LastMatchString_c_pr = NULL;
		}
		return "";
	}
	else
	{
		if (TempSourceString_c_pr)
		{
			free(TempSourceString_c_pr);
			TempSourceString_c_pr = NULL;
		}
		return (LastMatchString_c_pr);
	}
}