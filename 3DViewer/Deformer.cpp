#include "Deformer.h"
using namespace std;
#include <iostream>

Deformer::Deformer(void)
{
	faces = vector<Face*>();
	vertices = vector<Vertex*>();
	minx = 0;
	maxx = 0;
	miny = 0;
	maxy = 0;
	minz = 0;
	maxz = 0;
	xdiv = 0;
	ydiv = 0;
	zdiv = 0;
	controlPoints = vector<vector<vector<Vertex*>>>();
	allPoints = vector<Vertex*>();
	P0 = glm::vec3();
	S = glm::vec3();
	T = glm::vec3();
	U = glm::vec3();
}


Deformer::~Deformer(void)
{
}

Deformer::Deformer(vector<Face*> f, vector<Vertex*> v){
	faces = f;
	vertices = v;
	minx = 0;
	maxx = 0;
	miny = 0;
	maxy = 0;
	minz = 0;
	maxz = 0;
	xdiv = 0;
	ydiv = 0;
	zdiv = 0;
	controlPoints = vector<vector<vector<Vertex*>>>();
	allPoints = vector<Vertex*>();
	P0 = glm::vec3();
	S = glm::vec3();
	T = glm::vec3();
	U = glm::vec3();

}

void Deformer::getBounds(){
	//need to get min and max x, y, and z
	Vertex* vert = vertices[0];
	minx = vert->x;
	maxx = vert->x;
	miny = vert->y;
	maxy = vert->y;
	minz = vert->z;
	maxz = vert->z;

	for (int i = 0; i < vertices.size(); i++){
		vert = vertices[i];
		if (vert->x < minx)
			minx = vert->x;
		if (vert->x > maxx)
			maxx = vert->x;
		if (vert->y < miny)
			miny = vert->y;
		if (vert->y > maxy)
			maxy = vert->y;
		if (vert->z < minz)
			minz = vert->z;
		if (vert->z > maxz)
			maxz = vert->z;
	}

	P0 = glm::vec3(minx, miny, minz);
	S = glm::vec3(maxx - minx, 0, 0);
	T = glm::vec3(0, maxy - miny, 0);
	U = glm::vec3(0, 0, maxz - minz);

	setSTU();

	cout << "minx: " << minx << endl;
	cout << "maxx: " << maxx << endl;
	cout << "miny: " << miny << endl;
	cout << "maxy: " << maxy << endl;
	cout << "minz: " << minz << endl;
	cout << "maxz: " << maxz << endl;

}

void Deformer::setSTU(){
	for (int i = 0; i < vertices.size(); i++){
		Vertex* v = vertices[i];
		glm::vec3 vert = glm::vec3(v->x, v->y, v->z);
		/*v->s = ((v->x) - minx) / (minx - maxx);
		v->t = ((v->y) - miny) / (miny - maxy);
		v->u = ((v->z) - minz) / (minz - maxz); */

		v->s = glm::dot(glm::cross(T, U), ((vert - P0) / glm::dot(glm::cross(T,U), S)));
		v->t = glm::dot(glm::cross(U, S), ((vert - P0) / glm::dot(glm::cross(U,S), T)));
		v->u = glm::dot(glm::cross(S, T), ((vert - P0) / glm::dot(glm::cross(S,T), U)));
	}

}

void Deformer::makeControlPoints(){

	controlPoints = vector<vector<vector<Vertex*>>>();
	allPoints = vector<Vertex*>();

	float xinc = (maxx - minx) / (float)(xdiv-1);
	float yinc = (maxy - miny) / (float)(ydiv-1);
	float zinc = (maxz - minz) / (float)(zdiv-1);
	int ID = 0;

	Vertex* temp = new Vertex();

	for (int i = 0; i < xdiv; i++){
		controlPoints.push_back(vector<vector<Vertex*>>());
	}
	for (int i = 0; i < xdiv; i++){
		for (int j = 0; j < ydiv; j++){
			controlPoints[i].push_back(vector<Vertex*>());
		}
	}

	for (int i = 0; i < xdiv; i++){ //i corresponds to x values
		for (int j = 0; j < ydiv; j++){ //j corresponds to y values
			for (int k = 0; k < zdiv; k++){  //k corresponds to z values
				controlPoints[i][j].push_back(temp);
			}
		}
	}

	for (int i = 0; i < xdiv; i++){ //i corresponds to x values
		for (int j = 0; j < ydiv; j++){ //j corresponds to y values
			for (int k = 0; k < zdiv; k++){  //k corresponds to z values
				float x = minx + (xinc * i);
				float y = miny + (yinc * j);
				float z = minz + (zinc * k);
				Vertex* v = new Vertex(x, y, z, ID);
				v->isControlPoint = true;
				controlPoints[i][j][k] = v;
				allPoints.push_back(v);
				ID++;
			}
		}
	}
}

