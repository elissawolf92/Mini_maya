#include "mesh.h"
#include <iostream>

Mesh::Mesh(){
	created = 1;
	create2 = 1;
}
Mesh::~Mesh(){}

void Mesh::vertexintoedge(HalfEdge* hO){
	Vertex* vn = new Vertex();

	Face* thisface = hO->face;
	Face* symface = hO->sym->face;

	if(thisface->edges() == 4){
	quadintotwotriangles(thisface);
	}
	if(symface->edges() == 4){
	quadintotwotriangles(symface);
	}

	HalfEdge* next = hO->next;
	hO->isNew = false;
	HalfEdge* sym = hO->sym;
	sym->isNew = false;

	HalfEdge* second = new HalfEdge(create2);
	create2++;
	second->isNew = false;
	HalfEdge* secondsym = new HalfEdge(create2);
	create2++;
	secondsym->isNew = false;

	second->face = hO->face;
	second->vertex = vn;
	second->endv = hO->next->vertex;
	second->sym = secondsym;
	second->next = hO->next;
	second->prev = hO;
	hO->next->prev = second;
	hO->next = second;
	hO->endv = vn;

	secondsym->face = sym->face;
	secondsym->endv = vn;
	secondsym->sym = second;
	secondsym->next = sym;
	secondsym->vertex = sym->prev->endv;
	secondsym->prev = sym->prev;
	sym->prev->next = secondsym;
	sym->prev = secondsym;
	sym->vertex = vn;

unitvertexes->push_back(vn);
average(hO->vertex,	second->next->vertex, vn); //pseudo-code//

}

void Mesh::edgeFacePoint(Face* poly){
	HalfEdge* c = poly->startingedge;
	if(c->vertex->original == false){
		c = c->prev;
		poly->startingedge = c;
	}

	vector<Face*>* newfaces = new vector<Face*>();
	int numfaces = (poly->edges()/2);
	int num2 = numfaces;
	Vertex* vn = poly->facepoint;

	unitvertexes->push_back(vn);
	
	while(numfaces>0){
	Face* temp = new Face(created);
	created++;
	newfaces->push_back(temp);
	numfaces--;
	}

	for(int i = 0; i < newfaces->size(); i++){
	Face* face = newfaces->at(i);
	HalfEdge* one = new HalfEdge(create2);
	create2++;
	HalfEdge* two = new HalfEdge(create2);
	create2++;

	HalfEdge* tempsym = c->prev->prev;
	
	one->face = face;
	two->face = face;
	two->endv = vn;
	one->endv = tempsym->endv;
	one->vertex = vn;
	two->vertex = c->endv;
	two->prev = c;
	one->prev = two;
	one->next = c->prev;
	two->next = one;
	one->sym = tempsym;
	c->prev->prev = one;	
	c->next = two;
	two->sym = NULL;
	c->face = face;
	c->prev->face = face;

	face->startingedge = c;
	face->red = poly->red;
	face->green = poly->green;
	face->blue = poly->blue;

	tempunitfaces->push_back(face);
	c = tempsym;
	}
}

void Mesh::vertexintoedge2(HalfEdge* hO, Vertex* vn){
	Face* thisface = hO->face;
	Face* symface = hO->sym->face;

	HalfEdge* next = hO->next;
	hO->isNew = false;
	HalfEdge* sym = hO->sym;
	sym->isNew = false;

	HalfEdge* second = new HalfEdge(create2);
	second->isNew = false;
	create2++;
	HalfEdge* secondsym = new HalfEdge(create2);
	secondsym->isNew = false;
	create2++;

	second->face = hO->face;
	second->vertex = vn;
	second->endv = hO->next->vertex;
	second->sym = secondsym;
	second->next = hO->next;
	second->prev = hO;
	hO->next->prev = second;
	hO->next = second;
	hO->endv = vn;

	secondsym->face = sym->face;
	secondsym->endv = vn;
	secondsym->sym = second;
	secondsym->next = sym;
	secondsym->vertex = sym->prev->endv;
	secondsym->prev = sym->prev;
	sym->prev->next = secondsym;
	sym->prev = secondsym;
	sym->vertex = vn;

unitvertexes->push_back(vn);
}

