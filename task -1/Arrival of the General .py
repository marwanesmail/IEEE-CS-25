def minimum_swaps(n, heights):
    max_height = max(heights)
    min_height = min(heights)
    
    
    max_index = heights.index(max_height)
  
    min_index = len(heights) - 1 - heights[::-1].index(min_height)
    
  
    if max_index > min_index:
        return max_index + (n - 1 - min_index) - 1
    else:
        return max_index + (n - 1 - min_index)


n = 4
heights = [33, 44, 11, 22]
print(minimum_swaps(n, heights))  

n = 7
heights = [10, 10, 58, 31, 63, 40, 76]
print(minimum_swaps(n, heights))  