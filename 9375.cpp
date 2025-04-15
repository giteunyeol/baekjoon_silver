#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++)
    { 
        cin >> m;
        unordered_map<string, pair<string, int>>clothes; //key값은 string, value값의 첫번째는 string(각 부위의 옷), 두번째는 카운트.
        int answer = 1; //답의 초기값 = 1;

        for(int j = 0; j < m; j++)
        {

            string ckey, cvalue; 
            cin >> cvalue >> ckey; //부위를 키값으로, 각각 의상 종류를 value로.

            if(clothes[ckey].first.empty()) // 만약 ckey값의 count가 비어있을 경우 0으로 초기화
            {
                clothes[ckey].second = 0;
            }

            clothes[ckey].first = cvalue; //ckey의 string value값에 부위 삽입 (pair의 처음string)
            clothes[ckey].second ++; //ckey의 int값에 각각의 부위에 몇개째인지 삽입. (pair의 두번째 int)
        } 

        for(auto j = clothes.begin(); j != clothes.end(); j++)
        {
            answer *= (j -> second.second + 1);
        }        

        cout << answer - 1 << "\n";

    }
    

    return 0;
}