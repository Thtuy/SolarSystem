#include "System.h"

System::System()
{
  element= new Star[MAXNUM-1];
  n=0;
}

System::~System()
{
  delete []element;
}


bool System::insertPre(System sys,int i,Star star)
{
  if(i<0||i>n-1) return false;
  for (int j=n-1;j>=i;j--)
  {
    element[j+1]=element[j];
  }
  element[i]=star;
  n++;
  return true;
}

bool System::insertPost(System sys,int i,Star star)
{
  if(i<0||i>n-1) return false;
  for (int j=n-1;j>=i+1;j--)
  {
    element[j+1]=element[j];
  }
  element[i+1]=star;
  n++;
  return true;
}

bool System::deleteV(System sys,Star star)
{
  int j{-1};
  for (int i=0;i<n;i++)
  {
    if (element[i].name==star.name) {j=i;break;}
  }
  if (j<0) return false;
  for (int i=j;i<n-1;i++)
  {
    element[i]=element[i+1];
  }
  n--;
  return true;
}

bool System::deleteP(System sys,int i)
{
  if(i<0||i>n-1) return false;
  for(int j=i;j<n-1;j++)
  {
    element[j]=element[j+1];
  }
  n--;
  return true;
}

int System::locate(System sys,Star star)
{
  int j{-1};
  for (int i=0;i<n;i++)
  {
    if (element[i].name==star.name) {j=i;break;}
  }
  if(j<0) return -1;
  return j;
}

bool System::isNull(System sys)
{
  if (n==0) return true;
  return false;
}
