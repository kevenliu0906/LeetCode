// Console_Kth_Smallest_Prime_Fraction.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        // solution 1 (keven, using HASH TABLE to solve)
        {
            vector<int> result;
            map<double, vector<int>> result_map;
            for (int i = 0; i < arr.size() - 1; i++)
            {
                for (int j = i+1; j < arr.size(); j++)
                {
                    auto key = (1.0*arr[i]) / arr[j];
                    vector<int> value{i,j};
                    result_map.insert(pair<double, vector<int>>(key, value));
                }
            }

            // dbg
            int current_count = 0;
            for (auto result_map_each : result_map)
            {
                current_count++;
                // printf("%.3f(arr[%d]/arr[%d]), ", result_map_each.first, result_map_each.second.at(0), result_map_each.second.at(1));
                if (current_count == k)
                {
                    result.push_back(arr[result_map_each.second.at(0)]);
                    result.push_back(arr[result_map_each.second.at(1)]);
                    break;
                }
                
            }
            // printf("\n------------------------------------------------\n\n");
            
            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Kth Smallest Prime Fraction, Algorithm(Binary Search)!\n";
    cout << "https://leetcode.com/problems/k-th-smallest-prime-fraction/" << endl << endl;
    cout << "solution: https://www.cnblogs.com/grandyang/p/9135156.html" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: arr = [1,2,3,5], k = 3\n");
    printf("expected result: output = [2,5]\n");
    printf("Explanation: The fractions to be considered in sorted order are: 1/5, 1/3, 2/5, 1/2, 3/5, and 2/3. The third fraction is 2/5.\n");
    {
        vector<int> arr{1,2,3,5};
        int k = 3;
         
        Solution solution;
        auto result = solution.kthSmallestPrimeFraction(arr, k);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]=%d\n", i, result[i]);
        }
        
        
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: arr = [1,7], k = 1\n");
    printf("expected result: output = [1,7]\n");
    {
        vector<int> arr{1,7};
        int k = 1;
         
        Solution solution;
        auto result = solution.kthSmallestPrimeFraction(arr, k);
        printf("result size:%d\n", result.size());
        for (size_t i = 0; i < result.size(); i++)
        {
            printf("result[%d]=%d\n", i, result[i]);
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
