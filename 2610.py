'''
https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
'''

"""
You are given an integer array nums. You need to create a 2D array from nums satisfying the following conditions:

The 2D array should contain only the elements of the array nums.
Each row in the 2D array contains distinct integers.
The number of rows in the 2D array should be minimal.
Return the resulting array. If there are multiple answers, return any of them.

Note that the 2D array can have a different number of elements on each row.
"""

def findMatrix(nums):

    d = {}

    for num in nums:
        if num in d.keys():
            d[num] += 1
        else:
            d[num] = 1

    # answer = [[] for _ in range(max(d.values()))]

    # for key in d.keys():

    #     for value in range(d[key]):

    #         answer[value].append(key)

    answer = []

    while d:
        temp = []
        toRemove = []

        for key, value in d.items():
            temp.append(key)
            value -= 1
            if (value == 0):
                toRemove.append(key)
            d[key] = value

        answer.append(temp)

        for i in toRemove:
            del d[i]

    return answer


print(findMatrix([1,3,4,1,2,3,1]))    
