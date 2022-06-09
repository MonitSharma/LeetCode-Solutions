int strStr(char * haystack, char * needle)
{
    int len = strlen(haystack),j;
    int l=strlen(needle);
   
    if(l==0)
    return 0;
    
    if(len<l)
    return -1;
    
    for(int i=0;i<len;i++)
    {
        for(j=0;j<l;j++)
        {
            if(haystack[i+j]!=needle[j])
            break;    
        }
        if(j==l)
        return i;
    }  
    return -1;
}