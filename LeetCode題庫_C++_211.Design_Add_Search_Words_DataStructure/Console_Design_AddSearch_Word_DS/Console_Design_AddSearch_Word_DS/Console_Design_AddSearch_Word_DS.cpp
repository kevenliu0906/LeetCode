// Console_Design_AddSearch_Word_DS.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>


using namespace std;

class WordDictionary {
private:
    // solution 0 (best, use map to storage input string, refer other: https://zxi.mytechroad.com/blog/data-structure/leetcode-211-design-add-and-search-words-data-structure/)
    unordered_set<string> words;
    unordered_map<int, unordered_set<string>> ws;

    // solution 1 (keven, use 2D vector to storage input string)
    vector<vector<string>> base_vec_vec;  // each element in array is each word size, ex: base_set_vec[1] is data group for string len = 1, base_set_vec[5] is data group for string len = 5
    unordered_set<string> existSearchWord_set ;  // record existed searching word to save time
    // unordered_map<int, unordered_set<string>> base_strlen_str_map;
    
public:
    WordDictionary() {
        base_vec_vec.resize(26);    // 1 <= word len <= 25
    }
    
    void addWord(string word) {
        // // solution 0 (best, use map to storage input string, refer other: https://zxi.mytechroad.com/blog/data-structure/leetcode-211-design-add-and-search-words-data-structure/)
        // {
        //     words.insert(word);
        //     ws[word.length()].insert(word);
        //     return;
        // }

        // solution 1 (keven, use 2D vector to storage input string)
        {
            // Only add the different input word to save time
            if (existSearchWord_set.count(word) != 0){
                return;
            }

            existSearchWord_set.insert(word);
            base_vec_vec[word.size()].insert(base_vec_vec[word.size()].end(), word);
            // base_strlen_str_map[word.size()].insert(word);
        }
    }

    // // solution 0 (best, use map to storage input string, refer other: https://zxi.mytechroad.com/blog/data-structure/leetcode-211-design-add-and-search-words-data-structure/)
    // bool match(const string& p, const string& w) {
    //     for (int i = 0; i < p.length(); ++i) {
    //         if (p[i] == '.') continue;
    //         if (p[i] != w[i]) return false;
    //     }
    //     return true;
    // }
    
    bool search(string word) {
        // // solution 0 (best, use map to storage input string, refer other: https://zxi.mytechroad.com/blog/data-structure/leetcode-211-design-add-and-search-words-data-structure/)
        // {
        //     if (word.find(".") == string::npos)
        //         return words.count(word);
                
        //     for (const string& w : ws[word.length()])
        //         if (match(word, w)) return true;    
        
        //     return false;
        // }

        // solution 1 (keven, use 2D vector to storage input string)
        {
            vector<string>& base_vec = base_vec_vec[word.size()];  // avoid copy total object to cost much time
            if (base_vec.size() == 0)
            {
                return false;
            }
            // if (base_strlen_str_map[word.size()].size() == 0)
            // {
            //     return false;
            // }
            
            // printf("search(%s) >>> wordSize:%d, base_vec_vec[%d] size is:%d\n", word.c_str(), wordSize, wordSize, base_vec.size());
            int dotpos = word.find(".");

            if (dotpos == string::npos)
            {
                // // search word does NOT have '.'
                if (existSearchWord_set.count(word))
                {
                    return true;
                }

                return false;
                
            }else{
                for (size_t i = 0; i < base_vec.size(); i++)
                {
                    /*auto (//using auto will copy total object to cost much time) */const string& base_str = base_vec[i];
                    // Compare here !!!!!
                    int checkIdx = 0;
                    bool check_res = true;
                    while (checkIdx < word.size())
                    {
                        if (word[checkIdx] == '.')
                        {
                            checkIdx++;
                            continue;
                        }
                        if (base_str[checkIdx] != word[checkIdx])
                        {
                            check_res = false;
                            break;
                        }
                        
                        checkIdx++;
                    }
                    
                    if (check_res)
                    {
                        return true;
                    }                    
                }
                
                return false;

                // for (/*auto (//using auto will copy total object to cost much time) */const string& base_single_set : base_strlen_str_map[word.size()])
                // {
                //     bool match_fg = true;
                //     for (size_t i = 0; i < word.size(); i++)
                //     {
                //         if (word[i] == '.')
                //         {
                //             continue;
                //         }
                        
                //         if (word[i] != base_single_set[i])
                //         {
                //             match_fg = false;
                //             break;
                //         }
                //     }
                //     if (match_fg)
                //     {
                //         return true;
                //     }
                // }

                // return false;
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */


int main()
{
    std::cout << "Hello LeetCode - Design Add Search Words DataStructure, Algorithm(Depth-First Search)!\n";
    cout << "https://leetcode.com/problems/design-add-and-search-words-data-structure/" << endl << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: [\"WordDictionary\",\"addWord\",\"addWord\",\"addWord\",\"search\",\"search\",\"search\",\"search\"]\n");
    printf("       [[],[\"bad\"],[\"dad\"],[\"mad\"],[\"pad\"],[\"bad\"],[\".ad\"],[\"b..\"]]\n");
    {
        
        // Your WordDictionary object will be instantiated and called as such:
        WordDictionary* obj = new WordDictionary();
        obj->addWord("bad");
        obj->addWord("dad");
        obj->addWord("mad");
        obj->addWord("wadc");
        obj->addWord("bad");

        auto result = obj->search("pad"); // return False
        printf("search \"pad\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search("bad"); // return True
        printf("search \"bad\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search(".ad"); // return True
        printf("search \".ad\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search("b.."); // return True
        printf("search \"b..\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search("c.."); // return False
        printf("search \"c..\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search(".c."); // return False
        printf("search \".c.\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search("."); // return False
        printf("search \".\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search(".."); // return False
        printf("search \"..\" is %d, true(%d), false(%d)\n", result, true, false);

        result = obj->search(".a."); // return True
        printf("search \".a.\" is %d, true(%d), false(%d)\n", result, true, false);

        delete obj;
         
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
