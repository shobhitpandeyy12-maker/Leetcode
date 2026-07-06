#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * Find median using binary search partition approach
     * TC: O(log(min(m, n))), SC: O(1)
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int low = 0, high = m;
        
        while (low <= high) {
            // Partition smaller array
            int partitionX = (low + high) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;
            
            // Boundary elements
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX];
            
            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY];
            
            // Check if partition is correct
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // Found correct partition
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // Move left in nums1
                high = partitionX - 1;
            } else {
                // Move right in nums1
                low = partitionX + 1;
            }
        }
        
        return 0.0; // Should never reach here
    }
};
