// ConsoleApplication_Employee_Importance.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
private:
    int getImp(vector<Employee*> &emp, int id){
        
        // STEP1: save all employee information into map
        unordered_map<int, Employee*> employee_map;   // key:id, value: employee-info

        for (size_t i = 0; i < emp.size(); i++)
        {
            auto cur_emp = emp[i];
            employee_map.insert(std::pair<int,Employee*>(cur_emp->id, cur_emp));
        }

        int res_imp = 0;

        // STEP2: start to find the importance
        queue<int> tmp_id_que;
        queue<int> cur_id_que;
        
        tmp_id_que.push(id);
        while (tmp_id_que.size())
        {
            cur_id_que.swap(tmp_id_que);
            while (cur_id_que.size())
            {
                auto cur_id = cur_id_que.front();
                // check cur_id exist in database or not
                if (employee_map.count(cur_id))
                {
                    // Exist
                    res_imp += employee_map[cur_id]->importance;
                    auto sub = employee_map[cur_id]->subordinates;
                    for (size_t i = 0; i < sub.size(); i++)
                    {
                        tmp_id_que.push(sub[i]);
                    }

                    employee_map.erase(cur_id);
                }

                cur_id_que.pop();
            }            
        }
        
        return res_imp;
    }
public:
    int getImportance(vector<Employee*> employees, int id) {
        // solution 1 (keven, using BFS to solve)
        {
            auto res = getImp(employees, id);

            return res;
        }
    }
};

int main()
{
    std::cout << "Hello LeetCode - Employee Importance, Algorithm(Breadth-First Search)!\n";
    cout << "https://leetcode.com/problems/employee-importance/" << endl;

    printf("*****************************************************\n");
    printf("************* testcase 1 ****************************\n");
    printf("input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1\n");
    printf("expected result: output = 11\n");
    printf("Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.\n");
    printf("             They both have an importance value of 3.\n");
    printf("             Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.\n");
    {
        Employee *ep1 = new Employee{1,5,{2,3}};
        Employee *ep2 = new Employee{2,3,{}};
        Employee *ep3 = new Employee{3,3,{}};
        // printf("ep1 id:%d, ep1 imp:%d\n", ep1->id, ep1->importance);
        // printf("ep2 id:%d, ep2 imp:%d\n", ep2->id, ep2->importance);
        // printf("ep3 id:%d, ep3 imp:%d\n", ep3->id, ep3->importance);
        vector<Employee*> employees{ep1, ep2, ep3};
        int id = 1;

        Solution solution;
        auto res = solution.getImportance(employees, id);
        printf("res is %d\n", res);

        delete ep1;
        delete ep2;
        delete ep3;
    }
    printf("*****************************************************\n");

    printf("\n\n");

    printf("*****************************************************\n");
    printf("************* testcase 2 ****************************\n");
    printf("input: employees = [[1,2,[5]],[5,-3,[]]], id = 5\n");
    printf("expected result: output = -3\n");
    printf("Explanation: Employee 5 has an importance value of -3 and has no direct subordinates.\n");
    printf("             Thus, the total importance value of employee 5 is -3.\n");
    {
        Employee *ep1 = new Employee{1,2,{5}};
        Employee *ep2 = new Employee{5,-3,{}};
        // printf("ep1 id:%d, ep1 imp:%d\n", ep1->id, ep1->importance);
        // printf("ep2 id:%d, ep2 imp:%d\n", ep2->id, ep2->importance);
        vector<Employee*> employees{ep1, ep2};
        int id = 5;

        Solution solution;
        auto res = solution.getImportance(employees, id);
        printf("res is %d\n", res);

        delete ep1;
        delete ep2;
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
