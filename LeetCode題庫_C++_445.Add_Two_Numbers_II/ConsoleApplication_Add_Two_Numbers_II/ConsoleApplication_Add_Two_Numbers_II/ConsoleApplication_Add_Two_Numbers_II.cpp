// ConsoleApplication_Add_Two_Numbers_II.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
        // solution 1 (keven)
        {
            ListNode *tmp_l1 = l1;
            ListNode *tmp_l2 = l2;
            vector<ListNode *> l1_vec;
            vector<ListNode *> l2_vec;

            // STEP1-> record ListNode to vector
            while (tmp_l1 != NULL){
                l1_vec.push_back(tmp_l1);
                tmp_l1 = tmp_l1->next;
            }
            while (tmp_l2 != NULL){
                l2_vec.push_back(tmp_l2);
                tmp_l2 = tmp_l2->next;
            }

            // STEP2-> add num by vector
            ListNode *result = NULL;
            ListNode *currentNode = NULL;
            int index_l1 = l1_vec.size() - 1;
            int index_l2 = l2_vec.size() - 1;       
            int current_sum = 0;

            while (index_l1 >= 0 || index_l2 >= 0)
            {
                if (index_l1>=0){
                    current_sum += l1_vec[index_l1]->val;
                }
                if (index_l2>=0){
                    current_sum += l2_vec[index_l2]->val;
                }
                
                
                // current_sum += l1_vec[index_l1]->val + l2_vec[index_l2]->val;
                // printf("current_sum:%d, l1_vec[%d]:%d, l2_vec[%d]:%d\n", current_sum, index_l1, l1_vec[index_l1]->val, index_l2, l2_vec[index_l2]->val);
                result = new ListNode(current_sum%10, NULL);
                current_sum = current_sum/10;
                if (currentNode == NULL)
                {
                    ;
                }else{
                    result->next = currentNode;
                }
                currentNode = result;
                
                if (index_l1>=0){
                    index_l1--;
                }
                if (index_l2>=0){
                    index_l2--;
                }
            }

            // only over-bit case
            while (current_sum)
            {
                result = new ListNode(current_sum%10, NULL);
                // printf("over-bit case, only current_sum, current_sum:%d\n", current_sum);
                if (currentNode == NULL){
                    ;
                }else{
                    result->next = currentNode;
                }
                currentNode = result;

                current_sum = current_sum/10;
            }
            
            return result;
        }
    }
};


int main()
{
    std::cout << "Hello LeetCode - Add Two Numbers II, DataStructure(Linked List, Stack)!\n";
    cout << "https://leetcode.com/problems/add-two-numbers-ii/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: l1 = [7,2,4,3], l2 = [5,6,4]\n");
    printf("expected result: output = [7,8,0,7]\n");
    {
        ListNode *A_N1 = new ListNode(3, NULL);
        ListNode *A_N2 = new ListNode(4, A_N1);
        ListNode *A_N3 = new ListNode(2, A_N2);
        ListNode *A_N4 = new ListNode(7, A_N3);
        ListNode *l1 = A_N4;

        ListNode *B_N1 = new ListNode(4, NULL);
        ListNode *B_N2 = new ListNode(6, B_N1);
        ListNode *B_N3 = new ListNode(5, B_N2);
        ListNode *l2 = B_N3;
        
        Solution solution;
        auto result = solution.addTwoNumbers(l1, l2);
        printf("after add two numbrs,\n");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;
        delete A_N4;
        delete B_N1;
        delete B_N2;
        delete B_N3;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: l1 = [2,4,3], l2 = [5,6,4]\n");
    printf("expected result: output = [8,0,7]\n");
    {
        ListNode *A_N1 = new ListNode(3, NULL);
        ListNode *A_N2 = new ListNode(4, A_N1);
        ListNode *A_N3 = new ListNode(2, A_N2);
        ListNode *l1 = A_N3;

        ListNode *B_N1 = new ListNode(4, NULL);
        ListNode *B_N2 = new ListNode(6, B_N1);
        ListNode *B_N3 = new ListNode(5, B_N2);
        ListNode *l2 = B_N3;
        
        Solution solution;
        auto result = solution.addTwoNumbers(l1, l2);
        printf("after add two numbrs,\n");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;
        delete B_N1;
        delete B_N2;
        delete B_N3;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: l1 = [0], l2 = [0]\n");
    printf("expected result: output = [0]\n");
    {
        ListNode *A_N1 = new ListNode(0, NULL);
        ListNode *l1 = A_N1;

        ListNode *B_N1 = new ListNode(0, NULL);
        ListNode *l2 = B_N1;
        
        Solution solution;
        auto result = solution.addTwoNumbers(l1, l2);
        printf("after add two numbrs,\n");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete B_N1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: l1 = [9,9,9], l2 = [2,2]\n");
    printf("expected result: output = [1,0,2,1]\n");
    {
        ListNode *A_N1 = new ListNode(9, NULL);
        ListNode *A_N2 = new ListNode(9, A_N1);
        ListNode *A_N3 = new ListNode(9, A_N2);
        ListNode *l1 = A_N3;

        ListNode *B_N1 = new ListNode(2, NULL);
        ListNode *B_N2 = new ListNode(2, B_N1);
        ListNode *l2 = B_N2;
        
        Solution solution;
        auto result = solution.addTwoNumbers(l1, l2);
        printf("after add two numbrs,\n");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;
        delete B_N1;
        delete B_N2;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: l1 = [2,2], l2 = [9,9,9]\n");
    printf("expected result: output = [1,0,2,1]\n");
    {
        ListNode *A_N1 = new ListNode(2, NULL);
        ListNode *A_N2 = new ListNode(2, A_N1);
        ListNode *l1 = A_N2;

        ListNode *B_N1 = new ListNode(9, NULL);
        ListNode *B_N2 = new ListNode(9, B_N1);
        ListNode *B_N3 = new ListNode(9, B_N2);
        ListNode *l2 = B_N3;
        
        Solution solution;
        auto result = solution.addTwoNumbers(l1, l2);
        printf("after add two numbrs,\n");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete A_N2;
        delete B_N1;
        delete B_N2;
        delete B_N3;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: l1 = [1], l2 = [9,9]\n");
    printf("expected result: output = [1,0,0]\n");
    {
        ListNode *A_N1 = new ListNode(1, NULL);
        ListNode *l1 = A_N1;

        ListNode *B_N1 = new ListNode(9, NULL);
        ListNode *B_N2 = new ListNode(9, B_N1);
        ListNode *l2 = B_N2;
        
        Solution solution;
        auto result = solution.addTwoNumbers(l1, l2);
        printf("after add two numbrs,\n");
        if (result!=NULL){
            printf("result:\n");
            while (result!=NULL)
            {
                printf("val:%d\n", result->val);
                result = result->next;
            }
            
        }else{
            printf("result is NULL\n");
        }

        delete A_N1;
        delete B_N1;
        delete B_N2;
        
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
