class ATM {
private:
    vector<long long> banknotes = {20, 50, 100, 200, 500}, noteCount;
public:
    ATM() {
        noteCount.resize(5, 0);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i = 0; i < 5; i++){
            noteCount[i] += banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int> answer(5, 0);
        for(int i = 4; i >= 0; i--){
            if(noteCount[i] == 0 || amount < banknotes[i]){
                continue;
            }
            if(amount == 0){
                break;
            }
            long long count = amount / banknotes[i];
            answer[i] = min(noteCount[i], count);
            if(count == 0){
                break;
            }
            amount = amount - answer[i] * banknotes[i];
        }
        if(amount == 0){
            for(int i = 0; i < 5; i++){
                noteCount[i] -= answer[i];
            }
            return answer;
        }
        return {-1};
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */