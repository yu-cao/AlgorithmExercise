#include<iostream>
using namespace std;
//DP
class Solution {
public:
    static int uniquePaths(int m, int n) {
        int *x = (int*)malloc(n*sizeof(int));
        for(int i=0;i<n;++i)
            x[i] = 1;
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                x[j] += x[j-1];
            }
        }
        return x[n-1];
    }
};
// //Using the simple recusive and get the TLE
// class Solution {
// public:
//     static int uniquePaths(int m, int n) {
//         if(m == 0 || n == 0) return 0;
//         if(m == 1 && n == 1) return 1;
//         return uniquePaths(m-1,n) + uniquePaths(m,n-1);
//     }
// };

int main(int argc, char const *argv[])
{
    /* code */
    int m = 7;
    int n = 3;
    int result = Solution::uniquePaths(m,n);
    cout<<result;
    return 0;
}
