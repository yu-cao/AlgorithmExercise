//使用分治策略，使得代码可读性更强，条理更清晰
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		int l = (m + n + 1) / 2;
		int r = (m + n + 2) / 2;
		return (getkth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, l) +
				getkth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, r)) / 2.0;
	}

	double getkth(vector<int> &A, int aStart, int aEnd, vector<int> &B, int bStart, int bEnd, int k)
	{
		if (aStart > aEnd) return B[bStart + k - 1];
		if (bStart > bEnd) return A[aStart + k - 1];

		int aMid = (aEnd - aStart) / 2 + aStart;
		int bMid = (bEnd - bStart) / 2 + bStart;

		if (A[aMid] < B[bMid])
		{
			if (k <= (aMid - aStart) + (bMid - bStart) + 1)//k小于等于当前的两个数组中位数左半边之和，且A中位数比B小时，B中位数右侧的一定不可能是待选项，去掉
				return getkth(A, aStart, aEnd, B, bStart, bMid - 1, k);
			else//k大于当前的两个数组中位数左半边之和，且A中位数比B小时，显然A中位数左边边都是小于我们要找的中位数的，保留，把k和begin刷新
				return getkth(A, aMid + 1, aEnd, B, bStart, bEnd, k - (aMid - aStart) - 1);
		}
		else
		{
			if (k <= (aMid - aStart) + (bMid - bStart) + 1)
				return getkth(A, aStart, aMid - 1, B, bStart, bEnd, k);
			else
				return getkth(A, aStart, aEnd, B, bMid + 1, bEnd, k - (bMid - bStart) - 1);
		}
	}
};