using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include <stack>
#include "dijkstras.h"

// ** Dijkstra's Algorithm **
vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous) {
    int numV = G.numVertices;
    vector<int> distance(numV, INF);
    vector<bool> visited(numV, false);
    previous.resize(numV);

    distance[source] = 0;
    previous[source] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({source, 0});

    while (!pq.empty()) {
        pair<int, int> min = pq.top();
        int cur = min.first; 
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        for (Edge e: G[cur]) {
            int destination = e.dst;
            int weight = e.weight;

            if (!visited[destination] && distance[cur] + weight < distance[destination]) {
                distance[destination] = distance[cur] + weight;
                previous[destination] = cur;
                pq.push({destination, distance[destination]});
            }
        }
    }

    return distance;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> shortest;
    int cur = destination;

    while (cur != -1) {
        shortest.push_back(cur);
        cur = previous[cur];
    }

    reverse(shortest.begin(), shortest.end());
    return shortest;
}

void print_path(const vector<int>& v, int total) {
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << " ";

    cout << endl;
    cout << "Total cost is " << total << endl;
}


// ** File Functions **
string get_arg(int argc, char * argv[], string def) {
    string arg;

    if (argc > 1) {
        arg = string(argv[1]);
        return arg;
    }

    return def;
}