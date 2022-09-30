class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int area = 0;
        while(left<right){
            int d = right-left;
            int h = min(height[left],height[right]);
            area = max(area, d*h);
            if(height[left]<=height[right]) left++;
            else right--;
        }
        return area;
    }
};
