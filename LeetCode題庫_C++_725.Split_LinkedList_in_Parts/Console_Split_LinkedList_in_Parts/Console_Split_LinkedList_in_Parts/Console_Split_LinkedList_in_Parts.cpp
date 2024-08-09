// Console_Split_LinkedList_in_Parts.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // solution 1 (keven, best, using vector and math to solve)
        {
            int total_node_count = 0;
            ListNode *tmp_head = head;
            vector<ListNode*> result;

            result.resize(k, NULL);

            while (tmp_head)
            {
                total_node_count++;
                tmp_head = tmp_head->next;
            }

            // printf("total_node_count:%d\n", total_node_count);
            auto each_part_count = 0;
            int current_part_index = 0;

            tmp_head = head;
            while (total_node_count > 0)
            {
                result[current_part_index] = tmp_head;
                auto move_count  = 0;
                auto last_tmp_head = tmp_head;

                if (total_node_count%k == 0){
                    each_part_count = total_node_count/k;
                }else{
                    each_part_count = total_node_count/k + 1;
                }

                // printf("current_part_index:%d, each_part_count:%d\n", current_part_index, each_part_count);
                while (move_count < each_part_count)
                {
                    last_tmp_head = tmp_head;
                    tmp_head = tmp_head->next;
                    move_count++;
                }
                last_tmp_head->next = NULL;

                // update the rest of count for other move
                total_node_count -= move_count;
                k--;

                // move to the next part-index
                current_part_index++;
            }
            
            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Split Linked List in Parts, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/split-linked-list-in-parts" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3], k = 5\n");
    printf("expected result: output = [[1],[2],[3],[],[]]\n");
    {
        ListNode *N1 = new ListNode(3, NULL);
        ListNode *N2 = new ListNode(2, N1);
        ListNode *N3 = new ListNode(1, N2);
        ListNode *head = N3;
        int k = 5;

        Solution solution;
        auto result = solution.splitListToParts(head, k);
        if (result.size() == 0)
        {
            printf("result is NULL\n");
        }
        
        for (size_t i = 0; i < result.size(); i++)
        {
            auto listnode = result[i];
            if (listnode == NULL)
            {
                printf("result[%d]:NULL\n", i);
            }else{
                printf("result[%d]:", i);
                while (listnode)
                {
                    printf("%d,", listnode->val);
                    listnode = listnode->next;
                }
                printf("\n");
            }
            
        }

        delete N1;
        delete N2;
        delete N3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1,2,3,4,5,6,7,8,9,10], k = 3\n");
    printf("expected result: output = [[1,2,3,4],[5,6,7],[8,9,10]]\n");
    {
        ListNode *N1 = new ListNode(10, NULL);
        ListNode *N2 = new ListNode(9, N1);
        ListNode *N3 = new ListNode(8, N2);
        ListNode *N4 = new ListNode(7, N3);
        ListNode *N5 = new ListNode(6, N4);
        ListNode *N6 = new ListNode(5, N5);
        ListNode *N7 = new ListNode(4, N6);
        ListNode *N8 = new ListNode(3, N7);
        ListNode *N9 = new ListNode(2, N8);
        ListNode *N10 = new ListNode(1, N9);
        ListNode *head = N10;
        int k = 3;

        Solution solution;
        auto result = solution.splitListToParts(head, k);
        if (result.size() == 0)
        {
            printf("result is NULL\n");
        }
        
        for (size_t i = 0; i < result.size(); i++)
        {
            auto listnode = result[i];
            if (listnode == NULL)
            {
                printf("result[%d]:NULL\n", i);
            }else{
                printf("result[%d]:", i);
                while (listnode)
                {
                    printf("%d,", listnode->val);
                    listnode = listnode->next;
                }
                printf("\n");
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
    printf("input: head = [], k = 1\n");
    printf("expected result: output = [[]]\n");
    {
        ListNode *head = NULL;
        int k = 1;

        Solution solution;
        auto result = solution.splitListToParts(head, k);
        if (result.size() == 0)
        {
            printf("result is NULL\n");
        }
        
        for (size_t i = 0; i < result.size(); i++)
        {
            auto listnode = result[i];
            if (listnode == NULL)
            {
                printf("result[%d]:NULL\n", i);
            }else{
                printf("result[%d]:", i);
                while (listnode)
                {
                    printf("%d,", listnode->val);
                    listnode = listnode->next;
                }
                printf("\n");
            }
            
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1,2,3,4,5], k = 3\n");
    printf("expected result: output = [[1,2],[3,4],[5]]\n");
    {
        ListNode *N1 = new ListNode(5, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int k = 3;

        Solution solution;
        auto result = solution.splitListToParts(head, k);
        if (result.size() == 0)
        {
            printf("result is NULL\n");
        }
        
        for (size_t i = 0; i < result.size(); i++)
        {
            auto listnode = result[i];
            if (listnode == NULL)
            {
                printf("result[%d]:NULL\n", i);
            }else{
                printf("result[%d]:", i);
                while (listnode)
                {
                    printf("%d,", listnode->val);
                    listnode = listnode->next;
                }
                printf("\n");
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
