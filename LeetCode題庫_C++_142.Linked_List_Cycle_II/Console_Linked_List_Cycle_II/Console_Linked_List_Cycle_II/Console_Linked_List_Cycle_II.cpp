// Console_Linked_List_Cycle_II.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <unordered_set>

using namespace std;


//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        // solution 1 (keven, using HASH TABLE)
        {
            unordered_set<ListNode*> run_path_unordered_set;
            ListNode *tmp = head;
            while(tmp!=NULL){
                // judgement if current node is ran as before
                if (run_path_unordered_set.count(tmp) == 0)
                {
                    run_path_unordered_set.insert(tmp);
                }
                else{
                    // current node is already ran before
                    break;
                }
                
                tmp = tmp->next;
            }

            return tmp;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Linked List Cycle II, DataStructure & Algorithm(HASH TABLE, Linked List, Two Pointer)!\n";
    cout << "https://leetcode.com/problems/linked-list-cycle-ii/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [3,2,0,-4,2]\n");
    printf("expected result: output = 1\n");
    {
        ListNode *N1 = new ListNode(2, NULL);
        ListNode *N2 = new ListNode(-4, N1);
        ListNode *N3 = new ListNode(0, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(3, N4);
        ListNode *head = N5;
        
        Solution solution;
        auto result = solution.sortList(head);
        if (result!=NULL){
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete N1;
        delete N2;
        delete N3;
        delete N4;
        delete N5;
        
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
