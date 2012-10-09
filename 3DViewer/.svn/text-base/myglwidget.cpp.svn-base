#include "myglwidget.h"
#include <cmath>
#include <iostream>
#include "../glm/gtc/matrix_transform.hpp"
using namespace std;
#include "qt_windows.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#define DEG2RAD (M_PI/180.0)
#define MOUSEWHEEL 0x020A
#define _IRR WINDOWS_

MyGLWidget::MyGLWidget(QWidget* parent) : QGLWidget(parent) {
	//This starter code uses a timer to make a square rotate without
	//user intervention.  You can remove this.
	timer = new QTimer(this);
	rotation = 0;
	lastx = 0;
	lasty = 0;
	catmullclark = false;
	connect(timer, SIGNAL(timeout()), this, SLOT(play()));
	mousemode = false;
	//this->setMouseTracking(true);
	//We can set our vertex attributes rather than requesting their locations
	//I chose to do so in this constructor, maybe you would in your init() function?
	positionLocation = 0;
	normalLocation = 1;
	colorLocation = 2;
	mesh = new Mesh();
	camera = myCamera();
	mesh->unitcube();
	runhe = true;
	currentf = mesh->unitfaces->at(0);
	prevf = mesh->unitfaces->at(0);
	currentv = mesh->unitvertexes->at(0);
	currenth = currentf->startingedge;
	fedges = new vector<HalfEdge*>();
	ray = false;
	filename = "cow.obj";
	setFocusPolicy(Qt::StrongFocus);
	deformer = Deformer();
	controlPoints = vector<Vertex*>();
	light=glm::vec3(-5,-5,-5);
	deformOn = false;
	twistval = 1;
	taperval = 1;
	bendval = 1;
	bendMin = 0;
	bendMax = 1;
	axis = "Z";
}

void::MyGLWidget::unitCube(){
mesh->unitcube();

populateLists();
	currentf = mesh->unitfaces->at(0);
	prevf = mesh->unitfaces->at(0);
	currentv = mesh->unitvertexes->at(0);
	currenth = currentf->startingedge;
updateGL();
}


void MyGLWidget::lightsX(int x1){
	light[0]=(x1/10);
	updateGL();
} 

void MyGLWidget::lightsY(int y1){
	light[1]=(y1/10);
	updateGL();
}

void MyGLWidget::lightsZ(int z1){
	light[2]=(z1/10);
	updateGL();
}

void MyGLWidget::colorRed(int r){
	if(r != 0){
	currentf->red = (r/255.0);
	}
	else{
	currentf->red = 0;
	}
	updateGL();
}
void MyGLWidget::colorGreen(int g){
	if(g != 0){
	currentf->green = (g/255.0);
	}
	else{
	currentf->green = 0;
	}
	updateGL();
}
void MyGLWidget::colorBlue(int b){
	if(b != 0){
	currentf->blue = (b/255.0);
	}
	else{
	currentf->blue = 0;
	}
	updateGL();
}

void MyGLWidget::setCurrHE(QListWidgetItem* a){
	currenth = (HalfEdge*)a;
}

void MyGLWidget::setCurr(QListWidgetItem* a){
	prevf = currentf;
	currentf = (Face*)a;

	resetHalfEdge();
	setCurrHE(fedges->at(0));

	emit red((currentf->red)*255.0);
	emit green((currentf->green)*255.0);
	emit blue((currentf->blue)*255.0);
}

void MyGLWidget::resetHalfEdge(){

for(int i = 0; i<fedges->size(); i++){
	listofhe->takeItem(0);
	}

currentf->edges();
fedges = currentf->edgesinface;
for(int i = 0; i<fedges->size(); i++){
	listofhe->addItem(fedges->at(i)); 
}

}

void MyGLWidget::setCurr2(QListWidgetItem* a){
	currentv = (Vertex*)a;
	currx = currentv->x;
	emit xsig(currx);
	curry = currentv->y;
	emit ysig(curry);
	currz = currentv->z;
	emit zsig(currz);
}

void MyGLWidget::x(double doub){
	currx = doub;
	currentv->x = currx;
	currentv->setText2();
	if (currentv->isControlPoint){
		if (deformOn)
		    ffd();
	}
	updateGL();
}
void MyGLWidget::y(double doub){
	curry = doub;
	currentv->y = curry;
	currentv->setText2();
	if (currentv->isControlPoint){
		if (deformOn)
		    ffd();
	}
	updateGL();
}
void MyGLWidget::z(double doub){
	currz = doub;
	currentv->z = currz;
	currentv->setText2();
	if (currentv->isControlPoint){
		if (deformOn)
		    ffd();
	}
	updateGL();
}

void MyGLWidget::deleteVertex(){
	mesh->deletevertex(currentv);
	mesh->redoVertices();
	for(int i = 0; i < mesh->unitfaces->size(); i++){
	listoffaces->takeItem(i);
	}

	for(int j = 0; j < mesh->unitvertexes->size(); j++){
	listofvertices->takeItem(j);
	}

	populateLists();
	updateGL();

}

void MyGLWidget::quadtwotriangles(){
	mesh->quadintotwotriangles(currentf);

	for(int i = 0; i < mesh->unitfaces->size(); i++){
	listoffaces->takeItem(i);
	}

	resetHalfEdge();

	for(int j = 0; j < mesh->unitvertexes->size(); j++){
	listofvertices->takeItem(j);
	}

	populateLists();
	updateGL();
}

