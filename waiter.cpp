#include "waiter.h"
#include "fork.h"
#include "QMutex"
Waiter * Waiter::instance=NULL;

Waiter::Waiter()
{
  TakenForks=0;
}

Waiter * Waiter::getWaiter()
{
  if (instance!=NULL)
    {
      return instance;
    }
  else
    {
      instance= new Waiter;
      return instance;
    }
}

bool Waiter::AllowToTakeFork(Fork * i)
{
  WaiterMutex.lock();
  //i->MutexFork.lock();
  if (i->Owner==-1 && TakenForks<4)
    {
      TakenForks++;
      WaiterMutex.unlock();
      //i->MutexFork.unlock();
      return true;
    }
  else {
      WaiterMutex.unlock();
      //i->MutexFork.unlock();
      return false;
    }
}
void Waiter::ReturningofTheFork(Fork *i)
{
  {
    WaiterMutex.lock();
    TakenForks--;
    WaiterMutex.unlock();
    //i->MutexFork.lock();
    i->Owner=-1;
    //i->MutexFork.unlock();
  }
}
