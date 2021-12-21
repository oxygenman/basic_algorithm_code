#include <iostream>
#include <vector>
using namespace std;
//冒泡排序
vector<int> bubbleSort(vector<int> array){
    int len=array.size();
    if(len==0) return array;
    for(int i =0;i<len;i++){
        bool exchange=false;
        for(int j=0;j<len-1-i;j++){
            if(array[j]>array[j+1]){
            swap(array[j],array[j+1]);
            exchange=true;
            }
        }
        if(!exchange) return array;

    }
    return array;
}

vector<int> selectSort(vector<int> array){
    int len = array.size();
    for(int i=0;i<len;i++){
        int minIndex=i;
        for(int j=i;j<len;j++){
            if(array[j]<array[minIndex])
            minIndex=j;
        }
        swap(array[i],array[minIndex]);
    }
    return array;
}

vector<int> insertSort(vector<int> array){
    int len = array.size();
    for(int i= 0;i<len-1;i++){
        int current=array[i+1];
        int preIndex=i;
        while(preIndex>=0&&current<=array[preIndex]){
            array[preIndex+1]=array[preIndex];
            preIndex--;
        }
        array[preIndex+1]=current;
    }
    return array;
}

vector<int> hillSort(vector<int> array){
    int len=array.size();
    for(int gap=len/2;gap/=2;gap>0){
        for(int i = gap;i<len;i++){
            int current=array[i];
            int preIndex=i-gap;
            while(preIndex>=0&&array[preIndex]>current){
                array[preIndex+gap]=array[preIndex];
                preIndex-=gap;

            }
            array[preIndex+gap]=current;
        }

    }
    return array;
}
int main(){
   
    vector<int> array{2,3,5,1,9,2,3,4,5,8,3,4,9,0,1,2,15,18,12,20};
    vector<int> result=hillSort(array);
    for(int i=0;i<20;i++){
        cout<<i<<":"<<result[i]<<endl;
    }


}