// Console_Swap_Nodes_in_LinkedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    ListNode* swapNodes(ListNode* head, int k) {

        // solution 1(keven, using array & two pointer to solve)        
        {
            vector<ListNode*> list_node_vec;
            ListNode* tmp_head = head;

            // STEP1. record all list-node value in array
            while (tmp_head)
            {
                list_node_vec.push_back(tmp_head);
                tmp_head = tmp_head->next;
            }

            // STEP2. swap the indicated-position node
            int tmp_value = list_node_vec[k-1]->val;
            list_node_vec[k-1]->val = list_node_vec[list_node_vec.size()-k]->val;
            list_node_vec[list_node_vec.size()-k]->val = tmp_value;

        }
        return head;
    }
};

int main()
{
    std::cout << "Hello LeetCode , Swapping Nodes in a Linked List, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/swapping-nodes-in-a-linked-list/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5], k = 2\n");
    printf("expected result: output = [1,4,3,2,5]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int k = 2;

        // Your Solution object will be instantiated and called as such:
        Solution solution;
        auto result = solution.swapNodes(head, k);
        if (result == NULL)
        {
            printf("result is NULL\n");
        }
        else{
            printf("result is:\n");
            while (result)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
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
    printf("input: head = [7,9,6,6,7,8,3,0,9,5], k = 5\n");
    printf("expected result: output = [7,9,6,6,8,7,3,0,9,5]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(9, N1);
        ListNode *N3 = new ListNode(0, N2);
        ListNode *N4 = new ListNode(3, N3);
        ListNode *N5 = new ListNode(8, N4);
        ListNode *N6 = new ListNode(7, N5);
        ListNode *N7 = new ListNode(6, N6);
        ListNode *N8 = new ListNode(6, N7);
        ListNode *N9 = new ListNode(9, N8);
        ListNode *N10 = new ListNode(7, N9);
        ListNode *head = N10;
        int k = 5;

        // Your Solution object will be instantiated and called as such:
        Solution solution;
        auto result = solution.swapNodes(head, k);
        if (result == NULL)
        {
            printf("result is NULL\n");
        }
        else{
            printf("result is:\n");
            while (result)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }
        
        delete N1;
        delete N2;
        delete N3;
        delete N4;
        delete N5;
        delete N6;
        delete N7;
        delete N8;
        delete N9;
        delete N10;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [1,2,3,4,5], k = 3\n");
    printf("expected result: output = [1,2,3,4,5]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int k = 3;

        // Your Solution object will be instantiated and called as such:
        Solution solution;
        auto result = solution.swapNodes(head, k);
        if (result == NULL)
        {
            printf("result is NULL\n");
        }
        else{
            printf("result is:\n");
            while (result)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
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
    printf("************* testcase 4 ****************************\n");
    printf("input: head = [1,2,3,4], k = 2\n");
    printf("expected result: output = [1,3,2,4]\n");
    {
        ListNode *N1 = new ListNode(4, NULL);
        ListNode *N2 = new ListNode(3, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *head = N4;
        int k = 2;

        // Your Solution object will be instantiated and called as such:
        Solution solution;
        auto result = solution.swapNodes(head, k);
        if (result == NULL)
        {
            printf("result is NULL\n");
        }
        else{
            printf("result is:\n");
            while (result)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }
        
        delete N1;
        delete N2;
        delete N3;
        delete N4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: head = [6], k = 1\n");
    printf("expected result: output = [6]\n");
    {
        ListNode *N1 = new ListNode(6, NULL);
        ListNode *head = N1;
        int k = 1;

        // Your Solution object will be instantiated and called as such:
        Solution solution;
        auto result = solution.swapNodes(head, k);
        if (result == NULL)
        {
            printf("result is NULL\n");
        }
        else{
            printf("result is:\n");
            while (result)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
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
