import matplotlib.pyplot as plt
import os
import subprocess
import time

try:
    if os.path.exists('./build'):
        subprocess.check_output("cd build && cmake .. && make", stdin=None, stderr=subprocess.STDOUT, shell=True)
        
    else:
        subprocess.check_output("mkdir build && cd build && cmake .. && make", stdin=None, stderr=subprocess.STDOUT, shell=True)

    # This is Python's way of calling the command line. We use it to compile the C++ files.

except subprocess.CalledProcessError as e:
    # There were compiler errors in BubbleSort.cpp. Print out the error message and exit the program.
    print("<p>", e.output, "</p>")
    raise SystemExit

#  !!!! get reads and writes, this throws an error for me !!!!
subprocess.check_output("./build/sorting_binary", stdin=None, stderr=subprocess.STDOUT, shell=True)

algorithms = {'Selection': [], 'Merge': [], 'Heap': [], 'Bubble': []}

for algorithm in algorithms:
    for i in range(1, 11):
        print("Starting: " + str(algorithm) + " size " + str(i * 100))
        # Start the clock
        execute = "./build/sorting_binary " +  str(i*100) + " " + algorithm
        print(execute)
        tic = time.time()
        subprocess.check_output(execute, stdin=None, stderr=subprocess.STDOUT, shell=True)
        toc = time.time()
        # TODO: Add the runtime to the list
        algorithms[algorithm].append(toc - tic)
        print("finished: " + str(algorithm) + " size " + str(i*100) + " took " + str(toc - tic) + '\n')

    print("finished " + str(algorithm))
    print(algorithms[algorithm])






# Create a list of the sizes to use for the x axis tick marks
sizes = range(1000, 10001, 1000)


for algorithm in algorithms:
    ax = plt.subplot(111)
    ax.bar(range(1000, 10001, 1000), algorithms[algorithm], width=300, color='r', align='center')
    # Set the window title
    plt.gcf().canvas.manager.set_window_title(str(algorithm) + ' Sort times')
    # Set the graph title
    plt.title(str(algorithm) + ' Sort')
    # Label the x axis
    plt.xlabel('Number of items to sort')
    # Make sure the x-axis tick marks/labels are at each 1000
    plt.xticks(sizes)
    # Label the y axis
    plt.ylabel('Time in seconds')
    # Save the graph to a file
    plt.savefig('images/' + str(algorithm) + '_Sorting.png')
    # Display the graph in a new window
    plt.show()
