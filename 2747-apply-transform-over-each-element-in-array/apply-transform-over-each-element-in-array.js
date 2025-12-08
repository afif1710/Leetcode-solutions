/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let n = arr.length;
    let retArr = new Array(n);
    for(let i = 0; i<n; i++){
        retArr[i] = fn(arr[i], i);
    }
    return retArr;
};