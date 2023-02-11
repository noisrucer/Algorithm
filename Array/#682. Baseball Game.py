class Solution:
    def calPoints(self, operations: List[str]) -> int:
        record = []
        res = 0
        for op in operations:
            match op:
                case '+':
                    res += (record[-1] + record[-2])
                    record.append(record[-1] + record[-2])
                case 'D':
                    res += record[-1] * 2
                    record.append(record[-1] * 2)
                case 'C':
                    res -= record.pop()
                case other:
                    res += int(op)
                    record.append(int(op))
        return res
