// ConsoleApplication_Jewels_and_Stones.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        // solution 1 (keven, using HASH TABLE to solve)
        {
            int res = 0;
            string single_jewel = "";
            unordered_set<string> base_jewel;


            // STEP1: create base for search from jewels
            for (size_t i = 0; i < jewels.size(); i++){
                single_jewel = jewels.substr(i, 1);
                base_jewel.insert(single_jewel);
            }

            // STEP2: search if any stone in current stones is fitted into base-jewel
            for (size_t i = 0; i < stones.size(); i++)
            {
                if (base_jewel.find(stones.substr(i,1)) != base_jewel.end())
                {
                    res++;
                }
            }
            
            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Jewels and Stones, DataStructure(HASH TABLE)!\n";
    cout << "https://leetcode.com/problems/jewels-and-stones/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: jewels = \"aA\", stones = \"aAAbbbb\" \n");
    printf("expected result: output = 3\n");
    {
        string jewels = "aA";
        string stones = "aAAbbbb";
        
        Solution solution;
        auto res = solution.numJewelsInStones(jewels, stones);
        printf("res is %d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: jewels = \"z\", stones = \"ZZ\" \n");
    printf("expected result: output = 0\n");
    {
        string jewels = "z";
        string stones = "ZZ";
        
        Solution solution;
        auto res = solution.numJewelsInStones(jewels, stones);
        printf("res is %d\n", res);
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
