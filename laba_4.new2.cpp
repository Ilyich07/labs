#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int chanceStringToInt (const char *string){
    int num = 0;
    for(int i = 0; string[i] != '\0'; ++i){
        int int_i_order;
        char chr_i_order;
        chr_i_order = string[i];
        int_i_order = (int)chr_i_order - 48;
        num = num*10 + int_i_order;
    }
    return num;
}

char* replaceSpaces (char* string){
int str_length = strlen(string);
for (int i = 0; i < str_length; ++i){
    if (string[i] == ' '){
        string[i] = '\0';
    } 
}
return string;
}

int findCoutOfRepeats (char* word){
int max_repeat = 0;
for (int i = 0; i <= strlen(word); ++i){
    int repeat = 0;
    for (int k = 0; k <= strlen(word); ++k){
        if (word[i] == word[k]){
            ++ repeat;
        }
    }
    if (max_repeat < repeat){
        max_repeat = repeat;
    }
}
return max_repeat;
}

int main(){

// Задача А

char str[] = "1257483098"; // Любое целое число в десятичной системе счисления в символьном виде
cout << chanceStringToInt(str)<<endl;
cout << chanceStringToInt(str) + 3 <<endl;

// Задача В

const int MAX_SIZE = 300;
char str1[MAX_SIZE];
cout<< "Input a string of no more than 300 characters: ";
gets_s(str1, MAX_SIZE);
cout<< str1<< endl;

int lenght_of_string = strlen(str1);
replaceSpaces(str1);
int n = 0;
int max_repeat = 0;
char max_word[300];

while (n < lenght_of_string){
    while (str1[n] == '\0'){
        ++n;
    }
    char *word = new char[300];
    strcpy(word, &str1[n]);
    if (max_repeat < findCoutOfRepeats(word)){
        max_repeat = findCoutOfRepeats(word);
        strcpy(max_word, word);
    }
    n = n + strlen(word) + 1;
    delete[]word;
}
cout<<max_word;
}









