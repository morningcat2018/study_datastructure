import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 出现频率最高的前K个数
 */
public class TopKFrequency {

    @SuppressWarnings("unchecked")
    public static List<Integer> topK(int[] datas, int k) {
        Map<Integer, Integer> frequencyMap = new HashMap<>();
        for (Integer data : datas) {
            frequencyMap.put(data, frequencyMap.getOrDefault(data, 0) + 1);
        }
        List<Integer>[] buckets = new ArrayList[datas.length + 1];
        for (int key : frequencyMap.keySet()) {
            int count = frequencyMap.get(key);
            if (buckets[count] == null) {
                buckets[count] = new ArrayList<>();
            }
            buckets[count].add(key);
        }

        List<Integer> topK = new ArrayList<>();
        for (int i = buckets.length - 1; i >= 0 && topK.size() < k; i--) {
            if (buckets[i] == null)
                continue;
            if (buckets[i].size() <= (k - topK.size())) {
                topK.addAll(buckets[i]);
            } else {
                topK.addAll(buckets[i].subList(0, k - topK.size()));
            }
        }
        return topK;
    }

    public static void main(String[] args) {
        int[] a = new int[]{1, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 4, 4, 4, 8};
        List<Integer> topK = topK(a, 3);
        topK.stream().forEach(System.out::println);
    }
}