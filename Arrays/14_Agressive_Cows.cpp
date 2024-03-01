// #include <iostream>
// using namespace std;
// // int isPossible(vector<int> &stalls,int k, int mid)
// {
//     int cowcnt = 1;
//     int lastPos = stalls[0];
//     for (int i = 0; i < stalls.size(); i++)
//     {
//         if (stalls[i] - lastPos >= mid)
//         {
//             cowcnt++;
//             if (cowcnt == k)
//             {
//                 return true;
//             }
//             lastPos = stalls[i];
//         }
//     }
//     return false;
// }

// // int aggressiveCows(vector<int> &stalls, int k)
// {
//     int s = 0, maxi = -1;
//     sort(stalls.begin(), stalls.end());
//     for (int i = 0; i < stalls.size(); i++)
//     {
//         maxi = max(maxi, stalls[i]);
//     }
//     int e = maxi;
//     int mid = s + (e - s) / 2;
//     int ans = -1;
//     while (s <= e)
//     {
//         if (isPossible(stalls, k, mid))
//         {
//             ans = mid;
//             s = mid + 1;
//         }
//         else
//         {
//             e = mid - 1;
//         }
//         mid = s + (e - s) / 2;
//     }
//     return ans;
// }
// int main()
// {

//     return 0;
// }