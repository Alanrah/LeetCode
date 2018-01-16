#dict和map,list和vector
#enumerate()的用法
class Solution(object):
    def twoSum(self, nums, target):
        d = {}
        for i, n in enumerate(nums):#for index, item in enumerate(list):
            m = target - n
            if m in d:
                return [d[m], i]
            else:
                d[n] = i

solution = Solution()
nums =[2,7,11,5]
tar = 9
print(solution.twoSum(nums,tar))