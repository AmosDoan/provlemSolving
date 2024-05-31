#include <iostream>
#include <vector>
#include <queue>

#define MAX_COST 9999
//#define DEBUG

using namespace std;

struct edge
{
    int start;
    int end;
    int edge_cost;

    bool operator<(const struct edge& rhs) const
    {
        return (edge_cost < rhs.edge_cost);
    };
};

vector<int> mst;
vector<int> visit;

int generate_mst(vector<vector<int>>& adj_matrix, 
                 int nr_vertex, 
                 int nr_edgehb,
                 int start_node)
{
    int sum_cost = 0;
    priority_queue<struct edge> min_heap{};
    struct edge start;

    start.start = start_node;
    start.end = start_node;
    start.edge_cost = 0;
    min_heap.push(start);

    while(!min_heap.empty())
    {
        struct edge current = min_heap.top();
        min_heap.pop();

        if(visit[current.end])
            continue;

        visit[current.end] = 1;
        sum_cost += current.edge_cost;

#ifdef DEBUG
        cout << endl << endl << endl;
        cout << "Selected" << endl;
        cout << "start : " << current.start << endl;
        cout << "end : " << current.end << endl;
        cout << "cost : " << current.edge_cost << endl;
        cout << "===========" << endl;
#endif

        for(int i {1}; i < nr_vertex + 1; i++)
        {
            if(adj_matrix[current.end][i] != 0)
            {
                struct edge tmp;
                tmp.start = current.end;
                tmp.end = i;
                tmp.edge_cost = adj_matrix[current.end][i];

#ifdef DEBUG
                cout << "Enqueued" << endl;
                cout << "current : " << current.end << endl;
                cout << "start : " << tmp.start << endl;
                cout << "end : " << tmp.end << endl;
                cout << "cost : " << tmp.edge_cost << endl;
                cout << "===========" << endl;
#endif
                min_heap.push(tmp);
            }
        }
    }

    return sum_cost;
}

// Prim's Algorithm
int main()
{
    int nr_vertex, nr_edge;
    vector<vector<int>> adj_matrix;

    cin >> nr_vertex >> nr_edge;

    adj_matrix.clear();
    adj_matrix.resize(nr_vertex + 1, vector<int>(nr_vertex + 1, 0));

    visit.resize(nr_vertex + 1, 0);

    for(int i {0}; i < nr_edge; i++)
    {
        int start, end, edge_cost;
        cin >> start >> end >> edge_cost;

        adj_matrix[start][end] = adj_matrix[end][start] = edge_cost;
    }

#ifdef DEBUG
#if 0
    for(int i {0}; i < nr_vertex + 1; i++)
    {
        for(int j{0}; j < nr_vertex + 1; j++)
        {
            cout << adj_matrix[i][j];
        }
        cout << endl;
    }
#endif
#endif

    cout << generate_mst(adj_matrix, nr_vertex, nr_edge, 1);
    cout << endl;

    return 0;
}
