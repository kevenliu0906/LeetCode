// Console_LinkedList_Component.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <unordered_set>

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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        // solution 1 (keven, best, using HASH TABLE to solve)
        {
            unordered_set<int> nums_unorderedset(nums.begin(), nums.end());
            bool last_nums_check = false;
            int numCount = 0;

            while (head)
            {
                auto currentVal = head->val;
                if (nums_unorderedset.count(currentVal))
                {
                    // represent current value is existed in nums_unordered_set
                    if (!last_nums_check)
                    {
                        numCount++;
                    }

                    last_nums_check = true;
                    
                }else{
                    last_nums_check = false;
                }
                
                head = head->next;
            }

            return numCount;
            
        }

        return 0;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Linked List Component, DataStructure(Linked List, HASH TABLE)!\n";
    cout << "https://leetcode.com/problems/linked-list-components" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [0,1,2,3], nums = [0,1,3]\n");
    printf("expected result: output = 2\n");
    {
        ListNode *N1 = new ListNode(3, NULL);
        ListNode *N2 = new ListNode(2, N1);
        ListNode *N3 = new ListNode(1, N2);
        ListNode *N4 = new ListNode(0, N3);
        ListNode *head = N4;
        vector<int> nums{0, 1, 3};
        
        Solution solution;
        auto result = solution.numComponents(head, nums);
        printf("result: num Components is %d\n", result);

        delete N1;
        delete N2;
        delete N3;
        delete N4;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [0,1,2,3,4], nums = [0,3,1,4]\n");
    printf("expected result: output = 2\n");
    {
        ListNode *N1 = new ListNode(4, NULL);
        ListNode *N2 = new ListNode(3, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *N5 = new ListNode(0, N4);
        ListNode *head = N5;
        vector<int> nums{0, 3, 1, 4};
        
        Solution solution;
        auto result = solution.numComponents(head, nums);
        printf("result: num Components is %d\n", result);

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
    printf("input: head = [1], nums = [1]\n");
    printf("expected result: output = 1\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *head = N1;
        vector<int> nums{1};
        
        Solution solution;
        auto result = solution.numComponents(head, nums);
        printf("result: num Components is %d\n", result);

        delete N1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: head = [1], nums = [2]\n");
    printf("expected result: output = 0\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *head = N1;
        vector<int> nums{2};
        
        Solution solution;
        auto result = solution.numComponents(head, nums);
        printf("result: num Components is %d\n", result);

        delete N1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: head = [0,1,2], nums = [3,4]\n");
    printf("expected result: output = 0\n");
    {
        ListNode *N1 = new ListNode(2, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *N3 = new ListNode(0, N2);
        ListNode *head = N3;
        vector<int> nums{3, 4};
        
        Solution solution;
        auto result = solution.numComponents(head, nums);
        printf("result: num Components is %d\n", result);

        delete N1;
        delete N2;
        delete N3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: head = [1,2,3,4], nums = [5,3]\n");
    printf("expected result: output = 1\n");
    {
        ListNode *N1 = new ListNode(4, NULL);
        ListNode *N2 = new ListNode(3, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *head = N4;
        vector<int> nums{5, 3};
        
        Solution solution;
        auto result = solution.numComponents(head, nums);
        printf("result: num Components is %d\n", result);

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
