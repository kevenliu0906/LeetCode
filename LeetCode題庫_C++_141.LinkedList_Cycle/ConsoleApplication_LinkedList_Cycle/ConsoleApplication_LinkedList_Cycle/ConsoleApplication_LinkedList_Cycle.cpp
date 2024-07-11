// ConsoleApplication_LinkedList_Cycle.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <unordered_set>

using namespace std;


//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution{
public:
    bool hasCycle(ListNode *head) {

        // // solution 1 (best, use two pointer(slow & fast))
        // {
        //     ListNode *fast = head;
        //     ListNode *slow = head;

        //     while( fast != NULL && fast->next != NULL && slow != NULL ){
        //         fast = fast->next->next;
        //         slow = slow->next;
        //         if(fast == slow)
        //             return true;
        //     }
        //     return false;
        // }

        // solution 2 (keven)
        {
            unordered_set<ListNode *> ListNode_ptr_unorderedset;
            ListNode *current_ptr = head;
            
            while( current_ptr != NULL ){
                if (ListNode_ptr_unorderedset.count(current_ptr))
                {
                    return true;
                }
                ListNode_ptr_unorderedset.insert(current_ptr);
                current_ptr = current_ptr->next;
            }
            
            return false;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Linked List Cycle, DataStructure (Linked List, Hash Table)!\n";
    printf("LeetCode - 141. Linked List Cycle\n");
    cout << "https://leetcode.com/problems/linked-list-cycle" << endl << endl;
    // cout << "solution: https://mocowcow.github.io/leetcode-222-count-complete-tree-nodes/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [3, 2, 0, -4, 2], pos = 1\n");
    printf("expected result: output = true\n");
    {
        ListNode *N1 = new ListNode(-4);
        ListNode *N2 = new ListNode(0);
        N2->next = N1;
        ListNode *N3 = new ListNode(2);
        N3->next = N2;
        ListNode *N4 = new ListNode(3);
        N4->next = N3;

        N1->next = N3;
        ListNode *head = N4;

        Solution solution;
        auto result = solution.hasCycle(head);
        printf("Result:%d, true:%d, false:%d\n", result, true, false);

        delete N1;
        delete N2;
        delete N3;
        delete N4;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1, 2, 1], pos = 0\n");
    printf("expected result: output = true\n");
    {
        ListNode *N1 = new ListNode(2);
        ListNode *N2 = new ListNode(1);
        N2->next = N1;

        N1->next = N2;
        ListNode *head = N2;

        Solution solution;
        auto result = solution.hasCycle(head);
        printf("Result:%d, true:%d, false:%d\n", result, true, false);

        delete N1;
        delete N2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [1], pos = -1\n");
    printf("expected result: output = false\n");
    {
        ListNode *N1 = new ListNode(1);
        
        ListNode *head = N1;

        Solution solution;
        auto result = solution.hasCycle(head);
        printf("Result:%d, true:%d, false:%d\n", result, true, false);

        delete N1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    // printf("*****************************************************\n");
    // printf("************* testcase 4 ****************************\n");
    // printf("input: head = [-21,10,17,8,4,26,5,35,33,-7,-16,27,-12,6,29,-12,5,9,20,14,14,2,13,-24,21,23,-21,5], pos = -1\n");
    // printf("expected result: output = false\n");
    // {
    //     ListNode *N1 = new ListNode(5);
    //     ListNode *N2 = new ListNode(-21);
    //     N2->next = N1;
    //     ListNode *N3 = new ListNode(23);
    //     N3->next = N2;
    //     ListNode *N4 = new ListNode(21);
    //     N4->next = N3;
    //     ListNode *N5 = new ListNode(-24);
    //     N5->next = N4;
    //     ListNode *N6 = new ListNode(13);
    //     N6->next = N5;
    //     ListNode *N7 = new ListNode(2);
    //     N7->next = N6;
    //     ListNode *N8 = new ListNode(14);
    //     N8->next = N7;
    //     ListNode *N9 = new ListNode(14);
    //     N9->next = N8;
    //     ListNode *N10 = new ListNode(20);
    //     N10->next = N9;
    //     ListNode *N11 = new ListNode(9);
    //     N11->next = N10;
    //     ListNode *N12 = new ListNode(5);
    //     N12->next = N11;
    //     ListNode *N13 = new ListNode(-12);
    //     N13->next = N12;
    //     ListNode *N14 = new ListNode(29);
    //     N14->next = N13;
    //     ListNode *N15 = new ListNode(6);
    //     N15->next = N14;
    //     ListNode *N16 = new ListNode(-12);
    //     N16->next = N15;
    //     ListNode *N17 = new ListNode(27);
    //     N17->next = N16;
    //     ListNode *N18 = new ListNode(-16);
    //     N18->next = N17;
    //     ListNode *N19 = new ListNode(-7);
    //     N19->next = N18;
    //     ListNode *N20 = new ListNode(33);
    //     N20->next = N19;
    //     ListNode *N21 = new ListNode(35);
    //     N21->next = N20;
    //     ListNode *N22 = new ListNode(5);
    //     N22->next = N21;
    //     ListNode *N23 = new ListNode(26);
    //     N23->next = N22;
    //     ListNode *N24 = new ListNode(4);
    //     N24->next = N23;
    //     ListNode *N25 = new ListNode(8);
    //     N25->next = N24;
    //     ListNode *N26 = new ListNode(17);
    //     N26->next = N25;
    //     ListNode *N27 = new ListNode(10);
    //     N27->next = N26;
    //     ListNode *N28 = new ListNode(-21);
    //     N28->next = N27;

        
    //     ListNode *head = N28;

    //     Solution solution;
    //     auto result = solution.hasCycle(head);
    //     printf("Result:%d, true:%d, false:%d\n", result, true, false);

    //     delete N1;
    //     delete N2;
    //     delete N3;
    //     delete N4;
    //     delete N5;
    //     delete N6;
    //     delete N7;
    //     delete N8;
    //     delete N9;
    //     delete N10;
    //     delete N11;
    //     delete N12;
    //     delete N13;
    //     delete N14;
    //     delete N15;
    //     delete N16;
    //     delete N17;
    //     delete N18;
    //     delete N19;
    //     delete N20;
    //     delete N21;
    //     delete N22;
    //     delete N23;
    //     delete N24;
    //     delete N25;
    //     delete N26;
    //     delete N27;
    //     delete N28;
    // }
    // printf("*****************************************************\n");

    // printf("\n\n");
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
