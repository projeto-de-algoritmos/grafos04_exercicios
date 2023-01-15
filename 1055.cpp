#include <algorithm>
#include <deque>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main()
{
    int n, q, r, c = 1;

    cin >> n;

    while (n--) {
        cin >> q;

        vector<int> resp;

        while (q--) {
            cin >> r;
            resp.push_back(r);
        }

        sort(resp.begin(), resp.end());

        int t = 0, x = 0, y = resp.size() - 1;

        deque<int> ans;

        while (t < resp.size()) {
            if (ans.empty())
                ans.push_back(resp[y--]);
            else {
                priority_queue<iii> pq;

                pq.push(make_pair(make_pair(abs(resp[x] - ans[0]), 1), x));
                pq.push(make_pair(make_pair(abs(resp[x] - ans[ans.size() - 1]), 2), x));
                pq.push(make_pair(make_pair(abs(resp[y] - ans[0]), 3), y));
                pq.push(make_pair(make_pair(abs(resp[y] - ans[ans.size() - 1]), 4), y));

                if (pq.top().first.second == 1) {
                    ans.push_front(resp[pq.top().second]);
                    x++;
                }
                else if (pq.top().first.second == 2) {
                    ans.push_back(resp[pq.top().second]);
                    x++;
                }
                else if (pq.top().first.second == 3) {
                    ans.push_front(resp[pq.top().second]);
                    y--;
                }
                else {
                    ans.push_back(resp[pq.top().second]);
                    y--;
                }
            }
            t++;
        }

        int sum = 0;

        for (int i = 0; i < ans.size() - 1; ++i)
            sum += abs(ans[i] - ans[i + 1]);

        cout << "Case " << c++ << ": " << sum << "\n";
    }
    
    return 0;
}