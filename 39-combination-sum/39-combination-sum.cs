public class Solution {
    IList<IList<int>> answer = new List<IList<int>>();
    public void dfs(int pos, int[] candidates, int target, IList<int> path)
    {
        if(target == 0)
        {
            answer.Add(path.ToList());
            return;
        }
        if(target < 0 || pos >= candidates.Length)
        {
            return;
        }
        for(int i = pos; i < candidates.Length; i++){
            path.Add(candidates[i]);
            dfs(i, candidates, target - candidates[i], path);
            path.RemoveAt(path.Count - 1);
        }
    }
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        IList<int> path = new List<int>();
        dfs(0, candidates, target, path);
        return answer;
    }
}