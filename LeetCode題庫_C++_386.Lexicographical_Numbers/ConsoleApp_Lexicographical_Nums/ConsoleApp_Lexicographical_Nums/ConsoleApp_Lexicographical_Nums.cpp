// ConsoleApp_Lexicographical_Nums.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // solution 1 (keven, force directly)
        {
            vector<int> res;
            
            int num_1 = 1;
            // int num_10_origin = 10;
            // int num_100_origin = 100;
            while (num_1 <= n && num_1 <= 9)
            {
                res.push_back(num_1);

                auto num_10 = num_1 * 10;
                while (num_10 <= n && num_10 <= 99)
                {
                    res.push_back(num_10);

                    auto num_100 = num_10 * 10;
                    while (num_100 <= n && num_100 <= 999)
                    {
                        res.push_back(num_100);

                        auto num_1000 = num_100 * 10;
                        while (num_1000 <= n && num_1000 <= 9999)
                        {
                            res.push_back(num_1000);

                            auto num_10000 = num_1000 * 10;
                            while (num_10000 <= n && num_10000 <= 99999)
                            {
                                res.push_back(num_10000);

                                // auto num_100000 = num_10000 * 10;
                                // while (num_100000 <= n && num_100000 <= 999999)
                                // {
                                //     res.push_back(num_100000);

                                //     num_100000++;
                                //     if ( num_100000/10 > num_10000 ){
                                //         // need calc next round from the head
                                //         break;
                                //     }
                                // }

                                num_10000++;
                                if ( num_10000/10 > num_1000 ){
                                    // need calc next round from the head
                                    break;
                                }
                            }

                            num_1000++;
                            if ( num_1000/10 > num_100 ){
                                // need calc next round from the head
                                break;
                            }
                        }

                        num_100++;
                        if ( num_100/10 > num_10 ){
                            // need calc next round from the head
                            break;
                        }
                    }

                    num_10++;
                    if ( num_10/10 > num_1 ){
                        // need calc next round from the head
                        break;
                    }
                    
                }
                
                num_1++;
            }
            
            return res;
        }
    
    }
};

int main()
{
    std::cout << "Hello LeetCode - Lexicographical Numbers, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/lexicographical-numbers/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: n = 13\n");
    printf("expected result: output = [1,10,11,12,13,2,3,4,5,6,7,8,9]\n");
    {
        int n = 13;
        Solution solution;
        auto res = solution.lexicalOrder(n);
        
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: n = 2\n");
    printf("expected result: output = [1,2]\n");
    {
        int n = 2;
        Solution solution;
        auto res = solution.lexicalOrder(n);
        
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: n = 30\n");
    printf("expected result: output = [1,10,11,12,13,14,15,16,17,18,19,2,20,21,22,23,24,25,26,27,28,29,3,30,4,5,6,7,8,9]\n");
    {
        int n = 30;
        Solution solution;
        auto res = solution.lexicalOrder(n);
        
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: n = 50000\n");
    printf("expected result: output = [1,2]\n");
    {
        int n = 50000;
        Solution solution;
        auto res = solution.lexicalOrder(n);
        
        printf("res size is %d\n", res.size());
        for (size_t i = 0; i < res.size(); i++)
        {
            printf("%d,", res[i]);
        }
        printf("\n");
        
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
