#include "stdafx.h"
#include "PersonalOther.h"



int lengthOfLongestSubstring(char * s) 
{
	int   SourceStringLength_i = 0;
	int   TempStringLength_i = 0;
	int   StartIndex_i = 0;
	char  *TempString_c_pr = NULL;
	char  Target_c = '\0';
	char  TempTarget_c = '\0';
	bool  Repeat_Char_fg = false;

	if (s == NULL)
		return 0;

	SourceStringLength_i = strlen(s);
	TempStringLength_i = SourceStringLength_i;
	
	do {
		TempString_c_pr = (char *)malloc(sizeof(char) * (TempStringLength_i + 1));
		memset(TempString_c_pr, '\0', (TempStringLength_i + 1));
		StartIndex_i = 0;
		while ((StartIndex_i + TempStringLength_i) <= SourceStringLength_i)
		{
			//--> 先取出目前欲比對的子字串
			for (int i_i = StartIndex_i; i_i < StartIndex_i + TempStringLength_i; i_i++)
			{
				TempString_c_pr[i_i - StartIndex_i] = s[i_i];
			}

			//--> 判斷子字串中是否有重複的字元
			Repeat_Char_fg = false;
			for (int i_i = 0; i_i < TempStringLength_i; i_i++)
			{
				Target_c = TempString_c_pr[i_i];
				if (strchr(TempString_c_pr, Target_c) != NULL)
				{
					//繼續往i_i的下幾個找，看還有沒有相同字元的case存在
					for (int j_i = i_i + 1; j_i < TempStringLength_i; j_i++)
					{
						TempTarget_c = TempString_c_pr[j_i];
						if(Target_c == TempTarget_c)
						//Repeat_CharCount_i++;
						//if (Repeat_CharCount_i > 1)
						{
							Repeat_Char_fg = true;
							break;
						}
					}
				}
				if (Repeat_Char_fg)   //這個子字串已經有重複的字元，所以不必再尋找
					break;
			}
			if (!Repeat_Char_fg)  //代表這個子字串都沒有重複的字元，可以直接回傳
				break;

			StartIndex_i++;
		}
		if (!Repeat_Char_fg)  //代表這個子字串都沒有重複的字元，可以直接回傳
			break;
		free(TempString_c_pr);
		TempStringLength_i--;
	} while (TempStringLength_i > 0);

	return (TempStringLength_i);
}
