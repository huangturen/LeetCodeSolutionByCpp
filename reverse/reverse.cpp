#include <iostream>

int reverse(int x) {
    int start = x;
    int ret = 0;
    int index = 0;
    while(start !=0 ){
        int mod = start % 10;
        start /= 10;
        if(!(mod == 0 && index ==0)){
            if (ret > INT_MAX/10 || ret < INT_MIN/10) {
                return 0;
            }
            ret = ret * 10 + mod;
        }
        index++;
    }
    return ret;
}



int main(int argc, const char * argv[]) {
    vector<int> nums = {2,7,9,11,5};
//    vector<int> nums = {3,3};

    int reversed = reverse(123);
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
