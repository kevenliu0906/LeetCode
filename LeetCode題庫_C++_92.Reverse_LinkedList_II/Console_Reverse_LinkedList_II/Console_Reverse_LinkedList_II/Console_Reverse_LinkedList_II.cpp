// Console_Reverse_LinkedList_II.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        // solution 1 (keven, best)
        {
            vector<ListNode*> ReverseListNode_vec;
            ListNode *currentNode = head;
            ListNode *before_ReverseListNode = NULL;  // the last element in front of the left-reverse List Node
            ListNode *after_ReverseListNode = NULL;   // the first element next to the right-reverse List Node
            int currentPos = 1;

            /////// STEP1: find the 3 part (before_reverse List Node, reverse List Node, after_reverse List Node)
            while(currentNode != NULL){
                if( currentPos >= left && currentPos <= right ){
                    // printf("currentPos:%d, currentNode->val:%d\n", currentPos, currentNode->val);
                    ReverseListNode_vec.push_back(currentNode);
                }else{
                    if( currentPos < left ){
                        if( before_ReverseListNode != NULL ){
                            before_ReverseListNode->next = currentNode;
                        }
                        else{
                            ;
                        }
                        before_ReverseListNode = currentNode;
                    }
                    else if( currentPos > right ){
                        if( after_ReverseListNode != NULL )
                            ;
                        else{
                            after_ReverseListNode = currentNode;  // we only care about the element next to the reverse-right element
                            break;
                        }
                    }
                }
                currentNode = currentNode->next;
                currentPos++;
            }

            /////// STEP2: merge the befor_ReverseListNode & ReverseListNode & after_ReverseListNode
            //--> STEP2-2, reverse part
            while(ReverseListNode_vec.size()){

                auto reverseOne = ReverseListNode_vec[ReverseListNode_vec.size()-1];
                // reset the next pointer on the reversed-element
                reverseOne->next = NULL;
                
                // printf("reverseOne->val:%d, ReverseListNode_vec.size():%d\n", reverseOne->val, ReverseListNode_vec.size());
                if( before_ReverseListNode != NULL )
                    before_ReverseListNode->next = reverseOne;
                else
                    head = reverseOne;
                before_ReverseListNode = reverseOne;
                ReverseListNode_vec.pop_back();
                // printf("reverseOne->val:%d, ReverseListNode_vec.size():%d\n", reverseOne->val, ReverseListNode_vec.size());
            }
            //--> STEP2-3 after-reverse part
            if ( after_ReverseListNode != NULL )
            {
                if( before_ReverseListNode != NULL )
                    before_ReverseListNode->next = after_ReverseListNode;
                before_ReverseListNode = after_ReverseListNode;
            }

            return head;
            
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Reverse LinkedList II, DataStructure(Linked List)!\n";
    printf("LeetCode - 92. Reverse LinkedList II\n");
    cout << "https://leetcode.com/problems/reverse-linked-list-ii" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5], left = 2, right = 4\n");
    printf("expected result: output = [1,4,3,2,5]\n");
    {
        ListNode *N1 = new ListNode(5);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int left = 2;
        int right = 4;

        Solution solution;
        auto result = solution.reverseBetween(head, left, right);
        ListNode *Reverse = result;
        while (Reverse != NULL)
        {
            printf("Node->val:%d\n", Reverse->val);
            Reverse = Reverse->next;
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
    printf("input: head = [1,2,3,4,5], left = 1, right = 3\n");
    printf("expected result: output = [3,2,1,4,5]\n");
    {
        ListNode *N1 = new ListNode(5);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int left = 1;
        int right = 3;

        Solution solution;
        auto result = solution.reverseBetween(head, left, right);
        ListNode *Reverse = result;
        while (Reverse != NULL)
        {
            printf("Node->val:%d\n", Reverse->val);
            Reverse = Reverse->next;
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
    printf("input: head = [1,2,3,4,5], left = 2, right = 5\n");
    printf("expected result: output = [1,5,4,3,2]\n");
    {
        ListNode *N1 = new ListNode(5);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int left = 2;
        int right = 5;

        Solution solution;
        auto result = solution.reverseBetween(head, left, right);
        ListNode *Reverse = result;
        while (Reverse != NULL)
        {
            printf("Node->val:%d\n", Reverse->val);
            Reverse = Reverse->next;
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
    printf("input: head = [1,2,3,4,5], left = 1, right = 5\n");
    printf("expected result: output = [5,4,3,2,1]\n");
    {
        ListNode *N1 = new ListNode(5);
        ListNode *N2 = new ListNode(4, N1);
        ListNode *N3 = new ListNode(3, N2);
        ListNode *N4 = new ListNode(2, N3);
        ListNode *N5 = new ListNode(1, N4);
        ListNode *head = N5;
        int left = 1;
        int right = 5;

        Solution solution;
        auto result = solution.reverseBetween(head, left, right);
        ListNode *Reverse = result;
        while (Reverse != NULL)
        {
            printf("Node->val:%d\n", Reverse->val);
            Reverse = Reverse->next;
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
    printf("************* testcase 5 ****************************\n");
    printf("input: head = [5], left = 1, right = 1\n");
    printf("expected result: output = [5]\n");
    {
        ListNode *N1 = new ListNode(5);
        
        ListNode *head = N1;
        int left = 1;
        int right = 1;

        Solution solution;
        auto result = solution.reverseBetween(head, left, right);
        ListNode *Reverse = result;
        while (Reverse != NULL)
        {
            printf("Node->val:%d\n", Reverse->val);
            Reverse = Reverse->next;
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
