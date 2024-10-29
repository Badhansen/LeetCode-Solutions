class Solution:
    def __init__(self):
        self.flights_map = defaultdict(list)
        self.result = []
        
    def dfs(self, src):
        flights = self.flights_map[src]
        while flights:
            dest = flights.pop()
            self.dfs(dest)
        self.result.append(src)
        
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        for src, dest in tickets:
            self.flights_map[src].append(dest)
        for src, flights in self.flights_map.items():
            flights.sort(reverse=True)
        self.dfs("JFK")
        return self.result[::-1]