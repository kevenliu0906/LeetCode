#pragma once

/**/
// Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};

void Sort_List_Fn(struct ListNode *Final_List_cs_pr);

struct ListNode* CreateNewListData_Fn(int Value_i);

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
