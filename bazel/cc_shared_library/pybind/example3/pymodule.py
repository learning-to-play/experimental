from example3 import libpyext

def add(a: int, b: int) -> int:
  return libpyext.add(a, b)
