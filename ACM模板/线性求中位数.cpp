#include<cstdio>

int find_mid(int arr[], int left, int right, int x)
//下标从零开始
{
    if(left >= right){
        return arr[left + x];
    }
    int mid = arr[left];
    int i = left;
    int j = right;
    while(i < j){
        while(i < j && arr[j] >= mid) j--;
        arr[i] = arr[j];
        while(i < j && arr[i] <= mid) i++;
        arr[j] = arr[i];
    }
    arr[j] = mid;
    if(i - left == x)
        return arr[i];
    if(i - left < x)
        return find_mid(arr, i + 1, right, x - (i - left + 1));
    else
        return find_mid(arr, left, i - 1, x);
}

int arr[10005];
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0;i < n;i ++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", find_mid(arr, 0, n-1, n / 2));
    }
    return 0;
}
