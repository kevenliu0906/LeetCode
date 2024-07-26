// ConsoleApplication_SortedList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <map>
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
    ListNode* sortList(ListNode* head) {

        // solution 0 (keven, using merge sort)
        {
            if (head==NULL || head->next==NULL)
            {
                // represent only one node or empty node in current listNode
                return head;
            }
            
            vector<ListNode*> head_vec;
            ListNode *tmp = head;
            while(tmp!=NULL){
                head_vec.push_back(tmp);
                tmp = tmp->next;
            }
            int totalListNode = head_vec.size();

            // separate two listNode to sort
            ListNode* leftListNode_head = head_vec[0];
            ListNode* leftListNode_now = head_vec[totalListNode/2-1];
            leftListNode_now->next = NULL;

            ListNode* rightListNode_head = head_vec[totalListNode/2];
            ListNode* rightListNode_now = head_vec[totalListNode-1];
            
            // // left-part sort
            // printf("-----------------------------------\n");
            // printf("left_part-> sortList\n");
            // // debug
            // {
            //     ListNode *dbg = leftListNode_head;
            //     while (dbg != NULL)
            //     {
            //         printf("val:%d\n", dbg->val);
            //         dbg = dbg->next;
            //     }
            // }
            leftListNode_head = sortList(leftListNode_head);
            // printf("-----------------------------------\n");
            
            // // right-part sort
            // printf("-----------------------------------\n");
            // printf("right_part-> sortList\n");
            // // debug
            // {
            //     ListNode *dbg = rightListNode_head;
            //     while (dbg != NULL)
            //     {
            //         printf("val:%d\n", dbg->val);
            //         dbg = dbg->next;
            //     }
            // }
            rightListNode_head = sortList(rightListNode_head);
            // printf("-----------------------------------\n");

            ListNode *newListNode = NULL;
            ListNode *nowListNode = NULL;
            // merge "left-part" and "right-part"
            while( leftListNode_head != NULL && rightListNode_head != NULL ){
                if (leftListNode_head->val < rightListNode_head->val){
                    // left side element is smaller
                    if (newListNode == NULL){
                        newListNode = leftListNode_head;
                    }else{
                        nowListNode->next = leftListNode_head;
                    }
                    nowListNode = leftListNode_head;

                    leftListNode_head = leftListNode_head->next;
                }else{
                    // right side element is smaller
                    if (newListNode == NULL){
                        newListNode = rightListNode_head;
                    }else{
                        nowListNode->next = rightListNode_head;
                    }
                    nowListNode = rightListNode_head;
                    
                    rightListNode_head = rightListNode_head->next;
                }
            }

            while (leftListNode_head != NULL){
                nowListNode->next = leftListNode_head;
                nowListNode = leftListNode_head;
                // 
                leftListNode_head = leftListNode_head->next;
            }
            
            while (rightListNode_head != NULL){
                nowListNode->next = rightListNode_head;
                nowListNode = rightListNode_head;
                // 
                rightListNode_head = rightListNode_head->next;
            }

            return newListNode;
        }

        // // solution 1 (keven, using HASH TABLE)
        // {
        //     ListNode *tmp = head;
        //     multimap<int, ListNode*> sortlist_val_listnode_multimap;

        //     while (tmp!=NULL)
        //     {
        //         ListNode *current = tmp;
        //         tmp = tmp->next;

        //         current->next = NULL;
        //         sortlist_val_listnode_multimap.insert(pair<int, ListNode*>(current->val, current));
        //     }

        //     // debug
        //     // int itemCount = 0;
        //     ListNode *now = NULL;
        //     head = NULL;
        //     for (auto listnode_multimap_each : sortlist_val_listnode_multimap)
        //     {
        //         if (head == NULL){
        //             head = listnode_multimap_each.second;
        //         }else{
        //             now->next = listnode_multimap_each.second;
        //         }
        //         now = listnode_multimap_each.second;
        //         // itemCount++;
        //         // printf("item:%d, val:%d\n", itemCount, listnode_multimap_each.first);
        //     }
        //     return head;
        // }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Sorted List, Algorithm & DataStructure(Two Pointers, Divide and Conquer, Merge Sort, Linked List)!\n";
    cout << "https://leetcode.com/problems/sort-list/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [-1,5,3,4,0]\n");
    printf("expected result: output = [-1,0,3,4,5]\n");
    {
        ListNode *N1 = new ListNode(0, NULL);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(5, N3);
        ListNode *N5 = new ListNode(-1, N4);
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

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [-3,9,-100000,20,100000,0,-500,1,0,9,20]\n");
    printf("expected result: output = [-100000,-500,-3,0,0,1,9,9,20,20,100000]\n");
    {
        ListNode *N1 = new ListNode(20, NULL);
        ListNode *N2 = new ListNode(9, N1);
        ListNode *N3 = new ListNode(0, N2);
        ListNode *N4 = new ListNode(1, N3);
        ListNode *N5 = new ListNode(-500, N4);
        ListNode *N6 = new ListNode(0, N5);
        ListNode *N7 = new ListNode(100000, N6);
        ListNode *N8 = new ListNode(20, N7);
        ListNode *N9 = new ListNode(-100000, N8);
        ListNode *N10 = new ListNode(9, N9);
        ListNode *N11 = new ListNode(-3, N10);
        ListNode *head = N11;
        
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
        delete N6;
        delete N7;
        delete N8;
        delete N9;
        delete N10;
        delete N11;
        
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
