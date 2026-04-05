class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area=0, i=0, j=heights.size()-1;
        while(i<j){
            int temp_area = min(heights[i], heights[j])* (j-i);
            if(temp_area > area){
                area = temp_area;
            }
            if(heights[i]>heights[j]) j--;
            else i++;
        }
        return area;
    }
};
