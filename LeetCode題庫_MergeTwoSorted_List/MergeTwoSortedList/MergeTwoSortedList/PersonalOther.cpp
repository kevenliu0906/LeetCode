#include "stdafx.h"
#include "PersonalOther.h"

void Sort_List_Fn(struct ListNode *Final_List_cs_pr)
{
	int     ListDataCount_i = 0;
	struct ListNode *temp_cs_pr = Final_List_cs_pr;
	struct ListNode *Source_cs_pr = NULL;
	struct ListNode *Target_cs_pr = NULL;
	int    TempValue_i = 0;

	while (temp_cs_pr != NULL)
	{
		ListDataCount_i++;
		temp_cs_pr = temp_cs_pr->next;
	}

	for (int i_i = 0; i_i < ListDataCount_i; i_i++)
	{
		if (i_i == 0)
			Source_cs_pr = Final_List_cs_pr;
		else
			Source_cs_pr = Source_cs_pr->next;
		for (int j_i = i_i + 1; j_i < ListDataCount_i; j_i++)
		{
			if (j_i == i_i + 1)
				Target_cs_pr = Source_cs_pr->next;
			else
				Target_cs_pr = Target_cs_pr->next;
			if (Source_cs_pr->val > Target_cs_pr->val)  // swap value
			{
				TempValue_i = Target_cs_pr->val;
				Target_cs_pr->val = Source_cs_pr->val;
				Source_cs_pr->val = TempValue_i;
			}
		}
	}
}

struct ListNode* CreateNewListData_Fn(int Value_i)
{
	struct ListNode   *NewListData_cs_pr = NULL;
	struct ListNode   *Head_cs_pr = NULL;
	struct ListNode   *Tail_cs_pr = NULL;

	NewListData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
	NewListData_cs_pr->next = NULL;
	NewListData_cs_pr->val = Value_i;

	if (Head_cs_pr == NULL)
	{
		Head_cs_pr = NewListData_cs_pr;
		Tail_cs_pr = NewListData_cs_pr;
	}
	else
	{
		Tail_cs_pr->next = NewListData_cs_pr;
		Tail_cs_pr = NewListData_cs_pr;
	}

	return (Head_cs_pr);
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode   *Head_cs_pr = NULL;
	struct ListNode   *Tail_cs_pr = NULL;
	struct ListNode   *Temp1_cs_pr = l1;
	struct ListNode   *Temp2_cs_pr = l2;
	struct ListNode   *NewData_cs_pr = NULL;
	int    Temp1_Value_i = 0;
	int    Temp2_Value_i = 0;
	int    MinValue_i = 0;
	int    MaxValue_i = 0;
	bool   Temp1_Value_Exist_fg = false;
	bool   Temp2_Value_Exist_fg = false;

	while (Temp1_cs_pr != NULL || Temp2_cs_pr != NULL)
	{
		Temp1_Value_i = 0;
		Temp2_Value_i = 0;
		Temp1_Value_Exist_fg = false;
		Temp2_Value_Exist_fg = false;
		//--> calc min value & max value
		if (Temp1_cs_pr != NULL)
		{
			Temp1_Value_Exist_fg = true;
			Temp1_Value_i = Temp1_cs_pr->val;
		}
		if (Temp2_cs_pr != NULL)
		{
			Temp2_Value_Exist_fg = true;
			Temp2_Value_i = Temp2_cs_pr->val;
		}

		if (Temp1_Value_Exist_fg)
		{
			Temp1_Value_Exist_fg = false;   //建立完畢就必須轉為false，防止後面判斷式繼續建立list資料
			//Head_cs_pr = CreateNewListData_Fn(MinValue_i);
			NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
			NewData_cs_pr->next = NULL;
			NewData_cs_pr->val = Temp1_cs_pr->val;
			if (Head_cs_pr == NULL)
			{
				Head_cs_pr = NewData_cs_pr;
				Tail_cs_pr = NewData_cs_pr;
			}
			else
			{
				Tail_cs_pr->next = NewData_cs_pr;
				Tail_cs_pr = NewData_cs_pr;
			}
		}

		if (Temp2_Value_Exist_fg)
		{
			Temp2_Value_Exist_fg = false;   //建立完畢就必須轉為false，防止後面判斷式繼續建立list資料
			//Head_cs_pr = CreateNewListData_Fn(MinValue_i);
			NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
			NewData_cs_pr->next = NULL;
			NewData_cs_pr->val = Temp2_cs_pr->val;
			if (Head_cs_pr == NULL)
			{
				Head_cs_pr = NewData_cs_pr;
				Tail_cs_pr = NewData_cs_pr;
			}
			else
			{
				Tail_cs_pr->next = NewData_cs_pr;
				Tail_cs_pr = NewData_cs_pr;
			}
		}
		
		if (Temp1_cs_pr != NULL)
			Temp1_cs_pr = Temp1_cs_pr->next;
		if (Temp2_cs_pr != NULL)
			Temp2_cs_pr = Temp2_cs_pr->next;
	}

	Sort_List_Fn(Head_cs_pr);

	return Head_cs_pr;
}