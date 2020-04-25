// Àëãîðèòìû ïîèñêà â øèðèíó è ãëóáèíó.
//
// 7. Îïðåäåëèòü, ñóùåñòâóåò ëè ìàðøðóò ìåæäó äâóìÿ çàäàííûìè âåðøèíàìè â íåîðèåíòèðîâàííîì ãðàôå. 
// Ãðàô â ïàìÿòè ïðåäñòàâëÿòü â âèäå ìàòðèöû.
// 
// Âûïîëíèëè: Ïÿòàíèí À., Êîðæîâ Ê., Èøóòèí Ì., Áóðëàêîâ Â. (ÏÌ-93)
// Àâòîð: Ïÿòàíèí À.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <vector>

std::vector<bool> marks;

void doDfs(size_t source, size_t destination, const std::vector<std::vector<double>> &graph)
{
   marks[source] = true;
   for (size_t i = 0; i < graph[source].size() && marks[destination] != true; i++) // Такое условие чтобы не просматривал
      if (!marks[i] && graph[source][i]!= 0)                                       //  все вершины если уже нашел путь.
         doDfs(i, destination, graph);
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
      for (size_t j = 0; j < n; j++)
         in >> graph[i][j];

   size_t source = 0, destination = 0;
   in >> source >> destination;
   source--;
   destination--;

   marks.assign(n, false);

   auto startTime = std::chrono::high_resolution_clock::now();
   doDfs(source, destination, graph);
   auto endTime = std::chrono::high_resolution_clock::now() - startTime;
   auto elapsedTime = std::chrono::duration<double>(endTime).count();

   if (marks[destination])
      out << "Route exists.\n";
   else
      out << "Route is absent.\n";

   out << "Algorithm time is " << elapsedTime << " seconds."<<std::endl;

   return 0;
}

