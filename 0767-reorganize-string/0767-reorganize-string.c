
char * reorganizeString(char * S){
    int arr[26] = {0};
    
    int siz = 0;
    for(int i = 0; S[i]; i++){
        arr[S[i] - 'a']++;
        siz++;
    }
    char *st = (char *)malloc(sizeof(char) * 504);
    int idx = 0;
    int pr = -1;
    for(int i = 0; i < siz; i++){
        int id = 0, mx = -1;
        for(int j = 0; j < 26; j++){
            if(mx <= arr[j] && pr != j){
                mx = arr[j];
                id = j;
            }
        }
        if(arr[id] == 0) return "";
        st[i] = 'a' + id;
        arr[id]--;
        pr = id;
    }
    st[siz] = 0;
    return st;
}