void MyGLWidget::addVertex(){
	mesh->vertexintoedge(currenth);
	mesh->redoVertices();

	for(int i = 0; i < mesh->unitfaces->size(); i++){
	listoffaces->takeItem(i);
	}

	resetHalfEdge();

	for(int j = 0; j < mesh->unitvertexes->size(); j++){
	listofvertices->takeItem(j);
	}

	populateLists();
	updateGL();
}

void MyGLWidget::edgeBtwnTwoFaces(){
	mesh->edgebtwntwofaces(prevf, currentf);
	mesh->redoVertices();

	for(int i = 0; i < mesh->unitfaces->size(); i++){
	listoffaces->takeItem(i);
	}

	resetHalfEdge();

	for(int j = 0; j < mesh->unitvertexes->size(); j++){
	listofvertices->takeItem(j);
	}

	populateLists();
	updateGL();
}

void MyGLWidget::mousemodetoggle(){
//mousemode = !mousemode;
}

void MyGLWidget::play(){
/*rotation += 2.5;
timer->start(17); 
updateGL();
*/}
void MyGLWidget::stop(){
/*timer->stop();
updateGL();
*/}

MyGLWidget::~MyGLWidget() {
	//Release your resources, just like you'd delete pointers
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &cbo);
	glDeleteBuffers(1, &nbo);
	glDeleteBuffers(1, &ibo);

	//Tear down the shader program in reverse of building it
	glDetachShader(shaderProgram, vertexShader);
	glDetachShader(shaderProgram, fragmentShader);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glDeleteProgram(shaderProgram);
}
//this is the function i referred to as "init" in my lecture - Cory
void MyGLWidget::initializeGL() {
	populateLists();
	//Initialize GLEW to get access to latest OpenGL support on your computer
	//GLEW 1.7.0 supplied with this starter code, it's always a good idea to update
	//about once every year or so as OpenGL is updated
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		cerr << "GLEW is not initialized!";
	}

	//Create the VBOs and IBO we'll be using to render images in OpenGL
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &cbo);
	glGenBuffers(1, &nbo);
	glGenBuffers(1, &ibo);
	
	//Everybody does this
	glClearColor(1, 1, 1, 1);
	glEnable(GL_DEPTH_TEST);
	glClearDepth(1.0);
	glDepthFunc(GL_LEQUAL);

	//here is stuff for setting up our shaders
	const char* vertFile = "diffuseVert.vert";
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	shaderProgram = glCreateProgram();
	
	//load up the source, compile and link the shader program
	const char* vertSource = textFileRead(vertFile);
	const char* fragSource = textFileRead("frag.frag");
	glShaderSource(vertexShader, 1, &vertSource, 0);
	glShaderSource(fragmentShader, 1, &fragSource, 0);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);

	//For your convenience, i decided to throw in some compiler/linker output helper functions
	//from CIS 565
	GLint compiled;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		printShaderInfoLog(vertexShader);
	} 
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compiled);
	if (!compiled)
	{
		printShaderInfoLog(fragmentShader);
	} 

	//set the attribute locations for our shaders
	glBindAttribLocation(shaderProgram, positionLocation, "vs_position");
	glBindAttribLocation(shaderProgram, normalLocation, "vs_normal");
	glBindAttribLocation(shaderProgram, colorLocation, "vs_color");

	//finish shader setup
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	//check for linking success
	GLint linked;
	glGetProgramiv(shaderProgram,GL_LINK_STATUS, &linked);
	if (!linked) 
	{
		printLinkInfoLog(shaderProgram);
	}


	//Get the uniform locations for our shaders, unfortunately they can not be set by us, we have
	u_modelMatrixLocation = glGetUniformLocation(shaderProgram, "u_modelMatrix");
	u_projMatrixLocation = glGetUniformLocation(shaderProgram, "u_projMatrix");
	u_lightLocation = glGetUniformLocation(shaderProgram, "lightPos");


	//Always remember that it doesn't do much good if you don't have OpenGL actually use the shaders
	glUseProgram(shaderProgram);

	// Initialize Lighting
}
//this is what i referred to as a "paint" or "draw" function in my lecture - Cory
void MyGLWidget::paintGL() {
	//Always and only do this at the start of a frame, it wipes the slate clean
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//create an identity matrix for the model matrix
	//createCube(glm::mat4());	
	
	drawTheCube();
	if (deformOn)
	    deformer.drawPoints();

	glLineWidth(5.0);
	glBegin(GL_LINES);
	glVertex3f(currenth->vertex->x, currenth->vertex->y, currenth->vertex->z);
	glVertex3f(currenth->endv->x, currenth->endv->y, currenth->endv->z);
	glEnd();

	glPointSize(5.0f);
	glBegin(GL_POINTS);
			glVertex3f(currentv->x, currentv->y, currentv->z);
	glEnd();


}

void MyGLWidget::moveEverything(){
mesh->createEdges();
populateLists();
catmullclark = true;
updateGL();
}

