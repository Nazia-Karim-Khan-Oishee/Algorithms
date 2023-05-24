
class Solution {
public:
    void mergeSort(vector<int>& nums, int low, int high, int& count){
        if(low <high)
        {
        int mid = (low + high)/2;
        mergeSort(nums, low, mid, count);
        mergeSort(nums, mid+1, high, count);
        //merge
        int j = mid+1;
        int c=0;
        for(int i=low; i<=mid; i++)
        {
            while(j<=high && nums[i]>2*(long long)nums[j]){
                c++;
                j++;
        }
            count+=c;
        }
        int size = high-low+1;
        vector<int> temp(size, 0);
        int left = low, right = mid+1, k=0;
        while(left<=mid && right<=high)
        {
            if(nums[left] < nums[right])
            {
                temp[k] = nums[left];
                k++;
                left++;
            }
            else
            {
                temp[k] = nums[right];
                k++;
                right++;
            }
        }
        while(left<=mid)
        {
            temp[k] = nums[left];
            k++;
            left++;
        }
        while(right<=high)
        {
            temp[k] = nums[right];
            k++;
            right++;
        }
        int ind=0;
        for(int i=low; i<=high; i++)
        {
            nums[i] = temp[ind];
            ind++;
        }
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size()-1, count);
        return count;
    }
};
