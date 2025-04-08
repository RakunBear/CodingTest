#include <iostream>
#include <string>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int answer[21] {0};
    int operateCount {0};
    cin >> operateCount;
    
    int inputNum {0};
    string order;
    for (int opc = 0; opc < operateCount; ++opc)
    {
        cin >> order;
        
        if (order == "add")
        {
            cin >> inputNum;
            answer[inputNum] = 1;
        }
        else if (order == "remove")
        {
            cin >> inputNum;
            answer[inputNum] = 0;
        }
        else if (order == "check")
        {
            cin >> inputNum;
            if (answer[inputNum] == 1)
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (order == "toggle")
        {
            cin >> inputNum;
            if (answer[inputNum] == 1)
            {
                answer[inputNum] = 0;
            }
            else
            {
                answer[inputNum] = 1;
            }
        }
        else if (order == "all")
        {
            for (int i = 1; i < 21; ++i)
            {
                answer[i] = 1;
            }
        }
        else if (order == "empty")
        {
            for (int i = 1; i < 21; ++i)
            {
                answer[i] = 0;
            }
        }
        
    }
    return 0;
}
