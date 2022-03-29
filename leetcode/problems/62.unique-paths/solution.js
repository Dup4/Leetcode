/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function (s, p) {
    const r = new RegExp(`^${p}$`);
    return r.test(s);
};
