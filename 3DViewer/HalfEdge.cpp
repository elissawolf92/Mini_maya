#include "halfedge.h"

HalfEdge::HalfEdge(int x){
QString intn;
id = x;
intn = intn.setNum(x);
setText(intn);
isNew = true;
}
HalfEdge::HalfEdge(Face* f, Vertex* v, Vertex* v2, HalfEdge* n, HalfEdge* s, HalfEdge* p, int i){
	face = f;
	vertex = v;
	endv = v2;
	next = n;
	sym = s;
	id = i;
	prev = p;
	isNew = true;

QString intn;
intn = intn.setNum(i);
setText(intn);

}
void HalfEdge::add(Face* f, Vertex* v){
	face = f;
	vertex = v;
}

Vertex* HalfEdge::midpoint(){
		float x = ((vertex->x + endv->x)/2.0f);
		float y = ((vertex->y + endv->y)/2.0f);
		float z = ((vertex->z + endv->z)/2.0f);

		Vertex* v = new Vertex(x, y, z, 0);

		return v;
}


HalfEdge::~HalfEdge(){}
