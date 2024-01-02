// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
long long largestPerimeter(int* nums, int numsSize) {
    long long sum=0;
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
    } 
    
    for(int j=0;j<numsSize-2;j++){
        int flag=0;
        for(int i=0;i<numsSize;i++){
            if(sum<=2*nums[i]){
                sum-=nums[i];
                nums[i]=0;
                flag++;
            }
        }
        if(flag==0) return sum;
        
    }
    return -1;
    
}