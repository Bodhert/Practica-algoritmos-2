#include <bits/stdc++.h>
using namespace std;


struct Coordenadas
{
  char coordinatex [30];
  char coordinatey [30];
};


const int MAXN = 16000;
const int MAXDIS = 30;
const int INF = 1 << 30;

bool visited[MAXN];

typedef pair <int, int> edge;
vector < pair<int, int> > g[MAXN];
map <int, Coordenadas> cordinates;

int d[MAXN];
int p[MAXN];
int dis[MAXDIS][MAXDIS];


void setContainers()
{
  for(int i = 0; i < MAXN; ++i)
  {
    d[i] = INF;
    p[i] = -1;
    g[i].clear();
  }

  for (int i = 0; i < MAXDIS; ++i)
    for(int j = 0; j < MAXDIS; ++j)
      dis[i][j] = INF;
}

void printConexAndWeigth()
{
  for(int i = 0; i < MAXN; ++i )
  {
    if(g[i].size() != 0){
      cout << "nodo : " << i << " va a: (nodo, distancia) " << endl;
      for(int j = 0; j < g[i].size(); ++j)
      {
        cout << g[i][j].first << " ";
        cout << g[i][j].second << " ";
        cout << endl;
      }
    }
  }
}

void printCordenadas()
{

for(map <int,Coordenadas>:: iterator it = cordinates.begin(); it !=
 cordinates.end(); ++it)
 {
   cout <<" nodo: " << it -> first << " x = " << it -> second.coordinatex << " y = "
   << it -> second.coordinatey << endl;
 }
}

void storeCordenada(int vertex, char *coordinateX,char *coordinateY)
{
  struct Coordenadas c;

//cout << vertex << " " << c.coordinatex << " " << c.coordinatey << endl;
  strcpy(c.coordinatex,coordinateX);
  strcpy(c.coordinatey,coordinateY);

  cordinates[vertex] = c;

  //cout << vertex << " " << c.coordinatex << " " << c.coordinatey << endl;
}

void saveGraph(int vertex1, int vertex2,int weigth)
{
  g[vertex1].push_back(edge(vertex2,weigth));
}

void readFirstandStore()
{
  string ignore;
  char tmp[100];
  int vertex,vertex1,vertex2,weigth;
  char coordinateX[20],coordinateY[20];

  getline(cin,ignore); cout << ignore << endl;
  //getline(cin,ignore); cout << ignore;
  while(scanf("%i %s %s",&vertex, coordinateX, coordinateY))
  {
    // printf( "vertice:%i, x = %.15g, y = %.15g\n", vertex, coordinateX,
    // coordinateY);
    storeCordenada(vertex, coordinateX,coordinateY);
  }
  //getline(cin,ignore); cout << ignore;
  getline(cin,ignore);cout << ignore << endl;

  while(scanf("%i %i %i",&vertex1,&vertex2,&weigth) != EOF)
  {
    // printf( "vertice : %i, apunta a: %i, con peso de: %i\n", vertex1, vertex2,
    // weigth);
    saveGraph(vertex1,vertex2,weigth);
  }

}

int main()
{
  std::ios::sync_with_stdio(true);
  setContainers();
  readFirstandStore();
  //printCordenadas();
  //printConexAndWeigth();
  return 0;
}
