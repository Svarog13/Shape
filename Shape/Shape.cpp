#include <iostream>
#include <string>

class Shape
{
protected:
	std::string name;
	std::string type;
public:
	Shape() :name("no name"), type("no type"){}
	Shape(const std::string n, const  std::string & t) : name (n), type(t){}

	virtual void Show()const
	{
		std::cout << "Name: " << name << std::endl;
		std::cout << "Type: " << type << std::endl;
	}

	virtual double GetArea()const
	{
		return 0.0;
	}
};

class Rectangle : public Shape
{
private:
	double width;
	double height;
public:
	Rectangle (const std::string& n,double w, double h)
		: Shape(n, "Rectangle"),width(w), height(h){}
	
	void Show()const override
	{
		Shape::Show();
		std::cout << "Width: " << width << " units" << std::endl;
		std::cout << "Height: " << height << " units" << std::endl;
	}
	double GetArea()const override
	{
		return width * height;
	}
};

class Circle : public Shape {
private:
	double radius;

public:
	Circle(const std::string& n, double r) : Shape(n, "Circle"), radius(r) {}

	void Show() const override {
		Shape::Show();
		std::cout << "Radius: " << radius << " units" << std::endl;
	}

	double GetArea() const override {
		return 3.14159265359 * radius * radius; 
	}
};

class Triangle : public Shape
{
private: 
	double base;
	double height;
public:
	Triangle(const std:: string &n ,double b, double h):
		Shape (n,"Triangle"),base(b),height(h){}

	void Show() const override
	{
	    Shape:Show();
		std::cout << "Base: " << base << " units" << std::endl;
		std::cout << "Height: " << height << " units" << std::endl;
	}
	double GetArea()const override
	{
		return 0.5 * base * height;
	}
	
};
class Trapezoid : public Shape
{
private:
	double topBase;
	double bottomBase;
	double height;

public: 
	Trapezoid(const std::string& n, double td, double bb, double h)
		: Shape (n,"Trapezoid"), topBase(td) ,bottomBase(bb),height(h){}

	void Show()const override
	{
	Shape: Show();
		std::cout << "Top Base: " << topBase << " units" << std::endl;
		std::cout << "Bottom Base: " << bottomBase << " units" << std::endl;
		std::cout << "Height: " << height << " units" << std::endl;
	}
	double GetArea() const override
	{
		return 0.5 * (topBase + bottomBase) * height;
	}
};

void TestShape(const Shape& shape)
{
	shape.Show();
	std::cout << "Area: " << shape.GetArea() << " square units" << std::endl;
}

int main()
{
	Rectangle rect("Rectangle 1", 4.0, 5.0);
	Circle circle("Circle 1", 3.0);
	Triangle triangle("Triangle 1", 3.0, 4.0);
	Trapezoid trapezoid("Trapezoid 1", 2.0, 4.0, 3.0);

	TestShape(rect);
	std::cout << std::endl;
	TestShape(circle);
	std::cout << std::endl;
	TestShape(triangle);
	std::cout << std::endl;
	TestShape(trapezoid);

	return 0;
}