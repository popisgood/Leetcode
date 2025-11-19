#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

class Solution {
    public:
        string longestPalindrome(string s) {
            string output = "";
            int size = s.size();
            cout<<"size: "<<size<<endl;
            if(size == 1 || (size == 2 && s[0] == s[1])){
                return s;
            }else if (size == 2 ){
                return s.substr(0, 1);
            }
            if(s[0] == s[1]){
                output = s.substr(0,2);
            }
            for (int i=1;i<size-1;i++){
                int left = i - 1;
                int right = i + 1;
                string temp = Palindrome(s, left, right);
                string temp2;
                if(s[i] == s[i+1]){
                    temp2 = Palindrome(s, left, right+1);
                }
                cout<<"i: "<<i<<", "<<"temp: "<<temp<<", temp2: "<<temp2<<endl;
                if(temp2.size()>temp.size() && temp2.size()>output.size()){
                    output = temp2;
                }else if (temp.size()> temp2.size() && temp.size() > output.size()){
                    output = temp;
                }
            }

            return output;
        }
    private:
        string Palindrome(string s , int left, int right){
            if(left < 0 || right > s.size()-1){
                return s.substr(left+1, right-left-1);
            }
            if(s[left] == s[right]){
                return Palindrome(s, left-1, right+1);
            }else{
                return s.substr(left+1, right-left-1);
            }
        }
};

int main (){
    string s = "ccd";
    Solution class_A;
    string output = class_A.longestPalindrome(s);
    cout<<"output: "<<output<<endl;

    return 0;
}