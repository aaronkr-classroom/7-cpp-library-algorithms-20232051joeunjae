#include "Student_info.h"  
#include "grade.h"         


bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}