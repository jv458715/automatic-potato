/***********************************************************************
	The implementation file for course.h, which describes a college
	course.
		John Dolan		School of EECS		Summer2013
**************************************************************************/

/**
 * @file   course.cc
 * @date   10/12/17
 * @brief  Implementation for the college class.
 */

#include "course.h"
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

/** \class Course
 *  \brief Default constructor
 */
course::course(){
    hours = 0.0;
}

/** \class Course
 *  \brief Inputs course info
 */
void course::input(std::istream& ins){
    if(ins == cin){
	cout<<"Course Number: ";
	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
	cout<<"Grade received: ";
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
 	cout<<"Credit hours: ";
    	ins>>hours;
	upper_course();   // makes all lower case letters into caps
    }
    else{
    	if(ins.peek() == '\n') ins.ignore();
    	getline(ins, course_number);
    	if(ins.eof()) return;
    	getline(ins, grade);
	grade[0] = toupper(grade[0]);
    	if(ins.eof()) return;
    	ins>>hours;
    }
}

/** \class Course
 *  \brief outputs info on course
 */
void course::output(std::ostream& outs)const{
    if(outs == cout){
	outs<<"Course Number:"<<course_number<<endl;
	outs<<"Grade received:"<<grade<<endl;
	outs<<"Credit hours:"<<setprecision(2)<<hours<<endl;
      }
     else{
        outs<<course_number<<endl;
        outs<<grade<<endl;
        outs<<setprecision(2)<<hours<<endl;
      }
}

/** \class Course
 *  \brief returns grade of gpa
 */
double course::get_number_grade()const{
    if(grade == "A") return 4.0;
    if(grade == "A-") return 3.667;
    if(grade == "B+") return 3.333;
    if(grade == "B") return 3.0;
    if(grade == "B-") return 2.667;
    if(grade == "C+") return 2.333;
    if(grade == "C") return 2.0;
    if(grade == "C-") return 1.667;
    if(grade == "D+") return 1.333;
    if(grade == "D") return 1.0;
    if(grade == "D-") return 0.667;
    if(grade == "F") return 0.0;
    else return 0;
}

/** \class Course
 *  \brief Sets values of course
 */
void course::set_course(std::string num, std::string grad, double hrs){
	course_number = num;
	grade = grad;
	hours = hrs;
}

/** \class Course
 *  \brief Input operator
 */
istream& operator >>(istream& ins, course& c){
    c.input(ins);
    return ins;
}


/** \class Course
 *  \brief Output operator
 */
ostream& operator <<(ostream& outs, const course& c){
    c.output(outs);
    return outs;
}

/** \class Course
 *  \brief Capitalizes course
 */
void course::upper_course(){
    for(int i =0; i<course_number.length(); ++i)
	course_number[i] = toupper(course_number[i]);
}
