#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    string array;
    cin >> array;
    int answer = 0;
    stack<char> stk;
    for(int i = 0; i < array.size(); i++)
    {
        if(array[i] == '(') //여는괄호
        {
            stk.push(array[i]);
        }
        else //닫는괄호일때
        {
            stk.pop();
            if(array[i - 1] == '(') //앞이 여는괄호
            {
                answer += stk.size();
            }
            else if(array[i - 1] == ')') //앞이 닫는괄호
            {
                answer++;
            }
        }
    }
    cout << answer;
    return 0;
}