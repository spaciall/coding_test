// ConsoleApplication43.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& key)
{
    int K = key.size();
    vector<vector<int>> tmp(K, vector<int>(K, 0));
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            tmp[i][j] = key[K - (j + 1)][i];
        }
    }
    key = tmp;
}

bool is_fit(vector<vector<int>>& key, vector<vector<int>>& elock, size_t lock_size)
{
    size_t key_size = key.size();
    size_t elock_size = elock.size();
    for (size_t i = 0; i < elock_size - key_size; ++i)
    {
        for (size_t j = 0; j < elock_size - key_size; ++j)
        {
            // i, j가 시작점
            vector<vector<int>> copy_elock = elock;
            for (size_t k = 0; k < key_size; ++k)
            {
                for (size_t l = 0; l < key_size; ++l)
                {
                    if (i + k < lock_size || i + k >= 2 * lock_size || j + l < lock_size || j + l >= 2 * lock_size)
                    {
                        continue;
                    }
                    copy_elock[i + k][j + l] += key[k][l];
                }
            }
            bool flag = false;
            for (size_t k = 0; k < lock_size; ++k)
            {
                for (size_t l = 0; l < lock_size; ++l)
                {
                    if (copy_elock[k + lock_size][l + lock_size] != 1)
                    {
                        flag = true;
                        break;
                    }
                }
                if (flag)
                {
                    break;
                }
            }
            if (!flag)
            {
                return true;
            }
        }
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    size_t n = lock.size();
    vector<vector<int>> elock;
    elock.resize(n * 3);
    for (size_t i = 0; i < elock.size(); ++i)
    {
        elock[i].resize(n * 3, 0);
    }
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            elock[i + n][j + n] = lock[i][j];
        }
    }
    bool answer = false;
    for (int i = 0; i < 1; ++i)
    {
        if (is_fit(key, elock, n))
        {
            answer = true;
            break;
        }
        //rotate(key);
    }
    return answer;
}

int main()
{
    auto ret1 = solution({ {0, 1, 0,}, { 1, 0, 0,}, { 1, 0, 0,} }, {{1, 1, 1},{1, 1, 0},{1, 0, 1}});
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
