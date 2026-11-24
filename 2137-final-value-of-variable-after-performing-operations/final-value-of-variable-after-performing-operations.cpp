class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(string ex : operations) {
            if(ex=="X++" || ex=="++X") {
                cout<<"++"<<endl;
                x+=1;
            }
            else  {
                cout<<"--"<<endl;
                x-=1;
            }
        }
        return x;
    }
};