void MyGLWidget::populateLists(){
	QObject* parent = this->parent();
	listoffaces = parent->findChild<QListWidget*>(QString("ListOfFaces"));
	//listoffaces->clear();
	int temp = listoffaces->count();
	for (int i = 0; i < temp; i++){
		listoffaces->takeItem(0);
	}
	
	int howmanydeleted = 0;
	for(int i = 0; i<mesh->unitfaces->size(); i++){
		if(mesh->unitfaces->at(i)->edges() < 3){
			mesh->unitfaces->erase(mesh->unitfaces->begin() + i - howmanydeleted);
			howmanydeleted++;
		}
	} 

	vector<Face*>* faces = mesh->unitfaces;

	for(int i = 0; i<faces->size(); i++){
	listoffaces->addItem(faces->at(i)); 
	}

	listofvertices = parent->findChild<QListWidget*>(QString("ListOfVertices"));
	//listofvertices->clear();
    temp = listofvertices->count();
	for (int i = 0; i < temp; i++){
		listofvertices->takeItem(0);
	}
	

	vector<Vertex*>* vertexes = mesh->unitvertexes;
	
	for(int j = 0; j<vertexes->size(); j++){
	listofvertices->addItem(vertexes->at(j));
	}

	listofhe = parent->findChild<QListWidget*>(QString("HE"));
	runhe = false;
	//resetHalfEdge();

	listofcontrolpoints = parent->findChild<QListWidget*>(QString("ListOfControlPoints"));
	//listofcontrolpoints->clear();

	temp = listofcontrolpoints->count();
	for (int i = 0; i < temp; i++){
		listofcontrolpoints->takeItem(0);
	}

	controlPoints = deformer.allPoints;

	for (int i = 0; i < controlPoints.size(); i++){
		listofcontrolpoints->addItem(controlPoints[i]);
	}
}

void MyGLWidget::drawTheCube(){
	
	glm::mat4 rotmat = glm::mat4();
	glm::vec3 vecthree = glm::vec3(0, 1, 0);
	rotmat = glm::rotate(rotmat, rotation, vecthree);
	

	glm::mat4 model = glm::mat4();
	model = model*glm::rotate(glm::mat4(1.0), rotation, glm::vec3(0,1,0));
	

	vector<Face*>* faces = mesh->unitfaces;

	for(int i = 0; i<faces->size(); i++){
	drawFace(model, faces->at(i));
	}
}

void MyGLWidget::drawFace(glm::mat4 model, Face* face){
	face->edges();
	float* colors = new float[face->edges()*4];
	float* vertices = new float[face->edges()*4];
	float* normals = new float[face->edges()*4];
	unsigned short* indices = new unsigned short[(face->edges()-2)*3];

	//make colors array
	float r = face->red;
	float g = face->green;
	float b = face->blue;

	if(face == currentf){
	r = .5;
	g = .5;
	b = .5;
	}
	if(face->hovering == true){
	r = 1;//r - .1;
	g = 1;//g - .1;
	b = 1;//b - .1;
	}

		HalfEdge* firstedge = face->startingedge;
		HalfEdge* edge = firstedge->next;	
		int count = 0;

		colors[count] = (r);
		count++;
		colors[count] = (g);
		count++;
		colors[count] = (b);
		count++;
		colors[count] = 1;
		count++;

		while(firstedge != edge){

		colors[count] = (r);
		count++;
		colors[count] = (g);
		count++;
		colors[count] = (b);
		count++;
		colors[count] = 1;
		count++;

		edge = edge->next;
		}

		//make vertices array
		count = 0;
		HalfEdge* e = face->startingedge;
		Vertex* a = e->vertex;
	
		double xx = a->x;
		double yy = a->y;
		double zz = a->z;
		vertices[count] = xx;
		count++;
		vertices[count] = yy;
		count++;
		vertices[count] = zz;
		count++;
		vertices[count] = 1;
		count++;

		HalfEdge* edge2 = e->next;
		while(e != edge2){
			a = edge2->vertex;

			xx = a->x;
			yy = a->y;
			zz = a->z;
			vertices[count] = xx;
			count++;
			vertices[count] = yy;
			count++;
			vertices[count] = zz;
			count++;
			vertices[count] = 1;
			count++;

			edge2 = edge2->next;
		}

		//make normals array
		count = 0;
		bool truefalse = face->normals();
		if(catmullclark == false){
		if(truefalse == false){
			mesh->quadintotwotriangles(face);
		}
		}

		HalfEdge* newest = face->startingedge;
		glm::vec3 vone = newest->normal;

		normals[count] = vone[0];
		count++;
		normals[count] = vone[1];
		count++;
		normals[count] = vone[2];
		count++;
		normals[count] = 0;
		count++;

		HalfEdge* edge3 = newest->next;
		while(newest != edge3){
			vone = edge3->normal;
			normals[count] = vone[0];
			count++;
			normals[count] = vone[1];
			count++;
			normals[count] = vone[2];
			count++;
			normals[count] = 0;
			count++;

			edge3 = edge3->next;
		}
		count = 0;

		for(int l = 0; l < (face->edges() - 2); l++){
			indices[count] = 0;
			count++;
			indices[count] = l+1;
			count ++;
			indices[count] = l+2;
			count++;
		}
		
	//now we put the data into the Vertex Buffer Object for the graphics system to use
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 4 * face->edges() * sizeof(float), vertices, GL_STATIC_DRAW); //the square vertices don't need to change, ever,
																				 //while the program runs

	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	//always make sure you are telling OpenGL the right size to make the buffer, color data doesn't have as much data!
	glBufferData(GL_ARRAY_BUFFER, 4* face->edges() * sizeof(float), colors, GL_STATIC_DRAW);	

	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glBufferData(GL_ARRAY_BUFFER, 4 * face->edges() * sizeof(float), normals, GL_STATIC_DRAW); //the square normals don't need to change, ever,
																				 //while the program runs
	//activate our three kinds of information
	glEnableVertexAttribArray(positionLocation);
	glEnableVertexAttribArray(colorLocation);
	glEnableVertexAttribArray(normalLocation);
	
	//we're using the vertex data first
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//define how the vertex pointer should work, in our case we're accessing floats 4 at a time with no special pattern
	glVertexAttribPointer(positionLocation, 4, GL_FLOAT, 0, 0, static_cast<char*>(0));
	
	//now use color data
	glBindBuffer(GL_ARRAY_BUFFER, cbo);
	glVertexAttribPointer(colorLocation, 4, GL_FLOAT, 0, 0, static_cast<char*>(0));

	//one more time with the normals
	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glVertexAttribPointer(normalLocation, 4, GL_FLOAT, 0, 0, static_cast<char*>(0));
	
	//the last thing we need to do is setup our indices
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (face->edges() - 2)*3 * sizeof(unsigned short), indices, GL_STATIC_DRAW);

	//set the model uniform
	//GL_FALSE is used for not doing transpose operation, because glm has already provided us column major matrices.
	//if the matrices you used is row major, change this parameter to GL_TRUE.
	glUniformMatrix4fv(u_modelMatrixLocation, 1, GL_FALSE, &model[0][0]);
	glUniform3f(u_lightLocation, light[0],light[1],light[2]);

	//draw the elements
	glDrawElements(GL_TRIANGLES, (face->edges() - 2)*3, GL_UNSIGNED_SHORT, 0);
	
	//shut off the information since we're done drawing
	glDisableVertexAttribArray(positionLocation);
	glDisableVertexAttribArray(colorLocation);

	glLineWidth(1.0);
	glBegin(GL_LINES);
	glVertex3f(beginning[0], beginning[1], beginning[2]);
	glVertex3f(ending[0], ending[1], ending[2]);
	glEnd();


}
glm::vec3 MyGLWidget::getP(float t, glm::vec3 start, glm::vec3 end){
	glm::vec3 point;

	point = start + t*(end - start);

	return point;
}

