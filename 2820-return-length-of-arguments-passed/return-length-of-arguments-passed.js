/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    // let count = 0;
    // for(key in args) {
    //     count++;
    // }
    // return count;

    return Object.keys(args).length;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */