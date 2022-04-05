class Solution {
public:
    int maxArea(vector<int>& height) {
        int water=0; //use to store maximum water
    int left=0; //left pointer
    int right=height.size()-1; //right pointer
    
    while(left<right){
        water = max(water , min(height[left],height[right]) * (right-left));
        
        if(height[left]<=height[right]){
            left++;
        }
        else{
            right--;
        }
    }
    return water;
    }
};