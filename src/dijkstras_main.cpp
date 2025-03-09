#include "dijkstras.h"

int main(int argc, char *argv[]) {
    string filename = get_arg(argc, argv, "src/largest.txt");
    Graph G;
    int source = 0;
    vector<int> previous;
    file_to_graph(filename, G);

    cout << "Dijkstra's Algorithm:\n";
    vector<int> distances = dijkstra_shortest_path(G, source, previous);

    for (int destination = 0; destination < G.numVertices; ++destination) {
        vector<int> path = extract_shortest_path(distances, previous, destination);
        print_path(path, distances[destination]);
    }
}

// g++ -std=c++20 -o exec src/dijkstras_main.cpp src/dijkstras.cpp
// valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --track-origins=yes ./exec