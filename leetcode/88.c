//  合并两个有序数组
// https://leetcode-cn.com/problems/merge-sorted-array/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    if(nums1Size < m + n) return;
    int l1 = m - 1;
    int l2 = n - 1;
    // nums1 有足够的空间
    int len = m + n - 1;

    while(l1 >= 0 && l2 >= 0){
        nums1[len--] = nums1[l1] < nums2[l2]? nums2[l2--]:nums1[l1--];
    }
    while(l2 >= 0){
        nums1[len--] = nums2[l2--];
    }
}