// ConsoleApplication33.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g_sticker;

// dp[i] = max(dp[i] + dp[i + 2], dp[i] + dp[i + 3])
int caching_1[100000 + 1] = { 0, };
int caching_2[100000 + 1] = { 0, };
int caching_3[100000 + 1] = { 0, };

int dp_1(int index)
{
	if (index > (int)g_sticker.size() - 2)
	{
		return 0;
	}
	if (caching_1[index] > 0)
	{
		return caching_1[index];
	}
	int sum_1 = g_sticker[index] + dp_1(index + 2);
	int sum_2 = g_sticker[index] + dp_1(index + 3);
	if (caching_1[index] < max(sum_1, sum_2))
	{
		caching_1[index] = max(sum_1, sum_2);
	}
	return max(sum_1, sum_2);
}

int dp_2(int index)
{
	if (index > (int)g_sticker.size() - 1)
	{
		return 0;
	}
	if (caching_2[index] > 0)
	{
		return caching_2[index];
	}
	int sum_1 = g_sticker[index] + dp_2(index + 2);
	int sum_2 = g_sticker[index] + dp_2(index + 3);
	if (caching_2[index] < max(sum_1, sum_2))
	{
		caching_2[index] = max(sum_1, sum_2);
	}
	return max(sum_1, sum_2);
}

int dp_3(int index)
{
	if (index > (int)g_sticker.size())
	{
		return 0;
	}
	if (caching_3[index] > 0)
	{
		return caching_3[index];
	}
	int sum_1 = g_sticker[index] + dp_3(index + 2);
	int sum_2 = g_sticker[index] + dp_3(index + 3);
	if (caching_3[index] < max(sum_1, sum_2))
	{
		caching_3[index] = max(sum_1, sum_2);
	}
	return max(sum_1, sum_2);
}

int solution(vector<int> sticker)
{
	// 초기화
	g_sticker = std::move(sticker);
	// 실행
	if (g_sticker.size() == 1)
	{
		return g_sticker[0];
	}
	int sum_1 = dp_1(0);
	int sum_2 = dp_2(1);
	int sum_3 = dp_2(2);
	// 결과
	int answer = max(max(sum_1, sum_2), sum_3);
	return answer;
}

int main()
{
	//auto ret1 = solution({14, 6, 5, 11, 3, 9, 2, 10});
	auto ret2 = solution({5, 1, 16, 17, 16});
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
