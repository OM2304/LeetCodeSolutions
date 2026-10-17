class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n1 = a.size();
        int n2 = b.size();
        
        // 1. FIXED: Use a string directly instead of vector<int>
        string s = ""; 

        int i = n1-1;
        int j = n2-1;
        while(i>=0 && j>=0) {
            if(a[i]=='1' && b[j]=='1') {
                if(carry) {
                    s.push_back('1'); // Appending char '1' instead of int 1
                    carry = 0;
                }
                else s.push_back('0');
                carry = 1;
            } else if(a[i]=='0' && b[j]=='0') {
                if(carry) {
                    s.push_back('1');
                    carry = 0;
                } else s.push_back('0');
            } else {
                if(carry) {
                    s.push_back('0');
                } else {
                    s.push_back('1');
                }
            }
            i--;
            j--;
        }
        while(i>=0) {
            if(carry) {
                if(a[i]=='1') {
                    s.push_back('0');
                } else {
                    s.push_back('1');
                    carry = 0;
                }
            }
            else {
                s.push_back(a[i]); // a[i] is already a char ('0' or '1')!
            }
            i--;
        }
        while(j>=0) {
            if(carry) {
                if(b[j]=='1') {
                    s.push_back('0');
                } else {
                    s.push_back('1');
                    carry = 0;
                }
            }
            else s.push_back(b[j]); // b[j] is already a char!
            j--;
        }
        if(carry) {
            s.push_back('1');
        }

        // 2. FIXED: Simply reverse the string at the end instead of running a manual loop
        reverse(s.begin(), s.end()); 
        
        return s;
    }
};
