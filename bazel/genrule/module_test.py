import unittest
import module

class ModuleTest(unittest.TestCase):
  def test_read_generated_hello_world_text_file(self):
    self.assertEqual(module.read_text_file('hello_world.txt'), 'Hello, World!\n')


if __name__ == '__main__':
  unittest.main()