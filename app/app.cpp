#include "app.h"
#include <algorithm>
#include <format>
#include <string>

namespace vsite::oop::v2
{
/*
* class member function implementations
*/
	double color::get_red() const
	{
		return this->red;
	}

	double color::get_blue() const
	{
		return this->blue;
	}

	double color::get_green() const
	{
		return this->green;
	}

	void color::set_red(const double num)
	{
		if (num < 0)
		{
			this->red = 0;
			return;
		}
		if (num > 1)
		{
			this->red = 1;
			return;
		}
		this->red = num;
	}

	void color::set_blue(const double num)
	{
		if (num < 0)
		{
			this->blue = 0;
			return;
		}
		if (num > 1)
		{
			this->blue = 1;
			return;
		}
		this->blue = num;
	}

	void color::set_green(const double num)
	{
		if (num < 0)
		{
			this->green = 0;
			return;
		}
		if (num > 1)
		{
			this->green = 1;
			return;
		}
		this->green = num;
	}

	double color::get_luminance() const
	{
		return (0.2126 * this->red + 0.7152 * this->green + 0.0722 * this->blue);
	}

	uint32_t color::get_color_ref() const
	{
		return RGB(this->red * 255, this->green * 255, this->blue * 255);
	}

	std::string to_hex(const int num)
	{

		return std::format("{:X}", num);
	}


} // namespace
