#include<bits/stdc++.h>
using namespace std;
#define I int(1e6)

int main(int argc, char** argv){
    int n_nodes;
    cout << "Enter number of nodes: " << flush;
    cin >> n_nodes;

    vector<vector<int>> adj(n_nodes, vector<int>(n_nodes));
    cout << "Enter Adjency Matrix(I is inf)" << endl;
    for(int i=0; i < n_nodes; ++i){
        for(int j=0; j < n_nodes; ++j){
            string s_adj;
            cin >> s_adj;
            adj[i][j] = s_adj == "I" ? I : stoi(s_adj);
        }
    }

    int n_clust;
    cout << "Enter number of clusters: " << flush;
    cin >> n_clust;

    vector<int> cluster_heads(n_clust);
    cout << "Enter the Cluster heads: " << flush;

    for(int i=0; i < n_clust; ++i)
        cin >> cluster_heads[i];
    
    vector<vector<int>> clusters(n_clust);
    for(int i=0; i < n_clust; ++i){
        cout << "Enter members of cluster " << i+1 << ": " << flush;
        string x;
    
        while (true){
            cin >> x;
            if(x=="N")
                break;
    
            clusters[i].push_back(stoi(x));
        }
    }

    cout << "Enter the batteries of the nodes: " << flush;
    vector<int> battery(n_nodes);
    
    for(int i=0; i < n_nodes; ++i)
        cin >> battery[i];

    int n_iter;
    cout << "Enter the number of iterations: " << flush;
    cin >> n_iter;

    for(int i=0; i < n_iter; ++i){
        cout << "Iteration " << i + 1 << endl;

        for(int i=0; i < n_clust; ++i){
            int head = -1;
        
            for(int node : clusters[i]){
                if(head==-1 or battery[node] > battery[head])
                    head = node;
            }

            cluster_heads[i] = head;
            clusters[i].clear();
        }

        cout << "New Cluster Heads: " << flush;
        for(int cluster_head : cluster_heads)
            cout << "node" << cluster_head << " " << flush << endl;

        for (int i = 0; i < n_nodes; ++i){
            int nearest_cluster = -1;

            for(int cluster=0; cluster < n_clust; ++cluster){
                if (nearest_cluster == -1 or adj[i][cluster_heads[cluster]] < adj[i][cluster_heads[nearest_cluster]])
                    nearest_cluster = cluster;
            }
        
            clusters[nearest_cluster].push_back(i);
        }

        cout << "New clusters" << endl;
        for(int i=0; i < n_clust; ++i){
            cout << "cluster" << i + 1 << ": " << flush;
        
            for(int node : clusters[i])
                cout << "node" << node << " " << flush << endl;
        }

        for(int i=0; i < n_clust; ++i){
            int cluster_head = cluster_heads[i];
            battery[cluster_head] -= (int) clusters[i].size();
        }

        cout << "New battery levels: " << flush;
        for (int bat_i : battery)
            cout << bat_i << " " << flush << endl;
    }

    return 0;
}