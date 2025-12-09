/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let n = nums.length;
    if(n == 0){
        return init;
    }
    let val = fn(init, nums[0]);
    init = val;

    for(let i = 1; i<n ; i++){
        val = fn(init, nums[i]);
        init = val;
    }

    return val;
};