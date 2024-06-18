// ConsoleApplication_TwoSum.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        // reference: https://shengyu7697.github.io/std-unordered_map/#google_vignette
        // create a database // standard usage
        std::unordered_map<int, int> indexUnMap;  // advance usage, use unordered_map to increase efficiency of time cost
        // std::map<int, int> indexMap;

        vector<int> Result;
        
        for(int i = 0; i < nums.size(); i++){
            // calc the num of current index need to add what's value to reach target
            int CurrentNumNeedAdd = target - nums[i];

            // figure out if the addition value is included in database or NOT
            // auto iter = indexMap.find(CurrentNumNeedAdd);
            auto iter_un = indexUnMap.find(CurrentNumNeedAdd);

            // if( iter != indexMap.end() ){
            if( iter_un != indexUnMap.end()){
                // bingo, have found the additions value in database, so return both of the indexs for database-index & current-index
                // Result.push_back( iter->second );
                Result.push_back( iter_un->second );
                Result.push_back( i );
                break;
            }
            else {
                // the addition value is NOT included in database, so add this num of current index into database
                // indexMap.insert( std::pair<int, int>( nums[i], i ) );
                indexUnMap.insert( std::pair<int, int>( nums[i], i ) );
            }
        }
        return Result;
    }
};

int main()
{
    std::cout << "Hello LeetCode - Two Sum, data structure - DataStructure (HASH TABLE) !\n";

    printf("LeetCode - 1. Two Sum\n");
    cout << "https://leetcode.com/problems/two-sum/" << endl << endl;
    cout << "solution: https://blog.techbridge.cc/2017/01/21/simple-hash-table-intro/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: nums=[2, 7, 11, 15], target=9\n");
    printf("expected result: [0, 1]\n");
    {
        vector<int> nums{ 2, 7, 11, 15 };
        int target = 9;
        Solution Solution_cs;
        auto Result = Solution_cs.twoSum(nums, target);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: nums=[3, 2, 4], target=6\n");
    printf("expected result: [1, 2]\n");
    {
        vector<int> nums{ 3, 2, 4 };
        int target = 6;
        Solution Solution_cs;
        auto Result = Solution_cs.twoSum(nums, target);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: nums=[3, 3], target=6\n");
    printf("expected result: [0, 1]\n");
    {
        vector<int> nums{ 3, 3 };
        int target = 6;
        Solution Solution_cs;
        auto Result = Solution_cs.twoSum(nums, target);
        printf("Result size is %d\n", Result.size());
        for (size_t i = 0; i < Result.size(); i++)
        {
            printf("Result[%d]=%d\n", i, Result[i]);
        }
    }
    printf("*****************************************************\n");
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
