#include "myCamera.h"
#include "../glm/gtc/matrix_transform.hpp"

myCamera::myCamera(){
	position = glm::vec4(5,5,5,0);
	zoom = 45.0f;
	upVec = glm::vec4(0.0f,1.0f,0.0f,0.0f);
	center = glm::vec3(0,0,0);
}

glm::vec3 myCamera::compress(glm::vec4 vec){
	return glm::vec3(vec[0], vec[1], vec[2]);
}

glm::mat4 myCamera::returnView(){
	glm::mat4 camMat = glm::lookAt(compress(position), center, compress(upVec));
	glm::mat4 projectMat = glm::perspective(zoom, (4.0f/3.0f), .1f, 100.0f); 
	return projectMat*camMat;
}

void myCamera::up(){
	position = position*(glm::rotate(glm::mat4(1.0f), -5.0f, glm::cross(compress(position), compress(upVec))));
	upVec=upVec*(glm::rotate(glm::mat4(1.0f), -5.0f, glm::cross(compress(position), compress(upVec))));
}
void myCamera::down(){
	position = position*(glm::rotate(glm::mat4(1.0f), 5.0f, glm::cross(compress(position), compress(upVec))));
	upVec=upVec*(glm::rotate(glm::mat4(1.0f), 5.0f, glm::cross(compress(position), compress(upVec))));
}
void myCamera::left(){
	position = position*(glm::rotate(glm::mat4(1.0f), 5.0f, compress(upVec)));
	upVec=upVec*(glm::rotate(glm::mat4(1.0f), 5.0f, compress(upVec)));
}
void myCamera::right(){
	position = position*(glm::rotate(glm::mat4(1.0f), -5.0f, compress(upVec)));
	upVec=upVec*(glm::rotate(glm::mat4(1.0f), -5.0f, compress(upVec)));
}

void myCamera::zoomIn(){
	zoom=zoom-3;
	if (zoom<=0){
		zoom =0;
	}
}

void myCamera::zoomOut(){
	zoom=zoom+3;
	if (zoom>=180){
		zoom=180;
	}
}

glm::vec4 myCamera::getPos(){
	return position;
}

glm::vec4 myCamera::getUp(){
	return upVec;
}

float myCamera::getZoom(){
	return zoom;
}

void myCamera::pLeft(){
	position[0]=position[0]-1;
}