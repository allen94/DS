void quicksort(T a[],int low,int high)
{
    int mid;
    if(low>=high) return;
    mid=divide(a,low,high);
    quicksort(a,low,mid-1);
    quicksort(a,mid+1,high);
}

void quicksort(T a[],int size)
{
    quicksort(a,0,size-1);

}

int divide(T a[],int low,int high)
{
    T k=a[low];
    do {while(low<high&&a[high]>=k) --high;
        if (low<high) {a[low]=a[high];++low;}
        while(low<high&&a[high]<=k) ++low;
        if (low<high) {a[high]=a[low];--high;}
    }while(low!=high);
    a[low]=k;
    return low;
}