void Mesh::createEdges(){
	for(int m = 0; m < unitvertexes->size(); m++){
		Vertex* tt = unitvertexes->at(m);
		tt->original = true;
	}
	for(int cc = 0; cc < unitfaces->size(); cc++){
		Face* poly = unitfaces->at(cc);
		poly->facepoint = calculateCentroid(poly);
		std::cout<<poly->id<<endl;
	}

	for(int i = 0; i < unitfaces->size(); i++){
		HalfEdge* s = unitfaces->at(i)->startingedge;
		HalfEdge* c = unitfaces->at(i)->startingedge;
		do{
			c->isNew = true;
			c->edgepoint = calculateEdgePoint(c);
			c = c->next;
		}while(c != s);
	}
	int temp = unitfaces->size();
	movePts();

	for(int i = 0; i < temp; i++){
		HalfEdge* s = unitfaces->at(i)->startingedge;
		HalfEdge* c = unitfaces->at(i)->startingedge;
		do{
		if(c->isNew == true){
		vertexintoedge2(c, c->edgepoint);
		}
		c = c->next;
		}
		while(c != s);
	}
	tempunitfaces = new vector<Face*>();

	for(int i = 0; i < temp; i++){
	edgeFacePoint(unitfaces->at(i));
	}

	for(int x = 0; x < tempunitfaces->size(); x++){
		HalfEdge* h1 = tempunitfaces->at(x)->startingedge;
		h1 = h1->prev->prev;
		h1->sym = h1->sym->next;
		h1->sym->sym = h1;
	}
	unitfaces = tempunitfaces;

for(int k = 0; k<unitvertexes->size(); k++){
	Vertex* temp = unitvertexes->at(k);
	if(temp->original == true){
	temp->x = temp->tempx;
	temp->y = temp->tempy;
	temp->z = temp->tempz;
}
}
}

Vertex* Mesh::calculateCentroid(Face* fa){
	Vertex* v;
	float edges = fa->edges();
	HalfEdge* s = fa->startingedge;
	HalfEdge* c = fa->startingedge;
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	
	do{
		Vertex* vn = c->vertex;
		x = x + vn->x;
		y = y + vn->y;
		z = z + vn->z;
		c = c->next;
	}while(s != c);


	x = (x/edges);
	y = (y/edges);
	z = (z/edges);

	v = new Vertex(x, y, z, 0);

	v->set(false);
	return v;
}
Vertex* Mesh::calculateEdgePoint(HalfEdge* edge){
		Vertex* a = edge->vertex;
		Vertex* b = edge->endv;
		Vertex* c = edge->face->facepoint;
		Vertex* d = edge->sym->face->facepoint;
//	std::cout<<""<<endl;
//	std::cout<< "face->facepoint: " << c->x<<","<<c->y<<","<<c->z<<endl;
//	std::cout<<edge->face->id<<endl;
//	std::cout<< "symface->facepoint: " << d->x<<","<<d->y<<","<<d->z<<endl;
//	std::cout<<edge->sym->face->id<<endl;

		float x = ((a->x + b->x + c->x + d->x)/4);
		float y = ((a->y + b->y + c->y + d->y)/4);
		float z = ((a->z + b->z + c->z + d->z)/4);

		Vertex* v = new Vertex(x, y, z, 0);
		v->set(false);

//	std::cout<< "edgepoint: " << v->x<<","<<v->y<<","<<v->z<<endl;

		return v;
}

