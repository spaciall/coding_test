// ConsoleApplication39.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <assert.h>

using namespace std;

vector<vector<int>> g_board;
vector<vector<int>> g_cost;
set<pair<int, int>> g_visit;
int g_min_cost = 1e8;
int g_m = 0;
int g_n = 0;
int g_dx[4] = {1, -1, 0, 0}; // 0 ~ 1 가로, 2 ~ 3 세로
int g_dy[4] = {0, 0, 1, -1};
int g_stright_cost = 100;
int g_corner_cost = 500;

enum state_e
{
    none = 0,
    horizontal,
    vertical, 
};

void dfs(int x, int y, int cost, state_e state, int step)
{
    if (g_cost[y][x] + g_stright_cost * 1 < cost)
    {
        return;
    }
    else
    {
        g_cost[y][x] = cost;
    }
    if (x == g_m - 1 && y == g_n - 1)
    {
        if (g_min_cost > cost)
        {
            g_min_cost = cost;
        }
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + g_dx[i];
        int ny = y + g_dy[i];
        if (nx < 0 || ny < 0 || nx >= g_m || ny >= g_n)
        {
            continue;
        }
        if (g_board[ny][nx])
        {
            continue;
        }
        if (g_visit.count(make_pair(ny, nx )) > 0)
        {
            continue;
        }
        if (state == state_e::none)
        {
            g_visit.insert(make_pair(ny, nx));
            if (i == 0 || i == 1)
            {
                dfs(nx, ny, cost + g_stright_cost, state_e::horizontal, step + 1);
            }
            else
            {
                dfs(nx, ny, cost + g_stright_cost, state_e::vertical, step + 1);
            }
            g_visit.erase(make_pair(ny, nx));
        }
        else if (state == state_e::horizontal)
        {
            g_visit.insert(make_pair(ny, nx));
            if (i == 0 || i == 1)
            {
                dfs(nx, ny, cost + g_stright_cost, state_e::horizontal, step + 1);
            }
            else
            {
                dfs(nx, ny, cost + g_stright_cost + g_corner_cost, state_e::vertical, step + 1);
            }
            g_visit.erase(make_pair(ny, nx));
        }
        else if (state == state_e::vertical)
        {
            g_visit.insert(make_pair(ny, nx));
            if (i == 0 || i == 1)
            {
                dfs(nx, ny, cost + g_stright_cost + g_corner_cost, state_e::horizontal, step + 1);
            }
            else
            {
                dfs(nx, ny, cost + g_stright_cost, state_e::vertical, step + 1);
            }
            g_visit.erase(make_pair(ny, nx));
        }
        else
        {
            assert(false);
        }
    }
}

int solution(vector<vector<int>> board) 
{
    // 초기화
    g_board = move(board);
    g_n = g_board.size();
    g_m = g_board[0].size();
    g_min_cost = 1e8;
    g_cost.clear();
    g_cost.resize(g_n);
    for (int i = 0; i < g_n; ++i)
    {
        g_cost[i].resize(g_m);
        for (int j = 0; j < g_m; ++j)
        {
            g_cost[i][j] = 1e8;
        }
    }
    g_visit.insert({ 0, 0 });
    dfs(0, 0, 0, state_e::none, 1);
    dfs(0, 0, 0, state_e::none, 1);
    g_visit.erase(make_pair( 0, 0 ));
    int answer = g_min_cost;
    return answer;
}

int main()
{
    int ret1 = solution({ {0, 0, 0},{0, 0, 0},{0, 0, 0} });
    int ret2 = solution({ {0, 0, 0, 0, 0, 0, 0, 1},{0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 1, 0, 0},{0, 0, 0, 0, 1, 0, 0, 0},{0, 0, 0, 1, 0, 0, 0, 1},{0, 0, 1, 0, 0, 0, 1, 0},{0, 1, 0, 0, 0, 1, 0, 0},{1, 0, 0, 0, 0, 0, 0, 0} });
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