float MyGLWidget::getT(glm::vec3 nor, glm::vec3 s, glm::vec3 start, glm::vec3 end){
	glm::vec3 sec = (s-start);
	float temp = glm::dot(nor, sec);
	glm::vec3 fir = (end - start);
	float temp2 = glm::dot(nor, fir);

	return (temp/temp2);
}
void MyGLWidget::wheelEvent(QWheelEvent *event){
    if (event->delta()>0){
        camera.zoomIn();
    }else if(event->delta()<0){
        camera.zoomOut();
    }
    resizeGL(641,481);
    updateGL();
}
 
void MyGLWidget::focusV(){
	camera.position[0]=currentv->x;
	camera.position[1]=currentv->y;
	camera.position[2]=currentv->z;
	updateGL();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event){

	float x = event->x();
	float y = event->y();


if(event->buttons()==Qt::LeftButton){
	if(x > lastx){
	lastx =x;
	camera.right();
	
	}
	else if (x<lastx){
	lastx = x;
	camera.left();
	
}
	if(y >lasty){
	lasty = y;
	camera.up();
	
	}
else if (y < lasty){
	lasty =y;
	camera.down();
	
}

}

	//float x = e->x();
	//float y = e->y();

	// change to normalized device coordinates
	x = x / this->width();
	y = y / this->height();

	// TODO: update the eye position;
	// world coordinate of eye
	glm::vec3 E;//
	E = glm::vec3(camera.getPos()[0], camera.getPos()[1], camera.getPos()[2]);

	// TODO: update the U vector;
	// up vector
	glm::vec3 U;//
	U = glm::vec3(camera.getUp()[0], camera.getUp()[1], camera.getUp()[2]);

	// Viewing vector
	glm::vec3 center = glm::vec3(0,0,0); // assume we are focusing on the origin, if the center moves, it will be different.
	glm::vec3 C = center - E; // implies viewing distance is |C|

	// TODO: fill the two HALF view angles.
	// Field of view half angles: theta and phi
	// theta is the half angle in x plane. Think about why theta is such a weird value here.
	// phi is the half anlge in y plane. phi = 1/2 * the value you used in glPerspective.
	float theta = glm::radians(camera.getZoom()*(4/3)*.5);
	float phi = glm::radians(camera.getZoom()*.5);

	// Vector A = C x U
	glm::vec3 A = glm::cross(C, U);
	// The REAL up vector B = A x C
	glm::vec3 B = glm::cross(A, C);
	// View Center M = E + C
	glm::vec3 M = E+C;

	// V || B, but on NCD
	glm::vec3 V = B * (1.0f/(glm::length(B)) * (glm::length(C)*tan(-phi)));
	// H || A, but on NDC
	// If you didn't use theta here, you can simply use the ratio between this->width() and this->height()
	glm::vec3 H = A * (1.0f/(glm::length(A)) * (glm::length(C)*tan(theta)));

	// Clicking point on the screen. World Coordinate.
	glm::vec3 P = M + (2*x -1)*H + (2*y -1)*V;

	float t = 50000000;
	//float length = glm::length(P-E);
	// The ray is: where t goes from 0 to infinity
	R = E + (t*(P - E))/((glm::length(P-E)));
	glm::vec3 tbeginning = E;
	glm::vec3 tending = R;

Face* face = new Face(0, new HalfEdge(0));
	float tempt = 60000.0f;
	vector<Face*>* faces = mesh->unitfaces;
	for(int i = 0; i < faces->size(); i ++){
		if(faces->at(i)->planarity == true){
			t = getT(faces->at(i)->startingedge->normal, glm::vec3(faces->at(i)->startingedge->vertex->x,faces->at(i)->startingedge->vertex->y, faces->at(i)->startingedge->vertex->z), tbeginning, tending);
			glm::vec3 pt = getP(t, tbeginning, tending);
			glm::vec3 normal = faces->at(i)->startingedge->normal;
			Face* polygon = faces->at(i);
			polygon->hovering = false;
				//yz plane
			if((abs(normal[0]) >= abs(normal[1])) && (abs(normal[0]) >= abs(normal[2]))){
					bool check = checkWhichFace(polygon, pt, 0);
					if(check == true){
						if(tempt > 59999.0){
						tempt = t;
						face = polygon;
						}
						else if(t < tempt){
							tempt = t;
							face = polygon;
						}
					}
			}
				//xz plane
			else if((abs(normal[1]) >= abs(normal[0])) && (abs(normal[1]) >= abs(normal[2]))){
					bool check = checkWhichFace(polygon, pt, 1);
					if(check == true){
						if(tempt > 59999.0){
						tempt = t;
						face = polygon;
						}
						else if(t < tempt){
							tempt = t;
							face = polygon;
						}
					}
			}
				//xy plane
			else{
					bool check = checkWhichFace(polygon, pt, 2);
					if(check == true){
						if(tempt > 59999.0){
						tempt = t;
						face = polygon;
						}
						else if(t < tempt){
							tempt = t;
							face = polygon;
						}
					}
			}
		}
	}
	if(face->isNull == false){
	face->hovering = true;
	}
	resizeGL(641,481);
	updateGL();
}


