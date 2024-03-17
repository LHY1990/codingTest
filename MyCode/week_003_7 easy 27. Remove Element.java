import org.junit.Test;

// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

/*
27. 요소 제거
정수 배열 번호와 정수 값이 주어지면, val의 모든 발생을 제자리에서 제거합니다. 원소의 순서가 바뀔 수 있습니다. 그런 다음 val과 동일하지 않은 원소의 수를 반환합니다.

밸브와 동일하지 않은 숫자의 요소 수를 고려하면 합격하려면 다음 작업을 수행해야 합니다:

배열 번호를 바꾸어서 수들의 첫 k개의 원소들이 val과 같지 않은 원소들을 포함하도록 하세요. 나머지 수들의 원소들은 수들의 크기뿐만 아니라 중요하지도 않습니다.
리턴 k.
사용자 정의 심판:

판사는 다음 코드를 사용하여 솔루션을 테스트합니다:

int[] nums = [...]; // 입력 배열
intval = ...; // 제거할 값
int[] expectedNums = [...]; // 올바른 길이를 가진 예상 답변입니다.
                            // val과 동일한 값을 사용하지 않고 정렬됩니다.

intk = removeElement(숫자, val); // 구현 호출

주장 k == expectedNums.length;
sort(숫자, 0, k); // 숫자의 첫 번째 k개 요소를 정렬합니다
(inti = 0; i < 실제 길이; i++) {
    nums[i] == expected Nums[i];
}
모든 주장이 통과되면 솔루션이 수락됩니다.

 

예 1:

Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
설명: 함수는 k = 2를 반환해야 하며, 처음 두 개의 숫자 요소는 2입니다.
반환된 k(따라서 밑줄로 표시됨) 뒤에 무엇을 남겼는지는 중요하지 않습니다.
예제 2:

Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
설명: 함수는 0, 0, 1, 3, 4를 포함하는 숫자의 처음 5개의 요소와 함께 k = 5를 반환해야 합니다.
5가지 요소는 어떤 순서로든 반환할 수 있습니다.
반환된 k(따라서 밑줄로 표시됨) 뒤에 무엇을 남겼는지는 중요하지 않습니다.
 

제약 조건:

0 <= nums.length <= 100
0 <= nums[i] <= 50
0 <= val <= 100

토픽:
Array
Two Pointers
*/

public class RemoveElement27 {

    class Solution {
        public int removeElement(int[] nums, int val) {
            int removed=0;

            for (int i = 0; i+removed < nums.length;) {
                if (nums[i] == val) {
                    ++removed;

                    if (i+1 < nums.length)
                        System.arraycopy(nums, i+1, nums, i, nums.length-i-1);
                }
                else{
                    ++i;
                }
            }

            for (var single : nums) {
                System.out.println(single);
            }


            return nums.length-removed;
        }
    }

    @Test
    public void Test1() {
        var slt = new Solution();
        var result = slt.removeElement(new int[]{0,1,2,2,3,0,4,2}, 2);
        System.out.println(result);
    }
}