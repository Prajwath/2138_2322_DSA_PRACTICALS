import csv
from collections import Counter

# Function to count word occurrences and save results to a CSV file
def count_words(input_filename, output_filename):
    # Initialize a counter to store word occurrences
    word_counter = Counter()

    # Read the input file and count word occurrences
    with open(input_filename, 'r') as input_file:
        for line in input_file:
            words = line.split()
            word_counter.update(words)

    # Write the results to the output CSV file
    with open(output_filename, 'w', newline='') as output_file:
        writer = csv.writer(output_file)
        for word, count in word_counter.items():
            writer.writerow([count, word])  # Interchanged count and word, separated by a blank space

if __name__ == "__main__":
    input_filename = "occurInput.csv"
    output_filename = "inputQS.csv"
    count_words(input_filename, output_filename)
    print(f"Word count results saved to {output_filename}")
