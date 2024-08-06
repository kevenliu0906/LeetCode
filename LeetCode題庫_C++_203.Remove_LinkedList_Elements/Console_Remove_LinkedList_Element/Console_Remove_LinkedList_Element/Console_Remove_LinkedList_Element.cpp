// Console_Remove_LinkedList_Element.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // solution 1 (keven, best, direct force)
        {
            ListNode *tmp = head;
            ListNode *result_head = NULL;
            ListNode *result_now = NULL;

            while (tmp != NULL)
            {
                auto current = tmp;
                tmp = tmp->next;

                // reset next pointer of current list-node
                current->next = NULL;

                if (current->val != val)
                {
                    if (result_head == NULL)
                    {
                        result_head = current;
                    }else{
                        result_now->next = current;
                    }
                    result_now = current;
                }

            }

            return result_head;
        }
        
    }
};

int main()
{
    std::cout << "Hello LeetCode - Remove Linked List Elements!\n";
    cout << "https://leetcode.com/problems/remove-linked-list-elements" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,6,3,4,5,6], val = 6\n");
    printf("expected result: output = [1,2,3,4,5]\n");
    {
        ListNode *N1 = new ListNode(6, NULL);
        ListNode *N2 = new ListNode(5, N1);
        ListNode *N3 = new ListNode(4, N2);
        ListNode *N4 = new ListNode(3, N3);
        ListNode *N5 = new ListNode(6, N4);
        ListNode *N6 = new ListNode(2, N5);
        ListNode *N7 = new ListNode(1, N6);
        ListNode *head = N7;
        int val = 6;
        
        Solution solution;
        auto result = solution.removeElements(head, val);
        if (result != NULL){
            printf("result: remove elements is alive!\n");
        }else{
            printf("result: remove elements is NULL!\n");
        }
        
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }

        delete N1;
        delete N2;
        delete N3;
        delete N4;
        delete N5;
        delete N6;
        delete N7;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [], val = 1\n");
    printf("expected result: output = []\n");
    {
        ListNode *head = NULL;
        int val = 1;
        
        Solution solution;
        auto result = solution.removeElements(head, val);
        if (result != NULL){
            printf("result: remove elements is alive!\n");
        }else{
            printf("result: remove elements is NULL!\n");
        }
        
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [7,7,7,7], val = 7\n");
    printf("expected result: output = []\n");
    {
        ListNode *N1 = new ListNode(7, NULL);
        ListNode *N2 = new ListNode(7, N1);
        ListNode *N3 = new ListNode(7, N2);
        ListNode *N4 = new ListNode(7, N3);
        ListNode *head = N4;
        int val = 7;
        
        Solution solution;
        auto result = solution.removeElements(head, val);
        if (result != NULL){
            printf("result: remove elements is alive!\n");
        }else{
            printf("result: remove elements is NULL!\n");
        }
        
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }

        delete N1;
        delete N2;
        delete N3;
        delete N4;
    }
    printf("*****************************************************\n");

    printf("\n\n");
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
