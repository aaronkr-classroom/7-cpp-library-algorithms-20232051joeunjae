#pragma once
#ifndef GRADE_H
#define GRADE_H

#include <vector>
#include "median.h"
#include "Student_info.h"

double grade(double midterm, double final, double homework);
double grade(double midterm, double final, const std::vector<double>& hw);
double grade(const Student_info& s);
bool fgrade(const Student_info& s);

#endif 