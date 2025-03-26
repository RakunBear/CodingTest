#include <bits/stdc++.h>
// #include <iostream>
// #include <queue>

using namespace std;

int T, M, N, K;
int d[1000][1000];
queue<pair<int, int>> insertQueue;
queue<pair<int, int>> bfsQueue;
int answer;


void bfs()
{
   while (insertQueue.size() > 0)
   {
       pair<int, int> startP = insertQueue.front();
       insertQueue.pop();
       if (d[startP.first][startP.second] != 1)
        {
            continue;
        }
       bfsQueue.push(startP);

       while (bfsQueue.size() > 0)
       {
           pair<int, int> t = bfsQueue.front();
           bfsQueue.pop();
           if (d[t.first][t.second] != 1)
           {
               continue;
           }
           d[t.first][t.second] = 2;

           int tU = t.first - 1;
           int tD = t.first + 1;
           int tL = t.second - 1;
           int tR = t.second + 1;

           if (tU >= 0)
           {
               bfsQueue.push({ tU, t.second });
           }
           if (tD < M)
           {
               bfsQueue.push({ tD, t.second });
           }
           if (tL >= 0)
           {
               bfsQueue.push({ t.first, tL });
           }
           if (tR < N)
           {
               bfsQueue.push({ t.first, tR });
           }
       }
       ++answer;
   }
}

int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

   cin >> T;

   while (T--)
   {
       answer = 0;

       cin >> M >> N >> K;
       for (int i = 0; i < K; ++i)
       {
           int r, c;
           cin >> r >> c;
           d[r][c] = 1;
           insertQueue.push({ r, c });
       }

       bfs();

       cout << answer << "\n";
   }

   return 0;
}
