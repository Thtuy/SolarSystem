#ifndef _SYSTEM_H
#define _SYSTEM_H

#include<string>

#define MAXNUM 1000

using namespace std;

enum Data{pre_x=1,pre_y,pre_z,x,y,z,mass,pre_vx,pre_vy,pre_vz,vx,vy,vz,fx,fy,fz};////////////////////////////

struct Star
{
  string name;

  double pre_x,pre_y,pre_z;
  double x,y,z;

  double mass;

  double pre_vx,pre_vy,pre_vz;
  double vx,vy,vz;
  double fx,fy,fz;

  Star(){}
  Star(string nn,
       double preX,double preY,double preZ,
       double curX,double curY,double curZ,
       double m,
       double preVx,double preVy,double preVz,
       double curVx,double curVy,double curVz,
       double Fx,double Fy,double Fz):
         name{nn},
         pre_x{preX},pre_y{preY},pre_z{preZ},
         x{curX},y{curY},z{curZ},
         mass{m},
         pre_vx{preVx},pre_vy{preVy},pre_vz{preVz},
         vx{curVx},vy{curVy},vz{curVz},
         fx{Fx},fy{Fy},fz{Fz}{}
};

///////////////////////////////////////////

class System
{
public:
  Star *element;
  int n;

  System();
  ~System();

  bool insertPre(System sys,int i,Star star);
  bool insertPost(System sys,int i,Star star);
  bool deleteV(System sys,Star star);
  bool deleteP(System sys,int i);
  int locate(System sys,Star star);
  bool isNull(System sys);
};


#endif // _SYSTEM_H
