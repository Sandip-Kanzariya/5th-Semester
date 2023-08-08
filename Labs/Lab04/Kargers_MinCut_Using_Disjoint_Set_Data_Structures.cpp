// Online C++ compiler to run C++ program online
// This is one run of Karger's Min-Cut algorithm
// You can do it 100n(n-1) times with logic of random edge selection for accurate answer
// This code requires to enter (u,v) manually
#include <bits/stdc++.h>
using namespace std;
#define N 4
int G[N][N] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
int G1[N][N];

int count_edges()
{
    int counter = 0;
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (G[i][j] == 1)
                counter++;
        }
    }
    return counter;
}
void create_edge_matrix(int E[][2])
{
    int i, j;
    int x = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            if (G[i][j] == 1)
            {
                E[x][0] = i;
                E[x][1] = j;
                x++;
            }
        }
    }
}
int find(int node, int parent[])
{

    // If the node is the parent of
    // itself then it is the leader
    // of the tree.
    if (node == parent[node])
        return node;

    // Else, finding parent and also
    //  compressing the paths.
    return parent[node] = find(parent[node], parent);
}
// Union function
void Union(int u, int v, int parent[])
{
    u = find(u, parent);
    v = find(v, parent);
    parent[v] = u;
}

int main()
{
    // Write C++ code here
    srand(time(NULL));
    int parent[N] = {0, 1, 2, 3};
    int m = count_edges();
    cout << "Number of Edges : " << m << endl;
    int i, j;
    int n = N;
    int edges[m][2];
    create_edge_matrix(edges);
    while (n > 2)
    {
        int u, v;
        /*cout<<"Enter Edge:"<<endl;
        cout<<"Enter U:"<<endl;
        cin>>u;
        cout<<"Enter V:"<<endl;
        cin>>v;*/
        int e = rand() % m;
        u = edges[e][0];
        v = edges[e][1];

        int set1 = find(u, parent);
        // Finding leader element to which
        // edges[i].v belongs.
        int set2 = find(v, parent);

        // If they do not belong
        // to the same set.
        if (set1 != set2)
        {
            cout << "Contracting vertices " << u << " and " << v << endl;
            // Merging vertices u and v into one.
            Union(u, v, parent);
            // Reducing count of vertices by 1.
            n--;
        }
    }
    // Initializing answer (minCut) to 0.
    cout << "Parent : ";
    int ans = 0;
    for (i = 0; i < N; i++)
        cout << parent[i] << " ";
    cout << endl;
    cout << "Edges needs to be removed - " << endl; 
    for (int i = 0; i < m; i++)
    {
        // Finding leader element to which
        // edges[i].u belongs.
        int set1 = find(edges[i][0], parent);
        // Finding leader element to which
        // edges[i].v belongs.
        int set2 = find(edges[i][1], parent);

        // If they are not in the same set.
        if (set1 != set2)
        {
            cout << edges[i][0] << " <----> " << edges[i][1] << endl;
            // Increasing the ans.
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}