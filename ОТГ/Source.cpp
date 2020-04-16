#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<bool> marks;

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
               cout << "<-" << A + 1;
               return 1;
            }
      }
      return 0;
   }
   else
   {
      cout << "route: " << B + 1; 
      return 1;
   }
}

int main()
{
   int n, A, B; 
   cin >> n >> A >> B;

   vector<vector<double>> matrix(n, vector<double>(n, -1)); 
   int a, b;
   double w = 2;
   while (cin >> a >> b)
   {
      matrix[a - 1][b - 1] = w; 
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
   if (!(doDfs(A - 1, B - 1, matrix)))
      cout << "route is absent";
   cout << endl;
}
