#include <iterator>
#include <iostream>
#include <string>
#include "my_algs_T.h"

using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
		split(s, ostream_iterator<string>(cout, "\n"));
	
	return 0;
}
