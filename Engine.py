
import matplotlib.pyplot as plt
import os
import platform
import subprocess
from subprocess import Popen, PIPE, check_output
import time

from netaddr.strategy.ipv6 import int_to_str
from pyatspi import Selection

'''
try:
    # This is Python's way of calling the command line. We use it to compile the C++ files.
    subprocess.check_output("g++ -std=c++17 main.cpp", stdin=None, stderr=subprocess.STDOUT, shell=True)
except subprocess.CalledProcessError as e:
    # There were compiler errors in BubbleSort.cpp. Print out the error message and exit the program.
    print("<p>", e.output, "</p>")
    raise SystemExit
    '''

algorithms = {'Selection': [], 'Merge': [], 'Heap': [], 'Bubble': []}

for algorithm in algorithms:
    for i in range(1, 11):
        # Start the clock
        execute = "./sorting_binary " +  str(i*100) + " " + algorithm
        tic = time.time()
        subprocess.check_output(execute, stdin=None, stderr=subprocess.STDOUT, shell=True)
        toc = time.time()
        # Add the runtime to the list


# Create a list of the sizes to use for the x axis tick marks
sizes = range(1000, 10001, 1000)
# Create lists that are offset so the Python bars aren't overlapping with C++ bars in the graph
SelectionX = range(850, 10001, 1000)
MergeX = range(1150, 10501, 1000)
HeapX = range(1000, 10001, 1000)
BubbleX = range(1000, 10001, 1000)
# Create a graph plot with one (1) row and one (1) column.
# The third 1 signals to start at the first subplot (aka subplot 1 out of 1)
ax = plt.subplot(111)

ax.bar(SelectionX, Selection, width=300, color='r', align='center')
ax.bar(MergeX, Merge, width=300, color='y', align='center')
ax.bar(HeapX, Heap, width=300, color='b', align='center')
ax.bar(BubbleX, Bubble, width=300, color='g', align='center')
# Set the window title
plt.gcf().canvas.manager.set_window_title('Sort times')
# Set the graph title
plt.title('Sorting Algorithms')
# Label the x axis
plt.xlabel('Number of items to sort')
# Make sure the x-axis tick marks/labels are at each 1000
plt.xticks(sizes)
# Label the y axis
plt.ylabel('Times in seconds')
# Save the graph to a file
plt.savefig('Airport_Sorting.png')
# Display the graph in a new window
plt.show()
