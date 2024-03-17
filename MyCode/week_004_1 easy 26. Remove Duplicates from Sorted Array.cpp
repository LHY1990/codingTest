/*

한국어

26. 정렬된 배열에서 중복 제거
감소하지 않는 순서로 정렬된 정수 배열의 숫자가 주어지면 각 고유 요소가 한 번만 나타나도록 중복된 요소를 제자리에서 제거합니다. 요소의 상대적 순서는 동일하게 유지해야 합니다. 그런 다음 nums의 고유 요소 수를 반환합니다.

nums의 고유 요소 수를 k라고 가정하고, 이를 허용하려면 다음과 같은 작업을 수행해야 합니다:

nums의 첫 번째 k 요소에 처음에 nums에 있던 순서대로 고유 요소가 포함되도록 배열 nums를 변경합니다. nums의 나머지 요소는 nums의 크기만큼 중요하지 않습니다.
k를 반환합니다.
사용자 정의 판사:

심사위원은 다음 코드를 사용하여 솔루션을 테스트합니다:

int[] nums = [...]; // 입력 배열
int[] expectedNums = [...]; // 올바른 길이의 예상 답안

int k = removeDuplicates(nums); // 구현을 호출합니다.

assert k == expectedNums.length;
for (int i = 0; i < k; i++) { {
assert nums[i] == expectedNums[i];
}
모든 어설션이 통과하면 솔루션이 승인됩니다.


한국어

예 1:

입력: nums = [1,1,2]
출력 2, nums = [1,2,_]
설명: 함수는 k = 2를 반환해야 하며, nums의 처음 두 요소는 각각 1과 2입니다.
반환된 k 너머에 무엇이 남는지는 중요하지 않습니다(따라서 밑줄이 됩니다).
예 2:

입력: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
설명: 함수는 k = 5를 반환해야 하며, nums의 처음 다섯 요소는 각각 0, 1, 2, 3, 4입니다.
반환된 k 너머에 무엇이 남는지는 중요하지 않습니다(따라서 밑줄이 됩니다).


제약 조건:

1 <= nums.length <= 3 * 104
-100 <= nums[i] <= 100
nums는 감소하지 않는 순서로 정렬됩니다.

토픽:
Array
Two Pointers

*/

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1)
            return 1;

        int count=0;
        int index = 0;

        int last = -101;
        for (int i{0};i<nums.size();i++)
        {
            if (last != nums.at(i))
            {
                last = nums.at(i);
                nums[index++] = nums.at(i);
                ++count;
            }
        }
        
        
        return count;
    }

};

void main()
{
    auto temp = Solution();
    auto tempVector = vector<int>{ 1 ,1};

    int result = temp.removeDuplicates(tempVector);
    cout << result << endl;
    for (const auto& single : tempVector) {
        cout << single << " ";

    }
    cout << endl;

}