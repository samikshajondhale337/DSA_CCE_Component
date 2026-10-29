#include <iostream>
using namespace std;

int cost[10][10], dist[10], visited[10], parent[10];
int n, source;

void dijkstra() {
    for (int i = 0; i < n; i++) {
        dist[i] = 9999;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1, minCost = 9999;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minCost) {
                minCost = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (cost[u][v] > 0 && !visited[v] &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                parent[v] = u;
            }
        }
    }
}

void displayDistances() {
    cout << "\nShortest distances from " << source << ":\n";

    for (int i = 0; i < n; i++) {
        cout << "Location " << i << ": ";

        if (dist[i] == 9999)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }
}

void displayPath() {
    int dest, path[10], k = 0;

    cout << "Enter destination: ";
    cin >> dest;

    if (dest < 0 || dest >= n || dist[dest] == 9999) {
        cout << "Invalid or unreachable destination\n";
        return;
    }

    for (int v = dest; v != -1; v = parent[v])
        path[k++] = v;

    cout << "Shortest path: ";

    for (int i = k - 1; i >= 0; i--) {
        cout << path[i];
        if (i > 0)
            cout << " -> ";
    }

    cout << "\nMinimum cost: " << dist[dest] << "\n";
}

int main() {
    cout << "Enter number of locations (max 10): ";
    cin >> n;

    if (n < 1 || n > 10) {
        cout << "Invalid number of locations\n";
        return 0;
    }

    cout << "Enter cost matrix (0 = no road):\n";

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    cout << "Enter warehouse/source vertex: ";
    cin >> source;

    if (source < 0 || source >= n) {
        cout << "Invalid source vertex\n";
        return 0;
    }

    dijkstra();
    displayDistances();

    int choice;

    do {
        cout << "\n1. Change source vertex";
        cout << "\n2. Display shortest path";
        cout << "\n3. Update road cost";
        cout << "\n4. Display shortest distances";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter new source vertex: ";
            cin >> source;

            if (source >= 0 && source < n) {
                dijkstra();
                displayDistances();
            } else {
                cout << "Invalid source vertex\n";
            }
        }
        else if (choice == 2) {
            displayPath();
        }
        else if (choice == 3) {
            int u, v, newCost;

            cout << "Enter road vertices: ";
            cin >> u >> v;

            cout << "Enter new road cost: ";
            cin >> newCost;

            if (u < 0 || u >= n || v < 0 || v >= n ||
                u == v || newCost < 0) {
                cout << "Invalid vertices or cost\n";
            } else {
                cost[u][v] = newCost;
                cost[v][u] = newCost;

                dijkstra();
                displayDistances();
                cout << "Road cost updated successfully\n";
            }
        }
        else if (choice == 4) {
            displayDistances();
        }
        else if (choice != 0) {
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
