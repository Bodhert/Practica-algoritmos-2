#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
int size;

typedef pair <int, int> edge;
typedef vector <edge> vii;

vector <vii> graph;
vector <int> dist;
vector <int> predecesor;


void setContainers()
{
  graph.assign(size,vii());
  dist.assign(size,INF);
  predecesor.assign(size, -1);
}

void printConexAndWeigth()
{
  for(int i = 0; i < size; ++i )
  {
    if(graph[i].size() != 0){
      cout << "nodo : " << i << " va a: (nodo, distancia) " << endl;
      for(int j = 0; j < graph[i].size(); ++j)
      {
        cout << graph[i][j].first << " ";
        cout << graph[i][j].second << " ";
        cout << endl;
      }
    }
  }
  cout << endl;
}


void saveGraph(int vertex1, int vertex2,int weigth)
{
  graph[vertex1].push_back(edge(vertex2,weigth));
}

void readAndStore()
{
  int vertex1,vertex2,weigth;

  scanf("%i", &size);

  setContainers();

  while(scanf("%i %i %i",&vertex1,&vertex2,&weigth) != EOF)
  {
    saveGraph(vertex1,vertex2,weigth);
  }

}

int main()
{
  std::ios::sync_with_stdio(true);
  readAndStore();
  printConexAndWeigth();
  return 0;
}