void Deformer::drawPoints(){
	glPointSize(5.0f);
	for (int i = 0; i < allPoints.size(); i++){
		Vertex* v = allPoints[i];
		glBegin(GL_POINTS);
			glVertex3f(v->x, v->y, v->z);
		glEnd(); 
	}
}

int Deformer::factorial(int f){
	for (int i = f-1; i > 0; i--){
		f = f * i;
	}
	return f;
}

int Deformer::choose(int n, int k){
	if (k == 0)
		return 1;
	if (k == n)
		return 1;
	if (k > n)
		return 0;

	int out = factorial(n);
	out = out / factorial(k);
	out = out / factorial(n-k);
	return out;
}

void Deformer::deform(Vertex* v){ //takes in the vertex, returns its new position based on control pts
	float s = v->s;
	float t = v->t;
	float u = v->u; 

	int xdivtemp = xdiv - 1;
	int ydivtemp = ydiv - 1;
	int zdivtemp = zdiv-1;

	/*for (int cp = 0; cp < allPoints.size(); cp++){
		Vertex* controlPoint = allPoints[cp];
		Vertex temp = *controlPoint; */
		glm::vec3 out = glm::vec3(0,0,0); 

		for (int i = 0; i < xdiv; i++){
			glm::vec3 jsum = glm::vec3(0,0,0);

			for (int j = 0; j < ydiv; j++){
				glm::vec3 ksum = glm::vec3(0,0,0);

				for (int k = 0; k < zdiv; k++){
					Vertex* controlPoint = controlPoints[i][j][k];
					glm::vec3 addK = glm::vec3(controlPoint->x, controlPoint->y, controlPoint->z); //start with control point
					addK = addK * (float)pow(u, k); // multiply by u^k
					addK = addK * (float)pow((1 - u), (zdivtemp - k));  // * (l-u)^(n-k)
					addK = addK * (float)choose(zdivtemp, k); // * n choose k (n = zdiv)
					ksum = ksum + addK; //add to running sum
				}

				glm::vec3 addJ = ksum; //start with result from the k summation
				addJ = addJ * (float)pow(t, j); // multiply by t^j
				addJ = addJ * (float)pow((1-t), (ydivtemp-j)); // multiply by (l-t)^(m-j)
				addJ = addJ * (float)choose(ydivtemp, j); // * m choose j (m = ydiv)
				jsum = jsum + addJ; //add to running sum (middle summation)
			}

			glm::vec3 addI = jsum; //get the sum from the middle summation
			addI = addI * (float)pow(s, i); //multiply by s^i
			addI = addI * (float)pow((1 - s), (xdivtemp - i)); // * (l-s)^(l-i)
			addI = addI * (float)choose(xdivtemp, i); //* l choose i (l = xdiv)
			out = out + addI; //add to the final running sum
		}

		v->x = out.x;
		v->y = out.y;
		v->z = out.z; 
}

void Deformer::twist(float t, QString axis){
	for (int i = 0; i < controlPoints.size(); i++){
		for (int j = 0; j < controlPoints[i].size(); j++){
			for (int k = 0; k < controlPoints[i][j].size(); k++){

				if (axis == "Z"){

		            Vertex* v = controlPoints[i][j][k];
	                float oldx = v->x;
	                float oldy = v->y;
	                float theta = (v->z) * t;

		            v->x = ((oldx * cos(theta)) - (oldy * sin(theta)));
		            v->y = ((oldx * sin(theta)) + (oldy * cos(theta)));
				}

				else if (axis == "X"){

					Vertex* v = controlPoints[i][j][k];
	                float oldz = v->z;
	                float oldy = v->y;
	                float theta = (v->x) * t;

		            v->z = ((oldz * cos(theta)) - (oldy * sin(theta)));
		            v->y = ((oldz * sin(theta)) + (oldy * cos(theta)));

				}

				else { //axis == "Y"

					Vertex* v = controlPoints[i][j][k];
	                float oldz = v->z;
	                float oldx = v->x;
	                float theta = (v->y) * t;

		            v->z = ((oldz * cos(theta)) - (oldx * sin(theta)));
		            v->x = ((oldz * sin(theta)) + (oldx * cos(theta)));
				}

			}
		}

	}
}

void Deformer::taper(float r, QString axis){

	for (int i = 0; i < controlPoints.size(); i++){
		for (int j = 0; j < controlPoints[i].size(); j++){
			for (int k = 0; k < controlPoints[i][j].size(); k++){
				Vertex* v = controlPoints[i][j][k];

				if (axis == "Z"){
					float val = v->z * r;
					v->x = (v->x) * val;
					v->y = (v->y) * val;
					//z stays the same
				}

				else if (axis == "X"){
					float val = v->x * r;
					v->z = (v->z) * val;
					v->y = (v->y) * val;
					//x stays the same
				}

				else { //axis == "Y"
					float val = v->y * r;
					v->x = (v->x) * val;
					v->z = (v->z) * val;
					//y stays the same
				}

			}
		}

	}
}

