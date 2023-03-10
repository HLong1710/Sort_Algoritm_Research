import numpy as np
import json

# Tạo mảng ngẫu nhiên với 1 triệu phần tử
data = np.random.random_sample((1000000,))

# Sắp xếp mảng theo thứ tự tăng dần
#data = np.sort(data)
#data = data[::-1]

print(data[:])

with open('Data_Input_Array_10.txt', 'w') as filehandle:
    json.dump(data.tolist(), filehandle)