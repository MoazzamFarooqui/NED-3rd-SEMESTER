#include<bits/stdc++.h>
using namespace std;

class ProductOfNumbers{
private:
    vector<int> nums;
public:
    ProductOfNumbers(){}
    void add(int num){
        nums.push_back(num);
    }
    int getProduct(int k){
        int product=1;
        int n=nums.size();
        for(int i=n-k;i<n;i++){
            product*=nums[i];
        }
        return product;
    }
};

int main(void){
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);
    cout<<productOfNumbers.getProduct(2)<<endl;
    cout<<productOfNumbers.getProduct(3)<<endl;
    cout<<productOfNumbers.getProduct(4)<<endl;
    productOfNumbers.add(8);
    cout<<productOfNumbers.getProduct(2)<<endl;
    return 0;
}
