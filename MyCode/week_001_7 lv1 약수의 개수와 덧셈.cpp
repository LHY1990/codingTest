/*
https://school.programmers.co.kr/learn/courses/30/lessons/77884
*/

#include <string>
#include <vector>
#include<iostream>

using namespace std;



int solution(int left, int right) {
	int count = 0;
	int half = 0;
	bool isEven = false;
	int total = 0;

	for (int i = left; i <= right; i++)
	{
		if (i == 1)
		{
			--total;
			continue;
		}
		else if (i == 2) {
			total += 2;
			continue;
		}

		count = 0;
		if (i % 2 == 1)
			isEven = false;
		else
			isEven = true;

		if (isEven) {
			half = i / 2;
			for (int j = 1; j <= half; j++)
			{
				if ((i % j) == 0)
					++count;
			}
			++count;
		}
		else
		{
			half = (i - 1) / 2;
			for (int j = 1; j <= half; j++)
			{
				if ((i % j) == 0)
					++count;
			}
			++count;
		}

		if (count % 2 == 0)
			total += i;
		else 
			total -= i;
	}

	return total;
}

void main()
{
	int count = solution(1,1);
	cout << count;

}