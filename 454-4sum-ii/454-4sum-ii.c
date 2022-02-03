void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
void QuickSort(int *arr, int low, int high){
    int pivot = arr[(high + low) / 2];
    int L = low;
    int R = high;
    while(L <= R){
        while(arr[L] < pivot) L++;
        while(arr[R] > pivot) R--;
        if(L <= R){
            swap(&arr[L], &arr[R]);
            L++, R--;
        }
    }
    if(low < R){
        QuickSort(arr, low, R);   
    }
    if(L < high){
        QuickSort(arr, L, high);
    }
}

bool find(int *arr, int low, int high, int key){
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == key) return true;
        if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return false;
} 

/*
typedef struct Node{
    int key;
    int count;
    struct Node* left, *right;
}Node;
Node *root;
Node* newNode(int key){
    Node* t = (Node*) malloc(sizeof(Node));
    t->key = key;
    t->count = 1;
    t->left = t->right = NULL;
    return t;
}
Node* insert(Node* root, int key){
    if(root == NULL) return newNode(key);
    if(root->key == key){
        root->count++;
    }
    if(root->key > key)
        root->left = insert(root->left, key);
    if(root->key < key)
        root->right = insert(root->right, key);
    return root;
}
Node* Find(Node* root, int key){
    if(root == NULL) return NULL;
    if(root->key == key) return root;

    if(root->key > key)
        return Find(root->left, key);
    if(root->key < key)
       return Find(root->right, key);
    return NULL;
}
*/

int lowerBound(int *arr, int low, int high, int key){
    int ans = -1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(arr[mid] == key){
            ans = mid;
            high = mid - 1;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
int upperBound(int *arr, int low, int high, int key){
    int ans = -1;
    while(low <= high){
        int mid = (high + low) / 2;
        if(arr[mid] == key){
            ans = mid;
            low = mid + 1;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}
int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize){
    if(ASize == 0 || BSize == 0 || CSize == 0 || DSize == 0) return 0;
    int *ab = (int *)malloc(sizeof(int) * (ASize * BSize));
    int *cd = (int *)malloc(sizeof(int) * (CSize * DSize));
    int idx = 0;
    // root = NULL;
    for(int i = 0; i < ASize; i++){
        for(int j = 0; j < BSize; j++){
            ab[idx++] = A[i] + B[j];
        }
    }
    idx = 0;
    for(int i = 0; i < CSize; i++){
        for(int j = 0; j < DSize; j++){
            cd[idx++] = C[i] + D[j];
            //root = insert(root, cd[idx - 1]);
        }
    }
    QuickSort(cd, 0, idx - 1);    
    int cnt = 0;
    for(int i = 0; i < idx; i++){
        if(find(cd, 0, idx - 1, -1 * ab[i])){
            cnt += (upperBound(cd, 0, idx - 1, -1 * ab[i]) - lowerBound(cd, 0, idx - 1, -1 * ab[i]) + 1);
        }
    }
    return cnt;
}

