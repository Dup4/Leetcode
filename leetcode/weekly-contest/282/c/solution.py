class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        return bisect_left(range(totalTrips * min(time)), totalTrips, key=lambda x: sum(x // t for t in time))
