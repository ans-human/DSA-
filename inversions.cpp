#include <iostream>
#include <vector>
using namespace std;
#define ll long long

ll merger(vector<int> &a, vector<int> &b, size_t left, size_t mid, size_t right)
{
    int i,j,k;
    i = left;
    j = mid+1;
    k = left;
    ll cnt = 0;
    while( i <= mid && j<= right){
        if(a[i] <= a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }

    while( i<= mid) b[k++] = a[i++];

    while( j<= right) b[k++] = a[j++];

    for( ll i=left; i<=right; i++) a[i] = b[i];

    return cnt;
}

ll get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  ll number_of_inversions = 0;
  if (right <= left ) return number_of_inversions;
  size_t ave = (left + right)/ 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave+1, right);
  //write your code here
  number_of_inversions += merger(a, b, left, ave, right);

  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()-1) << '\n';
}