void Mesh::movePts(){
	for(int j = 0; j<unitvertexes->size(); j++){
	Vertex* curr = unitvertexes->at(j);

	vector<Vertex*> f = vector<Vertex*>();
	vector<Vertex*> r = vector<Vertex*>();
	for(int i = 0; i < unitfaces->size(); i++){
		int c = unitfaces->at(i)->hasV(curr);
	if(c < 5){
			f.push_back(unitfaces->at(i)->facepoint);
//			std::cout<<"fp: "<< unitfaces->at(i)->facepoint->x<<" "<< unitfaces->at(i)->facepoint->y<<" " << unitfaces->at(i)->facepoint->z<<endl;
			r.push_back(unitfaces->at(i)->midpoint(curr));
//			std::cout<<"i: "<<i<<endl;
		}
	}
//	std::cout<<""<<endl;
	Vertex* tot1 = new Vertex(0, 0, 0, 0);
	for(int i = 0; i < f.size(); i++){
		Vertex* v = f.at(i);
//		std::cout<<i << ": " << v->x<<","<<v->y<<","<<v->z<<endl;
		tot1->x = tot1->x + v->x;
		tot1->y = tot1->y + v->y;
		tot1->z = tot1->z + v->z;
	}

	Vertex* tot2 = new Vertex(0, 0, 0, 0);
	for(int i = 0; i < r.size(); i++){
		Vertex* v = r.at(i);
//		std::cout<<i << ": " << v->x<<","<<v->y<<","<<v->z<<endl;
		tot2->x = tot2->x + v->x;
		tot2->y = tot2->y + v->y;
		tot2->z = tot2->z + v->z;
	}

//	std::cout<<tot1->x<<","<<tot1->y<<","<<tot1->z<<endl;
//	std::cout<<tot2->x<<","<<tot2->y<<","<<tot2->z<<endl;
//	std::cout<<curr->x<<","<<curr->y<<","<<curr->z<<endl;
//	std::cout<<"f: " << f.size()<<endl;
//	std::cout<<"r: " << r.size()<<endl;
	float fsize = f.size();

	if(fsize > 0){
	float x, y, z, oneOverNSquared;
	oneOverNSquared = (1.0f/(fsize*fsize));

//	std::cout<<"oneOverNSquared: " <<oneOverNSquared <<endl;

	 x = (oneOverNSquared*tot1->x + oneOverNSquared*tot2->x + ((fsize - 2.0f)/fsize)*curr->x);
	 y = (oneOverNSquared*tot1->y + oneOverNSquared*tot2->y + ((fsize - 2.0f)/fsize)*curr->y);
	 z = (oneOverNSquared*tot1->z + oneOverNSquared*tot2->z + ((fsize - 2.0f)/fsize)*curr->z);

//	std::cout<<x<<","<<y<<","<<z<<endl;
//	std::cout<<""<<endl;

	curr->tempx = x;
	curr->tempy = y;
	curr->tempz = z;
	}

	}
}

void Mesh::average(Vertex* v1, Vertex* v2, Vertex* vfinal){
float v1x = v1->x;
float v1y = v1->y;
float v1z = v1->z;

float v2x = v2->x;
float v2y = v2->y;
float v2z = v2->z;

vfinal->x = ((v2x +v1x)/2);
vfinal->y = ((v2y +v1y)/2);
vfinal->z = ((v2z +v1z)/2);
}

void Mesh::edgebtwntwofaces(Face* fa, Face* fb){

	if(fa->edges() == 4){
	quadintotwotriangles(fa);
	}
	if(fb->edges() == 4){
	quadintotwotriangles(fb);
	}

	HalfEdge* a = fa->startingedge;
	HalfEdge* b = fb->startingedge;
	Vertex* temp;
	Vertex* temp2;

	for(int i = 0; i <fa->edges(); i++){
		temp = a->vertex;
		for(int j = 0; j <fb->edges(); j++){
			temp2 = b->vertex;
			if(temp == temp2){
			break;
			}
			b = b->next;
		}
		if(temp == temp2){
		break;
		}
		a = a->next;
	}
	bool dontgo = false;
		for(int i = 0; i <fa->edges(); i++){
		for(int j = 0; j <fb->edges(); j++){
			if(a == b){
			dontgo = true;
			break;
			}
			b = b->next;
		}
		if(a == b){
		dontgo = true;
		break;
		}
		a = a->next;
	}

if(temp == temp2 && dontgo==false){
Vertex *V1 = new Vertex((temp->x),(temp->y), (temp->z), 0);

unitvertexes->push_back(V1);

HalfEdge *HENL = new HalfEdge(create2); //HE New Left //
create2++;
HalfEdge *HENR = new HalfEdge(create2); //HE New Right//
create2++;

HENL->sym = HENR;
HENR->sym = HENL;

HENL->prev = a->prev;
HENR->prev = b->prev;

HENL->next = a;
HENR->next = b;

HENL->vertex = V1;
HENR->vertex = b->vertex;

HENL->endv = a->vertex;
HENR->endv = V1;

HENL->prev = a->prev;
HENR->prev = b->prev;

HENL->face = fa;
HENR->face = fb;

a->prev->next = HENL;
a->prev = HENL;

b->prev->next = HENR;
b->prev = HENR;

HalfEdge* temporary = HENL->prev;
HalfEdge* tempsym = temporary->sym;

while(tempsym != b){
	temporary->endv = V1;
	tempsym->vertex = V1;
	temporary = tempsym->prev;
	tempsym = temporary->sym;
}

temporary->endv = V1;
tempsym->vertex = V1;

}
}

