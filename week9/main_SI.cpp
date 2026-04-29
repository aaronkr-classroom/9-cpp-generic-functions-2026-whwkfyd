#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"
#include "median.h" //나중에 공유한 파일 사용

using namespace std;

int main()
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	//데이터 읽고 저장하기
	while (record.read(cin)) {//Student info의 멤버 함수 read
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	//이름과 점수 쓰기
	for (vector<Student_info>::size_type i = 0;
		i != students.size(); i++) {
		cout << students[i].getName()
			<< string(maxlen + 1
				- students[i].getName().size(), ' ');

		try {
			double final_grade = students[i].grade();

			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade
				<< setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl; //예외 출력
		}
	}
	return 0;
}

//필요한 파일 
// Student_info.cpp
// median.h
// median.cpp
//grade.h
//grade.cpp
