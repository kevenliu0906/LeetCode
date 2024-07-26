// ConsoleApplication_Partition_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        // solution 0 (keven, best)
        {
            ListNode *tmp = head;
            // 
            ListNode *smaller_head = NULL;
            ListNode *smaller_now = NULL;
            ListNode *biggerequal_head = NULL;
            ListNode *biggerequal_now = NULL;

            // separate two group with "smaller" & "bigger_equal"
            while (tmp!=NULL)
            {
                ListNode *current = tmp;
                tmp = tmp->next;
                // reset current ListNode
                current->next = NULL;

                if (current->val < x){
                    if (smaller_head == NULL){
                        smaller_head = current;
                    }else{
                        smaller_now->next = current;
                    }

                    smaller_now = current;
                    
                }
                else{
                    if (biggerequal_head == NULL){
                        biggerequal_head = current;
                    }else{
                        biggerequal_now->next = current;
                    }

                    biggerequal_now = current;
                    
                }
            }

            // append "bigger_equal" into "smaller"
            if (smaller_now!=NULL){
                smaller_now->next = biggerequal_head;
            }else{
                smaller_head = biggerequal_head;
                smaller_now = biggerequal_head;
            }
            
            
            return smaller_head;
        }

        // solution 1 (keven, using re-apply to solve)
        {
            ListNode *tmp = head;
            vector<ListNode *> smaller_than_x;
            vector<ListNode *> bigger_equal_than_x;
            // partition two group with "smaller" & "bigger_equal"
            while (tmp!=NULL)
            {
                ListNode *now = tmp;
                tmp = tmp->next;
                
                // reset now ListNode
                now->next = NULL;
                
                if (now->val < x){
                    smaller_than_x.push_back(now);
                }else{
                    bigger_equal_than_x.push_back(now);
                }
                
            }
            
            // apply these two group into one ListNode
            ListNode *newhead = NULL;
            ListNode *current = NULL;
            // apply "smaller" group
            for (size_t i = 0; i < smaller_than_x.size(); i++)
            {
                auto now = smaller_than_x[i];
                if (newhead == NULL)
                {
                    newhead = now;
                }else{
                    current->next = now;
                }
                current = now;
                
            }
            
            // apply "bigger_equal" group
            for (size_t i = 0; i < bigger_equal_than_x.size(); i++)
            {
                auto now = bigger_equal_than_x[i];
                if (newhead == NULL)
                {
                    newhead = now;
                }else{
                    current->next = now;
                }
                current = now;
            }

            return newhead;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Partition List, Algorithm & DataStructure(Two Pointer, Linked List)!\n";
    cout << "https://leetcode.com/problems/partition-list/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,4,3,2,5,2], x=3\n");
    printf("expected result: output = [1,2,2,4,3,5]\n");
    {
        ListNode *N1 = new ListNode(2, NULL);
        ListNode *N2 = new ListNode(5, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(3, N3);
        ListNode *N5 = new ListNode(4, N4);
        ListNode *N6 = new ListNode(1, N5);
        ListNode *head = N6;
        int x = 3;
         
        Solution solution;
        auto result = solution.partition(head, x);
        if (result!=NULL){
            printf("Result:\n");
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
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [2,1], x=2\n");
    printf("expected result: output = [1,2]\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *N2 = new ListNode(2, N1);
        ListNode *head = N2;
        int x = 2;
         
        Solution solution;
        auto result = solution.partition(head, x);
        if (result!=NULL){
            printf("Result:\n");
        }
        
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }

        delete N1;
        delete N2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [], x=0\n");
    printf("expected result: output = []\n");
    {
        ListNode *head = NULL;
        int x = 0;
         
        Solution solution;
        auto result = solution.partition(head, x);
        if (result!=NULL){
            printf("Result:\n");
        }else{
            printf("Result:NULL\n");
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
    printf("************* testcase 4 ****************************\n");
    printf("input: head = [1], x=0\n");
    printf("expected result: output = [1]\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *head = N1;
        int x = 0;
         
        Solution solution;
        auto result = solution.partition(head, x);
        if (result!=NULL){
            printf("Result:\n");
        }else{
            printf("Result:NULL\n");
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
