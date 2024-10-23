#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

int coutOfPolindromes(std::string s1){ //функция посчёта палиндромов в строке
    int i = 0;
    int count = 0;
    bool isWordPolindrome;
    int last_find = 0;
    std::string word;
    while (last_find < s1.size()){
        while ( s1[i] == ' '){
            i ++;
        } 
        last_find = s1.find(" ", i);
        word = s1.substr(i, last_find - i);
        for (int k = 0; k < word[word.size() - k - 1]; ++k){
            if (word[k] != word[word.size() - k - 1]){
            isWordPolindrome = false;
            break;
            } else {
            isWordPolindrome = true;
            }
        }
        if (isWordPolindrome){
            count ++;
        }
        i = last_find + 1;   
    }
    return count;
}

void outputStringToFile (std::string s1, std::string fileName ){
    std::ofstream fout (fileName, std::ios::app);
    fout<< s1<<std::endl;
    fout.close();
}
  


int main(){
std::string NameInputFile;
std::cout<< "Enter the name (or the path to the input file) of the input file: ";
std::cin>> NameInputFile;
std::ifstream fin1(NameInputFile);
std::string s1;
std::string s2;
fin1 >> s2;
if (s2 == ""){
    std::ofstream fout ("empty_file.txt", std::ios::app);
    return 0;
}
std::ifstream fin(NameInputFile);
while(getline(fin, s1)){
    if (coutOfPolindromes(s1) == 1){
        outputStringToFile(s1, "one_polyndrom_strings.txt");
    } else if (coutOfPolindromes(s1) == 0){
        outputStringToFile(s1, "strinds_without_polyndroms.txt");
    } 
}
int choice;
do{
std::cout<<"Please select one of the following options: "<<std::endl;
std::cout<< "1 - view strings with one palindrome "<<std::endl;
std::cout<< "2 - view strings without palindromes "<<std::endl;
std::cout<< "3 - end "<<std::endl;
std::cin>> choice;
if (choice == 1){
    std::ifstream fin2("one_polyndrom_strings.txt");
    std::string line;
    while(getline(fin2, line)){
        std::cout<<line<<std::endl;
    }
}    
if (choice == 2){
    std::ifstream fin3("strinds_without_polyndroms.txt");
    std::string line;
    while(getline(fin3, line)){
        std::cout<<line<<std::endl;
    }
}
} while (choice != 3);
}
