#include "stdafx.h"
#include "PersonalOther.h"

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
		if (Temp1_Value_i < Temp2_Value_i)
		{
			MinValue_i = Temp1_Value_i;
			MaxValue_i = Temp2_Value_i;
		}
		else
		{
			MinValue_i = Temp2_Value_i;
			MaxValue_i = Temp1_Value_i;
		}

		if (MinValue_i == Temp1_Value_i)
		{
			if (Temp1_Value_Exist_fg)
			{
				//Head_cs_pr = CreateNewListData_Fn(MinValue_i);
				NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
				NewData_cs_pr->next = NULL;
				NewData_cs_pr->val = MinValue_i;
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
		}
		if (MinValue_i == Temp2_Value_i)
		{
			if (Temp2_Value_Exist_fg)
			{
				//Head_cs_pr = CreateNewListData_Fn(MinValue_i);
				NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
				NewData_cs_pr->next = NULL;
				NewData_cs_pr->val = MinValue_i;
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
		}
		//NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
		//NewData_cs_pr->next = NULL;
		//NewData_cs_pr->val = MinValue_i;
		//if (Head_cs_pr == NULL)
		//{
			//Head_cs_pr = NewData_cs_pr;
			//Tail_cs_pr = NewData_cs_pr;
		//}
		//else
		//{
			//Tail_cs_pr->next = NewData_cs_pr;
			//Tail_cs_pr = NewData_cs_pr;
		//}

		if (MaxValue_i == Temp1_Value_i)
		{
			if (Temp1_Value_Exist_fg)
			{
				//Head_cs_pr = CreateNewListData_Fn(MaxValue_i);
				NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
				NewData_cs_pr->next = NULL;
				NewData_cs_pr->val = MaxValue_i;
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
		}
		if (MaxValue_i == Temp2_Value_i)
		{
			if (Temp2_Value_Exist_fg)
			{
				//Head_cs_pr = CreateNewListData_Fn(MaxValue_i);
				NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
				NewData_cs_pr->next = NULL;
				NewData_cs_pr->val = MaxValue_i;
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
		}
		//NewData_cs_pr = (struct ListNode *)malloc(sizeof(struct ListNode) * 1);
		//NewData_cs_pr->next = NULL;
		//NewData_cs_pr->val = MaxValue_i;
		//if (Head_cs_pr == NULL)
		//{
			//Head_cs_pr = NewData_cs_pr;
			//Tail_cs_pr = NewData_cs_pr;
		//}
		//else
		//{
			//Tail_cs_pr->next = NewData_cs_pr;
			//Tail_cs_pr = NewData_cs_pr;
		//}

		if (Temp1_cs_pr != NULL)
			Temp1_cs_pr = Temp1_cs_pr->next;
		if (Temp2_cs_pr != NULL)
			Temp2_cs_pr = Temp2_cs_pr->next;
	}

	return Head_cs_pr;
}