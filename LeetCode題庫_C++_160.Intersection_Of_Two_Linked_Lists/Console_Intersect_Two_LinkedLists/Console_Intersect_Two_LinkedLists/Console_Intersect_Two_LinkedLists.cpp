// Console_Intersect_Two_LinkedLists.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        // solution 0 (best)
        {
            //step 1
            ListNode* temp = headA;
            int lenA=0, lenB=0;
            while(temp!=NULL)
            {
                lenA++;
                temp=temp->next;
            }
            temp = headB;
            while(temp!=NULL)
            {
                lenB++;
                temp=temp->next;
            }

            //step 2
            int diff = 0;
            ListNode *list1 = NULL;
            ListNode *list2 = NULL;

            if(lenA > lenB){
                diff = lenA-lenB;
                list1 = headA;
                list2 = headB;
                while (diff) {
                    list1 = list1->next;
                    diff--;
                }
            }else{
                diff = lenB - lenA;
                list1 = headB;
                list2 = headA;
                while (diff) {
                    list1 = list1->next;
                    diff--;
                }
            }

            //step 3
            while(list1 != NULL)
            {
                if (list1 == list2) {
                    return list1;
                }
                list1=list1->next;
                list2=list2->next;
            }

            return NULL;

        }
    
    }
};

int main()
{
    std::cout << "Hello LeetCode - Intersection of Two Linked Lists, DataStructure(Linked List)!\n";
    printf("LeetCode - 160. Intersection of two linked lists\n");
    cout << "https://leetcode.com/problems/intersection-of-two-linked-lists" << endl << endl;
    // cout << "solution: https://www.geeksforgeeks.org/count-ways-reach-nth-stair/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: headA = [4,1,8,4,5], headB = [5,6,1,8,4,5]\n");
    printf("expected result: output = '1'\n");
    {
        ListNode *A_N1 = new ListNode(5);
        ListNode *A_N2 = new ListNode(4);
        A_N2->next = A_N1;
        ListNode *A_N3 = new ListNode(8);
        A_N3->next = A_N2;
        ListNode *A_N4 = new ListNode(1);
        A_N4->next = A_N3;
        ListNode *A_N5 = new ListNode(4);
        A_N5->next = A_N4;
        ListNode *headA = A_N5;
        // printf("result linked list(A):\n");
        // ListNode *view = A_N5;
        // while( view ){
        //     printf("result node:%d\n", view->val);
        //     view = view->next;
        // }

        ListNode *B_N5 = new ListNode(6);
        B_N5->next = A_N4;
        ListNode *B_N6 = new ListNode(5);
        B_N6->next = B_N5;
        ListNode *headB = B_N6;
        
        Solution solution;
        auto result = solution.getIntersectionNode(headA, headB);
        printf("result linked list:\n");
        while( result ){
            printf("result node:%d\n", result->val);
            result = result->next;
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;
        delete A_N4;
        delete A_N5;

        delete B_N5;
        delete B_N6;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: headA = [1,9,1,2,4], headB = [3,2,4]\n");
    printf("expected result: output = '2'\n");
    {
        ListNode *A_N1 = new ListNode(4);
        ListNode *A_N2 = new ListNode(2);
        A_N2->next = A_N1;
        ListNode *A_N3 = new ListNode(1);
        A_N3->next = A_N2;
        ListNode *A_N4 = new ListNode(9);
        A_N4->next = A_N3;
        ListNode *A_N5 = new ListNode(1);
        A_N5->next = A_N4;
        ListNode *headA = A_N5;
        // printf("result linked list(A):\n");
        // ListNode *view = A_N5;
        // while( view ){
        //     printf("result node:%d\n", view->val);
        //     view = view->next;
        // }

        ListNode *B_N3 = new ListNode(3);
        B_N3->next = A_N2;
        ListNode *headB = B_N3;
        // printf("result linked list(A):\n");
        // view = B_N3;
        // while( view ){
        //     printf("result node:%d\n", view->val);
        //     view = view->next;
        // }
        
        Solution solution;
        auto result = solution.getIntersectionNode(headA, headB);
        printf("result linked list:\n");
        while( result ){
            printf("result node:%d\n", result->val);
            result = result->next;
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;
        delete A_N4;
        delete A_N5;

        delete B_N3;
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: headA = [2,6,4], headB = [1,5]\n");
    printf("expected result: output = ''\n");
    {
        ListNode *A_N1 = new ListNode(4);
        ListNode *A_N2 = new ListNode(6);
        A_N2->next = A_N1;
        ListNode *A_N3 = new ListNode(2);
        A_N3->next = A_N2;
        ListNode *headA = A_N3;
        // printf("result linked list(A):\n");
        // ListNode *view = A_N5;
        // while( view ){
        //     printf("result node:%d\n", view->val);
        //     view = view->next;
        // }

        ListNode *B_N1 = new ListNode(5);
        ListNode *B_N2 = new ListNode(1);
        B_N2->next = B_N1;
        ListNode *headB = B_N2;
        // printf("result linked list(A):\n");
        // ListNode *view = B_N2;
        // while( view ){
        //     printf("result node:%d\n", view->val);
        //     view = view->next;
        // }
        
        Solution solution;
        auto result = solution.getIntersectionNode(headA, headB);
        printf("result linked list:\n");
        while( result ){
            printf("result node:%d\n", result->val);
            result = result->next;
        }

        delete A_N1;
        delete A_N2;
        delete A_N3;

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
