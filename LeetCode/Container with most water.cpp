class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int n = size(height);
        int i=0, j=n-1;
        while(j>i){
            int w = j-i;
            int h = min(height[j],height[i]);
            ans = max(w*h, ans);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
