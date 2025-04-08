#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    unordered_set<string> peopleMap;
    vector<string> findPeoples;
    string inputName;
    for (int count = 0; count < N; ++count)
    {
        cin >> inputName;
        peopleMap.insert(inputName);
    }
    
    for (int count = 0; count < M; ++count)
    {
        cin >> inputName;
        auto it = peopleMap.find(inputName);
        if (it != peopleMap.end())
        {
            findPeoples.push_back(inputName);
        }
    }
    sort(findPeoples.begin(), findPeoples.end());
    cout << findPeoples.size() << '\n';
    for (int findCount = 0; findCount < static_cast<int>(findPeoples.size()); ++findCount)
    {
        cout << findPeoples[findCount] << '\n';
    }
    
    return 0;
}
