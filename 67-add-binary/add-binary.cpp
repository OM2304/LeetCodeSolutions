class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        int n1 = a.size();
        int n2 = b.size();
        vector<int> v;

        int i = n1-1;
        int j = n2-1;
        int sum = 0;
        while(i>=0 && j>=0) {
            if(a[i]=='1' && b[j]=='1') {
                if(carry) {
                    v.push_back(1);
                    carry = 0;
                }
                else v.push_back(0);
                carry = 1;
            } else if(a[i]=='0' && b[j]=='0') {
                if(carry) {
                    v.push_back(1);
                    carry = 0;
                } else v.push_back(0);
            } else {
                if(carry) {
                    v.push_back(0);
                } else {
                    v.push_back(1);
                }
            }
            i--;
            j--;
        }
        while(i>=0) {
            if(carry) {
                if(a[i]=='1') {
                    v.push_back(0);
                } else {
                    v.push_back(1);
                    carry = 0;
                }
            }
            else {
                v.push_back((a[i]-'0'));
            }
            i--;
        }
        while(j>=0) {
            if(carry) {
                if(b[j]=='1') {
                    v.push_back(0);
                } else {
                    v.push_back(1);
                    carry = 0;
                }
            }
            else v.push_back((b[j]-'0'));
            j--;

        }
        if(carry) {
            v.push_back(1);
        }
        string s = "";
        for(int i=v.size()-1; i>=0; i--) {
            s += to_string(v[i]);
        }
        return s;
    }
};