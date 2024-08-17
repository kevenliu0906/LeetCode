// ConsoleApplication_Simply_Path.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {

        // solution 1 (keven, best, using stack to solve)
        {
            stack<string> folder_stack;
            string result;

            // STEP1. Append the "/" into the tail of path if not exist
            {
                auto laststring = path.substr(path.size() - 1, 1);
                // printf("(first check) last_string:%s\n", laststring.c_str());
                if (laststring != "/")
                {
                    // printf("append \"/\" into tail\n");
                    path.append("/");
                }
                laststring = path.substr(path.size() - 1, 1);
                // printf("(final check) last_string:%s\n", laststring.c_str());
            }

            // STEP2. Replace all "//" symbol into "/" in the path
            {
                string Replacement = "//";
                // printf("Replacement:%s, size:%d\n", Replacement.c_str(), (int)Replacement.size());
                if (path.find(Replacement) != string::npos)
                {
                    // printf("doing replace, find:%d\n", path.find(Replacement));
                    path.replace((int)path.find(Replacement), (int)Replacement.size(), "/");
                }
            }
            
            // printf("path to split:%s\n", path.c_str());
            
            // STEP3. Split all folder names with '/'
            {
                auto split_pos = 0;
                do{
                    split_pos = path.find("/");

                    if (split_pos == string::npos){
                        break;
                    }
                    
                    if (split_pos == 0){
                        // in the beginning case
                        path.erase(path.begin());
                    }
                    else{
                        // other cases
                        auto each_folder_name = path.substr(0, split_pos);
                        // printf("each_folder_name:%s\n", each_folder_name.c_str());

                        {
                            // STEP4. Judge all operation in path
                            if (each_folder_name == "..")
                            {
                                // remove the last folder name from stack
                                if (folder_stack.size())
                                {
                                    folder_stack.pop();
                                }
                                path.erase(0, split_pos);
                                continue;
                            }
                            else if (each_folder_name == ".")
                            {
                                path.erase(0, split_pos);
                                continue;
                            }
                        }

                        folder_stack.push(each_folder_name);
                        path.erase(0, split_pos);
                    }
                    
                }while (split_pos != string::npos);
            }

            // STEP5. assembly the folder name from stack 1-by-1
            {
                while (folder_stack.size())
                {
                    auto top = folder_stack.top();
                    top.insert(0, "/");
                    result = top + result;
                    // printf("top:%s, result:%s\n", top.c_str(), result.c_str());
                    folder_stack.pop();
                }
                if (result.size() == 0)
                {
                    result = "/";
                }
            }

            return result;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Simply Path, DataStructure(stack)!\n";
    cout << "https://leetcode.com/problems/find-peak-element/" << endl << endl;
    // cout << "solution: https://https://hackmd.io/@Zero871015/LeetCode-237/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: path = \"/home/\"\n");
    printf("expected result: output = \"/home\"\n");
    printf("Explaination: The trailing slash should be removed.\n\n");
    {
        string path = "/home/";
        Solution solution;

        auto result = solution.simplifyPath(path);
        printf("\"%s\" simplifyPath is:\"%s\"\n", path.c_str(), result.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: path = \"/home//foo/\"\n");
    printf("expected result: output = \"/home/foo\"\n");
    printf("Explaination: Multiple consecutive slashes are replaced by a single one.\n\n");
    {
        string path = "/home//foo/";
        Solution solution;

        auto result = solution.simplifyPath(path);
        printf("\"%s\" simplifyPath is:\"%s\"\n", path.c_str(), result.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 3 ****************************\n");
    printf("input: path = \"/home/user/Documents/../Pictures\"\n");
    printf("expected result: output = \"/home/user/Pictures\"\n");
    printf("Explaination: A double period \"..\" refers to the directory up a level.\n\n");
    {
        string path = "/home/user/Documents/../Pictures";
        Solution solution;

        auto result = solution.simplifyPath(path);
        printf("\"%s\" simplifyPath is:\"%s\"\n", path.c_str(), result.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 4 ****************************\n");
    printf("input: path = \"/../\"\n");
    printf("expected result: output = \"/\"\n");
    printf("Explaination: Going one level up from the root directory is not possible.\n\n");
    {
        string path = "/../";
        Solution solution;

        auto result = solution.simplifyPath(path);
        printf("\"%s\" simplifyPath is:\"%s\"\n", path.c_str(), result.c_str());
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 5 ****************************\n");
    printf("input: path = \"/.../a/../b/c/../d/.\"\n");
    printf("expected result: output = \"/.../b/d\"\n");
    printf("Explaination: \"...\" is a valid name for a directory in this problem.\n\n");
    {
        string path = "/.../a/../b/c/../d/.";
        Solution solution;

        auto result = solution.simplifyPath(path);
        printf("\"%s\" simplifyPath is:\"%s\"\n", path.c_str(), result.c_str());
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
