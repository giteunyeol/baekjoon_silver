#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    //아직 아무 의견이 없는 경우
    if(n == 0)
    {
        cout << "0";
        exit(0);    
    }

    vector <int> number_save(n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        number_save[i] = temp;
    }

    sort(number_save.begin(), number_save.end()); // number_save 정렬
    double k = n * 0.15;
    double trimmed_round = round(n * 0.15); // trimmed_round = 절사평균 반올림

    //cout << "test" << endl << k << endl << trimmed_round << endl << endl;

    double result = 0; //0으로 세팅
    for(int i = trimmed_round; i < n - trimmed_round; i++)
    {
        //cout << "test" << number_save[i] << endl ; 
        result += number_save[i];
    }
    result = result / (n - trimmed_round * 2);
    cout << round(result);

    return 0;
}