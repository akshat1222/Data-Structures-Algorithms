
#include <stdio.h>

//TRAVERSING THE ARRAY 
void display(int arr[],int n){
    for(int i=0; i<=n; i++){
        printf("%d\n",arr[i]);
    }
    
}

//INSERTING ELEMENT IN THE ARRAY
int indinsertion(int arr[],int index,int capacity,int size,int element){
    if(size>=capacity){
        return -1;
    }    
    for(int i=size-1;i>=index ;i--){
        arr[i+1]=arr[i];
}
    arr[index]=element;
}

int main(){
    int index, size=5, element;
    int arr[100]={1,2,33,72,88};
    printf("The elements already in array:\n");
    display(arr, size);
    printf("Enter the array index in which you want to put the value in:\n");
    scanf("%d",&index);
    printf("Enter the element to be insert:\n");
    scanf("%d",&element);
    indinsertion(arr,index,100,size,element);
    size+=1;
    if(arr[index]==element){
        printf("Insertion has been completed successfully\n");
        display(arr,size);
    }
    else{
        printf("Insertion has been failed!\n");
    }
    return 0;
}