#include <vector>           
#include <algorithm>          

#include "Student_info.h"
#include "fgrade.h"
#include "pgrade.h"

using std::vector;


vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;
    remove_copy_if(students.begin(), students.end(),
        back_inserter(fail), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade),
        students.end());
    return fail;
}