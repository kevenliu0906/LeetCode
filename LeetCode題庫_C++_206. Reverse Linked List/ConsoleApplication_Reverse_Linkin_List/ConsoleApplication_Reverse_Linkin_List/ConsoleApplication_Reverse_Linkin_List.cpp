// ConsoleApplication_Reverse_Linkin_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
 


class Solution{
public:
    ListNode* reverseList(ListNode* head) {

        // solution 0 (keven, best)
        {
            ListNode *tmp_head = NULL;
            ListNode* tmp = NULL;
            while (head!=NULL)
            {
                // printf("headlist->nodeval:%d\n", head->val);
                tmp = head;
                head = head->next;  // need move the origin list head to next to avoid have influence on original list
                
                tmp->next = NULL;  

                if (tmp_head == NULL){
                    ;
                }else{
                    tmp->next = tmp_head;   
                }
                tmp_head = tmp;
                
                // printf("tmplist->nodeval:%d\n", tmp->val);

            }

            return tmp_head;
        }
        
        // solution 1 (keven)
        {
            vector<ListNode *> origin_list_vec;

            while (head!=NULL)
            {
                if ( origin_list_vec.size() == 0 )
                {
                    origin_list_vec.push_back(head);
                }
                else{
                    origin_list_vec.insert(origin_list_vec.begin(), head);
                }
                
                head = head->next;
            }

            ListNode *current = NULL;
            // printf("********** reverseList ************\n");
            for (int i = 0; i<origin_list_vec.size(); i++)
            {
                // printf("node->val:%d\n", origin_list_vec[i]->val);
                auto tmp = origin_list_vec[i];
                tmp->next = NULL;
                if( head == NULL ){
                    head = tmp;
                }else{
                    current->next = tmp;
                }
                current = tmp;
            }
            // printf("***********************************\n");

            // // check the final result
            // printf("******* check value **********\n");
            // ListNode *check = head;
            // while (check!=NULL)
            // {
            //     printf("val:%d\n", check->val);
            //     check = check->next;
            // }
            // printf("******************************\n");

            return head;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - DataStructure(LinkList))!\n";
    cout << "https://leetcode.com/problems/reverse-linked-list" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5]\n");
    printf("expected result: output = [5,4,3,2,1]\n");
    {
        ListNode *A_N1 = new ListNode(5);
        ListNode *A_N2 = new ListNode(4);
        A_N2->next = A_N1;
        ListNode *A_N3 = new ListNode(3);
        A_N3->next = A_N2;
        ListNode *A_N4 = new ListNode(2);
        A_N4->next = A_N3;
        ListNode *A_N5 = new ListNode(1);
        A_N5->next = A_N4;
        ListNode *head = A_N5;
        // printf("linked list:\n");
        // ListNode *view = head;
        // while( view ){
        //     printf("node->val:%d\n", view->val);
        //     view = view->next;
        // }
        
        Solution solution;
        auto result = solution.reverseList(head);
        printf("reverse linked list:\n");
        while( result ){
            printf("node:%d\n", result->val);
            result = result->next;
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
    printf("input: head = [1,2]\n");
    printf("expected result: output = [2,1]\n");
    {
        ListNode *A_N1 = new ListNode(2);
        ListNode *A_N2 = new ListNode(1);
        A_N2->next = A_N1;
        
        ListNode *head = A_N2;
        // printf("linked list:\n");
        // ListNode *view = head;
        // while( view ){
        //     printf("node->val:%d\n", view->val);
        //     view = view->next;
        // }
        
        Solution solution;
        auto result = solution.reverseList(head);
        printf("reverse linked list:\n");
        while( result ){
            printf("node:%d\n", result->val);
            result = result->next;
        }

        delete A_N1;
        delete A_N2;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = []\n");
    printf("expected result: output = []\n");
    {
        ListNode *head = NULL;
                
        Solution solution;
        auto result = solution.reverseList(head);
        printf("reverse linked list:\n");
        while( result ){
            printf("node:%d\n", result->val);
            result = result->next;
        }
        
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
