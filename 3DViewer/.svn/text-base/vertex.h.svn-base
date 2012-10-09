#ifndef VERTEX
#define VERTEX

#include <QListWidgetItem>
#include <qstring.h>
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/glm.hpp"

class Face;

class Vertex : public QListWidgetItem{
public:
Vertex();
Vertex(double, double, double, int);
void vertices(double, double, double);
~Vertex();
void setText2();
double x;
double y;
double z;
double tempx;
double tempy;
double tempz;
float s;
float t;
float u;
bool original;
void set(bool);
bool isControlPoint;

//HalfEdge* edge;
int id;

private:

};
#endif