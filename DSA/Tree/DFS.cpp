#include <bits/stdc++.h>
using namespace std;
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define ll long long int
#define vi vector<ll>
#define pb emplace_back
#define logarr(arr, a, b)            \
    for (int i = (a); i <= (b); i++) \
        cout << (arr[i]) << " ";     \
    cout << endl;
void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
class Graph
{
    int v;
    vector<vector<int>> adj;

public:
    Graph(int v)
    {
        this->v = v;
        adj.resize(v);
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void DFS(int start)
    {
        vector<bool> vis(v, false);
        stack<int> st;
        st.push(start);
        while (!st.empty())
        {
            int v = st.top();
            st.pop() ;

            if(!vis[v]) {
                cout << v << " ";
                vis[v] = true;
            }

            for(auto i = adj[v].rbegin() ; i != adj[v].rend() ; ++i){
                if(!vis[*i]){
                    st.push(*i);
                }
            }
        }
    }
};
int main()
{
    int who[10];
    cout << "DFS starting from 0 \n";
    return 0;
}