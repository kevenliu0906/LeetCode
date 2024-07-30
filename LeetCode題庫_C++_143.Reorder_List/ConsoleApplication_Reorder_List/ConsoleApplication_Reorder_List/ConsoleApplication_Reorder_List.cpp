// ConsoleApplication_Reorder_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    void reorderList(ListNode* head) {
        
        // solution 1 (keven, best, using array to store listnode and two pointer to shift)
        {
            vector<ListNode *> list_vec;
            
            while (head!=NULL)
            {
                list_vec.push_back(head);
                head = head->next;
            }
            
            int index_left = 0;
            int index_right = list_vec.size() - 1;
            ListNode *left_node = NULL;
            ListNode *right_node = NULL;
            ListNode *current_node = NULL;
            head = NULL;

            while (index_left <= index_right)
            {
                if (index_left == index_right)
                {
                    // only apply left-node or right-node
                    left_node = list_vec[index_left];
                    left_node->next = NULL;
                    if (head == NULL){
                        head = left_node;
                    }
                    else{
                        current_node->next = left_node;
                    }
                    current_node = left_node;
                    break;
                }

                // 1st. apply left-node
                left_node = list_vec[index_left];
                left_node->next = NULL;
                if (head == NULL){
                    head = left_node;
                }
                else{
                    current_node->next = left_node;
                }
                current_node = left_node;

                // 2nd. apply right-node
                right_node = list_vec[index_right];
                right_node->next = NULL;
                if (head == NULL){
                    head = right_node;
                }
                else{
                    current_node->next = right_node;
                }
                current_node = right_node;

                // 3rd. index-left & index-right shift
                index_left++;
                index_right--;
            }
        }
    }
};


int main()
{
    std::cout << "Hello LeetCode - Reorder List, DataStructure(Linked List) & Algorithm(Two Pointer)!\n";
    cout << "https://leetcode.com/problems/reorder-list/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4]\n");
    printf("expected result: output = [1,4,2,3]\n");
    {
        ListNode *N1 = new ListNode(4, NULL);
        ListNode *N2 = new ListNode(3, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *head = N4;
        
        Solution solution;
        
        solution.reorderList(head);
        printf("after reorder list\n");
        while (head!=NULL)
        {
            printf("val:%d\n", head->val);
            head = head->next;
        }
        printf("----------------------------\n");

        delete N1;
        delete N2;
        delete N3;
        delete N4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1,2,3,4,5]\n");
    printf("expected result: output = [1,5,2,4,3]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        
        Solution solution;
        
        solution.reorderList(head);
        printf("after reorder list\n");
        while (head!=NULL)
        {
            printf("val:%d\n", head->val);
            head = head->next;
        }
        printf("----------------------------\n");

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
    printf("input: head = [1]\n");
    printf("expected result: output = [1]\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *head = N1;
        
        Solution solution;
        
        solution.reorderList(head);
        printf("after reorder list\n");
        while (head!=NULL)
        {
            printf("val:%d\n", head->val);
            head = head->next;
        }
        printf("----------------------------\n");

        delete N1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: head = [2,3,3,4,5]\n");
    printf("expected result: output = [2,5,3,4,3]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(3, N3);
        ListNode *N5 = new ListNode(2, N4);
        ListNode *head = N5;
        
        Solution solution;
        
        solution.reorderList(head);
        printf("after reorder list\n");
        while (head!=NULL)
        {
            printf("val:%d\n", head->val);
            head = head->next;
        }
        printf("----------------------------\n");

        delete N1;
        delete N2;
        delete N3;
        delete N4;
        delete N5;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: head = [3,3,1,5]\n");
    printf("expected result: output = [3,5,3,1]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(3, N3);
        ListNode *head = N4;
        
        Solution solution;
        
        solution.reorderList(head);
        printf("after reorder list\n");
        while (head!=NULL)
        {
            printf("val:%d\n", head->val);
            head = head->next;
        }
        printf("----------------------------\n");

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
