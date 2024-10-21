#include <iostream>
#include <format>
#include "app.h"

int main()
{
	double r, g, b;

	std::cin >> r >> g >> b;

	vsite::oop::v2::color this_color;
	this_color.set_red(r);
	this_color.set_blue(b);
	this_color.set_green(g);

	std::cout << vsite::oop::v2::to_hex(this_color.get_color_ref());
}
