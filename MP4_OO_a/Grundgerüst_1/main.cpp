#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.h"

struct Position{
  int x;
  int y;
  Position(int x_=0, int y_=0){ x=x_;y=y_;}
};

class Point{
protected:
  Position _position;
  Colors _color;
public:
  Point(int x=0, int y=0, Colors color = Colors::RED);
  void draw();
};

Point::Point(int x, int y, Colors color){
  _position = Position(x,y);
  _color = color;
}

void Point::draw(){
  ansiConsole.printText(_position.x,_position.y,"*", _color);
}

class Circle{
protected:
  Position  _position;
  int       _radius;
  Colors _color;
public:
  Circle(int x=0, int y=0, int radius=0, Colors color = Colors::RED);
  void draw();
};

Circle::Circle(int x, int y, int radius, Colors color){
  _position = Position(x,y);
  _color = color;
  _radius=radius;
}

void Circle::draw(){
  /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
   * Höhensatz des Euklid
   * */
  int x_start = _position.x - _radius/2;
  int x_stop  = _position.x + _radius/2;

  for(int i=x_start; i<=x_stop; i++){
    double x_relative = double(i) - double(x_start);
    double h = sqrt(x_relative*(x_stop-x_start-x_relative));
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y +h,"#",
                          _color);
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y -h,"#",
                          _color);

  }
}

class Rectangle {
protected:
  Position  _position;
  int       _height;
  int       _width;
  Colors _color;
public:
  Rectangle(int x=0, int y=0, int height=0, int width=0, Colors color = Colors::RED);
  void draw();
};

Rectangle::Rectangle(int x, int y, int height, int width, Colors color) {
  _position = Position(x,y);
  _height = height;
  _width = width;
  _color = color;
}

void Rectangle::draw() {
  for(int i = _position.x; i <= (_position.x + _width); i++) {
    ansiConsole.printText(i, _position.y, "#", _color);
    ansiConsole.printText(i, _position.y + _height, "#", _color);
  }
  for(int i = _position.y; i <= (_position.y + _height); i++) {
    ansiConsole.printText(_position.x , i, "#", _color);
    ansiConsole.printText(_position.x + _width, i, "#", _color);
  }
}

class Scene {
protected:
  std::vector<Point*> _vecPoint;
  std::vector<Circle*> _vecCircle;
  std::vector<Rectangle*> _vecRectangle;
public:
  Scene();
  void addPoint(Point* p);
  void addCircle(Circle* c);
  void addRectangle(Rectangle* r);
  void draw();
  ~Scene();
};

Scene::Scene() {

}

void Scene::addPoint(Point* p) {
  _vecPoint.push_back(p);
}

void Scene::addCircle(Circle* c) {
  _vecCircle.push_back(c);
}

void Scene::addRectangle(Rectangle* r) {
  _vecRectangle.push_back(r);
}

void Scene::draw() {
  for(auto r : _vecRectangle) {
    r->draw();
  }
}

Scene::~Scene() {
  for(auto p : _vecPoint) {
      delete p;
  }
  _vecPoint.clear();
  for(auto c : _vecCircle) {
      delete c;
  }
  _vecCircle.clear();
  for(auto r : _vecRectangle) {
      delete r;
  }
  _vecRectangle.clear();
}

int main(int argc, char **argv)
{
  // x=0 and y=0 is the upper left corner
  // x and y are more like column and row
  /*ansiConsole.printText(5,5,"Hello, World!");

  Point* p = new Point(10,10);
  p->draw();

  Point* p2 = new Point(2,10);
  p2->draw();


  Circle* c = new Circle(30, 15, 10);
  c->draw();

  Point* p3= new Point(30,15);
  p3->draw();


  delete p;
  delete p2;
  delete p3;
  delete c;*/
  int x = 1;
  Rectangle* r1 = new Rectangle(5,5,10,10, Colors::CYAN);
  Rectangle* r2 = new Rectangle(20,5,10,10, Colors::GREEN);
  Rectangle* r3 = new Rectangle(35,5,10,10, Colors::YELLOW);
  do {
  Scene test;
  std::cout << sizeof(r1) << std::endl;
  test.addRectangle(r1);
  test.addRectangle(r2);
  test.addRectangle(r3);
  test.draw();
  std::cout << sizeof(test) << std::endl;

} while( x != 1);



  return 0;
}
