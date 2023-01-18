// ConsoleApplication35.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> sum_vec;

int solution(vector<int> cookie) {
    sum_vec.resize(cookie.size() + 1);
    int sum = 0;
    sum_vec[0] = 0;
    for (size_t i = 0; i < cookie.size(); ++i)
    {
        sum += cookie[i];
        sum_vec[i + 1] = sum;
    }
    // l < m < r
    int max_answer = 0;
    for (int l = 0; l < sum_vec.size() - 2; ++l)
    {
        for (int m = l; m < sum_vec.size() - 1; ++m)
        {
            for (int r = m + 1; r < sum_vec.size(); ++r)
            {
                int left_sum = sum_vec[m] - sum_vec[l];
                int right_sum = sum_vec[r] - sum_vec[m];
                if (left_sum == right_sum)
                {
                    if (max_answer < left_sum)
                    {
                        max_answer = left_sum;
                    }
                }
            }
        }
    }
    int answer = max_answer;
    return answer;
}

int main()
{
    int ret1 = solution({1, 1, 2, 3});
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