void Deformer::bend(float min, float max, float bendval, QString axis){
	for (int i = 0; i < controlPoints.size(); i++){
		for (int j = 0; j < controlPoints[i].size(); j++){
			for (int k = 0; k < controlPoints[i][j].size(); k++){

				if (axis == "Y"){

				    Vertex* v = controlPoints[i][j][k];
				    float y = v->y;
				    float z = v->z;
				    float yPrime;
			    	float theta;
		    		float center = (min + max) /2;

			    	if (bendval == 0)
				    	return;

				    if (v->y < min){
					    yPrime = min;
					    theta = bendval * (yPrime - center);
					    v->y = ((-1 * sin(theta)) * (z - (1/bendval))) + center + (cos(theta) * (y - min));
					    v->z = (cos(theta) * (z - (1/bendval))) + (1/bendval) + (sin(theta) * (y - min));
				    }

				    else if (v->y > max){
					    yPrime = max;
					    theta = bendval * (yPrime - center);
					    v->y = ((-1 * sin(theta)) * (z - (1/bendval))) + center + (cos(theta) * (y - max));
					    v->z = (cos(theta) * (z - (1/bendval))) + (1/bendval) + (sin(theta) * (y - max));
				    }

				    else{
					    yPrime = y;
					    theta = bendval * (yPrime - center);
					    v->y = ((-1 * sin(theta)) * (z - (1/bendval))) + center;
					    v->z = (cos(theta) * (z - (1/bendval))) + (1/bendval);
				    }
				}

				else if (axis == "X"){

					Vertex* v = controlPoints[i][j][k];
				    float x = v->x;
				    float z = v->z;
				    float xPrime;
			    	float theta;
		    		float center = (min + max) /2;

			    	if (bendval == 0)
				    	return;

				    if (v->x < min){
					    xPrime = min;
					    theta = bendval * (xPrime - center);
					    v->x = ((-1 * sin(theta)) * (z - (1/bendval))) + center + (cos(theta) * (x - min));
					    v->z = (cos(theta) * (z - (1/bendval))) + (1/bendval) + (sin(theta) * (x - min));
				    }

				    else if (v->x > max){
					    xPrime = max;
					    theta = bendval * (xPrime - center);
					    v->x = ((-1 * sin(theta)) * (z - (1/bendval))) + center + (cos(theta) * (x - max));
					    v->z = (cos(theta) * (z - (1/bendval))) + (1/bendval) + (sin(theta) * (x - max));
				    }

				    else{
					    xPrime = x;
					    theta = bendval * (xPrime - center);
					    v->x = ((-1 * sin(theta)) * (z - (1/bendval))) + center;
					    v->z = (cos(theta) * (z - (1/bendval))) + (1/bendval);
				    }
				}
				else { //axis == "Z"
					Vertex* v = controlPoints[i][j][k];
				    float z = v->z;
				    float x = v->x;
				    float zPrime;
			    	float theta;
		    		float center = (min + max) /2;

			    	if (bendval == 0)
				    	return;

				    if (v->z < min){
					    zPrime = min;
					    theta = bendval * (zPrime - center);
					    v->z = ((-1 * sin(theta)) * (x - (1/bendval))) + center + (cos(theta) * (z - min));
					    v->x = (cos(theta) * (x - (1/bendval))) + (1/bendval) + (sin(theta) * (z - min));
				    }

				    else if (v->z > max){
					    zPrime = max;
					    theta = bendval * (zPrime - center);
					    v->z = ((-1 * sin(theta)) * (x - (1/bendval))) + center + (cos(theta) * (z - max));
					    v->x = (cos(theta) * (x - (1/bendval))) + (1/bendval) + (sin(theta) * (z - max));
				    }

				    else{
					    zPrime = z;
					    theta = bendval * (zPrime - center);
					    v->z = ((-1 * sin(theta)) * (x - (1/bendval))) + center;
					    v->x = (cos(theta) * (x - (1/bendval))) + (1/bendval);
				    }
				}

			}
		}

	}
}

void Deformer::setXDiv(int i){
	xdiv = i;
	getBounds();
	makeControlPoints();
	//fillPoints();
}

void Deformer::setYDiv(int i){
	ydiv = i;
	getBounds();
	makeControlPoints();
	//fillPoints();
}

void Deformer::setZDiv(int i){
	zdiv = i;
	getBounds();
	makeControlPoints();
	//fillPoints();
}