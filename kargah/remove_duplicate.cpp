#include <iostream>
using namespace std;
struct Data{
    int *array;
    int size;
    Data *next;
};

int main(){
   Data *phead=nullptr;
   int t;
   cin>>t;
   int n;
   cin>>n;
   Data *temp=phead;
   for (int i=0;i<t;i++){
        Data *new_data=new Data;
        new_data->array=(int *)malloc(sizeof(int)*n);
        new_data->next=nullptr;

        for (int j=0;j<n;j++){
            cin>>new_data->array[j];
        }
        if (phead==nullptr){
            phead=new_data;
            temp=phead;
        }
        else{
            temp->next=new_data;
            temp=temp->next;
        }
   } 
   for (Data *temp=phead;temp!=nullptr;temp=temp->next){
    for (int i=0;i<n-1;i++){
        int flag=0;
        for (int j=0;j<n-1-i;j++){
            if (temp->array[j]>temp->array[j+1]){
                swap(temp->array[j],temp->array[j+1]);
                flag=1;
            }
        }
        if (flag==0){
            break;
        }
    }
   }
 for (Data *temp = phead; temp != nullptr; temp = temp->next) {
    int size=n;
  for (int i=0;i<size;i++){
    for (int j=i+1;j<size;j++){
        if (temp->array[i]==temp->array[j]){
            for (int k=j;k<size-1;k++){
                temp->array[k]=temp->array[k+1];
            }
             j--;
            size--;
        }
    }
  }
  int *new_array=(int *)malloc(size*sizeof(int));
    for (int z=0;z<size;z++){
        new_array[z]=temp->array[z];
    }
    free(temp->array);
    temp->array=new_array;
    temp->size=size;
}

   FILE *file;
   file=fopen("Data.txt","w");
    for (Data *temp=phead;temp!=nullptr;temp=temp->next){
        int new_size1;
        new_size1=temp->size;
        for (int i=0;i<new_size1;i++){
            fprintf(file,"%d ",temp->array[i]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
}