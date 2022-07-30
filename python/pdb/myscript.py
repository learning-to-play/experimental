# Lint as: python3
"""PDB tutorial script.

A simple script that prints the full name.
Run:
  $ blaze run :myscript -- --run_with_pdb
"""
from absl import app
from absl import flags
import mymodule

FLAGS = flags.FLAGS


def main(argv):
  names = [
    {'first_name': 'John', 'last_name': 'Doe'},
    {'first_name': 'Jane', 'last_name': 'Doe'},
  ]

  for name in names:
    first_name_ = name['first_name']
    last_name_ = name['last_name']
    full_name_ = mymodule.full_name(first_name_, last_name_)
    print(full_name_)

  print('names processed: {}'.format(len(names)))

if __name__ == '__main__':
  app.run(main)
