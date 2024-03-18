import random
import time
import statistics

def merge_sort(list):
    if len(list) > 1:
        mid = len(list) // 2
        left_half = list[:mid]
        right_half = list[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                list[k] = left_half[i]
                i += 1
            else:
                list[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            list[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            list[k] = right_half[j]
            j += 1
            k += 1

    return list

list_sizes = [1000, 5000, 10000]
random_lists = [[random.randint(1, 100) for _ in range(size)] for size in list_sizes]

exectimes = []
for i, lst in enumerate(random_lists):
    for j in range (10):
        start_time = time.time()
        sorted_list = merge_sort(lst)
        end_time = time.time()
        execution_time = end_time - start_time
        exectimes.append(execution_time)
    print(f"Estatísticas do Merge Sort para a {i+1}ª lista (tamanho =  {len(lst)})\nMédia: {statistics.mean(exectimes)}\nMediana: {statistics.median(lst)}\nModa: {statistics.mode(lst)}\nDesvio Médio: {statistics.mean(abs(x - statistics.mean(exectimes)) for x in exectimes)}\nVariância: {statistics.pvariance(exectimes)}\nDesvio Padrão: {statistics.pstdev(exectimes)}")
    exectimes = []