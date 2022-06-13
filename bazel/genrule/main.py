import os

from absl import app


def main(_):
  with open('hello_world.txt') as f:
    for line in f:
      print(line)


if __name__ == '__main__':
  app.run(main)
