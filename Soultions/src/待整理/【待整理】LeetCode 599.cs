public class Solution {
    public string[] FindRestaurant(string[] list1, string[] list2) {
        Dictionary<string, int> index = new Dictionary<string, int>();
        for (int i = 0; i < list1.Length; i++) {
            index.Add(list1[i], i);
        }

        IList<string> ret = new List<string>();
        int index_sum = int.MaxValue;
        for (int i = 0; i < list2.Length; i++) {
            if (index.ContainsKey(list2[i])) {
                int j = index[list2[i]];
                if (i + j < index_sum) {
                    ret.Clear();
                    ret.Add(list2[i]);
                    index_sum = i + j;
                } else if (i + j == index_sum) {
                    ret.Add(list2[i]);
                }
            }
        }
        return ret.ToArray();
    }
}