import sys


def calculator(left: int, right: int, operation: str) -> None:
  try:
    result = {
      '+': add,
      '-': rest,
      '/': _div,
      '*': mul
    }[operation](left, right)

    print(result)
  except Exception as _:
    print(f'Operation: ({operation}) is invalid.')

def add(left: int, right: int) -> int:
  return left + right

def rest(left: int, right: int) -> int:
  return left - right

def _div(left: int, right: int) -> int:
  if left == 0 or right == 0:  # This is an important thing too, so the the code don't outcome an error
     print('Unable to divide by zero')
  else:
     return left / righ

def mul(left: int, right: int) -> int:
  return left * right


if __name__ == '__main__':
  left, operation, right = sys.argv[1:]
  
  calculator(int(left), int(right), operation)
