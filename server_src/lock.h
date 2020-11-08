#ifndef LOCK
#define LOCK

#include <mutex>

class Lock {
 private:
  std::mutex& m;

 public:
  explicit Lock(std::mutex& m);
  ~Lock();
};

#endif  // LOCK
