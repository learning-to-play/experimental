import os

def read_text_file(text_file):
  with open(text_file) as f:
    content = f.read()
  return content
