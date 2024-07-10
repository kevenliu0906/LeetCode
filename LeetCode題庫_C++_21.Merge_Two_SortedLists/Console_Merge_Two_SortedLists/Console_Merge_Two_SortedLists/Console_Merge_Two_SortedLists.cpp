// Console_Merge_Two_SortedLists.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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


class Solution{
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode *current_list1_ptr = list1;
        ListNode *current_list2_ptr = list2;
        ListNode *Result_head_ptr = NULL;
        ListNode *Result_tail_ptr = NULL;

        // solution 1(keven, best)
        {
            while( current_list1_ptr != NULL || current_list2_ptr != NULL ){
                
                if( current_list1_ptr != NULL && current_list2_ptr != NULL ){
                    // printf("list1->val:%d, list2->val:%d\n", current_list1_ptr->val, current_list2_ptr->val);
                    if ( current_list1_ptr->val <= current_list2_ptr->val )
                    {
                        if(Result_head_ptr == NULL){
                            Result_head_ptr = current_list1_ptr;
                        }else{
                            Result_tail_ptr->next = current_list1_ptr;
                        }
                        Result_tail_ptr = current_list1_ptr;
                        current_list1_ptr = current_list1_ptr->next;
                    }else{
                        if(Result_head_ptr == NULL){
                            Result_head_ptr = current_list2_ptr;
                        }else{
                            Result_tail_ptr->next = current_list2_ptr;
                        }
                        Result_tail_ptr = current_list2_ptr;
                        current_list2_ptr = current_list2_ptr->next;
                    }
                }
                else if( current_list1_ptr != NULL && current_list2_ptr == NULL ){
                    // printf("list1->val:%d, list2->val:NULL\n", current_list1_ptr->val);
                    if(Result_head_ptr == NULL){
                        Result_head_ptr = current_list1_ptr;
                    }else{
                        Result_tail_ptr->next = current_list1_ptr;
                    }
                    Result_tail_ptr = current_list1_ptr;
                    current_list1_ptr = current_list1_ptr->next;
                }
                else if( current_list1_ptr == NULL && current_list2_ptr != NULL ){
                    // printf("list1->val:NULL, list2->val:%d\n", current_list2_ptr->val);
                    if(Result_head_ptr == NULL){
                        Result_head_ptr = current_list2_ptr;
                    }else{
                        Result_tail_ptr->next = current_list2_ptr;
                    }
                    Result_tail_ptr = current_list2_ptr;
                    current_list2_ptr = current_list2_ptr->next;
                }
            }

            return Result_head_ptr;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Merge Two Sorted Lists, DataStructure (LinkList, Recursion)!\n";
    printf("LeetCode - 21. Merge Two Sorted Lists\n");
    cout << "https://leetcode.com/problems/merge-two-sorted-lists" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: list1 = [1, 2, 4], list2 = [1, 3, 4]\n");
    printf("expected result: output = [1, 1, 2, 3, 4, 4]\n");
    {
        ListNode *list1_1_ptr = new ListNode(4);
        ListNode *list1_2_ptr = new ListNode(2, list1_1_ptr);
        ListNode *list1_3_ptr = new ListNode(1, list1_2_ptr);
        ListNode *list1 = list1_3_ptr;

        ListNode *list2_1_ptr = new ListNode(4);
        ListNode *list2_2_ptr = new ListNode(3, list2_1_ptr);
        ListNode *list2_3_ptr = new ListNode(1, list2_2_ptr);
        ListNode *list2 = list2_3_ptr;
       
        Solution solution;
        auto result = solution.mergeTwoLists(list1, list2);
        printf("merge result:\n");
        ListNode *current_ptr = result;
        while(current_ptr != NULL){
            printf("current_ptr->val:%d\n", current_ptr->val);
            // if( current_ptr->next != NULL )
                current_ptr = current_ptr->next;
        }

        delete list1_1_ptr;
        delete list1_2_ptr;
        delete list1_3_ptr;
        delete list2_1_ptr;
        delete list2_2_ptr;
        delete list2_3_ptr;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: list1 = [], list2 = []\n");
    printf("expected result: output = []\n");
    {
        ListNode *list1_1_ptr = NULL;
        ListNode *list1 = list1_1_ptr;

        ListNode *list2_1_ptr = NULL;
        ListNode *list2 = list2_1_ptr;
       
        Solution solution;
        auto result = solution.mergeTwoLists(list1, list2);
        printf("merge result:\n");
        ListNode *current_ptr = result;
        while(current_ptr != NULL){
            printf("current_ptr->val:%d\n", current_ptr->val);
            // if( current_ptr->next != NULL )
                current_ptr = current_ptr->next;
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: list1 = [], list2 = [0]\n");
    printf("expected result: output = [0]\n");
    {
        ListNode *list1_1_ptr = NULL;
        ListNode *list1 = list1_1_ptr;

        ListNode *list2_1_ptr = new ListNode(0);
        ListNode *list2 = list2_1_ptr;
       
        Solution solution;
        auto result = solution.mergeTwoLists(list1, list2);
        printf("merge result:\n");
        ListNode *current_ptr = result;
        while(current_ptr != NULL){
            printf("current_ptr->val:%d\n", current_ptr->val);
            // if( current_ptr->next != NULL )
                current_ptr = current_ptr->next;
        }

        delete list1_1_ptr;
        
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
