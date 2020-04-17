// Алгоритмы поиска в ширину и глубину.
//
// 7. Определить, существует ли маршрут между двумя заданными вершинами в неориентированном графе. 
// Граф в памяти представлять в виде матрицы.
// 
// Выполнили: Пятанин А., Коржов К., Ишутин М., Бурлаков В. (ПМ-93)
// Автор: Пятанин А.

#include <iostream>
#include <iomanip>
#include <vector>

std::vector<bool> marks;

bool doDfs(size_t source, size_t destination, const std::vector<std::vector<double>> &graph)
{
   marks[source] = true;
   if (source != destination)
   {
      for (size_t i = 0; i < graph[source].size(); ++i)
      {
         if (graph[source][i] != -1 && !marks[i])
            if (doDfs(i, destination, graph))
            {
               std::cout << "<-" << source + 1; //не нравится
               return 1;
            }
      }

      return false;
   }
   else
   {
      std::cout << "route: " << destination + 1; //не нравится
      return true;
   }
}

int main()
{
   size_t n, source, destination; 
   std::cin >> n >> source >> destination;

   std::vector<std::vector<double>> graph(n, std::vector<double>(n, -1)); 
   size_t a, b;
   double w = 2.;
   while (std::cin >> a >> b)
   {
      graph[a - 1][b - 1] = w; 
      graph[b - 1][a - 1] = w;
   }

   for (size_t i = 0; i < graph.size(); ++i)
   {
      for (size_t j = 0; j < graph[i].size(); ++j)
      {
         std::cout << graph[i][j] << '\t';
      }
      std::cout << std::endl;
   }

   marks.assign(n, false);
   if (!(doDfs(source - 1, destination - 1, graph)))
      std::cout << "Route is absent" << std::endl;

   return 0;
}
