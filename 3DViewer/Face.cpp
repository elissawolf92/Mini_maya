#include "face.h"
#include "halfedge.h"
#include "vertex.h"

Face::Face(int x){
QString intn;
id = x;

edgesinface = new vector<HalfEdge*>();
intn = intn.setNum(x);
setText(intn);
planarity = true;
isNull = false;
hovering = false;
}


Face::Face(int x, HalfEdge* se){
QString intn;
id = x;

edgesinface = new vector<HalfEdge*>();
intn = intn.setNum(x);
setText(intn);
startingedge = se;
planarity = true;
isNull = true;
hovering = false;
}

Face::Face(HalfEdge* edge, float r, float g, float b, int name){
isNull = false;
planarity = true;
hovering = false;

red = r;
green = g;
blue = b;
id = name;
startingedge = edge;
edgesinface = new vector<HalfEdge*>();

QString intn;
intn = intn.setNum(name);
setText(intn);
}

//returns number of edges and refills array of halfedges
int Face::edges(){
	HalfEdge* edge = startingedge->next;
	int total = 1;
	while(edgesinface->empty() != true){
		edgesinface->pop_back();
	}
	edgesinface->push_back(startingedge);

	while(startingedge != edge){
		edgesinface->push_back(edge);
		edge = edge->next;
		total++;
	}

	return total;
}

//returns vertex of halfedge at location z
Vertex* Face::getV(int z){
	HalfEdge* tedge = startingedge;
	Vertex* v = tedge->vertex;
	while ( z > 0 ){
		tedge = tedge->next;
		v = tedge->vertex;
		z--;
	}
	return v;
}

int Face::hasV(Vertex* v){
	edges();
	int has = 5;
	for(int i = 0; i < edgesinface->size(); i++){
		if((edgesinface->at(i)->vertex == v)) has = i;
	}
	return has;
}

Vertex* Face::midpoint(Vertex* x){
	Vertex* v = new Vertex(0,0,0,0);
	for(int i = 0; i < edgesinface->size(); i++){
		if((edgesinface->at(i)->endv == x)) {
			v = edgesinface->at(i)->edgepoint; }	
	}
	return v;
}

//calculates normals
bool Face::normals(){
	glm::vec3 holdingvar;
	bool x = true;
	HalfEdge* edge1 = startingedge;
	HalfEdge* edge2 = startingedge->next;
	HalfEdge* edge3 = startingedge->next->next;
	
		glm::vec3 p1 = glm::vec3(edge1->vertex->x, edge1->vertex->y, edge1->vertex->z);
		glm::vec3 p2 = glm::vec3(edge2->vertex->x, edge2->vertex->y, edge2->vertex->z);
		glm::vec3 p3 = glm::vec3(edge3->vertex->x, edge3->vertex->y, edge3->vertex->z);

		glm::vec3 v1 = p3 - p2;
		glm::vec3 v2 = p2 - p1;

		glm::vec3 last = glm::normalize(glm::cross(v1, v2));

	HalfEdge* tedge1 = startingedge;
	HalfEdge* tedge2 = startingedge->next;
	HalfEdge* tedge3 = startingedge->next->next;

		while(((-.05 < last[0] < .05) && (-.05 < last[1] < .05) && (-.05 < last[2] < .05))&& (tedge2 != startingedge)){
		glm::vec3 v1 = glm::vec3(tedge1->vertex->x, tedge1->vertex->y, tedge1->vertex->z);
		glm::vec3 v2 = glm::vec3(tedge2->vertex->x, tedge2->vertex->y, tedge2->vertex->z);
		glm::vec3 v3 = glm::vec3(tedge3->vertex->x, tedge3->vertex->y, tedge3->vertex->z);

		glm::vec3 a1 = v3 - v2;
		glm::vec3 b2 = v2 - v1;

		last = glm::normalize(glm::cross(a1, b2));
		planarity = false;

		tedge1 = tedge1->next;
		tedge2 = tedge2->next;
		tedge3 = tedge3->next;
		}

		edge2->normal = last;

		edge1 = edge1->next;
		edge2 = edge2->next;
		edge3 = edge3->next;

	while(edge1 != startingedge){
		glm::vec3 v1 = glm::vec3(edge1->vertex->x, edge1->vertex->y, edge1->vertex->z);
		glm::vec3 v2 = glm::vec3(edge2->vertex->x, edge2->vertex->y, edge2->vertex->z);
		glm::vec3 v3 = glm::vec3(edge3->vertex->x, edge3->vertex->y, edge3->vertex->z);

		glm::vec3 a1 = v3 - v2;
		glm::vec3 b2 = v2 - v1;

		glm::vec3 last2 = glm::normalize(glm::cross(a1, b2));

		if((-.05 < last2[0] < .05) && (-.05 < last2[1] < .05) && (-.05 < last2[2] < .05)){
		last2 = last;
		planarity = false;
		}

		edge2->normal = last2;

		if(last2 != last){
		x = false;
		}

		edge1 = edge1->next;
		edge2 = edge2->next;
		edge3 = edge3->next;
	}

	return x;

}

Face::~Face(){}
