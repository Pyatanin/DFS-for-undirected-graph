// Алгоритмы поиска в ширину и глубину.
//
// 7. Определить, существует ли маршрут между двумя заданными вершинами в неориентированном графе. 
// Граф в памяти представлять в виде матрицы.
// 
// Выполнили: Пятанин А., Коржов К., Ишутин М., Бурлаков В. (ПМ-93)
// Автор: Пятанин А.

#include <iostream>
#include <iomanip>
#include <chrono>
#include <vector>

std::vector<bool> marks;

void doDfs(size_t source, const std::vector<std::vector<double>> &graph)
{
   marks[source] = true;
   for (size_t i = 0; i < graph[source].size(); i++)
      if (!marks[graph[source][i]])
         doDfs(graph[source][i], graph);
}

int main()
{
   std::ios::sync_with_stdio(false);
   std::cin.tie(NULL);

   size_t n = 0; 
   std::cin >> n;
   std::vector<std::vector<double>> graph(n, std::vector<double>(n, -1));

   for (size_t i = 0; i < n; i++)
   {
      for (size_t j = 0; j < n; j++)
      {
         size_t weight = 0;
         std::cin >> weight;
         graph[i][j] = weight;
         graph[j][i] = weight;
      }
   }

   size_t source = 0, destination = 0;
   std::cin >> source >> destination;

   marks.assign(n, false);

   auto startTime = std::chrono::high_resolution_clock::now();

   doDfs(source - 1, graph);
   if (!marks[destination - 1])
      std::cout << "Route is absent.\n";
   else
      std::cout << "Route exists.\n";

   auto endTime = std::chrono::high_resolution_clock::now() - startTime;
   auto elapsedTime = std::chrono::duration<double>(endTime).count();
   
   std::cout << "Algorithm time is " <<elapsedTime << " seconds.\n";

   return 0;
}
