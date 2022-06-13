#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
using std::cout;
using std::cin;
using std::endl;

#define HUMAN_TAKES_PARAMETERS const std::string& last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name,first_name,age

#define STUDENT_TAKE_PARAMETERS const std::string& specialty, const std::string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS specialty,group, year, rating, attendance

#define TEACHER_TAKE_PARAMETERS const std::string& specialty, unsigned int experience

#define GRADUATE_TAKE_PARAMETERS const std::string& diploma, unsigned int pages, unsigned int release
