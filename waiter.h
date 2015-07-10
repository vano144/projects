#ifndef WAITER_H
#define WAITER_H
#include "fork.h"
#include <QMutex>
class Waiter
{
public:
  int TakenForks;
  static Waiter * instance;
  QMutex WaiterMutex;
private:
  Waiter();
public:
  static Waiter * getWaiter();
  bool AllowToTakeFork(Fork * i);
  void ReturningofTheFork(Fork * i);
};

#endif // WAITER_H
