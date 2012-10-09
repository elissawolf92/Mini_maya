#ifndef DEFORMER
#define DEFORMER
#include "face.h"
#include "vertex.h"
#include "glew.h"
#include "../glm/glm.hpp"
#include <math.h>

using namespace std;

class Deformer
{
public:
	Deformer(void);
	~Deformer(void);
	Deformer(vector<Face*>, vector<Vertex*>);

	vector<vector<vector<Vertex*>>> controlPoints;
	vector<Vertex*> allPoints;
	vector<Face*> faces;
	vector<Vertex*> vertices;
	float minx;
	float maxx;
	float miny;
	float maxy;
	float minz;
	float maxz;

	int xdiv;
	int ydiv;
	int zdiv;

	glm::vec3 P0;
	glm::vec3 max;
	glm::vec3 S;
	glm::vec3 T;
	glm::vec3 U;

	void getBounds();
	void setSTU();
	void makeControlPoints();
	//void fillPoints();
	void drawPoints();
	int factorial(int);
	int choose(int, int);
	void deform(Vertex*);
	void twist(float, QString);
	void taper(float, QString);
	void bend(float, float, float, QString);

	void setXDiv(int);
	void setYDiv(int);
	void setZDiv(int);


private: 

};

#endif

