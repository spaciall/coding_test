// ConsoleApplication36.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

map<int, map<int, int>> g_cost_map;
map<int, map<int, int>> g_min_cost_map;

void dijkstra(int sv)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0, sv });
    while (!pq.empty())
    {
        auto pair = pq.top();
        pq.pop();
        int cost = -pair.first;
        int v = pair.second;
        if (g_min_cost_map[sv][v] < cost)
        {
            continue;
        }
        for (auto iter = g_cost_map[v].begin(); iter != g_cost_map[v].end(); ++iter)
        {
            int nv = iter->first;
            int nv_cost = iter->second;
            int new_cost = cost + nv_cost;
            if (new_cost < g_min_cost_map[sv][nv])
            {
                g_min_cost_map[sv][nv] = new_cost;
                pq.push({ -new_cost, nv });
            }
        }
    }
}

void init(int n, vector<vector<int>>& fares)
{
    for (int i = 0; i < n + 1; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            g_min_cost_map[i][j] = (int)1e8;
        }
    }
    for (auto& fare : fares)
    {
        int v1 = fare[0];
        int v2 = fare[1];
        int cost = fare[2];
        g_cost_map[v1][v2] = cost;
        g_cost_map[v2][v1] = cost;
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    // 초기화
    init(n, fares);
    // 계산
    for (int i = 1; i <= n; ++i)
    {
        dijkstra(i);
    }
    for (int i = 1; i <= n; ++i)
    {
        g_min_cost_map[i][i] = 0;
    }
    // 1. s -> i -> a
    // 2. s -> i -> b
    int min_cost = (int)1e8;
    for (int i = 1; i <= n; ++i)
    {
        int cost = g_min_cost_map[s][i] + g_min_cost_map[i][a] + g_min_cost_map[i][b];
        if (min_cost > cost)
        {
            min_cost = cost;
        }
    }
    // 결과
    int answer = min_cost;
    return answer;
}

int main()
{
    solution(6, 4, 6, 2, {{4, 1, 10}, { 3, 5, 24 }, { 5, 6, 2 }, { 3, 1, 41 }, { 5, 1, 24 }, { 4, 6, 50 }, { 2, 4, 66 }, { 2, 3, 22 }, { 1, 6, 25 }});
    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
