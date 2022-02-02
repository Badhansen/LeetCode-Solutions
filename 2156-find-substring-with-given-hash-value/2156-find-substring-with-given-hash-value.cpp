typedef long long LL;

class Solution {
public:
    LL modInverse(LL b, LL m){
        LL x, y;
        LL g = gcdExtended(b, m, &x, &y);
        if (g != 1)
            return -1;
        return (x % m + m) % m;
    }
    LL gcdExtended(LL a, LL b, LL *x, LL *y){
        if (a == 0){
            *x = 0, *y = 1;
            return b;
        }
        LL x1, y1;
        LL gcd = gcdExtended(b % a, a, &x1, &y1);
        *x = y1 - (b / a) * x1;
        *y = x1;
        return gcd;
    }
    LL calPower(LL x, unsigned int y, LL p){
        LL res = 1;
        x = x % p; 
        if (x == 0) return 0; 
        while (y > 0){
            if (y & 1)
                res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
        }
        return res;
    }
    LL modDivide(LL a, LL b, LL m){
        a = a % m;
        LL inv = modInverse(b, m);
        //if(inv == -1) return -1;
         LL c = (inv * a) % m;
        return c;
    }
    LL solve(string &s, LL p, LL m){
        LL hash = 0, res = 1;
        for(int i = 0; i < s.size(); i++){
            hash = hash + (s[i] - 'a' + 1) * res;
            res = (res * p) % m;
            hash %= m;
        }
        return hash;
    }
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int len = s.size();
        vector<LL> hash(len + 1), sum(len + 1), pw(len + 1);
        pw[0] = 1;
        for(int i = 1; i <= len; i++){
            pw[i] = (pw[i - 1] * power) % modulo;
        }
        for(int i = 0; i < len; i++){
            if(i == 0){
                sum[i] = ((s[i] - 'a' + 1) * pw[i]) % modulo;
            }
            else{
                sum[i] = (sum[i - 1] + (s[i] - 'a' + 1) * pw[i]) % modulo;
            }
            //cout << sum[i] << " ";
            hash[i] = sum[i] % modulo;
        }
        if(hash[k - 1] == hashValue){
            return s.substr(0, k);
        }
        for(int i = k; i < len; i++){
            LL diff = (hash[i] - hash[i - k] + modulo) % modulo;
            //if(diff < 0) diff += modulo;
            //LL h = modDivide(diff, calPower(power, i - k + 1, modulo), modulo);
            //cout << h << endl;
            LL pw = calPower(power, i - k + 1, modulo);
            LL npw = (pw * hashValue) % modulo;
            
            if(diff == npw){
                //return s.substr(i - k + 1, k);
                //cout << diff << " - "<< pw << " " << npw << endl;
                string ss = s.substr(i - k + 1, k); 
                if(solve(ss, power, modulo) == hashValue) return ss;
            }
        }
        return "";
    }
};