void MyGLWidget::mousePressEvent(QMouseEvent *event){
float x = event->x();
	float y = event->y();
	std::cout << "Someone clicked " << x << ", " << y << std::endl;
	// change to normalized device coordinates
	x = x / this->width();
	y = y / this->height();

	// TODO: update the eye position;
	// world coordinate of eye
	glm::vec3 E;//
	E = glm::vec3(camera.getPos()[0], camera.getPos()[1], camera.getPos()[2]);

	// TODO: update the U vector;
	// up vector
	glm::vec3 U;
	U = glm::vec3(camera.getUp()[0], camera.getUp()[1], camera.getUp()[2]);

	// Viewing vector
	glm::vec3 center = glm::vec3(0,0,0); // assume we are focusing on the origin, if the center moves, it will be different.
	glm::vec3 C = center - E; // implies viewing distance is |C|

	// TODO: fill the two HALF view angles.
	// Field of view half angles: theta and phi
	// theta is the half angle in x plane. Think about why theta is such a weird value here.
	// phi is the half anlge in y plane. phi = 1/2 * the value you used in glPerspective.
	float theta = glm::radians(camera.getZoom()*(4/3)*.5); //theta= zoom/2 *(x/y)
	float phi = glm::radians(camera.getZoom() * .5); //zoom/2

	// Vector A = C x U
	glm::vec3 A = glm::cross(C, U);
	// The REAL up vector B = A x C
	glm::vec3 B = glm::cross(A, C);
	// View Center M = E + C
	glm::vec3 M = E+C;

	// V || B, but on view plane
	glm::vec3 V = B * (1.0f/(glm::length(B)) * (glm::length(C)*tan(-phi)));
	// H || A, but on view plane
	// If you didn't use theta here, you can simply use the ratio between this->width() and this->height() to determine the length of H
	glm::vec3 H = A * (1.0f/(glm::length(A)) * (glm::length(C)*tan(theta)));

	// Clicking point on the screen. World Coordinate.
	glm::vec3 P = M + (2*x -1)*H + (2*y -1)*V;
	std::cout << "The point is " <<P[0]<<", "<<P[1]<<", "<<P[2]<< std::endl;

	// The ray is: where t goes from 0 to infinity
	// t is float

	float t = 50000000;
	float denom = glm::length(P-E);
	glm::vec3 R = E + t*(P - E)/denom;
	ray = true;
	beginning = E;
	ending = R;
	// TODO:
	Face* face = new Face(0, new HalfEdge(0));
	float tempt = 60000.0f;
	vector<Face*>* faces = mesh->unitfaces;
	for(int i = 0; i < faces->size(); i ++){
		if(faces->at(i)->planarity == true){
			t = getT(faces->at(i)->startingedge->normal, glm::vec3(faces->at(i)->startingedge->vertex->x,faces->at(i)->startingedge->vertex->y, faces->at(i)->startingedge->vertex->z), beginning, ending);
			glm::vec3 pt = getP(t, beginning, ending);
			glm::vec3 normal = faces->at(i)->startingedge->normal;
			Face* polygon = faces->at(i);
				//yz plane
			if((abs(normal[0]) >= abs(normal[1])) && (abs(normal[0]) >= abs(normal[2]))){
					bool check = checkWhichFace(polygon, pt, 0);
					if(check == true){
						if(tempt > 59999.0){
						tempt = t;
						face = polygon;
						}
						else if(t < tempt){
							tempt = t;
							face = polygon;
						}
					}
			}
				//xz plane
			else if((abs(normal[1]) >= abs(normal[0])) && (abs(normal[1]) >= abs(normal[2]))){
					bool check = checkWhichFace(polygon, pt, 1);
					if(check == true){
						if(tempt > 59999.0){
						tempt = t;
						face = polygon;
						}
						else if(t < tempt){
							tempt = t;
							face = polygon;
						}
					}
			}
				//xy plane
			else{
					bool check = checkWhichFace(polygon, pt, 2);
					if(check == true){
						if(tempt > 59999.0){
						tempt = t;
						face = polygon;
						}
						else if(t < tempt){
							tempt = t;
							face = polygon;
						}
					}
			}
		}
	}
	if(face->isNull == false){
	setCurr(face);
	}
	updateGL();
}
bool MyGLWidget::checkWhichFace(Face* polygon, glm::vec3 p, int omitted){
bool inside = false; 
 
glm::vec2 p1; 
 
glm::vec2 p2;
glm::vec2 point;

HalfEdge* edge = polygon->startingedge;

for (int i = 0; i<polygon->edges(); i++){ // iterate through each edge
	glm::vec3 temp1 = glm::vec3(edge->vertex->x, edge->vertex->y, edge->vertex->z); //get first edge endpoint from polygon
 
	glm::vec3 temp2 = glm::vec3(edge->next->vertex->x, edge->next->vertex->y, edge->next->vertex->z); // get second edge endpoint from polygon


if(omitted == 0){
	p1 = glm::vec2(temp1[1], temp1[2]);
	p2 = glm::vec2(temp2[1], temp2[2]);
	point = glm::vec2(p[1], p[2]);
}
else if(omitted == 2){
	p1 = glm::vec2(temp1[0], temp1[1]);
	p2 = glm::vec2(temp2[0], temp2[1]);
	point = glm::vec2(p[0], p[1]);

}
else{
	p1 = glm::vec2(temp1[0], temp1[2]);
	p2 = glm::vec2(temp2[0], temp2[2]);
	point = glm::vec2(p[0], p[2]);
}


if (p1[1] > p2[1]) {
	swap(p1, p2); } //want p1 to p2 to point in +y direction
	if (point[1] > p1[1]){ //above lower edge endpoint
		if (point[1] <= p2[1]){ //below upper edge endpoint
			if (p1[1] != p2[1]){ //if edge is not horizontal do half-plane check, z of crossproduct(point-p1, p2-p1) > 0) means we’re to the right
				if ((((point[0] - p1[0])*(p2[1] - p1[1]))-((p2[0] - p1[0])*(point[1] - p1[1])))> 0)
				{
						inside = !inside;}
// if true, point is to right of edge (and thus in the “strip”)
								}
							  }
 
						}

	edge = edge->next;	
}
return inside;
}

