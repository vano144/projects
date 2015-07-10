#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include "fork.h"

#include <QThread>

class Philosopher : public QThread
{
private :
  int NameOfPhilosopher;
  int State;
  Fork * LeftFork;
  Fork * RightFork;
public:
  int CurrentState();
  int PhilosopherName();
  void Distribution(Fork * i, Fork * j);
  Philosopher(int Number);
  void Think();
  bool TakeLeftFork();
  bool TakeRightFork();
  void PutLeftFork();
  void PutRightFork();
  void run();
};

#endif // PHILOSOPHER_H
