class Solution {
public:
    int partition(vector<int> & arr, int high, int low){
        int pivot= arr[high];
        int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
    }
    void quicksort(vector<int> & arr, int high , int low){
        if(high> low){
            int pi = partition(arr, high, low);

            quicksort(arr, high, pi+1);
            quicksort(arr, pi-1, low);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, nums.size()-1, 0);
        return nums;
    }
};