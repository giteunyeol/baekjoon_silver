#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 각각의 값을 리턴

int arithmeticmean(vector<int> & savenumber) // 산술평균, n개 수들의 합을 n으로 나눈 값
{
    double answer = 0;
    for(int i = 0; i < savenumber.size(); i++)
    {
        answer += savenumber[i];
    }

    return round(answer / savenumber.size());  //round : 소수점 반올림 함수
}

int Median(vector<int> &savenumber) // 중앙값
{
    sort(savenumber.begin(), savenumber.end()); //정렬

    return savenumber[savenumber.size() / 2];
}

int Mode(const vector<int> &savenumber) // 최빈값 함수
{
    int count_numbers[8002] = {0}; 
    int max_count = 0;            

    for (int i = 0; i < savenumber.size(); i++)
    {
        int num = savenumber[i];     // 현재 숫자
        count_numbers[num + 4000]++; // 0을 기준으로 조정
        if (count_numbers[num + 4000] > max_count)
        {
            max_count = count_numbers[num + 4000]; // 최빈값의 등장 횟수 갱신
        }
    }

    vector<int> mode_array; // 최빈값 저장

    for (int i = 0; i <= 8001; i++)
    {
        if (count_numbers[i] == max_count)
        {
            mode_array.push_back(i - 4000); // 원래 숫자로 변환하여 저장
        }
    }

    
    if (mode_array.size() == 1)
    {
        return mode_array[0];
    }
    else
    {
        return mode_array[1]; // 두 번째로 작은 값
    }
}

int range(const vector<int> &savenumber) // 최댓값 , 최솟값 차이
{
    int max = savenumber[0];
    int min = savenumber[0];

    for(int i = 0; i < savenumber.size(); i++)
    {
        if(max < savenumber[i])
        {
            max = savenumber[i];
        }
    }

    for (int i = 0; i < savenumber.size(); i++)
    {
        if (min > savenumber[i])
        {
            min = savenumber[i];
        }
    }

    return max - min;
}


int main(void)
{
    int count; // 입력받는 수의 갯수(홀수만 입력)
    cin >> count;
    vector<int> savenumber(count);

    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        savenumber[i] = temp;
    }

    cout 
    << arithmeticmean(savenumber) << "\n"
    << Median(savenumber) << "\n"
    << Mode(savenumber) << "\n"
    << range(savenumber);

    return 0;
}