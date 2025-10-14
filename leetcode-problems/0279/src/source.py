class Solution:
    def numSquares(self, n: int) -> int:
        sq = [i*i for i in range(1, (int)(sqrt(n))+1)]
        
        explore = {n}
        count = 0
        while explore:
            count += 1
            temp = set()
            for n in explore:              
                for x in sq:
                    if n - x == 0:
                        return count
                    if n - x > 0: 
                        temp.add(n-x)
            explore = temp

        return count
