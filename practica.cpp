#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16000;
bool visited[MAXN];
// typedef pair <int, int> edge;
// typedef pair<int, pair <double,double> > node_cordenadas;
typedef pair <int, int> edge;
vector < pair<int, int> > g[MAXN]; // para trabajaar mañan
map<int, double> coordinateXmap;
map<int, double> coordinateYmap;
int d[MAXN];
int p[MAXN];

void printCoordenadasX()
{
  for(map <int, double>::iterator it = coordinateXmap.begin();
  it != coordinateXmap.end(); ++it)
  {
    cout << it -> first << ": " << it -> second<< endl;
  }
}


void printCoordenadasY()
{
  for(map <int, double>::iterator it = coordinateYmap.begin();
  it != coordinateYmap.end(); ++it)
  {
    cout << it -> first << ": " << it -> second << endl;
  }
}

void storeCordenada(int vertex, int coordinateX,int coordinateY)
{
  coordinateXmap[vertex] = coordinateX;
  coordinateYmap[vertex] = coordinateY;
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
  double coordinateX,coordinateY;

  getline(cin,ignore); cout << ignore;
  //getline(cin,ignore); cout << ignore;
  while(scanf("%i %lf %lf",&vertex,&coordinateX,&coordinateY))
  {
    // printf( "vertice:%i, x = %.15g, y = %.15g\n", vertex, coordinateX,
    // coordinateY);
    storeCordenada(vertex, coordinateX,coordinateY);
  }
  //getline(cin,ignore); cout << ignore;
  getline(cin,ignore);cout << ignore;

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
  readFirstandStore();
  printCoordenadasX();
  printCoordenadasY();
  return 0;
}
