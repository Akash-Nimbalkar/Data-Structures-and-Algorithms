#include <bits/stdc++.h>
using namespace std;
void findCombinations(int ind, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &ds)
{
    if (ind == candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }

    // Pick the element case
    if (candidates[ind] <= target)
    {
        ds.push_back(candidates[ind]);
        findCombinations(ind, target - candidates[ind], candidates, ans, ds);
        ds.pop_back();
    }

    // Not pick the element case
    findCombinations(ind + 1, target, candidates, ans, ds);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
}
int main()
{

    int n, target;

    cout << "Enter no. of array elements : " << endl;
    cin >> n;

    vector<int> candidates(n);
    vector<vector<int>> ans;
    vector<int> ds;

    cout << "Enter " << n << " array elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> candidates[i];
    }

    cout << "Enter target sum" << endl;
    cin >> target;

    findCombinations(0, target, candidates, ans, ds);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}