#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <functional>
#include <limits>
#include <random>
#include <cassert>
#include <climits>

using namespace std;

int find_k_small2(int a[],int m, int b[], int n, int k) {
  int i = (int)( (double)m/(m+n)*(k-1));
  int j = k-1-i;
  int a_i = (i==0)?numeric_limits<int>::min():a[i-1];
  int b_j = (j==0)?numeric_limits<int>::min():b[j-1];
  int ai = (i==m)?numeric_limits<int>::max():a[i];
  int bj = (j==n)?numeric_limits<int>::max():b[j];
  if(b_j<ai&&ai<bj) return ai;
  if(a_i<bj&&bj<ai) return bj;
  if(ai<bj) return find_k_small2(a+i+1,m-i-1,b,j,k-i-1);
  else return find_k_small2(a,i,b+i+1,j-i-1,k-i-1);
}
int findKthSmallest(int A[], int m, int B[], int n, int k) {
  assert(m >= 0); assert(n >= 0); assert(k > 0); assert(k <= m+n);
  
  int i = (int)((double)m / (m+n) * (k-1));
  int j = (k-1) - i;
 
  assert(i >= 0); assert(j >= 0); assert(i <= m); assert(j <= n);
  // invariant: i + j = k-1
  // Note: A[-1] = -INF and A[m] = +INF to maintain invariant
  int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
  int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
  int Ai   = ((i == m) ? INT_MAX : A[i]);
  int Bj   = ((j == n) ? INT_MAX : B[j]);
 
  if (Bj_1 < Ai && Ai < Bj)
    return Ai;
  else if (Ai_1 < Bj && Bj < Ai)
    return Bj;
 
  assert((Ai > Bj && Ai_1 > Bj) ||
         (Ai < Bj && Ai < Bj_1));
 
  // if none of the cases above, then it is either:
  if (Ai < Bj)
    // exclude Ai and below portion
    // exclude Bj and above portion
    return findKthSmallest(A+i+1, m-i-1, B, j, k-i-1);
  else /* Bj < Ai */
    // exclude Ai and above portion
    // exclude Bj and below portion
    return findKthSmallest(A, i, B+j+1, n-j-1, k-j-1);
}
int main(int argc, char const *argv[]) {
  int m=10,n=15;
  int a[m],b[n];
  random_device rd;
  mt19937 e(rd());
  mt19937 e2(rd());
  uniform_int_distribution<int> uni(-100,100);
  //uniform_int_distribution<int> uni(numeric_limits<int>::min(),numeric_limits<int>::max());
  generate( &a[0], &a[m],[&]{return uni(e);});
  generate( &b[0], &b[n],[&]{return uni(e);});
  sort( &a[0], &a[m]);
  sort( &b[0], &b[n]);
  std::copy(&a[0], &a[m],std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  std::copy(&b[0], &b[n],std::ostream_iterator<int>(std::cout," ")); std::cout << std::endl;
  cout << "2nd smallest is " << find_k_small2(a,m,b,n,10) << endl;
  cout << "2nd smallest is " << findKthSmallest(a,m,b,n,10) << endl;
  return 0;
}
