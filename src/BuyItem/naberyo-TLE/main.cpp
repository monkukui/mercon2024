#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool in_list(vector<int> list, int target)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ulist;
    vector<int> vlist;
    unordered_map<string, int> happiness;

    int u, v, h;
    for (int i = 0; i < n; ++i)
    {
        cin >> u >> v;
        if (!in_list(ulist, u))
        {
            ulist.push_back(u);
        }
        if (!in_list(vlist, v))
        {
            vlist.push_back(v);
        }
        cin >> happiness[to_string(u) + "," + to_string(v)];
    }

    sort(vlist.begin(), vlist.end());

    cout << vlist.size() << endl;
    for (int v : vlist)
    {
        int u_opt, h = 0;
        cout << v << " ";
        for (int u : ulist)
        {
            int h_u = happiness[to_string(u) + "," + to_string(v)];
            if (h_u > h)
            {
                h = h_u;
                u_opt = u;
            }
        }
        cout << u_opt << endl;
    }

    return 0;
}