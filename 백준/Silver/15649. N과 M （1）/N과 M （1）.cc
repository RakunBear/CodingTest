#include <iostream>

using namespace std;

void backT(int canV[10], int canVIdx, int N, int M)
{
    if (M == 0)
    {
        int output[10];
        int outSize = 0;
        for (int i = 1; i <= N; ++i)
        {
            if (canV[i])
            {
                output[canV[i]] = i;
                ++outSize;
            }
        }

        for (int i = 1; i <= outSize; ++i)
        {
            cout << output[i] << " ";
        }
        cout << "\n";
        return ;
    }
        
    for (int i = 1; i <= N; ++i)
    {
        if (canV[i]) continue;
        
        canV[i] = canVIdx;
        
        backT(canV, canVIdx + 1, N, M - 1);
        
        canV[i] = 0;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    int canV[10];
    int canVIdx = 1;
    string answer;
    
    cin >> N >> M;

    for (int i = 0; i < 10; ++i)
    {
        canV[i] = 0;
    }
    
    backT(canV, canVIdx, N, M);
    
    return 0;
}
