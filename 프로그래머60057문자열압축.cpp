#include <string>
#include <vector>

using namespace std;

int repeat_count_to_len(int repeat)
{
    if (repeat < 10)
    {
        return 1;
    }
    else if (repeat < 100)
    {
        return 2;
    }
    else if (repeat < 1000)
    {
        return 3;
    }
    return 4;
}

int len_by_repeat_and_i(int repeat, int i)
{
    int ret;
    if (repeat == 1)
    {
        ret = i;
    }
    else
    {
        ret = repeat_count_to_len(repeat) + i;
    }
    return ret;
}

int solution(string s)
{
    int answer = s.size();
    for (int i = 1; i <= s.size(); i++)
    {
        int pos = i;
        int repeat = 1;
        int answer_to_i = 0;
        int debug_count = 0;
        string last_string = s.substr(0, i);
        while (pos < s.size())
        {
            string sub_str_to_this_time = s.substr(pos, i);
            if (last_string == sub_str_to_this_time)
            {
                // 일치한다.
                repeat++;
            }
            else
            {
                // 일치하지 않는다.
                answer_to_i += len_by_repeat_and_i(repeat, i);
                last_string = sub_str_to_this_time;
                repeat = 1;
            }
            pos += i;
            debug_count++;
        }
        answer_to_i += len_by_repeat_and_i(repeat, i - (pos - s.size()));
        if (answer_to_i < answer)
        {
            answer = answer_to_i;
        }
    }
    return answer;
}
