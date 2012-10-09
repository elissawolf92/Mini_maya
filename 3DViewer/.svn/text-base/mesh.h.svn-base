#ifndef MESH
#define MESH

#include "halfedge.h"
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include <vector>

using namespace std;

class Mesh {
public:
	
Mesh();
~Mesh();

//functions
void vertexintoedge(HalfEdge*);
void vertexintoedge2(HalfEdge*, Vertex*);
void edgeFacePoint(Face* f);
void edgebtwntwofaces(Face* fa, Face* fb);
void quadintotwotriangles(Face* one);
void average(Vertex*, Vertex*, Vertex*);
void deletevertex(Vertex*);
Vertex* calculateCentroid(Face* fa);
Vertex* calculateEdgePoint(HalfEdge* edge);
void edgepttofacept(Face* fa);
void movePts();
int containsVertex(Vertex*, Face*);
void createEdges();

//create cube
void unitcube();

//variable trackers
int created;
int create2;

//list fillers
vector<Face*>* unitfaces;
vector<Face*>* tempunitfaces;
vector<Vertex*>* unitvertexes;
void redoVertices();
bool contains(vector<Vertex*>*, Vertex*);

private:

};
#endif