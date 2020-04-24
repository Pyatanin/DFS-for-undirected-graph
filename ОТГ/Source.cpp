// Алгоритмы поиска в ширину и глубину.
//
// 7. Определить, существует ли маршрут между двумя заданными вершинами в неориентированном графе. 
// Граф в памяти представлять в виде матрицы.
// 
// Выполнили: Пятанин А., Коржов К., Ишутин М., Бурлаков В. (ПМ-93)
// Автор: Пятанин А.

#include <iostream>
#include <fstream>
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

   std::fstream in("in.txt");
   std::ofstream out("out.txt");

   size_t n = 0;
   in >> n;
   std::vector<std::vector<double>> graph(n, std::vector<double>(n, -1));

   for (size_t i = 0; i < n; i++)
   {
      for (size_t j = 0; j < n; j++)
      {
         size_t weight = 0;
         in >> weight;
         graph[i][j] = weight;
         graph[j][i] = weight;
      }
   }

   size_t source = 0, destination = 0;
   in >> source >> destination;

   marks.assign(n, false);

   auto startTime = std::chrono::high_resolution_clock::now();
   doDfs(source - 1, graph);
   auto endTime = std::chrono::high_resolution_clock::now() - startTime;
   auto elapsedTime = std::chrono::duration<double>(endTime).count();

   if (!marks[destination - 1])
      out << "Route is absent.\n";
   else
      out << "Route exists.\n";

   out << "Algorithm time is " << elapsedTime << " seconds."<<std::endl;

   return 0;
}

