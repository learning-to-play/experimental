import unittest
from example2 import mymodule

class MymoduleTest(unittest.TestCase):
  def test_add(self):
    self.assertEqual(mymodule.add(1, 1), 2)


if __name__ == '__main__':
  unittest.main()