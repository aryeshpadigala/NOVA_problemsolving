int lengthOfLastWord(char* s) 
{
    int i=strlen(s)-1;
    int last_word_count=0;
    while(i>=0 && s[i]==' ')
    {
        i--;
    }
    while(i>=0 && s[i]!=' ')
    {
        last_word_count++;
        i--;
    }
    return last_word_count;
    
}