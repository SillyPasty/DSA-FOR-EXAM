#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int adjMatrix[5][5] = {0};
    int wat, bewat, cal;
    char input[1000];
    int flg = 0;
    cin >> input;
    for(int i = 0; i < strlen(input); i += 4)
    {
        wat = int(input[i] - '0');
        bewat = int(input[i + 2] - '0');
        adjMatrix[wat][bewat] = 1;
    }
    cin >> cal;
    for(int i = 0; i < 5; i++)
    {
        int cnt = 0;
        for(int j = 0; j < 5; j++)
            if(adjMatrix[i][j] != 0)
            {
                cnt++;
                if(j == cal && cnt % 2)
                {
                    cout << i << ',';
                    flg = 1;
                }
            }
    }
    if(!flg)
        cout << -1;
    //system("pause");
    return 0;
}