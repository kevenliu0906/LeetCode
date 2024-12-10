// Cons_Find_MinMax_Num_Nodes.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
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
private:
    vector<int> nodes_Bet_CriticalPoints(ListNode *head){
        vector<int> record_idx_vec;
        vector<int> res = {-1,-1};

        // traversal the link-list
        ListNode *cur = head;
        int cur_val = cur->val;
        bool inc_fg = false;
        bool dec_fg = false;
        int cur_idx = -1;

        while (cur)
        {
            cur_idx++;
            if (cur->val < cur_val){
                if (inc_fg)
                {
                    // last one is incresing, but current is decreasing
                    record_idx_vec.push_back(cur_idx - 1);
                }
                inc_fg = false;
                dec_fg = true;
            }else if(cur->val > cur_val){
                if (dec_fg)
                {
                    // last one is decresing, but current is increasing
                    record_idx_vec.push_back(cur_idx - 1);
                }
                inc_fg = true;
                dec_fg = false;
            }else{
                // reset to default
                inc_fg = false;
                dec_fg = false; 
            }

            // change the stored value
            cur_val = cur->val;
            
            cur = cur->next;
        }

        int record_size = record_idx_vec.size();
        // printf("record_size=%d, record_idx >>>\n", record_size);
        // for (size_t i = 0; i < record_size; i++)
        // {
        //     printf("%d,", record_idx_vec[i]);
        // }
        // printf("\n");
        
        if (record_size == 2)
        {
            auto diff = record_idx_vec[1] - record_idx_vec[0];
            res[0] = diff;
            res[1] = diff;
        }else if (record_size > 2)
        {
            auto diff_min = INT_MAX;
            auto diff_max = record_idx_vec[record_size - 1] - record_idx_vec[0];
            for (size_t i = 0; i < record_size - 1; i++)
            {
                diff_min = min(diff_min, record_idx_vec[i+1] - record_idx_vec[i]);
            }

            res[0] = diff_min;
            res[1] = diff_max;
        }

        return res;
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // solution 1 (keven)
        {
            auto res = nodes_Bet_CriticalPoints(head);
            
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Find the Min Max Number of Nodes Between Critical Points, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [3,1]\n");
    printf("expected result: output = [-1,-1]\n");
    printf("Explanation: There are no critical points in [3,1].\n");
    {
        ListNode *ln_1 = new ListNode(1, NULL);
        ListNode *ln_3 = new ListNode(3, ln_1);
        ListNode *head = ln_3;

        Solution solution;
        auto res = solution.nodesBetweenCriticalPoints(head);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");

        delete ln_1;
        delete ln_3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: head = [5,3,1,2,5,1,2]\n");
    printf("expected result: output = [1,3]\n");
    printf("Explanation: There are three critical points.\n");
    printf("             - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.\n");
    printf("             - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.\n");
    printf("             - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.\n");
    printf("               The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.\n");
    printf("               The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.\n\n");
    {
        ListNode *ln_2_1 = new ListNode(2, NULL);
        ListNode *ln_1_1 = new ListNode(1, ln_2_1);
        ListNode *ln_5_1 = new ListNode(5, ln_1_1);
        ListNode *ln_2_2 = new ListNode(2, ln_5_1);
        ListNode *ln_1_2 = new ListNode(1, ln_2_2);
        ListNode *ln_3_1 = new ListNode(3, ln_1_2);
        ListNode *ln_5_2 = new ListNode(5, ln_3_1);
        ListNode *head = ln_5_2;

        Solution solution;
        auto res = solution.nodesBetweenCriticalPoints(head);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");

        delete ln_2_1;
        delete ln_1_1;
        delete ln_5_1;
        delete ln_2_2;
        delete ln_1_2;
        delete ln_3_1;
        delete ln_5_2;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: head = [1,3,2,2,3,2,2,2,7]\n");
    printf("expected result: output = [3,3]\n");
    printf("Explanation: There are two critical points.\n");
    printf("             - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.\n");
    printf("             - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.\n");
    printf("               The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.\n");
    printf("               Both the minimum and maximum distances are between the second and the fifth node.\n");
    printf("               Thus, minDistance and maxDistance is 5 - 2 = 3.\n");
    printf("               Note that the last node is not considered a local maxima because it does not have a next node.\n\n");
    {
        ListNode *ln_7_1 = new ListNode(7, NULL);
        ListNode *ln_2_1 = new ListNode(2, ln_7_1);
        ListNode *ln_2_2 = new ListNode(2, ln_2_1);
        ListNode *ln_2_3 = new ListNode(2, ln_2_2);
        ListNode *ln_3_1 = new ListNode(3, ln_2_3);
        ListNode *ln_2_4 = new ListNode(2, ln_3_1);
        ListNode *ln_2_5 = new ListNode(2, ln_2_4);
        ListNode *ln_3_2 = new ListNode(3, ln_2_5);
        ListNode *ln_1_1 = new ListNode(1, ln_3_2);
        ListNode *head = ln_1_1;

        Solution solution;
        auto res = solution.nodesBetweenCriticalPoints(head);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");

        delete ln_7_1;
        delete ln_2_1;
        delete ln_2_2;
        delete ln_2_3;
        delete ln_3_1;
        delete ln_2_4;
        delete ln_2_5;
        delete ln_3_2;
        delete ln_1_1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: head = [3,2,3,3,3,5,1,1,2,5,2]\n");
    printf("expected result: output = [4,8]\n");
    {
        ListNode *ln_2_1 = new ListNode(2, NULL);
        ListNode *ln_5_1 = new ListNode(5, ln_2_1);
        ListNode *ln_2_2 = new ListNode(2, ln_5_1);
        ListNode *ln_1_1 = new ListNode(1, ln_2_2);
        ListNode *ln_1_2 = new ListNode(1, ln_1_1);
        ListNode *ln_5_2 = new ListNode(5, ln_1_2);
        ListNode *ln_3_1 = new ListNode(3, ln_5_2);
        ListNode *ln_3_2 = new ListNode(3, ln_3_1);
        ListNode *ln_3_3 = new ListNode(3, ln_3_2);
        ListNode *ln_2_3 = new ListNode(2, ln_3_3);
        ListNode *ln_3_4 = new ListNode(3, ln_2_3);
        ListNode *head = ln_3_4;

        Solution solution;
        auto res = solution.nodesBetweenCriticalPoints(head);
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");

        delete ln_2_1;
        delete ln_5_1;
        delete ln_2_2;
        delete ln_1_1;
        delete ln_1_2;
        delete ln_5_2;
        delete ln_3_1;
        delete ln_3_2;
        delete ln_3_3;
        delete ln_2_3;
        delete ln_3_4;
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
