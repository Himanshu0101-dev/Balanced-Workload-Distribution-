def balanced_workload(projects):
    total = sum(projects)
    n = len(projects)
    
    # DP subset sum approach
    target = total // 2
    dp = [False] * (target + 1)
    dp[0] = True
    
    for hours in projects:
        for j in range(target, hours - 1, -1):
            if dp[j - hours]:
                dp[j] = True
    
    for i in range(target, -1, -1):
        if dp[i]:
            return total - 2 * i

# Dry Run Example
print(balanced_workload([10, 20, 15, 5]))  # Output: 0
print(balanced_workload([3, 1, 4, 2, 2]))  # Output: 0
print(balanced_workload([8, 6, 5]))        # Output: 3
