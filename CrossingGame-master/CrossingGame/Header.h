#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//check if the compiler is MSV to include 'Winmm.lib'
#ifdef _MSC_VER
#pragma comment(lib, "Winmm.lib")
#endif


//inorder to pass warning of using 'unsafe' functions in CRT (C runtime library) such as 'strerror' instead of 'strerror_s'
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <chrono>
#include <thread>
#include <conio.h>
#include <mutex>
#include <direct.h>

using namespace std;
using namespace std::chrono;

// code colours
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define AQUA 3
#define RED 4
#define PURPLE 5
#define YELLOW 6
#define WHITE 7
#define GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_AQUA 11
#define LIGHT_RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define BRIGHT_WHITE 15

// movements code
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define ENTER 13

// make mtx global variables in multiple files
extern mutex mtx;

#define _EASY 1
#define WIDTH_CONSOLE 1366
#define HEIGH_CONSOLE 768

#endif