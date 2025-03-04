#include <stdio.h>
#include <string.h>
int prod(int v[],int n){
    if (n < 1){
        return 1;
    } else return v[n-1] * prod(v, n-1);
}
int elim_c(int n, int c){
    if(n==0) return 0;
    int ultim=n%10;
    int cifra=elim_c(n/10,c);
    if(ultim != c){
        return cifra*10+ultim; 
    }
    else return cifra;
}

int nr_vocale(char v[]){
    if(strlen(v)==0) return 1;
    char vocals[]="AEIOUaeiou";
    if(strchr(vocals,v[0])){
        return 1+nr_vocale(v+1);
    }
    else{
        return nr_vocale(v+1);
    }

}

int rfact(int n){
    if(n==0) return 1;
    return n*rfact(n-1);
}

void ex5(int v[], int n, int *min, int *max, int *sum){
    if(n==1){
        *min = v[0];
        *max = v[0];
        *sum = v[0];
    }
    else{
        ex5(v,n-1,min,max,sum);
    
    if(*min>v[n-1]){
        *min = v[n-1];
    }
    if(*max<v[n-1]){
        *max = v[n-1];
    }
    *sum+=v[n-1];}
}

int main(){
    int n,c,p;
    int min,max,sum;
    int v[]={1,2,3,4,5};
    scanf("%d", &n);
    p=elim_c(1232323,2);
    switch (n)
    {
    case 1:
        printf("%d", p);
        break;
    case 2:
        printf("%d", nr_vocale("Aseara a plouat"));
        break;
    case 3:
        printf("%d", rfact(4));
        break;
    case 4:
        ex5(v,5,&min,&max,&sum);
        printf("%d %d %d", min,max,sum);
        break;
    case 5:
        printf("%d", prod(v,5));
        break;
    default:
        break;
    }
    return 0;
}