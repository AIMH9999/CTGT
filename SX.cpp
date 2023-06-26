#include <stdio.h>

void nhap(int n[], int *len){
	char c;
	int i=0;
	printf("Nhap day so n: ");
	do{
		scanf("%d%c", &n[i], &c);
		i++;
	}while(c!=10);
	*len = i;
}

void xuat(int n[], int len){
	int i;
	printf("\n");
	for(i=0;i<len;i++){
		printf("n[%d]=%d ",i , n[i]);
	}
}

void sw(int *a, int *b){
	int s;
	s = *a;
	*a = *b;
	*b = s;
}

void Bubble_Sort(int n[], int len){
	int i, j;
	for(i=0;i<len;i++){
		for(j=len-1;j>i;j--){
			if(n[j]<n[j-1]){
				sw(&n[j], &n[j-1]);
			}
		}
	}
}

void insertionSort(int n[], int len)
{
	int i, j, key;
	for(i=1;i<len;i++){
		key = n[i];
		j=i-1;
		while(j>=0 && n[j]<key){
			n[j+1] = n[j];
			j=j-1;
		}
		n[j+1] = key;
	}
}

void selectionSort(int n[], int len)
{
    int i, j;
    for (i = 0; i < len-1; i++){
 		for (j = i+1; j < len; j++){
     		if (n[j] < n[i]){
 			    sw(&n[j], &n[i]);
 			}
 		}
    }
}


int main(){
	int n[100];
	int len;
	nhap(n, &len);
	xuat(n, len);
	Bubble_Sort(n, len);
	xuat(n, len);
	insertionSort(n, len);
	xuat(n, len);
	selectionSort(n, len);
	xuat(n, len);
}