//from swiftless.com
char* MyGLWidget::textFileRead(const char* fileName) {
    char* text;
    
    if (fileName != NULL) {
        FILE *file = fopen(fileName, "rt");
        
        if (file != NULL) {
            fseek(file, 0, SEEK_END);
            int count = ftell(file);
            rewind(file);
            
            if (count > 0) {
                text = (char*)malloc(sizeof(char) * (count + 1));
                count = fread(text, sizeof(char), count, file);
                text[count] = '\0';	//cap off the string with a terminal symbol, fixed by Cory
            }
            fclose(file);
        }
    }
    return text;
}
void MyGLWidget::printLinkInfoLog(int prog) 
{
	int infoLogLen = 0;
	int charsWritten = 0;
	GLchar *infoLog;

	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &infoLogLen);

	// should additionally check for OpenGL errors here

	if (infoLogLen > 0)
	{
		infoLog = new GLchar[infoLogLen];
		// error check for fail to allocate memory omitted
		glGetProgramInfoLog(prog,infoLogLen, &charsWritten, infoLog);
		cerr << "InfoLog:" << endl << infoLog << endl;
		delete [] infoLog;
	}
}
void MyGLWidget::printShaderInfoLog(int shader)
{
	int infoLogLen = 0;
	int charsWritten = 0;
	GLchar *infoLog;

	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);

	// should additionally check for OpenGL errors here

	if (infoLogLen > 0)
	{
		infoLog = new GLchar[infoLogLen];
		// error check for fail to allocate memory omitted
		glGetShaderInfoLog(shader,infoLogLen, &charsWritten, infoLog);
		cerr << "InfoLog:" << endl << infoLog << endl;
		delete [] infoLog;
	}

	// should additionally check for OpenGL errors here
}
void MyGLWidget::mouseReleaseEvent(QMouseEvent *e){
//mouseRelease = true;
}
/*
void MyGLWidget::mousePressEvent(QMouseEvent *e){
	mouseRelease = false;
	if(mousemode == false){
	if(e->button() == Qt::MouseButton::LeftButton){
			camera.zoom(0.1f, -1.0f);
			updateGL();
	}
	if(e->button() == Qt::MouseButton::RightButton){
			camera.zoom(1.2f, 1.0f);
			updateGL();
	}
	}
}
*/
void MyGLWidget::keyPressEvent(QKeyEvent *e){
	
	if (e->key() == Qt::Key_Up){
		camera.up();
		resizeGL(641,481);
		updateGL();
	}
	if (e->key() == Qt::Key_Down){
		camera.down();
		resizeGL(641,481);
		updateGL();
	}
	if (e->key() == Qt::Key_Left){
		camera.left();
		resizeGL(641,481);
		updateGL();
	}
	if (e->key() == Qt::Key_Right){
		camera.right();
		resizeGL(641,481);
		updateGL();
	}
	if (e->key() == Qt::Key_I){
		camera.zoomIn();
		resizeGL(641,481);
		updateGL();
	}
	if (e->key() == Qt::Key_O){
		camera.zoomOut();
		resizeGL(641,481);

		updateGL();
	}
}
void MyGLWidget::resizeGL(int width, int height) {
    //set the viewport, more boilerplate
	glViewport(0, 0, width, height);

	// The current view matrix is calculated by hand/magic... you should come up with your own method to get the view matrix.
	// be ware that those glm matrices are all COLUMN MAJOR.
	glm::mat4 view = camera.returnView();

	//set the projection matrix here, it only needs to be changed if the screen is resized otherwise it can stay the same
	glUniformMatrix4fv(u_projMatrixLocation, 1, GL_FALSE, &view[0][0]);
}

