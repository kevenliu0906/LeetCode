// ConsoleApplication_Rotated_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

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
    ListNode* rotateRight(ListNode* head, int k) {

        // solution 1 (keven, force solve, using array to store the list node pointer)
        {
            if (k==0 || head == NULL)
            {
                return head;
            }
            
            ListNode *tmp_head = head;
            vector<ListNode*> total_listnode_vec;

            while (tmp_head != NULL)
            {
                total_listnode_vec.push_back(tmp_head);
                tmp_head = tmp_head->next;
            }

            if (total_listnode_vec.size() == 1)
            {
                // ONLY 1 element is ListNode, just return it
                return head;
            }
            

            int affect_Count = k % total_listnode_vec.size();
            if (affect_Count == 0)
            {
                // represent the rotated right will cause no effect
                return head;
            }
            
            // the last non-affect element
            int affect_index_before = total_listnode_vec.size() - affect_Count - 1;
            total_listnode_vec[affect_index_before]->next = NULL;
            
            // the affect elements
            int affect_index = total_listnode_vec.size() - affect_Count;
            total_listnode_vec[total_listnode_vec.size() - 1]->next = head;
            head = total_listnode_vec[affect_index];    

            return head;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Rotated List, DataStructure & Algorithm(Linked List, Two Pointer)!\n";
    cout << "https://leetcode.com/problems/rotate-list" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5], k = 2\n");
    printf("expected result: output = [4,5,1,2,3]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int k = 2;
        
        Solution solution;
        auto result = solution.rotateRight(head, k);
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
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [0,1,2], k = 4\n");
    printf("expected result: output = [2,0,1]\n");
    {
        ListNode *N1 = new ListNode(2, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *N3 = new ListNode(0, N2);
        ListNode *head = N3;
        int k = 4;
        
        Solution solution;
        auto result = solution.rotateRight(head, k);
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
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [], k = 0\n");
    printf("expected result: output = []\n");
    {
        ListNode *head = NULL;
        int k = 0;
        
        Solution solution;
        auto result = solution.rotateRight(head, k);
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

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: head = [1], k = 1\n");
    printf("expected result: output = [1]\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *head = N1;
        int k = 1;
        
        Solution solution;
        auto result = solution.rotateRight(head, k);
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
    printf("************* testcase 5 ****************************\n");
    printf("input: head = [1,2], k = 2\n");
    printf("expected result: output = [1,2]\n");
    {
        ListNode *N1 = new ListNode(2, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *head = N2;
        int k = 2;
        
        Solution solution;
        auto result = solution.rotateRight(head, k);
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
