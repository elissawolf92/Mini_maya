#include "vertex.h"

Vertex::Vertex(){
vertices(0,0,0);
original = true;
}

Vertex::Vertex(double xx, double yy, double zz, int idd){
id = idd;
original = true;
vertices(xx, yy, zz);
isControlPoint = false;

}

void Vertex::vertices(double xx, double yy, double zz){
x = xx;
y = yy;
z = zz;
QString temp = QString("{");
QString comma = QString(",");
QString int1;
int1= int1.setNum(xx);
temp.append(int1);
temp.append(comma);
int1 = int1.setNum(yy);
temp.append(int1);
temp.append(comma);
int1 = int1.setNum(zz);
temp.append(int1);
temp.append(QString("}"));
s = 0;
t = 0;
u = 0;
isControlPoint = false;

setText(temp);

}

void Vertex::set(bool x){
	original = x;
}

void Vertex::setText2(){

QString temp = QString("{");
QString comma = QString(",");
QString int1;
int1= int1.setNum(x);
temp.append(int1);
temp.append(comma);
int1 = int1.setNum(y);
temp.append(int1);
temp.append(comma);
int1 = int1.setNum(z);
temp.append(int1);
temp.append(QString("}"));

setText(temp);
}


Vertex::~Vertex(){}