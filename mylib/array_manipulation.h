#include <iostream>
#include <cstring>
using namespace std;
void sort_array_1D(float a[],int len_a){
    for (int i=0;i<len_a-1;i++){
        int flag=0;
        for (int j=0;j<len_a-i-1;j++){
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if (flag==0){
            break;
        }
        
    }
}
void print_array_1D(int a[],int len){
    for (int i=0;i<len;i++){
        cout<<a[i]<<"   ";
    }
}
void print_array_2D(float **a,int satr,int soton){
    for (int i=0;i<satr;i++){
        for (int j=0;j<soton;j++){
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void freeMatrix(float **array, int len) {
    for (int i = 0; i < len; i++) {
        free(array[i]);
    }
    free(array);
}
float **createarray2D(int length,int hieght){
    float **result=(float **)malloc(length*sizeof(float *));
    for (int i=0;i<length;i++){
        result[i]=(float*)malloc(hieght*sizeof(float));
    }
    return result;
}
float *createarray1D(int length){
    float *result=(float*)malloc(length*sizeof(int));
    return result;
}
void cin_array1D(float *array,int length){
    for (int i=0;i<length;i++)
        cin>>array[i];
}
void cin_array2D(float **array,int length,int hieght){
    for (int i=0;i<length;i++){
        for (int j=0;j<hieght;j++){
            cin>>array[i][j];
        }
    }
}
float **subtract_Matrix(float **array1,float **sarray2,int len,int hieght){
    float **result=createarray2D(len,hieght);
    for (int i=0;i<len;i++){
        for (int j=0;j<hieght;j++){
            result[i][j]=array1[i][j]-sarray2[i][j];
        }
    }
    return result;
    free(result);


}
float **sum_Matrix(float **array1,float **sarray2,int len,int hieght){
    float **result=createarray2D(len,hieght);
    for (int i=0;i<len;i++){
        for (int j=0;j<hieght;j++){
            result[i][j]=array1[i][j]+sarray2[i][j];
        }
    }
    return result;
    free(result);


}
float **multipies_Matrix(float **array1,float **array2,int len_array1,int hieght_array1,int hieght_array2){
    float **c=createarray2D(len_array1,hieght_array2);
    for (int i=0;i<len_array1;i++){
        for (int j=0;j<hieght_array2;j++){
            for (int k=0;k<hieght_array1;k++){
                c[i][j]+=array1[i][k]+array2[k][j];
            }
        }
    }
    return c;
    freeMatrix(c,len_array1);
}
float *mergesort(float *array,float *array2 ,int l,int l2){
    int i=0, j=0,k=0;
    float *result=createarray1D(l+l2);
    while (i<l&&j<l2){
        if (array[i]<array2[j]){
            result[k++]=array[i++];
        }
        else {
            result[k++]=array2[j++];
        }
    }
    while (i<l){
        result[k++]=array[i++];
    }
    while(j<l2){
        result[k++]=array2[j++];    
    }
    return result;
    free(result);

}