// Con_Flat_Multlevel_DoublLinkList.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int _val, Node* _prev, Node* _next, Node* _child) : val(_val), prev(_prev), next(_next), child(_child) {}
};


class Solution {
public:
    Node* flatten(Node* head) {
        
        // solution 1 (keven, using stack to solve)
        {
            stack<Node*> stock_node;
            Node* new_head = head;
            Node* new_last = NULL;

            while (head || stock_node.size())
            {
                while (head)
                {
                    auto current_node = head;
                    head = head->next;
                    new_last = current_node;
                    // // reset ptr
                    // current_node->next = NULL;   // for current_node
                    
                    if (current_node->child)
                    {
                        // reset ptr
                        current_node->next = NULL;
                        if (head){
                            head->prev = NULL;       // for current_next_node
                            stock_node.push(head);       // store the origin next_node into stack
                        }

                        // linked each other for current_node & current_node_child
                        current_node->child->prev = current_node;
                        current_node->next = current_node->child;

                        head = current_node->child;
                        // reset child member to NULL(must, because the result is only doubly linked-list format)
                        current_node->child = NULL;

                        new_last = head;
                    }
                }
                while (stock_node.size())
                {
                    auto last_top_node = stock_node.top();
                    last_top_node->prev = new_last;
                    new_last->next = last_top_node;
                    stock_node.pop();
                    head = last_top_node;
                    break;    // break this loop to do before process
                }
            }
            
            return new_head;
        }
    }
};

int main()
{
    std::cout << "Hello World!\n";
    cout << "https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12\n");
    printf("expected result: output = [1,2,3,7,8,11,12,9,10,4,5,6]\n");
    {
        // Node *N1 = new Node(1,NULL,);

        // myStack.push(1);
        // myStack.push(2);
        // auto top_value = myStack.top();
        // printf("top_value:%d\n", top_value);

        // auto pop_value = myStack.pop();
        // printf("pop_value:%d\n", pop_value);

        // auto empty_fg = myStack.empty();
        // printf("empty_fg:%d, true(%d), false(%d)\n", empty_fg, true, false);
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
