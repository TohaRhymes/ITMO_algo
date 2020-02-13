#include <iostream>
using namespace std;

int main(){
    // n - number's amount, ans - answer, sum - max sum of subarray till the i-t element, min_sum - current min;
    int n;
    cin >> n;
    int ans = 0;
    int sum = 0;
    int min_sum = 0;
    for (int i = 0; i < n; i++){
        int a;
        cin>>a;
        sum += a;
        ans = max (ans, sum - min_sum);
        min_sum = min (min_sum, sum);
    }
    cout<<ans;
    return 0;
}



