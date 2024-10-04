// ConsoleApplication_Number_of_Provinces.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<bool> City_HasChecked_fg_vec;

    void DFS(vector<vector<int>>& isConnected, int RowIdx)
    {
        for (size_t i = 0; i < isConnected[RowIdx].size(); i++)
        {
            if (isConnected[RowIdx][i])
            {
                // printf("DFS >>> isConnected, RowIdx:%d, i:%d\n", RowIdx, i);
                if (City_HasChecked_fg_vec[i])
                {
                    continue;
                }
                City_HasChecked_fg_vec[i] = true;
                // printf("DFS >>> call DFS isConnected, RowIdx:%d, i:%d\n", RowIdx, i);
                DFS(isConnected, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int Circle = 0;

        int CityCount = isConnected.size();
        City_HasChecked_fg_vec.resize(CityCount, false);

        int RowIdx = 0;
        // for (size_t i = 0; i < isConnected.size(); i++){
        while (RowIdx < isConnected.size())
        {
            bool check = City_HasChecked_fg_vec[RowIdx];
            if (City_HasChecked_fg_vec[RowIdx])
            {
                RowIdx++;
                continue;
            }
            
            for (size_t j = RowIdx; j < isConnected[RowIdx].size(); j++){
                if (isConnected[RowIdx][j] && !City_HasChecked_fg_vec[RowIdx]){
                    // printf("findCircleNum >>> isConnected, RowIdx:%d, j:%d\n", RowIdx, j);
                    DFS(isConnected, RowIdx);
                    Circle++;
                }
            }
            
            City_HasChecked_fg_vec[RowIdx] = true;

            RowIdx++;
        }

        return Circle;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    cout << "https://leetcode.com/problems/number-of-provinces/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]\n");
    printf("expected result: output = 2\n");
    {
        vector<vector<int>> isConnected{{1,1,0},{1,1,0},{0,0,1}};
        
        Solution solution;
        auto result = solution.findCircleNum(isConnected);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]\n");
    printf("expected result: output = 3\n");
    {
        vector<vector<int>> isConnected{{1,0,0},{0,1,0},{0,0,1}};
        
        Solution solution;
        auto result = solution.findCircleNum(isConnected);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: isConnected = [[1,1,0,0,1],[1,1,0,0,1],[0,0,1,0,0],[0,0,0,1,0],[1,1,0,0,1]]\n");
    printf("expected result: output = 3\n");
    {
        vector<vector<int>> isConnected{{1,1,0,0,1},{1,1,0,0,1},{0,0,1,0,0},{0,0,0,1,0},{1,1,0,0,1}};
        
        Solution solution;
        auto result = solution.findCircleNum(isConnected);
        printf("result:%d\n", result);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: isConnected = [[1,0,0,1],[0,1,1,0],[0,1,1,1],[1,0,1,1]]\n");
    printf("expected result: output = 1\n");
    {
        vector<vector<int>> isConnected{{1,0,0,1},{0,1,1,0},{0,1,1,1},{1,0,1,1}};
        
        Solution solution;
        auto result = solution.findCircleNum(isConnected);
        printf("result:%d\n", result);
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
