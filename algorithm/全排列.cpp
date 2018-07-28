#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void permutation(char* s,char* e)
{
    if(*s == '\0')
    {
        cout<<e<<endl;
    }
    else
    {
        int len = strlen(s);

        for(int i = 0;i<len;i++)
        {
            if((i == 0) || (s[0] != s[i]))
            {
            swap(s[0],s[i]);
            permutation(s+1,e);
            swap(s[0],s[i]);
            }
        }
    }
}
int main()
{
    char s[] = "aac";
    permutation(s,s);
    return 0;
}
