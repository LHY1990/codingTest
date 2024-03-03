/*
https://school.programmers.co.kr/learn/courses/30/lessons/12928
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
	
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	int total = 0;
	int half = n / 2;

	for (int i = 1; i <= half; i++) {
		if (n % i == 0)
			total += i;
	}
    
	total += n;

	return total;

}

void main()
{
    cout << solution(5) << endl;
}