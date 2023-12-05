#include<iostream>
#include<string>
using namespace std;
/*lengthOfLastWord() is a function which takes a string as an input and returns the length of the last word of the string as output*/
int lengthOfLastWord(string s){
    //setting res variable to zero because the length of the last word in a empty string is zero 
    int res=0;
    //Traversing the string from the last index[ie s.length()-1 th index] of the string
    for(int i=s.length()-1;i>=0;i--){
        //if spaces are present after the last word in the string then continue until you get the characters of last word
        if(s[i]==' ' && res==0){
            continue;
        }
        //if the current character is a letter then increment res
        else if(s[i]!=' '){
            res++;
        }
        //if the current character is a space then come out of the loop, because space cannot be part of the word
        else{
            break;
        }
    }
    //returning the length of the last word in the string
    return res;
}
int main(){
    string s;
    //Taking the input from the user
    cout << "Enter a string: " ;
    //The getline() function in C++ is used to read a string or a line from an input stream 
    getline(cin,s);
    //The length of the last word of the string is stored in the variable result
    int result = lengthOfLastWord(s);
    //Printing the length of the last word of the string
    cout << "The length of the last word in the string "  << s << " is " << result;
    return 0;
}