#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Graph {
    int V; // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    vector<int> *adj;

public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    int BFS();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // Add w to v’s list.
}
int Graph::BFS() {
    // Mark all the vertices as not visited
    bool *visited = new bool[V];

    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }


    // Create a deque for BFS
    deque<int> deque;

    // visited
    //a [0] true
    //b [1] true
    //c [2] true
    //d [3] true
    //e [4] true

    // deque[]
    // s = 4

    // adj
    // [A] => [B]
    // [B] => [A,D]
    // [C] => [E]
    // [D] => [B]
    // [E] => [C]
    int subgraphs = 0;

    for (int j = 0; j < V; j++) {
        if(visited[j] == false){
            // Mark the current node as visited and endeque it
            visited[j] = true;
            deque.push_back(j);

            // 'i' will be used to get all adjacent
            // vertices of a vertex
            vector<int>::iterator i;

            while (!deque.empty()) {
                // Dedeque a vertex from deque and print it
                int s = deque.front();
                //cout << s << " ";
                //nodes[s] = -1;
                deque.pop_front();

                // Get all adjacent vertices of the dedequed
                // vertex s. If a adjacent has not been visited,
                // then mark it visited and endeque it
                for (i = adj[s].begin(); i != adj[s].end(); ++i) {
                    if (!visited[*i]) {
                        visited[*i] = true;
                        deque.push_back(*i);
                    }
                }
            }
          subgraphs++;  //2
        }
        
    }
    return subgraphs;
}


int main() {
    int cases = 0;
    int max_node = 0;
    int nodes[27];
    string line = "";

    //vector<int> nodes;
    //vector<int, int>edges;
    //vector <int, edges> graph;
    for (int z = 0; z < 27; z++) {
        nodes[z] = -1;
    }
    int subgraph = 0;
    int sub_graph_check = 0;
    // get cases
    getline(cin, line); // get cases
    cases = stoi(line); // convert to int
    //cout << cases << endl;

    // get blank line
    getline(cin, line);

    //for loop for number of cases
    for (int i = 0; i < cases; i++) {

        // get max node
        getline(cin, line);
        max_node = line[0] - 65 + 1;
        //cout << max_node << endl;
        for (int a = 0; a < max_node; a++) {
            nodes[a] = a;
        }

        Graph g(max_node);
        // nodes.resize(int(max_node-65));
        // get edges
        //getline(cin,line);

        // while not empty line to read edges

        getline(cin, line);
        while (line != "") {
            int from, to;
            from = line[0] - 65;
            to = line[1] - 65;
            //cout<<from<<"->"<<to<<endl;
            g.addEdge(from, to);
            g.addEdge(to,from);
            getline(cin, line);
        }


        int subgraph = g.BFS();
        //do bfs
        //     for (int b=0;b<max_node;b++)
        //     {
        //       while(nodes[b]!=-1)
        //       {
        //         g.BFS(b,nodes);
        //         subgraph++;
        //       }

        //     }
        //   }
        //
        cout << subgraph << endl;
        
    }
    return 0;
}