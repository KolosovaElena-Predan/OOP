//Выполнила Колосова Елена ВМК-22


#include <cmath>

/// выявляет существует ли треугольник
/// \param x1 абсцисса первой вершины
/// \param y1 ордината первой вершины
/// \param x2 абсцисса второй вершины
/// \param y2 ордината второй вершины
/// \param x3 абсцисса третьей вершины
/// \param y3 ордината третьей вершины
/// \return true, если треугольник с заданными вершинами существует
/// \return false, если треугольник с заданными вершинами не существует
bool existence_of_a_triangle(float x1, float y1, float x2, float y2, float x3, float y3){
	float st1=0, st2=0, st3=0;
	st1=sqrt(pow((x1-x2), 2)+pow((y1-y2),2));
   	st2=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
   	st3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));
 
	if (((st1+st2)>st3) && ((st1+st2)>st3) && ((st1+st2)>st3)) return true; //условие существования треугольника
	else return false;}


/// вычисляет периметр треугольника по координатам его вершин
/// \param x1 абсцисса первой вершины
/// \param y1 ордината первой вершины
/// \param x2 абсцисса второй вершины
/// \param y2 ордината второй вершины
/// \param x3 абсцисса третьей вершины
/// \param y3 ордината третьей вершины
/// \return  периметр треугольника
float perimeter(float x1, float y1, float x2, float y2, float x3, float y3){
	float st1=0, st2=0, st3=0;
	st1=sqrt(pow((x1-x2), 2)+pow((y1-y2),2));
   	st2=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
   	st3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));  
	return st1+st2+st3;}

/// вычисляет площадь треугольника по координатам его вершин
/// \param x1 абсцисса первой вершины
/// \param y1 ордината первой вершины
/// \param x2 абсцисса второй вершины
/// \param y2 ордината второй вершины
/// \param x3 абсцисса третьей вершины
/// \param y3 ордината третьей вершины
/// \return  площадь треугольника
float area(float x1, float y1, float x2, float y2, float x3, float y3){
	float st1, st2, st3;
	st1=sqrt(pow((x1-x2), 2)+pow((y1-y2),2));
   	st2=sqrt(pow((x2-x3),2)+pow((y2-y3),2));
   	st3=sqrt(pow((x3-x1),2)+pow((y3-y1),2));    
	float pp=(st1+st2+st3)/2.0;	    //нахождение полупериметра треугольника
	float s=sqrt(pp*(pp-st1)*(pp-st2)*(pp-st3)); //нахождение площади треугольника
	return s;}


