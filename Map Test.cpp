/*
Gabe Sibulkin, Country Coloring Lab, Submitted 12/11/22
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;


struct country_edge 
{
    int a, b;
};

class Graph
{
public:
    vector<vector<int>> adjlst;

    Graph(vector<country_edge> const& edges, int n) // def constr
    {
        adjlst.resize(n);

        
        for (country_edge edge : edges) // found a cooler way to add edges
        {
            int a = edge.a;
            int b = edge.b;

            adjlst[a].push_back(b);
            adjlst[b].push_back(a);
        }
    }
};

string color[] =
{
    "", "RED", "GREEN", "BLUE", "YELLOW", "MAJENTA", "CYAN", "ORANGE" // needs the blank space because of the set type for some reason
};


void colorGraph(Graph const& graph, int n)
{
    unordered_map<int, int> result; // use a map to keep track of colors for each country

    
    for (int i = 0; i < n; i++) // color assignment loop
    {
        
        set<int> assigned; // found that sets were the best way to store the adj nodes

        
        for (int j : graph.adjlst[i]) // check colors of adjacent countries and store them in the set
        {
            if (result[j]) 
            {
                assigned.insert(result[j]);
            }
        }

        
        int color = 1; // to squash bug with set, needs the space too in string arr

        for (auto& c : assigned)
        {
            if (color != c)
            {
                break;
            }
            color++;
        }

        
        result[i] = color; // assign country vertex the first available color that isn't neighbored by any other country
    }

    for (int i = 0; i < n; i++)
    {
        cout << "The color assigned to node: " << i << " is " // display loop
            << color[result[i]] << endl;
    }
}



int main()
{
    // vector of edge struct
    vector<country_edge> edges =
    {
        {0, 1},
        {0, 2},
        {0, 3},
        {0, 4},
        {0, 5},
        {0, 6},
        {0, 8},
        {0, 9},
        {0, 10},
        {0, 11},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5 ,6},
        {5, 7},
        {6, 7},
        {6, 8},
        {6, 12},
        {8, 9},
        {8, 10},
        {8, 12},
        {9, 10},
        {10, 11},
        {10, 12}

    };

    
    int n = 13; // n for nodes

    Graph graph(edges, n); // graph builder

    colorGraph(graph, n); // color function

    return 0;
}