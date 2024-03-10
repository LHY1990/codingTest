import org.junit.Test;

import java.util.*;



public class MergedSortedArray88 {

    class Solution {
        public void merge(int[] nums1, int m, int[] nums2, int n) {
            int index1 = m - 1;
            int index2 = n - 1;

            for (int i = m + n - 1; i >= 0; --i) {
                if (index1 < 0) {
                    nums1[i] = nums2[index2--];
                } else if (index2 < 0) {
                    nums1[i] = nums1[index1--];

                } else {
                    if (nums1[index1] >= nums2[index2])
                        nums1[i] = nums1[index1--];
                    else
                        nums1[i] = nums2[index2--];
                }

            }
        }
    }

    @Test
    public void Test1() {
        Solution slt = new Solution();
        int[] input1 = {0};
        int[] input2 = {1};

        slt.merge(input1,0, input2,1);

    }
}
