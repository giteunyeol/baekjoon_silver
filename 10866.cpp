#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    deque<int> Deque;
    for(int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if(command == "push_front")
        {
            int number;
            cin >> number;
            Deque.push_front(number);
        }
        else if(command == "push_back")
        {
            int number;
            cin >> number;
            Deque.push_back(number);
        }
        else if (command == "pop_front")
        {
            if(Deque.empty() == true)
            {
                cout << "-1" << "\n";
                continue;
            }
            cout << Deque.front() << "\n";
            Deque.pop_front();
        }
        else if (command == "pop_back")
        {
            if (Deque.empty() == true)
            {
                cout << "-1" << "\n";
                continue;
            }
            cout << Deque.back() << "\n";
            Deque.pop_back();
        }
        else if (command == "size")
        {
            cout << Deque.size() << "\n";
        }
        else if (command == "empty")
        {
            if(Deque.empty() == true) { cout << "1" << "\n"; }
            else { cout << "0" << "\n";}
        }
        else if (command == "front")
        {
            if(Deque.empty() == true) { cout << "-1" << "\n"; continue;}
            cout << Deque.front() << "\n";
        }
        else if (command == "back")
        {
            if (Deque.empty() == true) { cout << "-1" << "\n"; continue;}
            cout << Deque.back() << "\n";
        }
        else {cout << "error"; exit(0);}
    }

    return 0;
}