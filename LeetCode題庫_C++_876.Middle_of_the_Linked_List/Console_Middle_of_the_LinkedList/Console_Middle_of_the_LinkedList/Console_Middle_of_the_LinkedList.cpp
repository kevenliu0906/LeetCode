// Console_Middle_of_the_LinkedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    ListNode* middleNode(ListNode* head) {

        // solution 1 (keven, using array to solve, best)
        {
            ListNode *tmp = head;
            vector<ListNode*> tmp_listnode_vec;

            while (tmp!=NULL)
            {
                tmp_listnode_vec.push_back(tmp);
                tmp = tmp->next;
            }
            
            auto total_node_count = tmp_listnode_vec.size();

            tmp = tmp_listnode_vec[total_node_count/2];
            
            return tmp;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Middle of the Linked List, DataStructure(Linked List) & Algorithm(Two Pointers)!\n";
    cout << "https://leetcode.com/problems/middle-of-the-linked-list/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5]\n");
    printf("expected result: output = [3,4,5]\n");
    {
        ListNode *A_N1 = new ListNode(5, NULL);
        ListNode *A_N2 = new ListNode(4, A_N1);
        ListNode *A_N3 = new ListNode(3, A_N2);
        ListNode *A_N4 = new ListNode(2, A_N3);
        ListNode *A_N5 = new ListNode(1, A_N4);
        ListNode *head = A_N5;
        
        Solution solution;
        auto result = solution.middleNode(head);
        printf("middle of the linked list,");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;
        delete A_N4;
        delete A_N5;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1,2,3,4,5,6]\n");
    printf("expected result: output = [4,5,6]\n");
    {
        ListNode *A_N1 = new ListNode(6, NULL);
        ListNode *A_N2 = new ListNode(5, A_N1);
        ListNode *A_N3 = new ListNode(4, A_N2);
        ListNode *A_N4 = new ListNode(3, A_N3);
        ListNode *A_N5 = new ListNode(2, A_N4);
        ListNode *A_N6 = new ListNode(1, A_N4);
        ListNode *head = A_N6;
        
        Solution solution;
        auto result = solution.middleNode(head);
        printf("middle of the linked list,");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;
        delete A_N4;
        delete A_N5;
        delete A_N6;
        
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
