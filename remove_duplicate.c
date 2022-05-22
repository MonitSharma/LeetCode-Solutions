int removeDuplicates(int* nums, int numsSize){
    if(nums == NULL || numsSize < 2)
    {
        return numsSize;
    }
    
    int len = 0, i = 1;
    while(i < numsSize)
    {
        if(nums[i] > nums[len])
        {
            len++;
            nums[len] = nums[i];
        }
        i++;
    }
    
    return 1 + len;
}