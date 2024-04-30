#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isOpen(char ch) {
        return ch == '{' || ch == '(' || ch == '[';
    }

    bool isPair(char open, char close) {
        return (open == '{' && close == '}') || (open == '(' && close == ')') || (open == '[' && close == ']');
    }
    
    bool isValid(std::string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (isOpen(s[i])) {
                st.push(s[i]);
            }
            else {
                if (!st.empty() && isPair(st.top(), s[i])) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.empty();
    }
private:
    std::stack<char> st;
};

int main() {
    Solution ob;
    
    std::string str1 = "()({[]}())"; // true
    std::string str2 = "{}"; // true
    std::string str3 = "}{"; // false
    std::string str4 = ""; // true
    std::string str5 = "(()"; // false
    std::string str6 = "())"; // false
    std::string str7 = "[(])"; // false

    std::cout << ob.isValid(str1) << std::endl;
    std::cout << ob.isValid(str2) << std::endl;
    std::cout << ob.isValid(str3) << std::endl;
    std::cout << ob.isValid(str4) << std::endl;
    std::cout << ob.isValid(str5) << std::endl;
    std::cout << ob.isValid(str6) << std::endl;
    std::cout << ob.isValid(str7) << std::endl;
}
