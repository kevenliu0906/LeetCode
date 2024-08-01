// Console_Insertion_Sort_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <map>

using namespace std;


//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:

    void insert_node_with_sorting(ListNode *target, ListNode *tmp_head, ListNode *tmp_current){
        // judge if target->val is behind the tmp_head->val or the tmp_current->val
        // assume list-node order is "tmp_head" ---> "tmp_current"
        if (target->val >= tmp_current->val)
        {
            // node order case is "tmp_head" --> "tmp_current" ---> "target"
            ListNode *search_node = tmp_current;
            ListNode *goal_node = NULL;
            while (target->val >= search_node->val)
            {
                goal_node = search_node;
                search_node = search_node->next;
                if (search_node == NULL)
                {
                    break;
                }
                
            }
            goal_node->next = target;
            tmp_current = target;
        }
        else if (target->val >= tmp_head->val && target->val < tmp_current->val)
        {
            // node order case is "tmp_head" --> "target" --> "tmp_current"
            ListNode *search_node = tmp_head;
            ListNode *goal_node = NULL;
            while (target->val >= search_node->val)
            {
                goal_node = search_node;
                search_node = search_node->next;
                if (search_node == NULL)
                {
                    break;
                }
                
            }

            goal_node->next = target;
            tmp_current = target;
        }
        else
        {
            // node order case is "target" --> "tmp_head" --> "tmp_current"
            target->next = tmp_head;
            tmp_head = target;
            tmp_current = target;
        }
        
    }

    ListNode* insertionSortList(ListNode* head) {

        // solution 0 (keven, using map to solve)
        {
            ListNode *tmp = head;
            ListNode *result = NULL;
            multimap<int, ListNode*> listnode_val_next_multimap;

            while (tmp != NULL)
            {
                listnode_val_next_multimap.insert(pair<int,ListNode*>(tmp->val, tmp));
                tmp = tmp->next;
            }

            result = NULL;
            tmp = NULL;
            for (auto listnode_val_next_multimap_each : listnode_val_next_multimap)
            {
                auto list_node_ptr = listnode_val_next_multimap_each.second;
                list_node_ptr->next = NULL;   // reset the next pointer for each list-node(MUST!!!!)

                // printf("current->val:%d\n", list_node_ptr->val);
                if (result == NULL){
                    result = list_node_ptr;
                }else{
                    tmp->next = list_node_ptr;
                }
                tmp = list_node_ptr;
            }
            
            return result;
        }

        // solution 1 (keven, direct sort the list-node, have bug)
        {
            ListNode *result_head = NULL;
            ListNode *result_current = NULL;

            while (head!=NULL)
            {
                auto now = head;
                head = head->next;
                // now->next = NULL;

                if (result_current == NULL){
                    result_head = now;
                }
                else{
                    // insert current list node into existed list with sorting
                    {
                        insert_node_with_sorting(now, result_head, result_current);
                    }
                }
                result_current = now;
                
            }
            

            return result_head;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Insertion Sort List, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/insertion-sort-list/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [4,2,1,3]\n");
    printf("expected result: output = [1,2,3,4]\n");
    {
        ListNode *N1 = new ListNode(3, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(4, N3);
        ListNode *head = N4;
        ListNode *tmp = head;

        printf("origin List: >>>>> \n");
        while (tmp!=NULL)
        {
            printf("val:%d\n", tmp->val);
            tmp = tmp->next;
        }

        Solution solution;
        auto result = solution.insertionSortList(head);

        printf("after insertion Sort List: >>>>> \n");
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [-1,5,3,4,0]\n");
    printf("expected result: output = [-1,0,3,4,5]\n");
    {
        ListNode *N1 = new ListNode(0, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(5, N3);
        ListNode *N5 = new ListNode(-1, N4);
        ListNode *head = N5;
        ListNode *tmp = head;

        printf("origin List: >>>>> \n");
        while (tmp!=NULL)
        {
            printf("val:%d\n", tmp->val);
            tmp = tmp->next;
        }

        Solution solution;
        auto result = solution.insertionSortList(head);

        printf("after insertion Sort List: >>>>> \n");
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
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [1,1]\n");
    printf("expected result: output = [1,1]\n");
    {
        ListNode *N1 = new ListNode(1, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *head = N2;
        ListNode *tmp = head;

        printf("origin List: >>>>> \n");
        while (tmp!=NULL)
        {
            printf("val:%d\n", tmp->val);
            tmp = tmp->next;
        }

        Solution solution;
        auto result = solution.insertionSortList(head);

        printf("after insertion Sort List: >>>>> \n");
        while (result!=NULL)
        {
            printf("val:%d\n", result->val);
            result = result->next;
        }

        delete N1;
        delete N2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [5,1,2,1,-3]\n");
    printf("expected result: output = [-3,1,1,2,5]\n");
    {
        ListNode *N1 = new ListNode(-3, NULL);
        ListNode *N2 = new ListNode(1, N1);
        ListNode *N3 = new ListNode(2, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *N5 = new ListNode(5, N4);
        ListNode *head = N5;
        ListNode *tmp = head;

        printf("origin List: >>>>> \n");
        while (tmp!=NULL)
        {
            printf("val:%d\n", tmp->val);
            tmp = tmp->next;
        }

        Solution solution;
        auto result = solution.insertionSortList(head);

        printf("after insertion Sort List: >>>>> \n");
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
