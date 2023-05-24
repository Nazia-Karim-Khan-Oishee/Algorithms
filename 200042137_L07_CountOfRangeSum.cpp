class Solution {
public:
    void mergeArray(vector<long long>& sum, int left, int mid, int right){
    vector<long long> tmp(right-left+1);
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right){
        if(sum[i] <= sum[j])
        tmp[k++] =  sum[i++] ;
        else
        tmp[k++]= sum[j++];
    }
    while(i <= mid){
        tmp[k++] = sum[i++];
    }
    while(j <= right){
        tmp[k++] = sum[j++];
    }
    i = left, k = 0;
    while(i <= right){
        sum[i++] = tmp[k++];
    }
}
int mergeSort(vector<long long>& sum, int left, int right, int lower, int upper)
{
    if(left == right){
        if(sum[left] >= lower && sum[right] <= upper) return  1 ;
        else return  0;
    }
    int count = 0;
    int mid = (left + right)/2;
    int leftCount = mergeSort(sum, left, mid, lower, upper);
    int rightCount = mergeSort(sum, mid+1, right, lower, upper);
    int i = left, k = mid+1, j = mid+1;
    while(i <= mid){
        long long lowerBound = sum[i]+lower, upperBound = sum[i]+upper;
        while(j <= right && sum[j] <= upperBound){
            ++j;
        }
        while(k <= right && sum[k] < lowerBound){
            ++k;
        }
        count += (j-k);
        ++i;
    }
     mergeArray(sum, left, mid, right);

    return leftCount+rightCount+count;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long long> sum(nums.size(), 0);
    sum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        sum[i] = sum[i-1]+nums[i];
    }
    return mergeSort(sum, 0, sum.size()-1, lower, upper);
}
};
