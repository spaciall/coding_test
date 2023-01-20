// ConsoleApplication34.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;

struct edge
{
	edge()
	{
		s = e = -1;
	}
	edge(int s, int e)
	{
		this->s = s;
		this->e = e;
	}
	bool operator < (const edge& rhs) const
	{
		if (s < rhs.s)
		{
			return true;
		}
		else if (s == rhs.s)
		{
			if (e < rhs.e)
			{
				return true;
			}
		}
		return false;
	}
	int s;
	int e;
};

map<edge, int> g_edge_map;
multimap<int, edge> g_cost_map;
set<int> g_vertex_set;
vector<int> g_parent_vec;
int g_n;

// union-find
int parent(int v)
{
	if (g_parent_vec[v] == v) 
	{
		return v;
	}
	return parent(g_parent_vec[v]);
}

void merge(int v1, int v2)
{
	int pv1 = parent(v1);
	int pv2 = parent(v2);
	if (pv1 < pv2)
	{
		g_parent_vec[pv1] = pv2;
	}
	else if (pv1 > pv2)
	{
		g_parent_vec[pv2] = pv1;
	}
	else
	{
		// pv1 == pv2
		return;
	}
}

int solution(int n, vector<vector<int>> costs) {
	// 초기화
	g_n = n;
		g_parent_vec.resize(g_n);
	for (size_t i = 0; i < g_parent_vec.size(); ++i)
	{
		g_parent_vec[i] = i;
	}
	// 실행
	for (vector<int>& cost : costs)
	{
		edge e;
		e.s = cost[0];
		e.e = cost[1];
		g_edge_map.insert(make_pair(e, cost[2]));
		g_cost_map.insert(make_pair(cost[2], e));
	}
	int cost_sum = 0;
	for (auto iter = g_cost_map.begin(); iter != g_cost_map.end(); ++iter)
	{
		int cost = iter->first;
		auto& edge = iter->second;
		int s = edge.s;
		int e = edge.e;
		if (parent(s) != parent(e))
		{
			merge(s, e);
			cost_sum += cost;
		}
		else
		{
			break;
		}
	}
	// 결과
	int answer = cost_sum;
	return answer;
}

int main()
{
	solution(4, { {0, 1, 1},{0, 2, 2},{1, 2, 5},{1, 3, 1},{2, 3, 8} });
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
