// Алгоритмы поиска в ширину и глубину.
//
// 7. Определить, существует ли маршрут между двумя заданными вершинами в неориентированном графе. 
// Граф в памяти представлять в виде матрицы.
// 
// Обход в глубину.
// Выполнили: Пятанин А., Коржов К., Ишутин М., Бурлаков В. (ПМ-93)
// Автор: Пятанин А.
// Рефакторинг: Коржов К.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>



bool doDfs(size_t sourceVertex, size_t targetVertex, const std::vector<std::vector<size_t>> &graph, std::vector<bool> &marks)
{
   if (sourceVertex == targetVertex)
      return true;
   marks[sourceVertex] = true;

   for (size_t iVertex = 0; iVertex < graph[sourceVertex].size(); iVertex++)
      if (!marks[iVertex] && graph[sourceVertex][iVertex])
         if (doDfs(iVertex, targetVertex, graph, marks))
            return true;

   return false;
}

int main()
{
   std::ios::sync_with_stdio(false);
   std::cin.tie(NULL);

   std::fstream in("in.txt");
   std::ofstream out("out.txt");

   size_t vertexCount = 0;
   in >> vertexCount;
   std::vector<std::vector<size_t>> graph(vertexCount, std::vector<size_t>(vertexCount, -1));

   for (size_t i = 0; i < vertexCount; i++)
      for (size_t j = 0; j < vertexCount; j++)
         in >> graph[i][j];

   size_t sourceVertex = 0, targetVertex = 0;
   in >> sourceVertex >> targetVertex;
   sourceVertex--;
   targetVertex--;

   std::vector<bool> marks(graph[sourceVertex].size(), false);
   
   auto startTime = std::chrono::high_resolution_clock::now();

   bool routeFound = doDfs(sourceVertex, targetVertex, graph, marks);
   
   auto endTime = std::chrono::high_resolution_clock::now() - startTime;
   auto elapsedTime = std::chrono::duration<double>(endTime).count();

   if (routeFound)
      out << "Route exists." << std::endl;
   else
      out << "Route is absent." << std::endl;

   out << "Algorithm time is " << elapsedTime << " seconds."<<std::endl;

   return 0;
}

