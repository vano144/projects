#ifndef FORK_H
#define FORK_H
#include <QMutex>
class Fork
{
public:
  QMutex MutexFork;
  int Owner;
};


#endif // FORK_H
