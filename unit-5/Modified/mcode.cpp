#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>
#include <algorithm>

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

    int source, destination;

    cout << "Enter source and destination stops: ";
    cin >> source >> destination;

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n)
    {
        cout << "Invalid source or destination." << endl;
        return 1;
    }

    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

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

        if (u == destination)
            break;

        for (int i = 0; i < (int)graph[u].size(); i++)
        {
            int v = graph[u][i].first;
            int weight = graph[u][i].second;

            if (dist[u] != INF &&
                dist[u] <= INT_MAX - weight &&
                dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                parent[v] = u;

                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if (dist[destination] == INF)
    {
        cout << "No route exists from stop "
             << source << " to stop "
             << destination << "." << endl;

        return 0;
    }

    vector<int> path;

    int v = destination;

    while (v != -1)
    {
        path.push_back(v);
        v = parent[v];
    }

    reverse(path.begin(), path.end());

    cout << endl;
    cout << "Minimum travel time: "
         << dist[destination] << " time units" << endl;

    cout << "Shortest path: ";

    for (int i = 0; i < (int)path.size(); i++)
    {
        if (i > 0)
            cout << " -> ";

        cout << path[i];
    }

    cout << endl;

    return 0;
}
