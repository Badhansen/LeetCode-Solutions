class SQL:

    def __init__(self, names: List[str], columns: List[int]):
        self._db = dict()
        self._dbsizes = defaultdict(int)
        self._dbrowid = defaultdict(int)
        for i, name in enumerate(names):
            self._db[name] = defaultdict(list)
            self._dbsizes[name] = columns[i]
            self._dbrowid[name] = 1

    def ins(self, name: str, row: List[str]) -> bool:
        if name not in self._db:
            return False
        if self._dbsizes[name] != len(row):
            return False
        self._db[name][self._dbrowid[name]] = row
        self._dbrowid[name] += 1
        return True
        
    def rmv(self, name: str, rowId: int) -> None:
        if name not in self._db:
            return
        if rowId not in self._db[name]:
            return
        del self._db[name][rowId]

    def sel(self, name: str, rowId: int, columnId: int) -> str:
        if name not in self._db:
            return "<null>"
        if rowId not in self._db[name]:
            return "<null>"
        if columnId <= len(self._db[name][rowId]):
            return self._db[name][rowId][columnId - 1]
        return "<null>"

    def exp(self, name: str) -> List[str]:
        if name not in self._db:
            return []
        results = []
        for key, value in self._db[name].items():
            res = ",".join([str(key)] + value)
            results.append(res)
        return results
            

# Your SQL object will be instantiated and called as such:
# obj = SQL(names, columns)
# param_1 = obj.ins(name,row)
# obj.rmv(name,rowId)
# param_3 = obj.sel(name,rowId,columnId)
# param_4 = obj.exp(name)