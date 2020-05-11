#include <iostream>
#include <vector>
#include <iomanip> 

using namespace std;
#define INF 99999
void printSolution(int** dist, int N ,int E, int T);  
// void addEdge(vector <pair<int, int> > adj[], int u, 
//                                      int v, int wt) 
// { 
//     adj[u].push_back(make_pair(v, wt)); 
//     adj[v].push_back(make_pair(u, wt)); 
// } 

// void printGraph(vector<pair<int,int> > adj[], int V) 
// { 
//     int v, w; 
//     for (int u = 0; u < V; u++) 
//     { 
//         cout << "Node " << u << " makes an edge with \n"; 
//         for (auto it = adj[u].begin(); it!=adj[u].end(); it++) 
//         { 
//             v = it->first; 
//             w = it->second; 
//             cout << "\tNode " << v << " with edge weight ="
//                  << w << "\n"; 
//         } 
//         cout << "\n"; 
//     } 
// } 

int** Make2dArray(int width,int height){
    int** graph;
    graph = new int*[height];
    for(int i=0;i<height;i++){
        graph[i] = new int[width];
    }
    return graph;
}

void Clean2dArray(int**graph, int N) //is graph passed by reference?
{
for (int i=0;i<N+1;i++)
    {
      for (int j=0;j<N+1;j++)
      {
          if(i==j){
            graph[i][j]=0;
          }else{
            graph[i][j]=INF;
          }
        
      }
    }
    
}

void Delete2dArray(int** graph, int width,int height){
    for (int i=0; i<height; i++)
        delete [] graph[i];
    delete [] graph;
}

void printSolution(int** , int );
  
// Solves the all-pairs shortest path  
// problem using Floyd Warshall algorithm  
void floydWarshall (int** &graph, int N, int T, int E)  
{  
    /* dist[][] will be the output matrix  
    that will finally have the shortest  
    distances between every pair of vertices */
    int** dist=Make2dArray(N+1, N+1);
    Clean2dArray(dist,N);

  
    /* Initialize the solution matrix same  
    as input graph matrix. Or we can say  
    the initial values of shortest distances 
    are based on shortest paths considering  
    no intermediate vertex. */
    for (int i = 1; i <= N; i++)  
        for (int j = 1; j <= N; j++)  
            dist[i][j] = graph[i][j];  
  
    /* Add all vertices one by one to  
    the set of intermediate vertices.  
    ---> Before start of an iteration,  
    we have shortest distances between all  
    pairs of vertices such that the  
    shortest distances consider only the  
    vertices in set {0, 1, 2, .. k-1} as 
    intermediate vertices.  
    ----> After the end of an iteration,  
    vertex no. k is added to the set of  
    intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (int k = 1; k <= N; k++)  
    {  
        // Pick all vertices as source one by one  
        for (int i = 1; i <= N; i++)  
        {  
            // Pick all vertices as destination for the  
            // above picked source  
            for (int j = 1; j <= N; j++)  
            {  
                // If vertex k is on the shortest path from  
                // i to j, then update the value of dist[i][j]  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
  
    // Print the shortest distance matrix  
    printSolution(dist, N, E, T);  
    Delete2dArray(dist,N+1,N+1);
}  
  
/* A utility function to print solution */
void printSolution(int** dist, int N ,int E, int T)  
{  
    int finish=0;
    for (int i=1; i<=N;i++)
    {
      if (dist[i][E]<=T)
        {
          finish++;
        }
    }
cout<<finish;
    // for (int i = 1; i < N+1; i++)  
    // {  
    //     for (int j = 1; j < N+1; j++)  
    //     {  
    //         if (dist[i][j] == INF)  
    //             cout<<setw(5)<<"INF";
    //         else
    //             cout<<setw(5)<<dist[i][j];
    //     }  
    //     cout<<endl;  
    // }  
}  





int main() 
{
  int cases;
  int N; // cells
  int E; // exit cells 
  int T; //time to beat
  int M; //connections

  int a; //edge from a to b
  int b; 
  int time; //edge time
 
  cin>> cases;
  for (int c=0; c<cases;c++)
  {
    cin>>N;
           
    cin>>E;
     
    cin>>T;
    
    cin>>M;
    //vector<pair<int, int> > adj[N+1];
    // make a 2D array with this line by calling above function
    int** graph = Make2dArray(N+1,N+1);
    //set graph to unconnected first....
    Clean2dArray(graph, N);
    //...then set the edges
    for (int i=0;i<M;i++)
    {
      cin>>a;
      cin>>b;
      cin>>time;
      graph[a][b]=time;
     //addEdge(adj, a, b, time); 
     
    
    }
    floydWarshall(graph,  N,  T,  E);
    //check matrix
    // for (int i=1;i<N+1;i++)
    // {
      
    //   for (int j=1;j<N+1;j++)
    //   {
    //     cout<<graph[i][j]<<" ";
    //   }
    //   cout<<endl;
    // }
  //printGraph(adj, N);
  //printSolution(graph,N);
  cout<<endl;
  Delete2dArray(graph, N+1,N+1);
  }
  return 0;
}