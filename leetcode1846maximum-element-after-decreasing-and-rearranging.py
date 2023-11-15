from typing import List

class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        if len(arr) == 1:
            return 1
        pn = 1
        mn = 1
        for n in arr[1:]:
            if n == pn:
                continue
            elif n < pn:
                break
            elif n > pn:
                pn = pn + 1
                mn = pn
        return mn