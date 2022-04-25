vector<int> sort_binary(vector<int> vec){
    int n = vec.size();
    for (int i = 1; i < n; i++){
        //if (vec[i] < vec[i-1]) swap(vec[i], vec[i-1]);
        //冒泡
        while (i > 0){
            if (vec[i] < vec[i-1]) swap(vec[i], vec[i-1]);
            i--;
        }
    }
    return vec;
}