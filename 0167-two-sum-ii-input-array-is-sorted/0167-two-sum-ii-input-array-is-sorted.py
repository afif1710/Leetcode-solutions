class Solution(object):
    def twoSum(self, numbers, target):
        first = 0
        last = len(numbers) - 1


        sum = 0

        while(1):
            sum = numbers[first] + numbers[last]
            if(sum == target):
                break
            elif(sum>target):
                last -= 1
            elif(sum<target):
                first += 1

        first += 1
        last += 1
        
        li = [first, last]
        
        return li
