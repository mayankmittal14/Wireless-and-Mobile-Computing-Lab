#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>& graph){
    int n = graph.size();
    cout << " ";

    for(int i=0; i<n; i++)
        printf("%3c", ('A' + i));

    cout << "\n";
    for(int i=0; i<n; i++){
        cout << (char)('A' + i);

        for(int j=0; j<n; j++){
            if(graph[i][j] == INT_MAX)
                printf("%3d", -1);
            else
                printf("%3d", graph[i][j]);
        }

        cout << "\n";
    }

    cout << "\n\n";
}

void solve(vector<vector<int>> &ans, vector<int> neighbores[]){
    int n = ans.size();
    cout << "After 1st iteration: \n\n";
    print(ans);

    for(int k=0; k < n-2; k++){
        vector<vector<int>> prev = ans;
        for(int i = 0; i < n; i++){
            for(int j=0; j < n; j++){
                ans[i][j] = prev[i][j];
                
                for(int t=0; t < neighbores[i].size(); t++){
                    int y = neighbores[i][t];
                    int val;

                    if(prev[i][y]==INT_MAX || prev[y][j]==INT_MAX)
                        val = INT_MAX;
                    else
                        val = prev[i][y] + prev[y][j];

                    ans[i][j] = min(ans[i][j], val);
                }
            }
        }

        cout << "After " << k + 2 << "th iteration : \n\n";
        print(ans);
    }
}

int main(){
    int IM = INT_MAX;
    cout << "\n....Distance Vector Routing Algorithm....\n\n";
    vector<vector<int>> graph = {{0, 2, IM, 1}, {2, 0, 3, 7},{IM, 3, 0, 11}, {1, 7, 11, 0}};

    int n = graph.size();
    vector<int> neighbors[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j] != INT_MAX)
                neighbors[i].push_back(j);
        }
    }
    
    solve(graph, neighbors);
    return 0;
}