class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int increase = 1;
        for(vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it){
            *it += increase;
            if(*it > 9){
                *it %= 10;
            }else{
                increase = 0;
            }
        }
        vector<int> resultVector;
        if(increase)
               resultVector.push_back(increase);
        for(vector<int>::iterator it = digits.begin(); it != digits.end(); ++it){
              resultVector.push_back(*it);
        }
        return resultVector;
        
    }
};
