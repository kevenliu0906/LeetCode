﻿// Console_Palindrome_LinkedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
 

class Solution{
public:

    bool isPalindrome(ListNode* head) {
        
        // solution 1 (keven, best)
        {
            int Num = 0;
            vector<int> head_vec;
            
            while (head)
            {
                head_vec.push_back(head->val);
                head = head->next;
            }

            int total_num = head_vec.size();
            for (size_t i = 0; i < total_num / 2; i++)
            {
                if (head_vec[i] != head_vec[total_num - i - 1])
                {
                    return false;
                }
                
            }

            return true;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode, Palindrome Linked List, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/longest-consecutive-sequence" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1, 2, 2, 1]\n");
    printf("expected result: output = true\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *N2 = new ListNode(2, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *head = N4;
        
        Solution solution;
        auto result = solution.isPalindrome(head);
        printf("result value:%d, true(%d), false(%d)\n", result, true, false);
        
        delete N1;
        delete N2;
        delete N3;
        delete N4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1, 2]\n");
    printf("expected result: output = false\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *N2 = new ListNode(2, N1);
        ListNode *head = N2;
        
        Solution solution;
        auto result = solution.isPalindrome(head);
        printf("result value:%d, true(%d), false(%d)\n", result, true, false);
        
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
