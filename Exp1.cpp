#include<bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& v, int n){
    int a = 1;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(a & v[i][j] == 0)
                return false;
        }
    }

    return true;
}

int main(){
    int n;
    cout << "Enter the number of sensor nodes: ";
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));
    cout << "Enter the graph to create connections: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }

    cout << "Are all the nodes connected? : ";
    if(check(v, n))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}