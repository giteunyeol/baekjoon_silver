#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int array1[1000002];
    int array2[1000002];
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> array1[i];
    }
    for(int j = 0; j < m; j++)
    {
        cin >> array2[j];
    }

    int array1_idx = 0;
    int array2_idx = 0;
    for(int i = 0; i < n + m; i++)
    {
        //한쪽 배열 이 끝에 먼저 닿았을때 예외케이스 처리를 해줘야함.
        if(array1_idx == n) //1번어레이가 닿았을경우
        {
            for(int j = array2_idx; j < m; j++)
            {
                cout << array2[array2_idx] << " ";
                array2_idx++;
            }
            return 0;
        }
        else if(array2_idx == m) //2번 어레이가 닿았을경우
        {
            for(int j = array1_idx; j < n; j++)
            {
                cout << array1[array1_idx] << " ";
                array1_idx++;
            }
            return 0;
        }
        
        if(array1[array1_idx] >= array2[array2_idx]) // 1번의 값이 크거나 같으면
        {
            cout << array2[array2_idx] << " ";
            array2_idx++;
        }
        else
        {
            cout << array1[array1_idx] << " ";
            array1_idx++;
        }
    }

    // [3. 5] 0,1에 들어있음. n : 2, array1_idx = 0 시작
    // [2. 9] 0,1에 들어있음. m : 2, array2_idx = 0 시작
    return 0;
}