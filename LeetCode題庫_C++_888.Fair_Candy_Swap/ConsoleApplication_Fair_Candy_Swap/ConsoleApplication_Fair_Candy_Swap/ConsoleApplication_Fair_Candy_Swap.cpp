// ConsoleApplication_Fair_Candy_Swap.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

        // solution 1 (keven, using HASH TABLE to solve)
        {
            int totalSizes = 0;
            int total_alice = 0;
            int total_bob = 0;
            int i = 0, j = 0;
            vector<int> swap_result;
            
            // STEP1: calc the total candy count
            for (size_t i = 0; i < aliceSizes.size(); i++)
            {
                total_alice += aliceSizes[i];
            }
            for (size_t i = 0; i < bobSizes.size(); i++)
            {
                total_bob += bobSizes[i];
            }
            totalSizes = total_alice + total_bob;
            
            // STEP2: calc the average candy count for each children.
            totalSizes /= 2;
            // printf("each child get %d candies\n", totalSizes);

            // STEP3: execute the swap
            {
                set<int> aliceSizes_set(aliceSizes.begin(), aliceSizes.end());
                set<int> bobSizes_set(bobSizes.begin(), bobSizes.end());
                for (auto aliceSizes_set_each : aliceSizes_set)
                {
                    auto swap_value = 0;

                    // because of "totalSizes = (total_alice - aliceSizes_set_each) + swap_value;"
                    swap_value = totalSizes - (total_alice - aliceSizes_set_each);
                    // need check if aliceSize_set_each is bigger than swap_value(because of total_alice > totalSizes)
                    // printf("total_alice:%d, alice_each:%d, swap_value:%d\n", total_alice, aliceSizes_set_each, swap_value);
                    if(swap_value < 1)
                        continue;   // this swap_value is not legal because swap_value need bigger than 1, so continue to find the next one
                    
                    // printf("[current] total_alice:%d, alice_each:%d, swap_value:%d\n", total_alice, aliceSizes_set_each, swap_value);
                    if (bobSizes_set.find(swap_value)!=bobSizes_set.end())
                    {
                        // bingo, FOUND it!!!!!
                        swap_result.push_back(aliceSizes_set_each);
                        swap_result.push_back(swap_value);
                        break;
                    }
                }
            }   
            return swap_result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Fail Candy Swap, Algorithm(Binary Search)!\n";
    cout << "https://leetcode.com/problems/fair-candy-swap/" << endl << endl;
    // cout << "solution: https://hackmd.io/@PeterLei/leetcode374?utm_source=preview-mode&utm_medium=rec/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: aliceSizes = [1,1], bobSizes = [2,2]\n");
    printf("expected result: output = [1,2]\n");
    {
        vector<int> aliceSizes{1,1};
        vector<int> bobSizes{2,2};
         
        Solution solution;
        auto result = solution.fairCandySwap(aliceSizes, bobSizes);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]:%d\n", i, result[i]);
        }
        
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: aliceSizes = [1,2], bobSizes = [2,3]\n");
    printf("expected result: output = [1,2]\n");
    {
        vector<int> aliceSizes{1,2};
        vector<int> bobSizes{2,3};
         
        Solution solution;
        auto result = solution.fairCandySwap(aliceSizes, bobSizes);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]:%d\n", i, result[i]);
        }
        
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: aliceSizes = [2], bobSizes = [1,3]\n");
    printf("expected result: output = [2,3]\n");
    {
        vector<int> aliceSizes{2};
        vector<int> bobSizes{1,3};
         
        Solution solution;
        auto result = solution.fairCandySwap(aliceSizes, bobSizes);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]:%d\n", i, result[i]);
        }
        
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: aliceSizes = [1,3], bobSizes = [2]\n");
    printf("expected result: output = [3,2]\n");
    {
        vector<int> aliceSizes{1,3};
        vector<int> bobSizes{2};

        Solution solution;
        auto result = solution.fairCandySwap(aliceSizes, bobSizes);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]:%d\n", i, result[i]);
        }


    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: aliceSizes = [2,3], bobSizes = [1,2]\n");
    printf("expected result: output = [2,1]\n");
    {
        vector<int> aliceSizes{ 2,3 };
        vector<int> bobSizes{ 1,2 };

        Solution solution;
        auto result = solution.fairCandySwap(aliceSizes, bobSizes);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]:%d\n", i, result[i]);
        }


    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 6 ****************************\n");
    printf("input: aliceSizes = [14,54,83,100,72,1,91,60,13,71,94,28,58,63,61,34,55,93,56,17], bobSizes = [58,75,8,87,48,22,23,9,85,82,42,99,23,1,83,77,19,32,9,56]\n");
    printf("expected result: output = [91,1]\n");
    {
        vector<int> aliceSizes{ 14,54,83,100,72,1,91,60,13,71,94,28,58,63,61,34,55,93,56,17 };
        vector<int> bobSizes{ 58,75,8,87,48,22,23,9,85,82,42,99,23,1,83,77,19,32,9,56 };

        Solution solution;
        auto result = solution.fairCandySwap(aliceSizes, bobSizes);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]:%d\n", i, result[i]);
        }


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