void Mesh::quadintotwotriangles(Face* one){

if(one->startingedge->next->next->next->next == one->startingedge){
HalfEdge* HE0 = one->startingedge; //starting edge//
HalfEdge *HER;
Face* two = new Face(HER, 1, 1, 1, created);
created++;
unitfaces->push_back(two);

HalfEdge *HEL = new HalfEdge(create2); //HE New Left //
create2++;
HER = new HalfEdge(create2); //HE New Right//
create2++;

HEL->face = one;
HER->face = two;

//FACE1 still points to its starting edge HE0, //
//and will contain the new HEL in its loop; //
//new FACE2 points to HER as its new starting edge//

HEL->sym = HER;
HER->sym = HEL;
HEL->next = HE0;
HER->next = HE0->next->next;
HEL->prev = HE0->next;
HER->prev = HE0->prev;
HER->endv = HE0->next->endv;
HEL->endv = HE0->vertex;
HER->vertex = HE0->vertex;
HEL->vertex = HE0->next->endv;

HE0->prev->face = two;
HE0->prev->next = HER;
HE0->next->next->face = two;
HE0->next->next->prev = HER;

HE0->prev = HEL;
HE0->next->next = HEL;

two->startingedge = HER;

//Vertex* m = new Vertex(0, 0, 0, 0);
//average(HEL->vertex, HEL->endv, m);
//vertexintoedge2(HEL, m);
}
}

