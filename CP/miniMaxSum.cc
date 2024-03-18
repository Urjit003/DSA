#include<bits/stdc++.h>
using namespace std;

// int_fast64_t  minSum = 0, maxSum = 0;
    
//     for(size_t i = 0; i < arr.size() ;i ++) {
//             // summ everything exceept i 
//             // sum !i + (i+1)
//             if(i == arr.size()) {
//                 continue;
//                  minSum += arr[i] ;
//             }
//             maxSum +=  (arr[i]+1) ;
            
//     }
//     cout << minSum << " " << maxSum; 
void miniMaxSum(vector<int> arr) {
    sort(arr.begin(),arr.end());
    long long int  minSum = 0, maxSum = 0;
    
    for(int i = 0; i < arr.size()-1 ;i ++) {
            minSum += arr[i];
        
    }
    for(size_t i = arr.size() ;i > 0 ; --i) {
        maxSum+= arr[i];
    }
    cout << minSum << " " << maxSum; 
}
int main (){
    vector<int> vec = {1,2,3,4,5};
     miniMaxSum(vec);
return 0;
}
// 396285104 573261094 759641832 819230764 364801279
// 256741038 623958417 467905213 714532089 938071625