void MyGLWidget::updateFilename(QString s){
	filename = s;
}
/*
void MyGLWidget::loadVert(){
	string line;
	filename =QFileDialog::getOpenFileName(this,tr("Open File"), "S:\\mayaWorkingCopy", tr("diffuse Vert Files (*.vert)"));
	QByteArray ba = filename.toLatin1();
	const char* vert = (const char*)(ba.data()); //convert qstring to const char*
	ifstream file (vert, ifstream::in);
	if (file.is_open()){
	*/

void MyGLWidget::loadFrag(){
	string line;
	filename =QFileDialog::getOpenFileName(this,tr("Open File"), "S:\\mayaWorkingCopy", tr("diffuseFrag Files (*.frag)"));
	QByteArray ba = filename.toLatin1();
	const char* frag = (const char*)(ba.data()); //convert qstring to const char*
	ifstream file (frag, ifstream::in);
	if (file.is_open()){

		ofstream os ("frag.frag", ofstream::out);
		while (file.good()){
			getline (file,line);
			 os << line << endl;
		}
	}initializeGL();
	updateGL();
}

void MyGLWidget::loadFile(){

	fileVertices = vector<Vertex*>();
	fileFaces = vector<Face*>();
	halfEdges = vector<HalfEdge*>();
	string line;
	int currentVertex = 1; //this will be the ID for the vertices; start at 1 because the .obj format starts at 1
	//for a vertex, its ID is its index in the .obj file
	int currentHE = 0;
	int currentFace = 0;
	filename = QFileDialog::getOpenFileName(this,
     tr("Open File"), "S:\\mayaWorkingCopy", tr("Image Files (*.obj)"));
	//ifstream file ("S:/mayaWorkingCopy/277repo/minimaya/cow.obj", ifstream::in);
	//ifstream file (filename.toStdString(), ifstream::in);
	//ifstream file (("S:\\mayaWorkingCopy\\277repo\\minimaya\\" + filename.toStdString()), ifstream::in);

	QByteArray ba = filename.toLatin1();
	const char* lol = (const char*)(ba.data()); //convert qstring to const char*
	ifstream file (lol, ifstream::in);

	if (file.is_open()){
		while (file.good()){
			getline(file, line, '\n');
			//make a stringstream from line
			//cout << line << endl;
			istringstream ss (line, stringstream::in | stringstream::out);
			string type;
			getline(ss, type, ' ');
			//cout << "type:" << type << endl;

			if (type == "v"){ //VERTEX
				
				string xstring, ystring, zstring;
				//getline(ss, xstring, ' ');
				getline(ss, xstring, ' '); //get the first float, the x value
				//getline(ss, ystring, ' ');
				getline(ss, ystring, ' '); //get the y value
				//getline(ss, zstring, ' ');
				getline(ss, zstring, ' '); //get the z value
				
				float x = atof(xstring.c_str());
				float y = atof(ystring.c_str());
				float z = atof(zstring.c_str());

				Vertex* newVertex = new Vertex(x, y, z, currentVertex); //make a vertex with the values
				fileVertices.push_back(newVertex);  //store it
				currentVertex++; 
			}


			else if (type == "f"){ //FACE
				string empty, vertexinfo;
				vector<Vertex*> faceVertices = vector<Vertex*>();
				vector<HalfEdge*> faceHEs = vector<HalfEdge*>();
				while (ss.good()) {
					//getline(ss, empty, ' ');
					getline(ss, vertexinfo, ' ');

					/*if(!ss.good()) {
						break;
					}

					if(vertexinfo == "") {
						continue;
					}*/
					
					
					int index = vertexinfo.find_first_of('/');
					if (index > 0)
						vertexinfo = vertexinfo.substr(0, index);
					int vindex = atoi(vertexinfo.c_str());
					Vertex* v = fileVertices[vindex-1];
					faceVertices.push_back(v); 
					//get the vertex, add it to the vector of the face's vertices
					//do this until the line is empty
				}

				for (int i = 0; i < faceVertices.size(); i++){ //now we have all the vertices in a vector,
					//need to make HEs

					Vertex* v1 = faceVertices[i];

					HalfEdge* HE = new HalfEdge(currentHE);
					currentHE++;
					HE->vertex = v1;

					halfEdges.push_back(HE);
					faceHEs.push_back(HE);
					//make a HE for the vertex, store it
					//HEs all have vertex set
				}
				Face* f = new Face(faceHEs[0], 1.0f, 1.0f, 1.0f, currentFace);
				currentFace++;

				//set up faces, prevs, nexts - for all EXCEPT the last one
				for (int i = 0; i < faceHEs.size()-1; i++){
					HalfEdge* HE = faceHEs[i];
					HalfEdge* HE2 = faceHEs[i+1];
					HE->face = f;
					HE->next = HE2;
					HE2->prev = HE;
				}
				//NOTE:  last one has nothing set, first one does not have prev set
				faceHEs[0]->prev = faceHEs[faceHEs.size()-1];
				HalfEdge* last = faceHEs[faceHEs.size()-1];
				last->face = f;
				last->next = faceHEs[0];

				//NOW all faces, vertices, prevs, and nexts are done.  need endvs
				for (int i = 0; i < faceHEs.size(); i++){
					HalfEdge* HE = faceHEs[i];
					HE->endv = HE->next->vertex;
				}

				fileFaces.push_back(f);
			} 
			else { //We don't care about vn or vt?

			}
		}
     
    file.close();
	setUpSyms();
	mesh = new Mesh();
	mesh->unitfaces = &fileFaces;
	mesh->unitvertexes = &fileVertices;
	cout << "mesh replaced" << endl;
	//cout << "number of vertices in file = " << fileVertices.size();
	//cout << "number of faces in file = " << fileFaces.size();
	updateGL();
	//populateLists();
	deformer = Deformer(fileFaces, fileVertices);
	deformer.xdiv = 5;
	deformer.ydiv = 5;
	deformer.zdiv = 5;
	deformer.getBounds();
	deformer.makeControlPoints();
	//deformer.fillPoints();
	deformer.drawPoints();
	controlPoints = deformer.allPoints;
	populateLists();

  }
  else cout << "Unable to open file"; 
}

