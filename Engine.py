import matplotlib.pyplot as plt
import os
import platform
import subprocess
from subprocess import Popen, PIPE, check_output
import time

try:
    # This is Python's way of calling the command line. We use it to compile the C++ files.
    subprocess.check_output("g++ -std=c++17 main.cpp", stdin=None, stderr=subprocess.STDOUT, shell=True)
except subprocess.CalledProcessError as e:
    # There were compiler errors in BubbleSort.cpp. Print out the error message and exit the program.
    print("<p>", e.output, "</p>")
    raise SystemExit

algorithms = ["Selection", "Merge", "Heap", "Bubble"]


for algorithm in algorithms:
    algorithm = []
    for i in range(10):
        # Start the clock
        tic = time.time()
        
        toc = time.time()
        # Add the runtime to the list
        pythonTimes.append(toc - tic)