void Mesh::unitcube(){
Vertex* vone = new Vertex();
Vertex* vtwo = new Vertex();
Vertex* vthree = new Vertex();
Vertex* vfour = new Vertex();
Vertex* vfive = new Vertex();
Vertex* vsix = new Vertex();
Vertex* vseven = new Vertex();
Vertex* veight = new Vertex();

HalfEdge* hone = new HalfEdge(create2);
create2++;
HalfEdge* htwo = new HalfEdge(create2);
create2++;
HalfEdge* hthree = new HalfEdge(create2);
create2++;
HalfEdge* hfour = new HalfEdge(create2);
create2++;

HalfEdge* hfive = new HalfEdge(create2);
create2++;
HalfEdge* hsix = new HalfEdge(create2);
create2++;
HalfEdge* hseven = new HalfEdge(create2);
create2++;
HalfEdge* height = new HalfEdge(create2);
create2++;

HalfEdge* hnine = new HalfEdge(create2);
create2++;
HalfEdge* hten = new HalfEdge(create2);
create2++;
HalfEdge* heleven = new HalfEdge(create2);
create2++;
HalfEdge* htwelve = new HalfEdge(create2);
create2++;

HalfEdge* hthirteen = new HalfEdge(create2);
create2++;
HalfEdge* hfourteen = new HalfEdge(create2);
create2++;
HalfEdge* hfifteen = new HalfEdge(create2);
create2++;
HalfEdge* hsixteen = new HalfEdge(create2);
create2++;

HalfEdge* hseventeen = new HalfEdge(create2);
create2++;
HalfEdge* heighteen = new HalfEdge(create2);
create2++;
HalfEdge* hnineteen = new HalfEdge(create2);
create2++;
HalfEdge* htwenty = new HalfEdge(create2);
create2++;


HalfEdge* htwentyone = new HalfEdge(create2);
create2++;
HalfEdge* htwentytwo = new HalfEdge(create2);
create2++;
HalfEdge* htwentythree = new HalfEdge(create2);
create2++;
HalfEdge* htwentyfour = new HalfEdge(create2);
create2++;


//nexts
hone->next = htwo;
htwo->prev = hone;
htwo->next = hthree;
hthree->prev = htwo;
hthree->next = hfour;
hfour->prev = hthree;
hfour->next = hone;
hone->prev = hfour;

hfive->next = hsix;
hsix->prev = hfive;
hsix->next = hseven;
hseven->prev = hsix;
hseven->next = height;
height->prev = hseven;
height->next = hfive;
hfive->prev = height;

hnine->next = hten;
hten->prev = hnine;
hten->next = heleven;
heleven->prev = hten;
heleven->next = htwelve;
htwelve->prev = heleven;
htwelve->next = hnine;
hnine->prev = htwelve;

hthirteen->next = hfourteen;
hfourteen->prev = hthirteen;
hfourteen->next = hfifteen;
hfifteen->prev = hfourteen;
hfifteen->next = hsixteen;
hsixteen->prev = hfifteen;
hsixteen->next = hthirteen;
hthirteen->prev = hsixteen;

hseventeen->next = heighteen;
heighteen->prev = hseventeen;
heighteen->next = hnineteen;
hnineteen->prev = heighteen;
hnineteen->next = htwenty;
htwenty->prev = hnineteen;
htwenty->next = hseventeen;
hseventeen->prev = htwenty;

htwentyone->next = htwentytwo;
htwentytwo->prev = htwentyone;
htwentytwo->next = htwentythree;
htwentythree->prev = htwentytwo;
htwentythree->next = htwentyfour;
htwentyfour->prev = htwentythree;
htwentyfour->next = htwentyone;
htwentyone->prev = htwentyfour;

//pairs
hone->sym = htwentythree;
htwo->sym = hnineteen;
hthree->sym = hfive;
hfour->sym = hfifteen;

hfive->sym = hthree;
hsix->sym = heighteen;
hseven->sym = hnine;
height->sym = hsixteen;

hnine->sym = hseven;
hten->sym = hseventeen;
heleven->sym = htwentyone;
htwelve->sym = hthirteen;

hthirteen->sym = htwelve;
hfourteen->sym = htwentyfour;
hfifteen->sym = hfour;
hsixteen->sym = height;

hseventeen->sym = hten;
heighteen->sym = hsix;
hnineteen->sym = htwo;
htwenty->sym = htwentytwo;

htwentyone->sym = heleven;
htwentytwo->sym = htwenty;
htwentythree->sym = hone;
htwentyfour->sym = hfourteen;


Face* fone = new Face(hone, 1.0f, 0.0f, 0.0f, created);
created++;
Face* ftwo = new Face(hfive, 0.0f, 1.0f, 0.0f, created);
created++;
Face* fthree = new Face(hnine, 0.0f, 0.0f, 1.0f,created);
created++;
Face* ffour = new Face(hfourteen, 1.0f, 1.0f, 0.0f, created);
created++;
Face* ffive = new Face(htwenty, 0.0f, 1.0f, 1.0f, created);
created++;
Face* fsix = new Face(htwentyone, 1.0f, 0.0f, 1.0f, created);
created++;

unitfaces = new vector<Face*>();
unitfaces->push_back(fone);
unitfaces->push_back(ftwo);
unitfaces->push_back(fthree);
unitfaces->push_back(ffour);
unitfaces->push_back(ffive);
unitfaces->push_back(fsix);

//face and vertex to half edge
hone->add(fone, vone);
htwo->add(fone, vtwo);
hthree->add(fone, vthree);
hfour->add(fone, vfour);

hfive->add(ftwo, vfour);
hsix->add(ftwo, vthree);
hseven->add(ftwo, vsix);
height->add(ftwo, vfive);

hnine->add(fthree, vfive);
hten->add(fthree, vsix);
heleven->add(fthree, vseven);
htwelve->add(fthree, veight);

hthirteen->add(ffour, vfive);
hfourteen->add(ffour, veight);
hfifteen->add(ffour, vone);
hsixteen->add(ffour, vfour);

hseventeen->add(ffive, vseven);
heighteen->add(ffive, vsix);
hnineteen->add(ffive, vthree);
htwenty->add(ffive, vtwo);

htwentyone->add(fsix, veight);
htwentytwo->add(fsix, vseven);
htwentythree->add(fsix, vtwo);
htwentyfour->add(fsix, vone);

hone->endv = hone->next->vertex;
htwo->endv = htwo->next->vertex;
hthree->endv = hthree->next->vertex;
hfour->endv = hfour->next->vertex;

hfive->endv = hfive->next->vertex;
hsix->endv = hsix->next->vertex;
hseven->endv = hseven->next->vertex;
height->endv = height->next->vertex;

hnine->endv = hnine->next->vertex;
hten->endv = hten->next->vertex;
heleven->endv = heleven->next->vertex;
htwelve->endv = htwelve->next->vertex;

hthirteen->endv = hthirteen->next->vertex;
hfourteen->endv = hfourteen->next->vertex;
hfifteen->endv = hfifteen->next->vertex;
hsixteen->endv = hsixteen->next->vertex;

hseventeen->endv = hseventeen->next->vertex;
heighteen->endv = heighteen->next->vertex;
hnineteen->endv = hnineteen->next->vertex;
htwenty->endv = htwenty->next->vertex;

htwentyone->endv = htwentyone->next->vertex;
htwentytwo->endv = htwentytwo->next->vertex;
htwentythree->endv = htwentythree->next->vertex;
htwentyfour->endv = htwentyfour->next->vertex;


//vertices
vone->vertices(-1.0, 1.0, 1.0);
vtwo->vertices(1.0, 1.0, 1.0);
vthree->vertices(1.0, -1.0, 1.0);
vfour->vertices(-1.0, -1.0, 1.0);

vfive->vertices(-1.0, -1.0, -1.0);
vsix->vertices(1.0, -1.0, -1.0);
vseven->vertices(1.0, 1.0, -1.0);
veight->vertices(-1.0, 1.0, -1.0);

unitvertexes = new vector<Vertex*>();
unitvertexes->push_back(vone);
unitvertexes->push_back(vtwo);
unitvertexes->push_back(vthree);
unitvertexes->push_back(vfour);
unitvertexes->push_back(vfive);
unitvertexes->push_back(vsix);
unitvertexes->push_back(vseven);
unitvertexes->push_back(veight);

}

