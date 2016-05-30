#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;
int size,disSize;

typedef pair <int, int> edge;
typedef vector <edge> vii;
typedef vector <int> vi;

vector <vii> graph;
vector <vi> dispatch;
vector <int> dist;
vector <int> predecesor;


void setContainers()
{
  graph.assign(size,vii());
  dist.assign(size,INF);
  predecesor.assign(size, -1);
}

void setDispatch(int dSize)
{
  dispatch.assign(dSize, vi());
}


void printDispatches()
{
  ofstream salida("salidaRepartidores.txt");
  for(int i = 0; i < disSize; ++i )
  {
    salida << "Despacho " << i + 1 << endl;
    salida << " esquinas: ";
    for(int j  = 0; j < dispatch[i].size(); ++j)
    {
      salida << dispatch[i][j] << ' ';
    }
    salida << endl;
  }
}

void printConexAndWeigth()
{
  ofstream salida("salidaGrafo.txt");

  for(int i = 0; i < size; ++i )
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
  int totalDom,pointDom;
  string Dompuntos;

  ifstream mapa("medellin_arcos.txt"); //cambiar esta linea por el nomre del archivo
  if(mapa.is_open())
  {
    mapa >> size;
    setContainers();

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
    disSize = totalDom;
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

    }

  }
    domi.close();
}

int main()
{
  std::ios::sync_with_stdio(true);
  readAndStore();
  printConexAndWeigth();
  printDispatches();
  return 0;
}
