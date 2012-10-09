#include <QKeyEvent>
#include "../glm/glm.hpp"

#ifndef MYCAMERA_H
#define MyCAMERA_H

class myCamera{

	/*position, center of world, upsideVector*/
public:
	myCamera();
	glm::vec4 position;
	glm::vec4 upVec;
	float zoom;
	float getZoom();
	glm::vec4 getUp();
	glm::vec4 getPos();
	glm::vec3 compress(glm::vec4);
	glm::mat4 returnView();
	glm::vec3 center;
	/*camera has view
	upvector of view port changing */
	void up();
	void down();
	void left();
	void right();
	void zoomIn();
	void zoomOut();
	void pLeft();
};

#endif