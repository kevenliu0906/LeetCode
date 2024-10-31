// Console_N-ary_Tree_Lev_Order_Trave.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        // solution 1 (keven, use Breadth First Search to solve)
        {
            vector<vector<int>> res;

            if (root == NULL) return res;
            
            vector<Node*> cur_n_vec;
            vector<Node*> tmp_n_vec;

            tmp_n_vec.push_back(root);
            while (tmp_n_vec.size())
            {
                cur_n_vec.swap(tmp_n_vec);
                vector<int> single_num;
                while (cur_n_vec.size())
                {
                    auto cur_n = cur_n_vec[0];
                    single_num.push_back(cur_n->val);

                    if (cur_n->children.size())
                    {
                        tmp_n_vec.insert(tmp_n_vec.end(), cur_n->children.begin(), cur_n->children.end());
                    }
                    
                    // cur_n_que.pop();
                    cur_n_vec.erase(cur_n_vec.begin());
                }

                res.push_back(single_num);

            }

            return res;
        }
    }
};


int main()
{
    std::cout << "Hello LeetCode - N-ary Tree Level Order Traversal - Algorithm(Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/n-ary-tree-level-order-traversal/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: root = [1,null,3,2,4,null,5,6]\n");
    printf("expected result: output = [[1],[3,2,4],[5,6]]\n");
    {
        
        Node *n5 = new Node(5);
        Node *n6 = new Node(6);
        vector<Node*> ch3{n5, n6};

        Node *n3 = new Node(3, ch3);
        Node *n2 = new Node(2);
        Node *n4 = new Node(4);

        vector<Node*> ch1{n3, n2, n4};
        Node *n1 = new Node(1, ch1);
        Node *root = n1;

        Solution solution;
        auto res = solution.levelOrder(root);
        for (size_t i = 0; i < res.size(); i++)
        {
            for (size_t j = 0; j < res[i].size(); j++)
            {
                printf("%d,", res[i][j]);
            }
            printf("\n");
        }
        

        
        
        if (n5) delete n5;
        if (n6) delete n6;
        if (n3) delete n3;
        if (n2) delete n2;
        if (n4) delete n4;
        if (n1) delete n1;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    // printf("*****************************************************\n");
    // printf("************* testcase 2 ****************************\n");
    // printf("input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]\n");
    // printf("expected result: output = [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]\n");
    // {
        
    //     Node *n14 = new Node(14);
    //     vector<Node*> ch11{n14};
    //     Node *n11 = new Node(11, ch11);
    //     vector<Node*> ch7{n11};


    //     Node *n11 = new Node(11, ch11);

    //     Node *n3 = new Node(3, ch3);
    //     Node *n2 = new Node(2);
    //     Node *n4 = new Node(4);

    //     vector<Node*> ch1{n3, n2, n4};
    //     Node *n1 = new Node(1, ch1);
    //     Node *root = n1;

    //     Solution solution;
    //     auto res = solution.levelOrder(root);
    //     for (size_t i = 0; i < res.size(); i++)
    //     {
    //         for (size_t j = 0; j < res[i].size(); j++)
    //         {
    //             printf("%d,", res[i][j]);
    //         }
    //         printf("\n");
    //     }
        

        
        
    //     if (n5) delete n5;
    //     if (n6) delete n6;
    //     if (n3) delete n3;
    //     if (n2) delete n2;
    //     if (n4) delete n4;
    //     if (n1) delete n1;
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
