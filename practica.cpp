#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
int size,disSize;

typedef pair <int, int> edge;
typedef vector <edge> vii;
typedef vector <int> vi;
typedef pair <int,int> dist_node; //datos del heap (nodo, peso)

vector <vii> graph;
vector <vi> dispatch;
vector <int> dist;
vector <int> predecesor;

void dijkstra(int source)
{
  priority_queue <dist_node ,vector <dist_node> , greater <dist_node> > q;

  dist[source] = 0;
  q.push(dist_node(0,source));
  while (!q.empty())
  {
    int distancia = q.top().first;
    int cur = q.top().second;
    q.pop();
    if(distancia > dist[cur]) continue;
    for(int i = 0; i < graph[cur].size(); ++i)
    {
          int next = graph[cur][i].first;
          int w_extra = graph[cur][i].second;
          if(dist[cur] + w_extra < dist[next])
          {
            dist[next] = dist[cur] + w_extra;
            predecesor[next] = cur;
            q.push(dist_node(dist[next],next));
          }
    }
  }
}

vector <int> find_path(int t)
{
  vector <int> path;
  int cur =  t;
  while(cur != -1)
  {
    path.push_back(cur);
    cur = predecesor[cur];
  }
  reverse(path.begin(),path.end());
  return path;
}

void call_dijkstra()
{
  dijkstra(0);
  cout << dist[1000] << endl;
  vi camino = find_path(1000);
  for(int i = 0; i < camino.size(); ++i)
  {
    cout << camino[i] << ' ';
  }
}


void setContainers(int graphSize)
{
  graph.assign(graphSize,vii());
  dist.assign(graphSize,INF);
  predecesor.assign(graphSize, -1);
}

void setDispatch(int dispatchSize)
{
  dispatch.assign(dispatchSize, vi());
}


void printDispatches(int dispatchSize)
{
  ofstream salida("salidaRepartidores.txt");
  for(int i = 0; i < dispatchSize; ++i )
  {
    salida << "Despacho " << i + 1 << endl;
    salida << " esquinas: ";
    for(int j  = 0; j < dispatch[i].size(); ++j)
    {
      salida << dispatch[i][j] << ' ';
    }
    salida << endl;
  }
  salida.close();
}

void printConexAndWeigth(int graphSize)
{
  ofstream salida("salidaGrafo.txt");

  for(int i = 0; i < graphSize; ++i )
  {
    if(graph[i].size() != 0)
    {
      salida << "nodo : " << i << " va a: (nodo, distancia) " << endl;
      for(int j = 0; j < graph[i].size(); ++j)
      {
        salida << graph[i][j].first << " ";
        salida << graph[i][j].second << " ";
        salida << endl;
      }
    }
  }
  salida.close();
}


void saveGraph(int vertex1, int vertex2,int weigth)
{
  graph[vertex1].push_back(edge(vertex2,weigth));
}

void readAndStore()
{
  int vertex1,vertex2,weigth;
  int totalDom,pointDom,graphSize;
  string Dompuntos;

  ifstream mapa("medellin_arcos.txt"); //cambiar esta linea por el nomre del archivo
  if(mapa.is_open())
  {
    mapa >> graphSize;
    setContainers(graphSize);

    while(mapa >> vertex1 >> vertex2 >> weigth)
    {
       saveGraph(vertex1,vertex2,weigth);
    }
    mapa.close();
  }

  ifstream domi("repartidores.txt");
  if(domi.is_open())
  {
    domi >> totalDom;
    setDispatch(totalDom);
    getline(domi, Dompuntos);
    for(int i = 0; i < totalDom; ++i)
    {

      getline(domi, Dompuntos);
      stringstream ss(Dompuntos);
      while(ss >> pointDom)
      {
        dispatch[i].push_back(pointDom);
      }

      // printConexAndWeigth(graphSize);
      // printDispatches(totalDom);   sirven para saber si guarda bien los datos
    }

  }
    domi.close();
}

int main()
{
  std::ios::sync_with_stdio(true);
  readAndStore();
  call_dijkstra();
  return 0;
}
