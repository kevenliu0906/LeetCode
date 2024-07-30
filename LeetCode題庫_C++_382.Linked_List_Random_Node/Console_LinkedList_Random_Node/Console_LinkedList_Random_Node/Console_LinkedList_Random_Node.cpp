// Console_LinkedList_Random_Node.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <chrono>

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
    vector<ListNode *> list_node_vec;
    Solution(ListNode* head) {
        
        // clear all elements in array
        list_node_vec.clear();

        // store all list-nodes into array
        ListNode *tmp = head;
        while (tmp)
        {
            list_node_vec.push_back(tmp);
            tmp = tmp->next;
        }

        // generate random seed (should call srand() ONLY one time for random seed)
        auto time_seed = (int)time(NULL);
        // printf("<<inner getRandom>> time_seed:%d\n", time_seed);
        srand(time_seed);
    }
    
    int getRandom() {
        
        int node_count = list_node_vec.size();
        
        // generate a random_index ( 0 <= random_index < node_count )
        // gererate random num: should call srand(seed) one time and call rand() many times - it should look random
        // reference: https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c (mention by Serge Dundich)
                     
        auto random_num = rand();
        auto random_index = random_num % node_count;
        // printf("<<inner getRandom>> node_count:%d, random_num:%d, random_index:%d, val:%d\n", 
        //                 node_count, 
        //                 random_num, 
        //                 random_index, 
        //                 (list_node_vec.at(random_index))->val);

        return (list_node_vec.at(random_index))->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{
    std::cout << "Hello LeetCode - Linked List Random Node, DataStructure(Linked List)!\n";
    cout << "https://leetcode.com/problems/design-hashmap" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"MyHashMap\", \"put\", \"put\", \"get\", \"get\", \"put\", \"get\", \"remove\", \"get\"], [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]\n");
    printf("expected result: output = [null, null, null, 1, -1, null, 1, null, -1]\n");
    {
        ListNode *N1 = new ListNode(3, NULL);
        ListNode *N2 = new ListNode(2, N1);
        ListNode *N3 = new ListNode(1, N2);
        ListNode *head = N3;

        // {
        //     printf("---------------- RANDOM NUM GEN ----------------\n");
        //     auto time_seed = (int)time(NULL);
        //     printf("time_seed:%d\n", time_seed);

        //     // output 10 random num
        //     for (size_t i = 0; i < 10; i++)
        //     {
        //         auto random_num = rand();
        //         printf("%6d, ", random_num);
        //     }
        //     printf("\n------------------------------------------------\n");
        // }

        // Your Solution object will be instantiated and called as such:
        Solution* obj = new Solution(head);
        for (size_t i = 0; i < 5; i++)
        {
            printf("Loop:%d - ", i);
            int param_1 = obj->getRandom();
            printf("param_1:%d\n", param_1);
        }
        delete obj;

        delete N1;
        delete N2;
        delete N3;
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
