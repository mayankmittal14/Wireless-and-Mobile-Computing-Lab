#include<bits/stdc++.h>
using namespace std;
#define V 9             // Number of vertices in the graph

int minDistance(int dist[], bool sptSet[]){
    int min=INT_MAX, min_index;

    for(int v=0; v < V; v++){
        if(sptSet[v]==false && dist[v] <= min)
            min = dist[v], min_index = v;
    }

    return min_index;
}

void printPath(int from[], int dest, int src){
    int destination = dest;
    cout << "\nThe RREP packet will be: ";
    vector<int> path;

    while(from[dest]!=-1){
        path.push_back(dest);
        dest = from[dest];
    }

    path.push_back(dest);
    
    cout << "\n_____________________________\n";
    cout << "| 3 | " << src << " | " << destination << " | ";

    for(int i=path.size()-1; i>=0; i--){
        if(i != 0)
            cout << path[i] << "->";
        else
            cout << path[i] << " |";
    }

    cout << "\n-----------------------------\n";
}

void DSRP(int graph[V][V], int src, int dest){
    int dist[V];
    int from[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
    from[src] = -1;

    for(int count=0; count < V-1; count++){
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for(int v=0; v < V; v++){
            if(!sptSet[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                from[v] = u;
            }
        }
    }

    printPath(from, dest, src);
}

int main(){
    int graph[V][V] = {{0, 1, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1},
        {1, 1, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 1, 0}};

    cout << "\nThe Graph:\n ";
    for(int i=0; i < V; i++)
        cout << i << " ";

    cout << "\n";
    for(int i=0; i < V; i++){
        cout << i << " : ";
        for(int j=0; j < V; j++)
            cout << graph[i][j] << " ";
    
        cout << "\n";
    }

    int src, dest;
    cout << "\nEnter src node : ";
    cin >> src;
    
    cout << "Enter dest node : ";
    cin >> dest;
    
    DSRP(graph, src, dest);
    return 0;
}