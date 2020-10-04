#include<bits/stdc++.h>
#include <chrono> 
using namespace std;
using namespace std::chrono; 
int memo[105][1005];
bool subsetSum(vector<int>& arr, int sum, int n)
{
	if(sum==0)
		return true;
	if(n==0)
		return false;
	if(memo[n][sum]!=-1)
		return memo[n][sum];
	if(arr[n-1] <= sum)
	{
		return memo[n][sum] = subsetSum(arr, sum-arr[n-1], n-1) | subsetSum(arr, sum, n-1);
	}
	return memo[n][sum] = subsetSum(arr, sum, n-1);
}
int main()
{
	int n, sum;
	cin >> n >> sum;
	vector<int> arr(n);

	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	auto start = high_resolution_clock::now(); 
    memset(memo, -1, sizeof(memo));
	cout << subsetSum(arr, sum, n) << endl;

	auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << duration.count() << " microseconds" << endl; 
	return 0;
}