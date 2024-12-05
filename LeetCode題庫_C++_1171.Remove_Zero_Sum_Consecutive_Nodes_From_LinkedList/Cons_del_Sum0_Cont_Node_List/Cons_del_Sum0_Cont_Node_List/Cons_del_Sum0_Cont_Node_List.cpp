// Cons_del_Sum0_Cont_Node_List.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <unordered_map>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void dbg_LT(ListNode *head){
    ListNode *cur = head;
    printf("dbg_LT >>>>>\n");
    while (cur)
    {
        printf("%d,", cur->val);
        cur = cur->next;
    }
    printf("\n------------------------------------\n\n");
}
 
class Solution {
private:
    unordered_map<int, ListNode*> totalsum_ln_map;   // key: total_sum for current node, value: current list-node
    ListNode *remove_cont_sublists_sum_zero(ListNode *head){
        ListNode *cur_ln = head;
        int sum = 0;
        
        // STEP1: store the 'prefix sum' for current list-node
        while (cur_ln)
        {
            sum += cur_ln->val;
            totalsum_ln_map[sum] = cur_ln;   // according to current list-node, record the 'prefix sum' till current node
            cur_ln = cur_ln->next;
        }       
        
        // reset
        cur_ln = head;
        sum = 0;

        // meet the consective sum is zero, so move directly to the next node to corresponding node.
        if(totalsum_ln_map.count(sum)){
            head = totalsum_ln_map[sum]->next;
            cur_ln = head;
        }
        
        // STEP2: traversal again and remove the zero prefix sum list-node
        while (cur_ln)
        {
            sum += cur_ln->val;
            // in order to skip all the list-nodes between 'current list-node' and 'final list-node' with the same prefix sum
            // link directly to next list-node that have the same pre-fix sum
            cur_ln->next = totalsum_ln_map[sum]->next;
            
            cur_ln = cur_ln->next;
        }

        return head;
    }
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // solution 1 (keven, refer others, using hash table to solve)
        //             a. https://hackmd.io/@HowN/leetcode_1171?utm_source=preview-mode&utm_medium=rec
        //             b. https://blog.csdn.net/myRealization/article/details/131269718
        //             c. https://zxi.mytechroad.com/blog/list/leetcode-1171-remove-zero-sum-consecutive-nodes-from-linked-list/
        {
            return remove_cont_sublists_sum_zero(head);
            // return head;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode, Remove Zero Sum Consecutive Nodes From LinkedList, DataStructure(HASH TABLE, LinkedList)!\n";
    cout << "https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/" << endl;
    cout << "solutiion: a. https://hackmd.io/@HowN/leetcode_1171?utm_source=preview-mode&utm_medium=rec" << endl;
    cout << "           b. https://blog.csdn.net/myRealization/article/details/131269718" << endl;
    cout << "           c. https://zxi.mytechroad.com/blog/list/leetcode-1171-remove-zero-sum-consecutive-nodes-from-linked-list/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,-3,3,1]\n");
    printf("expected result: output = [3,1]\n");
    printf("Note: The answer [1,2,1] would also be accepted.\n");
    {
        ListNode *ln_1_1 = new ListNode(1, NULL);
        ListNode *ln_3_1 = new ListNode(3, ln_1_1);
        ListNode *ln_3_2 = new ListNode(-3, ln_3_1);
        ListNode *ln_2_1 = new ListNode(2, ln_3_2);
        ListNode *ln_1_2 = new ListNode(1, ln_2_1);
        ListNode *head = ln_1_2;

        printf("origin link-list:\n");
        dbg_LT(head);

        Solution solution;
        auto res = solution.removeZeroSumSublists(head);

        printf("after remove zero sum sublists:\n");
        dbg_LT(res);

        delete ln_1_2;
        delete ln_2_1;
        delete ln_3_2;
        delete ln_3_1;
        delete ln_1_1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [1,2,3,-3,4]\n");
    printf("expected result: output = [1,2,4]\n");
    {
        ListNode *ln_4_1 = new ListNode(4, NULL);
        ListNode *ln_3_1 = new ListNode(-3, ln_4_1);
        ListNode *ln_3_2 = new ListNode(3, ln_3_1);
        ListNode *ln_2_1 = new ListNode(2, ln_3_2);
        ListNode *ln_1_1 = new ListNode(1, ln_2_1);
        ListNode *head = ln_1_1;

        printf("origin link-list:\n");
        dbg_LT(head);

        Solution solution;
        auto res = solution.removeZeroSumSublists(head);

        printf("after remove zero sum sublists:\n");
        dbg_LT(res);

        delete ln_4_1;
        delete ln_3_1;
        delete ln_3_2;
        delete ln_2_1;
        delete ln_1_1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [1,2,3,-3,-2]\n");
    printf("expected result: output = [1]\n");
    {
        ListNode *ln_2_1 = new ListNode(-2, NULL);
        ListNode *ln_3_1 = new ListNode(-3, ln_2_1);
        ListNode *ln_3_2 = new ListNode(3, ln_3_1);
        ListNode *ln_2_2 = new ListNode(2, ln_3_2);
        ListNode *ln_1_1 = new ListNode(1, ln_2_2);
        ListNode *head = ln_1_1;

        printf("origin link-list:\n");
        dbg_LT(head);

        Solution solution;
        auto res = solution.removeZeroSumSublists(head);

        printf("after remove zero sum sublists:\n");
        dbg_LT(res);

        delete ln_2_1;
        delete ln_3_1;
        delete ln_3_2;
        delete ln_2_2;
        delete ln_1_1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: head = [1,-1]\n");
    printf("expected result: output = []\n");
    {
        ListNode *ln_1_1 = new ListNode(-1, NULL);
        ListNode *ln_1_2 = new ListNode(1, ln_1_1);
        ListNode *head = ln_1_2;

        printf("origin link-list:\n");
        dbg_LT(head);

        Solution solution;
        auto res = solution.removeZeroSumSublists(head);

        printf("after remove zero sum sublists:\n");
        dbg_LT(res);

        delete ln_1_1;
        delete ln_1_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: head = [1,0,0,-1,2,-1,0]\n");
    printf("expected result: output = [2,-1]\n");
    {
        ListNode *ln_0_1 = new ListNode(0, NULL);
        ListNode *ln_1_1 = new ListNode(-1, ln_0_1);
        ListNode *ln_2_1 = new ListNode(2, ln_1_1);
        ListNode *ln_1_2 = new ListNode(-1, ln_2_1);
        ListNode *ln_0_2 = new ListNode(0, ln_1_2);
        ListNode *ln_0_3 = new ListNode(0, ln_0_2);
        ListNode *ln_1_3 = new ListNode(1, ln_0_3);
        ListNode *head = ln_1_3;

        printf("origin link-list:\n");
        dbg_LT(head);

        Solution solution;
        auto res = solution.removeZeroSumSublists(head);

        printf("after remove zero sum sublists:\n");
        dbg_LT(res);

        delete ln_0_1;
        delete ln_1_1;
        delete ln_2_1;
        delete ln_1_2;
        delete ln_0_2;
        delete ln_0_3;
        delete ln_1_3;
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
