#ifndef FACE
#define FACE
#include <vector>
#include <QListWidgetItem>
#include <qstring.h>
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/glm.hpp"

using namespace std;

class HalfEdge;
class Vertex;

class Face : public QListWidgetItem{
public:
Face(int, HalfEdge* se);
Face(HalfEdge*, float, float, float, int);
~Face();
Face(int x);

//vars
float red;
float green;
float blue;
int id;
HalfEdge* startingedge;
bool planarity;
bool isNull;
bool hovering;
vector<HalfEdge*>* edgesinface;
Vertex* facepoint;
Vertex* midpoint(Vertex*);
int hasV(Vertex*);

//returns
Vertex* getV(int);
int edges();
bool normals();

private:

};
#endif