class Solution {
public:
    int trap(vector<int>& height) {
        int area=0, i=0 , j=height.size()-1;
        int leftMax =0 , rightMax =0 ;
        while(i<=j){
            if(leftMax < rightMax){
                if(height[i]>=leftMax){
                    leftMax = height[i];
                }
                else{
                    area+= leftMax - height[i];
                }
                i++;
            }
            else{
                if(height[j]>=rightMax){
                    rightMax = height[j];
                }
                else{
                    area += rightMax - height[j];
                }
                j--;
            }
        }
        return area;
    }
};
