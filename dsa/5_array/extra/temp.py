# def count(N):
#     list_of_bin = []
#     for i in range(1,N+1):
#         list_of_bin.append(str(bin(i)).replace("0b",""))
#     new_list = []
#     for i in list_of_bin:
#         new_list.append(i.replace("1","2").replace("0","1"))
#     print(new_list)
#     cnt = 0
#     for i in new_list:
#         def sum_of_digits(s):
#             return sum(int(char) for char in s)

#         # Calculate the total sum of digits for all strings
#         total_sum = sum(sum_of_digits(s) for s in i)

#         # Check if the total sum is odd
#         if(total_sum % 2 != 0):
#             cnt += 1
#     return cnt
        
        
        
# print(count(6))
    
def count(N):
    cnt = 0
    for i in range(1, N + 1):
        bin_str = bin(i)[2:]
        transformed = bin_str.replace('1', '2').replace('0', '1')
        total_sum = sum(int(char) for char in transformed)
        if total_sum % 2 != 0:
            cnt += 1
    return cnt

print(count(6))
