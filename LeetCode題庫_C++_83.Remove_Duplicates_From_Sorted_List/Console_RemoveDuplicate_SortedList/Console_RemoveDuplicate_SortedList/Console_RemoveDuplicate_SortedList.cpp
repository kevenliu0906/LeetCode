// Console_RemoveDuplicate_SortedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    ListNode* deleteDuplicates(ListNode* head) {

        // solution 1 (keven, best, force solve)
        {
            if (head == NULL)
            {
                return head;
            }
            
            ListNode *tmp = head;
            ListNode *result_head = NULL;
            ListNode *result_now = NULL;
            int lastValue = tmp->val - 1;  // assign value that does not exist
            while (tmp)
            {
                auto currentValue = tmp->val;
                auto current = tmp;
                tmp = tmp->next;

                // reset next pointer
                current->next = NULL;

                // printf("currentValue:%d, lastValue:%d\n", currentValue, lastValue);
                if (currentValue != lastValue)
                {
                    // printf("FOUND IT!!!!!, currentValue:%d, lastValue:%d\n", currentValue, lastValue);
                    // found it
                    if (result_head == NULL){
                        result_head = current;
                    }else{
                        result_now->next = current;
                    }
                    result_now = current;
                    
                }
                lastValue = currentValue;
                
            }

            return result_head;    
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Remove Duplicates from Sorted List, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/remove-duplicates-from-sorted-list" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,1,2]\n");
    printf("expected result: output = [1,2]\n");
    {
        ListNode *N1 = new ListNode(2, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *N3 = new ListNode(1, N2);
        ListNode *head = N3;
        
        Solution solution;
        auto result = solution.deleteDuplicates(head);
        if (result != NULL){
            printf("result: rotated right is alive!\n");
        }else{
            printf("result: rotated right is NULL!\n");
        }
        
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }

        delete N1;
        delete N2;
        delete N3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1,1,2,3,3]\n");
    printf("expected result: output = [1,2,3]\n");
    {
        ListNode *N1 = new ListNode(3, NULL);
        ListNode *N2 = new ListNode(3, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        
        Solution solution;
        auto result = solution.deleteDuplicates(head);
        if (result != NULL){
            printf("result: rotated right is alive!\n");
        }else{
            printf("result: rotated right is NULL!\n");
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
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [3]\n");
    printf("expected result: output = [3]\n");
    {
        ListNode *N1 = new ListNode(3, NULL);
        ListNode *head = N1;
        
        Solution solution;
        auto result = solution.deleteDuplicates(head);
        if (result != NULL){
            printf("result: rotated right is alive!\n");
        }else{
            printf("result: rotated right is NULL!\n");
        }
        
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }

        delete N1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: head = []\n");
    printf("expected result: output = []\n");
    {
        ListNode *head = NULL;
        
        Solution solution;
        auto result = solution.deleteDuplicates(head);
        if (result != NULL){
            printf("result: rotated right is alive!\n");
        }else{
            printf("result: rotated right is NULL!\n");
        }
        
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }
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
