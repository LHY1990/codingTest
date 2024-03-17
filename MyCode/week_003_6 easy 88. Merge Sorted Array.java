import org.junit.Test;

import java.util.*;

// https://leetcode.com/problems/merge-sorted-array/?envType=study-plan-v2&envId=top-interview-150
/*
88. 정렬된 배열 병합

감소하지 않는 순서로 정렬된 2개의 정수 배열 num1과 num2와 각각 num1과 num2에 있는 원소의 수를 나타내는 2개의 정수 m과 n이 주어진다.

숫자 1과 숫자 2를 감소하지 않는 순서로 정렬된 단일 배열로 병합한다.

최종 정렬된 배열은 함수에 의해 반환되는 것이 아니라 배열 nums1 안에 저장되어야 한다. 이를 수용하기 위해 nums1은 m + n의 길이를 가지며, 여기서 처음 m개의 원소는 병합되어야 하는 원소를 나타내고, 마지막 n개의 원소는 0으로 설정되어 무시되어야 한다. nums2는 n의 길이를 가진다.

 

예 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
설명: 병합할 어레이는 [1,2,3]과 [2,5,6]입니다.
병합의 결과는 [1,2,2,3,5,6]이고 밑줄 친 원소는 1번에서 나온다.

예제 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
출력 : [1]
설명: 병합할 어레이는 [1]과 []입니다.
합병 결과는 [1]입니다.

예 3:
Input: nums1 = [0], m = 0, nums2 = [1], n = 1
출력 : [1]
설명: 병합할 어레이는 []과 [1]입니다.
합병 결과는 [1]입니다.
m = 0이므로 nums1에는 원소가 없다. 0은 병합 결과가 nums1에 들어갈 수 있도록 하기 위해서만 존재한다.
 

제약 조건:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: O(m + n) 시간에 실행되는 알고리즘을 생각해 낼 수 있는가?

토픽:
Array
Two Pointers
Sorting
*/


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

public class MergedSortedArray88 {
    @Test
    public void Test1() {
        Solution slt = new Solution();
        int[] input1 = {0};
        int[] input2 = {1};

        slt.merge(input1,0, input2,1);

    }
}
