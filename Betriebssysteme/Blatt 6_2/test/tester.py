import subprocess
from time import time
from matplotlib import pyplot

THREAD_VALUES = [1, 2, 5, 10, 15, 20]
DELAY_VALUES = [0, 300, 500, 1000]
measuered_times = {}

for delay_value in DELAY_VALUES:
    for thread_value in THREAD_VALUES:
        print("Starting Bot with {} thread/s and a delay of {}".format(thread_value, delay_value))
        args = [
            "./simple_bot_{}_threads".format(thread_value),
            "testSites_10_2019.txt",
            "--webreq-delay",
            str(delay_value),
            "--webreq-path",
            "download"
        ]
        start = time()
        subprocess.run(args, stdout=open("/dev/null", "w"))
        stop = time()
        duration = stop - start
        print("Duration: {}s".format(duration))
        try:
            measuered_times[delay_value]
        except KeyError:
            measuered_times[delay_value] = {}
        measuered_times[delay_value][thread_value] = duration

#measuered_times = {0: {1: 9.749529361724854, 2: 4.398436546325684, 20: 0.8282811641693115, 5: 2.346621513366699, 10: 1.5131034851074219, 15: 0.9421765804290771}, 500: {1: 25.815934896469116, 2: 11.537872552871704, 20: 1.135632038116455, 5: 5.108179330825806, 10: 2.971946954727173, 15: 6.363574981689453}, 300: {1: 17.820128202438354, 2: 8.931088209152222, 20: 1.728605031967163, 5: 3.7385566234588623, 10: 2.1428887844085693, 15: 1.9904961585998535}, 1000: {1: 37.73264670372009, 2: 19.249218940734863, 20: 2.836066722869873, 5: 7.966156482696533, 10: 4.35728907585144, 15: 3.042389154434204}}
print(measuered_times)

table_file = open("table.txt","w")
table_file.write("{:^10}|{:^6}|{:^6}|{:^6}|{:^6}|\n".format("#Threads", *DELAY_VALUES))
table_file.write("{0:-^10}+{0:-^6}+{0:-^6}+{0:-^6}+{0:-^6}+\n".format(""))
for thread_value in THREAD_VALUES:
    table_file.write("{:^10d}|{:>6.3f}|{:>6.3f}|{:>6.3f}|{:>6.3f}|\n".format(thread_value, *
                                                                [measuered_times[delay_value][thread_value] for delay_value in DELAY_VALUES]))
table_file.close()
pyplot.xlabel("Threads")
pyplot.ylabel("Duration")
for delay_value in DELAY_VALUES:
    thread_values = sorted(list(measuered_times[delay_value].keys()))
    duration = list(map(measuered_times[delay_value].get, thread_values))
    min_value = min(duration)
    multithreading_value = list(map(lambda val: min_value/val, duration))
    pyplot.plot(thread_values, multithreading_value, label=delay_value)
pyplot.legend()
pyplot.show()
