// ConsoleApplication_Odd_Even_LinkedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    ListNode* oddEvenList(ListNode* head) {

        // solution 0 (keven, using array to store the odd-list and even-list)
        {
            ListNode *current = head;
            vector<ListNode *> odd_node_vec;
            vector<ListNode *> even_node_vec;
            int total_node_count = 0;
            // group the odd_node & even_node
            while (current != NULL)
            {
                total_node_count++;
                auto tmp = current;
                current = current->next;
                tmp->next = NULL;
                if (total_node_count%2)
                {
                    odd_node_vec.push_back(tmp);
                }
                else{
                    even_node_vec.push_back(tmp);
                }

                
            }
            
            head = NULL;
            current = NULL;
            // assign odd-list first
            for (size_t i = 0; i < odd_node_vec.size(); i++)
            {
                // printf("odd_node_vec[%d].val:%d\n", i, odd_node_vec[i]->val);
                auto tmp = odd_node_vec[i];
                if (current == NULL){
                    head = tmp;
                }
                else{
                    current->next = tmp;
                }
                current = tmp;
                
            }

            // then assign even-list
            for (size_t i = 0; i < even_node_vec.size(); i++)
            {
                // printf("even_node_vec[%d].val:%d\n", i, even_node_vec[i]->val);
                auto tmp = even_node_vec[i];
                if (current == NULL){
                    head = tmp;
                }
                else{
                    current->next = tmp;
                }
                current = tmp;
            }
            
            return head;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Odd Even Linked List, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/odd-even-linked-list/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5]\n");
    printf("expected result: output = [1,3,5,2,4]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        
        Solution solution;
        auto result = solution.oddEvenList(head);
        printf("after odd even\n");
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
    printf("input: head = [2,1,3,5,6,4,7]\n");
    printf("expected result: output = [2,3,6,7,1,5,4]\n");
    {
        ListNode *N1 = new ListNode(7, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(6, N2);
        ListNode *N4 = new ListNode(5, N3);
        ListNode *N5 = new ListNode(3, N4);
        ListNode *N6 = new ListNode(1, N5);
        ListNode *N7 = new ListNode(2, N6);
        ListNode *head = N7;
        
        Solution solution;
        auto result = solution.oddEvenList(head);
        printf("after odd even\n");
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
        delete N7;
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
