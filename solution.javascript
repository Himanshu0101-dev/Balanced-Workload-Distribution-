function minWorkloadDifference(projects) {
    const total = projects.reduce((sum, x) => sum + x, 0);
    const target = Math.floor(total / 2);

    const dp = new Array(target + 1).fill(false);
    dp[0] = true;

    for (const hours of projects) {
        for (let j = target; j >= hours; j--) {
            dp[j] = dp[j] || dp[j - hours];
        }
    }

    let best = 0;

    for (let s = target; s >= 0; s--) {
        if (dp[s]) {
            best = s;
            break;
        }
    }

    return total - 2 * best;
}
