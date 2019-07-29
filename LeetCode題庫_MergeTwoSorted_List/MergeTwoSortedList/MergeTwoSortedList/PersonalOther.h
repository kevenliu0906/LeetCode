#pragma once

/**/
// Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* CreateNewListData_Fn(int Value_i);

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);
