#pragma once

#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student_info {
private: //숨기고 싶은 변수
	string name;
	double midterm, final;
	vector<double> homework;

public: //접근할 수 있는 함수
	// -------생성자-----
	Student_info(); //빈 객체를 생성
	Student_info(istream&); //스트림을 읽어 객체를 생성
	//윗 생성자가 read_hw() 함수와 비슷해

	//------멤버 함수 정의-----
	string getName() const { return name; }
	void setName(string n) { name = n; }

	bool valid() const { return !homework.empty(); }

	//9.2.1. 254p에서 정의한 함수들
	istream& read(istream&);
	double grade() const;

}; // 세미콜론 붙이기

//전역 함수 정의
bool compare(const Student_info&, const Student_info&);

#endif
