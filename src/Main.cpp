#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#define BRIGHTNESS_FILENAME "/sys/class/backlight/intel_backlight/brightness"
#define MAX_BRIGHTNESS_FILENAME "/sys/class/backlight/intel_backlight/max_brightness"

#define WRITE_FAILED "Setting brightness value failed"
#define READ_FAILED "Reading brightness value failed"

static int read_int(const char* filename)
{
	std::ifstream f (filename);
	std::string line;
	if(f.is_open())
	{
		std::getline(f,line);
		f.close();
	}
	else
	{
		std::cout << READ_FAILED << std::endl;
		exit(-1);
	}
	
	return std::atoi(line.c_str());
}

static void write_int(const char* filename, int value)
{
	std::ofstream  f(filename);
	if(f.is_open())
	{
		f << std::to_string(value) << std::endl;
		f.close();
	}
	else
	{
		std::cout << WRITE_FAILED << std::endl;
		exit(-1);
	}
}

static void print_help(char* name)
{
		std::cout << "usage: '" << name << "inc' to increace" << std::endl;
		std::cout << "or '" << name << "'dec' to decreace brightness" << std::endl;
		exit(0);
}

static int incr(int current, int max)
{
	return current + 100 + (current * 0.05);
}

static int decr(int current, int max)
{
	return current - 100 - (current * 0.05);
}
static void alter(int (*fptr)(int, int))
{
	int current_brightness = read_int(BRIGHTNESS_FILENAME);
	int max_brightness = read_int(MAX_BRIGHTNESS_FILENAME);
	int desired_brightness = (*fptr)(current_brightness, max_brightness);
	if(desired_brightness < 0)
	{
		desired_brightness = 0;
	}
	if(desired_brightness > max_brightness)
	{
		desired_brightness = max_brightness;
	}
	write_int(BRIGHTNESS_FILENAME, desired_brightness);
}

int main(int argc, char** argv)
{
	if(argc == 2 && strcmp(argv[1], "inc") == 0)
	{
		alter(*incr);
	}
	else if(argc == 2 && strcmp(argv[1], "dec") == 0)
	{
		alter(*decr);
	}
	else
	{
		print_help(argv[0]);
	}
}

