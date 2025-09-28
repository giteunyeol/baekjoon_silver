#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    string first_str;
    cin >> first_str;
    list<char> str;
    for(auto i : first_str) {str.push_back(i);}
    auto cursor = str.end();

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        char command;
        cin >> command;
        if(command == 'L')
        {
            if(cursor != str.begin()){ cursor--; }
        }
        else if (command == 'D')
        {
            if(cursor != str.end()) { cursor++; }
        }
        else if (command == 'B')
        {
            if(cursor != str.begin())
            cursor = str.erase(prev(cursor));
        }
        else if (command == 'P')
        {
            char input;
            cin >> input;
            str.insert(cursor, input);
        }
        else {cout << "error!!"; exit(0);}
    }
    for(auto i : str) { cout << i;}
    return 0;
}