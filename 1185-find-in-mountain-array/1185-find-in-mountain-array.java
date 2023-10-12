/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
    int peakIndex = findPeakIndex(mountainArr);
    int leftResult = binarySearch(mountainArr, target, 0, peakIndex);
    if (leftResult != -1) {
        return leftResult;
    }
    return binarySearch(mountainArr, target, peakIndex + 1, mountainArr.length() - 1);
}

private int findPeakIndex(MountainArray mountainArr) {
    int left = 0;
    int right = mountainArr.length() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

private int binarySearch(MountainArray mountainArr, int target, int left, int right) {
    boolean isIncreasing = mountainArr.get(left) < mountainArr.get(right);
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = mountainArr.get(mid);
        if (midValue == target) {
            return mid;
        }
        if (isIncreasing) {
            if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else {
            if (midValue < target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
    }
    return -1;
}

}