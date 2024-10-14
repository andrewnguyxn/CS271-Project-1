import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns

# Load the CSV data
data = pd.read_csv("runtime_data_output.csv")

# Use Seaborn style for better aesthetics
sns.set_style("whitegrid")

# Data for the plot (from CSV)
array_sizes = data['InputSize']
insertion_sort_times = data['InsertionSort']
merge_sort_times = data['MergeSort']
quick_sort_times = data['Quicksort']
randomized_quick_sort_times = data['RandomizedQuicksort']
improved_quick_sort_times = data['ImprovedQuicksort']
default_sort_times = data['DefaultSort']

# Initialize the plot
plt.figure(figsize=(16, 10))

# Use a color palette for better distinction
colors = sns.color_palette("tab10")

# Plot the data with markers and line styles
plt.plot(array_sizes, insertion_sort_times, marker='o', linestyle='-', color=colors[0], label='Insertion Sort', linewidth=2)
plt.plot(array_sizes, merge_sort_times, marker='s', linestyle='--', color=colors[1], label='Merge Sort', linewidth=2)
plt.plot(array_sizes, quick_sort_times, marker='^', linestyle='-.', color=colors[2], label='Quick Sort', linewidth=2)
plt.plot(array_sizes, randomized_quick_sort_times, marker='D', linestyle=':', color=colors[3], label='Randomized Quick Sort', linewidth=2)
plt.plot(array_sizes, improved_quick_sort_times, marker='v', linestyle='-', color=colors[4], label='Improved Quick Sort', linewidth=2)
plt.plot(array_sizes, default_sort_times, marker='*', linestyle='--', color=colors[5], label='C++ Sort Library', linewidth=2)

# Set logarithmic scales
plt.xscale('log')
plt.yscale('log')

# Add minor ticks for better readability
from matplotlib.ticker import LogLocator, NullFormatter

ax = plt.gca()
ax.xaxis.set_minor_locator(LogLocator(base=10.0, subs=np.arange(1, 10)*0.1, numticks=12))
ax.yaxis.set_minor_locator(LogLocator(base=10.0, subs=np.arange(1, 10)*0.1, numticks=12))
ax.xaxis.set_minor_formatter(NullFormatter())
ax.yaxis.set_minor_formatter(NullFormatter())

# Add labels and title
plt.xlabel('Array Size (n)', fontsize=18)
plt.ylabel('Time (milliseconds)', fontsize=18)
plt.title('Execution Time of Sorting Algorithms vs. Array Size', fontsize=22)

# Adjust tick label size
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)

# Add grid lines
plt.grid(True, which="both", linestyle='--', linewidth=0.7)

# Adjust axis limits dynamically based on data range
plt.xlim([min(array_sizes) * 0.8, max(array_sizes) * 1.2])
plt.ylim([data.iloc[:, 1:].min().min() * 0.8, data.iloc[:, 1:].max().max() * 1.2])

# Add annotations to highlight key points (e.g., divergence points)
plt.annotate('Insertion Sort diverges', xy=(1000, insertion_sort_times.iloc[2]), xytext=(2000, 1e-1),
             arrowprops=dict(facecolor='black', arrowstyle='->'), fontsize=12, color='black')

# Move the legend outside the plot for better visibility
plt.legend(fontsize=14, loc='upper left', bbox_to_anchor=(1.05, 1))

# Tight layout to prevent clipping
plt.tight_layout()

# Display the plot
plt.show()