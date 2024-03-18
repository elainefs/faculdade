import random
import time
import statistics

def insertion_sort(list):
    for i in range(1, len(list)):
        key = list[i]
        j = i - 1
        while j >= 0 and list[j] > key:
            list[j + 1] = list[j]
            j -= 1
        list[j + 1] = key
    return list

list_sizes = [1000, 5000, 10000]
random_lists = [[random.randint(1, 100) for _ in range(size)] for size in list_sizes]

exectimes = []
for i, lst in enumerate(random_lists):
    for j in range (10):
        start_time = time.time()
        sorted_list = insertion_sort(lst)
        end_time = time.time()
        execution_time = end_time - start_time
        exectimes.append(execution_time)
    print(f"Estatísticas do Insertion Sort para a {i+1}ª lista (tamanho =  {len(lst)})\nMédia: {statistics.mean(exectimes)}\nMediana: {statistics.median(lst)}\nModa: {statistics.mode(lst)}\nDesvio Médio: {statistics.mean(abs(x - statistics.mean(exectimes)) for x in exectimes)}\nVariância: {statistics.pvariance(exectimes)}\nDesvio Padrão: {statistics.pstdev(exectimes)}")
    exectimes = []


    