import org.junit.Test;

// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

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