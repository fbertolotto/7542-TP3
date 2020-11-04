#ifndef THREAD_H
#define THREAD_H

#include <thread>

class Thread {
 private:
  std::thread thread;

 public:
  /* Init del Thread */
  Thread();

  /* Inicializa el Thread */
  void start();

  /* Espera a que el Thread termine su ejecución para cerrarlo */
  void join();

  /* Ejecuta el Thread */
  virtual void run() = 0;

  /* No se permite constructor por copia o copia por asignación */
  Thread(const Thread&) = delete;
  Thread& operator=(const Thread&) = delete;

  /* Se permiten por movimiento */
  Thread(Thread&& other);
  Thread& operator=(Thread&& other);

  /* Destructor del Thread */
  virtual ~Thread();
};

#endif  // THREAD_H
