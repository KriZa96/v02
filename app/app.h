#pragma once

#include <cstdint>
#include <string>
// from <windows.h>
#define RGB(r,g,b) ((uint32_t)(((uint8_t)(r)|((uint16_t)((uint8_t)(g))<<8))|(((uint32_t)(uint8_t)(b))<<16)))

namespace vsite::oop::v2
{
/*
* class declaration
*/
	class color
	{
	public:
		double get_red() const;
		double get_blue() const;
		double get_green() const;
		double get_luminance() const;
		uint32_t get_color_ref() const;
		void set_red(const double num);
		void set_blue(const double num);
		void set_green(const double num);
	private:
		double red = 0;
		double blue = 0;
		double green = 0;
	};

	std::string to_hex(const int num);

}
