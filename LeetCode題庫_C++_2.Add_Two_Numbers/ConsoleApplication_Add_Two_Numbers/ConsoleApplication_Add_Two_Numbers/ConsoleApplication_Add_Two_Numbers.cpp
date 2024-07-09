// ConsoleApplication_Add_Two_Numbers.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        
        int sum = 0;
        int over_digit_num = 0;  // store the sum over digit
        ListNode* L1_ptr = l1;
        ListNode* L2_ptr = l2;
        ListNode* Head_ptr = NULL;
        ListNode* Tail_ptr = NULL;
        
        // solution 1 (keven)
        {
            while (L1_ptr != NULL || L2_ptr != NULL || over_digit_num) {
                // reset
                sum = 0;
                int L1_val = -1;
                int L2_val = -1;

                if (L1_ptr != NULL) {
                    L1_val = L1_ptr->val;
                    sum += L1_ptr->val;
                }
                if (L2_ptr != NULL) {
                    L2_val = L2_ptr->val;
                    sum += L2_ptr->val;
                }

                sum += over_digit_num;
                // printf("current sum:%d, L1_ptr->val:%d, L2_ptr->val:%d, over_digit_num:%d\n", sum, L1_val, L2_val, over_digit_num);
                
                
                int NewNodeValue = sum % 10;
                over_digit_num = sum / 10;

                // prepare new list node to store the sum
                ListNode *NewNode = new ListNode(NewNodeValue);
                if( Tail_ptr == NULL ){
                    Head_ptr = NewNode;
                    Tail_ptr = NewNode;
                }else{
                    Tail_ptr->next = NewNode;
                    Tail_ptr = NewNode;
                }

                // move to next list node
                if( L1_ptr != NULL )
                    L1_ptr = L1_ptr->next;
                if( L2_ptr != NULL )
                    L2_ptr = L2_ptr->next;
            }
        }

        return Head_ptr;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Add Two Numbers, DataStructure(Linked List, Recursion)!\n";

    printf("LeetCode - 2. Add Two Numbers\n");
    cout << "https://leetcode.com/problems/add-two-numbers" << endl << endl;
    // cout << "solution: https://medium.com/@zero.ling/c-sort-a-map-by-value-601a60ec0e01" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: l1 = [2, 4, 3], l2 = [5, 6, 4]\n");
    printf("expected result: nums = [7, 0, 8]\n");
    {
        ListNode *New_l1_1 = new ListNode(3, NULL);
        ListNode *New_l1_2 = new ListNode(4, New_l1_1);
        ListNode *New_l1_3 = new ListNode(2, New_l1_2);

        ListNode* New_l2_1 = new ListNode(4, NULL);
        ListNode* New_l2_2 = new ListNode(6, New_l2_1);
        ListNode* New_l2_3 = new ListNode(5, New_l2_2);

        ListNode *ptr_l1 = NULL;
        ListNode *ptr_l2 = NULL;
        
        // ListNode *ptr_l1 = New_l1_3;
        // // show the elements
        // while( ptr_l1 != NULL ){
        //     printf("current_ptr: ptr_l1->val:%d\n", ptr_l1->val);
        //     ptr_l1 = ptr_l1->next;
        // }
        // printf("*************************\n");
        // ListNode *ptr_l2 = New_l2_3;
        // // show the elements
        // while (ptr_l2 != NULL) {
        //     printf("current_ptr: ptr_l2->val:%d\n", ptr_l2->val);
        //     ptr_l2 = ptr_l2->next;
        // }
        // printf("*************************\n\n\n");

        ptr_l1 = New_l1_3;
        ptr_l2 = New_l2_3;

        Solution solution;
        auto result = solution.addTwoNumbers(ptr_l1, ptr_l2);
        printf("result: AddLinkList:\n");
        ListNode* res_ptr = result;
        while( res_ptr != NULL ){
            printf("res_ptr->val:%d\n", res_ptr->val);
            res_ptr = res_ptr->next;
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");
    
    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: l1 = [2, 4, 3], l2 = [5, 6, 6]\n");
    printf("expected result: nums = [7, 0, 0, 1]\n");
    {
        ListNode *New_l1_1 = new ListNode(3, NULL);
        ListNode *New_l1_2 = new ListNode(4, New_l1_1);
        ListNode *New_l1_3 = new ListNode(2, New_l1_2);

        ListNode* New_l2_1 = new ListNode(6, NULL);
        ListNode* New_l2_2 = new ListNode(6, New_l2_1);
        ListNode* New_l2_3 = new ListNode(5, New_l2_2);

        ListNode *ptr_l1 = NULL;
        ListNode *ptr_l2 = NULL;
        
        // ListNode *ptr_l1 = New_l1_3;
        // // show the elements
        // while( ptr_l1 != NULL ){
        //     printf("current_ptr: ptr_l1->val:%d\n", ptr_l1->val);
        //     ptr_l1 = ptr_l1->next;
        // }
        // printf("*************************\n");
        // ListNode *ptr_l2 = New_l2_3;
        // // show the elements
        // while (ptr_l2 != NULL) {
        //     printf("current_ptr: ptr_l2->val:%d\n", ptr_l2->val);
        //     ptr_l2 = ptr_l2->next;
        // }
        // printf("*************************\n\n\n");

        ptr_l1 = New_l1_3;
        ptr_l2 = New_l2_3;

        Solution solution;
        auto result = solution.addTwoNumbers(ptr_l1, ptr_l2);
        printf("result: AddLinkList:\n");
        ListNode* res_ptr = result;
        while( res_ptr != NULL ){
            printf("res_ptr->val:%d\n", res_ptr->val);
            res_ptr = res_ptr->next;
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");


    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: l1 = [0], l2 = [0]\n");
    printf("expected result: nums = [0]\n");
    {
        ListNode *New_l1_1 = new ListNode(0, NULL);
        ListNode* New_l2_1 = new ListNode(0, NULL);

        ListNode *ptr_l1 = NULL;
        ListNode *ptr_l2 = NULL;
        
        // ListNode *ptr_l1 = New_l1_1;
        // // show the elements
        // while( ptr_l1 != NULL ){
        //     printf("current_ptr: ptr_l1->val:%d\n", ptr_l1->val);
        //     ptr_l1 = ptr_l1->next;
        // }
        // printf("*************************\n");
        // ListNode *ptr_l2 = New_l2_1;
        // // show the elements
        // while (ptr_l2 != NULL) {
        //     printf("current_ptr: ptr_l2->val:%d\n", ptr_l2->val);
        //     ptr_l2 = ptr_l2->next;
        // }
        // printf("*************************\n\n\n");

        ptr_l1 = New_l1_1;
        ptr_l2 = New_l2_1;

        Solution solution;
        auto result = solution.addTwoNumbers(ptr_l1, ptr_l2);
        printf("result: AddLinkList:\n");
        ListNode* res_ptr = result;
        while( res_ptr != NULL ){
            printf("res_ptr->val:%d\n", res_ptr->val);
            res_ptr = res_ptr->next;
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");


    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]\n");
    printf("expected result: nums = [8, 9, 9, 9, 0, 0, 0, 1]\n");
    {
        ListNode *New_l1_1 = new ListNode(9, NULL);
        ListNode *New_l1_2 = new ListNode(9, New_l1_1);
        ListNode *New_l1_3 = new ListNode(9, New_l1_2);
        ListNode *New_l1_4 = new ListNode(9, New_l1_3);
        ListNode *New_l1_5 = new ListNode(9, New_l1_4);
        ListNode *New_l1_6 = new ListNode(9, New_l1_5);
        ListNode *New_l1_7 = new ListNode(9, New_l1_6);

        ListNode* New_l2_1 = new ListNode(9, NULL);
        ListNode* New_l2_2 = new ListNode(9, New_l2_1);
        ListNode* New_l2_3 = new ListNode(9, New_l2_2);
        ListNode* New_l2_4 = new ListNode(9, New_l2_3);
        
        ListNode *ptr_l1 = NULL;
        ListNode *ptr_l2 = NULL;
        // ListNode *ptr_l1 = New_l1_7;
        // // show the elements
        // while( ptr_l1 != NULL ){
        //     printf("current_ptr: ptr_l1->val:%d\n", ptr_l1->val);
        //     ptr_l1 = ptr_l1->next;
        // }
        // printf("*************************\n");
        // ListNode *ptr_l2 = New_l2_4;
        // // show the elements
        // while (ptr_l2 != NULL) {
        //     printf("current_ptr: ptr_l2->val:%d\n", ptr_l2->val);
        //     ptr_l2 = ptr_l2->next;
        // }
        // printf("*************************\n\n\n");

        ptr_l1 = New_l1_7;
        ptr_l2 = New_l2_4;

        Solution solution;
        auto result = solution.addTwoNumbers(ptr_l1, ptr_l2);
        printf("result: AddLinkList:\n");
        ListNode* res_ptr = result;
        while( res_ptr != NULL ){
            printf("res_ptr->val:%d\n", res_ptr->val);
            res_ptr = res_ptr->next;
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
