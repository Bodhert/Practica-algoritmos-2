#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300010;
vector<int> g[MAXN];
bool visited[MAXN];


void readFirstandStore()
{
  string ignore;
  char tmp[100];
  int vertex,vertex1,vertex2,weigth;
  double coordinateX,coordinateY;

  getline(cin,ignore); cout << ignore;
  getline(cin,ignore); cout << ignore;
  while(scanf("%i %lf %lf",&vertex,&coordinateX,&coordinateY))
  {
    printf( "vertice:%i, x = %.15g, y = %.15g\n", vertex, coordinateX,
    coordinateY);
  }
  //getline(cin,ignore); cout << ignore;
  getline(cin,ignore);cout << ignore;

  while(scanf("%i %i %i",&vertex1,&vertex2,&weigth) != EOF)
  {
    printf( "vertice : %i, apunta a: %i, con peso de: %i\n", vertex1, vertex2,
    weigth);
  }

}

int main()
{
  std::ios::sync_with_stdio(true);
  readFirstandStore();
  return 0;
}
