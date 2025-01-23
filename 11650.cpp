#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// x, y좌표 출력순서 정렬

typedef struct coordinate
{
    int x;
    int y;
}coordinate;

bool SortFunction(coordinate &a, coordinate &b)
{
    if(a.x == b.x) //x가 같은경우
    {
        return a.y < b.y;
    }
    else
    {
        return a.x < b.x;
    }
}

int main(void)
{
    int n;
    cin >> n;

    vector <coordinate> C(n);

    for(int i = 0; i < n; i++)
    {
        cin >> C[i].x >> C[i].y;
    }

    //정렬
    sort(C.begin(), C.end(), SortFunction);

    for(int i = 0; i < n; i++)
    {
        cout << C[i].x << " " << C[i].y << "\n";
    }

    return 0;
}