#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 단어정렬
// 규칙
// 1.길이가 짧은 것부터
// 2.길이가 같으면 사전순으로
// 3.문자열의 길이는 50을 넘으면 안됨.  -> string타입으로 해결
// 4.중복되면 안됨. cout 할때 boolean타입으로 기존 인덱스 / 다음 인덱스 비교해서 같다면 출력 x

bool length(string &a, string &b) // a는 word[i], b는 word[i+1]
{
    if (a.length() == b.length()) // 길이가 동일
    {
        return a < b;
    }
    else
    {
        return a.length() < b.length();
    }
}

int main(void)
{
    string word[20001];
    int n;
    cin >> n; // n갯수 입력

    for (int i = 0; i < n; i++) // n번만큼 word[i]에 입력받음.
    {
        cin >> word[i];
    }

    sort(word, word + n, length);

    for (int i = 0; i < n; i++) // 정렬된 word[i] 출력. boolean으로
    {
        if (bool(word[i] != word[i + 1]))
        {
            cout << word[i] << endl;
        }
    }

    return 0;
}