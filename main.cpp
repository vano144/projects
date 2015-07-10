#include <QCoreApplication>
#include "fork.h"
#include "philosopher.h"
int main(int argc, char *argv[])
{
  Philosopher FirstPhilosopher(0);
  Philosopher SecondPhilosopher(1);
  Philosopher ThirdPhilosopher(2);
  Philosopher FourthPhilosopher(3);
  Philosopher FifthPhilosopher(4);\
  Fork TableForks[5];
  for (int i=0;i<5;i++)
    {
      TableForks[i].Owner=-1;
    }
  FirstPhilosopher.Distribution(&TableForks[0],&TableForks[1]);
  SecondPhilosopher.Distribution(&TableForks[1],&TableForks[2]);
  ThirdPhilosopher.Distribution(&TableForks[2],&TableForks[3]);
  FourthPhilosopher.Distribution(&TableForks[3],&TableForks[4]);
  FifthPhilosopher.Distribution(&TableForks[4],&TableForks[0]);

  FirstPhilosopher.start();
  SecondPhilosopher.start();
  ThirdPhilosopher.start();
  FourthPhilosopher.start();
  FifthPhilosopher.start();
  QCoreApplication a(argc, argv);

  return   a.exec();
}
