#include <iostream>
#include <stack>
#include <string>

using namespace std;

//괄호 스택문제

int main(void)
{
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n; i++) //n번만큼 시행
    {
        stack<char> parenthesis;
        string par;
        cin >> par;
        
        for(int j = 0; j < par.length(); j++) // 괄호 입력 끝까지
        {
           if(par[j] == ')') // ")" 가 들어왔을때
           {
               if (!parenthesis.empty() && parenthesis.top() == '(')
                {
                   parenthesis.pop();
                }
                else // 우괄호가 들어왔는데 좌괄호가 없는경우 
                {
                    parenthesis.push(')');
                }
           }
           else // "(" 가 들어왔을때
           {
               parenthesis.push('(');
           }   
        }

        // ----- 입력 모두 끝난 후 --------
        if(parenthesis.empty()) //비어있는 경우
        {
            cout << "YES\n";
        }
        else //비어있지 않는경우
        {
            cout << "NO\n";
        }
        
    }

    return 0;
}