#include "stdafx.h"
#include "PersonalOther.h"


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *Temp1_pr = l1;
	struct ListNode *Temp2_pr = l2;
	struct ListNode *NewListNode_pr = NULL;
	struct ListNode *Head_cs_pr = NULL;
	struct ListNode *Tail_cs_pr = NULL;
	int    V1_Value_i = 0;
	int    V2_Value_i = 0;
	int    TotalDigital_Count_i = 0;
	int    Next_IncomeValue_i = 0;

	while (Temp1_pr != NULL || Temp2_pr != NULL || Next_IncomeValue_i)
	{
		NewListNode_pr = (struct ListNode*)malloc(sizeof(struct ListNode) * 1);
		TotalDigital_Count_i++;
		//Next_IncomeValue_i = 0;

		if (Temp1_pr == NULL)
		{
			V1_Value_i = 0;
		}
		else
		{
			V1_Value_i = Temp1_pr->val;
		}

		if (Temp2_pr == NULL)
		{
			V2_Value_i = 0;
		}
		else
		{
			V2_Value_i = Temp2_pr->val;
		}


		NewListNode_pr->val = (V1_Value_i + V2_Value_i + Next_IncomeValue_i) % 10;
		NewListNode_pr->next = NULL;

		Next_IncomeValue_i = (V1_Value_i + V2_Value_i + Next_IncomeValue_i) / 10;

		if (TotalDigital_Count_i == 1)
		{
			Head_cs_pr = NewListNode_pr;
			Tail_cs_pr = NewListNode_pr;
		}
		else
		{
			Tail_cs_pr->next = NewListNode_pr;
			Tail_cs_pr = NewListNode_pr;
		}

		if (Temp1_pr != NULL)
			Temp1_pr = Temp1_pr->next;

		if (Temp2_pr != NULL)
			Temp2_pr = Temp2_pr->next;

	}

	return (Head_cs_pr);
}