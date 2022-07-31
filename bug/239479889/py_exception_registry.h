#ifndef PY_EXCEPTION_REGISTRY_H_
#define PY_EXCEPTION_REGISTRY_H_

class PyExceptionRegistry {
 public:
  static void Init();
  static int Lookup();

 private:
  static int singleton_;
};

#endif