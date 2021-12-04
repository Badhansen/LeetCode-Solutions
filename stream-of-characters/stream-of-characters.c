char arr[100001];
int cnt;

int mstrlen(char *str){
    int len = 0;
    while(str[len]){
        len++;
    }
    return len;
}
typedef struct trieStruct {
    int isLeaf;
    struct trieStruct *child[26];
}Trie;
Trie *createNode() {
    Trie *newNode = (Trie *)malloc(sizeof(Trie));
    newNode->isLeaf = 0;
    for (int i = 0; i < 26; i++)
        newNode->child[i] = NULL;
    return newNode;
}
void insert(Trie *root, char word[]) {
    Trie *cur = root;
    int len = mstrlen(word);
    for (int i = len - 1; i >= 0; i--) {
        int id = word[i] - 'a';
        if (NULL == cur->child[id])
            cur->child[id] = createNode();
        cur = cur->child[id];
    }
    cur->isLeaf = 1;
}
bool find(Trie *root, char word[]){
    Trie *curr = root;
    for(int i = cnt - 1; i >= 0; i--){
        int id = word[i] - 'a';
        if(curr->child[id] == NULL) return false;
        if(curr->child[id]->isLeaf) return true;
        curr = curr->child[id];
    }
    return curr->isLeaf;
}
void print(Trie *cur, char word[], int pos) {
    if (NULL == cur) return;
    if (cur->isLeaf == 1) {
        word[pos] = '\0';
    }
    for (int i = 0; i < 26; i++) {
        word[pos] = i + 'a';
        print(cur->child[i], word, pos + 1);
    }
}





typedef struct {
    Trie *root;
} StreamChecker;


StreamChecker* streamCheckerCreate(char ** words, int wordsSize) {
    StreamChecker* t = (StreamChecker *)malloc(sizeof(StreamChecker));
    t->root = createNode();
    for(int i = 0; i < wordsSize; i++){
        insert(t->root, words[i]);
    }
    cnt = 0;
    return t;
}


bool streamCheckerQuery(StreamChecker* obj, char letter) {
    arr[cnt++] = letter;
    arr[cnt] = '\0';
    return find(obj->root, arr);
}

void streamCheckerFree(StreamChecker* obj) {
    cnt = 0;
    free(obj);
}

/**
 * Your StreamChecker struct will be instantiated and called as such:
 * StreamChecker* obj = streamCheckerCreate(words, wordsSize);
 * bool param_1 = streamCheckerQuery(obj, letter);
 
 * streamCheckerFree(obj);
*/