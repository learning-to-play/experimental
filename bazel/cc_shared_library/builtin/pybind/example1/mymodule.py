from absl import app
from example1 import pyext

def main(_):
  print('1 + 1 = {}'.format(pyext.add(1, 1)))

if __name__ == '__main__':
  app.run(main)