void Mesh::deletevertex(Vertex* todelete){
	vector<Face*>* faces = unitfaces;
	int howmanydeleted = 0;
	int temp = faces->size();
	for(int i = 0; i<temp; i++){
		Face* start = faces->at(i-howmanydeleted);
		HalfEdge* curr = start->startingedge;
		HalfEdge* prev = curr;
		HalfEdge* next = curr->next;
		Vertex* v = curr->vertex;

		if(v == todelete){
			start->startingedge = next;
			while(curr != next){
			prev = next;
			next = next->next;
			}
			prev->next = curr->next;
			vector<Vertex*>* temp = new vector<Vertex*>();
			for(int i = 0; i<unitvertexes->size(); i++){
				if(v != unitvertexes->at(i)){
				temp->push_back(unitvertexes->at(i));
				}
			}
			unitvertexes = temp;
		}
		else{
			while(curr != next){
				v = next->vertex;
				if(v == todelete){
					prev->next = next->next;
				vector<Vertex*>* temp = new vector<Vertex*>();
				for(int i = 0; i<unitvertexes->size(); i++){
					if(v != unitvertexes->at(i)){
					temp->push_back(unitvertexes->at(i));
					}
				}
				unitvertexes = temp;
				
				}
				prev = next;
				next = next->next;
			}
		}
		curr = start->startingedge;
		next = curr->next;
		int count = 1;
		while(curr!=next){
			next = next->next;
			count++;
		}
		if(count <= 2){
		int number = i-howmanydeleted;
		faces->erase(faces->begin() + number);
		howmanydeleted++;
		}

	}
}

void Mesh::redoVertices(){
	while(unitvertexes->empty() == false){
		unitvertexes->pop_back();
	}
	for(int i = 0; i<unitfaces->size(); i++){
		Face* temp = unitfaces->at(i);
		HalfEdge* a = temp->startingedge;
		HalfEdge* b = temp->startingedge->next;
		Vertex* vert = a->vertex;
		if(contains(unitvertexes, vert) == false){
		unitvertexes->push_back(vert);
		}
		while(b != a){
			vert = b->vertex;
			if(contains(unitvertexes, vert) == false){
				unitvertexes->push_back(vert);
			}
			b = b->next;
		}
	}
}

bool Mesh::contains(vector<Vertex*>* v, Vertex* tf){
	for(int i = 0; i<v->size(); i++){
	Vertex* v2 = v->at(i);
	if(v2 == tf){
	return true;
	}
	}
	return false;

}