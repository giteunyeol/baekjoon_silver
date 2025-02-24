#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
    while(true)
    {
        string str;
        stack<char> stk;
        getline(cin, str);

        if(str == ".") // '.' 입력받으면 탈출
        {
            exit(0);
        }

        bool balance = true;

        for(int i = 0; i < str.length(); i++)
        {
            char temp = str[i];

            //좌괄호가 들어오면 무조건 푸쉬
            if(temp == '(' || temp == '[')
            {
                stk.push(temp);
            }
            //우괄호:대
            else if(temp == ']')
            {
                if(!stk.empty() && stk.top() == '[') 
                {
                    stk.pop();
                }
                else
                {
                    balance = false;
                    break;
                }
            }
            //우괄호:소
            else if(temp == ')')
            {
                if(!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    balance = false;
                    break;
                }
            }
        }

        if(balance == true && stk.empty())
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }    
    

    return 0;
}