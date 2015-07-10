#include "philosopher.h"
#include "fork.h"
#include "waiter.h"
#include <QMutex>
#include <iostream>
QMutex GlobalMutex;
using namespace std;
int Philosopher::CurrentState()
{
  return State;
}

int Philosopher::PhilosopherName()
{
  return NameOfPhilosopher;
}

void Philosopher::Distribution(Fork *i, Fork *j)
{
  LeftFork=i;
  RightFork=j;
}

Philosopher::Philosopher(int Number)
{
  State=1;
  NameOfPhilosopher=Number;
}

void Philosopher::Think()
{
  sleep(1);
  State=1;
}

bool Philosopher::TakeLeftFork()
{
  LeftFork->MutexFork.lock();
  if ((LeftFork->Owner)==-1)
    {
      if ( Waiter::getWaiter()->AllowToTakeFork(LeftFork))
        {
          LeftFork->Owner=PhilosopherName();
          LeftFork->MutexFork.unlock();
          return true;
        }
      else
        {
          LeftFork->MutexFork.unlock();
          return false;
        }
    }
  else
    {
      LeftFork->MutexFork.unlock();
      return false;
    }
}

bool Philosopher::TakeRightFork()
{
  RightFork->MutexFork.lock();
  if ((RightFork->Owner)==-1)
    {
      if (Waiter::getWaiter()-> AllowToTakeFork(RightFork))
        {
          RightFork->Owner=PhilosopherName();
          RightFork->MutexFork.unlock();
          return true;
        }
      else
        {
          RightFork->MutexFork.unlock();
          return false;
        }
    }
  else
    {
      RightFork->MutexFork.unlock();
      return false;
    }
}

void Philosopher::PutLeftFork()
{
  LeftFork->MutexFork.lock();
  Waiter::getWaiter()-> ReturningofTheFork(LeftFork);
  LeftFork->Owner=-1;
  LeftFork->MutexFork.unlock();
}

void Philosopher::PutRightFork()
{
  RightFork->MutexFork.lock();
  Waiter::getWaiter()->ReturningofTheFork(RightFork);
  RightFork->Owner=-1;
  RightFork->MutexFork.unlock();
}

void Philosopher::run()
{
  while (true)
    {
      if (State==1)
        {
          if (TakeLeftFork())
            {
              if (TakeRightFork())
                {
                  GlobalMutex.lock();
                  cout <<" Eat "<<PhilosopherName()<<endl;
                  GlobalMutex.unlock();
                  State=2;
                  sleep(1);
                  continue;
                }
              else
                {
                  PutLeftFork();
                  continue;
                }
            }
          else
            {
              continue;
            }
        }
      else if (State==2)
        {
          State=0;
          GlobalMutex.lock();
          cout <<" End of eating "<<PhilosopherName()<<endl;
          GlobalMutex.unlock();
          sleep(1);
          PutLeftFork();
          PutRightFork();
        }
      else if (State==0)
        {
          GlobalMutex.lock();
          cout <<" Think "<<PhilosopherName()<<endl;
          GlobalMutex.unlock();
          Think();
          continue;
        }
    }
}

