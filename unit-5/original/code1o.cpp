#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

const int INF = INT_MAX;

int main()
{
    int n, m;

    cout << "Enter number of bus stops and routes: ";
    cin >> n >> m;

    if (n <= 0 || m < 0)
    {
        cout << "Invalid input." << endl;
        return 1;
    }

    vector< vector< pair<int, int> > > graph(n);

    cout << "Enter each route as: stop1 stop2 travelTime" << endl;

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= n || v < 0 || v >= n || w < 0)
        {
            cout << "Invalid route input." << endl;
            return 1;
        }

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    int source;

    cout << "Enter the starting stop: ";
    cin >> source;

    if (source < 0 || source >= n)
    {
        cout << "Invalid source stop." << endl;
        return 1;
    }

    vector<int> dist(n, INF);

    priority_queue<
        pair<int, int>,
        vector< pair<int, int> >,
        greater< pair<int, int> >
    > pq;

    dist[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int currentDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (currentDist != dist[u])
            continue;

        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[u] != INF &&
                dist[u] <= INT_MAX - weight &&
                dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    cout << endl;
    cout << "Minimum travel times from stop "
         << source << ":" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "Stop " << i << ": ";

        if (dist[i] == INF)
            cout << "Unreachable" << endl;
        else
            cout << dist[i] << " time units" << endl;
    }

    return 0;
}
