#include <iostream>
#include <algorithm>
#include <vector>

//#define DEBUG

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    return a[2] < b[2];
}

int find_set(int node, vector<int>& node_set)
{
    if(node_set[node] == node)
        return node;
    else
        return find_set(node_set[node], node_set);
}

// Kruskal's Algorithm
int generate_mst(vector<vector<int>>& cost, int nr_vertex, int nr_edge)
{
    vector<int> visit (nr_vertex + 1, 0);
    int ret = 0;

    for(int i {1}; i < visit.size(); i++)
        visit[i] = i;

    for(int i {0}; i < cost.size(); i++)
    {
        int start = cost[i][0];
        int end = cost[i][1];

        int start_set = find_set(start, visit);
        int end_set = find_set(end, visit);

#ifdef DEBUG
        cout << "Start Set : [" << start << "] " << start_set << endl;
        cout << "End Set : [" << end << "] " << end_set << endl;
#endif

        if(start_set == end_set)
            continue;
        else if(start_set > end_set)
            visit[start_set] = end_set;
        else
            visit[end_set] = start_set;
#ifdef DEBUG
        cout << "Add : ( " << start << "," << end << " )" << endl;
#endif

        ret += cost[i][2];
    }

    cout << ret << endl;
    return 0;
}

int main()
{
    int nr_vertex, nr_edge;
    vector<vector<int>> cost;

    cin >> nr_vertex;
    cin >> nr_edge;

    cost.clear();
    cost.resize(nr_edge, vector<int>(3, 0));

    for(int i {0}; i < nr_edge; i++)
    {
        int start, end, edge_cost;
        cin >> start >> end >> edge_cost;

        cost[i][0] = start;
        cost[i][1] = end;
        cost[i][2] = edge_cost;
    }

    sort(cost.begin(), cost.end(), compare);

    /*
    for(int i {0}; i < nr_edge; i++)
        cout << cost[i][0] << " " << cost[i][1] << " " << cost[i][2] << endl;
    */

    generate_mst(cost, nr_vertex, nr_edge);

    return 0;
}