void MyGLWidget::setUpSyms(){
	for (int i = 0; i < halfEdges.size(); i++){
		for (int j = 0; j < halfEdges.size(); j++){
			HalfEdge* HE1 = halfEdges[i];
			HalfEdge* HE2 = halfEdges[j];
			if ((HE1->vertex == HE2->endv) && (HE1->endv == HE2->vertex)){
				HE1->sym = HE2;
				HE2->sym = HE1;
			}
		}
	}
}

void MyGLWidget::saveFile(){
	ofstream os ("S:/mayaWorkingCopy/277repo/minimaya/newfile.obj", ofstream::out);

	for (int i = 0; i < fileVertices.size(); i++){ 
		//for every vertex, print a V followed by its coordinates
		os << "v ";
		os << fileVertices[i]->x << " ";
		os << fileVertices[i]->y << " ";
		os << fileVertices[i]->z << " ";
		os << "\n";
		cout << "v ";
		cout << fileVertices[i]->x << " ";
		cout << fileVertices[i]->y << " ";
		cout << fileVertices[i]->z << " " << endl;
	}

	for (int i = 0; i < fileFaces.size(); i++){
		os << "f ";
		cout << "f ";
		Face* f = fileFaces[i];
		HalfEdge* edge = f->startingedge;
		for (int j = 0; j < f->edges(); j++){ //do this for every vertex
			Vertex* v = edge->vertex;
			os << v->id;
			if (j != f->edges()-1)
			    os <<  " ";
			cout << v->id << " ";
			edge = edge->next;
		}
		if (i != fileFaces.size() - 1)
		    os << "\n";
		cout << endl;
	}
	cout << "end of saveFile method" << endl;
}

void MyGLWidget::getXDiv(int i){
	deformer.setXDiv(i);
	populateLists();
}

void MyGLWidget::getYDiv(int i){
	deformer.setYDiv(i);
	populateLists();
}

void MyGLWidget::getZDiv(int i){
	deformer.setZDiv(i);
	populateLists();
}

void MyGLWidget::ffd(){
	for (int i = 0; i < fileVertices.size(); i++){
		Vertex* v = fileVertices[i];
		deformer.deform(v);
	}
	cout<< "deform done" << endl;
	updateGL();
}

void MyGLWidget::toggleDeform(){
	deformOn = !deformOn;
	currentv = halfEdges[0]->vertex;
}

void MyGLWidget::twistmesh(){
	deformer.twist(twistval, axis);
	ffd();
}

void MyGLWidget::taperMesh(){
	deformer.taper(taperval, axis);
	ffd();
}

void MyGLWidget::bendMesh(){
	deformer.bend(bendMin, bendMax, bendval, axis);
	ffd();
}

void MyGLWidget::setTwistval(double f){
	twistval = f;
}

void MyGLWidget::setTaperval(double f){
	taperval = f;
}

void MyGLWidget::setBendval(double f){
	bendval = f;
}

void MyGLWidget::setBendMin(double f){
	bendMin = f;
}

void MyGLWidget::setBendMax(double f){
	bendMax = f;
}

void MyGLWidget::twistX(){
	axis = "X";
}

void MyGLWidget::twistY(){
	axis = "Y";
}

void MyGLWidget::twistZ(){
	axis = "Z";
}