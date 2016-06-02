#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
int size,disSize;

typedef pair <int, int> edge;
typedef vector <edge> vii;
typedef vector <int> vi;
typedef pair <int,int> dist_node; //datos del heap (nodo, distancia)

vector <vii> graph;
vector <vi> dispatch;
vector <int> dist;
vector <int> predecesor;
vector <vii> Node_dis;


void printDistances()
{
  for(int i = 0; i < Node_dis.size(); i++)
  {
    if(Node_dis[i].size() > 0) cout << "Distancia del nodo " << i << " al " << endl;
    for(int j = 0 ; j < Node_dis[i].size(); ++j)
    {
      cout << "Nodo: " << Node_dis[i][j].first << " Distancia: " << Node_dis[i][j].second << endl;
    }
  }
}

void dijkstra(int source)
{
  priority_queue <dist_node ,vector <dist_node> , greater <dist_node> > q;
  dist.assign(graph.size(),INF);
  //limpiar predecesor

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

void solve(int root)
{
  cout << " raiz: " << root << endl;
  vi dist;
  dist.assign(graph.size(), -1);
  queue <int> q;
  dist[root] = 1;
  q.push(root);

  while(!q.empty())
  {
    int cur = q.front() ; q.pop();
    int next = -1;
    int dis = INF;
    for(int i = 0 ; i < Node_dis[cur].size(); ++i)
    {
      int tempnext =  Node_dis[cur][i].first;
      int tempdist =  Node_dis[cur][i].second;

      if(tempdist < dis && dist[tempnext] == -1)
      {
        dis = tempdist;
        next = tempnext;
      }
    }

    if(next != -1)
    {
      if(dist[next] == -1)
      {
        cout << " ganador " << next;
        dist[next] = 1;
        q.push(next);
      }
    }
  }

}

void call_dijkstra()
{
  int root;

  for(int i = 0; i < dispatch.size(); ++i)
  {
     cout << " despacho # "  << i + 1 << endl;
    for(int j = 0; j < dispatch[i].size(); ++j)
    {
      if(j == 0 ) root = dispatch[i][j];

      int cur = dispatch[i][j];
      dijkstra(cur);
      // cout << "current: "<< cur << " " << endl;
      for(int l = 0; l < dispatch[i].size(); ++l)
      {
        int next = dispatch[i][l];
        if( next !=  cur)
        {
          int actdist = dist[next];
          // cout << " metiendo en la pos " << cur  << " indice: " << next <<
          //  " un distancia de: " << actdist << ' ' << endl;
          Node_dis[cur].push_back(edge(next,actdist));
        }
      }
    }
    printDistances();
    solve(root); // THE MAGIC IS HERE
    //llamar a una funcion que se encargue de encotrame el menor
    Node_dis.assign(graph.size(), vii());
    //setear solo los elementos del dijstra del despacho no  todo otra vez
    cout << endl;
  }

}


void setContainers(int graphSize)
{
  graph.assign(graphSize,vii());
  dist.assign(graphSize,INF);
  predecesor.assign(graphSize, -1);
  Node_dis.assign(graphSize,vii());
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
