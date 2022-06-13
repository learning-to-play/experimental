import os
from absl import app


def main(_):
  print('Data file(s):', [f for f in os.listdir() if f.endswith('.txt')])


if __name__ == '__main__':
  app.run(main)