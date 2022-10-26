//
// Created by donglijian on 10/26/22.
//

//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
bool BoxObjectMatch(const int i, std::vector<int > &indexes, bool visited[], const std::vector<std::vector<float>> &iouMap);
bool BoxObjectMatch(const int i, std::vector<int > &indexes, bool visited[], const std::vector<std::vector<float>> &iouMap)
{
    for (int j = 0; j < iouMap[0].size(); ++j)
        if (iouMap[i][j] > 0 && !visited[j]) //有边且未访问
        {
            visited[j] = true;                 //记录状态为访问过
            if (indexes[j] == -1 || BoxObjectMatch(indexes[j], indexes, visited, iouMap)) //如果暂无匹配，或者原来匹配的左侧元素可以找到新的匹配
            {
                indexes[j] = i;    //当前左侧元素成为当前右侧元素的新匹配
                return true; //返回匹配成功
            }
        }
    return false; //循环结束，仍未找到匹配，返回匹配失败
}

void Hungarian(const std::vector<std::vector<float>> &iouMap, std::vector<int> &indexes)
{
    const int boxSize = iouMap.size();
    if (boxSize > 0)
    {
        const int objectSize = iouMap[0].size();
        if (objectSize > 0)
        {
            indexes.resize(objectSize, -1);
            bool visited[objectSize];

            for (int i = 0; i < boxSize; ++i)
            {
                memset(&visited[0], false, iouMap[0].size() * sizeof(visited[0]));
                BoxObjectMatch(i, indexes, visited, iouMap);
            }
        }
    }
}
int main()
{
    std::vector<std::vector<float>> iouMap;
    std::vector<int> indexes;

    iouMap.push_back({0.2, 0.5, 0.7,5});
    iouMap.push_back({0, 0, 1,5});
    iouMap.push_back({1, 1, 0,5});

    Hungarian(iouMap,indexes);
    for (int i = 0; i < indexes.size(); ++i)
    {
        std::cout << indexes[i] <<std::endl;
    }
}