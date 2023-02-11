class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        answer = [str(x) for x in range(1, n + 1)]
        for fizz in range(3, n + 1, 3):
            answer[fizz - 1] = "Fizz"
        for buzz in range(5, n + 1, 5):
            if answer[buzz - 1] == 'Fizz':
                answer[buzz - 1] = "FizzBuzz"
            else:
                answer[buzz - 1] = "Buzz"

        return answer