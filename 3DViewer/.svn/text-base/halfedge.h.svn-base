#ifndef HALFEDGE
#define HALFEDGE

#include "vertex.h"
#include "face.h"
#include <iostream>

using namespace std;

class Face;

class HalfEdge : public QListWidgetItem{
public:
	
HalfEdge(int);
HalfEdge(Face* face, Vertex* v, Vertex* ev, HalfEdge* n, HalfEdge* s, HalfEdge* p, int);
void add(Face*, Vertex*);
~HalfEdge();
HalfEdge* next;
HalfEdge* prev;
HalfEdge* sym;
Face* face;
Vertex* vertex;
Vertex* endv;
bool isNew;

Vertex* edgepoint;
Vertex* midpoint();

glm::vec3 normal;
int id;

private:

};
#endif