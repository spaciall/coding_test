from typing import List

class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        time: List[int] = []

        for dist_elem, speed_elem in zip(dist, speed):
            div = dist_elem // speed_elem
            mod = dist_elem % speed_elem
            time_elem = div if mod == 0 else div + 1
            time.append(time_elem)

        time.sort()
        cur_time: int = 0
        for time_elem in time:
            if cur_time >= time_elem:
                break
            cur_time = cur_time + 1

        return cur_time

sol = Solution()
ret = sol.eliminateMaximum([3, 2, 4], [5, 3, 2])

print(ret)