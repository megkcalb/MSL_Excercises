#include<stdio.h>
int main(){
    char str1[]="meg";
    char str2[]="gilji";
    //char c='e';
   squeeze2(char str1[], char str2[]) {
    int i, j, k;
    for (k = 0;str2[k] != '\0'; k++) {
        for (i = j = 0; str1[i] != '\0'; i++)
            if (str1[i] != str2[k])
                str1[j++] = str2[i];
        str1[j] = '\0';
    }
}

    return 0;
}
