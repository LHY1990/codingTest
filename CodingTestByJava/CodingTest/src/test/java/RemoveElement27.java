/*
*
한국어

정수 배열 nums와 정수 val이 주어졌을 때, nums에서 val이 포함된 모든 요소를 제자리에서 제거합니다. 요소의 순서는 변경될 수 있습니다. 그런 다음 nums에서 val과 같지 않은 요소의 수를 반환합니다.

nums에서 val과 같지 않은 요소의 개수가 k라고 가정하면 다음과 같은 작업을 수행해야 허용됩니다:

nums의 첫 번째 k 요소에 val과 같지 않은 요소가 포함되도록 배열 nums를 변경합니다. nums의 나머지 요소는 nums의 크기만큼 중요하지 않습니다.
k를 반환합니다.
사용자 정의 판정:

판사는 다음 코드를 사용하여 솔루션을 테스트합니다:

int[] nums = [...]; // 입력 배열
int val = ...; // 제거할 값
int[] expectedNums = [...]; // 올바른 길이의 예상 답입니다.
// val과 같은 값이 없는 상태로 정렬됩니다.

int k = removeElement(nums, val); // 구현을 호출합니다.

assert k == expectedNums.length;
sort(nums, 0, k); // nums의 처음 k 요소를 정렬합니다.
for (int i = 0; i < actualLength; i++) { {
assert nums[i] == expectedNums[i];
}
모든 어설션이 통과하면 솔루션이 승인됩니다.

DeepL.com에서 열기
사전



* */

import org.junit.Test;




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
