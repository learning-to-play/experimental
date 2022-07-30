import unittest
from example3 import pymodule

class PymoduleTest(unittest.TestCase):
  def test_add(self):
    self.assertEqual(pymodule.add(1, 1), 2)


if __name__ == '__main__':
  unittest.main()