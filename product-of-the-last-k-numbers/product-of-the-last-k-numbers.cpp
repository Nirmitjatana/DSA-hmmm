class ProductOfNumbers {
public:
    vector<int> arr; 
    ProductOfNumbers() {
        arr = {1};
    }
    
    void add(int num) {
        if(num)
            arr.push_back(arr.back() * num);
        else
            arr = {1};
    }
    
    int getProduct(int k) {
        int n = arr.size();
        return (n - k - 1 >= 0) ? (arr.back() / arr[n - k - 1]) : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */