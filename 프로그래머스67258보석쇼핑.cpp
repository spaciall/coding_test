// ConsoleApplication16.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	vector<pair<int, int>> candidate;
	set<string> gems_set;
	map<string, int> gems_map;
	for (size_t i = 0; i < gems.size(); ++i)
	{
		gems_set.insert(gems[i]);
	}
	size_t pos_s = 0;
	size_t pos_e = 0;
	size_t last_pos_e = 0;
	for (size_t i = 0; i < gems.size(); ++i)
	{
		pos_s = i;
		if (pos_s > pos_e)
		{
			break;
		}
		for (pos_e = last_pos_e; pos_e < gems.size(); ++pos_e)
		{
			gems_map[gems[pos_e]]++;
			if (gems_map.size() == gems_set.size())
			{
				candidate.push_back({pos_s + 1, pos_e + 1});
				break;
			}
		}
		if (pos_e >= gems.size())
		{
			pos_e = gems.size() - 1;
		}
		last_pos_e = pos_e;
		gems_map[gems[pos_e]]--;
		if (gems_map[gems[pos_e]] <= 0)
		{
			gems_map.erase(gems[pos_e]);
		}
		gems_map[gems[pos_s]]--;
		if (gems_map[gems[pos_s]] <= 0)
		{
			gems_map.erase(gems[pos_s]);
		}
	}
	sort(candidate.begin(), candidate.end(), [](pair<int, int> a, pair<int, int> b) {
		assert(a.first <= a.second);
		assert(b.first <= b.second);
		int diff_a = a.second - a.first;
		int diff_b = b.second - b.first;
		if (diff_a > diff_b)
		{ 
			return true;
		}
		else if (diff_a == diff_b)
		{
			if (a.first > b.first)
			{
				return true;
			}
			return false;
		}
		return false;
	});
	return answer = { candidate[candidate.size() - 1].first, candidate[candidate.size() - 1].second};
}

int main()
{
	auto ret1 = solution({ "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	auto ret2 = solution({ "AA", "AB", "AC", "AA", "AC" });
	auto ret3 = solution({ "XYZ", "XYZ", "XYZ" });
	auto ret4 = solution({ "ZZZ", "YYY", "NNNN", "YYY", "BBB" });
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
