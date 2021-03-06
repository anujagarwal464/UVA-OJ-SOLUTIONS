#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define EPS 1e-9

struct point{
   double x,y;
   point(double _x,double _y){ x=_x;  y=_y; }
};

struct line { double a, b, c; };

void pointsToLine(point p1, point p2, line *l) {
  if (fabs(p1.x - p2.x) < EPS)
    l->a = 1.0, l->b = 0.0, l->c = -p1.x;
  else {
    l->a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l->b = 1.0;
    l->c = (double)(-l->a * p1.x) - p1.y;
  }
}


bool areParallel(line l1, line l2) {
  return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) {
  return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point *p) {
  if (areSame(l1, l2)) return false;
  if (areParallel(l1, l2)) return false;

  p->x = (double)(l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
  if (fabs(l1.b) > EPS)
    p->y = -(l1.a * p->x + l1.c);
  else
    p->y = -(l2.a * p->x + l2.c);
  return true;
}


int main(){
   double x1,x2,x3,x4,y1,y2,y3,y4;
   int n;
   scanf("%d",&n);
   printf("INTERSECTING LINES OUTPUT\n");
   while(n--){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
    point p1(x1,y1),p2(x2,y2),p3(x3,y3),p4(x4,y4);
    line l1,l2;
    pointsToLine(p1,p2,&l1);
    pointsToLine(p3,p4,&l2);

    if(areSame(l1,l2)) printf("LINE\n");
    else if(areParallel(l1,l2)) printf("NONE\n");
    else{
        point p(0.0,0.0);
        areIntersect(l1,l2,&p);
        printf("POINT %.2lf %.2lf\n",p.x,p.y);
    }
   }
   printf("END OF OUTPUT\n");
   return 0;
}
