/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {

     var result = []
    nums.forEach(function(num, i) {
        var diff = target - nums[i]
        var k = nums.indexOf(diff)
        if (k > -1 && k !== i) {
           result[0] = i
           result[1] = k
           return true
        }
      })
  return result
};