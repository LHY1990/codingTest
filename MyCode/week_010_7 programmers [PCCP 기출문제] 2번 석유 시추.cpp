// https://school.programmers.co.kr/learn/courses/30/lessons/250136

#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

constexpr int OIL = 1;

void bfs(const vector<vector<int>>& _land, bool* _visited, const int& _x, const int& _y, vector<pair<int, int>>& _posList, const int& _maxX, const int& _maxY)
{
   if (_y >= _maxY || _y < 0)
      return;

   if (_x >= _maxX || _x < 0)
      return;
    
    if (true == _visited[_maxX * _y + _x])
      return;

   // 방문 기록
   _visited[_maxX * _y + _x] = true;

   if (_land.at(_y).at(_x) == OIL)
      _posList.push_back(pair<int, int>(_x, _y));
   else
      return;

   bfs(_land, _visited, _x + 1, _y, _posList, _maxX, _maxY);
   bfs(_land, _visited, _x - 1, _y, _posList, _maxX, _maxY);
   bfs(_land, _visited, _x, _y + 1, _posList, _maxX, _maxY);
   bfs(_land, _visited, _x, _y - 1, _posList, _maxX, _maxY);
}

vector<vector<pair<int, int>>> findByLine(const vector<vector<int>>& _land, const int& _fixedX, bool* _visited, const int& _maxX, const int& _maxY)
{
   auto outList = vector<vector<pair<int, int>>>(0);
   
   for (int y = 0; y < _maxY; ++y)
   {
      if (true == _visited[y * _maxX + _fixedX])
         continue;

      //오일이면 탐색
      auto posList = vector<pair<int, int>>(0);
      if (_land.at(y).at(_fixedX) == OIL)
         bfs(_land, _visited, _fixedX, y, posList, _maxX, _maxY);

      //탐색한 결과가 있다면 리스트에 추가
      if (false == posList.empty())
         outList.push_back(posList);
   }

   return outList;
}

int solution(vector<vector<int>> land) {
   const int maxY = land.size();
   const int maxX = land.at(0).size();

   auto allSearchedList = vector<vector<pair<int, int>>>(0);

   bool* visited = new bool[maxY * maxX];
   for (int i = 0; i < maxY * maxX; ++i)
      visited[i] = false;

   // 아래로 내려가면서 검색합니다.
   vector<vector<pair<int, int>>> currentList;

   for (int x = 0; x < maxX; ++x)
   {
      currentList = findByLine(land, x, visited, maxX, maxY);
      if (false == currentList.empty())
         allSearchedList.insert(allSearchedList.end(), currentList.begin(), currentList.end());
   }

   delete[] visited;

    
   auto findMap = map<int, set<int>>(); // index, x set
   int index = 0;
   for (const auto& singlePairList : allSearchedList)
   {
      findMap[index] = set<int>();

      for (const auto& singlePair : singlePairList)
         findMap[index].insert(singlePair.first);

      ++index;
   }


   int temp = 0;
   int max = 0;
   
   for (int x = 0; x < maxX; ++x)
   {
      temp = 0;
      index = 0;
      for (const auto& singleMap : findMap)
      {
         if (singleMap.second.find(x) != singleMap.second.end())
         {
            temp += allSearchedList.at(index).size();
         }
         ++index;
      }

      if (max < temp) 
         max = temp;
   }
   

   return max;
}