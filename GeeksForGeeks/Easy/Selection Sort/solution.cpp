class Solution {
  public:
    void selectionSort(vector<int> &arr) {
        int n=arr.size();
        for (int i = 0; i<n-1;i++){
            int m=i;
            for(int j=i;j<n;j++){
                if(arr[j]<arr[m]){
                    m=j;
                }
            }
            int t=arr[m];
            arr[m]=arr[i];
            arr[i]=t;
        }
        
    }
};