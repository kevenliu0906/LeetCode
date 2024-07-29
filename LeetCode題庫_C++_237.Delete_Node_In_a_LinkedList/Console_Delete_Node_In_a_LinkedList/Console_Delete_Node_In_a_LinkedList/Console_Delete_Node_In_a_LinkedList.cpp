// Console_Delete_Node_In_a_LinkedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *head = NULL;
    void deleteNode(ListNode* node) {     
        
        // solution 0 (best)
        // 思路: 1. 刪除節點x時，通常我們會將x - 1的next指向x + 1，並將節點x刪除。
        //       2. 但因為這題只給予目標節點的存取權，拿不到所謂的x - 1，因為我們換一個做法。
        //       3.(I.M.P) 我們先將x的值設為x + 1的值，然後直接將x的next指向x + 2，最後將x + 1刪除。  <<------ 此篇重點
        // reference: https://hackmd.io/@Zero871015/LeetCode-237
        //            https://ithelp.ithome.com.tw/m/articles/10239394  
        {
            ListNode *tmp = node->next;    // record x+1
            node->val = node->next->val;   // x value is assigned to x+1
            node->next = node->next->next; // x next is assigned to x+2
            delete tmp;                    // delete x+1
        }
        
    }
};

int main()
{
    std::cout << "Hello LeetCode - Delete Node in a Linked List, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/delete-node-in-a-linked-list/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [4,5,1,9], node = 5\n");
    printf("expected result: output = [4,1,9]\n");
    {
        ListNode *N1 = new ListNode(9);
        N1->next = NULL;
        ListNode *N2 = new ListNode(1);
        N2->next = N1;
        ListNode *N3 = new ListNode(5);
        N3->next = N2;
        ListNode *N4 = new ListNode(4);
        N4->next = N3;
        
        Solution solution;
        solution.head = N4;
        
        ListNode *head = solution.head;
        ListNode *tmp_head = solution.head;

        printf("before delete node:\n");
        while (head!=NULL)
        {
            printf("val:%d\n", head->val);
            head = head->next;
        }
        printf("----------------------------\n");
        
        solution.deleteNode(N3);
        printf("after delete node\n");
        while (tmp_head!=NULL)
        {
            printf("val:%d\n", tmp_head->val);
            tmp_head = tmp_head->next;
        }
        printf("----------------------------\n");

        delete N1;
        // delete N2;
        delete N3;
        delete N4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [4,5,1,9], node = 1\n");
    printf("expected result: output = [4,5,9]\n");
    {
        ListNode *N1 = new ListNode(9);
        N1->next = NULL;
        ListNode *N2 = new ListNode(1);
        N2->next = N1;
        ListNode *N3 = new ListNode(5);
        N3->next = N2;
        ListNode *N4 = new ListNode(4);
        N4->next = N3;
        
        Solution solution;
        solution.head = N4;
        
        ListNode *head = solution.head;
        ListNode *tmp_head = solution.head;

        printf("before delete node:\n");
        while (head!=NULL)
        {
            printf("val:%d\n", head->val);
            head = head->next;
        }
        printf("----------------------------\n");
        
        solution.deleteNode(N2);
        printf("after delete node\n");
        while (tmp_head!=NULL)
        {
            printf("val:%d\n", tmp_head->val);
            tmp_head = tmp_head->next;
        }
        printf("----------------------------\n");

        // delete N1;
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
