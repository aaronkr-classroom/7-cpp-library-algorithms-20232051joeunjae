#include "Student_info.h" 
#include "fgrade.h"       


bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}