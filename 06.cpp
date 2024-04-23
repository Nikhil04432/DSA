#include<iostream>
#include<string>
#include<queue>
#include<stack>

using namespace std;

int route[10][10] = {0, 0};
int nc;
char op;
char city;
string ap[20];

void displayGraph() {
    cout << "\nAdjacency Matrix representation of graph: " << endl;

    for (int i = 0; i < nc; i++) {
        for (int j = 0; j < nc; j++) {
            cout << route[i][j] << "\t";
        }
        cout << endl;
    }
}

void DFS(int start) {
    bool visited[10] = {false};
    stack<int> s;

    cout << "\nDFS Traversal: ";

    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int current = s.top();
        s.pop();
        cout << ap[current] << " ";

        for (int i = 0; i < nc; i++) {
            if (route[current][i] != 0 && !visited[i]) {
                s.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

void BFS(int start) {
    bool visited[10] = {false};
    queue<int> q;

    cout << "\nBFS Traversal: ";

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << ap[current] << " ";

        for (int i = 0; i < nc; i++) {
            if (route[current][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;
}

int main() {
    cout << "\nEnter no. of cities: ";
    cin >> nc;

    for (int i = 0; i < nc; i++) {
        cout << "Enter " << i + 1 << " City : ";
        cin >> ap[i];
    }

    cout << "\nDisplay cities with airport code: " << endl;
    for (int i = 0; i < nc; i++) {
        cout << "City " << i + 1 << " -> " << ap[i] << endl;
    }

    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            cout << "Enter distance between " << ap[i] << " and " << ap[j] << " : ";
            cin >> route[i][j];
            route[j][i] = route[i][j];
        }
    }

    displayGraph();
    int startVertex;
    cout << "\nEnter the starting vertex for traversal: ";
    cin >> startVertex;

    DFS(startVertex);
    BFS(startVertex);

    return 0;
}
