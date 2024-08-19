// Console_Reverse_Nodes_in_K_Group.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // solution 1 (keven, using array to solve it)
        {
            int node_count = 0;
            ListNode *result_group_head = NULL;
            ListNode *result_group_now = NULL;
            vector<ListNode*> node_group_vec;    // record each node of group by array

            while (head)
            {
                node_count++;
                auto current_node = head;
                
                // STEP1: record each node of group by array
                // printf("STEP1\n");
                head = head->next;
                current_node->next = NULL;
                node_group_vec.push_back(current_node);
                // node_vec.insert(node_group_vec.begin(), current_node);

                // STEP2: judge when the count of node in array reach k
                // printf("STEP2\n");
                if (node_count == k)
                {
                    // STEP2-1: reverse the array 
                    // printf("STEP2-1\n");
                    vector<ListNode*> tmp_node_group_vec(node_group_vec.rbegin(), node_group_vec.rend());

                    // STEP2-2: linked each node in group to next node
                    // printf("STEP2-2\n");
                    for (size_t i = 0; i < node_count; i++)
                    {
                        if ( i+1 < node_count)
                            tmp_node_group_vec[i]->next = tmp_node_group_vec[i+1];
                        else
                            tmp_node_group_vec[i]->next = NULL;
                    }

                    // STEP2-3: linked each group head to each other
                    // printf("STEP2-3\n");
                    if (result_group_head == NULL)
                    {
                        result_group_head = tmp_node_group_vec[0];
                    }
                    else
                    {
                        result_group_now->next = tmp_node_group_vec[0];
                    }
                    result_group_now = tmp_node_group_vec[node_count - 1];

                    // reset the array for next group
                    node_count = 0;
                    node_group_vec.clear();
                }
            }

            // STEP3: apply the last one if exist(this case could not reach the reverse count, so do NOT need to execute reverse)
            // printf("STEP3\n");
            if (node_count != 0)
            {
                // STEP3-1: linked each node in group to next node
                // printf("STEP3-1\n");
                for (size_t i = 0; i < node_count; i++)
                {       
                    if ( i+1 < node_count)
                        node_group_vec[i]->next = node_group_vec[i+1];
                    else
                        node_group_vec[i]->next = NULL;
                }

                // STEP3-2: linked each group head to each other
                // printf("STEP3-2\n");
                if (result_group_head == NULL)
                {
                    result_group_head = node_group_vec[0];
                }
                else
                {
                    result_group_now->next = node_group_vec[0];
                }
                result_group_now = node_group_vec[node_count - 1];
            }
            
            return result_group_head;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Reverse Nodes in K Group, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/reverse-nodes-in-k-group/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5], k = 2\n");
    printf("expected result: output = [2,1,4,3,5]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int k = 2;

        Solution solution;
        auto result = solution.reverseKGroup(head, k);
        if (result == NULL){
            printf("reverseKGroup: result is NULL\n");
        }else{
            printf("reverseKGroup: result is val:\n");
            while (result)
            {
                printf("%d, ", result->val);
                result = result->next;
            }
            printf("\n");
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
    printf("input: head = [1,2,3,4,5], k = 3\n");
    printf("expected result: output = [3,2,1,4,5]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int k = 3;

        Solution solution;
        auto result = solution.reverseKGroup(head, k);
        if (result == NULL){
            printf("reverseKGroup: result is NULL\n");
        }else{
            printf("reverseKGroup: result is val:\n");
            while (result)
            {
                printf("%d, ", result->val);
                result = result->next;
            }
            printf("\n");
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
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [1,2,3,4,5], k = 1\n");
    printf("expected result: output = [1,2,3,4,5]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int k = 1;

        Solution solution;
        auto result = solution.reverseKGroup(head, k);
        if (result == NULL){
            printf("reverseKGroup: result is NULL\n");
        }else{
            printf("reverseKGroup: result is val:\n");
            while (result)
            {
                printf("%d, ", result->val);
                result = result->next;
            }
            printf("\n");
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
