int* plusOne(int* digits, int digitsSize, int* returnSize){
    
     for(int i=digitsSize-1;i>=0;i--)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
            }
            else{
                digits[i]+=1;
                * returnSize=digitsSize;
                return digits;
            }
        }
        * returnSize=++digitsSize;
        int* result = malloc(digitsSize * sizeof(int));
    for(int i=1;i<digitsSize;i++)
    {
        result[i]=0;
    }
        result[0]=1;
    return result;
    
     
}