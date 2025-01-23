#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Member
{
    int age;
    string name;
}Member;
//나이순 정렬, 만약 같다면 가입한 순서대로

bool sortfunction(const Member & a, const Member & b)
{
    return a.age < b.age;
}

int main(void)
{
    int n;
    cin >> n;

    vector <Member> M(n);

    for(int i = 0; i < n; i++)
    {
        cin >> M[i].age >> M[i].name;
    }

    //정렬
    stable_sort(M.begin(), M.end(), sortfunction);

    for(int i = 0; i < n; i++)
    {
        cout << M[i].age << " " << M[i].name << endl;
    }


    return 0;
}

//++ stable sort를 사용했더니 걸리는 시간이 파이썬급으로 느려졌다... 사용하는걸 지양해야할듯