#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
	    int l = (m + n + 1) / 2;
	    int r = (m + n + 2) / 2;
	    return (getkth(nums1,0, nums2,0, l) + getkth(nums1,0, nums2,0, r)) / 2.0;
    }

    double getkth(vector<int>& A,int aStart, vector<int>& B, int bStart, int k)
    {
        if(A.size()==0) return B[bStart + k -1];
        if(B.size()==0) return A[aStart + k -1];
        if (aStart > A.size() - 1) return B[bStart + k - 1];  //当a的起始地址已经到了a最后          
        if (bStart > B.size() - 1) return A[aStart + k - 1];                
        if (k == 1) return min(A[aStart], B[bStart]);

        int aMid = 100000000, bMid = 100000000;
        if (aStart + k/2 - 1 < A.size()) aMid = A[aStart + k/2 - 1];  //计算出在A[aStart,final]中的中位数
        if (bStart + k/2 - 1 < B.size()) bMid = B[bStart + k/2 - 1];        
        
        if (aMid < bMid) 
            return getkth(A, aStart + k/2, B, bStart,       k - k/2);// Check: aRight + bLeft 
        else 
            return getkth(A, aStart,       B, bStart + k/2, k - k/2);// Check: bRight + aLeft
    }

    int min(int a, int b)
    {
        if(a>=b) return b;
        else return a;
    }
};