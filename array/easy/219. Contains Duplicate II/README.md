### 标题
1. 我的方法
* 超过了92.72%方法，主要用unordered_map 记录键值和这个键最新出现的位置，下一次再遇到时判断索引差距。注意unordered_map对于不存在的键默认为0，所以数组所以要加一。
* 这种方法与我的类似，但更整洁，判断键值是否存在用 **map.count(nums[i])**或者**hashMap.find(nums[i])**。但好像更慢
```C++
    unordered_map<int,int> map;
    for(int i = 0; i < nums.size(); i++){
      if(map.count(nums[i]) && (i - map[nums[i]] <= k)) return true;
      map[nums[i]] = i;
    }
    return false;
```
2. 方法2
* 动态维持一个长为k的set，包含nums[i - k] 到 nums[i - 1]的唯一值，如果nums [i]在集合s中，则返回true否则更新集合。
```C++
 unordered_set<int> s;
       
       if (k <= 0) return false;
       if (k >= nums.size()) k = nums.size() - 1;
       
       for (int i = 0; i < nums.size(); i++)
       {
           if (i > k) s.erase(nums[i - k - 1]);
           if (s.find(nums[i]) != s.end()) return true;
           s.insert(nums[i]);
       }
       
       return false;
```


