#include <iostream>
#include <vector>

#define INF 10000.0f

using namespace std;

vector<float> dist;
vector<int> visit;
vector<vector<float>> cost;

// Dijkstra
void dijkstra(int nr_node)
{
    float min = INF;
    float tmp;
    cost[0][0] = 0;

    for(int i {0}; i < nr_node; i++)
    {
        dist[i] = 0;
        visit[i] = 1;
        min = INF;

        for(int j {0}; j < cost.size(); j++)
        {
            tmp = dist[j] + cost[j][i];
            if(visit[j] && min > tmp)
                min = tmp;
        }

        dist[i] = min;

        for(int j {0}; j < dist.size(); j++)
        {
            if(visit[j])
            {
                tmp = dist[i] + cost[i][j];
                if(tmp < dist[j])
                    dist[j] = tmp;
            }
        }
    }
}

// 시작 노드는 항상 0
int main()
{
    int nr_sample;
    cin >> nr_sample;

    for(int i {0}; i < nr_sample; i++)
    {
        int nr_node;
        int nr_edge;

        cin >> nr_node >> nr_edge;
        visit.clear();
        visit.resize(nr_node, 0);

        dist.clear();
        dist.resize(nr_node, INF);
        dist[0] = 0;

        cost.clear();
        cost.resize(nr_node, vector<float>(nr_node, INF));

        for(int j {0}; j < nr_edge; j++)
        {
            int start, end;
            float edge_cost;
            cin >> start >> end >> edge_cost;
            cost[start - 1][end - 1] = cost[end - 1][start - 1]
                = edge_cost;
        }

        dijkstra(nr_node);

        for(auto& it : dist)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
