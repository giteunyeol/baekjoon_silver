//백준 7568. 덩치
//몸무게, 키를 받아서 덩치가 몇순위인지 차례대로 출력.
//몸무게, 키가 둘다 큰 경우에만 덩치가 더 큰 case.
#include <iostream>
#include <vector>

using namespace std;

typedef struct Volume
{

    int weight;
    int height;

}Volume;

int main(void)
{
    int n;
    cin >> n;

    vector <Volume> human(n); //사람의 명수만큼 동적할당

    for(int i = 0; i < n; i++)
    {
        cin >> human[i].weight >> human[i].height; //몸무게, 키 할당
    }

    // 랭킹 할당
    for(int i = 0; i < n; i++)
    {
        int count = 1;
        for(int j = 0; j < n; j++)
        {
            if(human[i].weight < human[j].weight && human[i].height < human[j].height)
            {
                count++;
            }
        }
        cout << count << " ";
    }

}
