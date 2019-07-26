#include "stdafx.h"
#include "PersonalOther.h"

char * intToRoman(int num) {

	int TotalDig_i = 0;
	char Dig_Roman_c_ay[20] = {'\0'};
	char *Final_Roman_c_pr = NULL;

	while (num>0)
	{
		// calc 1000-bit
		while (num >= 1000)
		{
			strcat_s(Dig_Roman_c_ay, "M");
			num = num - 1000;
			TotalDig_i++;
		}

		// calc 100-bit
		while (num >= 100)
		{
			if (num / 100 == 4)
			{
				num = num - 400;
				strcat_s(Dig_Roman_c_ay, "CD");
				TotalDig_i = TotalDig_i + 2;
			}
			else if (num / 100 == 9)
			{
				num = num - 900;
				strcat_s(Dig_Roman_c_ay, "CM");
				TotalDig_i = TotalDig_i + 2;
			}
			else
			{
				if (num / 100 >= 5)
				{
					num = num - 500;
					strcat_s(Dig_Roman_c_ay, "D");
					TotalDig_i++;
				}
				else
				{
					num = num - 100;
					strcat_s(Dig_Roman_c_ay, "C");
					TotalDig_i++;
				}
			}
		}

		// calc 10-bit
		while (num >= 10)
		{
			if (num / 10 == 4)
			{
				num = num - 40;
				strcat_s(Dig_Roman_c_ay, "XL");
				TotalDig_i = TotalDig_i + 2;
			}
			else if (num / 10 == 9)
			{
				num = num - 90;
				strcat_s(Dig_Roman_c_ay, "XC");
				TotalDig_i = TotalDig_i + 2;
			}
			else
			{
				if (num / 10 >= 5)
				{
					num = num - 50;
					strcat_s(Dig_Roman_c_ay, "L");
					TotalDig_i++;
				}
				else
				{
					num = num - 10;
					strcat_s(Dig_Roman_c_ay, "X");
					TotalDig_i++;
				}
			}
		}

		// calc 1-bit
		while (num >= 1)
		{
			if (num / 1 == 4)
			{
				num = num - 4;
				strcat_s(Dig_Roman_c_ay, "IV");
				TotalDig_i = TotalDig_i + 2;
			}
			else if (num / 1 == 9)
			{
				num = num - 9;
				strcat_s(Dig_Roman_c_ay, "IX");
				TotalDig_i = TotalDig_i + 2;
			}
			else
			{
				if (num / 1 >= 5)
				{
					num = num - 5;
					strcat_s(Dig_Roman_c_ay, "V");
					TotalDig_i++;
				}
				else
				{
					num = num - 1;
					strcat_s(Dig_Roman_c_ay, "I");
					TotalDig_i++;
				}
			}
		}
	}

	Final_Roman_c_pr = (char *)malloc(sizeof(char) * (TotalDig_i + 1));
	memset(Final_Roman_c_pr, 0, sizeof(char)*(TotalDig_i + 1));
	//Final_Roman_c_pr = new char[TotalDig_i + 1];
	//memset(Final_Roman_c_pr, '\0', (sizeof(char))*(TotalDig_i+1));
	for (int i_i = 0; i_i < TotalDig_i; i_i++)
	{
		if (Dig_Roman_c_ay[i_i] == '0')
			break;
		Final_Roman_c_pr[i_i] = Dig_Roman_c_ay[i_i];
	}
	return Final_Roman_c_pr;
}