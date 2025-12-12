/**
 * @param {Promise} promise1  // a promise that will resolve to a number
 * @param {Promise} promise2  // another promise that will resolve to a number
 * @return {Promise}          // a promise that resolves to the sum of the two numbers
 */
var addTwoPromises = async function(promise1, promise2) {
    // Wait until promise1 finishes and get its resolved value (a number)
    const p1 = await promise1;

    // Wait until promise2 finishes and get its resolved value (a number)
    const p2 = await promise2;

    // Return the sum; because this is an async function,
    // the sum is automatically wrapped in a Promise
    return p1 + p2;
};


/**
 * Example usage:
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // logs 4 when both promises are done
 */
