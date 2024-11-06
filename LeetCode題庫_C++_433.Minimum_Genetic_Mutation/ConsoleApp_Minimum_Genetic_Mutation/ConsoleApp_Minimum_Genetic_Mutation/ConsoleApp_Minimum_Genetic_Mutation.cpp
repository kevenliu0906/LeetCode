// ConsoleApp_Minimum_Genetic_Mutation.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
private:
    int onechar_change(string &cur_str, string &target_str){
        int checkIdx = 0;
        int dif_count = 0;
        while (checkIdx < 8)
        {
            if (cur_str[checkIdx] != target_str[checkIdx])
            {
                dif_count++;
                if (dif_count > 1){
                    return false;
                }
            }
            
            checkIdx++;
        }
        
        return true;
    }

    int start_move_From_bank_BFS(string startGene, string endGene, vector<string>  &bank){

        if (bank.empty()) return -1;
        
        queue<string> cur_gene_que;
        queue<string> tmp_gene_que;
        unordered_set<string> check_gene_set;  // record the gene has checked
        int min_mutation = 0;


        tmp_gene_que.push(startGene);
        check_gene_set.insert(startGene);

        while (tmp_gene_que.size())
        {
            cur_gene_que.swap(tmp_gene_que);
            while (cur_gene_que.size())
            {
                auto cur_gene = cur_gene_que.front();

                // check if cur_gene is endGene
                if (cur_gene == endGene)
                {
                    // BINGO!!! ~ found the endGene
                    return min_mutation;
                }
                
                for (size_t i = 0; i < bank.size(); i++){
                    if (check_gene_set.count(bank[i]) == 0){
                        // never check before cur_gene and bank[i]
                        if (onechar_change(cur_gene, bank[i])){
                            // only one bit char change between cur_gene
                            tmp_gene_que.push(bank[i]);
                            check_gene_set.insert(bank[i]);
                        }
                    }
                }
                cur_gene_que.pop();
            }

            min_mutation++;
        }

        return -1;
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        // solution 1 (keven, using BFS, refer other https://alanzhan.dev/post/2022-06-28-leetcode-433/)
        {
            auto res = start_move_From_bank_BFS(startGene, endGene, bank);

            return res;
        }
        
    }
};

int main()
{
    std::cout << "Hello LeetCode - Minimum Genetic Mutation, Algorithm(Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/minimum-genetic-mutation/" << endl;
    cout << "solution: https://alanzhan.dev/post/2022-06-28-leetcode-433/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: startGene = \"AACCGGTT\", endGene = \"AACCGGTA\", bank = [\"AACCGGTA\"]\n");
    printf("expected result: output = 1\n");
    {
        string startGene = "AACCGGTT";
        string endGene = "AACCGGTA";
        vector<string> bank{"AACCGGTA"};
        
        Solution solution;
        auto res = solution.minMutation(startGene, endGene, bank);
        printf("res:%d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: startGene = \"AACCGGTT\", endGene = \"AAACGGTA\", bank = [\"AACCGGTA\",\"AACCGCTA\",\"AAACGGTA\"]\n");
    printf("expected result: output = 2\n");
    {
        string startGene = "AACCGGTT";
        string endGene = "AAACGGTA";
        vector<string> bank{"AACCGGTA","AACCGCTA","AAACGGTA"};
        
        Solution solution;
        auto res = solution.minMutation(startGene, endGene, bank);
        printf("res:%d\n", res);
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: startGene = \"AACCGGTT\", endGene = \"AACCGGTA\", bank = [\"\"]\n");
    printf("expected result: output = -1\n");
    {
        string startGene = "AACCGGTT";
        string endGene = "AACCGGTA";
        vector<string> bank;
        
        Solution solution;
        auto res = solution.minMutation(startGene, endGene, bank);
        printf("res:%d\n", res);
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
