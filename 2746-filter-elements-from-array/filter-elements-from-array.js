/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let n = arr.length;
    let l = 0;
    fil_arr = new Array();
    for(let i = 0; i<n ; i++){
        if(fn(arr[i], i)){
            fil_arr[l] = arr[i];
            l++;
        }
    }

    return fil_arr;
};