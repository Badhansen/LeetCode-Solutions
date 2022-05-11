public class Solution {
    public int CountConsistentStrings(string allowed, string[] words) {
        char[] wset = allowed.ToArray();
        int count = 0;
        foreach(string word in words)
        {
            char[] nwset = word.Distinct().OrderBy(c => c).ToArray();
            if(!nwset.Except(wset).Any())
            {
                count++;
            }   
        }
        return count;
    }
}