#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<bool> marks;

// Программа находит первый попавшийся ей маршрут, и выводит его сразу в подпрограмма, еси его нет то выведет соответствено
// Можно конечно запариться и сделать еще чтобы находила минимальный маршрут, но в задании такого нетy
int doDfs(int A, int B, const vector<vector<double>> &graph)
{
   marks[A] = true;
   if (A != B)
   {
      for (int i = 0; i < graph[A].size(); ++i)
      {
         if (graph[A][i] != -1 && !marks[i])
            if (doDfs(i, B, graph))
            {
               cout << "<-" << A + 1; // +1 потому что в векторе с 0
               return 1;
            }
      }
      return 0;
   }
   else
   {
      cout << "route: " << B + 1; // +1 потому что в векторе с 0
      return 1;
   }
}

int main()
{
   int n, A, B; //n-число вершин, из пункта А в пункт В
   cin >> n >> A >> B;

   vector<vector<double>> matrix(n, vector<double>(n, -1)); //храним информацию о ребрах
   int a, b;
   double w = 2;
   while (cin >> a >> b)
   {
      matrix[a - 1][b - 1] = w; // -1 потому что в векторе с 0
      matrix[b - 1][a - 1] = w;
   }

   for (int i = 0; i < matrix.size(); ++i)
   {
      for (int j = 0; j < matrix[i].size(); ++j)
      {
         cout << matrix[i][j] << '\t';
      }
      cout << endl;
   }

   marks.assign(n, false);
   if (!(doDfs(A - 1, B - 1, matrix))) // -1 потому что в векторе с 0
      cout << "route is absent";
   cout << endl;
}