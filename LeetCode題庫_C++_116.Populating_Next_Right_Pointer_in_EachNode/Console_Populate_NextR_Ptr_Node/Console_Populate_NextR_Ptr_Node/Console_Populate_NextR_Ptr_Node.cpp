// Console_Populate_NextR_Ptr_Node.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        // solution 0 (reference others, https://zxi.mytechroad.com/blog/tree/leetcode-116-populating-next-right-pointers-in-each-node/)
        {
            if ( !root || !root->left)
            {
                return root;
            }
            root->left->next = root->right;
            
            if (root->next)
            {
                root->right->next = root->next->left;
            }

            connect(root->left);
            connect(root->right);

            return root;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Populate Next Right Pointer in Each Node, DataStructure(Linked List, Tree)!\n";
    cout << "https://leetcode.com/problems/populating-next-right-pointers-in-each-node" << endl << endl;
    cout << "solution: a. https://zxi.mytechroad.com/blog/tree/leetcode-116-populating-next-right-pointers-in-each-node/" << endl;
    cout << "          b. https://home.gamer.com.tw/artwork.php?sn=5537707" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: roots = [1,2,3,4,5,6,7]\n");
    printf("expected result: output = [1,#,2,3,#,4,5,6,7#]\n");
    {
        Node *N1 = new Node(7, NULL, NULL, NULL);
        Node *N2 = new Node(6, NULL, NULL, N1);
        Node *N3 = new Node(5, NULL, NULL, N2);
        Node *N4 = new Node(4, NULL, NULL, N3);
        Node *N5 = new Node(3, N2, N1, NULL);
        Node *N6 = new Node(2, N4, N3, N5);
        Node *N7 = new Node(1, N6, N5, NULL);
        Node *root = N7;
        
        Solution solution;
        auto result = solution.connect(root);
        printf("result:%d\n", result);
        
        delete N1;
        delete N2;
        delete N3;
        delete N4;
        delete N5;
        delete N6;
        delete N7;
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
