/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch = function (s, p) {
    p = p.replace(/\?/g, ".");
    p = p.replace(/\*/g, ".*");
    const r = new RegExp(`^${p}$`);
    return r.test(s);
};
